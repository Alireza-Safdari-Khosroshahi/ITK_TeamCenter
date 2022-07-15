/*
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2011.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
*/

#ifndef MATERIALMGMT__MATERIALMGMTITK_HXX
#define MATERIALMGMT__MATERIALMGMTITK_HXX

#include <mat1materialmgmt/libmat1materialmgmt_exports.h>
#include <unidefs.h>

#ifdef __cplusplus
    extern "C"{
#endif


/**
    @defgroup MAT1MATERIALMGMT Material Management

    Material Management Module.
    <br>Enables to store material information required for an Original Equipment Manufacturers' (OEMs) part.
    <br>The Material is made of Substances and the relation is established between Material object and Substance(s).The relation stores the composition value of substance in percentage.
    <br>The part stored in Teamcenter as an Item/Item revision is related to the one or many materials that comprise that part. This relation stores the mass of each material and the total mass of material(s) is added up to the total mass of the part.

    @{
*/

/**
    Collects the list of Material and Substances associated with any object.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if the input tag is invalid
    <li>Possibly other errors
    </ul>
*/
extern MAT1MATERIALMGMT_API int MATERIALMGMT_ask_material_and_substances_information(
                        tag_t input_tag,                        /**< (I) Tag of item for which data is required      */
                        int *num_materials,                     /**< (O) Number of materials                         */
                        tag_t** material_information,           /**< (OF) num_materials Array of matInfos            */
                        int *number_substances,                 /**< (O) Number of substances                        */
                        tag_t** substance_information           /**< (OF) number_substances Array of subsInfos          */
                    );

/**
    Collects the list of Material and Substances associated with any object.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p item is #NULLTAG.
    <li>Possibly other errors
    </ul>
    
    @note This ITK returns values array in a packed format.
    <br>The proper way to release the allocated memory is by using #MEM_free on the container alone
*/
extern MAT1MATERIALMGMT_API int MATERIALMGMT_ask_material_and_substances_complete_information(
                        tag_t item,                             /**< (I)  Item for which data is required.
                                                                          <br/>If an invalid tag is specified, empty data structures will be retrieved by the ITK.*/
                        int *num_materials,                     /**< (O)  Number of materials                              */
                        tag_t** material_tag,                   /**< (OF) num_materials Array of materials                 */
                        char*** material_uom,                   /**< (OF) num_materials Array of material Unit Of Measure (UOM). <br/>The array is packed, which means that only the memory is deallocated by only calling #MEM_free on the container itself. */
                        double** material_mass,                 /**< (OF) num_materials Array of material mass             */
                        int *num_substances,                    /**< (O)  Number of substances                             */
                        tag_t** substance_tag,                  /**< (OF) num_substances Array of substances.              */
                        char*** substance_uom,                  /**< (OF) num_substances Array of substance Unit Of Measure (UOM). <br/>The array is packed, which means that the memory is deallocated by only calling #MEM_free on the container itself. */
                        double** substance_minimum_mass,        /**< (OF) num_substances Array of substance Minimum Mass   */
                        double** substance_maximum_mass,        /**< (OF) num_substances Array of substance Maximum Mass   */
                        logical** is_substance_mass_in_range    /**< (OF) num_substances Array of substance Mass in Range  */
                    );


/**
    Collects the list of Materials and Substances associated with any object.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#CXPOM_invalid_tag if @p item is #NULLTAG.
    <li>Possibly other errors
    </ul>
*/
extern MAT1MATERIALMGMT_API int MATERIALMGMT_ask_material_and_substances_complete_information2(
                        tag_t       item,                               /**< (I)  Item for which data is required.
                                                                                  <br/>If no Material is attached to the Item or to any of the Items in its BOM view, empty data structures will be retrieved by the ITK.*/
                        int*        num_materials,                      /**< (O)  Number of materials                              */
                        tag_t**     material_tag,                       /**< (OF) num_materials Array of materials                 */
                        char***     material_uom,                       /**< (OF) num_materials Array of material Unit Of Measure (UOM). <br/>The array is packed, which means that only the memory is deallocated by only calling #MEM_free on the container itself. */
                        double**    material_mass,                      /**< (OF) num_materials Array of material mass             */
                        double**    percent_mat_mass,                   /**< (OF) num_materials Array of percentage of material mass with respect to assembly mass */
                        int*        num_substances,                     /**< (O)  Number of substances                             */
                        tag_t**     substance_tag,                      /**< (OF) num_substances Array of substances.              */
                        char***     substance_uom,                      /**< (OF) num_substances Array of substance Unit Of Measure (UOM). <br/>The array is packed, which means that the memory is deallocated by only calling #MEM_free on the container itself. */
                        double**    substance_minimum_mass,             /**< (OF) num_substances Array of substance Minimum Mass   */
                        double**    substance_maximum_mass,             /**< (OF) num_substances Array of substance Maximum Mass   */
                        logical**   is_substance_mass_in_range,         /**< (OF) num_substances Array of substance Mass in Range  */
                        double**    percent_subs_mass,                  /**< (OF) num_substances Array of percentage of substance mass with respect to assembly mass */
                        double*     assembly_mass                       /**< (O) Total assembly mass */
                    );

/**
    Exports the selected materials into a MATML file.
    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#MATERIALMGMT_no_materials_selected_for_export if @p the materials input parameter is empty
    <li>Possibly other errors
    </ul>
*/
extern MAT1MATERIALMGMT_API int MATERIALMGMT_export_materials_into_matml(
                        const char* export_filter,            /**< (I)  Export filter or the unique key that could be retrieved from the preference IMM_EXPORT_FILTER. <br/>If the preference does not contain the key then no transformation will be applied to the generated MATML */
                        int n_materials,                      /**< (I)  Number of materials to export */
                        const tag_t* materials,               /**< (I)  n_materials Material to be exported. */
                        const char* matml_file_name,          /**< (I)  Name of the MATML file where the information will be exported. <br/>If NULL or an empty string is provided, the name used will be a concatenation of export_filter and _materials.xml. */
                        tag_t* matml_file,                    /**< (O)  Generated MATML xml file.         */
                        tag_t* export_log_file                /**< (O)  Log file of the export operation. */
                    );


/** @} */
#ifdef __cplusplus
}
#endif

#include <mat1materialmgmt/libmat1materialmgmt_undef.h>

#endif
