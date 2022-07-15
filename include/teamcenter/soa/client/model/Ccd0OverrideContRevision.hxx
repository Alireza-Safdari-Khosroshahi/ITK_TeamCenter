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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCD0OVERRIDECONTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCD0OVERRIDECONTREVISION_HXX

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
                class Ccd0ParmDefOverrideRecord;


class TCSOACCDMMODELMNGD_API Ccd0OverrideContRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    size_t count_ccd0OverrideRecords();
    Teamcenter::Soa::Common::AutoPtr<Ccd0ParmDefOverrideRecord> get_ccd0OverrideRecords_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasInputSource();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasOutputFiles();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ccd0OverrideContRevision")

   virtual ~Ccd0OverrideContRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
