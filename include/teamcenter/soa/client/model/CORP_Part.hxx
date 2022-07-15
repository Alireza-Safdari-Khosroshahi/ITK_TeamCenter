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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CORP_PART_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CORP_PART_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API CORP_Part : public Teamcenter::Soa::Client::Model::Item
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Site_Specific();
    const Teamcenter::Soa::Client::ModelObjectVector& get_MakeCost();
    const Teamcenter::Soa::Client::ModelObjectVector& get_BuyCost();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_validate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CORP_Part")

   virtual ~CORP_Part();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
