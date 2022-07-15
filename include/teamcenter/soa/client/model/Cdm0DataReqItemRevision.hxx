/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0DATAREQITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0DATAREQITEMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CompanyContact;
                class Fnd0StaticTable;


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0DataReqItemRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    bool get_cdm0ApprovalRequired();
    bool get_cdm0CertRequired();
    const std::string& get_cdm0Comments();
    int get_cdm0DataMgmtDueOffset();
    const std::string& get_cdm0DeliveryAddress();
    const std::string& get_cdm0DeliveryMechanism();
    const std::string& get_cdm0DIDTitle();
    bool get_cdm0DistributionRequired();
    const std::string& get_cdm0EffCutoffEventDesc();
    const Teamcenter::Soa::Common::DateTime& get_cdm0EffectiveCutoffDate();
    const std::string& get_cdm0ExhibitName();
    const std::string& get_cdm0MediaType();
    const std::string& get_cdm0OfficePriResp();
    int get_cdm0OPRNotifDueOffset();
    int get_cdm0ResponseDueOffset();
    bool get_cdm0ShippingDocumentReqd();
    bool get_cdm0SubmitFlowThru();
    const std::string& get_cdm0SubmitPurpose();
    int get_cdm0SubmitQuantity();
    Teamcenter::Soa::Common::AutoPtr<CompanyContact> get_cdm0Addressee();
    const std::string& get_cdm0ApprovalCode();
    const std::string& get_cdm0DRISubTitle();
    Teamcenter::Soa::Common::AutoPtr<Fnd0StaticTable> get_cdm0EventList();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cdm0ListsDRISubmittalSch();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cdm0IsDescribedbyDID();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cdm0DataReqItemHasSubmital();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cdm0DataReqItemHasContract();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0DataReqItemRevision")

   virtual ~Cdm0DataReqItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
