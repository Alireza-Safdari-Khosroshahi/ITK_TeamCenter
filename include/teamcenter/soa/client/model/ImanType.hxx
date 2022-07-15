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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANTYPE_HXX

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
                class POM_object;


class TCSOACLIENTMNGD_API ImanType : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_type_name();
    const std::string& get_type_class();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_parent_type();
    bool get_isAbstract();
    int get_category();
    const std::string& get_artifactName();
    const Teamcenter::Soa::Client::ModelObjectVector& get_pseudo_folders();
    const Teamcenter::Soa::Client::ModelObjectVector& get_parent_types();
    int get_child_types_count();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_types();
    const Teamcenter::Soa::Client::ModelObjectVector& get_related_properties();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_types_same_class();
    const Teamcenter::Soa::Client::ModelObjectVector& get_default_child_properties();
    const Teamcenter::Soa::Client::IntVector& get_project_debug();
    const Teamcenter::Soa::Client::ModelObjectVector& get_subtypes_same_class();
    const Teamcenter::Soa::Client::ModelObjectVector& get_subtypes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_primary_types();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_gdetypedef();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanType")

   virtual ~ImanType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
