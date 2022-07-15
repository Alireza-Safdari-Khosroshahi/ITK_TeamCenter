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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOUPROCUREMENTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOUPROCUREMENTPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cba0ProcurementProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API Cba0LOUProcurementProxy : public Teamcenter::Soa::Client::Model::Cba0ProcurementProxy
{
public:
    const std::string& get_cba0LOUPROCUREMENTTUID_ULOUProcurement();
    int get_cba0LOUPROCUREMENTSEQUENCE_ULOUProcurement();
    const std::string& get_cba0INCORPORATIONPACKAGEID_ULOUProcurement();
    const std::string& get_cba0INCORPORATIONCHANGEITEMTYPE_ULOUProcurement();
    const std::string& get_cba0EXPIRATIONPACKAGEID_ULOUProcurement();
    const std::string& get_cba0EXPIRATIONCHANGEITEMTYPE_ULOUProcurement();
    const std::string& get_cba0CODINAUTHORIZATION_ULOUProcurement();
    const std::string& get_cba0CODOUTAUTHORIZATION_ULOUProcurement();
    const std::string& get_cba0LOUPROCUREMENTMATURITY_ULOUProcurement();
    const std::string& get_cba0LOUPROCUREMENTPRIMARYSTREAM_ULOUProcurement();
    const std::string& get_cba0RECORDGROUP1TUID_ULOUProcurement();
    const std::string& get_cba0RECORDGROUP2TUID_ULOUProcurement();
    int get_cba0WIPSEQUENCE_ULOUProcurement();
    int get_cba0WIPCOUNT_ULOUProcurement();
    const std::string& get_cba0HISTORY_ULOUProcurement();
    const std::string& get_cba0RECORDSTATE_ULOUProcurement();
    const std::string& get_cba0MASTERCORPGROUP_UCorpGroup();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0LINEOFUSAGETUID_ULineOfUsage();
    int get_cba0LINEOFUSAGEID_ULineOfUsage();
    const std::string& get_cba0EFFECTIVEINPACKAGEID_ULineOfUsage();
    const std::string& get_cba0EFFECTIVEOUTAUTHORIZATION_ULineOfUsage();
    int get_cba0CONSISTENCYSTAMP_ULineOfUsage();
    const std::string& get_cba0CHANGESTATUS_ULineOfUsage();
    const std::string& get_cba0RECORDGROUP1TUID_ULineOfUsage();
    int get_cba0QUANTITY_ULineOfUsage();
    int get_cba0COMPLETENESSREQUIRED_ULineOfUsage();
    int get_cba0COMPLETENESSSATISFIED_ULineOfUsage();
    int get_cba0COMPLETENESSVALIDATED_ULineOfUsage();
    const std::string& get_cba0WIPACTION_ULOUProcurement();
    const std::string& get_cba0MUG01_ULineOfUsage();
    const std::string& get_cba0MUG02_ULineOfUsage();
    const std::string& get_cba0USAGEADDRESS01_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS02_UUsageAddress();
    const std::string& get_cba0PARTBASE_UPartNumber();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    const std::string& get_cba0USINGPLANT_ULOUProcurement();
    const std::string& get_cba0MAKE_ULOUProcurement();
    const std::string& get_cba0MAKEBUYINDICATOR_ULOUProcurement();
    const std::string& get_cba0PLANNEDINCORPORATIONAUTHORIZAT_ULOUProcurement();
    const std::string& get_cba0PLANNEDEXPIRATIONAUTHORIZATION_ULOUProcurement();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_ULineOfUsage();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDINCORPORATIONDATE_ULOUProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDEXPIRATIONDATE_ULOUProcurement();
    int get_cba0LOUPROCUREMENTID_ULOUProcurement();
    int get_cba0LINEOFUSAGEID_ULOUProcurement();
    int get_cba0VERSIONNUMBER_ULOUProcurement();
    int get_cba0VERSIONNUMBER_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_ULOUProcurement();
    const std::string& get_cba0CREATIONUSER_ULOUProcurement();
    const std::string& get_cba0CHANGESTATUS_ULOUProcurement();
    const std::string& get_cba0WIPSYSTEMGROUP_ULOUProcurement();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0DefaultPartName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0LOUProcurementProxy")

   virtual ~Cba0LOUProcurementProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
