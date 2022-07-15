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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAELOADITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAELOADITEMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CAELoadItemRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_vault_mode();
    const std::string& get_eint_form_type();
    const Teamcenter::Soa::Client::StringVector& get_criteria_names();
    const Teamcenter::Soa::Client::StringVector& get_criteria_values();
    const std::string& get_link_path();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAELoadItemRevision")

   virtual ~CAELoadItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
