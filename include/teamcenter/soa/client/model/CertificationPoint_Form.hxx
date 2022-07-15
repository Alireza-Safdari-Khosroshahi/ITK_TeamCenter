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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CERTIFICATIONPOINT_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CERTIFICATIONPOINT_FORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API CertificationPoint_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_type_();
    const std::string& get_db_part_name();
    const std::string& get_db_part_no();
    const std::string& get_db_part_rev();
    const std::string& get_connected_parts();
    const std::string& get_certification_point_name();
    double get_cert_i_value();
    double get_cert_j_value();
    double get_cert_k_value();
    double get_cert_x_value();
    double get_cert_y_value();
    double get_cert_z_value();
    const std::string& get_cert_locating_target();
    int get_sequence_();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CertificationPoint_Form")

   virtual ~CertificationPoint_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
