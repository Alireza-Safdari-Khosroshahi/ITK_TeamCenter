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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCOBJECT_HXX

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
                class ConfigurationContext;


class TCSOACLIENTMNGD_API CCObject : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<ConfigurationContext> get_config_context();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_self();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_manifestation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_CCContext();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_specification();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_top_line();
    const Teamcenter::Soa::Client::ModelObjectVector& get_structure_contexts();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_working_context();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_requirement();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CCObject")

   virtual ~CCObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
