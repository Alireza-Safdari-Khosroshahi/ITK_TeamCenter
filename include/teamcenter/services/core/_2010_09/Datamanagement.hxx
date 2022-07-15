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

#ifndef TEAMCENTER_SERVICES_CORE__2010_09_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2010_09_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Fnd0StaticTable.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2010_09
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct CreateOrUpdateStaticTableDataResponse;
    struct EventObject;
    struct EventTypesOutput;
    struct EventTypesResponse;
    struct NameValueStruct1;
    struct PostEventObjectProperties;
    struct PostEventOutput;
    struct PostEventResponse;
    struct PropInfo;
    struct RowData;
    struct SetPropertyResponse;
    struct StaticTableDataResponse;
    struct StaticTableInfo;
    struct VerifyExtensionInfo;
    struct VerifyExtensionResponse;

    /**
     * This map has information about object and its properties.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< std::string > > ObjectPropMap;

    /**
     * A map of row attribute value pair. Value is vector to support typed reference attributes.
     */
    typedef std::map< std::string, std::vector< std::string > > RowAttrValueMap;

    /**
     * Contains Creation or updation response for Static table.
     */
    struct CreateOrUpdateStaticTableDataResponse
    {
        /**
         * SOA Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * StaticTable Object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0StaticTable>  staticTableObject;
    };

    /**
     * The <code>EventObject</code> structure represents required parameter to get event
     * type names for the businessObject.
     */
    struct EventObject
    {
        /**
         * A unique identifier supplied by the caller. This ID is client's way of identifying
         * event list.  This is a required parameter. If nothing is to be passed to clientId;
         * assign an empty String object. Assigning NULL to clientId is not allowed.
         */
        std::string clientId;
        /**
         * The Business Object for which the valid Auditable and Subscribable event type list
         * is to be retrieved. This is a required parameter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  businessObject;
    };

    /**
     * The <code>EventTypesOutput</code> structure represents the outputs, auditableEvents
     * and subscribableEvents, which are vectors of auditable event type names and subscribable
     * event type names.
     */
    struct EventTypesOutput
    {
        /**
         * Client unique identifier which is passed back for tracking the operation status.
         */
        std::string clientId;
        /**
         * The list of Auditable event type names.
         */
        std::vector< std::string > auditableEvents;
        /**
         * The list of Subscribable event type names
         */
        std::vector< std::string > subscribableEvents;
    };

    /**
     * The <code>EventTypesResponse</code> structure represents the output response returning
     * a vector  of <code>EventTypesOutput</code> with partial errors wrapped in  serviceData,
     * if any.
     */
    struct EventTypesResponse
    {
        /**
         * A vector of <code>EventTypesOutput</code> structures packaged in custom response.
         * Success is defined by the return of the <code>ifailError</code> for <b>getEventTypes</b>
         * on each of the <code>businessObject</code>.
         */
        std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::EventTypesOutput > output;
        /**
         * Partial failures will be returned in the ServiceDate for each failed processing.
         * Error encountered while processing post event on element in the set is reported as
         * partial errors and processing continues for the remaining elements in the input set.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains property name and value pairs for each property.
     */
    struct NameValueStruct1
    {
        /**
         * Name of the property
         */
        std::string name;
        /**
         * Values of the property
         */
        std::vector< std::string > values;
    };

    /**
     * The <code>PostEventObjectProperties</code> structure represents required parameters
     * to post event on primaryObject when event eventTypeName occurs.
     */
    struct PostEventObjectProperties
    {
        /**
         * A unique identifier supplied by the caller. This ID is used to identify return PostEventOutput
         * and partial errors assocaited with this input structure. This is optional, provide
         * empty String for null or optional value i.e. new String[0].
         */
        std::string clientId;
        /**
         * The Business Object on which the event has occurred. This is a required parameter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  primaryObject;
        /**
         * Secondary object should be passed when an event involves two objects, primaryObject
         * and secondaryObject and writing the secondaryObject details conveys complete Audit
         * information. Example, attaching license to Item. This is optional, provide null value
         * for optional value.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondaryObject;
        /**
         * The propertyCount is the count of properties that user wants to be written  to Audit
         * log. If the propertyCount is 0 the propertyNames and propertyValues will be ignored
         * and treated as NULL values. This is optional and default value is 0.
         */
        int propertyCount;
        /**
         * The propertyNames is the list of property names to be written to audit log. The total
         * number of properties to write depends on the propertyCount value. This is optional,
         * provide empty String for null or optional value i.e. new String[0].
         */
        std::vector< std::string > propertyNames;
        /**
         * The propertyValues is the list of property values to be written to audit log for
         * each of the propertyNames. The total number of properties to write depends on the
         * propertyCount and propertyNames value. Any of these values if not specified will
         * treat propertyValues as NULL.  This is optional, provide empty String for null or
         * optional value i.e. new String[0].
         */
        std::vector< std::string > propertyValues;
        /**
         * Specify error code when failure of an event is to be recorded in audit log. This
         * is optional and default value is 0.
         */
        int errorCode;
        /**
         * Specify error message when failure of an event is to be recorded in audit log. This
         * is optional, you should provide empty String object for null or optional value i.e.
         * new String[0].
         */
        std::string errorMessage;
    };

    /**
     * The <code>PostEventOutput</code> structure represents the output success or failure
     * for each of the <code>PostEventObjectProperties</code> structure in ifailError  for
     * the assocaited clientId.
     */
    struct PostEventOutput
    {
        /**
         * Client unique identifier which is passed back for tracking the operation status.
         */
        std::string clientId;
        /**
         * The error code, if any. Packaged in the custom output response.
         */
        int ifailError;
    };

    /**
     * The <code>PostEventResponse</code> structure represents the output returning a vector
     * of <code>PostEventOutput</code>  with partial errors wrapped in serviceData, if any.
     */
    struct PostEventResponse
    {
        /**
         * A vector of <code>PostEventOutput</code> structures packaged in custom response.
         * Success is defined by the return of the ifailError for post event on each of the
         * primaryObject.
         */
        std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::PostEventOutput > output;
        /**
         * Partial failures will be returned in the Service Data for each failed processing.
         * Error encountered while processing post event on element in the set is reported as
         * partial errors and processing continues for the remaining elements in the input set.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure holds information about Teamcenter object & its timestamp and list
     * of property name/value pair information.
     */
    struct PropInfo
    {
        /**
         * business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Vector of property information
         */
        std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::NameValueStruct1 > vecNameVal;
        /**
         * Timestamp of the object when object was exported to clients.
         */
        Teamcenter::Soa::Common::DateTime timestamp;
    };

    /**
     * Row Data
     */
    struct RowData
    {
        /**
         * clientId
         */
        std::string clientId;
        /**
         * Row Object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  rowObject;
        /**
         * RowType
         */
        std::string rowType;
        /**
         * Row Attribute Value Pair Map
         */
        RowAttrValueMap rowAttrValueMap;
    };

    /**
     * response structure for setProperties operation. It returns the information about
     * overwritten objects.
     */
    struct SetPropertyResponse
    {
        /**
         * This is the service data. It contains the updated objects and their properties.
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * Additional information to be communicated to client such as objects and props those
         * are overwritten. This map can be empty if no overwritten object found or with <b>QUERY</b>
         * option is not an input to the service operation.
         */
        ObjectPropMap objPropMap;
    };

    /**
     * StaticTableDataResponse
     */
    struct StaticTableDataResponse
    {
        /**
         * A unique string supplied by caller.
         * <br>
         * This ID is used to identify return data elements and partial errors associated with
         * this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Static Table Info
     */
    struct StaticTableInfo
    {
        /**
         * type of table created/updated e.g. TableProperties
         */
        std::string tableType;
        /**
         * <b>Fnd0StaticTable</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0StaticTable>  tableObject;
    };

    /**
     * The required information in which to validate an extension exists on an operation
     * for a specific type.
     */
    struct VerifyExtensionInfo
    {
        /**
         * The name of the type in which to check the operations.
         */
        std::string typeName;
        /**
         * The name of the operation in which to check for the containing extension.
         */
        std::string operationName;
        /**
         * The name of the extension to check.
         */
        std::string extensionName;
        /**
         * The extension type to check: 0=All, 1=PreCondition, 2=PreAction, 3=PostAction, 4=BaseAction
         */
        int extensionType;
    };

    /**
     * The result of the Verify Extension method.
     */
    struct VerifyExtensionResponse
    {
        /**
         * Returns True if extension exists otherwise False.
         */
        std::vector< bool > output;
        /**
         * This data structure provides service data for associated information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is provided to update Teamcenter object instances for the given name/value
     * pairs. This operation works for all supported property value types. Each object need
     * to be passed with its property name/value pairs.Passing options are <b>not</b> mandatory,
     * <b>empty</b> list is allowed. When <b>no</b> options are provided, it just updates
     * the objects as per the inputs. Alternatively you can pass following valid options
     * to control updating the data.
     * <br>
     * <ul>
     * <li type="disc"><b>QUERY</b>: option is used to define the overall behavior of object
     * properties setting from Excel Live and Word Live. Once this option is passed, server
     * honours the preference value of TC_setProperties. Please see the Preferences and
     * Environment Variables Reference documentation for preference TC_setProperties for
     * more information.
     * </li>
     * </ul>
     * <br>
     * Note:It must be the 0th element when set as in the option list.
     * <br>
     * <ul>
     * <li type="disc"><b>ENABLE_PSE_BULLETIN_BOARD</b>: To enable the generation of PSE
     * bulletin board events. These events are processed through Bulletin board callback
     * mechanism.
     * </li>
     * </ul>
     *
     * @param info
     *        List of PropInfo structure which consists of information about the objects and the
     *        property values to set.
     *
     * @param options
     *        To updating the objects in controlled manner. Valid options are:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>No</b> options can be passed to update the objects as per the
     *        inputs.
     *        </li>
     *        <li type="disc"><b>QUERY</b> If this option is set please see the Preferences and
     *        Environment Variables Reference documentation for preference TC_setProperties for
     *        more information.
     *        </li>
     *        </ul>
     *        <br>
     *        Note: <b>QUERY</b> option must be the 0th element when set as in the option list.
     *        <br>
     *        <ul>
     *        <li type="disc"><b>ENABLE_PSE_BULLETIN_BOARD</b> To enable the generation of PSE
     *        bulletin board events.
     *        </li>
     *        </ul>
     *
     * @return
     *         Response structure for set Properties SOA.
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::SetPropertyResponse setProperties ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::PropInfo >& info,
        const std::vector< std::string >& options ) = 0;

    /**
     * This operation checks if an extension exists on an operation of a specific type.
     *
     * @param extensionInfo
     *        The specific type, operation and extension information required to verify an extension
     *        exists.
     *
     * @return
     *         If extension exists.
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::VerifyExtensionResponse verifyExtension ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::VerifyExtensionInfo >& extensionInfo ) = 0;

    /**
     * This creates a new Table along with Rows or updates an existing Table with rows and
     * their values based on input StaticTableInfo and created Table rows are added to the
     * Table. ServiceData is updated with newly created/updated Table.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to create/update the data for TableProperties objects of Fnd0StaticTable
     * object. When user selects <b>Cdm0DataReqItemRevision</b> object, the attribute cdm0EventsList
     * is displayed in the summary as well as on View/Edit Properties menu in RAC. The attribute
     * cdm0EventsList is type referenced to <b>Fnd0StaticTable</b>.
     * <br>
     * User can add the data in columns for each row of the table or adds rows to the table
     * or deletes rows. After creation/updation of the table, user saves the object which
     * invokes this SOA operation.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getStaticTableData
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Contract Data Management - Provides functionality to save or retrieve Event List
     * data for Data Requirement Item Revision
     *
     * @param staticTableInfo
     *        This represents static table object that needs to be created/updated.
     *
     * @param rowProperties
     *        Vector of RowData where each element is of type TableProperties
     *
     * @return
     *         Returns CreateOrUpdateStaticTableResponse with service data with table object which
     *         is created and created/updated row objects. This operation returns no errors internally.
     *         However, errors from following Teamcenter API calls are added to the ServiceData's
     *         error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">POM_attr_id_of_attr()
     *         </li>
     *         <li type="disc">TCTYPE_ask_type()
     *         </li>
     *         <li type="disc">TCTYPE_ask_create_descriptor()
     *         </li>
     *         <li type="disc">TCTYPE_construct_create_input()
     *         </li>
     *         <li type="disc">TCTYPE_create_object()
     *         </li>
     *         <li type="disc">AOM_save_with_extensions()
     *         </li>
     *         <li type="disc">AOM_save()
     *         </li>
     *         <li type="disc">AttributeAccessor::appendTag()
     *         </li>
     *         <li type="disc">tableResponse.serviceData.addCreatedObject()
     *         </li>
     *         </ul>
     *         <br>
     *         (This list may be incomplete, and is subject to change without notice.)
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::CreateOrUpdateStaticTableDataResponse createOrUpdateStaticTableData ( const Teamcenter::Services::Core::_2010_09::Datamanagement::StaticTableInfo&  staticTableInfo,
        const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::RowData >& rowProperties ) = 0;

    /**
     * Returns a list of objects of type TableProperties which are associated with <b>Fnd0StaticTable</b>
     * object. <b>Fnd0StaticTable</b> object has an attribute fnd0StaticTableData which
     * is an array of <b>TableProperties</b> objects.  Any failures will be returned with
     * the input object mapped to the error message in the ServiceData list of partial errors.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used to get the data for attribute fnd0StaticTableData of <b>Fnd0StaticTable</b>
     * object. Attribute fhd0StaticTableData is an array of TableProperties objects. When
     * user selects <b>Cdm0DataReqItemRevision</b> object, the attribute cdm0EventsList
     * is displayed in the summary as well as on View/Edit Properties menu in RAC. The attribute
     * cdm0EventsList is Typed Reference to <b>Fnd0StaticTable</b> object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateStaticTableData
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Contract Data Management - Provides functionality to save or retrieve Event List
     * data for Data Requirement Item Revision
     *
     * @param staticTable
     *        StaticTable
     *
     * @return
     *         A list of <b>TableProperties</b> objects. One for each successfully created row of
     *         fnd0StaticTableData attribute of <b>Fnd0StaticTable</b> object. This operation returns
     *         no errors internally. However, errors from following Teamcenter API calls are added
     *         to the ServiceData's error stack:
     *         <br>
     *         <ul>
     *         <li type="disc">POM_attr_id_of_attr()
     *         </li>
     *         <li type="disc">AttributeAccessor::getTagValues()
     *         </li>
     *         <li type="disc">tableResponse.serviceData.addPlainObject()
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::StaticTableDataResponse getStaticTableData ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0StaticTable>  staticTable ) = 0;

    /**
     * The <b>getEventTypes</b> operation retrieves the valid Auditable and Subscribable
     * events for each of the businessObject in the input <code>EventObject</code> vector.
     * When an event is auditable, you can audit actions on Teamcenter objects when that
     * event happens on the businessObject. When an event is Subscribable, that means subscriptions
     * can be created for that event. Partial failures, if any, will be returned in the
     * serviceData.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Subscription Management - Application that allows to subscribe to certain events
     * such as checkin etc on business objects.
     *
     * @param input
     *        A vector of <code>EventObject</code> structure consisting of list of Business Objects,
     *        for which the valid auditable and subscribable events are to be fetched.
     *
     * @return
     *         Output is a vector of eventsOutput structures packaged in a custom response. Partial
     *         failures will be returned in the ServiceData as a map of client id to error message.
     *
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::EventTypesResponse getEventTypes ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::EventObject >& input ) = 0;

    /**
     * This operation will post an event for each of the Teamcenter business objects in
     * the input list, with all the supplied information: <code>secondaryObject</code>,
     * properties to be logged, and the error details. . Partial failures will be returned
     * in the <code>serviceData</code>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Most events are posted by Teamcenter server logic. Use this operation to make an
     * event known only to your client code recorded in Audit Manager or supported by Subscription
     * Manager.
     * <br>
     * <b>Use Case1</b>: Auditing events
     * <br>
     * This operation helps auditing Teamcenter objects history by logging audit records
     * when event eventTypeName occurs on primaryObject.
     * <br>
     * <ul>
     * <li type="disc">When site preference TC_audit_manager is set to ON and no Audit Definition
     * exists for object type primaryObject and the eventTypeName, no audit records will
     * be logged. Audit Definitions are Audit Manager Application configurations and can
     * be viewed in Audit Manager Application.
     * </li>
     * <li type="disc">When site preference TC_audit_manager is set to ON and Audit Definition
     * exists for object type primaryObject and the eventTypeName, audit records will be
     * logged with all the information provided in the structure PostEventObjectProperties
     * </li>
     * <li type="disc">No audit records are written when preference TC_audit_manager is
     * set to OFF or if the event posted is not defined as Auditable.
     * </li>
     * </ul>
     * <br>
     * <b>
     * <br>
     * Use Case2</b>: Subscription Notifications&nbsp;&nbsp;&nbsp;&nbsp;
     * <br>
     * the site preference TC_subscription is set to ON , users can create subscriptions
     * for notifications for certain events on Teamcenter Objects  The event posted must
     * be described as subscribable and there should also exist an associated subscription
     * object for the notification to occur.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Subscription Management - Application that allows to subscribe to certain events
     * such as checkin etc on business objects.
     *
     * @param input
     *        A vector of <code>ObjectProperties</code> structure. Each structure consists of Primary
     *        Business Object, a manadatory parameter, on which event has occurred, any secondary
     *        object to post its information, along with any additional properties and the values
     *        and error code while performing the event.
     *
     * @param eventTypeName
     *        Name of the event. This is a mandatory parameter and should be a valid auditable
     *        or subscribable event mapped for the primary object. List of valid event types could
     *        be found using command line utility: install_event_types
     *
     * @return
     *         <code>PostEventResponse</code>, a vector of <code>postEventOutput</code> structures
     *         packaged in a custom response of returning back the unique identifier <code>clientId</code>
     *         for tracking the operation with failure code(<code>ifailError</code>) if any. Success
     *         is defined by the return of ifailError for post event on each Business Object, primaryObject.
     *         If error is encountered while processing post event on elements in the set, it is
     *         reported as partial errors and processing continues for the remaining elements in
     *         the input set. Partial failures will be returned in the  serviceData.
     *
     *
     * @exception ServiceException
     *           Service Exception.
     *           <br>
     *           Throws ServiceException with error message, error code, error count and severity.
     *           Error code and message will be returned as per which audit or notification operation
     *           failed during processing.
     */
    virtual Teamcenter::Services::Core::_2010_09::Datamanagement::PostEventResponse postEvent ( const std::vector< Teamcenter::Services::Core::_2010_09::Datamanagement::PostEventObjectProperties >& input,
        const std::string&  eventTypeName ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

