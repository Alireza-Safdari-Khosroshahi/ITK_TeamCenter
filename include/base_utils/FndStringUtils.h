/*
Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright 2010.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file
    Provides portablility between "ANSIC" header files.
*/

/*  */

#ifndef FNDSTRINGUTILS_H
#define FNDSTRINGUTILS_H

/** @if DOX_IGNORE
    This should be included by all NX division source files,
    but too much code has got in the habit of assuming this
    header file has done it for them
@endif */
#include <string.h>
#include <common/tc_deprecation_macros.h>
#include <base_utils/libbase_utils_exports.h>


#ifdef __cplusplus
    extern "C"{
#endif

/**
   Returns the number of characters contained in the given string @p s.
   @note The call is safe with a null pointer, for which the returned value is @c 0.
*/
extern BASE_UTILS_API size_t fnd_strlen(
    const char*            s
    );

/**
   Compares two strings.

   @returns
   <ul>
   <li>@c 0 if @p s1 and @p s2 are identical
   <li>a positive number if @p s1 is greater than @p s2.
   <li>a negative number if @p s1 is smaller than @p s2.
   </ul>

   @note The call is safe if @p s1 or @p s2 is null.
   <br/>A null pointer is less than any non-null pointer.
   <br/>Two null pointers compare equivalent.
*/
extern BASE_UTILS_API int fnd_strcmp(
    const char*         s1,  /**< (I) The first string to be compared. */
    const char*         s2   /**< (I) The second string to be compared. */
    );

/**
   @deprecated #fnd_strcpy deprecated in Teamcenter 11.3. Use #fnd_strlcpy instead.
   <br/>fnd_strlcpy specifies the size of the @p destination array, satisfying secure coding 
   guidelines for safe string handling.

   Copies the string @p source into the @p destination array, including the
   terminating null character (and stopping at that point).

   @warning To avoid overflow, the size of the @p destination array shall be
   long enough to contain @p source (including the terminating null character).

   @warning The @p destination must not overlap in memory with @p source.

   @returns The pointer @p destination.

   @note The call is safe for null pointers.
   <br/>If @p destination is a null pointer, no characters will be transferred.
   <br/>Otherwise, if @p source is a null pointer, @p destination will be an
   empty string.
*/
TC_DEPRECATED("11.3","fnd_strcpy","fnd_strlcpy")
extern BASE_UTILS_API char* fnd_strcpy(
    char*                 destination,  /**< (O) The modified string. */
    const char*           source        /**< (I) The string to copy. */
    );

/**
   Copies as much of the string @p source into the @p destination array as will
   fit, according to @p dest_length.  The @p destination is terminated
   with a null character (unless dest_length is @c 0).

   @warning The @p destination must not overlap in memory with @p source.

   @returns The number of bytes, as <tt>strlen(source)</tt>; when <tt> >=
   dest_length</tt>, it means the @p destination buffer is not large enough to
   hold the @p source string.
   
   @remark Typical usage: <tt>strlcpy(destination, source, sizeof(destination))</tt>
*/
extern BASE_UTILS_API size_t strlcpy(
    char*                 destination,  /**< (O) The modified string. */
    const char*           source,       /**< (I) The string to copy. */
    size_t                dest_length   /**< (I) The length of the destination buffer (bytes). */
    );

/**
   Copies as much of the string @p source into the @p destination array as will
   fit, as stated by @p dest_length.  The @p destination is terminated with a
   null character, unless dest_length is @c 0 or the @p destination pointer
   itself is null.

   @warning The @p destination must not overlap in memory with @p source.

   @returns The number of bytes, as <tt>fnd_strlen(source)</tt>; when <tt> >=
   dest_length</tt>, it means the @p destination buffer is not large enough to
   hold the @p source string.

   @note The call is safe for null pointers.
   <br/>If @p destination is a null pointer, no data is transferred, and the
   return value is equivalent to the case when @p dest_length is @c 0.
   <br/>Otherwise, if @p source is a null pointer, it is treated as an empty string.
   
   @remark Typical usage: <tt>fnd_strlcpy(destination, source, sizeof(destination))</tt>
*/
extern BASE_UTILS_API size_t fnd_strlcpy(
    char*                 destination,  /**< (O) The buffer to receive a copy of the string. */
    const char*           source,       /**< (I) The string to copy. */
    size_t                dest_length   /**< (I) The length of the destination buffer (bytes). */
    );

/**
   Copies @p n_bytes characters into @p destination, starting with the
   contents of @p source.

   If the end of @p source (which is signaled by a null character) is found
   before @p n_bytes characters have been copied, @p destination is padded
   with null characters until a total of @p n_bytes characters have been
   written to it.

   @warning No null character is appended at the end of @p destination if @p
   source is longer than @p n_bytes characters, <b>including the
   terminating null character.</b> That is, if (<tt>fnd_strlen(source) + 1 >
   n_bytes</tt>). Thus, in this case, @p destination shall <b>not</b> be
   null-terminated, so it shall not be suitable for use with most string
   functions, because they expect termination with a null character.

   @warning The @p destination must not overlap in memory with @p source.

   @sa @p fnd_strlcpy to copy @p source without padding @p destination, and
   ensuring that the @p destination is null-terminated.

   @note The call is safe for null pointers.
   <br/>If @p destination is a null pointer, no characters will be transferred.
   <br/>Otherwise, if @p source is a null pointer, @p destination will be an
   empty string (without the usual padding).

   @returns The pointer @p destination.
*/
extern BASE_UTILS_API char* fnd_strncpy(
    char*                 destination,   /**< (O) The copied string. */
    const char*           source,        /**< (I) The string to copy. */
    size_t                n_bytes        /**< (I) The number of bytes to copy. */
    );

/**
   Appends as much of the string @p source onto the end of the string in the @p
   destination array as will fit, as stated by @p dest_length.  The @p
   destination is terminated with a null character, unless dest_length is @c 0.

   The terminating null character in @p destination is overwritten by the first character of @p source,
   and a null character is included at the end of the new string formed by the concatenation of both
   in @p destination.

   @warning The @p destination must not overlap in memory with @p source.

   @returns The number of bytes, as <tt>strlen(destination) +
   strlen(source)</tt>; when <tt> >= dest_length</tt>, it means the @p
   destination buffer is too small to append the entire @p source string.
   
   @remark Typical usage: <tt>strlcat(destination, source, sizeof(destination))</tt>
*/
extern BASE_UTILS_API size_t strlcat(
    char*       destination,   /**< (O) The concatenated resulting string. */
    const char* source,        /**< (I) The string to be appended. */
    size_t      dest_length    /**< (I) The length of the destination buffer (bytes). */
    );

/**
   Appends as much of the string @p source onto the end of the string in the @p
   destination array as will fit, as stated by @p dest_length.  The @p
   destination is terminated with a null character, unless dest_length is @c 0
   or the @p destination pointer itself is null.

   The terminating null character in @p destination is overwritten by the first character of @p source,
   and a null character is included at the end of the new string formed by the concatenation of both
   in @p destination.

   @warning The @p destination must not overlap in memory with @p source.

   @note The call is safe for null pointers.
   <br/>If @p destination is a null pointer, no appending will occur.
   <br/>Otherwise, if @p source is a null pointer, nothing will be appended to @p destination.

   @returns The number of bytes, as <tt>fnd_strlen(destination) +
   fnd_strlen(source)</tt>; when <tt> >= dest_length</tt>, it means the @p
   destination buffer is too small to append the entire @p source string.
   
   @remark Typical usage: <tt>fnd_strlcat(destination, source, sizeof(destination))</tt>
*/
extern BASE_UTILS_API size_t fnd_strlcat(
    char*       destination,   /**< (O) The concatenated resulting string. */
    const char* source,        /**< (I) The string to be appended. */
    size_t      dest_length    /**< (I) The length of the destination buffer (bytes). */
    );

/**
   Returns a pointer to the first occurrence of @p match in @p str,
   or a null pointer if @p match is not part of @p str.

   The matching process does not include the terminating null characters, but
   it stops there.

   @note The call is safe for null pointers.
   <br/>If @p str or @p match is a null pointer, a null pointer is returned.
*/
extern BASE_UTILS_API const char* fnd_strstr(
    const char*           str,     /**< (I) The string in which to look. */
    const char*           match    /**< (I) The string to find. */
    );

/**
   Returns a pointer to the first occurrence of @p match in @p str,
   or a null pointer if @p match is not part of @p str.

   The matching process does not include the terminating null characters, but
   it stops there.

   @note The call is safe for null pointers.
   <br/>If @p str or @p match is a null pointer, a null pointer is returned.
*/
extern BASE_UTILS_API char* fnd_modifiable_strstr(
          char*           str,     /**< (I) The string in which to look. */
    const char*           match    /**< (I) The string to find. */
    );

/**
   Converts the input string to upper case.

   It correctly performs the upper case conversion for all character sets.

   @note Use @c free to deallocate the memory @p upper_str. DO NOT use #MEM_free.

   @note The call is safe if @p str is a null pointer. A null pointer is stored
   in @p upper_str.
*/
extern BASE_UTILS_API void fnd_strupr(
    const char*          str,       /**< (I) The string to convert. May be null. */
    char**               upper_str  /**< (OF) The upper case version of the string.
                                     <br/>Use @c free to deallocate the memory. */
    );

/**
   Converts a string to a lower case version.

   It correctly performs the lower case conversion for all character sets.

   @note Use @c free to deallocate the memory @p lower_str. DO NOT use #MEM_free.

   @note The call is safe if @p str is a null pointer. A null pointer is stored
   in @p lower_str.
 */
extern BASE_UTILS_API void fnd_strlower(
    const char*          str,       /**< (I) The string to convert. May be null. */
    char**               lower_str  /**< (OF) The lower case version of the string.
                                       <br/>Use @c free to deallocate the memory. */
    );

#ifdef __cplusplus
} /* extern "C"{ */

inline char* fnd_strstr( /* non-const overload for C++, C-users should use fnd_modifiable_strstr */
          char*           s1,
    const char*           s2
    )
{
    return const_cast< char * >(fnd_strstr( const_cast< const char * >(s1), s2 ));
}

#endif


/** @} */

#include <base_utils/libbase_utils_undef.h>
#endif /* FNDSTRINGUTILS_H */
