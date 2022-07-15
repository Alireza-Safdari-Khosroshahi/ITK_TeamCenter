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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PUBLISHEDOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PUBLISHEDOBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RuntimeBusinessObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API PublishedObject : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    const std::string& get_po_object_name();
    const std::string& get_po_object_id();
    const std::string& get_po_object_rev_id();
    const std::string& get_po_object_type();
    const std::string& get_po_object_class();
    const std::string& get_po_owner_id();
    const std::string& get_po_group_id();
    int get_po_owning_site();
    const Teamcenter::Soa::Common::DateTime& get_po_pub_date();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_po_object_tag();
    const std::string& get_po_object_desc();
    const Teamcenter::Soa::Common::DateTime& get_po_object_creation_date();
    const std::string& get_po_object_rel_stat_names();
    const std::string& get_po_object_obid();
    const std::string& get_po_idcxt_names();
    const std::string& get_po_idfr_ids();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PublishedObject")

   virtual ~PublishedObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
