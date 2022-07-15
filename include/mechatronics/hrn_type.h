/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the \#define for all new types, storage classes, their
    attributes and relations that will be introduced as part of HRN. The naming
    convention for these definitions is as followed:

    Definitions with CLASS_* are all derived from POM object (except for
    CLASS_POM_OBJECT). These represent the various storage classes introduced in
    the system.
 
   Definition with HRN_*_REL are all relations used by HRN
 
   Definition with *_ATTR are all attributes defined for the various storage
   classes that is created.
*/

/*  */

/**
    @defgroup HRN_TYPES HRN Types
    @ingroup MECHATRONICS

    This module has the definitions to various types,storage classes, their attributes and relations defined in HRN
    @{
*/

#ifndef HRN_TYPE_H
#define HRN_TYPE_H 

#include <tccore/item.h>

/**
    @name HRN Type Master and revision master storage class definitions for item types
    @{
*/

#define  CLASS_POM_OBJECT            "POM_object"

#define  CLASS_PART_MASTER           "HRN_PartMaster"
#define  CLASS_PART_REV              "HRN_PartRevMaster"
#define  CLASS_GNLWIRE_MASTER        "HRN_GeneralWireMaster"
#define  CLASS_GNLWIRE_REV           "HRN_GeneralWireRevMaster"
#define  CLASS_GNLTERMINAL_MASTER    "HRN_GenTerminalMaster"
#define  CLASS_GNLTERMINAL_REV       "HRN_GenTerminalRevMaster"
// Part_with_title_block
#define  CLASS_PARTWITHTB_MASTER     "HRN_PartWithTBMaster"
#define  CLASS_PARTWITHTB_REV        "HRN_PartWithTBRevMaster"

#define  CLASS_CONNHOUS_MASTER       "HRN_ConHousingMaster"
#define  CLASS_CONNHOUS_REV          "HRN_ConHousingRevMaster"
#define  CLASS_CAVPLUG_MASTER        "HRN_CavityPlugMaster"
#define  CLASS_CAVPLUG_REV           "HRN_CavityPlugRevMaster"
#define  CLASS_CAVSEAL_MASTER        "HRN_CavitySealMaster"
#define  CLASS_CAVSEAL_REV           "HRN_CavitySealRevMaster"
#define  CLASS_WIREPROTECT_MASTER    "HRN_WireProtectMaster"
#define  CLASS_WIREPROTECT_REV       "HRN_WireProtectRevMaster"
#define  CLASS_ACCESSORY_MASTER      "HRN_AccessoryMaster"
#define  CLASS_ACCESSORY_REV         "HRN_AccessoryRevMaster"
#define  CLASS_FIXING_MASTER         "HRN_FixingMaster"
#define  CLASS_FIXING_REV            "HRN_FixingRevMaster"
#define  CLASS_COPACKPART_MASTER     "HRN_CoPackMaster"
#define  CLASS_COPACKPART_REV        "HRN_CoPackRevMaster"
#define  CLASS_HARNESS_MASTER        "HRN_HarnessMaster"
#define  CLASS_HARNESS_REV           "HRN_HarnessRevMaster"
#define  CLASS_MODULE_MASTER         "HRN_ModuleMaster"
#define  CLASS_MODULE_REV            "HRN_ModuleRevMaster"
#define  CLASS_ASLPART_MASTER        "HRN_AssemblyPartMaster"
#define  CLASS_ASLPART_REV           "HRN_AssemblyPartRevMaster"
/** @} */

/**
    @name HRN Type Master storage class definitions for gde types
    @{
*/
#define CLASS_CAVITY_STORAGE        "HRN_CavityStorage"
#define CLASS_CORE_STORAGE          "HRN_CoreStorage"
#define CLASS_SLOT_STORAGE          "HRN_SlotStorage"
/** @} */

/**
    @name HRN Type class for instance specific/protection area/fixing assignment definitions
    @{
*/
#define CLASS_PROTECTION_AREA     "HRN_ProtectionArea"   
#define CLASS_FIXING_ASSIGN       "HRN_FixingAssignment"   
#define CLASS_WIRE_LENGTH         "HRN_WireLength"   
#define CLASS_WIRE_COLOR          "HRN_WireColor"
#define CLASS_WIRE_NUMBER         "HRN_InstanceGenWireData"

#define CLASS_INST_CONN_HOUSE     "HRN_InstanceConnHouse"
#define CLASS_INST_CAVITY         "HRN_InstanceCavity"
#define CLASS_INST_WIRE_PROTECT   "HRN_InstanceWireProtect"
#define CLASS_INST_PART_DATA      "HRN_InstancePartData"
/** @} */

/**
    @name HRN Type Item types defined
    @{
*/
#define  CONN_HOUSING        "HRN_ConHousing"
#define  GENERAL_TERMINAL    "HRN_GenTerminal"
#define  WIRE_PROTECTION     "HRN_WireProtect"
#define  ACCESSORY           "HRN_Accessory"
#define  FIXING              "HRN_Fixing"
#define  CO_PACK_PART        "HRN_CoPackPart"
#define  CAVITY_PLUG         "HRN_CavityPlug"
#define  CAVITY_SEAL         "HRN_CavitySeal"
#define  GENERAL_WIRE        "HRN_GeneralWire"
#define  HARNESS             "HRN_Harness"
#define  MODULE              "HRN_Module"
#define  ASSEMBLY_PART       "HRN_AssemblyPart"
/** @} */

/**
    @name HRN Type Item revisions defined
    @{
*/
#define CONN_HOUSING_REV     "HRN_ConHousingRevision"    
#define GENERAL_TERMINAL_REV "HRN_GenTerminalRevision"       
#define WIRE_PROTECTION_REV  "HRN_WireProtectRevision" 
#define ACCESSORY_REV        "HRN_AccessoryRevision"      
#define FIXING_REV           "HRN_FixingRevision"         
#define CO_PACK_PART_REV     "HRN_CoPackPartRevision"     
#define CAVITY_PLUG_REV      "HRN_CavityPlugRevision"     
#define CAVITY_SEAL_REV      "HRN_CavitySealRevision"     
#define GENERAL_WIRE_REV     "HRN_GeneralWireRevision"           
#define HARNESS_REV          "HRN_HarnessRevision"        
#define MODULE_REV           "HRN_ModuleRevision"         
#define ASSEMBLY_PART_REV    "HRN_AssemblyPartRevision"   
/** @} */

/**
    @name HRN Type GDE types defined
    @{
*/
#define  GDE_CLASS_NAME      "GeneralDesignElement"

#define  HRN_CAVITY_TYPE     "HRN_Cavity"
#define  HRN_CORE_TYPE       "HRN_Core"
#define  HRN_SLOT_TYPE       "HRN_Slot"
/** @} */

/**
    @name HRN Type Relations defined
    @{
*/
#define HRN_ASSOCIATED_PART_REL   "HRN_associated_part"
#define HRN_WIRE_LENGTH_REL       "HRN_wire_length_data"
#define HRN_FIXING_ASSIGN_REL     "HRN_fixing_assignment"
#define HRN_PROTECT_AREA_REL      "HRN_protection_area"
#define HRN_INSTANCE_DATA_REL     "HRN_part_data"
#define HRN_INST_CONN_DATA_REL    "HRN_connector_data"
#define HRN_INST_WIREP_DATA_REL   "HRN_wire_protect_data"
#define HRN_INST_CAV_DATA_REL     "HRN_cavity_data"
#define HRN_REF_COMPONENT_REL     "HRN_node_referenced_component"
#define HRN_WIRE_COLOR_REL        "HRN_wire_color"
#define HRN_WIRE_NUMBER_REL       "HRN_general_wire_data"
/** @} */

/**
    @name HRN Type Attributes for the classes defined
    @{
*/

/**
    This is used as the last entry for all the attribute
    list that will be defined using the structure 
    HRN_class_def_t
*/
#define DUMMY_ENTRY                 "{0,}"

/**
 * Copyright note is made a form
 */
#define HRN_COPYRIGHT_NOTE          "HRN_Copyright_Note_Storage"
#define COPYWRITE_NOTE              "copyright_note"
/**
    Attribute for PartMater Form
*/
#define PART_TYPE                   "part_type"
#define PROCESS_TYPE                "process_type"
#define PROCESS_VALUE               "process_value"

/**
    Attribute for PartRevMaster Form
*/
#define MTL_KEY                     "material_key"
#define MTL_REF_SYS                 "mtl_ref_system"
#define MASS_INFO                   "mass_information"

/**
    Attribute for GnlWireMaster Form
 */
#define BEND_RADIUS                 "bend_radius"
#define CABLE_DESIGN                "cable_designator"
#define CROSS_SECTION               "cross_section"
#define OUTSIDE_DIA                 "outside_dia"
#define MIN_LENGTH_ATTR             "min_length"
#define MAX_LENGTH_ATTR             "max_length"
#define WIRESPEC_ATTR               "wirespec"
#define WIDTH_ATTR                  "width"
#define HEIGHT_ATTR                 "height"
#define COVER_THICKNESS_ATTR        "cover_thickness"
#define GAUGE_ATTR                  "gauge"

/**
    Attributes for GnlTerminalMaster Form
 */
#define PLATING_MTL                 "plating_material"

/**
    Attributes for PartWithTBMaster Form
 */
#define CAR_CLASS_LEVEL2            "car_class_level2"
#define CAR_CLASS_LEVEL3            "car_class_level3"
#define CAR_CLASS_LEVEL4            "car_class_level4"
#define COMPANY_NAME                "company_name"
#define MODEL_YEAR                  "model_year"
//#define PROJECT_NO                  "project_no"

/**
    Attribute for ConnectorHousingMaster Form
 */
#define HOUSING_CODE                "housing_code"
#define HOUSING_COLOR               "housing_color"

/**
    Attribute for CavitysealMaster Form
 */
#define COLOR                       "color"
#define WIRE_SIZE                   "wire_size"

/**
    Attribute for WireProtectionMaster Form
 */
#define TYPE_DEPEN_PARAM            "type_depen_param"

/**
    Attribute for different fixing assignment, wire length, wire
    color, protection area 
 */

#define POSI_ON_WIRE_ATTR           "posi_on_wire"
#define LENGTH_TYPE_ATTR            "length_type"
#define LENGTH_VALUE_ATTR           "length_value"
#define END_LOCATION_ATTR           "end_location"
#define START_LOCATION_ATTR         "start_location"
#define GRADIENT_ATTR               "gradient"
#define TAPING_DIR_ATTR             "taping_dir"
#define LOCATION_ATTR               "location"
#define ORIENTATION_ATTR            "orientation"
#define COLOR_TYPE_ATTR             "color_type"
#define COLOR_VALUE_ATTR            "color_value"

/** 
    Attribute list for occurrence specific part types
 */
#define ID_ATTR                     "id"
#define ALIAS_ID_ATTR               "alias_id" 
#define USAGE_ATTR                  "usage" 
#define PROTECT_LENGTH_ATTR         "protect_length" 
#define WIRE_NUMBER_ATTR            "wire_number"
#define MULTIPLIER_ATTR             "multiplier" 
#define OFFSET_ATTR                 "offset" 
#define SEPERATION_CODE_ATTR        "seperation_code" 


/**    
    S T R U C T U R E S
 */

/** Structure for defining all storage classes */
typedef struct {
    const char  *name;       /* Name of the Attribute */
    int   type;              /* Type of the Attribute */
    int   descriptor;        /* Description of the Attribute */
    int   length;            /* Length of the Array */
    int   max_str_len;   /* Max String length,if type is String,0 otherwise*/
    const char  *ref_class_name; /* Reference Class Name, if type is a typed 
                                    reference */
} HRN_class_def_t;


/** @} */

/** @} */

#endif




