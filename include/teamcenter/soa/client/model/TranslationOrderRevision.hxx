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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSLATIONORDERREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSLATIONORDERREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

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
                class ItemRevision;
                class TransltnOfficeRevision;


class TCSOACLIENTMNGD_API TranslationOrderRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_translOfficeReference();
    const std::string& get_topicReference();
    const std::string& get_orderTitle();
    const std::string& get_orderDescription();
    const Teamcenter::Soa::Common::DateTime& get_requestDeliveryDate();
    const std::string& get_translResponsible();
    const std::string& get_responsibleAuthor();
    size_t count_languagesTbl();
    Teamcenter::Soa::Common::AutoPtr<LanguagesTbl> get_languagesTbl_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_fnd0ItemRevTagref();
    Teamcenter::Soa::Common::AutoPtr<TransltnOfficeRevision> get_fnd0TrnslOfficeTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TranslationOrderRevision")

   virtual ~TranslationOrderRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
