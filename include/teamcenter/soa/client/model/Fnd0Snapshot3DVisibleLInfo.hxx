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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0SNAPSHOT3DVISIBLELINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0SNAPSHOT3DVISIBLELINFO_HXX

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
                class Dataset;
                class ItemRevision;


class TCSOACLIENTMNGD_API Fnd0Snapshot3DVisibleLInfo : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_fnd0SnapshotViewData();
    const std::string& get_fnd0CloneStableOccIDChain();
    Teamcenter::Soa::Common::AutoPtr<ItemRevision> get_fnd0ItemRevision();
    const std::string& get_fnd0JTFileInfo();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0Snapshot3DVisibleLInfo")

   virtual ~Fnd0Snapshot3DVisibleLInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
