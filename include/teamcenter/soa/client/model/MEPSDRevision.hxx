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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPSDREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPSDREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MEProcessRevision.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API MEPSDRevision : public Teamcenter::Soa::Client::Model::MEProcessRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_PADImage();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_PADPreferredImage();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_PADQuality();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_PADReport();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEPSDRevision")

   virtual ~MEPSDRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
