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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2009_10_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2009_10_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2009_10
            {
                class Datamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Datamanagement
{
public:

    struct CreateInput;
    struct CreateIn;
    struct CreateOut;
    struct CreateResponse;
    struct DisconnectInput;

    /**
     * BoolMap
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * BoolVectorMap
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * CreateInputMap
     */
    typedef std::map< std::string, std::vector< CreateInput > > CreateInputMap;

    /**
     * DateMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * DateVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * DoubleMap
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * DoubleVectorMap
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * FloatMap
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * FloatVectorMap
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * IntMap
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * IntVectorMap
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * StringMap
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * StringVectorMap
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * TagMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * TagVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * CreateInput structure used to capture the inputs required for creation of a business
     * object. This is a recursive structure containing the CreateInput(s) for any secondary
     * (compounded) objects that might be created (e.g Item also creates ItemRevision and
     * ItemMasterForm, etc.)
     */
    struct CreateInput
    {
        /**
         * Business Object type name
         */
        std::string type;
        /**
         * Map containing string property values
         */
        StringMap stringProps;
        /**
         * Map containing string array property values
         */
        StringVectorMap stringArrayProps;
        /**
         * Map containing string property values
         */
        DoubleMap doubleProps;
        /**
         * Map containing string array property values
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map containing string property values
         */
        FloatMap floatProps;
        /**
         * Map containing string array property values
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map containing string property values
         */
        IntMap intProps;
        /**
         * Map containing string array property values
         */
        IntVectorMap intArrayProps;
        /**
         * Map containing string property values
         */
        BoolMap boolProps;
        /**
         * Map containing string array property values
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map containing DateTime property values
         */
        DateMap dateProps;
        /**
         * Map containing DateTime array property values
         */
        DateVectorMap dateArrayProps;
        /**
         * Map containing string property values
         */
        TagMap tagProps;
        /**
         * Map containing string array property values
         */
        TagVectorMap tagArrayProps;
        /**
         * CreateInput for compounded objects
         */
        CreateInputMap compoundCreateInput;
    };

    /**
     * Input for create operation including unique client identifier
     */
    struct CreateIn
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * The context for the new created object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * The target  to connect to
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  target;
        /**
         * The name of the relation to use to connect to the target. If the string is empty
         * then the relation defined as default will be used.
         */
        std::string relationName;
        /**
         * Input data for create operation
         */
        Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateInput data;
    };

    /**
     * Output for create operation including unique client identifier
     */
    struct CreateOut
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * Vector of tags representing objects that were created
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
    };

    /**
     * Response object for create operation
     */
    struct CreateResponse
    {
        /**
         * Vector of output objects representing objects that were created
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateOut > output;
        /**
         * Service data including partial errors that are mapped to the client id
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input for disconnect operation
     */
    struct DisconnectInput
    {
        /**
         * Unique client identifier
         */
        std::string clientId;
        /**
         * The object to disconnect
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The object to disconnect from
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  disconnectFrom;
        /**
         * The relation to disconnect in case 2 objects are connected by more than one relation
         */
        std::string relationName;
    };




    /**
     * Generic operation for creation of manufacturing objects. This will also create any
     * secondary(compounded) objects that need to be created, assuming the CreateInput for
     * the secondary object is represented in the recursive CreateInput object e.g. Item
     * is Primary Object that also creates ItemMasterForm, ItemRevision and ItemRevision
     * in turn creates ItemRevisionMasterForm. The input for all these levels is passed
     * in through the recursive CreateInput object. This operation creates the persistent
     * objects and the runtime objects accordingly. This operation also connects the created
     * objects to the specified target. The connection will be done by the relation defined
     * as default.
     *
     * @param input
     *        a list of CreateIn objects representing the Create Input for Business Objects to
     *        be created
     *
     * @return
     *         Contains a list of tags representing the objects that were created. Any failure will
     *         be returned with client id mapped to error message in the ServiceData list of partial
     *         errors.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateResponse createObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateIn >& input ) = 0;

    /**
     * Generic operation to disconnect objects.
     *
     * @param input
     *        A list of disconnectInput objects for the objects to disconnect
     *
     * @return
     *         Any failure will be returned with client id mapped to error message in the ServiceData
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData disconnectObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::DisconnectInput >& input ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

