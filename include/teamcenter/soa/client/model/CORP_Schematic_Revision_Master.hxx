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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_SCHEMATIC_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_SCHEMATIC_REVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API CORP_Schematic_Revision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    int get_model_year();
    const std::string& get_build_phase();
    const std::string& get_program();
    const std::string& get_da_check_status();
    const std::string& get_da_checksum();
    const std::string& get_translation_state();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Schematic_Revision_Master")

   virtual ~CORP_Schematic_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
