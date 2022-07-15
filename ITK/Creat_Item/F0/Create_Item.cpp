#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#include <base_utils/Mem.h>

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

void printErrorMessage( char* sErrorMessage, int iITK);
void printErrorMessage( char* sErrorMessage, int iITK)
{
	if(iITK!=ITK_ok){
		
		EMH_ask_error_text( iITK, &sErrorMessage);
   
		 printf(sErrorMessage);

	    TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
	}
}

char* set_ItemId()
{
	char part_ID[133];
	
	TC_printf ("Enter Item ID: ");
	 
    scanf("%s", &part_ID);
	
	return part_ID;
}

char* set_ItemName()
{
	char part_name[133];
	
	TC_printf ("Enter Item name: ");
	 
    scanf("%s", &part_name);
	
	return part_name;
}

char* set_ItemDes()
{
	char part_Des[133];
	
	TC_printf ("Enter Item Description: ");
	 
    scanf("%s", &part_Des);
	
	return part_Des;
}

void CreatItem (const std::string Item_Id ,const std::string Item_name  ,const std::string item_description ){
	
	char* Id =(char*)Item_Id.c_str();	
	char* name =(char*)Item_name.c_str();	
	char* item_type ="Item";	
	char* sErrorMessage=nullptr;	
	char* description =(char*)item_description.c_str();
	char* rev_id ="A";
		
	int iITK = ITK_ok;
	
	tag_t Item =NULLTAG;	
	tag_t ItemRev =NULLTAG;	
		
	iITK=ITEM_create_item(Id,name,item_type,rev_id, &Item, &ItemRev);	
	
	iITK=ITEM_set_description(Item,description);	
	iITK=AOM_save_with_extensions(Item);
	
	printErrorMessage(sErrorMessage,  iITK);

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
	
	std::string name = "", itemId  = "", itemdes = "";	
	
	itemId  = set_ItemId();	
	name = set_ItemName();
	itemdes = set_ItemDes();
	
	CreatItem(itemId,name,itemdes);

	printf("Completely created");
	
	retcode =  ITK_exit_module(true);
    
    return EXIT_SUCCESS;
}
