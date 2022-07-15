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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


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
            namespace _2013_05
            {
                class Structuremanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Structuremanagement
{
public:

    struct FindAffectedCCsOutput;
    struct FindAffectedCCsResponse;
    struct FindAffectedOutputObject;

    /**
     * The output object for FindAffectedCCs SOA.
     * <br>
     * This object contains a list of FindAffectedOutputObject. This vector represents all
     * of the queried objects and all of the affected CCs.
     */
    struct FindAffectedCCsOutput
    {
        /**
         * Each vector node inside "affectedObjects" includes  a quaried item and a single Collaboration
         * Context. For example, if CC1 (Collaboration Context) and CC2 (Collaboration Context)
         * contain inside their process structures both item1 and item 2 and the two items are
         * quaried for affected Collaboration Contexts, the output will be as follows:
         * <br>
         * 1. Item1, CC1
         * <br>
         * 2. Item1, CC2
         * <br>
         * 3. Item2, CC1
         * <br>
         * 4. Item2, CC2
         * <br>
         * <br>
         * Each of the items is represented by two vector nodes, one vector node for each relation
         * to a CC.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Structuremanagement::FindAffectedOutputObject > affectedObjects;
    };

    /**
     * A list of output objects and a service data.
     */
    struct FindAffectedCCsResponse
    {
        /**
         * The output data includes the affected CCs and the items which is related to each
         * CC.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Structuremanagement::FindAffectedCCsOutput > output;
        /**
         * The service data output.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The output object which contains the queried object and one of it's related CCs
     */
    struct FindAffectedOutputObject
    {
        /**
         * The item queried for affected CCs.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  queryObject;
        /**
         * One of the affected CCs of the query item.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  affectedCC;
    };




    /**
     * This operation finds all of the Collaboration Contexts which contain a process structure,
     * which contains the input objects (e.g. Item, MEWorkArea, METool, MEProcess or MEOperation).
     * The input objects must be of type Item or ItemRevision (BOMLine objects are not valid
     * input objects).
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * whereReferenced
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param objects
     *        The items to find their Collaboration Contexts (as a reference).
     *
     * @return
     *         Returns:
     *         <br>
     *         A response structure which holds the list of output objects and a service data. The
     *         following partial errors are returned in case invalid parameters are passed to the
     *         service:
     *         <br>
     *         300069: If an object of a wrong type is passed to the operation.
     *         <br>
     *         300070: If Where Referenced operation fails for the input object.
     *
     *
     * @exception ServiceException
     *           Throws:
     *           <br>
     *           NotSupportedObjectType: If the input object isn't one of the supported types (it's
     *           not a subtype of an item or an item_revision).
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Structuremanagement::FindAffectedCCsResponse findAffectedCCs ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  >& objects ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

