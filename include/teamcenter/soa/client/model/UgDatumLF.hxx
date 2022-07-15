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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMLF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMLF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/UgDatumBasic.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API UgDatumLF : public Teamcenter::Soa::Client::Model::UgDatumBasic
{
public:
    const std::string& get_section_plane_name();
    const std::string& get_body_section_line();
    const std::string& get_mature();
    const std::string& get_fixed_location();
    const std::string& get_direction_of_check();
    const std::string& get_standard();
    const std::string& get_override_();
    const std::string& get_relationships();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UgDatumLF")

   virtual ~UgDatumLF();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
