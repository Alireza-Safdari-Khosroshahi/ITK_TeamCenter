/*
Copyright 2020 Siemens Digital Industries Software
==================================================
 Copyright 2013.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/


/**
    @file
    Header file for declaring legacy naming rule counter related APIs.
*/


#ifndef LEGACY_COUNTER_H
#define LEGACY_COUNTER_H


#include <tc/tc_startup.h>
#include <fclasses/tc_stdio.h>
#include <fclasses/tc_stdlib.h>
#include <common/tc_deprecation_macros.h>
#include <property/libproperty_exports.h>


#define REPORT_IFAIL(M) \
ifail?printf("%s : ERROR : ifail = %d\n",M,ifail):printf("%s : Ok\n",M)

#define HANDLE_ERROR(E) \
{ EMH_store_initial_error(EMH_severity_error,(E)); return(E); }

#define HANDLE_ERROR_S1(E,S) \
{ EMH_store_initial_error_s1(EMH_severity_error,(E),(S)); return(E); }

#define HANDLE_ERROR_AND_RELEASE(E,I) \
{ \
    (void)PROPERTY_release_number(I); \
    EMH_store_initial_error(EMH_severity_error,(E)); \
    return(E); \
}

#define TEST_ERROR(E) \
if ((E) != ITK_ok) return(E);

#define TEST_POM_ERROR(E) \
if ((E) != ITK_ok) HANDLE_ERROR(E)


/**
    @name Defines the number of retries when fetching the next ID.
    <br/>This must be stored in both numeric and string forms.
    @{
*/
#define GET_ID_RETRIES              10
#define RETRY_STRING                "10"
/** @} */

/** Empty string test macro */
#define IS_EMPTY(S)  (!(*(S)))

/** @name Defines the methods by which a new item name can be obtained
    @{
*/
#define SEED_METHOD                 0
#define BUILD_METHOD                1
#define SAVEAS_BUILD_METHOD         2
/** @} */

/** Defines the maximum index number to be used.
 Note that the actual maximum is one less than MAXNUM.
 NUMERIC_LIMIT must be large enough to store decimal string
 version of MAXNUM plus a NULL terminator.  */
#define NUMERIC_LIMIT               12
#define MAXNUM                      0x7FFFFFFF

#define HANDLE_ERROR(E) \
{ EMH_store_initial_error(EMH_severity_error,(E)); return(E); }

#define TEST_ERROR_AND_RELEASE(E,I) \
if ((E) != ITK_ok) { (void)PROPERTY_release_number(I); return(E); }

/* define the class for which id and rev is generated */
#define CLASS_IS_ITEM               0
#define CLASS_IS_DATASET            1


/************************** USER CONTROLLED VALUES **************************/

/* Define padding options for building names */

/* Comment/Uncomment the following line to disable/enable padding */
#define PADDING

/* Minimum length of the numeric component.                    *
 * Please ensure that this value is less than NUMERIC_LIMIT!!! */
#define PADNUM                      6

/* Define the first index number to use, when a seed is provided *
 * which does not have a numeric postfix. eg. "item"             *
 * THIS MUST BE A SINGLE NUMERIC DIGIT INSIDE DOUBLE QUOTES!!!   */
#define FIRST_NUM                   "2"

/******************************************************************************/

/* Name of the standard counter */
#define ITEMID_COUNTER_NAME         "USER_item_id"


/* Store all Item IDs issued, whether they are used or not.*/
static int    item_ids_issued      = 0;
static char** item_ids_issued_list = 0;

/* Store the tags for the next_id POM object and the actual ID attribute.  */
/* This saves us having to obtain these every time a user hits the Assign  */
/* button. The logical variables define whether the tags are legal or not. */
/* I tried to set to tag_t's to NULLTAG for this purpose, but the HP C     */
/* compiler did not like this. Typical.                                    */

static tag_t   nextIdInstance = NULLTAG;
static tag_t   attr_id        = NULLTAG;


#ifdef __cplusplus
    extern "C"{
#endif

/**
    Generates part numbers during bulk creation of objects and a single part
    number during single object creation for a user.

    <br>This part number can be based on the part number of an existing item,
    passed in via the old_item parameter. The system operates by incrementing
    a numeric postfix on the old part number. eg. "Item3" would produce "Item4"
    as output. If no numeric postfix exists on the given old_item, a postfix is
    added. eg. "Item" would produce "Item2" as output.

    <br>A completely new part number can be produced by passing in a NULLTAG via
    old_item. This part number is based on a fixed prefix, a numeric section
    which is obtained from the database and a fixed postfix.

    <br>The prefix and postfix can be defined in the site preference file under
    the names "ITEM_id_prefix" and "ITEM_id_postfix".
    Alternatively, they can be stored as internationalized text under the
    names "k_item_id_prefix" and "k_item_id_postfix".

    <br>This function will return a part number which is unique (ie. no IMAN item
    with this part number exists in the database) <b>at the time of generation</b>.
    Although the algorithm will not generate the same part number twice, there
    is no way to prevent the (remote) possibility that someone could manually
    generate the same part number between a user hitting the Assign button and
    then hitting the OK (or Apply) button. In this situation the user will have
    to hit the Assign button again.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ITEM_max_id_exceeded if the maximum number is reached for Item types
    <li>#AE_max_id_exceeded if the maximum number is reached for Dataset types
    <li>Potentially other errors
    </ul>
*/
extern PROPERTY_API int PROPERTY_new_item_id(
    const tag_t     old_item,       /**< (I) A tag which provides a seed value for saveAs and freeze. May be a NULLTAG if a new number is requested or for bulk id creation. */
    const int       quantity,       /**< (I) Number of ids to be created. */
    const int       class_is,       /**< (I) Store the class identifier for the id and rev generation. */
    const char*     type_name,      /**< (I) The type_name corresponding to item_id property. */
    logical*        mod,            /**< (O) A boolean value specifying if the system user. */
    char***         id              /**< (OF) quantity An array of strings with length specified in 'quantity' for the new part numbers.
    <br/>This array is not packed, which means that both the elements and the container need to be freed through a call to #MEM_free. */
);


/**
    Create a new item id generator counter.

    <br>This is supplied as a mechanism for creating new counters in the IMAN database for the
    Item Id generator. This function should be called from a separate ITK program (not supplied).

    <br>See 'USER_new_item_id' for details on how to use the multiple counters once they have been
    created.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while creating or saving objects related to Counter.
    </ul>
*/
extern PROPERTY_API int PROPERTY_legacy_create_id_counter(
    const char*         counter             /**< (I) Name of the counter to create. */
);


/**
    Selects the ImanNextId instance for current Counter.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while selecting the Counter.
    </ul>
*/
extern PROPERTY_API int PROPERTY_select_counter(
    const char*         counter_name        /**< (I) Name of counter to access. */
);


/**
    Loads the next index number from the current counter in the database. This
    is stored as a POM object, of class 'ImanNextId'.

    @deprecated #PROPERTY_load_current_number deprecated in Teamcenter 11.3. Use #PROPERTY_load_next_numbers instead.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while loading the index number.
    </ul>
*/
TC_DEPRECATED("11.3", "PROPERTY_load_current_number", "PROPERTY_load_next_numbers" )
extern PROPERTY_API int PROPERTY_load_current_number(
    int     class_id,       /**< (I) Class identifier for the id and rev generation. */
    int*    num             /**< (O) The current value of the index number. */
);


/**
    Retrieves next values from the current counter in the database, incrementing it simultaneously.
    <br/>The values retrieved are not guaranteed to be gapless (e.g. 10, 11, 14, 15 and 16 might be retrieved if asking for 5 values) but will be unique.
    <br/>The current counter is the counter set by the latest call to #PROPERTY_select_counter. The code snippet below helps understand the usage.

    @code
    int ifail = ITK_ok;

    try
    {
        ResultCheck  rStat;
        ....
        scoped_smptr<int>   next_values;
        int quantity = 2;
        rStat = PROPERTY_select_counter( "counter001" );                //  sets the counter, "counter001". Creates counter, "counter001" if absent.
        rStat = PROPERTY_load_next_numbers( quantity, &next_values );   //  retrieves next 2 values on the counter, "counter001".
        ....
        next_values = 0;
        quantity = 5;
        rStat = PROPERTY_select_counter( "counter002" );                //  sets the counter, "counter002". Creates counter, "counter002" if absent.
        rStat = PROPERTY_load_next_numbers( quantity, &next_values );   //  retrieves next 5 values on the counter, "counter002".
        ....
    }
    catch( const IFail& ex )
    {
        ifail = ex.ifail();
    }

    return  ifail;
    @endcode

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#NR_invalid_qunatity_value      if @p quantity is 0 or a negative number.
    <li>Possibly other errors.
    </ul>
*/
extern PROPERTY_API int PROPERTY_load_next_numbers(
    const int   quantity,           /**< (I) Number of next values to be retrieved. */
    int**       next_values         /**< (OF) quantity Generated next values from the current counter. These are guaranteed to be unique, but not gapless. */
);


/**
    Releases the lock on the index number in the database. This is only
    called in error situations.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while releasing the lock on the index number.
    </ul>
*/
extern PROPERTY_API int PROPERTY_release_number(
    const tag_t     id_instance     /**< (I) The tag of the POM object to be unlocked. This is returned by the load function. */
);


/**
   Generates a new item name based on the current name.

   <br>    eg.  "item"  -> "item2"
   <br>         "item2" -> "item3"
   <br>         "item9" -> "item10"
   <br>         "76534" -> "76535"

   @note
   <br>      This function has the rather neat feature of
             only scanning the bare minimum number of
             characters in the string required to produce
             the next name. In 90% of cases, this will be a
             single character. Of the remaining cases, 90%
             will scan 2 characters. This ratio pattern will
             be maintained no matter how many digits you
             extend your item name to.

   <br>      his function allocates the required memory to
             new_name. Callers must ensure that any memory
             previously pointed to by new_name is correctly
             dealt with.

   <br>      A NULL or empty old_name parameter will result
             in a NULL new_name being returned.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while building item names.
    </ul>
*/
extern PROPERTY_API int PROPERTY_seed_name(
    const char*     old_name,       /**< (I) The item's current name. */
    const int       class_id,       /**< (I) Store the class identifier for the id and rev generation. */
    char**          new_name        /**< (OF) Pointer to the newly generated name. */
);


/**
    Builds new item names during bulk creation of objects.
    During non-bulk creation it builds a single new item name.
    based on a standard prefix, postfix
    and an index number stored as a POM object.

    <br>The prefix and postfix can be defined in the site preference
    file under the names "ITEM_id_prefix" and "ITEM_id_postfix".
    Alternatively, they can be stored as internationalized text
    under the names "k_item_id_prefix" and "k_item_id_postfix".

    @note
    This function allocates the required memory to new_names. Callers must
    ensure that any memory previously pointed to by new_names is correctly
    dealt with.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while building item names.
    </ul>
*/
extern PROPERTY_API int PROPERTY_build_name(
    const int   quantity,           /**< (I) Number of objects to be created. */
    const int   class_id,           /**< (I) Store the class identifier for the id and rev generation. */
    char***     new_names           /**< (OF) quantity An array of strings with length specified in 'quantity' for the new names.
    <br/>This array is not packed, which means that both the elements and the container need to be freed through a call to #MEM_free. */
);


/**
    Generates a unique ID to be used for the "item_id" property when invoking the save as function PROPERTY_new_item_id on an item which value for the property "item_id" is purely numeric.

    @note This method is only needed when the seed "item_id" value in cases of a save as command.
    <br/>If the seed "item_id" is not all numeric, use #PROPERTY_seed_name to generate the needed "item_id" value.

    @note This function is added to eliminate the possibility of duplicate "item_id" generation incases of saveas command.

 @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors while building item names.
    </ul>
*/
extern PROPERTY_API int PROPERTY_saveas_build_name(
    const int   quantity,           /**< (I) Number of ID's to be created. */
    char***     ids                 /**< (OF) quantity Generated ID's based on the sequence of already created elements.
    <br/>This array is not packed, which means that both the elements and the container need to be freed through a call to #MEM_free. */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <property/libproperty_undef.h>

#endif
