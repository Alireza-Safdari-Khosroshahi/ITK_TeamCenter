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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SCMCOMPOUNDELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SCMCOMPOUNDELEMENT_HXX

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
                class SCMElement;
                class SCMServer;


class TCSOASCMCCMODELMNGD_API SCMCompoundElement : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    size_t count_scm_elements();
    Teamcenter::Soa::Common::AutoPtr<SCMElement> get_scm_elements_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<SCMServer> get_scm_server();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SCMCompoundElement")

   virtual ~SCMCompoundElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ScmccMngd_undef.h>
#endif
