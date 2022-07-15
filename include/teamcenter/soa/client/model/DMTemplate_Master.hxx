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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DMTEMPLATE_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DMTEMPLATE_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API DMTemplate_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_ApplicationName();
    const std::string& get_ApplicationVersion();
    const Teamcenter::Soa::Client::StringVector& get_TemplateType();
    const std::string& get_TemplateUnits();
    const Teamcenter::Soa::Client::StringVector& get_ItemTypesToCreate();
    const std::string& get_ApplicationRelation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DMTemplate_Master")

   virtual ~DMTemplate_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
