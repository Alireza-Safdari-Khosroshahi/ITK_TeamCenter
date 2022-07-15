/*==============================================================================
                 Copyright 2009 Siemens Corp. All Rights Reserved.
==============================================================================*/

/**
    @file

    The MemoryManager provides the client application access to all Teamcenter
    Data Model objects Memory. To take advantage of this feature, client application
    needs to implement Allocator class deriving from Teamcenter::Soa::Common::MemoryAllocator
    class and call MemoryManager::initializeMemoryManager factory method before even
    creating a connection object. Once a connection object is created, Framework will check to
    see if there is any MemoryManager initialized by the client application, if not one
    then it initializes with a default allocator.

    Features of the Memory Manager

    1. Clients needs to implement MemoryAllocator interface.

    2. Call MemoryManager::initializeMemoryManager factory method before even creating a connection object.

    3. Default: Framework will initialize a default allocator if client application has not initialized one.

*/

/*  */
#ifndef TEAMCENTER_SOA_CLIENT_MEMORYMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_MEMORYMANAGER_HXX

#include <string>
#include <new> // for size_t
#include <map>

//#ifdef _WIN32
//#include <typeinfo>
//#endif

#include <teamcenter/soa/common/MemoryAllocator.hxx>
#include <teamcenter/soa/common/SoaCommonExports.h>

#ifdef _DEBUG
#define DEBUG_NEW new
#endif

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            class MemoryManager;
            struct MemoryInfo;
            struct MemObjectInfo;
            //typedef std::map<void*, size_t, std::less<void*>, tcsoastlallocator<std::pair<const void*, size_t> > > MemoryMap;
            typedef std::map<void*, MemObjectInfo> MemoryMap; //Only used for special debugging during memory tracking

struct TCSOACOMMON_API MemObjectInfo
{
    size_t       size;       //Memory size requested
    std::string  typeName;   //Class name for which memory is allocated.

    MemObjectInfo();
    MemObjectInfo(size_t memsize, const char* typeNameIn);
};

struct TCSOACOMMON_API MemoryInfo
{
    double currentAllocSize; //This is in KB
    double PeakMemSize;      //This is in KB
    size_t LargestMemSizeRequested; //Bytes

    MemoryInfo();
};

class TCSOACOMMON_API MemoryManager
{
public:
    /**
     * Creates a singleton memory manager object and initializes with allocator.
     * Calling this more than once will return false indicating that the initialization already happened.
     * If Client application wants to Create memory manager with their allocator, this must be called before creating even connection object.
     * If it has not been called, Framework will initalize with default allocator and no way to alter after that in that session.
     *
     * @return bool. true if successful.
     *
     */
    static bool initializeMemoryManager( MemoryAllocator* memAllocator, bool bTrackSoaMemory = false );

    /**
     * Gets a singleton MemoryManager object.
     *
     *
     * @return pointer to the MemoryManager singleton object.
     *
     */
    static Teamcenter::Soa::Common::MemoryManager* getMemoryManager();


    /**
     * Allocates memory for requested size and returns a pointer.
     * This intern deligates call to the allocator
     *
     *
     * @param size       size of the memory to be allocated.
     * @param typeName   the name of the type to be allocated.
     *
     * @return pointer to the allocated block of memory.
     *
     */
    void* allocate(size_t size, const char* typeName=NULL);

    /**
     * Deallocates memory for requested pointer.
     * This intern deligates call to the allocator.
     *
     *
     * @param ptr   pointer to the memory to be deallocated.
     *
     * @return void.
     *
     */
    void deallocate(void *ptr);

    /**
     * Allocates memory for requested size and returns a pointer.
     * This intern deligates call to the allocator
     * Equalent function for placement new
     * Please read placement new standards for implementing this.
     *
     * @param size   size of the memory to be allocated.
     * @param _where .
     *
     * @return pointer to the allocated block of memory.
     *
     */
    void* placementallocate(size_t size, void* _where);

    /**
     * Deallocates memory for requested pointer.
     * Equalent function for placement delete
     * This intern deligates call to the allocator.
     * Please read placement new standards for implementing this.
     *
     * @param ptr   pointer to the memory to be deallocated.
     * @param _where .
     *
     * @return void.
     *
     */
    void placementdeallocate(void *ptr, void* _where);

    /**
     * gets the allocator identifier.
     * This intern deligates call to the allocator
     *
     * @return std::string.
     *
     */
    virtual std::string getAllocatorID();


    /**
     * gets the Memory Information if the Tracking is enabled.
     *  No action if tracking is not enabled. This is for debug purpose.
     *
     * @param memInfo  memory info output.
     *
     * @return bool true if tracking is enabled, false if tracking is not enabled.
     *
     */
    bool getSoaMemoryInfo(Teamcenter::Soa::Common::MemoryInfo& memInfo ) const;

    /**
     * dumps memory table into a file for tracking.
     * No action if tracking is not enabled. This is for debug purpose
     *
     * @param filepath  full file name including path (input).
     *
     * @return bool true if success
     *
     */
    bool dumptofile(const char* filepath );

    static void* operator new (size_t size);
    static void operator delete (void *p);



private:
    MemoryAllocator*        m_memAllocator;
    bool                    m_bDefaultAllocatorSet; //set to true if default allocator is used.

    static MemoryManager*   m_sMemoryManager;

    //DEBUG: Only used for special debugging during memory tracking
    Teamcenter::Soa::Common::MemoryInfo*      m_pMemInfo;
    Teamcenter::Soa::Common::MemoryMap m_memoryMap;

    explicit MemoryManager( MemoryAllocator* memAllocator, bool bTrackSoaMemory = false );

    // Don't allow default and copy constructors
    explicit MemoryManager( );
    MemoryManager( const MemoryManager& right);
    MemoryManager& operator = ( const MemoryManager& right);

    virtual ~MemoryManager();
};
}}} //end namespace

//SOA NEW operator Macros
#define SOA_CLASS_NEW_OPERATORS \
    static void* operator new (size_t size); \
    static void operator delete (void *p); \
    static void* operator new(size_t, void* _Where); \
    static void operator delete(void *, void*); \
    static void* operator new[](size_t, void* _Where){return (_Where);} \
    static void operator delete[](void *, void*){}

#define SOA_CLASS_NEW_OPERATORS_IMPL(TYPE, TYPENAME) \
    void* TYPE::operator new (size_t size) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            return Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->allocate(size, TYPENAME ); \
        else \
            return ::operator new(size); \
    }; \
    void TYPE::operator delete (void *p) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate(p); \
        else \
            ::operator delete(p); \
    }; \
    void* TYPE::operator new(size_t size, void* _Where) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            return Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->placementallocate(size, _Where); \
        else \
            return (_Where); \
    }; \
    void TYPE::operator delete(void *p, void* _Where) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->placementdeallocate(p, _Where); \
    };

#define SOA_CLASS_NEW_OPERATORS_WITH_IMPL(TYPENAME) \
    static void* operator new (size_t size) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            return Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->allocate(size, TYPENAME); \
        else \
            return ::operator new(size); \
    }; \
    static void operator delete (void *p) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate(p); \
        else \
            ::operator delete(p); \
    }; \
    static void* operator new(size_t size, void* _Where) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            return Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->placementallocate(size, _Where); \
        else \
            return (_Where); \
    }; \
    static void operator delete(void *p, void* _Where) \
    { \
        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() ) \
            Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->placementdeallocate(p, _Where); \
    }; \
    static void* operator new[](size_t, void* _Where){return (_Where);} \
    static void operator delete[](void *, void*){}


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif //TEAMCENTER_SOA_CLIENT_MEMORYMANAGER_HXX
