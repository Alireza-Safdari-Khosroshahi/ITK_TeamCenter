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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIECONNECTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIECONNECTION_HXX

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
                class AIEConnectionFileList;
                class ImanFile;


class TCSOACLIENTMNGD_API AIEConnection : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_name();
    const std::string& get_desc();
    bool get_export_only();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_import_folder();
    Teamcenter::Soa::Common::AutoPtr<AIEConnectionFileList> get_file_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_cko_pom_list();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_transaction_log();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEConnection")

   virtual ~AIEConnection();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
