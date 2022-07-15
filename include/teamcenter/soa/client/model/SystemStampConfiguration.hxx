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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SYSTEMSTAMPCONFIGURATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SYSTEMSTAMPCONFIGURATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanType;
                class PrefixProperty;


class TCSOACLIENTMNGD_API SystemStampConfiguration : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    const std::string& get_applies_to();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_bus_obj();
    const std::string& get_user_stamp();
    const std::string& get_water_mark();
    bool get_include_date();
    bool get_include_user_name();
    const std::string& get_mds_template_name();
    size_t count_properties();
    Teamcenter::Soa::Common::AutoPtr<PrefixProperty> get_properties_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SystemStampConfiguration")

   virtual ~SystemStampConfiguration();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
