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

#ifndef TEAMCENTER_SERVICES_AI__2008_06_AI_HXX
#define TEAMCENTER_SERVICES_AI__2008_06_AI_HXX

#include <teamcenter/services/ai/_2006_03/Ai.hxx>
#include <teamcenter/soa/client/model/AppInterface.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
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
            namespace _2008_06
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct CompareConfigurationContextsResponse;
    struct Configuration;
    struct ConfigurationContextPair;
    struct GenerateScopedMultipleStructure2Response;
    struct GenerateScopedSyncRequest2Response;
    struct ObjectsWithConfig;
    struct ReferenceContext;

    /**
     * CompareConfigurationContextsResponse struct
     */
    struct CompareConfigurationContextsResponse
    {
        /**
         * bool array pointing to the result in the compares. Only successful (true/false) are
         * returned here.
         */
        std::vector< bool > compareResults;
        /**
         * any partial errors are reported here. For example: if any pair comparison fails -
         * that failed index with the failed message will be reported like this.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Configuration structure.
     */
    struct Configuration
    {
        /**
         * existingWindow
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  existingWindow;
        /**
         * if true - the Teamcenter preferences are used to pick up the rev rule. Overrides
         * everything if present.
         */
        bool useDefaultRevisionRule;
        /**
         * Used to specify the revisionrule by name.
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
    };

    /**
     * ConfigurationContextPair struct
     */
    struct ConfigurationContextPair
    {
        /**
         * src configurationcontext object to use in compare
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  src;
        /**
         * target configurationcontext object to use in compare.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  other;
    };

    /**
     * GenerateScopedMultipleStructure2Response struct
     */
    struct GenerateScopedMultipleStructure2Response
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
     * GenerateScopedSyncRequest2Response struct
     */
    struct GenerateScopedSyncRequest2Response
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
        Teamcenter::Services::Ai::_2008_06::Ai::Configuration config;
        /**
         * If passing process object, this parameter can be used to specify how to setup the
         * reference Product/Plant structure for that Process. If unused, pass an empty vector.
         */
        std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ReferenceContext > refContexts;
    };

    /**
     * structure to specify the reference structure, in the case of process element like
     * MEProcessRevision, MEOpRevision, a process APN etc.
     */
    struct ReferenceContext
    {
        /**
         * ApplicationRef specifying the object to be set as the topline of the reference structure.
         * It is optional if config structure's configuringObject is an StructureContext object.
         * If not needed - pass an empty ApplicationRef.
         */
        Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef topLineObject;
        /**
         * configuration to be used to construct the reference window.
         */
        Teamcenter::Services::Ai::_2008_06::Ai::Configuration config;
    };




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


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

