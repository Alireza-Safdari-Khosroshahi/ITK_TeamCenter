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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHARACTERISTICVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHARACTERISTICVALUE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class LogEntry;


class TCSOAMROCOREMODELMNGD_API CharacteristicValue : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_characteristicDefinition();
    double get_characteristicValue();
    const Teamcenter::Soa::Common::DateTime& get_recordingTime();
    Teamcenter::Soa::Common::AutoPtr<LogEntry> get_logEntryTag();
    const Teamcenter::Soa::Common::DateTime& get_characteristicDateValue();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CharacteristicValue")

   virtual ~CharacteristicValue();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
