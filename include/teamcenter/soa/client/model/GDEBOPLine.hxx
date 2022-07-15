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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GDEBOPLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GDEBOPLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GDELine.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API GDEBOPLine : public Teamcenter::Soa::Client::Model::GDELine
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_me_activity_lines();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_me_refwindow();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_me_appgroup();
    bool get_bl_me_occ_grp_in_base_mode();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_me_refobj();
    bool get_bl_me_has_loop_predecessor();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_me_refline();
    const std::string& get_bl_me_refline_abs_occ_id();
    bool get_bl_me_has_occ_group();
    const std::string& get_bl_me_time();
    bool get_bl_me_op_has_useditems();
    double get_bl_me_duration_time();
    double get_bl_me_work_time();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_bl_me_ref_time_analysis();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GDEBOPLine")

   virtual ~GDEBOPLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
