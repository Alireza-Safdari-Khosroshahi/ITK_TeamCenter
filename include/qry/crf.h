/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef CRF_H
#define CRF_H

#include <tc/tc_startup.h>
#include <ss/ss_const.h>
#include <pie/pie.h>

#include <qry/libqry_exports.h>

#define CRF_REP_name_size_c    128
#define CRF_REP_desc_size_c    512
#define CRF_REP_id_size_c      32
#define CRF_REP_source_size_c  32
#define CRF_REP_class_size_c   32
#define CRF_REP_folder_name_size_c   32

#define XML_REPORT_FORMATTER    "XMLReportFormatter" /*TODO delete me.*/

#define CRF_XML_STYLESHEET      "CrfXmlStylesheet"
#define CRF_HTML_STYLESHEET     "CrfHtmlStylesheet"
#define CRF_EXCEL_STYLESHEET    "CrfExcelStylesheet"
#define CRF_TEXT_STYLESHEET     "CrfTextStylesheet"
#define CRF_PDF_STYLESHEET      "CrfPdfStylesheet"
#define CRF_MSWORD_STYLESHEET   "CrfMSWordDocStylesheet"
#define CRF_NEWEXCEL_STYLESHEET  "MSExcelX"
#define CRF_NEWMSWORD_STYLESHEET "MSWordX"

#define CRF_DEFAULT_REPORT_EXTENSION ".xml"
#define CRF_HTML_EXTENSION           ".html"
#define CRF_EXCEL_EXTENSION          ".xls"
#define CRF_EXCEL_OOXML_EXTENSION    ".xlsx"
#define CRF_PDF_EXTENSION            ".pdf"
#define CRF_TEXT_EXTENSION           ".txt"
#define CRF_MSWORD_EXTENSION         ".doc"
#define CRF_NEWEXCEL_EXTENSION       ".xlsm"
#define CRF_NEWWORD_EXTENSION        ".docm"


#define CRF_OUTPUT_HTML_DATASET_TYPES     "CrfOutputHtml"
#define CRF_OUTPUT_EXCEL_DATASET_TYPES    "CrfOutputExcel"
#define CRF_OUTPUT_XML_DATASET_TYPES      "CrfOutputXml"
#define CRF_OUTPUT_PDF_DATASET_TYPES      "CrfOutputPdf"
#define CRF_OUTPUT_TEXT_DATASET_TYPES     "CrfOutputText"
#define CRF_OUTPUT_MSWORD_DATASET_TYPES   "CrfOutputMSWord"


#define CRF_OUTPUT_HTML_NAMED_REF     "HTML"
#define CRF_OUTPUT_EXCEL_NAMED_REF    "excel"
#define CRF_OUTPUT_XML_NAMED_REF      "XML"  
#define CRF_OUTPUT_PDF_NAMED_REF      "PDF"
#define CRF_OUTPUT_TEXT_NAMED_REF     "Text"
#define CRF_OUTPUT_MSWORD_NAMED_REF   "word"

#define XSL_REF                 "XSL"

#define urlServerPreference         "WEB_default_site_server"
#define urlProtocolPref             "WEB_protocol"
#define urlApplicationName          "WEB_default_site_deployed_app_name"
#define NAME_PROP                   "object_name"
#define REP_LOCALE_STR              "report_locale"
#define REP_LOCALE_VAL              "en_US"
#define OFFICE_LIVE                 "OfficeLive"
#define BOM_REP_TYPE                "BOMReport"
#define BOM_REP_CRITERIA            "BOM_REPORT"
#define BOM_REP_CRITERIA_VAL        "TRUE"
#define REP_NAME_STRING             "report_name"
#define REV_RULE                    "REV_RULE"
#define ITEM_REP_TYPE               "ItemReport"
#define URL_GEN_SUMMARY_REP         "URLGenSummaryReport"

/*TC release subrelease then rept type*/
#define CRF_SUM_REPORT_ID_PREFIX     "TC_9_00_SUM_RPT_"
#define CRF_ITM_REPORT_ID_PREFIX     "TC_9_00_ITM_RPT_"
#define CRF_CUS_REPORT_ID_PREFIX     "TC_9_00_CUS_RPT_"  

#ifdef __cplusplus
    extern "C"{
#endif

typedef enum CRF_report_type_e {
    CRF_REPORT_SUMMARY,          /* summary report */
    CRF_REPORT_ITEM_REPORT,      /* item report */
    CRF_REPORT_CUSTOM_REPORT,    /* custom report */
    CRF_ALL_REPORTS              /* All reports */
} CRF_report_type_t;


typedef enum CRF_qry_source_type_e {
    CRF_TC_QUERY,                /** For summary reports, IManQuery is the data source */
    CRF_TRANSFER_MODE            /** For item reports, transfer mode is data source for query */
} CRF_qry_source_type_t;


/**
    This function creates a  report definition in the database.
*/
extern QRY_API int CRF_create_report_definition(
        const char*     id,                      /**< (I) */
        const char*     name,                    /**< (I) */  
        const char*     description,             /**< (I) */
        const char*     rpt_class,               /**< (I) */
        int             report_type,             /**< (I) */
        const char*     folder_name,             /**< (I) */
        int             state,                   /**< (I) */
        const char*     source,                  /**< (I) */
        int             no_of_params,            /**< (I) */
        const char**    rd_parameters,           /**< (I) */
        const char**    rd_values,               /**< (I) */
        tag_t           query_source,            /**< (I) */
        tag_t           property_source,         /**< (I) */
        int             no_style_sheets,         /**< (I) */
        tag_t*          style_sheets,            /**< (I) */
        tag_t*          report_definition        /**< (O) */
     );

/**
    Returns report definitions of Report Builder reports based on input criteria.
    <br>Error returned if access is denied.
    <br>This funtion returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_access_denied when access is denied.
    </ul>
*/
extern QRY_API int CRF_get_report_definitions(
        const char*     reportId,                /**< (I) Report definition Id. <br>It can be passed as a null pointer. */
        const char*     reportName,              /**< (I) Report definition Name. <br>It can be passed as a null pointer. */
        const char*     category,                /**< (I) Item report or summary reports etc. Valid value are summary, item and custom. <br>It can be passed as a null pointer. */
        const char*     source,                  /**< (I) Report definition defined by Teamcenter or others. Valid value are Teamcenter for general reports, Office Template for Office Template based reports. <br>It can be passed as a null pointer. */
        int             status,                  /**< (I) For future purpose only, in order to query based on Report Definition state attribute. <br>The value can be passed as 0. */
        int             no_of_context_objs,      /**< (I) Number of input context objects for item reports. <br>The value can be passed as 0. */
        tag_t*          context_objects,         /**< (I) Item report input context objects tags. <br>It can be passed as a null pointer. */
        int*            n_tags,                  /**< (O) The number of report definition returned. */
        tag_t**         report_definition_tags   /**< (OF) n_tags The returned report definition tags. */
    );

/**
    Generates a XML report file based on a report definition and criteria.

    The parameters criteria_count/criteria_names/criteria_values were initially designed for Summary and Custom Reports.
    For Summary reports these will be the saved query criteria names and values. 

    For Item reports these will not be used. 
    But there exists a special case: For PLMXML BOM reports user need to pass at least BOM_REPORT = TRUE

    Other valid values that can be passed for these BOM Reports are:
    CriteriaNames = {"BOM_REPORT", "REV_RULE","ARIANT_RULE","PACKED_BOM"}
    CriteriaValues = {"TRUE","<REV RULE NAME>","<VARIANT RULE NAME>","<TRUE/FALSE>"}
    NOTE: Variant RULE is not being passed from the UI. This is added for offline execution of reports using a report template and import_export_reports utility.

    For Custom Reports : It takes Process and Output related values. Also the other report parameters defined for it need to be passed.
    Looking at the UI dialog it gives a better picture of what Process and Output are and other parameters would be.

    If user wants to store the generated report as a dataset he can pass in the data_set_name or else an empty string.
    If data_set_name is passed, a new dataset will be created under users New Stuff folder and the generated report will be copied to it. 

    report_path_name is the full path of the report file that is generated on the server.
    If TC_TMP_DIR is specified . The report gets generated in that path. Else it is generated in the "C:\\temp" folder for Windows and "/tmp" folder for UNIX 
    The report file name is auto generated.
    <br/>Error returned if access is denied.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_access_denied when access is denied.
    </ul>
*/
extern QRY_API int CRF_generate_report (
                                        tag_t           report_definition_tag,   /**< (I) The report definition */
                                        tag_t           stylesheet_tag,          /**< (I) The style sheet. <br>It can be passed as NULLTAG. */
                                        int             no_of_context_objs,      /**< (I) Num of input context objects for item reports. <br>The value can be passed as 0. */
                                        tag_t*          context_objects,         /**< (I) Item report input context objects tags. <br>It can be passed as a null pointer. */
                                        int             criteria_count,          /**< (I) Num of criteria. <br>The value can be passed as 0. */
                                        char**          criteria_names,          /**< (I) For Item reports this will not be used. But there exists a special case: For PLMXML BOM reports user need to pass at least BOM_REPORT. Other valid values that can be passed for these BOM Reports are CriteriaNames = {"BOM_REPORT", "REV_RULE","VARIANT_RULE","PACKED_BOM"} */
                                        char**          criteria_values,         /**< (I) For Item reports this will not be used. But there exists a special case: For PLMXML BOM reports user need to pass at least TRUE. Other valid values that can be passed for these BOM Reports are CriteriaValues = {"TRUE","<REV RULE NAME>","<VARIANT RULE NAME>","<TRUE/FALSE>"} */
                                        char*           data_set_name,           /**< (I) If user wants to store the generated report as a dataset he can pass in the dataset name or else an empty string. <br>It can be passed as a null pointer. */
                                        char**          report_path_name         /**< (OF) Report Path name is the full path of the report file that is generated on the server. */
                                        );

/**
    Generates a XML report file based on a report definition with more parameters.
    <br>Error returned if access is denied.
    <br>This funtion returns:
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_access_denied when access is denied.
    </ul>
*/
extern QRY_API int CRF_generate_report_1 (
        tag_t           report_definition_tag,   /**< (I)  The tag for the report definition */
        char*           report_name,             /**< (I)  The name of the report. <br>It can be passed as a null pointer. */
        char*           stylesheet_name,         /**< (I)  The name of the stylesheet. <br>It can be passed as a null pointer. */
        tag_t           stylesheet_tag,          /**< (I)  The tag to the stylesheet. <br>It can be passed as NULLTAG. */
        int             no_of_context_objs,      /**< (I)  The no of input context objects for item reports. <br>The value can be passed as 0. */
        tag_t*          context_objects,         /**< (I)  The context context objects tags. <br>It can be passed as a null pointer. */
        int             criteria_count,          /**< (I)  The number of criterias. <br>The value can be passed as 0. */
        char**          criteria_names,          /**< (I)  The criteira names. <br>It can be passed as a null pointer. */
        char**          criteria_values,         /**< (I)  The criteria values. <br>It can be passed as a null pointer. */
        char*           data_set_name,           /**< (I)  The dataset name. <br>It can be passed as a null pointer. */
        char*           data_set_type,           /**< (I)  The dataset type. <br>It can be passed as a null pointer. */
        char*           relation_name,           /**< (I)  The relation name to be used if none reference is used. <br>It can be passed as a null pointer. */
        tag_t           context_object,          /**< (I)  Context object in which the report is generated. <br>It can be passed as NULLTAG. */
        char**          report_path_name         /**< (OF) The path to the report. */
    );

/**
    Generates a XML report file based on a report definition with more parameters.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#POM_access_denied when access is denied.
    </ul>
*/
extern QRY_API int CRF_generate_report_2 (
        tag_t           report_definition_tag,   /**< (I)  The tag for the report definition */
        char*           report_name,             /**< (I)  The name of the report. <br>It can be passed as a null pointer. */
        char*           stylesheet_name,         /**< (I)  The name of the stylesheet. <br>It can be passed as a null pointer. */
        tag_t           stylesheet_tag,          /**< (I)  The tag to the stylesheet. <br>It can be passed as NULLTAG. */
        int             no_of_context_objs,      /**< (I)  The no of input context objects for item reports. <br>The value can be passed as 0. */
        tag_t*          context_objects,         /**< (I)  The context context objects tags. <br>It can be passed as a null pointer. */
        int             criteria_count,          /**< (I)  The number of criterias. <br>The value can be passed as 0. */
        char**          criteria_names,          /**< (I)  The criteira names. <br>It can be passed as a null pointer. */
        char**          criteria_values,         /**< (I)  The criteria values. <br>It can be passed as a null pointer. */
        char*           data_set_name,           /**< (I)  The dataset name. <br>It can be passed as a null pointer. */
        char*           data_set_type,           /**< (I)  The dataset type. <br>It can be passed as a null pointer. */
        char*           relation_name,           /**< (I)  The relation name to be used if none refernce is used. <br>It can be passed as a null pointer. */
        tag_t           context_object,          /**< (I)  Context object in which the report is generated. <br>It can be passed as NULLTAG. */
        int             report_options_count,    /**< (I)  The number of report options. <br>The value can be passed as 0. */
        char**          report_options_names,    /**< (I)  The report options names. <br>It can be passed as a null pointer. */
        char**          report_options_values,   /**< (I)  The report options values. <br>It can be passed as a null pointer. */
        char**          report_path_name         /**< (OF) The path to the report. */
    );

/**
    This function generates a new id for the report definition.
*/
extern QRY_API int CRF_generate_report_id ( 
        const char*     report_type_name,        /**< (I)  */
        char**          report_id                /**< (OF) */
    );

/**
   This function copies the file from the sorce directory to the transient volumes
*/
extern QRY_API int CRF_copy_report_to_transient_vol( 
        char*           filepath ,               /**< (I) */
        char**          transientVolumeDir,      /**< (OF)*/
        char**          copiedFileName           /**< (OF)*/
    );
    
extern QRY_API int CRF_get_item_report_definitions_of_parentclass(
        tag_t          parent_class_id,         /**< (I)  POM class  tag    */
        int*           n_tags,                  /**< (O) The number of report definition returned */
        tag_t**        report_definition_tags   /**< (OF) n_tags The returned report definition tags */
    );

/**
   This function generates the report when source is OfficeTemplate. This function is called by URL mechanism from a thin client.
   The parameters - report_definition_uid is the valid persistent uid of the reportdefinition.
   object_uid is the valid uid of the persistent object in Teamcenter, In case of BOMReport client passes the ItemRevision uid.
   template_name is the name of template which can be ExcelTemplate name or SpecTemplate name.
   rev_rule_uid is the uid of the selected revision rule by the client. This parameter is only used in case of BOMReport.
   isLive paraemter indicates if the generated report will be static report or Live report, Valid values are true/false
   report_type is the type of report. Valid values are ItemReport or BOMReport
   file_path is the generated report path.
   xml_string is the launch def xml file generated in case of Word Live reports. This launch def xml file is consumed by the Office App Launcher mechanism.
*/
extern QRY_API int CRF_generate_report_3(
        char*           report_definition_uid,   /**< (I)  The uid for the report definition */
        char*           object_uid,              /**< (I)  The uid of the object */
        char*           template_name,           /**< (I)  The name of the template */
        char*           rev_rule_uid,            /**< (I)  The uid of the revision rule */
        logical         isLive,                  /**< (I)  Is Live Sheet/document */
        char*           report_type,             /**< (I)  The type of report */
        char**          file_path,               /**< (OF) The generated file path */
        char**          xml_string               /**< (OF) The launch def XML */
    );

#ifdef __cplusplus
}
#endif

#include <qry/libqry_undef.h>

#endif
