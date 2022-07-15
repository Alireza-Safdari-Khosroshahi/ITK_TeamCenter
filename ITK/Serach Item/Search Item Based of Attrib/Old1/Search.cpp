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
#define ERROR_CHECK(X) (report_error( __FILE__, __LINE__, #X, (X)))

using namespace std;

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
	//ERROR_CHECK(ITEM_find_items_by_key_attributes(1,names,values,&nItems,&items ));
	
	for (int i = 0; i < nItems; i++)
	{	
		ITEM_ask_name2(items[i], &item_name);

		printf("\Name of Item :%s\n", item_name);
	}
	
	printf("no of items = [%d]\n", nItems);
	if(items != NULLTAG) MEM_free(items);
		ITK_exit_module(TRUE);
}
	
int ITK_user_main(int argc , char* argv[])
{
	int ifail = 0;	
	
	ITK_initialize_text_services(0);

	/*Login to Teamcenter*/
 
	ifail=login_TC();
	
	serch_And_Print_Items();	
		
	return(ifail);
}