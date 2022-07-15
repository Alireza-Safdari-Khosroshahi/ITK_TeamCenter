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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONFAMILY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONFAMILY_HXX

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
                class UnitOfMeasure;


class TCSOACLIENTMNGD_API ConfigurationFamily : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_namespace();
    const std::string& get_name();
    int get_mode();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_uom();
    const std::string& get_description();
    bool get_isMandatory();
    bool get_isModelFamily();
    const std::string& get_fnd0valueScope();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConfigurationFamily")

   virtual ~ConfigurationFamily();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
