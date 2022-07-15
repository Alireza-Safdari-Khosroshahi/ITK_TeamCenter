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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BOUNDINGBOX_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BOUNDINGBOX_HXX

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
                class BoundingMultiBox;


class TCSOACLIENTMNGD_API BoundingBox : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    double get_x_min();
    double get_y_min();
    double get_z_min();
    double get_x_max();
    double get_y_max();
    double get_z_max();
    Teamcenter::Soa::Common::AutoPtr<BoundingMultiBox> get_parent();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BoundingBox")

   virtual ~BoundingBox();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
