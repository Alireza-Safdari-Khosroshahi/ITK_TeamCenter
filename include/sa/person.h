/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This header file declares all the functions to be used
    by clients of the Person class which is part of the System
    Administration module of Teamcenter Engineering.

    <b>Restrictions:</b>

    This include file should not generally be used by anyone.
    Normally sa.h or person.hxx should be included instead.
*/

/*  */

#ifndef PERSON_H
#define PERSON_H

#include <unidefs.h>
#include <sa/libsa_exports.h>

/**
    @defgroup PERSON Person
    @ingroup SA
    @{
*/

#ifdef __cplusplus
    extern "C"{
#endif

/**
    Allocates an array of tags and stores in the array all persons in the database.
*/
extern SA_API int SA_extent_person(
    int*          n_persons,   /**< (O) Number of Persons. */
    tag_t**       persons       /**< (OF) n_persons The persons. */
    );


/**
    Initializes a Person object.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    This function is normally used with a subclass of Person.
    For example, if a you defined a class special Person,
    you would first call #POM_create_instance to create the object in memory. 
    Then you would use this function to initialize the attributes which were inherited from Person.
    Finally, you would use additional POM calls to initialize the attributes comprising your specialization of Person.
*/
extern SA_API int SA_initialize_person2(
    tag_t         person,                       /**< (I) */
    const char    *person_name                      /**< (I) */
    );

/**
    Creates a Person object.
    <br/>It is not saved to the database until an explicit call to #AOM_save occurs.
    You must specify a person_name.

    <b>Restrictions:</b> You can only access this function when logged in as a system or group administrator.
*/
extern SA_API int SA_create_person2(
    const char    *person_name,                     /**< (I) */
    tag_t*        person                        /**< (O) */
    );

/**
    Sets name attribute of the person.
*/
extern SA_API int SA_set_person_name2(
    tag_t         person,                       /**< (I) */
    const char    *person_name                      /**< (I) */
    );

/**
    Rtrieves the value of the name attribute for a person.
*/
extern SA_API int SA_ask_person_name2(
    tag_t         person,                       /**< (I) */
    char          **person_name                     /**< (OF) */
    );

/**
    Retrieves the value of the form name for this person.
    <br/>The form name is the name of the compiled UIL file that contains the form definition.
*/
extern SA_API int SA_ask_person_form_name2(
    tag_t         person,                   /**< (I) */
    char          **form_name                   /**< (OF) */
    );


/**
    Sets form name attribute of the person. 
    <br/>The form name is the name of the compiled UIL file that contains the form definition.
*/
extern SA_API int SA_set_person_form_name2(
    tag_t         person,                   /**< (I) */
    const char    *form_name                    /**< (I) */
    );


/**
    Retrieves the value of the locale for this person.
    <br/>The locale is the name of the compiled UIL file that contains the form definition.
*/
extern SA_API int SA_ask_person_locale2(
    tag_t         person,                   /**< (I) */
    char          **locale                      /**< (OF) */
    );


/**
    Sets locale attribute of the person. 
    <br/>The locale is the name of the compiled UIL file that contains the form definition.
*/
extern SA_API int SA_set_person_locale2(
    tag_t         person_tag,                   /**< (I) */
    const char    *locale                       /**< (I) */
    );
    

/**
    Retrieves the value of the timezone for this person.
    <br/>The timezone is the name of the compiled UIL file that contains the form definition.
*/
extern SA_API int SA_ask_person_timezone2(
    tag_t         person,                   /**< (I) */
    char          **timezone                    /**< (OF) */
    );

    
/**
    Sets timezone attribute of the person. 
    <br/>The timezone is the name of the compiled UIL file that contains the form definition.
*/
extern SA_API int SA_set_person_timezone2(
    tag_t         person,                   /**< (I) */
    const char    *timezone                     /**< (I) */
    );


/**
    Sets attributes of the person. 
    <br/>Valid attributes are PA1, PA2, ..., PA10.
*/
extern SA_API int SA_set_person_attribute2(
    tag_t         person,                            /**< (I) */
    const char    *attribute_name,                       /**< (I) */
    const char    *attribute_value                       /**< (I) */
    );


/**
    Retrieves the value of the person attribute for a person.
    <br/>The caller must provide the name of the attribute which can be one of the following: PA1, PA2, ..., PA10.
*/
extern SA_API int SA_ask_person_attribute2(
    tag_t         person,                            /**< (I) */
    const char    *attribute_name,                       /**< (I) */
    char          **attribute_value                      /**< (OF) */
    );


/**
    Finds a person with the specified name.

    @note If no Person exists with the specified name, #ITK_ok is returned and @p person is #NULLTAG.
*/
extern SA_API int SA_find_person2(
    const char    *person_name,                     /**< (I) */
    tag_t*        person                        /**< (O) */
    );


/**
    Sets the attribute of the person. 
    <br/>Valid attributes are PA1, PA2, ..., PA10.
*/
extern SA_API int SA_set_person_attr2(
    tag_t  person,                                           /**< (I) */
    const char *attribute_name,                                  /**< (I) */
    const char *attribute_value                                  /**< (I) */
    );



/**
    Retrieves the value of the person attribute for a person.
    <br/>The caller must provide the name of the attribute which can be one of the following: PA1, PA2, ..., PA10.
*/
extern SA_API int SA_ask_person_attr2(
    tag_t   person,                                         /**< (I) */
    const char  *attribute_name,                                /**< (I) */
    char        **attribute_value                               /**< (OF) The attribute values. */
    );

/**
    Retrieves the list of mapped attributes for a person.
*/
extern SA_API int SA_get_mapped_person_attr_list(
    int*     n_attributes,   /**< (O) */ 
    char***  list                  /**< (OF) n_attributes */);

/**
    Sets the data source for the person
*/
extern SA_API int SA_set_person_last_sync_date(
    const tag_t     person,                    /**< (I) */
    date_t          sync_date                       /**< (O) */
    );

/**
    Retrieves the person last sync date.
*/
extern SA_API int SA_get_person_last_sync_date(
    const tag_t   person,                     /**< (I) */
    date_t        *sync_date                       /**< (O) */
    );

/**
    Sets the data source for the person
*/
extern SA_API int SA_set_person_data_source(
    const tag_t     person,                     /**< (I) */
    int             data_source                      /**< (I) */
    );

/**
    Retrieves the person data source.
*/
extern SA_API int SA_get_person_data_source(
    const tag_t   person,                     /**< (I) */
    int           *data_source                     /**< (O) */
    );

/**
    Retrieves the email address of the person.
    <br/>If the preference @c TC_use_tc_alias_in_pa8 is set to:
    <ul>
    <li>@c ON, the address in the alias/address list will be retrieved.
    <li>to @c OFF, the email address stored on the person object will be retrieved.
    </ul>
*/
extern SA_API int SA_ask_person_email_address(
    tag_t   person,                                         /**< (I) */
    char    **email_address                                    /**< (OF)*/
    );

/** @} */
#ifdef __cplusplus
}
#endif

#include <sa/libsa_undef.h>

#endif
