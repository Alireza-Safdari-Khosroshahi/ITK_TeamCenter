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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMGRPDEF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMGRPDEF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CalParm.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACCDMMODELMNGD_API ParmGrpDef : public Teamcenter::Soa::Client::Model::CalParm
{
public:
    const std::string& get_represents();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmGrpDef")

   virtual ~ParmGrpDef();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
