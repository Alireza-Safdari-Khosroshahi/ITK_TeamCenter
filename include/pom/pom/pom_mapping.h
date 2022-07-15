/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    POM mapping
*/

/*  */

#ifndef POM_MAPPING_INC_INCLUDED
#define POM_MAPPING_INC_INCLUDED

/**
    @defgroup POM_MAPPING Mapping
    @ingroup POM
    @{
*/

/** @if DOX_IGNORE
    Codes used in mapping true/false to DB integers. This is only used by
    dms_util.c functions print value and find att. It is only here in order
    to make it visible to pom.inc and hence the SQL using world.
@endif */

#define DMS_true_str        "1"
#define DMS_false_str       "0"
#define DMS_true            1
#define DMS_false           0

/** @if DOX_IGNORE
    Columns names made public via "pom_tokens.inc".
    these are needed for those who wish to do their own mapping.
    if DDS_u_suffix or DDS_c_suffix are changed make sure that
    DDS_pval_nameu and DDS_cv_valueu are updated
@endif */

#define DDS_puid_name       "puid"
#define DDS_pseq_name       "pseq"
#define DDS_pval_name       "pval"
#define DDS_pval_nameu      "pvalu"
#define DDS_pval_namec      "pvalc"
#define DDS_u_suffix        "u"     /* used for UID values */
#define DDS_c_suffix        "c"     /* used for target class id values */
#define DDS_l_suffix        "l"     /* used for long string length values */
#define DDS_cv_apid         "capid"
#define DDS_cv_cpid         "ccpid"
#define DDS_cv_site         "csite"
#define DDS_cv_seq          "cseq"
#define DDS_cv_value        "cval"
#define DDS_cv_valueu       "cvalu"
#define DDS_cv_valuec       "cvalc"

/**
    @name CV base table names
    @{
*/
#define DDS_cv_logical      "pclass_vars_logical"
#define DDS_cv_char         "pclass_vars_char"
#define DDS_cv_short        "pclass_vars_short"
#define DDS_cv_int          "pclass_vars_int"
#define DDS_cv_float        "pclass_vars_float"
#define DDS_cv_double       "pclass_vars_double"
#define DDS_cv_date         "pclass_vars_date"
#define DDS_cv_string       "pclass_vars_string"
#define DDS_cv_note         "pclass_vars_note"
#define DDS_cv_untyped_ref  "pclass_vars_untyped_ref"
#define DDS_cv_typed_ref    "pclass_vars_typed_ref"
#define DDS_cv_external_ref "pclass_vars_external_ref"
/** @} */

/**
    @name As seen from the interface...
    @{
*/
#define POM_db_true         DMS_true
#define POM_db_false        DMS_false
#define POM_puid_name       DDS_puid_name
#define POM_pseq_name       DDS_pseq_name
#define POM_pval_name       DDS_pval_name
#define POM_u_suffix        DDS_u_suffix
#define POM_c_suffix        DDS_c_suffix
#define POM_cv_apid         DDS_cv_apid
#define POM_cv_cpid         DDS_cv_cpid
#define POM_cv_site         DDS_cv_site
#define POM_cv_seq          DDS_cv_seq
#define POM_cv_value        DDS_cv_value

#define POM_cv_logical      DDS_cv_logical
#define POM_cv_char         DDS_cv_char
#define POM_cv_short        DDS_cv_short
#define POM_cv_int          DDS_cv_int
#define POM_cv_float        DDS_cv_float
#define POM_cv_double       DDS_cv_double
#define POM_cv_date         DDS_cv_date
#define POM_cv_string       DDS_cv_string
#define POM_cv_note         DDS_cv_note
#define POM_cv_untyped_ref  DDS_cv_untyped_ref
#define POM_cv_typed_ref    DDS_cv_typed_ref
#define POM_cv_external_ref DDS_cv_external_ref
/** @} */

/** @} */

#endif
