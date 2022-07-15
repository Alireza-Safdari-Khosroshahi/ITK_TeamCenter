//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_THREADS_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_THREADS_HXX


#ifdef WNT
#include <windows.h>
#else
#include <pthread.h>
#endif



#include <teamcenter/soa/common/SoaCommonExports.h>


typedef unsigned long ThreadId_t;


namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {
                class Threads;
                class Mutex;
                class ScopedLock;
            }
        }
    }
}

class TCSOACOMMON_API Teamcenter::Soa::Internal::Common::Threads
{
public:
    static ThreadId_t getCurrentThreadId();
};


class TCSOACOMMON_API Teamcenter::Soa::Internal::Common::Mutex
{
public:
    Mutex();
    ~Mutex();

    void lock();
    void unlock();
private:

#ifdef WNT
    HANDLE      m_mutex;
#else
    pthread_mutex_t m_mutex;
#endif

    ThreadId_t  m_owner;
    int         m_lockCount;


};

class TCSOACOMMON_API Teamcenter::Soa::Internal::Common::ScopedLock
{
public:
     ScopedLock( Teamcenter::Soa::Internal::Common::Mutex* mutex );
    ~ScopedLock();
private:
    Teamcenter::Soa::Internal::Common::Mutex* mMutex;
};

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif
