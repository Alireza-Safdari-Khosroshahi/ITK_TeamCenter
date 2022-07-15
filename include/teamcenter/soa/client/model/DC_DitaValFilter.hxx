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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_DITAVALFILTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_DITAVALFILTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_Admin.hxx>

#include <teamcenter/soa/client/model/ContmgmtditaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DC_DitaValFilterTbl;


class TCSOACONTMGMTDITAMODELMNGD_API DC_DitaValFilter : public Teamcenter::Soa::Client::Model::DC_Admin
{
public:
    const std::string& get_ditaFilterName();
    size_t count_ditaValFilterTbl();
    Teamcenter::Soa::Common::AutoPtr<DC_DitaValFilterTbl> get_ditaValFilterTbl_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_DitaValFilter")

   virtual ~DC_DitaValFilter();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtditaMngd_undef.h>
#endif
