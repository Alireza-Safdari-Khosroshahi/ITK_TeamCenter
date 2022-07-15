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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ENGCHANGE_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ENGCHANGE_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API EngChange_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_affected_items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_reference_items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_tasks_to_review();
    const Teamcenter::Soa::Client::ModelObjectVector& get_problem_items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_affected_rev_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_problem_rev_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_addressed_by();
    const Teamcenter::Soa::Client::ModelObjectVector& get_solution_items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_tasks_to_perform();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EngChange_Revision")

   virtual ~EngChange_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
