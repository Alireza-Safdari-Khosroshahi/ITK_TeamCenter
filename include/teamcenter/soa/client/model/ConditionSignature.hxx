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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONDITIONSIGNATURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONDITIONSIGNATURE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ConditionParameter;


class TCSOACLIENTMNGD_API ConditionSignature : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_condition_parameters();
    Teamcenter::Soa::Common::AutoPtr<ConditionParameter> get_condition_parameters_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConditionSignature")

   virtual ~ConditionSignature();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
