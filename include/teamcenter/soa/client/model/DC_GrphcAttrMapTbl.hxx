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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_GRPHCATTRMAPTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_GRPHCATTRMAPTBL_HXX

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


class TCSOACONTMGMTBASEMODELMNGD_API DC_GrphcAttrMapTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_gamFunction();
    const std::string& get_gamFieldName();
    const std::string& get_gamAttributeName();
    const std::string& get_gamConstantValue();
    const std::string& get_gamFieldSeparator();
    const std::string& get_gamFixedFieldLength();
    const std::string& get_gamCapitalizationBehaviour();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_GrphcAttrMapTbl")

   virtual ~DC_GrphcAttrMapTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
