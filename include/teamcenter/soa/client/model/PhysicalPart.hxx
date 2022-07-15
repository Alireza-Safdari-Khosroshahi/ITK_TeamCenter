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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALPART_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALPART_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PhysicalElement.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API PhysicalPart : public Teamcenter::Soa::Client::Model::PhysicalElement
{
public:
    const Teamcenter::Soa::Common::DateTime& get_manufacturingDate();
    bool get_isSerialized();
    bool get_isLot();
    const std::string& get_physicalUID();
    double get_physicalQuantity();
    const std::string& get_serialNumber();
    const std::string& get_partNumber();
    bool get_lifeLimited();
    bool get_isConsumable();
    bool get_isRotable();
    const Teamcenter::Soa::Client::ModelObjectVector& get_AllowedDeviation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PhysicalPartManufacturer();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalPart")

   virtual ~PhysicalPart();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
