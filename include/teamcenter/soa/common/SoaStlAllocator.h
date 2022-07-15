#ifndef SOA_STL_ALLOCATOR_H_INCLUDED
#define SOA_STL_ALLOCATOR_H_INCLUDED

#ifdef _WIN32
#ifndef WNT
#define WNT
#endif
#endif

#ifdef _WIN64
#ifndef WNT
#define WNT
#endif
#endif

#include <memory>
#include <teamcenter/soa/common/MemoryManager.hxx>

#ifdef WNT
#pragma warning(push)
#pragma warning(disable:4100) // this is a warning about destroy(pointer ptr) having ptr unused which isn't really true
#include <typeinfo>
#endif

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            /** STL Allocator for Teamcenter memeory,  this class dispatches STL
              * allocator functions to the SM C++ memory area by using
              * the Teamcenter::Soa::Common::MemoryManager class.
              *
              * This class should be used by all internal SOA STL containers
              */
            template <class AllocatorType>
            class tcsoastlallocator
            {
            public:

                typedef AllocatorType        value_type;
                typedef value_type *       pointer;
                typedef const AllocatorType* const_pointer;
                typedef AllocatorType&       reference;
                typedef const AllocatorType& const_reference;
                typedef size_t     size_type;
                typedef ptrdiff_t  difference_type;


                template <class NewAllocatorType>
                struct rebind
                {
                    typedef tcsoastlallocator<NewAllocatorType> other;
                };

                /** constructors and destructors are noop's becuase this allocator carries no
                   *state, it simple delegates responsiblity to the Teamcenter::Soa::Common::MemoryManager::allocate()
                   */
                tcsoastlallocator()
                {
                }

                /** constructors and destructors are noop's becuase this allocator carries no
                  * state, it simple delegates responsiblity to the Teamcenter::Soa::Common::MemoryManager::allocate()
                  */

                // Add lint comment to suppress such warnings.
                template <class AllocatorType1> tcsoastlallocator(const tcsoastlallocator<AllocatorType1>&)  //lint !e1931
                {
                }

                /** constructors and destructors are noop's becuase this allocator carries no
                  *state, it simple delegates responsiblity to the Teamcenter::Soa::Common::MemoryManager::allocate()
                  */
                tcsoastlallocator(const tcsoastlallocator<AllocatorType>&)
                {
                }

                /** constructors and destructors are noop's becuase this allocator carries no
                  *state, it simple delegates responsiblity to the Teamcenter::Soa::Common::MemoryManager::allocate()
                  */
                ~tcsoastlallocator()
                {
                }


                pointer address(reference value)
                {
                    return &value;
                }


                const_pointer address(const_reference value) const
                {
                    return &value;
                }

#ifdef SUN
    // Note: SUN is not quite there with the ANSI standard so we need to
    // change static_cast to C cast, and change the arg to void *
    // for allocate and deallocate functions
    //
    //
                void* allocate(size_type sizeOfType, const void* = 0) const

                {
                    if( sizeOfType > 0 )
                    {
                        const char* typeName = "tcsoastlallocator";

                        // allocate storage for _Count elements of type value_type
                        //Fix for PR#6553223 : Now I look at Sun’s headers the argument to allocate is treated differently and is the number of bytes
                        //and not the number of objects of the allocators type you want. So we should remove the sizeof(value_type).
                        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                            return ((void *)Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->allocate(sizeOfType, typeName));
                        else
                            return (void *)(::operator new(sizeOfType));
                    }
                    else
                        return 0;

                }


                void deallocate(void* ptr, size_type) const
                {
                    if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                        Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate(ptr);
                    else
                        ::operator delete(ptr);
                }

                void deallocate(void*  ptr) const
                {
                    if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                        Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate(ptr);
                    else
                        ::operator delete(ptr);
                }

#else
                AllocatorType* allocate(size_type sizeOfType, const void* = 0) const
                {
                    if( sizeOfType > 0 )
                    {
                        const char* typeName = "tcsoastlallocator";

#ifdef WNT
                        typeName = typeid(value_type).name();
#endif
                        // allocate storage for _Count elements of type value_type
                        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                            return static_cast<value_type* >(Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->allocate(sizeOfType * sizeof (value_type), typeName));
                        else
                            return static_cast<value_type* >(::operator new(sizeOfType * sizeof (value_type)));
                    }
                    else
                        return 0;
                }


                void deallocate(pointer ptr, size_type) const
                {
                    if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                        Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate((void*)ptr);
                    else
                        ::operator delete((void*)ptr);

                }

                void deallocate(pointer ptr) const
                {
                    if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                        Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate((void*)ptr);
                    else
                        ::operator delete((void*)ptr);
                }
#ifdef WNTX64
                void deallocate(void *ptr, size_type) const
                {
                    if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                        Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->deallocate(ptr);
                    else
                        ::operator delete(ptr);
                }

                char *_Charalloc(size_type size)
                {
                    //return (char *)CppMemory::allocate(size);
                    return (char *)(::operator new(size));

                    if( sizeOfType > 0 )
                    {
                        const char* typeName = "tcsoastlallocator";

#ifdef WNT
                        typeName = typeid(value_type).name();
#endif
                        // allocate storage for _Count elements of type value_type
                        if( Teamcenter::Soa::Common::MemoryManager::getMemoryManager() )
                            return (char *)(Teamcenter::Soa::Common::MemoryManager::getMemoryManager()->allocate(size, typeName));
                        else
                            return (char *)(::operator new(size));
                    }
                    else
                        return 0;
                }
#endif
#endif

                size_type max_size() const
                {
                    return size_t(-1) / sizeof(value_type);
                }

                // required by SUN
                size_type max_size ( size_type size ) const
                {
                    return 1 > size_t(-1) / size ? size_type ( 1 ) : size_type ( size_t(-1) / size ) ;
                }


                void construct(pointer ptr, const AllocatorType& value) const
                {
                    new(ptr)AllocatorType(value);
                }

                void destroy(pointer ptr) const
                {
                    ptr->~AllocatorType();
                }

            };


            //*  specialization for tcsoastlallocator */
            template<>
            class  tcsoastlallocator<void>
            {
            public:
                typedef size_t      size_type;
                typedef ptrdiff_t   difference_type;
                typedef void*       pointer;
                typedef const void* const_pointer;
                typedef void        value_type;
            };

            /** Since the C++ allocators use the same memory area
             *  comparing 2 allocators always return true
             */

            template <class _T1, class _T2>
                inline bool operator==(const tcsoastlallocator<_T1>&,
                const tcsoastlallocator<_T2>& )
            {
                return (true);

            }


            /** Since the C++ allocators use the same memory area
             *  comparing 2 allocators always return true
             */
            template <class _T1, class _T2>
                inline bool operator!=(const tcsoastlallocator<_T1>&,
                const tcsoastlallocator<_T2>& )
            {
                return (false);

            }

            typedef std::basic_string<char, std::char_traits<char>, Teamcenter::Soa::Common::tcsoastlallocator<char> >  TcSoaString;
        }
    }
}


#ifdef WNT
#pragma warning(pop)
#endif

#endif
