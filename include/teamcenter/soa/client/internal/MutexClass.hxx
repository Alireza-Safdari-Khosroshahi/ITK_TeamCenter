
#ifndef SOA_MUTEX_CLASS
#define SOA_MUTEX_CLASS

#ifndef WINDOWS
#if defined(WIN32) || defined(WIN64)
#define WINDOWS
#endif
#endif

#ifndef WINDOWS
#include <pthread.h>
#else
#include <windows.h>
#endif

typedef unsigned long ThreadId_t;
ThreadId_t getCurrentThreadId();

class CMutexClass
{
private:
#ifdef WINDOWS
    HANDLE m_mutex;
#else
    pthread_mutex_t m_mutex;
#endif
    ThreadId_t m_owner;
public:
    bool m_bCreated;
    void Lock(ThreadId_t id);
    void Unlock(ThreadId_t id);
    CMutexClass(void);
    ~CMutexClass(void);
};
#endif
