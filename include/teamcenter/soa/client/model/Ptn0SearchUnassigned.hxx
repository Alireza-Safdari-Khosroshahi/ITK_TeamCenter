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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PTN0SEARCHUNASSIGNED_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PTN0SEARCHUNASSIGNED_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0SearchDef.hxx>

#include <teamcenter/soa/client/model/PartitionMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPARTITIONMODELMNGD_API Ptn0SearchUnassigned : public Teamcenter::Soa::Client::Model::Mdl0SearchDef
{
public:
    const Teamcenter::Soa::Client::StringVector& get_ptn0PartitionSchemeNames();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ptn0SearchUnassigned")

   virtual ~Ptn0SearchUnassigned();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PartitionMngd_undef.h>
#endif
