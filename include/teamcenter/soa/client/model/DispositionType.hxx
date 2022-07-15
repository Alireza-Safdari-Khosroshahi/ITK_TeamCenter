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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DISPOSITIONTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DISPOSITIONTYPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAASMAINTAINEDMODELMNGD_API DispositionType : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_dispositionValue();
    bool get_isServiceable();
    bool get_isActive();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DispositionType")

   virtual ~DispositionType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
