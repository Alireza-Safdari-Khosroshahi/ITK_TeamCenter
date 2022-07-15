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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HRN_INSTANCEGENWIREDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HRN_INSTANCEGENWIREDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/HrnMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAHRNMODELMNGD_API HRN_InstanceGenWireData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_wire_number();
    const std::string& get_multiplier();
    const std::string& get_offset();
    const std::string& get_seperation_code();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HRN_InstanceGenWireData")

   virtual ~HRN_InstanceGenWireData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/HrnMngd_undef.h>
#endif
