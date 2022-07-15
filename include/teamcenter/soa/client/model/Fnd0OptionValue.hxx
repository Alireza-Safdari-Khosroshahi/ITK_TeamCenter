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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0OPTIONVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0OPTIONVALUE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0VariantWSO.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;


class TCSOACLIENTMNGD_API Fnd0OptionValue : public Teamcenter::Soa::Client::Model::Fnd0VariantWSO
{
public:
    int get_fnd0value_index();
    const std::string& get_fnd0option_value();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_fnd0option_family();
    const std::string& get_fnd0option_family_desc();
    const std::string& get_fnd0option_family_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0OptionValue")

   virtual ~Fnd0OptionValue();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
