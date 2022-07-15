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

#ifndef TEAMCENTER_SERVICES_AI__2008_05_AI_HXX
#define TEAMCENTER_SERVICES_AI__2008_05_AI_HXX

#include <teamcenter/services/ai/_2006_03/Ai.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


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
            namespace _2008_05
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct GenerateArrangementsResponse;

    /**
     * GenerateArrangementsResponse struct
     */
    struct GenerateArrangementsResponse
    {
        /**
         * The FMS ticket is used to get the generated PLMXML file.
         */
        std::string fileTicket;
        /**
         * The service data is used to report any partial failures.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

