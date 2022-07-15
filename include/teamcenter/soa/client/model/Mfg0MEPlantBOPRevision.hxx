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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEPLANTBOPREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEPLANTBOPREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0MEProcAreaRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0MEPlantBOPRevision : public Teamcenter::Soa::Client::Model::Mfg0MEProcAreaRevision
{
public:
    const Teamcenter::Soa::Client::IntVector& get_Mfg0StationSize();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MEPlantBOPRevision")

   virtual ~Mfg0MEPlantBOPRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
