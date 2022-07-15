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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPCOPYELEMENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPCOPYELEMENTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElementRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPKGARTMODELMNGD_API CPCopyElementRevision : public Teamcenter::Soa::Client::Model::SpecElementRevision
{
public:
    const std::string& get_copy_element_type();
    const std::string& get_language();
    bool get_clearance_required();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPCopyElementRevision")

   virtual ~CPCopyElementRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
