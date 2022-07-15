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

#ifndef TEAMCENTER_SERVICES_AI__2007_12_AI_HXX
#define TEAMCENTER_SERVICES_AI__2007_12_AI_HXX

#include <teamcenter/services/ai/_2006_03/Ai.hxx>
#include <teamcenter/soa/client/model/AppInterface.hxx>
#include <teamcenter/soa/client/model/RequestObject.hxx>


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
            namespace _2007_12
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct Configuration2;
    struct GenerateScopedMultipleStructureResponse;
    struct GenerateScopedSyncRequestResponse;
    struct ObjectsWithConfig;

    /**
     * Configuration structure.
     */
    struct Configuration2
    {
        /**
         * if true - the Teamcenter preferences are used to pick up the rev rule. Overrides
         * everything if present.
         */
        bool useDefaultRevisionRule;
        /**
         * if id is NULLTAG, then used to specify the revisionrule by name.
         */
        std::string revRuleName;
        /**
         * ApplicationRef of a variantrule - only needed if revrule is being specified elsewhere.
         */
        Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef variantRule;
        /**
         * revisionrule object or structurecontext
         */
        Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef configuringObject;
        /**
         * vector of ApplicationRefs specifying the structure contexts to help create the linked
         * windows
         */
        std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef > relatedContexts;
    };

    /**
     * GenerateScopedMultipleStructureResponse struct
     */
    struct GenerateScopedMultipleStructureResponse
    {
        /**
         * The transient file ticket to be used for downloading the generated plmxml
         */
        std::string ticket;
        /**
         * partial failures are returned - along with object ids for each plmxml data could
         * not be generated.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * GenerateScopedSyncRequestResponse struct
     */
    struct GenerateScopedSyncRequestResponse
    {
        /**
         * request
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RequestObject>  request;
        /**
         * partial failures are returned - object ids for each sync data could not be created.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * structure to specify multiple objects with each set potentially having it's own configuration
     */
    struct ObjectsWithConfig
    {
        /**
         * vector of ApplicationRefs specifying the objects to be included in the plmxml generation
         */
        std::vector< Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef > apprefs;
        /**
         * configuration to be used for the above set of objects.
         */
        Teamcenter::Services::Ai::_2007_12::Ai::Configuration2 config;
    };




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


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

