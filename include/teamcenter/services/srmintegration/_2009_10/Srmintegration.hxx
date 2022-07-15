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

#ifndef TEAMCENTER_SERVICES_SRMINTEGRATION__2009_10_SRMINTEGRATION_HXX
#define TEAMCENTER_SERVICES_SRMINTEGRATION__2009_10_SRMINTEGRATION_HXX

#include <teamcenter/soa/client/model/TransferOptionSet.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/srmintegration/SrmIntegration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Srmintegration
        {
            namespace _2009_10
            {
                class Srmintegration;

class TCSOASRMINTEGRATIONSTRONGMNGD_API Srmintegration
{
public:

    struct SrmServiceInput;

    /**
     * Input structure for <code>exportToSRM</code>.
     */
    struct SrmServiceInput
    {
        /**
         * Reason for the export of the selected Teamcenter parts to SRM. This reason for the
         * export is used to populate the description of the event in RFx.
         */
        std::string reason;
        /**
         * Username of the current logged in Teamcenter user who is sponsor user of RFx application
         * in a specific partition. This user of Teamcenter will be assigned as sponsor to the
         * event being created as part of the SRM export.
         */
        std::string sponsorUserID;
        /**
         * Email ID of the sponsor or any person who is required to be notified for the success
         * or failure of the export to SRM.
         */
        std::string sponsorEmailID;
        /**
         * The reference of the Teamcenter parts to be exported to SRM.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > parts;
        /**
         * The name of the transfer option set to be used for exporting the selected Teamcenter
         * parts as Tc XML which will be further exported to the SRMConnect middleware application.
         * This middleware application calls RFx Web services to create an event, items, etc.
         * in RFx.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  transferOption;
    };




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


protected:
    virtual ~Srmintegration() {}
};
            }
        }
    }
}

#include <teamcenter/services/srmintegration/SrmIntegration_undef.h>
#endif

