/*
  Copyright 2020 Siemens Digital Industries Software
  ==================================================
  Copyright 2018.
  Siemens Product Lifecycle Management Software Inc.
  All Rights Reserved.
  ==================================================
  Copyright 2020 Siemens Digital Industries Software
*/
/**
   @file

   Include file to define entry points for user defined entry points.
*/

#ifndef INTOSITE_USER_EXITS_H
#define INTOSITE_USER_EXITS_H

#include <unidefs.h>
#include <ins0intosite/libins0intosite_exports.h>

/**
   @defgroup INTOSITE_USER_EXITS User exits 
   @ingroup USER_EXIT
   The user exits defined here are called during tc_to_intosite processing.
   @{
*/

/**
   Used by the user exit extension to instruct the user exit ITK implementation to continue to execute the out-of-the-box behavior.
*/
#define INTOSITE_USER_EXIT_CONTINUE        101

/**
    Indicates corresponding value is type bool.
*/
#define INS0_BOOL                                        0

/**
    Indicates corresponding value is type string.
*/
#define INS0_STRING                                      1

/**
    Indicates corresponding value is int.
*/
#define INS0_INT                                         2

/**
    Indicates corresponding value is double.
*/
#define INS0_DOUBLE                                      3

/**
    Indicates corresponding value is type bomline property.
*/
#define INS0_PROPERTY                                    4

/**
    Indicates corresponding value is dataset type.
*/
#define INS0_DATASET                                     5
/**
    Indicates corresponding value is relation type.
*/
#define INS0_RELATION                                    6
/**
    Indicates corresponding value is named ref type.
*/
#define INS0_NAMEDREF                                    7
/**
    Indicates corresponding value is dataset name type.
*/
#define INS0_DATASETNAME                                 8

#ifdef __cplusplus
extern "C"{
#endif

/**
 Provides the default implementation to produce an address string.
 <br/>The application using this USER exit determines its context within that application.
 <br/>The default implementation concatenates all the input arguments as a string. 
 <br/>Customizations can use custom logic to create an address string.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bomline is not a valid BOMLine.
    <li>#TCINTOSITE_utility_found_error if the (@p types,@p values) pair is invalid.
    </ul>
*/
extern INS0INTOSITE_API int USER_INS0_address_callback(
    const tag_t bomline,                  /**< (I) The BOMLine to use.*/
    const unsigned int  n_args,           /**< (I) The number of (type,value) pairs being passed in.*/
    const int * types,                    /**< (I) n_args Types must be one of the following: INS0_BOOL, INS0_STRING, INS0_INT, INS0_DOUBLE, INS0_PROPERTY.*/
    const void ** values,                 /**< (I) n_args Values.*/
    char **  address                      /**< (OF) The address string.*/
    );

/**
 Provides the default implementation to produce a create condition.
 <br/>The application using this USER exit determines its context within that application.
 <br/>The default implementation returns true. 
 <br/>Customizations can use custom logic to produce a create condition that returns true or false.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bomline is not a valid BOMLine.
    <li>#TCINTOSITE_utility_found_error if the (@p types,@p values) pair is invalid.
    </ul>
*/
extern INS0INTOSITE_API int USER_INS0_create_condition_callback(
    const tag_t bomline,                     /**< (I) The BOMLine to use.*/
    const unsigned int  n_args,              /**< (I) The number of (type,value) pairs being passed in.*/
    const int * types,                       /**< (I) n_args Types must be one of the following: INS0_BOOL, INS0_STRING, INS0_INT, INS0_DOUBLE, INS0_PROPERTY.*/
    const void ** values,                    /**< (I) n_args Values.*/
    logical * result                         /**< (O) Result as true or false.*/  
    );

/**
 Provides the default implementation to produce a propertycondition.
 <br/>The application using this USER exit determines its context within that application.
 <br/>The default implementation returns true. 
 <br/>Customizations can use custom logic to produce a property condition that returns true or false.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bomline is not a valid BOMLine.
    <li>#TCINTOSITE_utility_found_error if the (@p types,@p values) pair is invalid.
    </ul>
*/
extern INS0INTOSITE_API int USER_INS0_property_condition_callback(
    const tag_t bomline,                   /**< (I) The BOMLine to use.*/
    const unsigned int  n_args,            /**< (I) The number of (type,value) pairs being passed in.*/
    const int * types,                     /**< (I) n_args Types must be one of the following: INS0_BOOL, INS0_STRING, INS0_INT, INS0_DOUBLE, INS0_PROPERTY.*/
    const void ** values,                  /**< (I) n_args Values.*/
    logical * result                       /**< (O) Result as true or false.*/  
    );

/**
 Provides the default implementation to produce a name string.
 <br/>The application using this USER exit determines its context within that application.
 <br/>The default implementation concatenates all the input arguments as a string. 
 <br/>Customizations can use custom logic to create an address string.

 @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#BOM_invalid_tag if @p bomline is not a valid BOMLine.
    <li>#TCINTOSITE_utility_found_error if the (@p types,@p values) pair is invalid.
    </ul>
*/
extern INS0INTOSITE_API int USER_INS0_name_callback(
    const tag_t bomline,                    /**< (I) The BOMLine to use.*/
    const unsigned int  n_args,             /**< (I) The number of (type,value) pairs being passed in.*/
    const int * types,                      /**< (I) n_args Types must be one of the following: INS0_BOOL, INS0_STRING, INS0_INT, INS0_DOUBLE, INS0_PROPERTY, INS0_RELATION,INS0_DATASET,INS0_NAMEDREF .*/
    const void ** values,                   /**< (I) n_args Values.*/
    char **  address                        /**< (OF) The address string.*/
    );

#ifdef __cplusplus
}
#endif

#include <ins0intosite/libins0intosite_undef.h>
/** @} */
#endif
