/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all data types and constants to be used by
    clients of the Cascading Releases classes and their clients.

    @deprecated This will be removed from Tc14.2.
*/

/*  */

#ifndef CR_H
#define CR_H

/**
   @file

   @deprecated This file will be removed in tc14.2.
*/
#include <tccore/workspaceobject.h>
#include <tccore/releasestatus.h>
#include <epm/libepm_exports.h>

/**
    @defgroup CR Cascade Release (CR)
    @ingroup EPM

    The Cascade Release (CR) functions provide the capability to:
    <UL>
    <LI>Perform inquiries on release procedures, jobs, target objects,
        reference objects, required and unassigned roles, release status and levels,
        decisions, reviewers and date effectivity
    <LI>Initialize, create and refresh jobs
    <LI>Add, remove, promote and demote reference and target objects
    </UL>
    You must include the header file cr.h in your source code.

    @warning CR functions have been specially developed for CR.
    Using these functions with other EPM applications, procedures and tasks
    can result in unpredictable behavior and could cause loss of data.
    @{
*/
/** @deprecated This will be removed from Tc14.2. */
/*  */
typedef enum CR_signoff_decision_e {
             CR_no_decision         = 0,
             CR_approve_decision    = 'Y',
             CR_reject_decision     = 'N'
             } CR_signoff_decision_t;

/** @} CR group */

#include <epm/libepm_undef.h>
#endif
