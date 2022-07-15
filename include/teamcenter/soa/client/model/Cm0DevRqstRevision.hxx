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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CM0DEVRQSTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CM0DEVRQSTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ChangeRequestRevision.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API Cm0DevRqstRevision : public Teamcenter::Soa::Client::Model::ChangeRequestRevision
{
public:
    bool get_Cm0is_deviation_recurring();
    const std::string& get_Cm0rational_for_recurr();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cm0DevRqstRevision")

   virtual ~Cm0DevRqstRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
