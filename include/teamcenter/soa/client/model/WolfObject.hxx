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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_WOLFOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_WOLFOBJECT_HXX

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


class TCSOACLIENTMNGD_API WolfObject : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_ext_app_guid();
    const std::string& get_ext_obj_id();
    const Teamcenter::Soa::Client::StringVector& get_ext_obj_url();
    const std::string& get_ext_obj_name();
    const std::string& get_ext_obj_desc();
    const std::string& get_ext_obj_icon_url();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ext_app_type();
    const std::string& get_object_desc();
    const std::string& get_object_type();
    const std::string& get_ext_obj_url_1();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WolfObject")

   virtual ~WolfObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
