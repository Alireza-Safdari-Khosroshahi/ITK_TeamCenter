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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VIS_SNAPSHOT_2D_FORMSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VIS_SNAPSHOT_2D_FORMSTORAGE_HXX

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


class TCSOACLIENTMNGD_API Vis_Snapshot_2D_FormStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_saf_item_revision_id();
    const std::string& get_saf_page_number();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Vis_Snapshot_2D_FormStorage")

   virtual ~Vis_Snapshot_2D_FormStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
