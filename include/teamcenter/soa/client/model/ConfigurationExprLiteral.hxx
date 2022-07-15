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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONEXPRLITERAL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONEXPRLITERAL_HXX

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
                class ConfigurationFamily;


class TCSOACLIENTMNGD_API ConfigurationExprLiteral : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<ConfigurationFamily> get_family();
    int get_operator();
    double get_value_numeric();
    const std::string& get_value_text();
    const Teamcenter::Soa::Common::DateTime& get_value_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConfigurationExprLiteral")

   virtual ~ConfigurationExprLiteral();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
