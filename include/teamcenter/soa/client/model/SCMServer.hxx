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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCMSERVER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCMSERVER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/ScmccMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASCMCCMODELMNGD_API SCMServer : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_scm_type();
    const std::string& get_scm_server_uuid();
    const std::string& get_scm_replica_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SCMServer")

   virtual ~SCMServer();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ScmccMngd_undef.h>
#endif
