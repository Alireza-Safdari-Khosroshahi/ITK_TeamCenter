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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEATTR_HXX

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
                class AppearanceAttrDefinition;
                class Appearance;


class TCSOACLIENTMNGD_API AppearanceAttr : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_value();
    Teamcenter::Soa::Common::AutoPtr<AppearanceAttrDefinition> get_definition();
    Teamcenter::Soa::Common::AutoPtr<Appearance> get_appearance();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppearanceAttr")

   virtual ~AppearanceAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
