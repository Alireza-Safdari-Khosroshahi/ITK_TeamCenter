/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK API for Appearance, AppearanceRoot and associated mapped-attribute class(es).
*/

/*  */

#ifndef APPR_H
#define APPR_H

#include <unidefs.h>
#include <appr/libappr_exports.h>
#include <common/tc_deprecation_macros.h>

/**
    @defgroup APPR Appearances
    @{
*/

/**
    @name Appearance configuration modes

    Returned by APPR_root_ask_config_mode()
    @{
*/
#define APPR_cfg_mode_rel_date          0
#define APPR_cfg_mode_date_eff          1
#define APPR_cfg_mode_unit_eff          2
#define APPR_cfg_mode_unit_plus_rdate   3
#define APPR_cfg_mode_working_data      4
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @name Mapped attribute prefixes to allow more than just equality when searching
    @{
*/
extern APPR_API const char* APPR_get_APPR_attr_op_case_insensitive();
extern APPR_API const char* APPR_get_APPR_attr_op_like();
extern APPR_API const char* APPR_get_APPR_attr_op_not_like();
extern APPR_API const char* APPR_get_APPR_attr_op_null();
extern APPR_API const char* APPR_get_APPR_attr_op_not_null();
extern APPR_API const char* APPR_get_APPR_attr_op_ge();
extern APPR_API const char* APPR_get_APPR_attr_op_le();
extern APPR_API const char* APPR_get_APPR_attr_op_ne();
extern APPR_API const char* APPR_get_APPR_attr_op_eq();
extern APPR_API const char* APPR_get_APPR_attr_op_gt();
extern APPR_API const char* APPR_get_APPR_attr_op_lt();
/** @} */

/**
    @deprecated #APPR_root_create deprecated in Teamcenter 13.1.
    Creates an appearance root, setting its root_item, bom_view and revision_rule attributes to the given arguments.

    @note This function does not save the new appearance root. Use #AOM_save for that.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_create")
extern APPR_API int APPR_root_create(
    tag_t           root_item,          /**< (I) Root item of the structure to be tracked by this appearance root. */
    tag_t           bom_view,           /**< (I) Indicates the view of root_item to be tracked by this appearance root. */
    tag_t           revision_rule,      /**< (I) Revision that sets the configuration context for this appearance root. */
    logical         has_spatial_data,   /**< (I) If set to true spatial data will be tracked for this appearance root. */
    tag_t*          appr_root           /**< (O) Gives the tag of the newly created appearance root. */
    );

/**
    @deprecated #APPR_root_delete deprecated in Teamcenter 13.1.
    Destroy an AppearanceRoot and all associated data, including Appearances and update packages.
    Do not use lightly!

    @note If you merely want to destroy the AppearanceRoot alone, use #AOM_delete.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_delete")
extern APPR_API int APPR_root_delete(
    tag_t           appr_root         /**< (I) */
    );

/**
    @deprecated #APPR_root_extent deprecated in Teamcenter 13.1.
    Find all AppearanceRoots with attributes matching all the given arguments.
    If any argument is #NULLTAG, it is not matched against.
    So for example supplying all three as #NULLTAG finds *all* AppearanceRoots.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_extent")
extern APPR_API int APPR_root_extent(
    tag_t           root_item,        /**< (I) Search for appearance roots of the given root item. Ignored if #NULLTAG. */
    tag_t           bom_view,         /**< (I) Search for appearance roots of this bom view (of end item). Ignored if #NULLTAG */
    tag_t           revision_rule,    /**< (I) Search for appearance roots using this revision rule as
                                            their configuration context. Ignored if #NULLTAG. */
    int*            num_appr_roots,   /**< (O) The number of appearances roots matching the input search criteria. */
    tag_t**         appr_roots        /**< (OF) num_appr_roots Tags of the appearance roots matching the input search criteria. */
    );

/**
    @deprecated #APPR_root_extent_approx_rr deprecated in Teamcenter 13.1.
    Find applicable approximately-matching appearance roots,
    i.e. given a { root_item, bom_view, rev-rule } triple,
    find an appearance root with the same root_item and bom_view,
    but with a rev-rule which is a suitable subset of the supplied rev-rule,
    in the sense that it matches the supplied rev-rule except that it lacks a date and/or unit-no entry.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_extent_approx_rr")
extern APPR_API int APPR_root_extent_approx_rr(
    tag_t           root_item,        /**< (I) Search for appearance roots of the given root item. */
    tag_t           bom_view,         /**< (I) Search for appearance roots of this bom view (of end item). */
    tag_t           revision_rule,    /**< (I) Search for appearance roots having a configuration context revision rule
                                            that is a suitable subset of the given rule. */
    int*            num_appr_roots,   /**< (O) The number of appearances roots matching the input search criteria. */
    tag_t**         appr_roots        /**< (OF) num_appr_roots Tags of the appearance roots matching the input search criteria. */
    );

/**
    @deprecated #APPR_extent deprecated in Teamcenter 13.1.
    Find all Appearances matching the all the given criteria, i.e. the individual criteria are ANDed together.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_extent")
extern APPR_API int APPR_extent(
    tag_t           appearance_root,                /**< (I) Identifies the appearance set to which matching appearances must belong.
                                                            The appearance root object can be looked up from its identifying
                                                            combination of tracked item, view of tracked item, and context revision
                                                            rule using #APPR_root_extent. Ignored if set to #NULLTAG. */
    logical         search_on_parent_appearance,    /**< (I) If search_on_parent_appearance is true, the value of parent_appearance
                                                            will be matched against appearances’ parent appearance reference.
                                                            Note that #NULLTAG is a valid value (for the root-level appearance of
                                                            the appearance set). */
    tag_t           parent_appearance,              /**< (I) */
    logical         search_on_occurrence_thread,    /**< (I) If search_on_occurrence_thread is true, will attempt to match
                                                            appearances representing this occurrence_thread.

                                                            @note #NULLTAG is a valid value for occurrence_thread
                                                            (for the root-level appearance of the appearance set).

                                                            Occurrence thread is the same value as passed to the occurrence
                                                            argument of PS ITK functions, it is carried over for the same
                                                            ‘logical’ occurrence from one parent BVR to the next. */
    tag_t           occurrence_thread,              /**< (I) */
    tag_t           component_item,                 /**< (I) Searches for appearances having this item as component.
                                                            Ignored if #NULLTAG. */
    logical         search_on_component_bom_view,   /**< (I) If search_on_component_bom_view is true, searches for appearances
                                                            referencing component_bom_view as the view of their component item.
                                                            Note that #NULLTAG is a valid value for component_bom_view
                                                            (for "leaf node" appearances). */
    tag_t           component_bom_view,             /**< (I) */
    date_t          date,                           /**< (I) Searches for appearances valid at the given date and time.
                                                            Ignored if #NULLDATE. */
    logical         search_on_unit_number,          /**< (I) If search_on_unit_number is true, searches for appearances valid for
                                                            the unit number specified by the following argument unit_number. */
    int             unit_number,                    /**< (I) */
    tag_t           query,                          /**< (I) The tag of a Saved Query (see QRY_ module) that should return either a
                                                            list of Items or a list of Item Revisions to be used as matches for the
                                                            component_item attribute. If the query returns Items, it is simply
                                                            merged with the other supplied citeria; if it returns Item Revisions,
                                                            then it is run separately, the Item Revisions are filtered down to the
                                                            configured ones and their Items are used as an explicit list of matches
                                                            for the component_item attribute.

                                                            @note Using an Item Revision query is considerably slower than using
                                                            an Item query, and is generally not recommended.

                                                            A query that returns anything else is rejected.

                                                            This argument is ignored if #NULLTAG. */
    int             num_query_entries,              /**< (I) Arrays (of length num_query_entries) of { entry-name, entry-value }
                                                            pairs that are passed as parameters to the Saved Query specified by
                                                            the preceding query argument.
                                                            Ignored if query is #NULLTAG or if num_query_entries is 0. */
    char**          query_entries,                  /**< (I) num_query_entries  */
    char**          query_values,                   /**< (I) num_query_entries  */
    int             num_ics_classes,                /**< (I) An array (of length num_ics_classes) of Classification class or
                                                            subclass names. A subclass name must be in the format of
                                                            "class name"::"subclass name". */
    char**          ics_class_names,                /**< (I) num_ics_classes  */
    int             num_ics_entries,                /**< (I) Arrays (of length num_ics_entries) of { attribute id, value }
                                                            pairs to match against attributes of the above Classification classes
                                                            or subclasses. */
    int*            ics_uncts,                      /**< (I) num_ics_entries  */
    char**          ics_values,                     /**< (I) num_ics_entries  */
    int             ics_options,                    /**< (I) The Classification class query option. If ics_options is equal to
                                                            SML_ENQ_SEARCH_THIS_CLASS_ONLY, the search will be restricted to the
                                                            given class(es) only. Otherwise, the search will be done in all the
                                                            classes to which the given class(es) is/are an ancestor. */
    int             num_mapped_attrs,               /**< (I) Arrays (of length num_mapped_attrs) of { name, value } pairs to match
                                                            with the mapped attributes (those attributes which do not form original
                                                            data on the Appearance but instead are copied from the Occurrence).
                                                            Ignored if num_mapped_attrs is 0. */
    char**          mapped_attr_names,              /**< (I) num_mapped_attrs  */
    char**          mapped_attr_values,             /**< (I) num_mapped_attrs  */
    int             num_filter_appearances,         /**< (I) An array (of length num_filter_appearances) of appearances against which
                                                            to filter the result of the database query. That is, the final returned
                                                            appearances are the intersection of the query result with this list.
                                                            Ignored if num_filter_appearances is 0. */
    tag_t*          filter_appearances,             /**< (I) num_filter_appearances  */
    int*            num_appearances,                /**< (O) Outputs an array (of length num_appearances) which is the set of
                                                            appearances matching all the given search criteria. */
    tag_t**         appearances                     /**< (OF) num_appearances  */
    );

/**
    @deprecated #APPR_root_ask_root_item deprecated in Teamcenter 13.1.
    Gives the root item whose structure is tracked by this appearance root.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_ask_root_item")
extern APPR_API int APPR_root_ask_root_item(
    tag_t           appr_root,     /**< (I) Tag of the appearance root. */
    tag_t*          root_item      /**< (O) Tag of the appearance root’s root item. */
    );

/**
    @deprecated #APPR_root_ask_bom_view deprecated in Teamcenter 13.1.
    Gives the view of the root item whose structure is tracked by this appearance root.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_ask_bom_view")
extern APPR_API int APPR_root_ask_bom_view(
    tag_t           appr_root,    /**< (I) Tag of the appearance root. */
    tag_t*          bom_view      /**< (O) Tag of the appearance root’s root bom view. */
    );

/**
    @deprecated #APPR_root_ask_root_item_info deprecated in Teamcenter 13.1.
    The root-item-info object is a wrapper round the root item and the bom view.
    It's only really needed if you want to delete it;
    otherwise you can always get directly to the root item and the bom view using
    #APPR_root_ask_root_item and #APPR_root_ask_bom_view.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_ask_root_item_info")
extern APPR_API int APPR_root_ask_root_item_info(
    tag_t           appr_root,         /**< (I) Tag of the appearance root. */
    tag_t*          root_item_info     /**< (O) Tag of the appearance root’s root item info object. */
    );

/**
    @deprecated #APPR_root_ask_revision_rule deprecated in Teamcenter 13.1.
    Gives the revisioin rule used to give the configuration context to this appearance root.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_ask_revision_rule")
extern APPR_API int APPR_root_ask_revision_rule(
    tag_t           appr_root,      /**< (I) Tag of the appearance root. */
    tag_t*          revision_rule   /**< (O) Tag of the appearance root’s revision rule. */
    );

/**
    @deprecated #APPR_root_ask_config_mode deprecated in Teamcenter 13.1.
    Determines the configuration mode of the appearance root:
    release date, date effectivity, unit effectivity, or unit effectivity + release date.
    The configuration mode depends on the contents of the context revision rule.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_ask_config_mode")
extern APPR_API int APPR_root_ask_config_mode(
    tag_t           appr_root,     /**< (I) Tag of the appearance root. */
    int*            config_mode    /**< (O) Configuration mode of the appearance root: <br>
                                        #APPR_cfg_mode_rel_date <br>
                                        #APPR_cfg_mode_date_eff <br>
                                        #APPR_cfg_mode_unit_eff <br>
                                        #APPR_cfg_mode_unit_plus_rdate */
    );

/**
    @deprecated #APPR_root_ask_config_context deprecated in Teamcenter 13.1.
    The configuration-context object is a wrapper round the revision rule.
    It's only really needed if you want to delete it;
    otherwise you can always get directly to the revision rule using #APPR_root_ask_revision_rule.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_root_ask_config_context")
extern APPR_API int APPR_root_ask_config_context(
    tag_t           appr_root,        /**< (I) Tag of the appearance root. */
    tag_t*          config_context    /**< (O) The appearance root’s configuration context object. */
    );

/**
    @deprecated #APPR_ask_validity_dates deprecated in Teamcenter 13.1.
    Gives the range of dates for which the given appearance is valid.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_validity_dates")
extern APPR_API int APPR_ask_validity_dates(
    tag_t           appearance,   /**< (I) Tag of the appearance. */
    date_t*         in_date,      /**< (O) Date on which the appearance becomes valid. */
    date_t*         out_date,     /**< (O) Date from which the appearance is no longer valid. */
    logical*        is_null       /**< (O) True if the appearance is not valid for any date
                                        (in which case the values of in_date and out_date are undefined). */
    );

/**
    @deprecated #APPR_ask_validity_unit_nos deprecated in Teamcenter 13.1.
    Gives the range of unit numbers for which the given appearance is valid.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_validity_unit_nos")
extern APPR_API int APPR_ask_validity_unit_nos(
    tag_t           appearance,   /**< (I) Tag of the appearance. */
    int*            in_unit_no,   /**< (O) Unit number at which the appearance becomes valid. */
    int*            out_unit_no,  /**< (O) Unit number from which the appearance is no longer valid. */
    logical*        is_null       /**< (O) True if the appearance is not valid for any unit number
                                        (in which case the values of in_unit_no and out_unit_no are undefined). */
    );

/**
    @deprecated #APPR_ask_is_valid deprecated in Teamcenter 13.1.
    See if the Appearance is valid for the given date and/or unit-no.
    If checking against date *and* unit-no, it must be valid for both, i.e. it is an AND, not an OR.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_is_valid")
extern APPR_API int APPR_ask_is_valid(
    tag_t           appearance,     /**< (I) Tag of the appearance. */
    date_t          date,           /**< (I) The value to match against the validity date-range;
                                            that is, the Appearance's in-date
                                            must be less than or equal to the given date,
                                            and its out-date must be greater than the given date.
                                            Ignored if #NULLDATE. */
    logical         check_unit_no,  /**< (I) If check_unit_no is true,
                                            unit_no supplies the value to match against the validity unit-no-range;
                                            that is, the Appearance's in-unit-no must be less than or equal to the given unit-no,
                                            and its out-unit-no must be greater than the given unit-no. */
    int             unit_no,        /**< (I) */
    logical*        verdict         /**< (O) True if the appearance is valid for the given input criteria. */
    );

/**
    @deprecated #APPR_ask_parent deprecated in Teamcenter 13.1.
    Gives the appearance’s parent, i.e. the next-higher appearance in the structure.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_parent")
extern APPR_API int APPR_ask_parent(
    tag_t           appearance,   /**< (I) Tag of the appearance. */
    tag_t*          parent        /**< (O) Tag of the appearance's parent appearance. */
    );

/**
    @deprecated #APPR_ask_appr_root deprecated in Teamcenter 13.1.
    Gives the appearance root of the appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_appr_root")
extern APPR_API int APPR_ask_appr_root(
    tag_t           appearance,   /**< (I) Tag of the appearance. */
    tag_t*          appr_root     /**< (O) Tag of the appearance root. */
    );

/**
    @deprecated #APPR_ask_occurrence deprecated in Teamcenter 13.1.
    Gives the occurrence represented by this appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_occurrence")
extern APPR_API int APPR_ask_occurrence(
    tag_t           appearance,   /**< (I) Tag of the appearance. */
    tag_t*          occurrence    /**< (O) Tag of the appearances’s occurrence. */
    );

/**
    @deprecated #APPR_ask_component_item deprecated in Teamcenter 13.1.
    Gives the component item referenced by the appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_component_item")
extern APPR_API int APPR_ask_component_item(
    tag_t           appearance,       /**< (I) Tag of the appearance. */
    tag_t*          component_item    /**< (O) Tag of the component item. */
    );

/**
    @deprecated #APPR_ask_component_bom_view deprecated in Teamcenter 13.1.
    Gives the component bom view referenced by the appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_component_bom_view")
extern APPR_API int APPR_ask_component_bom_view(
    tag_t           appearance,           /**< (I) Tag of the appearance. */
    tag_t*          component_bom_view    /**< (O) Tag of the component bom view. */
    );

/**
    @deprecated #APPR_ask_transform deprecated in Teamcenter 13.1.
    Gives the absolute positional transformation matrix for this appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_transform")
extern APPR_API int APPR_ask_transform(
    tag_t           appearance,       /**< (I) Tag of the appearance. */
    double**        xform_data        /**< (OF) 16 A 16-element array giving the transform in PLM XML format. */
    );

/**
    @deprecated #APPR_ask_validity_min_date deprecated in Teamcenter 13.1.
    Gives the predefined minimum value for appearance date validity. This is used to mean ‘open initial date’.

    @note As this function is very simple it is deliberately not journaled.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_validity_min_date")
extern APPR_API int APPR_ask_validity_min_date(
    date_t*         validity_min_date   /**< (O) Minimum value for appearance date validity. */
    );

/**
    @deprecated #APPR_ask_validity_max_date deprecated in Teamcenter 13.1.
    Gives the predefined maximum value for appearance date validity.
    This is used to mean ‘open ended date validity’.

    @note As this function is very simple it is deliberately not journaled.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_validity_max_date")
extern APPR_API int APPR_ask_validity_max_date(
    date_t*         validity_max_date   /**< (O) Maximum value for appearance date validity. */
    );

/**
    @deprecated #APPR_ask_validity_min_unit_no deprecated in Teamcenter 13.1.
    Gives the predefined minimum value for appearance unit number validity.
    This is used to mean ‘open initial unit number validity’.

    @note As this function is very simple it is deliberately not journaled.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_validity_min_unit_no")
extern APPR_API int APPR_ask_validity_min_unit_no(
    int*            validity_min_unit_no   /**< (O) Minimum value for appearance unit number validity. */
    );

/**
    @deprecated #APPR_ask_validity_max_unit_no deprecated in Teamcenter 13.1.
    Gives the predefined maximum value for appearance unit number validity.
    This is used to mean ‘open ended unit number validity’.

    @note As this function is very simple it is deliberately not journaled.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_validity_max_unit_no")
extern APPR_API int APPR_ask_validity_max_unit_no(
    int*            validity_max_unit_no   /**< (O) Maximum value for appearance unit number validity. */
    );

/**
    @deprecated #APPR_define_attr deprecated in Teamcenter 13.1.
    Defines a new appearance attribute.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_define_attr")
extern APPR_API int APPR_define_attr(
    const char*     name,     /**< (I) Unique name for this appearance attribute. */
    tag_t*          attrdef   /**< (O) Definition of the new attribute. */
    );

/**
    @deprecated #APPR_ask_attr_list deprecated in Teamcenter 13.1.
    Returns definitions for all mapped appearance attributes.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_list")
extern APPR_API int APPR_ask_attr_list(
    int*            n_attrdefs,    /**< (O) Number of attributes. */
    tag_t**         attrdefs       /**< (OF) n_attrdefs Array of attribute definitions. */
    );

/**
    @deprecated #APPR_find_attr deprecated in Teamcenter 13.1.
    Returns the definition for the named appearance attribute.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_find_attr")
extern APPR_API int APPR_find_attr(
    const char*     attrname,  /**< (I) Name of attribute to find. */
    tag_t*          attrdef    /**< (O) Attribute definition. */
    );

/**
    @deprecated #APPR_ask_attr_name deprecated in Teamcenter 13.1.
    Returns the name of the given attribute.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_name")
extern APPR_API int APPR_ask_attr_name(
    tag_t           attrdef,    /**< (I) Definition of the attribute being queried. */
    char**          name        /**< (OF) Name of the attribute. */
    );

/**
    @deprecated #APPR_delete_instances_of_attr deprecated in Teamcenter 13.1.
    Deletes all instances of the given appearance attribute.
    This function must be invoked before attempting to delete an attribute definition.
    Failure to call this will result in POM’s referential integrity rules refusing to delete the definition.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_delete_instances_of_attr")
extern APPR_API int APPR_delete_instances_of_attr(
    tag_t           attrdef     /**< (I) Definition of the attribute whose instances should be deleted. */
    );


/**
    @deprecated #APPR_ask_attr_mappings deprecated in Teamcenter 13.1.
    Returns a list of all appearance attribute mappings.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_mappings")
extern APPR_API int APPR_ask_attr_mappings(
    int*            n_mappings,   /**< (O) Number of occurrence note types in the mapping. */
    tag_t**         mappings      /**< (OF) n_mappings Array of note types in the mapping. */
    );

/**
    @deprecated #APPR_ask_attr_mapping deprecated in Teamcenter 13.1.
    For a given mapping, this function returns a list of occurrence note types and
    the appearance attributes that they map onto.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_mapping")
extern APPR_API int APPR_ask_attr_mapping(
    tag_t           mapping,      /**< (I) Mapping being queried. */
    int*            n_notetypes,  /**< (O) Number of occurrence note types in the mapping. */
    tag_t**         notetypes,    /**< (OF) n_notetypes Array of note types in the mapping. */
    int*            n_attrdefs,   /**< (O) Number of attributes in the mapping. */
    tag_t**         attrdefs      /**< (OF) n_attrdefs Array of attribute definitions in the mapping. */
    );

/**
    @deprecated #APPR_ask_attr_mapping_as_string deprecated in Teamcenter 13.1.
    For a given mapping, this function returns its string representation.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_mapping_as_string")
extern APPR_API int APPR_ask_attr_mapping_as_string(
    tag_t           mapping,          /**< (I) Mapping being queried. */
    char**          mappingAsString   /**< (OF) Number of occurrence note types in the mapping. */
    );

/**
    @deprecated #APPR_create_attr_mapping deprecated in Teamcenter 13.1.
    Creates a new mapping for transferring occurrence note data onto appearance attributes.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_create_attr_mapping")
extern APPR_API int APPR_create_attr_mapping(
    int             n_notetypes,   /**< (I) Number of occurrence note types in the mapping. */
    tag_t*          notetypes,     /**< (I) n_notetypes Array of note types in the mapping. */
    int             n_attrdefs,    /**< (I) Number of attributes in the mapping. */
    tag_t*          attrdefs,      /**< (I) n_attrdefs Array of attribute definitions in the mapping. */
    logical         external,      /**< (I) Set this to true to invoke the mapping user exit for this mapping. */
    tag_t*          mapping        /**< (O) New mapping. */
    );

/**
    @deprecated #APPR_set_attr_mapping deprecated in Teamcenter 13.1.
    Changes an existing mapping to use the given list of occurrence note types and appearance attribute definitions.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_set_attr_mapping")
extern APPR_API int APPR_set_attr_mapping(
    tag_t           mapping,       /**< (I) Mapping to update. */
    int             n_notetypes,   /**< (I) Number of occurrence note types in the mapping. */
    tag_t*          notetypes,     /**< (I) n_notetypes Array of note types in the mapping. */
    int             n_attrdefs,    /**< (I) Number of attributes in the mapping. */
    tag_t*          attrdefs       /**< (I) n_attrdefs Array of attribute definitions in the mapping. */
    );

/**
    @deprecated #APPR_find_attr_mapping deprecated in Teamcenter 13.1.
    Searches for an appearance attribute mapping with the given notetypes onto the given appearances attributes.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_find_attr_mapping")
extern APPR_API int APPR_find_attr_mapping(
    int             n_notetypes,   /**< (I) Number of occurrence note types. */
    tag_t*          notetypes,     /**< (I) n_notetypes Array of note types to search for. */
    int             n_attrdefs,    /**< (I) Number of attributes. */
    tag_t*          attrdefs,      /**< (I) n_attrdefs Array of attribute definitions to search for. */
    tag_t*          mapping        /**< (O) Mapping found, or #NULLTAG if no mapping is found. */
    );

/**
    @deprecated #APPR_ask_mapping_external deprecated in Teamcenter 13.1.
    Returns a flag indicating whether or not the given mapping will invoke the mapping user exit.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_mapping_external")
extern APPR_API int APPR_ask_mapping_external(
    tag_t           mapping,        /**< (I) Mapping being queried. */
    logical*        external        /**< (O) Set to true if the user exit will be invoked. */
    );

/**
    @deprecated #APPR_set_mapping_external deprecated in Teamcenter 13.1.
    Controls whether or not the given mapping will invoke the mapping user exit.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_set_mapping_external")
extern APPR_API int APPR_set_mapping_external(
    tag_t           mapping,        /**< (I) Mapping being queried. */
    logical         external        /**< (I) Set this to true to invoke the user exit. */
    );

/**
    @deprecated #APPR_set_attr_value deprecated in Teamcenter 13.1.
    Sets the value of the given attribute of an appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_set_attr_value")
extern APPR_API int APPR_set_attr_value(
    tag_t           appearance,  /**< (I) Appearance being updated. */
    tag_t           attrdef,     /**< (I) Definition of the attribute to be set. */
    const char*     value        /**< (I) New value for the attribute. */
    );

/**
    @deprecated #APPR_ask_attr_value deprecated in Teamcenter 13.1.
    Returns the value of the given attribute of an appearance.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_value")
extern APPR_API int APPR_ask_attr_value(
    tag_t           appearance,    /**< (I) Appearance being queried. */
    tag_t           attrdef,       /**< (I) Definition of the attribute being queried. */
    char**          value          /**< (OF) Value of the attribute. */
    );

/**
    @deprecated #APPR_ask_named_attr_values deprecated in Teamcenter 13.1.
    Returns the values of the named appearance attributes.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_named_attr_values")
extern APPR_API int APPR_ask_named_attr_values(
    tag_t           appearance,  /**< (I) Appearance being queried. */
    int             n_values,    /**< (I) Number of attributes being queried. */
    const char**    attrnames,   /**< (I) n_values Array of names of attributes being queried. */
    char***         attrvalues   /**< (OF) n_values Values of the named attributes. */
    );

/**
    @deprecated #APPR_ask_attr_values deprecated in Teamcenter 13.1.
    Returns the values of the all set attributes of an appearance.
    Attributes which have not had a value set are not returned.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_attr_values")
extern APPR_API int APPR_ask_attr_values(
    tag_t           appearance,   /**< (I) Appearance being queried. */
    int*            n_values,     /**< (O) Number of attributes that have a value. */
    char***         attrnames,    /**< (OF) n_values Names of the attributes that have a value. */
    char***         attrvalues    /**< (OF) n_values Values of the attributes. */
    );

/**
    @deprecated #APPR_ask_all_attr_values deprecated in Teamcenter 13.1.
    Returns the values of the every attribute of an appearance.
    Attributes that have no value for a given appearance will return an empty string.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_ask_all_attr_values")
extern APPR_API int APPR_ask_all_attr_values(
    tag_t           appearance,   /**< (I) Appearance being queried. */
    int*            n_values,     /**< (O) Number of attributes. */
    char***         attrnames,    /**< (OF) n_values Names of the attributes. */
    char***         attrvalues    /**< (OF) n_values Values of the attributes. */
    );

/**
    @deprecated #APPR_create_updater deprecated in Teamcenter 13.1.
    Creates an appearances updater package with a release status and a list of item revisions
    that have been released with the given release status.
    This package is queued for processing under control of the Appearance Update Manager.

    <b>Restrictions:</b>

    The item revisions added to the updater must have a release status that is the same as that of the updater.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_create_updater")
extern APPR_API int APPR_create_updater(
    tag_t           release_status,    /**< (I) The release status applied to the changed item revisions. */
    int             n_item_revs,       /**< (I) The number of changed item revisions to be added to the updater. */
    tag_t*          item_revs,         /**< (I) n_item_revs Tags of the changed item revisions. */
    tag_t*          updater            /**< (O) The newly created appearances updater. */
    );

/**
    @deprecated #APPR_create_incr_updater deprecated in Teamcenter 13.1.
    Creates an update package with release status and a Incremental Change Revision that
    have been released with that release status instance.
    This package is placed on the primary queue for processing by the update manager.
    This function is called by the APPR-update-from-targets handler supplied out of the box,
    but may be called from custom handlers.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_create_incr_updater")
extern APPR_API int APPR_create_incr_updater(
    tag_t           release_status,    /**< (I) */
    tag_t           incr_rev,          /**< (I) IncrementalChangeRevision */
    tag_t*          updater            /**< (O) */
    );

/**
    @deprecated #APPR_create_pre_release_updater deprecated in Teamcenter 13.1.
    Creates an update-for-pre-release package with release status and a list of item revisions that
    have been released with that release status instance.
    This package is placed on the primary queue for processing by the update manager.
    This function is called by the APPR-update-from-targets handler supplied out of the box,
    but may be called from custom handlers.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_create_pre_release_updater")
extern APPR_API int APPR_create_pre_release_updater(
    tag_t           release_status,    /**< (I) */
    int             n_item_revs,       /**< (I) */
    tag_t*          item_revs,         /**< (I) n_item_revs */
    tag_t*          updater            /**< (O) */
    );

/**
    @deprecated #APPR_create_import_updater deprecated in Teamcenter 13.1.
    Creates an update-on-import package with release status and a list of item revisions that
    have been imported and have that release status instance.
    This package is placed on the primary queue for processing by the update manager.
    This function is called by the APPR-update-from-targets handler supplied out of the box,
    but may be called from custom handlers.

*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_create_import_updater")
extern APPR_API int APPR_create_import_updater(
    date_t          when,              /**< (I) */
    tag_t           release_status,    /**< (I) */
    int             n_item_revs,       /**< (I) */
    tag_t*          item_revs,         /**< (I) n_item_revs */
    tag_t*          updater            /**< (O) */
    );

/**
    @deprecated #APPR_create_working_updater deprecated in Teamcenter 13.1.
    Creates a working update package on the queue for the updater to process
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_create_working_updater")
extern APPR_API int APPR_create_working_updater(
    tag_t*          updater            /**< (O) */
    );

/**
    @deprecated #APPR_process_import_updates deprecated in Teamcenter 13.1.
    Processes the import info that the above call stored.
*/
TC_DEPRECATED_NO_REPLACEMENT("13.1", "APPR_process_import_updates")
extern APPR_API int APPR_process_import_updates();

/** @} */

#ifdef __cplusplus
}
#endif

#include <appr/libappr_undef.h>

#endif
