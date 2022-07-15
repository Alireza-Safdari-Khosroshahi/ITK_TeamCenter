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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NXCMVALDATAREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NXCMVALDATAREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/NXValDataRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Dataset;


class TCSOACLIENTMNGD_API NXCMValDataRevision : public Teamcenter::Soa::Client::Model::NXValDataRevision
{
public:
    bool get_validation_can_group();
    const std::string& get_validation_category();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_validation_ext_rule();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NXCMValDataRevision")

   virtual ~NXCMValDataRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
