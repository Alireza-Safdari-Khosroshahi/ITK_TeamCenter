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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISPROCSTAGEREVATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISPROCSTAGEREVATTR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPFreeTextRevision;
                class PSOccurrence;


class TCSOASPECMGRMODELMNGD_API ISProcStageRevAttr : public Teamcenter::Soa::Client::Model::Form
{
public:
    Teamcenter::Soa::Common::AutoPtr<CPFreeTextRevision> get_freetext_obj();
    const std::string& get_text();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrence> get_occurrence();
    int get_stage_id();
    int get_freetext_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISProcStageRevAttr")

   virtual ~ISProcStageRevAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
