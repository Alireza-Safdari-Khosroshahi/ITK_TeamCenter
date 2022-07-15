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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_TOPICTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_TOPICTYPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_Admin.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class TransferMode;


class TCSOACONTMGMTBASEMODELMNGD_API DC_TopicType : public Teamcenter::Soa::Client::Model::DC_Admin
{
public:
    const std::string& get_defaultPrefix();
    const std::string& get_namespaceUri();
    const std::string& get_tagName();
    const std::string& get_topicTypeName();
    const std::string& get_iconName();
    const std::string& get_systemUsage();
    const std::string& get_applyClassName();
    const std::string& get_topicTypeCondition();
    bool get_validateIncomingOnParse();
    bool get_validateOutgoingOnParse();
    bool get_validateIncomingRefOnParse();
    bool get_validateExampleContOnParse();
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_ctm0TransferModeTagref();
    const std::string& get_ctm0FileExtension();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTypeTopicTypeR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTypeXmlAttrMapR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTypePolicyR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTypeSchemaR();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_TopicTypeStyleSheetR();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_TopicType")

   virtual ~DC_TopicType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
