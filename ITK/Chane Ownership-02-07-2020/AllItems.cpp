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

static tag_t ask_secondary_of_an_Object(char* relation_type_name, tag_t primary_object)
{
    int
        n_secondary_object_tags = 0;
    tag_t
        relation = NULLTAG,
        *secondary_object_tags = NULL,
        item_tag = NULLTAG;

	char *objectname = NULL;
	
	if (GRM_find_relation_type(relation_type_name, &relation)!= ITK_ok )PrintErrorStack();	
	
	/**
    Returns a list and count of all secondary objects with a
    specified relation type to the specified primary object.
	*/
	
	if (GRM_list_secondary_objects_only(primary_object, relation,
        &n_secondary_object_tags, &secondary_object_tags)!= ITK_ok )PrintErrorStack();	

    /* should always be just one */
	
    item_tag = secondary_object_tags[0];

    if (secondary_object_tags) MEM_free(secondary_object_tags);
	
	if (AOM_ask_value_string(item_tag,"object_name",&objectname)!= ITK_ok )PrintErrorStack();

	printf("-->>> Secondry Object Name: %s , with Relation: %s \n", objectname, relation_type_name);	
	
	
    return item_tag;
}


	/**
		Retrieves all the Item Revisions attached to a specified Item.
	*/
	
static tag_t* get_and_Print_all_Item_Revision(tag_t item_tag)
{
	int  rev_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *rev_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;

	int j = 0;

	if (ITEM_list_all_revs (item_tag, &rev_count, &rev_list)== ITK_ok)
		{
			printf("-->>> num of Revision : %d \n", rev_count); 	
			for (int k = 0; k < rev_count; k++ )      
				{		
					if (AOM_ask_value_string(rev_list[k],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
					printf("-->>> Revision Name: %s \n", objectname); 
							
					//if (AOM_ask_value_string(ask_master_form_of_an_Object("IMAN_master_form", rev_list[k]),"object_name",&objectname)!= ITK_ok )PrintErrorStack();
					//printf("-->>> Revision Item Master Name: %s \n", objectname); 
					//ask_master_form_of_an_Object("IMAN_manifestation", rev_list[k]);
					
					ask_secondary_of_an_Object("IMAN_Rendering", rev_list[k]);
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
	int numOfParts = 0;
	
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
	
	userId = ITK_ask_cli_argument( "-u" );
	password = ITK_ask_cli_argument( "-p" );
	group = ITK_ask_cli_argument( "-g" );
	
	userId++;password++;group++;	

	if( (!userId) || (!password) ||(!group) )
	{
		printf("\n\n\t\t Enter -u=? -p=? -g=?");
		exit(0);
	} 
	
	 /*Initializing the text services */

    istatus = ITK_init_module( userId , password , group );
	
	//istatus = ITK_init_module("infodba","infodba","dba");

	if ( istatus != ITK_ok)
	{
		EMH_ask_error_text( istatus, &errormsg);
		printf("Error with ITK_init_module: %s \n",errormsg);
		MEM_free(errormsg);
		return istatus;
	}
	
	istatus = Get_Items(&n_item, &item_tags);
	
	printf("login status %d /n", iFail);
	
	if ( istatus ==  ITK_ok )
        {
			printf(" Login successful.... ?\n");

			if ( n_item > 0 )
			{
				printf("login status %d /n", iFail);	
				for ( int i = 0; i < n_item; i++ )      
				{
					if (WSOM_ask_object_type2((item_tags)[i],&object_type)!= ITK_ok )PrintErrorStack();

					if (strcmp (object_type , "Part") == 0)
					{
						if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
						
						printf("%d: Name: %s, Type: %s \n", numOfParts, objectname, object_type); 
						numOfParts++; 
						
						/**
							Retrieves all the BOM Views related to the Item.
						*/										
						bv_list = get_and_Print_all_Item_BOM (item_tags[i]);
						/**
							Retrieves all the Item Revisions attached to a specified Item.
						*/						
						rev_list = get_and_Print_all_Item_Revision(item_tags[i]);						
						/**
							Retrieves the Item Master form type of an Item type.
						*/						
						
						//master_form =  ask_secondary_of_an_Object("IMAN_Rendering", item_tags[i]);
					}
				}				
				printf("\nNumber of Part object found : %d \n\n", --numOfParts);
			}
		}
	return NULL;
	}	
	
	