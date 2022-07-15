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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCXFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCXFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/AbsOccData.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API AbsOccXform : public Teamcenter::Soa::Client::Model::AbsOccData
{
public:
    double get_ext_transform_rot00();
    double get_ext_transform_rot10();
    double get_ext_transform_rot20();
    double get_ext_transform_per0();
    double get_ext_transform_rot01();
    double get_ext_transform_rot11();
    double get_ext_transform_rot21();
    double get_ext_transform_per1();
    double get_ext_transform_rot02();
    double get_ext_transform_rot12();
    double get_ext_transform_rot22();
    double get_ext_transform_per2();
    double get_ext_transform_tra0();
    double get_ext_transform_tra1();
    double get_ext_transform_tra2();
    double get_ext_transform_invscale();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AbsOccXform")

   virtual ~AbsOccXform();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
