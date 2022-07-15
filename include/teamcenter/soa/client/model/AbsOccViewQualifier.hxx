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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCVIEWQUALIFIER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCVIEWQUALIFIER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AbsOccurrence;
                class PSBOMView;


class TCSOACLIENTMNGD_API AbsOccViewQualifier : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<AbsOccurrence> get_absocc_tag();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_bomview_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AbsOccViewQualifier")

   virtual ~AbsOccViewQualifier();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
