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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2009_10_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2009_10_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/StructureContext.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
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
                class Structuremanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Structuremanagement
{
public:

    struct CopyEBOPStructureResponse;
    struct GetStructureContextLinesResponse;
    struct PasteDuplicateStructureResponse;

    /**
     * Map of a line to it's new pasted child lines
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > LineToLinesMap;

    /**
     * map of StructureContexts to its associated BomLines
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > > StructureContextToLinesMap2;

    /**
     * response structure for the service method copyEBOPStructure.
     */
    struct CopyEBOPStructureResponse
    {
        /**
         * any newly created incremental change revisions
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > createdICRevs;
        /**
         * any newly created future Incremental Change Revisions.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > createdFutureICRevs;
        /**
         * the updated item(root) and any partial errors returned here.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The updatedObject which is the itemrevision of the passed in item.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  updatedObject;
    };

    /**
     * Get toplines from the BomWindow setup by StructureContext and any selected bomlines.
     */
    struct GetStructureContextLinesResponse
    {
        /**
         * Map of StructureContext to its toplines. For example, Product Structure and Process
         * Structure top lines.
         */
        StructureContextToLinesMap2 topLines;
        /**
         * Map of StructureContext to any selected child lines. Note: If the topline is selected
         * this map will be empty.
         */
        StructureContextToLinesMap2 selectedLines;
        /**
         * Structure to capture any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * response structure of operation that clones the src objects before pasting.
     */
    struct PasteDuplicateStructureResponse
    {
        /**
         * any newly created Incremental Change Revisions.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > createdICRevs;
        /**
         * any newly created future IC revs
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > createdFutureICRevs;
        /**
         * service data returns the populated targetLines along with any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * the map of targetline and the newly created lines under it.
         */
        LineToLinesMap newChildLines;
    };




    /**
     * Creates a clone of the supplied root of the configuringEBOPWindow under the rootObject
     * specified.
     *
     * @param newRoot
     *        The newly created rootobject under which the structure will be cloned.
     *
     * @param configuringEBOPWindow
     *        The window with source BOP(GBOP/PBOP) item as root.
     *
     * @param workingWindow
     *        optional window (the actual source window), from which the IncrementalChange Rev
     *        is picked up. In addition the window settings like show unconfigured etc. are also
     *        picked up.
     *
     * @param copyRulesKey
     *        The name of the preference which will be used for cloning rule to be used.
     *
     * @param copyFutureEffectivity
     *        if true, future ICRevs will be created appropriately, instead of all ICEs being cloned
     *        to the currently active ICRev. Note that if this is true - it is expected that there
     *        is an currently selected ICRev in the working window.
     *
     * @return
     *         returns the input rootobject whose structure will be updated along with any created
     *         IC revs.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Structuremanagement::CopyEBOPStructureResponse copyEBOPStructure ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  newRoot,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  configuringEBOPWindow,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  workingWindow,
        const std::string&  copyRulesKey,
        bool copyFutureEffectivity ) = 0;

    /**
     * Return the top lines and any selected lines if present.
     *
     * @param scList
     *        The list of StructureContexts for which toplines and selected lines are needed.
     *
     * @return
     *         Return a map of Structure Context to Top Line and a map of Structure Context to selected
     *         child lines.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Structuremanagement::GetStructureContextLinesResponse getStructureContextLines ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext>  >& scList ) = 0;

    /**
     * clone the selected lines to each of the targetline supplied. The 2 input vectors
     * are not related. Currently, this functionality is only for EBOP structures.
     *
     * @param srcLines
     *        input src lines which need to be cloned under the targetline(s). All of them must
     *        be from the same structure.
     *
     * @param targetLines
     *        the targetline(s) under which the clones of the object underlying the srclines will
     *        be created/pasted. These should be from the same structure.
     *
     * @param copyRulesKey
     *        name of the preference that will be used for cloning.
     *
     * @param copyFutureEffectivity
     *        flag to indicate whether future effectivities are to be created.
     *
     * @return
     *         The return structure has any newly created IC revs along with the populated targetlines.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Structuremanagement::PasteDuplicateStructureResponse pasteDuplicateStructure ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& srcLines,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& targetLines,
        const std::string&  copyRulesKey,
        bool copyFutureEffectivity ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

