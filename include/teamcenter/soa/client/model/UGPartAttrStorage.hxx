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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGPARTATTRSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGPARTATTRSTORAGE_HXX

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


class TCSOACLIENTMNGD_API UGPartAttrStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_title();
    const std::string& get_creator();
    const std::string& get_part_type();
    const std::string& get_part_no();
    const std::string& get_model();
    const std::string& get_material();
    const std::string& get_assemb_no();
    double get_weight();
    const std::string& get_task_no();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UGPartAttrStorage")

   virtual ~UGPartAttrStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
