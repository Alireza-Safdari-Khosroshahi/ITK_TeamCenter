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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROJECTOBJECTRELATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROJECTOBJECTRELATION_HXX

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
                class Project;
                class Project;


class TCSOACLIENTMNGD_API ProjectObjectRelation : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_top_level_proj_obj();
    const Teamcenter::Soa::Client::ModelObjectVector& get_propagation_obj_list();
    const Teamcenter::Soa::Common::DateTime& get_proj_list_mod_date();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();
    const std::string& get_ip_classification();
    const std::string& get_gov_classification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_license_list();
    size_t count_project_list();
    Teamcenter::Soa::Common::AutoPtr<Project> get_project_list_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Project> get_owning_project();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProjectObjectRelation")

   virtual ~ProjectObjectRelation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
