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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_PUBLICATIONREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_PUBLICATIONREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Specification_Revision.hxx>

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
                class DC_TopicType;
                class DC_StyleType;


class TCSOACONTMGMTBASEMODELMNGD_API DC_PublicationRevision : public Teamcenter::Soa::Client::Model::Specification_Revision
{
public:
    const std::string& get_topicTypeRef();
    int get_contentSize();
    const std::string& get_masterLanguageRef();
    int get_contentVersion();
    bool get_referenceOnly();
    bool get_isTemplate();
    const std::string& get_templateRef();
    const std::string& get_importOriginalName();
    const std::string& get_checksum();
    const std::string& get_styleTypeRef();
    const std::string& get_languageRef();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_ctm0MasterLanguageTagref();
    Teamcenter::Soa::Common::AutoPtr<DC_PublicationRevision> get_ctm0TemplateTagref();
    Teamcenter::Soa::Common::AutoPtr<DC_TopicType> get_ctm0TopicTypeTagref();
    Teamcenter::Soa::Common::AutoPtr<DC_StyleType> get_ctm0StyleTypeTagref();
    const std::string& get_ctm0VersionNumber();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicDocumentR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTranslOrderR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTransR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_UsedSaveItemR();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_PublicationRevision")

   virtual ~DC_PublicationRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
