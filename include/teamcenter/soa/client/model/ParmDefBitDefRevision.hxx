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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFBITDEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFBITDEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ParmDefRevision.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class BitDef;


class TCSOACCDMMODELMNGD_API ParmDefBitDefRevision : public Teamcenter::Soa::Client::Model::ParmDefRevision
{
public:
    size_t count_bitDef();
    Teamcenter::Soa::Common::AutoPtr<BitDef> get_bitDef_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmDefBitDefRevision")

   virtual ~ParmDefBitDefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
