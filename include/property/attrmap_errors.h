/*==================================================================================================

                     Copyright (c) 1999 Unigraphics Solutions
                       Unpublished - All rights reserved

====================================================================================================
File description:

====================================================================================================
   Date      Name                    Description of Change
22-Feb-1999  Mark Fawcett            Created
03-Mar-1999  Mark Fawcett            add some errors
10-Mar-1999  Mark Fawcett            more errors
12-Mar-1999  Mark Fawcett            more errors
02-Jul-1999  Mark Fawcett            add sa-only-test-mappings
05-Sep-2001  Charles Cheng           add illegal ICS attribute id
15-Nov-2001  chengc                  V8.0 Attribute Synchronization
09-Jan-2002  helmutl                 Merge from Charlie
09-Jan-2002  helmutl                 Merge fro P8.0.0.3 promote
06-Aug-2002  Aaron Ruckman           Split libtc.dll project
05-Sep-2002  Aaron Ruckman           Update headers as part of dll splitiman project
22-Nov-2002  Tim Baverstock          Normalise inclusion
$HISTORY$
==================================================================================================*/


#ifndef ATTRMAP_ERRORS_H
#define ATTRMAP_ERRORS_H

#include <common/emh_const.h>
#include <property/libproperty_exports.h>

#define ATTRMAP_bad_tag                     (EMH_ATTRMAP_error_base + 1)    /* 60001 */
    /* Tag is not a mapping */

#define ATTRMAP_bad_mapping_def_str         (EMH_ATTRMAP_error_base + 2)    /* 60002 */
    /* Mapping definition string is invalid */

#define ATTRMAP_cannot_resolve_mapping      (EMH_ATTRMAP_error_base + 3)    /* 60003 */
    /* Mapping definition cannot be resolved */

#define ATTRMAP_internal_error              (EMH_ATTRMAP_error_base + 4)    /* 60004 */
    /* Something Oo occurred */

#define ATTRMAP_cannot_find_related_object  (EMH_ATTRMAP_error_base + 5)    /* 60005 */
    /* Cannot find related object while resolving mapping part */

#define ATTRMAP_ambiguous_related_object    (EMH_ATTRMAP_error_base + 6)    /* 60006 */
    /* Cannot find unambiguous related object while resolving mapping part */

#define ATTRMAP_cannot_resolve_property     (EMH_ATTRMAP_error_base + 7)    /* 60007 */
    /* Property cannot be resolved */

#define ATTRMAP_cannot_resolve_propdesc     (EMH_ATTRMAP_error_base + 8)    /* 60008 */
    /* Property descriptor cannot be resolved */

#define ATTRMAP_cannot_resolve_type         (EMH_ATTRMAP_error_base + 9)    /* 60009 */
    /* Type information cannot be resolved */

#define ATTRMAP_wrong_object_type           (EMH_ATTRMAP_error_base + 10)   /* 60010 */
    /* Wrong type of object for mapping */

#define ATTRMAP_non_sa_may_not_use_test_mappings    (EMH_ATTRMAP_error_base + 11)   /* 60011 */
    /* Only SAs may use the test mappings */

#define ATTRMAP_illegal_ics_attr_id         (EMH_ATTRMAP_error_base + 12)    /* 60012 */
    /* Illegal ICS attribute id definition (id should be > 999 or < -999)  */

#define ATTRMAP_illegal_ics_class_id         (EMH_ATTRMAP_error_base + 13)    /* 60013 */
    /* Illegal ICS class id definition  */
    
#define ATTRMAP_cannot_find_valid_dataset      (EMH_ATTRMAP_error_base + 14)    /* 60014 */
    /* Cannot find a valid dataset object */

#include <property/libproperty_undef.h>
#endif /* ATTRMAP_ERRORS_H */
