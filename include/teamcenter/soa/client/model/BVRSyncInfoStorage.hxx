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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BVRSYNCINFOSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BVRSYNCINFOSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API BVRSyncInfoStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_last_sync_date();
    const Teamcenter::Soa::Common::DateTime& get_last_struct_mod();
    const std::string& get_view_type();
    const std::string& get_appl_data();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BVRSyncInfoStorage")

   virtual ~BVRSyncInfoStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
