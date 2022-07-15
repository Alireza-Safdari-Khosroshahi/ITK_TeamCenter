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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPADVERSIONMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPADVERSIONMASTER_HXX

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


class TCSOACMTPADTWPMODELMNGD_API MEPADVersionMaster : public Teamcenter::Soa::Client::Model::MEProcessTypeVersionMaster
{
public:
    const std::string& get_prd_dev_team();
    const std::string& get_bk_year();
    const std::string& get_bk();
    const std::string& get_pad_upc();
    const std::string& get_ecl();
    const std::string& get_erg_eval();
    const std::string& get_bestfitvpps();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEPADVersionMaster")

   virtual ~MEPADVersionMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
