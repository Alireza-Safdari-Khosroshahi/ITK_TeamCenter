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
#include <tccore/grmtype.h>

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
 
 static tag_t* get_and_Print_all_Item_Revision(tag_t item_tag)
{
	int  rev_count = 0;     		 /**< (O) Number of bom view found for the Item */
	int secondaryobjectcount  = 0;

    tag_t *rev_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	tag_t *secondary_objects  = NULLTAG;
	tag_t objTypeTag    = NULLTAG;
	
	tag_t new_user = NULLTAG;
	tag_t new_group = NULLTAG;
	
	char *object_type = NULL;  
	
	char *objectname = NULL;
	char *current_revision_id = NULL;

	int j = 0;

	if (ITEM_list_all_revs (item_tag, &rev_count, &rev_list)== ITK_ok)
		{
			char* Current_userID = "rezaei";
			char* new_groupName = "Digitales Produkt";
			//Digitales Produkt
			
			printf("-->>> num of Revision : %d \n", rev_count); 	
			for (int k = 0; k < rev_count; k++ )      
				{		
					if (AOM_ask_value_string(rev_list[k],"current_revision_id",&current_revision_id)!= ITK_ok )PrintErrorStack();
					printf("-->>> Revision Name: %s \n", current_revision_id); 					
					
					
					GRM_list_secondary_objects_only (rev_list[k],NULLTAG,&secondaryobjectcount,&secondary_objects);
					printf("Dataset count is: %d \n",secondaryobjectcount);
					
					/*
					for(int datasetcount=0;datasetcount<secondaryobjectcount;datasetcount++)
					{
						if (TCTYPE_ask_object_type(secondary_objects[datasetcount],&objTypeTag)!=ITK_ok)PrintErrorStack();
						if (TCTYPE_ask_name2(objTypeTag,&objectname)!=ITK_ok)PrintErrorStack();
						printf("type_name is: %s \n",objectname); 
						
						changeOwnership(secondary_objects[datasetcount], new_user, new_group));
						SA_find_user2(Current_userID, &new_user);
						SA_find_group(new_groupName, &new_group);
	
						printf("\n Name of Item by AOM_set_ownership:%d \n", AOM_set_ownership();			
						 
						
						
					}
					
					*/
					
					
					
				}
		}
						
    return rev_list;
}

static tag_t* get_and_Print_all_Item_BOM(tag_t item_tag)
{
	int  bv_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *bv_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;

	

		if (ITEM_list_bom_views (item_tag, &bv_count, &bv_list)== ITK_ok)
			{
				printf("-->>> num of BOM view : %d \n", bv_count);
			}
						
    return bv_list;
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

static tag_t ask_secondary_of_an_Object(tag_t primary_object)
{
    int
        count = 0;
    tag_t
        relation = NULLTAG,
       
        item_tag = NULLTAG;
		
	GRM_relation_t
				 *secondary_objects;

	char *objectname = NULL;
	
	//if (GRM_find_relation_type(relation_type_name, &relation)!= ITK_ok )PrintErrorStack();	
	
	/**
    Returns a list and count of all secondary objects with a
    specified relation type to the specified primary object.
	*/
	
	if (GRM_list_secondary_objects(primary_object, NULLTAG,
        &count, &secondary_objects)!= ITK_ok )PrintErrorStack();	

    /* should always be just one */
	
    //item_tag = secondary_objects[0];

    //if (secondary_objects) MEM_free(secondary_objects);
	
	if (AOM_ask_value_string(item_tag,"object_name",&objectname)!= ITK_ok )PrintErrorStack();

	printf("-->>> Secondry Object Name: %s \n", objectname);	
	
	
    return item_tag;
}

int login_TC ()
{	
	int retcode=ITK_ok; 	

	printf("Please enter with this template: -u=**** -p=*** -g=*** -itemype=***, -ouo=**** -ogo=*** -oun=*** -ogn=***");
	
	const char* userid =ITK_ask_cli_argument("-u=");
	const char* password = ITK_ask_cli_argument("-p=");
	const char* group = ITK_ask_cli_argument("-g=");
	const char* mode = ITK_ask_cli_argument("-m=");
	const char *itemType = ITK_ask_cli_argument("-itemype=");
	const char *old_Owning_User = ITK_ask_cli_argument("-ouo=");
	const char *old_Owning_Group = ITK_ask_cli_argument("-ogo=");
	const char *new_Owning_User = ITK_ask_cli_argument("-oun=");
	const char *new_Owning_Group = ITK_ask_cli_argument("-ogn=");
	
	
	int ifail=0;
	
	ITK_init_module(userid, password, group);
	
	if(ifail !=ITK_ok) 
	printf("iMAN login NOT sucessfull.\n");

	return ifail;
    
	printf("Teamcenter login sucessfull.\n");
	
	printf("You enterd: itemType: %s, old_Owning_User: %s, old_Owning_Group: %s, new_Owning_User: %s, new_Owning_Group: %s .\n", itemType, old_Owning_User, old_Owning_Group,  new_Owning_User, new_Owning_Group);
	
	  
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

void changeOwnership(tag_t item, char* Current_userID, char* new_groupName)
{ 
	tag_t new_user = NULLTAG;
	tag_t new_group = NULLTAG;
	
	SA_find_user2(Current_userID, &new_user);
	SA_find_group(new_groupName, &new_group);
	
	//printf("\n Name of Item by AOM_set_ownership:%d\n", AOM_set_ownership(item, new_user, new_group));		
	
}

void  do_it ()
{ 
	int nItems = 0;	
	tag_t *items = NULLTAG;	
	
	char *objectname = NULL;
	
	char *userId = NULL;
	char *password = NULL;	
	char *group = NULL;
	char *itemType = NULL;
	char *old_Owning_User = NULL;
	char *old_Owning_Group = NULL;
	char *new_Owning_User = NULL;
	char *new_Owning_Group = NULL;
	char *errormsg = NULL;
	char *object_type = NULL;  
	
	int istatus = ITK_ok;
	int n_item = 0;
	int iFail = ITK_ok;	
	int numOfParts = 1;
	
    tag_t *bv_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */	
    tag_t *rev_list = NULL;     /**< ( count Tag list of all the revisions of the Item */
	tag_t *item_tags = NULLTAG;
	tag_t titem_rev = NULLTAG;
	tag_t towning_user = NULLTAG;	
	tag_t master_form = NULLTAG;	
	tag_t iman_manifestation = NULLTAG;	
	
	userId = ITK_ask_cli_argument( "-u" );
	password = ITK_ask_cli_argument( "-p" );
	group = ITK_ask_cli_argument( "-g" );
	
	
	userId++;password++;group++;

	if( (!userId) || (!password) ||(!group))
	{
		printf("\n\n\t\t Enter -u=? -p=? -g=?");
		exit(0);
	} 
	
	 /*Initializing the text services */

   //istatus = ITK_init_module( userId , password , group );
	
	//istatus = ITK_init_module("infodba","infodba","dba");

	if ( istatus != ITK_ok)
	{
		EMH_ask_error_text( istatus, &errormsg);
		printf("Error with ITK_init_module: %s \n",errormsg);
		MEM_free(errormsg);
		return ;
	}
	
	istatus = Get_Items(&n_item, &item_tags);
	
	if ( istatus ==  ITK_ok )
        {
			printf("\n--->> Login successful.... ? <<<----- \n\n");

			if ( n_item > 0 )
			{				
				for ( int i = 0; i < n_item; i++ )      
				{
					if (WSOM_ask_object_type2((item_tags)[i],&object_type)!= ITK_ok )PrintErrorStack();

					if (strcmp (object_type , "Part") == 0)
					{
						if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
						
						printf("%d: Name: %s, Type: %s \n", numOfParts, objectname, object_type); 
						numOfParts++; 
						
						/**
							Change Owninggroup of  all the BOM Views related to the Item.
						*/		
						
						bv_list = get_and_Print_all_Item_BOM (item_tags[i]);
						/**
							Retrieves all the Item Revisions attached to a specified Item.
						*/						
						rev_list = get_and_Print_all_Item_Revision(item_tags[i]);	
						for (int  j = 0; j < sizeof(rev_list); j++ )      
						{		
							if (AOM_ask_value_string(bv_list[j],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
							printf("-->>> BOM view Name: %s \n", objectname);
							
							changeOwnership(bv_list[j], userId, new_Owning_Group);
							
						}								
						/**
							Retrieves the Item Master form type of an Item type.
						*/						
						
						//master_form =  ask_secondary_of_an_Object("IMAN_Rendering", item_tags[i]);
						
							
					}	
				}
			}
		}
	/*
	ITEM_find_items_by_key_attributes(1,names,values,&nItems,&items );
	
	for (int i = 0; i < nItems; i++)
	{
		changeOwnership(items[i], Current_userID, new_group_name);
		
	}
	
	if(items != NULLTAG) MEM_free(items);
		ITK_exit_module(TRUE);
		*/
}

int ITK_user_main(int argc , char* argv[])
{
	int ifail = 0;	
	
	ITK_initialize_text_services(0);
 
	ifail=login_TC();
	
	do_it();	
		
	return(ifail);
}