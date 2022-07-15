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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0AUDITDEFPROPERTY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0AUDITDEFPROPERTY_HXX

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
                class Fnd0AuditDefinition;
                class ImanType;


class TCSOACLIENTMNGD_API Fnd0AuditDefProperty : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Fnd0AuditDefinition> get_fnd0AuditDef();
    bool get_fnd0IsSecondary();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_fnd0ObjectType();
    const std::string& get_fnd0PropName();
    const std::string& get_fnd0TargetPropName();
    const std::string& get_fnd0OvlTargetPropName();
    const std::string& get_fnd0RefDisplayPropName();
    const std::string& get_fnd0OvlRefDisplayPropName();
    int get_fnd0EnableTracking();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0AuditDefProperty")

   virtual ~Fnd0AuditDefProperty();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
