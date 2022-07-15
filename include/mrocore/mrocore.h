/*==============================================================================
                Copyright (c) 2008 Siemens PLM Software
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    MRO module.
*/

#ifndef MROCORE_H
#define MROCORE_H

#include <unidefs.h>
#include <mrocore/libmrocore_exports.h>

#define MRO_srlnum_max_len                         128
#define MRO_form_name_len                          128
#define MRO_physical_quantity_one                  1.0

#define MEMFREE( ptr)   {                   \
                            MEM_free( ptr); \
                            ptr = NULL;     \
                        }

#define FREE_CREATEINPUT( ptr)  {                                                                           \
                                    Teamcenter::BusinessObjectRegistry::instance().deleteInputObject( ptr); \
                                    ptr = NULL;                                                             \
                                }
#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup MROCORE MRO Core

    The MRO Core (MROCore) module implements the basic set of classes and behaviour
    for As-Built module.

    @{
*/

/**
    Initializes the mrocore module. You must call this function before calling any other MROCORE functions.
*/
extern MROCORE_API int MROCORE_init_module();

/**
    This structure is used to pass on the parameters for Physical Part Creation.
*/
typedef struct MROCORE_API PhysicalPartParams
{
    char*    partNumber;         /**< Item Id of Neutral Part */
    char*    description;        /**< Item Name of Neutral Part */
    char*    serialNumber;       /**< Serial Number */
    char*    lotNumber;          /**< Lot Number */
    char*    manufacturerId;     /**< Manufacturer Id */
    char*    usageName;          /**< Usage Name */
    date_t   installationDate;   /**< Installation Date of Physical Part */
    date_t   manufactureDate;    /**< Manufacturer Date of Physical Part */
    logical  isSerialized;       /**< Is Serialized flag */
    logical  isLot;              /**< Is Lot flag */
    logical  isConsumable;       /**< Is Consumable flag */
    logical  isRotable;          /**< Is Rotable flag */
    logical  lifeLimited;        /**< Life Limited flag */
    logical  isPartAsBuilt;      /**< Is AsBuilt flag for physical part */
    double   physicalQuantity;   /**< Physical Part Quantity */
    char*    physicalItemId;     /**< Physical Part Id*/
}PhysicalPartParams;

/**
    This structure is used to pass on the parameters for Generate Physical Structure action.
*/
typedef struct MROCORE_API GenerateStructureParams
{
    char*       partNumber;         /**< Item Id of Neutral Part */
    char*       serialNumber;       /**< Serial Number */
    char*       lotNumber;          /**< Lot Number */
    char*       manufacturerId;     /**< Manufacturer Id */
    char*       structureContext;   /**< Structure Context Name */
    date_t      installationDate;   /**< Installation Date of Physical Part */
    date_t      manufactureDate;    /**< Manufacturer Date of Physical Part */
    logical     useSrlNoGen;        /**< Use Serial Number Generator flag */
    int         numberOfLevels;     /**< Number of Levels for Structure Generation */
    double      physicalQuantity;   /**< Physical Part Quantity */
}GenerateStructureParams;

/**
    This structure is used to pass on the parameters for Duplicate Physical Structure action.
*/
typedef struct MROCORE_API DuplicatePhysStructParams
{
    char*     serialNumber;                 /**< Serial Number */
    char*     lotNumber;                    /**< Lot Number */
    char*     manufacturerId;               /**< Manufacturer Id */
    char*     locationName;                 /**< Location Name */
    char*     dispositionType;              /**< Disposition Type */
    tag_t     dispositionTag;               /**< Disposition Tag*/
    date_t    installationDate;             /**< Installation Date of Physical Part */
    date_t    manufacturingDate;            /**< Manufacturer Date of Physical Part */
    logical   useSrlNoGen;                  /**< Use Serial Number Generator flag */
    logical   propagateDisposition;         /**< Flag to indicate if the Disposition is to be propagated to children*/
    int       numberOfLevels;               /**< Number of Levels for Structure Generation */
}DuplicatePhysStructParams;

/**
    This structure is used to pass on the parameters for Installing Physical Part.
*/
typedef struct MROCORE_API InstallPartParams
{
    char*   usageName;              /**< Usage Name */
    date_t  installationDate;       /**< Installtion Date of Physical Part */
}InstallPartParams;

/**
    This structure is used to pass on the parameters for Record utilization action.
*/
typedef struct MROCORE_API MROCORE_characteristics_data_s
{
    tag_t       charDef;                            /**< Tag of Characteristics Definition */
    double      value;                              /**< Value for the Characteristic */
    date_t      dateValue;                          /**< Date Value for the Characteristic */
}MROCORE_characteristics_data_s;

/**
    Contains information of a characteristic value for recording and invalidating part utilization.
*/
typedef struct MROCORE_API MROCORE_characteristics_value_data_s
{
    tag_t       characteristicDefinition;           /**< Recorded or invalidated CharacteristicDefinition object */
    tag_t       characteristicValue;                /**< The CharacteristicValue object which is being invalidated. If record is new, set it to NULL */
    double      doubleValue;                        /**< Numeric charecteristic value to be recorded for the part. It is considered if CharacteristicDefinition is for numeric value. */
    logical     isDoubleValueNull;                  /**< If true, doubleValue is considered as null; otherwise, the doubleValue is used. */
    date_t      dateValue;                          /**< Date charecteristic value to be recorded for the part. It may be different than current date. It is considered if CharacteristicDefinition is for date value. */
    char*       capturedBy;                         /**< Name of the user that captured/invalidated the characteristic value */
} MROCORE_characteristics_value_data_s;

/**
Contains information of a characteristic value of type boolean and string for recording and invalidating part utilization.
*/
typedef struct MROCORE_API MROCORE_char_values_with_bool_string_data_s
{
    tag_t       characteristicDefinition;           /**< Recorded or invalidated CharacteristicDefinition object */
    tag_t       characteristicValue;                /**< The CharacteristicValue object which is being invalidated. If record is new, set it to NULL */
    double      doubleValue;                        /**< Numeric charecteristic value to be recorded for the part. It is considered if CharacteristicDefinition is for numeric value. */
    logical     isValueNull;                        /**< If true, doubleValue/boolValue/stringValue is considered as null; else, the doubleValues/boolValue/stringValues are used.     */
    date_t      dateValue;                          /**< Date charecteristic value to be recorded for the part. It may be different than current date. It is considered if CharacteristicDefinition is for date value. */
    char*       capturedBy;                         /**< Name of the user that captured/invalidated the characteristic value */
    logical     boolValue;                          /**< Boolean Characteristic value to be recorded for the part. It is considered if CharacteristicDefinition is of Boolean type.*/
    char*       stringValue;                        /**< String Characteristic value to be recorded for the part. It is considered if CharacteristicDefinition is of String type.*/
} MROCORE_char_values_with_bool_string_data_s;


/**
    This structure is used to pass on the parameters for Record utilization action.
*/
typedef struct MROCORE_API MROCORE_utilization_data_s
{
    char*                       description;        /**< Description */
    date_t                      recordingTime;      /**< Recorded at */
    char*                       capturedBy;         /**< Captured by */
    logical                     propagate;          /**< Boolean to indicate Propagate the value to child physical part */
}MROCORE_utilization_data_s;

/**
    Contains information of log entry for a part.
*/
typedef struct MROCORE_API MROCORE_utilization_entry_data_s
{
    tag_t                       logEntry;           /**< The LogEntry object against which a record is being invalidated. If record is new, set it to NULL. */
    char*                       logEntryDesc;       /**< The description for LogEntry. Ignored in case of invalidation.  */
    date_t                      recordedAt;         /**< The time at which utilization is recorded. Ignored in case of invalidation */
    char*                       capturedBy;         /**< Name of the person who captured the characteristic value on the part. It may not be a TC user. */
    logical                     propagate;          /**< Whether the CharacteristicValue is to be propagated to child PhysicalPart objects. If true, the value is propagated. In case of invalidation, if propagate is true for existing characterstic value then it is ignored. */
}MROCORE_utilization_entry_data_s;


/**
    This structure is used to pass on the parameters for Record utilization action.
*/
typedef struct MROCORE_API MROCORE_timesince_values_s
{
    double                     value;              /**< Calculated value*/
    date_t                     dateValue;          /**< Calculated date value*/
    date_t                     lastDate;           /**< Last Utilization Date*/
}MROCORE_timesince_values_s;

/**
    This structure is used to pass on the parameters for Record utilization action.
*/
typedef struct MROCORE_API MROCORE_utilization_timesince_values_s
{
    double                     value;              /**< Calculated value*/
    date_t                     dateValue;          /**< Calculated date value*/
    date_t                     lastDate;           /**< Last Utilization Date*/
    logical                    lastBooleanValue;   /**< Last Boolean Value*/
    char                       *lastStringValue;   /**< Last String Value*/
}MROCORE_utilization_timesince_values_t;


/**
   Sets Installation Date on Physical Structure
*/
extern MROCORE_API int MROCORE_set_relation_install_date(
    tag_t         relation,     /**< (I) Tag of Physical Structure Relation */
    date_t        date          /**< (I) Installtion Date */
    );

/**
   Retrieves the Installation Date from Physical Structure
*/
extern MROCORE_API int MROCORE_ask_relation_install_date(
    tag_t         relation,     /**< (I) Tag of Physical Structure Relation */
    char**        date_string   /**< (O) Installtion Date */
    );

/**
    Sets the Serial Number on Physical Part Revision
*/
extern MROCORE_API int MROCORE_set_physpartrev_serial_number(
    tag_t         physRev,      /**< (I) Tag of Physical Part Revision */
    char*         serialNumber  /**< (I) Serial Number */
    );

/**
    Sets the Physical Part Unique Identifier
*/
extern MROCORE_API int MROCORE_set_physpart_uid(
    tag_t         physPart,     /**< (I) Tag of Physical Part */
    char*         physicalUID   /**< (I) Physical Part Unique Identifier */
    );

/**
   Sets the Manufacturer Id on Physical Part Revision
*/
extern MROCORE_API int MROCORE_set_physpartrev_mfg_id(
    tag_t         physRev,      /**< (I) Tag of Physical Part Revision */
    char*         mfgId         /**< (I) Manufacturer id */
    );

/**
    Sets the Manufacture Date on Physical Part
*/
extern MROCORE_API int MROCORE_set_physpart_mfg_date(
    tag_t         physPart,     /**< (I) Tag of Physical Part */
    date_t        date_string   /**< (I) Manufacture date */
    );

/**
   Sets the Part Used Is value on Physical Structure
*/
extern MROCORE_API int MROCORE_set_relation_part_used_is(
    tag_t         relation,     /**< (I) Tag of Physical Structure Relation */
    char*         partUsedIs    /**< (I) Part Used Is value */
    );

/**
    Retrieves the Part Used Is value from Physical Structure
*/
extern MROCORE_API int MROCORE_ask_relation_part_used_is(
    tag_t         relation,     /**< (I) Tag of Physical Structure Relation */
    char**        partUsedIs    /**< (O) Part Used Is value */
    );

/**
    Creates MRO BOM Window
*/
extern MROCORE_API int MROCORE_create_window(
    tag_t*         window       /**< (O) Tag of MRO BOM Window */
    );

/**
    Sets the top line in MRO BOM Window
*/
extern MROCORE_API int MROCORE_set_window_top_line(
    tag_t          window,                 /**< (I) Tag of MRO BOM Window */
    tag_t          item,                   /**< (I) Tag of Item */
    tag_t          itemRev,                /**< (I) Tag of Item Revision */
    tag_t          bomView,                /**< (I) Tag of BOM View */
    tag_t*         top_bom_line            /**< (O) Tag of Top BOM Line */
    );

/**
    Sets up deviation for Physical Part installation
*/
extern MROCORE_API int MROCORE_setup_deviation(
    tag_t                       inParentPhysicalPart,        /**< (I) Parent Physical Part on which deviation need to be set*/
    tag_t                       childPhysicalPart,           /**< (I) Child Physical Part for which deviation need to be set*/
    tag_t                       selDocument,                 /**< (I) Selected Deviation Documnet, can be empty*/
    tag_t*                      allowedDeviation             /**< (O) Created Allowed Deviation */
    );

/**
    Sets Part Used Is value on Physical Structure Relation
*/
extern MROCORE_API int MROCORE_update_relation_part_used_is2(
    tag_t                       physRev,            /**< (I) Tag of Physical Part Revision */
    tag_t                       itemRev             /**< (I) Tag of Neutral Item Revision */
    );

/**
    Sets the Occurrence Name
*/
extern MROCORE_API int MROCORE_name_occurrence(
    tag_t                       neutralBOMLine,  /**< (I) Tag of Neutal BOM Line */
    char*                       selectedPattern  /**< (I) Selected Pattern */
    );

/**
    Rebases the Physical Part to Neutral Part
*/
extern MROCORE_API int MROCORE_rebase_physical_part(
    tag_t                       physicalBOMLine,        /**< (I) Tag of Physical BOM Line */
    tag_t                       neutralBOMLine,         /**< (I) Tag of Neutal BOM Line */
    date_t                      rebaseDate,             /**< (I) Rebase Date */
    const char*                 structureContext        /**< (I) Structure Context Name */
    );

/**
    Displays utilization
*/
extern MROCORE_API int MROCORE_display_utilization(
    tag_t       physPart,                       /**< (I)  Physical Part Tag */
    date_t      tillDate,                       /**< (I)  Utilization till date*/
    int         *utilizationCount,              /**< (O)  Number of utilization objects. */
    tag_t**     utilizationList                 /**< (OF) List of Utilization*/
    );

/**
    Records utilization
*/
extern MROCORE_API int MROCORE_record_utilization(
    tag_t                           physBOMLine,        /**< (I) Physical BOMLine Tag*/
    tag_t                           logBook,            /**< (I) Log Book Tag*/
    MROCORE_utilization_data_s      in_param,           /**< (I) Contains the utilization data to record for physical part*/
    MROCORE_characteristics_data_s  *charValueParams,   /**< (I) List containing the Characteristics value for physical part*/
    int                             count,              /**< (I) Number of Characteristic values for physical part*/
    tag_t*                          logEntry            /**< (O) Log Entry Tag */
    );

/**
    Records and invalidates utilization for a part
    <br/>Utilization can be recorded/invalidated for the characteristics definition associated to neutral Item from which the physical part is realized.
    <br/>Record will create a new log entry and characteristic value. 
    <br/>Invalidate will set existing characteristic value as invalid and record new characteristic value for the same log entry.
    <br/>The invalidation is restrictied to the users as defined in access manager rule by admin in teamcenter.

    @returns
    <ul>
        <li>#ITK_ok on success
        <li>#MROCORE_utilization_on_invalid_object_type if input object is non PhysicalBOMLine (Physical BOM Line).
        <li>#MROCORE_creation_of_some_characteristics_failed if record failed for some Characteristic Values in a Log Entry.
    </ul>
*/
extern MROCORE_API int MROCORE_record_invalidate_utilization(
    const tag_t                                       physicalPart,           /**< (I)  The physical part for which utilization is recorded/invalidated. The valid object type is PhysicalBOMLine. */
    const tag_t                                       logBook,                /**< (I)  The LogBook object for which utlization entry is to be recorded. */
    const MROCORE_utilization_entry_data_s            logEntryParam,          /**< (I)  Contains the utilization data to record for physical part*/
    const int                                         charValueParamsCount,   /**< (I)  Number of Characteristic values for physical part*/
    const MROCORE_characteristics_value_data_s        *charValueParams,       /**< (I)  charValueParamsCount The Characteristics values for physical part*/
    tag_t*                                            logEntry,               /**< (O)  Created or invalidated LogEntry object. */
    int*                                              charValuesTagListCount, /**< (O)  Number of Characteristic Values created */
    tag_t**                                           charValuesTagList       /**< (OF) charValuesTagListCount Characteristic Values created */
    );

/**
Records and invalidates utilization for a part
<br/>Utilization can be recorded/invalidated for the characteristics definition associated to neutral Item from which the physical part is realized.
<br/>Record will create a new log entry and characteristic value.
<br/>Invalidate will set existing characteristic value as invalid and record new characteristic value for the same log entry.
<br/>The invalidation is restrictied to the users as defined in access manager rule by admin in teamcenter.
<br/>This ITK will also record string and boolean characteristics.

@returns
<ul>
<li>#ITK_ok on success
<li>#MROCORE_utilization_on_invalid_object_type if input object is non PhysicalBOMLine (Physical BOM Line).
<li>#MROCORE_creation_of_some_characteristics_failed if record failed for some Characteristic Values in a Log Entry.
</ul>
*/
extern MROCORE_API int MROCORE_record_and_invalidate_utilization(
    const tag_t                                                 physical_Part,           /**< (I)  The physical part for which utilization is recorded/invalidated. The valid object type is PhysicalBOMLine. */
    const tag_t                                                 log_Book,                /**< (I)  The LogBook object for which utlization entry is to be recorded. */
    const MROCORE_utilization_entry_data_s                     *logEntry_Param,          /**< (I)  Contains the utilization data to record for physical part*/
    const int                                                   n_params,                /**< (I)  Number of Characteristic values for physical part*/
    const MROCORE_char_values_with_bool_string_data_s           *charValueParams,        /**< (I)  charValueParamsCount The Characteristics values for physical part*/
    tag_t*                                                      logEntry,                /**< (O)  Created or invalidated LogEntry object. */
    int*                                                        n_values ,               /**< (O)  Number of Characteristic Values created */
    tag_t**                                                     values                   /**< (OF) charValuesTagListCount Characteristic Values created */
    );


/**
    Calculates Time Since
*/
extern MROCORE_API int MROCORE_calculate_time_between(
    tag_t           item,         /**< (I) Item */
    tag_t           charDef,      /**< (I) Characteristic Definition */
    date_t          fromDate,     /**< (I) Time From (NULL allowed) */
    date_t          toDate,       /**< (I) Time To   (NULL allowed) */
    double          *value,       /**< (O) Calculated Value */
    date_t          *dateValue    /**< (O) Calculated Date Value */
    );

/**
    Calculates Time Since
*/
extern MROCORE_API int MROCORE_calculate_time_between2(
    tag_t                       item,         /**< (I) Item */
    tag_t                       charDef,      /**< (I) Characteristic Definition */
    date_t                      fromDate,     /**< (I) Time From (NULL allowed) */
    date_t                      toDate,       /**< (I) Time To   (NULL allowed) */
    MROCORE_timesince_values_s  *output       /**< (O) Calculated Value Structure*/
    );

/**
Calculates Time Since With String and Boolean Characteristics

@returns
<ul>
<li>#ITK_ok on success
</ul>
*/
extern MROCORE_API int MROCORE_calculate_time_between3(
    tag_t                                   item,          /**< (I) Item */
    tag_t                                   char_def,      /**< (I) Characteristic Definition */
    date_t                                  from_date,     /**< (I) Time From (NULL allowed) */
    date_t                                  to_date,       /**< (I) Time To   (NULL allowed) */
    MROCORE_utilization_timesince_values_t  *output        /**< (O) Calculated Value Structure*/
    );

/**
    Retrieves the first Physical Element revision
*/
extern MROCORE_API int MROCORE_get_first_physical_element_revision(
    tag_t   physPart,           /**< (I) Tag of Physical Element or Physical Element Revision */
    tag_t*  PhysPartRev         /**< (O) Tag of first Physical Element Revision */
    );

/**
    Retrieves the latest Physical Element revision
*/
extern MROCORE_API int MROCORE_get_latest_physical_element_revision(
    tag_t   physPart,         /**< (I) Tag of Physical Element or Physical Element Revision */
    tag_t*  PhysPartRev       /**< (O) Tag of latest Physical Element Revision */
    );


/**
    Retrieves the Part Logistics Form attached to a Neutral Item
*/
extern MROCORE_API int MROCORE_get_related_part_logistics_form(
    tag_t   neutralItem,          /**< (I) Tag of Neutral Item */
    tag_t*  partLogisticsForm     /**< (O) Tag of Part Logistics Form */
    );

/**
    Renames the physical part
*/
extern MROCORE_API int MROCORE_rename_physical_part(
    tag_t   physBOMLine ,         /**< (I) Tag of Physical BOM Line*/
    tag_t   physPartRev ,         /**< (I) Tag of Physical Part Revision*/
    char*   newPartNumber,        /**< (I) New Part Number*/
    char*   newSerialNumber,      /**< (I) New Serial Number*/
    date_t  renameDate,           /**< (I) Rename Date*/
    tag_t*  newPhysPartRev        /**< (O) Tag of new Physical Part Revision*/
    );

/**
    Renames the physical part
*/
extern MROCORE_API int MROCORE_rename_physical_part_2(
    tag_t   physPartRev ,         /**< (I) Tag of Physical Part Revision*/
    char*   newPartNumber,        /**< (I) New Part Number*/
    char*   newSerialNumber,      /**< (I) New Serial Number*/
    date_t  renameDate,           /**< (I) Rename Date*/
    tag_t*  newPhysPartRev        /**< (O) Tag of new Physical Part Revision*/
    );

/**
    Duplicates given physical Structure
*/
extern MROCORE_API int MROCORE_duplicate_phys_structure(
    tag_t                       inLine,                 /**< (I) Selected BOM line */
    DuplicatePhysStructParams*  inParam,                /**< (I) Parameters required for duplicate structure operation */
    tag_t*                      newPhysPartRev          /**< (O) Generated top Physical Part Revision */
    );

/**
    Converts a mathematical expression into AST form
*/
extern MROCORE_API int MROCORE_convert_expression_to_prefix_form(
    char * expression,            /**< (I) input expression   */
    char ** prefixForm,           /**< (OF) output AST form expression  */
    int * keywordCount,           /**< (O)  keyword count  */
    char *** keywords             /**< (OF) keywords  */
    );

/**
    Assigns the specified Lot to the given Physical Part and deducts the quantity by the specified size.
    <br>If the quantity is greater than the Lot usage or the Physical Part quantity then the error is given.
    <br>If the specified size is less than the expected quantity then
    the Physical Part with remaining quantity is created with the Missing usage.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#MROCORE_lot_usage_error if the Lot Size is exhausted for Lot Number. Please select another Lot.
    <li>#MROCORE_lot_is_expired  if the Lot expiration date is earlier than manufacturing date while assigning the Lot to Physical Part.
    </ul>
*/
extern MROCORE_API int MROCORE_assign_lot(
    tag_t      physical_bom_line,       /**< (I) Tag of Physical BOM Line  */
    tag_t      physical_part_revision,  /**< (I) Tag of Physical Part Revision */
    tag_t      lot,                     /**< (I) Tag of Lot */
    int        quantity                 /**< (I) Quantity that will be deducted on lot assignment. */
    );

/**
    Reconstructs a BOM Line for an input recipe.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors
    </ul>
*/
extern MROCORE_API int MROCORE_reconstruct_bomline (
    const char *  recipe,          /**< (I) Input recipe */
    tag_t*  bom_line               /**< (O) Reconstructed BOM Line tag */
    );

/**
    Retrieves all lots for a Design Part

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors
    </ul>
*/
extern MROCORE_API int MROCORE_get_all_lots_for_design_part(
    tag_t       neutral_item_tag,   /**< (I) The Input Design part */
    int*       size,                /**< (0) Number of Lots */
    tag_t**    lots_for_part        /**< (0F) size Lot part tags */
);

/**
    Finds the lots for a given Neutral Part.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Possibly other errors
    </ul>
*/
extern MROCORE_API int MROCORE_find_lots(
    tag_t            neutral_item_tag,      /**< (I) The Input Design Part */
    const char*      lot_number,            /**< (I) Input Lot Number */
    const char*      mfg_id,                /**< (I) Input Manufacturer ID */
    int *            lot_count,             /**< (0) Lot count for the part */
    tag_t**          lots_for_part          /**< (0F) lot_count Lots for the Part */
);


/**
    Sets an internal flag for @p physical_bom_line to regenerate the child lines.
    Regeneration of child lines occurs when user asks for child lines using #BOM_line_ask_all_child_lines, after setting it to be regenerated

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#BOM_invalid_tag if @p physical_bom_line is #NULLTAG or invalid 
    </ul>
*/
extern MROCORE_API int MROCORE_set_to_regenerate_physical_bom_line_children(
    tag_t          physical_bom_line       /**< (I) Physical bom line */
);

/** @} */


#ifdef __cplusplus
    }
#endif

#include <mrocore/libmrocore_undef.h>
#endif
