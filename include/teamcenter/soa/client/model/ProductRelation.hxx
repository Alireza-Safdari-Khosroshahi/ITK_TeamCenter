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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTRELATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTRELATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GeneralDesignElementLink.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ProductRelation : public Teamcenter::Soa::Client::Model::GeneralDesignElementLink
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_PR_references();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Feature_Form_Relation();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_PR_owning_part();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_PR_context_assembly();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProductRelation")

   virtual ~ProductRelation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
