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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMPERFORMSIGNOFFTASKTEMPLATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMPERFORMSIGNOFFTASKTEMPLATE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/EPMTaskTemplate.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API EPMPerformSignoffTaskTemplate : public Teamcenter::Soa::Client::Model::EPMTaskTemplate
{
public:
    int get_review_task_quorum();
    const Teamcenter::Soa::Client::ModelObjectVector& get_signoff_profiles();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMPerformSignoffTaskTemplate")

   virtual ~EPMPerformSignoffTaskTemplate();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
