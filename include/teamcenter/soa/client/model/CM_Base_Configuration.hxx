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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CM_BASE_CONFIGURATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CM_BASE_CONFIGURATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CM_Base_Configuration : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_end_item_str();
    int get_unit_no();
    const Teamcenter::Soa::Common::DateTime& get_from_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CM_Base_Configuration")

   virtual ~CM_Base_Configuration();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
