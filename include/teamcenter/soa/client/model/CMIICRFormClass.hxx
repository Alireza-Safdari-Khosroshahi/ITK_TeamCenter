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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CMIICRFORMCLASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CMIICRFORMCLASS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CMIICRFormClass : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_cr_type();
    const std::string& get_cr_priority();
    const std::string& get_department();
    const std::string& get_fast_track();
    const std::string& get_impl_time();
    const std::string& get_tr_priority();
    const std::string& get_prop_soln();
    const std::string& get_tr_result();
    double get_rec_cost();
    double get_non_rec_cost();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_change_rev();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CMIICRFormClass")

   virtual ~CMIICRFormClass();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
