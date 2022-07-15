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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MROBOMWINDOW_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MROBOMWINDOW_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BOMWindow.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API MroBOMWindow : public Teamcenter::Soa::Client::Model::BOMWindow
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mroRevisionRule();
    bool get_Smr0showUntracedParts();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MroBOMWindow")

   virtual ~MroBOMWindow();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
