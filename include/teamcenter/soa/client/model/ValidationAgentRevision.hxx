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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONAGENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONAGENTREVISION_HXX

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


class TCSOACLIENTMNGD_API ValidationAgentRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    bool get_keep_overridden_result();
    bool get_override_reason_mandatory();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_validation_data();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValidationAgentRevision")

   virtual ~ValidationAgentRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
