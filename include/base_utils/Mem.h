/*
    Copyright 2020 Siemens Digital Industries Software
    ==================================================
    Copyright 2009.
    Siemens Product Lifecycle Management Software Inc.
    All Rights Reserved.
    ==================================================
    Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    Provides specific memory allocation and disposal.
*/

#ifndef TEAMCENTER_BASE_UTILS_MEM_H
#define TEAMCENTER_BASE_UTILS_MEM_H

#include <stdarg.h>
#include <unidefs.h>
#include <stddef.h>
#include <base_utils/libbase_utils_exports.h>

/**
    @defgroup MEM Memory
    @ingroup TC
    @{

    These APIs use NX Storage Management (SM) functionalities, which offers several key features.
    <br>One of them is that the memory is returned to the Operating System once #MEM_free is called. This means that the memory
    footprint of the application just not increases, but can also decrease significantly.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** 
    Allocates a block on <i>n_bytes</i> bytes of memory.
    
    @return On success, a pointer to the allocated block of memory is returned. 
    <br>If <i>n_bytes</i> is zero or any error occurs, a 0 pointer is returned.
 */
extern BASE_UTILS_API void* MEM_alloc(
    int n_bytes    /**< (I) number of bytes to be allocated. */
    );

/** 
    Reallocates memory and copies the existing contents.
    <br>Allocates a new memory block of input size and copies contents of existing memory block.
    <br>Contents of extra memory in new block are undefined.

    If the input pointer is 0, normal allocation is done.
    <br>If <i>n_bytes</i> is zero, existing storage is freed and 0 pointer is returned.
    <br>If <i>n_bytes</i> is less than current size of the memory block, the first <i>n_bytes</i> 
    are copied.

    @return A pointer to new memory block.
 */
extern BASE_UTILS_API void* MEM_realloc(
    void* ptr,       /**< (I) Pointer to a memory block to be reallocated.*/
    int   n_bytes    /**< (I) Number of bytes to be allocated to the new block. */
    );

/**
   Reallocates memory for an array and copies the existing data.
   <br>It works like #MEM_realloc, but this ITK is for arrays. It also initializes extra space with zeroes.

    @return A pointer to the new storage.
 */
extern BASE_UTILS_API void* MEM_crealloc(
    void* ptr,      /**< (I) Pointer to start of array to be reallocated.*/
    int   n_items,  /**< (I) New number of elements in the array. */
    int   item_size /**< (I) New size, in bytes, for a single array element. */
    );

/** 
    Frees the specified memory block.
    <br>The input pointer is expected to be a valid pointer allocated via relevant MEM_ API.
    <br>If <i>ptr</i> is a 0 pointer, no operation is performed.    
 */
extern BASE_UTILS_API void MEM_free(
    void* ptr   /**< (I) Pointer to the block to be freed.*/
    );

/** 
    Makes a copy of a '\0' terminated string.
    @return A pointer to the copy of the input string. <br>It needs to be deallocated through a call to #MEM_free.
 */
extern BASE_UTILS_API char* MEM_string_copy(
    const char* str /**< (I) NULL terminated string to be copied. */
    );

/** 
    Makes a copy of 'n' bytes of a '\0' terminated SM-allocated string. 

    @returns A pointer to the NULL-terminated copy of the input string. 
    <br> It needs to be freed using #MEM_free.
*/
extern BASE_UTILS_API char* MEM_string_ncopy(
    const char *str,                        /**< (I) NULL terminated string to be copied. */
    int n                                   /**< (I) Number of bytes to copy. */
    );

/** 
    Appends a string to an SM allocated string.
    <br>The string pointer @p str must not be used after this call.

    @returns A pointer to the new copy of the input string, in the same type of storage as before.
    <br> It needs to be freed using #MEM_free.
*/
extern BASE_UTILS_API char* MEM_string_append(
    char       *str,                         /**< (I) String in SM allocated memory to have another appended. It must not be NULL. */
    const char *appendage                    /**< (I) String to be appended to the end of str. */
);

/** 
    Appends at most n characters from a string to an SM allocated string.
    <br>The string pointer @p str must not be used after this call.

    @returns A pointer to the new copy of the input string, in the same type of storage as before.
    <br> It needs to be freed using #MEM_free.
*/
extern BASE_UTILS_API char* MEM_string_nappend(
    char       *str,                          /**< (I) String in SM allocated memory to have another appended. It must not be NULL. */
    const char *appendage,                    /**< (I) String to be appended to the end of SM allocated string. */
    int n                                     /**< (I) Number of characters to append. */
);

/** 
    Composes a string with the same text that would be printed if format was used on printf, but
    instead of being printed, the content is stored as a C string in the buffer pointed by string.
    @note The total size of the replaced string must not exceed 255 characters (not including the '\0' termination character). 

    @code
        char * someString = "Example";
        double d = 90;
        char* returnedString = MEM_sprintf ( " Some string %s , Some double %d \n", someString, d );
        [...]
        MEM_free( returnedString ); 
        returnedString = 0;
    @endcode

    @returns The allocated pointer, which will need to be freed using #MEM_free.
*/
extern BASE_UTILS_API char* MEM_sprintf(
    const char *format,                /**< (I) String that contains some ASCII printf formatting: %s (string), %d (integer), etc. */
    ...                                /**< (I) variable arguments */  
    );

/** 
    Composes the result of a formatted string and replacement arguments

    <br/>The format string contains ASCII printf formatting (e.g. %s), and the replacement parameters are in the variable argument @p arg.
    @note The total size of the replaced string must not exceed 255 characters (not including the '\0' termination character). 

    @code
        char * someString = "Example";
        double d = 90;
        char* returnedString = MEM_sprintf ( " Some string %s , Some double %d \n", someString, d );
        [...]
        MEM_free( returnedString ); 
        returnedString = 0;
    @endcode

    @returns The allocated pointer, which will need to be freed using #MEM_free.
*/
extern BASE_UTILS_API char* MEM_vsprintf(
    const char *format,                /**< (I) String that contains some ASCII printf formatting: %s (string), %d (integer), etc. */
    va_list    arg                     /**< (I) variable arguments */  
    );


/**
    Identifies the source data to be packed using #MEM_alloc_packed.
*/
typedef struct MEM_data_to_pack_s
{
    const void *data;                  /**< (I) Pointer to the data to be packed. */
    size_t data_size;                  /**< (I) Data size of the pData pointer. */
} MEM_data_to_pack_t, *MEM_data_to_pack_p_t;

/**
    Allocates and marks a block of memory as packed data. This function is normally used by 
    the Teamcenter::PackedMemory::Builder but can be use like this below:

    @code
        const char *pStringData[] = { "Some strings", "we are packing" };
        const size_t nStrings = sizeof(pStringData) / sizeof(pStringData[0]);

        MEM_data_to_pack_t dataToPack[nStrings + 1] = {
            { NULL, sizeof(pStringData) } ,
            { pStringData[0], strlen(pStringData[0]) + 1 } ,
            { pStringData[1], strlen(pStringData[1]) + 1 }
        };

        char **packedBuffer = (char **)MEM_alloc_packed(dataToPack, nStrings + 1, false);
        for (size_t i = 0; i < nStrings; ++i)
        {
            printf("String[%u]: %s\n", i, packedBuffer[i]);
        }

        MEM_free(packedBuffer);
    @endcode

    @returns The allocated pointer, which will need to be freed using #MEM_free.
*/
extern BASE_UTILS_API void* MEM_alloc_packed(
    size_t n_data,                        /**< (I) The number of structures in @p data_to_pack. */
    MEM_data_to_pack_p_t data_to_pack,    /**< (I/O) n_data Pointer to the data to pack and allocate. <br/>After allocation, the
                                                   @p data_to_pack @p data member will have the new allocation pointer for each of the 
                                                   source data which will be in the storage allocation. If the @p data member has pointer 
                                                   value, this data is also copied to this new location during allocation. Just 
                                                   like a @c realloc would do. */
    logical allow_override                /**< (I) If @c true and the environment variable @c SM_OVERRIDE_PACKING is set to @c 1, the packing 
                                                   will not be done and each data member in @p data_to_pack is allocated using #MEM_alloc. */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <base_utils/libbase_utils_undef.h>

#endif /* TEAMCENTER_BASE_UTILS_MEM_H */
