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

#ifndef TEAMCENTER_SERVICES_CONFIGURATION__2010_04_SMARTUIBLDR_HXX
#define TEAMCENTER_SERVICES_CONFIGURATION__2010_04_SMARTUIBLDR_HXX

#include <teamcenter/soa/client/model/TCX_SCConfig.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/configuration/Configuration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Configuration
        {
            namespace _2010_04
            {
                class Smartuibldr;

class TCSOACONFIGURATIONSTRONGMNGD_API Smartuibldr
{
public:

    struct ComponentInfo;
    struct ContainerWiseProperties;
    struct ForTypePreferences;
    struct GetPropertiesForSelectionsOutput;
    struct GetPropertiesForSelectionsResponse;
    struct GetResultForSelectionsOutput;
    struct GetResultForSelectionsResponse;
    struct GetValuesForComponentOutput;
    struct GetValuesForComponentResponse;
    struct ListForerunnersForComponentsOutput;
    struct ListForerunnersForComponentsResponse;
    struct ListObjectsForComponentsOutput;
    struct ListObjectsForComponentsResponse;
    struct ListValuesForComponentsOutput;
    struct ListValuesForComponentsResponse;

    /**
     * This map contains a key value pairs, where key is the Smart Code configuration property
     * and the value is the user selected value for the property.
     */
    typedef std::map< std::string, std::string > CurrentSelectionsMap;

    /**
     * This map contains the properties and values of Smart Code configuration object.
     */
    typedef std::map< std::string, std::string > PropertiesMap;

    /**
     * The ComponentInfo structure contains the optional clientId and the TCX_SCConfig configuration
     * object.
     */
    struct ComponentInfo
    {
        /**
         * Contains  a unique identifier supplied by the caller. This ID is used to
         * <br>
         * track the related objects.
         */
        std::string clientId;
        /**
         * Contains a valid Smart code configuration object in Teamcenter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCX_SCConfig>  component;
    };

    /**
     * ContainerWiseProperties structure contains the container name (any one of "I", "IR",
     * "IM", "IRM") and the properties mapped on to this container in the form of key-value
     * pairs.
     */
    struct ContainerWiseProperties
    {
        /**
         * Contains the name of the container, which can be any one of the following -  "I",
         * "IR", "IM" or "IRM".
         * <br>
         */
        std::string container;
        /**
         * This map contains the properties and values of Smart Code configuration object.
         * <br>
         */
        PropertiesMap properties;
    };

    /**
     * The ForTypePreferences structure contains the information such as Classname, Typename
     * and the property of the object for which the Smart Code needs to be generated.
     */
    struct ForTypePreferences
    {
        /**
         * Contains the Class Name of the object for which the Smart Code needs to be generated.
         * <br>
         */
        std::string className;
        /**
         * Contains the Type Name of the object for which the Smart Code&nbsp;&nbsp;&nbsp;&nbsp;needs
         * to be generated.
         * <br>
         */
        std::string typeName;
        /**
         * Contains the Property of the object for which the Smart Code needs to be generated.
         * <br>
         */
        std::string property;
    };

    /**
     * The GetPropertiesForSelectionsOutput structure contains the information about the
     * properties of selected objects for which the Smart Code needs to be generated.
     */
    struct GetPropertiesForSelectionsOutput
    {
        /**
         * Contains a unique string supplied by the caller. This ID is used to identify return
         * data and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Contains the container name (any one of "I", "IR", "IM", "IRM") and the properties
         * mapped on to this container in the form of key-value pairs.
         * <br>
         */
        std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ContainerWiseProperties > containerWiseProperties;
    };

    /**
     * This structure contains the GetPropertiesForSelectionsOutput object and the ServiceData.
     */
    struct GetPropertiesForSelectionsResponse
    {
        /**
         * Contains the information about the properties of selected objects for which the Smart
         * Code needs to be generated.
         * <br>
         */
        Teamcenter::Services::Configuration::_2010_04::Smartuibldr::GetPropertiesForSelectionsOutput output;
        /**
         * Contains the successful Object ids, partial error mentioned below.
         * <br>
         * o&nbsp;&nbsp;&nbsp;&nbsp;258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component
         * is passed, this error is added in the ServiceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The GetResultForSelectionsOutput structure contains the clientID, generated Smart
     * Code and the containerwise properties.
     */
    struct GetResultForSelectionsOutput
    {
        /**
         * Contains a unique string supplied by the caller. This ID is used to identify return
         * data and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Contains the final generated SmartCode.
         */
        std::vector< std::string > resultStrings;
        /**
         * Contains the container name (any one of "I", "IR", "IM", "IRM") and the properties
         * mapped on to this container in the form of key-value pairs.
         * <br>
         */
        std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ContainerWiseProperties > containerWiseProperties;
    };

    /**
     * This structure contains GetResultForSelectionsOutput object and the ServiceData.
     */
    struct GetResultForSelectionsResponse
    {
        /**
         * Contains the information about the the generated Smart Code for the given Component's
         * Item ID as per the given configuration.
         */
        Teamcenter::Services::Configuration::_2010_04::Smartuibldr::GetResultForSelectionsOutput output;
        /**
         * The successful Object ids, partial error mentioned below.
         * <br>
         * o&nbsp;&nbsp;&nbsp;&nbsp;258000&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-
         * If an invalid Root Component is passed, this error is added in the ServiceData.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure GetValuesForComponentsOutput contains the clientID and a vector containing
     * the next avialable Smart Code values.
     */
    struct GetValuesForComponentOutput
    {
        /**
         * Contains a unique string supplied by the caller. This ID is used to identify return
         * data and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Contains the next valid available Smart Code values for Item ID for the  given  component.
         */
        std::vector< std::string > componentValues;
    };

    /**
     * This structure contains GetValuesForComponentsOutput object and the ServiceData.
     */
    struct GetValuesForComponentResponse
    {
        /**
         * Contains the information about the next avialable Smart Code values for Item ID for
         * the given component.
         * <br>
         */
        std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::GetValuesForComponentOutput > output;
        /**
         * The successful Object ids, partial error mentioned below.
         * <br>
         * o&nbsp;&nbsp;&nbsp;&nbsp;258000&nbsp;&nbsp;&nbsp;&nbsp;- &nbsp;&nbsp;&nbsp;&nbsp;If
         * an invalid Root Component is passed, this error is added in the ServiceData.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure ListForerunnersForComponentsOutput contains the clientID and SCConfig
     * configuration object.
     */
    struct ListForerunnersForComponentsOutput
    {
        /**
         * Contains a unique string supplied by the caller. This ID is used to identify return
         * data and partial errors associated with this input structure
         * <br>
         */
        std::string clientId;
        /**
         * Contains a list of valid Smart Code configuration objects in Teamcenter.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCX_SCConfig>  > forerunningComponents;
    };

    /**
     * The structure ListForerunnersForComponentsResponse contains the object of ListForerunnersForComponentsOutput
     * and the ServiceData.
     */
    struct ListForerunnersForComponentsResponse
    {
        /**
         * Contains information about the components explicitly dependent on each of the given
         * component
         * <br>
         */
        std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ListForerunnersForComponentsOutput > output;
        /**
         * Contains the successful Object ids, partial error mentioned below.
         * <br>
         * o&nbsp;&nbsp;&nbsp;&nbsp;258000&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-
         * If an invalid Root Component is passed, this error is added in the ServiceData
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure ListObjectsForComponentsOutput contains the clientID and a vector of
     * TCX_SCConfig  objects.
     */
    struct ListObjectsForComponentsOutput
    {
        /**
         * Contains a unique string supplied by the caller. This ID is used to identify return
         * data and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Contains the list of components explicitly dependent on the given component.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TCX_SCConfig>  > componentsList;
    };

    /**
     * The structure contains the  ListObjectsForComponentsOutput object and the ServiceData.
     */
    struct ListObjectsForComponentsResponse
    {
        /**
         * Contains a list of ListObjectsForComponentsoutput objects. Each object represents
         * the components explicitly dependent on the given component.
         * <br>
         */
        std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ListObjectsForComponentsOutput > output;
        /**
         * Contains the successful Object ids, partial error mentioned below.
         * <br>
         * o&nbsp;&nbsp;&nbsp;&nbsp;258000&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-
         * If an invalid Root Component is passed, this error is added in the ServiceData.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure ListValuesForComponentsOutput contains the clientID and a vector of
     * strings.
     */
    struct ListValuesForComponentsOutput
    {
        /**
         * Contains a unique string supplied by the caller. This ID is used to identify return
         * data and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Contains the list of Smart Code values for Item IDs for the given component as per
         * the Smart Code configuration set by the user.
         */
        std::vector< std::string > allowedValues;
    };

    /**
     * The structure ListValuesForComponentsResponse contains a vector of ListValuesForComponentsOutput
     * objects and the ServiceData.
     */
    struct ListValuesForComponentsResponse
    {
        /**
         * Contains a list of ListValuesForComponentsOutput. Each object contains a list of
         * Smart Code values for Item IDs for the given component as mentioned in the Smart
         * Code configuration by the user.
         * <br>
         */
        std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ListValuesForComponentsOutput > output;
        /**
         * Contains the successful Object ids, partial error mentioned below.
         * <br>
         * o&nbsp;&nbsp;&nbsp;&nbsp;258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component
         * is passed, this error is added in the ServiceData.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * As per the given Smart Code configuration, the getPropertiesForSelections operation
     * is used to get the Form properties and their corresponding values.
     * <br>
     * <br>
     * For example if 'Component Type' is mapped to 'user_data_1' on Item Master Form through
     * FieldSet, getPropertiesForSelections method returns a map containing ( 'user_data_1',
     * 'BA (component part)' ) as an entry. This map contains as many elements as the number
     * of FieldSet entries in Smart Code configuration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param rootComponent
     *        Contains the information about the component for which the Form Properties and its
     *        corresponding properties are to be retrieved.
     *
     * @param forTypePref
     *        Contains the information about the properties of the Component object for which the
     *        Form Properties and its corresponding properties are to be retrieved.
     *
     * @param currentSelections
     *        Contains the map of user selected values to the object IDs.
     *
     * @param container
     *        Contains the name of the container. The container name can be any one of the following
     *        -  "I", "IR", "IM" or "IRM". If the value is an empty string  ("") then this method
     *        will return the properties corresponding to all the four containers.
     *
     * @return
     *         The Form properties and their corresponding values as per the given Smart Code configuration
     *         and also the updated ServiceData element with the partial error mentioned below.
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Configuration::_2010_04::Smartuibldr::GetPropertiesForSelectionsResponse getPropertiesForSelections ( const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo&  rootComponent,
        const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ForTypePreferences&  forTypePref,
        const CurrentSelectionsMap&  currentSelections,
        const std::string&  container ) = 0;

    /**
     * The getResultForSelections operation is used to get the Smart Code for Item ID as
     * per the given Smart Code configuration.
     * <br>
     * For example for the below mentioned selections, final ItemID - 300005190 is generated
     * using getResultForSelections::
     * <br>
     * { "ITEM_COMP_TYPE","BA(Component part)", "ITEM_MACHINE_TYPE","A-Type",
     * <br>
     * "ITEM_COUNTER_1","300005", "ITEM_DIMENSION","1",  "ITEM_DIMENSION_RW","190"   }
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param rootComponent
     *        Contains the information about the the Root component as configured in the Smart
     *        code configuration.
     *        <br>
     *
     * @param currentSelections
     *        Contains the Map of user selected values to the object ids.
     *        <br>
     *
     * @param alsoGetMappedProperties
     *        Contains the boolean value.
     *        <br>
     *        true -  Adds the container wise properties to the response.
     *        <br>
     *        false - Container wise properties are not added to the response.
     *        <br>
     *
     * @return
     *         The getResultForSelections operation returns the Smart Code value for the Item ID,
     *         as per the Smart Code configuration and also the updated ServiceData element with
     *         the partial error mentioned below.
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Configuration::_2010_04::Smartuibldr::GetResultForSelectionsResponse getResultForSelections ( const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo&  rootComponent,
        const CurrentSelectionsMap&  currentSelections,
        bool alsoGetMappedProperties ) = 0;

    /**
     * For a given set of user selections, getValuesForComponents returns the next available
     * Smart Code value/string in the database for the given Component.
     * <br>
     * For Example, if previously assigned Item ID's Smart Code is -  "300010", getValuesForComponents
     * returns "300011" as the next available Smart Code value for Item ID for the given
     * component.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param component
     *        Contains the vector of ComponentInfo for which the next available Smart Code for
     *        Item ID needs to be generated.
     *        <br>
     *
     * @param rootComponent
     *        Contains the information about the Root component.
     *
     * @param currentSelections
     *        Contains the configuration specified by the user.
     *
     * @return
     *         A list of Smart Code values for each of the given Item ID and also the updated ServiceData
     *         element with the partial error mentioned below.
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Configuration::_2010_04::Smartuibldr::GetValuesForComponentResponse getValuesForComponent ( const std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo >& component,
        const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo&  rootComponent,
        const CurrentSelectionsMap&  currentSelections ) = 0;

    /**
     * As per the given Smart Code configuration, the listForerunnersForComponents operation
     * is used to get all the components implicitly dependent on each of the given component.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param components
     *        Contains the ComponentInfo about all the components for which the dependent objects
     *        are to be retrieved.
     *        <br>
     *
     * @param currentSelections
     *        Contains the map of user selected values to the object IDs.
     *
     * @return
     *         The components implicitly dependent on each of the given component object and also
     *         the updated ServiceData element with the partial error as mentioned below.
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ListForerunnersForComponentsResponse listForerunnersForComponents ( const std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo >& components,
        const CurrentSelectionsMap&  currentSelections ) = 0;

    /**
     * The listObjectsForComponents operation  is used to get the components explicitly
     * dependent on each of the given components as per the Smart Code configuration set
     * by the user.
     * <br>
     * <br>
     * For example if we pass 'Component Type' as the input component, its explicit dependents
     * 'Machine Type' will be returned as output components.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param compInfo
     *        Contains the information about all the components for which the dependent components
     *        are to be retrieved.
     *        <br>
     *
     * @param typePref
     *        Contains the information about the properties of the Component object for which the
     *        dependent Components are to be retrieved.
     *        <br>
     *
     * @param currSelection
     *        Contains the map (string, string) of user selected values to the Object IDs.
     *
     * @return
     *         The  list of explicitly dependent objects for  each of the given components and also
     *         the updated ServiceData element with the partial error as mentioned below.
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ListObjectsForComponentsResponse listObjectsForComponents ( const std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo >& compInfo,
        const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ForTypePreferences&  typePref,
        const CurrentSelectionsMap&  currSelection ) = 0;

    /**
     * The  listValuesForComponents operation is used to get the Smart Code values for Item
     * IDs that each of the given  component  can assume as per the Smart Code configuration
     * set by the user.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param compInfo
     *        Contains the information about all the components for which the valid Smart Code
     *        values for Item IDs needs to be generated.
     *        <br>
     *
     * @param typePref
     *        Contains the information about the properties of the components for which all the
     *        valid Smart Code values for Item ID needs to be generated.
     *        <br>
     *
     * @param currSelection
     *        Contains the map of user selected values to the object IDs.
     *
     * @return
     *         A list of Smart Code values for Item IDs for each of the given component can assume
     *         as per the Smart Code configuration set by the user, and also the updated ServiceData
     *         element with the partial error mentioned below.
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ListValuesForComponentsResponse listValuesForComponents ( const std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo >& compInfo,
        const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ForTypePreferences&  typePref,
        const CurrentSelectionsMap&  currSelection ) = 0;

    /**
     * The ungetValuesForComponents operation is used to undo the generated Smart Code for
     * the Item ID if users do not want to proceed with the Item creation after generating
     * the Smart Code.
     * <br>
     * <br>
     * For example after generating the Smart Code for Item ID, if users want to cancel
     * Item creation, ungetValuesForComponents operation resets the Smart Code counters/numbers/attributes
     * back to the earlier values so that these values are reusable
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SmartUIBuilder - SmartUIBuilder
     *
     * @param components
     *        Contains the information about the components for which the generated Smart Code
     *        value for Item ID needs to be undone/ reverted.
     *        <br>
     *
     * @param rootComponent
     *        Contains the information about the Root Component.
     *
     * @param currentSelections
     *        Contains a map of user selected values to the object IDs.
     *
     * @return
     *         The updated ServiceData element with the partial error mentioned below.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">258000&nbsp;&nbsp;&nbsp;&nbsp;- If an invalid Root Component is passed,
     *         this error is added in the ServiceData.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData ungetValuesForComponents ( const std::vector< Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo >& components,
        const Teamcenter::Services::Configuration::_2010_04::Smartuibldr::ComponentInfo&  rootComponent,
        const CurrentSelectionsMap&  currentSelections ) = 0;


protected:
    virtual ~Smartuibldr() {}
};
            }
        }
    }
}

#include <teamcenter/services/configuration/Configuration_undef.h>
#endif

