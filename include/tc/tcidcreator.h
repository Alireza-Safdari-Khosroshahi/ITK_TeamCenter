/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This include file contains the definitions for the ITK functions to access TcIDCreator.
*/

/*  */

#ifndef TCIDCREATOR_H
#define TCIDCREATOR_H

#include <tc/tcid_errors.h>
#include <tc/libtc_exports.h>

/**
    @defgroup TCID ID Creator
    @ingroup TC

    The set of ITK given here accesses TcIDCreator class, which can be used to 
    format item ids or change ids based on user defined formats. For example if
    a user wants to create an id format which will follow a sequence as given below:

    EC000AA, EC000AB, EC000AC,....,EC752AC, EC752AD,...,ECZZZ98,ECZZZ99.

    then following steps can be used to produce this ID sequence:
    
    @code 
        TCID_create(7,&tcidtag);
        TCID_add_sequence(tcidtag,"1-2","EC",STATIC);
        TCID_add_sequence(tcidtag,"3-5","000",RUNNING);
        TCID_add_sequence(tcidtag,"6-7","AA",RUNNING);
        TCID_save(tcidtag);
    @endcode
    
    Once this is done, every time the function below is called, it returns
    the next id by incrementing it by one.
    
    @code
        TCID_get_next_value(tcidtag,&nextValue);
    @endcode
    @{
*/

/** 
    Type of sequence

    Running Sequence starts from alpha A to Z,a to z or Digit - 0 to 9
*/
#define RUNNING              (1)

/** 
    Type of sequence

    Any Static String sequence
*/
#define STATIC               (2)

#ifdef __cplusplus
extern "C"{
#endif

/**
    This function is used to create an ID format with the specified number of digits. 
    The function #TCID_add_sequence is used to add sequences to the newly create ID Format. 
    The total number of digits specified through the #TCID_add_sequence function calls must be
    equal to the number of digits (number_of_digits) used to create the ID Format.
*/
extern TC_API int TCID_create(
    int             number_of_digits,   /**< (I) Total number of digits required to create an ID Format */
    tag_t*          new_tcid          /**< (O) Tag of the new ID format. */
    );

/**
    Returns the sequence of the digits, starting value and type information of the sequence,
    at the specified index of the ID Format. 
*/
extern TC_API int TCID_ask_sequence(
    tag_t           tcid,     /**< (I) Tag of the ID Format. */
    int             index,      /**< (I) Index of the sequence in the ID format. */
    char**          digSeq,     /**< (OF) Sequence of Digits. */
    char**          start,      /**< (OF) Starting Value of the sequence. */
    int*            type        /**< (O) Type of format, either #STATIC or #RUNNING. */
    );

/**
    This function is used to add a sequence to the ID format. 
*/
extern TC_API int TCID_add_sequence(
    tag_t           tcid,     /**< (I) Tag of the ID Format. */
    char*           digSeq,     /**< (I) Specifies the sequence of Digits(e.g., 1-2, 3-5, etc) */
    char*           start,      /**< (I) Specifies the starting value of the sequence(e.g., 0, AA, AAA etc) */
    int             type        /**< (I) Type of format, either #STATIC or #RUNNING. <br>
                                         #RUNNING sequence starts from alpha (A to Z, a to z)
                                         or it can start from numeric (0 to 9).<br>
                                         #STATIC sequence can be static string sequence. */
    );

/**
    Returns the number of sequences in an ID format.
*/
extern TC_API int TCID_number_of_sequences(
    tag_t           tcid,         /**< (I) Tag of the ID format. */
    int*            n_sequences     /**< (O) Number of sequence in the ID format */
    );

/**
    Saves the changes made to the ID format
*/
extern TC_API int TCID_save(
    tag_t           tcid      /**< (I) Tag of the ID format. */
    );

/**
    Deletes the ID format.
*/
extern TC_API int TCID_delete(
    tag_t           tcid      /**< (I) Tag of the ID format. */
    );

/**
    Returns the next ID value based on the ID format provided as input.
*/
extern TC_API int TCID_get_next_value(
    tag_t           tcid,     /**< (I) Tag of the ID format. */
    char**          nextValue   /**< (OF) Next ID value. */
    );

/** 
    Returns ID length of a given TCID object
*/
extern TC_API int TCID_ask_id_length(
    tag_t           tcid,     /**< (I) */
    int*            length      /**< (O) */
    );

/**
    Returns the initial revision ID as per the ID format provided as input.
    This value is independent of the stored value. 
    This function is used for revision ID generation only.
*/
extern TC_API int TCID_get_initial_value(
    tag_t           tcid,         /**< (I) Tag of the ID format */
    char**          initialValue    /**< (OF) Initial revision ID value */
    );

/**
    Returns the succeeding value of the ID provided as input and also as per the ID format provided as input.
    This value is independent of the stored value. This function is used for revision ID generation only.
*/
extern TC_API int TCID_get_succeeding_value(
    tag_t           tcid,     /**< (I) Tag of the ID format. */
    char*           value,      /**< (I) Revision ID provided as input */
    char**          newValue    /**< (OF) Subsequent revision ID value obtained based on the input ID and ID format */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <tc/libtc_undef.h>

#endif
