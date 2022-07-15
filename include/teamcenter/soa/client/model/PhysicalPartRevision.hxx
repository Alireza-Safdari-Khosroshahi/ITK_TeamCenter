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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALPARTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALPARTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PhysicalElementRevision.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Lot;


class TCSOAMROCOREMODELMNGD_API PhysicalPartRevision : public Teamcenter::Soa::Client::Model::PhysicalElementRevision
{
public:
    const std::string& get_partNumber();
    const std::string& get_serialNumber();
    const std::string& get_manufacturerOrgId();
    bool get_isAsBuiltRevision();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_configContextTag();
    const std::string& get_neutralBOMView();
    Teamcenter::Soa::Common::AutoPtr<Lot> get_lotTag();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PhysicalContext();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PhysicalRealization();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalPartRevision")

   virtual ~PhysicalPartRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
