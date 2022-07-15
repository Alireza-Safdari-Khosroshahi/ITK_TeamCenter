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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DRAWING_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DRAWING_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Drawing_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_author();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_DrawingOf();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_DrawingUsing();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Drawing_Revision")

   virtual ~Drawing_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
