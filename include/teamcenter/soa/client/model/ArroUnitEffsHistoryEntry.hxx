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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ARROUNITEFFSHISTORYENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ARROUNITEFFSHISTORYENTRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ArroHistoryEntry.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ArroUnitEffsHistoryEntry : public Teamcenter::Soa::Client::Model::ArroHistoryEntry
{
public:
    const Teamcenter::Soa::Client::IntVector& get_unit_effectivities();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ArroUnitEffsHistoryEntry")

   virtual ~ArroUnitEffsHistoryEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
