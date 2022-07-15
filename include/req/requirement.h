/* Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2015
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    This file contains the function prototypes for working with the requirements class
    specifically with the C ITK interface to this class.

    */

/**  */


#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <tc/tc_startup.h>
#include <req/libreq_exports.h>

/**
    @defgroup REQ Requirements
    @ingroup TC

    Requirements Management allows users to export the teamcenter objects to Microsoft Office applications 
    like Word and Excel and allow them editing in live and offline mode. 
    <br>It also provides functions to extract user defined markups in word document and store them in Teamcenter.

    Teamcenter makes use of this mechanism itself, and it also provides ITK level functions for programmers 
    to make use of the same.
    <br>Programmers can define their own requirement codes if they wish, or they can write their own functions 
    to export / import the objects.

    If you intend to add new requirement codes, we suggest that you prefix them with your company name,
    thus ensuring that they will not conflict with any requirement codes that Teamcenter may implement in the future.

    @note Teamcenter may alter or obsolete requirement codes as the product evolves.
    These changes will be documented in the Release Notes.

    The ITK requirements functions include:
    <ul>
    <li>A function to export objects/requirement structure to MS Word. 
    <li>A function to objects / structure to MS Excel either in live mode or offline mode.
    <li>A function to collect markup data from word document.
    </ul>

    To use these functions, include requirements.h.
@{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/** Defines the mode used to specify the operation to export the word document as a static report.  */
#define REQ_export_as_ms_word_xml           "MSWordXML"
/** Defines the mode used to specify the operation to export the word document as a live word document. */
#define REQ_export_as_ms_word_xml_live      "MSWordXMLLive"
/** Defines the mode used to specify the operation to export the word document as a structured and live word document. */
#define REQ_export_as_structure_contents    "StructureWithContents"
/** Defines the mode used to specify the operation to export the word document as a markup word document. */
#define REQ_export_as_ms_word_markup        "ReqMarkupMgmt"
/** Defines the mode used to specify the operation to export the word document as a markup live word report. */
#define REQ_export_as_ms_word_markup_live   "ReqMarkupMgmtFN"
/** Defines the name of the preference used to store the url used to connect to 4-tier server. */
#define REQ_url_server_preference           "WEB_default_site_server"
/** Defines the name of the preference used to store the protocol used (HTTP/HTTPS) to connect to the 4-tier server url. */
#define REQ_url_protocol_preference         "WEB_protocol"
/** Defines the name of the preference used to store the teamcenter application name for 4-tier. */
#define REQ_url_application_name            "WEB_default_site_deployed_app_name"

/**
    Structure used by the import and export functionalities to specify the options
*/
typedef struct
{
    char* option; /**< Option name. */    
    char* value;  /**< Option value. */
}REQ_importexport_options_t;

/**
     Defines the valid content types of the FullText object.
*/
typedef enum REQ_content_types_e{ 
    REQ_HTML,      /**< The content of the fulltext dataset is of type html. */
    REQ_PLAINTEXT, /**< The content of the fulltext dataset is of type plain text. */
    REQ_RICHTEXT   /**< The content of the fulltext dataset is of type rich text (MS Word compatible). */
}REQ_content_types_t; 

/** 
    Exports the Teamcenter objects to a Word document. 
    <br/>The exported document can be used for structure editing and work offline or for editing properties of objects.
    @returns
    <ul>
        <li>#ITK_ok on success.
        <li>#REQ_multiple_object_not_allowed if multiple objects are exported for StructureWithContents/StructureOnly operation. 
        <li>#REQ_default_styles_template_not_found if no default templates(as defined in the preference REQ_default_struct_template/REQ_default_object_template) were found to export the document.
        <li>#REQ_Word_template_not_found  if the word template used to export is not found on the system.
        <li>#REQ_content_object_not_found if the object template does not have any fulltext property.
        <li>Possibly other errors
    </ul>
*/
extern REQ_API int REQ_word_export(
        int size,                                          /**< (I) Number of tags */
        const tag_t* bom_lines,                            /**< (I) Tags of BOMLines to export */        
        logical deep,                                      /**< (I) Logical flag to decide whethere to traverse the tree or not */
        int document_type,                                 /**< (I) Type of document (0 for static and 1 for live) */
        const char* specification_template,                /**< (I) Specification Template override */
        int object_template_count,                         /**< (I) Count of objecttemplate override */
        const char** bo_type,                              /**< (I) Types of Business Object Overrides */
        const char** object_template,                      /**< (I) Object templates for BO type */
        int export_option_count,                           /**< (I) Number of export options */ 
        const REQ_importexport_options_t* export_options,  /**< (I) Array of export options */
        const char* mode_of_operation,                     /**< (I) Mode of operation while exporting.
                                                              <br/>Valid values are:
                                                              <ul>
                                                              <li>MSWordXML
                                                              <li>MSWordXMLLive
                                                              <li>MSWordXMLFN
                                                              <li>MSWordXMLLiveFN
                                                              <li>StructureWithContents
                                                              <li>StructureOnly
                                                              <li>MSWordXMLLiveMarkup
                                                              <li>MSWordXMLLiveMarkupFN
                                                              </ul>
                                                           */
        char **document_location                           /**< (OF) Location of the generated Word document in file system */
);


/** 
    Exports the Teamcenter objects to Excel file. 
    <br/>The exported sheet can also be used for bulk update or reimport depending upon the applicationFormat.
    @returns
    <ul>
        <li>#ITK_ok on success.
        <li>#REQ_no_attributes_for_export if no attributed are specified in attributes.
        <li>#REQ_excel_template_not_found if no excel template is found for export.         
        <li>#REQ_cannot_export_packing_template if Packing enabled template is selected for working offline and reimport
        <li>#REQ_cannot_export_by_view if export by view is selected for offline work and reimport from Structure Manager.
        <li>#REQ_not_supported_for_reimport if user exports from newstuff/mailbox, etc. where export for structure editing is not supported.
        <li>#REQ_runtimeobjects_not_supported if user exports runtime objects for structure editing and work offline. 
        <li>#REQ_excel_outline_limit_static if user tries to export more than 8 levels of hierarchy in static mode. MS Excel's outlining feature is limited to 8 levels.
        <li>#REQ_excel_outline_limit_reimport if user tries to export more than 8 levels of hierarchy in reimport. MS Excel's outlining feature is limited to 8 levels.
        <li>#REQ_excel_duplicate_columns_found if user exports duplicate columns to Excel.
        <li>Possibly other errors
    </ul>
*/
extern REQ_API int REQ_excel_export(
            int object_count,                                 /**< (I) objects count selected for export */
            const tag_t* objects,                             /**< (I) objects selected for export */
            int attribute_count,                              /**< (I) Attribute count */            
            const char** attributes,                          /**< (I) Attributes */
            const char* template_name,                        /**< (I) Name of Template to be exported */
            const char* application_format,                   /**< (I) Application format. Supported application format for this operation are:                                                                    
                                                                          <ul>
                                                                              <li>MSExcel: This format is used for exporting Teamcenter objects to static MSExcel  application.</li>
                                                                              <li>CSV: This format is used for exporting Teamcenter objects in a comma separated file format used for audit purpose.</li>
                                                                              <li>MSExcelLive: This format is used for exporting Teamcenter objects to Live MSExcel  application.</li>
                                                                              <li>MSExcelReimport: This format is used for exporting Teamcenter objects to MSExcel  application for reimport purpose.</li>
                                                                              <li>MSExcelLiveBulkMode: This format is used for exporting Teamcenter objects to MSExcel  application for Bulk Live mode so that user can make all the property changes and save all the changes to Teamcenter on click of “Save to Teamcenter” button.</li>
                                                                          </ul>*/                                                                  
            int export_option_count,                          /**< (I) Number of export options */ 
            const REQ_importexport_options_t* export_options, /**< (I) Array of export options */
            char**  file_path                                 /**< (OF) Generated Excel file path */
);


/**
    Retrieves a consolidated Markup file given a list of Requirement IDs. 
    <br/>For multiple requirements, different markup files are combined into one file and its path is returned.
    @returns
    <ul>
        <li>#ITK_ok on success.
        <li>#REQ_bad_parameter if parameter missing, not valid, null.
        <li>#REQ_relation_type_not_found if the relation for markup does not exist.
        <li>Possibly other errors
    </ul>
*/
extern REQ_API int REQ_collect_markups(
        int     req_rev_count,                   /**< (I) Number of requirements */
        const tag_t*  req_rev_list,              /**< (I) Requirement IDs */
        char**  markup_file_path                 /**< (OF) The consolidated markup file location  */
);

/**
    Sets the content on the Fulltext object attached to revision object.
    <br>Accepts both revision and Fulltext tag as input. In case revision is input, it will traverse to Fulltext object attached to it.
    @returns
     <ul>
        <li>#ITK_ok on success.
        <li>#REQ_bad_parameter if parameter missing, not valid, null.
        <li>Possibly other errors
    </ul>
*/
extern REQ_API int REQ_set_contents(
    tag_t rev_or_fulltext_tag,                  /**< (I) Tag of revision or fulltext object. If revision is specified, it will traverse to its fulltext object. */
    REQ_content_types_t content_type,           /**< (I) Type of content to set on the fulltext, i.e. Plain/HTML/Rich Text(MS Word compatible) */
    const char*  contents                       /**< (I) The actual content to set on fulltext object */
);

/**
    Sets the content on the Fulltext object attached to revision object.
    <br>Accepts both revision and Fulltext tag as input. In case revision is input, it will traverse to Fulltext object attached to it.
    If no fulltext object is attached to revision, ITK will create new full text object.
    @returns
     <ul>
        <li>#ITK_ok on success.
        <li>#REQ_bad_parameter if parameter missing, not valid, null.
        <li>#GRM_relationship_not_allowed if IMAN_Specification is not allowed between primary object and fulltext.
        <li>Possibly other errors
    </ul>
*/
extern REQ_API int REQ_create_set_contents(
    tag_t rev_or_fulltext_tag,                  /**< (I) Tag of revision or fulltext object. If revision is specified, it will traverse to its fulltext object. */
    REQ_content_types_t content_type,           /**< (I) Type of content to set on the fulltext, i.e. Plain/HTML/Rich Text(MS Word compatible) */
    const char*  contents                       /**< (I) The actual content to set on fulltext object */
);

#ifdef __cplusplus
}
#endif

/** @} */

#include <req/libreq_undef.h>
#endif
