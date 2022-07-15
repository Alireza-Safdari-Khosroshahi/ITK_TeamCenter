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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPLANTBOP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPLANTBOP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrProcessArea.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrPlantBOP : public Teamcenter::Soa::Client::Model::Mfg0BvrProcessArea
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0associated_context();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0productVariants();
    const Teamcenter::Soa::Client::IntVector& get_Mfg0StationSize();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrPlantBOP")

   virtual ~Mfg0BvrPlantBOP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
