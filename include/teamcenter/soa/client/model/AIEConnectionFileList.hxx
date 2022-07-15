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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIECONNECTIONFILELIST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIECONNECTIONFILELIST_HXX

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
                class AIEConnectionXdataFile;
                class AIEConnectionFile;
                class ImanFile;


class TCSOACLIENTMNGD_API AIEConnectionFileList : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_export_dir();
    const std::string& get_temp_directory();
    size_t count_x_files();
    Teamcenter::Soa::Common::AutoPtr<AIEConnectionXdataFile> get_x_files_at( size_t inx );
    size_t count_connection_files();
    Teamcenter::Soa::Common::AutoPtr<AIEConnectionFile> get_connection_files_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_transaction_log();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEConnectionFileList")

   virtual ~AIEConnectionFileList();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
