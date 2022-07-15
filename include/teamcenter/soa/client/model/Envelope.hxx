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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ENVELOPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ENVELOPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Folder.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class User;


class TCSOACLIENTMNGD_API Envelope : public Teamcenter::Soa::Client::Model::Folder
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_listOfReceivers();
    bool get_envelopeReadFlag();
    const Teamcenter::Soa::Common::DateTime& get_sent_date();
    const Teamcenter::Soa::Client::StringVector& get_fnd0ListOfExtRecipients();
    const Teamcenter::Soa::Client::StringVector& get_fnd0ListOfCcExtRecipients();
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0ListOfCcRecipients();
    Teamcenter::Soa::Common::AutoPtr<User> get_senders_tag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Envelope")

   virtual ~Envelope();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
