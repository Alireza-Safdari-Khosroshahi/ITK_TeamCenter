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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SPR0PARTREQUEST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SPR0PARTREQUEST_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TransactionActivity.hxx>

#include <teamcenter/soa/client/model/ServiceprocessingMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class SavedQueryCriteria;


class TCSOASERVICEPROCESSINGMODELMNGD_API SPR0PartRequest : public Teamcenter::Soa::Client::Model::TransactionActivity
{
public:
    bool get_spr0invalidPart();
    double get_spr0quantityRequested();
    Teamcenter::Soa::Common::AutoPtr<SavedQueryCriteria> get_spr0RequestedPartInfo();
    const std::string& get_spr0partNumber();
    const Teamcenter::Soa::Client::ModelObjectVector& get_SPR0RequestedPart();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SPR0PartRequest")

   virtual ~SPR0PartRequest();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ServiceprocessingMngd_undef.h>
#endif
