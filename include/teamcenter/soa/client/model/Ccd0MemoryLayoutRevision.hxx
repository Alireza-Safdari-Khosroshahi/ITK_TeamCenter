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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCD0MEMORYLAYOUTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCD0MEMORYLAYOUTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mem0MemoryLayoutRevision.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACCDMMODELMNGD_API Ccd0MemoryLayoutRevision : public Teamcenter::Soa::Client::Model::Mem0MemoryLayoutRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasInputSource();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasOutputFiles();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ccd0MemoryLayoutRevision")

   virtual ~Ccd0MemoryLayoutRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
