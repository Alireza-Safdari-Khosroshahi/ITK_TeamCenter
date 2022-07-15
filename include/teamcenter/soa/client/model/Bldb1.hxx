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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BLDB1_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BLDB1_HXX

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
                class Bldb0;


class TCSOACLIENTMNGD_API Bldb1 : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_sind();
    int get_attr_index();
    const std::string& get_min_value();
    const std::string& get_max_value();
    int get_aflags();
    const std::string& get_text();
    int get_flags_1();
    const std::string& get_text_1();
    int get_flags_2();
    const std::string& get_text_2();
    const std::string& get_ext_1();
    const std::string& get_ext_2();
    const Teamcenter::Soa::Client::StringVector& get_groups();
    const std::string& get_defaultValue();
    const std::string& get_descr();
    const std::string& get_comment();
    const std::string& get_name();
    const std::string& get_userfcn();
    const std::string& get_userfcnparam();
    const std::string& get_defaultValue2();
    const std::string& get_max_value2();
    const std::string& get_min_value2();
    Teamcenter::Soa::Common::AutoPtr<Bldb0> get_tag_to_header();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Bldb1")

   virtual ~Bldb1();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
