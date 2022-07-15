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
#include <tccore/grm.h>
#include <tccore/grmtype.h>
#include <bom/bom.h>
#include <ps/vrule.h>
#include <tccore/tctype.h>

using namespace std;

static void report_error(char *file, int line, char *function, int return_code)
{
	if (return_code != ITK_ok)
	{
		/*
		char *error_message_string;
		EMH_get_error_text (NULLTAG, return_code, &error_message_string);
		printf ("ERROR: %d ERROR MSG: %s.\n", return_code, error_message_string);
		printf ("FUNCTION: %s\nFILE: %s LINE: %d\n", function, file, line);
		if(error_message_string) MEM_free(error_message_string);
		printf("\nExiting program!\n");
		exit (EXIT_FAILURE);
*/
	}
}

void Costum_Search()
{
	/**
	char* sErrorMessage=nullptr;

	char *attribs_names [1]  = {"object__name"};
	char *attribs_Values [1] = {"Tasse"};
	int num_attribs = 1;

	int fined_n_Item = 0;
	tag_t *Item[2] = NULLTAG;
	int iITK = ITK_ok;

	iITK=ITEM_find_items_by_key_attributes(num_attribs,attribs_names,attribs_Values, &fined_n_Item, &Item);

	printErrorMessage(sErrorMessage,  iITK);

	return;
	*/
}

void list_displayable_properties_with_value(char *indention, tag_t object)
{
	logical
		is_displayable = TRUE;
	int
		n_props = 0,
		ii = 0;
	int num_values = 0;
	char
		**prop_names = NULL,
		*disp_name = NULL,
		*value = NULL;

	AOM_ask_prop_names(object, &n_props, &prop_names);
	for (ii = 0; ii < n_props; ii++)
	{
		// AOM_UIF_is_displayable(object, prop_names[ii],&is_displayable);
		if (is_displayable == TRUE)
		{
			value = NULL;
			AOM_UIF_ask_name(object, prop_names[ii], &disp_name);
			AOM_ask_displayable_values(object, prop_names[ii], (int*)&num_values, (char ***)&value);
			if ((value != NULL) && (strlen(value) > 0))
			{
				if (strlen(value) == 1)
				{
					if (strcmp(value, " ") != 0)
						fprintf(stdout, "%s %s: %s \n", indention, disp_name,
							value);
				}
				else
					fprintf(stdout, "%s %s: %s\n", indention, disp_name, value);
			}
		}
	}
	if (prop_names != NULL) MEM_free(prop_names);
	if (disp_name != NULL) MEM_free(disp_name);
	if (value != NULL) MEM_free(value);
}


void list_secondary_objects(tag_t primary_object, char *rel_type_name)
{


	tag_t relation_type = NULLTAG;
	if ((rel_type_name != NULL) && (strlen(rel_type_name) > 0))
	{
		GRM_find_relation_type(rel_type_name, &relation_type);
		//IFERR_REPORT(GRM_find_relation_type(rel_type_name, &relation_type));
	}

	int n_objects = 0;
	tag_t *objects = NULL;
	GRM_list_secondary_objects_only(primary_object, relation_type, &n_objects, &objects);
	//IFERR_REPORT(GRM_list_secondary_objects_only(primary_object, relation_type,
	 //   &n_objects, &objects)); 

	for (int ii = 0; ii < n_objects; ii++)
	{
		list_displayable_properties_with_value("        ", objects[ii]);
	}

	MEM_free(objects);
}

int ITK_user_main(int argc, char* argv[])
{
	int retcode = ITK_ok;

	/*get command line input from user*/
	const char* userid = ITK_ask_cli_argument("-u=");
	const char* password = ITK_ask_cli_argument("-p=");
	const char* group = ITK_ask_cli_argument("-g=");
	const char* mode = ITK_ask_cli_argument("-m=");
	const char* prj_id = ITK_ask_cli_argument("-prj_id=");

	int nItems = 0;
	tag_t *items = NULLTAG;
	char *item_name = "Umair";

	const char
		*names[1] = { "item_id" },
		*values[1] = { "MD0001565" };




	ITK_initialize_text_services(0);


	/*Login to Teamcenter*/
	ERROR_CHECK(ITK_init_module(userid, password, group));
	int ifail = 0;
	if (ifail != ITK_ok)
	{
		printf("iMAN login NOT sucessfull.\n"); return ifail;
	}

	printf("Teamcenter login sucessfull.\n");
	ERROR_CHECK(ITEM_find_items_by_key_attributes(1, names, values, &nItems, &items));

	for (int i = 0; i < nItems; i++)
	{
		ITEM_ask_name2(items[i], &item_name);

		list_secondary_objects(items[i], "revision_list");

		printf("Name of Item :%s\n", item_name);
	}

	printf("no of items = [%d]\n", nItems);



	/*
else
{
	printf("Teamcenter login sucessfull.\n");
	ERROR_CHECK(ITEM_find_items_by_key_attributes(1,names,values,&nItems,&items ));
	printf("no of items = [%d]\n", nItems);

	if (tc_strcmp(mode, "assign") == 0){
		printf("assigning objects to project prj_id prj001\n");
		//ERROR_CHECK(PROJ_find (prj_id,&project ));
		printf("project tag is %d and no of objects %d",project,nItems);
		//ERROR_CHECK(PROJ_assign_objects (1,&project,nItems,items ));
		printf("no of items assign to project %d for project tag %d \n",nItems,project );
	}


}
*/

	if (items != NULLTAG) MEM_free(items);
	ITK_exit_module(TRUE);

	return(ifail);
	/**

	int retcode = ITK_ok;

	retcode = ITK_auto_login();

	if (retcode != ITK_ok){

		TC_printf ("Failed to login to Teamcenter using auto-login with ");
		TC_printf ("error code %d\n\n", retcode);
		return EXIT_FAILURE;
	}

	char* attribs_names [1]  = {"object__name"};
	char* attribs_Values [1] = {"Tasse"};
	int num_attribs = 1;


	//Costum_Search(n_attributes , attribute_names  , attribute_values);
	Costum_Search();

	printf("Complete");

	retcode =  ITK_exit_module(true);

	return EXIT_SUCCESS;
	*/
}