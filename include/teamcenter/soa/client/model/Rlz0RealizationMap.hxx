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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RLZ0REALIZATIONMAP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RLZ0REALIZATIONMAP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/RealizationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Rlz0Realization;


class TCSOAREALIZATIONMODELMNGD_API Rlz0RealizationMap : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Rlz0Realization> get_rlz0realization();
    const std::string& get_rlz0cs_id();
    const std::string& get_rlz0target();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Rlz0RealizationMap")

   virtual ~Rlz0RealizationMap();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/RealizationMngd_undef.h>
#endif
