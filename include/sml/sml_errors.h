/*HEAD SML_ERRORS HHH IN-CLASS */
/*==============================================================================

                   Copyright (c) 1999,2001,2002 Unigraphics Solutions
                       Unpublished - All rights reserved
================================================================================
File description:

    Error codes returnd by the SML module

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!                                                !!!
    !!! NOTE: changes in here need to be in sync with  !!!
    !!!       ics_errors.uih                           !!!
    !!!       ICSErrors.java                           !!!
    !!!                                                !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    Filename:
    Module  :

================================================================================
   Date      Name                    Description of Change
26-Jun-2001  braun                   Added SML_ERR_CANT_CREATE_QUERY_NAME
06-Jul-2001  braun                   Added format errors
10-Jul-2001  braun                   Minor changes.
15-Aug-2001  helmutl                 add SML_ERR_NO_DEFAULT_VIEW
15-Aug-2001  helmutl                 merge from Helmut
27-Jul-2001  helmutl                 add SML_ERR_MULTIINST_VIOLATON
24-Sep-2001  helmutl                 merge from V7.0.2.1
28-Sep-2001  helmutl                 merge from v8
04-Oct-2001  helmutl                 Merge from promote attr project branch
05-Oct-2001  helmutl                 merge from inclass_v8_dev
09-Oct-2001  helmutl                 merge from Karen
31-Oct-2001  helmutl                 add SML_ERR_CANT_CHANGE_ATTRIBUTE
06-Nov-2001  braun                   Added some error codes.
07-Nov-2001  helmutl                 merge from Karen
08-Nov-2001  braun                   Added SML_ERR_USER_NOT_PRIVILEGED
09-Nov-2001  helmutl                 merge from Karen
12-Nov-2001  helmutl                 merge from helmutl_v8_dev
13-Nov-2001  helmutl                 merge from helmutl_v8_devi
13-Nov-2001  helmutl                 merge from helmutl_v8_devi2
23-Nov-2001  helmutl                 add SML_ERR_CLASS_IS_ABSTRACT
09-Jan-2002  helmutl                 Merge fro P8.0.0.3 promote
22-Aug-2001  brenneck                Merged to expose function SML_set_tags to CME.
24-Aug-2001  brenneck                Merge NavigationControl setSearchResult changes into cgn_cme_int.
16-Jan-2002  helmutl                 resolve conflict with CYP_P8.0.0.3
06-Feb-2002  braun                   Added SML_FAILED_TO_CREATE_EVENTTYPE
12-Feb-2002  helmutl                 merge from Karen
13-Feb-2002  helmutl                 merge from helmutl_p8004
15-Apr-2002  braun                   Added SML_ERR_INVALID_WHERE_ATTR.
15-Apr-2002  braun                   Merge from braun_p8005_2
16-Apr-2002  braun                   Merge from braun_p8006
03-Jun-2002  helmutl                 merge from P8.0.0.9 to main
04-Jun-2002  braun                   Added error codes for access control.
04-Jun-2002  braun                   Merge from braun_p8.1.0.0
07-Jun-2002  braun                   Merge from braun_p8.1.0.0_1
07-Jun-2002  helmutl                 merge from AM project
04-Jul-2002  braun                   Added error messages for access control.
05-Jul-2002  braun                   Merge from braun_p8.1.0.1
29-Jul-2002  braun                   Added SML_ERR_UNKNOWN_OVERRIDABLE_PRIVILEGE.
29-Jul-2002  braun                   Merge from braun_p8.1.0.3.
31-Jul-2002  braun                   Added SML_ERR_DUPLICATE_SITES_DEFINITION.
31-Jul-2002  braun                   Merge from braun_p8.1.0.3
22-Aug-2002  Helmut Lohmueller       add SML_ERR_PARENT_DOES_NOT_EXIST
23-Aug-2002  Helmut Lohmueller       merge from Helmut
16-Apr-2003  Helmut Lohmueller       update #include
28-Apr-2003  Helmut Lohmueller       merge from SDL_P9.0.0.0 based branch
01-Aug-2003  braun                   Added SML_ERR_EMPTY_TEMPLATE_REVISION, SML_ERR_WRONG_TEMPLATE_REVISION, SML_ERR_NO_PART_FAMILY_MEMBER_TYPE.
04-Aug-2003  braun                   Merge from braun_p9.0
08-Aug-2003  braun                   Added SML_ERR_NO_EXPRESSION.
13-Aug-2003  braun                   merge from braun_v9.0.x.
13-Aug-2003  Helmut Lohmueller       merge from Karen
30-Apr-2004  Braun                   Changed SML_ERR_NO_EXPRESSION to SML_ERR_TOO_FEW_EXPRESSIONS.
06-Jul-2004  terbahl                 add SML_ERR_FORMAT_VALUE_MUST_BE_POSITIVE
17-Jan-2005  Braun                   Add some error numbers.
19-Jan-2005  Braun                   Add some error codes.
24-Feb-2005  Braun                   Fix bug with Masterform attributes.
15-Mar-2005  piller                  Add error SML_ERR_INVALID_SEARCH_CRITERIA( EMH_ICS_error_base + 160 ).
14-Apr-2005  Braun                   Add some error codes.
27-Jul-2005  Braun                   Fix PR5222430: SAM group could not be saved due to too long local site name.
12-Jan-2006  Braun                   Add attribute project.
23-Jan-2006  helmutl                 add error codes for add and remove attribute functions
07-Jun-2006  terbahl                 change error codes for SML_ERR_FORMAT...
06-Sep-2006  helmutl                 SML_ERR_NO_ACCESS_TO_REMOTE_CLASS
21-Nov-2006  terbahl                 merge PR fixes from V9.1.3.6
27-Nov-2006  terbahl                 merge for DMS migration
27-Nov-2006  terbahl                 DeImanization
24-Jun-2009  agaibia                 add error code for PR#6070992
$HISTORY$
================================================================================*/
#ifndef SML_ERRORS_H_INCLUDED
#define SML_ERRORS_H_INCLUDED


#include <common/emh_const.h>

#define ERROR_SML_BASE                   EMH_ICS_error_base

#define SML_OK                           0

/** No Command */
#define SML_ERR_NO_COMMAND               ( EMH_ICS_error_base +  1 )

/** Missing Parameter */
#define SML_ERR_MISSING_PARAMETER        ( EMH_ICS_error_base +  2 )

/** Inconsistent Parameter */
#define SML_ERR_INCONSISTENT_PARAMETER   ( EMH_ICS_error_base +  3 )

/** Wrong Option */
#define SML_ERR_WRONG_OPTION             ( EMH_ICS_error_base +  4 )

#define SML_ERR_INVALID_OPTION           ( EMH_ICS_error_base +  4 )  /* same as SML_ERR_WRONG_OPTION */

/** Unsupported function */
#define SML_ERR_UNSUPPORTED_FUNCTION     ( EMH_ICS_error_base +  5 )

/** Unknown Function */
#define SML_ERR_UNKNOWN_FUNCTION         ( EMH_ICS_error_base +  6 )

/** No class instance */
#define SML_ERR_NO_CLASS_INSTANCE        ( EMH_ICS_error_base +  7 )

/** Attribute not in use */
#define SML_ERR_ATTR_NOT_IN_USE          ( EMH_ICS_error_base +  9 )

/** The Attribute ID "%1$" is invalid. Please check that the Attribute ID belongs to a valid Attribute. */
#define SML_ERR_INVALID_UNCT             ( EMH_ICS_error_base + 10 )

/** Attribute not in Class */
#define SML_ERR_ATTR_NOT_IN_CLASS        ( EMH_ICS_error_base + 11 )

/** Attribute already in Class/View */
#define SML_ERR_ATTR_NOT_UNIQUE          ( EMH_ICS_error_base + 12 )

/** Value not available */
#define SML_ERR_VALUE_NOT_AVAILABLE      ( EMH_ICS_error_base + 13 )

/** Invalid Value */
#define SML_ERR_INVALID_VALUE            ( EMH_ICS_error_base + 14 )

/** Out of Memory */
#define SML_ERR_OUT_OF_MEMORY            ( EMH_ICS_error_base + 15 )

/** Maximum number of available attribute exceeded */
#define SML_ERR_NO_FREE_ATTR             ( EMH_ICS_error_base + 16 )

/** ID not unique */
#define SML_ERR_ID_NOT_UNIQUE            ( EMH_ICS_error_base + 17 )

/** Object not loaded */
#define SML_ERR_NOT_LOADED               ( EMH_ICS_error_base + 18 )

/** Object not locked */
#define SML_ERR_NOT_LOCKED               ( EMH_ICS_error_base + 19 )

/** Error in Format */
#define SML_ERR_IN_FORMAT                ( EMH_ICS_error_base + 20 )

/** Invalid range definition */
#define SML_ERR_INVALID_RANGE_DEF        ( EMH_ICS_error_base + 21 )

/** Before first instance */
#define SML_ERR_BEFORE_FIRST_INSTANCE    ( EMH_ICS_error_base + 22 )

/** Behind last instance */
#define SML_ERR_BEHIND_LAST_INSTANCE     ( EMH_ICS_error_base + 23 )

/** No instance found */
#define SML_ERR_NO_INSTANCE_FOUND        ( EMH_ICS_error_base + 24 )

/** Unknown parameter */
#define SML_ERR_UNKNOWN_PARAMETER        ( EMH_ICS_error_base + 25 )

/** Unsupported object */
#define SML_ERR_UNSUPPORTED_OBJECT       ( EMH_ICS_error_base + 26 )

/** Error in reading file */
#define SML_ERR_READING_FILE             ( EMH_ICS_error_base + 27 )

/** No enquiry created */
#define SML_ERR_NO_ENQUIRY_CREATED       ( EMH_ICS_error_base + 28 )

/** Too many values */
#define SML_ERR_TO_MANY_VALUES           ( EMH_ICS_error_base + 29 )

/** Invalid Username */
#define SML_ERR_INVALID_USERNAME         ( EMH_ICS_error_base + 30 )

/** Invalid Password */
#define SML_ERR_INVALID_PASSWORD         ( EMH_ICS_error_base + 31 )

/** Already set */
#define SML_ERR_ALREADY_SET              ( EMH_ICS_error_base + 32 )

/** Class not set */
#define SML_ERR_CLASS_NOT_SET            ( EMH_ICS_error_base + 33 )

/** Subclass not set */
#define SML_ERR_SUBCLASS_NOT_SET         ( EMH_ICS_error_base + 34 )

/** The object cannot be modified, because it is locked by the user "%1$" on the node "%2$" in a session started at "%3$".*/
#define SML_ERR_LOCKED_BY_OTHER_USER     ( EMH_ICS_error_base + 35 )

/** Invalid privileges */
#define SML_ERR_INVALID_PRIVILEGES       ( EMH_ICS_error_base + 36 )

/** Invalid CIM File */
#define SML_ERR_INVALID_CIM_FILE         ( EMH_ICS_error_base + 37 )

/** Named Reference exists */
#define SML_ERR_NAMED_REF_EXISTS         ( EMH_ICS_error_base + 38 )

/** Instance modified */
#define SML_ERR_INSTANCE_MODIFIED        ( EMH_ICS_error_base + 39 )

/** Unable to open file */
#define SML_ERR_UNABLE_TO_OPEN_FILE      ( EMH_ICS_error_base + 40 )

/** No Subclass instance */
#define SML_ERR_NO_SUBCLASS_INSTANCE     ( EMH_ICS_error_base + 41 )

/** DB Table not available */
#define SML_ERR_DB_TABLE_NOT_AVAILABLE   ( EMH_ICS_error_base + 42 )

/** DBC_ID not open */
#define SML_ERR_DBC_ID_NOT_OPEN          ( EMH_ICS_error_base + 43 )

/** Missing Environment */
#define SML_ERR_MISSING_ENVIRONMENT      ( EMH_ICS_error_base + 44 )

/** The instance "%1$" cannot be classified, because the uniqueness rule is violated for the following attributes: %2$.*/
#define SML_ERR_INSTANCE_NOT_UNIQUE      ( EMH_ICS_error_base + 45 )

/** Only subset loaded */
#define SML_ERR_ONLY_SUBSET_LOADED       ( EMH_ICS_error_base + 46 )

/** Invalid DBC_ID */
#define SML_ERR_INVALID_DBC_ID           ( EMH_ICS_error_base + 47 )

/** Error in processing UCL Function */
#define SML_ERR_PROCESSING_UCL_FUNCTION  ( EMH_ICS_error_base + 48 )

/** Invalid parameter */
#define SML_ERR_INVALID_PARAMETER        ( EMH_ICS_error_base + 49 )

/** Unsupported operator */
#define SML_ERR_UNSUPPORTED_OPERATOR     ( EMH_ICS_error_base + 50 )

/** Class not found */
#define SML_ERR_CLASS_NOT_FOUND          ( EMH_ICS_error_base + 51 )

/** Subclass/View not found */
#define SML_ERR_SUBCLASS_NOT_FOUND       ( EMH_ICS_error_base + 52 )

/** Popup definition not found */
#define SML_ERR_STXT_NOT_FOUND           ( EMH_ICS_error_base + 53 )

/** The given Attribute does not exist */
#define SML_ERR_UNCT_NOT_FOUND           ( EMH_ICS_error_base + 54 )

/** Unable to delete node */
#define SML_ERR_UNABLE_TO_DELETE_NODE    ( EMH_ICS_error_base + 55 )

/** Unable to copy file */
#define SML_ERR_UNABLE_TO_COPY_FILE      ( EMH_ICS_error_base + 56 )

/** Unable to rename file */
#define SML_ERR_UNABLE_TO_RENAME_FILE    ( EMH_ICS_error_base + 57 )

/** Unable to delete file */
#define SML_ERR_UNABLE_TO_DELETE_FILE    ( EMH_ICS_error_base + 58 )

/** SML Module not initialized */
#define SML_ERR_MODULE_NOT_INITIALIZED   ( EMH_ICS_error_base + 59 )

/** Unable to set parent */
#define SML_ERR_CANT_SET_PARENT          ( EMH_ICS_error_base + 60 )

/** No access to object */
#define SML_ERR_NO_ACCESS                ( EMH_ICS_error_base + 61 )

/** No write access */
#define SML_ERR_WRITE_ACCESS             ( EMH_ICS_error_base + 62 )

/** Class already instantiated */
#define SML_ERR_CLASS_INSTANTIATED       ( EMH_ICS_error_base + 63 )

/** Class already subclassed */
#define SML_ERR_CLASS_IS_SUBCLASSED      ( EMH_ICS_error_base + 64 )

/** No view defined for this class */
#define SML_ERR_NO_DEFAULT_VIEW          ( EMH_ICS_error_base + 65 )

/** Cannot create a new query name */
#define SML_ERR_CANT_CREATE_QUERY_NAME   ( EMH_ICS_error_base + 66 )

/** Can't classify the object in the same class twice */
#define SML_ERR_MULTIINST_VIOLATON       ( EMH_ICS_error_base + 67 )

/** Hook not supported */
#define SML_ERR_UNSUPPORTED_HOOK         ( EMH_ICS_error_base + 68 )

/** Internal error */
#define SML_ERR_INTERNAL_ERROR           ( EMH_ICS_error_base + 69 )

/** The property of the attribute can't be changed */
#define SML_ERR_CHANGE_ATTRIBUTE_PROPERTY ( EMH_ICS_error_base + 70 )

/** Object is owned by local site */
#define SML_ERR_IS_LOCAL_OBJECT          ( EMH_ICS_error_base + 71 )

/** Local site cannot be found */
#define SML_ERR_NO_LOCAL_SITE            ( EMH_ICS_error_base + 72 )

/** Site name is too long */
#define SML_ERR_SITE_NAME_TOO_LONG       ( EMH_ICS_error_base + 73 )

/** Cannot find Teamcenter Engineering event for synchronization */
#define SML_ERR_SYNCEVENT_NOT_AVAILABLE  ( EMH_ICS_error_base + 74 )

/** Duplicate site name */
#define SML_ERR_DUPLICATE_SITE           ( EMH_ICS_error_base + 75 )

/** Cannot find Teamcenter Engineering type of instance */
#define SML_ERR_INSTANCE_TYPE_NOT_FOUND  ( EMH_ICS_error_base + 76 )

/** User does not have enough privileges */
#define SML_ERR_USER_NOT_PRIVILEGED      ( EMH_ICS_error_base + 77 )

/** Internal error in list class: current is null */
#define SML_ERR_LIST_CURRENT_IS_NULL     ( EMH_ICS_error_base + 78 )

/** Class is abstract */
#define SML_ERR_CLASS_IS_ABSTRACT        ( EMH_ICS_error_base + 79 )

/** Could not create Teamcenter Engineering event type for synchronization */
#define SML_FAILED_TO_CREATE_EVENTTYPE   ( EMH_ICS_error_base + 80 )

/** Invalid attribute to query */
#define SML_ERR_INVALID_WHERE_ATTR       ( EMH_ICS_error_base + 81 )

/** Internal error: could not find class alias */
#define SML_ERR_NO_CLASS_ALIAS_FOUND     ( EMH_ICS_error_base + 82 )

/** Unknown privilege */
#define SML_ERR_UNKNOWN_PRIVILEGE        ( EMH_ICS_error_base + 83 )

/** Invalid privilege */
#define SML_ERR_INVALID_PRIVILEGE        ( EMH_ICS_error_base + 84 )

/** Could not find system rule in AM rule tree */
#define SML_ERR_SYSTEM_RULE_NOT_FOUND    ( EMH_ICS_error_base + 85 )

/** Error in AM rule tree: system rule is not unique */
#define SML_ERR_SYSTEM_RULE_NOT_UNIQUE   ( EMH_ICS_error_base + 86 )

/** Error in AM rule tree: system rule is not a child of the AM rule tree root */
#define SML_ERR_SYSTEM_RULE_NOT_ROOT_CHILD ( EMH_ICS_error_base + 87 )

/** Error in Classification access rules: rule for subclass has no parent class rule */
#define SML_ERR_SID_RULE_WITHOUT_CID     ( EMH_ICS_error_base + 88 )

/** Error in Classification access rules: rule must not have children but does */
#define SML_ERR_RULE_MUST_NOT_HAVE_CHILDREN ( EMH_ICS_error_base + 89 )

/** Error in Classification access rules: rule must have children but does not */
#define SML_ERR_RULE_MUST_HAVE_CHILDREN  ( EMH_ICS_error_base + 90 )

/** Error in Classification access rules: child rule has wrong name */
#define SML_ERR_CHILD_HAS_WRONG_RULE     ( EMH_ICS_error_base + 91 )

/** Error in Classification access rules: rule has wrong parent */
#define SML_ERR_NODE_HAS_WRONG_PARENT    ( EMH_ICS_error_base + 92 )

/** Error in Classification access rules: acl is not empty */
#define SML_ERR_ACL_IS_NOT_EMPTY         ( EMH_ICS_error_base + 93 )

/** Error in Classification access rules: found rules with different parents and different acls */
#define SML_RULES_WITH_DIFFERENT_ACLS    ( EMH_ICS_error_base + 94 )

/** Error in Classification access rules: found more than one rule as root for class rules */
#define SML_ERR_MORE_THAN_ONE_RULE       ( EMH_ICS_error_base + 95 )

/** Error in Classification access rules: unknown simple privilege */
#define SML_ERR_UNKNOWN_SIMPLE_PRIVILEGE ( EMH_ICS_error_base + 96 )

/** Insufficient privileges: cannot share ancestor */
#define SML_ERR_UNSHARED_NOT_PRIVILEGED_ANCESTOR ( EMH_ICS_error_base + 97 )

/** Insufficient privileges: New parent cannot be read */
#define SML_ERR_CANT_READ_NEW_PARENT     ( EMH_ICS_error_base + 98 )

/** Insufficient privileges: New parent cannot be written */
#define SML_ERR_CANT_WRITE_NEW_PARENT    ( EMH_ICS_error_base + 99 )

/** Insufficient privileges: Cannot read new class of ICO */
#define SML_ERR_CANT_READ_NEW_OWNER      ( EMH_ICS_error_base + 100 )

/** Insufficient privileges: Cannot write ICOs of new class */
#define SML_ERR_CANT_WRITE_ICOS_OF_NEW_OWNER  ( EMH_ICS_error_base + 101 )

/** The given overridable privilege is unknown */
#define SML_ERR_UNKNOWN_OVERRIDABLE_PRIVILEGE ( EMH_ICS_error_base + 102 )

/** The privilege is not set in the instance */
#define SML_ERR_PRIVILEGE_UNSET_IN_INSTANCE   ( EMH_ICS_error_base + 103 )

/** Too many instances were found */
#define SML_ERR_TOO_MANY_INSTANCES_FOUND      ( EMH_ICS_error_base + 104 )

/** Found a duplicate sites definition */
#define SML_ERR_DUPLICATE_SITES_DEFINITION    ( EMH_ICS_error_base + 105 )

/** The specified parent does not exist */
#define SML_ERR_PARENT_DOES_NOT_EXIST         ( EMH_ICS_error_base + 106 )

/** Informational messages have been produced. Please check log files */
#define SML_ERR_INFO                          ( EMH_ICS_error_base + 107 )

/** Warning messages have been produced. Please check log files */
#define SML_ERR_WARNING                       ( EMH_ICS_error_base + 108 )

/** Error messages have been produced. Please check log files */
#define SML_ERR_ERROR                         ( EMH_ICS_error_base + 109 )

/** The template revision is empty */
#define SML_ERR_EMPTY_TEMPLATE_REVISION       ( EMH_ICS_error_base + 110 )

/** The template revision is wrong */
#define SML_ERR_WRONG_TEMPLATE_REVISION       ( EMH_ICS_error_base + 111 )

/** No part family member type */
#define SML_ERR_NO_PART_FAMILY_MEMBER_TYPE    ( EMH_ICS_error_base + 112 )

/** No part type is specified. */
#define SML_ERR_NO_PART_FAMILY_TEMPLATE_TYPE  ( EMH_ICS_error_base + 113 )

/** Not a reference attribute */
#define SML_ERR_NO_REF_ATTR                   ( EMH_ICS_error_base + 114 )

/** Unknown error */
#define SML_ERR_UNKNOWN_ERROR                 ( EMH_ICS_error_base + 115 )

/** Relation Type specified does not exist */
#define SML_RELATION_TYPE_DOES_NOT_EXIST      ( EMH_ICS_error_base + 116 )

/** The name of the POM class where ICOs are stored could not be found. */
#define SML_ERR_NO_ICO_POM_CLASS_NAME                           (EMH_ICS_error_base + 117)

/** The given POM class is not a subclass of the given base class. */
#define SML_ERR_NO_POM_SUBCLASS                                 (EMH_ICS_error_base + 118)

/** The given type is not a sub type of the given base type. */
#define SML_ERR_NOT_A_SUB_TYPE                                  (EMH_ICS_error_base + 119)

/** The given index is not valid for ICO attributes. */
#define SML_ERR_INVALID_SM_ATTR_INDEX                           (EMH_ICS_error_base + 120)

/** The reference type is invalid */
#define SML_ERR_INVALID_REFERENCE_TYPE                          (EMH_ICS_error_base + 121)

/** Reference attribute requires class identifier. */
#define SML_ERR_PREFIX_BUT_NO_CID                               (EMH_ICS_error_base + 122)

/** The given type must not be 0. */
#define SML_ERR_TYPE_IS_NULL                                    (EMH_ICS_error_base + 123)

/** The given type is neither an item nor an item revision type. */
#define SML_ERR_NEITHER_ITEM_NOR_REVISION_TYPE                  (EMH_ICS_error_base + 124)

/** No attribute name given for reference attribute. */
#define SML_ERR_EMPTY_ATTRIBUTE                                 (EMH_ICS_error_base + 125)

/** No property name given for reference attribute. */
#define SML_ERR_EMPTY_PROPERTY                                  (EMH_ICS_error_base + 126)

/** POM class name must be specified for this kind of reference attribute */
#define SML_ERR_EMPTY_POM_CLASS                                 (EMH_ICS_error_base + 127)

/** The given POM attribute / attribute id is invalid. */
#define SML_ERR_INVALID_ATTRIBUTE                               (EMH_ICS_error_base + 128)

/** An empty query string was created from a reference attribute. */
#define SML_ERR_EMPTY_QUERY_STRING                              (EMH_ICS_error_base + 129)

/** There is no format for this attribute type. */
#define SML_ERR_NO_FORMAT_FOR_ATTRIBUTE_TYPE                    (EMH_ICS_error_base + 130)

/** Try to create an attribute query without specifying the attribute. */
#define SML_ERR_EMPTY_CHILD                                     (EMH_ICS_error_base + 131)

/** Try to create an attribute query without specifying a value. */
#define SML_ERR_EMPTY_VALUE                                     (EMH_ICS_error_base + 132)

/** Try to use inner ICO reference attribute values without specifying the prefix. */
#define SML_ERR_EMPTY_PREFIX                                    (EMH_ICS_error_base + 133)

/** Try to use the same ICO reference attribute with different class IDs. */
#define SML_ERR_QUERY_ON_DIFFERENT_CIDS                         (EMH_ICS_error_base + 134)

/** Try to load ICO attributes in non existing ICO. */
#define SML_ERR_NO_INSTANCE_TAGS                                (EMH_ICS_error_base + 135)

/** No class ID given for ICO search. */
#define SML_ERR_CID_IS_EMPTY                                    (EMH_ICS_error_base + 136)

/** Try to set a type expression in a query without specifying the type. */
#define SML_ERR_NO_TYPE_EXPRESSION_TO_SET                       (EMH_ICS_error_base + 137)

/** Try to find an attribute without specifying the ID. */
#define SML_ERR_EMPTY_UNCT                                      (EMH_ICS_error_base + 138)

/** Could not find the attribute with the specified ID. */
#define SML_ERR_ATTRIBUTE_NOT_FOUND                             (EMH_ICS_error_base + 139)

/** The ICO Attribute is not expanded. */
#define SML_ERR_NO_INNER_ATTRIBUTES                             (EMH_ICS_error_base + 140)

/** Attempt to create the query tree twice. */
#define SML_ERR_QUERY_TREE_ALREADY_CREATED                      (EMH_ICS_error_base + 141)

/** The attribute is not an ICO reference. */
#define SML_ERR_NO_ICO_REFERENCE                                (EMH_ICS_error_base + 142)

/** The pomclass is neither a subclass of item nor of itemrevision. */
#define SML_ERR_NEITHER_ITEM_NOR_REVISION_POMCLASS              (EMH_ICS_error_base + 143)

/** An unknown option was specified. */
#define SML_ERR_UNKNOWN_OPTION                                  (EMH_ICS_error_base + 144)

/** An invalid attribute type was specified. */
#define SML_ERR_INVALID_ATTR_TYPE                               (EMH_ICS_error_base + 145)

/** The number string does not specify an integer. */
#define SML_ERR_NOT_AN_INTEGER                                  (EMH_ICS_error_base + 146)

/** More than one POM class for masterform attributes. */
#define SML_ERR_TOO_MANY_MASTERFORMS                            (EMH_ICS_error_base + 147)

/** Internal error: The attribute name does not exist. */
#define SML_ERR_INVALID_ATTRIBUTE_NAME                          (EMH_ICS_error_base + 148)

/** Internal error: The attribute name does not exist. */
#define SML_ERR_INVALID_ATTRIBUTE_DEFINITION                    (EMH_ICS_error_base + 149)

/** Don't call this function: it is not implemented. */
#define SML_ERR_FUNCTION_NOT_IMPLEMENTED                        (EMH_ICS_error_base + 150)

/** Type for POM class Item cannot be found. */
#define SML_ERR_CANNOT_GET_ITEM_TYPE                            (EMH_ICS_error_base + 151)

/** The given type is not an item type. */
#define SML_ERR_NO_ITEM_TYPE                                    (EMH_ICS_error_base + 152)

/** The given type is not an item revision type. */
#define SML_ERR_NO_ITEMREVISION_TYPE                            (EMH_ICS_error_base + 153)

/** Type for POM class Item Revision cannot be found. */
#define SML_ERR_CANNOT_GET_ITEMREVISION_TYPE                    (EMH_ICS_error_base + 154)

/** The master form for the given item / item revision type cannot be found. */
#define SML_ERR_CANNOT_GET_MASTERFORM                           (EMH_ICS_error_base + 155)

/** The given property does not specify a POM attribute. */
#define SML_ERR_NO_POM_ATTRIBUTE                                (EMH_ICS_error_base + 156)

/** The given Attribute ID specifies a Classification object reference Attribute, which cannot be used as a key Attribute. */
#define SML_ERR_INVALID_KEY_ATTRIBUTE                           (EMH_ICS_error_base + 157)

/** The object is not a property (but an attribute). */
#define SML_ERR_NOT_A_PROPERTY                                  (EMH_ICS_error_base + 158)

/** The Item Revision type cannot be found from the provided Item type "%1$". Please refer to the Teamcenter server syslog file for more information on this error. */
#define SML_ERR_NO_REV_TYPE_FOR_ITEM_TYPE                       (EMH_ICS_error_base + 159)

/** create a query with invalid parameters e.g. wildcard search for integer */
#define SML_ERR_INVALID_SEARCH_CRITERIA                         (EMH_ICS_error_base + 160)

/** The specified attribute description type does not exist */
#define SML_ERR_INVALID_ATTR_DESC_TYPE                          (EMH_ICS_error_base + 161)

/** Something is wrong with the reference attribute definition */
#define SML_ERR_INVALID_REFATTR_DEFINITION                      (EMH_ICS_error_base + 162)

/** No attribute name was specified for the reference attribute definition */
#define SML_ERR_EMPTY_REFATTR_ATTRNAME                          (EMH_ICS_error_base + 163)

/** A relation type was specified for a reference attribute that does not specify a related object attribute */
#define SML_ERR_RELATIONTYPE_BUT_NO_RELATED                     (EMH_ICS_error_base + 164)

/** The length of the string attribute "%1$" of the POM class "%2$" cannot be modified. Please refer to the Teamcenter server syslog file for more information on this error. */
#define SML_ERR_ALTER_STRING_LENGTH                             (EMH_ICS_error_base + 165)

/** The view attributes could not be saved in the new format. */
#define SML_ERR_VIEW_ATTR_CONVERSION_FAILED                     (EMH_ICS_error_base + 166)

/** An object was given twice and the second values (e.g. the new ids) are different. */
#define SML_ERR_DIFFERENT_VALUE_IN_DUPLICATE                    (EMH_ICS_error_base + 167)

/** Cannot create unique id. Increasing the number of digits in the used pattern preference could solve the problem. */
#define SML_ERR_CANNOT_CREATE_UNIQUE_ID                         (EMH_ICS_error_base + 168)

/** The parent of the class is not local. */
#define SML_ERR_PARENT_NOT_LOCAL                                (EMH_ICS_error_base + 169)

/** The operation requires the classification hierarchy to be local. */
#define SML_ERR_REMOTE_HIERARCHY_NOT_ACCESSIBLE                 (EMH_ICS_error_base + 170)

/** Found attribute in descendants of class while trying to add the attribute. */
#define SML_ERR_ATTR_IN_DESCENDANTS                             (EMH_ICS_error_base + 171)

/** The operation (remove or add attribute) can't be performed if there are potential remote objects. */
#define SML_ERR_REMOTE_ICOS_NOT_ACCESSIBLE                      (EMH_ICS_error_base + 172)
#define SML_ERR_NO_WRITE_ACCESS_TO_REMOTE_CLASS                 (EMH_ICS_error_base + 173)


/** Tried to create an ICO for a class specified supporting both unit systems without specifying the unit system*/
#define SML_ERR_UNIT_SYSTEM_UNSPECIFIED                         (EMH_ICS_error_base + 174)

/** Tried to create an ICO in a unit system the class doesn't support */
#define SML_ERR_UNIT_SYSTEM_INCONSISTENT                        (EMH_ICS_error_base + 175)

/** Tried to fetch the value or deprecated status of non existant keyLov entry  */
#define SML_ERROR_KEYLOV_VALUE_UNKNOWN                          (EMH_ICS_error_base + 176)

/** The add attribute operation (xml/plmxml import) cannot be performed if the dbindex is already in use **/
#define SML_ERR_DBINDEX_IS_IN_USE                               (EMH_ICS_error_base + 177)

/** The error code if a group is used to classify a workspace object**/
#define SML_ERR_IF_GROUP                                        (EMH_ICS_error_base + 178)

/** The error code if invalid format type is specified in the query field for dictionary attribute query **/
#define SML_ERR_INVALID_FORMAT                                  (EMH_ICS_error_base + 179)

/** Tried to set the min max value without setting the Format  */
#define SML_ERROR_FORMAT_NOT_SET                                (EMH_ICS_error_base + 180)

/** The update class operation (xml/plmxml import) cannot be performed due to update errors in parent class **/
#define SML_ERR_PLMXML_UPDATE_PARENT                            (EMH_ICS_error_base + 181)

/** The add class attribute operation (xml/plmxml import) cannot be performed due to import/update errors of dict attr**/
#define SML_ERR_PLMXML_ADD_CLASSATTR                            (EMH_ICS_error_base + 182)

/** The Object is a stub. */
#define SML_ERR_OBJECT_IS_A_STUB                                (EMH_ICS_error_base + 183)

/** The Object is not a class or view */
#define SML_ERR_NOT_A_CLASS_OR_VIEW                             (EMH_ICS_error_base + 184)

/** The mandatory attribute is empty for an ICO */
#define SML_ERR_EMPTY_MANDATORY_ATTRIBUTE                       (EMH_ICS_error_base + 185)

/** Tried to sync ICO instances without access */
#define SML_ERR_MULTIINST_CANNOT_SYNC_OBJ_NO_ACCESS_TO_CLASS    (EMH_ICS_error_base + 186)

/** ICS_SEARCH_IN_BOTH_UNIT_SYSTEMS defined but active unit system not given, used in ICS_ico_search*/
#define SML_ERR_ACTIVE_UNIT_NOT_SPECIFIED                       (EMH_ICS_error_base + 187)

/** WSO Type is not a classifiable type*/
#define SML_WSO_TYPE_NOT_CLASSIFIABLE                           (EMH_ICS_error_base + 188)

/** The Item of Item Revision is already classsified*/
#define SML_ERR_ITEM_OF_ITEMREV_CLASSIFIED                      (EMH_ICS_error_base + 189)

/** The Item Revision of Item is already classsified*/
#define SML_ERR_ITEMREV_OF_ITEM_CLASSIFIED                      (EMH_ICS_error_base + 190)

/** Attribute not in Class, but exists in View */
#define SML_ERR_VIEW_ATTR_NOT_IN_SYNC_WITH_CLASS                ( EMH_ICS_error_base + 191 )

/** Attribute not unique in Class */
#define SML_ERR_ANNOTATION_NOT_UNIQUE                           ( EMH_ICS_error_base + 192 )

/** Some entries for the KeyLOV are having empty values, which is not supported when localization is enabled. Either none or all entries need to have non-empty values. Please provide appropriate values for all entries.*/
#define SML_ERR_EMPTY_VALUES_NOT_ALLOWED                        ( EMH_ICS_error_base + 193 )

/** The ID contains invalid characters. */
#define SML_ID_WITH_INVALID_CHARS                               (EMH_ICS_error_base + 194)

/** The Key LOV ID must be a negative integer value. */
#define SML_KEYLOV_ID_NOT_NEGATIVE                              (EMH_ICS_error_base + 195)

/** The property of the attribute cannot be changed as it is referenced by a classification ICO object property. */
#define SML_ERR_ATTRIBUTE_IS_REFERENCED                         (EMH_ICS_error_base + 196)

/** The active unit system of a Classification object cannot be changed directly. Instead, use the Classification application to switch the active unit system.*/
#define SML_ERR_CANNOT_CHANGE_UNITSYSTEM                        (EMH_ICS_error_base + 197)

/** The class &quot;%1$&quot; for this Classification object does not exist. If this object was exported from another site, please contact the administrator to synchronize the associated Class hierarchy.*/
#define SML_ERR_CLASS_NOT_EXIST_FOR_ICO                         (EMH_ICS_error_base + 198)

/** The specified tolerance value "%1$" contains an error. Please specify a positive tolerance value. */
#define SML_ERR_INVALID_TOLERANCE_VALUE                         (EMH_ICS_error_base + 199)

/** The &quot;Revise&quot; or &quot;Save As&quot; operation has partially succeeded: the object &quot;%1$&quot; could not be classified under
the Classification class &quot;%2$&quot; because of a lack of write permission.*/
#define SML_ERR_NO_ACCESS_TO_CLASS                              (EMH_ICS_error_base + 200)

/** The Classification object cannot be created or updated due to an error encountered with the attribute "%2$" (%1$). */
#define SML_ERR_ATTRIBUTE_ERR                                   (EMH_ICS_error_base + 201)

/** The value for this attribute cannot be set as it exceeds the total maximum length of 256 characters. */
#define SML_ERR_TO_MANY_VALUES_FOR_VLA                          ( EMH_ICS_error_base + 202 )

/** The class attribute "%1$" could not be added to the class "%2$". */
#define SML_ERR_ADD_ATTRIBUTE_ERR                               (EMH_ICS_error_base + 203)

/** The type "%1$" for POM class Dataset cannot be found. */
#define SML_ERR_CANNOT_GET_DATASET_TYPE                         (EMH_ICS_error_base + 204)

/** The provided type "%1$" is not a Dataset type. */
#define SML_ERR_NO_DATASET_TYPE                                 (EMH_ICS_error_base + 205)

/** A range search cannot be performed on the "%1$" attribute with ID "%2$", because it is a string attribute. Please either execute a regular search for string attributes or surround the search string with quotes to execute an exact search.*/
#define SML_ERR_RANGE_SEARCH_ON_STRING                          (EMH_ICS_error_base + 206)

/** A range search cannot be performed on the "%1$" attribute with ID "%2$", because it is a Key LOV attribute. Please either execute a regular search for Key LOV attributes or surround the search string with quotes to execute an exact search.*/
#define SML_ERR_RANGE_SEARCH_ON_KEYLOV                          (EMH_ICS_error_base + 207)

/** A relational search (less than, greater than, etc.) cannot be performed on the "%1$" attribute with ID "%2$", because it is a Key LOV attribute. Please either execute a regular search for Key LOV attributes or surround the search string with quotes to execute an exact search.*/
#define SML_ERR_RELATIONAL_SEARCH_ON_KEYLOV                     (EMH_ICS_error_base + 208)

/** The specified search expression "%1$" contains an error. Please specify a tolerance value at the end of the search expression. */
#define SML_ERR_INVALID_TOLERANCE_EXPRESSION                    (EMH_ICS_error_base + 209)

/**The value "%1$" specified to search on the attribute "%2$" does not form a valid expression.*/
#define SML_ERR_INVALID_QUERY_EXPRESSION                        (EMH_ICS_error_base + 210)

/** The dependency information cannot be set, because it is already inherited. */
#define SML_ERR_DEPENDENCY_CANNOT_BE_SET                        (EMH_ICS_error_base + 211)

/** The dependency configuration is not valid.  */
#define SML_ERR_DEPENDENCY_CONFIGURATION_NOT_VALID              (EMH_ICS_error_base + 212)

/** The dependency attribute is not valid.  */
#define SML_ERR_DEPENDENCY_ATTRIBUTE_NOT_VALID                  (EMH_ICS_error_base + 213)

/** Either all the sub-menus must contain a key, or none of them. */
#define SML_ERR_KEYLOV_DEPENDENCY_VIOLATION                     (EMH_ICS_error_base + 214)

/** The provided key &quot;%1$&quot; for Key LOV &quot;%2$&quot; is already used in another entry. */
#define SML_ERR_KEY_NOT_UNIQUE                                  (EMH_ICS_error_base + 215)

/** A wildcard search is not supported. */
#define SML_ERR_WILDCARD_NOT_SUPPORTED                          (EMH_ICS_error_base + 216)

/** The mandatory name of the Key LOV is either not set or set to the initial temporary value because the server crashed before. Please set the correct name.*/
#define SML_ERR_STXT_NAME_MISSING                               (EMH_ICS_error_base + 217)

/** The relational operators cannot be used while searching for attributes with multiple values. The valid operators are equal and wildcard. */
#define SML_ERR_VLA_RELATIONAL_OPERATOR                        (EMH_ICS_error_base + 218)

/** The invalid schema input. */
#define SML_ERR_SCHEMA_NOT_VALID                               (EMH_ICS_error_base + 219)

/** The file "%1$" could not be found. */
#define SML_ERR_FILE_NOT_FOUND                                 (EMH_ICS_error_base + 220)

/** The input request is not a valid JSON file. */
#define SML_ERR_NO_VALID_JSON                                  (EMH_ICS_error_base + 221)

/** Could not find "Has application(ClassificationAdministration)" rule in AM rule tree. */
#define SML_ERR_CLS_ADMIN_RULE_NOT_FOUND                       (EMH_ICS_error_base + 222)

/** Error in AM rule tree: "Has application(ClassificationAdministration)->ClsAdminObjectACL" is not unique. */
#define SML_ERR_CLS_ADMIN_RULE_NOT_UNIQUE                      (EMH_ICS_error_base + 223)


/*
** Error numbers from EMH_ICS_error_base+351 up to 400 are reserved for SML_ERR_FORMAT...
*/

/** Incorrect A flag */
#define SML_ERR_FORMAT_INCORRECT_A_FLAG                        (EMH_ICS_error_base + 351)

/** Incorrect B flag */
#define SML_ERR_FORMAT_INCORRECT_B_FLAG                        (EMH_ICS_error_base + 352)

/** Incorrect type */
#define SML_ERR_FORMAT_INCORRECT_T_FLAG                         (EMH_ICS_error_base + 353)

/** Not a number */
#define SML_ERR_FORMAT_NO_NUMBER                                (EMH_ICS_error_base + 354)

/** Incorrect format specification: precision greater than total length */
#define SML_ERR_FORMAT_DECIMAL_POINT_CONFLICT                   (EMH_ICS_error_base + 355)

/** Too many digits before decimal point */
#define SML_ERR_FORMAT_TOO_MANY_DIGITS_LEFT_TO_DECIMAL_POINT    (EMH_ICS_error_base + 356)

/** Too many characters */
#define SML_ERR_FORMAT_TOO_MANY_CHARS                           (EMH_ICS_error_base + 357)

/** System error: local time cannot be determined */
#define SML_ERR_FORMAT_NO_LOCAL_TIME                            (EMH_ICS_error_base + 358)

/** Not a year */
#define SML_ERR_FORMAT_INCORRECT_YEAR                           (EMH_ICS_error_base + 359)

/** Not a month */
#define SML_ERR_FORMAT_INCORRECT_MONTH                          (EMH_ICS_error_base + 360)

/** Not a day */
#define SML_ERR_FORMAT_INCORRECT_DAY                            (EMH_ICS_error_base + 361)

/** Not an hour */
#define SML_ERR_FORMAT_INCORRECT_HOUR                           (EMH_ICS_error_base + 362)

/** Not a minute */
#define SML_ERR_FORMAT_INCORRECT_MINUTE                         (EMH_ICS_error_base + 363)

/** Not a second */
#define SML_ERR_FORMAT_INCORRECT_SECOND                         (EMH_ICS_error_base + 364)

/** Invalid format */
#define SML_ERR_FORMAT_INCORRECT_FORMAT                         (EMH_ICS_error_base + 365)

/** Invalid denominator */
#define SML_ERR_FORMAT_INCORRECT_DENOMINATOR                    (EMH_ICS_error_base + 366)

/** Invalid nominator */
#define SML_ERR_FORMAT_INCORRECT_NOMINATOR                      (EMH_ICS_error_base + 367)

/** Too many digits behind decimal point */
#define SML_ERR_FORMAT_TOO_MANY_DIGITS_RIGHT_TO_DECIMAL_POINT   (EMH_ICS_error_base + 368)

/** Invalid date */
#define SML_ERR_FORMAT_INCORRECT_DATE                           (EMH_ICS_error_base + 369)

/** Internal error */
#define SML_ERR_FORMAT_INTERNAL_ERROR                           (EMH_ICS_error_base + 370)

/** Invalid time range */
#define SML_ERR_FORMAT_INCORRECT_TIME_RANGE                     (EMH_ICS_error_base + 371)

/** Invalid character */
#define SML_ERR_FORMAT_INVALID_CHARACTER                        (EMH_ICS_error_base + 372)

/** Too few expressions */
#define SML_ERR_TOO_FEW_EXPRESSIONS                             (EMH_ICS_error_base + 373)

/** Invalid Value: Value must be positive. */
#define SML_ERR_FORMAT_VALUE_MUST_BE_POSITIVE                   (EMH_ICS_error_base + 374)

/** Attributes cannot be added to a Group in Classification. Please select a Class or View to add the attributes. **/
#define SML_ERR_CANNOT_ADD_ATTRIBUTE_IN_GROUP                   (EMH_ICS_error_base + 375)

#define SML_ERR_FORMAT_MAX_NUMBER                               (EMH_ICS_error_base + 400)

#define SML_ERR_MAX_NUMBER                                      (EMH_ICS_error_base + 400)

#define SML_ERR_NUM                    122


#endif /* SML_ERRORS_H_INCLUDED */

