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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVREQUIPMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVREQUIPMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrResource.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrEquipment : public Teamcenter::Soa::Client::Model::Mfg0BvrResource
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0used_by();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrEquipment")

   virtual ~Mfg0BvrEquipment();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
