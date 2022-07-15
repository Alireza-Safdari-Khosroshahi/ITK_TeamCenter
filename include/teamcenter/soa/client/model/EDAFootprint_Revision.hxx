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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EDAFOOTPRINT_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EDAFOOTPRINT_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/EDAShape_Revision.hxx>

#include <teamcenter/soa/client/model/EdalibraryMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAEDALIBRARYMODELMNGD_API EDAFootprint_Revision : public Teamcenter::Soa::Client::Model::EDAShape_Revision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_EDAPadstackRelation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EDAFootprint_Revision")

   virtual ~EDAFootprint_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EdalibraryMngd_undef.h>
#endif
