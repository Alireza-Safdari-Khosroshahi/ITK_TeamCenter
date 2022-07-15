// @<COPYRIGHT_START>@
// ===============================================
// Copyright 2006 UGS Corp. All Rights Reserved.
// ===============================================
// @<COPYRIGHT_END>@


/** 
    @file discipline.h

    This header file declares all the functions to be used
    by clients of the Discipline class which is part of the System
    Administration module of Teamcenter Engineering.

*/

#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include <sa/sa.h>
#include <sa/libsa_exports.h>


#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup DISCIPLINE Discipline
    @ingroup SA
    @{
*/

/**
    Creates discipline object. 
    It is not saved to the database until an explicit call to AOM_save occurs.
    You must specify a discipline name.
 */
extern SA_API int SA_create_discipline(
  const char* discipline_name,   /**< (I) The name of the Discipline to create. */
  tag_t* discipline_tag          /**< (O) The created Discipline. */
  );

/**
    Finds a discipline with the specified name. The discipline name is unique in the database.
    If no Discipline exists with the specified name, a #NULLTAG returns for the discipline tag.
 */
extern SA_API int SA_find_discipline(
    const char* discipline_name,    /**< (I) The name of the Discipline to search for. */
    tag_t* discipline_tag           /**< (O) Reference to the Discipline object found. If not found, this will be #NULLTAG. */
);

/**
    Retrieves all the Discipline objects defined in the system.
*/
extern SA_API int SA_extent_discipline(
    int* num_disciplines,       /**< (O) The number of Disciplines in the system. */
    tag_t** discipline_tags     /**< (OF) Array of Disciplines objects. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
