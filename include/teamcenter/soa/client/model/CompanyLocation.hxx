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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_COMPANYLOCATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_COMPANYLOCATION_HXX

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


class TCSOACLIENTMNGD_API CompanyLocation : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_street();
    const std::string& get_city();
    const std::string& get_state_province();
    const std::string& get_postal_code();
    const std::string& get_country();
    const std::string& get_region();
    const std::string& get_url();
    const std::string& get_fnd0LocationType();
    const std::string& get_fnd0LocationCode();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ContactInCompany();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CompanyLocation")

   virtual ~CompanyLocation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
