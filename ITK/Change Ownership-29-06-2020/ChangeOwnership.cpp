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
#include <sa/user.h>
#include <sa/group.h>
#define ERROR_CHECK(X) (report_error( __FILE__, __LINE__, #X, (X)))

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
 
int  login_TC ()
{	
	int retcode=ITK_ok; 	

	
	const char* userid =ITK_ask_cli_argument("-u=");
	const char* password = ITK_ask_cli_argument("-p=");
	const char* group = ITK_ask_cli_argument("-g=");
	const char* mode = ITK_ask_cli_argument("-m=");
	const char* prj_id = ITK_ask_cli_argument("-prj_id=");
	int ifail=0;
	
	ITK_init_module(userid, password, group);
	
	if(ifail !=ITK_ok) 
	{printf("iMAN login NOT sucessfull.\n"); return ifail;}	
    
	printf("Teamcenter login sucessfull.\n");
	  
}
	
void  serch_And_Print_Items ()
{
	char *item_name="Abbas";
	const char
        *names[2] = { "item_id" },
        *values[2] = { "000276" };

	int nItems = 0;	
	tag_t *items = NULLTAG;
	tag_t owning_user = NULLTAG;
	tag_t owning_group = NULLTAG;
	
	tag_t new_user = NULLTAG;
	tag_t new_group = NULLTAG;
	
	
	
	ITEM_find_items_by_key_attributes(1,names,values,&nItems,&items );
	
	for (int i = 0; i < nItems; i++)
	{	
		AOM_ask_name(items[i], &item_name);
		
		printf("\Name of Item by AOM_ask_name:%s\n", item_name);
		
		AOM_ask_owner(items[i], &owning_user);
		
		AOM_ask_name(owning_user, &item_name);
		
		printf("\Name of Item by AOM_ask_owner:%s\n", item_name);
		
		AOM_ask_group(items[i], &owning_group);
		
		AOM_ask_name(owning_group, &item_name);
		
		printf("\Name of Item by AOM_ask_group:%s\n", item_name);
		
		
		
		
		char* new_userID = "rezaei";
		SA_find_user2(new_userID, &new_user);
		
		AOM_ask_name(new_user, &item_name);		
		printf("\Name of Item by SA_find_user2:%s\n", item_name);
		
		
		
		char* new_group_name = "Produktentwicklung";
		SA_find_group(new_group_name, &new_group);
		
		AOM_ask_name(new_group, &item_name);		
		printf("\Name of Item by SA_find_group:%s\n", item_name);
	
		printf("\Name of Item by AOM_set_ownership:%d\n", AOM_set_ownership(items[i], new_user, new_group));
		
		
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