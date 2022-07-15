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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONCONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class VariantRule;
                class StoredOptionSet;
                class AssemblyArrangement;
                class VariantRule;
                class Fnd0EffectvtyGrpRevision;
                class RevisionRule;
                class ClosureRule;


class TCSOACLIENTMNGD_API ConfigurationContext : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<VariantRule> get_variant_rule();
    Teamcenter::Soa::Common::AutoPtr<StoredOptionSet> get_sos();
    const Teamcenter::Soa::Client::StringVector& get_revrule_strings();
    Teamcenter::Soa::Common::AutoPtr<AssemblyArrangement> get_active_arrangement();
    const std::string& get_Mfg0VisibilityUncnfVar();
    const std::string& get_Mfg0VisibilityUncnfAssgnOcc();
    const std::string& get_Mfg0VisibilityUncnfOccEff();
    const std::string& get_Mfg0VisibilitySuppOcc();
    const std::string& get_Mfg0VisibilityGCSConn();
    const std::string& get_Mfg0VisibilityUncnfChanges();
    bool get_Mfg0ApplyOccTypeFilters();
    const Teamcenter::Soa::Client::StringVector& get_Mfg0OccTypeFilters();
    size_t count_variant_rules();
    Teamcenter::Soa::Common::AutoPtr<VariantRule> get_variant_rules_at( size_t inx );
    int get_fnd0cc_flags();
    size_t count_Fnd0EffectvtyGrpList();
    Teamcenter::Soa::Common::AutoPtr<Fnd0EffectvtyGrpRevision> get_Fnd0EffectvtyGrpList_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<RevisionRule> get_revision_rule();
    Teamcenter::Soa::Common::AutoPtr<ClosureRule> get_closure_rule();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_manifestation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_specification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_requirement();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConfigurationContext")

   virtual ~ConfigurationContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
