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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0AUDITDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0AUDITDEFINITION_HXX

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
                class ImanType;
                class ImanEventType;
                class Condition;
                class Fnd0EventTypeMapping;


class TCSOACLIENTMNGD_API Fnd0AuditDefinition : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_fnd0PrimaryType();
    Teamcenter::Soa::Common::AutoPtr<ImanEventType> get_fnd0EventType();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_fnd0Condition();
    bool get_fnd0IsActive();
    Teamcenter::Soa::Common::AutoPtr<Fnd0EventTypeMapping> get_fnd0EventTypeMap();
    const std::string& get_fnd0Description();
    const Teamcenter::Soa::Client::StringVector& get_fnd0Extensions();
    bool get_fnd0TrackOldValues();
    bool get_fnd0AuditPropertyChangeOnly();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0AuditDefinition")

   virtual ~Fnd0AuditDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
