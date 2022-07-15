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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_OPERATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_OPERATION_HXX

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
                class OperationTemplate;
                class Release;
                class Release;
                class ParameterInfo;
                class MetaInterface;


class TCSOACLIENTMNGD_API Operation : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const std::string& get_description();
    Teamcenter::Soa::Common::AutoPtr<OperationTemplate> get_opTemplate();
    bool get_isPublished();
    bool get_canOverride();
    const std::string& get_returnDescription();
    Teamcenter::Soa::Common::AutoPtr<Release> get_createRelease();
    bool get_isDeprecated();
    Teamcenter::Soa::Common::AutoPtr<Release> get_deprecatedRelease();
    const std::string& get_deprecatedDescription();
    const std::string& get_id();
    bool get_isPreConditionAllowed();
    bool get_isPreActionAllowed();
    bool get_isPostActionAllowed();
    size_t count_parametersInfos();
    Teamcenter::Soa::Common::AutoPtr<ParameterInfo> get_parametersInfos_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<MetaInterface> get_interface();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Operation")

   virtual ~Operation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
