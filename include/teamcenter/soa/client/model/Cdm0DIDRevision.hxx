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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0DIDREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0DIDREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0DIDRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_cdm0DIDHasDataReqItem();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0DIDRevision")

   virtual ~Cdm0DIDRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
