// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_LOGGER_HXX
#define TEAMCENTER_SOA_CLIENT_LOGGER_HXX

#include <string>
#include <map>
#include <new>
#include <cstdio>




#include <teamcenter/soa/client/RequestListener.hxx>
#include <teamcenter/soa/client/Connection.hxx>
#include <teamcenter/soa/common/MemoryManager.hxx>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**
 * This class provides basic logging for the SOA Client framework.
 *
 * By default the this class will log at ERROR level to the file
 * $TEMP/soaclient_<id>.log. 
 * This can also be changed with the environment variable or programaticaly.
 *   Environment Variable: TC_SOACLIENT_LOGGING=ERROR|WARN|INFO|DEBUG,
 *   Programatically:      Logger::setLoggingLevel
 * Setting it progmaatically will take precidence over the environment variable.
*/

class Logger :  public Teamcenter::Soa::Client::RequestListener
{
public:



    ~Logger();

    /**
     * Set the logging level of the SOA Framework.
     * By default the framework will log at ERROR level to the file
     * $TEMP/soaclient_<id>.log. This can also be changed with the environment
     * variable TC_SOACLIENT_LOGGING=ERROR|WARN|INFO|DEBUG, howerver setting it progmatically
     * through this method will take precidence.
     * @param logFile   Pointer to a file to write all messages to. If NULL the
     *                  default file of $TEMP/soaclient_<id>.log will be used.
     * @param level     Level at which to log messages
     */
    static void    setLoggingLevel( FILE* logFile, Teamcenter::Soa::Client::Connection::LoggingLevel level);

    /**
     * Get the current logging level .
     *
     * @return The current logging level.
     */
    static Teamcenter::Soa::Client::Connection::LoggingLevel   getLoggingLevel();

    /**
     * Get the singleton instance of the this class.
     */
    static Logger* getInstance();

    static bool isErrorEnabled(  );
    static bool isWarnEnabled (  );
    static bool isInfoEnabled (  );
    static bool isDebugEnabled(  );


    /**
     * Log the message at ERROR level.
     */
    static void error( const std::string& message );
     /**
     * Log the message at WARN level.
     */
    static void warn ( const std::string& message );
    /**
     * Log the message at INFO level.
     */
    static void info ( const std::string& message );
    /**
     * Log the message at DEBUG level.
     */
    static void debug( const std::string& message );


    virtual void serviceRequest ( const Teamcenter::Soa::Client::ServiceInfo& info );
    virtual void serviceResponse( const Teamcenter::Soa::Client::ServiceInfo& info );
    SOA_CLASS_NEW_OPERATORS

    static long currentTimeMillis();
    static long elapsedTimeMillis( long start);

private:
    struct RequestInfo
    {
        long            start;
        std::string     size;
    };

    static Logger* s_singlton;
    static Teamcenter::Soa::Client::Connection::LoggingLevel   s_level;
    static std::map<unsigned long, RequestInfo> s_infoMap;
    static bool makeDirectories( const std::string& folderPath );

    FILE*   m_logFile;
    
    Logger();
    void log( const Teamcenter::Soa::Client::Connection::LoggingLevel& level, const std::string& message );



};

}}} //end namespace
#endif
