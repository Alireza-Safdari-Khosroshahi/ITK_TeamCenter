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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EXTERNALDATASOURCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EXTERNALDATASOURCE_HXX

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


class TCSOACLIENTMNGD_API ExternalDataSource : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_dsname();
    const std::string& get_hostname();
    const std::string& get_eint_url();
    const std::string& get_adapter_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_accessor();
    const Teamcenter::Soa::Client::ModelObjectVector& get_proxy_accounts();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ExternalDataSource")

   virtual ~ExternalDataSource();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
