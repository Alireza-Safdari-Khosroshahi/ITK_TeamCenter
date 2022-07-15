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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWT_PARTDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWT_PARTDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API PWT_PartData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_traceable();
    const std::string& get_color_code();
    const std::string& get_kpc();
    const std::string& get_pqc();
    const std::string& get_safety();
    const std::string& get_ppap_status();
    const Teamcenter::Soa::Common::DateTime& get_ppap_date();
    const Teamcenter::Soa::Client::StringVector& get_part_readiness();
    const Teamcenter::Soa::Client::StringVector& get_physical_milestones();
    const Teamcenter::Soa::Client::StringVector& get_comments();
    const std::string& get_compliance();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PWT_PartData")

   virtual ~PWT_PartData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
