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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCD0MEMORYOVERRIDERECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCD0MEMORYOVERRIDERECORD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Ccd0ParmDefOverrideRecord.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACCDMMODELMNGD_API Ccd0MemoryOverrideRecord : public Teamcenter::Soa::Client::Model::Ccd0ParmDefOverrideRecord
{
public:
    const std::string& get_ccd0OffsetAddr();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ccd0MemoryOverrideRecord")

   virtual ~Ccd0MemoryOverrideRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
