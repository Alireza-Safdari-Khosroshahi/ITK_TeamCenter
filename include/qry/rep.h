/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef REP_H
#define REP_H

#include <tc/tc_startup.h>
#include <ss/ss_const.h>
#include <qry/libqry_exports.h>

/**
    @defgroup REP Report Writer
    @ingroup QRY

    The REP module is a sub module in the QRY module.
    It provides the interfaces to manage report designs.
    @{
*/

#define XML_REPORT_FORMATTER    "XMLReportFormatter"
#define EXCEL_REPORT_FORMATTER  "ExcelReportFormatter"
#define XSL_REF                 "XSL"
#define XLT_REF                 "XLT"

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Retrieves all report designs in the database.
*/
extern QRY_API int REP_design_extent (
    int*           n_tags,      /**< (O) The number of report design returned */
    tag_t**        design_tags  /**< (OF) n_tags The returned report design tags */
    );

/**
   Finds a report design in the database based on the input design name.
*/
extern QRY_API int REP_find_design (
    const char*    design_name,     /**< (I) A unique report design name */
    tag_t*         design_tag       /**< (O) The returned report design object tag */
    );

/**
   Generates a XML report file based on a report design.
*/
extern QRY_API int REP_generate_report (
    tag_t          design_tag,          /**< (I) A report design object tag */
    int            n_entries,           /**< (I) Number of entries in the criteria names and criteria values arguments */
    char**         criteria_names,      /**< (I) The saved query input criteria names */
    char**         criteria_values,     /**< (I) The saved query input criteria values */
    int            limitCount,          /**< (I) The number of objects in the limitList argument */
    tag_t*         limitList,           /**< (I) The list of objects to search within.
                                                 Users can limit the scope of search by using the limitList argument. */
    const char*    full_pathname        /**< (I) The full path name for the output XML file */
    );

/**
   Retrieves the query associated with the report design.
*/
extern QRY_API int REP_design_ask_query (
    tag_t          design_tag,  /**< (I) */
    tag_t*         query_tag    /**< (O) */
    );

/**
   Asks all report formatters associated with the report design.
   <br/>Report formatters are datasets that control the format of a selected report.
*/
extern QRY_API int REP_design_ask_formatters (
    tag_t          design_tag,      /**< (I) The report design object tag */
    int*           n_tags,          /**< (O) The number of dataset tags returned */
    char***        filenames,       /**< (OF) n_tags Names of the report formatters */
    tag_t**        dataset_tags     /**< (OF) n_tags Dataset tags of the report formatters */
    );

/**
    Creates a temporary directory in the specified location.
*/
extern QRY_API int REP_create_temp_directory (
    const char*         dirpath,              /**< (I)  */
    char**              created_dir,          /**< (OF) */
    char**              dir_name              /**< (OF) */
    );

/**
   Adds named references to the dataset.
*/
extern QRY_API int REP_save_named_ref (
    tag_t               dataset,              /**< (I)  */
    const char *        dirpath               /**< (I)  */
    );


/**
   Appends the Batch Request file with selected bom line information
*/
extern QRY_API int REP_append_batchfile_for_report (
    char**              itemid,               /**< (I)  */
    char**              itemuid,              /**< (I)  */
    char**              revisionid,           /**< (I)  */
    const char*         reportlocation,       /**< (I)  */
    char**              revisionrule,         /**< (I)  */
    const char*         variantrule,          /**< (I)  */
    const char*         transfermode,         /**< (I)  */
    const char*         formatter,            /**< (I)  */
    const char*         rt_product,           /**< (I)  */
    const char*         rt_prd_rev_rule,      /**< (I)  */
    const char*         rt_prd_var_rule,      /**< (I)  */
    const char*         rt_process,           /**< (I)  */
    const char*         hierarcyid,           /**< (I)  */
    const char*         level,                /**< (I)  */
    const char*         rt_plt,               /**< (I)  */
    const char*         rt_plt_rev_rule,      /**< (I)  */
    const char*         rt_plt_var_rule,      /**< (I)  */
    int                 numberoflines         /**< (I)  */
    );


/**
    Generates multiple html files for intermediate file outFile
*/
extern QRY_API int REP_generate_multiple_files (
    const char*         outFile,              /**< (I)  */
    const char*         dirPath               /**< (I)  */
    );

/**
   Transforms xml file using xsl into an intermediate file.
   @returns
   <ul>
   <li>#ITK_ok on success
   <li>#EMH_GENERIC_ERROR on Tranformation failure
   </ul>
*/
extern QRY_API int REP_apply_stylesheet(
    const char*         xmlFile,              /**< (I) The XML file generated using PLMXML/TCXML export. */
    const char*         xslFile,              /**< (I) The Stylesheet(XSL) file. */
    const char*         outFile,              /**< (I) The name of expected report output file with extension provided in the XSL file. */
    const char*         dirPath               /**< (I) The path of the directory that contains all the files. */
    );

/**
   Retrieves filenames under the directory
*/
extern QRY_API int REP_getfilenames (
    const char          *dirpath,           /**< (I)  */
    int*                n_filenames,        /**< (O)  */
    char***             filenames,          /**< (OF) n_filenames Names of the files */
    char***             abs_filenames       /**< (OF) n_filenames Names of the files */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <qry/libqry_undef.h>

#endif
