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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PADISHIKAWAQUALITYFORMC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PADISHIKAWAQUALITYFORMC_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PADQualityFormC.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API PADIshikawaQualityFormC : public Teamcenter::Soa::Client::Model::PADQualityFormC
{
public:
    const Teamcenter::Soa::Client::StringVector& get_environment();
    const Teamcenter::Soa::Client::StringVector& get_equipment();
    const Teamcenter::Soa::Client::StringVector& get_material();
    const Teamcenter::Soa::Client::StringVector& get_methods();
    const Teamcenter::Soa::Client::StringVector& get_people();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PADIshikawaQualityFormC")

   virtual ~PADIshikawaQualityFormC();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
