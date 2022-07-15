/*HEAD SET_ITEM_REV_ATTACHMENTS_OWNER_AND_GROUP ITK */
#include<stdlib.h>

#include <sa/sa.h>

#include <ae/ae.h>
#include <ae/dataset.h>
#include <ae/datasettype.h>
#include <ae/nxsm.h>
#include <ecm/ecm.h>
#include <epm/epm.h>
#include <tc/folder.h>
#include <form/form.h>
#include <ict/ict_userservice.h>
#include <itk/mem.h>
#include <property/prop.h>
#include <property/prop_errors.h>
#include <property/prop_msg.h>
#include <stdarg.h>
#include <string.h>
#include <tc/emh.h>
#include <tc/emh_const.h>
#include <tc/tc.h>
#include <tccore/aom.h>
#include <tccore/aom_prop.h>
#include <tccore/custom.h>
#include <tccore/item.h>
#include <tccore/item_errors.h>
#include <tccore/method.h>
#include <tccore/tctype.h>
#include <tccore/workspaceobject.h>
#include <tcinit/tcinit.h>
#include <time.h>
#include <pom\enq\enq.h>
#include <fclasses/tc_date.h>

#include <tccore/grm.h>
#include <tccore/grmtype.h>

#define CALLAPI(expr)ITKCALL(ifail = expr); if(ifail != ITK_ok)return ifail;

#include<iostream>

#define EXIT_FAILURE 1
#define ITK_CALL(x) {           \
    int stat;                     \
    char *err_string;             \
    if( (stat = (x)) != ITK_ok)   \
    {                             \
    EMH_get_error_string (NULLTAG, stat, &err_string);                 \
    printf ("ERROR: %d ERROR MSG: %s.\n", stat, err_string);           \
    printf ("FUNCTION: %s\nFILE: %s LINE: %d\n",#x, __FILE__, __LINE__); \
    if(err_string) MEM_free(err_string);                                \
    exit (EXIT_FAILURE);                                                   \
    }                                                                    \
}

static void report_owner_and_group(tag_t object)
{
    WSO_description_t
        desc;
	WSOM_describe(object, &desc);
    printf("\n\tName: %s\tType: %s\n", desc.object_name, desc.object_type);
    printf("\t\tOwner: %s\tGroup: %s\n", desc.owners_name, desc.owning_group_name);
}

static void set_ownership(tag_t object, tag_t user, tag_t group)
{
	AOM_refresh(object, 1);
	
    printf("\nBefore calling AOM_set_ownership...");
    report_owner_and_group(object);
	AOM_set_ownership(object, user, group);
    
	AOM_save(object);
    
    printf("After calling AOM_set_ownership...");
    report_owner_and_group(object);
    
	AOM_unload(object);
}
 
static void do_it(void)
{
    int
        ii,
        count;
    char
        owner_name[SA_user_size_c + 1],
        group_name[SA_name_size_c + 1],
        item_name[ITEM_name_size_c +1];
    tag_t   
        item, 
        group,
        rev,
        user;

    ITEM_attached_object_t
        *objects;
            
    printf("\nEnter New Owner Name : ");
	scanf("%s", &owner_name);
	SA_find_user(owner_name, &user);
    
    printf("\nEnter New Group Name : ");
    gets(group_name);
	SA_find_group(group_name, &group);
	
    while (printf("\nEnter the item name : ") && gets(item_name) &&
        strlen(item_name))
    {
		ITEM_find_item(item_name, &item);
		
        set_ownership(item, user, group);
		ITEM_ask_latest_rev(item, &rev);
        set_ownership(rev, user, group);
		ITEM_list_all_rev_attachments(rev, &count, &objects);
        for (ii = 0; ii < count; ii++)
        {
            set_ownership(objects[ii].attachment, user, group);
        }
        if (objects) MEM_free(objects); 
    }      
}


int ITK_user_main(int argc, char* argv[])
{
    int
        status = 0; 
    char
        *message;
    
    ITK_initialize_text_services( 0 );
    status = ITK_auto_login();
   
    if (  (status != ITK_ok)) printf("iMAN login NOT successful.\n");
    else
    {
        printf("iMAN login successful.\n");
        ITK_set_journalling(TRUE);
        do_it();
    }
    ITK_exit_module(TRUE);
    return status;
}
