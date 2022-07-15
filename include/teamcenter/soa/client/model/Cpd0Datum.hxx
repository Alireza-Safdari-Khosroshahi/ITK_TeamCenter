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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DATUM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DATUM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cpd0DesignFeature.hxx>

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


class TCSOACPDMODELMNGD_API Cpd0Datum : public Teamcenter::Soa::Client::Model::Cpd0DesignFeature
{
public:
    bool get_cpd0controls_in_x_direction();
    bool get_cpd0controls_in_y_direction();
    bool get_cpd0controls_in_z_direction();
    Teamcenter::Soa::Common::AutoPtr<Cpd0ShapeDesignRevision> get_cpd0source_object();
    const std::string& get_cpd0control_direction();
    const std::string& get_cpd0section_plane_name();
    double get_cpd0plane_normal_x();
    double get_cpd0plane_normal_y();
    double get_cpd0plane_normal_z();
    double get_cpd0axis_direction_x();
    double get_cpd0axis_direction_y();
    const std::string& get_cpd0derived();
    double get_cpd0axis_direction_z();
    const Teamcenter::Soa::Client::DoubleVector& get_cpd0position();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0Datum")

   virtual ~Cpd0Datum();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
