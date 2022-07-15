/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Defines error codes used with Mechatronics
*/

/*  */

#ifndef MECHATRONICS_ERRORS_H
#define MECHATRONICS_ERRORS_H

#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif
#include <common/tc_deprecation_macros.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup MECHATRONICS Mechatronics
*/

/**
    @defgroup MECHATRONICS_ERRORS Mechatronics Errors
    @ingroup MECHATRONICS
    @{
*/

#define MECHATRONICS_ERROR_BASE       EMH_MECHATRONICS_error_base

/**
    The provided input "%1$" is invalid.
*/
#define MECH_invalid_input          ((EMH_MECHATRONICS_error_base)+2)

/**
    The role "%1$" is not defined in the database.
*/
#define SIG_invalid_role            ((EMH_MECHATRONICS_error_base)+3)

/**
    No association between the signal "%1$" and the system "%2$".
*/
#define SIG_no_association          ((EMH_MECHATRONICS_error_base)+4)

/**
    No process variable is associated to the signal %1$.
*/
#define SIG_no_pv_associated        ((EMH_MECHATRONICS_error_base)+5)

/**
    %1$ is an invalid selection.
Expected a process variable.
*/
#define SIG_not_a_pv                ((EMH_MECHATRONICS_error_base)+6)

/**
    %1$ is an invalid selection.
Expected a signal.
*/
#define SIG_not_a_signal            ((EMH_MECHATRONICS_error_base)+7)

/**
    The signal "%1$" and process variable "%2$" are already associated.
*/
#define SIG_pv_already_attached     ((EMH_MECHATRONICS_error_base)+8)

/** @deprecated #SIG_sig_has_a_pv deprecated in Teamcenter 11.1. */
#define SIG_sig_has_a_pv            ((EMH_MECHATRONICS_error_base)+9)
TC_DEPRECATED_PREPROCESSOR( "11.1", SIG_sig_has_a_pv, "" )

/** @deprecated #SIG_duplicate_association deprecated in Teamcenter 11.1. */
#define SIG_duplicate_association   ((EMH_MECHATRONICS_error_base)+10)
TC_DEPRECATED_PREPROCESSOR( "11.1", SIG_duplicate_association, "" )


/**
    Memory error in Signal module.
*/
#define SIG_mem_error               ((EMH_MECHATRONICS_error_base)+11)

/**
    No redundant signal associated to the signal.
*/
#define SIG_no_redundant            ((EMH_MECHATRONICS_error_base)+12)

/**
    No characteristics attached to signal revision.
*/
#define SIG_no_characteristics      ((EMH_MECHATRONICS_error_base)+13)

/**
    No value attached to signal revision / signal line.
*/
#define SIG_no_value                ((EMH_MECHATRONICS_error_base)+14)

/**
    No UOM attached to signal.
*/
#define SIG_no_uom                  ((EMH_MECHATRONICS_error_base)+15)

/**
    Signal parent %1$ needs to be the ancestor of associating Line %2$.
*/
#define SIG_invalid_hierarchy       ((EMH_MECHATRONICS_error_base)+16)

/**
    Topline of structure cannot be primary line of association.
*/
#define SIG_is_topline              ((EMH_MECHATRONICS_error_base)+17)

/**
    The type "%1$" (%2$) for the secondary object is an invalid selection for this relationship.
The following types, and their sub-types, are valid secondary object selections:
%3$
*/
#define MECH_invalid_secondary      ((EMH_MECHATRONICS_error_base)+18)

/**
    The primary object of type "%1$" is an invalid selection for this relationship.
The following types, and their sub-types, are valid primary object selections:
"%2$"
*/
#define MECH_invalid_primary        ((EMH_MECHATRONICS_error_base)+19)

/**
    Primary already exists in the lookup table.
*/
#define MECH_duplicate_primary      ((EMH_MECHATRONICS_error_base)+20)

/**
    No secondary found for the given primary in lookup table.
*/
#define MECH_no_secondary           ((EMH_MECHATRONICS_error_base)+21)

/**
    %1$ parent is not an ancestor of "%2$".
*/
#define MECH_no_ancestor            ((EMH_MECHATRONICS_error_base)+22)

/**
    No secondary object types specified corresponding to the rule for primary object of type "%1$".
*/
#define MECH_no_secondary_for_rule  ((EMH_MECHATRONICS_error_base)+23)

/**
    The tag for the bomline specified is invalid.
*/
#define MECH_invalid_bomline        ((EMH_MECHATRONICS_error_base)+24)

/**
    The tag for the connection line specified is invalid.
*/
#define MECH_invalid_connection_line ((EMH_MECHATRONICS_error_base)+25)

/**
    Memory error has occurred in %1$.
*/
#define MECH_memory_error           ((EMH_MECHATRONICS_error_base)+26)

/**
    A NULL string is passed for name.
*/
#define MECH_invalid_name           ((EMH_MECHATRONICS_error_base)+27)

/**
    Invalid Signal Line, A NULLTAG is passed to Signal Line.
*/
#define SIG_invalid_signal_line     ((EMH_MECHATRONICS_error_base)+28)

/**
    Invalid ProcessVariable Line, A NULLTAG is passed to ProcessVariable Line.
*/
#define SIG_invalid_pv_line         ((EMH_MECHATRONICS_error_base)+29)

/**
    Invalid Associating Line, A NULLTAG is passed to Associating Line.
*/
#define SIG_invalid_associating_line ((EMH_MECHATRONICS_error_base)+30)

/**
    Invalid Redundant Line, A NULLTAG is passed to Redundant Line.
*/
#define SIG_invalid_redundant_line     ((EMH_MECHATRONICS_error_base)+31)

/**
    Invalid UOM object, A NULLTAG is passed to UOM object.
*/
#define SIG_invalid_uom     ((EMH_MECHATRONICS_error_base)+32)

/**
    Invalid Signal, A NULLTAG is passed to Signal.
*/
#define SIG_invalid_signal     ((EMH_MECHATRONICS_error_base)+33)

/**
    Invalid Signal Revision object, A NULLTAG is passed to Signal Revision object.
*/
#define SIG_invalid_signal_rev     ((EMH_MECHATRONICS_error_base)+34)

/**
    More than one value is found for the signal.
*/
#define SIG_multiple_value     ((EMH_MECHATRONICS_error_base)+35)

/**
    More than one value found for the Process Variable.
*/
#define SIG_multiple_pv     ((EMH_MECHATRONICS_error_base)+36)

/**
    Can't modify Signal Revision.
*/
#define SIG_rev_not_modify     ((EMH_MECHATRONICS_error_base)+37)

/**
    Number of Source Components more than defined in Preference.
*/
#define ALLOC_invalid_source_cardinality   ((EMH_MECHATRONICS_error_base)+38)

/**
    Number of Target Components more than defined in Preference.
*/
#define ALLOC_invalid_target_cardinality   ((EMH_MECHATRONICS_error_base)+39)

/**
    Cannot create Allocation - Please check Cardinality values for Source and Targets.
*/
#define ALLOC_invalid_source_target_cardinality   ((EMH_MECHATRONICS_error_base)+40)

/**
    Cannot create Allocation Map - Please check the BOMView types allowed.
*/
#define ALLOC_invalid_bom_view_for_map  ((EMH_MECHATRONICS_error_base)+41)

/**
    The creation of the Allocation Data object for change has failed. Please see the syslog for more information.
*/
#define ALLOC_invalid_allocation_data   ((EMH_MECHATRONICS_error_base)+42)

/**
    "%2$" (of type "%1$") cannot be associated as a Signal Target, because its direction is not "Input".
*/
#define SIG_gde_direction_not_input     ((EMH_MECHATRONICS_error_base)+43)

/**
    "%2$" (of type "%1$") cannot be associated as a Signal Source, because its direction is not "Output".
*/
#define SIG_gde_direction_not_output    ((EMH_MECHATRONICS_error_base)+44)

/**
    The direction of "%2$" (of type "%1$") must be set to "Output", because it is a Signal Source.
*/
#define SIG_gde_direction_stays_output  ((EMH_MECHATRONICS_error_base)+45)

/**
    The direction of "%2$" (of type "%1$") must be set to "Input", because it is a Signal Target.
*/
#define SIG_gde_direction_stays_input   ((EMH_MECHATRONICS_error_base)+46)

/**
    The direction of "%2$" (of type "%1$") cannot be set, because it is related to both Source and Target Signals.
*/
#define SIG_gde_relation_conflict       ((EMH_MECHATRONICS_error_base)+47)

/**
    "%2$" (of type "%1$") is not modifiable.
*/
#define SIG_gde_not_modifiable          ((EMH_MECHATRONICS_error_base)+48)

/**
   "%2$" (of type "%1$") cannot be replaced, because its direction and the one of the replacement object do not match.
*/
#define SIG_direction_mismatch_for_replace ((EMH_MECHATRONICS_error_base)+49)

/**
   "%2$" (of type "%1$") cannot be replaced, because the direction of the replacement object does not match the Signal Association.
*/
#define SIG_direction_invalid_for_replace  ((EMH_MECHATRONICS_error_base)+50)

/**
   "%2$" (of type "%1$") cannot be associated to the Signal "%3$", because its direction value is "Bi-direction". Its value should be "Input", "Output", or empty.
*/
#define SIG_direction_invalid_for_signal_association ((EMH_MECHATRONICS_error_base)+51)

/**
    "%2$" (of type "%1$") cannot be associated to the Signal "%3$", because both its direction and the specified role are empty.
*/
#define SIG_no_role_no_gde_direction    ((EMH_MECHATRONICS_error_base)+52)


/**
    The preference "%1$" contains an invalid secondary object value "%3$" for the primary object type "%2$".
*/
#define MECH_invalid_secondary_type ((EMH_MECHATRONICS_error_base)+53)

/**
    A NULLTAG is passed for the Connection Line.
*/
#define MECH_null_connection_line ((EMH_MECHATRONICS_error_base)+54)

/**
    A NULLTAG is passed for the Context Line.
*/
#define MECH_null_context_line ((EMH_MECHATRONICS_error_base)+55)

/**
    The tag for the context line specified is invalid.
*/
#define MECH_invalid_context_line ((EMH_MECHATRONICS_error_base)+56)

/**
    A NULLTAG is passed for the GDE Line.
*/
#define MECH_null_gde_line ((EMH_MECHATRONICS_error_base)+57)

/**
    The tag for the GDE line specified is invalid.
*/
#define MECH_invalid_gde_line ((EMH_MECHATRONICS_error_base)+58)

/**
    Class of specified object is not found
*/
#define HRN_no_class_found          ((EMH_MECHATRONICS_error_base)+101)

/**
    There is no object as specified attached to the input passed.
*/
#define HRN_no_association          ((EMH_MECHATRONICS_error_base)+102)

/**
    The input passed is already associated to the selected line %1$.
*/
#define HRN_duplicate_association   ((EMH_MECHATRONICS_error_base)+103)

/**
    A NULLTAG is passed for Cavity Line.
*/
#define HRN_invalid_cavity_line   ((EMH_MECHATRONICS_error_base)+104)

/**
    A NULLTAG is passed for Associating line.
*/
#define HRN_invalid_associating_line   ((EMH_MECHATRONICS_error_base)+105)

/**
    Invalid WireProtect Line, A NULLTAG is passed to WireProtect Line.
*/
#define HRN_invalid_wire_protect_line   ((EMH_MECHATRONICS_error_base)+106)

/**
    A NULLTAG is passed for ReferencedComponent.
*/
#define HRN_invalid_referenced_component   ((EMH_MECHATRONICS_error_base)+107)

/**
    A NULLTAG is passed for Fixing Line.
*/
#define HRN_invalid_fixing_line   ((EMH_MECHATRONICS_error_base)+108)

/**
    A NULLTAG is passed for LengthType.
*/
#define HRN_invalid_length_type   ((EMH_MECHATRONICS_error_base)+109)

/**
    A NULLTAG is passed for ColorType.
*/
#define HRN_invalid_color_type   ((EMH_MECHATRONICS_error_base)+110)

/**
    HRN object could not be obtained.
*/
#define HRN_init_object_error   ((EMH_MECHATRONICS_error_base)+111)

/**
    The object "%1$" cannot be revised because it is obsoleted.
*/
#define HRN_not_eligible_to_revise   ((EMH_MECHATRONICS_error_base)+112)

/**
    The tag of the source BOM view specified is invalid.
*/
#define ALLOC_invalid_source_bv     ((EMH_MECHATRONICS_error_base)+201)

/**
    The tag of the target BOM view specified is invalid.
*/
#define ALLOC_invalid_target_bv     ((EMH_MECHATRONICS_error_base)+202)

/**
    AllocationMap cannot be created using the same BOM view as source and target.
*/
#define ALLOC_source_target_same    ((EMH_MECHATRONICS_error_base)+203)

/**
    Modify access to AllocationMap denied.
*/
#define ALLOC_map_not_modifiable    ((EMH_MECHATRONICS_error_base)+204)

/**
    The tag of the AllocationMapRevision is invalid.
*/
#define ALLOC_invalid_map_rev       ((EMH_MECHATRONICS_error_base)+205)

/**
    The tag of the source BOM Line specified is invalid.
*/
#define ALLOC_invalid_source_bomline   ((EMH_MECHATRONICS_error_base)+206)

/**
    The tag of the target BOM Line specified is invalid.
*/
#define ALLOC_invalid_target_bomline     ((EMH_MECHATRONICS_error_base)+207)

/**
    The tag of the Allocation specified is invalid.
*/
#define ALLOC_invalid_allocation       ((EMH_MECHATRONICS_error_base)+208)

/**
    The string specified for the reason is invalid.
*/
#define ALLOC_invalid_reason       ((EMH_MECHATRONICS_error_base)+209)

/**
    The tag of the source BOM Window specified is invalid.
*/
#define ALLOC_invalid_src_bom_window       ((EMH_MECHATRONICS_error_base)+210)

/**
    The tag of the target BOM Window specified is invalid.
*/
#define ALLOC_invalid_target_bom_window    ((EMH_MECHATRONICS_error_base)+211)

/**
    The tag of the IC Revision specified is invalid.
*/
#define ALLOC_invalid_IC_revision    ((EMH_MECHATRONICS_error_base)+212)

/**
    The tag of the Condition object specified is invalid.
*/
#define ALLOC_invalid_condition_object    ((EMH_MECHATRONICS_error_base)+213)

/**
    The tag of the Revision rule specified is invalid.
*/
#define ALLOC_invalid_revision_rule    ((EMH_MECHATRONICS_error_base)+214)

/**
    The tag of the AllocationMap specified is invalid.
*/
#define ALLOC_invalid_map       ((EMH_MECHATRONICS_error_base)+215)

/**
    Allocation cannot be created using the same BOMLine as source and target.
*/
#define ALLOC_source_target_bomline_same    ((EMH_MECHATRONICS_error_base)+216)

/**
    The Source BOMLine %2$ is invalid.
It does not belong to Source product structure.
*/
#define ALLOC_src_bomline_not_in_src_bv    ((EMH_MECHATRONICS_error_base)+217)

/**
     The Target BOMLine %2$ is invalid.
It does not belong to Target product structure.
*/
#define ALLOC_target_bomline_not_in_target_bv    ((EMH_MECHATRONICS_error_base)+218)

/**
    Tags for the source and the target BOMView specified are invalid.
*/
#define ALLOC_invalid_target_source_bv     ((EMH_MECHATRONICS_error_base)+219)

/**
    Absolute Occurrence tag is not available for the specified BOMLine %1$.
*/
#define ALLOC_invalid_AbsOcc_tag     ((EMH_MECHATRONICS_error_base)+220)

/**
    The specified type %1$ does not exist in the Database.
*/
#define ALLOC_invalid_allocation_type    ((EMH_MECHATRONICS_error_base)+221)

/**
    Invalid or no source specified.
*/
#define ALLOC_invalid_source_apn           ((EMH_MECHATRONICS_error_base)+222)

/**
    Invalid or no target specified.
*/

#define ALLOC_invalid_target_apn           ((EMH_MECHATRONICS_error_base)+223)

/**
    Invalid source or target specified.
*/
#define ALLOC_invalid_apn           ((EMH_MECHATRONICS_error_base)+224)

/**
    The specified targets are invalid in IC context.
*/

#define ALLOC_invalid_targets_UsingIC           ((EMH_MECHATRONICS_error_base)+225)

/**
    The specified sources are invalid in IC context.
*/

#define ALLOC_invalid_sources_UsingIC           ((EMH_MECHATRONICS_error_base)+226)

/**
    BOM View list is empty.
*/
#define ALLOC_empty_bv_list          ((EMH_MECHATRONICS_error_base)+227)

/**
    One or more source and target belong to the same Bomview.
*/
#define ALLOC_source_target_in_same_bv          ((EMH_MECHATRONICS_error_base)+228)

/**
    Invalid Query passed.
*/
#define ALLOC_query_error ((EMH_MECHATRONICS_error_base)+229)

/**
    An invalid Absolute Occurrence View Qualifier object (type AbsOccViewQualifier) is specified.
*/
#define ALLOC_invalid_absoccviewqualifier     ((EMH_MECHATRONICS_error_base)+230)

/**
    Invalid defining object.
*/
#define TRACE_invalid_def    ((EMH_MECHATRONICS_error_base)+251)

/**
    Invalid complying object.
*/
#define TRACE_invalid_comp    ((EMH_MECHATRONICS_error_base)+252)

/**
    Invalid Tracelink type.
*/
#define TRACE_invalid_tracelink_type ((EMH_MECHATRONICS_error_base)+253)

/**
    Invalid Tracelink object.
*/
#define TRACE_invalid_tracelink ((EMH_MECHATRONICS_error_base)+254)

/**
    Invalid apn object.
*/
#define TRACE_invalid_apn ((EMH_MECHATRONICS_error_base)+255)

/**
    Defining object already exists in the given Tracelink.
*/
#define TRACE_same_def_comp ((EMH_MECHATRONICS_error_base)+256)

/**
    A Tracelink already exists between the source and the target.
*/
#define TRACE_duplicate_trace    ((EMH_MECHATRONICS_error_base)+257)

/**
    Invalid context for route object.
*/
#define ROUTE_context_not_same      ((EMH_MECHATRONICS_error_base)+301)

/**
    No Routes are associated to this BOM line.
*/
#define ROUTE_no_routes_associated      ((EMH_MECHATRONICS_error_base)+302)

/**
    Display properties are not set for this route.
*/
#define ROUTE_no_display_objects      ((EMH_MECHATRONICS_error_base)+303)

/**
    The input provided is not a location line.
*/
#define ROUTE_invalid_location_line     ((EMH_MECHATRONICS_error_base)+304)

/**
    The invalid input provided. Provide BOM Line object.
*/
#define ROUTE_invalid_defining_item_line ((EMH_MECHATRONICS_error_base)+305)

/**
    The invalid input provided. Provide BOM Line or Routing object.
*/
#define ROUTE_invalid_associating_item_line ((EMH_MECHATRONICS_error_base)+306)

/**
    The role of association to location is invalid.
*/
#define ROUTE_location_invalid_role ((EMH_MECHATRONICS_error_base)+307)

/**
    The "Defining Item" is not set on the selected Location.
*/
#define ROUTE_location_no_defining_item_associated ((EMH_MECHATRONICS_error_base)+308)

/**
    The "Assigned Location" is not defined on the selected Location.
*/
#define ROUTE_location_no_assigning_item_associated ((EMH_MECHATRONICS_error_base)+309)

/**
    The tag for the BOM Window specified is invalid.
*/
#define ROUTE_invalid_bom_window    ((EMH_MECHATRONICS_error_base)+310)

/**
    The tag for the context specified is invalid.
*/
#define ROUTE_invalid_context      ((EMH_MECHATRONICS_error_base)+311)

/**
    The tag for the segment specified is invalid.
*/
#define ROUTE_invalid_segment     ((EMH_MECHATRONICS_error_base)+312)

/**
    The tag for the route specified is invalid.
*/
#define ROUTE_invalid_route     ((EMH_MECHATRONICS_error_base)+313)

/**
    The tag for the node specified is invalid.
*/
#define ROUTE_invalid_node     ((EMH_MECHATRONICS_error_base)+314)

/**
    The tag for the center_curve specified is invalid.
*/
#define ROUTE_invalid_center_curve     ((EMH_MECHATRONICS_error_base)+315)

/**
    The tag of the location specified is invalid.
*/
#define ROUTE_invalid_location     ((EMH_MECHATRONICS_error_base)+316)

/**
    A unique BOM Line could not be identified in the specified BOM Window.
*/
#define MECH_absocc_bomline_error     ((EMH_MECHATRONICS_error_base)+317)
/**
    The %1$ and "%2$" are not created in the same context.
*/
#define ROUTE_route_objects_are_not_in_same_context     ((EMH_MECHATRONICS_error_base)+318)

/**
    An SCMCC internal error occurred.
*/
#define MECH_SCMCC_internal_error           ((EMH_MECHATRONICS_error_base)+319)

/**
    The Topline of structure cannot be primary bomline for association.
*/
#define MECH_primary_is_topline              ((EMH_MECHATRONICS_error_base)+320)


/**
    The Topline of structure cannot be secondary bomline for association.
*/
#define MECH_secondary_is_topline              ((EMH_MECHATRONICS_error_base)+321)

/**
    TThe specified primary and secondary bomline tags are not in same bomwindow.
*/
#define MECH_primary_secondary_are_not_in_same_window              ((EMH_MECHATRONICS_error_base)+322)

/**
    The specified primary and secondary bomlines are already associated.
*/
#define MECH_duplicate_association   ((EMH_MECHATRONICS_error_base)+323)

/**
    The specified relation kind is invalid.
*/
#define MECH_invalid_relation_kind   ((EMH_MECHATRONICS_error_base)+324)

/**
    The specified context level is invalid.
*/
#define MECH_invalid_context_level   ((EMH_MECHATRONICS_error_base)+325)

/**
    Failed to create AllocationWindow, Internal error.
*/
#define ALLOC_window_create_error               ((EMH_MECHATRONICS_error_base)+330)

/**
    Revision rule is not set for the specified AllocationWindow.
*/
#define ALLOC_window_revrule_not_set            ((EMH_MECHATRONICS_error_base)+331)

/**
    Allocation Context is not set for the specified AllocationWindow.
*/
#define ALLOC_window_context_not_set            ((EMH_MECHATRONICS_error_base)+332)

/**
    No BOM Windows are associated to the specified AllocationWindow.
*/
#define ALLOC_window_no_bomwindows              ((EMH_MECHATRONICS_error_base)+333)

/**
    Failed to create AllocationLine, Internal error.
*/
#define ALLOC_window_error_creating_line        ((EMH_MECHATRONICS_error_base)+334)

/**
    The specified target bom line for Allocation line is from the same bom window of source bom line.
*/
#define ALLOC_window_target_in_source_bv        ((EMH_MECHATRONICS_error_base)+335)

/**
    The specified source bom line for Allocation line is from the same bom window of target bom line.
*/
#define ALLOC_window_source_in_target_bv        ((EMH_MECHATRONICS_error_base)+336)

/**
    Invalid Allocation line does not represent a valid Allocation object.
*/
#define ALLOC_line_no_allocation                ((EMH_MECHATRONICS_error_base)+337)

/**
    Invalid Allocation Window specified by the Allocation line.
*/
#define ALLOC_line_invalid_window               ((EMH_MECHATRONICS_error_base)+338)

/**
    Invalid Allocation line specified as input.
*/
#define ALLOC_line_invalid_line                 ((EMH_MECHATRONICS_error_base)+339)

/**
    Invalid Allocation map revision is specified for the current Allocation.
*/
#define ALLOC_not_in_map_rev                    ((EMH_MECHATRONICS_error_base)+340)

/**
    Cannot modify the specified Allocation map revision.
*/
#define ALLOC_cant_modify_maprev                ((EMH_MECHATRONICS_error_base)+341)

/**
    Allocation map revision needs to be refreshed.
*/
#define ALLOC_maprev_need_refresh               ((EMH_MECHATRONICS_error_base)+342)
/**
    Allocation map revision is not locked for modification.
*/
#define ALLOC_map_rev_not_locked                ((EMH_MECHATRONICS_error_base)+343)

/**
    Allocation object is referenced by ices.
*/
#define ALLOC_ices_on_allocation                ((EMH_MECHATRONICS_error_base)+344)

/**
    Fail to delete %1$ object: it is referenced by Route object.
*/
#define ROUTE_referenced_by_route                ((EMH_MECHATRONICS_error_base)+345)

/**
    Fail to delete %1$ object: it is referenced by Segment object.
*/
#define ROUTE_referenced_by_segment                ((EMH_MECHATRONICS_error_base)+346)

/**
    The deletion of object %1$ failed because deletion of replica Allocation objects is not allowed.
*/
#define ALLOC_cannot_delete_replica_allocation     ((EMH_MECHATRONICS_error_base)+347)


/***********************
 * ESM Error Messsages *
 ***********************/

/**
    Top line of the structure cannot be the primary or secondary line for creating relation.
*/
#define ESM_is_topline     ((EMH_MECHATRONICS_error_base)+400)

/**
    Given tag is not a valid Processor BOM Line.
*/
#define ESM_invalid_processor_line     ((EMH_MECHATRONICS_error_base)+401)

/**
    Given tag is not a valid Software BOM Line.
*/
#define ESM_invalid_software_line     ((EMH_MECHATRONICS_error_base)+402)

/**
    Failed to associate Processor with software with embeds relation.
*/
#define ESM_embeds_create_failure     ((EMH_MECHATRONICS_error_base)+403)

/**
    Given tag is not a valid gateway processor BOM Line.
*/
#define ESM_invalid_gateway_processor_line     ((EMH_MECHATRONICS_error_base)+404)

/**
    Failed to associate gateway processor with processors using GatewayOf relation.
*/
#define ESM_GatewayOf_create_failure      ((EMH_MECHATRONICS_error_base)+405)

/**
    Failed to associate software lines with Dependent On relation.
*/
#define ESM_DependsOn_create_failure      ((EMH_MECHATRONICS_error_base)+406)

/**
    Failed to remove embeds association of processor with software.
*/
#define ESM_embeds_remove_failure      ((EMH_MECHATRONICS_error_base)+407)

/**
    Failed to remove association of gateway processor with processors using GatewayOf relation.
*/
#define ESM_GatewayOf_remove_failure      ((EMH_MECHATRONICS_error_base)+408)

/** @deprecated #SIG_invalid_frameorsignal deprecated in Teamcenter 11.1. */
#define SIG_invalid_frameorsignal      ((EMH_MECHATRONICS_error_base)+409)
TC_DEPRECATED_PREPROCESSOR( "11.1", SIG_invalid_frameorsignal, "" )

/** @deprecated #SIG_invalid_target deprecated in Teamcenter 11.1. */
#define SIG_invalid_target      ((EMH_MECHATRONICS_error_base)+410)
TC_DEPRECATED_PREPROCESSOR( "11.1", SIG_invalid_target, "" )

/** @deprecated #SIG_invalid_source deprecated in Teamcenter 11.1. */
#define SIG_invalid_source      ((EMH_MECHATRONICS_error_base)+411)
TC_DEPRECATED_PREPROCESSOR( "11.1", SIG_invalid_source, "" )

/**
    The selected Software is not a sibling of the Processor's ancestor.
*/
#define ESM_invalid_ancestors     ((EMH_MECHATRONICS_error_base)+412)

/**
    The selected processor already has a gateway processor.
*/
#define ESM_already_have_gateway_processor  ((EMH_MECHATRONICS_error_base)+413)

/**
    Create Relations failed for the following lines - %1$.
*/
#define MECH_some_relations_set_failed  ((EMH_MECHATRONICS_error_base)+414)

/**
    The software line not embedded in any Processor.
*/
#define ESM_software_not_embedded_in_processor      ((EMH_MECHATRONICS_error_base)+415)

/**
    The secondary software line is not dependent on any software.
*/
#define ESM_secsoftline_not_dependenton_software      ((EMH_MECHATRONICS_error_base)+416)

/**
    The processor line does not have Gateway processors.
*/
#define ESM_Processor_has_no_gatway_processor      ((EMH_MECHATRONICS_error_base)+417)

/**
    The gateway processor has no processor lines accessing it.
*/
#define ESM_invalid_gatewayof_relation      ((EMH_MECHATRONICS_error_base)+418)

/**
    The embeds relation is invalid.
*/
#define ESM_invalid_embeds_relation      ((EMH_MECHATRONICS_error_base)+419)

/**
    The dependent on relation is invalid.
*/
#define ESM_invalid_dependent_relation      ((EMH_MECHATRONICS_error_base)+420)

/**
    Preference ESM_PROCESSOR_TYPE is not set.
*/
#define ESM_processor_type_pref_not_set      ((EMH_MECHATRONICS_error_base)+421)

/**
    Preference ESM_GATEWAY_PROCESSOR_TYPE is not set.
*/
#define ESM_gateway_processor_type_pref_not_set      ((EMH_MECHATRONICS_error_base)+422)

/**
    Remove Relations failed for the following lines - %1$.
*/
#define MECH_some_relations_unset_failed      ((EMH_MECHATRONICS_error_base)+423)

/**
    Multiple BOM Lines found for same absolute occurrence which is secondary in Embeds relation.
*/
#define ESM_invalid_multiple_bomlines_for_secondary_in_embeds_relation      ((EMH_MECHATRONICS_error_base)+424)

/**
    Multiple BOMLines found for same absolute occurrence which is secondary in DependentOn relation.
*/
#define ESM_invalid_multiple_bomlines_for_secondary_in_dependenton_relation      ((EMH_MECHATRONICS_error_base)+425)

/**
    Multiple BOM Lines found for same absolute occurence which is secondary in GatewayOf relation.
*/
#define ESM_invalid_multiple_bomlines_for_secondary_in_gatewayof_relation      ((EMH_MECHATRONICS_error_base)+426)

/**
    Software Type Preferences are not set correctly.
*/
#define ESM_software_type_pref_not_set      ((EMH_MECHATRONICS_error_base)+427)

/**
    Warning. No compatible hardware items exist for the given software item.
*/

#define ESM_no_hardware_related_to_software ((EMH_MECHATRONICS_error_base)+428)

/**
    Warning. No compatible sofware items exist for the given hardware item.
*/

#define ESM_no_software_related_to_hardware ((EMH_MECHATRONICS_error_base)+429)

/**
    No transfermodes found for Reports Creation.
*/

#define ESM_no_trfmodes_found_for_report ((EMH_MECHATRONICS_error_base)+430)

/**
    No style sheet found for Reports Creation.
*/

#define ESM_no_xslt_found_for_report ((EMH_MECHATRONICS_error_base)+431)

/**
    Failed to Check-Out Embedded Software Manager License.
*/
#define ESM_failed_to_checkout_license       ((EMH_MECHATRONICS_error_base)+432)

/**
    Gateway already exists for %1$ in context of %2$.
*/
#define ESM_gateway_already_exists_in_context       ((EMH_MECHATRONICS_error_base)+433)

/**
    Failed to Check-Out Embedded Software Manager License.
*/
#define ESM_license_feature_not_available       ((EMH_MECHATRONICS_error_base)+434)

/**
    Invalid input. Primary and secondary input lines cannot be the same for this association.
*/
#define MECH_same_pri_secondary_in_relation     ((EMH_MECHATRONICS_error_base)+435)

/**
    Configuration for Processor attribute - %1$ is missing.
*/
#define ESM_proc_prop_config_not_set     ((EMH_MECHATRONICS_error_base)+436)

/**
    Multiple BOM Lines found for same absolute occurrence which is primary in Embeds relation.
*/
#define ESM_invalid_multiple_bomlines_for_primary_in_embeds_relation      ((EMH_MECHATRONICS_error_base)+437)

/**
    Multiple BOMLines found for same absolute occurrence which is primary in DependentOn relation.
*/
#define ESM_invalid_multiple_bomlines_for_primary_in_dependenton_relation      ((EMH_MECHATRONICS_error_base)+438)

/**
    Multiple BOM Lines found for same absolute occurence which is primary in GatewayOf relation.
*/
#define ESM_invalid_multiple_bomlines_for_primary_in_gatewayof_relation      ((EMH_MECHATRONICS_error_base)+439)

/**
    Object %1$ was found in %2$ relation but is invalid as it is not a %3$.
*/
#define ESM_invalid_relation           ((EMH_MECHATRONICS_error_base)+440)

/**
    Selected processor is not a direct child of hardware.
If processor is more than one level below hardware, change the preference value ESM_Processor_direct_child_of_hardware to "false".
*/
#define ESM_proc_is_not_direct_child_of_hw           ((EMH_MECHATRONICS_error_base)+441)

/**
    %1$ of type %2$ cannot be replaced by %3$ of type %4$. Type %5$ is not allowed as it is not %6$ or its subtype.
*/
#define MECH_type_mismatch_for_replace           ((EMH_MECHATRONICS_error_base)+442)

/**
    Cannot replace an Item Element whose parent or grandparent is a Variant Item.
*/
#define MECH_cannot_replace_gde_in_vi            ((EMH_MECHATRONICS_error_base)+443)

/**
    In-Context replacement of Item Elements is not supported.
*/
#define MECH_cannot_replace_gde_in_context       ((EMH_MECHATRONICS_error_base)+444)

/**
    Failed to Replace Item Element-Item Element not replaceable.
*/
#define MECH_cannot_replace_gde                  ((EMH_MECHATRONICS_error_base)+445)

/**
    Invalid Clearcase server name specified. Check value of "%1$" preference.
*/
#define MECH_SCMCC_invalid_server                ((EMH_MECHATRONICS_error_base)+446)

/**
    Clearcase element to be associated with Teamcenter object not specified.
*/
#define MECH_SCMCC_element_not_specified            ((EMH_MECHATRONICS_error_base)+447)

/**
    Failed to Check-Out Wire Harness application license.
*/
#define WH_failed_to_checkout_license            ((EMH_MECHATRONICS_error_base)+448)

/**
    The BOM View %1$ is not Checked-Out. You don't have sufficient privileges to create or delete any relation.
*/
#define  MECH_cant_modify_bv                     ((EMH_MECHATRONICS_error_base)+449)

/**
    The BOM View Revision %1$ is not Checked-Out. You don't have sufficient privileges to create or delete any relation.
*/
#define  MECH_cant_modify_bvr                    ((EMH_MECHATRONICS_error_base)+450)

/**
    The BOM View %1$ and BOM View Revision %2$ are not Checked-Out. You don't have sufficient privileges to create or delete any relation.
*/
#define  MECH_cant_modify_bv_bvr                     ((EMH_MECHATRONICS_error_base)+451)

/**
* 009712
*/

/**
    At least one of selected BOM lines is marked for removal. The association cannot be created.
*/
#define MECH_bomline_remove_mode            ((EMH_MECHATRONICS_error_base)+452)

/**
    A Split Occurrence is not allowed for the selected BOM line.
*/
#define MECH_bomline_split_not_allowed        ((EMH_MECHATRONICS_error_base)+453)

/**
    The quantity should be an integer to support split on GDE Line.
*/
#define MECH_gdeline_split_not_allowed        ((EMH_MECHATRONICS_error_base)+454)

/**
    The context for the relation is changed.
*/
#define MECH_context_changed        ((EMH_MECHATRONICS_error_base)+455)

/**
    The association of the Processor With Software with embeds relations has failed, because the hardware line is marked for removal.
*/
#define MECH_hardwareline_remove_mode        ((EMH_MECHATRONICS_error_base)+456)

/**
    A Wire Harness user needs a Teamcenter author license.
*/
#define WH_user_needs_author_license            ((EMH_MECHATRONICS_error_base)+457)

/**
    A Wire Harness user needs a Teamcenter consumer license.
*/
#define WH_user_needs_consumer_license            ((EMH_MECHATRONICS_error_base)+458)

/**
    The password file path to invoke Capital webservice is empty.
*/
#define WH_pwd_filepath_empty                                ((EMH_MECHATRONICS_error_base)+459)

/**
    The url to invoke Capital webservice is empty.
*/
#define WH_webservice_url_empty                             ((EMH_MECHATRONICS_error_base)+460)

/**
    The password file \"%s\" failed to open, or password is empty.
*/
#define WH_tc_capital_get_password_failed                   ((EMH_MECHATRONICS_error_base)+461)

/**
    The Capital release status is empty.
*/
#define WH_tc_capital_empty_release_status                  ((EMH_MECHATRONICS_error_base)+462)

/**
    The SSL certificate file (.pem) for Capital webservice is empty.
*/
#define WH_webservice_certFile_empty                        ((EMH_MECHATRONICS_error_base)+463)

/**
    The Capital rejected status is empty.
*/
#define WH_tc_capital_empty_rejected_status                 ((EMH_MECHATRONICS_error_base)+464)

/**
    Failed to find the associated Capital Design(s) for the Teamcenter object %1$.
*/
#define WH_tc_capital_find_design_failed                    ((EMH_MECHATRONICS_error_base)+465)

/**
    No Capital Design(s) were found for the Teamcenter object %1$.
*/
#define WH_tc_capital_find_design_result_empty              ((EMH_MECHATRONICS_error_base)+466)

/**
    The release status update of one or more Capital Designs failed.
*/
#define WH_tc_capital_apply_release_status_failed           ((EMH_MECHATRONICS_error_base)+467)

/**
    The reject status update of one or more Capital Designs failed.
*/
#define WH_tc_capital_apply_reject_status_failed            ((EMH_MECHATRONICS_error_base)+468)

/**
    No response was recieved from the release design Capital webservice.
*/
#define WH_tc_capital_release_design_result_empty           ((EMH_MECHATRONICS_error_base)+469)

/**
    The user name to invoke Capital webservice is empty.
*/
#define WH_capital_user_empty                               ((EMH_MECHATRONICS_error_base)+470)

/**
    Failed to connect to the Capital Webservice. Please provide correct connection credentials.
*/
#define WH_webservice_connection_failure                    ((EMH_MECHATRONICS_error_base)+471)

/**
    Failed to authenticate user to the Capital Webservice. Please provide correct login credentials.
*/
#define WH_capital_authentication_failure                   ((EMH_MECHATRONICS_error_base)+472)

/**
    Revise of one or more Capital Designs failed.
*/
#define WH_tc_capital_revise_failed                         ((EMH_MECHATRONICS_error_base)+473)

/**
    No Capital Design(s) were found for the Teamcenter object %1$. Please associate source Teamcenter revision to a Capital Design before initiating revise Workflow.
*/
#define WH_tc_capital_find_design_result_empty_associate    ((EMH_MECHATRONICS_error_base)+474)

/** @} */

#include <mechatronics/libmechatronics_undef.h>
#endif

