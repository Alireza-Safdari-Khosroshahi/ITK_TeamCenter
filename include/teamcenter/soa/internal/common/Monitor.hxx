/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_MONITOR_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_MONITOR_HXX

#include <string>
#include <ctime>
#include <vector>
#include <map>


#include <teamcenter/soa/common/SoaCommonExports.h>



namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
             {

class TCSOACOMMON_API ThreadProvider
{
public:
    virtual long getCurrentThreadId()=0;

};

class TCSOACOMMON_API Mark 
{
public: 
    Mark();
    explicit Mark( const std::string& label);
    ~Mark();

    long getElapsedTime() const;
    
    std::string  label;
    time_t       startSeconds;
    int          startMilli;
};

class TCSOACOMMON_API ExecutionTime 
{
public: 
 
    ExecutionTime();
    explicit ExecutionTime( const std::string& label );
    ~ExecutionTime( );

    void updateChildren( const std::vector<Mark*>& marks, size_t index );
    ExecutionTime* getExecutionTime( const std::vector<Mark*>& marks, size_t index );
    std::string toString( const std::string& pad="" );
    
    
    std::string                  label;
    std::string                  dataUnits;
    long                         totalTime;
    long                         dataValue;
    int                          nCalls;
    std::vector<ExecutionTime*>  children;
};






class TCSOACOMMON_API Monitor 
{
public: 
    static void setThreadProvider( ThreadProvider* threadProvider );
    static void enable   ( bool enable );
    static void markStart( const std::string& label );
    static void markEnd  ( const std::string& label );
    static void markEnd  ( const std::string& label, const std::string& dataUnits, int dataValue );
    static std::string dumpTimes(  );

 
private:   

    static std::vector<Mark*>* getMarkStack();
    static void addTimeStackToExTimes            ( const std::vector<Mark*>& markStack, const std::string& label);
    static ExecutionTime* getCurrentExecutionTime( const std::vector<Mark*>& markStack );

    static std::map< std::string, std::vector<Mark*>* >   activeMarkStacks;
    static std::map<std::string, ExecutionTime*>          keyExTimes;
    
    static bool    enabled;
    static ThreadProvider* threadProvider;
};


}}}}


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

