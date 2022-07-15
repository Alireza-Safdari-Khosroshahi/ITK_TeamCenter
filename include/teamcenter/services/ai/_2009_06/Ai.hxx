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

#ifndef TEAMCENTER_SERVICES_AI__2009_06_AI_HXX
#define TEAMCENTER_SERVICES_AI__2009_06_AI_HXX

#include <teamcenter/services/ai/_2008_06/Ai.hxx>
#include <teamcenter/soa/client/model/AppInterface.hxx>
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
            namespace _2009_06
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct GenerateScopedMultipleStructure3Response;

    /**
     * GenerateScopedMultipleStructure3Response struct
     */
    struct GenerateScopedMultipleStructure3Response
    {
        /**
         * The transient file ticket to be used for downloading the generated plmxml
         */
        std::string ticket;
        /**
         * The transient file tickets for any files exported during generation of plmxml
         */
        std::vector< std::string > fileTickets;
        /**
         * Name of the folder where the transient fileTickets have to be downloaded relative
         * to the folder where plmxml file is downloaded.
         */
        std::string relativeFolderName;
        /**
         * filenames as they appear in the transient volume under the plmxml created folder.
         */
        std::vector< std::string > fileNames;
        /**
         * partial failures are returned - along with object ids for each plmxml data could
         * not be generated.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };




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


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

