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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAECONNITEMREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAECONNITEMREVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAEConnItemRevision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_conn_name();
    const std::string& get_conn_desc();
    const std::string& get_conn_type();
    const std::string& get_geometry();
    const Teamcenter::Soa::Client::StringVector& get_conn_links();
    const std::string& get_strength();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owner_form_obj();
    const std::string& get_conn_rev_name();
    const std::string& get_conn_rev_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEConnItemRevision_Master")

   virtual ~CAEConnItemRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
