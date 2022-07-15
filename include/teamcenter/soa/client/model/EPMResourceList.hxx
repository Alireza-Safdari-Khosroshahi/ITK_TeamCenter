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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMRESOURCELIST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMRESOURCELIST_HXX

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
                class EPMSignoffProfile;
                class POM_system_class;


class TCSOACLIENTMNGD_API EPMResourceList : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::IntVector& get_actions();
    size_t count_profiles();
    Teamcenter::Soa::Common::AutoPtr<EPMSignoffProfile> get_profiles_at( size_t inx );
    int get_ack_quorum();
    int get_rev_quorum();
    int get_wait_for_all_reviewers();
    size_t count_resources();
    Teamcenter::Soa::Common::AutoPtr<POM_system_class> get_resources_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMResourceList")

   virtual ~EPMResourceList();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
