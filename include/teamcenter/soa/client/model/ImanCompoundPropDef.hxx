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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANCOMPOUNDPROPDEF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANCOMPOUNDPROPDEF_HXX

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


class TCSOACLIENTMNGD_API ImanCompoundPropDef : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_compound_prop_name();
    const std::string& get_display_type_name();
    const std::string& get_source_type_name();
    const std::string& get_source_prop_name();
    const Teamcenter::Soa::Client::StringVector& get_object_hierarchy();
    bool get_is_read_only();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanCompoundPropDef")

   virtual ~ImanCompoundPropDef();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
