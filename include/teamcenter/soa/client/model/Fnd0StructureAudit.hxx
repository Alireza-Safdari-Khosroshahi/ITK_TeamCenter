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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0STRUCTUREAUDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0STRUCTUREAUDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0AuditLog.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0StructureAudit : public Teamcenter::Soa::Client::Model::Fnd0AuditLog
{
public:
    const std::string& get_comp_orientationOvl();
    const std::string& get_comp_positionOvl();
    const std::string& get_fnd0Reason();
    const std::string& get_fnd0ChangeID();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0Object();
    const std::string& get_object_name();
    const std::string& get_object_type();
    const std::string& get_fnd0ObjectDisplayName();
    const std::string& get_fnd0EventTypeName();
    const std::string& get_fnd0UserId();
    const std::string& get_fnd0GroupName();
    const std::string& get_fnd0RoleName();
    const Teamcenter::Soa::Common::DateTime& get_fnd0LoggedDate();
    const std::string& get_fnd0ErrorMessage();
    int get_fnd0ErrorCode();
    const std::string& get_item_id();
    const std::string& get_item_revision_id();
    const std::string& get_comp_position();
    const std::string& get_comp_orientation();
    int get_sequence_id();
    const std::string& get_note_texts();
    const std::string& get_note_types();
    const std::string& get_note_textsOvl();
    const std::string& get_note_typesOvl();
    const std::string& get_seq_no();
    const std::string& get_occurrence_name();
    const std::string& get_note_typesDisp();
    const std::string& get_note_typesOvlDisp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0SecondaryObject();
    const std::string& get_fnd0SecondaryObjectType();
    const std::string& get_fnd0SecondaryObjectName();
    const std::string& get_fnd0SecondaryObjectID();
    const std::string& get_fnd0SecondaryObjectRevID();
    int get_fnd0SecondaryObjectSeqID();
    const std::string& get_fnd0SecondaryObjDispName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0StructureAudit")

   virtual ~Fnd0StructureAudit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
