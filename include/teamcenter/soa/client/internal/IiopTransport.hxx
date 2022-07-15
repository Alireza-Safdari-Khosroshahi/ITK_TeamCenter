// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_INTERNAL_IIOPTRANSPORT_HXX
#define TEAMCENTER_SOA_CLIENT_INTERNAL_IIOPTRANSPORT_HXX


#include <string>
#include <teamcenter/soa/client/internal/Transport.hxx>
#include <teamcenter/soa/client/internal/IiopLateLoad.hxx>
#include <teamcenter/soa/client/internal/LateLoad.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class TCSOACLIENTMNGD_API IiopTransport : public Transport
{
public:
    SOA_CLASS_NEW_OPERATORS
    explicit IiopTransport(  Teamcenter::Soa::Client::SessionManager *sessionManager );
    ~IiopTransport();

    virtual void sendRequest( const std::string& port, const std::string& method, const std::string& args, const std::string& servletURI, std::string& responseString );

    std::string  getIOR(bool tcServer);

protected:


private:
     static int sSenderCount;

    // Don't allow default and copy constructors
    IiopTransport();
    IiopTransport( const IiopTransport& right);
    IiopTransport& operator = ( const IiopTransport& right);

    void connect( const std::string& connectString );

    std::string m_connectString;
    LateLoad* lateLoad;
    IiopLateLoad* lateLoadObj;
    typedef IiopLateLoad* createLateLoadObj_t();
    typedef void deleteLateLoadLib_t( IiopLateLoad* );    
};


}}} // namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif