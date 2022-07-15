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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ROLLUPTEMPLATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ROLLUPTEMPLATE_HXX

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


class TCSOACLIENTMNGD_API RollupTemplate : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const std::string& get_description();
    const std::string& get_delimiter();
    const std::string& get_scope_context();
    int get_scope();
    bool get_lock_flag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RollupTemplate")

   virtual ~RollupTemplate();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
