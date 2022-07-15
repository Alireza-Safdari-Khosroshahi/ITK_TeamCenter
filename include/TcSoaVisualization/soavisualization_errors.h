/** 
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2012.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/** 
    @file 

    Define error codes used with Tc soavisualization

*/

#ifndef SOAVISUALIZATION_ERRORS_H
#define SOAVISUALIZATION_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif


/**
    @defgroup SOAVISUALIZATION_ERRORS Visualization SOA Errors
    @ingroup SOAVISUALIZATION
    @{
*/

#define SOAVISUALIZATION_ERROR_BASE                                EMH_SOAVISUALIZATION_error_base
/** The attribute name or value provided to resolve an occurrence chain is empty. */
#define  SOAVISUALIZATION_attrnames_attrvalues_empty               (SOAVISUALIZATION_ERROR_BASE + 1)
/** The first element of attribute names array provided to resolve an occurrence chain is empty. */
#define  SOAVISUALIZATION_first_element_of_attrnames_empty         (SOAVISUALIZATION_ERROR_BASE + 2)
/** The provided "bl_absocc_uid_in_topline_context" attribute is not the first element of the attribute names array. */
#define  SOAVISUALIZATION_absoccuid_in_topline_not_first_element   (SOAVISUALIZATION_ERROR_BASE + 3)
/** The input parent BOM Line is invalid. */
#define  SOAVISUALIZATION_invalid_parent_bomline                   (SOAVISUALIZATION_ERROR_BASE + 4)

/** The related objects represented by the expanded BOM Line could not be retrieved. */
#define  SOAVISUALIZATION_unable_to_get_related_object_for_bomline (SOAVISUALIZATION_ERROR_BASE + 20)
/** The preferred JT file for the expanded BOM Line could not be retrieved. */
#define  SOAVISUALIZATION_unable_to_get_preferredjt_for_bomline    (SOAVISUALIZATION_ERROR_BASE + 21)
/** The Part and Manufacturing Information (PMI) sidecar JT file could not be retrieved for the expanded BOM Line. */
#define  SOAVISUALIZATION_unable_to_get_pmisidecar_for_bomline     (SOAVISUALIZATION_ERROR_BASE + 22)
/** The provided relation type "%1$" could not be found. */
#define  SOAVISUALIZATION_cannot_find_relation_type                (SOAVISUALIZATION_ERROR_BASE + 23)

/** A failure has occurred while attempting to create the object of type "VisStructureContext". Please consult the Teamcenter server syslog file for more information. */
#define  SOAVISUALIZATION_cannot_create_visstructurecontext        (SOAVISUALIZATION_ERROR_BASE + 30)

/** The Active Workspace services could not be located. Make sure the Active Workspace template has been installed. */
#define  SOAVISUALIZATION_awb_services_not_found                   (SOAVISUALIZATION_ERROR_BASE + 50)
/** The input product structure configuration recipe object is invalid. */
#define  SOAVISUALIZATION_input_recipe_object_not_valid            (SOAVISUALIZATION_ERROR_BASE + 51)
/** The BOM Index Administrative Data (BIAD) object definition cannot be found. Make sure the "bomindex_admin" utility has been run to configure a structure for indexing. */
#define  SOAVISUALIZATION_biad_object_not_found                    (SOAVISUALIZATION_ERROR_BASE + 52)
/** The Product Structure for the provided product configuration has not been configured for indexing. */
#define  SOAVISUALIZATION_not_configured_for_indexing              (SOAVISUALIZATION_ERROR_BASE + 53)

/** @} */


#endif

