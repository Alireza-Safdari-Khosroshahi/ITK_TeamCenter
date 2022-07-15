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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ITDC_WAP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ITDC_WAP_HXX

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


class TCSOAGMOMODELMNGD_API ITDC_WAP : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Common::DateTime& get_ITDC_WAP1_CREATE_DATE();
    const std::string& get_ITDC_WAP1_DWG_FMT();
    const std::string& get_ITDC_WAP1_PLANT();
    const std::string& get_ITDC_WAP1_BLDG();
    const std::string& get_ITDC_WAP1_COMPANY();
    const std::string& get_ITDC_WAP1_CO_ORDER_NO();
    const std::string& get_ITDC_WAP1_CO_DWG_NO();
    const std::string& get_ITDC_WAP1_COLUMN_LINE();
    const std::string& get_ITDC_WAP1_LEVEL();
    const std::string& get_ITDC_WAP1_CLASSIFICATION();
    const std::string& get_ITDC_WAP1_COMMENT();
    const std::string& get_ITDC_WAP1_REMARK();
    const std::string& get_ITDC_WAP1_APPROVAL_TYPE();
    const std::string& get_ITDC_WAP1_APPROVAL_NO();
    const std::string& get_ITDC_WAP1_INV_NO();
    const std::string& get_ITDC_WAP1_MF_Storage();
    const std::string& get_ITDC_WAP1_MF_YEAR();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ITDC_WAP")

   virtual ~ITDC_WAP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
