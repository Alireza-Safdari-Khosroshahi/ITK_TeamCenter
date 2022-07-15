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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNCONTROLELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNCONTROLELEMENT_HXX

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
                class Cpd0ShapeDesignRevision;


class TCSOACPDMODELMNGD_API Cpd0DesignControlElement : public Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<Cpd0ShapeDesignRevision> get_cpd0source_object();
    const std::string& get_cpd0design_control_id();
    const std::string& get_cpd0source_object_id();
    const std::string& get_cpd0source_object_name();
    const std::string& get_cpd0source_object_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cpd0source_specifications();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignControlElement")

   virtual ~Cpd0DesignControlElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
