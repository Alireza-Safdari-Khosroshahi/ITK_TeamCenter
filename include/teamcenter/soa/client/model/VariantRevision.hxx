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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VARIANTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VARIANTREVISION_HXX

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
                class Variant;


class TCSOACLIENTMNGD_API VariantRevision : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_mode();
    const Teamcenter::Soa::Client::StringVector& get_enums();
    Teamcenter::Soa::Common::AutoPtr<Variant> get_parent_variant();
    const std::string& get_extended_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VariantRevision")

   virtual ~VariantRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
