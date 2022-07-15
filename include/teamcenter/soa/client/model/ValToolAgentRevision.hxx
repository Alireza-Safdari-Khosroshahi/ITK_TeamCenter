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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALTOOLAGENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALTOOLAGENTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ValidationAgentRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ValToolAgentRevision : public Teamcenter::Soa::Client::Model::ValidationAgentRevision
{
public:
    const Teamcenter::Soa::Client::StringVector& get_validation_arguments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_validation_tool();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValToolAgentRevision")

   virtual ~ValToolAgentRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
