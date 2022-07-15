/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2020.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
@file

Contains declarations of the publish APIs of Product Master Automation.
*/

#ifndef PMA0_AUTOMATION_H
#define PMA0_AUTOMATION_H

#include <unidefs.h>

#include <Pma0automation/libpma0automation_exports.h>

/**
@defgroup PMA0AUTOMATION Product Master Automation
<br/>This module contains the declaration of APIs used during generation/updation of Engineering BOM from Design BOM and vice-versa.
<br/>The term "Source" refers to the input structure and "Target" refers to the output structure.
<br/>ex. For generating Engineerig BOM from a Design BOM, Design BOM is the source structure and Engineering BOM is the target structure.

<br/>This process involves creating target items and target structure.
<br/>While generating a target Item corresponding to a source Item, Find or Create of target item is performed.
<ul>
<li>If the target item is found, the same is used n the target structure
<li>If the target item is NOT found, a new target item is created.
</ul>
<br/>The OOTB find logic is based on Part Design alignment
<br/>The OOTB create logic uses the prefix/suffix specified in the preferences @c Pma0_EBOM_Prefix_Suffix
<br/>and @c Pma0_DBOM_Prefix_Suffix to set @c item_id, @c object_name properties on target Item CreateInput.
<br/>In addition, @c object_desc property is copied on the target Item CreateInput.
<br/>
<br/>The above OOTB Find or create logic is customizable using following 2 User Exits.
<ul>
<li>@c BMF_Pma0_find_target_items_for_sources -
<br/>User Exit for customizing the target Item Find behavior.
<li>@c BMF_Pma0_populate_target_item_creI_for_sources -
<br/>User Exit for customizing the target Item Create behavior.
</ul>
<br/>These User Exits are invoked from both the ITKs - #PMA0_generate_engineering_bom, #PMA0_generate_design_bom.
<br/>
<br/>For more details about Find or Create customization follow the below documentation.

<br/><b>Find:</b>
<ul>
<li>When this User Exit is not overridden, system finds the target ITEMs based on Part-Design alignment.
<li>This User Exit should be overridden for custom ITEM types when an existing ITEM need to be re-used using business logic other than Part-Design alignment.

@note To override the User Exit, attach the extension to BO operation BMF_Pma0_find_target_items_for_sources on source Item.
        The arguments of the extension should exactly match the arguments of this User Exit.

<li>The output map should contain only the valid target ITEMs found against sources. Sources for which target is NOT found should NOT be returned in output map.
</ul>

@code
int CustomPartType::Custom_find_parts( METHOD_message_t *, va_list args )
{
    int iFail = ITK_ok;
    try
    {
        va_list  largs;
        va_copy(largs, args);

        const tag_t pSrcDesignType = static_cast<const tag_t>(va_arg(largs, void *));

        //In this example, we want the custom find logic to be executed for Designs of type "CustomDesign"
        scoped_smptr<char> srcDesignTypeName;
        rs = TCTYPE_ask_name2(pSrcDesignType, &srcDesignTypeName);
        if (std::string(srcDesignTypeName.getString()) != "CustomDesign")
        {
            //Following error must be added to error stack and returned,
            //when we do not want to proceed with the custom logic.
            int ifail = PMA0AUTOMATION_user_exit_skip_execution;
            ERROR_store(ERROR_severity_error, ifail);
            return ifail;
        }

        const std::vector<tag_t> * pSrcDesignLines = static_cast<const std::vector<tag_t>*>( va_arg( largs, void * ) );
        std::map<tag_t, tag_t > * pSrcDsgnLineToFoundPart = static_cast<std::map<tag_t, tag_t> *>( va_arg( largs, void * ) );
        va_end( largs );
        for( auto srcLine : *pSrcDesignLines )
        {
            tag_t foundPart = NULLTAG;
            //Custom find logic based on srcLine
            if( found )
            {
                ( *pSrcDsgnLineToFoundPart ).insert( { srcLine,foundPart } );
            }
        }
    }
}
@endcode








<br/><b>Create:</b>
<ul>
<li>When the User Exit is not overridden, system creates the target ITEMs using default createInput.
<li>This User Exit should be overridden for custom ITEM types when the custom ITEM type has mandatory properties to be populated from @p source_lines.

@note To override the User Exit, attach the extension to BO operation BMF_Pma0_find_target_items_for_sources on source Item.
        The arguments of the extension should exactly match the arguments of this User Exit.

<li>The output map contains the target item createInputs against sources. All the input sources should have a corresponding target createInput.
</ul>
@code
int CustomPartType::Custom_populate_creI_for_parts( METHOD_message_t *, va_list args )
{
    int iFail = ITK_ok;
    try
    {
        va_list  largs;
        va_copy( largs, args );

        const tag_t pSrcDesignType = static_cast<const tag_t>(va_arg(largs, void *));

        //In this example, we want the custom find logic to be executed for Designs of type "CustomDesign"
        scoped_smptr<char> srcDesignTypeName;
        rs = TCTYPE_ask_name2(pSrcDesignType, &srcDesignTypeName);
        if (std::string(srcDesignTypeName.getString()) != "CustomDesign")
        {
            //Following error must be added to error stack and returned,
            //when we do not want to proceed with the custom logic.
            int ifail = PMA0AUTOMATION_user_exit_skip_execution;
            ERROR_store(ERROR_severity_error, ifail);
            return ifail;
        }
        const std::vector<tag_t> * pSrcDesignLines = static_cast<const std::vector<tag_t>*>( va_arg( largs, void * ) );
        std::map<tag_t, tag_t > * pSrcDsgnLineToPartCreI = static_cast<std::map<tag_t, tag_t> *>( va_arg( largs, void * ) );
        va_end( largs );
        for( auto srcLine : *pSrcDesignLines )
        {
            tag_t partCreInput = NULLTAG;
            //populate createInput of the target type for mandatory properties to be derived from srcLine
            ( *pSrcDsgnLineToPartCreI ).insert( { srcLine,partCreInput } );
        }
    }
}
@endcode
@{
*/

#ifdef __cplusplus
extern "C"
{
#endif

    /**
        Generates an Engineering BOM structure corresponding to the input design sources.
        @note The following preferences must be appropriately set prior to calling this ITK:
        <ul>
        <li>@c Pma0_EBOM_Prefix_Suffix
        <li>@c Pma0_DBOM_skip_node_conditions
        <li>@c Pma0_DBOM_skip_occurrence_conditions
        <li>@c Pma0_Part_Design_Type
        <li>@c Pma0_EBOMRoot_DBOMRoot_Type
        <li>@c Pma0_ChildItemType_RevOccType
        </ul>

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>#PF_INVALID if value provided for the preference @c Pma0_EBOM_Prefix_Suffix, @c Pma0_EBOM_skip_node_conditions, @c Pma0_DBOM_skip_occurrence_conditions, @c Pma0_Part_Design_Type, @c Pma0_EBOMRoot_DBOMRoot_Type, @c Pma0_ChildItemType_RevOccType  is invalid.
        <li>#PMA0AUTOMATION_input_root_skipped if the Engineering BOM structure cannot be generated for the input @p dbom_source, because it is configured to be skipped (through preference @c Pma0_skip_node_conditions) and it does not contain any unskipped parent.
        <li>#PMA0AUTOMATION_invalid_part_or_design if the Part object for source object Design  @p dbom_sources was not created because it is not a valid type. The supported type is Design.
        <li>#PMA0AUTOMATION_no_item_rev if the Engineering BOM top line is unconfigured.
        <li>#AOM_inst_read_protected if there is no read access or revision not configured on topline
        <li>#AOM_inst_write_protected if current logged in user have no write access on target BOM Line in drag drop.
        <li>#PMA0AUTOMATION_nodes_not_processed if the engineering node creation fails or if the engineering node and design node linking/alignment fails.
        <li>#PMA0AUTOMATION_invalid_source_selection if the root design node is drag-dropped which is a representation of product.
        <li>#PMA0AUTOMATION_target_node_skipped if the root target node is configured to be skipped.
        </ul>
    */
    extern PMA0AUTOMATION_API int PMA0_generate_engineering_bom(
        tag_t          dbom_source,              /**< (I) Design BOM source BOMLine */
        logical        is_part_ebom,             /**< (I) Specifies whether to create a Engineering BOM root item as part or product. It is required when @p ebom_target is #NULLTAG. */
        tag_t*         ebom_target               /**< (O)Top line of the generated engineering BOM.*/
    );

    /**
        Generates a Design BOM structure corresponding to the input part sources.
        @note The following preferences must be appropriately set prior to calling this ITK:
        <ul>
        <li>@c Pma0_DBOM_Prefix_Suffix
        <li>@c Pma0_EBOM_skip_node_conditions
        <li>@c Pma0_EBOM_skip_occurrence_conditions
        <li>@c Pma0_Part_Design_Type
        <li>@c Pma0_EBOMRoot_DBOMRoot_Type
        </ul>

        @returns
        <ul>
        <li>#ITK_ok on success.
        <li>#PF_INVALID if value provided for the preference @c Pma0_DBOM_Prefix_Suffix, @c Pma0_DBOM_skip_node_conditions, @c Pma0_EBOM_skip_occurrence_conditions, @c Pma0_Part_Design_Type, @c Pma0_EBOMRoot_DBOMRoot_Type, @c Pma0_ChildItemType_RevOccType is invalid.
        <li>#PMA0AUTOMATION_input_root_skipped if the Design BOM structure cannot be generated for the input @p ebom_source, because it is configured to be skipped (through preference @c Pma0_skip_node_conditions) and it does not contain any unskipped parent.
        <li>#PMA0AUTOMATION_invalid_part_or_design if the Design object for source object Part was not created because it is not a valid type. The supported type is Part.
        <li>#PMA0AUTOMATION_no_item_rev if the Design BOM top line is unconfigured.
        <li>#AOM_inst_read_protected if there is no read access or revision not configured on topline
        <li>#AOM_inst_write_protected if current logged in user have no write access on target BOM Line in drag drop.
        <li>#PMA0AUTOMATION_nodes_not_processed if the design node creation fails or if the engineering node and design node linking/alignment fails.
        <li>#PMA0AUTOMATION_invalid_source_selection if the product is drag-dropped on a design node.
        <li>#PMA0AUTOMATION_target_node_skipped if the root target node is configured to be skipped.
        </ul>
    */
    extern PMA0AUTOMATION_API int PMA0_generate_design_bom(
        tag_t          ebom_source,             /**< (I) Engineering BOM source BOMLine */
        tag_t*         dbom_target              /**< (O)Top line of the generated design BOM.*/
    );

    /**
        Updates the engineering BOM structure linked to the design BOM structure starting from a given design top line.
        <br/>The engineering structure is updated as per the default action specified on the design BOMLine property @c pma0UpdateAction.
        @note The following preferences must be appropriately set prior to calling this ITK:
        <ul>
        <li>@c Pma0_EBOM_Prefix_Suffix
        <li>@c Pma0_DBOM_skip_node_conditions
        <li>@c Pma0_DBOM_skip_occurrence_conditions
        <li>@c Pma0_Part_Design_Type
        <li>@c Pma0_EBOMRoot_DBOMRoot_Type
        <li>@c Pma0_ChildItemType_RevOccType
        </ul>

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#PF_INVALID if value provided for the preference @c Pma0_DBOM_Prefix_Suffix, @c Pma0_DBOM_skip_node_conditions, @c Pma0_Part_Design_Type, @c Pma0_EBOMRoot_DBOMRoot_Type, @c Pma0_ChildItemType_RevOccType is invalid.
        <li>#PMA0AUTOMATION_input_root_skipped if the Engineering BOM structure cannot be updated for the input @p dbom_source, because it is configured to be skipped (through preference @c Pma0_skip_node_conditions) and it does not contain any unskipped parent.
        <li>#PMA0AUTOMATION_no_item_rev if the Design BOM top line is unconfigured.
        <li>#PMA0AUTOMATION_invalid_part_or_design if the Part object for source object Design  @p dbom_source was not created because it is not a valid type. The supported type is Design.
        <li>#AOM_inst_read_protected if there is no read access or revision not configured on topline
        <li>#AOM_inst_write_protected if current logged in user have no write access on Engineering BOM Line.
        <li>Possibly other errors.
        </ul>
    */
    extern PMA0AUTOMATION_API int PMA0_update_engineering_bom(
        tag_t             dbom_source,                    /**< (I) Top BOMLine of design BOM structure.*/
        tag_t*            ebom_updated_target             /**< (O) Top BOMLine in updated engineering BOM structure*/
    );


    /**
        Updates the design BOM structure linked to the engineering BOM structure starting from a given engineering top line.
        <br/>The design structure is updated as per the default action specified on the engineering BOMLine property @c pma0UpdateAction.
        @note The following preferences must be appropriately set prior to calling this ITK:
        <ul>
        <li>@c Pma0_DBOM_Prefix_Suffix
        <li>@c Pma0_EBOM_skip_node_conditions
        <li>@c Pma0_EBOM_skip_occurrence_conditions
        <li>@c Pma0_Part_Design_Type
        <li>@c Pma0_EBOMRoot_DBOMRoot_Type
        </ul>

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#PF_INVALID if value provided for the preference @c Pma0_DBOM_Prefix_Suffix, @c Pma0_DBOM_skip_node_conditions, @c Pma0_Part_Design_Type, @c Pma0_EBOMRoot_DBOMRoot_Type, @c Pma0_ChildItemType_RevOccType is invalid.
        <li>#PMA0AUTOMATION_input_root_skipped if the Design BOM structure cannot be updated for the input @p ebom_source, because it is configured to be skipped (through preference @c Pma0_skip_node_conditions) and it does not contain any unskipped parent.
        <li>#PMA0AUTOMATION_no_item_rev if the Engineering BOM top line is unconfigured.
        <li>#PMA0AUTOMATION_invalid_part_or_design if the Design object for source object Part @p dbom_source was not created because it is not a valid type. The supported type is Part.
        <li>#AOM_inst_read_protected if there is no read access or revision not configured on topline
        <li>#AOM_inst_write_protected if current logged in user have no write access on Design BOM Line.
        <li>Possibly other errors.
        </ul>
    */
    extern PMA0AUTOMATION_API int PMA0_update_design_bom(
        tag_t             ebom_source,                      /**< (I) Top BOMLine of engineering BOM structure.*/
        tag_t*            dbom_updated_target               /**< (O) Top BOMLine in updated design BOM structure*/
    );

#ifdef __cplusplus
}
#endif
/**
@}
*/

#include <Pma0automation/libpma0automation_undef.h>
#endif
#pragma once
