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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGSEAM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGSEAM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/UgDollop.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API UgSeam : public Teamcenter::Soa::Client::Model::UgDollop
{
public:
    int get_conn_number();
    const std::string& get__weld_class();
    const std::string& get__weld_group_id();
    const std::string& get_kpc_spec();
    const std::string& get_kpc_just();
    const std::string& get_dcw();
    const std::string& get_proc_weld();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UgSeam")

   virtual ~UgSeam();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
