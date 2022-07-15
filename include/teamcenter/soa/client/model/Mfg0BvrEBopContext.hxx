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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVREBOPCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVREBOPCONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrProcessContext.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrEBopContext : public Teamcenter::Soa::Client::Model::Mfg0BvrProcessContext
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0partition_breakdowns();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrEBopContext")

   virtual ~Mfg0BvrEBopContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
