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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ITEMIDRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ITEMIDRECORD_HXX

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


class TCSOACLIENTMNGD_API ItemIdRecord : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_iir_item_id();
    const std::string& get_iir_context();
    int get_iir_registration_site();
    const std::string& get_fnd0iir_domain();
    const std::string& get_fnd0iir_key_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ItemIdRecord")

   virtual ~ItemIdRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
