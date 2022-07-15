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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPPROCLINEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPPROCLINEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElementRevision.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPSpecificationRevision;
                class CPPlant;


class TCSOASPECMGRMODELMNGD_API CPProcLineRevision : public Teamcenter::Soa::Client::Model::SpecElementRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<CPSpecificationRevision> get_specification();
    Teamcenter::Soa::Common::AutoPtr<CPPlant> get_plant();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPProcLineRevision")

   virtual ~CPProcLineRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
