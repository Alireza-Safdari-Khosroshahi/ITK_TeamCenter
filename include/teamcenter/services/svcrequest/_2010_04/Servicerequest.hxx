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

#ifndef TEAMCENTER_SERVICES_SVCREQUEST__2010_04_SERVICEREQUEST_HXX
#define TEAMCENTER_SERVICES_SVCREQUEST__2010_04_SERVICEREQUEST_HXX

#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>
#include <teamcenter/soa/client/model/SRP0GnSrvRequestRevision.hxx>
#include <teamcenter/soa/client/model/SRP0RqstActivityRevision.hxx>
#include <teamcenter/soa/client/model/SRP0ServiceCatalog.hxx>
#include <teamcenter/soa/client/model/SRP0ServiceOffering.hxx>
#include <teamcenter/soa/client/model/SRP0SrvRequestRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/svcrequest/SvcRequest_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Svcrequest
        {
            namespace _2010_04
            {
                class Servicerequest;

class TCSOASVCREQUESTSTRONGMNGD_API Servicerequest
{
public:

    struct CancelInput;
    struct CancelOut;
    struct CancelResponse;
    struct DelegateInput;
    struct DelegateOut;
    struct DelegateResponse;
    struct GetSvcOfferingOrCatalogInput;
    struct GetSvcOfferingOrCatalogOut;
    struct GetSvcOfferingOrCatalogResponse;
    struct QualifyInput;
    struct QualifyOut;
    struct QualifyResponse;
    struct TimeCostInput;
    struct TimeCostOut;
    struct TimeCostResponse;

    /**
     * Date property map
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * String Name value pair
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * The input for the cancel operation. It contains the request object to be canceled.
     */
    struct CancelInput
    {
        /**
         * A unique client identifier. This is a unique string supplied by the caller. This
         * ID
         * <br>
         * is used to identify return data elements and partial errors associated with this
         * input structure.
         * <br>
         */
        std::string clientId;
        /**
         * The request object to be canceled. This object can be a Requested Activity,
         * <br>
         * Primary Service Request or a Delegate Service Request.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision>  request;
    };

    /**
     * The request that was cancelled
     */
    struct CancelOut
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * the cancelled request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision>  output;
    };

    /**
     * Structure containing vector of canceled objects and service data containing partial
     * errors.
     */
    struct CancelResponse
    {
        /**
         * Vector of cancelled objects
         */
        std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::CancelOut > output;
        /**
         * The SOA framework object containing objects that were created, deleted,or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input for the delegate requested activities operation
     */
    struct DelegateInput
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * The primary service request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision>  primaryServiceRequest;
        /**
         * Set to true if a new delegate is to be created
         */
        bool newDelegate;
        /**
         * String properties for the new delegate service request
         */
        StringMap delegateStringProps;
        /**
         * Date properties for the delegate service request
         */
        DateMap delegateDateProps;
        /**
         * Company contact object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  delegateContact;
        /**
         * Company Location object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  delegateLocation;
        /**
         * The service request to perform the requested activities
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision>  performsServiceRequest;
        /**
         * The requested activities to delegate
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0RqstActivityRevision>  > requestedActivities;
    };

    /**
     * Structure containing a list of output objects representing delegate service requests
     * that were created.
     */
    struct DelegateOut
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * New Performs Service Requests
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision>  newPerforms;
        /**
         * This is a vector of service request that have been modified
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision>  > currPerforms;
    };

    /**
     * Structure containing a list of delegate service request objects and service data
     * containing partial errors.
     */
    struct DelegateResponse
    {
        /**
         * Vector of delegate out objects
         */
        std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::DelegateOut > output;
        /**
         * The SOA framework object containing objects that were created, deleted,or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * the input for the getServiceOfferingOrServiceCatalogObjs operation
     */
    struct GetSvcOfferingOrCatalogInput
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * String properties for the service offering query. Ex: "prop_name" = "prop_value"
         */
        StringMap queryProps;
        /**
         * This is physical part to get the service catalogs from.If the vector of service catalogs
         * is empty, this is used to find the service catalogs.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  physicalPart;
        /**
         * This is a vector of service catalogs to get the service offerings from. If this is
         * empty then the operation will get the service catalogs from the physical part.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0ServiceCatalog>  > svcCatalogs;
    };

    /**
     * The service catalogs or service offerings
     */
    struct GetSvcOfferingOrCatalogOut
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * This is a vector of service offerings
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0ServiceOffering>  > svcOfferings;
        /**
         * This is a vector of service catalogs
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0ServiceCatalog>  > svcCatalogs;
    };

    /**
     * <code>GetSvcOfferingOrCatalogResponse</code> structure contains a list of Service
     * Catalog and Offering objects. It also contains standard Service Data that contain
     * partial errors.
     */
    struct GetSvcOfferingOrCatalogResponse
    {
        /**
         * Vector of <code>GetSvcOfferingOrCatalogOut</code> objects
         */
        std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::GetSvcOfferingOrCatalogOut > output;
        /**
         * The SOA framework object containing objects that were created, deleted,or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input for the qualifyActivity function
     */
    struct QualifyInput
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * If set to true, requalify the requested activity.
         */
        bool requalify;
        /**
         * RequestedActivity
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0RqstActivityRevision>  requestedActivity;
        /**
         * String properties for requested activity
         */
        StringMap stringProps;
        /**
         * Date properties
         */
        DateMap dateProps;
        /**
         * Product Physical Element
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  productPhysicalPart;
        /**
         * A vector of service offerings
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0ServiceOffering>  > serviceOfferings;
        /**
         * Service Request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision>  serviceRequest;
    };

    /**
     * Vector of output objects representing objects that were created
     */
    struct QualifyOut
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Vector of tags representing objects that were created
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0RqstActivityRevision>  > output;
    };

    /**
     * Structure containing a vector of Requested Activity objects and Service Data that
     * contains partial errors.
     */
    struct QualifyResponse
    {
        /**
         * Vector of output objects representing objects that were created
         */
        std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::QualifyOut > output;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input for the time and cost rollup operation
     */
    struct TimeCostInput
    {
        /**
         * A unique client identifier. This is a unique string supplied by the caller. This
         * ID
         * <br>
         * is used to identify return data elements and partial errors associated with this
         * input structure.
         * <br>
         */
        std::string clientId;
        /**
         * The Service Request object whose time and cost information needs to be rolled
         * <br>
         * up from its related Requested Activity(s).
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision>  serviceRequest;
    };

    /**
     * A map of time and cost rollup values
     */
    struct TimeCostOut
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * Service Request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision>  serviceRequest;
        /**
         * The time and cost properties with rolled up values
         */
        StringMap timeCostProps;
    };

    /**
     * Vector of time and cost objects representing time and cost that was rolled up to
     * the service request.
     */
    struct TimeCostResponse
    {
        /**
         * Vector of time and cost values
         */
        std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::TimeCostOut > output;
        /**
         * The SOA framework object containing objects that were created, deleted,or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation cancels a Primary Service Request and its associated Requested Activity(s)
     * for each <code>CancelInput</code> supplied. The input can be a Primary Service Request,
     * Delegate Service Request(s) or any of its Requested Activity(s) associated with the
     * Primary Service Request through the Includes relationship. If the input parameter
     * is a Primary Service Request, then the service request is canceled and the Closure
     * attribute is set to <b>Canceled</b> state. Any Requested Activity(s) or Delegate
     * Service Request(s) that are in the <b>Requested</b> state will also be automatically
     * <b>Canceled</b>. The input parameter can also be a Requested Activity or a Delegate
     * Service Request in which case, the Closure attribute is set to <b>Canceled</b> for
     * the respective input supplied. If a requested activity is <b>Open</b> and is delegated
     * to a service request, an attempt to cancel the Delegate Service Request will throw
     * an appropriate warning message to the user using error code <b>246512</b>. An attempt
     * to cancel an object that is already canceled throws an appropriate warning message
     * telling the user that the object is already canceled. A canceled Requested Activity
     * cannot be delegated to a Service Request based on the condition <b>SRP0IsRequestedActivityDelegateable</b>.
     * Similarly, a new Requested Activity cannot be created for a canceled Primary Service
     * Request based on the condition <b>SRP0IsRequestedActivityCreatable</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Cancel Requested Activity</b>
     * <br>
     * This use case allows the user to cancel a Requested Activity based on the condition
     * <b>SRP0IsRequestedActivityCancelable</b> where the Closure is <b>Open</b> and the
     * Maturity is not in <b>Executing</b> state. The Closure will be set to <b>Canceled</b>.
     * <br>
     * <b>Use case 2: Cancel Service Request</b>
     * <br>
     * This use case allows the user to cancel a Service Request based on the condition
     * <b>SRP0IsServiceRequestCancelable</b>. The Closure attribute will be set to <b>Canceled</b>.
     * A Service Request cannot be canceled if it is Executing. If a Service Request is
     * canceled, any Requested Activities or Service Requests that are in the Requested
     * State will also be canceled.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        Object that is a Primary Service Request, Requested Activity or a Delegate
     *        <br>
     *        Service Request.
     *        <br>
     *
     * @return
     *         The cancel response is returned and the closure attribute for the input object is
     *         set to Canceled. If the input parameters are invalid or if sufficient conditions
     *         are not met for performing the cancel operation, errors are returned.  Following
     *         are some possible errors returned:
     *         <br>
     *         <ul>
     *         <li type="disc">246508:&nbsp;&nbsp;&nbsp;&nbsp;A remote object cannot be canceled.
     *         </li>
     *         <li type="disc">246509:&nbsp;&nbsp;&nbsp;&nbsp;The object of type object_type with
     *         name object_name is already canceled.
     *         </li>
     *         <li type="disc">246512:&nbsp;&nbsp;&nbsp;&nbsp;The Delegate Service Request cannot
     *         be canceled because the object of type SRP0RqstActivityRevision with name object_name
     *         is open.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::CancelResponse cancelRequest ( const std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::CancelInput >& input ) = 0;

    /**
     * Operation that delegates requested activities to new or existing service requests.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        input
     *
     * @return
     *         returns delegate response
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 10, this operation is set deprecated as 10.0 release. Use  delegateRequestedActivity2
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, this operation is set deprecated as 10.0 release. Use  delegateRequestedActivity2"))
#endif
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::DelegateResponse delegateRequestedActivity ( const std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::DelegateInput >& input ) = 0;

    /**
     * This operation is used to get the service offerings or service catalogs that are
     * related to the neutral part that a physical part is realized from.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Retrieve Available Service Offerings</b>
     * <br>
     * Based on the physical part identified for the Requested Activity as the Product Physical
     * Part, the available Service Catalogs and Service Offerings are retrieved and made
     * available for the user to select.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        The physical part that is realized from the neutral part that the Service Catalogs
     *        are related to.
     *
     * @return
     *         <code>GetSvcOfferingOrCatalogResponse</code> which contains a list of <code>GetSvcOfferingOrCatalogOut</code>
     *         structures and a standard Service Data.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::GetSvcOfferingOrCatalogResponse getSvcOfferingOrCatalogObjs ( const std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::GetSvcOfferingOrCatalogInput >& input ) = 0;

    /**
     * Operation that creates new requested activities base on service offerings.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        input
     *
     * @return
     *         Returns
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of Teamcenter 10, this operation is set deprecated as 10.0 release. Use  qualifyActivity2
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, this operation is set deprecated as 10.0 release. Use  qualifyActivity2"))
#endif
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::QualifyResponse qualifyActivity ( const std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::QualifyInput >& input ) = 0;

    /**
     * This operation rolls up time and cost information from the Requested Activity(s)
     * to the Service Request. The input parameter is a Service Request and when a user
     * edits or updates the estimated or actual time and cost information for a Requested
     * Activity, the values get rolled up to the parent Service Request. A user logged in
     * as an administrator can restrict certain users from being able to create the time
     * and cost information.
     * <br>
     * <br>
     * If the Requested Activity is catalog based and if the related Service Offering has
     * estimated time and cost information, those estimated values are copied to the estimated
     * time and cost values for the requested activity. These values can still be modified
     * if required by the user. If the Requested Activity is noncatalog based, no initial
     * cost estimates are created and a value can be entered if required. The time and cost
     * for the Primary Service Request is automatically rolled up from the time and cost
     * for all its related Requested Activity(s) in the <b>Includes Activity</b> folder.
     * The time and cost for a Delegate Service Request is rolled up from its related Requested
     * Activity(s) located in the <b>Performs</b> folder. The time and cost for Requested
     * Activity(s) are not rolled up if they have the following values set for any of the
     * properties as illustrated below:
     * <br>
     * <ul>
     * <li type="disc"><b>Closure Value</b>:Canceled
     * </li>
     * <li type="disc"><b>Maturity Value</b>:Superseded
     * </li>
     * <li type="disc"><b>Disposition Value</b>:Disapproved
     * </li>
     * </ul>
     * <br>
     * A user can change the settings for these properties value by modifying the condition
     * <b>SRP0IsRequestedActivityInvalidforRollup</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case1: Edit Actual Time and Cost of Requested Activity</b>
     * <br>
     * A user is allowed to enter the actual time and cost details for a Requested Activity.
     * The ability to update time and cost information is controlled independently of the
     * Requested Activity and limited to members of a specific group.
     * <br>
     * <b>Use Case 2: Edit Estimated Time and Cost of Requested Activity</b>
     * <br>
     * This operation allows the user to indicate an estimated time and cost for a Requested
     * Activity. If the Requested Activity was created from a Service Offering, the initial
     * time and cost estimate should be copied from the Service Offering to the Requested
     * Activity.
     * <br>
     * <b>Use Case 3: Rollup Requested Activity Actuals to Service Request</b>
     * <br>
     * This use case is performed by the system. If the user updates an actual time or cost
     * value on a Requested Activity, the system rolls that value up to the parent Service
     * Request(s). The Primary Service Request should have a rollup of all of the activities
     * that were requested. The Delegate Request should include all of the requested activities
     * that are performed as part of that Service Request.
     * <br>
     * <b>Use Case 4: Rollup Requested Activity Estimates to Service Request</b>
     * <br>
     * This use case is performed by the system. If a user updates an estimated time or
     * cost value on a Requested Activity, the system rolls up that value up to the parent
     * Service Request(s).
     * <br>
     * <b>Use Case 5: View Time and Cost Information
     * <br>
     * </b>A specific group of users are provided with the ability to view the time and
     * cost information of all Service Request and Requested Activities.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        Object that is a Service Request.
     *
     * @return
     *         The rolled up time and cost information is returned as response. If the input parameters
     *         are invalid or if sufficient conditions are not met for performing the time and cost
     *         rollup operation, error messages are returned. Following are some possible errors
     *         returned:
     *         <br>
     *         <ul>
     *         <li type="disc">246507:&nbsp;&nbsp;&nbsp;&nbsp;A remote Service Request object cannot
     *         display rolled up time and cost.
     *         </li>
     *         <li type="disc">246515:&nbsp;&nbsp;&nbsp;&nbsp;Rollup of time and cost is not possible
     *         because of data access limits.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::TimeCostResponse timeAndCostRollup ( const std::vector< Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::TimeCostInput >& input ) = 0;


protected:
    virtual ~Servicerequest() {}
};
            }
        }
    }
}

#include <teamcenter/services/svcrequest/SvcRequest_undef.h>
#endif

