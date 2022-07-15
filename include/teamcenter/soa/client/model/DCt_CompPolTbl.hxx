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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_COMPPOLTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_COMPPOLTBL_HXX

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


class TCSOACONTMGMTBASEMODELMNGD_API DCt_CompPolTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_cpLeft();
    const std::string& get_cpRelation();
    const std::string& get_cpRight();
    const std::string& get_cpBehaviour();
    bool get_cpMultilevel();
    const std::string& get_ctm0ConditionRef();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_CompPolTbl")

   virtual ~DCt_CompPolTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
