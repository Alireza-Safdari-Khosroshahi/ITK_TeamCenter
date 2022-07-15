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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEROBOTICOPVERSIONMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEROBOTICOPVERSIONMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MEProcessTypeVersionMaster.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API MERoboticOpVersionMaster : public Teamcenter::Soa::Client::Model::MEProcessTypeVersionMaster
{
public:
    const std::string& get_operation_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MERoboticOpVersionMaster")

   virtual ~MERoboticOpVersionMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
