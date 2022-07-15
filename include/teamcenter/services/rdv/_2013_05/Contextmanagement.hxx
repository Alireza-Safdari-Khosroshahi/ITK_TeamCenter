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

#ifndef TEAMCENTER_SERVICES_RDV__2013_05_CONTEXTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_RDV__2013_05_CONTEXTMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/rdv/Rdv_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Rdv
        {
            namespace _2013_05
            {
                class Contextmanagement;

class TCSOARDVSTRONGMNGD_API Contextmanagement
{
public:

    struct ContextObjectResponse;

    /**
     * This map contains a list of related objects for each input object.
     * <br>
     * Key: The input object is the key.
     * <br>
     * Values: A list of objects that related to the input object are the values.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > RelatedObjectsInfo;

    /**
     * This structure contains the list of all the objects related to the current object
     * within context and the serviceData object.
     */
    struct ContextObjectResponse
    {
        /**
         * A map of input business object to a list of related <b>Item</b>, <b>Processes</b>
         * <b>and</b> <b>ChangeRequestRevision</b>  (business object/ vector). The DesignContext
         * application then adds these objects to the respective lists i.e. Workparts list,
         * ChangeRequestRevision list or the Processes list based on the type of object. If
         * no related object is found empty map is returned.
         */
        RelatedObjectsInfo objectMap;
        /**
         * The ServiceData objects containing error codes and error messages in case of failure.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation finds all the business objects that are within the current active
     * context of the list of objects sent as input. The objects within context are objects
     * of the types specified below that are related to the input object either through
     * reference or relation.
     * <br>
     * <ul>
     * <li type="disc"><b>Items</b>
     * </li>
     * <li type="disc"><b>Processes</b>
     * </li>
     * <li type="disc"><b>ChangeRequestRevision</b>
     * </li>
     * <li type="disc"><b>StructureContext</b>
     * </li>
     * <li type="disc"><b>AppearanceGroup</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <br>
     * The RDV module maintains a state that defines the currently active context. A combination
     * of one or more of the following objects defines the current active context.
     * <br>
     * <ul>
     * <li type="disc"><b>WorkpartItem</b>
     * </li>
     * <li type="disc"><b>Process</b>
     * </li>
     * <li type="disc"><b>ChangeRequestRevision</b>
     * </li>
     * <li type="disc"><b>ConfigurationContext</b>
     * </li>
     * <li type="disc"><b>StructureContext</b>
     * </li>
     * <li type="disc"><b>AppearanceGroup</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <br>
     * Every time this operation is invoked, the objects in the current context are refreshed.
     * <br>
     * This operation is mainly used for adding work parts, EngChange revisions and processes
     * to the Design Context application.
     * <br>
     * The following criteria is used to determine the objects related to the inputs:
     * <br>
     * <br>
     * 1) Item objects that are attached with the ChangeRequestRevision, Process objects
     * through the relation type mentioned in the preferences listed below.
     * <br>
     * <br>
     * <code>PortalDesignContextProcess.WorkPartOrChangeAttachmentTypes</code>
     * <br>
     * <code>PortalDesignContextECObject.WorkPartRelationships</code>
     * <br>
     * <br>
     * <br>
     * 2) Item objects that are associated with the EPM job where the input object is also
     * a part of the EPM job.
     * <br>
     * <br>
     * 3) Item objects that are part of the same ConfigurationContext object, StructureContext
     * object or an AppearanceGroup object as that of the input objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: If user enters an item ID in the WorkParts text field in DesignContext
     * application. The Design Context application uses this operation to display the item
     * revision in the WorkParts list, and any changes or processes that reference the item
     * revision in the EngChange Revision and Processes lists.
     * <br>
     * <br>
     * Use Case 2: If user enters a change ID in the EngChange Revision text field DesignContext
     * application. The DesignContext application uses this operation to add the change
     * object to the EngChange Revision list, and any item revisions or processes referenced
     * by the change object are displayed in the WorkParts and Processes lists. If the change
     * references revisions of Product Items, Teamcenter automatically adds them to the
     * Selected Product Context list.
     * <br>
     * <br>
     * Use Case 3: If user enters a process name in Processes test field DesignContext application.
     * The DesignContext application uses this operation to add the process object to the
     * Processes list, and any objects targeted by the process are displayed in the WorkParts
     * and EngChange lists.
     * <br>
     * <br>
     * The items in the WorkPart lists can then be selected by the user for carrying out
     * the design validation analysis.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Context Management - Application to perform Digital Product Validations. This also
     * lists other ITK Main programs maintained by RDV Team.
     *
     * @param objectList
     *        List of objects for which the related objects in the current active context are to
     *        be found.
     *        <br>
     *        The list may contain the following objects based on the input:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>Items</b>
     *        </li>
     *        <li type="disc"><b>Processes</b>
     *        </li>
     *        <li type="disc"><b>ChangeRequestRevision</b>
     *        </li>
     *        <li type="disc"><b>StructureContext</b>
     *        </li>
     *        <li type="disc"><b>AppearanceGroup</b>
     *        </li>
     *        </ul>
     *
     * @return
     *         The map of <b>Item</b>, <b>Process</b> <b>and ChangeRequestRevision</b> objects that
     *         are related to input objects in current active context.
     *         <br>
     *         <br>
     *         The following partial errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">202003 If no related object is found for the current input object.
     *         </li>
     *         <li type="disc">202004 If the number of objects added to result list exceeds the
     *         value set in <b>PortalDesignContextMaxMatchingObjects</b> preference.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Rdv::_2013_05::Contextmanagement::ContextObjectResponse getRelatedObjectsInContext ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objectList ) = 0;


protected:
    virtual ~Contextmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/rdv/Rdv_undef.h>
#endif

