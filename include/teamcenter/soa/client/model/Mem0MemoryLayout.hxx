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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYLAYOUT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEM0MEMORYLAYOUT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACCDMMODELMNGD_API Mem0MemoryLayout : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_mem0PrgType();
    const std::string& get_mem0MemoryType();
    const std::string& get_mem0Attribute();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mem0MemoryLayout")

   virtual ~Mem0MemoryLayout();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
