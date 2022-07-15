/*==================================================================================================

                             Copyright (c) 2000-2004 UGS Corp.
                             Unpublished - All rights reserved

====================================================================================================
File description:
    <BJS> 05-Sep-01
    An STL style map implemented using as hashtable.

    <BJS> 01-Apr-02
    I started writing this myself in a style that I thought
    matched STL. I was making this more complete and looking
    on the web and then found Matt Austern's proposal for
    adding hash maps and sets to STL at
        http://std.dkuug.dk/jtc1/sc22/wg21/docs/papers/2001/n1326.html
    which was remarkably similar to what I was doing.
    Having found this I have actually made this implementation
    even more similar.

    <BJS> 16-Nov-2004
    I have mutated this into a base class for the TR1 unordered
    containers. See:
        http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1687.pdf
    so we can implement a version of unordered_map and so on.

====================================================================================================
   Date      Name                    Description of Change

09-Oct-2001  Bernard Solomon         STL style hash map
13-Feb-2002  bernard                 MSVC doesn't seem to like nested class called entry, friend doesn't work so make some stuff public
18-Feb-2002  Bernard Solomon         Fix for compilation on SGI
13-Mar-2002  Bernard Solomon         Hack round AIX compile problem
08-Apr-2002  Bernard Solomon         Make it match a STL proposal more accurately - but no allocators so far
16-Sep-2002  Aaron Ruckman           Test for VC7.0
14-Apr-2004  Brendan Brolly          NX3 rebase changes. HP is now compiled as AA and so no longer a special case
16-Nov-2004  Bernie Solomon          Adapted my TCEng code for use in NX and to implement TR1 more closely.
17-Nov-2004  Bernie Solomon          Tweak to get to compile on every Unix platform
23-Nov-2004  Bernie Solomon          Remove a few of the qaz warnings but there are still more
24-Nov-2004  Bernie Solomon          Fixes after qaz changes and more qaz fixes
07-Dec-2004  Bernie Solomon          Fix HP compile errors
25-Jan-2005  Bernie Solomon          Missed a couple of cases where _get_key was needed
09-Feb-2005  Bernie Solomon          Add some QAZ annotation
24-Mar-2005  Bernie Solomon          HP doesn't seem to cope with friend nested classes the same way
25-Mar-2005  Bernie Solomon          More changes to remove warnings from GCC yet let HP accept it
03-May-2005  Bernie Solomon          Fix for MS VC8 compile 
05-Dec-2005  Bernie Solomon          Fix use of allocators, add a wee bit of doc
10-Feb-2006  Bernie Solomon          More qaz tweaks
15-Feb-2006  Bernie Solomon          Fix last change so Sun compile works
23-Oct-2006  Jack Marr               NX5 Mac port - g++ 4.0 handles friend access hpux
10-Aug-2007  Bernie Solomon          Suppress lint warning about erase argument
23-Aug-2007  Bernie Solomon          PR#5806822: make sure destructor doesn't leak memory
11-Dec-2007  Bernie Solomon          Cope if constructed as a zero size map
19-May-2008  Bernie Solomon          Enable multi versions of unordered_map/set
04-Jun-2008  Bernie Solomon          Fix a couple of qaz warnings
13-Mar-2009  D.Silkworth             Adapted the NX implementation for use in Teamcenter SOA
$HISTORY$
==================================================================================================*/
#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_TR1_HASHTABLE_HXX_INCLUDED
#define TEAMCENTER_SOA_INTERNAL_COMMON_TR1_HASHTABLE_HXX_INCLUDED

#include <utility>
#include <functional>
#include <iterator>
#include <vector>

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
        /*  <BJS> 01-Apr-02
            The general style of hash function functor to use. In practice
            we only have specializations of this implemented - these follow.
            <BJS> 16-Nov-2004
            According to TR1 these should be in functional but given that is
            a standard header I am putting them here so they are available
            when using any unordered container.
        */

        template <class T>
        struct hash : public std::unary_function<T, size_t>
        {
            ::size_t operator()(T val) const;
        }; //lint !e1509 // base class destructor not virtual

        template<>
        struct hash<bool>
        {
            size_t operator()(bool val) const
            {
                return (int)val;
            }
        };

        template<>
        struct hash<int>
        {
            size_t operator()(int val) const
            {
                return (size_t)(val * 2654435761);
            }
        };

        template<>
        struct hash<unsigned int>
        {
            size_t operator()(unsigned int val) const
            {
                return (size_t)(val * 2654435761);
            }
        };

        template<class T>
        struct hash<T *>
        {
            size_t operator()(T *val) const
            {
                return (size_t)(void *)val * 2654435761;
            }
        };

        template<>
        struct hash<char *>
        {
            size_t operator()(char *val) const
            {
                size_t h = 0;
                for (; *val != '\0'; ++val)
                    h = h * 27 + *val;
                return h;
            }
        };

        //  <BJS> 16-Nov-2004
        //  This is not a TR1 specialization. But is useful.
        //  Should we move it.
        template<>
        struct hash<const char *>
        {
            size_t operator()(const char *val) const
            {
                size_t h = 0;
                for (; *val != '\0'; ++val)
                    h = h * 27 + *val;
                return h;
            }
        };

    //  <DAS> 14-Mar-2009
    //  Specialization of hash so that we can use std::string keys
        template<>
        struct hash<std::string>
        {
            size_t operator()(const std::string &val) const
            {
                return Teamcenter::hash<const char *>()(val.c_str());
            }
        };

        template <class Traits>
        class _Hashtable : public Traits
        {
        public:
            typedef typename Traits::key_type                key_type; //lint !e1516  // hides base class (which is the same)
            typedef typename Traits::value_type              value_type; //lint !e1516 
            typedef typename Traits::hasher                  hasher; //lint !e1516 
            typedef typename Traits::key_equal               key_equal; //lint !e1516 
            typedef typename Traits::allocator_type          allocator_type; //lint !e1516 
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
        private:
            class map_entry
            {
                friend class _Hashtable<Traits>;
                friend class hashtable_iterator;
                friend class const_hashtable_iterator;
                friend class local_iterator;
                friend class const_local_iterator;
            public:
                map_entry() : link(NULL), m_value()
                {
                }
                map_entry(const value_type &v, map_entry *l) : link(l), m_value(v)
                {
                }
                value_type &value()
                {
                    return m_value;
                }
#if !defined(__hpux) && !(defined(__GNUG__) && __GNUG__ == 4) // these don't take the friend declarations like other compilers
            protected:
#endif
                map_entry *link;
                value_type m_value;
            };
#ifdef __sun
            typedef allocator_type table_allocator; // not really retyped on Sun
            typedef _RW_STD::allocator_interface<allocator_type, map_entry>    entry_allocator;
            typedef std::vector<map_entry *, allocator_type> entry_table;
#else
            typedef typename allocator_type::template rebind<map_entry *>::other table_allocator;
            typedef typename allocator_type::template rebind<map_entry>::other entry_allocator;
            typedef typename ::std::vector<map_entry *, table_allocator> entry_table;
#endif
            typedef typename entry_table::iterator table_iterator;
            typedef typename entry_table::const_iterator const_table_iterator;

        public:
            class hashtable_iterator;
            friend class hashtable_iterator;
            class const_hashtable_iterator;
            friend class const_hashtable_iterator;

            /*  <BJS> 16-Nov-04
                Sun got confused when the nested class was directly called
                iterator hence the names and typedef.
            */

            typedef hashtable_iterator iterator;
            typedef const_hashtable_iterator const_iterator;

            class local_iterator;
            friend class local_iterator;
            class const_local_iterator;
            friend class const_local_iterator;

            class local_iterator : public  ::std::iterator< ::std::forward_iterator_tag, value_type>
            {
                friend class const_local_iterator;
            public:
                local_iterator() : m_entry(NULL)
                {
                }
                explicit local_iterator( map_entry *he) : m_entry(he)   //lint !e1942
                {
                }
                local_iterator(const local_iterator &other) : m_entry(other.m_entry)
                {
                }
                bool operator == (const local_iterator &other) const
                {
                    return m_entry == other.m_entry;
                }
                bool operator != (const local_iterator &other) const
                {
                    return ! operator == (other);
                }
#ifndef __hpux
                typename local_iterator::value_type & operator * ()
                {
                    return m_entry->value();
                }
                typename local_iterator::value_type * operator -> ()
                {
                    return & operator * ();
                }
#else
                value_type & operator * ()
                {
                    return m_entry->value();
                }
                value_type * operator -> ()
                {
                    return & operator * ();
                }
#endif
                local_iterator& operator++ ()
                {
                    advance();
                    return *this;
                }
                local_iterator operator++ (int)
                {
                    local_iterator tmp = *this;
                    advance();
                    return tmp;
                }
            private:
                void advance()
                {
                    m_entry = m_entry->link;
                }

                map_entry *m_entry; //lint !e1942
            /*lint --e(1509) */ // base class has non virtual destructor
            };

            class const_local_iterator : public  ::std::iterator< ::std::forward_iterator_tag, value_type>
            {
            public:
                const_local_iterator() : m_entry(NULL)
                {
                }
                explicit const_local_iterator(const map_entry *he) : m_entry(he) //lint !e1942
                {
                }
                const_local_iterator(const const_local_iterator &other) : m_entry(other.m_entry)
                {
                }
                const_local_iterator(const local_iterator &other) //lint !e1942
                    /*lint --e(1931) */ // ok to use as conversion
                    : m_entry(other.m_entry)
                {
                }
                bool operator == (const local_iterator &other) const //lint !e1942
                {
                    return m_entry == other.m_entry;
                }
                bool operator != (const local_iterator &other) const //lint !e1942
                {
                    return ! operator == (other);
                }
#ifndef __hpux
                const typename const_local_iterator::value_type & operator * () const
                {
                    return m_entry->value();
                }
                const typename const_local_iterator::value_type * operator -> () const
                {
                    return & operator * ();
                }
#else
                const value_type & operator * () const
                {
                    return m_entry->value();
                }
                const value_type * operator -> () const
                {
                    return & operator * ();
                }
#endif
                const_local_iterator& operator++ ()
                {
                    advance();
                    return *this;
                }
                const_local_iterator operator++ (int)
                {
                    const_local_iterator tmp = *this;
                    advance();
                    return tmp;
                }
            private:
                void advance()
                {
                    m_entry = m_entry->link;
                }

                const map_entry *m_entry; //lint !e1942
            /*lint --e(1509) */ // base class has non virtual destructor
            };

            class const_hashtable_iterator : public ::std::iterator< ::std::forward_iterator_tag, value_type>
            {
                friend class _Hashtable<Traits>;
                friend class hashtable_iterator;
            public:
                /*  <BJS> 17-Nov-04
                    IBM would not take the second constructor with two default arguments
                    the first of which was initialized to const_table_iterator(), it
                    does however take an explicit default constructor and the second
                    constructor only having one default argument.
                */
                const_hashtable_iterator()
                    : m_table_it(), m_entry(NULL)
                {
                }
                explicit const_hashtable_iterator(const_table_iterator table_it, map_entry * entry = NULL) //lint !e1942
                    : m_table_it(table_it), m_entry(entry)
                {
                }
                const_hashtable_iterator(const const_hashtable_iterator &other)
                    : m_table_it(other.m_table_it), m_entry(other.m_entry)
                {
                }
                const_hashtable_iterator(const hashtable_iterator &other) /*lint --e(1931) */ // ok to use as conversion
                    : m_table_it(other.m_table_it), m_entry(other.m_entry)
                {
                }
                bool operator == (const const_hashtable_iterator &other) const
                {
                    return m_entry == other.m_entry;
                }
                bool operator != (const const_hashtable_iterator &other) const
                {
                    return ! operator == (other);
                }
#ifndef __hpux
                const typename const_hashtable_iterator::value_type & operator * () const
                {
                    return m_entry->value();
                }
                const typename const_hashtable_iterator::value_type * operator -> () const
                {
                    return & operator * ();
                }
#else
                const value_type & operator * () const
                {
                    return m_entry->value();
                }
                const value_type * operator -> () const
                {
                    return & operator * ();
                }
#endif
                const_hashtable_iterator& operator++ ()
                {
                    advance();
                    return *this;
                }
                const_hashtable_iterator operator++ (int)
                {
                    const_iterator tmp = *this;
                    advance();
                    return tmp;
                }
            protected:
                void advance()
                {
                    m_entry = m_entry->link;
                    if (m_entry == NULL)
                    {
                        for (++m_table_it; ; ++m_table_it)
                            if (*m_table_it != NULL)
                                break;
                        m_entry = *m_table_it;
                    }
                }
            protected:
                const_table_iterator m_table_it;  //lint !e1942
                map_entry *m_entry;               //lint !e1942
            }; //lint !e1509 !e1510 // not virtual destructor & base class has no destructor

            class hashtable_iterator : public ::std::iterator< ::std::forward_iterator_tag, value_type>
            {
                friend class const_hashtable_iterator;
            public:
                hashtable_iterator()
                    : m_table_it(), m_entry(NULL)
                {
                }
                explicit hashtable_iterator(table_iterator table_it, map_entry * entry = NULL) //lint !e1942
                    : m_table_it(table_it), m_entry(entry)
                {
                }
                hashtable_iterator(const hashtable_iterator &other)
                    : m_table_it(other.m_table_it), m_entry(other.m_entry)
                {
                }
                bool operator == (const hashtable_iterator &other) const
                {
                    return m_entry == other.m_entry;
                }
                bool operator != (const hashtable_iterator &other) const
                {
                    return ! operator == (other);
                }
#ifndef __hpux
                typename hashtable_iterator::value_type & operator * ()
                {
                    return m_entry->value();
                }
                typename hashtable_iterator::value_type * operator -> ()
                {
                    return & operator * ();
                }
#else
                value_type & operator * ()
                {
                    return m_entry->value();
                }
                value_type * operator -> ()
                {
                    return & operator * ();
                }
#endif
                hashtable_iterator& operator++ ()
                {
                    advance();
                    return *this;
                }
                hashtable_iterator operator++ (int)
                {
                    hashtable_iterator tmp = *this;
                    advance();
                    return tmp;
                }
            protected:
                void advance()
                {
                    m_entry = m_entry->link;
                    if (m_entry == NULL)
                    {
                        for (++m_table_it; ; ++m_table_it)
                            if (*m_table_it != NULL)
                                break;
                        m_entry = *m_table_it;
                    }
                }
            protected:
                table_iterator m_table_it;   //lint !e1942
                map_entry *m_entry;          //lint !e1942
            /*lint --e(1509) */ // base class has non virtual destructor
            }; //lint !e1510 // base class has no destructor

            explicit _Hashtable(size_type n = 2, 
                                const hasher& hf = hasher(), 
                                const key_equal &eql = key_equal(),
                                const allocator_type& a = allocator_type())
                : Traits(hf, eql, a), m_table(table_allocator(a)), m_size(0), m_next_resize_at(0), m_end(), m_max_load_factor(1.0)
            {
                _init(n);
            }
            _Hashtable(const _Hashtable& other)
                : Traits(other), m_table(other.m_table.get_allocator()), m_size(0), m_next_resize_at(0), m_end(), m_max_load_factor(1.0)
            {
                _init((size_type)((2.0f * other.size()) / other.max_load_factor()));
                max_load_factor(other.max_load_factor());
                insert(other.begin(), other.end());
            }
            ~_Hashtable()
                /*lint --e(1509) */ // base class has non virtual destructor
            {
                _clear();
            }
            _Hashtable& operator = (const _Hashtable& other)
            {
                if (this != &other)
                {
                    clear();
                    /*  <BJS> 17-Nov-04
                        For some reason HP needs the this-> to
                        parse this correctly.
                    */
                    this->m_equals = other.m_equals;
                    this->m_hasher = other.m_hasher;
                    max_load_factor(other.max_load_factor());
                    insert(other.begin(), other.end());
                }
                return *this;
            }
            typename ::std::pair<iterator, bool> insert(const value_type &v)
            {
                const key_type &k = _get_key(v);         //lint !e1942
                size_type index = bucket(k);
                map_entry *insert_after = NULL;
                for (map_entry *e = m_table[index]; e != NULL; e = e->link)
                    if (m_equals(_get_key(e->m_value), k))   //lint !e1942
                    {
                        if (Traits::_ALLOW_DUPLICATES) //lint !e774 // constant value // this one directive seems to silence all these warnings
                        {
                            insert_after = e;
                            break;
                        }
                        else
                        {
                            return ::std::pair<iterator, bool>(iterator(m_table.begin() + index, e), false);
                        }
                    }
                if (m_size >= m_next_resize_at)
                {
                    rehash(bucket_count() * 2);
                    index = bucket(k);
                }
                entry_allocator a(get_allocator());
                map_entry *ptr = a.allocate(1);
                if (insert_after == NULL)
                {
                    m_table[index] = new (ptr) map_entry(v, m_table[index]);
                }
                else
                {
                    insert_after->link = new (ptr) map_entry(v, insert_after->link);
                }
                ++m_size;
                return ::std::pair<iterator, bool>(iterator(m_table.begin() + index, m_table[index]), true);
            }
            iterator insert(const_iterator /*hint*/, const value_type &v)
            {
                return insert(v).first;
            }
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                for (; first != last; ++first)
                    insert(*first);
            }
            iterator find(const key_type &k)
            {
                size_type index = bucket(k);
                for (map_entry *e = m_table[index]; e != NULL; e = e->link)
                    if (m_equals(_get_key(e->m_value), k))                       //lint !e1942
                        return iterator(m_table.begin() + index, e);
                return end();
            }
            ::std::pair<iterator, iterator> equal_range(const key_type &k)
            {
                size_type index = bucket(k);
                for (map_entry *e = m_table[index]; e != NULL; e = e->link)
                {
                    if (m_equals(_get_key(e->m_value), k))
                    {
                        iterator first = iterator(m_table.begin() + index, e);
                        if (Traits::_ALLOW_DUPLICATES)
                        {
                            iterator last = first;
                            ++last;
                            while (m_equals(_get_key(*last), k))
                                ++last;
                            return std::make_pair(first, last);
                        }
                        else
                        {
                            return std::make_pair(first, ++first);
                        }
                    }
                }
                return std::make_pair(end(), end());
            }
            const_iterator find(const key_type &k) const
            {
                size_type index = bucket(k);
                for (map_entry *e = m_table[index]; e != NULL; e = e->link)
                    if (m_equals(_get_key(e->m_value), k))
                        return const_iterator(m_table.begin() + index, e);
                return end();
            }
            ::std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
            {
                size_type index = bucket(k);
                for (map_entry *e = m_table[index]; e != NULL; e = e->link)
                {
                    if (m_equals(_get_key(e->m_value), k))
                    {
                        const_iterator first = const_iterator(m_table.begin() + index, e);
                        if (Traits::_ALLOW_DUPLICATES)
                        {
                            const_iterator last = first;
                            ++last;
                            while (m_equals(_get_key(*last), k))
                                ++last;
                            return std::make_pair(first, last);
                        }
                        else
                        {
                            return std::make_pair(first, ++first);
                        }
                    }
                }
                return std::make_pair(end(), end());
            }
            size_type count(const key_type& k) const
            {
                if (Traits::_ALLOW_DUPLICATES)
                {
                    std::pair<const_iterator, const_iterator> range = equal_range(k);
                    const_iterator it = range.first;
                    size_type c = 0;
                    while (it != range.second)
                    {
                        ++it;
                        ++c;
                    }
                    return c;
                }
                else
                {
                    return find(k) != end();
                }
            }
            void clear()
            {
                _clear();
                //  <BJS> 23-Aug-2007
                //  This re init ensures end is set up correctly.
                _init(2);
            }
            void erase(const_iterator it)
            {
                for (map_entry *prev = NULL, *e = *it.m_table_it; e != NULL; prev = e, e = e->link)
                    if (e == it.m_entry)
                    {
                        if (prev == NULL)
                            m_table[it.m_table_it - m_table.begin()]= e->link;
                        else
                            prev->link = e->link;
                        entry_allocator a(get_allocator());
                        a.destroy(e);
                        a.deallocate(e, 1);
                        m_size--;
                        break;
                    }
            } //lint !e1746
            void erase(const_iterator first, const_iterator last)
            {
                while (first != last)
                {
                    const_iterator next = first;
                    ++next;
                    erase(first);
                    first = next;
                }
            }
            size_type erase(const key_type &k)
            {
                size_type count = 0;
                do
                {
                    iterator it = find(k);
                    if (it == end())
                        break;
                    erase(it);
                    ++count;
                } while (Traits::_ALLOW_DUPLICATES);
                return count;
            }
            hasher hash_function() const
            {
                return this->m_hasher; // HP needs this
            }
            void swap(_Hashtable &other)
            {
                if (get_allocator() == other.get_allocator())
                {
                    std::swap(this->m_equals, other.m_equals); // HP needs this
                    std::swap(this->m_hasher, other.m_hasher); 
                    m_table.swap(other);
                    std::swap(m_size, other.m_size);
                    std::swap(m_next_resize_at, other.m_next_resize_at);
                    std::swap(m_end, other.m_end);
                    std::swap(m_max_load_factor, other.m_max_load_factor);
                }
                else
                {
                    _Hashtable tmp = *this;
                    *this = other;
                    other = tmp;
                }
            }
            key_equal key_eq() const
            {
                return this->m_equals; // HP needs this
            }
            allocator_type get_allocator() const
            {
                return this->m_allocator; // HP again needs the explicit this
            }
            bool empty() const
            {
                return size() == 0;
            }
            size_type size() const
            {
                return m_size;
            }
            iterator begin()
            {
                for (table_iterator ei = m_table.begin(); ei != m_table.end(); ++ei)
                    if (*ei != NULL)
                        return iterator(ei, *ei);
                return end();
            }
            const_iterator begin() const
            {
                for (const_table_iterator ei = m_table.begin(); ei != m_table.end(); ++ei)
                    if (*ei != NULL)
                        return const_iterator(ei, *ei);
                return end();
            }
            iterator end()
            {
                return m_end;
            }  //lint !e1762 the compiler does not like this method to be const
            const_iterator end() const
            {
                return m_end;
            }
            local_iterator begin(size_type n)
            {
                return local_iterator(m_table[n]);
            }
            const_local_iterator begin(size_type n) const
            {
                return const_local_iterator(m_table[n]);
            }
            local_iterator end(size_type)
            {
                return local_iterator(0);
            }
            const_local_iterator end(size_type) const
            {
                return const_local_iterator(0);
            }
            size_type bucket_count() const
            {
                return m_table.size() - 1;
            }
            size_type bucket(const key_type& k) const
            {
                return m_hasher(k) % bucket_count();         //lint !e1942
            }
            void rehash(size_type m)
            {
                size_type old_size = m_table.size();
                size_type n = 1;
                while (n < m)
                    n <<= 1;
                size_type new_size = n + 1;
                m_next_resize_at = (size_type)(m_max_load_factor * n);
                entry_table tmp_table(new_size, (map_entry *)NULL); 
                m_table.swap(tmp_table);
                m_table[new_size - 1] = tmp_table[old_size - 1];
                for (size_type j = 0; j < old_size - 1; ++j)
                    for (map_entry *next, *e = tmp_table[j]; e != NULL; e = next)
                    {
                        next = e->link;
                        ::size_t index = bucket(_get_key(e->m_value));   //lint !e1942
                        e->link = m_table[index];
                        m_table[index] = e;
                    }
                _set_end();
            }
            float load_factor() const
            {
                return (float)size() / bucket_count();
            }
            float max_load_factor() const
            {
                return m_max_load_factor;
            }
            void max_load_factor(float f)
            {
                m_max_load_factor = f;
                m_next_resize_at = (size_type)(m_max_load_factor * bucket_count());
            }
        private:
            void _clear()
            {
                entry_allocator a(get_allocator());
                for (table_iterator it = m_table.begin(); it != m_table.end(); ++it)
                {
                    for (map_entry *next, *e = *it; e != NULL; e = next)
                    {
                        next = e->link;
                        a.destroy(e);
                        a.deallocate(e, 1);
                    }
                }
                m_table.clear();
                m_size = 0;
            }
            void _init(size_type n)
            {
                if (n == 0)
                    n = 1;
                m_next_resize_at = (size_type) ( m_max_load_factor * n );
                m_table.assign(n + 1, NULL);
                entry_allocator a(get_allocator());
                m_table[n] = a.allocate(1);
                new (m_table[n]) map_entry();
                _set_end();
            }
            void _set_end()
            {
                m_end = iterator(m_table.begin() + bucket_count(), m_table.back());
            }
        private:
            entry_table     m_table;
            size_type       m_size;
            size_type       m_next_resize_at;
            iterator        m_end;
            float           m_max_load_factor;
        /*lint --e(1509) */ // base destructor not virtual
        };
//}}}}
}
#endif
