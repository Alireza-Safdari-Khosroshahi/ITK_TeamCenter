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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_NAMSPACESTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_NAMSPACESTBL_HXX

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


class TCSOACONTMGMTBASEMODELMNGD_API DC_NamspacesTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_nsPrefix();
    const std::string& get_nsNamespaceUri();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_NamspacesTbl")

   virtual ~DC_NamspacesTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
