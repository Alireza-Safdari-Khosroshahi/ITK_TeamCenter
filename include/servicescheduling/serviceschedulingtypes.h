/* 
    @<COPYRIGHT_START>@
    ===============================================
    Copyright 2011 UGS Corp. All Rights Reserved.
    ===============================================
    @<COPYRIGHT_END>@
*/


/*

    @file        serviceschedulingtypes.h

    Description: This File gives the Definitions of all the servicescheduling
                 Types used
*/

#ifndef SERVICESCHEDULING_TYPES_H
#define SERVICESCHEDULING_TYPES_H

/* SERVICESCHEDULING Relation Types */
/*    Work Order */
#define SSS_CMHASWORKBREAKDOWNREL          "CMHasWorkBreakdown"
#define SSS_SAM0WORKPERFORMEDATREL         "Sam0WorkPerformedAt"
#define SSS_SSS0WORKFORASSETTREL           "SSS0WorkForAsset"
#define SSS_SSS0WKORDCUSTOMERCONTACTREL    "SSS0WkOrderCustomerContact"
#define SSS_LOCATIONINCOMPANYREL           "LocationInCompany"

/*   Job Activity */
#define SSS_SSS0SPECIFIESCHARTOCAPTUREREL  "SSS0SpecifiesCharToCapture"
                                             
/*   Job Card */
#define SSS_CMHASIMPACTEDPARTREL           "CMHasImpactedItem"


/* SERVICESCHEDULING Attribute names */
/*    Work Order */
#define SSS_SSS0WKORDSCHEDULEATTR          "sss0WkOrdSchedule"
#define SSS_SSS0PHYSICALLOCATIONATTR       "sss0WkOrdPhysLoc"
#define SSS_SSS0WKORDASSETATTR             "sss0WkOrdAsset"
#define SSS_SSS0WKORDLOCINCOMPANYTATTR     "sss0WkOrdLocInCompany"
#define SSS_SSS0WKORDCUSTCONTACTATTR       "sss0WkOrdCustContact"
#define SSS_SSS0SPECIFIESCHARTOCAPTUREATTR "sss0SpecifiesCharToCapture"

/*   Job Card */
#define SSS_SSS0JOBCARDASSETATTR           "sss0JobCardAsset"
#define SSS_SSS0JOBCARDIMPPARTATTR         "sss0JobCardImpPart"

/*   Job Activity */
#define SSS_SSS0PARTSMOVEDATTR             "sss0partsMoved"

/*   Part Movement */
#define SSS_INSTALLTEXT                    "Install"
#define SSS_REPLACETEXT                    "Replace"

#endif
