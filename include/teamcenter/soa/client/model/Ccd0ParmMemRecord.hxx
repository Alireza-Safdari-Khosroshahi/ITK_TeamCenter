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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCD0PARMMEMRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCD0PARMMEMRECORD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mem0MemoryRecord.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ParmDefRevision;


class TCSOACCDMMODELMNGD_API Ccd0ParmMemRecord : public Teamcenter::Soa::Client::Model::Mem0MemoryRecord
{
public:
    Teamcenter::Soa::Common::AutoPtr<ParmDefRevision> get_ccd0ParmDefRevision();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ccd0ParmMemRecord")

   virtual ~Ccd0ParmMemRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
