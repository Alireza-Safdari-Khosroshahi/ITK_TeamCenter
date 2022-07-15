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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARTTOPARTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARTTOPARTPROXY_HXX

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


class TCSOACBAMODELMNGD_API PartToPartProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    const std::string& get_cba0BUSINESSKEYTUID_UPartToPart();
    const std::string& get_cba0EFFECTIVEINCHANGEITEMTYPE_UPartToPart();
    const std::string& get_cba0EFFECTIVEOUTCHANGEITEMTYPE_UPartToPart();
    const std::string& get_cba0IMPRECISEREFERENCETUID_UPartToPart();
    const std::string& get_cba0JOBNUMBERDELETE_UPartToPart();
    const std::string& get_cba0JOBNUMBER_UPartToPart();
    const std::string& get_cba0PRIMARYSTREAM_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0PRODUCTIONEFFECTIVEINDATE_UPartToPart();
    const std::string& get_cba0PRODUCTIONEFFECTIVEINPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0PRODUCTIONEFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_cba0PRODUCTIONEFFECTIVEOUTPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0PROTOTYPEEFFECTIVEINDATE_UPartToPart();
    const std::string& get_cba0PROTOTYPEEFFECTIVEINPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0PROTOTYPEEFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_cba0PROTOTYPEEFFECTIVEOUTPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0VIRTUALBUILDEFFECTIVEINDATE_UPartToPart();
    const std::string& get_cba0VIRTUALBUILDEFFECTIVEINPOINT_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0VIRTUALBUILDEFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_cba0VIRTUALBUILDEFFECTIVEOUTPOINT_UPartToPart();
    const Teamcenter::Soa::Client::ModelObjectVector& get_next_up_act();
    const Teamcenter::Soa::Client::ModelObjectVector& get_next_down_act();
    bool get_is_modifiable();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const std::string& get_checked_out();
    const std::string& get_last_mod_date();
    const std::string& get_object_type();
    const std::string& get_owning_group();
    const std::string& get_owning_user();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    const std::string& get_cba0EFFECTIVEOUTPOINT_UPartToPart();
    const std::string& get_cba0EFFECTIVEINPACKAGEID_UPartToPart();
    const std::string& get_cba0ASSEMBLYPARTTUID_UPartToPart();
    int get_cba0P2PID_UPartToPart();
    int get_cba0P2POCCURRENCEID_UPartToPart();
    const std::string& get_cba0COMPONENTSYSTEMUNITOFMEASURE_UPartToPart();
    const std::string& get_cba0GOV_CLASSIFICATION_UPartToPart();
    const std::string& get_cba0FUTURE_TXT_2_UPartToPart();
    const std::string& get_cba0HISTORY_UPartToPart();
    int get_cba0WIPCOUNT_UPartToPart();
    const std::string& get_cba0EFFECTIVEOUTAUTHORIZATION_UPartToPart();
    const std::string& get_cba0EFFECTIVEOUTPACKAGEID_UPartToPart();
    int get_cba0ASSEMBLYSEQUENCE_UPartToPart();
    const std::string& get_cba0P2PMATURITY_UPartToPart();
    int get_cba0FUTURE_NUM_4_UPartToPart();
    int get_cba0COMPONENTQUANTITY_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UPartToPart();
    const std::string& get_cba0CREATIONUSER_UPartToPart();
    const std::string& get_cba0RECORDGROUP1TUID_UPartToPart();
    const std::string& get_cba0EFFECTIVEINPOINT_UPartToPart();
    const std::string& get_cba0RECORDGROUP2TUID_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0EFFECTIVEOUTDATE_UPartToPart();
    const std::string& get_cba0RECORDGROUP3TUID_UPartToPart();
    const std::string& get_cba0RECORDGROUP4TUID_UPartToPart();
    const std::string& get_cba0RECORDGROUP5TUID_UPartToPart();
    int get_cba0WIPSEQUENCE_UPartToPart();
    const std::string& get_cba0COMPONENTPARTTUID_UPartToPart();
    const std::string& get_cba0RECORDGROUP6TUID_UPartToPart();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_UPartToPart();
    const std::string& get_cba0RECORDGROUP7TUID_UPartToPart();
    const std::string& get_cba0SLOC_UPartToPart();
    const std::string& get_cba0COMPONENTUNITOFMEASURE_UPartToPart();
    const std::string& get_cba0RECORDGROUP8TUID_UPartToPart();
    const std::string& get_cba0FUTURE_TXT_1_UPartToPart();
    int get_cba0P2PSEQUENCE_UPartToPart();
    int get_cba0P2P_LEVEL_UPartToPart();
    const std::string& get_cba0P2PCOMPLETEBK_UPartToPart();
    const std::string& get_cba0FUTURE_TXT_3_UPartToPart();
    const std::string& get_cba0RECORDSTATE_UPartToPart();
    const std::string& get_cba0WIPACTION_UPartToPart();
    const std::string& get_cba0CHANGESTATUS_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UPartToPart();
    const std::string& get_cba0LASTMODIFIEDUSER_UPartToPart();
    double get_cba0COMPONENTSYSTEMQUANTITY_UPartToPart();
    const std::string& get_cba0COMPONENTHANDCODE_UPartToPart();
    const std::string& get_cba0PARTTOPARTTUID_UPartToPart();
    const Teamcenter::Soa::Common::DateTime& get_cba0EFFECTIVEINDATE_UPartToPart();
    const std::string& get_cba0WIPSYSTEMGROUP_UPartToPart();
    const std::string& get_cba0FINALASSEMBLYINDICATOR_UPartToPart();
    const std::string& get_cba0EFFECTIVEOUTDATETYPE_UPartToPart();
    const std::string& get_cba0EFFECTIVEINDATETYPE_UPartToPart();
    const std::string& get_cba0COMPONENTALPHAQUANTITY_UPartToPart();
    const std::string& get_cba0RpgRpdGroupIdAsmPart();
    const std::string& get_cba0RpgRpdGroupIdCmpPart();
    const std::string& get_cba0ConsistencyStamp();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PartToPartProxy")

   virtual ~PartToPartProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
