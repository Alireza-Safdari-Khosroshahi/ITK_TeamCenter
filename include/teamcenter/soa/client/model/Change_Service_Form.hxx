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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGE_SERVICE_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGE_SERVICE_FORM_HXX

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


class TCSOAGMOMODELMNGD_API Change_Service_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_interchng_prod_parts();
    const std::string& get_interchng_serv_parts();
    const std::string& get_chng_mold_irreverse();
    const std::string& get_impact_handbook();
    const std::string& get_impact_stnds();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Change_Service_Form")

   virtual ~Change_Service_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
