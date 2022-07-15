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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMASSIGNMENTLIST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMASSIGNMENTLIST_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class EPMTaskTemplate;
                class EPMResourceList;


class TCSOACLIENTMNGD_API EPMAssignmentList : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_list_name();
    const Teamcenter::Soa::Client::StringVector& get_list_desc();
    bool get_shared();
    size_t count_task_templates();
    Teamcenter::Soa::Common::AutoPtr<EPMTaskTemplate> get_task_templates_at( size_t inx );
    size_t count_resources();
    Teamcenter::Soa::Common::AutoPtr<EPMResourceList> get_resources_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMAssignmentList")

   virtual ~EPMAssignmentList();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
