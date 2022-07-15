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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNMODELELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNMODELELEMENT_HXX

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


class TCSOACPDMODELMNGD_API Cpd0DesignModelElement : public Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<Cpd0DesignModelElement> get_cpd0presented_parent();
    const std::string& get_cpd0id_in_parent();
    const std::string& get_cpd0category();
    const std::string& get_cpd0design_element_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cpd0connected_features();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignModelElement")

   virtual ~Cpd0DesignModelElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
