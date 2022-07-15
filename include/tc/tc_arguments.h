/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Teamcenter arguments
*/

/*  */

#ifndef TC_ARGUMENTS_H
#define TC_ARGUMENTS_H

/**
    @name Specifies data type of user arguments for #TC_argument_s
    @{
*/
/** Integer type argument value */
#define TC_argument_int                     POM_int

/** String type argument value */
#define TC_argument_string                  POM_string

/** Double type argument value */
#define TC_argument_double                  POM_double

/** Pointer type argument value */
#define TC_argument_pointer                 POM_MAX_type_token

/** 
    For internal use only, type for concatenated string of argument 
    values defined within BMF extensions in BMIDE.
*/
#define TC_argument_user_parameter_string  (POM_MAX_type_token + 1)

/** @} */

/**
    @defgroup TC_ARGUMENTS Teamcenter Arguments
    @ingroup TC
    @{
*/

typedef enum TC_module_state_e
{
    TC_uninitialized, 
    TC_initializing, 
    TC_initialized
} TC_module_state_t;


/**
    Argument processing for registered functions.
    <br>It is often used in an array of instances (refer to #TC_argument_list_t).
*/
typedef struct TC_argument_s
{
  int type;              /**< Defines the type of the contained data: e.g.TC_argument_int, TC_argument_string, etc. */
  int array_size;        /**< If set should be < \>= 1 */
  char * name;           /**< For internal use only, parameter name as defined in BMIDE */
  union
  {
    int   int_value;     /**< Argument value of integer type */
    char* str_value;     /**< Argument value of string type */
    double double_value; /**< Argument value of double type */
    void* ptr_value;     /**< Argument value of pointer type */
  } val_union;
} TC_argument_t;


/**
   List of #TC_argument_t.
   <br>Before each use, the cursor to access members of the list needs to be initialized 
   using the #TC_init_argument_list method.
   <br><br>Below is an example. Let us create a registration method:
   @code
     extern void GTAC_register_method(tag_t iPOMTag, 
                                      unsigned int iNbOfProperties, const char** iPropertyNames)
       {
         fprintf(stdout, "GTAC_register_method...\n");

         if( iNbOfProperties>0 && !iPropertyNames )
           {
             fprintf(stdout, "Error %d - METHOD_find_method\n", returned);
             return ITK_parameter_invalid_value;
           }

         int returned = ITK_ok;
         METHOD_id_t  method;
         
         returned = METHOD_find_method("Item", ITEM_create_msg, &method);
         if (returned) fprintf(stdout, "Error %d - METHOD_find_method\n", returned);

         if (method.id != NULLTAG)
           {
             TC_argument_list_t *userArgs = NULL;      
             int number_of_arguments = iNbOfProperties + 1;
             userArgs = (TC_argument_list_t *) MEM_alloc( sizeof(TC_argument_list_t) );
             userArgs->number_of_arguments = 4;
             
             userArgs->arguments = (TC_argument_t *) 
               MEM_alloc( userArgs->number_of_arguments*sizeof(TC_argument_t) );

             int argNb=0;
             userArgs->arguments[argNb].type = POM_int;
             userArgs->arguments[argNb].array_size = 1;
             userArgs->arguments[argNb++].val_union.int_value = iPOMTag;

             for(int i=0; i<iNbOfProperties; i++)
               {
                 userArgs->arguments[argNb].type = POM_string;
                 userArgs->arguments[argNb].array_size = 1;
                 userArgs->arguments[argNb].val_union.str_value = 
                   (char*) MEM_alloc( tc_strlen(iPropertyNames[i])*sizeof(char) );
                 tc_strcpy(userArgs->arguments[argNb].val_union.str_value, iPropertyNames[i]);
                 argNb++;
               }
        
             returned = METHOD_add_action(method, METHOD_post_action_type,
                                          GTAC_post_action, userArgs);
             if (returned != ITK_ok) 
               fprintf(stdout, "Error %d - METHOD_add_action\n", returned);
             else
               fprintf(stdout, "Method post action registered\n");
           }
         else    fprintf(stdout, "Method NOT found!\n", returned);
       
         return returned;
       }
   @endcode
   And the registered post action method can use the argument list as follows:
   @code
     extern int GTAC_post_action(METHOD_message_t *m, va_list args)
       {
         fprintf(stdout, "GTAC_post_action...\n");

         int n_args = 0;
         TC_init_argument_list(m->userArgs);       
         n_args = TC_number_of_arguments(m->userArgs);
         fprintf(stdout, "n_args = %d\n", n_args);

         for(int i=0; i<=n_args; i++)
           {
             if(POM_string == m->userArgs[i].type)
               {
                 int int_val = TC_next_int_argument(m->userArgs);
                 fprintf(stdout, "int_val = %d\n", int_val);
               }
             else
               {
                 char* str_value = TC_next_argument(m->userArgs);
                 fprintf(stdout, "str_value = %s\n", str_value);
               }
           }
         return ITK_ok;
       }
   @endcode
**/
typedef struct TC_argument_list_s
{
    int              i;
    int              number_of_arguments;
    TC_argument_t* arguments;
} TC_argument_list_t;


/**
   Returns the total number of Teamcenter arguments contained in a pointer to #TC_argument_list_t.
   @param a (I) #TC_argument_list_t* 
*/
#define TC_number_of_arguments(a) ((a == 0) ? 0 : a->number_of_arguments)


/**
   Initializes cursor position of a pointer to #TC_argument_list_t.
   <br>This has to be used to ensure proper functioning of #TC_next_argument and #TC_next_int_argument.
   @param a (I) #TC_argument_list_t* 
 **/
#define TC_init_argument_list(a) { if(a != 0) a->i = 0; }


/**
   Returns the current argument from the list of Teamcenter arguments, assuming that it is a string.
   <br>If there is no more argument in the list, it returns 0.

   Subsequently, the position cursor is increased by one.
   @param a (I) #TC_argument_list_t*   
*/
#define TC_next_argument(a) ((a == 0) ? 0 : ((a->i < a->number_of_arguments) ? (a->arguments[a->i++].val_union.str_value) : 0))



/**
   Returns the current argument from the list of Teamcenter arguments, assuming that it is an integer.
   <br>If there is no more argument in the list, it returns 0.

   Subsequently, the position cursor is increased by one.
   @param a (I) #TC_argument_list_t*   
*/
#define TC_next_int_argument(a) ((a == 0) ? 0 : ((a->i < a->number_of_arguments) ? (a->arguments[a->i++].val_union.int_value) : 0))

/** @} */

#endif
