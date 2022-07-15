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

#ifndef TEAMCENTER_SERVICES_CORE__2009_04_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2009_04_SESSION_HXX



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
            namespace _2009_04
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:





    /**
     * Start an operation bracket.  An operation bracket is a period of execution in which
     * any object will need to be refreshed in the server from the database only once.
     * This allows the client to avoid unnecessary database operations that the server might
     * perform redundantly if underlying code accesses the same object multiple times.
     * The client will use the return value to call the <code>stopOperation</code> operation
     * to indicate the end of the bracket.  Brackets may be nested or overlapped.  A bracket
     * should start and end within the scope of a single client function and should not
     * span a user interaction.  By default, each service operation starts and stops its
     * own operation bracket.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * stopOperation
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @return
     *         The Operation Identifier assigned to the operation, to be used to stop the operation
     *         bracket.
     *
     */
    virtual std::string startOperation (  ) = 0;

    /**
     * Stop an operation bracket, in which objects need to be refreshed only once.  See
     * <code>startOperation</code>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * startOperation
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param opId
     *        The operation identifier assigned to the operation and returned by the <code>startOperation</code>
     *        request.
     *
     * @return
     *         true
     *
     */
    virtual bool stopOperation ( const std::string&  opId ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

