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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RLZ0ITEMREALIZATIONMAP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RLZ0ITEMREALIZATIONMAP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Rlz0RealizationMap.hxx>

#include <teamcenter/soa/client/model/RealizationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAREALIZATIONMODELMNGD_API Rlz0ItemRealizationMap : public Teamcenter::Soa::Client::Model::Rlz0RealizationMap
{
public:
    const std::string& get_rlz0source_occ_id();
    bool get_rlz0is_source_occ_id_fnv();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Rlz0ItemRealizationMap")

   virtual ~Rlz0ItemRealizationMap();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/RealizationMngd_undef.h>
#endif
