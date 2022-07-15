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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPSPECIFICATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPSPECIFICATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Specification.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPSpecType;


class TCSOASPECMGRMODELMNGD_API CPSpecification : public Teamcenter::Soa::Client::Model::Specification
{
public:
    const std::string& get_authoring_system();
    Teamcenter::Soa::Common::AutoPtr<CPSpecType> get_spec_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPSpecification")

   virtual ~CPSpecification();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
