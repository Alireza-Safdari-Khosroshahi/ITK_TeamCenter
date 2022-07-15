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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SMLB0_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SMLB0_HXX

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


class TCSOACLIENTMNGD_API Smlb0 : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_cid();
    const Teamcenter::Soa::Client::StringVector& get_parent();
    const std::string& get_type();
    const std::string& get_name();
    const std::string& get_sname();
    const std::string& get_klassi();
    const std::string& get_gfile();
    int get_cflags();
    int get_multiinst();
    const std::string& get_ext_1();
    const std::string& get_ext_2();
    const std::string& get_descr();
    const std::string& get_comment();
    const Teamcenter::Soa::Client::StringVector& get_shared_sites();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_default_template();
    const std::string& get_cr_uid();
    const std::string& get_cr_gid();
    const std::string& get_cr_date();
    const std::string& get_mod_uid();
    const std::string& get_mod_date();
    int get_gac();
    int get_wac();
    const std::string& get_conceptID();
    const Teamcenter::Soa::Client::StringVector& get_fnd0library();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0LibraryForProject();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Smlb0")

   virtual ~Smlb0();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
