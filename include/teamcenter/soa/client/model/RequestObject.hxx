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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REQUESTOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REQUESTOBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class RecordObject;
                class ImanFile;
                class ImanFile;
                class User;


class TCSOACLIENTMNGD_API RequestObject : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_request_type();
    int get_status();
    const std::string& get_status_msg();
    int get_state();
    const std::string& get_state_msg();
    const Teamcenter::Soa::Common::DateTime& get_processed_on();
    int get_scope();
    int get_update_type();
    size_t count_file_mappings();
    Teamcenter::Soa::Common::AutoPtr<RecordObject> get_file_mappings_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_fnd0CustomKeys();
    const Teamcenter::Soa::Client::StringVector& get_fnd0CustomValues();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_xml_file();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_delta_xml_file();
    Teamcenter::Soa::Common::AutoPtr<User> get_processed_by();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0pred_list();
    const std::string& get_type_str();
    const std::string& get_status_str();
    const std::string& get_state_str();
    bool get_can_process();
    const std::string& get_update_str();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ic();
    const std::string& get_scope_str();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0LogRelation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RequestObject")

   virtual ~RequestObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
