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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPCOMPONENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPCOMPONENTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASPECMGRMODELMNGD_API CPComponentRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_component_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Component();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPComponentRevision")

   virtual ~CPComponentRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
