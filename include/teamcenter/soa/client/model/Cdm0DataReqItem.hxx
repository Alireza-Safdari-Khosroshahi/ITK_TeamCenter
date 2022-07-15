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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0DATAREQITEM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0DATAREQITEM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Cdm0Contract;


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0DataReqItem : public Teamcenter::Soa::Client::Model::Item
{
public:
    const std::string& get_cdm0ContractLineItemNumber();
    const std::string& get_cdm0ReferenceCitation();
    const std::string& get_cdm0ContractReference();
    bool get_cdm0ProvideRecContractDel();
    Teamcenter::Soa::Common::AutoPtr<Cdm0Contract> get_cdm0ContractTypedRef();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0DataReqItem")

   virtual ~Cdm0DataReqItem();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
