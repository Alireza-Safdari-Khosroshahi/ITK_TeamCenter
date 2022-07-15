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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BOMWINDOW_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BOMWINDOW_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RuntimeBusinessObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API BOMWindow : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    int get_ove_message_error_level();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_appearance_root();
    bool get_show_suppressed_occurrences();
    bool get_reposition_all_arrangements();
    bool get_show_out_of_context_lines();
    bool get_has_visible_line();
    bool get_absocc_edit_for_itemrev();
    bool get_has_occupancy_cache();
    bool get_ove_ignore_errors();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_incr_change_rev();
    bool get_icm_flag();
    bool get_show_unconfigured_variants();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_engineering_change();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_revision_rule();
    bool get_is_tracking_appearances();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_active_arrangement();
    bool get_absocc_specific_edit_mode();
    bool get_ec_flag();
    bool get_show_unconfigured_changes();
    bool get_ignore_arrangements();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_top_line();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_absocc_ctxtline();
    bool get_is_packed_by_default();
    bool get_in_pending_edit_mode();
    bool get_fnd0bw_in_markup_mode();
    bool get_fnd0bw_in_cv_cfg_to_load_md();
    bool get_fnd0show_gcs_cps();
    bool get_fnd0show_uncnf_occ_eff();
    bool get_fnd0IsOccTypeFilterApplied();
    int get_fnd0bwVariantRuleMode();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0appliedClosureRule();
    bool get_fnd0bw_is_mono_mode();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BOMWindow")

   virtual ~BOMWindow();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
