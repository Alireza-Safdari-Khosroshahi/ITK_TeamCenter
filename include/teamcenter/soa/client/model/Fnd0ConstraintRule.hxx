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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0CONSTRAINTRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0CONSTRAINTRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0VariantWSO.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ConstraintRule : public Teamcenter::Soa::Client::Model::Fnd0VariantWSO
{
public:
    const std::string& get_fnd0message();
    const std::string& get_fnd0constraint();
    const std::string& get_fnd0applicability();
    const std::string& get_fnd0product_family();
    int get_fnd0severity();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ConstraintRule")

   virtual ~Fnd0ConstraintRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
