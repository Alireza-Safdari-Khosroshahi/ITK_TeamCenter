/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Text Server function prototypes
*/

/*  */

#ifndef TEXTSERVER_H
#define TEXTSERVER_H

#include <base_utils/Mem.h>
#include <common/tc_deprecation_macros.h>

#include <textsrv/libtextsrv_exports.h>

/**
    @defgroup TEXT_SERVER Text Server
    @ingroup TC

    Enables retrieving of text resources (translatable and non-translatable, as stored in TextServer xml files).
    @{
*/

/**
   @name Translation Statuses
   Definition of the different translation status codes applied to translatable properties
   @{
*/
  /** Defines the translation status of Master */
#define TC_TRANSLATIONSTATUS_master       'M'

/** Defines the translation status of Approved */
#define TC_TRANSLATIONSTATUS_approved     'A'

/** Defines the translation status of Pending */
#define TC_TRANSLATIONSTATUS_pending      'P'

/** Defines the translation status of In Review */
#define TC_TRANSLATIONSTATUS_in_review    'R'

/** Defines the translation status of Invalid */
#define TC_TRANSLATIONSTATUS_invalid      'I'

/** Defines the translation status of Ghost. This is purely for internal processing */
#define TC_TRANSLATIONSTATUS_ghost        'G'
/** @} */

/**
    Defines a pointer to a TextServer object.
*/
typedef void* txt_t;            

#ifdef __cplusplus
 extern "C"{
#endif

     /**
        Retrieves a text resource through the key identifier, and substitutes the potential string parameters with the input parameters.
        <br/>If a parameter is not needed, a null pointer can be provided.

        @code
        //Let us consider retrieving the text resource identified in a TextServer xml file as:
        // <key id="k_soft_warning_email_comments">The remaining monthly usage for the user &quot;%1$&quot; is %2$ unique calendar days and %3$ hours before reaching the limit of usage for an occasional user.</key>
        char* substituted_message = 0;
        if( ITK_ok == TXTSRV_get_substituted_text_resource( "k_soft_warning_email_comments", "User A", "21", "7", 0, 0, 0, 0, &substituted_message ) )
        {
           //The substituted message will be:
           //'The remaining monthly usage for the user "User A" is 21 unique calendar days and 7 hours before reaching the limit of usage for an occasional user.'
           [...]
        }
        else
        {
           //The resource key is not found...
        }
        @endcode

        @note This only applies to text resources, and not error resources. For error resources, use #EMH_ask_error_text.

        @returns 
        <ul>
        <li>#ITK_ok on success
        <li>#TEXTSRV_ERR_text_key_not_found if the specified resource key is not found. The returned pointer is null in this case.
        </ul>
     */
     extern TEXTSRV_API int TXTSRV_get_substituted_text_resource( 
         const char* key,                  /**< (I) The key used to retrieve the text resource from the xml file. */
         const char* parameter_1,          /**< (I) The value to be substituted to the first parameter. */    
         const char* parameter_2,          /**< (I) The value to be substituted to the second parameter. */    
         const char* parameter_3,          /**< (I) The value to be substituted to the third parameter. */    
         const char* parameter_4,          /**< (I) The value to be substituted to the fourth parameter. */    
         const char* parameter_5,          /**< (I) The value to be substituted to the fifth parameter. */    
         const char* parameter_6,          /**< (I) The value to be substituted to the sixth parameter. */    
         const char* parameter_7,          /**< (I) The value to be substituted to the seventh parameter. */    
         char** substituted_text_resource  /**< (OF) The substituted text resource */
         );
         
     /**
        Retrieves a text resource through the key identifier.
        <br/>If the resource does not contain any parameter, this will be equivalent to calling #TXTSRV_get_substituted_text_resource 
        and providing a null pointer for each parameter.
        <br/>If the resource contains some parameters, the string will show the unsubstituted parameters (e.g. 'The remaining monthly
        usage for the user "%1$" is %2$ unique calendar days and %3$ hours before reaching the limit of usage for an occasional user.').

        @note This only applies to text resources, and not error resources. For error resources, use #EMH_ask_error_text.

        @returns 
        <ul>
        <li>#ITK_ok on success (the resource key is found)
        <li>#TEXTSRV_ERR_text_key_not_found if the specified resource key is not found. The returned pointer is null in this case.
        </ul>
     */
     extern TEXTSRV_API int TXTSRV_get_unsubstituted_text_resource( 
         const char* key,                  /**< (I) The key used to retrieve the text resource from the xml file. */
         char** substituted_text_resource  /**< (OF) The substituted text resource */
         );
         

     /**
        @deprecated #txt_ctor deprecated in Teamcenter 10.1.3. Use #TXTSRV_get_substituted_text_resource instead.
     */
     TC_DEPRECATED( "10.1.3", "txt_ctor", "TXTSRV_get_substituted_text_resource" )
     extern TEXTSRV_API txt_t txt_ctor(
         const char*
         );
     
     /**
        @deprecated #txt_destructor deprecated in Teamcenter 10.1.3. Use #TXTSRV_get_substituted_text_resource instead.
     */
     TC_DEPRECATED( "10.1.3", "txt_destructor", "TXTSRV_get_substituted_text_resource" )
     extern TEXTSRV_API void txt_destructor(
         txt_t               ts
         );
     
     /**
        @deprecated #txt_subText deprecated in Teamcenter 10.1.3. Use #TXTSRV_get_substituted_text_resource instead.
     */
     TC_DEPRECATED( "10.1.3", "txt_subText", "TXTSRV_get_substituted_text_resource" )
     extern TEXTSRV_API char* txt_subText(
         txt_t,
         const char*,
         int,
         const char*          s1,
         const char*          s2,
         const char*          s3,
         const char*          s4,
         const char*          s5
         );
     
     /**
        @deprecated #txt_noSubText deprecated in Teamcenter 10.1.3. Use #TXTSRV_get_unsubstituted_text_resource instead.

        Returns the text resource without any substitution.
     */
     TC_DEPRECATED( "10.1.3", "txt_noSubText", "TXTSRV_get_unsubstituted_text_resource" )
     extern TEXTSRV_API char*  txt_noSubText(
         txt_t,
         const char*,
         int
         );
     
         
     /**
        Returns the text resource through the key identifier.
        <br/>Use preferably #TXTSRV_get_substituted_text_resource or #TXTSRV_get_unsubstituted_text_resource instead.
     */
     extern TEXTSRV_API char* TC_text(
         const char*          key
         );
     
     /**
        Returns the text resource through the key identifier and replaces the first parameter of the string.
        <br/>Use preferably #TXTSRV_get_substituted_text_resource instead.
     */
     extern TEXTSRV_API char* TC_text_arg(
         const char *  key,
         const char * arg
         );
     
     /**
        Returns the text resource through the key identifier, and raises and error (through ERROR_internal) if no translation is found.
        <br/>Use preferably #TXTSRV_get_substituted_text_resource or #TXTSRV_get_unsubstituted_text_resource instead.
     */
     extern TEXTSRV_API char* TC_text_required(
         const char*          key
         );
     
     /**
        Returns the name of the product.
     */
     extern TEXTSRV_API char* TC_product_text(
         const char*          key
         );
     
     /**
        Returns the Teamcenter text for a key *without* substituting the \%n\$ values
        Use preferably #TXTSRV_get_substituted_text_resource or #TXTSRV_get_unsubstituted_text_resource instead.
     */
     extern TEXTSRV_API char* TC_unsubst_text(
         const char*          key
         );
     
     /**
        @deprecated #TC_hier_text deprecated in Teamcenter 10.1.3.

        Use key to fetch string from a hier, either in gizmolocal.uih or
        a local.uih, when given an hierarchy name
     */
     TC_DEPRECATED_NO_REPLACEMENT( "10.1.3", "TC_hier_text" )
     extern TEXTSRV_API char* TC_hier_text(
         const char*          hierarchy_name,
         const char*          key
         );
     
     /**
        Used in a Thin client connection configuration in order to present the locale rejection message.
        Once the call is made, any subsequent calls will return an empty string.
     */ 
     extern TEXTSRV_API int TC_text_get_locales_check_message (
        char** warning_message   /**< (OF) Warning message */
        );
     
     /**
        Returns the W3C-standardized locale being requested and served for the connection with the TCServer.
        This information is mainly used by the Thin client.
        For instance, the Thin client can request a connection in Austrian German (de-AT), which will be
        served in German German (de_DE) internally (internal locale format is Java standard).
     */
     extern TEXTSRV_API int TC_text_get_current_W3C_locale (
         char** current_w3_locale  /**< (OF) Current W3C-standardized locale */
         );
     
     /**
        Returns the Java-standardized locale being used by the TCServer.
        For instance, the client can request a connection in Canadian French, which will be 
        served in French French (fr_FR) internally (internal locale format is Java standard).
     */
     extern TEXTSRV_API int TC_text_get_current_Java_locale (
         char** current_java_locale  /**< (OF) Current Java-standardized locale */
         );
         
    /**
        Retrieves the ordered list of Java-standard formatted values of languages that can be used for displaying localized property values.
        <br/>The associated access methods need to do the following operations:
        <ul>
        <li>Retrieve the value from the preference "TC_language_localized_property_value_display" from all locations.
        <li>Add the connection locale at the end of the list.
        <li>Use the first locale supported by the system.
        </ul>

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#TEXTSRV_ERR_no_supported_language if no supported language code is found
        </ul>
    */
    extern TEXTSRV_API int TXTSRV_get_localized_property_value_display_languages (
        int* nb_of_languages,          /**< (O)   Number of languages */
        char*** language_code_list,    /**< (OF)  nb_of_languages Lists of 5-letter codes of all the languages that can be used for localized property value display.  */
        char*** language_name_list     /**< (OF)  nb_of_languages Lists the localized names of all the languages that can be used for localized property value display. */
        );
    
    /**
       Retrieves the Java-standard formatted name of the language to be used for localized property 
       values entries.
       The preference value should always be retrieved using the associated ITK API or SOA operation. 
       The TC_language_data_entry (Site) defines the list of locales to be used for data entry. 
       The TC_language_localized_property_value_entry (User, Role, Group, Site) defines the sub-value 
       as preferred by the user.
       Since both preference entry are a result of manual modifications, we need to check that they 
       are not off from the reality.
       Therefore, the check will be:
       1. Retrieve the values from the preference itself as defined at the User, Role, Group and Site
       levels, and only keep the ones supported by the system.
       
       2. Retrieve the values from the preference TC_language_data_entry.
       a. If there are values for TC_language_data_entry, only keep the preference values from step 1
       that are in that list.
       b. If there is no value for TC_language_data_entry, keep all the preference values from step 1.
       
       3. If the list is empty, add the Master locale as defined in the BMIDE global constant
       
       4. Return the first value of the list.
     */
    extern TEXTSRV_API int TXTSRV_get_localized_property_value_entry_language (
        char** language_code, /**< (OF)  5-letter code of the language used for localized property value entry. */
        char** language_name  /**< (OF)  Localized name of the language used for localized property value entry. */
        );


    /**
       Retrieves the Java-standard formatted name of the language used for Search operations.
       <br/>It is determined in the following manner:
       <ul>
       <li>Retrieve the value from the preference "TC_language_search" from all locations.
       <li>Add the connection locale at the end of the list.
       <li>Use the first locale supported by the system.
       </ul>
       
       @returns #ITK_ok always
    */
    extern TEXTSRV_API int TXTSRV_get_search_language (
        char** language_code, /**< (OF)  5-letter code of the language used for Search operations.  */
        char** language_name  /**< (OF)  Localized name of the language used for Search operations. */
        );


    /**
       Retrieves the list of Java-standard formatted name of languages that are supported by the system
       (i.e. the server machine and the database).
     */
    extern TEXTSRV_API int TXTSRV_get_supported_languages_list (
        int* n_languages,           /**< (O)  Number of languages */
        char*** language_code_list, /**< (OF) n_languages Lists of 5-letter codes of all the languages supported by the system. */
        char*** language_name_list  /**< (OF) n_languages Lists the localized names of all the languages supported by the system. */
        );

     /**
        Retrieves the list of Java-standard formatted name of languages that are supported by the system and specified
        in the BMIDE Global Constant Fnd0SelectedLocales.
        (i.e. intersection of the server machine, the database and Global Constant).

        @returns
        <ul>
        <li>#ITK_ok on success
        <li>#TEXTSRV_ERR_no_supported_language if no supported language code is found
        </ul>
     */
    extern TEXTSRV_API int TXTSRV_get_localized_languages_list (
        int* n_languages,           /**< (O)  Number of languages */
        char*** language_code_list, /**< (OF) n_languages Lists of 5-letter codes of all the languages supported by the system. */
        char*** language_name_list  /**< (OF) n_languages Lists the localized names of all the languages supported by the system and Fnd0SelectedLocales. */
        );

    /**
       Returns the name and the description associated with a given translation status code.
    */
    extern TEXTSRV_API int TXTSRV_getTranslationStatusNameAndDescription (
        char translation_status_code,         /**< (I) The translation status code for which the information is requested. */
        char** translation_status_name,       /**< (OF) The localized name for the requested status. */
        char** translation_status_description /**< (OF) The localized description for the requested status. */
        );
    
    /**
       Returns the localized names and descriptions of all the translation statuses, 
       in the predefined logical order Master, Approved, Pending, In Review.
     */
    extern TEXTSRV_API int TXTSRV_getAllTranslationStatusNamesAndDescriptions (
        int* number_of_statuses,                 /**< (O)  The number of translation statuses. */
        char*** translation_status_names,        /**< (OF) number_of_statuses An ordered array of localized translation status names. */
        char*** translation_status_descriptions  /**< (OF) number_of_statuses An ordered array of localized translation status descriptions. */
        ); 
    
    /**
       Returns the codes, localized names and descriptions of all the translation statuses.
     */
    extern TEXTSRV_API int TXTSRV_getAllTranslationStatusCodesNamesAndDescriptions (
        int* number_of_statuses,                 /**< (O)  The number of translation statuses. */
        char** translation_status_codes,         /**< (OF) number_of_statuses An ordered array of char representing the different statuses. */
        char*** translation_status_names,        /**< (OF) number_of_statuses An ordered array of localized translation status names. */
        char*** translation_status_descriptions  /**< (OF) number_of_statuses An ordered array of localized translation status descriptions. */
        );

    /**
       Provides a means to convert a status from a name to its actual code representation.
       The name can be:
       <ul>
       <li>either the display name (e.g. "En Revue" in French), 
       <li>or the internal name: "Master", "Approved", "Pending", "In Review", "Invalid" or "Ghost"
       <li>or the status code (#TC_TRANSLATIONSTATUS_master, #TC_TRANSLATIONSTATUS_approved, #TC_TRANSLATIONSTATUS_pending,
       #TC_TRANSLATIONSTATUS_in_review, #TC_TRANSLATIONSTATUS_invalid, #TC_TRANSLATIONSTATUS_ghost )
       </ul>

       The method returns:
       <ul>
       <li>#TEXTSRV_ERR_no_status_names if initialization of the status names has failed.
       <li>#TEXTSRV_ERR_unsupported_status if the provided name does not correspond to any status.
       </ul>
    */
    extern TEXTSRV_API int TXTSRV_convertStatusFromStringToCode (
        char* translation_status_name, /**< (I)  The name of the status. */
        char* translation_status_code  /**< (O)  The status code corresponding to the status name. */
        );


    /**
       Provides a means to convert a status from its actual code to its localized name.
    */
    extern TEXTSRV_API int TXTSRV_convertStatusFromCodeToString(
        char translation_status_code,   /**< (I)  The internal representation of the status. */
        char** translation_status_name  /**< (0F) The localized name of the status. */
    );

    /**
       Provides a means to convert a status from its code to its internal name.
       <br/>The code can be any of the following:
       <ul>
       <li>#TC_TRANSLATIONSTATUS_master, #TC_TRANSLATIONSTATUS_approved, #TC_TRANSLATIONSTATUS_in_review,
       #TC_TRANSLATIONSTATUS_pending, #TC_TRANSLATIONSTATUS_invalid, #TC_TRANSLATIONSTATUS_ghost
       </ul>

       @returns
       <ul>
       <li>#ITK_ok on success
       <li>#TEXTSRV_ERR_unsupported_status if the provided code does not correspond to any status.
       </ul>
    */
    extern TEXTSRV_API int TXTSRV_convertStatusFromCodeToInternalString( 
        char    translation_status_code,                /**< (I)  The internal representation of the status. */
        char**  translation_status_internal_name        /**< (0F) The internal name of the status. */  
    );

    /**
       Provides the site master language if set otherwise returns the current 
       locale.
    */
    extern TEXTSRV_API int TXTSRV_get_site_master_language (
        char** language_code, /**< (OF)  5-letter code of the language used for localized property value entry. */
        char** language_name  /**< (OF)  Localized name of the language used for localized property value entry. */
    );

#ifdef __cplusplus
}
#endif


/** 
    @deprecated #TC_free_text deprecated in Teamcenter 10.1.3. Use #MEM_free instead.

    Frees the specified block of storage (transient or persistent) for reuse. 
    <br/>If the pointer is a NULL value then no operation is performed.

    @param[in] void *ptr The pointer to a block of memory to be deallocated.
*/
#define TC_free_text MEM_free
TC_DEPRECATED_PREPROCESSOR( "10.1.3", TC_free_text, "MEM_free" )

/**
    Macro for no variable substitution (i.e. the text resource does not contain any parameter). 
*/
#define txt_text(ts,keyStr) txt_noSubText(ts, keyStr, 0)

/**
    Macro for one variable substitution (i.e. the text resource contains only one parameter). 
*/
#define txt_texts(ts,keyStr,subStr) txt_subText(ts, keyStr, 0, subStr, NULL, NULL, NULL, NULL)

/** @} */

#include <textsrv/libtextsrv_undef.h>
#endif
