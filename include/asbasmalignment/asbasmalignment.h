/*==============================================================================
//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by clients of
    AsMaintained module.
*/

#ifndef ASBASMALIGNMENT_H
#define ASBASMALIGNMENT_H

#include <mrocore/mrocore.h>
#include <asbuilt/asbuilt.h>
#include <asmaintained/asmaintained.h>

#include <asbasmalignment/libasbasmalignment_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup ASBASMALIGNMENT As-Maintained

    The As-Built As-Maintained Alignment module implements the interoperability behavior

    @{
*/

/**
    This structure is used to pass on the parameters for Generate Physical Structure action.
*/
struct ASBASMALIGNMENT_API GeneratePhysStrucParams
{
    GeneratePhysStrucParams ();

    char*       locationName;       /**< Location Name */
    char*       dispositionType;    /**< Disposition Type */
    date_t      rebuildDate;        /**< Build Date For As-Built or As-Maintained Structure */
    int         numberOfLevels;     /**< Number of Levels for Structure Generation */
    bool        generateAsBuilt;    /**< Flag to indicate if an asbuilt structure is to be generated*/
};

/**
    ITK function to generate As-Maintained Structure from
    As-Built Structure and vice versa.
*/
extern ASBASMALIGNMENT_API int ASBASMALIGNMENT_generate_physical_structure(
    tag_t  physical_part_revision,                    /**< (I) Tag of AsBuilt AsMaintained Physical Part Revision */
    GeneratePhysStrucParams* generate_parameters,     /**< (I) Generate Physical Structure Params */
    tag_t* new_physical_part_revision                 /**< (O) Created AsBuilt or AsMaintained Physical Part Revision */
    );
/** @} */

#ifdef __cplusplus
    }
#endif

#include <asbasmalignment/libasbasmalignment_undef.h>

#endif
