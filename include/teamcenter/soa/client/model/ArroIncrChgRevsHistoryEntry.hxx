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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ARROINCRCHGREVSHISTORYENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ARROINCRCHGREVSHISTORYENTRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ArroHistoryEntry.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ItemRevision;


class TCSOACLIENTMNGD_API ArroIncrChgRevsHistoryEntry : public Teamcenter::Soa::Client::Model::ArroHistoryEntry
{
public:
    size_t count_incr_change_revs();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_incr_change_revs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ArroIncrChgRevsHistoryEntry")

   virtual ~ArroIncrChgRevsHistoryEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
