#include <tccore/tctype.h>
#include <tc/folder.h>
#include <sys/types.h>
#include <tcinit/tcinit.h>
#include <ps/ps.h>
#include <tccore/workspaceobject.h>
#include <sa/tcfile.h>
#include <string.h>
#include <fclasses/tc_string.h>
#include <fclasses/tc_date.h>
#include <tc/tc_util.h>
#include <nls/nls.h>
#include <iostream>
#include <tie\tie.h>
#include <error_decode.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <tc/tc.h>
#include <ae/ae.h>
#include <itk/mem.h>
#include <tc/emh.h>
#include <tccore/item.h>
#include <qry/qry.h>
#include <errno.h>
#include <ctype.h>
#include <windows.h>
#include <sys/stat.h>
#include <unidefs.h>
#include <pom/pom/pom.h>
#include <tccore/aom.h>
#include <tccore/aom_prop.h>
#include <tc/tc_startup.h>
#include <publication/ods_itk.h>
#include <stdarg.h>
#define ERROR_CHECK(X) (report_error( __FILE__, __LINE__, #X, (X)))
#define IFERR_ABORT(X)  (report_error( __FILE__, __LINE__, #X, X, TRUE))
#define IFERR_REPORT(X) (report_error( __FILE__, __LINE__, #X, X, FALSE))
#define WRITE_D(X) ECHO("%s = %d\n", #X, X);

#define WRITE_L(X) if (X) ECHO("%s = TRUE\n", #X); \
    else ECHO("%s = FALSE\n", #X);
	
using namespace std;

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

static bool is_object_referenced(tag_t object)
{
    int
        ii,
        n_levels,
        n_instances,
        *instance_levels,
        *instance_where_found,
        n_classes,
        *class_levels,
        *class_where_found;
    tag_t
        *ref_instances,
        *ref_classes,
		 newstuff_type,
        type = NULLTAG;
		
    char
        *class_name,
        *name,
       *type_name = nullptr;
		
		POM_referencers_of_instance(object, 1, POM_in_ds_and_db,
        &n_instances, &ref_instances, &instance_levels,
        &instance_where_found, &n_classes, &ref_classes, &class_levels,
        &class_where_found);
        TCTYPE_find_type("Newstuff Folder", NULL, &newstuff_type);
		
    if (n_instances > 0)
    {
        ECHO("Referencing instances:\n");
        for (ii = 0; ii < n_instances; ii++)
        {
			AOM_ask_name(ref_instances[ii], &name);
			TCTYPE_ask_object_type(ref_instances[ii], &type);
			TCTYPE_ask_name2(type, &type_name);
			FL_remove(ref_instances[ii], newstuff_type);
		    AOM_save(ref_instances[ii]);
			AOM_refresh(ref_instances[ii], 0);
           
        }
        MEM_free(ref_instances);
        MEM_free(instance_levels);
        MEM_free(instance_where_found);
    }

    if (n_classes > 0)
    {
        ECHO("Referencing classes:\n");
        for (ii = 0; ii < n_classes; ii++)
        {
			POM_name_of_class(ref_classes[ii], &class_name);
			
            if (class_name) MEM_free(class_name);
        }
        MEM_free(ref_classes);
        MEM_free(class_levels);
        MEM_free(class_where_found);
    }

    if ((n_instances + n_classes) > 0) return true;

    return false;

}

static int remove_from_all_folders(tag_t object)
{
    int
        cnt = 0,
        ii,
        n_levels,
        n_instances,
        *instance_levels,
        *instance_where_found,
        n_classes,
        *class_levels,
        *class_where_found;
    tag_t
        folder_type,
        newstuff_type,
        *ref_instances,
        *ref_classes,
        type = NULLTAG;
		
		TCTYPE_find_type("Folder", NULL, &folder_type);
		
    if (folder_type == NULLTAG)
    {
        ECHO("Folder type not found!\n");
        return FALSE;
    }
	TCTYPE_find_type("Newstuff Folder", NULL, &newstuff_type);
	
    if (newstuff_type == NULLTAG)
    {
        ECHO("Newstuff Folder type not found!\n");
        return FALSE;
    }
	
	POM_referencers_of_instance(object, 1, POM_in_ds_and_db,
        &n_instances, &ref_instances, &instance_levels,
        &instance_where_found, &n_classes, &ref_classes, &class_levels,
        &class_where_found);

    if (n_instances > 0)
    {
        for (ii = 0; ii < n_instances; ii++)
        {
			TCTYPE_ask_object_type(ref_instances[ii], &type);
			
            if ((type == folder_type) || (type == newstuff_type))
            {
				printf("Folder name: s%\n", type);
                AOM_refresh(ref_instances[ii], 0);
				FL_remove(ref_instances[ii], newstuff_type);
				AOM_save(ref_instances[ii]);
				AOM_refresh(ref_instances[ii], 0);	
                cnt++;
            }
        }
        MEM_free(ref_instances);
        MEM_free(instance_levels);
        MEM_free(instance_where_found);
    }

    if (n_classes > 0)
    {
        MEM_free(ref_classes);
        MEM_free(class_levels);
        MEM_free(class_where_found);
    }

    return cnt;
}

int  login_TC ()
{	
	int retcode=ITK_ok; 	


	/*get command line input from user*/
	const char* userid =ITK_ask_cli_argument("-u=");
	const char* password = ITK_ask_cli_argument("-p=");
	const char* group = ITK_ask_cli_argument("-g=");
	const char* mode = ITK_ask_cli_argument("-m=");
	const char* prj_id = ITK_ask_cli_argument("-prj_id=");
	int ifail=0;
	
	ITK_init_module(userid, password, group);
	
	//ERROR_CHECK(ITK_init_module(userid, password, group));
	  if(ifail !=ITK_ok) 
	{printf("iMAN login NOT sucessfull.\n"); return ifail;}	
    
	printf("Teamcenter login sucessfull.\n");
	  
}
	
	
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
 
 static void find_item(char *item_id, tag_t *item)
{
    int
        n = 0;
    tag_t
        *items;
    const char
        *names[1] = { "item_id" },
        *values[1] = { item_id };
	ITEM_find_items_by_key_attributes(1, names, values, &n, &items);
    if (n > 0) *item = items[0];
    if (items) MEM_free(items);
}


 
 static void do_it(void)
{
	
	
	char *item_name=nullptr;
	
    tag_t
        item = NULLTAG;
    char
        item_id[ITEM_id_size_c +1];  
       
       // ITEM_find_item("000275", &item) ;
		find_item("000299",  &item);
		
		ITEM_ask_name2(item, &item_name);	
		printf("\1-Name of Item :%s\n", item_name); 

        is_object_referenced(item);

		//remove_from_all_folders(item);
		PrintErrorStack();

		//PrintErrorStack();
		//AOM_refresh(item, TRUE);

		printf("Refrences %d\n", is_object_referenced(item));
		//PrintErrorStack();
		
		AOM_lock_for_delete(item);
		//PrintErrorStack();
		ITEM_delete_item(item);
}

int ITK_user_main(int argc , char* argv[])
{
	int ifail = 0;	
	
	ITK_initialize_text_services(ITK_BATCH_TEXT_MODE);

	
	//serch_And_Print_Items();	
	login_TC();
	
	ITK_set_journalling(TRUE);
	
	do_it();
	
	ITK_exit_module(FALSE);
	
	
	
	
	
	
	
	/*
	int iITK = ITK_ok;
	
	tag_t Item =NULLTAG;
	
	char *item_name="Abbas";


	iITK=ITEM_find_item("000199",&Item);
	PrintErrorStack();

	//printf("\find_item :%d\n", iITK);
	ITEM_ask_name2(Item, &item_name);	
	//PrintErrorStack();
	printf("\1-Name of Item :%s\n", item_name); 
	//PrintErrorStack();
	//int siteID = 0;
	ifail=ODS_unpublish_object (0,Item);
	//printf("\1-ODS_unpublish_object :%d\n", ifail);
	PrintErrorStack();
	

	//printf("\1-AOM_delete_with_extensions :%d\n", AOM_delete_with_extensions (Item));
	//PrintErrorStack();
	printf("\1-ITEM_delete_item :%d\n", ITEM_delete_item(Item));
	//PrintErrorStack();
	printf("\1-ITEM_save_item :%d\n", ITEM_save_item(Item));
	//PrintErrorStack();
	
	
	ITK_exit_module(true);
	iITK=ITEM_find_item("000148",&Item);
	iITK=ITEM_ask_name2(Item, &item_name);
	
	
	printf("\2-Name of Item :%d\n", iITK);
	*/
	return(ifail);
}