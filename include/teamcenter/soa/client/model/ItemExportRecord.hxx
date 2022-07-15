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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ITEMEXPORTRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ITEMEXPORTRECORD_HXX

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


class TCSOACLIENTMNGD_API ItemExportRecord : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_itxr_exported_object();
    int get_itxr_export_options();
    const Teamcenter::Soa::Client::StringVector& get_itxr_excluded_relations();
    const std::string& get_itxr_rstatus_type();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_itxr_target_site();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ItemExportRecord")

   virtual ~ItemExportRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
