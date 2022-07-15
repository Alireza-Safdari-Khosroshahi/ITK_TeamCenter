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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DMTEMPLATEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DMTEMPLATEREVISION_HXX

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


class TCSOACLIENTMNGD_API DMTemplateRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_ApplicationName();
    const std::string& get_ApplicationRelation();
    const std::string& get_ApplicationVersion();
    const Teamcenter::Soa::Client::StringVector& get_ItemTypesToCreate();
    const Teamcenter::Soa::Client::StringVector& get_TemplateType();
    const std::string& get_TemplateUnits();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DMTemplateRevision")

   virtual ~DMTemplateRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
