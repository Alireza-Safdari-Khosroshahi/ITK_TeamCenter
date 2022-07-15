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

#include <tcinit/tcinit.h>
#include <nls/nls.h>
#include <iostream>
#include <ps/ps.h>
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

#define CALLAPI(expr)ITKCALL(ifail = expr); if(ifail != ITK_ok)return ifail; 

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
 
int login_TC ()
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

 int Get_Items (int *nFound, tag_t** foundTags)
{

    /* Add select attributes. We want the uids of the workspace

	objects so we can load them: */
	const char *select_attrs[]  = {"puid"};


	const char *name[] = {"Item"};
	char *enqid      = "find_wso_by_type";
	char *value_prop    = NULL;
	char *object_type    = NULL;

	int i;
	int n_rows, n_cols;

	void ***values;

	if (POM_enquiry_create (enqid)!= ITK_ok )PrintErrorStack();
	if (POM_enquiry_add_select_attrs (enqid,"Item", 1,select_attrs)!= ITK_ok )PrintErrorStack();
	
	/* Add any attribute expressions. We need two of them – one
	for the value we are given and another for the attribute we are
	testing against: */
	
	POM_enquiry_set_string_value (enqid, "test",1,name, POM_enquiry_bind_value );
	POM_enquiry_set_attr_expr (enqid, "expr1","workspaceobject", "object_type",POM_enquiry_equal, "test" );
	POM_enquiry_set_where_expr (enqid, "expr1");

	/* Now execute the query: */

	if ( POM_enquiry_execute (enqid, &n_rows, &n_cols,&values)!= ITK_ok ) PrintErrorStack();
	printf ("Number of Item object found : %d\n", n_rows );
	
	if ( n_rows != 0 )
        {
			*foundTags = (tag_t *)MEM_alloc ( n_rows * sizeof( tag_t ));
			*nFound = n_rows;

		for ( i =0 ; i < (*nFound) ; i++ )
          {
			(*foundTags )[i] = *((tag_t *)values[i][0]);
			
			
			if (AOM_ask_value_string((*foundTags )[i],"object_name",&value_prop)!= ITK_ok )PrintErrorStack();
			printf("object name is: %s \n",value_prop); 
			
			if (WSOM_ask_object_type2((*foundTags )[i],&object_type)!= ITK_ok )PrintErrorStack();
		
			printf("object type is: %s \n",object_type);
			
			}

		}
		
	if ( POM_enquiry_delete("find_wso_by_type")!= ITK_ok ) PrintErrorStack();
	MEM_free( values );

    return 0;
}


void changeOwnership(tag_t item, char* new_userID, char* new_groupName)
{ 
	tag_t new_user = NULLTAG;
	tag_t new_group = NULLTAG;
	
	SA_find_user2(new_userID, &new_user);
	SA_find_group(new_groupName, &new_group);
	
	printf("\Name of Item by AOM_set_ownership:%d\n", AOM_set_ownership(item, new_user, new_group));		
	
}

void  do_it ()
{ 
	const char
        *names[2] = { "item_id" },
        *values[2] = { "000303" };
		
	char* new_userID = "rezaei";
	char* new_group_name = "Produktentwicklung";

	int nItems = 0;	
	tag_t *items = NULLTAG;	
	
	ITEM_find_items_by_key_attributes(1,names,values,&nItems,&items );
	
	for (int i = 0; i < nItems; i++)
		changeOwnership(items[i], new_userID, new_group_name);
	
	
	if(items != NULLTAG) MEM_free(items);
		ITK_exit_module(TRUE);
}

int ITK_user_main(int argc , char* argv[])
{
	int ifail = 0;	
	
	ITK_initialize_text_services(0);
 
	ifail=login_TC();
	
	do_it();	
		
	return(ifail);
}