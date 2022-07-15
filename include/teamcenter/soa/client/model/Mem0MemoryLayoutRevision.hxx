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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYLAYOUTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYLAYOUTREVISION_HXX

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
                class Mem0MemoryContent;


class TCSOACCDMMODELMNGD_API Mem0MemoryLayoutRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mem0HeaderObject();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mem0TrailerObject();
    const std::string& get_mem0StartAddress();
    Teamcenter::Soa::Common::AutoPtr<Mem0MemoryContent> get_mem0MemoryContent();
    int get_mem0Size();
    const Teamcenter::Soa::Client::StringVector& get_mem0MirroredOffset();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mem0MemoryLayoutRevision")

   virtual ~Mem0MemoryLayoutRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
