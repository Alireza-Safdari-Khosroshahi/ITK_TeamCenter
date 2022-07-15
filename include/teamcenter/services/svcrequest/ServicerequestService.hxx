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

#ifndef TEAMCENTER_SERVICES_SVCREQUEST_SERVICEREQUESTSERVICE_HXX
#define TEAMCENTER_SERVICES_SVCREQUEST_SERVICEREQUESTSERVICE_HXX

#include <teamcenter/services/svcrequest/_2010_04/Servicerequest.hxx>
#include <teamcenter/services/svcrequest/_2012_02/Servicerequest.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/svcrequest/SvcRequest_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Svcrequest
        {
            class ServicerequestService;

/**
 * ServiceRequest service
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoasvcrequeststrongmngd.dll
 * </li>
 * <li type="disc">libtcsoasvcrequesttypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASVCREQUESTSTRONGMNGD_API ServicerequestService
    : public Teamcenter::Services::Svcrequest::_2010_04::Servicerequest,
             public Teamcenter::Services::Svcrequest::_2012_02::Servicerequest
{
public:
    static ServicerequestService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation delegates Requested Activities to new or existing Service Requests.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case 1: Delegate Requested Activity to a new Service Request</b>
     * <br>
     * User delegates the Requested Activity to a delegated Service Request.
     * <br>
     * <b>Use Case 2: Identify Service Request to address some Requested Activities</b>
     * <br>
     * User identifies an additional (delegated) Service Request to address some of the
     * Requested Activities from the original Service Request.  Requested Activities from
     * the first Service Request can be added to the additional Service Request.  During
     * this operation, the user will be presented with an opportunity to identify the Requested
     * Activities to be moved to the identified Service Request.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        The container of objects that are used to create Requested Activities.
     *
     * @return
     *         The container of Delegate Service Requests that were created.
     *
     */
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::DelegateResponse delegateRequestedActivity2 ( const std::vector< Teamcenter::Services::Svcrequest::_2012_02::Servicerequest::DelegateRqstInput >& input ) = 0;

    /**
     * This Operation qualifies and creates new Requested Activities.  Processing includes
     * the creation of relations between the Requested Activity and the parent Service Request,
     * the Product Physical Part, any selected Service Offerings and Activity Cost.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Create and Relate Requested Activity to Service Request</b>
     * <br>
     * This use case allows the user to create a Requested Activity from the perspective
     * of a Service Request.  A Requested Activity is created and the relationship between
     * the Requested Activity and the Service Request is also created.
     * <br>
     * <b>Create NonCatalog Requested Activity</b>
     * <br>
     * This use case allows a user to create a Requested Activity without an identified
     * Service Offering.  The user identifies one of the Product physical parts from the
     * parent Service Request for which the Requested Activity will be created.  If only
     * one Product physical part is identified on the parent Service Request, then it is
     * automatically designated as the Product physical part for the Requested Activity.
     * <br>
     * <b>Create Relationship between Requested Activity and Service Offering</b>
     * <br>
     * The system creates the relationship between the Requested Activity and the Service
     * Offering that identifies the standard service to be performed.
     * <br>
     * <b>Create Requested Activity</b>
     * <br>
     * This use case allows the user to create the specific Requested Activities that identify
     * the complete requested work scope of the Service Request.  Each Requested Activity
     * identifies the work to be done, the Product Physical part, and optionally the impacted
     * and problem physical part.  A Requested Activity can only be for one Product Physical
     * Part.
     * <br>
     * <b>Create Requested Activity based on Service Offering</b>
     * <br>
     * User creates a Requested Activity based on a Service Offering contained within the
     * Service Catalog related to the Product Neutral Part.  The user identifies one of
     * the Product physical parts from the parent Service Request for which the Requested
     * Activity will be created.  If only one Product physical part is identified on the
     * parent Service Request, then it is automatically designated as the Product physical
     * part for the Requested Activity.  The user is presented with the available Service
     * Offering for that Product Physical Part and selects the appropriate ones based on
     * their need.  A Requested Activity is created for every Service Offering selected.
     * The Requested Activity is related to both the Product Physical Part, and the Service
     * Offering.  The narrative and initial time and cost estimates are copied from the
     * Service Offering to the Requested Activity.
     * <br>
     * <b>Requalify Requested Activity</b>
     * <br>
     * This use case allows the user to requalify the Service Offering that a Requested
     * Activity is related to, or add a Service Offering if the Requested Activity is not
     * related to a Service Offering.  There could be multiple Service Offerings that are
     * identified as the services required to fulfill a particular Requested Activity. The
     * system will create additional Requested Activities as necessary to accommodate the
     * additional catalog based requests.  The user will be asked whether or not to update
     * the Requested Activity with the narrative and time and cost estimates from the Service
     * Offering.
     * <br>
     * <b>Retrieve Available Service Offerings</b>
     * <br>
     * The available Service Offerings are retrieved and available to the user based on
     * the physical part identified for the Requested Activity as the Product Physical Part.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Request Processing - This Component is intended to identify all Operations
     * and Services under Service Request Processing.
     *
     * @param input
     *        The container of objects that are used to create Requested Activities.
     *
     * @return
     *         The container of Requested Activities that were created.
     *
     */
    virtual Teamcenter::Services::Svcrequest::_2010_04::Servicerequest::QualifyResponse qualifyActivity2 ( const std::vector< Teamcenter::Services::Svcrequest::_2012_02::Servicerequest::QualifyRqstInput >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ServicerequestService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/svcrequest/SvcRequest_undef.h>
#endif

