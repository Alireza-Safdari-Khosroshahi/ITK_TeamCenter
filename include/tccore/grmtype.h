/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    GRM type
*/

/*  */

#ifndef GRMTYPE_H
#define GRMTYPE_H

/**
    @defgroup GRMTYPE Types
    @ingroup GRM
    @{
*/

/**
    @name Teamcenter standard relation type names
    @{
*/
#define TC_document_sheet_rtype   "IMAN_document_sheet"
#define TC_master_form_rtype      "IMAN_master_form"
#define TC_manifestation_rtype    "IMAN_manifestation"
#define TC_reference_rtype        "IMAN_reference"
#define TC_requirement_rtype      "IMAN_requirement"
#define TC_specification_rtype    "IMAN_specification"
#define TC_archive_library_rtype  "IMAN_archive_library"
#define TC_attaches_rtype         "TC_Attaches"
#define Thumbnail_Source_rtype    "Thumbnail_Source"
#define Thumbnail_rtype           "Thumbnail"
#define Derived_Thumbnail_rtype   "Derived_Thumbnail"

/** @} */

/** @if DOX_IGNORE
    (PDJ)  16-Feb-1996
    From V3.4 on, whenever a Item, Item Revision or Dataset is revised/copied/save as'd,
    the new object references the source object via this based on relationship.
    New object is primary, source object is secondary to relation.
    When either object is deleted the relationship is lost.
@endif */

#define TC_based_on_rtype         "IMAN_based_on"
#define TC_baseline_rtype         "IMAN_baseline"
#define TC_snapshot_rtype         "IMAN_snapshot"

/**
    @name VI relation type names
    @{
*/
#define TC_vi_sos_rtype                 "IMAN_vi_sos"
#define TC_vi_linked_module_rtype       "IMAN_vi_linked_module"
#define TC_vi_unlinked_module_rtype     "IMAN_vi_unlinked_module"
#define TC_vi_instantiated_from_rtype   "TC_vi_instantiated_from"
/** @} */

#define TC_ic_intent_rtype              "IMAN_ic_intent"

/** @name Multisite Part Families
    @{
*/
#define TC_part_family_rtype      "IMAN_UG_part_family_link"
/** @name Part Design relation
    @{
*/
#define TC_Is_Represented_By_rtype      "TC_Is_Represented_By"
/** @} */


#define TC_Primary_Design_Representation_rtype      "TC_Primary_Design_Representation"

#define TC_Rendering            "IMAN_Rendering"
/** @} */

/** @name Participant relation
    @{
*/
#define TC_Has_Participant      "HasParticipant"
/** @} */

#endif
