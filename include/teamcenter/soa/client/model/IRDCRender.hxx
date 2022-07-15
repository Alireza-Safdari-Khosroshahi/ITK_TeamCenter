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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRDCRENDER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRDCRENDER_HXX

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
                class DatasetType;
                class DatasetType;
                class ImanType;
                class ImanType;


class TCSOACLIENTMNGD_API IRDCRender : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_der_ds_name();
    bool get_delete_after_translate();
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_der_input_ds();
    const std::string& get_when_to_translate();
    const std::string& get_input_filenames();
    const std::string& get_defining_irdc();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_input_ds_relation();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_derived_from_ds_relation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRDCRender")

   virtual ~IRDCRender();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
