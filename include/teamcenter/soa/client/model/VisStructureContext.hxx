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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VISSTRUCTURECONTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VISSTRUCTURECONTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/StructureContext.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanFile;


class TCSOACLIENTMNGD_API VisStructureContext : public Teamcenter::Soa::Client::Model::StructureContext
{
public:
    const Teamcenter::Soa::Client::StringVector& get_occurrence_list();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_static_structure_file();
    const Teamcenter::Soa::Client::StringVector& get_fnd0bg_occurrences();
    const Teamcenter::Soa::Client::StringVector& get_fnd0sel_bg_occurrences();
    const Teamcenter::Soa::Client::StringVector& get_fnd0target_occurrences();
    const Teamcenter::Soa::Client::StringVector& get_fnd0sel_target_occurrences();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VisStructureContext")

   virtual ~VisStructureContext();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
