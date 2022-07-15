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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GROOVE_FORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GROOVE_FORM_HXX

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


class TCSOAGMOMODELMNGD_API Groove_Form : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get__weld_type();
    int get__weld_id();
    const std::string& get_conn_part_num();
    const std::string& get_conn_part_name();
    const std::string& get_standard_flag();
    const std::string& get_standard_desc();
    const std::string& get__weld_type_sub();
    int get_conn_number();
    const std::string& get__weld_process();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Groove_Form")

   virtual ~Groove_Form();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
