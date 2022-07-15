/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2014
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/


/**
    @file

    Attribute and Product Target Management SOA Error Codes Declaration

*/

#ifndef ATT0SOAATTTARGETMGMT_ERRORS_H
#define ATT0SOAATTTARGETMGMT_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup ATT0SOAATTTARGETMGMT_ERRORS Errors for the SOA operations of the Attribute and Product Target Management solution
    @ingroup ATT0ATTRTARGETMGMT
    @{
*/


#define ATT0SOAATTTARGETMGMT_ERROR_BASE                                       EMH_ATT0SOAATTRTARGETMGMT_error_base 

/** The Item or Item Revision type cannot be empty to find attribute definitions. Please specify the value in the definition criteria. */
#define ATT0SOAATTTARGETMGMT_empty_item_or_revision_type                      (EMH_ATT0SOAATTRTARGETMGMT_error_base +   1 )

/** The given Item or Item Revision type "%1$" does not exist. Please specify an existing Item or Item Revision type name in the definition criteria. */
#define ATT0SOAATTTARGETMGMT_none_exist_item_or_revision_type                 (EMH_ATT0SOAATTRTARGETMGMT_error_base +   2 )

/** The value "%1$" is not a valid Item or Item Revision type. Please specify a valid Item or Item Revision type name in the definition criteria. */
#define ATT0SOAATTTARGETMGMT_invalid_item_or_revision_type                    (EMH_ATT0SOAATTRTARGETMGMT_error_base +   3 )

/** A valid parent object must be specified. */
#define ATT0SOAATTTARGETMGMT_empty_parent_object                              (EMH_ATT0SOAATTRTARGETMGMT_error_base +   4 )

/** A value for the measurable attribute parameter must be provided in order to complete the "Delete" operation. */
#define ATT0SOAATTTARGETMGMT_empty_input_attribute_list                       (EMH_ATT0SOAATTRTARGETMGMT_error_base +   5 )

/** The measurable attribute "%1$" could not be deleted, because it is referenced in the Analysis Request "%2$". */
#define ATT0SOAATTTARGETMGMT_attribute_referenced_in_ar                       (EMH_ATT0SOAATTRTARGETMGMT_error_base +   6 )

/** The measurable attribute "%1$" could not be deleted, because it is referenced by the context "%2$". */
#define ATT0SOAATTTARGETMGMT_attribute_referenced_by_another_context          (EMH_ATT0SOAATTRTARGETMGMT_error_base +   7 )

/** The measurable attribute "%1$" could not be deleted, because it is referenced by the object "%2$".*/
#define ATT0SOAATTTARGETMGMT_attribute_referenced_by_another_relation         (EMH_ATT0SOAATTRTARGETMGMT_error_base +   8 )

/** @} */


#endif 

