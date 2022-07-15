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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMGRPVALREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMGRPVALREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ParmGrpDefRevision;
                class ParmVal;


class TCSOACCDMMODELMNGD_API ParmGrpValRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<ParmGrpDefRevision> get_masterDefRev();
    size_t count_parmValues();
    Teamcenter::Soa::Common::AutoPtr<ParmVal> get_parmValues_at( size_t inx );
    const std::string& get_masterDefGenericCompId();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmGrpValRevision")

   virtual ~ParmGrpValRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
