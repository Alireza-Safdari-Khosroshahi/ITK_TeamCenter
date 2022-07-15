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
#include <publication\ods_itk.h>

#include <fclasses/tc_basic.h>

#include <tccore/libtccore_exports.h>

using namespace std;

void deleteItem (const std::string Item_Id ){
	
	char* Id =(char*)Item_Id.c_str();
	
	char* sErrorMessage=nullptr;

	
	int iITK = ITK_ok;
	
	tag_t Item =NULLTAG;
	
	
	iITK=ITEM_find_item(Id,&Item);
	
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);
   
		 printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
	
	int a =000241;
	
	iITK=ODS_unpublish_object(a,Item);
	
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);
   
		 printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
	
	iITK=ITEM_delete_item(Item);
	
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);

         printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
	
	
	return;
}

int ITK_user_main(int argc , char* argv[]){
	
	int retcode = ITK_ok;
 	/* Function error return code */
  
	retcode = ITK_auto_login();
	
    if (retcode != ITK_ok){
        TC_printf ("Failed to login to Teamcenter using auto-login with ");
        TC_printf ("error code %d\n\n", retcode);
        return EXIT_FAILURE;
    }
	
	
	
	std::string itemId  = "000241";

	deleteItem(itemId);
	
	printf("Completely deleted");
	
	retcode =  ITK_exit_module(true);
    
    return EXIT_SUCCESS;
}