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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_TRANSFPOLICY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_TRANSFPOLICY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_Admin.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DC_TransfPolTbl;


class TCSOACONTMGMTBASEMODELMNGD_API DC_TransfPolicy : public Teamcenter::Soa::Client::Model::DC_Admin
{
public:
    const std::string& get_policyName();
    const std::string& get_adminComment();
    size_t count_transfPolTbl();
    Teamcenter::Soa::Common::AutoPtr<DC_TransfPolTbl> get_transfPolTbl_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_TransfPolicy")

   virtual ~DC_TransfPolicy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
