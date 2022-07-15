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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSLTNOFFICEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSLTNOFFICEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CompanyRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class LanguagesTbl;


class TCSOACLIENTMNGD_API TransltnOfficeRevision : public Teamcenter::Soa::Client::Model::CompanyRevision
{
public:
    size_t count_languagesTbl();
    Teamcenter::Soa::Common::AutoPtr<LanguagesTbl> get_languagesTbl_at( size_t inx );
    const std::string& get_translOfficeTitle();
    const std::string& get_lifeCycleReference();
    const std::string& get_translResponsible();
    const std::string& get_emailInbox();
    const std::string& get_emailReceivingInbox();
    const std::string& get_styleTypeRef();
    bool get_deliverComposedContent();
    bool get_deliverDecomposedContent();
    bool get_includeGraphics();
    bool get_includeSupportingData();
    const std::string& get_translOfficeName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TransltnOfficeRevision")

   virtual ~TransltnOfficeRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
