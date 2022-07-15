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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONMASTER_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALIDATIONMASTER_FORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ValidationResult;


class TCSOACLIENTMNGD_API ValidationMaster_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    bool get_compound_result();
    int get_compound_status();
    size_t count_validation_result_objs();
    Teamcenter::Soa::Common::AutoPtr<ValidationResult> get_validation_result_objs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValidationMaster_Form")

   virtual ~ValidationMaster_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
