// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2011.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 
/** 
    @file 
 
    Class declaration for dynamic loading of TcServer CPP binding library
 
*/

#ifndef TSP_LATELOAD_HXX
#define TSP_LATELOAD_HXX

#include <iostream>
#include <map>

#include "TcServerCppBinding/EnvironmentInfo.hxx"

#if defined(_MSC_VER)
    #define TSP_LATELOAD_EXPORT __declspec(dllexport)
#else
    #define TSP_LATELOAD_EXPORT
#endif

class TspLateLoad
{
public:
    TspLateLoad() {}
    virtual ~TspLateLoad() {}
    virtual void initTsp() = 0;
    virtual void termTsp() = 0;
    virtual Teamcenter::Net::TcServerProxy::Admin::EnvironmentInfo* getEnvInfo() = 0;
    virtual Teamcenter::Net::TcServerProxy::Client::TSPSession* getTSPSession() = 0;
    virtual void setTSPSession(Teamcenter::Net::TcServerProxy::Client::TSPSession* tspSession) = 0;
    virtual void setProxyCredProvider(const Teamcenter::Net::TcServerProxy::Client::CredentialProvider* pCredProv) = 0;
    virtual const Teamcenter::Net::TcServerProxy::Client::CredentialProvider* getProxyCredProvider() = 0;
    virtual const std::vector< const Teamcenter::Net::TcServerProxy::Admin::Environment* > &getEnvironments() = 0;
    virtual const std::vector< const Teamcenter::Net::TcServerProxy::Admin::Environment* > &getEnvsForVersion(const std::string& expression) = 0;
    virtual const std::vector< const Teamcenter::Net::TcServerProxy::Admin::Environment* > &getEnvironmentsForURL(const std::string& inURL) = 0;
    virtual const Teamcenter::Net::TcServerProxy::Admin::Environment* getEnvironment(const std::string& envName) = 0;
    virtual std::string getServerAddress( std::string& envName ) = 0;
    virtual void sendRequest( const std::string& args,       
                              std::map<std::string, std::string>& tspHeaderList,
                              std::string& responseString ) = 0;
protected:
};

extern "C" TSP_LATELOAD_EXPORT TspLateLoad* createTspLateLoadObj();
extern "C" TSP_LATELOAD_EXPORT void destroyTspLateLoadObj( TspLateLoad* lateLoadLibObj );

#endif


