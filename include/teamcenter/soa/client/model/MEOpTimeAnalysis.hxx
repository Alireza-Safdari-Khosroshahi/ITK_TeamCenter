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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEOPTIMEANALYSIS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEOPTIMEANALYSIS_HXX

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


class TCSOACLIENTMNGD_API MEOpTimeAnalysis : public Teamcenter::Soa::Client::Model::Form
{
public:
    double get_estimated_time();
    double get_simulated_time();
    double get_allocated_time();
    const std::string& get_operation_start();
    const std::string& get_work_content();
    const std::string& get_operation_end();
    const std::string& get_restriction();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEOpTimeAnalysis")

   virtual ~MEOpTimeAnalysis();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
