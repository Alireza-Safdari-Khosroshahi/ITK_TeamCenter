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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROPRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROPRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API PropRule : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_type_name();
    const std::string& get_property_name();
    const Teamcenter::Soa::Client::StringVector& get_initial_value();
    int get_modifiable();
    bool get_is_required();
    bool get_is_enabled();
    bool get_is_visible();
    const Teamcenter::Soa::Client::StringVector& get_complex_property();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PropRule")

   virtual ~PropRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
