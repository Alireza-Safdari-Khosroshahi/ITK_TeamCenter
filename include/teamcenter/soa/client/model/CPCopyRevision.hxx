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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPCOPYREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPCOPYREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Specification_Revision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPKGARTMODELMNGD_API CPCopyRevision : public Teamcenter::Soa::Client::Model::Specification_Revision
{
public:
    const std::string& get_region();
    const std::string& get_language();
    const std::string& get_copy_language_type();
    bool get_clearance_required();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Has_Local_Copy();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Has_Master_Copy();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPCopyRevision")

   virtual ~CPCopyRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
