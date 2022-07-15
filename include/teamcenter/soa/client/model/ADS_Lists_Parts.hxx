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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADS_LISTS_PARTS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADS_LISTS_PARTS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/model/AdsfoundationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAADSFOUNDATIONMODELMNGD_API ADS_Lists_Parts : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const std::string& get_adsdrawing_find_number();
    const std::string& get_adsdrawing_zone();
    const std::string& get_adsremarks();
    const Teamcenter::Soa::Client::StringVector& get_ads0notenumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADS_Lists_Parts")

   virtual ~ADS_Lists_Parts();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
