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

#ifndef TEAMCENTER_SERVICES_AI__2013_05_AI_HXX
#define TEAMCENTER_SERVICES_AI__2013_05_AI_HXX

#include <teamcenter/services/ai/_2012_09/Ai.hxx>
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
            namespace _2013_05
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct FindRequestOnAiWithReferencesResponse;

    /**
     * The latest <b>RequestObjects</b> (by creation date) that are on the <b>AppInterface</b>
     * objects (latest by creation date) that reference the input baseRefs .
     * <br>
     * The following partial errors may be returned:
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Invalid inputs
     * </li>
     * <li type="disc">    Permission errors
     * </li>
     * </ul>
     */
    struct FindRequestOnAiWithReferencesResponse
    {
        /**
         * Each element in the details (type _2012_09::Ai::RequestDetail) vector maps to the
         * corresponding set based input vector and contains the following fields.
         */
        std::vector< Teamcenter::Services::Ai::_2012_09::Ai::RequestDetail > details;
        /**
         * The standard soa serviceData that is used for adding partial errors and sending properties
         * of the object. The properties that are returned by default ( without getting not
         * loaded exception ) are:
         * <br>
         * <ul>
         * <li type="disc">object_name
         * </li>
         * <li type="disc">object_desc
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

