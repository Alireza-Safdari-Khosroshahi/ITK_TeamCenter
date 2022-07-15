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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_TRANSFPOLTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_TRANSFPOLTBL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TableProperties.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DC_ProcedureRevision;
                class DC_TrnTool;


class TCSOACONTMGMTBASEMODELMNGD_API DC_TransfPolTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_tpUserAction();
    const std::string& get_tpToolName();
    const std::string& get_tpStyleSheet();
    const std::string& get_tpProcedure();
    Teamcenter::Soa::Common::AutoPtr<DC_ProcedureRevision> get_ctm0ProcedureTagref();
    Teamcenter::Soa::Common::AutoPtr<DC_TrnTool> get_ctm0ToolTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_TransfPolTbl")

   virtual ~DC_TransfPolTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
