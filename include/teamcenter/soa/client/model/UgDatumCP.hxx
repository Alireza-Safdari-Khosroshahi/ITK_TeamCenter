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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMCP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGDATUMCP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/UgDatumBasic.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API UgDatumCP : public Teamcenter::Soa::Client::Model::UgDatumBasic
{
public:
    const std::string& get_certification_point_name();
    double get_cert_i_value();
    double get_cert_j_value();
    double get_cert_k_value();
    double get_cert_x_value();
    double get_cert_y_value();
    double get_cert_z_value();
    const std::string& get_cert_locating_target();
    int get_sequence_();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UgDatumCP")

   virtual ~UgDatumCP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
