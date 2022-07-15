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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPROCESSREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPROCESSREVISION_HXX

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


class TCSOACLIENTMNGD_API MEProcessRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_METarget();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEWorkArea();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEOutput();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEFolder();
    const Teamcenter::Soa::Client::ModelObjectVector& get_METimeAnalysisRelation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0MEProductLAssignmentRel();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0METoolRequirementRel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEProcessRevision")

   virtual ~MEProcessRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
