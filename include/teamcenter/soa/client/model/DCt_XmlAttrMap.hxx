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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_XMLATTRMAP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_XMLATTRMAP_HXX

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
                class DC_NamspacesTbl;
                class DCt_XmlAttrMapTbl;


class TCSOACONTMGMTBASEMODELMNGD_API DCt_XmlAttrMap : public Teamcenter::Soa::Client::Model::DC_Admin
{
public:
    const std::string& get_xmlAttrMapName();
    const std::string& get_adminComment();
    size_t count_namespacesTbl();
    Teamcenter::Soa::Common::AutoPtr<DC_NamspacesTbl> get_namespacesTbl_at( size_t inx );
    size_t count_xmlAttrMapTbl();
    Teamcenter::Soa::Common::AutoPtr<DCt_XmlAttrMapTbl> get_xmlAttrMapTbl_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_XmlAttrMap")

   virtual ~DCt_XmlAttrMap();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
