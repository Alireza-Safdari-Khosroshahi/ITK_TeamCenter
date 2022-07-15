/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*
    H+++  File description:

This file contains some definition related to Application Interface module.

    File   : sample_inh.h
    Module : user_exits
 */

#define    APP_NAME    "SampleForm"
#define APP_PASSWD    "sampleform"

/* Define for the class name */

#define    SAMPLE_FORM_CLASS_NAME    "SampleForm"

/* Defines for the attribute names */

#define SF_ID                  "id"
#define SF_DESC                "desc"
#define SF_TYPE                "type"
#define SF_SIZE                "size"
#define SF_MAT                "material"

/* Define the string size for string attributes,  */
/* needed by database and POM_define_attr functions */

#define ID_STR_SIZE        30
#define DESC_STR_SIZE        200
#define TYPE_STR_SIZE        30
#define SIZE_STR_SIZE        30
#define MAT_STR_SIZE        30


/* combination of attribute types for the attributes */

#define ATTR_TYPE ( (POM_null_is_valid + POM_public_read + POM_public_write) )
