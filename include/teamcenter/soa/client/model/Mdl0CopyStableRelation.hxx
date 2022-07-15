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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0COPYSTABLERELATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0COPYSTABLERELATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAAPPMODELMODELMNGD_API Mdl0CopyStableRelation : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const std::string& get_mdl0cs_id();
    const Teamcenter::Soa::Common::DateTime& get_mdl0secondary_revision_lmd();
    bool get_mdl0sync_secondary_revision();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0CopyStableRelation")

   virtual ~Mdl0CopyStableRelation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
