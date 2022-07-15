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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RLZ0MODELREALIZATIONMAP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RLZ0MODELREALIZATIONMAP_HXX

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
                class POM_object;


class TCSOAREALIZATIONMODELMNGD_API Rlz0ModelRealizationMap : public Teamcenter::Soa::Client::Model::Rlz0RealizationMap
{
public:
    bool get_rlz0is_realized();
    const std::string& get_rlz0source();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_rlz0source_object();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Rlz0ModelRealizationMap")

   virtual ~Rlz0ModelRealizationMap();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/RealizationMngd_undef.h>
#endif
