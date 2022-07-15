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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ROUTESEGMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ROUTESEGMENT_HXX

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
                class RouteCurve;
                class RouteNode;
                class RouteNode;


class TCSOACLIENTMNGD_API RouteSegment : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_segment_name();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_context();
    double get_represented_length();
    double get_real_length();
    double get_cross_section();
    Teamcenter::Soa::Common::AutoPtr<RouteCurve> get_center_curve();
    Teamcenter::Soa::Common::AutoPtr<RouteNode> get_start_node();
    Teamcenter::Soa::Common::AutoPtr<RouteNode> get_end_node();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RouteSegment")

   virtual ~RouteSegment();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
