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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DISPATCHERREQUEST_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DISPATCHERREQUEST_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanFile;


class TCSOACLIENTMNGD_API DispatcherRequest : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_providerName();
    const std::string& get_serviceName();
    int get_priority();
    const Teamcenter::Soa::Client::ModelObjectVector& get_primaryObjects();
    const Teamcenter::Soa::Client::ModelObjectVector& get_secondaryObjects();
    const std::string& get_taskID();
    const Teamcenter::Soa::Client::StringVector& get_argumentKeys();
    const Teamcenter::Soa::Client::StringVector& get_argumentData();
    const std::string& get_type();
    const Teamcenter::Soa::Common::DateTime& get_startTime();
    const Teamcenter::Soa::Common::DateTime& get_endTime();
    int get_interval();
    const Teamcenter::Soa::Client::StringVector& get_dataFilesKeys();
    size_t count_dataFiles();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_dataFiles_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_historyStates();
    const Teamcenter::Soa::Common::DateTimeVector& get_historyDates();
    const std::string& get_currentState();
    int get_mode();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DispatcherRequest")

   virtual ~DispatcherRequest();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
