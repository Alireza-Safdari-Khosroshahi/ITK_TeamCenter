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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DISCIPLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DISCIPLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_system_class.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Discipline : public Teamcenter::Soa::Client::Model::POM_system_class
{
public:
    const std::string& get_discipline_name();
    const std::string& get_description();
    double get_default_rate();
    const std::string& get_default_currency();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_discipline_member();
    const std::string& get_object_name();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Discipline")

   virtual ~Discipline();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
