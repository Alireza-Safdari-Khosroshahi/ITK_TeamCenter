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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRHISTORYUNITNOENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRHISTORYUNITNOENTRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprHistoryEntry.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ApprHistoryUnitNoEntry : public Teamcenter::Soa::Client::Model::ApprHistoryEntry
{
public:
    int get_in_unit_no();
    int get_out_unit_no();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprHistoryUnitNoEntry")

   virtual ~ApprHistoryUnitNoEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
