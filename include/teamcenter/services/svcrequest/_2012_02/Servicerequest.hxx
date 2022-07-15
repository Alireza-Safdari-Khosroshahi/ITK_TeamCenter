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

#ifndef TEAMCENTER_SERVICES_SVCREQUEST__2012_02_SERVICEREQUEST_HXX
#define TEAMCENTER_SERVICES_SVCREQUEST__2012_02_SERVICEREQUEST_HXX

#include <teamcenter/services/svcrequest/_2010_04/Servicerequest.hxx>
#include <teamcenter/soa/client/model/SRP0GnSrvRequestRevision.hxx>
#include <teamcenter/soa/client/model/SRP0RqstActivityRevision.hxx>
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
            namespace _2012_02
            {
                class Servicerequest;

class TCSOASVCREQUESTSTRONGMNGD_API Servicerequest
{
public:

    struct SvcRqCreateInput;
    struct DelegateRqstInput;
    struct QualifyRqstInput;

    /**
     * Attribute boolean Map
     */
    typedef std::map< std::string, bool > BooleanMap;

    /**
     * Attribute boolean vector map
     */
    typedef std::map< std::string, std::vector< bool > > BooleanVectorMap;

    /**
     * Attribute date map
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DatesMap;

    /**
     * Attribute date vector map
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * Attribute double map
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * Attribute double vector map
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * Attribute foat map
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * Attribute float array map
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * Attribute integer map
     */
    typedef std::map< std::string, int > IntegerMap;

    /**
     * attribute integer vector map
     */
    typedef std::map< std::string, std::vector< int > > IntegerVectorMap;

    /**
     * Attribute Strings map
     */
    typedef std::map< std::string, std::string > StringsMap;

    /**
     * Attribute string vector map
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * Attribute reference map
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * Attribute reference vector map
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * Service Request create input
     */
    struct SvcRqCreateInput
    {
        /**
         * Property string name/value
         */
        StringsMap stringProps;
        /**
         * Property string array name/value
         */
        StringVectorMap stringArrayProps;
        /**
         * Property boolean name/value
         */
        BooleanMap boolProps;
        /**
         * Property boolean array name/value
         */
        BooleanVectorMap boolArrayProps;
        /**
         * Property double name/value
         */
        DoubleMap doubleProps;
        /**
         * Property double array name/value
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Property date name/value
         */
        DatesMap dateProps;
        /**
         * Property date array name/value
         */
        DateVectorMap dateArrayProps;
        /**
         * Property integer name/value
         */
        IntegerMap intProps;
        /**
         * Property integer array name/value
         */
        IntegerVectorMap intArrayProps;
        /**
         * Property reference name/value
         */
        TagMap tagProps;
        /**
         * Property reference array name/value
         */
        TagVectorMap tagArrayProps;
        /**
         * attribute float name/value
         */
        FloatMap floatProps;
        /**
         * attribute float array name/value
         */
        FloatVectorMap floatArrayProps;
    };

    /**
     * input for the delegate requested activities operation
     */
    struct DelegateRqstInput
    {
        /**
         * Client Id
         */
        std::string clientId;
        /**
         * Primary Service Request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0GnSrvRequestRevision>  primaryServiceRequest;
        /**
         * New delegate request
         */
        bool newDelegate;
        /**
         * Item object
         */
        Teamcenter::Services::Svcrequest::_2012_02::Servicerequest::SvcRqCreateInput itemData;
        /**
         * Item revision object
         */
        Teamcenter::Services::Svcrequest::_2012_02::Servicerequest::SvcRqCreateInput itemRevData;
        /**
         * Business Object Name
         */
        std::string boName;
        /**
         * Perform Service Request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0SrvRequestRevision>  performsServiceRequest;
        /**
         * Requested Activity Revision array
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::SRP0RqstActivityRevision>  > requestedActivities;
    };

    /**
     * Requested Activity create input structure
     */
    struct QualifyRqstInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * If set to true, re qualify the Requested Activity.
         */
        bool requalify;
        /**
         * Name of the business object being created
         */
        std::string boName;
        /**
         * item Data for parent Service Request, Product Physical Part and Service Offerings
         */
        Teamcenter::Services::Svcrequest::_2012_02::Servicerequest::SvcRqCreateInput itemData;
        /**
         * item Revision Data for parent Service Request, Product Physical Part and Service
         * Offerings
         */
        Teamcenter::Services::Svcrequest::_2012_02::Servicerequest::SvcRqCreateInput itemRevData;
    };




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


protected:
    virtual ~Servicerequest() {}
};
            }
        }
    }
}

#include <teamcenter/services/svcrequest/SvcRequest_undef.h>
#endif

