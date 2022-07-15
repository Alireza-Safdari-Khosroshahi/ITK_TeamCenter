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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAEMODELREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAEMODELREVISION_HXX

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


class TCSOACLIENTMNGD_API CAEModelRevision : public Teamcenter::Soa::Client::Model::CAEItemRevision
{
public:
    const std::string& get_solver_name();
    const Teamcenter::Soa::Client::StringVector& get_analysis_types();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0CAE_TargetOccurrence();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEModelRevision")

   virtual ~CAEModelRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
