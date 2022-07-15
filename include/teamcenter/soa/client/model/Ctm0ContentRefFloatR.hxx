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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CTM0CONTENTREFFLOATR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CTM0CONTENTREFFLOATR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Ctm0ContRefTbl;


class TCSOACONTMGMTBASEMODELMNGD_API Ctm0ContentRefFloatR : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    size_t count_ctm0ContRefTblRef();
    Teamcenter::Soa::Common::AutoPtr<Ctm0ContRefTbl> get_ctm0ContRefTblRef_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ctm0ContentRefFloatR")

   virtual ~Ctm0ContentRefFloatR();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
