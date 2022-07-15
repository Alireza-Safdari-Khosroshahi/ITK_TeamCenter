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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MENCMACHINING_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MENCMACHINING_REVISION_MASTER_HXX

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


class TCSOACLIENTMNGD_API MENCMachining_Revision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_program_id();
    const std::string& get_process_comment();
    double get_scheduled_time();
    double get_scheduled_cost();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MENCMachining_Revision_Master")

   virtual ~MENCMachining_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
