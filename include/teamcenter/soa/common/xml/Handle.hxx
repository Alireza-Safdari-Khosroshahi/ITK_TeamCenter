/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */

#ifndef TEAMCENTER_SOA_COMMON_XML_HANDLE_HXX
#define TEAMCENTER_SOA_COMMON_XML_HANDLE_HXX

#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Xml
            {

class  TCSOACOMMON_API TryingToCreateNullHandle
{};

                    
template< class T > class  Handle
{
public:
    Handle(){}

    Handle( const Handle& other )
         : m_object( other.m_object )
    {
         init();
    }

    virtual ~Handle()
    {
        if ( m_object != 0 )
            m_object->removeRef();
    }


    Handle& operator = ( const Handle& other )
    {
        if ( this == &other )
            return *this;

        if ( m_object != other.m_object )
        {
            m_object->removeRef();
            m_object = other.m_object;
            init();
        }

        return *this;
    }

    void ensureUnShared()
    {
        if ( m_object->askRefCount() > 1 )
        {
            m_object->removeRef();
            m_object = static_cast<T*>( m_object->clone() );
            init();
        }
    }

protected:
    explicit Handle( T* base )
        : m_object( base )
    {
        if ( m_object == 0 )
        {
           throw TryingToCreateNullHandle();
        }
        init();
    }

    T& getHandleObject() const { return *m_object; }

private:
    void init()
    {
        m_object->addRef();
    }

    T* m_object;
};

            }
        }
    }
}







#include <teamcenter/soa/common/SoaCommonUndef.h>



#endif
