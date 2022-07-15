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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0RECIPECONTAINER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0RECIPECONTAINER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ConfigurationContext;
                class ApprSearchCriteria;


class TCSOACLIENTMNGD_API Fnd0RecipeContainer : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<ConfigurationContext> get_fnd0configuration_context();
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_fnd0search_recipe();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0RecipeContainer")

   virtual ~Fnd0RecipeContainer();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
