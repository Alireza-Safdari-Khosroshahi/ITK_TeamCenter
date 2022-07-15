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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MELEADCONSTRAINT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MELEADCONSTRAINT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0MEPrecedenceCons.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0MELeadConstraint : public Teamcenter::Soa::Client::Model::Mfg0MEPrecedenceCons
{
public:
    bool get_mfg0is_percentage();
    double get_mfg0lead_percentage();
    double get_mfg0lead_time();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MELeadConstraint")

   virtual ~Mfg0MELeadConstraint();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
