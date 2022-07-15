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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REMOTEOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REMOTEOBJECT_HXX

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


class TCSOACLIENTMNGD_API RemoteObject : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ro_object_tag();
    const std::string& get_ro_object_type();
    int get_ro_owning_site();
    const Teamcenter::Soa::Common::DateTime& get_ro_master_lmd();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ro_parent_object_tag();
    const std::string& get_ro_object_class();
    const std::string& get_ro_object_relation();
    const Teamcenter::Soa::Common::DateTime& get_ro_replica_lmd();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ro_child_objects();
    const std::string& get_ro_object_string();
    const std::string& get_ro_replica_status();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RemoteObject")

   virtual ~RemoteObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
