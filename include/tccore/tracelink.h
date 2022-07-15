/* ================================================== 
Copyright 2014. 
Siemens Product Lifecycle Management Software Inc. 
All Rights Reserved. 
================================================== */ 
/**
    @file

    This header file contains ITK API definitions for Tracelink related functionality.
    Tracelink is a subtype of IMANRelation, a Tracelink establishes a directional relationship between two objects.
    Tracelink can be created on absolute occurrences and user can run Trace Report on objects with Tracelinks to do
    impact analysis.
*/

/*  */

/**
    @defgroup TL Tracelink
    @ingroup tccore

    This module defines the required ITK interface for Tracelink related operations.
    @{
*/

#ifndef TEAMCENTER_TRACELINK_H 
#define TEAMCENTER_TRACELINK_H

#include <unidefs.h>
#include <tccore/libtccore_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/** 
   Searches all Tracelink objects in the database that point to the given defining tags.
   <br/>The @p source object can either be a BOM Line or the primary object of Tracelink, which can be Workspace object or Absoccdata.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#GRM_invalid_primary_object, if @p source is NULLTAG or invalid.
    </ul>
*/
extern TCCORE_API int TL_find_trace_links_for_defining (
    tag_t source,               /**<  (I) Tracelink source tag */
    int *tracelink_count,       /**<  (O) Number of Tracelinks found */
    tag_t **tracelink_tags      /**<  (OF) tracelink_count The found Tracelink objects */
);

/** 
  Searches for all Tracelink objects in the database that point to the given complying tags.
  <br/>The @p target object can either be a BOM Line or the secondary object of Tracelink, which can be Workspace object or Absoccdata.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#GRM_invalid_secondary_object, if @p target is NULLTAG or invalid.
    </ul>
*/
extern TCCORE_API int TL_find_trace_links_for_complying  (
    tag_t target,               /**< (I) Tracelink target tag */
    int *tracelink_count,       /**< (O) Number of Tracelinks found */
    tag_t **tracelink_tags      /**< (OF) tracelink_count The found Tracelink objects */
);

/**
    Searches all the in-context Tracelinks present under the TopLine of given BOM Window, only the Tracelinks from defining end will be returned.
    <br/>It will return only the Tracelinks which are created in context of topline of given BOM Window.
    User needs to provide the configured BOM Window as input and Tracelinks will be returned on that configured structure only.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TL_null_value_passed, if @p bom_window object is NULLTAG or invalid.
    </ul>
*/
extern TCCORE_API int TL_find_in_context_trace_links_for_defining(
    tag_t bom_window,               /**< (I) Configured BOM Window tag */
    int * tracelink_count,          /**< (O) Count of Tracelinks present under BOM Window considering top line as context line */
    tag_t ** bom_lines,             /**< (OF) tracelink_count List of BOM Line tags where Tracelinks are present */
    tag_t ** tracelinks             /**< (OF) tracelink_count List of Tracelinks present for each BOM Line in bom_lines there is one to one mapping between bom_lines and tracelinks */
);

/**
    Searches all the in-context Tracelinks present under the TopLine of given BOM Window, only the Tracelinks from complying end will be returned.
    <br/>It will return only the Tracelinks which are created in context of topline of given BOM Window.
    User needs to provide the configured BOM Window as input and Tracelinks will be returned on that configured structure only.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#TL_null_value_passed, if @p bom_window object is NULLTAG or invalid.
    </ul>
*/
extern TCCORE_API int TL_find_in_context_trace_links_for_complying(
    tag_t bom_window,              /**< (I) Configured BOM Window tag */
    int * tracelink_count,         /**< (O) Count of Tracelinks present under BOM Window considering top line as context line */
    tag_t ** bom_lines,            /**< (OF) tracelink_count List of bom line tags where Tracelinks are present */
    tag_t ** tracelinks            /**< (OF) tracelink_count List of Tracelinks present for each BOM Line in bom_lines there is one to one mapping between bom_lines and tracelinks */
);

/** @} */

#ifdef __cplusplus
}
#endif

#include <tccore/libtccore_undef.h>
#endif
