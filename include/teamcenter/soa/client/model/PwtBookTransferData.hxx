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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWTBOOKTRANSFERDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWTBOOKTRANSFERDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API PwtBookTransferData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_sender_psp();
    const std::string& get_receiver_psp();
    const Teamcenter::Soa::Common::DateTime& get_sap_date();
    int get_sap_index();
    float get_sap_amount();
    const std::string& get_purchase_req();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PwtBookTransferData")

   virtual ~PwtBookTransferData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
