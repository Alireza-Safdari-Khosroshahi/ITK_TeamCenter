/*==============================================================================

                         Copyright (c) 2005 UGS
                    Unpublished - All rights reserved

===============================================================================*/

/**
    @file

    This file contains definitions and interfaces for ESM class
*/

/*  */

#ifndef ESM_H
#define ESM_H

#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup ESM Esm
    @ingroup MECHATRONICS
    @{
*/


#ifdef __cplusplus
    extern "C"{
#endif

/**
    Given a BOM Line tag, this function checks whether it is a Processor BOM Line 
*/
extern MECHATRONICS_API int ESM_is_processor  
(
    tag_t    bom_line,  /**< (I) Tag of a BOM Line */ 
    logical *status     /**< (O) Is TRUE if the BOM line tag is a Processor, otherwise FALSE */
);

/**
    Given a BOM Line tag, this function checks whether it is a Gateway Processor BOM Line 
*/
extern MECHATRONICS_API int ESM_is_gateway  
(
    tag_t    bom_line,  /**< (I) Tag of a BOM Line */ 
    logical *status     /**< (O) Is TRUE if the BOM line tag is a Processor, otherwise FALSE */
);
/**
    Given a BOM Line tag, this function checks whether it is a Software BOM Line
*/

extern MECHATRONICS_API int ESM_is_software  
(
    tag_t    bom_line,  /**< (I) Tag of a BOM Line */
    logical *status    /**< (O) Is TRUE if the BOM line tag is a software, otherwise FALSE */
);

/**
    Given a Processor BOM line, and an array of Software BOM lines, this method associates Processor and software using Embeds relation.
*/

extern MECHATRONICS_API int ESM_associate_processor_to_software
(
    tag_t    processor_line,              /**< (I) Tag of a Processor BOM Line */
    int      num_software_lines,          /**< (I) Number of Software BOM lines */
    tag_t   *software_lines,              /**< (I) Array of software BOM lines */
    logical *hasFailures,                 /**< (O) Did any failures occur */
    int     *numFailedLines,              /**< (O) Number of failed association lines */ 
    tag_t  **failedLines                  /**< (OF) numFailedLines Array of failed association lines */
);


/**
    Given a Processor BOM line, and an array of Software BOM lines, this method  removes association betwn Processor and software participating in Embeds relation.
*/

extern MECHATRONICS_API int ESM_remove_processor_to_software_association
(
    tag_t    processor_line,              /**< (I) Tag of a Processor BOM Line */
    int      num_software_lines,          /**< (I) Number of Software BOM lines */
    tag_t   *software_lines,              /**< (I) Array of software BOM lines */
    logical *hasFailures,                 /**< (O) Did any failures occur */
    int     *numFailedLines,              /**< (O) Number of failed remove lines */ 
    tag_t  **failedLines                  /**< (OF) numFailedLines Array of failed association lines */
);

/**
    Given a gateway Processor BOM line, and an array of Software BOM lines, this method removes association betwn Gateway Processor and Processor
*/
extern MECHATRONICS_API int ESM_remove_processor_to_processor_association
(
    tag_t    gateway_processor_line,       /**< (I) Tag of a gateway processor BOM Line */
    int      num_processor_lines,          /**< (I) Number of associated processor lines */
    tag_t    *processor_lines,             /**< (I) Array of processor lines */
    logical *hasFailures,                 /**< (O) Did any failures occur */
    int     *numFailedLines,              /**< (O) Number of failed remove lines */ 
    tag_t  **failedLines                  /**< (OF) numFailedLines Array of failed assoc lines */
);

/**
    Given a gateway Processor BOM line, and an array of Software BOM lines, this method associates Processor and software using Embeds relation.
*/
extern MECHATRONICS_API int ESM_associate_processor_to_processor
(
    tag_t    gateway_processor_line,       /**< (I) Tag of a gateway processor BOM Line */
    int      num_processor_lines,          /**< (I) Number of associated processor lines */
    tag_t    *processor_lines,             /**< (I) Array of processor lines */
    logical *hasFailures,                 /**< (O) Did any failures occur */
    int     *numFailedLines,              /**< (O) Number of failed association lines */ 
    tag_t  **failedLines                  /**< (OF) numFailedLines Array of failed association lines */
);

/**
    Given a software BOM line, and an array of Software BOM lines, this method associates software using Dependent On relation.
*/
extern MECHATRONICS_API int ESM_associate_software_to_software
(
    tag_t    software_line,               /**< (I) Tag of a software BOM Line */
    int      num_software_lines,          /**< (I) Number of Software BOM lines */
    tag_t    *software_lines,             /**< (I) Array of software BOM lines */
    logical *hasFailures,                 /**< (O) Did any failures occur */
    int     *numFailedLines,              /**< (O) Number of failed association lines */ 
    tag_t  **failedLines                  /**< (OF) numFailedLines Array of failed association lines */
);
/**
    Given a software BOM line, and an array of Software BOM lines, this method associates software using Dependent On relation.
*/
extern MECHATRONICS_API int ESM_remove_software_to_software_association
(
    tag_t    software_line,               /**< (I) Tag of a software BOM Line */
    int      num_software_lines,          /**< (I) Number of Software BOM lines */
    tag_t    *software_lines,             /**< (I) Array of software BOM lines */
    logical *hasFailures,                 /**< (O) Did any failures occur */
    int     *numFailedLines,              /**< (O) Number of failed removes */ 
    tag_t  **failedLines                  /**< (OF) numFailedLines Array of failed assoc lines */
);

/**
 * Given a Processor BOM line, this function gets an array of Software BOM lines
 * that are associated to Processor with Embeds relation
 */
extern MECHATRONICS_API int ESM_ask_embedded_software_of_processor
(
    tag_t    processor_line,               /**< (I) Tag of a processor BOM Line  */
    int      *num_software_lines,          /**< (O) Number of Software BOM lines */
    tag_t    **software_lines              /**< (OF) num_software_lines Array of software BOM lines */
);
/**
 * Given a Software BOM line, this function gets an array of Processor BOM lines
 * that are associated with it with Embeds relation
 */
extern MECHATRONICS_API int ESM_ask_processors_associated_with_software
(
    tag_t    software_line,                 /**< (I) Tag of a software BOM Line  */
    int      *num_processor_lines,          /**< (O) Number of processor BOM lines */
    tag_t    **processor_lines              /**< (OF) num_processor_lines Array of processor BOM lines */
);

/** 
 * Given a Processor BOM line, this function gets an array of gateway processor
 * BOM lines that are associated to it with GatewayOf relation
 */
extern MECHATRONICS_API int ESM_ask_gateway_of_processor
(
    tag_t    processor_line,                /**< (I) Tag of a processor BOM Line  */
    int      *num_gateway_processor_lines,  /**< (O) Number of Gateway BOM lines  */
    tag_t    **gateway_processor_lines      /**< (OF) num_gateway_processor_lines Array of Gateway Processor BOM lines */
);
/** 
 * Given a gateway Processor BOM line, this function gets an array of processor 
 * BOM lines that are associated with GatewayOf relation 
 */
extern MECHATRONICS_API int ESM_ask_processors_accessedby_processor
(
    tag_t    gateway_processor_line,      /**< (I) Tag of a Gateway Processor BOM Line  */
    int      *num_processor_lines,        /**< (O) Number of processor BOM lines  */
    tag_t    **processor_lines            /**< (OF) num_processor_lines Array of processor BOM lines */
);
/**
 * Given a primary software BOM line, this function gets an array of (secondary) 
 * Software BOM lines that are dependent on the primary software
 */
extern MECHATRONICS_API int ESM_ask_dependent_software_of_software
(
    tag_t    software_line,               /**< (I) Tag of a primary software BOM Line  */
    int      *num_software_lines,         /**< (O) Number of secondary software BOM lines  */
    tag_t    **software_lines             /**< (OF) num_software_lines Array of secondary software BOM lines */
);

/**
 * Given a (secondary) software BOM line, this function gets an array of (primary) 
 * Software BOM lines that are used by the secondary software
 */
extern MECHATRONICS_API int ESM_ask_software_used_by_software
(
    tag_t    software_line,               /**< (I) Tag of a secondary software BOM Line  */
    int      *num_software_lines,         /**< (O) Number of primary software BOM lines   */
    tag_t    **software_lines             /**< (OF) num_software_lines Array of primary software BOM lines */
);


/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>

#endif

