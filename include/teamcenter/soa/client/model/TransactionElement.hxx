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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSACTIONELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSACTIONELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/HierarchicalWSO.hxx>

#include <teamcenter/soa/client/model/TransactionprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ActivityCost;


class TCSOATRANSACTIONPROCESSINGMODELMNGD_API TransactionElement : public Teamcenter::Soa::Client::Model::HierarchicalWSO
{
public:
    const std::string& get_transaction_id();
    const Teamcenter::Soa::Common::DateTime& get_initiation_date();
    const Teamcenter::Soa::Common::DateTime& get_due_date();
    const std::string& get_approval();
    const std::string& get_disposition();
    const Teamcenter::Soa::Common::DateTime& get_disposition_date();
    const std::string& get_dispositioned_by();
    const std::string& get_transaction_element_type();
    const std::string& get_mropurpose();
    Teamcenter::Soa::Common::AutoPtr<ActivityCost> get_activity_cost();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();
    const Teamcenter::Soa::Client::ModelObjectVector& get_InProgress();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Completed();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TransactionElement")

   virtual ~TransactionElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/TransactionprocessingMngd_undef.h>
#endif
