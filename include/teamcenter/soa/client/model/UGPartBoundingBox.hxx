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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGPARTBOUNDINGBOX_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGPARTBOUNDINGBOX_HXX

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


class TCSOACLIENTMNGD_API UGPartBoundingBox : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    double get_xmin();
    double get_xmax();
    double get_ymin();
    double get_ymax();
    double get_zmin();
    double get_zmax();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UGPartBoundingBox")

   virtual ~UGPartBoundingBox();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
