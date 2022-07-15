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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYBLOCK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYBLOCK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mem0MemoryRecord;


class TCSOACCDMMODELMNGD_API Mem0MemoryBlock : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mem0HeaderObject();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mem0TrailerObject();
    const std::string& get_mem0StartAddress();
    size_t count_mem0MemoryBlocks();
    Teamcenter::Soa::Common::AutoPtr<Mem0MemoryBlock> get_mem0MemoryBlocks_at( size_t inx );
    size_t count_mem0MemoryRecords();
    Teamcenter::Soa::Common::AutoPtr<Mem0MemoryRecord> get_mem0MemoryRecords_at( size_t inx );
    const std::string& get_mem0BlockName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mem0MemoryBlock")

   virtual ~Mem0MemoryBlock();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
