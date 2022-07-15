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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPSDVERSIONMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPSDVERSIONMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MEProcessTypeVersionMaster.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API MEPSDVersionMaster : public Teamcenter::Soa::Client::Model::MEProcessTypeVersionMaster
{
public:
    const std::string& get_process_notes();
    const std::string& get_eng_ref();
    const std::string& get_pe_engineer();
    const std::string& get_me_engineer();
    const std::string& get_me_group_leader();
    const std::string& get_assembly_position();
    const std::string& get_assembly_side();
    int get_work_height();
    double get_required_time_for_tryout();
    const std::string& get_restriction_description();
    double get_assembly_time_mpt();
    const std::string& get_PDT();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEPSDVersionMaster")

   virtual ~MEPSDVersionMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
