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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMAN_3D_SNAP_SHOT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMAN_3D_SNAP_SHOT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API IMAN_3D_snap_shot : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_MEWorkArea();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IMAN_3D_snap_shot")

   virtual ~IMAN_3D_snap_shot();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
