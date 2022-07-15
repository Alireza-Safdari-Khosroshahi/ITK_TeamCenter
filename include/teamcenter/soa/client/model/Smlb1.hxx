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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SMLB1_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SMLB1_HXX

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
                class Smlb0;


class TCSOACLIENTMNGD_API Smlb1 : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_attr_index();
    int get_dbindex();
    const std::string& get_attr_id();
    int get_unct();
    const std::string& get_min_value();
    const std::string& get_max_value();
    int get_aflags();
    int get_arraySize();
    const std::string& get_ext_1();
    const std::string& get_ext_2();
    const Teamcenter::Soa::Client::StringVector& get_groups();
    const std::string& get_ref_type();
    const std::string& get_ref_objType();
    const std::string& get_ref_options();
    const std::string& get_defaultValue();
    const std::string& get_descr();
    const std::string& get_comment();
    const std::string& get_name();
    const std::string& get_userfcn();
    const std::string& get_userfcnparam();
    const std::string& get_defaultValue2();
    const std::string& get_max_value2();
    const std::string& get_min_value2();
    Teamcenter::Soa::Common::AutoPtr<Smlb0> get_tag_to_header();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Smlb1")

   virtual ~Smlb1();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
