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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0PROPERTYRENDERERATTACH_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0PROPERTYRENDERERATTACH_HXX

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
                class Condition;


class TCSOACLIENTMNGD_API Fnd0PropertyRendererAttach : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_fnd0pr_name();
    const std::string& get_fnd0type_name();
    const std::string& get_fnd0property_name();
    Teamcenter::Soa::Common::AutoPtr<Condition> get_fnd0condition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0PropertyRendererAttach")

   virtual ~Fnd0PropertyRendererAttach();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
