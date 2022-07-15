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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRHISTORYDATEENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRHISTORYDATEENTRY_HXX

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


class TCSOACLIENTMNGD_API ApprHistoryDateEntry : public Teamcenter::Soa::Client::Model::ApprHistoryEntry
{
public:
    const Teamcenter::Soa::Common::DateTime& get_in_date();
    const Teamcenter::Soa::Common::DateTime& get_out_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprHistoryDateEntry")

   virtual ~ApprHistoryDateEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
