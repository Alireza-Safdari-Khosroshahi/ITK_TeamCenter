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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2013_05_INCREMENTALCHANGE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2013_05_INCREMENTALCHANGE_HXX

#include <teamcenter/soa/client/model/IncrementalChangeElement.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2013_05
            {
                class Incrementalchange;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Incrementalchange
{
public:

    struct ObjectsICEInfo;

    /**
     * A structure to hold BOMLine or the MECfgLine component and their corresponding ICE.
     */
    struct ObjectsICEInfo
    {
        /**
         * Business object (e.g. BOMLine, MECfgLine) for which the list of ICE are mapped with.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The list of structural ICE elements for the given business object.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IncrementalChangeElement>  > ices;
    };




    /**
     * This operation deletes the list of Incremental Change Elements (ICE) on the given
     * BOMLine or the MECfgLine.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Incremental Change - An incremental change collects a number of structure changes
     * to a component such as add or remove of components or changes to attachments (data).
     * Incremental change is an alternative to revision-based effectivity configuration.
     *
     * @param listOfObjects
     *        A list of BOMLine or the MECfgLine component and their corresponding ICE.
     *
     * @return
     *         For successfully deleted ICEs, corresponding business object will be sent back in
     *         the ServiceData lists of updated object. If an invalid business object is detected,
     *         72035 is returned as a partial error with the corresponding business object. If an
     *         ICE does not affect the corresponding BOMLine, 46000 is returned as a partial error.
     *         Similarly, if an ICE does not affect the corresponding MECfgLine, 200165 is returned
     *         as a partial error.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeIncrementalChanges ( const std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Incrementalchange::ObjectsICEInfo >& listOfObjects ) = 0;


protected:
    virtual ~Incrementalchange() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

