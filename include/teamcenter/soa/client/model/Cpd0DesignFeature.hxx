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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNFEATURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNFEATURE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0PositionedModelElement.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPDMODELMNGD_API Cpd0DesignFeature : public Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement
{
public:
    const std::string& get_cpd0design_feature_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Cpd0ConnectedElement();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignFeature")

   virtual ~Cpd0DesignFeature();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
