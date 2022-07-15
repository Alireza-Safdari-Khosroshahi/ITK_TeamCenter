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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ACTLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ACTLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BOMLine.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API ACTLine : public Teamcenter::Soa::Client::Model::BOMLine
{
public:
    const std::string& get_cba0_alignedMathOccs();
    const std::string& get_cba0_componentAlphaQuantity();
    const std::string& get_bl_act_ALTERNATEREP_UAsmUAMajor();
    const std::string& get_bl_act_ALTERNATEREP_UUAMajor();
    const std::string& get_bl_act_ASSEMBLYINDICATOR_UAsmPartMaster();
    const std::string& get_bl_act_ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_bl_act_ASSEMBLYPARTAPPLICATIONTUID_ULineOfAssembly();
    const std::string& get_bl_act_ASSEMBLYPARTTUID_ULineOfAssembly();
    const std::string& get_bl_act_ASSEMBLYPARTTUID_UPartToPart();
    int get_bl_act_ASSEMBLYSEQUENCE_ULineOfAssembly();
    int get_bl_act_ASSEMBLYSEQUENCE_UPartToPart();
    const std::string& get_bl_act_ASSEMBLYUAPREFIX_ULineOfAssembly();
    const std::string& get_bl_act_AUTH01_UAuthorization();
    const std::string& get_bl_act_AUTH02_UAuthorization();
    const std::string& get_bl_act_AUTHORIZATIONANDPACKAGETUID_UAuthorizationAndPackage();
    const std::string& get_bl_act_AUTHORIZATIONSTATE_UAuthorization();
    const std::string& get_bl_act_AUTHORIZATIONTYPE_UAuthorization();
    const std::string& get_bl_act_BOMVALIDATIONSTATUS_ULineOfAssembly();
    const std::string& get_bl_act_BUSINESSKEYTUID_ULineOfAssembly();
    const std::string& get_bl_act_BUSINESSKEYTUID_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_CHANGEDATE_UAuthorization();
    const std::string& get_bl_act_CHANGEDESCRIPTION_UAuthorization();
    const std::string& get_bl_act_CHANGESTATUS_ULineOfAssembly();
    const std::string& get_bl_act_COLORINDICATOR_UPartMaster();
    const std::string& get_bl_act_COMPONENTHANDCODE_UPartToPart();
    const std::string& get_bl_act_COMPONENTPARTAPPLICATIONTUID_ULineOfAssembly();
    const std::string& get_bl_act_COMPONENTPARTTUID_ULineOfAssembly();
    const std::string& get_bl_act_COMPONENTPARTTUID_UPartToPart();
    double get_bl_act_COMPONENTQUANTITY_UPartToPart();
    const std::string& get_bl_act_COMPONENTUAPREFIX_ULineOfAssembly();
    const std::string& get_bl_act_COMPONENTUNITOFMEASURE_UPartToPart();
    int get_bl_act_CONCURRENCYCOUNT_UWorkPackage();
    int get_bl_act_CONSISTENCYSTAMP_ULineOfAssembly();
    const std::string& get_bl_act_CORPGROUPTUID_UAuthorization();
    const std::string& get_bl_act_CORPGROUPTYPE_UCorpGroup();
    const std::string& get_bl_act_CORPGROUP_UCorpGroup();
    const std::string& get_bl_act_CORPGROUP_URespCorpGroup();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_CREATIONTIME_ULineOfAssembly();
    const std::string& get_bl_act_CREATIONUSER_ULineOfAssembly();
    const std::string& get_bl_act_DEFAULTDESCRIPTION_UAsmUsageAddress();
    const std::string& get_bl_act_DEFAULTDESCRIPTION_UReason();
    const std::string& get_bl_act_DEFAULTDESCRIPTION_UUsageAddress();
    const std::string& get_bl_act_DEFAULTLNG_UCorpGroup();
    const std::string& get_bl_act_DEFAULTPARTNAME_UAsmPartNomenclature();
    const std::string& get_bl_act_DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_bl_act_DEFAULTREASONFORASSIGNMENT_UPartNomenclatureText();
    const std::string& get_bl_act_DISPLAYUNITOFMEASURE_UAsmPartMaster();
    int get_bl_act_DRAWINGID_UPartMaster();
    const std::string& get_bl_act_DRAWINGTOFOLLOWINDICATOR_UAsmPartMaster();
    const std::string& get_bl_act_DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_bl_act_DRAWINGVALIDATIONSTATUS_UAsmPartMaster();
    const std::string& get_bl_act_DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_bl_act_EFFECTIVEINAUTHORIZATION_ULineOfAssembly();
    const std::string& get_bl_act_EFFECTIVEINPOINT_ULineOfAssembly();
    const std::string& get_bl_act_FINALASSEMBLYINDICATOR_ULineOfAssembly();
    const std::string& get_bl_act_JOBNUMBER_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_LASTMODIFIEDTIME_ULineOfAssembly();
    const std::string& get_bl_act_LASTMODIFIEDUSER_ULineOfAssembly();
    const std::string& get_bl_act_LESSFINISHINDICATOR_UPartMaster();
    const std::string& get_bl_act_LOACOMPLETEBK_ULineOfAssembly();
    const std::string& get_bl_act_LOAFORMFITFUNCTIONINDICATOR_ULineOfAssembly();
    int get_bl_act_LOAID_ULineOfAssembly();
    const std::string& get_bl_act_LOAMATURITY_ULineOfAssembly();
    int get_bl_act_LOAOVERRIDEID_ULineOfAssembly();
    int get_bl_act_LOASEQUENCE_ULineOfAssembly();
    const std::string& get_bl_act_LOATUID_ULineOfAssembly();
    int get_bl_act_LOA_LEVEL_ULineOfAssembly();
    const std::string& get_bl_act_LOCKINDICATOR_UWorkPackage();
    const std::string& get_bl_act_MATHTOFOLLOWINDICATOR_UAsmPartMaster();
    const std::string& get_bl_act_MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_bl_act_MATHVALIDATIONSTATUS_UAsmPartMaster();
    const std::string& get_bl_act_MATHVALIDATIONSTATUS_ULineOfAssembly();
    const std::string& get_bl_act_MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_bl_act_MOSTRECENTPURGEDREFERENCEYEAR_UAsmPartMaster();
    const std::string& get_bl_act_MOSTRECENTPURGEDREFERENCEYEAR_UPartMaster();
    const std::string& get_bl_act_NAME_UCorpGroup();
    const std::string& get_bl_act_NODRAWINGINDICATOR_UAsmPartMaster();
    const std::string& get_bl_act_NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_bl_act_NOMATHINDICATOR_UAsmPartMaster();
    const std::string& get_bl_act_NOMATHINDICATOR_UPartMaster();
    const std::string& get_bl_act_NOMATHREQUIREDINDICATOR_UAsmUsageAddress();
    const std::string& get_bl_act_NOMATHREQUIREDINDICATOR_UUsageAddress();
    const std::string& get_bl_act_NONPREFERRED_UAsmPartMaster();
    int get_bl_act_P2PID_UPartToPart();
    const std::string& get_bl_act_P2PMATURITY_UPartToPart();
    int get_bl_act_P2POCCURRENCEID_UPartToPart();
    int get_bl_act_P2PSEQUENCE_UPartToPart();
    int get_bl_act_P2P_LEVEL_UPartToPart();
    const std::string& get_bl_act_PACKAGEID_UAuthorizationAndPackage();
    const std::string& get_bl_act_PACKAGEINTENT_UWorkPackage();
    const std::string& get_bl_act_PARTAPPLICATIONTUID_UAsmPartApplication();
    const std::string& get_bl_act_PARTAPPLICATIONTUID_UPartApplication();
    const std::string& get_bl_act_PARTBASE_UAsmPartNumber();
    const std::string& get_bl_act_PARTBASE_UPartNumber();
    const std::string& get_bl_act_PARTFAMILY_UAsmPartMaster();
    const std::string& get_bl_act_PARTFAMILY_UPartMaster();
    const std::string& get_bl_act_PARTFINISH_UPartMaster();
    int get_bl_act_PARTID_UAsmPartMaster();
    const std::string& get_bl_act_PARTITIONVALUE_UAsmUsageAddressToPartition();
    const std::string& get_bl_act_PARTITIONVALUE_UUsageAddressToPartition();
    const std::string& get_bl_act_PARTKEY02_UAsmPartNumber();
    const std::string& get_bl_act_PARTKEY02_UPartNumber();
    const std::string& get_bl_act_PARTKEY03_UAsmPartNumber();
    const std::string& get_bl_act_PARTKEY03_UPartNumber();
    const std::string& get_bl_act_PARTMATURITY_UAsmPartMaster();
    const std::string& get_bl_act_PARTMATURITY_UPartMaster();
    const std::string& get_bl_act_PARTNUMBERTUID_UAsmPartNumber();
    int get_bl_act_PARTSEQUENCE_UAsmPartMaster();
    int get_bl_act_PARTSEQUENCE_UPartMaster();
    const std::string& get_bl_act_PARTTOPARTTUID_ULineOfAssembly();
    const std::string& get_bl_act_PARTTOPARTTUID_UPartToPart();
    const std::string& get_bl_act_PARTTUID_UAsmPartMaster();
    const std::string& get_bl_act_PARTTUID_UPartMaster();
    const std::string& get_bl_act_PARTTYPE_UAsmPartMaster();
    const std::string& get_bl_act_PARTTYPE_UPartMaster();
    const std::string& get_bl_act_PRIMARYSTREAM_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_PRODUCTIONEFFECTIVEINDATE_UPartToPart();
    const std::string& get_bl_act_PRODUCTIONEFFECTIVEINPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_PRODUCTIONEFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_bl_act_PRODUCTIONEFFECTIVEOUTPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_PROTOTYPEEFFECTIVEINDATE_UPartToPart();
    const std::string& get_bl_act_PROTOTYPEEFFECTIVEINPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_PROTOTYPEEFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_bl_act_PROTOTYPEEFFECTIVEOUTPOINT_UPartToPart();
    const std::string& get_bl_act_STATE_UWorkPackage();
    const std::string& get_bl_act_STOCKDISPOSITION_ULineOfAssembly();
    const std::string& get_bl_act_TYPE__UAuthorization();
    const std::string& get_bl_act_USAGEADDRESS01_UAsmUsageAddress();
    const std::string& get_bl_act_USAGEADDRESS01_UUsageAddress();
    const std::string& get_bl_act_USAGEADDRESS02_UAsmUsageAddress();
    const std::string& get_bl_act_USAGEADDRESS02_UUsageAddress();
    const std::string& get_bl_act_USAGEADDRESSTUID_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_VIRTUALBUILDEFFECTIVEINDATE_UPartToPart();
    const std::string& get_bl_act_VIRTUALBUILDEFFECTIVEINPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_VIRTUALBUILDEFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_bl_act_VIRTUALBUILDEFFECTIVEOUTPOINT_UPartToPart();
    const std::string& get_bl_act_WIPGROUPIDORAUTHORIZATION_UAuthorizationAndPackage();
    const std::string& get_bl_act_pa_ALTERNATELNG_UPartMaster();
    const std::string& get_bl_act_pa_ALTERNATEPARTNAME_UPartMaster();
    const std::string& get_bl_act_pa_ALTERNATEREPRESENTATION_UPartNumber();
    const std::string& get_bl_act_pa_APPEARANCEINDICATOR_UPartApplication();
    const std::string& get_bl_act_pa_ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_ASSEMBLYINTERCHANGEABILTIY_UPartApplication();
    const std::string& get_bl_act_pa_AUTHORIZATION__UPartApplication();
    const std::string& get_bl_act_pa_AUTHORIZATION__UPartMaster();
    const std::string& get_bl_act_pa_BESTCOSTMATURITY_UPartMaster();
    double get_bl_act_pa_BESTCOST_UPartMaster();
    const std::string& get_bl_act_pa_BESTMASSMATURITY_UPartMaster();
    double get_bl_act_pa_BESTMASSQUANTITY_UPartMaster();
    const std::string& get_bl_act_pa_BROADCAST_UPartMaster();
    const std::string& get_bl_act_pa_CHANGEITEMTYPE_UPartMaster();
    const std::string& get_bl_act_pa_CHANGESTATUS_UPartApplication();
    const std::string& get_bl_act_pa_CHANGESTATUS_UPartMaster();
    const std::string& get_bl_act_pa_COLORINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_COMMONGLOBALINDICATOR_UPartMaster();
    int get_bl_act_pa_CONSISTENCYSTAMP_UPartApplication();
    int get_bl_act_pa_CONSISTENCYSTAMP_UPartMaster();
    const std::string& get_bl_act_pa_CONTINUESERVICE_UPartApplication();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UPartApplication();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UPartNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UPartNomenclatureTUID();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UPartNomenclatureText();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_CREATIONTIME_UUsageAddress();
    const std::string& get_bl_act_pa_CREATIONUSER_UPartApplication();
    const std::string& get_bl_act_pa_CREATIONUSER_UPartMaster();
    const std::string& get_bl_act_pa_CREATIONUSER_UPartNomenclature();
    const std::string& get_bl_act_pa_CREATIONUSER_UPartNomenclatureTUID();
    const std::string& get_bl_act_pa_CREATIONUSER_UPartNomenclatureText();
    const std::string& get_bl_act_pa_CREATIONUSER_UPartNumber();
    const std::string& get_bl_act_pa_CREATIONUSER_UUsageAddress();
    const std::string& get_bl_act_pa_DEFAULTDESCRIPTION_UUsageAddress();
    const std::string& get_bl_act_pa_DEFAULTLNG_UPartNomenclature();
    const std::string& get_bl_act_pa_DEFAULTLNG_UUsageAddress();
    const std::string& get_bl_act_pa_DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_bl_act_pa_DEFAULTREASONFORASSIGNMENT_UPartNomenclature();
    const std::string& get_bl_act_pa_DEFAULTREASONFORASSIGNMENT_UPartNomenclatureText();
    const std::string& get_bl_act_pa_DEFAULTREASONFORASSIGNMENT_UPartNumber();
    const std::string& get_bl_act_pa_DEFAULTSORTCRITERA_UPartNumber();
    const std::string& get_bl_act_pa_DESCRIPTIONOFCHANGE_UPartApplication();
    double get_bl_act_pa_DIMENSIONQUANTITY_UPartMaster();
    double get_bl_act_pa_DIMENSIONSYSTEMQUANTITY_UPartMaster();
    const std::string& get_bl_act_pa_DIMENSIONSYSTEMUNITOFMEASURE_UPartMaster();
    const std::string& get_bl_act_pa_DIMENSIONUNITOFMEASURE_UPartMaster();
    const std::string& get_bl_act_pa_DIMENSION_UPartMaster();
    const std::string& get_bl_act_pa_DISPLAYUNITOFMEASURE_UPartMaster();
    int get_bl_act_pa_DRAWINGID_UPartMaster();
    const std::string& get_bl_act_pa_DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_bl_act_pa_EMISSIONSINDICATOR_UPartApplication();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_ENGINEERINGSIGNOFFCOMPLETEDATE_UPartMaster();
    const std::string& get_bl_act_pa_ENGINEERINGSIGNOFFNUMBER_UPartMaster();
    const std::string& get_bl_act_pa_FEATUREBASEDRELEASEDIND_UPartApplication();
    const std::string& get_bl_act_pa_FIRSTPROJECTUSED_UPartMaster();
    const std::string& get_bl_act_pa_FIRSTYEARUSED_UPartMaster();
    const std::string& get_bl_act_pa_FLAMEABILITYINDICATOR_UPartApplication();
    const std::string& get_bl_act_pa_FUNCTIONALREMARKS_UPartApplication();
    int get_bl_act_pa_FUTURE_NUM_4_UPartApplication();
    int get_bl_act_pa_FUTURE_NUM_4_UPartMaster();
    int get_bl_act_pa_FUTURE_NUM_4_UUsageAddress();
    const std::string& get_bl_act_pa_FUTURE_TXT_10_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_11_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_12_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_1_UPartApplication();
    const std::string& get_bl_act_pa_FUTURE_TXT_1_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_1_UUsageAddress();
    const std::string& get_bl_act_pa_FUTURE_TXT_2_UPartApplication();
    const std::string& get_bl_act_pa_FUTURE_TXT_2_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_2_UUsageAddress();
    const std::string& get_bl_act_pa_FUTURE_TXT_3_UPartApplication();
    const std::string& get_bl_act_pa_FUTURE_TXT_3_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_3_UUsageAddress();
    const std::string& get_bl_act_pa_FUTURE_TXT_5_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_6_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_7_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_8_UPartMaster();
    const std::string& get_bl_act_pa_FUTURE_TXT_9_UPartMaster();
    const std::string& get_bl_act_pa_GOV_CLASSIFICATION_UPartApplication();
    const std::string& get_bl_act_pa_GOV_CLASSIFICATION_UPartMaster();
    const std::string& get_bl_act_pa_HISTORY_UPartApplication();
    const std::string& get_bl_act_pa_HISTORY_UPartMaster();
    const std::string& get_bl_act_pa_IMPRECISEREFERENCETUID_UPartMaster();
    const std::string& get_bl_act_pa_INTERIOREXTERIORINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_KEY02REASONFORASSIGNMENT_UPartNumber();
    const std::string& get_bl_act_pa_KEY03REASONFORASSIGNMENT_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UPartApplication();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UPartNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UPartNomenclatureTUID();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UPartNomenclatureText();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_LASTMODIFIEDTIME_UUsageAddress();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UPartApplication();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UPartMaster();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UPartNomenclature();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UPartNomenclatureTUID();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UPartNomenclatureText();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UPartNumber();
    const std::string& get_bl_act_pa_LASTMODIFIEDUSER_UUsageAddress();
    const std::string& get_bl_act_pa_LESSFINISHINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_LNG_UPartNomenclatureText();
    const std::string& get_bl_act_pa_LOUSITE02_UPartApplication();
    const std::string& get_bl_act_pa_MADEFROMPARTBASE_UPartMaster();
    const std::string& get_bl_act_pa_MADEFROMPARTKEY02_UPartMaster();
    const std::string& get_bl_act_pa_MADEFROMPARTKEY03_UPartMaster();
    const std::string& get_bl_act_pa_MADEFROMPARTTUID_UPartMaster();
    const std::string& get_bl_act_pa_MATERIAL_UPartMaster();
    int get_bl_act_pa_MATHID_UPartMaster();
    const std::string& get_bl_act_pa_MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_bl_act_pa_MOSTRECENTPURGEDREFERENCEYEAR_UPartMaster();
    const std::string& get_bl_act_pa_NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_NOMATHINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_NOMATHREQUIREDINDICATOR_UUsageAddress();
    const std::string& get_bl_act_pa_NOMENCLATURETUID_UPartNomenclatureTUID();
    const std::string& get_bl_act_pa_NOMENCLATURETUID_UPartNomenclatureText();
    const std::string& get_bl_act_pa_NONPREFERRED_UPartMaster();
    const std::string& get_bl_act_pa_NUMBERNAMESPACE_UPartNomenclature();
    const std::string& get_bl_act_pa_NUMBERNAMESPACE_UPartNomenclatureText();
    const std::string& get_bl_act_pa_NUMBERNAMESPACE_UPartNumber();
    const std::string& get_bl_act_pa_OWNINGGROUP_UPartApplication();
    const std::string& get_bl_act_pa_P2POCCDOMAINTUID_UPartMaster();
    const std::string& get_bl_act_pa_PACKAGEID_UPartApplication();
    const std::string& get_bl_act_pa_PACKAGEID_UPartMaster();
    const std::string& get_bl_act_pa_PAMATURITY_UPartApplication();
    int get_bl_act_pa_PARTAPPLICATIONID_UPartApplication();
    int get_bl_act_pa_PARTAPPLICATIONSEQUENCE_UPartApplication();
    const std::string& get_bl_act_pa_PARTAPPLICATIONTUID_UPartApplication();
    const std::string& get_bl_act_pa_PARTBASE_UPartNumber();
    const std::string& get_bl_act_pa_PARTCLASS_UPartApplication();
    const std::string& get_bl_act_pa_PARTFAMILY_UPartMaster();
    const std::string& get_bl_act_pa_PARTFINISH_UPartMaster();
    int get_bl_act_pa_PARTID_UPartMaster();
    const std::string& get_bl_act_pa_PARTKEY02_UPartNumber();
    const std::string& get_bl_act_pa_PARTKEY03_UPartNumber();
    const std::string& get_bl_act_pa_PARTMATURITY_UPartMaster();
    const std::string& get_bl_act_pa_PARTNAME_UPartNomenclatureText();
    const std::string& get_bl_act_pa_PARTNOMENCLATURETEXTTUID_UPartNomenclatureText();
    const std::string& get_bl_act_pa_PARTNOMENCLATURETUID_UPartMaster();
    const std::string& get_bl_act_pa_PARTNOMENCLATURETUID_UPartNomenclature();
    const std::string& get_bl_act_pa_PARTNUMBERINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_PARTNUMBERTUIDINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_PARTNUMBERTUID_UPartMaster();
    const std::string& get_bl_act_pa_PARTNUMBERTUID_UPartNumber();
    int get_bl_act_pa_PARTSEQUENCE_UPartMaster();
    const std::string& get_bl_act_pa_PARTTUID_UPartApplication();
    const std::string& get_bl_act_pa_PARTTUID_UPartMaster();
    const std::string& get_bl_act_pa_PARTTYPE_UPartMaster();
    const std::string& get_bl_act_pa_PRODUCTCOMPLIANCESELECTIVELIST_UPartApplication();
    const std::string& get_bl_act_pa_PROTOTYPESTOCKDISPOSITION_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP1TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP1TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP2TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP2TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP3TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP3TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP4TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP4TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP5TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP5TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP6TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP6TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP7TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP7TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDGROUP8TUID_UPartApplication();
    const std::string& get_bl_act_pa_RECORDGROUP8TUID_UPartMaster();
    const std::string& get_bl_act_pa_RECORDSTATE_UPartApplication();
    const std::string& get_bl_act_pa_RECORDSTATE_UPartMaster();
    const std::string& get_bl_act_pa_RECORDSTATE_UPartNomenclature();
    const std::string& get_bl_act_pa_RECORDSTATE_UPartNomenclatureTUID();
    const std::string& get_bl_act_pa_RECORDSTATE_UPartNomenclatureText();
    const std::string& get_bl_act_pa_RECORDSTATE_UPartNumber();
    const std::string& get_bl_act_pa_RECORDSTATE_UUsageAddress();
    const std::string& get_bl_act_pa_REGULATEDPRODUCTINDICATOR_UPartApplication();
    const std::string& get_bl_act_pa_RESPONSIBLEENGINEER_UPartApplication();
    const std::string& get_bl_act_pa_RESPONSIBLEGROUPTUID_UPartMaster();
    const std::string& get_bl_act_pa_SAFETYINDICATOR_UPartApplication();
    const std::string& get_bl_act_pa_SAFETYINDICATOR_UPartMaster();
    const std::string& get_bl_act_pa_SERVICEASRELEASED_UPartApplication();
    const std::string& get_bl_act_pa_SERVICEINDICATOR_UPartApplication();
    const std::string& get_bl_act_pa_SERVICEINTERCHANGEABILITY_UPartApplication();
    const std::string& get_bl_act_pa_SERVICESTOCKDISPOSITION_UPartApplication();
    const std::string& get_bl_act_pa_SHELFLIFEMONTHS_UPartApplication();
    const std::string& get_bl_act_pa_SIMILARPARTNUMBER_UPartMaster();
    const std::string& get_bl_act_pa_SLOC_UPartApplication();
    const std::string& get_bl_act_pa_SLOC_UPartMaster();
    const std::string& get_bl_act_pa_SLOC_UPartNomenclature();
    const std::string& get_bl_act_pa_SLOC_UPartNomenclatureTUID();
    const std::string& get_bl_act_pa_SLOC_UPartNomenclatureText();
    const std::string& get_bl_act_pa_SLOC_UPartNumber();
    const std::string& get_bl_act_pa_SLOC_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_pa_STATEMENTOFREQUESTCOMPLETEDATE_UPartMaster();
    const std::string& get_bl_act_pa_STATEMENTOFREQUESTNUMBER_UPartMaster();
    const std::string& get_bl_act_pa_STOCKDISPOSITION_UPartApplication();
    const std::string& get_bl_act_pa_SYSTEMGENERATED_UPartNumber();
    double get_bl_act_pa_THICKNESSQUANTITY_UPartMaster();
    double get_bl_act_pa_THICKNESSSYSTEMQUANTITY_UPartMaster();
    const std::string& get_bl_act_pa_THICKNESSSYSTEMUNITOFMEASURE_UPartMaster();
    const std::string& get_bl_act_pa_THICKNESSUNITOFMEASURE_UPartMaster();
    const std::string& get_bl_act_pa_THICKNESS_UPartMaster();
    const std::string& get_bl_act_pa_USAGEADDRESS01_UUsageAddress();
    const std::string& get_bl_act_pa_USAGEADDRESS02_UUsageAddress();
    const std::string& get_bl_act_pa_USAGEADDRESS03_UUsageAddress();
    const std::string& get_bl_act_pa_USAGEADDRESS04_UUsageAddress();
    const std::string& get_bl_act_pa_USAGEADDRESS05_UUsageAddress();
    const std::string& get_bl_act_pa_USAGEADDRESSFAMILYTUID_UUsageAddress();
    const std::string& get_bl_act_pa_USAGEADDRESSTUID_UPartApplication();
    const std::string& get_bl_act_pa_USAGEADDRESSTUID_UUsageAddress();
    const std::string& get_bl_act_pa_WIPACTION_UPartApplication();
    const std::string& get_bl_act_pa_WIPACTION_UPartMaster();
    int get_bl_act_pa_WIPCOUNT_UPartApplication();
    int get_bl_act_pa_WIPCOUNT_UPartMaster();
    int get_bl_act_pa_WIPSEQUENCE_UPartApplication();
    int get_bl_act_pa_WIPSEQUENCE_UPartMaster();
    const std::string& get_bl_act_pa_WIPSYSTEMGROUP_UPartApplication();
    const std::string& get_bl_act_pa_WIPSYSTEMGROUP_UPartMaster();
    const std::string& get_bl_act_prt_ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_bl_act_prt_AUTHORIZATION__UPartMaster();
    const std::string& get_bl_act_prt_CHANGESTATUS_UPartMaster();
    const std::string& get_bl_act_prt_COLORINDICATOR_UPartMaster();
    int get_bl_act_prt_CONSISTENCYSTAMP_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_prt_CREATIONTIME_UPartMaster();
    const std::string& get_bl_act_prt_CREATIONUSER_UPartMaster();
    const std::string& get_bl_act_prt_DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_bl_act_prt_DISPLAYUNITOFMEASURE_UPartMaster();
    int get_bl_act_prt_DRAWINGID_UPartMaster();
    const std::string& get_bl_act_prt_DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_bl_act_prt_DRAWINGVALIDATIONSTATUS_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_prt_LASTMODIFIEDTIME_UPartMaster();
    const std::string& get_bl_act_prt_LASTMODIFIEDUSER_UPartMaster();
    const std::string& get_bl_act_prt_LESSFINISHINDICATOR_UPartMaster();
    int get_bl_act_prt_MATHID_UPartMaster();
    const std::string& get_bl_act_prt_MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_bl_act_prt_MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_bl_act_prt_NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_bl_act_prt_NOMATHINDICATOR_UPartMaster();
    const std::string& get_bl_act_prt_NUMBERNAMESPACE_UPartNumber();
    const std::string& get_bl_act_prt_PACKAGEID_UPartMaster();
    const std::string& get_bl_act_prt_PARTBASE_UPartNumber();
    const std::string& get_bl_act_prt_PARTFAMILY_UPartMaster();
    int get_bl_act_prt_PARTID_UPartMaster();
    const std::string& get_bl_act_prt_PARTKEY02_UPartNumber();
    const std::string& get_bl_act_prt_PARTKEY03_UPartNumber();
    const std::string& get_bl_act_prt_PARTMATURITY_UPartMaster();
    const std::string& get_bl_act_prt_PARTNUMBERTUIDINDICATOR_UPartMaster();
    int get_bl_act_prt_PARTSEQUENCE_UPartMaster();
    const std::string& get_bl_act_prt_PARTTUID_UPartMaster();
    const std::string& get_bl_act_prt_PARTTYPE_UPartMaster();
    const std::string& get_bl_act_prt_WIPSYSTEMGROUP_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_ua_CREATIONTIME_UUsageAddress();
    const std::string& get_bl_act_ua_CREATIONUSER_UUsageAddress();
    const std::string& get_bl_act_ua_DEFAULTDESCRIPTION_UUsageAddress();
    const std::string& get_bl_act_ua_DEFAULTLNG_UUsageAddress();
    int get_bl_act_ua_FUTURE_NUM_4_UUsageAddress();
    const std::string& get_bl_act_ua_FUTURE_TXT_1_UUsageAddress();
    const std::string& get_bl_act_ua_FUTURE_TXT_2_UUsageAddress();
    const std::string& get_bl_act_ua_FUTURE_TXT_3_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_bl_act_ua_LASTMODIFIEDTIME_UUsageAddress();
    const std::string& get_bl_act_ua_LASTMODIFIEDUSER_UUsageAddress();
    const std::string& get_bl_act_ua_NOMATHREQUIREDINDICATOR_UUsageAddress();
    const std::string& get_bl_act_ua_RECORDSTATE_UUsageAddress();
    const std::string& get_bl_act_ua_SLOC_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESS01_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESS02_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESS03_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESS04_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESS05_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESSFAMILYTUID_UUsageAddress();
    const std::string& get_bl_act_ua_USAGEADDRESSTUID_UUsageAddress();
    const std::string& get_cba0_loaVersionNumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ACTLine")

   virtual ~ACTLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
