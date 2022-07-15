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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAEANALYSISREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAEANALYSISREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CAEItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAEAnalysisRevision : public Teamcenter::Soa::Client::Model::CAEItemRevision
{
public:
    const std::string& get_solver_name();
    const std::string& get_analysis_type();
    const std::string& get_solution_type();
    const std::string& get_solution_step();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEAnalysisRevision")

   virtual ~CAEAnalysisRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
