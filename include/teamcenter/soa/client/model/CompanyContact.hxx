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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_COMPANYCONTACT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_COMPANYCONTACT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CompanyContact : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_first_name();
    const std::string& get_last_name();
    const std::string& get_title();
    const std::string& get_suffix();
    const std::string& get_phone_business();
    const std::string& get_phone_home();
    const std::string& get_phone_mobile();
    const std::string& get_fax_number();
    const std::string& get_pager_number();
    const std::string& get_email_address();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CompanyContact")

   virtual ~CompanyContact();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
