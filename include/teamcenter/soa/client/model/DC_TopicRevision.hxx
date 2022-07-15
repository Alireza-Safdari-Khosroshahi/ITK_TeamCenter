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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_TOPICREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_TOPICREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElementRevision.hxx>

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


class TCSOACONTMGMTBASEMODELMNGD_API DC_TopicRevision : public Teamcenter::Soa::Client::Model::SpecElementRevision
{
public:
    const std::string& get_topicTypeRef();
    int get_contentSize();
    const std::string& get_DocumentTitle();
    const std::string& get_masterLanguageRef();
    int get_contentVersion();
    bool get_referenceOnly();
    bool get_isTemplate();
    const std::string& get_templateRef();
    const std::string& get_importOriginalName();
    const std::string& get_checksum();
    Teamcenter::Soa::Common::AutoPtr<DC_TopicRevision> get_ctm0TemplateTagref();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_ctm0MasterLanguageTagref();
    Teamcenter::Soa::Common::AutoPtr<DC_TopicType> get_ctm0TopicTypeTagref();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTranslOrderR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ctm0ContentRefFixedR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ctm0ContentRefFloatR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTransR();
    const std::string& get_ctm0VersionNumber();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicDocumentR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicGraphicR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_UsedSaveItemR();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_TopicRevision")

   virtual ~DC_TopicRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
