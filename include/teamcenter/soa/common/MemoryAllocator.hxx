/*==============================================================================
                 Copyright 2009 Siemens Corp. All Rights Reserved.
==============================================================================*/

/**
    @file
    This file defines an interface for MemoryAllocator.
    Client applications needs to implement this interface to get control over 
    all the memory allocations and deallocations.
    
    Features of the Memory Allocator
    1. This is an interface needs to be implemented by the client application to get access to CDM memory.

    2. Call MemoryManager::initializeMemoryManager factory method before even creating a connection object
       and register the client implemented allocator.

    3. Default: Framework will initialize a default allocator if client application has not initialized one.

*/

/*  */
#ifndef TEAMCENTER_SOA_CLIENT_MEMORYALLOCATOR_HXX
#define TEAMCENTER_SOA_CLIENT_MEMORYALLOCATOR_HXX

#include <string>

#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {


class TCSOACOMMON_API MemoryAllocator
{
public:

    /**
     * Allocates memory for requested size and returns a pointer.
     * Client application needs to implement this method for efficient memory management.
     *
     *
     * @param size   size of the memory to be allocated.
     *
     * @return pointer to the allocated block of memory.
     *
     */
    virtual void* allocate(size_t size) = 0;

    /**
     * Deallocates memory for requested pointer.
     * Client application needs to implement this method for efficient memory management.
     *
     *
     * @param ptr   pointer to the memory to be deallocated.
     *
     * @return void.
     *
     */
    virtual void deallocate(void *ptr) = 0;

    /**
     * Allocates memory for requested size and returns a pointer.
     * Equalent function for placement new
     * Please read placement new standards for implementing this.
     *
     * @param size   size of the memory to be allocated.
     * @param _where .
     *
     * @return pointer to the allocated block of memory at _where.
     *
     */
    virtual void* placementallocate(size_t size, void* _where) = 0;

    /**
     * Deallocates memory for requested pointer.
     * Equalent function for placement delete
     * Please read placement new standards for implementing this.
     *
     * @param ptr   pointer to the memory to be deallocated.
     * @param _where  .
     *
     * @return void.
     *
     */
    virtual void placementdeallocate(void *ptr, void* _where) = 0;

    /**
     * gets the allocator identifier.
     * Client application needs to implement this method to return a identifier for their implementation.
     *
     * @return std::string.
     *
     */
    virtual std::string getAllocatorID() = 0;

    MemoryAllocator( ) {};

    virtual ~MemoryAllocator(){};
};
}}} //end namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif //TEAMCENTER_SOA_CLIENT_MEMORYALLOCATOR_HXX
