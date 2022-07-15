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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPCOMPONENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPCOMPONENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASPECMGRMODELMNGD_API CPComponent : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_ingredient_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPComponent")

   virtual ~CPComponent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
