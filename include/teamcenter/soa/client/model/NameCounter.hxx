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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_NAMECOUNTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_NAMECOUNTER_HXX

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
                class NextIdField;


class TCSOACLIENTMNGD_API NameCounter : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_counter_name();
    int get_start_pos();
    int get_no_of_chars();
    const std::string& get_char_type();
    const std::string& get_init_value();
    const std::string& get_max_value();
    const std::string& get_fnd0_next_id();
    size_t count_next_id_tags();
    Teamcenter::Soa::Common::AutoPtr<NextIdField> get_next_id_tags_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("NameCounter")

   virtual ~NameCounter();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
