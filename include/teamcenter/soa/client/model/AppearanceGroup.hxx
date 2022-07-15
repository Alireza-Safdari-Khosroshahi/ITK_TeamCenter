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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEGROUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEGROUP_HXX

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
                class MEAppearancePathRoot;
                class ApprSearchCriteria;


class TCSOACLIENTMNGD_API AppearanceGroup : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathRoot> get_app_path_root();
    const std::string& get_fnd0clone_stable_id();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_search_criteria();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_3D_snap_shot();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_ProductManual();
    const Teamcenter::Soa::Client::ModelObjectVector& get_appearance_groups();
    const Teamcenter::Soa::Client::ModelObjectVector& get_appearances();
    const Teamcenter::Soa::Client::ModelObjectVector& get_parents();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_end_item();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEWorkInstruction();
    const Teamcenter::Soa::Client::ModelObjectVector& get_VisSession();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppearanceGroup")

   virtual ~AppearanceGroup();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
