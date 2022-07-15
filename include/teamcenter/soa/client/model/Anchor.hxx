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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ANCHOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ANCHOR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class WorkspaceObject;
                class WorkspaceObject;


class TCSOACLIENTMNGD_API Anchor : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    int get_keep_limit();
    size_t count_managed_objects();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_managed_objects_at( size_t inx );
    size_t count_immune_objects();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_immune_objects_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Anchor")

   virtual ~Anchor();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
