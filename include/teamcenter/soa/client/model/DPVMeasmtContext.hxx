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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DPVMEASMTCONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DPVMEASMTCONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/DpvMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOADPVMODELMNGD_API DPVMeasmtContext : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_item_measured();
    const std::string& get_site();
    const std::string& get_project();
    const std::string& get_phase();
    const std::string& get_build_lbl_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DPVMeasmtContext")

   virtual ~DPVMeasmtContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
