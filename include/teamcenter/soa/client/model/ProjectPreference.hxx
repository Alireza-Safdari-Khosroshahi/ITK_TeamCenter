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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROJECTPREFERENCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROJECTPREFERENCE_HXX

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
                class ImanType;


class TCSOACLIENTMNGD_API ProjectPreference : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_preference_name();
    const std::string& get_preference_desc();
    size_t count_relation_type_list();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_relation_type_list_at( size_t inx );
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProjectPreference")

   virtual ~ProjectPreference();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
