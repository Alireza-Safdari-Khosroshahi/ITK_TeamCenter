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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IDENTIFIER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IDENTIFIER_HXX

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
                class POM_object;
                class POM_object;
                class IdContext;


class TCSOACLIENTMNGD_API Identifier : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_idfr_id();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_altid_of();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_suppl_context();
    bool get_disp_default();
    Teamcenter::Soa::Common::AutoPtr<IdContext> get_idcontext();
    const std::string& get_current_revision_id();
    const std::string& get_item_id();
    const std::string& get_current_id();
    const std::string& get_item_revision_id();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Identifier")

   virtual ~Identifier();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
