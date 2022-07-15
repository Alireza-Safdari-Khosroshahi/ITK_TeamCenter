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

    /* Add select attributes. We want the uids of the workspace

	objects so we can load them: */
	const char *select_attrs[]  = {"puid"};


	const char *name[]    = {"Item"};
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

	//CHECK_FAIL(POM_enquiry_set_string_value (enqid, "test",1,name, POM_enquiry_bind_value ));
	//CHECK_FAIL(POM_enquiry_set_attr_expr (enqid, "expr1","workspaceobject", "object_type",POM_enquiry_equal, "test" ));
	/* Set the where condition so we only get back matching rows: */
       //CHECK_FAIL(POM_enquiry_set_where_expr (enqid, "expr1"));

	/* Now execute the query: */

	if ( POM_enquiry_execute (enqid, &n_rows, &n_cols,&values)!= ITK_ok ) PrintErrorStack();
	cout<<"Number of Item object found : "<<n_rows<<endl;

	if ( n_rows != 0 )
        {
			*foundTags = (tag_t *)MEM_alloc ( n_rows * sizeof( tag_t ));
			*nFound = n_rows;

		for ( i =0 ; i < (*nFound) ; i++ )
          {
			(*foundTags )[i] = *((tag_t *)values[i][0]);
			
			/*
			if (AOM_ask_value_string((*foundTags )[i],"object_name",&value_prop)!= ITK_ok )PrintErrorStack();
			printf("object name is: %s \n",value_prop); 
			
			if (WSOM_ask_object_type2((*foundTags )[i],&object_type)!= ITK_ok )PrintErrorStack();
		
			printf("object type is: %s \n",object_type);
			*/
			}

		}
		
	if ( POM_enquiry_delete("find_wso_by_type")!= ITK_ok ) PrintErrorStack();
	MEM_free( values );

    return 0;
}

 extern int ITK_user_main( int argc, char **argv )
 {
	//getchar();

    char *out_file_name    = "Itemdetails.csv";    /* Output file name */
	char *out_Datasetfile_name  = "DatasetDetails.csv";    /* Output file name */
	char *objectname    = NULL;
	char *revisionid    = NULL;
	char *datasetname    = NULL;
	char *item_revision_id   = NULL; 
	char *object_desc    = NULL; 
	char *owning_user    = NULL;
	char *project_ids    = NULL;
	char *last_mod_user    = NULL;
	char *release_status_list  = NULL;
	char *date_format    = NULL;
	char *lastmoddate_string  = NULL;
	char *creationdate_string  = NULL;
	char *userId     = NULL;
	char *password     = NULL;
	char *group      = NULL;
	char *errormsg     = NULL;
	char *object_type    = NULL;

	date_t creation_date   = NULLDATE;  
	date_t last_mod_date   = NULLDATE;
	char type_name[TCTYPE_name_size_c+1];
	char refname[AE_reference_size_c + 1];
    char orig_name[IMF_filename_size_c + 1];
    char path_name[SS_MAXPATHLEN];
    char relative_path[IMF_relative_path_size_c+1];

	FILE  *out_file_fp    = NULL;     /* Output file pointer */
	FILE  *out_Datasefile_fp  = NULL;     /* Output file pointer */


	tag_t *item_tags    = NULLTAG;
	tag_t *secondary_objects  = NULLTAG;
	tag_t titem_rev     = NULLTAG;
	tag_t objTypeTag    = NULLTAG;
	tag_t refobject     = NULLTAG;
	tag_t towning_user    = NULLTAG;
	tag_t tlast_mod_user   = NULLTAG;

	AE_reference_type_t     reftype;
       (void)argc;
       (void)argv;

	int secondaryobjectcount  = 0;
	int referencenumberfound  = 0;
	int statuscount     = 0;
	int istatus      = ITK_ok;
	int n_item      = 0;
	int iFail      = ITK_ok;
	int retcode      = ITK_ok;

	//auto t       = *std::time(nullptr);
	//auto tm       = *std::localtime(&t);

	/* Display help if user asked for it */
    /*if ( ITK_ask_cli_argument("-h") )
    {
        display_help();
        return EXIT_FAILURE;
    }
*/
	userId    = ITK_ask_cli_argument( "-u" );
	password    = ITK_ask_cli_argument( "-p" );
	group    = ITK_ask_cli_argument( "-g" );//dba
	
	userId++;password++;group++;
	//return argument was containing '=' so pointer incremented

	if( (!userId) || (!password) ||(!group) )
	{
		printf("\n\n\t\t Enter -u=? -p=? -g=?");
		exit(0);
	}
 
	out_file_fp   = fopen ( out_file_name , "w" );
	out_Datasefile_fp = fopen ( out_Datasetfile_name , "w" );

    if ( out_file_fp == NULL || out_Datasefile_fp == NULL )
     {
        fprintf(stdout , "Could not open the output file. \n");
        return EXIT_FAILURE;
     }
	 
	  /*Initializing the text services */

    ITK_initialize_text_services( 0 );
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
					if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
					printf("object name is: %s \n",objectname); 
					
					if (WSOM_ask_object_type2((item_tags)[i],&object_type)!= ITK_ok )PrintErrorStack();		
					printf("object type is: %s \n",object_type);

					ITEM_ask_latest_rev( item_tags[i],&titem_rev );
					
					if (AOM_ask_value_string(item_tags[i],"object_desc",&object_desc)!= ITK_ok )PrintErrorStack();					
					printf("object_desc is: %s \n",object_desc);
					
					if (AOM_ask_value_string(titem_rev,"item_revision_id",&revisionid)!= ITK_ok )PrintErrorStack();
					printf("Revision id is: %s \n",revisionid); 

					if (AOM_ask_value_string(titem_rev,"object_desc",&object_desc)!= ITK_ok )PrintErrorStack();					
					printf("Revision_object_desc is: %s \n",object_desc);
					
					if (AOM_ask_value_date(titem_rev,"creation_date",&creation_date)!= ITK_ok )PrintErrorStack();
					DATE_default_date_format(&date_format);
					
					DATE_date_to_string ( creation_date , date_format , &creationdate_string);
					printf("creation_date is: %s \n",creationdate_string); 

					if (AOM_ask_owner(titem_rev,&towning_user)!= ITK_ok )PrintErrorStack();
					AOM_ask_value_string(towning_user,"user_id",&owning_user);
					printf("owning_user is: %s \n",owning_user);  

					if (AOM_UIF_ask_value(titem_rev,"project_ids",&project_ids)!= ITK_ok )PrintErrorStack();
					printf("project_ids is: %s \n",project_ids);   

					if (AOM_ask_value_date(titem_rev,"last_mod_date",&last_mod_date)!= ITK_ok )PrintErrorStack();
					DATE_date_to_string ( last_mod_date , date_format , &lastmoddate_string);
					printf("last_mod_date is: %s \n",lastmoddate_string); 

					if ( AOM_ask_last_modifier(titem_rev,&tlast_mod_user)!= ITK_ok )PrintErrorStack();
					AOM_ask_value_string(tlast_mod_user,"user_id",&last_mod_user);
					printf("last_mod_user is: %s \n",last_mod_user);  

					AOM_UIF_ask_value(titem_rev,"last_release_status",&release_status_list);
					printf("release_status_list is: %s \n",release_status_list);  

					fprintf (out_file_fp , "%s,%s,%s,%s,%s,%s,%s,%s,%s\n" , objectname,object_desc,revisionid,creationdate_string,owning_user,project_ids,lastmoddate_string,last_mod_user,release_status_list );

					//GRM_list_secondary_objects_only (titem_rev,NULLTAG,&secondaryobjectcount,&secondary_objects);
					//printf("Dataset count is: %s \n",secondaryobjectcount);
					
					/*
					for(int datasetcount=0;datasetcount<secondaryobjectcount;datasetcount++)
					{
						if (TCTYPE_ask_object_type(secondary_objects[datasetcount],&objTypeTag)!=ITK_ok)PrintErrorStack();
						if (TCTYPE_ask_name2(objTypeTag,type_name)!=ITK_ok)PrintErrorStack();
						printf("type_name is: %s \n",type_name);  
						
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
						}
					}
					*/
				}
			}
		}
	return NULL;
	}