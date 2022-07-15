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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_LANGUAGESTBL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_LANGUAGESTBL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TableProperties.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DCt_Language;


class TCSOACLIENTMNGD_API LanguagesTbl : public Teamcenter::Soa::Client::Model::TableProperties
{
public:
    const std::string& get_language();
    bool get_reviewOrdered();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_fnd0LanguageTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LanguagesTbl")

   virtual ~LanguagesTbl();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
