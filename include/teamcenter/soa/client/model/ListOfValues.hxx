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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_LISTOFVALUES_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_LISTOFVALUES_HXX

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
                class Condition;
                class Condition;
                class Condition;


class TCSOACLIENTMNGD_API ListOfValues : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_lov_name();
    const std::string& get_lov_desc();
    const std::string& get_lov_type();
    int get_lov_value_type();
    int get_lov_usage();
    int get_lov_attached_type();
    const std::string& get_lov_attached_class();
    const std::string& get_lov_attached_attr();
    const Teamcenter::Soa::Client::StringVector& get_lov_attached_types();
    const Teamcenter::Soa::Client::StringVector& get_lov_attached_properties();
    const Teamcenter::Soa::Client::IntVector& get_lov_attached_specifiers();
    const Teamcenter::Soa::Client::StringVector& get_classification_names();
    const Teamcenter::Soa::Client::IntVector& get_lov_value_indexes();
    const Teamcenter::Soa::Client::StringVector& get_value_classifications();
    const Teamcenter::Soa::Client::IntVector& get_value_filters_indexes();
    size_t count_value_filters();
    Teamcenter::Soa::Common::AutoPtr<ListOfValues> get_value_filters_at( size_t inx );
    const Teamcenter::Soa::Client::BoolVector& get_override_lov_attachments();
    bool get_fnd0isManagedExternally();
    size_t count_lov_attached_conditions();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_lov_attached_conditions_at( size_t inx );
    size_t count_value_filter_conditions();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_value_filter_conditions_at( size_t inx );
    size_t count_lov_value_conditions();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_lov_value_conditions_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_referencing_filters();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ListOfValues")

   virtual ~ListOfValues();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
