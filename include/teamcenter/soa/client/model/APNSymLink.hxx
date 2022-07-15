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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APNSYMLINK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APNSYMLINK_HXX

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
                class MEAppearancePathNode;
                class MEAppearancePathNode;
                class MEAppearancePathNode;


class TCSOACLIENTMNGD_API APNSymLink : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_config_bvr();
    bool get_orig_visible();
    const std::string& get_seqno();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_orig_apn();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_symbolic_apn();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_destination_parent_apn();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("APNSymLink")

   virtual ~APNSymLink();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
