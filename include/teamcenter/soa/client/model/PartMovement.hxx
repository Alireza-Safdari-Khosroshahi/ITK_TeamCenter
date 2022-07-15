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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARTMOVEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARTMOVEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/ServiceprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PhysicalElement;
                class PhysicalPart;
                class ItemRevision;
                class PhysicalElementRevision;
                class PhysicalLocation;


class TCSOASERVICEPROCESSINGMODELMNGD_API PartMovement : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_manufacture_id();
    const std::string& get_part_number();
    const std::string& get_serial_number();
    const std::string& get_lot_number();
    const std::string& get_usage_name();
    bool get_is_traceable();
    const std::string& get_part_movement_type();
    bool get_is_new();
    bool get_is_approved_deviation();
    const Teamcenter::Soa::Common::DateTime& get_action_date();
    const std::string& get_new_part_class();
    const std::string& get_new_part_name();
    Teamcenter::Soa::Common::AutoPtr<PhysicalElement> get_parent_physical_element();
    Teamcenter::Soa::Common::AutoPtr<PhysicalPart> get_physical_part();
    bool get_is_extra_to_design();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_spr0neutralPart();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_spr0movedOccurrence();
    Teamcenter::Soa::Common::AutoPtr<PhysicalElementRevision> get_spr0replacedPart();
    Teamcenter::Soa::Common::AutoPtr<PhysicalLocation> get_spr0removeLocation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MovedPart();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PartMovement")

   virtual ~PartMovement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceprocessingMngd_undef.h>
#endif
