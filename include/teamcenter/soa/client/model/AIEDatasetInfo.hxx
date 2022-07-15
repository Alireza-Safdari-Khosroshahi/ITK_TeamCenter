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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEDATASETINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEDATASETINFO_HXX

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
                class DatasetType;
                class ImanFile;


class TCSOACLIENTMNGD_API AIEDatasetInfo : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_ds_name();
    const std::string& get_dstype_name();
    int get_co_status();
    int get_export_status();
    const std::string& get_co_info();
    bool get_co_request();
    int get_num_nr();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_ds_ref();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_dstype_ref();
    size_t count_nr_refs();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_nr_refs_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEDatasetInfo")

   virtual ~AIEDatasetInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
