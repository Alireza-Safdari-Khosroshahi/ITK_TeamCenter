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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIECONNECTIONFILE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIECONNECTIONFILE_HXX

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
                class AIEConnectionAssocFile;
                class AIERootObject;


class TCSOACLIENTMNGD_API AIEConnectionFile : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_file();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_item();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_item_revision();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_owning_dataset();
    const std::string& get_named_ref_type();
    const std::string& get_connection_filespec();
    const std::string& get_client_timestamp();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_associated_tool();
    bool get_exported();
    bool get_checked_out();
    const std::string& get_connection_relative_path();
    size_t count_connection_associated_files();
    Teamcenter::Soa::Common::AutoPtr<AIEConnectionAssocFile> get_connection_associated_files_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<AIERootObject> get_root();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEConnectionFile")

   virtual ~AIEConnectionFile();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
