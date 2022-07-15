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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAEGEOMETRYREVMASTERSTORE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAEGEOMETRYREVMASTERSTORE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CAERevMasterStore.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAEGeometryRevMasterStore : public Teamcenter::Soa::Client::Model::CAERevMasterStore
{
public:
    const std::string& get_pre_processor_type();
    const Teamcenter::Soa::Client::StringVector& get_analysis_types();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEGeometryRevMasterStore")

   virtual ~CAEGeometryRevMasterStore();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
