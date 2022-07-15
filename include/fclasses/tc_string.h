/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Provides portablility between "ANSIC" header files.
*/

/*  */

#ifndef TC_STRING_H
#define TC_STRING_H

/** @if DOX_IGNORE
    This should be included by all NX division source files,
    but too much code has got in the habit of assuming this
    header file has done it for them
@endif */
#include <unidefs.h>
#include <string.h>
#include <common/tc_deprecation_macros.h>
#include <fclasses/libfclasses_exports.h>

/**
    @defgroup TC_STRING Teamcenter String
    @ingroup TC
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
   Returns the number of characters contained in the given string @p s.
   @note The call is safe with null pointer and empty strings, for which the returned value is @c 0.
*/
extern FCLASSES_API size_t tc_strlen(
    const char*            s  /**< (I) The string which length is to be determined. */
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
*/
extern FCLASSES_API int tc_strcmp(
    const char*         s1,  /**< (I) The first string to be compared. */
    const char*         s2   /**< (I) The second string to be compared. */
    );


/**
   Compares two strings regardless of their case.

   @returns
   <ul>
   <li>@c 0 if @p s1 and @p s2 are identical
   <li>a positive number if @p s1 is greater than @p s2.
   <li>a negative number if @p s1 is smaller than @p s2.
   </ul>

   @note The call is safe if @p s1 or @p s2 is null.
*/
extern FCLASSES_API int tc_strcasecmp(
    const char*         s1,  /**< (I) The first string to be compared. */
    const char*         s2   /**< (I) The second string to be compared. */
    );

/**
   Compares two strings up to @p n_characters characters regardless of their case.

   @returns
   <ul>
   <li>@c 0 if @p s1 and @p s2 are identical for up to @p n_characters characters.
   <li>a positive number if @p s1 is greater than @p s2 for up to @p n_characters characters.
   <li>a negative number if @p s1 is smaller than @p s2 for up to @p n_characters characters.
   </ul>

   @note The call is safe if @p s1 or @p s2 is null.
*/
extern FCLASSES_API int tc_strncasecmp(
    const char*         s1,           /**< (I) The first string to be compared. */
    const char*         s2,           /**< (I) The second string to be compared. */
    size_t              n_characters  /**< (I) Number of characters to use for the comparison. */
    );

/**
   Copies the string @p source into the array @p destination, including the terminating null character
   (and stopping at that point).

   <br/>To avoid overflows, the size of @p destination shall be long enough to contain @p source
   (including the terminating null character), and should not overlap in memory with @p source.

   @returns The pointer @p destination.

   @note The call is safe for null pointers.
   <br/>If @p source is a null pointer, @p destination will be an empty string.
   <br/>If @p destination is a null pointer, it will return a null pointer.
*/
extern FCLASSES_API char* tc_strcpy(
    char*                 destination,  /**< (O) The modified string. */
    const char*           source        /**< (I) The string to copy. */
    );

/**
   Copies the first @p n_characters characters of @p source into @p destination.
   <br/>If the end of @p source (which is signaled by a null-character) is found before @p n_characters
   characters have been copied, @p destination is padded with zeros until a total of @p n_characters
   characters have been written to it.
   <br/>No null-character is implicitly appended at the end of @p destination if @p source is longer than
   @p n_characters characters. Thus, in this case, @p destination shall <b>not</b> be considered as null terminated
   (reading it as such would overflow).

   @note @p destination and @p source shall not overlap.

   @note The call is safe for null pointers.
   <br/>If @p source is a null pointer, @p destination will be an empty string.
   <br/>If @p destination is a null pointer, it will return a null pointer.

   @returns The pointer @p destination.
*/
extern FCLASSES_API char* tc_strncpy(
    char*                 destination,   /**< (O) The copied string. */
    const char*           source,        /**< (I) The string to copy. */
    size_t                n_characters   /**< (I) The number of characters to copy. */
    );

/**
   Appends a copy of @p source to @p destination.
   <br/>The terminating null character in @p destination is overwritten by the first character of @p source,
   and a null-character is included at the end of the new string formed by the concatenation of both
   in @p destination.

   @note @p destination and @p source shall not overlap.

   @note The call is safe for null pointers.
   <br/>If @p source is a null pointer, nothing will be appended to @p destination.
   <br/>If @p destination is a null pointer, it will return a null pointer.

   @returns The pointer @p destination.
*/
extern FCLASSES_API char* tc_strcat(
    char*       destination,   /**< (O) The destination pointer which should be large enough to
                                   contain the concatenated resulting string. */
    const char* source         /**< (I) String to be appended. This should not overlap @p destination. */
    );


/**
    Returns a pointer to the first occurrence of @p match in @p str,
    or a null pointer if @p match is not part of @p str.

    <br/>The matching process does not include the terminating null-characters, but it stops there.

   @note The call is safe for null pointers.
   <br/>If @p str or @p match is a null pointer, a null pointer is returned.
*/
extern FCLASSES_API char* tc_strstr(
    const char*           str,     /**< (I) The string in which to look for. */
    const char*           match    /**< (I) The string to find. */
    );


/**
   Converts a string to an upper case version.
   <br/>It correctly performs the upper case conversion for all character sets.

    @note Use @c free to deallocate the memory @p upper_str. DO NOT use #MEM_free.
*/
extern FCLASSES_API void tc_strupr(
    const char*          str,       /**< (I) The string to convert. */
    char**               upper_str  /**< (OF) The upper case version of the string.
                                     <br/>Use @c free to deallocate the memory. */
    );

/**
   Converts a string to a lower case version.
   <br/>It correctly performs the lower case conversion for all character sets.

    @note Use @c free to deallocate the memory @p lower_str. DO NOT use #MEM_free.
 */
extern FCLASSES_API void tc_strlwr(
    const char*          str,       /**< (I) The string to convert. */
    char**               lower_str  /**< (OF) The upper case version of the string.
                                       <br/>Use @c free to deallocate the memory. */
    );

/**
    Converts a string into a long long typed value.

    <br/>If @p str contains non-digits, the conversion is done up to what is possible,
    e.g. @c -123ffs will be converted into the long long typed value @c -123.
*/
extern FCLASSES_API signed long long tc_atoll(
    const char*          str   /**< (I) The string to convert. */
    );

/**
   Duplicates the string @p str into @p copy.
   
   @note Use @c free to deallocate the memory @p copy. DO NOT use #MEM_free.
*/
extern FCLASSES_API void tc_strdup(
    const char*          str,  /**< (I) The string to duplicate. */
    char**               copy  /**< (OF) The copied string. <br/>Use @c free to deallocate the memory. */
    );

/**
   Emulates the behavior of the C strtok utility.
   <br/>It differs from the strtok function in that it only matches the first occurrence 
   of a separator and returns an empty string if 2 separators in a row are found. This allows
   comma-separated lists (for instance) to be processed correctly: <tt>abc,def,,ghi</tt>
*/
extern FCLASSES_API char* tc_strtok(
    char*                 str,         /**< (I) The string to tokenize. */
    const char*           separators   /**< (I) The separators to use for tokenization. */
    );

/**
   Emulates the behavior of the C strtok utility.
   <br/>It differs from the strtok function in that it only matches the first occurrence 
   of a separator and returns an empty string if 2 separators in a row are found. This allows
   comma-separated lists (for instance) to be processed correctly: <tt>abc,def,,ghi</tt>
   <br/><br/>Furthermore, the matched separator is retrieved, which is helpful in knowing if a 
   null pointer is returned because of a gap in the matching sequence (i.e. two consecutive 
   separators in the string), or because the end of the string is reached.
*/
extern FCLASSES_API char* tc_strtok_and_delimiter(
    char*                 str,              /**< (I) The string to tokenize. */
    const char*           separators,       /**< (I) The separators to use for tokenization. */
    char**                matched_separator /**< (OF) The matched separator.
                                               <br/>Use #MEM_free to deallocate the memory. */
    );

/**
   Checks if a string contains any wild card character (for single or multiple character replacement).
   
   <br/>The value used for the wild card characters are defined by the value given to the preference
   "TC_pattern_match_style":
      <table>
      <tr><th>Value</th><th>Multi-character replacement</th><th>Single character replacement</th></tr>
      <tr><td>1</td><td>'%'</td><td>'_'</td>
      <tr><td>2</td><td>'*'</td><td>'.'</td>
      <tr><td>3</td><td>'*'</td><td>'?'</td>
      </table>
      <br/>If no value is provided for the preference, the wild card characters are '%' and'_'.
*/
extern FCLASSES_API void tc_str_contains_wildcard(
    const char*          str,              /**< (I) The string to analyze. */
    logical*             contains_wildcard /**< (O) Indicates if @p str contains a wildcard character. */ 
    );


/**
   Checks if a string contains any wild card character (for single or multiple character replacement),
   and retrieves the position of the first wildcard occurrence.
   
   <br/>The value used for the wild card characters are defined by the value given to the preference
   "TC_pattern_match_style":
      <table>
      <tr><th>Value</th><th>Multi-character replacement</th><th>Single character replacement</th></tr>
      <tr><td>1</td><td>'%'</td><td>'_'</td>
      <tr><td>2</td><td>'*'</td><td>'.'</td>
      <tr><td>3</td><td>'*'</td><td>'?'</td>
      </table>
      <br/>If no value is provided for the preference, the wild card characters are '%' and'_'.
*/
extern FCLASSES_API void tc_str_contains_wildcard_at(
    const char*          str,               /**< (I) The string to analyze. */
    logical*             contains_wildcard, /**< (O) Indicates if @p str contains a wildcard character. */ 
    int*                 position           /**< (O) The position of the first found occurrence. 
                                               <br/>The value is meaningful only if @p contains_wildcard 
                                               is @c true. */
    );

/**
   Copies the first @p n_characters characters of @p source into @p destination.

   <br/>Like #tc_strncpy, this function operates equally well with single or multi-byte characters.
   <br/>It differs from  #tc_strncpy in that the ouput string @p destination
   is always null-terminated.
  
   @returns The pointer @p destination.
*/
extern FCLASSES_API char* STRNG_mb_strncpy(
    char*                 destination,  /**< (O) The copied string. */
    const char*           source,       /**< (I) The string to copy. */
    const int             n_characters  /**< (I) The number of characters to copy. */
    );

/**
   Concatenates @p n_bytes of single and multi-byte characters from the input string @p source into @p destination until:
   <ul>
   <li>@p n_bytes bytes have been copied, or
   <li>a null byte has been copied, or
   <li>a multibyte character would have to be split.
   </ul>
   <br/>If the length of @p source is less than @p n_bytes, only the content up to the terminating null-character is copied.
   <br/>It differs from strncat, in that @p destination is always null-terminated.

   @returns The concatenated string.
*/
extern FCLASSES_API char* STRNG_mb_strncat(
    char*                 destination, /**< (O) The string containing the concatenation. */
    const char*           source,      /**< (O) The source string to concatenate. */
    const int             n_bytes      /**< (I) The number of bytes to copy. */
    );

/**
   Indicates if the input string contains any multibyte character as defined in the current locale.
*/
extern FCLASSES_API logical STRNG_mb_yesno(
    const char*             source    /**< (I) The string to analyze. */
    );


/**
    Converts a given integer into a string in a form like @c "4.2M", @c "3K" or @c "10G" as appropriate.
*/
extern FCLASSES_API void STRNG_MegaBytesToText2(
    long int             large_value,        /**< (I) The large value. */
    char                 **text              /**< (OF) The string that contains the conversion.
                                              <br/>It must be deallocated using #MEM_free. */
    );

/**
   @deprecated #STRNG_to_lower deprecated in Teamcenter 10.1.7. Use #STRNG_to_lower2 instead.

   Converts A-Z to lower case in the given string @p str, coping even if it is a multibyte string.

   @note It contains some known issues with non-ascii characters.
*/
TC_DEPRECATED("10.1.7","STRNG_to_lower","STRNG_to_lower2")
extern FCLASSES_API void STRNG_to_lower(
    char*          str    /**< (I/O) The string to convert. */
    );

/**
   @deprecated #STRNG_to_upper deprecated in Teamcenter 10.1.7. Use #STRNG_to_upper2 instead.

   Converts A-Z to upper case in given string, coping even if it is a multibyte string.

   @note It contains some known issues with non-ascii characters.
*/
TC_DEPRECATED("10.1.7","STRNG_to_upper","STRNG_to_upper2")
extern FCLASSES_API void STRNG_to_upper(
    char*          str    /**< (I/O) The string to convert. */
    );


/**
   Converts a string to a lower case version.
   <br/>It correctly performs the lower case conversion for all character sets.
*/
extern FCLASSES_API void STRNG_to_lower2(
    const char*          str,       /**< (I) The string to convert. */
    char**               lower_str  /**< (OF) The upper case version of the string.
                                       <br/>Use @c free to deallocate the memory. */
    );

/**
   Converts a string to an upper case version.
   <br/>It correctly performs the upper case conversion for all character sets.
*/
extern FCLASSES_API void STRNG_to_upper2(
    const char*          str,       /**< (I) The string to convert. */
    char**               upper_str  /**< (OF) The upper case version of the string.
                                       <br/>Use @c free to deallocate the memory. */
    );

/**
   Replaces all ASCII non-alphanummeric characters to <tt>'_'</tt> but leave multibyte characters alone.
*/
extern FCLASSES_API void STRNG_clean_up_string(
    char*                str       /**< (I/O) The string to clean. */
    );

/**
   Replaces all characters not present in provided character list by a given character.
   <br/>Multibyte characters are not affected.
   @code
   STRNG_limit_characters( name_to_clean, 
                           "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890-_~", 
                           '_'
                         );
   @endcode
*/
extern FCLASSES_API void STRNG_limit_characters(
    char*                str,            /**< (I/O) The string to clean. */
    const char*          character_list, /**< (I) The list of characters to keep. */
    char                 replacement     /**< (I) The replacement character. */
    );

/**
    Returns a pointer (or NULL) to the first match of the given ASCII character,
    even in the face of multibyte characters. 
    <br/>The given character must be a single-byte character.
*/
extern FCLASSES_API char* STRNG_find_first_char(
    const char*           source,  /**< (I) The string to analyze. */
    const char            match    /**< (I) The character to find. */
    );

/**
    Returns a pointer (or NULL) to the last match of the given ASCII character,
    even in the face of multibyte characters. 
    <br/>The given character must be a single-byte character.
*/
extern FCLASSES_API char* STRNG_find_last_char(
    const char*           source,  /**< (I) The string to analyze. */
    const char            match    /**< (I) The character to find. */
    );

/**
    Substitutes special XML characters in a string with their XML representations.
    <br/>The changes are done in the following fashion:
    <table>
    <tr><th>Character</th><th>Replacement</th></tr>
    <tr><td>&</td><td>&amp;amp;</td></tr>
    <tr><td>&lt;</td><td>&amp;lt;</td></tr>
    <tr><td>&gt;</td><td>&amp;gt;</td></tr>
    <tr><td>%</td><td></td>&amp;\#x25;</tr>
    <tr><td>"</td><td>&amp;quot;</td></tr>
    <tr><td>'</td><td>&amp;apos;</td></tr>
    <tr><td>\\r\\n</td><td>&amp;\#xD;&amp;\#xA;</td></tr>
    <tr><td>\\n</td><td>&amp;\#xD;</td></tr>
    <tr><td>\\r</td><td>&amp;\#xA;</td></tr>
    <tr><td>\\t</td><td>&amp;\#x9;</td></tr>
    <tr><td>\\</td><td>\\\\</td></tr>
    </table>

    @returns #ITK_ok always
*/
extern FCLASSES_API int STRNG_quote_xml(
    const char* original_string,      /**< (I) The string to quote. */
    char**      modified_string       /**< (OF) The quoted string.
                                         <br/>The memory should be deallocated using #MEM_free.*/
    );

/**
    Strips off any leading and trailing blank spaces from a provided string.
    
    @note Only deallocate the memory from the input string @p str.

    @returns The stripped string.
*/
extern FCLASSES_API char* stripBlanks(
    char* str  /**< (I/O) The string to strip. */
    );

/**
    Checks if a string ends with a given character.
*/
extern FCLASSES_API logical STRNG_ends_with(
    const char* source,    /**< (I) The string to check. */ 
    const char* ending     /**< (I) The string to find. */
    );

/**
   Replaces all the occurrences of string with a given replacement.
   
   @returns #ITK_ok always.
*/
extern FCLASSES_API int STRNG_replace_str(
    const char*         source,      /**< (I) The string to analyze. */
    const char*         occurrence,  /**< (I) The string to find. */
    const char*         replacement, /**< (I) The replacement string. */
    char**              destination  /**< (OF) The modified string. 
                                        <br/>Use #MEM_free to deallocate the memory. */
    );

/**
    Determines if a string represents a @c double, and converts it.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#STRNG_not_a_double if @p source does not represent a @c double.
    </ul>
*/
extern FCLASSES_API int STRNG_is_double(
    const char* source, /**< (I) The string to analyze. */
    double* value       /**< (O) The double value. */
    );


/**
    Determines if a string is a unique character.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#STRNG_not_a_char if @p source is a null pointer or a string with more or less than one character.
    </ul>
*/
extern FCLASSES_API int STRNG_is_char(
    const char* source, /**< (I) The string to analyze. */
    char* character     /**< (O) The only character in the string. */
    );

/**
    Determines if a string is a logical, and converts it.
    <br/>The function will strip the input string of any leading and trailing white characters.
    <br/>The determination is based on case insensitive comparisons using the following information:
    <ul>
    <li>For @c true: the TextServer resources of key @c gk_logical_true_label, "y", "true", "1", "t".
    <li>For @c false: the TextServer resources of key @c gk_logical_false_label, "n", "false", "0", "f".
    </ul>

    @note The TextServer resources are different depending on the current language of the server.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#STRNG_not_a_logical if the string is not a @c logical.
    </ul>
*/
extern FCLASSES_API int STRNG_is_logical(
    const char* source,   /**< (I) The string to analyze. */
    logical* value        /**< (O) The logical value. */
    );

/**
    Determines if a string is an integer, and converts it.

    @returns
    <ul>
    <li>#ITK_ok on success.
    <li>#STRNG_not_an_integer if the string is not an integer.
    <li>#STRNG_integer_out_of_range if the integer value contained by the string is out of range
    for programming integer values.
    </ul>
*/
extern FCLASSES_API int STRNG_is_integer(
    const char* source, /**< (I) The string to analyze. */
    int* value          /**< (O) The integer value */
    );

/**
    Checks if a pattern is found in a string, offering customer defined matching characters.

    <br/>The special characters in the string from the @p pattern parameter are:
    <ul>
    <li>@p escape: this character is ignored and the following one is taken literally
    <li>@p any: matches any character (zero or more characters)
    <li>@p one: matches any character (one only)
    </ul>

    @note The wild characters are considered case sensitive, but not other in the @p pattern 
    and @p match strings.

    The following examples return @c true:
    <br/>
    @code
    STRNG_compare_wildcard_i ('@', '*', '.', "abc", "abc")
    STRNG_compare_wildcard_i ('@', '*', '.', "*abc...", "abcANY")
    STRNG_compare_wildcard_i ('@', '*', '.', "*abc...", "anything abcANY")
    STRNG_compare_wildcard_i ('@', '*', '.', "@*abc...", "*abcANY")
    @endcode

    @returns #true on success
*/
extern FCLASSES_API logical STRNG_compare_wildcard_i(
    char escape,         /**< (I) Escape character to be used in the pattern ('\' for example) */
    char any,            /**< (I) Wild match character to be used in the pattern ('*' for instance) */
    char one,            /**< (I) Unique match character to be used in the pattern ('?' for instance). 
                           <br/>It matches exactly one character. */
    const char *pattern, /**< (I) Input pattern string */
    const char *match    /**< (I) Input match string */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <fclasses/libfclasses_undef.h>
#endif
