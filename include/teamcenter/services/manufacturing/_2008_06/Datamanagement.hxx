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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2008_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2008_06_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/MEActivity.hxx>
#include <teamcenter/soa/client/model/MENXObject.hxx>
#include <teamcenter/soa/client/model/PSBOMView.hxx>
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
            namespace _2008_06
            {
                class Datamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Datamanagement
{
public:

    struct ActivityToolInfo;
    struct CreateOrUpdateMEActivityFolderResponse;
    struct CreateOrUpdateMENXObjectResponse;
    struct MEActivityFolderInfo;
    struct MENXObjectInfo;
    struct NameValueStruct;

    /**
     * OccThreadChainsSet
     */
    typedef std::map< int, std::vector< std::string > > OccThreadChainsSet;

    /**
     * SuccessFullyProcessedMapMEAct
     */
    typedef std::map< int, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEActivity>  > SuccessFullyProcessedMapMEAct;

    /**
     * SuccessFullyProcessedMapMENXObj
     */
    typedef std::map< int, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MENXObject>  > SuccessFullyProcessedMapMENXObj;

    /**
     * TODO
     */
    struct ActivityToolInfo
    {
        /**
         * The context bom view
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMView>  processBV;
        /**
         * The context bom view
         */
        OccThreadChainsSet toolOccThreadChains;
    };

    /**
     * TODO
     */
    struct CreateOrUpdateMEActivityFolderResponse
    {
        /**
         * successfullyProcessedMEAct
         */
        SuccessFullyProcessedMapMEAct successfullyProcessedMEAct;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * TODO
     */
    struct CreateOrUpdateMENXObjectResponse
    {
        /**
         * successfullyProcessedMENXObj
         */
        SuccessFullyProcessedMapMENXObj successfullyProcessedMENXObj;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * TODO
     */
    struct MEActivityFolderInfo
    {
        /**
         * The MEActivity object tag in cases of update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEActivity>  activity;
        /**
         * Name of the activity folder that needs to created/updated.
         */
        std::string name;
        /**
         * Description of the acivity folder that needs to created or updated.
         */
        std::string description;
        /**
         * Type of the activity folder that needs to be created.
         */
        std::string type;
        /**
         * toolInfo
         */
        Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::ActivityToolInfo toolInfo;
        /**
         * Objects that need to be inserted into the activity folder as contents.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > contents;
        /**
         * Parent activity folder into which this folder needs to inserted as a content.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEActivity>  > parentActivities;
        /**
         * MEActivity folder that need to added as predecessors.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MEActivity>  > predecessors;
        /**
         * A vector of NameValueStruct  that has the name value pairs. Through this act_location,
         * time and start_time can be set for the folder.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::NameValueStruct > attributes;
        /**
         * Whether the given information completely represents the folder to be updated. This
         * is flag is applicable only for completely replacing tools, predecessors and contents.
         */
        bool complete;
    };

    /**
     * TODO
     */
    struct MENXObjectInfo
    {
        /**
         * The MENXObject object tag in cases of update
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MENXObject>  menxObject;
        /**
         * Name of the MENXObject that needs to created or updated.
         */
        std::string name;
        /**
         * Description of the MENXObject that needs to created or updated.
         */
        std::string description;
        /**
         * Type of the MENXObject that needs to created.
         */
        std::string type;
        /**
         * Sub-Type of the MENXObject that needs to created.
         */
        std::string subType;
        /**
         * A vector of NameValueStruct  that has the name value pairs. Through this the attributes
         * of the MENXObject like double_attrs, double_keys, int_attrs, int_keys, string_attrs,
         * string_keys can be set.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::NameValueStruct > attributes;
    };

    /**
     * TODO
     */
    struct NameValueStruct
    {
        /**
         * Title of the attribute that needs to be set
         */
        std::string name;
        /**
         * Values of the attribute to be set
         */
        std::vector< std::string > values;
    };




    /**
     * Allows the user to create and/or update a MEActivityFolder.  If the given MEActivity
     * object exists but the input attribute values that differ from those already set,
     * an attempt is made to update the values if possible. If multiple level of sub activities
     * are to be created those activities can be passed in as the objects if they already
     * exist in database. The created folder and updated folders are returned to the client
     * through the createdObjects and updatedObject list of the service data respectively.
     *
     * @param activityInfos
     *        Input is a vector of MEActivityFolderInfo structs. A Boolean value part of the structure
     *        signifying if the input data represents the complete representation of the folder
     *        tools, predecessors, and contents or if it represents objects to be appended to the
     *        existing folder tools, predecessors, and contents (folder context information) if
     *        complete is true, then the expectation is that the entire folder context information
     *        is supplied and any folder context not supplied that currently exist in Teamcenter
     *        will be removed from the folder context, if complete is false, the input context
     *        elements will be appended to the input folder.
     *
     * @return
     *         contains map between the index of the input structure and the created or updated
     *         object, All Object ids that were successfully created or updated are added to ServiceData.
     *         Objects/object ids that failed the find are returned in a list of failures in the
     *         ServiceData with its index.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::CreateOrUpdateMEActivityFolderResponse createOrUpdateMEActivityFolders ( const std::vector< Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::MEActivityFolderInfo >& activityInfos ) = 0;

    /**
     * Allows the user to create and/or update a MENXObject. If the given MENXObject object
     * exists but the input attribute values that differ from those already set, an attempt
     * is made to update the values if possible.
     *
     * @param meObjectInfos
     *        Input is a vector of MENXObjectInfo structs.
     *
     * @param container
     *        The folder into which the created objects are to be placed. This can be a NULLTAG
     *        in which case the created objects will not be inserted into any folder.
     *
     * @return
     *         contains map between the index of the input structure and the created or updated
     *         object, All Object ids that were successfully created or updated are added to ServiceData.
     *         Objects/object ids that failed the find are returned in a list of failures in the
     *         ServiceData with its index.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::CreateOrUpdateMENXObjectResponse createOrUpdateMENXObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2008_06::Datamanagement::MENXObjectInfo >& meObjectInfos,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  container ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

