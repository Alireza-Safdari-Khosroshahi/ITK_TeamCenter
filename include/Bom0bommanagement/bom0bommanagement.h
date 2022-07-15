/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2016.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
@file

Contains declarations of APIs for the 4G Product Master module.
*/

#ifndef BOM0_BOMMANAGEMENT_H
#define BOM0_BOMMANAGEMENT_H

#include <unidefs.h>

#include <Bom0bommanagement/libbom0bommanagement_exports.h>

/**
@defgroup BOMMGMT 4th Generation Product Master(4GPM)
<br/>4G Product Master is the next generation BOM application which provides formal BOM management capabilities in Teamcenter.
<br/>It supports features like release of a formal bill of materials by Engineering, Engineering solve requests including order solves and forecast order solves.
<br/>This group provides ITKs for part structure management and CAD BOM Alignment.
@{
*/

#ifdef __cplusplus
extern "C"
{
#endif

    /**
    Contains Design Line (ImanItemLine) and configuration context information. This is used in #BOM0_get_aligned_part_occurrences.
    */
    typedef struct BOM0_design_line_input_s
    {
        tag_t design_line;               /**< The Design Line (ImanItemLine)*/
        tag_t configuration_context;     /**< The Configuration Context object.*/
    } BOM0_design_line_input_t;

    /**
    An array of aligned Part Breakdown Element Lines (Bom0PBELine) for Design Line (ImanItemLine). This is used in #BOM0_get_aligned_part_occurrences.
    <br/> If there are no @p pbe_lines, @p n_pbe_lines will be 0.
    */
    typedef struct BOM0_aligned_pbe_lines_s
    {
        tag_t design_line;        /**< The Design Line (ImanItemLine) for which @p pbe_lines is retrieved.*/
        unsigned int n_pbe_lines; /**< Number of objects in @p pbe_lines*/
        tag_t* pbe_lines;         /**< n_pbe_lines List of Part Breakdown Element Line (Bom0PBELine)*/
    } BOM0_aligned_pbe_lines_t;

    /**
    Structure of the Part Breakdown Element Line (Bom0PBELine) to align with the given Design Line (ImanItemLine).
    */
    typedef struct BOM0_pbe_line_algnmt_input_s
    {
        tag_t pbe_line;                  /**< The PBE Line (Bom0PBELine).*/
        tag_t iman_item_line;            /**< The Design Line (ImanItemLine).*/
    } BOM0_pbe_line_algnmt_input_t;

    /**
    Structure of the Part Breakdown Element Line (Bom0PBELine) and respective alignment object (Bom0AbstractPBEAlignment).
    */
    typedef struct BOM0_pbe_line_algnmt_output_s
    {
        tag_t pbe_line;                  /**< The PBE Line (Bom0PBELine).*/
        tag_t alignment;                 /**< The Alignment instance(Bom0AbstractPBEAlignment).*/
    } BOM0_pbe_line_algnmt_output_t;

    /**
    Structure of the Part Breakdown Element Line (Bom0PBELine) and intent to unalign the child Part Breakdown Element Lines.
    */
    typedef struct BOM0_pbe_line_unalgnmt_input_s
    {
        tag_t pbe_line;                  /**< The PBE Line (Bom0PBELine).*/
        logical unalign_child_pbe_lines; /**< If true, the operation unaligns all the child PBE Lines of the input PBE Line. If false, only the input PBE Line is unaligned.*/
    } BOM0_pbe_line_unalgnmt_input_t;

    /**
    Structure of Designs (ItemRevision) to align on a given Part (Bom0AbstractPart). It also contains the Primary Design (ItemRevision) to mark on the Part.
    */
    typedef struct BOM0_part_design_algnmt_input_s
    {
        tag_t part;                     /**< The Part (Bom0AbstractPart).*/
        unsigned int num_designs;       /**< Number of Designs to align.*/
        tag_t* designs;                 /**< num_designs List of Designs (ItemRevision).*/
        tag_t primary_design;           /**< The Primary Design (ItemRevision) to mark on @p part.*/
    } BOM0_part_design_algnmt_input_t;

    /**
    Structure of Designs (ItemRevision) to unalign on the Part (Bom0AbstractPart).
    */
    typedef struct BOM0_part_design_unalgnmt_input_s
    {
        tag_t part;                     /**< The Part (Bom0AbstractPart).*/
        unsigned int num_designs;       /**< Number of Designs to unalign.*/
        tag_t* designs;                 /**< num_designs List of Designs (ItemRevision).*/
    } BOM0_part_design_unalgnmt_input_t;

    /**
    Structure of Part (Bom0AbstractPart) and the Primary Design (ItemRevision) to mark on the Part.
    */
    typedef struct BOM0_mark_primary_design_input_s
    {
        tag_t part;                     /**< The Part (Bom0AbstractPart).*/
        tag_t primary_design;           /**< The Primary Design (ItemRevision) to mark on @p part.*/
    } BOM0_mark_primary_design_input_t;

    /**
    Structure of Design Components (Cpd0DesignElements) to unalign on Part Usage (Bom0AbstractPartUsage).
    */
    typedef struct BOM0_part_usage_alignment_info_s
    {
        tag_t part_usage;                                      /**< Part Usage (Bom0AbstractPartUsage)*/
        unsigned int n_design_elements;                        /**< Number of Design Components to unalign */
        tag_t *design_elements;                                /**< n_design_elements List of Design Components (Cpd0DesignElement) */
    } BOM0_part_usage_alignment_info_t;

    /**
    Structure of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) linked to a Design Component (Cpd0DesignElement).
    <br/> If @p design_component has no aligned Part Usages, @p n_composite_alignment_objects is to be 0.
    */
    typedef struct BOM0_alignment_info_of_design_component_s
    {
        tag_t design_component;                         /**< The Design Component (Cpd0DesignElement).*/
        unsigned int n_composite_alignment_objects;     /**< Number of Composite Part Usage Alignment objects*/
        tag_t* composite_alignment_objects;             /**< n_composite_alignment_objects List of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment)*/
    } BOM0_alignment_info_of_design_component_t;

    /**
    Structure of Composite Part Breakdown Element Substitutes (Bom0CompositePBEsubstitutes) linked to a Part Breakdown Element (Bom0AbstractPartBrkdownElem).
    <br/> If @p part_breakdown_element has no substitutes, @p n_part_breakdown_element_substitutes will be equal to 0.
    */
    typedef struct BOM0_substitute_info_for_part_breakdown_element_s
    {
        tag_t part_breakdown_element;                          /**< The Part Breakdown Element (Bom0AbstractPartBrkdownElem).*/
        unsigned int n_part_breakdown_element_substitutes;     /**< Number of Part Breakdown Element Substitutes. */
        tag_t* composite_part_breakdown_element_substitutes;   /**< n_part_breakdown_element_substitutes List of Composite Part Breakdown Element Substitutes (Bom0CompositePBEsubstitutes). */
    } BOM0_substitute_info_for_part_breakdown_element_t;


    /**
    Retrieves the part structure window associated with a @p part (Bom0AbstractPart), by looking through its complete breakdown.
    <br>The Part Breakdown Element Lines ( Bom0PBELine ) are created in pack or unpacked mode as per @p pack_lines value.
    <br>In packed mode, alignment information will not be populated on Part Breakdown Element Lines even if @p include_aligned_design_info is true.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p part is #NULLTAG or not type or subtype of Bom0AbstractPart.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_part_structure_with_pack_option(
        const tag_t part,                           /**< (I) The Part.*/
        const tag_t configuration_context,          /**< (I) The Configuration Context object.*/
        const logical include_aligned_design_info,  /**< (I) Indicates whether aligned design information should be populated with part structure or not.
                                                             <br/>The alignment information is derived from occurrence alignment of part structure.*/
        const logical pack_lines,                   /**< (I) Indicates whether Part Breakdown Element Line ( Bom0PBELine ) should be packed or unpacked.*/
        tag_t* part_structure_window                /**< (O) Part structure window associated with the @p part.*/
        );

    /**
    Retrieves Part Usage Substitutes (bom0CompositePUSubstitutes) for  @p part_usage (Bom0AbstractPartUsage).
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p part_usage is #NULLTAG or is not type or subtype of Bom0AbstractPartUsage.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_part_usage_substitutes(
        const tag_t part_usage,                             /**< (I) The Part Usage.*/
        const tag_t configuration_context,                  /**< (I) The Configuration Context object.*/
        unsigned int *n_part_usage_substitutes ,            /**< (O) The number of found Part Usage Substitutes */
        tag_t** composite_part_usage_substitutes            /**< (OF) n_part_usage_substitutes The found Part Usage Substitutes */
        );

    /**
    Retrieves all the occurrences for a given @p part_breakdown_element (Bom0AbstractPartBrkdownElem).
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p part_breakdown_element is #NULLTAG, or not type or subtype of Bom0AbstractPartBrkdownElem.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_part_occurrences(
        const tag_t part_breakdown_element,         /**< (I)  The Part Breakdown Element(Bom0AbstractPartBrkdownElem).*/
        unsigned int* n_occurrences,                /**< (O)  Number of occurrences found.*/
        tag_t** occurrences                         /**< (OF) n_occurrences The list of occurrences (Bom0PartOccurrence).*/
        );

    /**
    Retrieves the alignment object for a given Part Breakdown Element Line ( Bom0PBELine ).
    <br/>Alignment information is retrieved for unpacked @p pbe_line.
    <br/>The configuration context from part structure window will be applied on the alignment object.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p pbe_line is #NULLTAG, or not type or subtype of Bom0PBELine.
    <li>#BOM0BOMMANAGEMENT_packed_line_not_supported if @p pbe_line (or its ancestors) is packed.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_pbe_alignment(
        const tag_t pbe_line,                       /**< (I) Part Breakdown Element(PBE) Line( Bom0PBELine ).*/
        tag_t* alignment                            /**< (O) Alignment instance( Bom0AbstractPBEAlignment ).*/
        );

    /**
    Retrieves the list of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) for a given Part Usage (Bom0AbstractPartUsage) configured with a given context.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p part_usage is #NULLTAG or is not type or subtype of Bom0AbstractPartUsage.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_alignment_info_for_part_usage(
        const tag_t part_usage,                           /**< (I) The Part Usage.*/
        const tag_t configuration_context,                /**< (I) The Configuration Context object used to configure the output alignment objects.*/
        unsigned int* n_alignment_info,                   /**< (O) Number of aligned information found.*/
        tag_t** alignment_info                            /**< (OF) n_alignment_info The Alignment objects found.*/
        );

    /**
    Aligns the occurrence path of a Part Breakdown Element (PBE) Line (type Bom0PBELine) to absolute occurrence of an Iman Item Line (type ImanItemLine).
    <br/>To align Part Breakdown Element Lines in bulk, use #BOM0_align_pbe_lines.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p pbe_line is #NULLTAG, or not type or subtype of Bom0PBELine.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p iman_item_line is #NULLTAG, or not type or subtype of ImanItemLine.
    <li>#BOM0BOMMANAGEMENT_part_structure_already_aligned if the occurrence path of @p pbe_line is already aligned to the absolute occurrence of an ImanItemLine other than @p iman_item_line.
    <li>#BOM0BOMMANAGEMENT_packed_line_not_supported if @p pbe_line (or its ancestors) or @p iman_item_line (or its ancestors) is packed.
    <li>#BOM0BOMMANAGEMENT_top_line_for_alignment if @p pbe_line is top line of part structure or @p iman_item_line is top line of design structure
    </ul>
    @note If the occurrence path of @p pbe_line is already aligned to the absolute occurrence of the Iman Item Line @p iman_item_line, #ITK_ok is returned, and the existing alignment instance is retrieved.
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_align_pbe_line(
        const tag_t pbe_line,                       /**< (I) The PBE Line.*/
        const tag_t iman_item_line,                 /**< (I) The Iman Item Line.*/
        tag_t* alignment                            /**< (O) The alignment instance (type Bom0PBEAlignment).*/
        );

    /**
    Unaligns the occurrence path of a Part Breakdown Element (PBE) Line (type Bom0PBELine) from the absolute occurrence of an Iman Item Line.
    <br/>To unalign Part Breakdown Element Lines in bulk, use #BOM0_unalign_pbe_lines.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p pbe_line is #NULLTAG, or not type or subtype of Bom0PBELine.
    <li>#BOM0BOMMANAGEMENT_packed_line_not_supported if @p pbe_line (or its ancestors) is packed.
    </ul>
    @note If the occurrence path of a Part Breakdown Element (PBE) Line is not aligned to any absolute occurrence of an Iman Item Line, #ITK_ok is returned.
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_unalign_pbe_line(
        const tag_t pbe_line                       /**< (I) The PBE Line.*/
        );

    /**
    Retrieves the list of Composite Part Usage Alignments objects (Bom0CompositePartUsageAlignment) for a given Design Component (Cpd0DesignElement) configured with a given context.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p design_element is #NULLTAG or is not type or subtype of Cpd0DesignElement.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_alignment_info_for_design_element(
        const tag_t design_element,                       /**< (I) Design Component ( Cpd0DesignElement ).*/
        const tag_t configuration_context,                /**< (I) The Configuration Context object used to configure the output alignment objects.*/
        unsigned int* n_alignment_info,                   /**< (O) Number of aligned information found.*/
        tag_t** alignment_info                            /**< (OF) n_alignment_info The Alignment objects found.*/
        );

    /**
    Defines different options available to perform search for the given part.
    */
    typedef enum BOM0_part_where_used_options_e {
        alternate_part,                         /**< Part used as Alternate <br/> The retrieved objects would be of type Bom0AbstractPart*/
        part_usage_substitute,                  /**< Part used as Part Usage Substitute <br/> The retrieved objects would be of type Bom0AbstractPartUsage*/
        part_usage,                             /**< Part Usages referencing the given Part <br/> The retrieved objects would be of type Bom0AbstractPartUsage*/
        top_level_part_breakdown_elem,          /**< Top Level Part Breakdown Elements (PBE) of a Part structure containing given Part
                                                     where Part structure is not a sub-assembly <br/> The retrieved objects would be of type Bom0AbstractPartBrkdownElem*/
        part_breakdown_elem,                    /**< Part used as Child Part in Part Breakdown Elements (PBE) <br/> The retrieved objects would be of type Bom0AbstractPartBrkdownElem*/
        all_part_usages                         /**< Part usages referencing the Parts that contains given Part in their structure <br/> The retrieved objects would be of type Bom0AbstractPartUsage*/
    } BOM0_part_where_used_options_t;

    /**
    An array of objects using the part (Bom0AbstractPart). This is used in #BOM0_get_part_where_used.
    <br/> If there are no objects, @p n_objects will be 0.
    */
    typedef struct BOM0_part_where_used_objects
    {
        unsigned int n_objects; /**< Number of objects in @p objects*/
        tag_t* objects;         /**< n_objects List of objects*/
    } BOM0_part_where_used_objects_t;

    /**
    Searches where the @p part (Bom0AbstractPart) is used as per the provided options @p requested_options.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if the @p part is #NULLTAG, or not type or subtype of Bom0AbstractPart.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    <li>#BOM0BOMMANAGEMENT_invalid_part_where_used_option if any entry in @p requested_options is invalid.
    </ul>

    @note If search is to be performed for all options, @p requested_options should be NULL and @p n_requested_options should be 0.
    <br/>In this case, the order of results is same as #BOM0_part_where_used_options_t and its size is 6.
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_part_where_used(
        const tag_t                             part,                      /**< (I) The input Part on which "Where Used" is to be performed.*/
        const tag_t                             configuration_context,     /**< (I) The configuration context used to configure the results.*/
        const unsigned int                      n_requested_options,       /**< (I) Number of options in @p requested_options.*/
        const BOM0_part_where_used_options_t    *requested_options,        /**< (I) n_requested_options List of options to restrict how the search is performed.*/
        BOM0_part_where_used_objects_t          **results_for_each_option  /**< (OF) n_requested_options Array representing results for each input option requested.
                                                                                     <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        );

    /**
    Retrieves the list of aligned Part Occurrences (Bom0PBELine) for given Design Lines (ImanItemLine).
    <br/><br/>The part structure window associated with the found Part Occurrences (Bom0PBELine) needs to be closed as appropriate.
    <br/>Example
    @code
        // Create input
        ...

        scoped_smptr< BOM0_aligned_pbe_lines_t > aligned_pbe_lines;
        ResultStatus status = BOM0_get_aligned_part_occurrences( n_design_lines, design_lines, &aligned_pbe_lines );
        // Usage of output
        ...

        // Extract the corresponding part structure window from aligned_pbe_lines and close the window.
        // Here window for first aligned pbe line found for the first design line is fetched and closed.
        tag_t window = NULLTAG;
        status = BOM_line_ask_window( aligned_pbe_lines[0].pbe_lines[0], &window );
        status = BOM_close_window( window );

        // Here we are using scoped_smptr thus memory will be dellocated once pointer goes out of scope.
        // If scoped_smptr is not used, call MEM_free on the retrieved container aligned_pbe_lines.
    @endcode

    @note If the found PBE Lines belongs to more than one structure, more than one windows will be created in the ITK.
    In such case, extract windows for all the PBE Lines and close all the windows.

    @see BOM_line_ask_window
    <br/>BOM_close_window

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any member of @p design_lines is #NULLTAG or not type or subtype of ImanItemLine.
    <li>#BOM0BOMMANAGEMENT_packed_line_not_supported if any of design line in @p design_lines (or its ancestors) is packed.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context in @p design_lines is #NULLTAG, or not type or subtype of ConfigurationContext.
    </ul>

    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_aligned_part_occurrences(
        const unsigned int n_design_lines,                        /**< (I) Number of Design Lines.*/
        const BOM0_design_line_input_t* design_lines,             /**< (I) n_design_lines Design Lines (ImanItemLine) and configuration context to be used for finding Part Breakdown Element Lines.*/
        BOM0_aligned_pbe_lines_t** aligned_pbe_lines              /**< (OF) n_design_lines The Part Breakdown Element Lines( Bom0PBELine ) retrieved for each input Design Line.
                                                                  <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        );

    /**
    Creates an alignment for each input structure between its Part (Bom0AbstractPart) and the list of Designs (ItemRevision).
    <br/>POM_object objects cannot be aligned.
    <br/>For each input structure, its primary Design will be marked as the primary Design of the provided Part.
    <br/>For each input structure, if the given primary Design is not in the list of Designs to align and also it is not already aligned with the Part, it will be aligned with the Part and marked as a primary Design on the Part.
    <br/>If none of the aligned Design exists as a primary Design and no primary Design is given as input, the first Design to be aligned will be marked as the primary Design.

    @note If the alignment creation fails between the Part and any Designs, the complete transaction for all the input structures is rolled back and no Design is aligned.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any of the Part or if any of the Designs in @p alignments is #NULLTAG.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the Part or if any of the Designs in @p alignments is not of type or subtype of Bom0AbstractPart or ItemRevision respectively.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the primary Design in @p alignments is not of type or subtype of ItemRevision.
    <li>#BOM0BOMMANAGEMENT_already_related if any of the Part and any of the Designs in @p alignments are already aligned.
    <li>#BOM0BOMMANAGEMENT_no_input_specified if @p alignments is NULL or @p n_alignments is 0.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_align_part_and_designs(
        const unsigned int n_alignments,                            /**< (I) Number of Alignment inputs (BOM0_part_design_algnmt_input_t) for performing the alignment.*/
        const BOM0_part_design_algnmt_input_t* alignments           /**< (I) n_alignments Parts, Designs and primary Design to mark on the Part for performing the alignment.*/
        );

    /**
    Unaligns Parts (Bom0AbstractPart) and all of the Designs (ItemRevision) in @p unalignments.
    <br/>If the input Design is also primary Design for the given Part, it will be unset from the Part.

    @note If any error occurs while unaligning, the complete transaction for all the input structures is rolled back and no Design is unaligned.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any member of @p unalignments is #NULLTAG.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the Part or if any of the Designs in @p unalignments is not of type or subtype of Bom0AbstractPart or ItemRevision respectively.
    <li>#BOM0BOMMANAGEMENT_bom_design_not_aligned if any of the Part and any of the Designs in @p unalignments are not aligned.
    <li>#BOM0BOMMANAGEMENT_no_input_specified if @p unalignments is NULL or @p n_unalignments is 0.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_unalign_part_and_designs(
        const unsigned int n_unalignments,                          /**< (I) Number of Unalignment inputs (BOM0_part_design_unalgnmt_input_t) for performing the unalignment.*/
        const BOM0_part_design_unalgnmt_input_t* unalignments       /**< (I) n_unalignments Parts and list of Designs for performing the unalignment.*/
        );

    /**
    Marks a Design (ItemRevision) as the primary Design on the Part (Bom0AbstractPart) in @p mark_primary_designs.
    <br/>The Design cannot be marked as the primary Design if there is no prior aligned relation between the Part (Bom0AbstractPart) and the Design (ItemRevision).

    @note If any error occurs while performing mark primary Design on the Part, the complete transaction for all the input structures is rolled back and no primary Design is marked on the Part.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any member of @p mark_primary_designs is #NULLTAG.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the Part or if any of the Design in @p mark_primary_designs is not of type or subtype of Bom0AbstractPart or ItemRevision respectively.
    <li>#BOM0BOMMANAGEMENT_bom_design_not_aligned if any of the Part and any of the Design in @p mark_primary_designs are not aligned.
    <li>#BOM0BOMMANAGEMENT_no_input_specified if @p mark_primary_designs is NULL or @p n_mark_primary_designs is 0.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_mark_primary_design(
        const unsigned int n_mark_primary_designs,                          /**< (I) Number of Mark Primary Design inputs (BOM0_mark_primary_design_input_t) for performing mark primary design on the Part.*/
        const BOM0_mark_primary_design_input_t* mark_primary_designs        /**< (I) n_mark_primary_designs Part and Design for performing mark primary design on the Part.*/
        );

    /**
    Creates an alignment for each input structure between its occurrence path of Part Breakdown Element Line (Bom0PBELine) and the absolute occurrence of the Design Line (ImanItemLine).
    <br/>To align a single Part Breakdown Element Line, use #BOM0_align_pbe_line.

    @note If the alignment creation fails between the Part Breakdown Element Line and the Design Line, the complete transaction for all the input structures is rolled back and no Part Breakdown Line is aligned.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any of the Part Breakdown Element Line or if any of the Design Line in @p pbe_line_algnmt is #NULLTAG.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the Part Breakdown Element Line in @p pbe_line_algnmt is not of type or subtype of Bom0PBELine.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the Design Line in @p pbe_line_algnmt is not of type or subtype of ImanItemLine.
    <li>#BOM0BOMMANAGEMENT_part_structure_already_aligned if any of the Part Breakdown Element Line in @p pbe_line_algnmt is already aligned to the absolute occurrence of an ImanItemLine other than Design Line in @p pbe_line_algnmt_input.
    <li>#BOM0BOMMANAGEMENT_packed_line_not_supported if any of the Part Breakdown Element Line (or its ancestors) or the Design Line (or its ancestors) in @p pbe_line_algnmt is packed.
    <li>#BOM0BOMMANAGEMENT_top_line_for_alignment if any of the Part Breakdown Element Line in @p pbe_line_algnmt is the top line of part structure.
    <li>#BOM0BOMMANAGEMENT_top_line_for_alignment if any of the Design Line in @p pbe_line_algnmt is the top line of design structure.
    <li>#BOM0BOMMANAGEMENT_no_input_specified if @p pbe_line_algnmt is NULL or @p n_pbe_line_algnmt is 0.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_align_pbe_lines(
        const unsigned int n_pbe_line_algnmt,                 /**< (I) Number of PBE Line alignment inputs (BOM0_pbe_line_algnmt_input_t) for performing the alignment.*/
        const BOM0_pbe_line_algnmt_input_t *pbe_line_algnmt,  /**< (I) n_pbe_line_algnmt PBE Line (Bom0PBELine) and Design Line (ImanItemLine) for performing the alignment.*/
        BOM0_pbe_line_algnmt_output_t **aligned_pbe_line      /**< (OF) n_pbe_line_algnmt PBE Line (Bom0PBELine) and alignment object for each input PBE Line.*/
        );

    /**
    Unaligns the Part Breakdown Element Line in @p pbe_line_unalgnmt from the Design Line of design structure it is aligned.
    <br/>To unalign a single Part Breakdown Element Line, use #BOM0_unalign_pbe_line.

    @note If the unalignment fails for any of the Part Breakdown Element Line, the complete transaction for all the input structures is rolled back and no Part Breakdown Element Line is unaligned.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any of the Part Breakdown Element Line in @p pbe_line_unalgnmt is #NULLTAG.
    <li>#BOM0BOMMANAGEMENT_invalid_type_of_input if any of the Part Breakdown Element Line in @p pbe_line_unalgnmt is not of type or subtype of Bom0PBELine.
    <li>#BOM0BOMMANAGEMENT_packed_line_not_supported if any of the Part Breakdown Element Line (or its ancestors) in @p pbe_line_unalgnmt is packed.
    <li>#BOM0BOMMANAGEMENT_no_input_specified if @p pbe_line_unalgnmt is NULL or @p n_pbe_line_unalgnmt is 0.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_unalign_pbe_lines(
        const unsigned int n_pbe_line_unalgnmt,                    /**< (I) Number of PBE Line unalignment inputs (BOM0_pbe_line_unalgnmt_input_t) for performing the unalignment.*/
        const BOM0_pbe_line_unalgnmt_input_t *pbe_line_unalgnmt    /**< (I) n_pbe_line_unalgnmt PBE Line (Bom0PBELine) and intent to unalign child PBE Lines while performing the unalignment.*/
        );

    /**
    Unaligns the part usage (Bom0AbstractPartUsage) from given design elements (Cpd0DesignElements).
    @note If any error occurs while unaligning, the complete transaction is rolled back and no Design Component will be unaligned.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any of Part Usage or any Design Component in the structures is #NULLTAG or not a type or subtype of Bom0AbstractPartUsage or Cpd0DesignElement respectively.
    <li>#BOM0BOMMANAGEMENT_no_input_specified if @p part_usage_alignments is NULL or @p n_part_usage_alignments is 0.
    <li>#BOM0BOMMANAGEMENT_bom_design_not_aligned if any Design Component in a structure is not aligned to the provided Part Usage.
    </ul>
    */
    BOM0BOMMANAGEMENT_API int BOM0_unalign_part_usage_design_elements(
        const unsigned int n_part_usage_alignments,                                 /**< (I) Number of structures for unalignments. */
        const BOM0_part_usage_alignment_info_t *part_usage_alignments               /**< (I) n_part_usage_alignments The structures for unalignments.*/
        );

    /**
    List of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) linked to a Part Usage (Bom0AbstractPartUsage).
    This is used in #BOM0_get_alignment_info_for_part_usages.
    <br/> If there are no @p composite_alignment_objects, @p n_composite_alignment_objects will be 0.
    */
    typedef struct BOM0_alignment_info_of_part_usage_s
    {
        tag_t part_usage;                           /**< The Part Usage (Bom0AbstractPartUsage).*/
        unsigned int n_composite_alignment_objects; /**< Number of Composite Part Usage Alignment objects*/
        tag_t* composite_alignment_objects;         /**< n_composite_alignment_objects List of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment)*/
    } BOM0_alignment_info_of_part_usage_t;

    /**
    Retrieves the list of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) for given Part Usages (Bom0AbstractPartUsage) configured with a given context.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any member of @p part_usages is #NULLTAG or not type or subtype of Bom0AbstractPartUsage.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_alignment_info_for_part_usages(
        const unsigned int n_part_usages,                        /**< (I) Number of Part Usages.*/
        const tag_t* part_usages,                                /**< (I) n_part_usages Part Usages (Bom0AbstractPartUsage) whose alignments need to be retrieved.*/
        const tag_t configuration_context,                       /**< (I) The configuration context used to configure the results.*/
        BOM0_alignment_info_of_part_usage_t** alignments_info    /**< (OF) n_part_usages The Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) retrieved for each input Part Usage.
                                                                 <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        );


    /**
    Retrieves the list of Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) for given Design Components (Cpd0DesignElement) configured with a given context.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any member of @p design_components is #NULLTAG.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_alignment_info_for_design_components(
        const unsigned int n_design_components,                         /**< (I) Number of Design Components.*/
        const tag_t* design_components,                                 /**< (I) n_design_components Design Components (Cpd0DesignElement) whose alignments need to be retrieved.*/
        const tag_t configuration_context,                              /**< (I) The configuration context used to configure the results.*/
        BOM0_alignment_info_of_design_component_t** alignments_info     /**< (OF) n_design_components The Composite Part Usage Alignment objects (Bom0CompositePartUsageAlignment) retrieved for each input Design Components.
                                                                        <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        );

    /**
    Retrieves Part Breakdown Element Substitutes (Bom0CompositePBESubstitutes) for given Part Breakdown Elements (Bom0AbstractPartBrkdownElem) configured with a given context.
    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#COLLABCTX_invalid_ccobject if @p configuration_context is #NULLTAG, or not type or subtype of ConfigurationContext.
    <li>#BOM0BOMMANAGEMENT_invalid_input if any member of @p part_breakdown_elements is #NULLTAG or is not type or subtype of Bom0AbstractPartBrkdownElem.
    </ul>
    */
    extern BOM0BOMMANAGEMENT_API int BOM0_get_substitutes_for_part_breakdown_elements(
        const unsigned int n_part_breakdown_elements,                            /**< (I) Number of Part Breakdown Elements.*/
        const tag_t* part_breakdown_elements,                                    /**< (I) n_part_breakdown_elements The Part Breakdown Elements whose substitutes need to be retrieved.*/
        const tag_t configuration_context,                                       /**< (I) The Configuration Context object.*/
        BOM0_substitute_info_for_part_breakdown_element_s ** substitute_info     /**< (OF) n_part_breakdown_elements The Composite Part Breakdown Element Substitute objects (Bom0CompositePBESubstitutes) retrieved for each input Part Breakdown Element.
                                                                                 <br/>The array is packed, which means that the memory is to be deallocated by calling #MEM_free on the container only.*/
        );

#ifdef __cplusplus
}
#endif
/**
@}
*/

#include <Bom0bommanagement/libbom0bommanagement_undef.h>
#endif
