#include <sys/types.h>
#include <sys/stat.h>

#include <pom/pom/pom.h>
#include <pom\enq\enq.h>

#include <ecm/ecm.h>
#include <epm/epm.h>

#include <tccore/workspaceobject.h>
#include <tccore/item.h>
#include <tccore/aom.h>
#include <tccore/aom_prop.h>
#include <tccore/custom.h>
#include <tccore/item_errors.h>
#include <tccore/method.h>
#include <tccore/tctype.h>
#include <tccore/grm.h>
#include <tccore/workspaceobject.h>
#include <tccore/grmtype.h>
#include <tccore/tc_msg.h>

#include <sa/tcfile.h>
#include <sa/user.h>
#include <sa/group.h>

#include <property/prop.h>
#include <property/prop_errors.h>
#include <property/prop_msg.h>

#include <string.h>
#include <fclasses/tc_string.h>
#include <fclasses/tc_date.h>

#include <tc/tc_util.h>
#include <tc/tc.h>
#include <tc/emh.h>
#include <tc/tc_startup.h>
#include <tc/folder.h>
#include <tc/emh_const.h>

#include <ae/ae.h>
#include <ae/dataset.h>
#include <ae/datasettype.h>
#include <ae/nxsm.h>

#include <ps/ps.h>
#include <ps/vrule.h>

#include <tcinit/tcinit.h>
#include <nls/nls.h>
#include <iostream>
#include <tie\tie.h>
#include <error_decode.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <itk/mem.h>
#include <qry/qry.h>
#include <errno.h>
#include <ctype.h>
#include <windows.h>
#include <unidefs.h>
#include <form/form.h>
#include <ict/ict_userservice.h>
#include <stdarg.h>
#include <time.h>
#include <bom/bom.h>
#include <me/me.h>
#include <cfm/cfm.h>
#include <collabctx/collabctx.h>
#include <user_exits/user_exits.h>
#include <ss/ss_const.h>

#define CALLAPI(expr)ITKCALL(ifail = expr); if(ifail != ITK_ok)return ifail; 
#define IFERR_ABORT(X)  (report_error( __FILE__, __LINE__, #X, X, TRUE));
#define ITEM_find_item FindItem
#define WRITE_D(X) ECHO("%s = %d\n", #X, X);

#define WRITE_L(X) if (X) ECHO("%s = TRUE\n", #X); \
    else ECHO("%s = FALSE\n", #X);

using namespace std;

static int PrintErrorStack( void )
{
	int iNumErrs = 0;
	const int *pSevLst = NULL;
	const int *pErrCdeLst = NULL;
	const char **pMsgLst = NULL;
	register int i = 0;
 
	EMH_ask_errors( &iNumErrs, &pSevLst, &pErrCdeLst, &pMsgLst );
	fprintf( stderr, "Error(s): \n");
	
	for ( i = 0; i < iNumErrs; i++ )
	{
		fprintf( stderr, "\t%6d: %s\n", pErrCdeLst[i], pMsgLst[i] );
	}
	return ITK_ok;
 }
 
char* strings_trim (char* word)
{
	char* trimed_word = word;
	int init_size = strlen(word);
	char delim[] = "=";

	char *ptr = strtok(word, delim);	
	char *temp_ptr = ptr;
	
	while(ptr != NULL)
	{		
		temp_ptr = ptr;
		ptr = strtok(NULL, delim);
		if (ptr == NULL)
			trimed_word = temp_ptr;
	}	
	
	return trimed_word;
}

static void ECHO(char *format, ...)
{
    char msg[1000];
    va_list args;
    va_start(args, format);
    vsprintf(msg, format, args);
    va_end(args);
    printf(msg);
    TC_write_syslog(msg);
}

static int report_error(char *file, int line, char *call, int status,
    logical exit_on_error)
{
    if (status != ITK_ok)
    {
        int
            n_errors = 0;
		const int 	
            *severities = NULL,
            *statuses = NULL;
        const char
            **messages;

        EMH_ask_errors(&n_errors, &severities, &statuses, &messages);
        if (n_errors > 0)
        {
            ECHO("\n%s\n", messages[n_errors-1]);
            EMH_clear_errors();
        }

        ECHO("error %d at line %d in %s\n", status, line, file);
        ECHO("%s\n", call);

        if (exit_on_error)
        {
            ECHO("%s", "Exiting program!\n");
            exit (status);
        }
    }

    return status;
}

int save_object (tag_t object_tag)
 {
    int ReturnCode;
   /* Save the object. */
    ReturnCode = AOM_save (object_tag);
    if (ReturnCode != ITK_ok)
    {
     //output_error ("ERROR %d save object.\n", ReturnCode);
      return (ReturnCode);
    }
	/* Unlock the object. */
 
	ReturnCode = AOM_unlock (object_tag);
     return (ReturnCode);
 }
 
int trim(char *str)
 {
	char *ptr = NULL;
	int i,j=0;
	ptr = (char*)malloc((strlen(str)+1) * 2);
	for(i=0;str[i]!='\0';i++)
	{
	if (str[i] != ' ' && str[i] != '\t')
		ptr[j++]=str[i];
	}
	ptr[j]='\0';
	str=ptr;
	free(ptr);
	return 0;
 }

int Get_Items (int *nFound, tag_t** foundTags)
{

	const char *select_attrs[]  = {"puid"};
	const char *name[] = {"Item"};
	char *enqid  = "find_wso_by_type";
	char *value_prop    = NULL;
	char *object_type    = NULL;
	
	int i;
	int n_rows, n_cols;

	void ***values;

	if (POM_enquiry_create (enqid)!= ITK_ok )PrintErrorStack();
	if (POM_enquiry_add_select_attrs (enqid,"Item", 1,select_attrs)!= ITK_ok )PrintErrorStack();	

	if ( POM_enquiry_execute (enqid, &n_rows, &n_cols,&values)!= ITK_ok ) PrintErrorStack();

	if ( n_rows != 0 )
        {
			*foundTags = (tag_t *)MEM_alloc ( n_rows * sizeof( tag_t ));
			*nFound = n_rows;

		for ( i =0 ; i < (*nFound) ; i++ )
			(*foundTags )[i] = *((tag_t *)values[i][0]);
		}
		
	if ( POM_enquiry_delete("find_wso_by_type")!= ITK_ok ) PrintErrorStack();
	MEM_free( values );

    return 0;
}

static tag_t get_Vrule_Object(char* relation, tag_t primary_obj)
{
	char* object_type = NULL;
	tag_t vrule = NULLTAG;
	tag_t relation_type = NULLTAG;
	
	GRM_find_relation_type(relation, &relation_type);
					
	int n_objects = 0;
	tag_t *objects = NULL;
	GRM_list_secondary_objects_only(primary_obj, relation_type, &n_objects, &objects); 
					
					
	for(int ii = 0; ii < n_objects; ii++)
	{
		if (AOM_ask_value_string(objects[ii],"object_type",&object_type)!= ITK_ok )PrintErrorStack();						
		 
		
		if (strcmp(object_type, "VariantRule") == 0)
		{
			vrule = objects[ii];
			printf("vrule_object_name: %s  \n", object_type);
		}
	}
	
	return vrule;
}
static void create_saved_variant_rule(tag_t window, tag_t rev_tag, char *target_value)
{      
    int ifail = ITK_ok;
	int count = 0;
    tag_t* vrule_tag = NULLTAG;
	char* test_print = NULL;
	
    ifail = BOM_window_ask_variant_rules(window,&count, &vrule_tag);  
    if (ifail != ITK_ok) { 		 }
	//printf("BOM_window_ask_variant_rules: %d  \n", count);

    int n_options = 0;
    tag_t *options = NULL;
    tag_t *option_revs = NULL;
	
	
	
    ifail = BOM_variant_rule_ask_options(vrule_tag[0], &n_options, &options , &option_revs);
    if (ifail != ITK_ok) {}
	
	
	
	
    printf("n_options: %d  \n", n_options);
   
    /* assuming only one */
    tag_t opt_tag = options[0];
    tag_t opt_rev_tag = option_revs[0];
    
    if(options) MEM_free(options);
    if(option_revs) MEM_free(option_revs);
  
    int n_values = 0; 
    int *index = NULL;
	printf("BOM_list_option_rev_values1: %s  \n", target_value);
    ifail = BOM_list_option_rev_values(opt_rev_tag, &n_values, &index);
	printf("BOM_list_option_rev_values2: %s  \n", target_value);
    if (ifail != ITK_ok) { /* your error logic here */ }
    for(int ii = 0; ii < n_values; ii++)
    {                             
        char *value = NULL;
        ifail = BOM_ask_option_rev_value(opt_rev_tag, index[ii], &value); 
        if (ifail != ITK_ok) { /* your error logic here */ }
		
		printf("target_value: %s  \n", target_value); 

		
        if(strcmp(target_value, value) == 0)      
        {
            ifail = BOM_variant_rule_set_option_values(vrule_tag[0] , opt_tag, 1, &index[ii]);
            if (ifail != ITK_ok) { /* your error logic here */ }
                       
            tag_t saved_vrule_tag = NULLTAG;
            ifail = VRULE_create_from_variant_rule("MyVarRule", "", vrule_tag[0], 1, &opt_tag,  &saved_vrule_tag);
            if (ifail != ITK_ok) { /* your error logic here */ }
            
            tag_t relation_type_tag = NULLTAG;
            ifail = GRM_find_relation_type( "IMAN_specification", &relation_type_tag);
            if (ifail != ITK_ok) { /* your error logic here */ }
            
            tag_t relation_tag = NULLTAG;
            ifail = GRM_create_relation(rev_tag, saved_vrule_tag , relation_type_tag, NULLTAG, &relation_tag);
            if (ifail != ITK_ok) { /* your error logic here */ }
            
            ifail = GRM_save_relation(relation_tag);
            if (ifail != ITK_ok) { /* your error logic here */ }
        }
        if(value) MEM_free(value);
    }
    if(index) MEM_free(index);
}


static int new_child_item_from_template_using_saved_variant_rule(tag_t tRev, tag_t tSVR)
{  
    int ifail = ITK_ok;
    int status;
	
	tag_t tWindow = NULLTAG;
	status = BOM_create_window (&tWindow); 
	
	tag_t tTopLine = NULLTAG;
	status = BOM_set_window_top_line(tWindow, NULLTAG, tRev, NULLTAG, &tTopLine);
	
	tag_t tRule = NULLTAG;
	status = CFM_find("Latest Working", &tRule);        
	status = BOM_set_window_config_rule(tWindow, tRule);
	status = BOM_window_hide_variants (tWindow);
	status = BOM_window_apply_full_vrule(tWindow, tSVR);
	
	tag_t ccContext = NULLTAG;
	status = COLLABCTX_create_config_context_based_on_ref( "", "CCName", "CCDesc", &tWindow, &ccContext);       

	tag_t tItem = NULLTAG;
	status = ITEM_ask_item_of_rev(tRev, &tItem);
	
	tag_t tType =NULLTAG;
	status = TCTYPE_ask_object_type(tItem, &tType);
	
	logical isModified = FALSE;
	char* itemId = NULL;
	status = USER_new_item_id(NULLTAG, tType, &isModified, &itemId);
	cout << "\n  itemId: "<< itemId << endl;

	tag_t tNewRev;
	char ruleKey[] = "Product.Template.Cloning";
	status = ME_create_product_from_template(itemId, "A", itemId, "", tRev, ccContext, tWindow, ruleKey, &tNewRev);     
	status = BOM_close_window(tWindow);
	if(itemId) MEM_free(itemId); 
    return ifail;
}

static int new_root_item_from_template_using_saved_variant_rule(tag_t tRev, tag_t tSVR)
{  
    int ifail = ITK_ok;
    int status;
      
    tag_t tWindow = NULLTAG;
    status = BOM_create_window (&tWindow); 
        
    tag_t tTopLine = NULLTAG;
    status = BOM_set_window_top_line(tWindow, NULLTAG, tRev, NULLTAG, &tTopLine);
        
    tag_t tRule = NULLTAG;
    status = CFM_find("Latest Working", &tRule);   
     
    status = BOM_set_window_config_rule(tWindow, tRule);
    status = BOM_window_hide_variants (tWindow);
    status = BOM_window_apply_full_vrule(tWindow, tSVR);
        
    tag_t ccContext = NULLTAG;
    status = COLLABCTX_create_config_context_based_on_ref( "", "CCName", "CCDesc", &tWindow, &ccContext);       
        
    tag_t tNewWindow = NULLTAG; 
    status = BOM_create_window (&tNewWindow);   
        
    tag_t tItem = NULLTAG;
    status = ITEM_ask_item_of_rev(tRev, &tItem);
        
    tag_t tType =NULLTAG;
	status = TCTYPE_ask_object_type(tItem, &tType);
	
	logical isModified = FALSE;
	char* itemId = NULL;
	status = USER_new_item_id(NULLTAG, tType, &isModified, &itemId);
	cout << "\n  itemId: "<< itemId << endl;

	tag_t tNewRev;
	char ruleKey[] = "Product.Template.Cloning";
	status = ME_create_product_from_template(itemId, "A", itemId, "", tRev, ccContext, tNewWindow, ruleKey, &tNewRev);      
	status = BOM_close_window(tWindow);
	status = BOM_close_window(tNewWindow);
	if(itemId) MEM_free(itemId);
   
    return ifail;
}

static void new_VRULE_create()
{
	char* objectname = NULL;

	char*  name = "New_VR";        
    char*   description = "Abbas baute diese Regel!!";
	
    tag_t   vrule = NULLTAG;       
	VRULE_create(name, description, &vrule);
	
	if (AOM_ask_value_string(vrule,"object_desc",&objectname)!= ITK_ok )PrintErrorStack();						
		printf("bl_item_item_id: %s  \n", objectname); 
	
}

static void create_sos(tag_t window, char *opt_name, char *value)
{
	char* test_print = NULL;

    tag_t top_line = NULLTAG;
    BOM_ask_window_top_line(window, &top_line);	
	
    tag_t rt_sos = NULLTAG;
    BOM_line_ask_sos(top_line, &rt_sos);
               
    tag_t var_config = NULLTAG;
    BOM_create_variant_config(NULLTAG, 1, &rt_sos, &var_config);

    tag_t item = NULLTAG;
    AOM_ask_value_tag(top_line, "bl_item", &item);	
   
   
   //if (AOM_ask_value_string(item,"object_name",&test_print)!= ITK_ok )PrintErrorStack();
						
	
   
    int opt = 0;
	BOM_item_ask_option_handle(window, item, opt_name, &opt);
	
	printf("top_line: %d  \n", opt);
	
    
    int how_set = BOM_option_set_by_user;
    BOM_sos_set_entry_string(rt_sos, opt, "", value, how_set);
    
    int opt_name_length = strlen(opt_name) + strlen(value) + 2;
    char *db_sos_name = NULL;
    db_sos_name = (char *) MEM_alloc(opt_name_length * sizeof(char));
    sprintf(db_sos_name, "%s - %s", opt_name, value);

    tag_t db_sos = NULLTAG;
    BOM_sos_db_create(db_sos_name, var_config, &db_sos);
    AOM_save(db_sos);
    MEM_free(db_sos_name);

    /* To save sos as References (IMAN_refrence) to the revision */
    tag_t revision = NULLTAG;
    AOM_ask_value_tag(top_line, "bl_revision", &revision);
  
    tag_t rel_type = NULLTAG;
    GRM_find_relation_type( "IMAN_reference", &rel_type);
    
    tag_t relation  = NULLTAG;
    GRM_create_relation(revision, db_sos, rel_type, NULLTAG, &relation);
    GRM_save_relation(relation);  
}

static tag_t print_Variant_Rule_Text (tag_t  irev_tag)
{
	
	tag_t* vrule_tag = NULLTAG;
		
	int ifail = ITK_ok;
	int count = 0;
	int n_entries = 0;
	/*
	char**       items = NULLTAG;
	char**       options = NULLTAG;
    char**       descriptions = NULLTAG;
	char**       values  = NULLTAG;
	*/
	char* objectname = NULL;
	
	int n_options = 0;
    tag_t *options = NULL;
    tag_t *option_revs = NULL;
	
		
	tag_t window = NULLTAG;
    BOM_create_window (&window);

    tag_t rule = NULLTAG;
    CFM_find("Latest Working", &rule);
    BOM_set_window_config_rule(window, rule);
    BOM_set_window_pack_all(window, TRUE);
	
	//tag_t top_line = NULLTAG;
   // BOM_ask_window_top_line(window, &top_line);	

    tag_t top_line = NULLTAG;
    BOM_set_window_top_line(window, NULLTAG, irev_tag, NULLTAG, &top_line);

    int n_children = 0;
    tag_t *children = NULL;
    //BOM_line_ask_child_lines(top_line, &n_children, &children);

	//tag_t bom_line = NULLTAG;
	
	//bom_line = top_line;
    if (children) MEM_free(children);	
		
	if (AOM_ask_value_string(top_line,"bl_rev_item_id",&objectname)!= ITK_ok )PrintErrorStack();
	//printf("top_line: %s  \n", objectname);
	
	
	//BOM_line_create_vi_structures (top_line, is_linked_to_generic_component, &new_item, &new_rev);
	
	
	
	
	
						
	//printf("top_line: %s  \n", objectname);
	
	char *opt_name = "613, 614, 616, 618";
	char *value = "638, 620, 626, 633";
	//create_sos(window, opt_name,  value);	
	
	//create_saved_variant_rule(window, irev_tag, opt_name);
	
	return top_line;
	
}

static void FindItem(char *item_id, tag_t *item)
{
    int
        n = 0;
    tag_t
        *items;
    const char
        *names[1] = { "item_id" },
        *values[1] = { item_id };

    ITEM_find_items_by_key_attributes(1, names, values, &n,&items);
    if (n > 0) *item = items[0];
    if (items) MEM_free(items);
}

/**
	Retrieves and Prints all the Item Revisions attached to a specified Item.
*/
	
static tag_t get_all_Item_Revision(tag_t item_tag)
{
	int  rev_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *rev_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;
	tag_t objTypeTag    = NULLTAG;
	int j = 0;
	tag_t rev_list_0 = NULL;
	
	int secondaryobjectcount  = 0;
	int referencenumberfound  = 0;
	tag_t *secondary_objects  = NULLTAG;
	char *type_name[TCTYPE_name_size_c+1];
	
	char *current_item_type = NULL;
	
	int
        n_revs,
        ii,
        n_rev_attach,
        jj;
    char
        item_name[ITEM_name_size_c +1],
        *id_string,
        *class_name;
    tag_t
        item,
        *revs,
        class_Object;
    GRM_relation_t
        *rev_attachs;

	if (ITEM_list_all_revs (item_tag, &rev_count, &rev_list)== ITK_ok)
	{
		//printf("-->>> num of Revision : %d \n", rev_count); 	
		for (int k = 0; k < rev_count; k++ )      
		{				
			if (AOM_ask_value_string(rev_list[0],"item_revision_id",&objectname)!= ITK_ok )PrintErrorStack();
				
			tag_t vrule = get_Vrule_Object("IMAN_specification", rev_list[0]);
			//if (AOM_ask_value_string(vrule,"object_name",&objectname)!= ITK_ok )PrintErrorStack();
			//printf("vrule_object_name: %s  \n", objectname); 
			
			
			//new_root_item_from_template_using_saved_variant_rule(rev_list[0], vrule);
			//new_child_item_from_template_using_saved_variant_rule(rev_list[0], vrule);
			//print_Variant_Rule_Text(rev_list[0]);					
				rev_list_0 = rev_list[0];
		}
		
		
	}						
    return rev_list_0;
}

/**
    Retrieves and Prints all the BOM Views related to the Item.
*/

static tag_t* get_all_Item_BOM(tag_t item_tag)
{
	int  bv_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *bv_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;

	int j = 0;

		if (ITEM_list_bom_views (item_tag, &bv_count, &bv_list)== ITK_ok)
			{
				for (int  j = 0; j < bv_count; j++ )      
				{	
					//print_Variant_Rule_Text(bv_list[0]);
				}
				//printf("bv_count: %d \n",bv_count);
			}						
    return bv_list;
}
 
 /*	
	Check that the item type, the owner of the user and the owner group have been entered 	
 */
 
 extern int ITK_user_main( int argc, char **argv )
{
	char *objectname = NULL;
	char *userId = NULL;
	char *password = NULL;
	char *group = NULL;
	char *errormsg = NULL;
	char *object_type = NULL;  
	char *item_id = NULL; 
	char *item_revision_id = NULL; 
	char *new_objectname = NULL;
	
	tag_t new_item = NULLTAG;
	tag_t new_rev = NULLTAG;
	bool is_linked_to_generic_component = false;	
	
	
	int istatus = ITK_ok;
	int n_item = 0;
	int iFail = ITK_ok;	
	int numOfParts = 0;
	
    tag_t *bv_list = NULL;		
    tag_t *rev_list = NULL;    
	tag_t *item_tags = NULLTAG;
	tag_t titem_rev = NULLTAG;
	tag_t towning_user = NULLTAG;	
	tag_t master_form = NULLTAG;	
	tag_t iman_manifestation = NULLTAG;	
	tag_t new_user = NULLTAG;
	tag_t  new_group = NULLTAG;	
	
	AE_reference_type_t     reftype;
       (void)argc;
       (void)argv;	
	
	userId = ITK_ask_cli_argument( "-u" );
	password = ITK_ask_cli_argument( "-p" );
	group = ITK_ask_cli_argument( "-g" );
	
	userId++;password++;group++;	
	
	if( (!userId) || (!password) ||(!group) )
	{
		printf("\n\n\t\t Enter -u=? -p=? -g=?");		
		exit(0);
	} 	

    istatus = ITK_init_module( userId , password , group );
	istatus = ITK_set_bypass( true );
	
	if ( istatus != ITK_ok)
	{
		EMH_ask_error_text( istatus, &errormsg);
		printf("Error with ITK_init_module: %s \n",errormsg);
		MEM_free(errormsg);
		return istatus;
	}
	

	
	istatus = Get_Items(&n_item, &item_tags);
	
	printf("login status %d /n", iFail);
	
	if ( istatus ==  ITK_ok )
        {
			printf(" Login successful.... \n");

			if ( n_item > 0 )
			{
				for ( int i = 0; i < n_item; i++ )      
				{		
						
						//printf("%d: Name: %s  \n", numOfParts, objectname); 
						
						
						
						//printf(" id: %s \n",  item_id); 
						
						//ructure_search_by_item_id(item_id,(item_tags)[i]);
						
						//do_it2((item_tags)[i]);
						
						/**
							Retrieves all the BOM Views related to the Item.
						*/
						if (AOM_ask_value_string(item_tags[i],"item_id",&item_id)!= ITK_ok )PrintErrorStack();

						//printf("-01: %s  \n", objectname);
						if (strcmp(item_id, "PR00000018") == 0)
						{
							//printf("Name: %s \n", objectname);
							//bv_list = get_all_Item_Revision (item_tags[i]);
							//new_VRULE_create();
							/*
							bool check = false;
							ITEM_ask_is_vi(item_tags[i], &check);
							if (check == true)
							{*/
								
								//printf("Das ist eine S_V .\n");
							//printf("00: %s  \n", objectname);
							tag_t top_line = print_Variant_Rule_Text (get_all_Item_Revision (item_tags[i]));	
							if (AOM_ask_value_string(top_line,"bl_line_name",&objectname)!= ITK_ok )PrintErrorStack();
							printf("001: %s  \n", objectname);
							//if (AOM_ask_value_string(item_tags[i],"item_id",&item_id)!= ITK_ok )PrintErrorStack();
							//printf("01: %s  \n", objectname);
							if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
							printf("02: %s  \n", objectname);
							if (AOM_ask_value_string(item_tags[i],"object_type",&object_type)!= ITK_ok )PrintErrorStack();
							printf("03: %s  \n", object_type);
							if (AOM_ask_value_string(get_all_Item_Revision (item_tags[i]),"item_revision_id",&item_revision_id)!= ITK_ok )PrintErrorStack();
							printf("04: %s  \n", objectname);
							if (BOM_line_create_vi(top_line, is_linked_to_generic_component, item_id, objectname, object_type,item_revision_id, &new_item, &new_rev)!= ITK_ok )PrintErrorStack();
							AOM_save(new_item);
							AOM_save(new_rev);

							if (new_item == NULLTAG)
							printf("05: %s  \n", objectname);
							//if (AOM_ask_value_string(new_rev,"item_revision_id",&item_revision_id)!= ITK_ok )PrintErrorStack();
							//printf("new_item: %s  \n", item_revision_id); 	
								
								
							}
							
							
							
							
						//}
							//if (AOM_ask_value_string(item_tags[i],"release_status_list",&item_id)!= ITK_ok )PrintErrorStack();
						//bv_list = get_all_Item_BOM (item_tags[i], new_user, new_group );
						/**
							Retrieves all the Item Revisions attached to a specified Item.
						*/						
						//rev_list = get_all_Item_Revision(item_tags[i], new_user, new_group);
						
						/**
							Retrieves the Item Master form type of an Item type.
						*/						
						
						//master_form =  ask_secondary_of_an_Object(item_tags[i]);
						
						/**
							change Owningchip.
						*/	
	
						//set_ownership((item_tags)[i],new_user, new_group);
						numOfParts++; 
					
				}
				
			}
		}
		
	return NULL;
	}	
	
	