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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHANGETYPEDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHANGETYPEDATA_HXX

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


class TCSOACLIENTMNGD_API ChangeTypeData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    bool get_is_effectivity_shared();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_id_format();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_rev_id_format();
    const Teamcenter::Soa::Client::ModelObjectVector& get_form_types();
    const Teamcenter::Soa::Client::StringVector& get_processes();
    const std::string& get_object_type();
    const std::string& get_object_name();
    const std::string& get_object_full_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ChangeTypeData")

   virtual ~ChangeTypeData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
