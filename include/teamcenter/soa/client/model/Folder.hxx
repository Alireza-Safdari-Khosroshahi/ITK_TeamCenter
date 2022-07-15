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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FOLDER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FOLDER_HXX

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
                class WorkspaceObject;


class TCSOACLIENTMNGD_API Folder : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_sort_order();
    int get_sort_criteria();
    size_t count_contents();
    Teamcenter::Soa::Common::AutoPtr<WorkspaceObject> get_contents_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_external_object_link();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Folder")

   virtual ~Folder();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
