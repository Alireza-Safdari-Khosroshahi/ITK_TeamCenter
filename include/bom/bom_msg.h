/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    BOM specific Message definitions.

    Messages are general actions e.g. save, delete. When a Message is sent to a
    specific Type or instance of a Type, then the Method registered with that
    Message/Type combination will be executed. See ITK documentation on Methods
    for further details.

    Each message has a unique set of parameters, which are defined here. These
    parameters are passed in the varargs list of #METHOD_execute /
    #METHOD_execute_using, and received in the varargs list of
    action functions registered to perform methods.

    Generic system messages, e.g. save, delete are defined in tc_msg.h.
*/

/*  */

#ifndef BOM_MSG_H
#define BOM_MSG_H

#include <bom/libbom_exports.h>

/**
    Function called to evaluate a BOM Window's variant configuration.

    @param[in] logical first_call       Indicates if this is the first time that the function is called

    Registering message for action can be done through BMIDE or method like below to be called when message get invoked:
    @code
    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMWindow", BOM_variant_config_msg, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post{pre}_action_type, eventVariantConfig, NULL);
    }
    @endcode

    Here the function @c eventVariantConfig will invoked and then parameters of this message can be retrieved as below:
    @code
    static int eventVariantConfig ( METHOD_message_t* message, va_list args )
    {
        va_list largs;
        va_copy( largs, args );

        logical first_call = va_arg( largs, int );
        va_end( largs );

        //continue with implementation...
     }
    @endcode
*/
#define BOM_variant_config_msg     "BOM_variant_config"

/**
    Define BOMWindow_save, BOMLine_add and BOMLine_cut message
*/

/**
    Function called to save a BOM Window.

    @param[in] tag_t window_tag     The BOMWindow to save

    Registering message for action can be done through BMIDE or method like below to be called when message get invoked:
    @code
    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMWindow", BOMWindow_save_msg, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post{pre}_action_type, eventBOMWindowSave, NULL);
    }
    @endcode

    Here the function @c eventBOMWindowSave will invoked and then parameters of this message can be retrieved as below:
    @code
    static int eventBOMWindowSave ( METHOD_message_t* message, va_list args )
    {
        va_list largs;
        va_copy( largs, args );

        tag_t window_tag = va_arg( largs, tag_t );
        va_end( largs );

        //continue with implementation...
     }
    @endcode
*/
#define BOMWindow_save_msg    "BOMWindow_save"

/**
    Function called to add BOMLine.

    @param[in] tag_t parent                 The line to which the component is to be added.
    @param[in] tag_t item                   Item to add. It can be #NULLTAG.
    @param[in] tag_t item_revision          Item Revision to add. This is only used if @p pitem is #NULLTAG.
    @param[in] tag_t bom_view               View to use. If #NULLTAG, the default view is used.
    @param[in] char *occurrence_type        The Occurrence type.
    @param[out] tag_t *new_bom_line         The created BOM Line.
    @param[in] tag_t gde                    The General Design Element (GDE) line to add.
    @param[in] tag_t occ_create_input       The create input object for the Occurrence to be created.

    Registering message for action can be done through BMIDE or method like below to be called when message get invoked:
    @code
    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMLine", BOMLine_add_msg, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post{pre}_action_type, eventBOMLineAdd, NULL);
    }
    @endcode
    Here the function @c eventBOMLineAdd will invoked and then parameters of this message can be retrieved as below:
    @code
    static int eventBOMLineAdd ( METHOD_message_t* message, va_list args )
    {
        va_list largs;
        va_copy( largs, args );
        tag_t parent          = va_arg( largs, tag_t );
        tag_t item            = va_arg( largs, tag_t );
        tag_t item_revision   = va_arg( largs, tag_t );
        tag_t bom_view        = va_arg( largs, tag_t );
        char *occurrence_type = va_arg( largs, char* );
        tag_t *new_bom_line   = va_arg( largs, tag_t * );
        tag_t gde             = va_arg( largs, tag_t );
        tag_t occ_create_input = va_arg( largs, tag_t );
        va_end( largs );

        //continue with implementation...
     }
    @endcode
*/
#define BOMLine_add_msg       "BOMLine_add"

/**
    Function called to cut the BOMLine.

    @param[in] tag_t bom_line       The BOMLine to be cut

    Registering message for action can be done through BMIDE or method like below to be called when message get invoked:
    @code
    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMLine", BOMLine_cut_msg, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post{pre}_action_type, eventBOMLineCut, NULL);
    }
    @endcode

    Here the function @c eventBOMLineCut will invoked and then parameters of this message can be retrieved as below:
    @code
    static int eventBOMLineCut ( METHOD_message_t* message, va_list args )
    {
        va_list largs;
        va_copy( largs, args );

        tag_t line_tag = va_arg( largs, tag_t);
        va_end( largs );

        //continue with implementation...
     }
    @endcode
*/
#define BOMLine_cut_msg       "BOMLine_cut"

/**
    This is a no-op function. It is called when duplicating structure completes to duplicate attached diagrams as well.
    <br>Customizers can add their functions as post action to this function.

    @param[in] tag_t   toplineTag              Top level of the structure to duplicate
    @param[in] tag_t   new_item_rev              New top level item rev of the duplicated structure
    @return    ITK_ok on success

    @code

    Registering message for action method to be called when message get invoked:

    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMLine", BOM_duplicate_structure_post_msg, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post_action_type, eventDuplicateStructurePost, NULL);
    }

    Here eventDuplicateStructurePost will invoked and then paranmeters of this message can be retrived as below:

    static int eventDuplicateStructurePost( METHOD_message_t*  m, va_list args)
    {
         va_list largs;
         va_copy( largs, args);

         tag_t toplineTag = va_arg( largs, tag_t);
         tag_t new_item_rev = va_arg( largs, tag_t);

         va_end( largs);

         continue with implementation...
    }
    @endcode

*/
#define BOM_duplicate_structure_post_msg       "BOM__duplicate_structure_post"

/**
    Function called to link the design root BOMLine
    to the root of the Engineering BOMLine (EBOM).

    @param[in] tag_t (EBOM) top line
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ME_design_ebom_disabled if the structures cannot be linked
    <li>#ME_design_ebom_alignment_disabled if publish links exist for top level context
    </ul>

    @code

    Registering message for action can be done through BMIDE or like this method to
    <br>be called when message get invoked:

    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMWindow", BOM_link_design_ebom_roots_msg, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post{pre}_action_type, fnd0Post{pre}LinkRoots, NULL);
    }

    Here fnd0Post{pre}LinkRoots will be invoked and the parameters of this message can be retrived as below:

    //----------------------------------------------------------------------------

    static int fnd0Post{pre}LinkRoots ( METHOD_message_t* message, va_list args )
    {
        va_list largs;
        va_copy( largs, args );

        tag_t ebomRootLine = va_arg( largs, tag_t);

        tag_t designRootLine=NULLTAG;
        METHOD_PROP_MESSAGE_OBJECT(m, designRootLine);
        va_end( largs );

        continue with implementation...
     }
    @endcode
*/
#define BOM_link_design_ebom_roots_msg "BOM_link_design_ebom_roots"

/**
    Function called to link/align the design BOMLine (on which the method is called)
    to the BOMLine representing the Engineering BOM.

    @param[in] tag_t (EBOM) line
    @param[in] int  Link mode  Valid values are: <ul><li>1 for simple link</li><li>2 to assign the design line under the EBOM lin design line under the EBOM line.</li></ul>
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#ME_missing_root_link if the root of the structures are not linked
    <li>#BOM_invalid_data if item revisions cannot be obtained
    <li>#ME_mismatched_design_part_rev if (EBOM) line is already linked to another design.
    </ul>

    @code

    Registering message for action can be done through BMIDE or like this method to
    <br>be called when message get invoked:

    METHOD_id_t method;
    ifail = METHOD_find_method( "BOMWindow", BOM_link_design_to_ebom, &method);
    if( method.id != 0 )
    {
         ifail = METHOD_add_action( method, METHOD_post{pre}_action_type, fnd0Post{pre}LinkDesignEbom, NULL);
    }

    Here fnd0Post{Pre}LinkDesignEbom will invoked and then parameters of this message can be retrived as below:

    //----------------------------------------------------------------------------

    static int fnd0Post{Pre}LinkDesignEbom ( METHOD_message_t* message, va_list args )
    {
        va_list largs;
        va_copy( largs, args );

        tag_t ebomRootLine = va_arg( largs, tag_t);
        int alignMode = va_arg( largs, int );
        va_end( largs );

        tag_t designRootLine=NULLTAG;
        METHOD_PROP_MESSAGE_OBJECT(m, designRootLine);

        continue with implementation...
     }
    @endcode
*/
#define BOM_link_design_to_ebom_msg "BOM_link_design_to_ebom"

#include <bom/libbom_undef.h>

#endif
