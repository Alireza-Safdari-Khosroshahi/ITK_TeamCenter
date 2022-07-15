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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SUPERCEDURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SUPERCEDURE_HXX

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
                class BomChange;
                class BomChange;


class TCSOACLIENTMNGD_API Supercedure : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_is_transfer();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_affected_bvr();
    size_t count_bom_add_list();
    Teamcenter::Soa::Common::AutoPtr<BomChange> get_bom_add_list_at( size_t inx );
    size_t count_bom_cancel_list();
    Teamcenter::Soa::Common::AutoPtr<BomChange> get_bom_cancel_list_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cancels();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ec_rev_tag();
    const std::string& get_object_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_custom_form_tag();
    const std::string& get_object_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Adds();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_problem_bvr();
    const std::string& get_object_full_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Supercedure")

   virtual ~Supercedure();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
