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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_XMLATTRMAPTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_XMLATTRMAPTBL_HXX

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


class TCSOACONTMGMTBASEMODELMNGD_API DCt_XmlAttrMapTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_xamFunction();
    const std::string& get_xamAttributeName();
    const std::string& get_xamConstantValue();
    const std::string& get_xamFieldSeparator();
    const std::string& get_xamFixedFieldLength();
    const std::string& get_xamPath();
    bool get_xamOmitEmptyAttribute();
    const std::string& get_xamProcedure();
    Teamcenter::Soa::Common::AutoPtr<DC_ProcedureRevision> get_ctm0ProcedureTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_XmlAttrMapTbl")

   virtual ~DCt_XmlAttrMapTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
