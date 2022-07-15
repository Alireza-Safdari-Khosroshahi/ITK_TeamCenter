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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_DITAVALFILTERTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_DITAVALFILTERTBL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TableProperties.hxx>

#include <teamcenter/soa/client/model/ContmgmtditaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTDITAMODELMNGD_API DC_DitaValFilterTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_dtDitaAttributeName();
    const std::string& get_dtDitaValue();
    const std::string& get_dtDitaAction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_DitaValFilterTbl")

   virtual ~DC_DitaValFilterTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtditaMngd_undef.h>
#endif
