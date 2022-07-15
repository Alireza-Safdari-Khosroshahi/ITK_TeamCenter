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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0PARTPROCUREMENTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0PARTPROCUREMENTPROXY_HXX

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


class TCSOACBAMODELMNGD_API Cba0PartProcurementProxy : public Teamcenter::Soa::Client::Model::Cba0ProcurementProxy
{
public:
    const std::string& get_cba0PARTPROCUREMENTTUID_UPartProcurement();
    int get_cba0PARTPROCUREMENTSEQUENCE_UPartProcurement();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_UPartProcurement();
    const std::string& get_cba0INCORPORATIONPACKAGEID_UPartProcurement();
    const std::string& get_cba0INCORPORATIONCHANGEITEMTYPE_UPartProcurement();
    const std::string& get_cba0EXPIRATIONPACKAGEID_UPartProcurement();
    const std::string& get_cba0EXPIRATIONCHANGEITEMTYPE_UPartProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0ACTUALINCORPORATIONDATE_UPartProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0ACTUALEXPIRATIONDATE_UPartProcurement();
    const std::string& get_cba0CODINAUTHORIZATION_UPartProcurement();
    const std::string& get_cba0CODOUTAUTHORIZATION_UPartProcurement();
    const std::string& get_cba0PARTPROCUREMENTMATURITY_UPartProcurement();
    int get_cba0WIPSEQUENCE_UPartProcurement();
    int get_cba0WIPCOUNT_UPartProcurement();
    int get_cba0CONSISTENCYSTAMP_UPartProcurement();
    const std::string& get_cba0HISTORY_UPartProcurement();
    const std::string& get_cba0PARTPROCUREMENTPRIMARYSTREAM_UPartProcurement();
    const std::string& get_cba0BUSINESSKEYTUID_UPartProcurement();
    const std::string& get_cba0IMPRECISEREFERENCETUID_UPartProcurement();
    const std::string& get_cba0RECORDGROUP1TUID_UPartProcurement();
    const std::string& get_cba0RECORDGROUP2TUID_UPartProcurement();
    const std::string& get_cba0RECORDSTATE_UPartProcurement();
    const std::string& get_cba0PARTKEY02_UPartNumber();
    const std::string& get_cba0PARTKEY03_UPartNumber();
    const std::string& get_cba0MASTERCORPGROUP_UCorpGroup();
    const std::string& get_cba0EFFECTIVEOUTAUTHORIZATION_UPartMaster();
    const std::string& get_cba0PARTMASTERPRIMARYSTREAM_UPartMaster();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0WIPGROUPIDORAUTHORIZATION_UAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEID_UAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEINTENT_UWorkPackage();
    const std::string& get_cba0AUTHORIZATION__UAuthorization();
    const std::string& get_cba0AUTHORIZATIONTYPE_UAuthorization();
    const std::string& get_cba0REASON_UAuthorization();
    const std::string& get_cba0WIPGROUPIDORAUTHORIZATION_UOutAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEID_UOutAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEINTENT_UOutWorkPackage();
    const std::string& get_cba0AUTHORIZATION__UOutAuthorization();
    const std::string& get_cba0AUTHORIZATIONTYPE_UOutAuthorization();
    const std::string& get_cba0AUTHORIZATIONSTATE_UOutAuthorization();
    const std::string& get_cba0REASON_UOutAuthorization();
    const std::string& get_cba0WIPACTION_UPartProcurement();
    const std::string& get_cba0PARTBASE_UPartNumber();
    const std::string& get_cba0DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    const std::string& get_cba0USINGPLANT_UPartProcurement();
    const std::string& get_cba0MAKE_UPartProcurement();
    const std::string& get_cba0MAKEBUYINDICATOR_UPartProcurement();
    const std::string& get_cba0PLANNEDINCORPORATIONAUTHORIZAT_UPartProcurement();
    const std::string& get_cba0PLANNEDEXPIRATIONAUTHORIZATION_UPartProcurement();
    const std::string& get_cba0AUTHORIZATION__UPartMaster();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDINCORPORATIONDATE_UPartProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0PLANNEDEXPIRATIONDATE_UPartProcurement();
    int get_cba0PARTPROCUREMENTID_UPartProcurement();
    int get_cba0PARTID_UPartProcurement();
    int get_cba0VERSIONNUMBER_UPartProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartProcurement();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartProcurement();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartProcurement();
    const std::string& get_cba0CREATIONUSER_UPartProcurement();
    const std::string& get_cba0CHANGESTATUS_UPartProcurement();
    const std::string& get_cba0WIPSYSTEMGROUP_UPartProcurement();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0RpsRpdByGroupId();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0PartProcurementProxy")

   virtual ~Cba0PartProcurementProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
