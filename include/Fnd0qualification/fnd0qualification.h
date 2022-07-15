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

    This header file declares all data types and constants to be used by clients of
    Fnd0Qualification module.

    The ITK fnd0qualification functions include:
    <ul>
    <li>A function to create qualification
    <li>A function to assign qualification to user
    <li>A function to remove qualification from user
    <li>A function to append qualification level
    <li>A function to remove qualification level
    <li>A function to update qualification
    </ul>

    To use these functions, include fnd0qualification.h.
*/

#ifndef TEAMCENTER_FND0QUALIFICATION_H
#define TEAMCENTER_FND0QUALIFICATION_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>
#include <Fnd0qualification/libfnd0qualification_exports.h>

/** object_name property on Fnd0Qualification */
#define OBJECTNAME_ATTR "object_name"

/** object_desc property on Fnd0Qualification */
#define OBJECTDESCRIPTION_ATTR "object_desc"

/** fnd0IsExpiryDateRequired property on Fnd0Qualification. This indicates whenther expiration date needs to be defined while assigning Fnd0Qualification to User */
#define FND0ISEXPIRYDATEREQUIRED_ATTR "fnd0IsExpiryDateRequired"

/** fnd0Levels property on Fnd0Qualification. This represents ordered list of levels */
#define FND0LEVELS_ATTR "fnd0Levels"

/** primary_object property on ImanRelation. */
#define PRIMARYOBJECT_ATTR "primary_object"

/** secondary_object property on ImanRelation. */
#define SECONDARYOBJECT_ATTR "secondary_object"

/** secondary_object property on ImanRelation. */
#define RELATIONTYPE_ATTR "relation_type"

/** fnd0LevelAchieved property on Fnd0UserHasQual. */
#define FND0LEVELACHIEVED_ATTR "fnd0LevelAchieved"

/** fnd0QualAchievedDate property on  Fnd0UserHasQual*/
#define FND0QUALACHIEVEDDATE_ATTR "fnd0QualAchievedDate"

/** fnd0QualExpirationDate property on  Fnd0UserHasQual*/
#define FND0QUALEXPIRATIONDATE_ATTR "fnd0QualExpirationDate"

/** Relation type name through which User is assigned to Fnd0Qualification. */
#define FND0USERHASQUAL_REL "Fnd0UserHasQual"

/** Relation type name through which Job Activity is related to Fnd0Qualification. */
#define FND0REQDQUAL_REL "Fnd0ReqdQual"

/** The condition name which is used to validate create access. */
#define FND0CREATEQUALIFICATION_CONDITION "Fnd0CanCreateQualification"

/** fnd0LevelReqd property on Fnd0ReqdQual Relation. */
#define FND0LEVELREQD_ATTR  "fnd0LevelReqd"

#ifdef __cplusplus
    extern "C"{
#endif


/**
    Structure that holds information to create or update qualification
*/
typedef struct 
{
   char *   qualification_name;                     /**< The qualification name */
   char *   description;                            /**< The qualification description */
   logical  is_expiration_date_required;            /**< If expiration date is required or not */
   int      n_qualification_levels;                 /**< Number of qualification levels */
   char**   qualification_levels;                   /**< Ordered array of string as levels */
} FND0QUALIFICATION_manage_qualification_info_t;

/**
    Structure that holds information to assign a qualification to a user
*/
typedef struct 
{
   tag_t    user_tag;                               /**< The user tag which needs to be related to qualification */
   tag_t    qualification_tag;                      /**< The qualification tag which needs to be related to user */
   char *   qualification_level;                    /**< The level of the qualification */
   date_t   effective_date;                         /**< The effective date of qualification */
   date_t   expiration_date;                        /**< The expiration date of qualification */
} FND0QUALIFICATION_assign_qualification_info_t;

/**
    Structure that holds information to remove a qualification from a user
*/
typedef struct 
{
   tag_t user_tag;                                  /**< The user tag from which the qualification needs to be removed */
   tag_t qualification_tag;                         /**< The qualification tag which is assigned to user */
} FND0QUALIFICATION_remove_qualification_info_t;

/*  */
/**
   @deprecated #FND0QUALIFICATION_init_module deprecated in Teamcenter 11.2.

   Initializes the Fnd0Qualification module. You must call this function before calling any other FND0QUALIFICATION functions.
*/
TC_DEPRECATED_NO_REPLACEMENT("11.2","FND0QUALIFICATION_init_module")
extern FND0QUALIFICATION_API int FND0QUALIFICATION_init_module();

/**
    Creates a Qualification object.
    @return
    <ul>
    <li>#ITK_ok on success.
    <li>#FND0QUALIFICATION_create_permission_fail error if user is not privileged to create qualification.
    </ul>
*/
extern FND0QUALIFICATION_API int FND0QUALIFICATION_create_qualification 
(
    const   FND0QUALIFICATION_manage_qualification_info_t* manage_qualification_info, /**< (I) Information to create a Qualification object.*/
    tag_t*  created_qualification                                                     /**< (O) Tag of the created Qualification object.*/
);

/**
    Assigns a qualification to a user with the specified qualification level.
    @return
    <ul>
    <li>#ITK_ok on success.
    <li>#FND0QUALIFICATION_assign_user_qualfication_permission_fail error if user is not privileged to assign user qualification.
    <li>#FND0QUALIFICATION_invalid_effective_or_expiration_date_fail error if invalid expiration or effective date is provided.
    <li>#FND0QUALIFICATION_effective_date_greater_fail error if expiration date is less than effective date.
    <li>#FND0QUALIFICATION_level_already_exists_fail error if qualification with same level is already assigned to user.
    </ul>
*/
extern FND0QUALIFICATION_API int FND0QUALIFICATION_assign_user_qualification 
(
    const   FND0QUALIFICATION_assign_qualification_info_t* assign_user_qualification_info,    /**< (I) Information to assign a qualification to a user.*/
    tag_t*  added_user_qualification_relation                                                 /**< (O) Tag of the relation object created on assigning the qualification to the user.*/
);

/**
    Removes a qualification from the user.
    @return
    <ul>
    <li>#ITK_ok on success.
    <li>#FND0QUALIFICATION_remove_user_qualfication_privilege_fail error if user is not privileged to remove user qualification.
    </ul>
*/
extern FND0QUALIFICATION_API int FND0QUALIFICATION_remove_user_qualification 
(
    const FND0QUALIFICATION_remove_qualification_info_t* remove_user_qualification_info,     /**< (I) Information to remove a qualification from a user*/
    tag_t*  removed_user_qualification_relation                                              /**< (O) Tag of the deleted relation object on removing the qualification from the user.*/
);

/**
    Appends a level to the qualification object.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#FND0QUALIFICATION_level_already_exists_fail error if same level is already in qualification.
    </ul>
*/
extern FND0QUALIFICATION_API int FND0QUALIFICATION_append_qualification_level
(
    tag_t         qualification_tag,                          /**< (I) Tag of the Qualification object to append new level*/
    const char * const  qualification_level                   /**< (I) The new level that needs to be appended to the Qualification's list of levels */
);

/**
    Removes a level from the qualification object.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#FND0QUALIFICATION_qualification_level_referenced_fail error if level is assigned to users.
    <li>#FND0QUALIFICATION_level_not_exist_fail error if qualification level is not present.
    </ul>
*/
extern FND0QUALIFICATION_API int FND0QUALIFICATION_remove_qualification_level
(
    tag_t         qualification_tag,                          /**< (I) Tag of the Qualification object to remove the level */
    const char * const  qualification_level                   /**< (I) The level that needs to be removed from the Qualification's list of levels */
);

/**
    Updates the qualification object based on the given information.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#FND0QUALIFICATION_update_qualification_privilege_fail error if user is not privileged to modify qualification.
    <li>#FND0QUALIFICATION_qualification_level_referenced_fail error if level to be removed is assigned to users or tasks.
    <li>#FND0QUALIFICATION_cannot_change_exp_date_requirement_fail error if expiration date requirement cannot be changed 
        because the qualification has been assigned to users.
    </ul>
*/
extern FND0QUALIFICATION_API int FND0QUALIFICATION_update_qualification 
(
    tag_t         qualification_tag,                                            /**< (I) Tag of the Qualification object to update. */
    const FND0QUALIFICATION_manage_qualification_info_t*  qualification_info    /**< (I) Information to update the Qualification object. */
);

#ifdef __cplusplus
    }
#endif

#include <Fnd0qualification/libfnd0qualification_undef.h>

#endif
