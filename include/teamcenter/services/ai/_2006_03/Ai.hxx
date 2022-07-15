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

#ifndef TEAMCENTER_SERVICES_AI__2006_03_AI_HXX
#define TEAMCENTER_SERVICES_AI__2006_03_AI_HXX

#include <teamcenter/soa/client/model/AppInterface.hxx>
#include <teamcenter/soa/client/model/RequestObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/ai/Ai_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Ai
        {
            namespace _2006_03
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct ApplicationRef;
    struct CommitFileData;
    struct CommitFilesResponse;
    struct CommitStructureFileResponse;
    struct Configuration;
    struct FileTicket;
    struct CreatePublishRequestResponse;
    struct GenerateFullSyncRequestResponse;
    struct GenerateStructureResponse;
    struct GetFileReadTicketsResponse;
    struct GetFileWriteTicketsResponse;
    struct GetNextApprovedRequestResponse;
    struct GetPropertiesOfObjectsResponse;
    struct GetStructureReadTicketResponse;
    struct GetStructureWriteTicketResponse;
    struct ObjectsExistResponse;
    struct ProjectCreationData;
    struct ProjectFilter;
    struct ProjectInfo;
    struct StatusInfo;
    struct RequestDetail;
    struct StateFilter;

    /**
     * Type of file being uploaded to Teamcenter.
     */
    enum FileType{ FileType_Binary,
                 FileType_Text
                 };

    /**
     * Filter on whether the project_id is set on the ApplicationInterface object or not
     */
    enum ProjectType{ ProjectType_New,
                 ProjectType_Existing,
                 ProjectType_Any
                 };

    /**
     * RequestScope
     */
    enum RequestScope{ RequestScope_Whole,
                 RequestScope_Partial,
                 RequestScope_Any
                 };

    /**
     * State of the Request Object
     */
    enum RequestState{ RequestState_New,
                 RequestState_Processing,
                 RequestState_Pending,
                 RequestState_Communicating,
                 RequestState_Completed,
                 RequestState_Rejected,
                 RequestState_Any
                 };

    /**
     * Status of the Request Object. TC or application can set these depending on which
     * party is doing the authoring.
     */
    enum RequestStatus{ RequestStatus_Normal,
                 RequestStatus_Warning,
                 RequestStatus_Severe,
                 RequestStatus_Abort,
                 RequestStatus_Any
                 };

    /**
     * Type of the Request Object
     */
    enum RequestType{ RequestType_Publish,
                 RequestTypeSync,
                 RequestType_Any,
                 RequestType_Notify
                 };

    /**
     * Request update type
     */
    enum UpdateType{ UpdateType_Full,
                 UpdateType_Delta,
                 UpdateType_Any
                 };

    /**
     * StrVStrMap
     */
    typedef std::map< std::string, std::vector< std::string > > StrVStrMap;

    /**
     * Structure representing application neutral identifier
     */
    struct ApplicationRef
    {
        /**
         * The application where these fields can be resolved. For example - it is Teamcenter
         * for TC.
         */
        std::string application;
        /**
         * the actual id. In Teamcenter this maps to b uid /b
         */
        std::string label;
        /**
         * can be blank. If obtained from Teamcenter pass it as is.
         */
        std::string version;
    };

    /**
     * commitFileData structure to be used when commiting files to teamcenter.
     */
    struct CommitFileData
    {
        /**
         * the write ticket returned from Teamcenter from a prior call to GetWriteFileTickets.
         */
        std::string ticket;
        /**
         * If used with AI object, this represents the id of the RequestObject.
         */
        Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef id;
        /**
         * filename as specified, when getting the write ticket.
         */
        std::string filename;
    };

    /**
     * commit files response.
     */
    struct CommitFilesResponse
    {
        /**
         * failedCommits
         */
        std::vector< Teamcenter::Services::Ai::_2006_03::Ai::CommitFileData > failedCommits;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * returns the fileIds if the saved plmxml file.
     */
    struct CommitStructureFileResponse
    {
        /**
         * fileId
         */
        std::string fileId;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Configuration structure.
     */
    struct Configuration
    {
        /**
         * Tag of ConfigurationContext or StructureContext or RevRule or VariantRule or storedOptionSetId,or
         * TransferMode.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  id;
        /**
         * if id is NULLTAG, then used to specify the revisionrule by name.
         */
        std::string rulename;
        /**
         * if true - the Teamcenter preferences are used to pick up the rev rule. Overrides
         * the above 2 members if true.
         */
        bool useDefaultRevisionRule;
    };

    /**
     * FileTicket details
     */
    struct FileTicket
    {
        /**
         * the FMS ticket
         */
        std::string ticket;
        /**
         * name of the file that is displayed in TC UI
         */
        std::string originalFileName;
    };

    /**
     * response of the createPublishRequest method.
     */
    struct CreatePublishRequestResponse
    {
        /**
         * ticket
         */
        Teamcenter::Services::Ai::_2006_03::Ai::FileTicket ticket;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Used to generate the plmxml for a sync request.
     */
    struct GenerateFullSyncRequestResponse
    {
        /**
         * ticket
         */
        Teamcenter::Services::Ai::_2006_03::Ai::FileTicket ticket;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * generatestructure returns the transient file ticket on success.
     */
    struct GenerateStructureResponse
    {
        /**
         * ticket
         */
        std::string ticket;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * tickets to download files referenced by plmxml.
     */
    struct GetFileReadTicketsResponse
    {
        /**
         * tickets
         */
        std::vector< Teamcenter::Services::Ai::_2006_03::Ai::FileTicket > tickets;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Tickets to upload files referenced by plmxml.
     */
    struct GetFileWriteTicketsResponse
    {
        /**
         * tickets
         */
        std::vector< std::string > tickets;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * get next approved request. Currently not used.
     */
    struct GetNextApprovedRequestResponse
    {
        /**
         * ticket
         */
        Teamcenter::Services::Ai::_2006_03::Ai::FileTicket ticket;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * GetPropertiesOfObjectsResponse struct
     */
    struct GetPropertiesOfObjectsResponse
    {
        /**
         * nameValues
         */
        StrVStrMap nameValues;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * response of getStructureReadTicket - returns the plmxml file ticket.
     */
    struct GetStructureReadTicketResponse
    {
        /**
         * ticket
         */
        Teamcenter::Services::Ai::_2006_03::Ai::FileTicket ticket;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * response of getStructureWriteTicket - returns the ticket to be used for uploading
     * a plmxml file.
     */
    struct GetStructureWriteTicketResponse
    {
        /**
         * ticket
         */
        std::string ticket;
        /**
         * data
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * response of ObjectsExist method
     */
    struct ObjectsExistResponse
    {
        /**
         * does the object exist in Teamcenter or not.
         */
        std::vector< bool > bExist;
        /**
         * All the ApplicationRef registered for the Teamcenter object
         */
        std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef > ids;
        /**
         * used to report any partial failures.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Project(AI) creation method data
     */
    struct ProjectCreationData
    {
        /**
         * Type of the Application Interface object to be created.
         */
        std::string type;
        /**
         * Name of the AI object to be created.
         */
        std::string name;
        /**
         * Description of the AI object to be created.
         */
        std::string description;
        /**
         * The application id to be set on the AI object.
         */
        std::string targetApplicationId;
    };

    /**
     * Structure to specify the filter when using GetProjects method.
     */
    struct ProjectFilter
    {
        /**
         * ProjectType enum. Set it to ProjectType_Any if not needed.
         */
        ProjectType projectType;
        /**
         * name of the AppliationInterface Object
         */
        std::string name;
        /**
         * description of the ApplicationInterface Object
         */
        std::string description;
        /**
         * type of the ApplicationInterface Object. The type must be a valid type of AI Object.
         */
        std::string type;
        /**
         * userId to filter on
         */
        std::string userId;
        /**
         * filter on AI objects using groupName
         */
        std::string groupName;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime createdBefore;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime createdAfter;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime modifiedBefore;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime modifiedAfter;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime releasedBefore;
        /**
         * filtering by Date
         */
        Teamcenter::Soa::Common::DateTime releasedAfter;
        /**
         * maps to the Export TransferMode's (of the AI) context string
         */
        std::string applicationId;
        /**
         * description of the ApplicationInterface Object
         */
        std::string siteId;
        /**
         * used only if projectType==ProjectType_Existing
         */
        std::string targetAppProjectId;
    };

    /**
     * Structure to specify ApplicationInterface information.
     */
    struct ProjectInfo
    {
        /**
         * The projectId string recorded on the ApplicationInterface Object
         */
        std::string targetAppProjectId;
        /**
         * name of the AppliationInterface Object
         */
        std::string name;
        /**
         * description of the ApplicationInterface Object
         */
        std::string description;
    };

    /**
     * Structure representing the status fields of the RequestObject
     */
    struct StatusInfo
    {
        /**
         * RequestStatus enum RequestStatus_Normal etc.
         */
        RequestStatus status;
        /**
         * status message of the Request.
         */
        std::string description;
    };

    /**
     * Structure representing the details of the RequestObject
     */
    struct RequestDetail
    {
        /**
         * name of the RequestObject
         */
        std::string name;
        /**
         * description of the RequestObject
         */
        std::string description;
        /**
         * description on the state of the RequestObject.
         */
        std::string stateDesc;
        /**
         * the status fields of the RequestObject
         */
        Teamcenter::Services::Ai::_2006_03::Ai::StatusInfo status;
        /**
         * RequestScope_Whole - no ExternalReference elements will be found in plmxml. If Partial
         * then there will be ExternalReference elements in plmxml.
         */
        RequestScope scope;
        /**
         * used to specify an incremental update.
         */
        UpdateType update;
    };

    /**
     * Structure to filter RequestObject
     */
    struct StateFilter
    {
        /**
         * vector of RequestState enums
         */
        std::vector< RequestState > states;
        /**
         * vector of RequestType enums
         */
        std::vector< RequestType > types;
    };




    /**
     * Create ApplicationInterface Objects in Teamcenter based on the input values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projectDatas
     *        std::vector of ProjectCreationData, each of which has the name,type, description
     *        and optional targetApplicationId.
     *
     * @return
     *         new objects added to the CreatedObjs member of ServiceData. Partial failures will
     *         be reported in the service data too. member.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData createProjects ( const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ProjectCreationData >& projectDatas ) = 0;

    /**
     * Generate a plmxml for the given set of ids.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param idsToProcess
     *        ids for which plmxml will be generated. If multiple ids are specified - the traverse
     *        rootRef in plmxml will have these multiple roots.
     *
     * @param transferModeName
     *        The name of the transferMode in TC.
     *
     * @param config
     *        Configuration structure. If the id(Tag) member is specified, it must be the     the
     *        tag of ConfigurationContext or StructureContext or RevRule or VariantRule or storedOptionSetId,
     *        or TransferMode.     If this is a NULLTAG - then rulename will be used to find
     *        RevisionRule. If both are empty, and     useDefaultRevisionRule is true - the Teamcenter
     *        preferences are used to pick up the rev rule.     If all 3 are not used - then no
     *        revrule will be used in the generation of plmxml.
     *
     * @param serverMode
     *        - 2 or 4 - 2tier or 4-tier. This is used for transient file ticket generation on
     *        server.
     *
     * @return
     *         file path to the FCC Cache location. Any errors during plmxml processing are returned
     *         in resp struct. severe error would result in an exception being thrown.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GenerateStructureResponse generateStructure ( const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef >& idsToProcess,
        const std::string&  transferModeName,
        const Teamcenter::Services::Ai::_2006_03::Ai::Configuration&  config,
        int serverMode ) = 0;

    /**
     * Used to download the tickets for the files referenced by the plmxml file previously
     * exported from Teamcenter. These tickets are then to be used with FCC client Proxy
     * to actually download the files.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param fileIds
     *        Ids for which the files are obtained.
     *
     * @return
     *         list of successful tickets, successul originalFileNames (which will be the same size)
     *         and the list of failedIds. Reasons of failure - will be inServiceData struct.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GetFileReadTicketsResponse getFileReadTickets ( const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef >& fileIds ) = 0;

    /**
     * Used to download the tickets for the files referenced by the plmxml file created
     * by a client application. These tickets are then to be used with FCC client Proxy
     * to actually upload(commit) the files.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param originalFileNames
     *        The original fileName array. If there it a path - it is stripped out.
     *
     * @param fileTypes
     *        The fileType for each corresponding element in originalFileNames array. If empty
     *        - then default to Binary for all files.
     *
     * @return
     *         list of successful tickets, failed originalFileNames. Reasons of failure - will be
     *         in ServiceData struct.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GetFileWriteTicketsResponse getFileWriteTickets ( const std::vector< std::string >& originalFileNames,
        const std::vector< FileType >& fileTypes ) = 0;

    /**
     * Get a list of projects that are available on this database based on the filter specified.
     * Suggest atleast filtering based on type of AppInterface
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param filter
     *        qualifier to customize the projects returned.
     *
     * @return
     *         serviceData returned will have the projects added as plainobjects. In case of partial
     *         failures - they will be reported in ServiceData - errorStack
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData getProjects ( const Teamcenter::Services::Ai::_2006_03::Ai::ProjectFilter*  filter ) = 0;

    /**
     * Get Properties of Teamcenter obects based on a propertyset created using the plmxml
     * admin application.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param appRefs
     *        The ApplicationRefs of objects on which properties are desired.
     *
     * @param propertySetNames
     *        The name of the property set for each of the corresponding objects in appRefs array.
     *        The scope of any propertySetName must be TcEng. Refer to the plmxml admin application
     *        documentation for further details.
     *
     * @return
     *         partial failures are returned in data. The property name and it's values are retuned
     *         in the nameValues member.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GetPropertiesOfObjectsResponse getPropertiesOfObjects ( const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef >& appRefs,
        const std::vector< std::string >& propertySetNames ) = 0;

    /**
     * Used to download the ticket for the plmxml file that will be uploaded by the client.
     * This ticket is then to be used with FCC client Proxy to actually upload the file.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param originalFileName
     *        originalFileName to be used in Teamcenter.
     *
     * @return
     *         fileticket is returned in the Response struct.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GetStructureWriteTicketResponse getStructureWriteTicket ( const std::string&  originalFileName ) = 0;

    /**
     * Given 1 or more ApplicationRef objects - find the corresponding TeamCenter Object(s).
     * Typically, the ApplicationRef is obtained from a plmxml file. The ApplicationRef
     * for Teamcenter objects is (from a client point of view) - application='TcEng', label=teamcenter_uid,
     * version=teamcenter_uid.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param objIds
     *        ApplicationRef's of client domain context id.
     *
     * @return
     *         structure. If (bExist) is true then the corresponding (id) will have the Teamcenter
     *         ApplicationRef, else (id) fields will be empty. The failed ids' will be in data member.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::ObjectsExistResponse objectsExist ( const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef >& objIds ) = 0;

    /**
     * Import a plmxml for a previously uploaded plmxml via getStructureWriteTicket, fcc
     * method to upload the file and commitStructureFile (with no associated RequestObject
     * - non AI plmxml import).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param transferModeName
     *        The name of the transferMode in TC. Must be of ImportType.
     *
     * @param plmxmlFileId
     *        The id of the file from a prior call to commitStructureFile.
     *
     * @param config
     *        Configuration structure. If the id(Tag) member is specified, it must be the the tag
     *        of ConfigurationContext or StructureContext or RevRule or VariantRule or storedOptionSetId,
     *        or TransferMode. If this is a NULLTAG - then rulename will be used to find RevisionRule.
     *        If both are empty, and useDefaultRevisionRule is true - the Teamcenter preferences
     *        are used to pick up the rev rule. If all 3 are not used - then no revrule will be
     *        used in the generation of plmxml.
     *
     * @return
     *         errors during plmxml processing are returned in the return struct.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData processStructure ( const std::string&  transferModeName,
        const std::string&  plmxmlFileId,
        const Teamcenter::Services::Ai::_2006_03::Ai::Configuration&  config ) = 0;

    /**
     * After a call to getFileWriteTickets - this method is to be used to create TeamCenter
     * file objects - referencing the files in the volume.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param reqObj
     *        The optional id of the Request Object in TeamCenter. Optional if AI
     *        is not being used. If RequestObject is not passed then specify NULL for this.
     *
     * @param data
     *        vector of CommitFileData elements - ticket, ApplicationRef and originalFileName combination.
     *        The ApplicationRef element for each of the file must be the same as those present
     *        in the plmxml file. filename - to be assigned to each of the TC file object. If path
     *        is supplied with - it is stripped out.
     *
     * @return
     *         list of successful tickets, failed originalFileNames. Reasons of failure - will be
     *         in ServiceData struct. ServiceData will have the list of Teamcenter File uids as
     *         plain objects, which can be retrieved by client if needed.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::CommitFilesResponse commitFiles ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  reqObj,
        const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::CommitFileData >& data ) = 0;

    /**
     * This method is to be used to save a plmxml file after getting the write ticket using
     * the GetStructureWriteTicket method.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The optional id of the Request Object in TeamCenter. Optional if AI
     *        is not being used. If RequestObject is not passed then specify NULL for this
     *        parameter.
     *
     * @param ticket
     *        ticket obtained from a prior call to GetStructureWriteTicket method.
     *
     * @param pUpdate
     *        If specified (only valid if id param is also specified), must be Full.
     *
     * @return
     *         teamcenter FileUID. Reasons of failure - will be inServiceData struct.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::CommitStructureFileResponse commitStructureFile ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  id,
        const Teamcenter::Services::Ai::_2006_03::Ai::FileTicket&  ticket,
        const UpdateType*  pUpdate ) = 0;

    /**
     * Create a new RequestObject of type Publish on the specified AI Object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The id of the AI Object in TeamCenter.
     *
     * @param detail
     *        The details like name,desc etc. to be set on the newly created
     *        RequestObject
     *
     * @param plmxmlFileName
     *        optional. Only needed if  plmxml will be uploaded right away.
     *
     * @return
     *         Failures will be returned in ServiceData. The created object is returned in data
     *         member. If plmxmlFileName is used as input - the FileTicket will have the FMS file
     *         write ticket. So, no additional call to getstructureWriteTicket is needed.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::CreatePublishRequestResponse createPublishRequest ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  id,
        const Teamcenter::Services::Ai::_2006_03::Ai::RequestDetail&  detail,
        const std::string*  plmxmlFileName ) = 0;

    /**
     * Delete the specified AI Objects from the Database.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projectIds
     *        any of the ids returned from a prior call to getProjects, or contructed from uid
     *
     * @return
     *         Partial Failures will be returned in ServiceData and DeletedObjs will be marked in
     *         service data.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteProjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  >& projectIds ) = 0;

    /**
     * Given 1 or more requestObjects - delete them from the database.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param requestIds
     *        The Request object list
     *
     * @return
     *         partial Failures will be returned in ServiceData and the DeleteObjs list will be
     *         available.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteRequests ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  >& requestIds ) = 0;

    /**
     * Set Completed state on the Sync RequestObject or Pending state on a Publish RequestObject.
     * StatusInfo and state description can be set by client
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        stateMsg
     *
     * @param stateMsg
     *        message to be set as state message.
     *
     * @param info
     *        StatusInfo that is to be set on the RequestObject. For example: some test like Okay,normal.
     *        Or, any reason of failure on client side etc.
     *
     * @return
     *         Failures will be returned in ServiceData.  The updatedObject is available too.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData endExchange ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  id,
        const std::string*  stateMsg,
        const Teamcenter::Services::Ai::_2006_03::Ai::StatusInfo*  info ) = 0;

    /**
     * Generate a Sync Request on a new AI or Existing AI object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The id of the Project(AI) object on which to generate the Sync Request Object
     *
     * @param name
     *        name to be given to the newly created Sync RequestObject. If no baseRefs argument
     *        is specified                   then, this name is used as a lookup for existing sync
     *        requests and that is processed. If no such                   request is found - then
     *        the last existing sync request is processed.
     *
     * @param description
     *        description of the newly created Sync RequestObject. Not used if baseRefs is not
     *        specified.
     *
     * @param baseRefs
     *        In the case of a newly createdAI object - this parameter specifies the the list of
     *        database objects to be exported in the Sync. It is an error to specify this parameter
     *        on an AI object having existing baseRefs. In such a case pass an empty vector.
     *
     * @return
     *         partial Failures will be returned in ServiceData. And the newly created RequestObject
     *         will be available as createdObject in servicedata
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GenerateFullSyncRequestResponse generateFullSyncRequest ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  id,
        const std::string&  name,
        const std::string&  description,
        const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef >& baseRefs ) = 0;

    /**
     * Given a  RequestObject get the next approved pending sync RequestObject.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projectId
     *        The Id of the AI object for which the next Pending,Sync Request is needed.
     *
     * @param curReq
     *        The current requestId with the client.
     *
     * @return
     *         partial Failures will be returned in ServiceData(data) member , and the plainObject
     *         will have the RequestObject. ticket member will have the fms ticket to be used with
     *         fcc client to download the plmxml.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GetNextApprovedRequestResponse getNextApprovedRequest ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  projectId,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  curReq ) = 0;

    /**
     * Get details of the specified AI Objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiIds
     *        An array of ids obtained for which only uids are available, and data is needed from
     *        Team Center.
     *
     * @return
     *         serviceData will have a  vector of type Application Interface Objects - added as
     *         PlainObjects Partial failures are also reported in serviceData
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     * @deprecated
     *         As of Teamcenter 10, use the getProjectsInfo2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the getProjectsInfo2 operation."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData getProjectsInfo ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  >& aiIds ) = 0;

    /**
     * Given a Project(AI) object, get the RequestObjects based on the optional filter.
     * default filter used: RequestType Sync and RequestState - pending.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projectId
     *        one of the ids returned from a prior call to getProjects.
     *
     * @param filter
     *        optional StateFilter where a combination of RequestStates and/or RequestTypes can
     *        be specifed.
     *
     * @return
     *         Partial Failures will be returned in ServiceData. ServiceData will contain the RequestObject
     *         Ids as plainObjects - so client Data Model can be used.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData getRequestsForProject ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  projectId,
        const Teamcenter::Services::Ai::_2006_03::Ai::StateFilter*  filter ) = 0;

    /**
     * Given a vector of RequestObjects, get details on those. This can be used if the RequestObject
     * Ids are known. If not, GetProjectRequests can be used.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param reqIds
     *        1 or more RequestObject ids obtained from a prior call getProjectRequests or some
     *        newly created ones using createPublishMethod. The reqIds are just wrappers around
     *        a stored UID - perhaps obtained from plmxml or a prior call.
     *
     * @return
     *         Partial Failures will be returned in ServiceData. The requestObjects (filled in)
     *         are available as plain objects in service data.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData getRequestsInfo ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  >& reqIds ) = 0;

    /**
     * Used to download the ticket for the plmxml file associated with the RequestObject.
     * This ticket is then to be used with FCC client Proxy to download the file.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The id of the Request Object in TeamCenter.
     *
     * @param type
     *        if specified must be Full.
     *
     * @return
     *         fileticket is returned in the Response struct.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2006_03::Ai::GetStructureReadTicketResponse getStructureReadTicket ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  id,
        const UpdateType*  type ) = 0;

    /**
     * Process(import) the plmxml corresponding to the RequestObject.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The id of the Request Object in TeamCenter.
     *
     * @return
     *         Failures will be returned in ServiceData.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData processPublishRequest ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  id ) = 0;

    /**
     * Set any StatusInfo on the RequestObject and state description.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The id of the RequestObject.
     *
     * @param stateMsg
     *        The description to be set for the current requestObject state. Note you can't change
     *        the state itself
     *
     * @param info
     *        StatusInfo that is to be set on the RequestObject
     *
     * @return
     *         Failures will be returned in ServiceData.  The updatedObject is available too.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData setExchangeMessage ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  id,
        const std::string*  stateMsg,
        const Teamcenter::Services::Ai::_2006_03::Ai::StatusInfo*  info ) = 0;

    /**
     * Set details of the specified AI Objects from the supplied vector of ProjectInfo objects.
     * You can only set targetAppProjectId, description and name fields.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projectIds
     *        An id returned from a prior call to GetProjects.
     *
     * @param infos
     *        ProjectInfo object containing the data to be set on AI's in database.
     *
     * @return
     *         Any partial failures will be returned in ServiceData.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData setProjectsInfo ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  >& projectIds,
        const std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ProjectInfo >& infos ) = 0;

    /**
     * Set Communicating State on the RequestObject. To be called before uploading or downloading
     * files to the RequestObject
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param id
     *        The id of the RequestObject.
     *
     * @return
     *         Failures will be returned in ServiceData. The createdObject is available in data.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Soa::Client::ServiceData startExchange ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  id ) = 0;


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

