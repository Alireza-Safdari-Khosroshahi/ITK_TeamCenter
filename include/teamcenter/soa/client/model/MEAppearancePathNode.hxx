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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEAPPEARANCEPATHNODE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEAPPEARANCEPATHNODE_HXX

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
                class MEAppearancePathRoot;
                class AbsOccurrence;
                class AbsOccurrence;
                class Appearance;
                class PSOccurrenceThread;


class TCSOACLIENTMNGD_API MEAppearancePathNode : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_parent();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_next_level();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathRoot> get_path_root();
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_abs_occ();
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_parent_abs_occ();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();
    size_t count_appearance_list();
    Teamcenter::Soa::Common::AutoPtr<Appearance> get_appearance_list_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceThread> get_occ_thread();
    const Teamcenter::Soa::Client::ModelObjectVector& get_child_nodes();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEAppearancePathNode")

   virtual ~MEAppearancePathNode();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
