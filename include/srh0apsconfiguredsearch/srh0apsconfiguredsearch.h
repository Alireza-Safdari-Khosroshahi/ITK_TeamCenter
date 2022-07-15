/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2016.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the declaration of published ITK APIs from srh0apsconfiguredsearch module.
*/

#ifndef TEAMCENTER__SRH0CONFIGUREDSEARCH_H
#define TEAMCENTER__SRH0CONFIGUREDSEARCH_H

#include <unidefs.h>
#include <srh0apsconfiguredsearch/libsrh0apsconfiguredsearch_exports.h>

/**
    @defgroup SRH0_CONFIGURED_SEARCH Advanced Product Lifecycle Management Services Configured Search
    @ingroup TC
    
    This class provides APIs for Configured Search.

    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
   An array of configured revisions.
   <br/> If there are no configured revisions for a thread, n_configured_revisions will be 0.
*/
typedef struct
{
    unsigned int n_configured_revisions;   /**< Number of configured revisions */
    tag_t * configured_revisions;          /**< Array of configured revisions. */
} SRH0_configured_revision_t;
   
/**
    Retrieves configured Workspace Object revisions for each given object thread (type Fnd0ObjectThread)
    based on the configuration object having the ConfigurationProvider behavior. 
    <br/>The elements are configured using information supplied by the configuration provider. This consists of: 
    <ul> 
    <li>the Revision Rule (it can contain the effectivity criteria) 
    <li>the Variant Rule 
    </ul> 

    <br/>The configuration object (@p configuration_provider) contains the configuration parameters
    and can be either a ConfigurationContext object or Cfg0ConfiguratorPerspective object. 

    <br/>Each configured Workspace Object matches the @c cparam of the given object thread (type Fnd0ObjectThread).
    Mixed @c cparams are supported. 

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#ITK_parameter_invalid_value if @p configuration_provider  is #NULLTAG or does not support the configuration provider behavior.
    <li>#ITK_parameter_invalid_value if @p threads is a null pointer and @p n_threads is not @c 0.
    <li>#ITK_parameter_invalid_value if any element of @p threads is not an object thread (type Fnd0ObjectThread).
    </ul>
*/
extern SRH0APSCONFIGUREDSEARCH_API int SRH0_get_configured_revisions(
    const tag_t         configuration_provider,         /**< (I) Configuration object */
    const unsigned int  n_threads,                      /**< (I) Number of input threads */
    const tag_t*        threads,                        /**< (I) Input threads  */
    SRH0_configured_revision_t **  revisions            /**< (OF) n_threads Array of configured revisions. 
    <br/>The array is packed, which means that the deallocation is done by calling #MEM_free on the container only. */ 

    );

#ifdef __cplusplus
}
#endif
/** @} */
#include <srh0apsconfiguredsearch/libsrh0apsconfiguredsearch_undef.h>
#endif
