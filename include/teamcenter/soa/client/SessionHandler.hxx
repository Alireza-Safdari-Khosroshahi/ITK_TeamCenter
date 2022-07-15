// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2009.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
#ifndef  TEAMCENTER_SOA_CLIENT_SESSIONHANDLER_HXX
#define  TEAMCENTER_SOA_CLIENT_SESSIONHANDLER_HXX
#include <string>
#include <new>
#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
/**
 * The SessionHandler is used by the ModelManager to notify the client application
 * of changes to the session state.
 * Clients should extend it and override the desired methods to change the default behavior.
 *
 */
class TCSOACLIENTMNGD_API SessionHandler
{
public:

    virtual ~SessionHandler();

    /**
     * This method is called by the SOA Framework when this client application
     * has changed one of the shared session variables.
     *
     * @param userSession   UserSession containing latest values for group, role, etc.
     */
    virtual void localSessionChange(Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> userSession ) ;

    /**
     * This method is called by the SOA Framework when another client application
     * using the same server has changed one of the shared session variables.
     *
     * @param userSession   UserSession containing latest values for group, role, etc.
     */
    virtual void sharedSessionChange( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> userSession );


    //void sharingStatusChange( boolean isSharingServer);  // when server starts/stops being shared


    /**
     * This method is called by the SOA Framework when a problem occurs with the
     * TCCS mechanism for sharing session state across clients.
     * 
     * @param e   InternalServerException.
     */
    virtual void handleException( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InternalServerException& e ) ; // problem with TcMEM event sharing

    SOA_CLASS_NEW_OPERATORS    

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
