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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONMASTERS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONMASTERS_HXX

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
                class IRValidationResultS;


class TCSOAGMOMODELMNGD_API IRValidationMasterS : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_validations();
    Teamcenter::Soa::Common::AutoPtr<IRValidationResultS> get_validations_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRValidationMasterS")

   virtual ~IRValidationMasterS();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
