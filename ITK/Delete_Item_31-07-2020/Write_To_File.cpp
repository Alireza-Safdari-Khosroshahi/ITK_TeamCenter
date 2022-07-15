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

#include <tc/folder.h>
#include <ae/nxsm.h>

#include <tcinit/tcinit.h>
#include <nls/nls.h>
#include <iostream>
#include <ps/ps.h>

using namespace std;

#define WRITE_D(X) ECHO("%s = %d\n", #X, X);

#define WRITE_L(X) if (X) ECHO("%s = TRUE\n", #X); \
    else ECHO("%s = FALSE\n", #X);

#define IFERR_ABORT(X)  (report_error( __FILE__, __LINE__, #X, X, TRUE))
#define IFERR_REPORT(X) (report_error( __FILE__, __LINE__, #X, X, FALSE))	

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

char* Trim_Entered_TXTs (char* complete_name)
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

static void ECHO(char *format, ...)
{
    char msg[1000];
    va_list args;
    va_start(args, format);
    vsprintf(msg, format, args);
    va_end(args);
    printf(msg);
    TC_write_syslog(msg);
}

static int report_error(char *file, int line, char *call, int status, logical exit_on_error)
{
    if (status != ITK_ok)
    {
        int
            n_errors = 0;
		const int 	
            *severities = NULL,
            *statuses = NULL;
        const char
            **messages;

        EMH_ask_errors(&n_errors, &severities, &statuses, &messages);
        if (n_errors > 0)
        {
            ECHO("\n%s\n", messages[n_errors-1]);
            EMH_clear_errors();
        }
        else
        {
			/*
            char *error_message_string;
            EMH_get_error_string (NULLTAG, status, &error_message_string);
            ECHO("\n%s\n", error_message_string);
			*/
        }

        ECHO("error %d at line %d in %s\n", status, line, file);
        ECHO("%s\n", call);

        if (exit_on_error)
        {
            ECHO("%s", "Exiting program!\n");
            exit (status);
        }
    }

    return status;
}

static int remove_from_all_folders(tag_t object)
{
    int
        cnt = 0,
        ii,
        n_levels,
        n_instances,
        *instance_levels,
        *instance_where_found,
        n_classes,
        *class_levels,
        *class_where_found;
    tag_t
        folder_type,
        newstuff_type,
        *ref_instances,
        *ref_classes,
        type = NULLTAG;
		
    IFERR_REPORT(POM_referencers_of_instance(object, 1, POM_in_ds_and_db,
        &n_instances, &ref_instances, &instance_levels,
        &instance_where_found, &n_classes, &ref_classes, &class_levels,
        &class_where_found));

    if (n_instances > 0)
    {
        for (ii = 0; ii < n_instances; ii++)
        {
            IFERR_REPORT(TCTYPE_ask_object_type(ref_instances[ii], &type));          
            IFERR_REPORT(AOM_refresh(ref_instances[ii], TRUE));
            IFERR_REPORT(FL_remove(ref_instances[ii], object));
            IFERR_REPORT(AOM_save(ref_instances[ii]));
            IFERR_REPORT(AOM_refresh(ref_instances[ii], FALSE));
            cnt++;            
        }
        MEM_free(ref_instances);
        MEM_free(instance_levels);
        MEM_free(instance_where_found);
    }

    if (n_classes > 0)
    {
        MEM_free(ref_classes);
        MEM_free(class_levels);
        MEM_free(class_where_found);
    }

    return cnt;
}

static logical is_object_referenced(tag_t object)
{
    int
        ii,
        n_levels,
        n_instances,
        *instance_levels,
        *instance_where_found,
        n_classes,
        *class_levels,
        *class_where_found;
    tag_t
        *ref_instances,
        *ref_classes,
        type = NULLTAG;
    char
        *class_name,
        *name,
        *type_name;

    IFERR_REPORT(POM_referencers_of_instance(object, 1, POM_in_ds_and_db,
        &n_instances, &ref_instances, &instance_levels,
        &instance_where_found, &n_classes, &ref_classes, &class_levels,
        &class_where_found));

    if (n_instances > 0)
    {
        ECHO("Referencing instances:\n");
        for (ii = 0; ii < n_instances; ii++)
        {
            IFERR_REPORT(AOM_ask_name(ref_instances[ii], &name));
            IFERR_REPORT(TCTYPE_ask_object_type(ref_instances[ii], &type));
            TCTYPE_ask_name2(type, &type_name);

            ECHO("  %s (%s)\n", name, type_name);
            if (name) MEM_free(name);
        }
        MEM_free(ref_instances);
        MEM_free(instance_levels);
        MEM_free(instance_where_found);
    }

    if (n_classes > 0)
    {
        ECHO("Referencing classes:\n");
        for (ii = 0; ii < n_classes; ii++)
        {
            IFERR_REPORT(POM_name_of_class(ref_classes[ii], &class_name));
            ECHO("  %s\n", class_name);
            if (class_name) MEM_free(class_name);
        }
        MEM_free(ref_classes);
        MEM_free(class_levels);
        MEM_free(class_where_found);
    }

    if ((n_instances + n_classes) > 0) return TRUE;

    return FALSE;
}

static void Object_Delete(tag_t item)
{  		
        WRITE_D(remove_from_all_folders(item));
        IFERR_REPORT(AOM_refresh(item, TRUE));

        WRITE_L(is_object_referenced(item));

        IFERR_REPORT(AOM_lock_for_delete(item));
        IFERR_REPORT(ITEM_delete_item(item));		
}

int check_Object_Status(tag_t object,char *status)
{
	int ifail = 0;	
	char *last_release_status = NULL;
	
	AOM_UIF_ask_value(object, "last_release_status", &last_release_status);						
						
	if ((strcmp (strings_trim (status) , last_release_status) == 0))
		ifail = 1;
	
	return ifail;
 }

int check_initial_vlues(tag_t item, char *itemType)
{
	int ifail = 0;	
	char *current_item_type = NULL;	
	
	if (WSOM_ask_object_type2(item ,&current_item_type)!= ITK_ok )PrintErrorStack();	
	
	if ((strcmp (strings_trim (itemType) , current_item_type) == 0))
		ifail = 1;
	
	return ifail;
 }

static tag_t ask_secondary_of_an_Object(char* relation_type_name, tag_t primary_object)
{
    int
        n_secondary_object_tags = 0;
    tag_t
        relation = NULLTAG,
        *secondary_object_tags = NULL,
        item_tag = NULLTAG;
		
	GRM_relation_t
		*secondary_list = NULL;

	char *objectname = NULL;
	
	if (GRM_find_relation_type(relation_type_name, &relation)!= ITK_ok )PrintErrorStack();	
	if (GRM_list_secondary_objects(primary_object, relation,
       &n_secondary_object_tags, &secondary_list)!= ITK_ok )PrintErrorStack();	
		
	for (int k = 0; k < n_secondary_object_tags; k++ )      
	{
		if (AOM_ask_value_string(secondary_list[k].secondary,"object_name",&objectname)!= ITK_ok )PrintErrorStack();	
		//printf("-->>> Secondry Object Name: %s , with Relation: %s \n", objectname, relation_type_name);	
        AE_reference_type_t ref_type;			
		Object_Delete(secondary_list[k].secondary);		
	}
	
	if (secondary_list) MEM_free(secondary_list);
	
    return item_tag;
}

static void delete_dataset_named_reference(tag_t dataset, char *reference_name, tag_t reference_object)
{
    char
        backup[SS_MAXPATHLEN],
        name[IMF_filename_size_c + 1],
        pathname[SS_MAXPATHLEN],
        *type;

    AOM_refresh(dataset, TRUE);

   // export_backup_imanfile(reference_object);
    AE_purge_dataset_revs(dataset);
    AE_remove_dataset_named_ref_by_tag2(dataset, reference_name,
        reference_object);
    AE_save_myself(dataset);
    AOM_unlock(dataset);

    AOM_lock_for_delete(reference_object);
   // IMF_ask_file_pathname(reference_object, SS_MACHINE_TYPE,pathname);
    printf("Deleted: %s\n", pathname);
    AOM_delete(reference_object);
}

static logical is_descendant_of_folder(tag_t object_tag)
{
    tag_t parent_class = NULLTAG;
    IFERR_REPORT(POM_class_id_of_class("Folder", &parent_class));
        
    tag_t class_tag = NULLTAG;
    IFERR_REPORT(POM_class_of_instance(object_tag, &class_tag));
    
    logical verdict = FALSE;
    IFERR_REPORT(POM_is_descendant(parent_class, class_tag, &verdict));

    return verdict;
}

static void removal_of_certain_reference_types(tag_t object_tag)
{
    int n_references = 0;
    int *levels = NULL;
    tag_t *reference_tags = NULL;
    char **relation_type_name = NULL;
	char  *type_name = NULL;
    IFERR_REPORT(WSOM_where_referenced(object_tag, 1, &n_references, &levels, 
        &reference_tags, &relation_type_name));

    for (int ii = 0; ii < n_references; ii++)
    {
       
        IFERR_REPORT(WSOM_ask_object_type2(reference_tags[ii], &type_name));

        if (is_descendant_of_folder(reference_tags[ii]))
        {
            tag_t folder = reference_tags[ii];
            IFERR_REPORT(AOM_refresh(folder, TRUE));
            IFERR_REPORT(FL_remove(folder, object_tag));
            IFERR_REPORT(AOM_save(folder));
            IFERR_REPORT(AOM_refresh(folder, FALSE));
        }
        else if ( (relation_type_name[ii] != NULL) && 
            (strlen(relation_type_name[ii]) > 0 ) )
        {
            tag_t relation_type_tag = NULLTAG;
            IFERR_REPORT(GRM_find_relation_type(relation_type_name[ii],
                &relation_type_tag));
            
            // GRM_delete_relation requires the relation object which we don't have
            tag_t relation_tag = NULLTAG;

            // First try relation using the reference as a primary object
            tag_t primary_object = reference_tags[ii];
            tag_t second_object = object_tag; 
            IFERR_REPORT(GRM_find_relation(primary_object, second_object, 
                relation_type_tag, &relation_tag));

            // If no relation is found try the reference as a secondary object
            if (relation_tag == NULLTAG)
            {
                primary_object = object_tag;
                second_object = reference_tags[ii]; 
                IFERR_REPORT(GRM_find_relation(primary_object, second_object, 
                    relation_type_tag, &relation_tag));
            }
            IFERR_REPORT(GRM_delete_relation(relation_tag ));
        }
        else if(strcmp(type_name, "EPMTask") == 0 )
        {
            tag_t task = reference_tags[ii];
            EPM_state_t state;
            IFERR_REPORT(EPM_ask_state(task, &state));

            char *state_string  = NULL;
            IFERR_REPORT(EPM_ask_state_string2(state, &state_string));

            if(strcmp(state_string, "Completed") == 0)
            {
                ECHO("\n Can't remove targets of completed jobs! \n");
            }
            else
            {
                ITK_set_bypass(TRUE);
                IFERR_REPORT(EPM_remove_attachments(task, 1, &object_tag));
            }
        }

    }
    if(levels) MEM_free(levels);
    if(reference_tags) MEM_free(reference_tags);
    if(relation_type_name) MEM_free(relation_type_name);
}

extern int ITK_user_main( int argc, char **argv )
{
	char *objectname = NULL;
	char *userId = NULL;
	char *password = NULL;
	char *group = NULL;
	char *errormsg = NULL;
	char *object_type = NULL;  
	char *item_id = NULL; 	
	char *release_status_list = NULL; 
	char *line_In_Report  = NULL; 
	
	int istatus = ITK_ok;
	int n_item = 0;
	int iFail = ITK_ok;		
	int all_ItemRevision_mit_Status = 0;  
	int num_of_candidate_deleted_items = 0;
	
	tag_t *item_tags = NULLTAG;
		
	userId = ITK_ask_cli_argument( "-u" );
	password = ITK_ask_cli_argument( "-p" );
	group = ITK_ask_cli_argument( "-g" );
	
	userId++;password++;group++;	
	
	FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("C:\\Delete_Item_Report.txt","w");
   
	if(fptr == NULL)
   {
      printf("Error, es gibt keine txt-Daten!!!!!");   
      exit(1);             
   }
   
	if( (!userId) || (!password) ||(!group) )
	{
		printf("\n\n\t\t Enter -u=? -p=? -g=?");		
		exit(0);
	} 	

    istatus = ITK_init_module( userId , password , group );
	istatus = ITK_set_bypass( true );
	
	if ( istatus != ITK_ok)
	{
		EMH_ask_error_text( istatus, &errormsg);
		printf("Error with ITK_init_module: %s \n",errormsg);
		MEM_free(errormsg);
		return istatus;
	}
	
	 char *itemType = ITK_ask_cli_argument("-itemtype");
	 char *status = ITK_ask_cli_argument("-s");
		
	if((!itemType) || (!status)  )
	{		
		printf("\n\n\t\t Enter: -itemype=? -s(status)=?");
		exit(0);
	} 	
	
	istatus = Get_Items(&n_item, &item_tags);	
	printf("login status %d /n", iFail);
	
	if ( istatus ==  ITK_ok )
        {
			if ( n_item > 0 )
			{	
				fprintf(fptr,"List of founded Items: \n\n");					

				for ( int i = 0; i < n_item; i++ )      
				{	
					if (check_Object_Status(item_tags[i], status) > 0 )
					{
						if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
						if (AOM_ask_value_string(item_tags[i],"item_id",&item_id)!= ITK_ok )PrintErrorStack();							
							
						num_of_candidate_deleted_items++;
							
						fprintf(fptr,"No: %d = ID:%s, Name: %s  \n", num_of_candidate_deleted_items, item_id, objectname);					
						
						removal_of_certain_reference_types(item_tags[i]);
						Object_Delete(item_tags[i]);
						
					}
				}
				
				if (num_of_candidate_deleted_items > 0)
				{
					
					istatus = Get_Items(&n_item, &item_tags);
					
					if ( n_item > 0 )
					{
						fprintf(fptr,"\nList of items that could not be deleted: \n\n");	
						
						int counter = 0;
						
						for ( int i = 0; i < n_item; i++ )      
						{	
							if (check_Object_Status(item_tags[i], status)  > 0 )
							{
								if (AOM_ask_value_string(item_tags[i],"object_name",&objectname)!= ITK_ok )PrintErrorStack();
								if (AOM_ask_value_string(item_tags[i],"item_id",&item_id)!= ITK_ok )PrintErrorStack();	
								
								counter++;
								fprintf(fptr,"No: %d = ID:%s, Name: %s  \n", counter, item_id, objectname);	
							}
						}
						fprintf(fptr,"\nNumber of items with status '%s': %d", strings_trim (status) ,num_of_candidate_deleted_items);
						fprintf(fptr,"\nNumber of items that could not be deleted: %d", counter);
					}
				}
			}		
			else
			{
				printf ("Artikeltyp wurde nicht gefunden. \n");							
				return NULL;

			}
		}
		fclose(fptr);	
	return NULL;
	}	
	
	