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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWT_CHANGESERVICEDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWT_CHANGESERVICEDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API PWT_ChangeServiceData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_interchng_prod_parts();
    const std::string& get_interchng_serv_parts();
    const std::string& get_chng_mold_irreverse();
    const std::string& get_impact_handbook();
    const std::string& get_impact_stnds();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PWT_ChangeServiceData")

   virtual ~PWT_ChangeServiceData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
