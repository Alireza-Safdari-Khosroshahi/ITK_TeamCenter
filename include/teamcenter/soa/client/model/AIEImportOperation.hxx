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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEIMPORTOPERATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEIMPORTOPERATION_HXX

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
                class AIEPersistentConnection;
                class Folder;


class TCSOACLIENTMNGD_API AIEImportOperation : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_num_files();
    const Teamcenter::Soa::Client::StringVector& get_file_names();
    const std::string& get_supplier_user();
    Teamcenter::Soa::Common::AutoPtr<AIEPersistentConnection> get_conn_ref();
    Teamcenter::Soa::Common::AutoPtr<Folder> get_import_folder_ref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEImportOperation")

   virtual ~AIEImportOperation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
