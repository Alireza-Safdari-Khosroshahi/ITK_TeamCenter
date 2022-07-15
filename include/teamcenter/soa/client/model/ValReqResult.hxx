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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VALREQRESULT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VALREQRESULT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ValidationResult.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ValidationReqRevision;


class TCSOACLIENTMNGD_API ValReqResult : public Teamcenter::Soa::Client::Model::ValidationResult
{
public:
    Teamcenter::Soa::Common::AutoPtr<ValidationReqRevision> get_validation_requirement();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValReqResult")

   virtual ~ValReqResult();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
