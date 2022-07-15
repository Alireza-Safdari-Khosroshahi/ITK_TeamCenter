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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UNCT_DICT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UNCT_DICT_HXX

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


class TCSOACLIENTMNGD_API Unct_dict : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_unct();
    int get_format();
    int get_format2();
    const std::string& get_name();
    const std::string& get_sname();
    const std::string& get_unit();
    const std::string& get_unit2();
    const std::string& get_ref();
    int get_uflags();
    const std::string& get_ext_1();
    const std::string& get_ext_2();
    const std::string& get_descr();
    const std::string& get_comment();
    const std::string& get_ref_type();
    const std::string& get_ref_objType();
    const std::string& get_ref_options();
    const Teamcenter::Soa::Client::StringVector& get_shared_sites();
    const std::string& get_cr_uid();
    const std::string& get_cr_gid();
    const std::string& get_cr_date();
    const std::string& get_mod_uid();
    const std::string& get_mod_date();
    int get_gac();
    int get_wac();
    const std::string& get_defaultValue();
    const std::string& get_defaultValue2();
    const std::string& get_userfcn();
    const std::string& get_userfcnparam();
    const std::string& get_conceptID();
    const std::string& get_max_value();
    const std::string& get_min_value();
    const std::string& get_max_value2();
    const std::string& get_min_value2();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Unct_dict")

   virtual ~Unct_dict();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
