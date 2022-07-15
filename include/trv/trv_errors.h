/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2015.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file
        Traversal errors
*/
#ifndef TEAMCENTER_TRV_ERRORS_HXX
#define TEAMCENTER_TRV_ERRORS_HXX

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

/**
    @defgroup TRV_ERRORS Traversal Errors
    @ingroup TRV
    @{
*/

#define TRV_ERROR_BASE                          EMH_TRV_error_base

/**
    The input provided is invalid.
*/
#define TRV_invalid_input                       (EMH_TRV_error_base + 1)

/**
    No traversal object found with key %1.
*/
#define TRV_no_traversal_object_found           (EMH_TRV_error_base + 2)

/**
    An internal error has occured in Generic Traversal module.
*/
#define TRV_internal_error                      (EMH_TRV_error_base + 3)

/**
    There are no candidates for synchronization.
*/
#define TRV_no_sync_candidates                  (EMH_TRV_error_base + 4)

/**
    Once set, the value of the option "%1$" cannot be modified, because it is used to control code logic.
*/
#define TRV_option_not_consistent               (EMH_TRV_error_base + 5)

/**
    The property "%1$" cannot be found in the table for the type "%2$". Please add that property to the Property Set, and try the export operation again.
*/
#define TRV_property_missing_in_table           (EMH_TRV_error_base + 6)

/**
    Unconfigured revision exports are not supported to unmanaged sites
*/
#define TRV_unconfigured_revision_export        (EMH_TRV_error_base + 7)

/**
  Wildcard characters are not supported for ATTRIBUTE and REFBY Relationship-selectors in the following Closure Rule Clause: %1$. 
*/
#define TRV_wildcard_not_supported              (EMH_TRV_error_base + 8)

/**
    The conditional clause of the closure rule "%1$" is invalid.
*/
#define TRV_invalid_conditional_clause          (EMH_TRV_error_base + 9)

/**
    The relation type "%1$" is not supported.
*/
#define TRV_invalid_relationshiptype            (EMH_TRV_error_base + 10)

/**
    The action "%1$" is not supported.
*/
#define TRV_invalid_action                      (EMH_TRV_error_base + 11)

/**
    The input object(s) have been previously replicated and will not be re-processed. To override this behavior, specify -force_retraverse on the command line.
*/
#define TRV_no_export_candidates                (EMH_TRV_error_base + 12)

/**
   The attribute "%1$" specified in the candidate key definition of the business object type "%2$" is invalid. Please correct the definition in the Business Modeler IDE.
*/
#define TRV_invalid_attribute_in_candidate_key  (EMH_TRV_error_base + 13)

/**
   The value "%1$" in the candidate key definition of the business object type "%2$" is invalid, because it does not start with the prefix "$". Please correct the definition in the Business Modeler IDE.
*/
#define TRV_invalid_field_in_candidate_key      (EMH_TRV_error_base + 14)

/**
    The specified clause "%1$" is not valid.
*/
#define TRV_invalid_clause                      (EMH_TRV_error_base + 15)

/**
    The traversal rule "%1$" uses a small array attribute "%2$", which is not supported to traverse objects. Small array attribute is an attribute array with length of less than eight.
*/
#define TRV_invalid_sa_attribute                (EMH_TRV_error_base + 16)

/**
    The Traversal Table "%1$" does not exist in the database. Please contact your system administrator.
*/
#define TRV_table_not_found                     (EMH_TRV_error_base + 17)

/**
    No configured revision is found for the given top line Item "%1$". In order to export the required structure, either change the default Revision Rule or choose a specific revision.
*/
#define TRV_no_configured_revision_for_topline  (EMH_TRV_error_base + 18)

/**
    The BOM Window to traverse is invalid
*/
#define TRV_invalid_bomwindow                   (EMH_TRV_error_base + 19)

/**
   The number of root objects is invalid. Provide a non-zero, positive number of root objects.
*/
#define TRV_invalid_number_of_root_objects      (EMH_TRV_error_base + 20)

/**
   Only one BOM Window can be supported for traversal
*/
#define TRV_more_than_one_bomwindow_error       (EMH_TRV_error_base + 21)

/**
   The BOM Window to traverse is not the same as the one set during the initialization of the traversal.
*/
#define TRV_inconsistent_bomwindow              (EMH_TRV_error_base + 22)

/**
    @}
*/

#endif
