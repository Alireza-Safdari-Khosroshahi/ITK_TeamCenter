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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDATERCRONENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDATERCRONENTRY_HXX

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


class TCSOACLIENTMNGD_API ApprUpdaterCronEntry : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_machine();
    const std::string& get_osuser();
    const std::string& get_minute();
    const std::string& get_hour();
    const std::string& get_day_of_month();
    const std::string& get_month_of_year();
    const std::string& get_day_of_week();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdaterCronEntry")

   virtual ~ApprUpdaterCronEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
