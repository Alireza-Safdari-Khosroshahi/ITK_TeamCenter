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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOFPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOFPROXY_HXX

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


class TCSOACBAMODELMNGD_API Cba0LOFProxy : public Teamcenter::Soa::Client::Model::Cba0PersistentProxy
{
public:
    const std::string& get_relation();
    const std::string& get_cba0LOFTUID_ULineOfFabrication();
    int get_cba0LOFSEQUENCE_ULineOfFabrication();
    int get_cba0UPPERPARTRPGRPDGROUPID_ULineOfFabrication();
    int get_cba0LOWERPARTRPGRPDGROUPID_ULineOfFabrication();
    const std::string& get_cba0REASON_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEINPOINT_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEINPACKAGEID_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEOUTPOINT_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEOUTPACKAGEID_ULineOfFabrication();
    float get_cba0LOWERPARTSYSTEMQUANTITY_ULineOfFabrication();
    const std::string& get_cba0LOWERPARTSYSTEMUNITOFMEASURE_ULineOfFabrication();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP1TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP2TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP3TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP4TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP5TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP6TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP7TUID_ULineOfFabrication();
    const std::string& get_cba0RECORDGROUP8TUID_ULineOfFabrication();
    const std::string& get_cba0WIPSYSTEMGROUP_ULineOfFabrication();
    int get_cba0WIPSEQUENCE_ULineOfFabrication();
    int get_cba0WIPCOUNT_ULineOfFabrication();
    int get_cba0CONSISTENCYSTAMP_ULineOfFabrication();
    const std::string& get_cba0HISTORY_ULineOfFabrication();
    const std::string& get_cba0DEFAULTLNG_ULineOfFabrication();
    const std::string& get_cba0PROTOTYPESTOCKDISPOSITION_ULineOfFabrication();
    const std::string& get_cba0HIGHESTPROJECTMATURITY_ULineOfFabrication();
    int get_cba0VERSIONNUMBER_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEINCHANGEITEMTYPE_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEOUTCHANGEITEMTYPE_ULineOfFabrication();
    const std::string& get_cba0PARTTUID_UUpperPartMaster();
    int get_cba0PARTID_UUpperPartMaster();
    int get_cba0PARTSEQUENCE_UUpperPartMaster();
    const std::string& get_cba0PARTNUMBERTUID_UUpperPartMaster();
    const std::string& get_cba0PARTNUMBERTUIDINDICATOR_UUpperPartMaster();
    const std::string& get_cba0PARTNOMENCLATURETUID_UUpperPartMaster();
    const std::string& get_cba0PARTTYPE_UUpperPartMaster();
    const std::string& get_cba0PARTIDENTIFIER_UUpperPartMaster();
    const std::string& get_cba0PARTMATURITY_UUpperPartMaster();
    const std::string& get_cba0ASSEMBLYINDICATOR_UUpperPartMaster();
    const std::string& get_cba0NOMATHINDICATOR_UUpperPartMaster();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UUpperPartMaster();
    int get_cba0MATHID_UUpperPartMaster();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UUpperPartMaster();
    const std::string& get_cba0NODRAWINGINDICATOR_UUpperPartMaster();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UUpperPartMaster();
    int get_cba0DRAWINGID_UUpperPartMaster();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UUpperPartMaster();
    const std::string& get_cba0LESSFINISHINDICATOR_UUpperPartMaster();
    const std::string& get_cba0COLORINDICATOR_UUpperPartMaster();
    const std::string& get_cba0MADEFROMPARTTUID_UUpperPartMaster();
    const std::string& get_cba0MADEFROMPARTBASE_UUpperPartMaster();
    const std::string& get_cba0MADEFROMPARTKEY03_UUpperPartMaster();
    const std::string& get_cba0MADEFROMPARTKEY02_UUpperPartMaster();
    const std::string& get_cba0NONPREFERRED_UUpperPartMaster();
    const std::string& get_cba0DISPLAYUNITOFMEASURE_UUpperPartMaster();
    const std::string& get_cba0PARTFAMILY_UUpperPartMaster();
    const std::string& get_cba0BESTCOSTMATURITY_UUpperPartMaster();
    int get_cba0BESTCOST_UUpperPartMaster();
    const std::string& get_cba0BESTMASSMATURITY_UUpperPartMaster();
    int get_cba0BESTMASSQUANTITY_UUpperPartMaster();
    const std::string& get_cba0AUTHORIZATION__UUpperPartMaster();
    const std::string& get_cba0PACKAGEID_UUpperPartMaster();
    const std::string& get_cba0MOSTRECENTPURGEDREFERENCEYEAR_UUpperPartMaster();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_UUpperPartMaster();
    const std::string& get_cba0NOMENCLATURETUID_UUpperPartNomenclatureTUID();
    const std::string& get_cba0PARTNOMENCLATURETUID_UUpperPartNomenclature();
    const std::string& get_cba0NUMBERNAMESPACE_UUpperPartNomenclature();
    const std::string& get_cba0DEFAULTLNG_UUpperPartNomenclature();
    const std::string& get_cba0DEFAULTPARTNAME_UUpperPartNomenclature();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UUpperPartNomenclature();
    const std::string& get_cba0NOMENCLATURETUID_UUpperPartNomenclatureText();
    const std::string& get_cba0NUMBERNAMESPACE_UUpperPartNomenclatureText();
    const std::string& get_cba0LNG_UUpperPartNomenclatureText();
    const std::string& get_cba0PARTNAME_UUpperPartNomenclatureText();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UUpperPartNomenclatureText();
    const std::string& get_cba0PARTNUMBERTUID_UUpperPartNumber();
    const std::string& get_cba0NUMBERNAMESPACE_UUpperPartNumber();
    const std::string& get_cba0SYSTEMGENERATED_UUpperPartNumber();
    const std::string& get_cba0ALTERNATEREPRESENTATION_UUpperPartNumber();
    const std::string& get_cba0DEFAULTSORTCRITERA_UUpperPartNumber();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UUpperPartNumber();
    const std::string& get_cba0CORPGROUPTUID_URespCorpGroup();
    const std::string& get_cba0CORPGROUP_URespCorpGroup();
    const std::string& get_cba0CORPGROUPTYPE_URespCorpGroup();
    const std::string& get_cba0DEFAULTLNG_URespCorpGroup();
    const std::string& get_cba0NAME_URespCorpGroup();
    const std::string& get_cba0PARTTUID_UPartMaster();
    int get_cba0PARTID_UPartMaster();
    int get_cba0PARTSEQUENCE_UPartMaster();
    const std::string& get_cba0PARTNUMBERTUID_UPartMaster();
    const std::string& get_cba0PARTNUMBERTUIDINDICATOR_UPartMaster();
    const std::string& get_cba0PARTNOMENCLATURETUID_UPartMaster();
    const std::string& get_cba0PARTIDENTIFIER_UPartMaster();
    const std::string& get_cba0PARTTYPE_UPartMaster();
    const std::string& get_cba0PARTMATURITY_UPartMaster();
    const std::string& get_cba0ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_cba0NOMATHINDICATOR_UPartMaster();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UPartMaster();
    int get_cba0MATHID_UPartMaster();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    int get_cba0DRAWINGID_UPartMaster();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0MADEFROMPARTTUID_UPartMaster();
    const std::string& get_cba0MADEFROMPARTKEY03_UPartMaster();
    const std::string& get_cba0MADEFROMPARTKEY02_UPartMaster();
    const std::string& get_cba0NONPREFERRED_UPartMaster();
    const std::string& get_cba0DISPLAYUNITOFMEASURE_UPartMaster();
    const std::string& get_cba0PARTFAMILY_UPartMaster();
    const std::string& get_cba0AUTHORIZATION__UPartMaster();
    const std::string& get_cba0PACKAGEID_UPartMaster();
    const std::string& get_cba0MOSTRECENTPURGEDREFERENCEYEAR_UPartMaster();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_UPartMaster();
    const std::string& get_cba0NOMENCLATURETUID_UPartNomenclatureTUID();
    const std::string& get_cba0PARTNOMENCLATURETUID_UPartNomenclature();
    const std::string& get_cba0DEFAULTLNG_UPartNomenclature();
    const std::string& get_cba0DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNomenclature();
    const std::string& get_cba0NOMENCLATURETUID_UPartNomenclatureText();
    const std::string& get_cba0NUMBERNAMESPACE_UPartNomenclatureText();
    const std::string& get_cba0LNG_UPartNomenclatureText();
    const std::string& get_cba0PARTNAME_UPartNomenclatureText();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNomenclatureText();
    const std::string& get_cba0NUMBERNAMESPACE_UPartNumber();
    const std::string& get_cba0PARTNUMBERTUID_UPartNumber();
    const std::string& get_cba0SYSTEMGENERATED_UPartNumber();
    const std::string& get_cba0ALTERNATEREPRESENTATION_UPartNumber();
    const std::string& get_cba0DEFAULTSORTCRITERA_UPartNumber();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNumber();
    const std::string& get_cba0CORPGROUPTUID_UCorpGroup();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0DEFAULTLNG_UCorpGroup();
    const std::string& get_cba0NAME_UCorpGroup();
    const std::string& get_cba0AUTHORIZATIONANDPACKAGETUID_UAuthorizationAndPackage();
    const std::string& get_cba0WIPGROUPIDORAUTHORIZATION_UAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEID_UAuthorizationAndPackage();
    const std::string& get_cba0AUTHORIZATION__UAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEID_UWorkPackage();
    const std::string& get_cba0PACKAGEINTENT_UWorkPackage();
    const std::string& get_cba0STATE_UWorkPackage();
    int get_cba0CONCURRENCYCOUNT_UWorkPackage();
    const std::string& get_cba0LOCKINDICATOR_UWorkPackage();
    const std::string& get_cba0ERR_INFO_UWorkPackage();
    const std::string& get_cba0AUTHORIZATION__UAuthorization();
    const std::string& get_cba0TYPE__UAuthorization();
    const std::string& get_cba0AUTH01_UAuthorization();
    const std::string& get_cba0AUTH02_UAuthorization();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const std::string& get_cba0CORPGROUPTUID_UAuthorization();
    const std::string& get_cba0CHANGEDESCRIPTION_UAuthorization();
    const Teamcenter::Soa::Common::DateTime& get_cba0CHANGEDATE_UAuthorization();
    const std::string& get_cba0AUTHORIZATIONTYPE_UAuthorization();
    const std::string& get_cba0AUTHORIZATIONANDPACKAGETUID_UOutAuthorizationAndPackage();
    const std::string& get_cba0WIPGROUPIDORAUTHORIZATION_UOutAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEID_UOutAuthorizationAndPackage();
    const std::string& get_cba0AUTHORIZATION__UOutAuthorizationAndPackage();
    const std::string& get_cba0PACKAGEID_UOutWorkPackage();
    const std::string& get_cba0PACKAGEINTENT_UOutWorkPackage();
    const std::string& get_cba0STATE_UOutWorkPackage();
    int get_cba0CONCURRENCYCOUNT_UOutWorkPackage();
    const std::string& get_cba0LOCKINDICATOR_UOutWorkPackage();
    const std::string& get_cba0ERR_INFO_UOutWorkPackage();
    const std::string& get_cba0AUTHORIZATION__UOutAuthorization();
    const std::string& get_cba0TYPE__UOutAuthorization();
    const std::string& get_cba0AUTH01_UOutAuthorization();
    const std::string& get_cba0AUTH02_UOutAuthorization();
    const std::string& get_cba0AUTHORIZATIONSTATE_UOutAuthorization();
    const std::string& get_cba0CORPGROUPTUID_UOutAuthorization();
    const std::string& get_cba0CHANGEDESCRIPTION_UOutAuthorization();
    const Teamcenter::Soa::Common::DateTime& get_cba0CHANGEDATE_UOutAuthorization();
    const std::string& get_cba0AUTHORIZATIONTYPE_UOutAuthorization();
    int get_cba0SOURCEITEMID_ULOFDerivedFrom();
    const std::string& get_cba0REASON_UReason();
    const std::string& get_cba0DEFAULTLNG_UReason();
    int get_cba0REPLACESREPLACEDBYGROUPID_UUpperPartMaster();
    int get_cba0REPLACESREPLACEDBYGROUPID_UPartMaster();
    const std::string& get_cba0WIPACTION_ULineOfFabrication();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    const std::string& get_cba0LOFDESCRIPTION_ULineOfFabrication();
    int get_cba0LOWERPARTQUANTITY_ULineOfFabrication();
    const std::string& get_cba0LOWERPARTUNITOFMEASURE_ULineOfFabrication();
    const std::string& get_cba0LOFMATURITY_ULineOfFabrication();
    const std::string& get_cba0MASTERCORPGROUP_UCorpGroup();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_ULineOfFabrication();
    const std::string& get_cba0STOCKDISPOSITION_ULineOfFabrication();
    const std::string& get_cba0DEFAULTDESCRIPTION_UReason();
    const std::string& get_cba0SERVICESTOCKDISPOSITION_ULineOfFabrication();
    const std::string& get_cba0LESSFINISHINDICATOR_UPartMaster();
    const std::string& get_cba0COLORINDICATOR_UPartMaster();
    const std::string& get_cba0PARTFINISH_UPartMaster();
    const std::string& get_cba0MADEFROMPARTBASE_UPartMaster();
    int get_cba0LOFID_ULineOfFabrication();
    const std::string& get_cba0CHANGESTATUS_ULineOfFabrication();
    int get_cba0LOF_LEVEL_ULineOfFabrication();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_ULineOfFabrication();
    const std::string& get_cba0CREATIONUSER_ULineOfFabrication();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_ULineOfFabrication();
    const std::string& get_cba0LASTMODIFIEDUSER_ULineOfFabrication();
    const std::string& get_cba0EFFECTIVEOUTAUTHORIZATION_ULineOfFabrication();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0UpperPartBase();
    const std::string& get_cba0UpperPartKey02();
    const std::string& get_cba0UpperPartKey03();
    const std::string& get_cba0LowerPartBase();
    const std::string& get_cba0LowerPartKey02();
    const std::string& get_cba0LowerPartKey03();
    const std::string& get_cba0PartVersionNumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0LOFProxy")

   virtual ~Cba0LOFProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
