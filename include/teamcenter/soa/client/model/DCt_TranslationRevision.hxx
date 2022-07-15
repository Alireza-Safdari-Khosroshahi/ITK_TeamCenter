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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_TRANSLATIONREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_TRANSLATIONREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DCt_ItemRevision.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DCt_Language;


class TCSOACONTMGMTBASEMODELMNGD_API DCt_TranslationRevision : public Teamcenter::Soa::Client::Model::DCt_ItemRevision
{
public:
    int get_contentSize();
    int get_contentVersionReference();
    bool get_translationReceived();
    const std::string& get_languageRef();
    const std::string& get_DocumentTitle();
    const std::string& get_topicReference();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_ctm0LanguageTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_TranslationRevision")

   virtual ~DCt_TranslationRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
