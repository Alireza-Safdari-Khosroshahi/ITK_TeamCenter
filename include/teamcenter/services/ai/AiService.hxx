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

#ifndef TEAMCENTER_SERVICES_AI_AISERVICE_HXX
#define TEAMCENTER_SERVICES_AI_AISERVICE_HXX

#include <teamcenter/services/ai/_2006_03/Ai.hxx>
#include <teamcenter/services/ai/_2007_12/Ai.hxx>
#include <teamcenter/services/ai/_2008_05/Ai.hxx>
#include <teamcenter/services/ai/_2008_06/Ai.hxx>
#include <teamcenter/services/ai/_2009_06/Ai.hxx>
#include <teamcenter/services/ai/_2009_10/Ai.hxx>
#include <teamcenter/services/ai/_2010_09/Ai.hxx>
#include <teamcenter/services/ai/_2012_09/Ai.hxx>
#include <teamcenter/services/ai/_2013_05/Ai.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/ai/Ai_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Ai
        {
            class AiService;

/**
 * Contains Ai Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaaistrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaaitypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAAISTRONGMNGD_API AiService
    : public Teamcenter::Services::Ai::_2006_03::Ai,
             public Teamcenter::Services::Ai::_2007_12::Ai,
             public Teamcenter::Services::Ai::_2008_05::Ai,
             public Teamcenter::Services::Ai::_2008_06::Ai,
             public Teamcenter::Services::Ai::_2009_06::Ai,
             public Teamcenter::Services::Ai::_2009_10::Ai,
             public Teamcenter::Services::Ai::_2010_09::Ai,
             public Teamcenter::Services::Ai::_2012_09::Ai,
             public Teamcenter::Services::Ai::_2013_05::Ai
{
public:
    static AiService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * GenerateScopedMultipleStructure: Same as GenerateScopedSyncRequest - except no aiObject
     * is needed. If specified - it is only used to get the TransferMode (in case the exportTransferMode
     * is not specified). objects or occurrence group objects - specified as application
     * refs. The configuration is optional if the ids consist of StructureContexts. ApplicationRefs
     * can be ids of occurrence from a previous export from TC, or APNs or AbsOccs, or OccurrenceGroup
     * or an Item/Itemrev(only one in that last case). If the Appref is custom (non TcEng
     * AppRef), occurrence appref must resolve to AbsOccurrence or APN ), or they can be
     * ids of structure context/occurrence group objects. The return is the transient file
     * ticket for the plmxml file generated. In case any of the input apprefs cannot be
     * processed they will be returned in the data member of response. Errors during plmxml
     * processing will be returned in partialerror as xml string, based on TcError.xsd in
     * iman_data folder. Configuration structure can be used to specify default revrule
     * (if true) all other fields are ignored. Basically, they are declared in the order
     * of precedence (where duplication is possible).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiObject
     *        The Application Interface object under which the new sync request is to be created.
     *
     * @param objectsToProcess
     *        The list of objects for which a single plmxml will be generated. The configuration
     *        for each of the                             object is also specified here.
     *
     * @param exportTransferMode
     *        Name of the transfermode for exporting plmxml.
     *
     * @param serverMode
     *        values are 2 or 4 (2-tier or 4-tier). Used in the generation of transient ticket.
     *
     * @return
     *         partial failures are returned in data.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     * @deprecated
     *         As of Teamcenter 8.0.1, use generateScopedMultipleStructure2 (if the transfermode
     *         is not exporting files to disk), or generateScopedMultipleStructure3 (if the transfermode
     *         is export files to disk on server side - closure rule: ImanFile:*:original_file_name:DO).
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.0.1, use generateScopedMultipleStructure2 (if the transfermode is not exporting files to disk), or generateScopedMultipleStructure3 (if the transfermode is export files to disk on server side - closure rule: ImanFile:*:original_file_name:DO)."))
#endif
    virtual Teamcenter::Services::Ai::_2007_12::Ai::GenerateScopedMultipleStructureResponse generateScopedMultipleStructure ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  aiObject,
        const std::vector< Teamcenter::Services::Ai::_2007_12::Ai::ObjectsWithConfig >& objectsToProcess,
        const std::string*  exportTransferMode,
        int serverMode ) = 0;

    /**
     * Generates a new Sync Request for the given occurrences (from any context) or Structure
     * Context objects or occurrence group objects - specified as application refs. The
     * configuration is optional if the ids consist of StructureContexts. ApplicationRefs
     * can be ids of occurrence from a previous export from TC, or APNs or AbsOccs, or OccurrenceGroup
     * or an Item/Itemrev(only one in that last case). If the Appref is custom (non TcEng
     * AppRef), occurrence appref must resolve to AbsOccurrence or APN ), or they can be
     * ids of structure context/occurrence group objects. The return will be the details
     * of the newly created Sync Request. Note that the name, desc, scope, updateType of
     * this request are based on the passed in requestDetail. The other fields of the RequestDetail
     * are not used during input. In case any of the input apprefs cannot be processed they
     * will be returned in the failedIndices structure. Errors during plmxml processing
     * will be returned in partialerror , based on TcError.xsd in iman_data folder.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiObject
     *        The Application Interface object under which the new sync request is to be created.
     *
     * @param objectsToProcess
     *        The list of objects for which a single plmxml will be generated. The configuration
     *        for each of the                             object is also specified here.
     *
     * @param requestDetail
     *        The details (name, description, scope, updateType(incremental)) are used in the creation
     *        of the sync request. Set the scope type to RequestScope_Whole and updatetype to UpdateType_Full
     *        if this structure is not to be used.
     *
     * @return
     *         partial failures are returned in data.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2007_12::Ai::GenerateScopedSyncRequestResponse generateScopedSyncRequest ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  aiObject,
        const std::vector< Teamcenter::Services::Ai::_2007_12::Ai::ObjectsWithConfig >& objectsToProcess,
        const Teamcenter::Services::Ai::_2006_03::Ai::RequestDetail*  requestDetail ) = 0;

    /**
     * The generateArrangements operation will generate a PLMXML file with arrangements
     * for an Item Revision. This operation will find out the BOMView Revision with input
     * BOMView Type associated to the Item Revision at first and then do generating process.
     * An Item Revision and a BOMView Type can specify an unique BOMView Revision. If input
     * BOMView Type is NULL, the default BOMView Type will be picked up. A revision rule
     * can be applied to the BOMView Revision while generating. The output is struct GenerateArrangementsResponse
     * with generated PLMXML file ticket and soa service data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param itemRev
     *        The Item Revision object to generate arrangements from.
     *
     * @param revRule
     *        The revision rule to be applied to BOMView Revision of input Item Revision.
     *
     * @param bvType
     *        The BOMView Type name to be used to specify the BOMView Revision of the input Item
     *        Revision. There may be more than one BOMView Revision associated to an Item Revision
     *        with different BOMView Types. If the input BOMView Type name is NULL, the default
     *        BOMView Type will be used to pick up the BOMView Revision.
     *
     * @return
     *         The FMS ticket to generated PLMXML file and any partial failures.
     *
     */
    virtual Teamcenter::Services::Ai::_2008_05::Ai::GenerateArrangementsResponse generateArrangements ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev,
        const Teamcenter::Services::Ai::_2006_03::Ai::Configuration&  revRule,
        const std::string*  bvType ) = 0;

    /**
     * compareConfigurationContexts: allows clients to check if configurationcontext with
     * different uids are equivalent or not. This is because a configurationcontext is used
     * to capture runtime revisionrules and there might be 2 configurationcontext created
     * with same set of runtime rules. This interface is for backward compatibility with
     * Ai. configurationsToCompare pairs of configurationContexts to compare with one other.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param configurationsToCompare
     *        vector of configurations to compare.
     *
     * @return
     *         a bool vector which has the results for successful comparisions - either true or
     *         false. Any pair that gives an error - the index of such a failed error is returned
     *         in the serviceData member.
     *
     */
    virtual Teamcenter::Services::Ai::_2008_06::Ai::CompareConfigurationContextsResponse compareConfigurationContexts ( const std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ConfigurationContextPair >& configurationsToCompare ) = 0;

    /**
     * GenerateScopedMultiple2Structure: Same as GenerateScopedSyncRequest2 - except no
     * aiObject is needed. If specified - it is only used to get the TransferMode (in case
     * the exportTransferMode is not specified). objects or occurrence group objects - specified
     * as application refs. The configuration is optional if the ids consist of StructureContexts.
     * ApplicationRefs can be ids of occurrence from a previous export from TC, or APNs
     * or AbsOccs, or OccurrenceGroup or an Item/Itemrev(only one in that last case). If
     * the Appref is custom (non TcEng AppRef), occurrence appref must resolve to AbsOccurrence
     * or APN ), or they can be ids of structure context/occurrence group objects. The return
     * is the transient file ticket for the plmxml file generated. In case any of the input
     * apprefs cannot be processed they will be returned in the data member of response.
     * Errors during plmxml processing will be returned in partialerror as xml string, based
     * on TcError.xsd in iman_data folder. Configuration structure can be used to specify
     * default revrule (if true) all other fields are ignored. Basically, they are declared
     * in the order of precedence (where duplication is possible).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiObject
     *        The Application Interface object under which the new sync request is to be created.
     *
     * @param objectsToProcess
     *        The list of objects for which a single plmxml will be generated. The configuration
     *        for each of the                             object is also specified here.
     *
     * @param exportTransferMode
     *        Name of the transfermode for exporting plmxml.
     *
     * @param serverMode
     *        values are 2 or 4 (2-tier or 4-tier). Used in the generation of transient ticket.
     *
     * @return
     *         partial failures are returned in data.
     *
     */
    virtual Teamcenter::Services::Ai::_2008_06::Ai::GenerateScopedMultipleStructure2Response generateScopedMultipleStructure2 ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  aiObject,
        const std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ObjectsWithConfig >& objectsToProcess,
        const std::string*  exportTransferMode,
        int serverMode ) = 0;

    /**
     * generateScopedSyncRequest2: Generates a new Sync Request for the given occurrences
     * (from any context) or Structure Context objects or occurrence group objects - specified
     * as application refs. The configuration is optional if the ids consist of StructureContexts.
     * ApplicationRefs can be ids of occurrence from a previous export from TC, or APNs
     * or AbsOccs, or OccurrenceGroup or an Item/Itemrev(only one in that last case). If
     * the Appref is custom (non TcEng AppRef), occurrence appref must resolve to AbsOccurrence
     * or APN ), or they can be ids of structure context/occurrence group objects. The return
     * will be the details of the newly created Sync Request. Note that the name, desc,
     * scope, updateType of this request are based on the passed in requestDetail. The other
     * fields of the RequestDetail are not used during input. In case any of the input apprefs
     * cannot be processed they will be returned in the failedIndices structure. Errors
     * during plmxml processing will be returned in partialerror , based on TcError.xsd
     * in iman_data folder. This differs from generateScopedSyncRequest, in that it allows
     * you to specify the reference structures for process.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiObject
     *        The Application Interface object under which the new sync request is to be created.
     *
     * @param objectsToProcess
     *        The list of objects for which a single plmxml will be generated. The configuration
     *        for each of the                             object is also specified here.
     *
     * @param requestDetail
     *        The details (name, description, scope, updateType(incremental)) are used in the creation
     *        of the sync request. Set the scope type to RequestScope_Whole and updatetype to UpdateType_Full
     *        if this structure is not to be used.
     *
     * @return
     *         partial failures are returned in data.
     *
     */
    virtual Teamcenter::Services::Ai::_2008_06::Ai::GenerateScopedSyncRequest2Response generateScopedSyncRequest2 ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  aiObject,
        const std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ObjectsWithConfig >& objectsToProcess,
        const Teamcenter::Services::Ai::_2006_03::Ai::RequestDetail*  requestDetail ) = 0;

    /**
     * Given a set of bomlines from the same window, create a private structure context
     * and return that. If the input contains any persistent objects like a workspaceobject
     * - those will be returned as is.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param inputLines
     *        list of bomlines from the same bomwindow, for which a StructureContext needs to be
     *        created. Note that if input has persistent objects - they will be returned as is.
     *
     * @return
     *         The serviceData willl have any newly created StructureContext object and partialErrors.
     *         In addition - if any persistent objects are passed in - they will be returned as
     *         objects.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getPersistentObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& inputLines ) = 0;

    /**
     * GenerateScopedMultipleStructure3: Same as GenerateScopedMultipleStructure2 - except
     * filetickets are returned. If aiObject is specified - it is only used to get the TransferMode
     * (in case the exportTransferMode is not specified). objects or occurrence group objects
     * - specified as application refs. The configuration is optional if the ids consist
     * of StructureContexts. ApplicationRefs can be ids of occurrence from a previous export
     * from TC, or APNs or AbsOccs, or OccurrenceGroup or an Item/Itemrev(only one in that
     * last case). If the Appref is custom (non TcEng AppRef), occurrence appref must resolve
     * to AbsOccurrence or APN ), or they can be ids of structure context/occurrence group
     * objects. The return is the transient file ticket for the plmxml file generated. In
     * case any of the input apprefs cannot be processed they will be returned in the data
     * member of response. Errors during plmxml processing will be returned in partialerror
     * as xml string, based on TcError.xsd in iman_data folder. Configuration structure
     * can be used to specify default revrule (if true) all other fields are ignored. Basically,
     * they are declared in the order of precedence (where duplication is possible).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiObject
     *        The Application Interface object under which the new sync request is to be created.
     *
     * @param objectsToProcess
     *        The list of objects for which a single plmxml will be generated. The configuration
     *        for each of the                             object is also specified here.
     *
     * @param exportTransferMode
     *        Name of the transfermode for exporting plmxml.
     *
     * @param serverMode
     *        values are 2 or 4 (2-tier or 4-tier). Used in the generation of transient ticket.
     *
     * @return
     *         partial failures are returned in data.
     *
     */
    virtual Teamcenter::Services::Ai::_2009_06::Ai::GenerateScopedMultipleStructure3Response generateScopedMultipleStructure3 ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  aiObject,
        const std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ObjectsWithConfig >& objectsToProcess,
        const std::string*  exportTransferMode,
        int serverMode ) = 0;

    /**
     * get the property values for the object supplied as ApplicationReferences and configuration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param input
     *        array of input structure - each of which specifies the object and configuration,
     *        along with properties.
     *
     * @return
     *         return the property values for the input properties and objects.
     *
     */
    virtual Teamcenter::Services::Ai::_2009_10::Ai::GetPropertyValuesResponse getPropertyValues ( const std::vector< Teamcenter::Services::Ai::_2009_10::Ai::GetPropertyValuesData >& input ) = 0;

    /**
     * Service to generate a plmxml based on the input objects, configuration, transfermode
     * provided and  evaluate the specified xpaths 1.0 expressions against that plmxml.
     * Optionally - a pre-existing xml file can be specified (via a full path accessible
     * in tc server environment). In that case, only the xpaths argument is used along with
     * the absoluteXmlFile argument.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param aiObject
     *        This parameter is optional (specify NULL if not used). If specified, will be used
     *        to get the export transfermode name to be used for plmxml generation.
     *
     * @param objectsToProcess
     *        A mandatory parameter. If not specified an exception will be thrown. The list of
     *        objects for which a single plmxml will be generated. The configuration for each of
     *        the object is also specified here.
     *
     * @param exportTransferMode
     *        The transfermode to use for generating the plmxml file. If not specified, the aiObject's
     *        transfermode is used. If neither is specified - an exception will be thrown.
     *
     * @param absoluteXmlFileName
     *        In case there is already a plmxml file generated and available on the tcserver environment,
     *        then instead of passing objectsToProcess - this argument can be passed with the absolute
     *        path name of such a file. If this is specified -  only the xpaths argument is used,
     *        unless the file does not exist - in which case it will be created using the other
     *        arguments.
     *
     * @param xpaths
     *        The list of xpath 1.0 expressions to be used for evaluation on top of the generated
     *        plmxml.
     *
     * @return
     *         return the map of xpath expression to it's evaluations and any errors in serviceData.
     *         If an xml file is generated - the transient ticket for that file is also returned.
     *
     *
     * @exception ServiceException
     *           Thrown on service failure.
     */
    virtual Teamcenter::Services::Ai::_2010_09::Ai::GenerateAndEvaluateStructureResponse generateAndEvaluateStructure ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  aiObject,
        const std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ObjectsWithConfig >& objectsToProcess,
        const std::string*  exportTransferMode,
        const std::string*  absoluteXmlFileName,
        const std::vector< std::string >& xpaths ) = 0;

    /**
     * method to find request objects based on the input criteria.
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
     *        Mandatory input field for filtering Request objects as per the input criteria.
     *
     * @return
     *         list of found requests and any  partial errors.
     *
     */
    virtual Teamcenter::Services::Ai::_2012_09::Ai::FindRequestsResponse findRequests ( const Teamcenter::Services::Ai::_2012_09::Ai::FindRequestsFilter&  filter ) = 0;

    /**
     * get the Application Interface objects based on a optional filter.
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
     *        optional filter used to narrow down the number of ApplicationInterface Objects.
     *
     * @return
     *         ServiceData object that has the ApplicationInterface objects that were found (returned
     *         as plain objects).
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getProjects ( const Teamcenter::Services::Ai::_2012_09::Ai::ProjectFilter*  filter ) = 0;

    /**
     * set the info on the ApplicationInterface Objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param infos
     *        info to be set on the ApplicationInterface Object. The Ai object is part of the structure.
     *
     * @return
     *         ServiceData object that returns the objects on which setting the data succeeded,
     *         and partial failures for those that failed.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setProjectsInfo ( const std::vector< Teamcenter::Services::Ai::_2012_09::Ai::ProjectInfo >& infos ) = 0;

    /**
     * method to allow caller to set the fields on the RequestObject.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param infos
     *        vector of info elements to set data on respective RequestObject.
     *
     * @return
     *         ServiceData that captures partial failures, and also list of updated objects if data
     *         is set successfully.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setRequestsInfo ( const std::vector< Teamcenter::Services::Ai::_2012_09::Ai::RequestInfo >& infos ) = 0;

    /**
     * return the projectInfo information for each of the supplied ApplicationInterface
     * Objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param projects
     *        list of Application Interface objects for which the details are needed.
     *
     * @return
     *         return the info for the provided Application Interface Objects, and any partial errors
     *         - the Application Interface Objects position in the passed in vector will be used
     *         as the clientId for errors
     *
     */
    virtual Teamcenter::Services::Ai::_2012_09::Ai::GetProjectsInfo2Response getProjectsInfo2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppInterface>  >& projects ) = 0;

    /**
     * get details about specific RequestObjects. These include state desc,status info,
     * custom key value pairs.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param robjects
     *        input vector of RequestObjects for which details are needed.
     *
     * @return
     *         vector or RequestDetails. The size of this vector may not be same as input vector.
     *         Partial errors are recorded in serviceData.
     *
     */
    virtual Teamcenter::Services::Ai::_2012_09::Ai::GetRequestsInfo2Response getRequestsInfo2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  >& robjects ) = 0;

    /**
     * The operation queries for the latest <b>RequestObjects</b> (by creation date and
     * type) on the latest <b>ApplicationInterface</b> Object ( by creation date) that references
     * the input object in the base_refs member. Additional filtering based on type of <b>RequestObject</b>
     * is also possible.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param baseRef
     *        The object referenced by ApplicationsInterface. Currently, these are the allowed
     *        types:
     *        <br>
     *        <ul>
     *        <li type="disc">Item
     *        </li>
     *        <li type="disc">ItemRevision
     *        </li>
     *        <li type="disc">PSBOMView
     *        </li>
     *        <li type="disc">PSBOMViewRevision
     *        </li>
     *        <li type="disc">CCObject
     *        </li>
     *        <li type="disc">StructureContext
     *        </li>
     *        </ul>
     *        <br>
     *        The input is set based.
     *
     * @param requestType
     *        The type of the RequestObject to qualify the search. Valid values are (Case sensitive):
     *        <br>
     *        <ul>
     *        <li type="disc">Sync
     *        </li>
     *        <li type="disc">Publish
     *        </li>
     *        <li type="disc">All (default if value is not one of Sync or Publish including NULL)
     *        </li>
     *        </ul>
     *
     * @return
     *         The latest <b>RequestObjects</b> ( creation date) that are on the <b>AppInterface</b>
     *         objects (latest by creation date) that reference the input baseRefs.
     *         <br>
     *         The following partial errors may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">515024
     *         </li>
     *         <li type="disc">51005&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Ai::_2013_05::Ai::FindRequestOnAiWithReferencesResponse findRequestOnAiWithReferences ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& baseRef,
        const std::string*  requestType ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AiService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/ai/Ai_undef.h>
#endif

