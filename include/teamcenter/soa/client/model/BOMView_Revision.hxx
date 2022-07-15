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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BOMVIEW_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BOMVIEW_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PSBOMViewRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API BOMView_Revision : public Teamcenter::Soa::Client::Model::PSBOMViewRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Arrangement();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_external_object_link();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_BaseArrangementAnchor();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_DefaultArrangement();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BOMView_Revision")

   virtual ~BOMView_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
