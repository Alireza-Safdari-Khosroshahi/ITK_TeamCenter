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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOAPROCUREMENTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOAPROCUREMENTPROXY_HXX

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


class TCSOACBAMODELMNGD_API Cba0LOAProcurementProxy : public Teamcenter::Soa::Client::Model::Cba0ProcurementProxy
{
public:
    const std::string& get_cba0LOAPROCUREMENTTUID_ULOAProcurement();
    int get_cba0LOAPROCUREMENTSEQUENCE_ULOAProcurement();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_ULOAProcurement();
    const std::string& get_cba0INCORPORATIONPACKAGEID_ULOAProcurement();
    const std::string& get_cba0INCORPORATIONCHANGEITEMTYPE_ULOAProcurement();
    const std::string& get_cba0EXPIRATIONPACKAGEID_ULOAProcurement();
    const std::string& get_cba0EXPIRATIONCHANGEITEMTYPE_ULOAProcurement();
    const std::string& get_cba0CODINAUTHORIZATION_ULOAProcurement();
    const std::string& get_cba0CODOUTAUTHORIZATION_ULOAProcurement();
    const std::string& get_cba0LOAPROCUREMENTMATURITY_ULOAProcurement();
    int get_cba0WIPSEQUENCE_ULOAProcurement();
    int get_cba0WIPCOUNT_ULOAProcurement();
    int get_cba0CONSISTENCYSTAMP_ULOAProcurement();
    const std::string& get_cba0HISTORY_ULOAProcurement();
    const std::string& get_cba0BUSINESSKEYTUID_ULOAProcurement();
    const std::string& get_cba0LOAPROCUREMENTPRIMARYSTREAM_ULOAProcurement();
    const std::string& get_cba0IMPRECISEREFERENCETUID_ULOAProcurement();
    const std::string& get_cba0RECORDGROUP1TUID_ULOAProcurement();
    const std::string& get_cba0RECORDGROUP2TUID_ULOAProcurement();
    const std::string& get_cba0RECORDSTATE_ULOAProcurement();
    int get_cba0LOAID_ULineOfAssembly();
    const std::string& get_cba0COMPONENTUAPREFIX_ULineOfAssembly();
    const std::string& get_cba0WIPSYSTEMGROUP_ULineOfAssembly();
    int get_cba0LOAOVERRIDEID_ULineOfAssembly();
    const std::string& get_cba0ASSEMBLYUAPREFIX_ULineOfAssembly();
    const std::string& get_cba0EFFECTIVEINPACKAGEID_ULineOfAssembly();
    const std::string& get_cba0EFFECTIVEOUTAUTHORIZATION_ULineOfAssembly();
    const std::string& get_cba0MASTERCORPGROUP_UCorpGroup();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0USAGEADDRESS01_UAsmUsageAddress();
    const std::string& get_cba0USAGEADDRESS02_UAsmUsageAddress();
    const std::string& get_cba0WIPACTION_ULOAProcurement();
    const std::string& get_cba0USAGEADDRESS01_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS02_UUsageAddress();
    const std::string& get_cba0PARTBASE_UPartNumber();
    int get_cba0ASSEMBLYSEQUENCE_ULineOfAssembly();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    const std::string& get_cba0USINGPLANT_ULOAProcurement();
    const std::string& get_cba0MAKE_ULOAProcurement();
    const std::string& get_cba0MAKEBUYINDICATOR_ULOAProcurement();
    const std::string& get_cba0PLANNEDINCORPORATIONAUTHORIZAT_ULOAProcurement();
    const std::string& get_cba0PLANNEDEXPIRATIONAUTHORIZATION_ULOAProcurement();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_ULineOfAssembly();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDINCORPORATIONDATE_ULOAProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDEXPIRATIONDATE_ULOAProcurement();
    int get_cba0LOAPROCUREMENTID_ULOAProcurement();
    int get_cba0LINEOFASSEMBLYID_ULOAProcurement();
    int get_cba0VERSIONNUMBER_ULOAProcurement();
    int get_cba0VERSIONNUMBER_ULineOfAssembly();
    int get_cba0VERSIONNUMBER_UAsmPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_ULOAProcurement();
    const std::string& get_cba0LASTMODIFIEDUSER_ULOAProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_ULOAProcurement();
    const std::string& get_cba0CREATIONUSER_ULOAProcurement();
    const std::string& get_cba0CHANGESTATUS_ULOAProcurement();
    const std::string& get_cba0WIPSYSTEMGROUP_ULOAProcurement();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0AssemblyPartBase();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0LOAProcurementProxy")

   virtual ~Cba0LOAProcurementProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
