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

static void report_owner_and_group(tag_t object)
{
    WSO_description_t
        desc;
	WSOM_describe(object, &desc);
    printf("\n\tName: %s\tType: %s\n", desc.object_name, desc.object_type);
    printf("\t\tOwner: %s\tGroup: %s\n", desc.owners_name, desc.owning_group_name);
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


static void set_ownership(tag_t object, tag_t user, tag_t group)
{
	AOM_refresh(object, 1);
    
    //printf("\nBefore calling AOM_set_ownership...");
   // report_owner_and_group(object);
    
    AOM_set_ownership(object, user, group);
    AOM_save(object);
    
    //printf("After calling AOM_set_ownership...");
    //report_owner_and_group(object);
    
    AOM_unload(object);  
}

	/**
		Retrieves and Prints all the Item Revisions attached to a specified Item.
	*/
	
static tag_t* get_and_Set_Owner_of_all_Item_Revision(tag_t item_tag,tag_t user, tag_t group)
{
	int  rev_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *rev_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;
	tag_t objTypeTag    = NULLTAG;
	int j = 0;
	
	int secondaryobjectcount  = 0;
	int referencenumberfound  = 0;
	tag_t *secondary_objects  = NULLTAG;
	char *type_name[TCTYPE_name_size_c+1];
	
	char *current_item_type = NULL;

	if (ITEM_list_all_revs (item_tag, &rev_count, &rev_list)== ITK_ok)
		{
			printf("-->>> num of Revision : %d \n", rev_count); 	
			for (int k = 0; k < rev_count; k++ )      
				{		
					//set_ownership(rev_list[k],user, group);
					
					//ask_master_form_of_an_Object("IMAN_manifestation", rev_list[k]);
					
					ask_secondary_of_an_Object(rev_list[k]);
					GRM_list_secondary_objects_only (rev_list[k],NULLTAG,&secondaryobjectcount,&secondary_objects);
					printf("Dataset count is:%d\n",secondaryobjectcount);
					
					
					for(int datasetcount=0;datasetcount<secondaryobjectcount;datasetcount++)
					{
						if (TCTYPE_ask_object_type(secondary_objects[datasetcount],&objTypeTag)!=ITK_ok)PrintErrorStack();
						//if (WSOM_ask_object_type2(objTypeTag ,&current_item_type)!= ITK_ok)PrintErrorStack();
						printf("type_name is: %s\n",current_item_type);  
						/*
						if( (strcmp(type_name,"UGMASTER") == 0)|| (strcmp(type_name,"MSExcelX") ==0 ) || (strcmp(type_name,"DirectModel") == 0 ) )
						{
							if (AE_ask_dataset_ref_count(secondary_objects[datasetcount],&referencenumberfound)!=ITK_ok)PrintErrorStack();
							if ( referencenumberfound > 0 )
							{
								AOM_ask_name (secondary_objects[datasetcount],&datasetname);
								fprintf (out_Datasefile_fp , "%s,%s,%s,", objectname,revisionid,datasetname);

								for ( int j=0;j<referencenumberfound;j++ )
								{

									strcpy(orig_name,"");
									strcpy(path_name,"");
									strcpy(relative_path,"");

									if (AE_find_dataset_named_ref(secondary_objects[datasetcount],j,refname,&reftype,&refobject)!=ITK_ok)PrintErrorStack();
									printf("reftype is: %s \n",reftype);  
									printf("refname is: %s \n",refname);  
									
									if(strcmp(refname,"UGPART-ATTR")!=0)
									{
									if ( IMF_ask_original_file_name(refobject,orig_name)!=ITK_ok)PrintErrorStack();
									printf("\n orig_name is :%s\n",orig_name);   

									if(IMF_ask_file_pathname(refobject,SS_WNT_MACHINE,path_name)!=ITK_ok)PrintErrorStack();
									printf("\n path_name is :%s\n",path_name); 

									fprintf (out_Datasefile_fp , "%s,%s\n" , orig_name,path_name );
									//
									}
								}
							}
						}*/
					}
					
					
					
					
					
					
					
				}
		}						
    return rev_list;
}

char* trim_user_id (char* complete_name)
{
	char* user_ID = complete_name;
	int init_size = strlen(complete_name);
	char delim[] = "()";

	char *ptr = strtok(complete_name, delim);	
	char *temp_ptr = ptr;
	
	while(ptr != NULL)
	{	
		temp_ptr = ptr;
		ptr = strtok(NULL, delim);
		if (ptr == NULL)
			user_ID = temp_ptr;
	}
	
	return user_ID;
}

char* strings_trim (char* word)
{
	char* trimed_word = word;
	int init_size = strlen(word);
	char delim[] = "=";

	char *ptr = strtok(word, delim);	
	char *temp_ptr = ptr;
	
	while(ptr != NULL)
	{		
		temp_ptr = ptr;
		ptr = strtok(NULL, delim);
		if (ptr == NULL)
			trimed_word = temp_ptr;
	}	
	
	return trimed_word;
}

/**
    Retrieves and Prints all the BOM Views related to the Item.
*/

static tag_t* get_and_Set_Owner_of_all_Item_BOM(tag_t item_tag, tag_t user, tag_t group)
{
	int  bv_count = 0;     		 /**< (O) Number of bom view found for the Item */
    tag_t *bv_list = NULL;		/**< (OF) count Tag list of all the bom views for the Item */
	char *objectname = NULL;

	int j = 0;

		if (ITEM_list_bom_views (item_tag, &bv_count, &bv_list)== ITK_ok)
			{
				for (int  j = 0; j < bv_count; j++ )      
				{	
					set_ownership(bv_list[j],user, group);	
				}
			}						
    return bv_list;
}
 
 /*
	
	Check that the item type, the owner of the user and the owner group have been entered 
	
 */
 int check_initial_vlues(tag_t item, char *itemType, char *old_Owning_User,char *old_Owning_Group)
 {
	int ifail = 0;
	
	char *current_item_type = NULL;	
	if (WSOM_ask_object_type2(item ,&current_item_type)!= ITK_ok )PrintErrorStack();
	
	char *current_owning_user = NULL;
	if (AOM_UIF_ask_value(item, "owning_user", &current_owning_user)!= ITK_ok )PrintErrorStack();
	 	
	char *current_owning_group = NULL;		
	if (AOM_UIF_ask_value(item, "owning_group", &current_owning_group)!= ITK_ok )PrintErrorStack();	
	
	if ((strcmp (strings_trim (itemType) , current_item_type) == 0) && (strcmp (strings_trim (old_Owning_User) , trim_user_id(current_owning_user)) == 0)  && (strcmp (current_owning_group , strings_trim ( old_Owning_Group)) == 0))
	{
		ifail = 1;
	}
	
	return ifail;
 }
 
int check_new_vlues(char *new_Owning_User,char *new_Owning_Group)
 {
	int ifail = 0;
	
	tag_t new_user = NULLTAG;
	
	printf ("\n new_Owning_User1 %s\n", new_Owning_User);
	printf ("\n new_Owning_User2 %s\n", strings_trim (new_Owning_User));
	
	if (SA_find_user2(strings_trim (new_Owning_User), &new_user)!= ITK_ok )PrintErrorStack();

	 
	tag_t  new_group = NULLTAG;	

	printf ("\n new_Owning_Group1 %s\n", new_Owning_Group);	
	printf ("\n new_Owning_Group2 %s\n", strings_trim (new_Owning_Group));
	if (SA_find_group(strings_trim (new_Owning_Group) , &new_group) != ITK_ok )PrintErrorStack();	
		
	
	if ((new_group != NULLTAG) && (new_user != NULLTAG))
	{
			ifail = 1;
	}
	
	return ifail;
 }
 

static void report_wso_object_string_and_owning_user(tag_t object)
{
    char *object_string = NULL;
    WSOM_ask_object_id_string(object, &object_string);

    char *owning_user = NULL;
    AOM_UIF_ask_value(object, "owning_user", &owning_user);

    //ECHO("       %s - %s \n", object_string, owning_user);
    MEM_free(object_string);
    MEM_free(owning_user);
}

static void find_all_dataset_owned_by_user(tag_t user_tag)
{  
    tag_t dataset_class = NULLTAG;
    POM_class_id_of_class("Dataset", &dataset_class); 
    
    tag_t owning_user_id = NULLTAG;
    POM_attr_id_of_attr("owning_user", "Folder", &owning_user_id);
    
    tag_t enq = NULLTAG;
    POM_create_enquiry_on_tag(dataset_class, owning_user_id, POM_contains,  &user_tag, &enq);

    int no_of_hits = 0;
    tag_t *tag_list = NULL;
    POM_execute_enquiry(enq, &no_of_hits, &tag_list);
    //ECHO("\n  no_of_hits: %d \n", no_of_hits);
    for (int ii = 0; ii < no_of_hits; ii++)
        report_wso_object_string_and_owning_user(tag_list[ii]);
    
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
            
    
	SA_find_user2(owner_name, &user);
    
	SA_find_group(group_name, &group);
	
    while (printf("\nEnter the item name : ") &&
        strlen(item_name))
    {
		ITEM_find_item(item_name, &item);
		
        set_ownership(item, user, group);
		ITEM_ask_latest_rev(item, &rev);
        set_ownership(rev, user, group);
		//ITEM_list_all_rev(rev, &count, &objects);
        for (ii = 0; ii < count; ii++)
        {
            set_ownership(objects[ii].attachment, user, group);
        }
        if (objects) MEM_free(objects); 
    }      
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
	tag_t new_user = NULLTAG;
	tag_t  new_group = NULLTAG;		

	char *oou = NULL;
	char *oog = NULL;
	
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

    istatus = ITK_init_module( userId , password , group );

	if ( istatus != ITK_ok)
	{
		EMH_ask_error_text( istatus, &errormsg);
		printf("Error with ITK_init_module: %s \n",errormsg);
		MEM_free(errormsg);
		return istatus;
	}
	
	char *itemType = ITK_ask_cli_argument("-itemtype");
	 char *old_Owning_User = ITK_ask_cli_argument("-oou");
	 char *old_Owning_Group = ITK_ask_cli_argument("-oog");
	 char *new_Owning_User = ITK_ask_cli_argument("-nou");
	 char *new_Owning_Group = ITK_ask_cli_argument("-nog");
	
	
	if((!itemType) || (!old_Owning_User)  || (!old_Owning_Group) || (!new_Owning_User) || (!new_Owning_Group) )
	{		
		printf("\n\n\t\t Enter: -itemype=? -oou=? -oog=? -nou=? -nog=?");
		exit(0);
	} 
	
	istatus = Get_Items(&n_item, &item_tags);
	
	printf("login status %d /n", iFail);
	
	if ( istatus ==  ITK_ok )
        {
			printf(" Login successful.... \n");

			if ( n_item > 0 )
			{					
				if (check_new_vlues(new_Owning_User,new_Owning_Group ) > 0)
				{	
					if (SA_find_user2(strings_trim (new_Owning_User), &new_user)!= ITK_ok )PrintErrorStack();
	 	
					if (SA_find_group(strings_trim (new_Owning_Group) , &new_group) != ITK_ok )PrintErrorStack();
				}
				else	
				{
						printf("\nNew Owning User and Group not founded.\n");
						exit(0);
				}
				
				for ( int i = 0; i < n_item; i++ )      
				{
					if (check_initial_vlues ((item_tags)[i], itemType, old_Owning_User,old_Owning_Group) > 0)
					{
						if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
						
						printf("%d: Name: %s \n", numOfParts, objectname); 
						
						/**
							Retrieves all the BOM Views related to the Item.
						*/										
						bv_list = get_and_Set_Owner_of_all_Item_BOM (item_tags[i], new_user, new_group );
						/**
							Retrieves all the Item Revisions attached to a specified Item.
						*/						
						rev_list = get_and_Set_Owner_of_all_Item_Revision(item_tags[i], new_user, new_group);
						
						/**
							Retrieves the Item Master form type of an Item type.
						*/						
						
						//master_form =  ask_secondary_of_an_Object(item_tags[i]);
						
						/**
							change Owningchip.
						*/	
	
						set_ownership((item_tags)[i],new_user, new_group);
						numOfParts++; 
					}
				}
				if (numOfParts > 0)
				{
					//printf ("\nArtikeltyp wurde gefunden. \n");
					printf("\nNumber of Part object found : %d \n\n", --numOfParts);					
				}
				else
					printf ("Artikeltyp wurde nicht gefunden. \n");
			}
		}
	return NULL;
	}	
	
	