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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_STRUCTUREMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_STRUCTUREMANAGEMENTSERVICE_HXX

#include <teamcenter/services/manufacturing/_2009_06/Structuremanagement.hxx>
#include <teamcenter/services/manufacturing/_2009_10/Structuremanagement.hxx>
#include <teamcenter/services/manufacturing/_2011_06/Structuremanagement.hxx>
#include <teamcenter/services/manufacturing/_2013_05/Structuremanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class StructuremanagementService;

/**
 * Services to deal with attachments and structures
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API StructuremanagementService
    : public Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement,
             public Teamcenter::Services::Manufacturing::_2009_10::Structuremanagement,
             public Teamcenter::Services::Manufacturing::_2011_06::Structuremanagement,
             public Teamcenter::Services::Manufacturing::_2013_05::Structuremanagement
{
public:
    static StructuremanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * close any attachment window that got created for the bomline during the soa session.
     * This will only close the attachment windows that are created to support the attachment
     * line soa calls.
     *
     * @param lines
     *        input bomlines for which the attachmentwindow has to be closed.
     *
     * @return
     *         any partial errors are returned in the response
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData closeAttachmentWindow ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& lines ) = 0;

    /**
     * create or update attachments. The following properties are loaded automatically for
     * the line:me_cl_object_name,me_cl_object_type,me_cl_object_desc and these for the
     * workspaceobject:object_name, object_type, object_desc irrespective of policy files.
     *
     * @param attachments
     *        input either bomline or attachmentline (parent) and the relations and workspace objects
     *        to be processed as attachments.
     *
     * @return
     *         failures returned as partial failures in serviceData
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateAttachments ( const std::vector< Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement::CreateOrUpdateAttachmentsData >& attachments ) = 0;

    /**
     * remove the specified attachment lines. Only if these lines have a parent is this
     * action performed.
     *
     * @param lines
     *        remove the specified lines from the parent attachment window.
     *
     * @return
     *         partial errors retuned in the serviceData
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteAttachments ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgAttachmentLine>  >& lines ) = 0;

    /**
     * given a vector of input attachmentlines - for each - get the immediate level of child
     * attachment lines. For each attachment line the following properties are available
     * on client side automatically:me_cl_object_name, me_cl_object_type, me_cl_object_desc
     *
     * @param attlines
     *        input parent attachment lines
     *
     * @return
     *         returns the child attachment lines for a given line.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement::GetAttachmentLineChildrenResponse getAttachmentLineChildren ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgAttachmentLine>  >& attlines ) = 0;

    /**
     * given a bomline get it's activities (these activities are really the children of
     * the root activity associated with the bomline). This assumes that the bomline is
     * a bopline. The following properties are available on client side for each line irrespective
     * of policy: al_activity_object_name, al_activity_time. If the actual attachments of
     * these activity lines are desired - use the getProperties method of DataManagementService
     * with al_object as the property name.
     *
     * @param bomLines
     *        input vector of bomlines for which activities are needed.
     *
     * @return
     *         returns a vector of a map of bomline to it's activities.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement::GetBOMLineActivitiesResponse getBOMLineActivities ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& bomLines ) = 0;

    /**
     * given a bomline get it's attachments. The follow properties are available on client
     * side irrespective of policy: me_cl_object_name, me_cl_object_type, me_cl_object_desc
     *
     * @param bomlines
     *        list of input BOMLines
     *
     * @param filter
     *        optional relation filter to be used for attachments. The relation names specified
     *        here are used as a filter on the attachmentwindow
     *
     * @return
     *         returns a  map of bomline to attachments
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement::GetBOMLineAttachmentsResponse getBOMLineAttachments ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& bomlines,
        const std::vector< std::string >& filter ) = 0;

    /**
     * Given a vector of StructureContext objects, for each - get the activitylines that
     * are attached to the SC by the relation - TC_SC_activities. Currently, this is only
     * created during a population of WorkInstruction page by selecting an activity. The
     * following properties are available to the client irrespective of policy: al_activity_object_name,
     * al_activity_time
     *
     * @param scs
     *        list of input structurecontext objects
     *
     * @return
     *         lines has the map of sc to activitylines, and serviceData has partial errors.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement::GetStructureContextActivityLinesResponse getStructureContextActivityLines ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext>  >& scs ) = 0;

    /**
     * method to get the toplines of specified StructureContext. Client is responsible for
     * closing any windows that are returned during this call. The following properties
     * are available irrespective of policy:bl_line_name
     *
     * @param scs
     *        input list of SC's
     *
     * @return
     *         returns the response structure containing the map of StructureContext to it's lines
     *         and the response.
     *
     * @deprecated
     *         As of Teamcenter 8.1, use the getStructureContextLines operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.1, use the getStructureContextLines operation."))
#endif
    virtual Teamcenter::Services::Manufacturing::_2009_06::Structuremanagement::GetStructureContextTopLinesResponse getStructureContextTopLines ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext>  >& scs ) = 0;

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

    /**
     * return referenced contexts of input context.
     *
     * @param contexts
     *        vector of input contexts
     *
     * @return
     *         return ReferenceContextResponse structure
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2011_06::Structuremanagement::ReferencedContextsResponse getReferenceContexts ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& contexts ) = 0;

    /**
     * set Reference context according to user choice.
     *
     * @param input
     *        includes ReferencedContexts structure
     *
     * @return
     *         service data will return errors only and no data.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setReferenceContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2011_06::Structuremanagement::ReferencedContexts >& input ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuremanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

