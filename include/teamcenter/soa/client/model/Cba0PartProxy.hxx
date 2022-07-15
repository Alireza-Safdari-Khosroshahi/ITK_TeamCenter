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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0PARTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0PARTPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cba0PersistentProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API Cba0PartProxy : public Teamcenter::Soa::Client::Model::Cba0PersistentProxy
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Representations();
    const Teamcenter::Soa::Client::ModelObjectVector& get_next_down_act();
    const std::string& get_relation();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0NUMBERNAMESPACE_UPartNumber();
    const std::string& get_cba0PARTTYPE_UPartMaster();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartMaster();
    const std::string& get_cba0CREATIONUSER_UPartMaster();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0DISPLAYUNITOFMEASURE_UPartMaster();
    int get_cba0DRAWINGID_UPartMaster();
    const std::string& get_cba0PARTKEY02_UPartNumber();
    const std::string& get_cba0ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_cba0NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_cba0PARTKEY03_UPartNumber();
    const std::string& get_cba0AUTHORIZATION__UPartMaster();
    const std::string& get_cba0WIPSYSTEMGROUP_UPartMaster();
    const std::string& get_cba0NOMATHINDICATOR_UPartMaster();
    int get_cba0MATHID_UPartMaster();
    const std::string& get_cba0COLORINDICATOR_UPartMaster();
    int get_cba0PARTSEQUENCE_UPartMaster();
    const std::string& get_cba0LESSFINISHINDICATOR_UPartMaster();
    const std::string& get_cba0PARTNUMBERTUIDINDICATOR_UPartMaster();
    const std::string& get_cba0DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_cba0PARTMATURITY_UPartMaster();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0PACKAGEID_UPartMaster();
    const std::string& get_cba0CHANGESTATUS_UPartMaster();
    int get_cba0PARTID_UPartMaster();
    const std::string& get_cba0PARTFAMILY_UPartMaster();
    const std::string& get_cba0PARTBASE_UPartNumber();
    int get_cba0CONSISTENCYSTAMP_UPartMaster();
    const std::string& get_cba0PARTTUID_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartMaster();
    const std::string& get_cba0_AuthorizationState();
    const std::string& get_cba0PartIdentifier();
    const std::string& get_cba0DisplayName();
    const Teamcenter::Soa::Common::DateTime& get_cba0_EffectiveInDate();
    const std::string& get_cba0_EffectiveInPoint();
    const Teamcenter::Soa::Common::DateTime& get_cba0_EffectiveOutDate();
    const std::string& get_cba0_EffectiveOutPoint();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0EffOutAuthorization();
    const std::string& get_cba0MadeFromPart();
    const std::string& get_cba0CorpGroup();
    const std::string& get_cba0MasterCorpGroup();
    const std::string& get_cba0PartFinish();
    const Teamcenter::Soa::Common::DateTime& get_cba0ProdEffectiveInDate();
    const std::string& get_cba0ProdEffectiveInPoint();
    const Teamcenter::Soa::Common::DateTime& get_cba0ProdEffectiveOutDate();
    const std::string& get_cba0ProdEffectiveOutPoint();
    const std::string& get_cba0PartVersionNumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0PartProxy")

   virtual ~Cba0PartProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
