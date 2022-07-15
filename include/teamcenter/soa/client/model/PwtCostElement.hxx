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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PWTCOSTELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PWTCOSTELEMENT_HXX

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
                class PwtBookTransferData;


class TCSOAGMOMODELMNGD_API PwtCostElement : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_title();
    float get_value();
    const std::string& get_currency();
    const Teamcenter::Soa::Client::StringVector& get_comments();
    const std::string& get_ar_number();
    Teamcenter::Soa::Common::AutoPtr<PwtBookTransferData> get_book_transfer();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PwtCostElement")

   virtual ~PwtCostElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
