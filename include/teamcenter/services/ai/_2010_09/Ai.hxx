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

#ifndef TEAMCENTER_SERVICES_AI__2010_09_AI_HXX
#define TEAMCENTER_SERVICES_AI__2010_09_AI_HXX

#include <teamcenter/services/ai/_2008_06/Ai.hxx>
#include <teamcenter/soa/client/model/AppInterface.hxx>


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
            namespace _2010_09
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct GenerateAndEvaluateStructureResponse;

    /**
     * Map of xpath string to the values obtained by running this against the plmxml file.
     */
    typedef std::map< std::string, std::vector< std::string > > XpathToValuesMap;

    /**
     * Response structure for generateAndEvaluateStructure method.
     */
    struct GenerateAndEvaluateStructureResponse
    {
        /**
         * The map of xpath to the values obtained by evaluating this xpath against the generated
         * plmxml.
         */
        XpathToValuesMap xpathToValuesMap;
        /**
         * partial failures are returned - along with object ids for each plmxml data could
         * not be generated.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * If an xml is generated on server - input does not specify an existing plmxml or invalid
         * filename - a fileticket is returned for that file.
         */
        std::string transientFileTicket;
    };




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


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

