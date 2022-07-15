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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REVNEXTIDFIELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REVNEXTIDFIELD_HXX

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
                class RevisionNameRuleAttach;


class TCSOACLIENTMNGD_API RevNextIdField : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_init_next_id();
    const std::string& get_sec_next_id();
    const std::string& get_suppl_next_id();
    Teamcenter::Soa::Common::AutoPtr<RevisionNameRuleAttach> get_rev_name_field_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RevNextIdField")

   virtual ~RevNextIdField();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
