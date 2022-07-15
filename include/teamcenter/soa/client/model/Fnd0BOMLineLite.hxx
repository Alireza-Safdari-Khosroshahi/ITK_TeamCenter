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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0BOMLINELITE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0BOMLINELITE_HXX

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


class TCSOACLIENTMNGD_API Fnd0BOMLineLite : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    bool get_bl_has_children();
    const std::string& get_bl_line_name();
    const std::string& get_bl_plmxml_occ_xform();
    const std::string& get_bl_property_overrides();
    const std::string& get_bl_clone_stable_occurrence_id();
    bool get_bl_is_occ_suppressed();
    const std::string& get_bl_absocc_uid_in_topline_context();
    const std::string& get_bl_occurrence_uid();
    const std::string& get_bl_abs_occ_id();
    const std::string& get_bl_plmxml_abs_xform();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_jt_dataset_tag();
    const std::string& get_bl_apn_uid_in_topline_context();
    bool get_bl_jt_override_children();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_config_window();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_window();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0BOMLineLite")

   virtual ~Fnd0BOMLineLite();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
