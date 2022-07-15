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
#include <sa/tcfile.h>
#include <sa/user.h>
#include <sa/group.h>

#include <tccore/grm.h>
#include <tccore/grmtype.h>

#define CALLAPI(expr)ITKCALL(ifail = expr); if(ifail != ITK_ok)return ifail;



#include<iostream>

using namespace std;
int nItems = 5;


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
 

int serch_User_and_group (char * userId, char * groupname, tag_t *items)
{
	int find = 0;
	int i = 0;
	
	
	
	for  (i = 0; items[i] != NULLTAG; i++)
	{
		
	}
   
   printf ("Num of Items Type ---------%d \n",  i);
	tag_t user = NULLTAG;	
	
	char* person = "person";
	
	//printf ("Enterd User ID:   %s \n" , userId);
	
	
	
	//SA_ask_user_person_name2(user, &person);
	
	if (  SA_find_user2("rezaei", &user)!= ITK_ok ) PrintErrorStack();
	
	
	
	printf ("SA_find_user2 : %d \n", find);
	
	if(user != NULLTAG)
		find = 1;
	else 
		find = 0;
	
		
	return find;
}

int serch_group (char * groupname)
{
	int find = 0;
	
	tag_t group =  NULLTAG;
    SA_find_group("dba", &group);
	
	
	//tag_t group = NULLTAG;
	printf ("Group name %s \n",groupname);
	
	if (SA_find_group(groupname, &group)!= ITK_ok ) PrintErrorStack();
	
	
	SA_find_group(groupname, &group);
	
	
	
	char* groupname2 = "Abbas";
	 SA_ask_group_name2(group, &groupname2);
	printf ("Group name %s \n",groupname2);
	
	if(group == NULLTAG)
		find = 0;
	else 
		find = 1;
	
		
	return find;
}


tag_t* serch_Item_Type (char * itemType)
{
	tag_t *items = NULLTAG;
	
	char *item_name="test";
	const char
        *names[1] = { "object_type"},
        *values[1] = {itemType};	
	
	ITEM_find_items_by_key_attributes(1,names,values,&nItems,&items );	
	
		
	if(items != NULLTAG) MEM_free(items);
		ITK_exit_module(TRUE);
		
	return items;
}

int Get_Items (int *nFound, tag_t** foundTags)
{

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

	if ( POM_enquiry_execute (enqid, &n_rows, &n_cols,&values)!= ITK_ok ) PrintErrorStack();

	if ( n_rows != 0 )
        {
			*foundTags = (tag_t *)MEM_alloc ( n_rows * sizeof( tag_t ));
			*nFound = n_rows;

		for ( i =0 ; i < (*nFound) ; i++ )
			(*foundTags )[i] = *((tag_t *)values[i][0]);
		}
		
	if ( POM_enquiry_delete("find_wso_by_type")!= ITK_ok ) PrintErrorStack();
	MEM_free( values );

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

	/**
		Retrieves all the Item Revisions attached to a specified Item.
	*/
	
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
			char* new_userID = "rezaei";
			char* new_groupName = "Digitales Produkt";
			//Digitales Produkt
			
			printf("-->>> num of Revision : %d \n", rev_count); 	
			for (int k = 0; k < rev_count; k++ )      
				{		
					if (AOM_ask_value_string(rev_list[k],"current_revision_id",&current_revision_id)!= ITK_ok )PrintErrorStack();
					printf("-->>> Revision Name: %s \n", current_revision_id); 					
					
					
					GRM_list_secondary_objects_only (rev_list[k],NULLTAG,&secondaryobjectcount,&secondary_objects);
					printf("Dataset count is: %d \n",secondaryobjectcount);
					
					
					for(int datasetcount=0;datasetcount<secondaryobjectcount;datasetcount++)
					{
						if (TCTYPE_ask_object_type(secondary_objects[datasetcount],&objTypeTag)!=ITK_ok)PrintErrorStack();
						if (TCTYPE_ask_name2(objTypeTag,&objectname)!=ITK_ok)PrintErrorStack();
						printf("type_name is: %s \n",objectname); 
						
						
						
	
						SA_find_user2(new_userID, &new_user);
						SA_find_group(new_groupName, &new_group);
	
						printf("\n Name of Item by AOM_set_ownership:%d \n", AOM_set_ownership(secondary_objects[datasetcount], new_user, new_group));			
						 
						
						
					}
					
					
					
					
					
				}
		}
						
    return rev_list;
}

static tag_t* get_and_Print_all_Item_BOM(tag_t item_tag)
{
	int  bv_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *bv_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;

	int j = 0;

		if (ITEM_list_bom_views (item_tag, &bv_count, &bv_list)== ITK_ok)
			{
				printf("-->>> num of Bome view : %d \n", bv_count); 	

				for (int  j = 0; j < bv_count; j++ )      
				{		
					if (AOM_ask_value_string(bv_list[j],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
						printf("-->>> Bom view Name: %s \n", objectname);
				}
			}
						
    return bv_list;
}

int check_availability (char *itemType,char *old_Owning_User,char *old_Owning_Group,char *new_Owning_User, char *new_Owning_Group)
{	
	
	int ifail = 1;
	tag_t *items =serch_Item_Type(itemType); 
	
	serch_User_and_group(old_Owning_User, old_Owning_Group, items);
	
	
	if (sizeof(items) > 0)
		printf ("Artikeltyp wurde gefunden. \n");
	else 
		printf ("Artikeltyp wurde nicht gefunden. \n");
	//int a = sizeof(items);
	//printf("Num of item -------: %d \n", a);
	//if (serch_User(old_Owning_User) == 1)
		//printf ("old_Owning_User wurde gefunden. \n");
	//else 
//printf ("old_Owning_User wurde nicht gefunden. \n");
	
	if (serch_group(old_Owning_Group) == 1)
		printf ("old_Owning_Group wurde gefunden. \n");
	else 
		printf ("old_Owning_Group wurde nicht gefunden. \n");
	/*
	
	if (serch_User(new_Owning_User) == 1)
		printf ("new_Owning_User wurde gefunden. \n");
	else 
		printf ("new_Owning_User wurde nicht gefunden. \n");
	
	if (serch_group(new_Owning_Group) == 1)
		printf ("new_Owning_Group wurde gefunden. \n");
	else 
		printf ("new_Owning_Group wurde nicht gefunden. \n");
	*/
	return ifail;	
}

 int login_TC ()
{	
	int retcode=ITK_ok; 	
	
	const char* userid =ITK_ask_cli_argument("-u=");
	const char* password = ITK_ask_cli_argument("-p=");
	const char* group = ITK_ask_cli_argument("-g=");
	
	int ifail=0;
	
	if( (!userid) || (!password) ||(!group) )
	{
		printf("\n\n\t\t Enter -u=? -p=? -g=?");
		exit(0);
	} 
	
	ifail = ITK_init_module(userid, password, group);
	
	if(ifail !=ITK_ok) 
	printf("iMAN login NOT sucessfull.\n");

	printf("Teamcenter login sucessfull.\n");

	 char *itemType = ITK_ask_cli_argument("-itemtype=");
	 char *old_Owning_User = ITK_ask_cli_argument("-oou");
	 char *old_Owning_Group = ITK_ask_cli_argument("-oog=");
	 char *new_Owning_User = ITK_ask_cli_argument("-nou=");
	 char *new_Owning_Group = ITK_ask_cli_argument("-nog=");
	
	
	if((!itemType) || (!old_Owning_User)  || (!old_Owning_Group) || (!new_Owning_User) || (!new_Owning_Group) )
	{		
		printf("\n\n\t\t Enter: -itemype=? -oou=? -oog=? -nou=? -nog=?");
		exit(0);
	} 
	
	check_availability (itemType,old_Owning_User,old_Owning_Group,new_Owning_User,new_Owning_Group );
	//printf("You Entered: itemType: %s, old_Owning_User: %s, old_Owning_Group: %s, new_Owning_User: %s, new_Owning_Group: %s .\n", itemType, old_Owning_User, old_Owning_Group,  new_Owning_User, new_Owning_Group);

	
	//int check_item_type_avalibility = serch_Item_Type(itemType);
	
	
	

	return ifail;	
	  
}


 extern int ITK_user_main( int argc, char **argv )
{
	char *objectname = NULL;
	char *userId = NULL;
	char *password = NULL;
	char *group = NULL;
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
	
	
	AE_reference_type_t     reftype;
       (void)argc;
       (void)argv;	
	

	
	 /*Initializing the text services */

    istatus = login_TC();

	
	return NULL;
}