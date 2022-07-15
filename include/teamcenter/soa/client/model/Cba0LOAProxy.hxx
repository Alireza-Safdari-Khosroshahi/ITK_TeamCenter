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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOAPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOAPROXY_HXX

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


class TCSOACBAMODELMNGD_API Cba0LOAProxy : public Teamcenter::Soa::Client::Model::Cba0PersistentProxy
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_next_up_act();
    const Teamcenter::Soa::Client::ModelObjectVector& get_next_down_act();
    const std::string& get_relation();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_ULineOfAssembly();
    int get_cba0P2PID_UPartToPart();
    const std::string& get_cba0ASSEMBLYPARTTUID_UPartToPart();
    const std::string& get_cba0PARTAPPLICATIONTUID_UAsmPartApplication();
    int get_cba0P2POCCURRENCEID_UPartToPart();
    int get_cba0PARTSEQUENCE_UAsmPartMaster();
    const std::string& get_cba0STATE_UWorkPackage();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UAsmPartMaster();
    int get_cba0DRAWINGID_UPartMaster();
    const std::string& get_cba0NOMATHINDICATOR_UPartMaster();
    const std::string& get_cba0NONPREFERRED_UAsmPartMaster();
    int get_cba0ASSEMBLYSEQUENCE_UPartToPart();
    const std::string& get_cba0PARTITIONVALUE_UUsageAddressToPartition();
    const std::string& get_cba0USAGEADDRESS02_UAsmUsageAddress();
    const std::string& get_cba0COMPONENTPARTAPPLICATIONTUID_ULineOfAssembly();
    const std::string& get_cba0ASSEMBLYUAPREFIX_ULineOfAssembly();
    int get_cba0PARTSEQUENCE_UPartMaster();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0AUTHORIZATIONTYPE_UAuthorization();
    const std::string& get_cba0EFFECTIVEINPOINT_ULineOfAssembly();
    const std::string& get_cba0DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_cba0PARTTOPARTTUID_ULineOfAssembly();
    const std::string& get_cba0DEFAULTDESCRIPTION_UReason();
    const std::string& get_cba0CORPGROUP_URespCorpGroup();
    const std::string& get_cba0AUTHORIZATIONANDPACKAGETUID_UAuthorizationAndPackage();
    const std::string& get_cba0TYPE__UAuthorization();
    const std::string& get_cba0AUTH01_UAuthorization();
    const std::string& get_cba0COMPONENTPARTTUID_ULineOfAssembly();
    const std::string& get_cba0COMPONENTPARTTUID_UPartToPart();
    const std::string& get_cba0NOMATHREQUIREDINDICATOR_UUsageAddress();
    const std::string& get_cba0NAME_UCorpGroup();
    const std::string& get_cba0PACKAGEID_UAuthorizationAndPackage();
    const std::string& get_cba0COMPONENTUNITOFMEASURE_UPartToPart();
    const std::string& get_cba0LOAMATURITY_ULineOfAssembly();
    const std::string& get_cba0PARTITIONVALUE_UAsmUsageAddressToPartition();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    int get_cba0P2PSEQUENCE_UPartToPart();
    int get_cba0PARTID_UPartMaster();
    int get_cba0PARTID_UAsmPartMaster();
    const std::string& get_cba0CHANGESTATUS_ULineOfAssembly();
    const std::string& get_cba0NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_cba0PACKAGEINTENT_UWorkPackage();
    int get_cba0CONSISTENCYSTAMP_ULineOfAssembly();
    int get_cba0ASSEMBLYSEQUENCE_ULineOfAssembly();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNomenclatureText();
    const std::string& get_cba0PARTFAMILY_UAsmPartMaster();
    const std::string& get_cba0PARTTUID_UAsmPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_ULineOfAssembly();
    const std::string& get_cba0COLORINDICATOR_UPartMaster();
    const std::string& get_cba0MATHVALIDATIONSTATUS_ULineOfAssembly();
    const std::string& get_cba0PARTAPPLICATIONTUID_UPartApplication();
    const std::string& get_cba0PARTMATURITY_UPartMaster();
    const std::string& get_cba0DEFAULTPARTNAME_UAsmPartNomenclature();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0PARTTOPARTTUID_UPartToPart();
    const std::string& get_cba0COMPONENTHANDCODE_UPartToPart();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UAsmPartMaster();
    const std::string& get_cba0PARTTYPE_UAsmPartMaster();
    const std::string& get_cba0DEFAULTDESCRIPTION_UAsmUsageAddress();
    const std::string& get_cba0COMPONENTALPHAQUANTITY_UPartToPart();
    const std::string& get_cba0ALTERNATEREP_UUAMajor();
    int get_cba0LOAOVERRIDEID_ULineOfAssembly();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UAsmPartMaster();
    const std::string& get_cba0AUTH02_UAuthorization();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UAsmPartMaster();
    const std::string& get_cba0STOCKDISPOSITION_ULineOfAssembly();
    const std::string& get_cba0ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_cba0LOATUID_ULineOfAssembly();
    const std::string& get_cba0COMPONENTUAPREFIX_ULineOfAssembly();
    const std::string& get_cba0P2PMATURITY_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_ULineOfAssembly();
    const std::string& get_cba0DISPLAYUNITOFMEASURE_UAsmPartMaster();
    const std::string& get_cba0CREATIONUSER_ULineOfAssembly();
    const std::string& get_cba0ASSEMBLYPARTAPPLICATIONTUID_ULineOfAssembly();
    const std::string& get_cba0BOMVALIDATIONSTATUS_ULineOfAssembly();
    const std::string& get_cba0LESSFINISHINDICATOR_UPartMaster();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const std::string& get_cba0NODRAWINGINDICATOR_UAsmPartMaster();
    const std::string& get_cba0USAGEADDRESS01_UAsmUsageAddress();
    int get_cba0LOAID_ULineOfAssembly();
    const std::string& get_cba0FINALASSEMBLYINDICATOR_ULineOfAssembly();
    const std::string& get_cba0PARTTUID_UPartMaster();
    const std::string& get_cba0PARTFAMILY_UPartMaster();
    const std::string& get_cba0LOAFORMFITFUNCTIONINDICATOR_ULineOfAssembly();
    const std::string& get_cba0LOACOMPLETEBK_ULineOfAssembly();
    const std::string& get_cba0CHANGEDESCRIPTION_UAuthorization();
    const std::string& get_cba0ASSEMBLYPARTTUID_ULineOfAssembly();
    const std::string& get_cba0PARTTYPE_UPartMaster();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0WIPGROUPIDORAUTHORIZATION_UAuthorizationAndPackage();
    const std::string& get_cba0NOMATHREQUIREDINDICATOR_UAsmUsageAddress();
    int get_cba0P2P_LEVEL_UPartToPart();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0ALTERNATEREP_UAsmUAMajor();
    const std::string& get_cba0DEFAULTLNG_UCorpGroup();
    int get_cba0CONCURRENCYCOUNT_UWorkPackage();
    const std::string& get_cba0DEFAULTDESCRIPTION_UUsageAddress();
    const std::string& get_cba0MOSTRECENTPURGEDREFERENCEYEAR_UAsmPartMaster();
    const std::string& get_cba0PARTFINISH_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CHANGEDATE_UAuthorization();
    const std::string& get_cba0CORPGROUPTUID_UAuthorization();
    const std::string& get_cba0LOCKINDICATOR_UWorkPackage();
    const std::string& get_cba0USAGEADDRESSTUID_UUsageAddress();
    const std::string& get_cba0MOSTRECENTPURGEDREFERENCEYEAR_UPartMaster();
    const std::string& get_cba0ASSEMBLYINDICATOR_UAsmPartMaster();
    const std::string& get_cba0LASTMODIFIEDUSER_ULineOfAssembly();
    const std::string& get_cba0NOMATHINDICATOR_UAsmPartMaster();
    const std::string& get_cba0PARTNUMBERTUID_UAsmPartNumber();
    const std::string& get_cba0PARTMATURITY_UAsmPartMaster();
    int get_cba0LOASEQUENCE_ULineOfAssembly();
    int get_cba0LOA_LEVEL_ULineOfAssembly();
    const std::string& get_cba0_ComponentQuantity();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0MasterCorpGroup();
    const std::string& get_cba0RpsRpdByGroupIdAsm();
    const std::string& get_cba0RpsRpdByGroupIdCmpPart();
    const std::string& get_cba0AssemblyPartBase();
    const std::string& get_cba0ComponentPartBase();
    const std::string& get_cba0ComponentUsageAddress01();
    const std::string& get_cba0ComponentUsageAddress02();
    const std::string& get_cba0AssemblyPartKey03();
    const std::string& get_cba0AssemblyPartKey02();
    const std::string& get_cba0ComponentPartKey03();
    const std::string& get_cba0ComponentPartKey02();
    const std::string& get_cba0PartVersionNumber();
    const Teamcenter::Soa::Common::DateTime& get_cba0PRODEFFECTIVEINDATE();
    const Teamcenter::Soa::Common::DateTime& get_cba0PRODEFFECTIVEOUTDATE();
    const Teamcenter::Soa::Common::DateTime& get_cba0VIRTEFFECTIVEINDATE();
    const Teamcenter::Soa::Common::DateTime& get_cba0VIRTEFFECTIVEOUTDATE();
    const Teamcenter::Soa::Common::DateTime& get_cba0PROTOEFFECTIVEINDATE();
    const Teamcenter::Soa::Common::DateTime& get_cba0PROTOEFFECTIVEOUTDATE();
    const std::string& get_cba0Version_ULineOfAssembly();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0LOAProxy")

   virtual ~Cba0LOAProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
