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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANEXPORTRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANEXPORTRECORD_HXX

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
                class POMImc;
                class TransferOptionSet;


class TCSOACLIENTMNGD_API ImanExportRecord : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_ixr_exported_object();
    const std::string& get_ixr_exporting_user();
    const std::string& get_ixr_export_reason();
    const Teamcenter::Soa::Common::DateTime& get_ixr_last_export_date();
    bool get_dirty();
    const std::string& get_transactionID();
    int get_exportStatus();
    const Teamcenter::Soa::Common::DateTime& get_prevExportDate();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_ixr_target_site();
    Teamcenter::Soa::Common::AutoPtr<TransferOptionSet> get_recipe();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanExportRecord")

   virtual ~ImanExportRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
