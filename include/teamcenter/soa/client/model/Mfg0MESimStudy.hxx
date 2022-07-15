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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MESIMSTUDY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MESIMSTUDY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0MEStudy.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0MESimStudy : public Teamcenter::Soa::Client::Model::Mfg0MEStudy
{
public:
    const Teamcenter::Soa::Common::DateTime& get_Mfg0last_sync_date();
    const Teamcenter::Soa::Common::DateTime& get_Mfg0last_publish_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MESimStudy")

   virtual ~Mfg0MESimStudy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
