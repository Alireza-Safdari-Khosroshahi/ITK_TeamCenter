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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROGRESSDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROGRESSDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ProgressData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_pd_operation_state();
    int get_pd_progress_state();
    const std::string& get_pd_progress_data();
    const std::string& get_pd_completion_file();
    const Teamcenter::Soa::Client::StringVector& get_pd_completion_data();
    const std::string& get_pd_error_file();
    const Teamcenter::Soa::Client::ModelObjectVector& get_pd_completion_objects();
    const Teamcenter::Soa::Client::IntVector& get_pd_error_codes();
    const std::string& get_pd_display_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProgressData")

   virtual ~ProgressData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
