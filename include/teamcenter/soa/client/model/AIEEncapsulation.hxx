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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AIEENCAPSULATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AIEENCAPSULATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/AIEConnection.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Tool;


class TCSOACLIENTMNGD_API AIEEncapsulation : public Teamcenter::Soa::Client::Model::AIEConnection
{
public:
    const std::string& get_session_id1();
    Teamcenter::Soa::Common::AutoPtr<Tool> get_encapsulation_tool();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AIEEncapsulation")

   virtual ~AIEEncapsulation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
