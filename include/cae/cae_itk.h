/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2019.
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/

/**
@file

This header file declares all data types and ITKs to be used by the customers of Teamcenter for Simulation.
*/

#ifndef CAE_ITK_H
#define CAE_ITK_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>
#include <cae/libcae_exports.h>

/**
@defgroup CAE CAE

This module provides implementation for all the ITKs to be used by the customers of Teamcenter for Simulation.

To use these ITK functions, include the cae_itk.h file in the source code.
@{
*/


#ifdef __cplusplus
extern "C"{
#endif

    /**
    * Data struture defined to save runtime overrides for export configuration of Simulation Tool
    */
    typedef struct CAE_tool_launch_export_config_runtime_overrides_s
    {
        char* plmxml_name;                              /**< Runtime override for PLMXML export file name */            
        int num_runtime_arguments;                      /**< Number of runtime arguments */
        char** runtime_arguments;                       /**< Values of runtime arguments */
    } CAE_tool_launch_export_config_runtime_overrides_t;

    /**
    * Data struture defined to save runtime overrides for import configuration of Simulation Tool
    */
    typedef struct CAE_tool_launch_import_config_runtime_overrides_s
    {
        char* item_creation_setting;                /**< Runtime override for item creation setting */
        char* dataset_creation_setting;             /**< Runtime override for dataset creation setting */
        int num_output_name_patterns;               /**< Number of output item naming patterns */
        char** output_name_patterns;                /**< Output item naming patterns */
    } CAE_tool_launch_import_config_runtime_overrides_t;

    /**
    * Data struture defined to save runtime overrides for import configuration of Simulation Tool with file upload option for auto process
    */
    typedef struct CAE_tool_launch_import_config_runtime_overrides_with_file_upload_option_s
    {
        char* item_creation_setting;                /**< Runtime override for item creation setting */
        char* dataset_creation_setting;             /**< Runtime override for dataset creation setting */
        int num_output_name_patterns;               /**< Number of output item naming patterns */
        char** output_name_patterns;                /**< Output item naming patterns */
        char* auto_process_options;                 /**< Auto process options to upload files. Valid values are "Upload", "Rename And Upload" or "Skip"*/
    } CAE_tool_launch_import_config_runtime_overrides_with_file_upload_option_t;

    /**
    * Data struture defined for export file options when Simulation Tool is configured to use staging directory
    */
    typedef struct CAE_tool_launch_export_file_options_for_user_staging_directory_s
    {
        bool is_auto_process_selected;               /**< If true, auto_process_option is used for export action for all files; otherwise prompt_user_options is used for export action.*/
        char* auto_process_option;                   /**< Auto process options to export files. Valid values are: "Override", "Skip".*/
        int num_export_file;                         /**< Number of files for which export options are present in prompt_user_options*/
        tag_t* export_file_tags;                     /**< Array of export file object tags */
        char** prompt_user_options;                  /**< List of export option for each export_file_tags. Valid values are: "Override", "Skip".*/
    } CAE_tool_launch_export_file_options_for_user_staging_directory_t;

    /**
     @deprecated #CAE_launch_simulation_tool deprecated in Teamcenter 11.4. Use #CAE_launch_simulation_tool_asynchronous instead.

     Launches external simulation tool as per the pre-defined configuration.
     The configuration can be defined through the External Simulation Process Framework. 
     A valid configuration for the tool must exists before this ITK is called. 
     Returns integer code.    
    */
    TC_DEPRECATED("11.4","CAE_launch_simulation_tool","CAE_launch_simulation_tool_asynchronous")
    extern CAE_API int CAE_launch_simulation_tool(
        tag_t*** input_objects_array,          /**< (I) Array of array (two-dimensional array) of tags of Item Revisions.
                                                  <br/>Each one-dimensional array is taken as an input for the specified process.
                                                  <br/>Thus the specified tool can be launched multiple times using a two-dimensional array. */
        int array_count,                       /**< (I) Number of one-dimensional arrays in @p input_objects_array */
        int* objects_count,                    /**< (I) Array of integers each representing the length of each one-dimensional array in @p input_objects_array */
        const char* tool_name,                 /**< (I) Name of the configured tool which will be launched by this ITK */
        const char* launch_type,               /**< (I) Launch type for the process. It could be "LOCAL" or "REMOTE" */
        const char* item_creation,             /**< (I) Item creation options for the process. It could be either "As Needed", "Always" or "Never" */
        const char* dataset_creation,          /**< (I) Dataset creation options for the process. It could be either "As Needed", "Always" or "Never" */
        const char* plmxml_name,               /**< (I) PLMXML Export file name */
        const char* working_directory,         /**< (I) Path to the working directory */
        char** runtime_arguments,              /**< (I) List of runtime arguments and their values.
                                                  <br/>The argument and values are represented by a single string seperated by token "::"
                                                  <br/>Example: To pass -fem -dat=blk as an argument, the user should pass [fem::\<empty string\>, dat::blk] as a string vector */
        int argument_count                     /**< (I) Number of arguments */
        );
    
    /**
     * Launches external simulation tool as per the pre-defined configuration.
     * <br/>The configuration can be defined through the External Simulation Process framework.
    * <br/>A valid configuration for the tool must be created in CAEManager by Simulation Administrator or user with dba privileges, before this ITK is called.
    *
    * @returns
    * <ul>
    * <li>#ITK_ok on success.</li>
    * <li>#CAE_sim_process_launch_log_file_not_created if the log file cannot be created.</li>
    * <li>#CAE_sim_process_launch_working_dir_not_created if the working directory cannot be created.</li>
    * <li>#CAE_sim_process_launch_process_not_specified if the simulation tool is not specified.</li>
    * <li>#CAE_sim_process_launch_process_input_types_undefined if the primary input types are not defined.</li>
    * <li>#CAE_sim_process_launch_process_input_rule_undefined if the primary input rule is not defined.</li>
    * <li>#CAE_sim_process_launch_script_not_specified if the launch script is not defined.</li>
    * <li>#CAE_sim_process_launch_no_file_to_export if the input files for the tool are not found.</li>
    * <li>#CAE_sim_process_workingdir_empty_space if the working directory path cannot contain spaces.</li>
    * <li>#CAE_error_in_xerces_c_initialization if an error occurred while initializing the parser.</li>
    * <li>#CAE_error_while_parsing_file if an error occurred while parsing the configuration file.</li>
    * <li>#CAE_sim_process_launch_workflow_min_max_error if the number of inputs to the tool is not between the minimum criteria and maximum criteria defined for the simulation tool.</li>
    * <li>#CAE_sim_process_launch_script_space_error if the input launch script path contains spaces, and cannot, therefore, be executed.</li>
    * </ul>
    */
    extern CAE_API int CAE_launch_simulation_tool_asynchronous(
        int array_count,                       /**< (I) First dimension of the arrays @p input_objects_array and @p cntx_objects_array. */
        const int* objects_count,              /**< (I) Second dimension of the arrays @p input_objects_array and @p cntx_objects_array. */
        const tag_t*** input_objects_array,    /**< (I) Array of array (two-dimensional array) of tags of business objects passed as reference.*/
        const tag_t*** cntx_objects_array,     /**< (I) Corresponding array of array (two-dimensional array) of tags of configuration context objects passed as reference. */
        const char* tool_name,                 /**< (I) Name of the configured tool to be launched. */
        const char* launch_type,               /**< (I) Launch type for the process. It could be "LOCAL" or "REMOTE" */
        const char* item_creation,             /**< (I) Item creation options for the process. It could be either "As Needed", "Always" or "Never" */
        const char* dataset_creation,          /**< (I) Dataset creation options for the process. It could be either "As Needed", "Always" or "Never" */
        const char* plmxml_name,               /**< (I) PLMXML Export file name */
        const char* working_directory,         /**< (I) Path to the specified working directory in tool configuration, where the input data will be exported. */
        int argument_count,                    /**< (I) Number of arguments */
        const char** runtime_arguments         /**< (I) List of runtime arguments and their values.
                                                  <br/>Each argument and values are represented by a single string separated by the token "::"
                                                  <br/>E.g. "-fem" argument translates as "fem::".
                                                  <br/>E.g. "-dat=blk" argument translates as "dat::blk".*/
                                               );

    /**
    * Executes Data Mapping rules on a Input Structure and creates a Simulation Structure.
    */
    extern CAE_API int CAE_execute_datamap(
        tag_t rootIR,                         /**< (I)  Root Item Revision tag of the Input Structure. */
        tag_t snapshotFolder,                 /**< (I)  Snapshot folder tag. */
        tag_t revRule,                        /**< (I)  Revision rule tag of the input structure. */
        tag_t variantRule,                    /**< (I)  Variant Rule tag for the Input Structure. */
        char* domain,                         /**< (I)  Domain for datamapping. */
        const char** processLog,              /**< (OF) Process log. */
        tag_t* outputRoot                     /**< (OF) Root Item Revision tag of the Output Structure. */
        );

    /**
    * This ITK would be used to execute a StructureMap rules on a Input Structure and create a Simulation Structure as an output.
    */
    extern CAE_API int CAE_execute_structuremap(
        tag_t rootIR,                         /**< (I)  Root Item Revision tag of the Input Structure. */
        tag_t snapshotFolder,                 /**< (I)  Snapshot folder tag. */
        tag_t revRule,                        /**< (I)  Revision rule tag of the input structure. */
        tag_t variantRule,                    /**< (I)  Variant Rule tag for the Input Structure. */
        tag_t structureMapIR,                 /**< (I)  Structure Map Item Revision. */
        const char** processLog,              /**< (OF) Process log. */
        tag_t* outputRoot                     /**< (OF) Root Item Revision tag of the Output Structure. */
        );

    /**
    * Creates variants of the Input Structure by applying Derivative Rule.
    * @note The optional rootname, if not provided the source rootname is taken as input.
    * @note The optional index, if not provided the multiple derived structures will have no index suffices.
    * @returns
    * <ul>
    * <li>#ITK_ok on success.</li>
    * <li>#CAE_invalid_derive_xml if an invalid Derive XML is found.</li>
    * <li>#CAE_invalid_ruleset if derive rule does not exist.</li>
    * <li>#CAE_invalid_derive_domain if mapping domain is invalid.</li>
    * <li>#CAE_derive_operation_error if derive operation fails.</li>
    * </ul>
    */
    extern CAE_API int CAE_execute_derive_structures(
        tag_t source_ir,                       /**< (I)  Root Item Revision tag of the Input Structure. */
        tag_t struct_cntxt,                    /**< (I)  Structure context object tag. */
        tag_t dr_ir,                           /**< (I)  Derivative Rule to be applied. */
        const char* optional_rootname,         /**< (I)  Optional root name for output structure. */
        const char* optional_index,            /**< (I)  Optional index for output structure. */
        int struct_count,                      /**< (I)  Number of structures to be created */
        const char** process_log               /**< (O)  Process log. */
        );

    /**
     @deprecated #CAE_execute_simulation_tool_launch deprecated in Teamcenter 11.4. Use #CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input instead.

     Launches external simulation tool as per the pre-defined configuration.
     <br/>The configuration can be defined through the External Simulation Process framework.
     <br/>A valid configuration for the tool must be created in CAEManager by Simulation Administrator or user with dba privileges, before this ITK is called.
     @returns
     <ul>
     <li>#ITK_ok on success.</li>
     <li>#CAE_sim_process_launch_log_file_not_created if the log file cannot be created.</li>
     <li>#CAE_sim_process_launch_working_dir_not_created if the working directory cannot be created.</li>
     <li>#CAE_sim_process_launch_process_input_types_undefined if the primary input types are not defined.</li>
     <li>#CAE_sim_process_launch_process_input_rule_undefined if the primary input rule is not defined.</li>
     <li>#CAE_sim_process_launch_script_not_specified if the launch script is not defined.</li>
     <li>#CAE_sim_process_launch_no_file_to_export if the input files for the tool are not found.</li>
     <li>#CAE_sim_process_workingdir_empty_space if the working directory path cannot contain spaces.</li>
     <li>#CAE_sim_process_launch_workflow_min_max_error if the number of inputs to the tool is not between the minimum criteria and maximum criteria defined for the simulation tool.</li>
     <li>#CAE_sim_process_launch_script_space_error if the input launch script path contains spaces, and cannot, therefore, be executed.</li>
     </ul>     
    */
    TC_DEPRECATED("11.4","CAE_execute_simulation_tool_launch","CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input")
    extern CAE_API int CAE_execute_simulation_tool_launch(
        tag_t tool_tag,                                                                   /**< (I) Tag of Simulation Tool */
        int num_inputs,                                                                   /**< (I) Number of inputs to the Simulation Tool */
        const tag_t* input_objects_tags,                                                  /**< (I) Array of input object tags */
        const tag_t* configuration_context_tags,                                          /**< (I) Array of configuration context tags */
        const char* working_directory,                                                    /**< (I) Simulation Tool working directory */
        const char* launch_type,                                                          /**< (I) Simulation Tool launch type. It could be "LOCAL", "REMOTE", "SERVER, "LOCAL_DETACHED" */
        const CAE_tool_launch_export_config_runtime_overrides_t* export_config_overrides, /**< (I) Runtime overrides for export configuration of Simulation Tool */
        const CAE_tool_launch_import_config_runtime_overrides_t* import_config_overrides  /**< (I) Runtime overrides for import configuration of Simulation Tool */
        );


    /**
     @deprecated #CAE_execute_simulation_tool_launch2 deprecated in Teamcenter 11.4. Use CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input instead.

     Launches external simulation tool as per the pre-defined configuration.
     <br/>The configuration can be defined through the External Simulation Process framework.
     <br/>A valid configuration for the tool must be created in CAEManager by Simulation Administrator or user with dba privileges, before this ITK is called.
     @returns
     <ul>
     <li>#ITK_ok on success.</li>
     <li>#CAE_sim_process_launch_log_file_not_created if the log file cannot be created.</li>
     <li>#CAE_sim_process_launch_working_dir_not_created if the working directory cannot be created.</li>
     <li>#CAE_sim_process_launch_process_input_types_undefined if the primary input types are not defined.</li>
     <li>#CAE_sim_process_launch_process_input_rule_undefined if the primary input rule is not defined.</li>
     <li>#CAE_sim_process_launch_script_not_specified if the launch script is not defined.</li>
     <li>#CAE_sim_process_launch_no_file_to_export if the input files for the tool are not found.</li>
     <li>#CAE_sim_process_workingdir_empty_space if the working directory path cannot contain spaces.</li>
     <li>#CAE_sim_process_launch_workflow_min_max_error if the number of inputs to the tool is not between the minimum criteria and maximum criteria defined for the simulation tool.</li>
     <li>#CAE_sim_process_launch_script_space_error if the input launch script path contains spaces, and cannot, therefore, be executed.</li>
     </ul>     
    */
    TC_DEPRECATED("11.4","CAE_execute_simulation_tool_launch2","CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input")
    extern CAE_API int CAE_execute_simulation_tool_launch2(
        tag_t tool,                                                                       /**< (I) Tag of Simulation Tool */
        int num_inputs,                                                                   /**< (I) Number of inputs to the Simulation Tool */
        const tag_t* input_objects,                                                       /**< (I) num_inputs Array of input object tags */
        const tag_t* configuration_context,                                               /**< (I) num_inputs Array of configuration context tags */
        const char* working_directory,                                                    /**< (I) Simulation Tool working directory */
        const char* launch_type,                                                          /**< (I) Simulation Tool launch type. It could be "LOCAL", "REMOTE", "SERVER, "LOCAL_DETACHED" */
        const CAE_tool_launch_export_config_runtime_overrides_t* export_config_overrides, /**< (I) Runtime overrides for export configuration of Simulation Tool */
        const CAE_tool_launch_import_config_runtime_overrides_t* import_config_overrides, /**< (I) Runtime overrides for import configuration of Simulation Tool */
        int pedigree_info_size,                                                           /**< (I) Size of capture pedigree info for import configuration of Simulation Tool */
        const tag_t* pedigree_capture_info                                                /**< (I) pedigree_info_size Array of capture pedigree info for import configuration of Simulation Tool */
        );

    /**
     @deprecated #CAE_execute_simulation_tool_launch_with_datasets_files_and_file_upload_option deprecated in Teamcenter 11.4. Use CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input instead.

     Launches external simulation tool on interatively selected dataset and file as per the pre-defined configuration.
     <br/>The configuration can be defined through the External Simulation Process framework.
     <br/>A valid configuration for the tool must be created in CAEManager by Simulation Administrator or user with dba privileges, before this ITK is called.
     @returns
     <ul>
     <li>#ITK_ok on success.</li>
     <li>#CAE_sim_process_launch_log_file_not_created if the log file cannot be created.</li>
     <li>#CAE_sim_process_launch_working_dir_not_created if the @p working_directory cannot be created.</li>
     <li>#CAE_sim_process_launch_process_input_types_undefined if the primary input types in the @p tool are not defined.</li>
     <li>#CAE_sim_process_launch_process_input_rule_undefined if the primary input rule in the @p tool is not defined.</li>
     <li>#CAE_sim_process_launch_script_not_specified if the launch script in the @p tool is not defined.</li>
     <li>#CAE_sim_process_launch_no_file_to_export if the input files for the @p tool are not found.</li>
     <li>#CAE_sim_process_workingdir_empty_space if the @p working_directory path contains spaces.</li>
     <li>#CAE_sim_process_launch_workflow_min_max_error if @p num_inputs to the tool is not between the minimum criteria and maximum criteria defined for the simulation tool.</li>
     <li>#CAE_sim_process_launch_script_space_error if the input launch script path in the @p tool contains spaces, and cannot, therefore, be executed.</li>
     </ul>    
    */
    TC_DEPRECATED("11.4","CAE_execute_simulation_tool_launch_with_datasets_files_and_file_upload_option","CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input")
    extern CAE_API int CAE_execute_simulation_tool_launch_with_datasets_files_and_file_upload_option(
        tag_t tool,                                                                                                /**< (I) Tag of Simulation Tool */
        int num_inputs,                                                                                            /**< (I) Number of inputs to the Simulation Tool */
        const tag_t* input_objects,                                                                                /**< (I) num_inputs Array of input object tags. Parameter can have invalid value and in such case tool launch operation returns ITK_ok and continue process without any error*/
        const tag_t* configuration_context,                                                                        /**< (I) num_inputs Array of configuration context tags. Parameter can have invalid value and in such case tool launch operation returns ITK_ok and continue process without any error*/
        const tag_t* input_datasets,                                                                               /**< (I) num_inputs Array of input datasets tags. Parameter can have invalid value and in such case tool launch operation returns ITK_ok and continue process without any error*/
        const tag_t* input_files,                                                                                  /**< (I) num_inputs Array of input files tags. Parameter can have invalid value and in such case tool launch operation returns ITK_ok and continue process without any error*/
        const char* working_directory,                                                                             /**< (I) Simulation Tool working directory */
        const char* launch_type,                                                                                   /**< (I) Simulation Tool launch type. It could be "LOCAL", "REMOTE", "SERVER, "LOCAL_DETACHED" */
        const CAE_tool_launch_export_config_runtime_overrides_t* export_config_overrides,                          /**< (I) Runtime overrides for export configuration of Simulation Tool */
        const CAE_tool_launch_import_config_runtime_overrides_with_file_upload_option_t* import_config_overrides,  /**< (I) Runtime overrides for import configuration of Simulation Tool with file upload option */
        int pedigree_info_size,                                                                                    /**< (I) Size of capture pedigree info for import configuration of Simulation Tool */
        const tag_t* pedigree_capture_info                                                                         /**< (I) pedigree_info_size Array of capture pedigree info for import configuration of Simulation Tool */
        );

    /**
     @deprecated #CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input deprecated in Teamcenter 12.3. Use #CAE_execute_simulation_tool_launch_with_user_staging_dir instead.

     Launches an external simulation tool on a given Dataset and a given file as per a pre-defined configuration.
     <br/>The configuration is defined through the External Simulation Process framework.
     <br/>A valid configuration for the tool must be created in CAEManager application by a Simulation Administrator or any user with DBA privileges, before this ITK is called.
     @returns
     <ul>
     <li>#ITK_ok on success.</li>
     <li>#CAE_sim_process_launch_log_file_not_created if the log file having Simulation tool launch operation information cannot be created.</li>
     <li>#CAE_sim_process_launch_working_dir_not_created if the @p working_directory does not exist yet and needs to be created, but the creation fails.</li>
     <li>#CAE_sim_process_launch_process_input_types_undefined if the primary input types in the @p tool are not defined.</li>
     <li>#CAE_sim_process_launch_process_input_rule_undefined if the primary input rule in the @p tool is not defined.</li>
     <li>#CAE_sim_process_launch_script_not_specified if the launch script in the @p tool is not defined.</li>
     <li>#CAE_sim_process_launch_no_file_to_export if the input files for the @p tool are not found.</li>
     <li>#CAE_sim_process_workingdir_empty_space if the path @p working_directory path contains spaces.</li>
     <li>#CAE_sim_process_launch_workflow_min_max_error if @p num_inputs is not between the minimum criterion and maximum criterion defined for the Simulation tool.</li>
     <li>#CAE_sim_process_launch_script_space_error if the input launch script path in the @p tool contains spaces, and cannot, therefore, be executed.</li>
     </ul>    
    */
    TC_DEPRECATED("12.3","CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input","CAE_execute_simulation_tool_launch_with_user_staging_dir")
    extern CAE_API int CAE_execute_simulation_tool_launch_with_file_upload_and_optional_input(
        const tag_t tool,                                                                                          /**< (I) The Simulation tool.*/
        const unsigned int n_inputs,                                                                               /**< (I) Number of inputs to the Simulation tool.*/
        const tag_t* input_objects,                                                                                /**< (I) n_inputs The input objects. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* configuration_context,                                                                        /**< (I) n_inputs The input Configuration Contexts. <br/> If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* input_datasets,                                                                               /**< (I) n_inputs The input Datasets. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* input_files,                                                                                  /**< (I) n_inputs The input Files. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const char* working_directory,                                                                             /**< (I) The path to the working directory of the Simulation tool.*/
        const char* launch_type,                                                                                   /**< (I) The launch type of the Simulation tool. Valid values are "LOCAL", "REMOTE", "SERVER, "LOCAL_DETACHED".*/
        const CAE_tool_launch_export_config_runtime_overrides_t* export_config_overrides,                          /**< (I) Runtime overrides for export configuration of the Simulation tool.*/
        const CAE_tool_launch_import_config_runtime_overrides_with_file_upload_option_t* import_config_overrides,  /**< (I) Runtime overrides for import configuration of the Simulation tool with the file upload option.*/
        const unsigned int n_pedigree_info,                                                                        /**< (I) Number of capture pedigree information for import configuration of the Simulation tool.*/
        const tag_t* pedigree_capture_info,                                                                        /**< (I) n_pedigree_info The capture pedigree information for import configuration of the Simulation tool.*/
        const unsigned int n_optional_input,                                                                       /**< (I) Number of optional input configured for the Simulation tool.*/
        const tag_t* optional_input_item_revisions,                                                                /**< (I) n_optional_input The Item Revisions configured for the optional input.*/
        const char** optional_input_export_directories                                                             /**< (I) n_optional_input  The path to the export directories to be provided during the optional input configuration for the Simulation tool.*/
        );

    /**
    Launches an external simulation tool on a given Dataset and a given file as per a pre-defined configuration.
    <br/>The configuration is defined through the External Simulation Process framework.
    <br/>A valid configuration for the tool must be created in CAEManager application by a Simulation Administrator or any user with DBA privileges, before this ITK is called.
    <br/>It exports the file(s) into staging directory if tool is configured to use staging directory, otherwise it uses scratch driectory to export file(s).
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#CAE_scratch_directory_not_created if the @p scratch_directory does not exist yet and needs to be created, but the creation fails.
    <li>#CAE_staging_directory_not_created if the @p staging_directory does not exist yet and needs to be created, but the creation fails.
    <li>#CAE_sim_process_launch_process_input_types_undefined if the primary input types in the @p tool are not defined.
    <li>#CAE_sim_process_launch_script_not_specified if the launch script in the @p tool is not defined.
    <li>#CAE_sim_process_launch_workflow_min_max_error if @p n_inputs is not between the minimum criterion and maximum criterion defined for the Simulation tool.
    <li>#CAE_sim_process_launch_script_space_error if the input launch script path in the @p tool contains spaces, and cannot, therefore, be executed.
    </ul>
    */
    extern CAE_API int CAE_execute_simulation_tool_launch_with_user_staging_dir(
        const tag_t tool,                                                                                          /**< (I) The Simulation tool.*/
        const unsigned int n_objects,                                                                              /**< (I) Number of objects to the Simulation tool.*/
        const tag_t* objects,                                                                                      /**< (I) n_objects The objects. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* configuration_context,                                                                        /**< (I) n_objects The object Configuration Contexts. <br/> If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* datasets,                                                                                     /**< (I) n_objects The object Datasets. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* files,                                                                                        /**< (I) n_objects The object Files. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const tag_t* web_links,                                                                                    /**< (I) n_objects The Object Web Links. <br/>If any value is invalid, the tool launch operation returns #ITK_ok and continues without any error.*/
        const char* scratch_directory,                                                                             /**< (I) The path to the scratch directory of the Simulation tool.*/
        const char* staging_directory,                                                                             /**< (I) The path to the staging directory of the Simulation tool.*/
        const char* launch_type,                                                                                   /**< (I) The launch type of the Simulation tool. Valid values are "LOCAL", "REMOTE", "SERVER, "LOCAL_DETACHED". <br/> If invalid value is provided, the tool launch operation continues with "REMOTE".*/
        const CAE_tool_launch_export_config_runtime_overrides_t* export_config_overrides,                          /**< (I) Runtime overrides for export configuration of the Simulation tool.*/
        const CAE_tool_launch_import_config_runtime_overrides_with_file_upload_option_t* import_config_overrides,  /**< (I) Runtime overrides for import configuration of the Simulation tool with the file upload option.*/
        const unsigned int n_pedigree_info,                                                                        /**< (I) Number of capture pedigree information for import configuration of the Simulation tool.*/
        const tag_t* pedigree_capture_info,                                                                        /**< (I) n_pedigree_info The capture pedigree information for import configuration of the Simulation tool.*/
        const unsigned int n_optional_object,                                                                      /**< (I) Number of optional object configured for the Simulation tool.*/
        const tag_t* optional_object_item_revisions,                                                               /**< (I) n_optional_object The Item Revisions configured for the optional input.*/
        const char** optional_object_export_directories,                                                           /**< (I) n_optional_object  The path to the export directories to be provided during the optional input configuration for the Simulation tool.*/
        const unsigned int n_export_file_info,                                                                     /**< (I) Number of export file options for the Simulation tool.*/
        const CAE_tool_launch_export_file_options_for_user_staging_directory_t* export_file_options                /**< (I) n_export_file_info The Export file options when Simulation Tool is configured to use staging directory.*/
    );
    
#ifdef __cplusplus
}
#endif

/** @} CAE_ITK group */

#include <cae/libcae_undef.h>
#endif

