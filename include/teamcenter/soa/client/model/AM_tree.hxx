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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AM_TREE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AM_TREE_HXX

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
                class AM_ACL;


class TCSOACLIENTMNGD_API AM_tree : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_rule_name();
    const std::string& get_rule_arg();
    Teamcenter::Soa::Common::AutoPtr<AM_tree> get_parent();
    Teamcenter::Soa::Common::AutoPtr<AM_tree> get_prev();
    bool get_edit_children();
    bool get_expand_below();
    bool get_cut();
    Teamcenter::Soa::Common::AutoPtr<AM_ACL> get_acl();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AM_tree")

   virtual ~AM_tree();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
