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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_STXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_STXT_HXX

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


class TCSOACLIENTMNGD_API Stxt : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_id();
    const std::string& get_name();
    int get_iflags();
    const Teamcenter::Soa::Client::StringVector& get_key();
    const Teamcenter::Soa::Client::StringVector& get_value();
    const std::string& get_comment();
    const Teamcenter::Soa::Client::StringVector& get_shared_sites();
    const std::string& get_cr_uid();
    const std::string& get_cr_gid();
    const std::string& get_cr_date();
    const std::string& get_mod_uid();
    const std::string& get_mod_date();
    int get_gac();
    int get_wac();
    const std::string& get_conceptID();
    const Teamcenter::Soa::Client::IntVector& get_deprecated_key_values();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Stxt")

   virtual ~Stxt();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
