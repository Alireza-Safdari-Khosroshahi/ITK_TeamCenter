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

#ifndef TEAMCENTER_SERVICES_CORE__2007_12_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2007_12_SESSION_HXX

#include <teamcenter/soa/client/model/IdDispRule.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2007_12
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct StateNameValue;

    /**
     * This structure is used to hold a single name/value pair.
     */
    struct StateNameValue
    {
        /**
         * The name of the UserSession state property.
         */
        std::string name;
        /**
         * The value of the state property.
         */
        std::string value;
    };




    /**
     * Set the ID display rule for the session and optionally set it in the database.  The
     * business objects from the <code>identifiableObjects</code> list are expanded using
     * the new ID display rule and returned. The rule is applied to all business objects
     * process throughout the rest of the session.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param identifiableObjects
     *        A list of business objects for which the new ID display rule has to be re-evaluated.
     *
     * @param displayRule
     *        The ID display rule that is to be used for evaluation.
     *
     * @param setRuleAsCurrentInDB
     *        If true then the ID display rule will be set for the current user in the database.
     *
     * @return
     *         If the requested <code>displayRule</code> is invalid, partial error 214312 is returned,
     *         and none of the  <code>identifiableObjects</code> are processed.  Otherwise each
     *         <code>identifiableObjects</code> is expanded with the new ID display rule and returned
     *         in the plain list of the <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setAndEvaluateIdDisplayRule ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& identifiableObjects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdDispRule>  displayRule,
        bool setRuleAsCurrentInDB ) = 0;

    /**
     * Set the desired user session state values.  To clear a field's value, pass an empty
     * string "" as the value. Failure to set a particular state value will result in a
     * Partial Error with the clientId set to the name of the state property. State values
     * can be per client session or per server session. Client session state is kept separate
     * for each client application sharing the same Teamcenter server session, while server
     * session state is shared with all client application sharing the Teamcenter server
     * session. Valid keys for the session state pairs are:
     * <br>
     * <ul>
     * <li type="disc"><i>groupMember</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired
     * <b>GroupMember</b> (server session).
     * </li>
     * <li type="disc"><i>currentProject</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired
     * <b>Project</b> (server session).
     * </li>
     * <li type="disc"><i>workContext</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired
     * <b>WorkContext</b> (server session).
     * </li>
     * <li type="disc"><i>currentOrganization</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
     * desired <b>Organization</b> (server session).
     * </li>
     * <li type="disc"><i>refreshPOM</i> &nbsp;&nbsp;&nbsp;&nbsp;'1' (true) to refresh business
     * objects in the POM before returning property values. This ensures property data is
     * up-to-date, but is a performance hit (client session).
     * </li>
     * <li type="disc"><i>maxOperationBracketTime</i>&nbsp;&nbsp;&nbsp;&nbsp;Time (seconds)
     * to bracket to limit a  POM refresh (client session).
     * </li>
     * <li type="disc"><i>maxOperationBracketInactiveTime</i>  Time (seconds) to bracket
     * to limit a  POM refresh (client session).
     * </li>
     * <li type="disc"><i>currentChangeNotice</i>&nbsp;&nbsp;&nbsp;&nbsp;The UID of the
     * desired <b>ChangeNotice</b> (server session).
     * </li>
     * <li type="disc"><i>clientVersion</i>&nbsp;&nbsp;&nbsp;&nbsp;The version of the client
     * (client session).
     * </li>
     * <li type="disc"><i>locale</i>&nbsp;&nbsp;&nbsp;&nbsp;The locale of the session (server
     * session).
     * </li>
     * <li type="disc"><i>volume</i> &nbsp;&nbsp;&nbsp;&nbsp;The UID of the desired <b>Volume</b>
     * (server session).
     * </li>
     * <li type="disc"><i>objectPropertyPolicy</i>&nbsp;&nbsp;&nbsp;&nbsp;The name of the
     * desired object property policy.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param pairs
     *        A list of name/value pairs of state properties to set.
     *
     * @return
     *         A partial error for any state value that was not set. The 'clientId' of the partial
     *         error is set to the name of the state variable.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setUserSessionState ( const std::vector< Teamcenter::Services::Core::_2007_12::Session::StateNameValue >& pairs ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

