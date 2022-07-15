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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPROCESSPARTITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPROCESSPARTITION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrPartition.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrProcessPartition : public Teamcenter::Soa::Client::Model::Mfg0BvrPartition
{
public:
    const std::string& get_Mfg0ld_representation();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0origin();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0context();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0MELogicalDesignatorForm();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrProcessPartition")

   virtual ~Mfg0BvrProcessPartition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
