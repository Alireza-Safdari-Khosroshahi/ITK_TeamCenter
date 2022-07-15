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

    This file contains the exposed defines for Classification
*/

#ifndef ICS_DEFINES_H_INCLUDED
#define ICS_DEFINES_H_INCLUDED

/**
    @defgroup ICS_DEFINES Defines
    @ingroup ICS
    @{
*/


/**
   Defines if the key of a Classification KeyLOV entry should be displayed -
   if not set always key and value are displayed.
   <br/>If set only the value will be displayed.
*/
#define ICS_KEYLOV_HIDE_KEY  (1 << 0)


/**
    @name General internal attributes
    @{
*/
/** Defines the internal attribute id for the UID property of Classification objects */
#define ICS_UNCT_PUID                    -590

/** Defines the internal attribute id for the CID property of Classification objects */
#define ICS_UNCT_CID                     -600

/** Defines the internal attribute id for the SID property of Classification objects */
#define ICS_UNCT_SID                     -620

/** Defines the internal attribute id for the CREATE_NAME property of Classification objects */
#define ICS_UNCT_CREATE_NAME             -615

/** Defines the internal attribute id for the CREATE_DATE property of Classification objects */
#define ICS_UNCT_CREATE_DATE             -616

/** Defines the internal attribute id for the MODIFY_NAME property of Classification objects */
#define ICS_UNCT_MODIFY_NAME             -618

/** Defines the internal attribute id for the MODIFY_DATE property of Classification objects */
#define ICS_UNCT_MODIFY_DATE             -619

/** Defines the internal attribute id for the SID/PUID property  of Classification object*/
#define ICS_UNCT_INSTANCE_SID_PUID       -728

/** Defines the internal attribute id for the CID/PUID property  of Classification object*/
#define ICS_UNCT_INSTANCE_CID_PUID       -729

/** Defines the internal attribute id for icm0.fnd0IcoType*/
#define ICS_UNCT_INSTANCE_ICO_TYPE       -732 

/** Defines if this property is set the search will be validated against revision rule */
#define ICS_UNCT_INSTANCE_REVISION_RULE  -726

/** Defines if this property is set to true the search will be validated against READ accsess*/
#define ICS_UNCT_INSTANCE_READ_ACCESS    -727 
/** @} */



/**
    @name Classification Class/Classification View (smlb0/bldb0) specific attributes
    @{
*/
/** Defines the internal attribute id for the class name property of a Classification class/view (smlb0/bldb0) */
#define ICS_UNCT_CLASS_NAME         -607

/** Defines the internal attribute id for the class short name property of a Classification class/view (smlb0/bldb0) */
#define ICS_UNCT_CLASS_SHORTNAME    -608

/** Defines the internal attribute id for the user1 property of a Classification class/view (smlb0/bldb0) */
#define ICS_UNCT_CLASS_USER1        -612

/** Defines the internal attribute id for the user2 property of a Classification class/view (smlb0/bldb0) */
#define ICS_UNCT_CLASS_USER2        -613
/**
   @}
*/

/**
    @name Classification object (ICO/icm0)
    @{
*/
/** Defines the internal attribute id for the EREF property (represented as an integer) of a Classification object (ICO/icm0) */
#define ICS_UNCT_INSTANCE_EREF      -598

/** Defines the internal attribute id for the EREF property (represented as a string) of a Classification object (ICO/icm0) */
#define ICS_UNCT_INSTANCE_PEREF     -589

/** Defines the internal attribute id for the ID property of a Classification object (ICO/icm0) */
#define ICS_UNCT_INSTANCE_ID        -599

/** Defines the internal attribute id for the UNIT_SYSTEM property of a Classification object (ICO/icm0) */
#define ICS_UNCT_INSTANCE_UNIT      -630

/** Defines the internal attribute id for the type of the classified object of a Classification object (ICO/icm0) */
#define ICS_UNCT_INSTANCE_WSO_TYPE  -570
/**
   @}
*/

/**
   @}
*/

#endif
