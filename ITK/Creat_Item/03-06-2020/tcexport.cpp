
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#include <itk/mem.h>
#include <unidefs.h>
#include <tcinit/tcinit.h>
#include <tccore/item.h>
#include <pom/pom/pom.h>
#include <ps/ps.h>
#include <tccore/workspaceobject.h>
#include <ae/ae.h>
#include <sa/tcfile.h>
#include <string.h>
#include <fclasses/tc_string.h>
#include <fclasses/tc_date.h>
#include <tc/emh.h>
#include <tc/tc_util.h>
#include <tccore/aom.h>
#include <nls/nls.h>
#include <iostream>
#include <tc/tc.h>
#include <tccore/item.h>
#include <tccore/aom_prop.h>
#include <tie\tie.h>
#include <error_decode.h>
using namespace std;

#define ITK_ERR(x) if(x != ITK_ok) { printf("Error: %d, %s, Line: %d\n", x, "Error", __LINE__); goto ITK_ERROR; }


string exportObjects(const std::string itemUid, const std::string reason, const std::string logFileName, const std::string logFilePath, const std::string transfermode, const std::string xmlFilePath, const std::string messageID){


	            char* transfer_mode=(char*)transfermode.c_str();

			    char* selectedpath=(char*)xmlFilePath.c_str();

			    char* item_Uid=(char*)itemUid.c_str();

			    char* logFile_name=(char*)logFileName.c_str();

                std::string serverMessage=NULL;
				
			    char* message_ID=(char*)messageID.c_str();

			  	char* reason_transfer=(char*)reason.c_str();

			  	char* logFile_path=(char*)logFilePath.c_str();

			  	int iITK = ITK_ok;

	            char* sErrorMessage = nullptr;

			   // int siteID = -1234567899; 					// ID of a POM_icm object. (User supplied)

			  	tag_t itemTag  ;

			  	tag_t transferSiteTag = NULLTAG;  			// tag to a POM_imc object.

			  	logical synchronize = FALSE;

			  	TIE_transfer_formula_t opts;

			  	TIE_output_data_t output_data;


			  	memset(&opts, 0, sizeof(TIE_transfer_formula_t));

			  	memset(&output_data, 0, sizeof(TIE_output_data_t));

			  	ITK__convert_uid_to_tag(item_Uid,  &itemTag); // user must obtain their own item tags.


			  	opts.n_options = 3;
			  	opts.optionOverrides = (TIE_option_value_t*) MEM_alloc(sizeof(TIE_option_value_t) * opts.n_options);
			  	opts.optionOverrides[0].name = "opt_rev_select";
			  	opts.optionOverrides[0].value = "allItemRevisions";
			  	opts.optionOverrides[1].name = "opt_all_ds_vers";
			  	opts.optionOverrides[1].value = "true";
			  	opts.optionOverrides[2].name = "opt_all_ds_files";
			  	opts.optionOverrides[2].value = "true";
			  	opts.n_sessOptions = 1;
			  	opts.sessionOptions = (TIE_option_value_t*) MEM_alloc(sizeof(TIE_option_value_t) * opts.n_sessOptions);
			  	opts.sessionOptions[0].name = "ContinueOnError";
			  	opts.sessionOptions[0].value = "true";
			  	opts.transferModeName =transfer_mode ;
			  	opts.logFileName = logFile_name;
			  	opts.logFilePath =logFile_path;
			  	opts.reason = reason_transfer;

			  	output_data.xmlFilePath = selectedpath; // File and path to the output XML file.

			  	iITK=TIE_export_objects(message_ID, 1, &itemTag, 1, &transferSiteTag, synchronize, opts, &output_data);

				if(iITK != ITK_ok)
			    {
			      EMH_ask_error_text( iITK, &sErrorMessage);

			      printf("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );

				  TC_write_syslog("\nError occurred in IDFR_set_id was :%s\n", sErrorMessage );
				  
				  serverMessage="Sometime happen wrong: ";

			       if(opts.optionOverrides != NULL)
			       		MEM_free(opts.optionOverrides);

			       	if(opts.sessionOptions != NULL)
			       		MEM_free(opts.sessionOptions);

			       	if(output_data.xmlFilePath != NULL)
			       		MEM_free(output_data.xmlFilePath);

			       	if(output_data.importexport_log_fmsticket != NULL)
			       		MEM_free(output_data.importexport_log_fmsticket);

			    }
				else
					serverMessage="completely Exported";
				

				return serverMessage;
	
}

//static logical validate_arguments_name(int argc, char* argv[]);

//static void display_help(void);



int ITK_user_main(int argc , char* argv[]){
	
	TC_printf ("Failed to login to Teamcenter using auto-login with ");
	
	int retcode = ITK_ok;
 	/* Function error return code */
    string result=NULL;
	retcode = ITK_auto_login();
	
    if (retcode != ITK_ok){
        TC_printf ("Failed to login to Teamcenter using auto-login with ");
        TC_printf ("error code %d\n\n", retcode);
        return EXIT_FAILURE;
    }
	
     std::string this_item_Uid ="wZNAAAQpp4UX4B";
	
	 std::string this_reason="User supplied reason for export";
	
	 std::string this_logFileName="exportObjects.log";
	
	 std::string this_logFilePath="C:\\Temp\\lelouch";
	
	 std::string this_transfermode="TIEExportDefaultTM";
	
	 std::string this_xmlFilePath ="C:\\Temp\\export\\lelouch.xml";
	
	 std::string this_messageID="MyUniqueExportString";
	
	result=exportObjects(this_item_Uid,this_reason,this_logFileName,this_logFilePath,this_transfermode,this_xmlFilePath,this_messageID);
	
	TC_printf ((char*)result.c_str());
	
    retcode =  ITK_exit_module(true);
    
    return EXIT_SUCCESS;
}
