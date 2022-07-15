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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRREVRELATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRREVRELATION_HXX

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
                class Appearance;
                class AppearanceRoot;
                class ItemRevision;
                class ItemRevision;


class TCSOACLIENTMNGD_API ApprRevRelation : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_creation_date();
    size_t count_appearances();
    Teamcenter::Soa::Common::AutoPtr<Appearance> get_appearances_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<AppearanceRoot> get_appr_root();
    size_t count_valid_revs();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_valid_revs_at( size_t inx );
    size_t count_impacting_incr_change_revs();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_impacting_incr_change_revs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprRevRelation")

   virtual ~ApprRevRelation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
