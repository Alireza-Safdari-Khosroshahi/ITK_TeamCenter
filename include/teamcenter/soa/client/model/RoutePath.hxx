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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ROUTEPATH_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ROUTEPATH_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class RouteDisplay;
                class RouteSegment;
                class RouteCurve;
                class RouteNode;


class TCSOACLIENTMNGD_API RoutePath : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_context();
    double get_represented_length();
    double get_real_length();
    Teamcenter::Soa::Common::AutoPtr<RouteDisplay> get_route_display();
    size_t count_segments();
    Teamcenter::Soa::Common::AutoPtr<RouteSegment> get_segments_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<RouteCurve> get_center_curve();
    size_t count_nodes();
    Teamcenter::Soa::Common::AutoPtr<RouteNode> get_nodes_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RoutePath")

   virtual ~RoutePath();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
