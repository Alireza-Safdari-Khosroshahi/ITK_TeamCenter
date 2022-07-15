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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEOPREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEOPREVISION_HXX

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
                class Mfg0MEExecutionPosnStorage;


class TCSOACLIENTMNGD_API MEOPRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_root_activity();
    size_t count_Mfg0ExecPositions();
    Teamcenter::Soa::Common::AutoPtr<Mfg0MEExecutionPosnStorage> get_Mfg0ExecPositions_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_METarget();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEWorkArea();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEOutput();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_METimeAnalysisRelation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0MEProductLAssignmentRel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0METoolRequirementRel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEOPRevision")

   virtual ~MEOPRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
