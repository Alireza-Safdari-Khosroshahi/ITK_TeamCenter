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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSBOMVIEWREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSBOMVIEWREVISION_HXX

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
                class PSBOMView;


class TCSOACLIENTMNGD_API PSBOMViewRevision : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_bom_view();
    const Teamcenter::Soa::Client::IntVector& get_cd_indexes();
    int get_is_precise();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cd_tags();
    int get_occ_flags();
    const Teamcenter::Soa::Client::ModelObjectVector& get_occs_vla();
    const Teamcenter::Soa::Client::ModelObjectVector& get_threads_vla();
    const Teamcenter::Soa::Client::ModelObjectVector& get_occs_to_destroy_vla();
    double get_legacy_transform_factor();
    const Teamcenter::Soa::Common::DateTime& get_struct_last_mod_date();
    bool get_struct_changed();
    double get_assy_units();
    const Teamcenter::Soa::Client::ModelObjectVector& get_bvr_occurrences();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0PS_Markup();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSBOMViewRevision")

   virtual ~PSBOMViewRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
