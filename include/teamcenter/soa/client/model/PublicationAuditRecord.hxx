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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PUBLICATIONAUDITRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PUBLICATIONAUDITRECORD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POMImc;


class TCSOACLIENTMNGD_API PublicationAuditRecord : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_par_published_object();
    const std::string& get_par_publishing_user();
    const Teamcenter::Soa::Common::DateTime& get_par_publication_date();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_par_target_site();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PublicationAuditRecord")

   virtual ~PublicationAuditRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
