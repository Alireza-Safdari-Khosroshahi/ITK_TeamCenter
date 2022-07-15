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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TMXPROJECTC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TMXPROJECTC_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/model/CmtebopMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEBOPMODELMNGD_API TMXProjectC : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_Supplier();
    const std::string& get_Name();
    const std::string& get_Version();
    const std::string& get_Location();
    const std::string& get_Comment();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TMXProjectC")

   virtual ~TMXProjectC();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtebopMngd_undef.h>
#endif
