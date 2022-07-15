/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2012_09_PREFERENCEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2012_09_PREFERENCEMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            namespace _2012_09
            {
                class Preferencemanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Preferencemanagement
{
public:

    struct PreferenceDefinition;
    struct PreferenceValue;
    struct CompletePreference;
    struct GetPreferencesAtLocationsResponse;
    struct GetPreferencesResponse;
    struct PreferenceLocation;
    struct ImportPreferencesAtLocationDryRunIn;
    struct ImportPreferencesAtLocationDryRunResponse;
    struct ImportPreferencesAtLocationsIn;
    struct PreferenceResponseWithFileTicket;
    struct PreferencesAtLocationIn;
    struct SetPreferences2In;
    struct SetPreferencesAtLocationsIn;
    struct SetPreferencesDefinitionIn;

    /**
     * Contains all the preference definition details.
     */
    struct PreferenceDefinition
    {
        /**
         * The name of the preference.
         */
        std::string name;
        /**
         * The name of the category where the preference is sorted.
         * <br>
         * A category is a logical group of preferences.
         */
        std::string category;
        /**
         * The description associated with the preference.
         */
        std::string description;
        /**
         * Type of the preference.
         * <br>
         * Values are:
         * <br>
         * <ul>
         * <li type="disc">0 : String preference
         * </li>
         * <li type="disc">1: Logical preference
         * </li>
         * <li type="disc">2: Integer preference
         * </li>
         * <li type="disc">3: Double preference
         * </li>
         * <li type="disc">4: Date preference
         * </li>
         * </ul>
         */
        int type;
        /**
         * Determines if the preference is multi-valued.
         */
        bool isArray;
        /**
         * Determines if the preference is disabled.
         * <br>
         * If this is set to false, preference values and definition can be modified.
         * <br>
         * If this is set to true, no change can be made to the preference values at any location.
         */
        bool isDisabled;
        /**
         * Determines the protection scope of the preference, which is who is the lowest person
         * (in the organization) who is allowed to provide values. Valid values are User, Role,
         * Group, Site, System.
         */
        std::string protectionScope;
        /**
         * Determines if the value can be taken from an environment variable.
         */
        bool isEnvEnabled;
        /**
         * Determines if the preference is defined out-of-the-box.
         */
        bool isOOTBPreference;
    };

    /**
     * Contains the preference value and its location.
     * <br>
     * This structure is used by different operations with different possible values for
     * the location parameter.
     */
    struct PreferenceValue
    {
        /**
         * The values associated with this preference.
         */
        std::vector< std::string > values;
        /**
         * Defines where the preference values are coming from.
         * <br>
         * Valid values are:
         * <br>
         * <ul>
         * <li type="disc">"<b>COTS</b>": The value is the one defined by Siemens.
         * </li>
         * <li type="disc">"<b>Overlay</b>":  The COTS value has been altered.
         * </li>
         * <li type="disc">"<b>Group</b>": The value is defined at the group level.
         * </li>
         * <li type="disc">"<b>Role</b>": The value is defined at the role level.
         * </li>
         * <li type="disc">"<b>User</b>": The value is defined at the user level.
         * </li>
         * <li type="disc">"<b>Env</b>": The value is coming from an environment variable.
         * </li>
         * </ul>
         */
        std::string valueOrigination;
    };

    /**
     * Composite structure completely representing a preference: its definition is captured
     * in the <b>PreferenceDefinition</b> structure, and its values in the <b>PreferenceValue</b>
     * structure.
     */
    struct CompletePreference
    {
        /**
         * A structure holding all the preference definition parameters.
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceDefinition definition;
        /**
         * A structure holding the preference values.
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceValue values;
    };

    /**
     * Structure returned by the <code>getPreferencesAtLocation</code> operation.
     */
    struct GetPreferencesAtLocationsResponse
    {
        /**
         * Partial errors. Each partial error will contain the index of the related input data.
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * The preference description and category for the locations OOTB (out-of-the-box),
         * Overlay or Site. In the other cases, those strings will be empty.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::CompletePreference > responses;
    };

    /**
     * Contains the preference information (value and description if requested), as well
     * as any potential partial errors.
     */
    struct GetPreferencesResponse
    {
        /**
         * Contains the partial errors in the same order as in the input list.
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * A list of complete preference information.
         * <br>
         * Each structure holds all the preference definition (<code>PreferenceDefinition</code>
         * structure) and its values (<code>PreferenceValue</code> structure).
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::CompletePreference > response;
    };

    /**
     * Defines where the preference is to be retrieved.
     * <br>
     * This structure is used by different operations with different possible values for
     * the location parameter.
     */
    struct PreferenceLocation
    {
        /**
         * Object where the preferences will be retrieved. This can be a User, Role or Group.
         * <br>
         * This value can only be used if the location string is empty.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Name of the location.
         * <br>
         * This value can only be specified if the object is not specified.
         */
        std::string location;
    };

    /**
     * A structure that contains all the parameters for the import dry run operation.
     */
    struct ImportPreferencesAtLocationDryRunIn
    {
        /**
         * Location where to simulate the import.
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceLocation location;
        /**
         * Ticket of the input XML file in the transient volume uploaded by the client
         */
        std::string fileTicket;
        /**
         * Vector of category names to be considered for import. No value means import all categories
         */
        std::vector< std::string > categoryNames;
    };

    /**
     * Response from importPreferencesAtLocationDryRun operation.
     */
    struct ImportPreferencesAtLocationDryRunResponse
    {
        /**
         * A ServiceData structure. The following partial errors will be returned:  * An error
         * 1759 will be returned if the preference name is empty.   * An error 1760 will be
         * returned if the preference name is invalid ("*" for instance).   * An error 1700
         * will be returned if the preference does not exist.  * An error 1751 will be returned
         * if the specified object information does not correspond to any user, role or group.
         * * An error 1752 will be returned if both an object and a location are specified
         * for an entry.  * An error 1753 will be returned if the specified location is invalid.
         * * An error 1725 will be returned if the logged-in user does not have the requested
         * permission to carry-out the operation.  * An error 1728 will be returned in case
         * the protection scope of the preference prevents a creation of one instance at the
         * specified location.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of preferences in the database that would be impacted by the import.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::CompletePreference > dbImpactedPreferences;
        /**
         * Llist of preferences from the input file, for which conflict will arise.  Conflicts
         * are cases in which either the preference already exists in the database and is different,
         * or the preference does not exist in the database yet.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::CompletePreference > conflictingPreferencesFromFile;
    };

    /**
     * A structure that contains all the parameters for the import operation.
     */
    struct ImportPreferencesAtLocationsIn
    {
        /**
         * A list of structures defining where the preferences are to be imported.
         */
        std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceLocation > locations;
        /**
         * Ticket of the input XML file in the transient volume uploaded by the client.
         */
        std::string fileTicket;
        /**
         * List of category names to be considered for import.
         * <br>
         * No value means import all categories.
         */
        std::vector< std::string > categoryNames;
        /**
         * Specifies what to do when the preference already exists.
         * <br>
         * Valid values are:
         * <br>
         * <ul>
         * <li type="disc">"<b>SKIP</b>": to skip the import of this preference.
         * </li>
         * <li type="disc">"<b>OVERRIDE</b>": to override the preference value at this location
         * with the value specified in the input file.
         * </li>
         * <li type="disc">"<b>MERGE</b>": to append the preference value from the input file
         * to the preference value at the location. This is only possible if the preference
         * is a multi-valued preference. Otherwise, this will result in the "<b>SKIP</b>" action
         * for this preference.
         * </li>
         * </ul>
         * <br>
         * If a wrong value is provided, the operation will revert to using the "<b>SKIP</b>"
         * mode.
         */
        std::string importAction;
    };

    /**
     * Response that also contains a file ticket, which usage differs upon the operation
     * returning it.
     */
    struct PreferenceResponseWithFileTicket
    {
        /**
         * A ServiceData structure.   It will contain errors at indexes where errors have occurred.
         * Error details will vary according to the calling operation, and it will be specified
         * in its description.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A ticket of a file in the transient volume uploaded by the client. The content of
         * the file will depend on the calling operation, and it will be specified in its description.
         */
        std::string fileTicket;
    };

    /**
     * Defines a list of preferences at a provided location.
     */
    struct PreferencesAtLocationIn
    {
        /**
         * The desired location of the requested preferences.
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceLocation location;
        /**
         * A list of desired preference names.
         * <br>
         * If the list is empty or its first element is "*", all the preferences for the specified
         * locations (and only for preference instances at this location) are returned.
         */
        std::vector< std::string > preferenceNames;
    };

    /**
     * Structure of preference name and values.
     */
    struct SetPreferences2In
    {
        /**
         * The name of the preference.
         */
        std::string preferenceName;
        /**
         * The list of values.
         * <br>
         * <br>
         * Even though the value can be of a type different than string, the conversion to string
         * should be made using the <code>Property</code> class provided by the SOA framework.
         */
        std::vector< std::string > values;
    };

    /**
     * Contains the preference definition, values and the location where to set the information.
     */
    struct SetPreferencesAtLocationsIn
    {
        /**
         * Structure defining where the preferences are to be set.
         * <br>
         * <br>
         * The intent is that only the system administrator should create a preference. However,
         * this could be needed from non-directly-related user interactions. Therefore, the
         * decision to make a call to this operation is delegated to its caller.
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceLocation location;
        /**
         * Structure that contains the preference name, definition and values.
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::SetPreferences2In preferenceInputs;
    };

    /**
     * Structure containing a <code>PreferenceDefinition</code> structure and a list of
     * strings representing the preference values at the site level.
     */
    struct SetPreferencesDefinitionIn
    {
        /**
         * A structure holding the preference definition (possibly simplified).
         */
        Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceDefinition definition;
        /**
         * The list of values at the site level.
         * <br>
         * Even though the values can be of a type different than string, they should be converted
         * to a string through the use of the <code>Property</code> class from the SOA framework.
         * <br>
         */
        std::vector< std::string > values;
    };




    /**
     * Deletes the definition of the specified preferences.
     * <br>
     * If the intent is to delete the value, use the <code>deletePreferencedAtLocations</code>
     * operation instead. This enables the removal of any definition customization made
     * to the system.
     * <br>
     * <br>
     * When the <code>deletePreferenceDefinitions</code> operation is called with the <b>deleteAllCustomDefinition</b>
     * flag set to true, then all custom definitions are removed.
     * <br>
     * A custom definition is:
     * <br>
     * <ul>
     * <li type="disc">Any change made to the definition of a foundation preference (for
     * instance a change in the protection scope).
     * </li>
     * <li type="disc">Any preference (not part of the foundation preference list) that
     * was imported.
     * </li>
     * <li type="disc">Any preference that was created through the GUI or code API.
     * </li>
     * </ul>
     * <br>
     * This operation removes the preference definitions, but the preference instances will
     * not be removed. Use the <code>removeStalePreferenceInstancesAtLocations</code> operation
     * in order to do that.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param preferenceNames
     *        The list of names for the preference definitions to delete.
     *
     * @param deleteAllCustomDefinitions
     *        If set to true, indicates to delete all the custom definitions. No preference names
     *        should be provided then.
     *
     * @return
     *         A <code>ServiceData</code> structure that will contain errors at indexes where errors
     *         have occurred.
     *         <br>
     *         <br>
     *         The following partial errors will be returned at the same index as the input structure:
     *         <br>
     *         <ul>
     *         <li type="disc">1725: If the logged-in user does not have system administrator privileges.
     *         </li>
     *         <li type="disc">1760: If the string is invalid ("*", an empty string or a string
     *         only composed of any number of ' ' characters for instance).
     *         </li>
     *         <li type="disc">1762: If the preference does not exist. The call will proceed with
     *         the removal of the other preference definitions though.
     *         </li>
     *         <li type="disc">1764: If the preference is coming from the list of Teamcenter foundation
     *         preferences and their preference definitions have not been changed. The call will
     *         proceed with the removal of the other preference definitions though.
     *         </li>
     *         <li type="disc">1766: If the <b>deleteAllCustomDefinitions</b> flag is set to true,
     *         and some preference names are passed as arguments.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deletePreferenceDefinitions ( const std::vector< std::string >& preferenceNames,
        bool deleteAllCustomDefinitions ) = 0;

    /**
     * Deletes the given preference instances at the specified location only.
     * <br>
     * This operation takes a list of <code>PreferencesAtLocationIn</code> structures representing
     * the preferences to delete and the location.
     * <br>
     * The location is a <code>PreferenceLocation</code> structure, which contains 2 mutually
     * exclusive parameters:
     * <br>
     * 1. The location parameter, for which values can be for this specific operation:
     * <br>
     * <ul>
     * <li type="disc">"<b>Overlay</b>": The Overlay value will be deleted for an out-of-the-box
     * (OOTB) preference, and the whole preference will be deleted for a custom preference.
     * </li>
     * <li type="disc">"<b>Group</b>": The preference will be deleted for the group of the
     * logged-in user.
     * </li>
     * <li type="disc">"<b>Role</b>": The preference will be deleted for the role of the
     * logged-in user.
     * </li>
     * <li type="disc">"<b>User</b>": The preference will be deleted for the logged-in user.
     * </li>
     * </ul>
     * <br>
     * 2. The object parameter, which represents the <b>User</b>, <b>Role</b> or <b>Group</b>
     * where to delete the values. This is to be used when the target is for the non-logged-in
     * user.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A preference instance is present at the user level, and it needs to be removed.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param deletePreferencesAtLocationIn
     *        A list of preferences at a given location.
     *
     * @return
     *         This operation returns a <code>ServiceData</code> structure. It will contain errors
     *         at indexes where errors have occurred.
     *         <br>
     *         <br>
     *         The following partial errors will be returned at the same index as the input structure:
     *         <br>
     *         <ul>
     *         <li type="disc">1700: If the preference does not exist.
     *         </li>
     *         <li type="disc">1709: If the logged-in user tries to delete the out-of-the-box value
     *         for the preference.
     *         </li>
     *         <li type="disc">1725: If the logged-in user does not have the privileges to carry-out
     *         the operation.
     *         </li>
     *         <li type="disc">1751: If the specified object information does not correspond to
     *         any user, role or group.
     *         </li>
     *         <li type="disc">1752: If both an object and a location are specified.
     *         </li>
     *         <li type="disc">1753: If the specified location is invalid.
     *         </li>
     *         <li type="disc">1759: If the preference name is empty.
     *         </li>
     *         <li type="disc">1760: If the preference name is invalid ("*" for instance).
     *         </li>
     *         <li type="disc">1775: If the instance to be removed for the preference does not exist
     *         at the specified location.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deletePreferencesAtLocations ( const std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferencesAtLocationIn >& deletePreferencesAtLocationIn ) = 0;

    /**
     * Retrieves the values for the preferences specified in the list of names, as seen
     * by the current logged-in user.
     * <br>
     * If the list is empty or its first value is equal to "*", all the preferences as seen
     * by the logged-in user will be returned (not only the preference instances created
     * by the logged-in user).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Retrieving the value for a series of preferences.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param preferenceNames
     *        The list of preferences for which values is requested.
     *        <br>
     *        If the list is empty or its first value is equal to "*", all the preferences visible
     *        by the logged-in user will be returned (not only the preference instances created
     *        by the logged-in user).
     *
     * @param includePreferenceDescriptions
     *        Decides if the preference descriptions will be included in the response. Valid values
     *        are true (descriptions are added) or false (no description). This offers flexibility
     *        to decide the important information to the caller and reduce the size of the response
     *        payload.
     *
     * @return
     *         Returns the preference information (value and description if requested), as well
     *         as any potential partial errors. Those errors will be returned at the same index
     *         as the input structure whenever an error has occurred:
     *         <br>
     *         <ul>
     *         <li type="disc">1700: If the preference does not exist.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Administration::_2012_09::Preferencemanagement::GetPreferencesResponse getPreferences ( const std::vector< std::string >& preferenceNames,
        bool includePreferenceDescriptions ) = 0;

    /**
     * Retrieves the values for the specified preferences and locations.
     * <br>
     * The input structure contains:
     * <ul>
     * <li>A vector preference names. If the list is empty or its first element is "*",
     * all the preferences for the specified locations (and only for preference instances
     * at this location) are being returned.
     * </li>
     * <li>A <code>PreferenceLocation</code>  structure, which contains 2 mutually exclusive
     * parameters:<ol><li>The location parameter, for which values can be for this specific
     * operation:<ul type="circle"><li>"<i>Site</i>": The preference will be retrieved either
     * as overwritten or as an out-of-the-box (OOTB) value (whichever gives a value first).
     * </li>
     * <li>"<i>Group</i>": The preference will be retrieved for the group of the logged-in
     * user.
     * </li>
     * <li>"<i>Role</i>": The preference will be retrieved for the role of the logged-in
     * user.
     * </li>
     * <li>"<i>User</i>": The preference will be retrieved for the logged-in user.
     * </li>
     * </ul>
     * </li>
     * <li> The <b><i>object</i></b> parameter, which represents the <b>User</b>, <b>Role</b>
     * or <b>Group</b> where to retrieve the values. This is to be used when the target
     * is for the non-logged-in user.
     * </li>
     * </ol>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1. The logged-in user needs to know the preference value given at her/his Role or
     * Group level.
     * <br>
     * 2. The logged-in user needs to know the preference value given by another user, or
     * a Role/Group than hers/his.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param getPreferenceAtLocationIn
     *        The desired list of preferences for a given location.
     *
     * @param includePreferenceDescriptions
     *        Decides if the preference descriptions will be included in the response. Valid values
     *        are true (descriptions are added) or false (no description). This offers flexibility
     *        to decide the important information to the caller and reduce the size of the response
     *        payload.
     *
     * @return
     *         The returned description and category strings within the <code>PreferenceDefinition</code>
     *         structure (which is part of each <code>CompletePreferencesResponse</code> structure)
     *         will be empty except for the location specified as Site. The order of the returned
     *         vector is the same as the order of the input vector.
     *         <br>
     *         The following partial errors may be returned. Each partial error will contain the
     *         index of the related input data:
     *         <br>
     *         <ul>
     *         <li type="disc">1751: If the specified object information does not correspond to
     *         any <b>User</b>, <b>Role</b> or <b>Group</b>.
     *         </li>
     *         <li type="disc">1752: If both an object and a location are specified for an entry.
     *         </li>
     *         <li type="disc">1753: If one of the specified locations is invalid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Administration::_2012_09::Preferencemanagement::GetPreferencesAtLocationsResponse getPreferencesAtLocations ( const std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferencesAtLocationIn >& getPreferenceAtLocationIn,
        bool includePreferenceDescriptions ) = 0;

    /**
     * Pretends to import the preferences from the input file into the specified location.
     * On the contrary to the import operation, the dry run operates on one location at
     * a time. The objective is to gather information on what would be the final result
     * for proceeding with the real import operation.  This operation takes a vector of
     * structure representing the preferences and the location where to import. The valid
     * values for the location parameter in the PreferenceLocation structure are: Site,
     * Group, Role, User. The Site value means that the preference will be imported for
     * the entire organization. Group or Role means that the value will be imported for
     * the Group or Role of the current logged-in user. It is also possible to import for
     * the non-current user.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param importPreferences
     *        A structure that contains all the parameters for the import operation
     *
     * @return
     *         A <code>PreferenceResponseWithFileTicket</code> structure, which contains:<ol><li>A
     *         file ticket to the report file (generated by the import operation) in the transient
     *         volume uploaded by the client. If the operation is called to import at several locations,
     *         all the report informations are gathered in the same file.
     *         </li>
     *         <li>A ServiceData structure, which contains errors at indexes where errors have occurred.
     *         The following partial errors will be returned at the same index as the input structure:<ul
     *         type="circle"><li>1700: If the preference does not exist.
     *         </li>
     *         <li>1725: If the logged-in user does not have the requested permission to carry-out
     *         the operation.
     *         </li>
     *         <li>1728: If the protection scope of the preference prevents a creation of one instance
     *         at the specified location.
     *         </li>
     *         <li>1751: If the specified object information does not correspond to any <b>User</b>,
     *         <b>Role</b> or <b>Group</b>.
     *         </li>
     *         <li>1752: If both an object and a location are specified for an entry.
     *         </li>
     *         <li>1753: If the specified location is invalid.
     *         </li>
     *         <li>1759: If the preference name is empty.
     *         </li>
     *         <li>1760: If the preference name is invalid ("*" for instance).
     *         </li>
     *         </ul>
     *         </li>
     *         </ol>
     *
     */
    virtual Teamcenter::Services::Administration::_2012_09::Preferencemanagement::ImportPreferencesAtLocationDryRunResponse importPreferencesAtLocationDryRun ( const Teamcenter::Services::Administration::_2012_09::Preferencemanagement::ImportPreferencesAtLocationDryRunIn&  importPreferences ) = 0;

    /**
     * Imports the preferences from the input file into the specified locations.  This operation
     * takes a vector of structure representing the preferences and the location where to
     * import. The valid values for the location parameter in the PreferenceLocation structure
     * are: Site, Group, Role, User. The Site value means that the preference will be imported
     * for the entire organization. Group or Role means that the value will be imported
     * for the Group or Role of the current logged-in user. It is also possible to import
     * for the non-current user.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param importPreferenceIn
     *        A structure that contains all the parameters for the import operation
     *
     * @return
     *         A <code>PreferenceResponseWithFileTicket</code> structure, which contains:&lt;ol&gt;&lt;li&gt;A
     *         file ticket to the report file (generated by the import operation) in the transient
     *         volume uploaded by the client. If the operation is called to import at several locations,
     *         all the report informations are gathered in the same file. &lt;/li&gt;&lt;li&gt;A
     *         ServiceData structure, which contains errors at indexes where errors have occurred.
     *         The following partial errors will be returned at the same index as the input structure:&lt;ul
     *         type=&quot;circle&quot;&gt;&lt;li&gt;1700: If the preference does not exist. &lt;/li&gt;&lt;li&gt;1725:
     *         If the logged-in user does not have the requested permission to carry-out the operation.
     *         &lt;/li&gt;&lt;li&gt;1751: If the specified object information does not correspond
     *         to any &lt;b&gt;User&lt;/b&gt;, &lt;b&gt;Role&lt;/b&gt; or &lt;b&gt;Group&lt;/b&gt;.
     *         &lt;/li&gt;&lt;li&gt;1752: If both an object and a location are specified for an
     *         entry. &lt;/li&gt;&lt;li&gt;1753: if the specified location is invalid. &lt;/li&gt;&lt;/ol&gt;
     *
     */
    virtual Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceResponseWithFileTicket importPreferencesAtLocations ( const Teamcenter::Services::Administration::_2012_09::Preferencemanagement::ImportPreferencesAtLocationsIn&  importPreferenceIn ) = 0;

    /**
     * Removes stale preferences from the specified locations.
     * <br>
     * <br>
     * Stale preferences are remaining instances for preferences that either does not exist
     * anymore, or for which the protection scope has been moved (e.g. a preference with
     * protection scope user, for which the protection scope was changed to being group).
     * <br>
     * <br>
     * This operation takes a vector of <code>PreferenceLocation</code> structure representing
     * the location where to remove the stale preferences. The structure contains 2 mutually
     * exclusive parameters:
     * <br>
     * <ol><li>The location parameter, for which values can be for this specific operation:<ul
     * type="circle"><li>"<b>*</b>": the stale values will be removed everywhere. This can
     * only be used by a system administrator.
     * </li>
     * <li>"<b>Site</b>": the stale preference will be removed for the site level.
     * </li>
     * <li>"<b>Group</b>": the stale preference will be removed for the group of the logged-in
     * user.
     * </li>
     * <li>"<b>Role</b>": the stale preference will be removed for the role of the logged-in
     * user.
     * </li>
     * <li>"<b>User</b>": the stale preference will be removed for the logged-in user.
     * </li>
     * </ul>
     * </li>
     * <li>The object parameter, which represents the <b>User</b>, <b>Role</b> or <b>Group</b>
     * where to remove the stale preferences. This is to be used when the target is for
     * the non-logged-in user.
     * </li>
     * </ol>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param locations
     *        The locations where to remove the stale preference instances.
     *
     * @return
     *         A <code>ServiceData</code> structure, which will contain errors at indexes where
     *         errors have occurred.
     *         <br>
     *         The following partial errors will be returned at the same index as the input structure:
     *         <br>
     *         <ul>
     *         <li type="disc">1725: If the logged-in user does not have the requested permission
     *         to carry-out the operation.
     *         </li>
     *         <li type="disc">1751: If the specified object information does not correspond to
     *         any <b>User</b>, <b>Role</b> or <b>Group</b>.
     *         </li>
     *         <li type="disc">1752: If both an object and a location are specified for an entry.
     *         </li>
     *         <li type="disc">1753: If the specified location is invalid.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeStalePreferenceInstancesAtLocations ( const std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::PreferenceLocation >& locations ) = 0;

    /**
     * Allows the logged-in user to set the values for the given preferences for the logged-in
     * user.
     * <br>
     * Values can only be given to preferences already defined in the system and for which
     * the protection scope allows the user to give a value. Otherwise, the operation will
     * return an error for this preference.
     * <br>
     * Preference name and values are specified in input structure <code>SetPreferences2In</code>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param preferenceInput
     *        A list of preference names and values.
     *
     * @return
     *         A ServiceData structure that will contain errors at indexes where errors have occurred.&lt;br
     *         /&gt;&lt;br /&gt;The following partial errors will be returned at the same index
     *         as the input structure:&lt;br /&gt;&lt;ul&gt;&lt;ul&gt;&lt;li type=&quot;disc&quot;&gt;1700:
     *         If the preference does not exist. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1728:
     *         If the logged-in user is not a privileged user or is trying to set a preference value
     *         in case the protection scope of the preference prevents a creation of one instance
     *         at the user level. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1759: If the preference
     *         name is empty. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1760: If the preference
     *         name is not valid (&quot;*&quot; is not a valid preference name for instance). &lt;/li&gt;&lt;li&gt;1771:
     *         If one of the values is incompatible with a preference of type Integer.&lt;/li&gt;&lt;li&gt;1772:
     *         If one of the values is incompatible with a preference of type Double.&lt;/li&gt;&lt;li&gt;1773:
     *         If one of the values is incompatible with a preference of type Date.&lt;/li&gt;&lt;li&gt;1774:
     *         If one of the values is incompatible with a preference of type Logical.&lt;/li&gt;&lt;/ul&gt;&lt;/ul&gt;
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setPreferences2 ( const std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::SetPreferences2In >& preferenceInput ) = 0;

    /**
     * Sets the values for the specified preferences and locations.
     * <br>
     * <br>
     * The input <code>PreferenceLocation</code> structure (within the <code>SetPreferencesAtLocationsIn</code>
     * structure) contains 2 mutually exclusive parameters: <ol><li>The location parameter,
     * for which values can be for this specific operation: <ul type="circle"><li>"<b>Site</b>":
     * The preference will be set for the entire organization.
     * </li>
     * <li>"<b>Group</b>": the preference will be set for the group of the logged-in user.
     * </li>
     * <li>"<b>Role</b>": The preference will be set for the role of the logged-in user.
     * </li>
     * <li>"<b>User</b>": The preference will be set for the logged-in user.
     * </li>
     * </ul>
     * </li>
     * <li> The object parameter, which represents the <b>User</b>, <b>Role</b> or <b>Group</b>
     * where to set the values. This is to be used when the target is for the non-logged-in
     * user. Note that the caller must have permission to set the preference values for
     * the specified object.
     * </li>
     * </ol>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param setPreferenceIn
     *        A list of preference definition, values and the location where to set the information.
     *
     * @return
     *         A <code>ServiceData</code> structure, which will contain errors (when they occur)
     *         at the same index as the input structure: &lt;br /&gt;&lt;ul&gt;&lt;ul&gt;&lt;li
     *         type=&quot;disc&quot;&gt;1700: if the preference does not exist. &lt;/li&gt;&lt;li
     *         type=&quot;disc&quot;&gt;1725: If the logged-in user does not have the requested
     *         permission to carry-out the operation. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1728:
     *         If the protection scope of the preference prevents a creation of one instance at
     *         the specified location. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1751: If the specified
     *         object information does not correspond to any user, role or group. &lt;/li&gt;&lt;li
     *         type=&quot;disc&quot;&gt;1752: If both an object and a location are specified for
     *         an entry. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1753: If the specified location
     *         is invalid. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1759: If the preference name
     *         is empty. &lt;/li&gt;&lt;li type=&quot;disc&quot;&gt;1760: If the preference name
     *         is invalid (&quot;*&quot; for instance). &lt;/li&gt;&lt;li&gt;1771: If one of the
     *         values is incompatible with a preference of type Integer.&lt;/li&gt;&lt;li&gt;1772:
     *         If one of the values is incompatible with a preference of type Double.&lt;/li&gt;&lt;li&gt;1773:
     *         If one of the values is incompatible with a preference of type Date.&lt;/li&gt;&lt;li&gt;1774:
     *         If one of the values is incompatible with a preference of type Logical.&lt;/li&gt;&lt;/ul&gt;&lt;/ul&gt;
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setPreferencesAtLocations ( const std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::SetPreferencesAtLocationsIn >& setPreferenceIn ) = 0;

    /**
     * Allows system administrators to create the definitions for new preferences, or to
     * modify existing preference definitions.
     * <br>
     * If the preferences do not exist, it sets the definitions and values for the specified
     * preferences.
     * <br>
     * If the preferences already exist (i.e. they have been defined already), it modifies
     * them.
     * <br>
     * <br>
     * <br>
     * This is a system administrator level operation. The intent is that only the system
     * administrator should create a preference. However, this could be needed from non-directly-related
     * user interactions. Therefore, the decision to make a call to this operation is delegated
     * to its caller.
     * <br>
     * <br>
     * This operation takes a list of <code>SetPreferencesDefinitionIn</code> structures,
     * which contains a <code>PreferenceDefinition</code> structure. This structure can
     * be simplified in case of preference modifications. Its parameters are:
     * <ul>
     * <li>category: The category where the preference is stored.
     * <br>
     * If the input string is empty, the parameter will not be taken into account. However,
     * in case the preference has not been created yet, it will be assumed that the preference
     * will go under the "General" category. If the string is not empty, the code will consider
     * this to be a category modification.
     * <br>
     * &nbsp;
     * </li>
     * <li>description: The textual explanation of what the preference does.
     * <br>
     * If the input string is empty, the parameter will not be taken into account.
     * <br>
     * &nbsp;
     * </li>
     * <li>type: The preference type.
     * <br>
     * Valid values are: <ul type="circle"><li>0: String preference.
     * </li>
     * <li>1: Logical preference.
     * </li>
     * <li>2: Integer preference.
     * </li>
     * <li>3: Double preference.
     * </li>
     * <li>4: Date preference.
     * </li>
     * </ul>
     * If the preference does not exist, this piece of information will be needed.
     * <br>
     * If the preference exists and is an OOTB preference, this argument is discarded.
     * <br>
     * If the preference exists and is not an OOTB preference and if the value is provided
     * and if a preference instance already exist with the old type and the conversion from
     * the old type to the new one is not possible, any further call to a getPreferences
     * operation will revert to giving the value at the higher level instead of returning
     * an error.
     * <br>
     * &nbsp;
     * </li>
     * <li>protectionScope: The level at which the preference is protected.
     * <br>
     * Valid values are:<ul type="circle"><li>"<b>User</b>": All users can provide a value
     * for the preference.
     * </li>
     * <li>"<b>Role</b>": Only system and group administrators can provide a value.
     * </li>
     * <li>"<b>Group</b>": Only system and group administrators can provide a value.
     * </li>
     * <li>"<b>Site</b>": Only system administrators can provide a value.
     * </li>
     * <li>"<b>System</b>": Only system administrators can provide a value. Furthermore,
     * the protection scope cannot be changed from then on.
     * </li>
     * </ul>
     * If the preference does not exist, this information is mandatory.
     * <br>
     * If the preference exists and the protection scope string is empty, the parameter
     * will not be taken into account.
     * <br>
     * If the preference exists and the protection scope string is not empty, the code will
     * consider this to be a modification.
     * <br>
     * &nbsp;
     * </li>
     * <li>isEnvEnabled: Status if the preference value can be set through an environment
     * variable, in which case it will come from that location first.
     * <br>
     * This piece of information will always be taken into consideration.
     * <br>
     * &nbsp;
     * </li>
     * <li>isOOTBPreference: Not used for this operation.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param preferenceInput
     *        A list of preference definitions.
     *
     * @return
     *         A <code>ServiceData</code> structure, which will contain errors at specific indexes
     *         where errors have occurred.
     *         <br>
     *         The following partial errors will be returned at the same index as the input structure:
     *         <ul>
     *         <li>1755: If the preference does not exist yet, and no description or no protection
     *         scope is provided.
     *         </li>
     *         <li>1756: This is returned in several case: <ul type="circle"><li>If the preference
     *         does not exist and the type or the protection scope is incorrect.
     *         </li>
     *         <li>If the preference exists and the protection scope is invalid.
     *         </li>
     *         <li>If the preference is not an out-of-the-box (OOTB) preference and the type is
     *         incorrect.
     *         </li>
     *         <li>If the category name is provided and the category does not exist yet in the system.
     *         </li>
     *         </ul>
     *         </li>
     *         <li>1757: If a category name is provided and the value is different from the current
     *         value and the preference is an OOTB preference.
     *         </li>
     *         <li>1758: If the preference is an OOTB preference with protection scope of System
     *         and the provided value is not System.
     *         </li>
     *         <li>1759: If the preference name is empty.
     *         </li>
     *         <li>1760: If the preference name is invalid ("*" for instance).
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setPreferencesDefinition ( const std::vector< Teamcenter::Services::Administration::_2012_09::Preferencemanagement::SetPreferencesDefinitionIn >& preferenceInput ) = 0;


protected:
    virtual ~Preferencemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

