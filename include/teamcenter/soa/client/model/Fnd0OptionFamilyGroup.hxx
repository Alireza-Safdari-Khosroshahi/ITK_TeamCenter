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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0OPTIONFAMILYGROUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0OPTIONFAMILYGROUP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0ConfiguratorWSO.hxx>

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


class TCSOACLIENTMNGD_API Fnd0OptionFamilyGroup : public Teamcenter::Soa::Client::Model::Fnd0ConfiguratorWSO
{
public:
    size_t count_fnd0variant_families();
    Teamcenter::Soa::Common::AutoPtr<Variant> get_fnd0variant_families_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0OptionFamilyGroup")

   virtual ~Fnd0OptionFamilyGroup();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
