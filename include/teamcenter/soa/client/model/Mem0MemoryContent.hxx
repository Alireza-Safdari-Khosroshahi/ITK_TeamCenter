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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYCONTENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYCONTENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mem0MemoryBlock;
                class Mem0MemoryRecord;


class TCSOACCDMMODELMNGD_API Mem0MemoryContent : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_mem0MemoryBlocks();
    Teamcenter::Soa::Common::AutoPtr<Mem0MemoryBlock> get_mem0MemoryBlocks_at( size_t inx );
    size_t count_mem0MemoryRecords();
    Teamcenter::Soa::Common::AutoPtr<Mem0MemoryRecord> get_mem0MemoryRecords_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mem0MemoryContent")

   virtual ~Mem0MemoryContent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
