/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2014.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    Erros codes for Fnd0Qualification APIs.
*/


#ifndef TEAMCENTER_FND0QUALIFICATION_ERRORS_H
#define TEAMCENTER_FND0QUALIFICATION_ERRORS_H

#include <common/emh_const.h>
#define FND0QUALIFICATION_error_base                                              EMH_FND0QUALIFICATION_error_base


/**   The current user does not have permission to create Qualification objects. */
#define FND0QUALIFICATION_create_permission_fail                                ( EMH_FND0QUALIFICATION_error_base + 1 )

/**   A Qualification Level with the name "%1$" already exists. */
#define FND0QUALIFICATION_level_already_exists_fail                             ( EMH_FND0QUALIFICATION_error_base + 2 )

/**   No Qualification Level with the name "%1$" can be found. */
#define FND0QUALIFICATION_level_not_exist_fail                                  ( EMH_FND0QUALIFICATION_error_base + 3 )

/**   The operation has failed, because the Qualification Level "%1$" is being referenced by other objects. Please find all references using the "Qualification" view, remove the unwanted references, and try again. */
#define FND0QUALIFICATION_qualification_level_referenced_fail                   ( EMH_FND0QUALIFICATION_error_base + 4 )

/**   The effective or expiration date for the User Qualification "%1$" is either empty or invalid. */
#define FND0QUALIFICATION_invalid_effective_or_expiration_date_fail             ( EMH_FND0QUALIFICATION_error_base + 5 )

/**   The effective date cannot be later than the expiration date. */
#define FND0QUALIFICATION_effective_date_greater_fail                           ( EMH_FND0QUALIFICATION_error_base + 6 )

/**   The expiration date requirement cannot be changed, because the Qualification "%1$" has already been assigned to users. Please find and remove all assignments using the "Qualifications" view, and try again. */
#define FND0QUALIFICATION_cannot_change_exp_date_requirement_fail               ( EMH_FND0QUALIFICATION_error_base + 7)

/**   The current user does not have permission to assign User Qualifications. */
#define FND0QUALIFICATION_assign_user_qualfication_permission_fail               ( EMH_FND0QUALIFICATION_error_base + 8)

/**   The operation cannot be performed, because Qualifications cannot persist without qualification levels. Please add at least one qualification level to the Qualification "%1$", and try again. */
#define FND0QUALIFICATION_qualification_without_level_fail                       ( EMH_FND0QUALIFICATION_error_base + 9)

/**   The current user does not have privileges to remove User Qualifications. */
#define FND0QUALIFICATION_remove_user_qualfication_privilege_fail                ( EMH_FND0QUALIFICATION_error_base + 10 )

/**   The current user does not have privileges to modify Qualification objects. */
#define FND0QUALIFICATION_update_qualification_privilege_fail                    ( EMH_FND0QUALIFICATION_error_base + 11 )

/** @} */

#endif
