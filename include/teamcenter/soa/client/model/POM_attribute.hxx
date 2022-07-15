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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_ATTRIBUTE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_ATTRIBUTE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_dd.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_dd;
                class POM_dd;


class TCSOACLIENTMNGD_API POM_attribute : public Teamcenter::Soa::Client::Model::POM_dd
{
public:
    const std::string& get_name();
    const std::string& get_initial_value();
    const std::string& get_upper_bound();
    const std::string& get_lower_bound();
    const std::string& get_dbname();
    Teamcenter::Soa::Common::AutoPtr<POM_dd> get_defining_class();
    int get_properties();
    int get_length();
    int get_null_offset();
    int get_empty_offset();
    Teamcenter::Soa::Common::AutoPtr<POM_dd> get_referenced_class();
    int get_type();
    int get_ptype();
    int get_apid();
    int get_max_string_length();
    int get_number_of_columns();
    bool get_has_table();
    bool get_nulls_allowed();
    bool get_unique();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_attribute")

   virtual ~POM_attribute();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
