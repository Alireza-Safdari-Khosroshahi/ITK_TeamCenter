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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ARROVALIDREVSHISTORYENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ARROVALIDREVSHISTORYENTRY_HXX

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


class TCSOACLIENTMNGD_API ArroValidRevsHistoryEntry : public Teamcenter::Soa::Client::Model::ArroHistoryEntry
{
public:
    size_t count_valid_revs();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_valid_revs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ArroValidRevsHistoryEntry")

   virtual ~ArroValidRevsHistoryEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
