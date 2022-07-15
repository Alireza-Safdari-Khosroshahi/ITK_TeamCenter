/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_CORE_ENVELOPESERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_ENVELOPESERVICE_HXX

#include <teamcenter/services/core/_2011_06/Envelope.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class EnvelopeService;

/**
 * The Envelope service provides an operation for sending envelopes to the associated
 * recipients. An envelope represents Envelope business object with information about
 * a mail such as subject, body of message, recipients, and attachments. Recipients
 * are of two types: external and internal, and can be added under To or Cc list. External
 * recipients are email addresses, while internal recipients are Teamcenter users, groups
 * and address lists. Envelopes are delivered as email notifications to external recipients.
 * For internal recipients, the envelopes are delivered to the associated user Teamcenter
 * Mailbox. However, if the Mail_OSMail_activated site preference is set to <code>true</code>,
 * email notifications are also sent to the internal recipients.
 * <br>
 * This service addresses the following use cases:
 * <br>
 * <ul>
 * <li type="disc">Send mail messages and emails to Teamcenter users
 * </li>
 * <li type="disc">Send emails to external users
 * </li>
 * </ul>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API EnvelopeService
    : public Teamcenter::Services::Core::_2011_06::Envelope
{
public:
    static EnvelopeService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation sends mails to the recipients of each <b>Envelope</b> business object
     * in envelopes. All the envelopes passed to this operation are deleted after they are
     * processed, even if the processing is not successful. Each <b>Envelope</b> business
     * object contains mail information such as subject, body, recipients, and attachments.
     * Recipients can be Teamcenter users, groups and address lists, or, external email
     * addresses. Teamcenter users receive envelopes in their Teamcenter Mailbox and also
     * as emails if <b>Mail_OSMail_activated</b> site preference is set to <code>true</code>.To
     * send the emails, the site preference <b>Mail_server_name</b> should be properly configured.
     * Any errors that occur while sending envelopes are returned as partial errors in ServiceData.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use case 1: <b>Send envelopes to Teamcenter users</b>
     * <br>
     * You can send envelopes to the Mailbox of Teamcenter users by specifying the users
     * as recipients on Envelope business objects.  Also, email messages can be sent to
     * Teamcenter users if Mail_OSMail_activated site preference is set to <code>true</code>.
     * <br>
     * <br>
     * User case 2: <b>Send emails to external email addresses</b>
     * <br>
     * Email messages can be sent to external users by specifying their email addresses
     * as recipients on Envelope business objects.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mail - Sends SMTP (Simple Mail Transfer Protocol) e-mail to Teamcenter users.Uses
     * platform-independent utility to send e-mail on both UNIX and Windows platforms.
     *
     * @param envelopes
     *        The list of <b>Envelope</b> business objects to be sent.
     *
     * @return
     *         This operation returns an instance of <code>ServiceData</code> which will contain
     *         partial errors occurred in sending out the envelopes.
     *         <br>
     *         Following are possible errors which may occur during the process:
     *         <br>
     *         <ul>
     *         <li type="disc">17007&nbsp;&nbsp;&nbsp;&nbsp;There are no receivers in the recipients
     *         lists
     *         </li>
     *         <li type="disc">17033&nbsp;&nbsp;&nbsp;&nbsp;Mail_OSMail_activated site preference
     *         is set to false
     *         </li>
     *         <li type="disc">17029&nbsp;&nbsp;&nbsp;&nbsp;Failed to send mail possibly due to
     *         Mail_server_name site preference not being set properly.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData sendAndDeleteEnvelopes ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Envelope>  >& envelopes ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EnvelopeService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

