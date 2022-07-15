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

#ifndef TEAMCENTER_SERVICES_BOM__2010_09_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_BOM__2010_09_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/bom/Bom_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Bom
        {
            namespace _2010_09
            {
                class Structuremanagement;

class TCSOABOMSTRONGMNGD_API Structuremanagement
{
public:

    struct ObjectCoverageInput;
    struct ObjectCoverageResponse;
    struct TraversedObjectsInput;
    struct TraversedObjectsResponse;

    /**
     * Structure contains input parameters for verifyObjectCoverageByRule operation
     */
    struct ObjectCoverageInput
    {
        /**
         * scoped lines in the target window
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contexts;
        /**
         * the list of lines,that will be checked against the supplied closure rule
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToCheck;
        /**
         * the closure rule selected by the user
         */
        std::string closureRule;
        /**
         * the traversal depth entered by the user
         */
        int depth;
        /**
         * context of another structure (can be window or any line in it)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  otherStructure;
    };

    /**
     * Structure contains output parameters for verifyObjectCoverageByRule operation
     */
    struct ObjectCoverageResponse
    {
        /**
         * return vector (corresponds to the input objects vector) - with true or false
         */
        std::vector< bool > covered;
        /**
         * contains any errors received during the execution
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * structure contains input parameters for getTraversedObjectsByRule operation
     */
    struct TraversedObjectsInput
    {
        /**
         * the scope lines selected by the user
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > scopeObjects;
        /**
         * the closure rule selected by the user
         */
        std::string closureRule;
        /**
         * the traversal depth entered by the user
         */
        int depth;
        /**
         * target context (can be window or any line in it)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  otherStructure;
    };

    /**
     * structure contains output parameters for getTraversedObjectsByRule operation
     */
    struct TraversedObjectsResponse
    {
        /**
         * return vector of the the auto-expanded/filtered lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > resultObjects;
        /**
         * return errors if verifacation was failed or illegal
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This SOA traverses the structure according to supplied filtering rule and returns
     * the full list of resulting lines.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BOM Expand - Set of core services that allow to efficiently solve a product structure
     * based on revision rules; effectivities etc.
     *
     * @param input
     *        TraversedObjectsInput structure
     *
     * @return
     *         return the filtered and expanded lines for a structure
     *
     */
    virtual Teamcenter::Services::Bom::_2010_09::Structuremanagement::TraversedObjectsResponse getTraversedObjectsByRule ( const Teamcenter::Services::Bom::_2010_09::Structuremanagement::TraversedObjectsInput&  input ) = 0;

    /**
     * This SOA verifies whether the received lines fit the supplied filtering rule.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BOM Expand - Set of core services that allow to efficiently solve a product structure
     * based on revision rules; effectivities etc.
     *
     * @param input
     *        ObjectCoverageInput structure
     *
     * @return
     *         for each received line returns whether it fits the supplied closure rule
     *
     */
    virtual Teamcenter::Services::Bom::_2010_09::Structuremanagement::ObjectCoverageResponse verifyObjectCoverageByRule ( const Teamcenter::Services::Bom::_2010_09::Structuremanagement::ObjectCoverageInput&  input ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/bom/Bom_undef.h>
#endif

