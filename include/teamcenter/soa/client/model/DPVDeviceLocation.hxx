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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DPVDEVICELOCATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DPVDEVICELOCATION_HXX

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


class TCSOADPVMODELMNGD_API DPVDeviceLocation : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_location_name();
    const std::string& get_data_directory();
    int get_alive_test_interval_min();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DPVDeviceLocation")

   virtual ~DPVDeviceLocation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
