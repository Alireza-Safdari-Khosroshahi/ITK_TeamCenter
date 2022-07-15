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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGPARTMASSPROPSFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGPARTMASSPROPSFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API UGPartMassPropsForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    double get_accuracy();
    double get_mass();
    double get_mass_error();
    double get_volume();
    double get_volume_error();
    double get_density();
    double get_area();
    double get_area_error();
    double get_com_x();
    double get_com_y();
    double get_com_z();
    double get_com_error();
    double get_moi_xx();
    double get_moi_yy();
    double get_moi_zz();
    double get_moi_error();
    double get_poi_xy();
    double get_poi_xz();
    double get_poi_yz();
    double get_min_mass();
    double get_max_mass();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UGPartMassPropsForm")

   virtual ~UGPartMassPropsForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
