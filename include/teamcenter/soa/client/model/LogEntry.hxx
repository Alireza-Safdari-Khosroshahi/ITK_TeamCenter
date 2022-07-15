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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_LOGENTRY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_LOGENTRY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class LogBook;


class TCSOAMROCOREMODELMNGD_API LogEntry : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const Teamcenter::Soa::Common::DateTime& get_recordingTime();
    const std::string& get_capturedBy();
    Teamcenter::Soa::Common::AutoPtr<LogBook> get_logBookTag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LogEntry")

   virtual ~LogEntry();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
