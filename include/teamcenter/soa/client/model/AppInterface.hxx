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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPINTERFACE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPINTERFACE_HXX

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
                class RequestObject;
                class MasterRecord;
                class ItemRevision;
                class POMImc;
                class POMImc;
                class TransferMode;
                class TransferMode;


class TCSOACLIENTMNGD_API AppInterface : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_base_refs();
    size_t count_request_objects();
    Teamcenter::Soa::Common::AutoPtr<RequestObject> get_request_objects_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<MasterRecord> get_master_record();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_incremental_change();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_site_id();
    size_t count_fnd0target_site_ids();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_fnd0target_site_ids_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_tm_export();
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_tm_import();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_TCPublishedPortfolio();
    bool get_can_add_sync();
    const std::string& get_project_id();
    bool get_can_add_publish();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0LogRelation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppInterface")

   virtual ~AppInterface();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
