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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMVALBITDEF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMVALBITDEF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ParmVal.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class BitValue;


class TCSOACCDMMODELMNGD_API ParmValBitDef : public Teamcenter::Soa::Client::Model::ParmVal
{
public:
    size_t count_values();
    Teamcenter::Soa::Common::AutoPtr<BitValue> get_values_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmValBitDef")

   virtual ~ParmValBitDef();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
