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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAERESULTREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAERESULTREVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CAERevision_Master.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAEResultRevision_Master : public Teamcenter::Soa::Client::Model::CAERevision_Master
{
public:
    const std::string& get_solver_name();
    const std::string& get_analysis_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEResultRevision_Master")

   virtual ~CAEResultRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
