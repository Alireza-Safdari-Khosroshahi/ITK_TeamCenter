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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DATASETTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DATASETTYPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Tool;
                class Tool;


class TCSOACLIENTMNGD_API DatasetType : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_datasettype_name();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_parent_type();
    const std::string& get_description();
    int get_action_list();
    const Teamcenter::Soa::Client::StringVector& get_named_ref_list();
    size_t count_list_of_tools();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_list_of_tools_at( size_t inx );
    size_t count_list_of_tools_view();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_list_of_tools_view_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatasetType")

   virtual ~DatasetType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
