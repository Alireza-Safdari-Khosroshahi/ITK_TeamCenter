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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AURVIRFORINCRCHANGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AURVIRFORINCRCHANGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprUpdRevViewImpactsRoot.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class IncrementalChangeElement;


class TCSOACLIENTMNGD_API AurvirForIncrChange : public Teamcenter::Soa::Client::Model::ApprUpdRevViewImpactsRoot
{
public:
    size_t count_change_elems();
    Teamcenter::Soa::Common::AutoPtr<IncrementalChangeElement> get_change_elems_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AurvirForIncrChange")

   virtual ~AurvirForIncrChange();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
