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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPSPECSECTION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPSPECSECTION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElement.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPSpecification;


class TCSOASPECMGRMODELMNGD_API CPSpecSection : public Teamcenter::Soa::Client::Model::SpecElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<CPSpecification> get_parent_specification();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPSpecSection")

   virtual ~CPSpecSection();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
