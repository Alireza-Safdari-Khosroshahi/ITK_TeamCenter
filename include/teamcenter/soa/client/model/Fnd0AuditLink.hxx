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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0AUDITLINK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0AUDITLINK_HXX

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
                class Fnd0SecondaryAudit;
                class Fnd0AuditLog;


class TCSOACLIENTMNGD_API Fnd0AuditLink : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Fnd0SecondaryAudit> get_fnd0SecondaryAudit();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_fnd0SecondaryQualifier();
    Teamcenter::Soa::Common::AutoPtr<Fnd0AuditLog> get_fnd0PrimaryAudit();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0AuditLink")

   virtual ~Fnd0AuditLink();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
