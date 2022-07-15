/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file contains constants used throughout the ReleaseStatus class.
    It also contains the prototypes for the ITK functions for the Releasestatus class.
*/

/*  */

#ifndef TCCORE_RELEASESTATUS_H
#define TCCORE_RELEASESTATUS_H

#include <tccore/workspaceobject.h>
#include <common/tc_deprecation_macros.h>
#include <tccore/libtccore_exports.h>

/**
    @defgroup RELEASE_STATUS Release Status
    @ingroup TCCORE
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Creates release status object for given input status type.
    The function initializes start and end effectivity dates and start and end serial numbers to NULL.
    This means that the released objects will be effective for all dates and all serial numbers.

    See also CR_add_release_status(tag_t job, tag_t release_status).
   =============   
   !!!CAUTION!!!
   =============
   CR_create_release_status creates a release status with null value to the date_released property. 
   So the date_released property needs to be populated before the release status is added to workspace 
   objects.
   Use #RELSTAT_add_release_status which populates the date_released with the current date (if release status 
   has an invalid date) before adding the status. 
*/



/**
    Creates release status object for given input status type.
    The function initializes start and end effectivity dates and start and end serial numbers to NULL.
    This means that the released objects will be effective for all dates and all serial numbers.

    See also RELSTAT_add_release_status(tag_t job, tag_t release_status).
    =============   
    !!!CAUTION!!!
    =============
    RELSTAT_create_release_status creates a release status with null value to the date_released property. 
    So the date_released property needs to be populated before the release status is added to workspace 
    objects.
    Use #RELSTAT_add_release_status which populates the date_released with the current date (if release status 
    has an invalid date) before adding the status. 

    An error #POM_attr_null_forbidden will be returned if the input 
    status_type is null or an empty string.
    An error #POM_string_too_long will be returned if the input status_type is too long.
    No error is returned if the status type already exists.
*/
extern TCCORE_API int RELSTAT_create_release_status(
    const char     *status_type,                      /**< (I) The new status type to create. */
    tag_t*         release_status                     /**< (O) The newly created release status object. */
    );


/**
    Adds the given release status to each of the ws_objects, with an indicator to retain the released
    date or not.

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
    An error #POM_invalid_tag will be returned if the input count and/or the input set of Workspace objects does not 
    lead to valid objects.
*/
extern TCCORE_API int RELSTAT_add_release_status(
  tag_t   release_status,                         /**< (I) The release_status object. */
  int     count,                                  /**< (I) The number of objects to get a release_status object. */
  tag_t * ws_objects,                             /**< (I) The set of objects to get a release_status object. */
  logical retain_released_date                    /**< (I) The indicator of whether to keep the released date or not. */
);



/**
    Initializes release status with given status type.

    You normally use this function with subclass of object ReleaseStatus.
    Generally, this function follows immediately after #POM_create_instance.
    This function is used to initialize the attributes inherited from the ReleaseStatus.

    An error #POM_attr_null_forbidden will be returned if the input status_type is null or an empty string.
    An error #POM_string_too_long will be returned if the input status_type is too long.
*/
extern TCCORE_API int RELSTAT_initialize_release_status(
    tag_t          release_status,                  /**< (I) The release_status object to initialize. */
    const char     *status_type                     /**< (I) The status_type that the release_status will be initialized to. */
    );



/**
    Returns the status_type for the given release status.

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
*/
extern TCCORE_API int RELSTAT_ask_release_status_type(
    tag_t          release_status,                          /**< (I) The release_status object. */
    char           **release_status_type                    /**< (OF) The type of the given release_status object. */
    );




/**
    Sets the status_type for the given release status.

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
    An error #POM_attr_null_forbidden will be returned if the input 
    release_status_type is null or an empty string.
    An error #POM_string_too_long will be returned if the input release_status_type is too long.
*/
extern TCCORE_API int RELSTAT_set_release_status_type(
    tag_t          release_status,                          /**< (I) The release_status object. */
    const char     *release_status_type                     /**< (I) The status type to set on the object. */
    );


/**
    @deprecated #RELSTAT_ask_date_effectivity deprecated in Teamcenter 12.3. Use #WSOM_eff_ask_date_range instead.
    <br/>Release Status business object attributes(Start Date,End Date,Beginning Serial Number,Ending Serial Number) is deprecated and is replaced by Effectivity business object. In order to migrate Releasestatus effectivity to Effectivity, please refer to the link -
    http://docsstage.plm.automation.siemens.com/tdoc/tc/11.6/help#uid:effupgrade after migration use following function to get effective date values.
    @code
        WSOM_eff_ask_date_range
    @endcode

    Returns the effective start and end dates from the given release_status.

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
  */
TC_DEPRECATED( "12.3", "RELSTAT_ask_date_effectivity", "WSOM_eff_ask_date_range" )
extern TCCORE_API int RELSTAT_ask_date_effectivity(
    tag_t          release_status,  /**< (I) The release_status object. */
    date_t*        start_date,      /**< (O) The start date. */
    date_t*        end_date         /**< (O) The end date. */
    );

/**
    @deprecated #RELSTAT_set_date_effectivity deprecated in Teamcenter 12.3. Use #WSOM_eff_set_date_range instead.
    <br/>Release Status business object attributes(Start Date,End Date,Beginning Serial Number,Ending Serial Number) is deprecated and is replaced by Effectivity business object. In order to migrate Release Status effectivity to Effectivity, please refer to the link -
    http://docsstage.plm.automation.siemens.com/tdoc/tc/11.6/help#uid:effupgrade after migration use following function to set effective date values.
    @code
        WSOM_eff_set_date_range
    @endcode

    Sets the date effectivity on the given release_status.

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
    An error #EPM_cannot_edit_old_effectivities will be returned if the 
    current mode of V7 effectivity is set.
    An error #POM_invalid_date will be returned if the start_date or end_date are invalid dates.
    An error #EPM_end_before_start_date will be returned if the start_date is after than the end_date.
  */
TC_DEPRECATED( "12.3", "RELSTAT_set_date_effectivity", "WSOM_eff_set_date_range" )
extern TCCORE_API int RELSTAT_set_date_effectivity(
    tag_t          release_status,  /**< (I) The release_status object */
    date_t         start_date,      /**< (I) The start date */
    date_t         end_date         /**< (I) The end date */
    );

/**
    @deprecated #RELSTAT_ask_unit_effectivity deprecated in Teamcenter 12.3. Use #WSOM_eff_ask_unit_range instead.
    <br/>Release Status business object attributes(Start Date,End Date,Beginning Serial Number,Ending Serial Number) is deprecated and is replaced by Effectivity business object. In order to migrate Release Status effectivity to Effectivity, please refer to the link -
    http://docsstage.plm.automation.siemens.com/tdoc/tc/11.6/help#uid:effupgrade after migration use following function to get effective unit values.
    @code
        WSOM_eff_ask_unit_range
    @endcode

    Returns the unit effectivity from the given release_status.

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
  */
TC_DEPRECATED( "12.3", "RELSTAT_ask_unit_effectivity", "WSOM_eff_ask_unit_range" )
extern TCCORE_API int RELSTAT_ask_unit_effectivity(
    tag_t          release_status,  /**< (I) The release_status object */
    int*           start_num,       /**< (O) The unit start number */
    int*           end_num          /**< (O) The unit end number */
    );


/**
    @deprecated #RELSTAT_set_unit_effectivity deprecated in Teamcenter 12.3. Use #WSOM_eff_set_unit_range instead.
    <br/>Release Status business object attributes(Start Date,End Date,Beginning Serial Number,Ending Serial Number) is deprecated and is replaced by Effectivity business object. In order to migrate Release Status effectivity to Effectivity, please refer to the link -
    http://docsstage.plm.automation.siemens.com/tdoc/tc/11.6/help#uid:effupgrade after migration use following function to set effective unit values.
    @code
        WSOM_eff_set_unit_range
    @endcode

    Sets the unit effectivity on the given release_status. 

    An error #CXPOM_wrong_class will be returned if the input release_status is a tag to an object other 
    than a release status object.
    An error #EPM_cannot_edit_old_effectivities will be returned if the current mode of V7 effectivity is set.
    An error #EPM_negative_serial_number will be returned if the start_num or end_num are invalid (too long) or negative numbers.
    An error #EPM_end_before_start_serial_number will be returned if the start_num is larger than the end_num.
  */
TC_DEPRECATED( "12.3", "RELSTAT_set_unit_effectivity", "WSOM_eff_set_unit_range" )
extern TCCORE_API int RELSTAT_set_unit_effectivity(
    tag_t          release_status,  /**< (I) The release_status object */
    int            start_num,       /**< (I) The unit start number */
    int            end_num          /**< (I) The unit end number */
    );


/**
    Answers true if the user as currently logged in to Teamcenter Engineering has the
    privilege to edit effectivity data. This privilege is granted by preferences in the
    site preference file, either for an individual user or by role.
*/
extern TCCORE_API int RELSTAT_ask_is_effectivity_user(
    logical*       answer   /**< (O) The indicator if the user has effectivity edit privilege */
    );

#ifdef __cplusplus
}
#endif

/** @} */

#include <tccore/libtccore_undef.h>
#endif
