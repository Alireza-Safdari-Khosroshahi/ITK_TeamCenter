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

#ifndef TEAMCENTER_SERVICES_RDV__2009_04_CONTEXTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_RDV__2009_04_CONTEXTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>


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
            namespace _2009_04
            {
                class Contextmanagement;

class TCSOARDVSTRONGMNGD_API Contextmanagement
{
public:

    struct GetGOPartSolutionsResponse;
    struct GetPastePrimeInfo;

    /**
     * The GetGOPartSolutionsResponse structure represents output of vector of APN of line
     * of usages (part solution), instantiating architecture  bom window and the service
     * data.
     */
    struct GetGOPartSolutionsResponse
    {
        /**
         * vector of BOMLine of LOU
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > louBomLine;
        /**
         * Instantiating Architecture Bom window
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  archBomWindow;
        /**
         * serviceData returned as response for retrieving information on LOU APN
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the list of the source and target <b>BOMLine</b> objects
     * and a flag to indicate which attributes needs to be copied from the source <b>BOMLine</b>
     * to target <b>BOMLine</b>.
     */
    struct GetPastePrimeInfo
    {
        /**
         * List of the target Architecture Breakdown or Architecture Breakdown Element <b>BOMLine</b>
         * objects.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > parentBomLine;
        /**
         * List of the source Architecture Breakdown Element <b>BOMLine</b> objects.
         * <br>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > componentBomLine;
        /**
         * Flag to decide which attributes need to be copied from the source to the target BOMLine.
         * <br>
         * If flag value is 1 then only variability will be copied from the source to target
         * BOMLine.
         * <br>
         * If flag value is 2 then variability and NVEs will be copied from the source to target
         * BOMLine.
         * <br>
         * If flag value is 3 then variability, NVEs and part solutions will be copied from
         * the source to target BOMLine.
         * <br>
         */
        int flag;
    };




    /**
     * Get the required information for display of part solutions of selected GBE and its
     * instantiating ABE.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param goBomLine
     *        contains selected GBE bomline
     *
     * @return
     *         Contains vector of APN of line of usages (part solution) and            instantiating
     *         architecture bom window
     *
     */
    virtual Teamcenter::Services::Rdv::_2009_04::Contextmanagement::GetGOPartSolutionsResponse getAllGOPartSolutions ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  goBomLine ) = 0;

    /**
     * This operation pastes source <b>Architecture Breakdown Element</b> (ABE) <b>BOMLine</b>
     * to the target <b>Architecture Breakdown </b>(AB) <b>BOMLine</b>. It pastes all the
     * parents (up to top level AB) of the source ABE under target AB. This operation also
     * copies the variability, Named Variant Expressions (NVEs) and part solutions from
     * the source <b>BOMLine</b> to target <b>BOMLine</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used to paste the source Architecture Breakdown Element <b>BOMLine</b>
     * to target Architecture Breakdown <b>BOMLine</b>.
     * <br>
     * <br>
     * Use case 1: Copy variability
     * <br>
     * User needs to set flag value as 1 in GetPastePrimeInfo structure to copy only the
     * variability from the source <b>BOMLine</b> to target <b>BOMLine</b>.
     * <br>
     * <br>
     * Use case 2: Copy variability and NamedVariantExpressions
     * <br>
     * User needs to set flag value as 2 in GetPastePrimeInfo structure to copy the variability
     * and Named Variant Expressions from the source <b>BOMLine</b> to target <b>BOMLine</b>.
     * <br>
     * <br>
     * Use case 3: Copy variability, NamedVariantExpressions and part solutions
     * <br>
     * User needs to set flag value as 3 in GetPastePrimeInfo structure to copy the variability,
     * Named Variant Expressions and part solutions from the source <b>BOMLine</b> to target
     * <b>BOMLine</b>.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Platform Designer - Application to create and manage architecture breakdowns and
     * product variability.
     *
     * @param input
     *        Reference to <code>GetPastePrimeInfo</code> object which contains the list of source
     *        and target <b>BOMLine</b> and a flag to indicate which attributes needs to be copied
     *        from the source <b>BOMLine</b> to target <b>BOMLine</b>.
     *
     * @return
     *         Returns the <code>ServiceData</code> object. If there is any exception during this
     *         operation it will be added to the <code>ServiceData</code> object and returned as
     *         a partial error.
     *         <br>
     *         Following are some possible errors returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM module
     *         </li>
     *         <li type="disc">46000 Internal error in BOM module
     *         </li>
     *         <li type="disc">38041 An invalid object is being used in conjunction with property
     *         </li>
     *         <li type="disc">46024 You cannot have variants of the top line of the BOM
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData getPastePrimeAttributes ( const Teamcenter::Services::Rdv::_2009_04::Contextmanagement::GetPastePrimeInfo&  input ) = 0;


protected:
    virtual ~Contextmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/rdv/Rdv_undef.h>
#endif

