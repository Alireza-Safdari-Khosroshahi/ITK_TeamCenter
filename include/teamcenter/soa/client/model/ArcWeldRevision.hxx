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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ARCWELDREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ARCWELDREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PSConnectionRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ArcWeldRevision : public Teamcenter::Soa::Client::Model::PSConnectionRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Feature_Form_Relation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0TCContextFeatureFormRel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ArcWeldRevision")

   virtual ~ArcWeldRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
