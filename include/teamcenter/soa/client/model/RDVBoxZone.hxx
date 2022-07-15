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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RDVBOXZONE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RDVBOXZONE_HXX

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


class TCSOACLIENTMNGD_API RDVBoxZone : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    double get_base_coord_x();
    double get_base_coord_y();
    double get_base_coord_z();
    double get_vector1_x();
    double get_vector1_y();
    double get_vector1_z();
    double get_vector2_x();
    double get_vector2_y();
    double get_vector2_z();
    double get_vector3_x();
    double get_vector3_y();
    double get_vector3_z();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RDVBoxZone")

   virtual ~RDVBoxZone();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
