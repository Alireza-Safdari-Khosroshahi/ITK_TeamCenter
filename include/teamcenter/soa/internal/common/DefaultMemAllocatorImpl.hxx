/*==============================================================================
                 Copyright 2009 Siemens Corp. All Rights Reserved.
==============================================================================*/

/**
    @file


*/

/*  */

#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_DEFAULTMEMALLOCATORIMPL_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_DEFAULTMEMALLOCATORIMPL_HXX

#include <string>
#include <exception>
#include <list>
#include <algorithm>
#include <iostream>  //for dump()

#include <teamcenter/soa/common/MemoryAllocator.hxx>

namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {
                class DefaultMemoryAllocatorImpl;

class DefaultMemoryAllocatorImpl : public Teamcenter::Soa::Common::MemoryAllocator
{

public:
    DefaultMemoryAllocatorImpl( );

    ~DefaultMemoryAllocatorImpl();
    
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
    void* allocate(size_t size);

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
    void deallocate(void *ptr);

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
    virtual void* placementallocate(size_t size, void* _where);

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
    virtual void placementdeallocate(void *ptr, void* _where);


    std::string getAllocatorID();

};
}}}} //end namespace

#endif //TEAMCENTER_SOA_INTERNAL_COMMON_DEFAULTMEMALLOCATORIMPL_HXX
