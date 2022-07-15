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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSFERPENDING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSFERPENDING_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API TransferPending : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    int get_operation_type();
    const std::string& get_comments();
    const Teamcenter::Soa::Client::ModelObjectVector& get_obj_list();
    const Teamcenter::Soa::Client::StringVector& get_obj_name();
    const Teamcenter::Soa::Client::StringVector& get_obj_type();
    const std::string& get_device_or_label();
    const std::string& get_media_type();
    const std::string& get_meta_filename();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TransferPending")

   virtual ~TransferPending();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
