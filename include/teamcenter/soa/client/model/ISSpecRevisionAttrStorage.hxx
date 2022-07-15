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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISSPECREVISIONATTRSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISSPECREVISIONATTRSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASPECMGRMODELMNGD_API ISSpecRevisionAttrStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_creation_date();
    const Teamcenter::Soa::Common::DateTime& get_obsolescence_date();
    const Teamcenter::Soa::Common::DateTime& get_last_modified_date();
    const Teamcenter::Soa::Common::DateTime& get_status_changed_date();
    const Teamcenter::Soa::Common::DateTime& get_issued_date();
    const std::string& get_created_by();
    const std::string& get_last_modified_by();
    bool get_ped_in_sync();
    int get_mask_id();
    const std::string& get_mask();
    int get_phase_in_tolerance();
    const std::string& get_frame_no();
    int get_frame_revision();
    int get_frame_owner();
    bool get_is_metric();
    bool get_is_multilanguage();
    bool get_is_international();
    const std::string& get_international_part_no();
    int get_international_part_rev();
    int get_part_type_id();
    const std::string& get_part_type();
    const std::string& get_part_source();
    const Teamcenter::Soa::Common::DateTime& get_date_imported();
    const std::string& get_bar_code();
    const std::string& get_spec_reason_type();
    const std::string& get_spec_reason_text();
    const std::string& get_spec_status();
    const std::string& get_spec_statustype();
    const Teamcenter::Soa::Common::DateTime& get_spec_effective_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISSpecRevisionAttrStorage")

   virtual ~ISSpecRevisionAttrStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
