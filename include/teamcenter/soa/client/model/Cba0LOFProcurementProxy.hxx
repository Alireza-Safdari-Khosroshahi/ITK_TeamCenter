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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOFPROCUREMENTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOFPROCUREMENTPROXY_HXX

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


class TCSOACBAMODELMNGD_API Cba0LOFProcurementProxy : public Teamcenter::Soa::Client::Model::Cba0ProcurementProxy
{
public:
    const std::string& get_cba0LOFPROCUREMENTTUID_ULOFProcurement();
    int get_cba0LOFPROCUREMENTSEQUENCE_ULOFProcurement();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_ULOFProcurement();
    const std::string& get_cba0INCORPORATIONPACKAGEID_ULOFProcurement();
    const std::string& get_cba0INCORPORATIONCHANGEITEMTYPE_ULOFProcurement();
    const std::string& get_cba0EXPIRATIONPACKAGEID_ULOFProcurement();
    const std::string& get_cba0EXPIRATIONCHANGEITEMTYPE_ULOFProcurement();
    const std::string& get_cba0CODINAUTHORIZATION_ULOFProcurement();
    const std::string& get_cba0CODOUTAUTHORIZATION_ULOFProcurement();
    const std::string& get_cba0LOFPROCUREMENTMATURITY_ULOFProcurement();
    int get_cba0WIPSEQUENCE_ULOFProcurement();
    int get_cba0WIPCOUNT_ULOFProcurement();
    int get_cba0CONSISTENCYSTAMP_ULOFProcurement();
    const std::string& get_cba0HISTORY_ULOFProcurement();
    const std::string& get_cba0BUSINESSKEYTUID_ULOFProcurement();
    const std::string& get_cba0LOFPROCUREMENTPRIMARYSTREAM_ULOFProcurement();
    const std::string& get_cba0IMPRECISEREFERENCETUID_ULOFProcurement();
    const std::string& get_cba0RECORDGROUP1TUID_ULOFProcurement();
    const std::string& get_cba0RECORDGROUP2TUID_ULOFProcurement();
    const std::string& get_cba0RECORDSTATE_ULOFProcurement();
    int get_cba0LOFID_ULineOfFabrication();
    const std::string& get_cba0WIPSYSTEMGROUP_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEINPACKAGEID_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEOUTAUTHORIZATION_ULineOfFabrication();
    const std::string& get_cba0MASTERCORPGROUP_UCorpGroup();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0WIPACTION_ULOFProcurement();
    const std::string& get_cba0PARTBASE_UPartNumber();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    const std::string& get_cba0USINGPLANT_ULOFProcurement();
    const std::string& get_cba0MAKE_ULOFProcurement();
    const std::string& get_cba0MAKEBUYINDICATOR_ULOFProcurement();
    const std::string& get_cba0PLANNEDINCORPORATIONAUTHORIZAT_ULOFProcurement();
    const std::string& get_cba0PLANNEDEXPIRATIONAUTHORIZATION_ULOFProcurement();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_ULineOfFabrication();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDINCORPORATIONDATE_ULOFProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDEXPIRATIONDATE_ULOFProcurement();
    int get_cba0LOFPROCUREMENTID_ULOFProcurement();
    int get_cba0LINEOFFABRICATIONID_ULOFProcurement();
    int get_cba0VERSIONNUMBER_ULOFProcurement();
    int get_cba0VERSIONNUMBER_ULineOfFabrication();
    int get_cba0VERSIONNUMBER_UUpperPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_ULOFProcurement();
    const std::string& get_cba0CREATIONUSER_ULOFProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_ULOFProcurement();
    const std::string& get_cba0LASTMODIFIEDUSER_ULOFProcurement();
    const std::string& get_cba0CHANGESTATUS_ULOFProcurement();
    const std::string& get_cba0WIPSYSTEMGROUP_ULOFProcurement();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0UpperPartBase();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0LOFProcurementProxy")

   virtual ~Cba0LOFProcurementProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
