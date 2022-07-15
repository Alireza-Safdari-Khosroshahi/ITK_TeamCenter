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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAELOADITEMMASTERSTORE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAELOADITEMMASTERSTORE_HXX

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


class TCSOACLIENTMNGD_API CAELoadItemMasterStore : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_project_id();
    const std::string& get_previous_version_id();
    const std::string& get_serial_number();
    const std::string& get_item_comment();
    const std::string& get_user_data_1();
    const std::string& get_user_data_2();
    const std::string& get_user_data_3();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAELoadItemMasterStore")

   virtual ~CAELoadItemMasterStore();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
