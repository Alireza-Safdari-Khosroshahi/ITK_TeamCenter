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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0LICENSESERVER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0LICENSESERVER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POMImc;


class TCSOACLIENTMNGD_API Fnd0LicenseServer : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_fnd0name();
    const std::string& get_fnd0host_name();
    int get_fnd0license_port();
    int get_fnd0protocol();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_fnd0site();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0LicenseServer")

   virtual ~Fnd0LicenseServer();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
