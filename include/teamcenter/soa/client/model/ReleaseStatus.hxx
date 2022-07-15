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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RELEASESTATUS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RELEASESTATUS_HXX

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


class TCSOACLIENTMNGD_API ReleaseStatus : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const Teamcenter::Soa::Common::DateTime& get_start_date();
    const Teamcenter::Soa::Common::DateTime& get_end_date();
    int get_start_serial_number();
    int get_end_serial_number();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_authorization();
    const Teamcenter::Soa::Common::DateTime& get_date_released();
    const Teamcenter::Soa::Client::ModelObjectVector& get_effectivities();
    const Teamcenter::Soa::Client::ModelObjectVector& get_effs_to_destroy();
    const std::string& get_effectivity_text();
    const std::string& get_object_name();
    const std::string& get_object_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ReleaseStatus")

   virtual ~ReleaseStatus();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
