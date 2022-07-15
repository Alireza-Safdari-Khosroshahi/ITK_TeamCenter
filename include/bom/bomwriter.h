/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK calls into the BOMWriter system
*/

/*  */

#ifndef BOMWRITER_H
#define BOMWRITER_H

#include <stdio.h>

#include <unidefs.h>

#include <bom/libbom_exports.h>

/**
    @defgroup BOMWRITER Writer
    @ingroup BOM

    <b>ITK calls into the BOMWriter system</b>

    BOM_writer_write_bomwindow() traverses a bomwindow, writing its bomlines according to some
    file format (eg AJT, PLMXML), to an output mode (typically an open file handle).

    The user has to nominate the output mode, file format, and any traversal modifiers. This
    is done via three pointers to structures that select the particular mode, format, or
    modifiers, and allow you to communicate options for each.

    You should NOT allocate the structures yourself. Use the ITK calls, which fill in the
    default values for you and mark the structure's first field so the system can identify
    which format/mode you've chosen. They can only fail by exhausting memory (when the returned
    pointer shall be NULL, assuming it ever gets back to you).

    The default values set are always zero or null, unless otherwise specified. Some defaults
    are invalid, to force you to set a value. You must set an explicit filehandle, for
    instance. Future additional options should default to backwards-compatible behaviour.

    By default, packed lines are ignored except for the packmaster. You may request virtual
    unpacking, but this slows down traversal as lines are unpacked and repacked. It is strongly
    recommended that you create unpacked windows in the first place.

    Example: write an AJT format file:

    @code
        #include <bom/bom.h>
        #include <bom/bomwriter.h>

        BOM_writer_output*      file_output=0;
        BOM_writer_format*      ajt_format=0;
        BOM_writer_traversal*   traversal=0;

        if ( BOM_writer_new_output_file(&file_output) == ITK_ok &&
            BOM_writer_new_format_ajt (&ajt_format)  == ITK_ok &&
            BOM_writer_new_traversal  (&traversal)   == ITK_ok )
        {
            file_output->file.filehandle = fopen("myfilename","w");
    @endcode
    Use AJT format, but:
    <ol>
    <li>The File "" attributes' value shall be the tcfs file path
        appropriate for the native system to use (Unix vs NT path)
    <li>The nominated user function shall be called for each part/assembly
    <li>The nominated user data shall be supplied to the user function.
    </ol>
    @code
            ajt_format->ajt.file_attr_style = BOM_writer_ajt_file_attr_native;
            ajt_format->ajt.userfunc        = &user_supplied_function;
            ajt_format->ajt.userdata        = &datastructure_for_user_functions;

            ifail = BOM_writer_write_bomwindow( window, file_output, ajt_format, traversal );
        }

        BOM_writer_delete(file_output);
        BOM_writer_delete(ajt_format);
        BOM_writer_delete(traversal);
    @endcode

    <b>USER FUNCTIONS</b>

    All output formats should provide one or more callbacks, to allow for some user-level
    augmentation of the data being emitted by the format - for instance, add attributes to AJT
    entries.

    User functions shall typically use #BOM_writer_userfunc_t, but some formats may use other
    function prototypes, which shall be detailed with their structure definition.

    They are passed the current bomline, the bomline's parent for the purposes
    of file-structure (in case the flatten adapter or similar is being used)
    the reason the bomline has been supplied (it's one or more of:
    #BOM_writer_node_ancestor, selected, descendant, or leaf), and any userdata
    the caller provided.

    @note The parent tag of the root node is the tag of the root node itself, not
    #NULLTAG as you might expect. You should check depth==0 for the root.

    BOMWriter user-functions generally return a null-terminated string that the
    system can send to the output system, or a NULL pointer to indicate a fatal
    error. BOM_writer_write_bomwindow() takes responsibility for MEM_free()ing
    any string returned.

    <b>USER ATTRIBUTES</b>

    Most formats have a way of presenting arbitrary key-value pairs for
    particular nodes in the output file. user_attributes provide a simple
    manner of using these to present various user-required data.

    User attributes allow the user to specify that for a given format-defined
    target (a location or locations within the file), certain additional values
    should be presented. These values are generally specified as key/property
    or key/attribute pairs appearing after a target specifier.

    Currently, AJT format supports Root and Node targets: Node representing every
    PRT or ASM node; Root representing the topmost Node. PLMXML format supports
    Root, Part, Instance, and Occurrence targets. Root represents the topmost
    Part node. The root targets are intended for once-per-file data, typically
    literal strings, perhaps to communicate the intent of the file to receiving
    applications (eg Merge with current tree, Delete from current tree, etc).

    For example:

    <b>target:Node, key:alt_rep, prop:UG ALTREP, key:creator, attr:TOOL</b>

    The directive propuid: behaves like prop: but must be given a property that
    returns a tag (or tag-list), which it presents as a UID
    (space-separated list of UIDs). The directive literal: simply evaluates to
    the string given to it.

    There is a special directive attrmap: which inserts all the attributes
    returned by the ITK call ATTRMAP_list_mappings() with key:s based on the
    the attributes' standard names. attrmap: is never paired with a key: of its
    own.

    User attributes may also specify preferences that should be examined for
    more list items. If this sublist appears after a target: has been specified
    in the main list, any key/value pairs in the sublist will be inserted into
    that target until another target is specified in the sublist. It is an
    error for key: or attrmap: to be specified unless a target: has been
    indicated. The preference BOMWRITER_max_preference_depth controls how
    deeply sublists can refer to other sublists. The default is 10. Perhaps
    confusingly, target settings revert at the end of a preference.

    For example:

    <b>target:Node, pref:some_pref

    some_pref = key:alt_rep, prop:UG ALTREP, pref:other_pref, key:ID, prop:bl_item_item_id
    other_pref = target:Leaf, key:creator, attr:TOOL</b>

    results in Node=alt_rep/UG ALTREP, ID/bl_item_item_id and Leaf=creator/TOOL

    A malformed prop/key list will cause an error. Multiple lists directed to
    the same target: will be concatenated/merged. An empty target-list is legal
    but has no effect. It is an error for one key: to have more than one value
    specified.

    An undefined property will cause an error. An undefined preference will cause an error.

    The syntax of char** user_attributes is as follows, examples follow:

    user_attributes :== \<target-pref-entry\>* \<target-specifier\>* \<end-attribute\>

    target-specifier :== \<target-entry\> \<target-list\>

    target-list :=+ (   \<key-entry\> \<value-entry\> <br>
                      | \<pref-entry\> <br>
                      | \<global-attrmap\> <br>
                    )*

    target-entry    :== "target:" \<target id\>,

    key-entry       :== "key:" \<key string\>,

    value-entry     :== "prop:" \<bomline property name\>, <br>
                        | "propuid:" \<bomline property tag value converted to uid\> <br>
                        | "literal:" \<literal string>, <br>
                        | "attr:" \<attribute-mapped name\>, <br>

    target-pref-entry :== "pref:" \<preference name\>, <br>
        NOTE: target-pref-entry's preference data :== \<user_attributes\>

    pref-entry      :== "pref:" \<preference name\>, <br>
        NOTE: pref-entry's preference data :== \<target-list\> \<target-specifier\>*

    global-attrmap  :== "attrmap:",

    end-attributes  :== NULL or 0 (null string pointer, not empty string)

    eg:
    @code
        char** plmxml_attributes =
        {
            BOMWRITER_UA_PREF,
            "DesignContext_plmxml_user_attributes",
            BOMWRITER_PLMXML_PART_UA_TARGET,
            BOMWRITER_UA_KEY,
            "OCCUID",
            BOMWRITER_UA_PROPUID,
            "bl_occurrence_uid",
            0
        };
    @endcode
    ---------
    # Preference file excerpt
    DesignContext_plmxml_user_attributes=
    target:part
    key:IMAN_REV_ID
    prop:bl_item_rev_id
    target:instance
    key:IMAN_REF_SET
    prop:UG REF SET
    ----------
    @code
        char** ajt_attributes =
        {
            BOMWRITER_AJT_NODE_UA_TARGET,
            "attrmap:",
            0
        };
    @endcode

    <b>Structures</b>

    Insert the word 'new' after 'BOM_writer' to get each structure's allocating function:
    #BOM_writer_output_file structures are created by BOM_writer_new_output_file().

    @{
*/

/**
    @name BOM Writer - format user callback definitions
    @{
*/
#define BOM_writer_node_unset                   0
#define BOM_writer_node_selected                (1<<0)
#define BOM_writer_node_ancestor                (1<<1)
#define BOM_writer_node_descendant              (1<<2)
#define BOM_writer_node_leaf                    (1<<3)
#define BOM_writer_node_assy_geom               (1<<4)
#define BOM_writer_node_subselected             (1<<5)
#define BOM_writer_node_subancestor             (1<<6)
#define BOM_writer_node_subdescendant           (1<<7)

/**
    Many of these input-parameter structures take function-parameters for callback routines.
    The callbacks often return BOM_writer_delete()able strings which are printed to the selected
    output mechanism and then freed by the system.
    Returning NULL indicates an error that should halt traversal.
    The callbacks often have the following parameters.
    Extra parameters are mentioned with the function's documentation. 
    Unless otherwise specified, you may ignore the callback parameters and a sensible do-nothing default will be assumed.
*/
typedef char* (*BOM_writer_userfunc_t)(
    tag_t       bomline,        /**< The tag of the bomline being visited */
    tag_t       parent,         /**< The tag of the effective parent of the bomline. 
                                    If the BOMWriter 'flatten' adaptor is in use,
                                    the BOMWriter output tree differs from the PSE tree,
                                    and the bomline property 'bl_parent' becomes unreliable. */
    void*       transform,      /**< A pointer to the transform associated with the bomline. */
    int         node_reason,    /**< A bit-vector: The logical 'or' of one or more of: <br>
                                    #BOM_writer_node_unset - Node has no properties. You should never see this. <br>
                                    #BOM_writer_node_selected - Node was in the user-supplied selection list. <br>
                                    #BOM_writer_node_ancestor - Node is an ancestor of a selected line <br>
                                    #BOM_writer_node_descendant - Node is a descendant of a selected line. <br>
                                    #BOM_writer_node_assy_geom - (AJT format only) Node has assembly-level geometry <br>
                                    #BOM_writer_node_subselected - Node was in the user-supplied subselection list. <br>
                                    #BOM_writer_node_subancestor - Node is an ancestor of a subselected line <br>
                                    #BOM_writer_node_subdescendant - Node is a descendant of a subselected line. <br>
                                    #BOM_writer_node_leaf - Node is a leaf node. */
    int         depth,          /**< The depth of the node. Root is 0, root's children are 1, etc. */
    void*       userdata        /**< The userdata parameter passed in via the format structure */
    );

/**
    This must be the first member of every BOM_writer structure 
*/
typedef struct{
    long    struct_type;  /**< reserved */
    void*   object;       /**< reserved */
} BOM_writer_struct;

/** @} */

/**
    @name User Attribute prefix strings
    @{
*/
#define BOMWRITER_UA_TARGET                     "target:"
#define BOMWRITER_UA_PREF                       "pref:"
#define BOMWRITER_UA_ATTRMAP                    "attrmap:"
#define BOMWRITER_UA_KEY                        "key:"
#define BOMWRITER_UA_PROP                       "prop:"
#define BOMWRITER_UA_ATTR                       "attr:"
#define BOMWRITER_UA_LITERAL                    "literal:"
#define BOMWRITER_UA_PROPUID                    "propuid:"
/** @} */

/**
    @name Output Modes
    
    Where the output format gets written to
    @{
*/

/**
    Output is sent to a filehandle. Example:

    @code
        BOM_writer_output_file* p;
        BOM_writer_new_output_file( &p );
        p->filehandle = fopen("file", "r");
        BOM_writer_write_bomwindow( p, ... );
        fclose( p->filehandle );
        BOM_writer_delete( p );
    @endcode
*/
typedef struct{
    BOM_writer_struct   struct_type;
    FILE*               filehandle;     /**< Must be a valid fopen() style filehandle */
}  BOM_writer_output_file;

/**
    MEM_free()able string output mode. Example:

    @code
        BOM_writer_output_smstring* p;
        BOM_writer_new_output_smstring( &p );
        BOM_writer_write_bomwindow( ..., p, ...);
        printf("%s",(p->smstring!=NULL)?(p->smstring):"NO DATA");
        MEM_free(p->smstring);
        BOM_writer_delete(p);
    @endcode

    smstring will be valid or NULL after the call. 
    You gain a complete null-terminated string of the data in memory,
    which could be large. Use with caution.

    You may adopt the string (to MEM_free() yourself later)
    by setting smstring = 0 before BOM_writer_delete().
*/
typedef struct{
    BOM_writer_struct   struct_type;
    char*               smstring;       /**< Will be valid or NULL after the call. You win a complete file in memory.
                                            You may adopt the string (to MEM_free() it yourself later) by setting smstring = 0
                                            before BOM_writer_delete(). */
} BOM_writer_output_smstring;

typedef union{
    BOM_writer_struct           common;
    BOM_writer_output_file      file;
    BOM_writer_output_smstring  smstring;
} BOM_writer_output;

/** @} */

/**
    @name Output Formats
    
    How the BOM Window looks when it's written out
    @{
*/

/**
    EMPTY format - Lots of callbacks though 
*/
typedef char* (*BOM_writer_empty_ep_t)(  
    tag_t       bomline,        /**< The tag of the bomline being visited */
    tag_t       parent,         /**< The tag of the effective parent of the bomline. 
                                    If the BOMWriter 'flatten' adaptor is in use,
                                    the BOMWriter output tree differs from the PSE tree,
                                    and the bomline property 'bl_parent' becomes unreliable. */
    void*       transform,      /**< A pointer to the transform associated with the bomline. */
    int         node_reason,    /**< A bit-vector: The logical 'or' of one or more of: <br>
                                    #BOM_writer_node_unset - Node has no properties. You should never see this. <br>
                                    #BOM_writer_node_selected - Node was in the user-supplied selection list. <br>
                                    #BOM_writer_node_ancestor - Node is an ancestor of a selected line <br>
                                    #BOM_writer_node_descendant - Node is a descendant of a selected line. <br>
                                    #BOM_writer_node_assy_geom - (AJT format only) Node has assembly-level geometry <br>
                                    #BOM_writer_node_subselected - Node was in the user-supplied subselection list. <br>
                                    #BOM_writer_node_subancestor - Node is an ancestor of a subselected line <br>
                                    #BOM_writer_node_subdescendant - Node is a descendant of a subselected line. <br>
                                    #BOM_writer_node_leaf - Node is a leaf node. */
    int         depth,          /**< The depth of the node. Root is 0, root's children are 1, etc. */
    int         count,
    void*       userdata,       /**< The userdata parameter passed in via the format structure */
    int*        prune
    );

typedef int (*BOM_writer_asktform_t)(
    tag_t     bomline,     /**< The tag of the bomline being visited */
    int       depth,       /**< The depth of the node. Root is 0, root's children are 1, etc. */
    void**    transform
    );

typedef int (*BOM_writer_combtform_t)(
    void*     transform1,
    void*     transform2,
    void**    result
    );

typedef int (*BOM_writer_freetform_t)(
    void*     transform
    );

/**
    Completely blank format: all output comes from the callbacks, 
    which should return NULL on fatal error, or a MEM_free()able string otherwise.
*/
typedef struct{
    BOM_writer_struct      struct_type;
    BOM_writer_empty_ep_t  enter_parent;          /**< Is called before any of a node's decendants are visited.
                                                        If it sets (*prune) to nonzero, traversal will skip this node's children
                                                        and won't call this node's leave_parent() call. */
    BOM_writer_userfunc_t  write_leaf;            /**< Is called for every leaf node scheduled to be visited */
    BOM_writer_userfunc_t  leave_parent;          /**< Is called after all of a node's scheduled descendants have been visited */
    BOM_writer_asktform_t  ask_transform;         /**< Should return a free_transform()-freeable block,
                                                        representing the transform passed to your enter/leave_parent,
                                                        and write_leaf() calls. Defaults to a function returning NULL. */
    BOM_writer_combtform_t combine_transforms;    /**< Should return a free_transform()-freeable block,
                                                        representing the combination of the two supplied tranforms.
                                                        Defaults to a function returning NULL. */
    BOM_writer_freetform_t free_transform;        /**< Should allow the system to free tranforms.
                                                        Essentially defaults to MEM_free(). */
    void*                  userdata;              /**< Store bomwriter output content */
} BOM_writer_format_empty;

typedef enum BOM_writer_ajt_style_e{
    BOM_writer_ajt_file_url,        /**< Default, currently unimplemented */
    BOM_writer_ajt_file_unix,
    BOM_writer_ajt_file_nt,
    BOM_writer_ajt_file_native,
    BOM_writer_ajt_file_user,
    BOM_writer_ajt_file_uidtag,
    BOM_writer_ajt_file_webtag
}  BOM_writer_ajt_file_style;

typedef char* (*BOM_writer_ajtfilefunc_t)(
    tag_t       dataset,
    tag_t       imanfile,
    tag_t       line,
    void*       userdata
    );

#define BOMWRITER_AJT_ROOT_UA_TARGET BOMWRITER_UA_TARGET "Root"
#define BOMWRITER_AJT_NODE_UA_TARGET BOMWRITER_UA_TARGET "Node"

/**
    This format implements the AJT format, writing ASY and PRT clauses.
    @note Any node appearing as a leaf node only as a result of line-selection or
    the 'suppress descendants' option will still be emitted as an ASY line (with no children).

    These attributes are supported:
    ASY and PRT "DB_PART_NO", "DB_PART_REV", "DB_OCC_UID"
     
    ASY and PRT Matrix [] where available
     
    PRT "File", "DB_PART_REP_TIMESTAMP" where available
*/
typedef struct{
    BOM_writer_struct         struct_type;
    logical                   supply_identity;      /**< If true, absent transforms are treated like identity transforms.
                                                       <br/>The default value is "false" (this default is historical).
                                                       By default, a missing tranform is a fatal error.
                                                    */
    logical skip_fake_part;                         /**< If true, skip dummy parts for sub-assemblies.
                                                     <br/>The default value is "false". */
    logical asm_jt_file;                            /**< If false, only writer the leaf node files
                                                    <br/>If true,writer files associated with both leaf nodes and assembly lines
                                                    <br/>The default value is "false". */
    BOM_writer_userfunc_t     userfunc;             /**< Called immediately after the ASY/PRT line is emitted 
                                                       so you can add attributes. 
                                                       <br/>You should return a MEM_free()able string that we free. 
                                                       <br/>There is no default value. */
    BOM_writer_ajtfilefunc_t  userfilefunc;         /**< Only used if file_attr_style is #BOM_writer_ajt_file_user.
                                                       <br/>Return a MEM_free()able string that contains the 
                                                       value of the FILE attribute that we free. 
                                                       <br/>There is no default value. */
    void*                     userdata;             /**<  */
    BOM_writer_ajt_file_style file_attr_style;      /**< The format of the data in the File "" attribute;
                                                       either a URL (default), or a filepath to the imanfile storage. <br/>
                                                       #BOM_writer_ajt_file_url - URL format (unimplemented). <br/>
                                                       #BOM_writer_ajt_file_unix - Teamcenter Engineering FS path in UNIX format. <br/>
                                                       #BOM_writer_ajt_file_nt - Teamcenter Engineering FS path in NT format. <br/>
                                                       #BOM_writer_ajt_file_native - Unix or NT format. <br/>
                                                       #BOM_writer_ajt_file_uidtag - UIDTAG format. <br/>
                                                       #BOM_writer_ajt_file_webtag - WEBTAG Format. <br/>
                                                       #BOM_writer_ajt_file_user - For internal use only. */
    char**                    user_attributes;      /**< Ask for certain bomline properties to appear in the output file,
                                                       for each "Node". */
    long                      fatal_minor_errors;   /**< By default, minor errors will be handled quietly.
                                                       Set this to -1 to make BOMWriter abort. 
                                                       (Missing AJT transforms are not handled through this flag.) */
} BOM_writer_format_ajt;

#define BOMWRITER_PLMXML_ROOT_UA_TARGET         BOMWRITER_UA_TARGET "Root"
#define BOMWRITER_PLMXML_PART_UA_TARGET         BOMWRITER_UA_TARGET "Part"
#define BOMWRITER_PLMXML_INSTANCE_UA_TARGET     BOMWRITER_UA_TARGET "Instance"
#define BOMWRITER_PLMXML_OCCURRENCE_UA_TARGET   BOMWRITER_UA_TARGET "Occurrence"

/**
    This format implements the PLMXML format.

    Since BOMWriter uses the Parasolid PLMXML Toolkit for its PLMXML abilities,
    any user-extension code must interact with that toolkit, which requires a C++ compiler.
    Since a C++ compiler must be available,
    the user-extensions will be supplied as a subclass of the
    BOMWriterFormatPLMXMLBuilder class or its subclasses (headers supplied). 
    The user will use C++ to interact with the PLMXML toolkit,
    but will still use ITK from C++ to interrogate TCEng. 

    Although the user-extension code could be linked into a multiple-object ITK program,
    it is best supplied as a shared library, using a dynamic registration system,
    so the extension format is generally available throughout the system.
*/
typedef enum TransformType_e
{
    TransformType_None,
    TransformType_Cumulative,
    TransformType_AbsOcc,
    TransformType_AbsOcc_Then_Cumulative
} BOM_writer_TransformType;
typedef struct{
    BOM_writer_struct   struct_type;
    char*               builder_name;           /**< Name of plmxml builder to use
                                                    (pointer must remain valid until BOM_writer_write_bomwindow() returns).
                                                    Defaults to BaseOccurrences builder. */
    void*               builder_object;         /**< If builder_name is NULL, use this builder object. */
    void*               auto_doc;               /**< automatic transient plmxml::Document if builder_name is non-NULL.
                                                    (Core development use only) */
    char**              user_attributes;        /**< Ask for certain bomline properties to appear in the output file, 
                                                    for "Part" or "Instance". */
    logical             suppress_output;        /**< prevent the normal output from working,
                                                    if you are only interested in the side-effects of the traversal.
                                                    (Core development use only) */
    long                fatal_minor_errors;     /**< By default, minor errors will be handled quietly.
                                                    Set this to -1 to make BOMWriter abort.
                                                    (Minor errors - missing transforms, empty datasets, etc) */
    char*                       transfer_mode;
    BOM_writer_TransformType    transform_type; 
    char**              lang_codes;            /**< language list given by user for bomwriter export with plmxml format */
    int                 number_of_langs;       /**< the number of languages in lang_codes */
    char*               perf_file;             /**< the file which wil contains the performance status of the bomwriter */
    int                 sequence_no;           /**< the sequence no for this bomwriter running */
    char*               assembly_size;         /**< the assembly size for bomwriter export */
    char*               log_file;
} BOM_writer_format_plmxml;

/**
    Flatten's struct needs a forward reference to this union 
*/
typedef union BOM_writer_format_u               BOM_writer_format;

/**
    This filters the tree seen by the subformat, so it appears to be collapsed to a single level
    with the root node as the immediate parent of all presented nodes.

    Currently, only explicitly selected nodes will be presented - no ancestors or descendants,
    but for future expansion, the root node does not know how many children it has,
    and so claims to have -1 children.

    @note You should ask the traversal to suppress descendants,
    or this will run more slowly than it needs to.
*/
typedef struct{
    BOM_writer_struct   struct_type;
    BOM_writer_format*  subformat;
} BOM_writer_format_flatten;

union BOM_writer_format_u{
    BOM_writer_struct           common;
    BOM_writer_format_empty     empty;
    BOM_writer_format_ajt       ajt;
    BOM_writer_format_plmxml    plmxml;
    BOM_writer_format_flatten   flatten;
};

/** @} */

/**
    Flags to control the overall traversal. 
    @note This structure must be initialized by calling #BOM_writer_new_traversal in order to ensure that all members are properly initialized. 
*/
typedef struct{
    BOM_writer_struct   struct_type;
    logical             no_descendants;             /**< [false] - if true, you only want ancestors and selected lines reported */
    int                 selected_count;             /**< Selected_count/selected_lines <br>
                                                                0/NULL     - Default: selects just the root of the bomwindow. <br>
                                                                0/non-NULL - selected_lines must be a #NULLTAG-terminated array. <br>
                                                            non-0/NULL     - undefined behaviour. Don't do this. <br>
                                                            non-0/non-NULL - selected_lines must be an array of tags, of length selected_count.
                                                         
                                                         If you want to select no lines, not even the root line, you must supply a 
                                                         one-element list containing #NULLTAG. 
                                                         You should supply count=1 if you do this, for a marginal speed saving. */
    tag_t*              selected_lines;             /**< selected_count */
    logical             unload_lines;               /**< Try to save memory by partially unloading bomlines during traversal. 
                                                         This may only be used when the BOM Window being traversed is
                                                         used exclusively owned by the caller. References to BOM Lines will become invalid.
                                                         (Note: in v7, this was hard-wired 'true'. In v8, the default is 'false'.) */
    logical             transient_unpack;           /**< Set to true if the traversal should unpack and repack
                                                         bomlines it encounters during traversal. This option adversely affects
                                                         performance and may cause unnecessary display updates;
                                                         its use should be avoided if possible. */
    logical             emit_unselected_ancestors;  /**< Set to true if the traversal should return a list of
                                                         ancestor lines that were emitted without being explicitly requested.
                                                         Undefined behavior with 'flatten'. */
    int                 unselected_ancestors_count; 
    tag_t*              unselected_ancestors;       
    int                 sub_count;                  /**< Sub_count/sub_lines - cause the marking of a subselection of lines in a
                                                         format-defined way. Input behavior is similar to selected_count/lines,
                                                         except that 0/NULL defaults to 'no subselection'.
                                                         @note The behavior is undefined if sub_lines contains lines that
                                                         do not appear in the final output file.
                                                         (Typically, you will observe extraneous subancestors.) */
    tag_t*              sub_lines;                  /**< sub_count */
    int                 filter_by_level;            /**< Filter by level when process BOM. The traverse and process will get stopped at the
                                                         specific level. */
    int                 bomset_max_lines;           /**< Specifies the maximum number of lines that a BOMSet contains during BOM expansion 
                                                         when BOMSet is enabled or used. */
    logical             varuid;                     /**< Value of varuid_on option of PLMXML format, indicates whether loading variant 
                                                         condition for BVRs. */
    logical             revid;                      /**< Value of revid_off option of PLMXML format, indicates whether export item_revision_id 
                                                         of ItemRevision in PRV name attribute. */
    logical             grdvua;                     /**< Value of grdvua_on option of PLMXML format, indicates whether export user attributes 
                                                         for GRDVA in &lt;Instance&gt; element. */
    logical             bulksave_off;               /**< Value of bulksave_off option of PLMXML format, indicates whether enable bulk save for APN generation. */
    logical             window_close_off;           /**< Value of window_close_off option, indicates whether skip BOM window close to save performance. */
} BOM_writer_traversal;

/** @} */

#include <bom/libbom_undef.h>
#endif
