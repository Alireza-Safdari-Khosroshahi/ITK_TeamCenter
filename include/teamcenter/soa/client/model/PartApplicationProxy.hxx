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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARTAPPLICATIONPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARTAPPLICATIONPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TcUsageProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API PartApplicationProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    const std::string& get_cba0CHANGEITEMTYPE_UPartMaster();
    const std::string& get_cba0IMPRECISEREFERENCETUID_UPartMaster();
    bool get_is_modifiable();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const std::string& get_checked_out();
    const std::string& get_last_mod_date();
    const std::string& get_object_type();
    const std::string& get_owning_user();
    const std::string& get_owning_group();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    const std::string& get_cba0USAGEADDRESSTUID_UPartApplication();
    const std::string& get_cba0LOUSITE02_UPartApplication();
    const std::string& get_cba0PROTOTYPESTOCKDISPOSITION_UPartApplication();
    const std::string& get_cba0SERVICEINTERCHANGEABILITY_UPartApplication();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartMaster();
    const std::string& get_cba0DIMENSIONSYSTEMUNITOFMEASURE_UPartMaster();
    const std::string& get_cba0USAGEADDRESS02_UUsageAddress();
    int get_cba0WIPCOUNT_UPartApplication();
    const std::string& get_cba0PACKAGEID_UPartApplication();
    const std::string& get_cba0SLOC_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartApplication();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartNomenclatureTUID();
    int get_cba0DRAWINGID_UPartMaster();
    const std::string& get_cba0RECORDSTATE_UUsageAddress();
    const std::string& get_cba0PARTKEY03_UPartNumber();
    const std::string& get_cba0SLOC_UPartNomenclatureTUID();
    double get_cba0THICKNESSSYSTEMQUANTITY_UPartMaster();
    const std::string& get_cba0SERVICEINDICATOR_UPartApplication();
    const std::string& get_cba0NOMATHINDICATOR_UPartMaster();
    const std::string& get_cba0BESTCOSTMATURITY_UPartMaster();
    const std::string& get_cba0AUTHORIZATION__UPartMaster();
    const std::string& get_cba0RECORDSTATE_UPartNumber();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartNomenclature();
    const std::string& get_cba0FUTURE_TXT_11_UPartMaster();
    const std::string& get_cba0SLOC_UPartApplication();
    const std::string& get_cba0MADEFROMPARTKEY02_UPartMaster();
    double get_cba0DIMENSIONSYSTEMQUANTITY_UPartMaster();
    const std::string& get_cba0RECORDSTATE_UPartApplication();
    int get_cba0PARTSEQUENCE_UPartMaster();
    const std::string& get_cba0USAGEADDRESSFAMILYTUID_UUsageAddress();
    const std::string& get_cba0DEFAULTLNG_UPartNomenclature();
    int get_cba0BESTCOST_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UUsageAddress();
    const std::string& get_cba0LNG_UPartNomenclatureText();
    const std::string& get_cba0NUMBERNAMESPACE_UPartNomenclature();
    const std::string& get_cba0RESPONSIBLEENGINEER_UPartApplication();
    const std::string& get_cba0PARTNUMBERTUIDINDICATOR_UPartMaster();
    const std::string& get_cba0MATERIAL_UPartMaster();
    const std::string& get_cba0PARTNUMBERINDICATOR_UPartMaster();
    const std::string& get_cba0CREATIONUSER_UPartNomenclatureText();
    const std::string& get_cba0DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_cba0ALTERNATEPARTNAME_UPartMaster();
    const std::string& get_cba0HISTORY_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_2_UPartApplication();
    const std::string& get_cba0GOV_CLASSIFICATION_UPartApplication();
    const std::string& get_cba0PACKAGEID_UPartMaster();
    int get_cba0WIPCOUNT_UPartMaster();
    const std::string& get_cba0ALTERNATEREPRESENTATION_UPartNumber();
    int get_cba0PARTID_UPartMaster();
    const std::string& get_cba0FIRSTYEARUSED_UPartMaster();
    const std::string& get_cba0KEY03REASONFORASSIGNMENT_UPartNumber();
    const std::string& get_cba0PARTBASE_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartMaster();
    const std::string& get_cba0RECORDGROUP2TUID_UPartApplication();
    const std::string& get_cba0NOMATHREQUIREDINDICATOR_UUsageAddress();
    const std::string& get_cba0NUMBERNAMESPACE_UPartNumber();
    const std::string& get_cba0NOMENCLATURETUID_UPartNomenclatureText();
    const std::string& get_cba0FUTURE_TXT_8_UPartMaster();
    const std::string& get_cba0RECORDGROUP5TUID_UPartApplication();
    const std::string& get_cba0RECORDGROUP8TUID_UPartApplication();
    const std::string& get_cba0PARTNOMENCLATURETUID_UPartMaster();
    const std::string& get_cba0THICKNESSUNITOFMEASURE_UPartMaster();
    const std::string& get_cba0FEATUREBASEDRELEASEDIND_UPartApplication();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_1_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartApplication();
    const std::string& get_cba0USAGEADDRESS04_UUsageAddress();
    const std::string& get_cba0BESTMASSMATURITY_UPartMaster();
    const std::string& get_cba0SLOC_UPartNomenclature();
    const std::string& get_cba0AUTHORIZATION__UPartApplication();
    const std::string& get_cba0ASSEMBLYINTERCHANGEABILTIY_UPartApplication();
    const std::string& get_cba0NODRAWINGINDICATOR_UPartMaster();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNomenclatureText();
    const std::string& get_cba0PARTNOMENCLATURETUID_UPartNomenclature();
    const std::string& get_cba0CREATIONUSER_UPartNomenclatureTUID();
    int get_cba0WIPSEQUENCE_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_12_UPartMaster();
    const std::string& get_cba0HISTORY_UPartApplication();
    const std::string& get_cba0COLORINDICATOR_UPartMaster();
    const std::string& get_cba0MADEFROMPARTKEY03_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0STATEMENTOFREQUESTCOMPLETEDATE_UPartMaster();
    const std::string& get_cba0SLOC_UPartMaster();
    const std::string& get_cba0OWNINGGROUP_UPartApplication();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS01_UUsageAddress();
    const std::string& get_cba0FUTURE_TXT_1_UPartMaster();
    const std::string& get_cba0PARTAPPLICATIONTUID_UPartApplication();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartNomenclatureText();
    const std::string& get_cba0NOMENCLATURETUID_UPartNomenclatureTUID();
    const std::string& get_cba0RECORDSTATE_UPartMaster();
    const std::string& get_cba0PARTMATURITY_UPartMaster();
    const std::string& get_cba0CREATIONUSER_UPartNumber();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0DEFAULTLNG_UUsageAddress();
    const std::string& get_cba0FUTURE_TXT_5_UPartMaster();
    const std::string& get_cba0FIRSTPROJECTUSED_UPartMaster();
    const std::string& get_cba0CHANGESTATUS_UPartApplication();
    const std::string& get_cba0CHANGESTATUS_UPartMaster();
    const std::string& get_cba0SYSTEMGENERATED_UPartNumber();
    const std::string& get_cba0PARTCLASS_UPartApplication();
    const std::string& get_cba0NUMBERNAMESPACE_UPartNomenclatureText();
    int get_cba0PARTAPPLICATIONID_UPartApplication();
    const std::string& get_cba0SERVICEASRELEASED_UPartApplication();
    int get_cba0FUTURE_NUM_4_UUsageAddress();
    const std::string& get_cba0DESCRIPTIONOFCHANGE_UPartApplication();
    const std::string& get_cba0EMISSIONSINDICATOR_UPartApplication();
    const std::string& get_cba0BROADCAST_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_9_UPartMaster();
    const std::string& get_cba0PAMATURITY_UPartApplication();
    const std::string& get_cba0PARTNUMBERTUID_UPartNumber();
    const std::string& get_cba0REGULATEDPRODUCTINDICATOR_UPartApplication();
    const std::string& get_cba0RECORDGROUP1TUID_UPartApplication();
    const std::string& get_cba0ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_3_UUsageAddress();
    const std::string& get_cba0RECORDSTATE_UPartNomenclatureText();
    const std::string& get_cba0RECORDGROUP4TUID_UPartApplication();
    const std::string& get_cba0WIPSYSTEMGROUP_UPartMaster();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartNomenclatureTUID();
    const std::string& get_cba0RECORDGROUP7TUID_UPartApplication();
    const std::string& get_cba0WIPACTION_UPartApplication();
    const std::string& get_cba0FUTURE_TXT_3_UPartApplication();
    const std::string& get_cba0FUNCTIONALREMARKS_UPartApplication();
    const std::string& get_cba0SAFETYINDICATOR_UPartMaster();
    const std::string& get_cba0COMMONGLOBALINDICATOR_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartNomenclatureText();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartApplication();
    const std::string& get_cba0STATEMENTOFREQUESTNUMBER_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartNumber();
    const std::string& get_cba0FUTURE_TXT_2_UPartMaster();
    const std::string& get_cba0GOV_CLASSIFICATION_UPartMaster();
    const std::string& get_cba0LESSFINISHINDICATOR_UPartMaster();
    const std::string& get_cba0MADEFROMPARTBASE_UPartMaster();
    const std::string& get_cba0CREATIONUSER_UUsageAddress();
    const std::string& get_cba0USAGEADDRESS03_UUsageAddress();
    const std::string& get_cba0THICKNESSSYSTEMUNITOFMEASURE_UPartMaster();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartNumber();
    int get_cba0DIMENSIONQUANTITY_UPartMaster();
    int get_cba0PARTAPPLICATIONSEQUENCE_UPartApplication();
    const std::string& get_cba0FUTURE_TXT_6_UPartMaster();
    int get_cba0FUTURE_NUM_4_UPartMaster();
    const std::string& get_cba0SHELFLIFEMONTHS_UPartApplication();
    const std::string& get_cba0PARTTUID_UPartMaster();
    const std::string& get_cba0SIMILARPARTNUMBER_UPartMaster();
    const std::string& get_cba0PARTFAMILY_UPartMaster();
    int get_cba0CONSISTENCYSTAMP_UPartMaster();
    const std::string& get_cba0PRODUCTCOMPLIANCESELECTIVELIST_UPartApplication();
    const std::string& get_cba0RECORDSTATE_UPartNomenclature();
    const std::string& get_cba0RECORDSTATE_UPartNomenclatureTUID();
    int get_cba0WIPSEQUENCE_UPartApplication();
    const std::string& get_cba0PARTTYPE_UPartMaster();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0INTERIOREXTERIORINDICATOR_UPartMaster();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNomenclature();
    const std::string& get_cba0CREATIONUSER_UPartMaster();
    const std::string& get_cba0DIMENSION_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0ENGINEERINGSIGNOFFCOMPLETEDATE_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_1_UPartApplication();
    const std::string& get_cba0SERVICESTOCKDISPOSITION_UPartApplication();
    const std::string& get_cba0STOCKDISPOSITION_UPartApplication();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UPartMaster();
    int get_cba0BESTMASSQUANTITY_UPartMaster();
    const std::string& get_cba0RECORDGROUP1TUID_UPartMaster();
    const std::string& get_cba0NONPREFERRED_UPartMaster();
    const std::string& get_cba0RECORDGROUP2TUID_UPartMaster();
    const std::string& get_cba0ENGINEERINGSIGNOFFNUMBER_UPartMaster();
    const std::string& get_cba0DEFAULTDESCRIPTION_UUsageAddress();
    const std::string& get_cba0PARTKEY02_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartNomenclatureTUID();
    const std::string& get_cba0DISPLAYUNITOFMEASURE_UPartMaster();
    const std::string& get_cba0RECORDGROUP3TUID_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_10_UPartMaster();
    const std::string& get_cba0WIPSYSTEMGROUP_UPartApplication();
    const std::string& get_cba0PARTFINISH_UPartMaster();
    const std::string& get_cba0MADEFROMPARTTUID_UPartMaster();
    const std::string& get_cba0RECORDGROUP4TUID_UPartMaster();
    const std::string& get_cba0CREATIONUSER_UPartNomenclature();
    const std::string& get_cba0SAFETYINDICATOR_UPartApplication();
    int get_cba0MATHID_UPartMaster();
    const std::string& get_cba0RECORDGROUP5TUID_UPartMaster();
    const std::string& get_cba0PARTNUMBERTUID_UPartMaster();
    const std::string& get_cba0RECORDGROUP6TUID_UPartMaster();
    const std::string& get_cba0USAGEADDRESSTUID_UUsageAddress();
    const std::string& get_cba0PARTNOMENCLATURETEXTTUID_UPartNomenclatureText();
    const std::string& get_cba0DIMENSIONUNITOFMEASURE_UPartMaster();
    int get_cba0FUTURE_NUM_4_UPartApplication();
    const std::string& get_cba0PARTTUID_UPartApplication();
    int get_cba0CONSISTENCYSTAMP_UPartApplication();
    const std::string& get_cba0MOSTRECENTPURGEDREFERENCEYEAR_UPartMaster();
    const std::string& get_cba0RESPONSIBLEGROUPTUID_UPartMaster();
    const std::string& get_cba0RECORDGROUP7TUID_UPartMaster();
    const std::string& get_cba0DEFAULTSORTCRITERA_UPartNumber();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartNomenclatureText();
    const std::string& get_cba0CREATIONUSER_UPartApplication();
    const std::string& get_cba0CONTINUESERVICE_UPartApplication();
    const std::string& get_cba0RECORDGROUP8TUID_UPartMaster();
    const std::string& get_cba0SLOC_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartNumber();
    const std::string& get_cba0SLOC_UPartNomenclatureText();
    const std::string& get_cba0ALTERNATELNG_UPartMaster();
    int get_cba0THICKNESSQUANTITY_UPartMaster();
    const std::string& get_cba0RECORDGROUP3TUID_UPartApplication();
    const std::string& get_cba0LASTMODIFIEDUSER_UUsageAddress();
    const std::string& get_cba0KEY02REASONFORASSIGNMENT_UPartNumber();
    const std::string& get_cba0FUTURE_TXT_3_UPartMaster();
    const std::string& get_cba0RECORDGROUP6TUID_UPartApplication();
    const std::string& get_cba0WIPACTION_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_2_UUsageAddress();
    const std::string& get_cba0APPEARANCEINDICATOR_UPartApplication();
    const std::string& get_cba0P2POCCDOMAINTUID_UPartMaster();
    const std::string& get_cba0USAGEADDRESS05_UUsageAddress();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UPartNumber();
    const std::string& get_cba0PARTNAME_UPartNomenclatureText();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartMaster();
    const std::string& get_cba0FUTURE_TXT_7_UPartMaster();
    const std::string& get_cba0THICKNESS_UPartMaster();
    const std::string& get_cba0FLAMEABILITYINDICATOR_UPartApplication();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PartApplicationProxy")

   virtual ~PartApplicationProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
