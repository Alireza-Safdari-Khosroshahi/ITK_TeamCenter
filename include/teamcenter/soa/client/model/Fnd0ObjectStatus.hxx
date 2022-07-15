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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0OBJECTSTATUS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0OBJECTSTATUS_HXX

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
                class Fnd0DetailedMessage;
                class Fnd0KeyValuePair;
                class POM_system_class;


class TCSOACLIENTMNGD_API Fnd0ObjectStatus : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    int get_fnd0StatusType();
    size_t count_fnd0DetailedMessages();
    Teamcenter::Soa::Common::AutoPtr<Fnd0DetailedMessage> get_fnd0DetailedMessages_at( size_t inx );
    size_t count_fnd0KeyValuePairs();
    Teamcenter::Soa::Common::AutoPtr<Fnd0KeyValuePair> get_fnd0KeyValuePairs_at( size_t inx );
    size_t count_fnd0Resources();
    Teamcenter::Soa::Common::AutoPtr<POM_system_class> get_fnd0Resources_at( size_t inx );
    bool get_fnd0MyStatus();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ObjectStatus")

   virtual ~Fnd0ObjectStatus();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
