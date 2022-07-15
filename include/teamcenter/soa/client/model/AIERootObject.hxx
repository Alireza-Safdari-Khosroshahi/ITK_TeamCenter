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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEROOTOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEROOTOBJECT_HXX

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
                class VariantRule;
                class RevisionRule;
                class Folder;


class TCSOACLIENTMNGD_API AIERootObject : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_target_object();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_datasets();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_item_revision();
    bool get_root_configured();
    bool get_export_as_assembly();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_naming_rule();
    const Teamcenter::Soa::Common::DateTime& get_effectivity_date();
    Teamcenter::Soa::Common::AutoPtr<VariantRule> get_variant_rule();
    Teamcenter::Soa::Common::AutoPtr<RevisionRule> get_revision_rule();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_override_folder();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIERootObject")

   virtual ~AIERootObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
