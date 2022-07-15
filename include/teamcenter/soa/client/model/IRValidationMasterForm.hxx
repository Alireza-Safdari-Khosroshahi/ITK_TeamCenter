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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONMASTERFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRVALIDATIONMASTERFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

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


class TCSOAGMOMODELMNGD_API IRValidationMasterForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    size_t count_validations();
    Teamcenter::Soa::Common::AutoPtr<IRValidationResultS> get_validations_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRValidationMasterForm")

   virtual ~IRValidationMasterForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
