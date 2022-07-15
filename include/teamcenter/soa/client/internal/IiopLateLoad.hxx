/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
#ifndef IIOP_LATELOAD_HXX
#define IIOP_LATELOAD_HXX

#include <string>

#if defined(_MSC_VER)
    #define IIOP_LATELOAD_EXPORT __declspec(dllexport)
#else
    #define IIOP_LATELOAD_EXPORT
#endif


class IiopLateLoad
{
public:
    IiopLateLoad() {}
    virtual ~IiopLateLoad() {}
    virtual void cleanORB() = 0;
    virtual void sendRequest( const std::string& port,const std::string& method,
                              const std::string& args,      std::string& responseString  ) = 0;
    virtual void         setConnectionString( const std::string& connectionString )=0;
    virtual std::string  getIOR(bool tcServer)=0;
protected:
};

extern "C" IIOP_LATELOAD_EXPORT IiopLateLoad* createLateLoadObj();
extern "C" IIOP_LATELOAD_EXPORT void destroyLateLoadObj( IiopLateLoad* lateLoadLibObj );

#endif


