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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0POSITIONEDMODELELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0POSITIONEDMODELELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ConditionalElement.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class WorkspaceObject;
                class Dataset;
                class Dataset;
                class POM_object;


class TCSOAAPPMODELMODELMNGD_API Mdl0PositionedModelElement : public Teamcenter::Soa::Client::Model::Mdl0ConditionalElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_mdl0delegate();
    const std::string& get_mdl0logical_designator();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mdl0positioned_geometry();
    const Teamcenter::Soa::Client::DoubleVector& get_mdl0absolute_transform();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_mdl0alsg_data();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mdl0alsg_file();
    const Teamcenter::Soa::Client::DoubleVector& get_mdl0bounding_box();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_mdl0direct_model_data();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mdl0jt_file();
    const Teamcenter::Soa::Common::DateTime& get_mdl0position_lmd();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_mdl0relative_to();
    const Teamcenter::Soa::Common::DateTime& get_mdl0shape_lmd();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0PositionedModelElement")

   virtual ~Mdl0PositionedModelElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
