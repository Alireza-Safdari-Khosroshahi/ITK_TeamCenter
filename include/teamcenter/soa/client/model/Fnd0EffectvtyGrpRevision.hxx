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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0EFFECTVTYGRPREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0EFFECTVTYGRPREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Effectivity;


class TCSOACLIENTMNGD_API Fnd0EffectvtyGrpRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    size_t count_Fnd0EffectivityList();
    Teamcenter::Soa::Common::AutoPtr<Effectivity> get_Fnd0EffectivityList_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0EffectvtyGrpRevision")

   virtual ~Fnd0EffectvtyGrpRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
