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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_INSTALLEDTEMPLATES_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_INSTALLEDTEMPLATES_HXX

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


class TCSOACLIENTMNGD_API InstalledTemplates : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const std::string& get_fnd0OpsDeployCS();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LastOpsDeployDate();
    const std::string& get_fnd0LastOpsDeployClientID();
    const std::string& get_fnd0FullDeployCS();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LastFullDeployDate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("InstalledTemplates")

   virtual ~InstalledTemplates();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
