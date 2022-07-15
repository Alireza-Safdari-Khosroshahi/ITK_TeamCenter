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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMECOUNTERS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMECOUNTERS_HXX

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


class TCSOACLIENTMNGD_API NameCounters : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_counter_name();
    int get_no_of_chars();
    int get_start_pos();
    const std::string& get_char_type();
    const std::string& get_init_value();
    const std::string& get_max_value();
    const std::string& get_next_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameCounters")

   virtual ~NameCounters();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
