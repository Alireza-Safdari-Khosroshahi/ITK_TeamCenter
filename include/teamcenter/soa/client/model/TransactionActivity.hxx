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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSACTIONACTIVITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSACTIONACTIVITY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TransactionElement.hxx>

#include <teamcenter/soa/client/model/TransactionprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOATRANSACTIONPROCESSINGMODELMNGD_API TransactionActivity : public Teamcenter::Soa::Client::Model::TransactionElement
{
public:
    const std::string& get_transaction_note();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TransactionActivity")

   virtual ~TransactionActivity();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/TransactionprocessingMngd_undef.h>
#endif
