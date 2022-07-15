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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0EVENTTYPEMAPPING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0EVENTTYPEMAPPING_HXX

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
                class ImanType;
                class ImanType;


class TCSOACLIENTMNGD_API Fnd0EventTypeMapping : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_fnd0AuditType();
    Teamcenter::Soa::Common::AutoPtr<ImanEventType> get_fnd0EventType();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_fnd0ObjectType();
    bool get_fnd0Auditable();
    bool get_fnd0Subscribable();
    const std::string& get_fnd0Description();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_fnd0SecPropAuditType();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0EventTypeMapping")

   virtual ~Fnd0EventTypeMapping();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
