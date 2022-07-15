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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0POSITIONEDGEOMETRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0POSITIONEDGEOMETRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ModelArtifact.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;
                class POM_object;
                class Dataset;
                class Dataset;
                class Dataset;


class TCSOAAPPMODELMODELMNGD_API Mdl0PositionedGeometry : public Teamcenter::Soa::Client::Model::Mdl0ModelArtifact
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_mdl0positioned_object();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_mdl0relative_to();
    bool get_mdl0position_constrained();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_mdl0direct_model_data();
    const std::string& get_mdl0jt_ref_set();
    double get_mdl0ext_transform_rot00();
    double get_mdl0ext_transform_rot10();
    double get_mdl0ext_transform_rot20();
    double get_mdl0ext_transform_per0();
    double get_mdl0ext_transform_rot01();
    double get_mdl0ext_transform_rot11();
    double get_mdl0ext_transform_rot21();
    double get_mdl0ext_transform_per1();
    double get_mdl0ext_transform_rot02();
    double get_mdl0ext_transform_rot12();
    double get_mdl0ext_transform_rot22();
    double get_mdl0ext_transform_per2();
    double get_mdl0ext_transform_tra0();
    double get_mdl0ext_transform_tra1();
    double get_mdl0ext_transform_tra2();
    double get_mdl0ext_transform_invscale();
    double get_mdl0bounding_box_min0();
    double get_mdl0bounding_box_min1();
    double get_mdl0bounding_box_min2();
    double get_mdl0bounding_box_max0();
    double get_mdl0bounding_box_max1();
    double get_mdl0bounding_box_max2();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_mdl0alsg_data();
    const std::string& get_mdl0source_bbox_uid();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_mdl0trueshape_data();
    const Teamcenter::Soa::Common::DateTime& get_mdl0shape_lmd();
    const Teamcenter::Soa::Common::DateTime& get_mdl0position_lmd();
    const Teamcenter::Soa::Client::DoubleVector& get_mdl0absolute_transform();
    const Teamcenter::Soa::Client::DoubleVector& get_mdl0bounding_box();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mdl0jt_file();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mdl0alsg_file();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0PositionedGeometry")

   virtual ~Mdl0PositionedGeometry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
