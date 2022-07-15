/*==================================================================================================

                               Copyright (c) 2004 UGS Corp.
                             Unpublished - All rights reserved

====================================================================================================
File description:
    <BJS> 16-Nov-2004
    An implementation of unordered_map as specified in
        http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1687.pdf

====================================================================================================
   Date      Name                    Description of Change

16-Nov-2004  Bernie Solomon          Initial version written
17-Nov-2004  Bernie Solomon          Tweak to get to compile on every Unix platform
23-Nov-2004  Bernie Solomon          Reduce qaz messages a tad
09-Feb-2005  Bernie Solomon          Add some QAZ annotation
05-Dec-2005  Bernie Solomon          Wee bit of doc
10-Feb-2006  Bernie Solomon          Add UGS::unordered_map to set up SM allocator for you
15-Feb-2006  Bernie Solomon          Fix HP compile
19-May-2008  Bernie Solomon          Enable multi versions of unordered_map/set
11-Jun-2008  Bernie Solomon          Fix some Linux compile warnings
12-Jun-2008  Bernie Solomon          I missed some cases yesterday
13-Mar-2009  D.Silkworth             Adapted NX unordered_map to use in Teamcenter SOA
$HISTORY$
==================================================================================================*/
#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_UNORDERED_MAP_HXX_INCLUDED
#define TEAMCENTER_SOA_INTERNAL_COMMON_UNORDERED_MAP_HXX_INCLUDED

#include <teamcenter/soa/internal/common/Tr1Hashtable.hxx>
#include <teamcenter/soa/common/SoaStlAllocator.h>


namespace Teamcenter
{
    //Fix for warning C4503: decorated name length exceeded, name was truncated.
    //This warning showsup in many places so we need to fix this by reducing the namespace length.
    //This is a special case senario (Because it is a template class and nexting is possible) 
    //where SOA name space convention is not followed. Reducing the namespace length to avoid issues.
    //namespace Soa
    //{
    //     namespace Internal
    //     {
    //        namespace Common
    //        {
        //  <BJS> 16-Nov-2004
        //  Traits class to adapt _Hashtable to be a map.
        template <class Key, class T, class Hash, class Pred, class Alloc, int ALLOW_DUPLICATES>
        class _MapTraits
        {
        public:
            typedef Key                              key_type;
            typedef typename std::pair<const Key, T> value_type;
            typedef Hash                             hasher;
            typedef Pred                             key_equal;
            typedef Alloc                            allocator_type;
            enum    
            { 
                _ALLOW_DUPLICATES = ALLOW_DUPLICATES
            };

            _MapTraits(const hasher &h, const key_equal &ke, const allocator_type &a)
                : m_hasher(h), m_equals(ke), m_allocator(a)
            {
            }

            _MapTraits(const _MapTraits &other)
                : m_hasher(other.m_hasher), m_equals(other.m_equals), m_allocator(other.m_allocator)
            {
            }

        protected:
            static const key_type& _get_key(const value_type& v)
            {    // extract key from element value
                return v.first;
            }

            hasher          m_hasher;
            key_equal       m_equals;
            allocator_type  m_allocator;
        /*lint --e(1509) */ // base destructor not virtual
        /*lint --e(1712) */ // no default constructor
        };

        /*  <BJS> 09-Oct-01
            The template takes 5 arguments:
            Key - the key type
            T - the value type
            Hash - the hashing functor
            Pred - the equality functor
            Alloc - allocator
        */
        /// Template class for unordered maps implemented as hashtables.
        template <class Key, 
                class T, 
                class Hash = hash<Key>, 
                class Pred = typename std::equal_to<Key>, 
                class Alloc = typename std::allocator<std::pair<const Key, T> > >
        class unordered_map : 
            public _Hashtable<_MapTraits<Key, T, Hash, Pred, Alloc, 0> >
        {
        public:
            typedef _Hashtable<_MapTraits<Key, T, Hash, Pred, Alloc, 0> >           //lint !e1942
                                                            _Base;
            typedef T                                        mapped_type;
            /*  <BJS> 17-Nov-04
                HP seems to need these typedefs all redefined to be in scope again...
            */
#ifndef _lint // but qaz does not like these so comment then out for it.
            typedef typename _Base::key_type                 key_type;
            typedef typename _Base::value_type               value_type;
            typedef typename _Base::hasher                   hasher;
            typedef typename _Base::key_equal                key_equal;
            typedef typename _Base::allocator_type           allocator_type;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename _Base::iterator                 iterator;
            typedef typename _Base::const_iterator           const_iterator;
#endif
            explicit unordered_map(size_type n = 2,                         //lint !e1942
                                const hasher& hf = hasher(),                //lint !e1942
                                const key_equal &eql = key_equal(),         //lint !e1942
                                const allocator_type& a = allocator_type()) //lint !e1942
                : _Base(n, hf, eql, a)
            {
            }
            unordered_map(const unordered_map& other)
                : _Base(other)
            {
            }
            template<class InputIterator>
            unordered_map(InputIterator first, InputIterator last,
                          size_type n = 2,                                  //lint !e1942
                          const hasher& hf = hasher(),                      //lint !e1942
                          const key_equal &eql = key_equal(),               //lint !e1942
                          const allocator_type& a = allocator_type())       //lint !e1942
                : _Base(n, hf, eql, a)
            {
                for (; first != last; ++first)
                    insert(*first);
            }
            mapped_type& operator [](const key_type &k)                     //lint !e1942
            {
                iterator it = insert(value_type(k, mapped_type())).first;
                return it->second;
            }
        }; //lint !e1509 // base destructor not virtual

        /*  <BJS> 19-May-2008
            The template takes 5 arguments:
            Key - the key type
            T - the value type
            Hash - the hashing functor
            Pred - the equality functor
            Alloc - allocator
        */
        /// Template class for unordered multimaps implemented as hashtables.
        template <class Key, 
                class T, 
                class Hash = hash<Key>, 
                class Pred = typename std::equal_to<Key>, 
                class Alloc = typename std::allocator<std::pair<const Key, T> > >
        class unordered_multimap : 
            public _Hashtable<_MapTraits<Key, T, Hash, Pred, Alloc, 1> >
        {
        public:
            typedef _Hashtable<_MapTraits<Key, T, Hash, Pred, Alloc, 1> >     //lint !e1942      
                                                            _Base;            //lint !e1942
            typedef T                                        mapped_type;
            /*  <BJS> 17-Nov-04
                HP seems to need these typedefs all redefined to be in scope again...
            */
#ifndef _lint // but qaz does not like these so comment then out for it.
            typedef typename _Base::key_type                 key_type;
            typedef typename _Base::value_type               value_type;
            typedef typename _Base::hasher                   hasher;
            typedef typename _Base::key_equal                key_equal;
            typedef typename _Base::allocator_type           allocator_type;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename _Base::iterator                 iterator;
            typedef typename _Base::const_iterator           const_iterator;
#endif
            explicit unordered_multimap(size_type n = 2,                        //lint !e1942
                                const hasher& hf = hasher(),                    //lint !e1942
                                const key_equal &eql = key_equal(),             //lint !e1942
                                const allocator_type& a = allocator_type())     //lint !e1942
                : _Base(n, hf, eql, a)
            {
            }
            unordered_multimap(const unordered_multimap& other)
                : _Base(other)
            {
            }
            template<class InputIterator>
            unordered_multimap(InputIterator first, InputIterator last,
                          size_type n = 2,                                  //lint !e1942
                          const hasher& hf = hasher(),                      //lint !e1942
                          const key_equal &eql = key_equal(),               //lint !e1942
                          const allocator_type& a = allocator_type())       //lint !e1942
                : _Base(n, hf, eql, a)
            {
                for (; first != last; ++first)
                    insert(*first);
            }

            //  <BJS> 21-May-2008
            //  multimap has different return types for insert so we override and hide
            //  the base class version - but that means we must define all flavours of insert
            //  again.
            iterator insert(const value_type &v)            //lint !e1942
            { //lint !e1511 // intentional hiding
                return _Base::insert(v).first;
            }

            iterator insert(const_iterator /*hint*/, const value_type &v)   //lint !e1942
            {
                return insert(v);
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                for (; first != last; ++first)
                    insert(*first);
            }
        }; //lint !e1509 // base destructor not virtual

//}}}}
}

#endif
