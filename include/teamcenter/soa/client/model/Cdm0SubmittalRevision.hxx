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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0SUBMITTALREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0SUBMITTALREVISION_HXX

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


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0SubmittalRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const std::string& get_cdm0Disposition();
    const Teamcenter::Soa::Common::DateTime& get_cdm0DispositionDate();
    const std::string& get_cdm0DRLItemType();
    const std::string& get_cdm0OfficePriResp();
    const Teamcenter::Soa::Common::DateTime& get_cdm0ReceivedDate();
    const std::string& get_cdm0ResubmitComments();
    const Teamcenter::Soa::Common::DateTime& get_cdm0ResubmitDueDate();
    bool get_cdm0ResubmitRequired();
    const std::string& get_cdm0ShippingDocumentName();
    const Teamcenter::Soa::Common::DateTime& get_cdm0SubmitDueDate();
    const std::string& get_cdm0SubmittalMaturity();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cdm0ListsCorspSubmittals();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cdm0SubmitalHasDataReqItem();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0SubmittalRevision")

   virtual ~Cdm0SubmittalRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
