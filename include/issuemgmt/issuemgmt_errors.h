
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/** 
    @file 

    This file contains the declaration for issue management error codes

*/

#ifndef TEAMCENTER__ISSUEERRORS_H
#define TEAMCENTER__ISSUEERRORS_H

/*================================================================================================*/

#include <common/emh_const.h>
#include <issuemgmt/libissuemgmt_exports.h>

/**
 * Please perform the signoff by reviewing the issue report revision from the following menu entry 
 * in either the Rich Client or the Thin Client: Tools-&gt;Review Issue.
 */
#define ISSUEMGMT_review_issue_not_supported              (EMH_ISSUEMGMT_error_base + 0)
/**
 * The retrieval of the configuration context has failed. One possible cause is that the named reference does not exist.
 */
#define ISSUEMGMT_retrieve_conf_context_failed            (EMH_ISSUEMGMT_error_base + 1)
/**
 * The rebuild of the BOM window has failed. The configuration context object may be out-of-date or corrupted.
 */
#define ISSUEMGMT_build_bom_window_failed                 (EMH_ISSUEMGMT_error_base + 2)
/**
 * The retrieval of the view statistics data from the pv-view xml file "%1$" has failed. One possible cause is that 
 * the view statistics data is not defined. 
 */
#define ISSUEMGMT_retrieve_view_stat_data_failed          (EMH_ISSUEMGMT_error_base + 3)
/**
 * The retrieval of the pv-view xml file "%1$" has failed. Please check if the file exists. 
 */
#define ISSUEMGMT_retrieve_pv_view_file_failed            (EMH_ISSUEMGMT_error_base + 4)
/**
 * The retrieval of the pv-structure xml file "%1$" has failed. Please check if the file exists. 
 */
#define ISSUEMGMT_retrieve_pv_structure_file_failed       (EMH_ISSUEMGMT_error_base + 5)
/**
 * An error has occurred while saving the bookmark PLMXML file. Please refer to the Teamcenter server log 
 * file (plmxml framework) for details.
 */
#define ISSUEMGMT_generate_bomwriterexport_plmxml_failed  (EMH_ISSUEMGMT_error_base + 6)
/**
 * The retrieval of the issue review records for the issue "%1$" has not returned anything. The issue report revision 
 * may not have been reviewed yet. If this is the case, please verify that the issue management life cycle workflow is defined properly. 
 */
#define ISSUEMGMT_review_record_not_found                 (EMH_ISSUEMGMT_error_base + 7)

#include <issuemgmt/libissuemgmt_undef.h>

#endif
