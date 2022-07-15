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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SEARCHSTRUCTURECONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SEARCHSTRUCTURECONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/VisStructureContext.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Fnd0EffectvtyGrpRevision;


class TCSOACLIENTMNGD_API SearchStructureContext : public Teamcenter::Soa::Client::Model::VisStructureContext
{
public:
    bool get_fnd0isResultStored();
    const std::string& get_fnd0scopeNames();
    bool get_fnd0shared();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0topline();
    size_t count_fnd0EffectvtyGrpList();
    Teamcenter::Soa::Common::AutoPtr<Fnd0EffectvtyGrpRevision> get_fnd0EffectvtyGrpList_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SearchStructureContext")

   virtual ~SearchStructureContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
