/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/


#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_LOGCORRELATION_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_LOGCORRELATION_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {
/**
 * The LogCorrelation class is used to create unique IDs that can be passed
 * from tier to tier with a service request, so that any log messages on each
 * tier that processes the service request can be synced/correlated with logs
 * on other tiers.
 * 
 * By default the ID will have the host name and process/thread ID, the SOA Framework
 * will add information to uniquely identify each service reqest, so the ID sent 
 * with the service request to the server will have the form:
 * <pre>
 * host.process.connection.user.request
 * where:
 *  host:       The name of the client host
 *  process:    Unique Id for the process/thread
 *  connection: Index of the Connection instance associated with this request
 *  user:       The User name asscociated with this Connection/request
 *  reqest:     Counter of service request for this Connection
 * 
 * example:
 *  cyi6p007.45089.01.infodba.00124
 * </pre>
 * 
 * The client applicaiton can insert any informtion into this ID between the process
 * and connection elements, using the <code>push</code> method. This infromation
 * will remain on the ID for the life of the application, or until the <code>pop</code>
 * method is called.
 *
 */
class TCSOACOMMON_API LogCorrelation
{

public:
    /**
     * Push information onto the end of the ID string.
     * Each element is delimited by a '.' in the ID string. 
     * 
     * @param id    Element to add to the end of the ID string
     */
    static void push( const std::string& id );
    
    /**
     * Pop the last element from the ID string.
     * Each element is delimited by a '.' in the ID string. 
     * 
     */
    static void pop( );

    
    /**
     * Get the ID string
     * 
     * @return the ID string
     */
    static std::string getId();
                
    static void clear();
    static int  size();

    SOA_CLASS_NEW_OPERATORS

private:    
    static LogCorrelation* getCurrent();

    static std::map<unsigned long, LogCorrelation*> logs;

    LogCorrelation();
    ~LogCorrelation();
    
 
    std::vector<std::string>   stack;
                  
};
}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif

