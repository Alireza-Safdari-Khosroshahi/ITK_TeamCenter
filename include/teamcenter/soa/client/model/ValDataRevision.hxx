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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALDATAREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALDATAREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ValidationParams;


class TCSOACLIENTMNGD_API ValDataRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    int get_usage_status();
    Teamcenter::Soa::Common::AutoPtr<ValidationParams> get_validation_parameters();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValDataRevision")

   virtual ~ValDataRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
