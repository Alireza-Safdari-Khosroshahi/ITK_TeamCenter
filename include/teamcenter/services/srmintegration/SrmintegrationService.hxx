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

#ifndef TEAMCENTER_SERVICES_SRMINTEGRATION_SRMINTEGRATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_SRMINTEGRATION_SRMINTEGRATIONSERVICE_HXX

#include <teamcenter/services/srmintegration/_2009_10/Srmintegration.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/srmintegration/SrmIntegration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Srmintegration
        {
            class SrmintegrationService;

/**
 * The SRM Integration service exposes operations that are used to export assemblies,
 * attributes, and attachments to the RFx application. The RFx application is one of
 * a suite of SRM products that deals with exchanging information with the supplier
 * and is primarily used for qualifying, negotiating, and collecting supplier capability
 * information.
 * <br>
 * <br>
 * This service provides the following SRM Integration use case
 * <br>
 * <ul>
 * <li type="disc">Exchange of Teamcenter assemblies, attributes and attachments with
 * the suppliers.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoasrmintegrationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoasrmintegrationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASRMINTEGRATIONSTRONGMNGD_API SrmintegrationService
    : public Teamcenter::Services::Srmintegration::_2009_10::Srmintegration
{
public:
    static SrmintegrationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Through this option Teamcenter initiates asynchronous exchange of assemblies, attributes,
     * and attachments with the suppliers through RFx. Data is exported directly from Teamcenter
     * to RFx through SRMConnect middleware application with no intermediate objects created.
     * Once the export finishes, an event is created in RFx with the item data exported
     * from Teamcenter. The supplier can provide a change in assembly with the item attribute
     * information and attachments through the created RFx event. Sponsors and suppliers
     * users of RFx can access Teamcenter datasets directly from the Teamcenter FMS. Responses
     * from the supplier to the event can be published back to Teamcenter from RFx. No supplier
     * comparison or award process is supported by this exchange.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SrmIntegration SOA Component - Component for TcSoaSrmIntegration
     *
     * @param srmInput
     *        The data is exported to RFx based on the information on the <code>SrmServiceInput</code>
     *        type input. It contains information of the Teamcenter parts, transfer option set,
     *        sponsor username, sponsor email, and the reason for export.
     *
     * @return
     *         A <code>serviceData</code> element with no object is returned as part of create,
     *         update, delete, or plain lists. If the SRMConnect middleware application, which acts
     *         as a bridge between Teamcenter and RFx, is not reachable then error code 33123 is
     *         returned as a partial error.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData exportToSRM ( const Teamcenter::Services::Srmintegration::_2009_10::Srmintegration::SrmServiceInput&  srmInput ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SrmintegrationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/srmintegration/SrmIntegration_undef.h>
#endif

