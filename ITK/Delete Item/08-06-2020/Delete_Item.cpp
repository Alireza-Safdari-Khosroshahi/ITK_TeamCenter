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
#include <stdarg.h>
#define ERROR_CHECK(X) (report_error( __FILE__, __LINE__, #X, (X)))
#define IFERR_ABORT(X)  (report_error( __FILE__, __LINE__, #X, X, TRUE))
#define IFERR_REPORT(X) (report_error( __FILE__, __LINE__, #X, X, FALSE))
#define WRITE_D(X) ECHO("%s = %d\n", #X, X);

#define WRITE_L(X) if (X) ECHO("%s = TRUE\n", #X); \
    else ECHO("%s = FALSE\n", #X);
	
using namespace std;

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

    IFERR_REPORT(TCTYPE_find_type("Folder", NULL, &folder_type));
    if (folder_type == NULLTAG)
    {
        ECHO("Folder type not found!\n");
        return FALSE;
    }

    IFERR_REPORT(TCTYPE_find_type("Newstuff Folder", NULL, &newstuff_type));
    if (newstuff_type == NULLTAG)
    {
        ECHO("Newstuff Folder type not found!\n");
        return FALSE;
    }

    IFERR_REPORT(POM_referencers_of_instance(object, 1, POM_in_ds_and_db,
        &n_instances, &ref_instances, &instance_levels,
        &instance_where_found, &n_classes, &ref_classes, &class_levels,
        &class_where_found));

    if (n_instances > 0)
    {
        for (ii = 0; ii < n_instances; ii++)
        {
            IFERR_REPORT(TCTYPE_ask_object_type(ref_instances[ii], &type));
            if ((type == folder_type) || (type == newstuff_type))
            {
                IFERR_REPORT(AOM_refresh(ref_instances[ii], TRUE));
                IFERR_REPORT(FL_remove(ref_instances[ii], object));
                IFERR_REPORT(AOM_save(ref_instances[ii]));
                IFERR_REPORT(AOM_refresh(ref_instances[ii], FALSE));
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
	
void  serch_And_Print_Items ()
{
	char *item_name="Abbas";
	const char
        *names[2] = { "object_name", "object_type" },
        *values[2] = { "Test" , "CT4product"};

	int nItems = 0;	
	tag_t *items = NULLTAG;
	
	ITEM_find_items_by_key_attributes(2,names,values,&nItems,&items );

/*
	
	for (int i = 0; i < nItems; i++)
	{	
		ITEM_ask_name2(items[i], &item_name);
		printf("\Name of Item :%s\n", item_name);
	}
		printf("\n\n\n\nnum of items = [%d]\n", nItems);

	ITEM_delete_item(&items[2]);


ITEM_find_items_by_key_attributes(2,names,values,&nItems,&items );

	
	for (int i = 0; i < nItems; i++)
	{	
		ITEM_ask_name2(items[i], &item_name);
		printf("\Name of Item :%s\n", item_name);

	}
	

	printf("Abbas num of items = [%d]\n", nItems);
	if(items != NULLTAG) MEM_free(items);
		ITK_exit_module(TRUE);
		*/
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

	TCTYPE_find_type("Folder", NULL, &folder_type)
    if (folder_type == NULLTAG)
    {
        ECHO("Folder type not found!\n");
        return FALSE;
    }
	TCTYPE_find_type("Newstuff Folder", NULL, &newstuff_type)
   //FERR_REPORT(TCTYPE_find_type("Newstuff Folder", NULL, &newstuff_type));
    if (newstuff_type == NULLTAG)
    {
        ECHO("Newstuff Folder type not found!\n");
        return FALSE;
    }

    IFERR_REPORT(POM_referencers_of_instance(object, 1, POM_in_ds_and_db,
        &n_instances, &ref_instances, &instance_levels,
        &instance_where_found, &n_classes, &ref_classes, &class_levels,
        &class_where_found));

    if (n_instances > 0)
    {
        for (ii = 0; ii < n_instances; ii++)
        {
            IFERR_REPORT(TCTYPE_ask_object_type(ref_instances[ii], &type));
            if ((type == folder_type) || (type == newstuff_type))
            {
                IFERR_REPORT(AOM_refresh(ref_instances[ii], TRUE));
                IFERR_REPORT(FL_remove(ref_instances[ii], object));
                IFERR_REPORT(AOM_save(ref_instances[ii]));
                IFERR_REPORT(AOM_refresh(ref_instances[ii], FALSE));
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


	
	static void do_it(void)
{
    tag_t
        item = NULLTAG;
    char
        item_id[ITEM_id_size_c +1];
	char *test= "000090";
    do
    {
        printf("Enter Item ID: ");
		
       // gets(item_id);
	   
	    
        // (!strcmp(item_id, "")) return;

        item = NULLTAG;
        ITEM_find_item(test, &item) ;
		/*
        if (item == NULL_TAG)
        {
            ECHO("Item %s was NOT found!\n", item_id);
        }
        else
        {
            ECHO("Item %s was found\n", item_id);
        }
		*/
        WRITE_D(remove_from_all_folders(item));
        IFERR_REPORT(AOM_refresh(item, TRUE));

      //WRITE_L(is_object_referenced(item));

        IFERR_REPORT(AOM_lock_for_delete(item));
        IFERR_REPORT(ITEM_delete_item(item));

    } while (TRUE);
}

int ITK_user_main(int argc , char* argv[])
{
	int ifail = 0;	
	
	ITK_initialize_text_services(0);

	/*Login to Teamcenter*/
 
	ifail=login_TC();
	
	//serch_And_Print_Items();	
	
	
	int iITK = ITK_ok;
	
	tag_t Item =NULLTAG;
	
	char *item_name="Abbas";


	iITK=ITEM_find_item("000109",&Item);
	ITEM_ask_name2(Item, &item_name);	
	printf("\1-Name of Item :%s\n", item_name); 
	
	ITEM_delete_item(Item);
	ITK_exit_module(true);
	
	iITK=ITEM_find_item("000109",&Item);
	iITK=ITEM_ask_name2(Item, &item_name);
	
	
	printf("\2-Name of Item :%d\n", iITK);

	return(ifail);
}