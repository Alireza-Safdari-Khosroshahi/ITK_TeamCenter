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

#ifndef TEAMCENTER_SERVICES_CONFIGURATION_SMARTUIBLDRSERVICE_HXX
#define TEAMCENTER_SERVICES_CONFIGURATION_SMARTUIBLDRSERVICE_HXX

#include <teamcenter/services/configuration/_2010_04/Smartuibldr.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/configuration/Configuration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Configuration
        {
            class SmartuibldrService;

/**
 * The SmartUiBldr service helps any client to generate Custom Item Ids based on LOVs
 * and configurations as defined in the system. The SmartUiBldr service exposes operations
 * that are used to develop interactive composing of custom item ids.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaconfigurationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaconfigurationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACONFIGURATIONSTRONGMNGD_API SmartuibldrService
    : public Teamcenter::Services::Configuration::_2010_04::Smartuibldr
{
public:
    static SmartuibldrService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SmartuibldrService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/configuration/Configuration_undef.h>
#endif

