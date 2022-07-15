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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEPERSISTENTCONNECTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEPERSISTENTCONNECTION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/AIEConnection.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AIEBatchOperation;


class TCSOACLIENTMNGD_API AIEPersistentConnection : public Teamcenter::Soa::Client::Model::AIEConnection
{
public:
    size_t count_batch_refs();
    Teamcenter::Soa::Common::AutoPtr<AIEBatchOperation> get_batch_refs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEPersistentConnection")

   virtual ~AIEPersistentConnection();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
