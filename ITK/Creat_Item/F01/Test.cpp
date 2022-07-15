#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#include <itk/mem.h>
#include <unidefs.h>
#include <tcinit/tcinit.h>
#include <tccore/item.h>
#include <pom/pom/pom.h>
#include <ps/ps.h>
#include <tccore/workspaceobject.h>
#include <ae/ae.h>
#include <sa/tcfile.h>
#include <string.h>
#include <fclasses/tc_string.h>
#include <fclasses/tc_date.h>
#include <tc/emh.h>
#include <tc/tc_util.h>
#include <tccore/aom.h>
#include <nls/nls.h>
#include <iostream>
#include <tc/tc.h>
#include <tccore/item.h>
#include <tccore/aom_prop.h>
#include <tie\tie.h>
#include <error_decode.h>

using namespace std;

void CreatItem (const std::string Item_Id ,const std::string Item_name  ,const std::string item_description ){
	
	char* Id =(char*)Item_Id.c_str();
	
	char* name =(char*)Item_name.c_str();
	
	char* item_type ="Item";
	
	char* sErrorMessage=nullptr;
	
	char* description =(char*)item_description.c_str();
	
	int iITK = ITK_ok;
	
	tag_t Item =NULLTAG;
	
	char* rev_id ="A";
	
	tag_t ItemRev =NULLTAG;
	
	// Item is created with the following Parameters 
	
	iITK=ITEM_create_item(Id,name,item_type,rev_id, &Item, &ItemRev);
	
	// we add another Property call description to the Item
	
	
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);
   
		 printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
	
	iITK=ITEM_set_description(Item,description);
	
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);

         printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
	
	iITK=AOM_save_with_extensions(Item);
	
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);

         printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
	return;
}

int ITK_user_main(int argc , char* argv[]){
	
	int retcode = ITK_ok;

	retcode = ITK_auto_login();
	
    if (retcode != ITK_ok){
		
        TC_printf ("Failed to login to Teamcenter using auto-login with ");
        TC_printf ("error code %d\n\n", retcode);
        return EXIT_FAILURE;
    }
	
	std::string name ="F01";
	std::string itemId  = "000261";
	std::string itemdescription  = "The ITK Programm";
	
	CreatItem(itemId,name,itemdescription);
	
	printf("Completely created");
	
	retcode =  ITK_exit_module(true);
    
    return EXIT_SUCCESS;
}