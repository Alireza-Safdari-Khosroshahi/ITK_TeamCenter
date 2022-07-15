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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TC_PROGRAM_PREFERRED_ITEMS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TC_PROGRAM_PREFERRED_ITEMS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API TC_Program_Preferred_Items : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    bool get_limited_use();
    const std::string& get_limitation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TC_Program_Preferred_Items")

   virtual ~TC_Program_Preferred_Items();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
