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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IDCLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IDCLINE_HXX

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


class TCSOACLIENTMNGD_API IDCLine : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_idcline_parent();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_idcline_window();
    int get_idcline_quick_num_children();
    const std::string& get_idcline_bg_colour_int_as_str();
    const std::string& get_bl_item_item_id();
    const std::string& get_bl_rev_object_name();
    const std::string& get_bl_rev_object_type();
    const std::string& get_bl_rev_item_revision_id();
    const std::string& get_bl_plmxml_abs_xform();
    const std::string& get_bl_network_viewer_route();
    const std::string& get_bl_has_children();
    const std::string& get_bl_clone_stable_occurrence_id();
    const std::string& get_bl_quantity();
    const std::string& get_fnd0bl_real_quantity();
    const std::string& get_bl_part_source();
    const std::string& get_bl_uom();
    const std::string& get_bl_ref_designator();
    const std::string& get_bl_sequence_no();
    const std::string& get_bl_abs_occ_id();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_revision();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_jt_dataset_tag();
    const std::string& get_bl_jt_refsetname();
    const std::string& get_bl_absocc_uid_in_topline_context();
    const std::string& get_bl_clone_stable_occurrence_id_chain();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_absocc_or_occgroup();
    const std::string& get_bl_line_name();
    const std::string& get_bl_intended_title();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_operation_tcpublishingpage_dataset();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_activity_tcpublishingpage_dataset();
    const std::string& get_me_cl_display_string();
    const std::string& get_me_cl_relation();
    const std::string& get_me_cl_object_name();
    const std::string& get_me_cl_object_desc();
    const std::string& get_me_cl_object_type();
    const Teamcenter::Soa::Client::StringVector& get_idcline_form_titles();
    const Teamcenter::Soa::Client::StringVector& get_idcline_form_title_values();
    const std::string& get_start_time();
    const std::string& get_time();
    const std::string& get_calc_start_time();
    const std::string& get_calc_time();
    const std::string& get_object_name();
    const std::string& get_object_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_imanfile();
    const std::string& get_bl_plmxml_occ_xform();
    const std::string& get_bl_bomview_uid();
    const std::string& get_bl_occurrence_uid();
    const std::string& get_bl_jt_dataset_dakid();
    const std::string& get_bl_jt_override_children();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IDCLine")

   virtual ~IDCLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
