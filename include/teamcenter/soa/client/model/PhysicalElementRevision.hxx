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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALELEMENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALELEMENTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API PhysicalElementRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    bool get_isSuperseded();
    bool get_isStandAlone();
    const Teamcenter::Soa::Common::DateTime& get_effectiveFrom();
    const Teamcenter::Soa::Common::DateTime& get_effectiveTo();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_previousRevision();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalElementRevision")

   virtual ~PhysicalElementRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
