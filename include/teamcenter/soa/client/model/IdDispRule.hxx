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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IDDISPRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IDDISPRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API IdDispRule : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_iddisp_name();
    bool get_use_default();
    const Teamcenter::Soa::Client::ModelObjectVector& get_idcontext_list();
    const std::string& get_iddisp_disp_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IdDispRule")

   virtual ~IdDispRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
