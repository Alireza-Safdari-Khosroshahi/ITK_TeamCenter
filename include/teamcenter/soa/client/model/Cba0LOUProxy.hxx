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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOUPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0LOUPROXY_HXX

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


class TCSOACBAMODELMNGD_API Cba0LOUProxy : public Teamcenter::Soa::Client::Model::Cba0PersistentProxy
{
public:
    int get_cba0LINEOFUSAGEID_ULineOfUsage();
    const std::string& get_cba0LINEOFUSAGEPRIMARYSTREAM_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0PRODUCTIONEFFECTIVEINDATE_ULineOfUsage();
    const std::string& get_cba0PRODUCTIONEFFECTIVEINPOINT_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0PRODUCTIONEFFECTIVEOUTDATE_ULineOfUsage();
    const std::string& get_cba0PRODUCTIONEFFECTIVEOUTPOINT_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0PROTOTYPEEFFECTIVEINDATE_ULineOfUsage();
    const std::string& get_cba0PROTOTYPEEFFECTIVEINPOINT_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0PROTOTYPEEFFECTIVEOUTDATE_ULineOfUsage();
    const std::string& get_cba0PROTOTYPEEFFECTIVEOUTPOINT_ULineOfUsage();
    const std::string& get_cba0UAPREFIX_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0VIRTUALBUILDEFFECTIVEINDATE_ULineOfUsage();
    const std::string& get_cba0VIRTUALBUILDEFFECTIVEINPOINT_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0VIRTUALBUILDEFFECTIVEOUTDATE_ULineOfUsage();
    const std::string& get_cba0VIRTUALBUILDEFFECTIVEOUTPOINT_ULineOfUsage();
    const std::string& get_alignedState();
    const std::string& get_usage_address();
    const Teamcenter::Soa::Client::ModelObjectVector& get_subusages();
    const Teamcenter::Soa::Client::ModelObjectVector& get_next_down_act();
    const Teamcenter::Soa::Client::ModelObjectVector& get_position_designators();
    const std::string& get_relation();
    const std::string& get_cba0MUG01_ULineOfUsage();
    const std::string& get_cba0USAGEADDRESS02_UUsageAddress();
    const std::string& get_cba0CHANGESTATUS_ULineOfUsage();
    const std::string& get_cba0ASSEMBLYINDICATOR_UPartMaster();
    const std::string& get_cba0SHORTSHORTHANDEXPR_ULineOfUsage();
    int get_cba0DRAWINGID_UPartMaster();
    const std::string& get_cba0LINEOFUSAGEMATURITY_ULineOfUsage();
    const std::string& get_cba0UNITOFMEASURE_ULineOfUsage();
    const std::string& get_cba0NOMATHINDICATOR_UPartMaster();
    const std::string& get_cba0PARTKEY03_UPartNumber();
    const std::string& get_cba0PARTITIONVALUE_UUsageAddressToPartition();
    const std::string& get_cba0ASSEMBLYCONTROLINDICATOR_ULineOfUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_ULineOfUsage();
    const std::string& get_cba0CORPGROUPTYPE_UCorpGroup();
    const std::string& get_cba0AUTHORIZATIONTYPE_UAuthorization();
    const std::string& get_cba0BOMVALIDATIONSTATUS_ULineOfUsage();
    const std::string& get_cba0MUG02_ULineOfUsage();
    const std::string& get_cba0DEFAULTPARTNAME_UPartNomenclature();
    const std::string& get_cba0AUTHORIZATIONSTATE_UAuthorization();
    const std::string& get_cba0HANDCODE_ULineOfUsage();
    int get_cba0CONSISTENCYSTAMP_ULineOfUsage();
    const std::string& get_cba0AUTHORIZATION__UAuthorization();
    const std::string& get_cba0PARTTUID_UPartMaster();
    const std::string& get_cba0LASTMODIFIEDUSER_ULineOfUsage();
    const std::string& get_cba0PARTFAMILY_UPartMaster();
    const std::string& get_cba0PARTBASE_UPartNumber();
    const std::string& get_cba0CHANGEDESCRIPTION_UAuthorization();
    const std::string& get_cba0DRAWINGVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0NAME_UCorpGroup();
    int get_cba0COMPLETENESSSATISFIED_ULineOfUsage();
    const std::string& get_cba0MATHTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0MATHVALIDATIONSTATUS_UPartMaster();
    const std::string& get_cba0CORPGROUP_UCorpGroup();
    const std::string& get_cba0EFFECTIVEINPOINT_ULineOfUsage();
    const std::string& get_cba0DISPLAYUNITOFMEASURE_UPartMaster();
    const std::string& get_cba0PARTKEY02_UPartNumber();
    const std::string& get_cba0VERIFICATIONCOMMENTS_ULineOfUsage();
    const std::string& get_cba0NODRAWINGINDICATOR_UPartMaster();
    const Teamcenter::Soa::Common::DateTime& get_cba0CHANGEDATE_UAuthorization();
    const std::string& get_cba0LINEOFUSAGETUID_ULineOfUsage();
    const std::string& get_cba0USAGEADDRESSTUID_UUsageAddress();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_ULineOfUsage();
    const std::string& get_cba0USAGEADDRESS01_UUsageAddress();
    int get_cba0COMPLETENESSREQUIRED_ULineOfUsage();
    const std::string& get_cba0MATHVALIDATIONSTATUS_ULineOfUsage();
    const std::string& get_cba0RECORDGROUP1TUID_ULineOfUsage();
    const std::string& get_cba0CUSTOMERCODE_UExpression();
    const std::string& get_cba0PARTAPPLICATIONTUID_UPartApplication();
    const std::string& get_cba0PARTMATURITY_UPartMaster();
    const std::string& get_cba0EFFECTIVEINAUTHORIZATION_ULineOfUsage();
    const std::string& get_cba0DRAWINGTOFOLLOWINDICATOR_UPartMaster();
    const std::string& get_cba0CREATIONUSER_ULineOfUsage();
    const std::string& get_cba0USERENTEREDSHORTHANDCONFIGEXPR_ULineOfUsage();
    const std::string& get_cba0ALPHAQUANTITY_ULineOfUsage();
    const std::string& get_cba0_Quantity();
    const std::string& get_cba0_PartID();
    const std::string& get_cba0DisplayName();
    const std::string& get_cba0VersionNumber();
    const std::string& get_cba0RpsRpdByGroupId();
    const std::string& get_cba0MasterCorpGroup();
    const std::string& get_cba0BomSolveType();
    const std::string& get_cba0WIPSystemGroup();
    const std::string& get_cba0BomSolveProdExpression();
    const std::string& get_cba0BomSolveModelDes();
    const std::string& get_cba0PARTTYPE_UPartMaster();
    const std::string& get_cba0PartVersionNumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0LOUProxy")

   virtual ~Cba0LOUProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
