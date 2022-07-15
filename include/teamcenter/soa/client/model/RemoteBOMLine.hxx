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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REMOTEBOMLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REMOTEBOMLINE_HXX

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


class TCSOACLIENTMNGD_API RemoteBOMLine : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_rbl_parent_object_tag();
    const std::string& get_rbl_replica_status();
    const Teamcenter::Soa::Common::DateTime& get_rbl_master_lmd();
    const Teamcenter::Soa::Common::DateTime& get_rbl_replica_lmd();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_rbl_object_tag();
    const Teamcenter::Soa::Client::ModelObjectVector& get_rbl_child_objects();
    const std::string& get_rbl_object_string();
    int get_rbl_assembly_level();
    const std::string& get_rbl_object_class();
    int get_rbl_owning_site();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RemoteBOMLine")

   virtual ~RemoteBOMLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
