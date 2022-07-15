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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGEITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGEITEMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Company;


class TCSOACMMODELMNGD_API ChangeItemRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_CMClosure();
    const std::string& get_CMDisposition();
    const std::string& get_CMMaturity();
    const std::string& get_CMClosureComments();
    const std::string& get_CMDispositionComments();
    const Teamcenter::Soa::Common::DateTime& get_CMClosureDate();
    const Teamcenter::Soa::Common::DateTime& get_CMDispositionDate();
    size_t count_customers();
    Teamcenter::Soa::Common::AutoPtr<Company> get_customers_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMHasImpactedItem();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMHasProblemItem();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMHasSolutionItem();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMHasWorkBreakdown();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMReferences();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMImplements();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CMImplementedBy();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Analyst();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ChangeImplementationBoard();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ChangeReviewBoard();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ChangeSpecialist1();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ChangeSpecialist2();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ChangeSpecialist3();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Requestor();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cm0Incorporates();
    const std::string& get_analyst_user_id();
    const std::string& get_change_specialist1_user_id();
    const std::string& get_change_specialist2_user_id();
    const std::string& get_change_specialist3_user_id();
    const std::string& get_requestor_user_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ChangeItemRevision")

   virtual ~ChangeItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
