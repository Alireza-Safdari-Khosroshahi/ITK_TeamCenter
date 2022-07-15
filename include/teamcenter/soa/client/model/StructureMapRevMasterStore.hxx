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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_STRUCTUREMAPREVMASTERSTORE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_STRUCTUREMAPREVMASTERSTORE_HXX

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


class TCSOACLIENTMNGD_API StructureMapRevMasterStore : public Teamcenter::Soa::Client::Model::CAERevMasterStore
{
public:
    const std::string& get_domain();
    const Teamcenter::Soa::Common::DateTime& get_last_validation_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructureMapRevMasterStore")

   virtual ~StructureMapRevMasterStore();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
