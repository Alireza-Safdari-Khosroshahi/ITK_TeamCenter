//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    CCDM Data import / export would require additional data model changes so that
    customers and partners could implement parsers and writers to support additional formats.
    This file contains the common methods and structures for Ccdm Export Import
    exposed for the customers and partners.

*/

#ifndef CCDM__CCD0EXPIMP_H
#define CCDM__CCD0EXPIMP_H

#include <map>
#include <string>
#include <vector>
#include <fstream>

#include <ccdm/libccdm_exports.h>
#include <unidefs.h>

/**< typedef for a String Array Map */
typedef std::map< std::string, std::vector< std::string > > StringArrayMap;

/**
    ValueAddress is a structure having information about the memory record in a Memory block.
    It contains the value, computed value, computed address of the memory record.
*/
typedef struct ValueAddress
{
    tag_t valueObjectTag;                       /**< Tag of the value object */
    std::vector<std::string> computedValue;     /**< Computed Value */
    std::string computedAddress;                /**< Address */
    tag_t parmMemoryRecordTag;                  /**< Tag of parameter Memory record */

}ValueAddressS;

/**
    address and tag of the memory layout
*/
typedef struct MemoryLayoutExportData
{
    tag_t memoryLayoutTag;                      /**< Tag of memory layout object */
    std::vector<ValueAddress> valueAddress;     /**< Value and Address */

}MemoryLayoutExportDataS;

/**
    memory layout and attributes to be exported for flash file generation
*/
typedef struct ParmFlashGenerationExpData
{

    std::vector<MemoryLayoutExportData > memoryLayoutExportData;        /**< Structure containing information about value object and its details */
    StringArrayMap attributesMap;                                       /**< Forms options info */

}ParmFlashGenerationExpDataS;

/**
    information about the parameter definition
*/
typedef struct ParmValueDetails
{
    tag_t parmDefinitionRevTag;             /**< Tag of Parameter Definition Revision object */
    tag_t parmValTag;                       /**< Tag of Parameter value object */
    tag_t variantExpTag;                    /**< Tag of Variant Expression */

}ParmValueDetailsS;

/**
    parm value details for export
*/
typedef struct ParmValueSharingExpData
{
    std::vector<ParmValueDetails> parmValDetails;   /**< Parameter Valaue details */
    StringArrayMap attributesMap;                   /**< Forms options info */
}ParmValueSharingExpDataS;

/**
    parameter group information tag and revTag
*/
typedef struct GroupParmDetails
{
    tag_t parmGroupTag;                         /**< Tag of Parameter Group object */
    std::vector<tag_t> parmDefinitionRevTag;    /**< Vector of Parameter Definition Revision tag */
}GroupParmDetailsS;

/**
    Parameter dictionary details containing group of parmGroups for export
*/
typedef struct ParmDictionaySharingExpData
{
    std::vector<GroupParmDetails> groupParmDetails; /**< Vector of GroupParmDetails */
    StringArrayMap attributesMap;                   /**< Forms options info */

}ParmDictionaySharingExpDataS;

/**
    File path export location
*/
typedef struct ExportFileData
{
    std::string absFilePath;        /**< File path */
    std::vector<tag_t> objectTags;  /**< Memory Layout  Object tags */

}ExportFileDataS;

/**
    Error info
    Contains the ifail code for error occured in import/export operation and severity of the error
*/

typedef struct ErrorInfo
{
    int ifail;      /**< Error code */
    int severity;   /**< Severity */

    std::string s1; /**< Additional strings required for error code */
    std::string s2; /**< Additional strings required for error code */
    std::string s3; /**< Additional strings required for error code */
    std::string s4; /**< Additional strings required for error code */
    std::string s5; /**< Additional strings required for error code */
    std::string s6; /**< Additional strings required for error code */
    std::string s7; /**< Additional strings required for error code */

} ErrorInfoS;

/**
    Error Info for a particular object
    Structure contains the tag and information about the error occured on an object
*/
typedef struct ObjectErrorInfo
{
    tag_t objectTag;                    /**< Object */
    std::vector<ErrorInfoS> errorInfo;  /**< Errors */

}ObjectErrorInfoS;

/**
    Object exported and exported file location details
    Error info related to object if any
*/
typedef struct ExportFileOutput
{
    std::vector<ExportFileDataS> exportFileData;    /**< Exported file data */
    std::vector<ObjectErrorInfoS> objErrorInfos;    /**< Error information, if any */

}ExportFileOutputS;

/**
    Blocks structure contains the information(address, block name, parent block) of a Memory block
*/
typedef struct Blocks
{
    std::string startAddressOffset;     /**< offset address is position/address of the block with respect to the Memory Layout or parent block */
    std::string blockName;              /**< Name of the memory block */
    Blocks *parentBlock;                /**< pointer to the parent memory block structure */

}BlocksS;

/**
    Individual parameter definition information with adderss and it's parent block
*/
typedef struct Records
{
    std::string recAddressOffset;       /**< this address is position of the memory record(parameter definition) with respect to the parent memory block  */
    std::string parameterName;          /**< Name of the parameter definition */
    Blocks *parentBlock;                /**< pointer to the parent memory block structure */

}RecordsS;

/**
    Name, start address, blocks and records information of a memory layout
*/
typedef struct MemoryLayoutDetails
{
    std::string name;               /**< Header for a memory layout */
    std::string startAddress;       /**< start address of the layout */
    std::vector<BlocksS> blocks;    /**< memory blocks inside the layout */
    std::vector<RecordsS> records;  /**< memory records/parm defs inside the layout */

}MemoryLayoutDetailsS;

/**
    This structure represents the algebraic formula, e.g. Linear, Quadratic, Rational.
*/
typedef struct AlgebraicFormula
{
    std::string name;               /**< algebraic formula name */

    int numberOfConstNames;         /**< no of constants in the formula */
    char** constNames;              /**< names of the constants in the formula */

    int numberOfVariableNames;      /**< number of variables in the formula */
    char** variableNames;           /**< name of the variables in the formula */

    std::string expresssion;        /**< formula expression in the form of string */
    std::string invExpression;      /**< Inverse-formula expression */
    std::string asteExpression;     /**< Formula prefix expression */
    std::string invAsteExpression;  /**< Inverse-formula prefix expression */

}AlgebraicFormulaS;

/**
    formula conversion information is required for storing the actual values of parameter definition in the ECU
*/
typedef struct FormulaConversion
{
    int numberOfFormulaConstValues;     /**< no of values for constants */
    char** formulaConvConstVals;        /**< array of constant values */

    AlgebraicFormulaS algebraicFormula; /**< Algebraic Formula structure*/

}FormulaConversionS;

/**
    contains actual input value of parameter definition
*/
typedef struct ValueConversion
{
    std::string inputValue;     /**< actual value input by user */

}ValueConversionS;

/**
    Range of the input value of a parmdef between the minimal value and the maximal value
*/
typedef struct RangeConversion
{
    std::string minValue;   /**< Minimal value of the range */
    std::string maxValue;   /**< Maximal value of the range */

}RangeConversionS;

/**
    contains information about the parmdef conversion and output value
*/
typedef struct RecordConversion
{
    std::string outputValue;            /**< Output value */
    ValueConversionS *valueConversion;  /**< ValueConversionS */
    RangeConversionS *rangeConversion;  /**< RangeConversionS */

}RecordConversionS;

/**
    contains GenericCovnersionRule, which represents a table conversion.
    It contains a list of record conversion to map an input value to an
    output value respectively.
*/
typedef struct RecordColConversion
{
    std::string defaultValue;                           /**< If any record conversion cannot satisfy the input value, use the default value as the output value. */

    std::vector<RecordConversionS> vecRecordConversion; /**< An array of Record conversion rules information */

    bool withInterpolation;     /**< This flag indicates whether or not interpolation should be done for determining
                                an output value between the input values if necessary. If the flag is set as true,
                                the output value of the previous input value is assigned to the respective input value. */

}RecordColConversionS;

/**
    Conversion rule information - formula and record col conversion
*/
typedef struct ConversionRuleDetails
{
    std::string ruleName;                       /**< Conversion rule name */
    std::string ruleDesc;                       /**< Conversion rule description */

    FormulaConversionS *formulaConversion;      /**< Populate this if formula conversion is applicable */
    RecordColConversionS *recordColConversion;  /**< Populate this if Record Conversion is applicable */

}ConversionRuleDetailsS;

/**
    value Structures for a parmdDef added for CCDM
*/
typedef struct TableCellValueType {
    std::string     type;       /**< Indicates what value to use; string,date,double,int,bool */
    std::string     strVal;     /**< string value */
    date_t          dateVal;    /**< value in the form of date */
    double          dblVal;     /**< double value */
    int             intVal;     /**< int value */
    bool            boolVal;    /**< bool value */
}TableCellValueTypeS;

/**
    Table cell containing row, col, desc and value for a parmDef
*/
typedef struct TableCell {
    int row;                    /**< row and col indicate the number of values for a parameter definition */
    int col;                    /**< row and col indicate the number of values for a parameter definition */
    std::string desc;           /**< description */
    TableCellValueTypeS value;  /**< value */
}TableCellS;

/**
    row lables and column labels for no of rows, cols
*/
typedef struct TableDef {
    int rows;                           /**< row and col indicate the number of values for a parameter definition */
    int cols;                           /**< row and col indicate the number of values for a parameter definition */

    std::vector<std::string> rowLabels; /**< row labels */
    std::vector<std::string> colLabels; /**< column labels */

}TableDefS;

/**
    Table contains table definition info and table cells information
*/
typedef struct Table {
    TableDefS *tableDefInfo;
    std::vector<TableCellS> tableCells;
    //Table():tableDefInfo(), tableCells(){}
    //Table(TableDefS *tableDefInfo1, std::vector<TableCellS>& tableCells1):tableDefInfo(tableDefInfo1), tableCells(tableCells1){}
} TableS;

/**
    Structures related to Bit Definition
*/
typedef struct BitDefinitionData {
    int byteNum;
    int bitNum;
    std::string name;

    std::string meaningOf0;     /**< Meaning of 0 and 1 for bitDef parameter since only 2 values could exist */
    std::string meaningOf1;     /**< Meaning of 0 and 1 for bitDef parameter since only 2 values could exist */
}BitDefinitionDataS;

/**
    Parmater Definition Revision Details containing all the information about a memory record / parm def
*/
typedef struct ParmDefinitionRevDetails
{
    std::string  parmDefRevComment;     /**< Revision comment */
    std::string  parmDefControlEngr;    /**< Control engineer name */
    int parmDefSize;                    /**< Size */
    std::string  parmDefSizeUnits;      /**< Unit of size */
    TableDefS tableDefinition;          /**< Table definition */
    bool parmDefIsSigned;               /**< Flag to indicate is signed int/dbl type of parameters */
    int parmDefResoNumerator;           /**< Resolution numberator */
    int parmDefResoDenominator;         /**< Resolution denominator */
    double parmDefTolerance;            /**< Tolerance */
    double parmDefPrecision;            /**< Precision */

    ConversionRuleDetailsS parmDefConversionRule;   /**< Conversion rule formula */
    TableS parmDefMinValues;                        /**< Minimum Value */
    TableS parmDefMaxValues;                        /**< Maximum Value */
    TableS parmDefInitialValues;                    /**< Initial Value */
    TableS parmDefValidValues;                      /**< Valid Value */
    std::vector<BitDefinitionDataS> vecBitDefInfo;  /**< BitDef */

}ParmDefinitionRevDetailsS;

/**
    details of parameter group in a dictionary
*/
typedef struct ParmGroupDetails
{
    std::string parmGrpName;        /**< Name of the parameter group */
    std::string parmGrpDescriptor;  /**< Group Description */
    std::string parmGrpComment;     /**< Group comments */
    std::string parmGrpRepresents;  /**< Type of group */
    std::string parmGrpControlEngr; /**< Name of the control engineer associated to this group */
    std::string parmGrpspecialistUser;  /**< Name of the specialist associated to this group */
    ParmGroupDetails *parentGroup;      /**< Reference to parent group of this group */

}ParmGroupDetailsS;

/**
    Parameter definition details
*/
typedef struct ParmDefinitionDetails
{
    int findNumber;                             /**< Find number */
    std::string  parmDefType;                   /**< Parameter definition type [int, dbl, bool etc] */
    std::string  parmDefParmType;               /**< Parameter definition usage  [Calibration, Configuration, Measurement etc] */
    std::string  parmDefComment;                /**< Comments */
    std::string  parmDefName;                   /**< Parameter name */
    ParmDefinitionRevDetailsS parmDefRevDetails;/**< Parameter revision details */
    std::string  parmDefDescriptor;             /**< Description */
    ParmGroupDetailsS* parentGroup;             /**< Reference to parent group of this group */

}ParmDefinitionDetailsS;

/**
    ParmDictionaryUpdateData
*/
typedef struct ParmDictionaryUpdateData
{
    tag_t selectedObject;                                   /**< Selected dictionary for import */
    std::vector<MemoryLayoutDetailsS> vecMemLayoutDetails;  /**< Vector of memory layouts */
    std::vector<ParmGroupDetailsS> vecParmGroupDetails;     /**< Vector of parameter group definition */
    std::vector<ParmDefinitionDetailsS> vecParmDefDetails;  /**< Vector of parameter definition */


}ParmDictionaryUpdateDataS;

/**
    Structure to hold the output of the parse process
*/
typedef struct DictionaryParseOutput
{
    ParmDictionaryUpdateData importData;            /**< paramaeter data to be imported to dictionary or project */
    std::vector<ObjectErrorInfo> vecParseErrorData; /**< error inforamtion while data parsing from file, if any */

}DictionaryParseOutputS;

#include <ccdm/libccdm_undef.h>
#endif // CCDM__CCD0EXPIMP_H
