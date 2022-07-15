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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cpd0DesignModelElement.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ItemRevision;


class TCSOACPDMODELMNGD_API Cpd0DesignElement : public Teamcenter::Soa::Client::Model::Cpd0DesignModelElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_cpd0source_object();
    const std::string& get_cpd0UG_ENTITY_HANDLE();
    const std::string& get_cpd0thread_in_parent_source();
    bool get_cpd0is_leaf();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cpd0instance();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cpd0thumbnail_ds();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cpd0where_partitioned();
    bool get_cpd0source_not_latest();
    bool get_cpd0structure_requires_sync();
    bool get_cpd0source_frozen();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cpd0subordinates();
    const std::string& get_cpd0source_object_id();
    const std::string& get_cpd0source_object_name();
    const std::string& get_cpd0source_object_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cpd0source_specifications();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignElement")

   virtual ~Cpd0DesignElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
