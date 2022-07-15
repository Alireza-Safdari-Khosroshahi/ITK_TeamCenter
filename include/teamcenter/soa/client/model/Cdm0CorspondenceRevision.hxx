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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0CORSPONDENCEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0CORSPONDENCEREVISION_HXX

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


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0CorspondenceRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const std::string& get_cdm0Category();
    const std::string& get_cdm0CorrespondenceDirection();
    const std::string& get_cdm0Priority();
    const std::string& get_cdm0ReceivedOrgName();
    const Teamcenter::Soa::Common::DateTime& get_cdm0ReceivedorSentDate();
    const std::string& get_cdm0References();
    const Teamcenter::Soa::Common::DateTime& get_cdm0ReplyRequestedDate();
    bool get_cdm0ReplyRequired();
    const std::string& get_cdm0ResponsibleParty();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cdm0ListsCorspRefItems();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cdm0CorrespondHasSubmittal();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0CorspondenceRevision")

   virtual ~Cdm0CorspondenceRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
