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
#include <stdlib.h>`
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
#include <teamcenter\services\classification\_2007_01\Classification.hxx>
#include <tccore/workspaceobject.h>
#include <ics/ics.h>
#include <string.h>

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

int ITK_user_main(int argc, char* argv[]){
	int retcode = ITK_ok;

	/*get command line input from user*/
	const char* userid = ITK_ask_cli_argument("-u=");
	const char* password = ITK_ask_cli_argument("-p=");
	const char* group = ITK_ask_cli_argument("-g=");
	const char* mode = ITK_ask_cli_argument("-m=");
	const char* prj_id = ITK_ask_cli_argument("-prj_id=");
	const char* item_id = ITK_ask_cli_argument("-item_id=");

	int nItems = 0;
	tag_t *items = NULLTAG;
	char *item_name = "Umair";

	const char
		*names[1] = { "item_id" },
		*values[1] = { item_id };


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
	
	printf("No of items %d\n", nItems);
	
	ITEM_ask_name2(items[0], &item_name);
	printf("Name of the item is %s\n", item_name);
	

	//find item relation
	tag_t
        item_revision = NULLTAG;

	char *rev_id = NULL;

		
	ERROR_CHECK(ITEM_ask_latest_rev(items[0], &item_revision));
	

	tag_t relation_type_tag = NULLTAG;
	int n_objects = 0;
	tag_t *objects = NULL;
    GRM_find_relation_type( "IMAN_classification", &relation_type_tag);
	GRM_list_secondary_objects_only(item_revision, relation_type_tag, &n_objects, &objects);
	
	printf("Numer of IMAN_Spec %d\n", n_objects);
	char *rev_name = "Umair";
	

	int nAttributes = 0;
	char **attributeNames;
	char **attributeValues;
	//get attributes of classification
	ICS_ask_attributes_of_classification_obj(objects[0], &nAttributes, &attributeNames, &attributeValues);
	char* full_text;
	std::string result= item_name;
	
	

	for(int i =0 ;i < nAttributes; i++){
		//char**         attributeValue;
		//ICS_ask_attribute_value(objects[0], attributeNames[i], attributeValue);
		result = std::string(result) +" - "+ std::string(attributeValues[i]);
		printf("%s : %s\n", attributeNames[i], attributeValues[i]);
	}
	
	char **id;
	char **name;
	ICS_ask_id_name(objects[0], id, name);
	
	//for(int i =0 ;i < nAttributes; i++){
		//char**         attributeValue;
		//ICS_ask_attribute_value(objects[0], attributeNames[i], attributeValue);
		//result = std::string(result) +" - "+ std::string(attributeValues[i]);
		printf("Id: %s : name: %s\n", id, name);
	//}
	
	ITEM_set_rev_description(item_revision,result.c_str());
	AOM_save_with_extensions(item_revision);

	
	
}