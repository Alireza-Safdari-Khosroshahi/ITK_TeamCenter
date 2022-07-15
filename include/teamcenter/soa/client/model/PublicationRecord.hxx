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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PUBLICATIONRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PUBLICATIONRECORD_HXX

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


class TCSOACLIENTMNGD_API PublicationRecord : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_pubr_object_tag();
    int get_pubr_owning_site();
    const Teamcenter::Soa::Common::DateTime& get_pubr_pub_date();
    const std::string& get_pubr_object_class();
    const std::string& get_pubr_object_type();
    const std::string& get_pubr_object_id();
    const std::string& get_pubr_object_name();
    const std::string& get_pubr_owner_id();
    const std::string& get_pubr_group_id();
    const std::string& get_pubr_object_desc();
    const Teamcenter::Soa::Common::DateTime& get_pubr_object_create_date();
    const Teamcenter::Soa::Client::StringVector& get_pubr_object_status_names();
    int get_pubr_flag();
    const Teamcenter::Soa::Client::StringVector& get_pubr_appref();
    const std::string& get_pubr_project_name();
    const std::string& get_pubr_object_rev_id();
    const Teamcenter::Soa::Client::StringVector& get_pubr_idcxt_names();
    const Teamcenter::Soa::Client::StringVector& get_pubr_idfr_ids();
    const std::string& get_fnd0pubr_domain();
    const std::string& get_fnd0pubr_key_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PublicationRecord")

   virtual ~PublicationRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
