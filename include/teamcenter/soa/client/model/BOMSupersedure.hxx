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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BOMSUPERSEDURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BOMSUPERSEDURE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class BOMEdit;
                class BOMEdit;


class TCSOACMMODELMNGD_API BOMSupersedure : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMImpactedBvr();
    size_t count_CMBOMAddList();
    Teamcenter::Soa::Common::AutoPtr<BOMEdit> get_CMBOMAddList_at( size_t inx );
    size_t count_CMBOMCancelList();
    Teamcenter::Soa::Common::AutoPtr<BOMEdit> get_CMBOMCancelList_at( size_t inx );
    bool get_CMIsTransfer();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMAdds();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMCancels();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMCustomFormTag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMChangeRevTag();
    const std::string& get_CMObjectFullName();
    const std::string& get_CMObjectName();
    const std::string& get_CMObjectString();
    const std::string& get_CMObjectType();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMProblemBvr();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BOMSupersedure")

   virtual ~BOMSupersedure();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
