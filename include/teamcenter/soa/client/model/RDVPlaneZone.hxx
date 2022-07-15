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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RDVPLANEZONE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RDVPLANEZONE_HXX

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


class TCSOACLIENTMNGD_API RDVPlaneZone : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    double get_base_coord_x();
    double get_base_coord_y();
    double get_base_coord_z();
    double get_normal_vector_x();
    double get_normal_vector_y();
    double get_normal_vector_z();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RDVPlaneZone")

   virtual ~RDVPlaneZone();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
