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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2009_06_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2009_06_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/CfgActivityLine.hxx>
#include <teamcenter/soa/client/model/CfgAttachmentLine.hxx>
#include <teamcenter/soa/client/model/StructureContext.hxx>
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
            namespace _2009_06
            {
                class Structuremanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Structuremanagement
{
public:

    struct CreateOrUpdateAttachmentsData;
    struct GetAttachmentLineChildrenResponse;
    struct GetBOMLineActivitiesResponse;
    struct GetBOMLineAttachmentsResponse;
    struct GetStructureContextActivityLinesResponse;
    struct GetStructureContextTopLinesResponse;

    /**
     * map of attachmentline to it's child attachmentlines
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgAttachmentLine> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgAttachmentLine>  > > AttachmentLineToChildLinesMap;

    /**
     * map of bomline to it's mfg activity lines
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgActivityLine>  > > BOMLineToActivitiesMap;

    /**
     * map of bomline to it's attachment lines
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgAttachmentLine>  > > BOMLineToAttachmentLinesMap;

    /**
     * the map if relation string to the secondary workspace objects that defines the attachment(s)
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > > ContextToSecondaryObjectsMap;

    /**
     * map of StructureContext to Activities,
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgActivityLine>  > > StructureContextActivityLinesMap;

    /**
     * map of StructureContext Object to it's toplines
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureContext> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > > StructureContextToLinesMap;

    /**
     * Structure to specify input data for createOrUpdateAttachments
     */
    struct CreateOrUpdateAttachmentsData
    {
        /**
         * bomline - the top line of the attachment window. Optional if attLine is going to
         * be specified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Parent attachment line-under which the new one will be created or updated. Overrides
         * bomLine member if specified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CfgAttachmentLine>  attLine;
        /**
         * relation string to the workspaceobject secondaries map
         */
        ContextToSecondaryObjectsMap objects;
    };

    /**
     * response of getAttachmentLineChildren method - a map of input line to it's children
     */
    struct GetAttachmentLineChildrenResponse
    {
        /**
         * map of parent attachmentline to child lines.
         */
        AttachmentLineToChildLinesMap lines;
        /**
         * any partial errors to be returned.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response of getBOMLineActivities method. lines represent the activities for supplied
     * bomline. servicesData to capture partialErrors.
     */
    struct GetBOMLineActivitiesResponse
    {
        /**
         * vector of bomline to activities map
         */
        BOMLineToActivitiesMap lines;
        /**
         * serviceData object to capture partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response of getBOMLineAttachments method. lines represent the attachmentlines for
     * supplied bomline. servicesData to capture partialErrors.
     */
    struct GetBOMLineAttachmentsResponse
    {
        /**
         * bomline to attachmentlines map
         */
        BOMLineToAttachmentLinesMap lines;
        /**
         * serviceData to capture partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * return structure of getStructureContextActivityLinesResponse. lines has the map of
     * sc to activitylines, and serviceData has partial errors.
     */
    struct GetStructureContextActivityLinesResponse
    {
        /**
         * map of sc to activity lines
         */
        StructureContextActivityLinesMap lines;
        /**
         * for reporting partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * response of getStructureContextTopLines methods. lines member has the map of StructureContext
     * to it's toplines, and serviceData member has any partial errors.
     */
    struct GetStructureContextTopLinesResponse
    {
        /**
         * map of SC to it's lines
         */
        StructureContextToLinesMap lines;
        /**
         * serviceData to hold partial errors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

