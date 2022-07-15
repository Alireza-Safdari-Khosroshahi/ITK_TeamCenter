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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSBOMVIEW_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSBOMVIEW_HXX

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
                class PSViewType;


class TCSOACLIENTMNGD_API PSBOMView : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_item();
    const Teamcenter::Soa::Client::IntVector& get_cd_indexes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cd_tags();
    Teamcenter::Soa::Common::AutoPtr<PSViewType> get_view_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_METarget();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSBOMView")

   virtual ~PSBOMView();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
