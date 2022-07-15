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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EXTENSION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EXTENSION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanParameters;


class TCSOACLIENTMNGD_API Extension : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    const std::string& get_name();
    const std::string& get_library_name();
    int get_lang_type();
    const Teamcenter::Soa::Client::StringVector& get_validity();
    Teamcenter::Soa::Common::AutoPtr<ImanParameters> get_argdefs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Extension")

   virtual ~Extension();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
