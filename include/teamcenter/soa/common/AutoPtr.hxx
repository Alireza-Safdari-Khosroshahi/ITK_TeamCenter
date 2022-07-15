/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef TEAMCENTER_SOA_COMMON_AUTOPTR_HXX
#define TEAMCENTER_SOA_COMMON_AUTOPTR_HXX


#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {

/**
 * Holds a pointer to classes implementing reference counting (ModelObject)
 * and behaves as a smart pointer.  Upon assignment, the base obect is referenced,
 * and upon destruction, the object is unreferenced.  All methods on this class
 * are inline.
 **/
template <class T> class  AutoPtr
{
public:

    /**
     * Default constructor, assigns the underlying pointer to NULL;
     */
    AutoPtr(): instancePtr(0)
    {
    }



    /**
     * Construct an instance of the AutoPtr while incrementing  the reference count
     * on the underlying pointer.
     *
     * @param tp  A Pointer of type T
     *
     */
    AutoPtr(T* tp ):            //lint !e1931 allow for AutoPtr<X> x = new X();
        instancePtr(tp)
    {
        if (instancePtr)
            instancePtr->ref();
    }

    /**
     * Construct an instance of the AutoPtr, while incrementing the reference count
     * on the underlying pointer.
     *
     * @param ap   The AutoPtr instance to copy.
     */
    AutoPtr(const AutoPtr& ap):
        instancePtr(ap.instancePtr)         //lint !e1554 OK to copy the pointer, we are keeping track of how many times it is used
    {
        if (instancePtr)
            instancePtr->ref();
    }

    /**
     * Construct an AutoPtr with an implicit cast while incrementing  the reference count
     * on the underlying pointer.
     *
     * @param otherPtr   An AutoPtr of type Other
     */
    template <class Other> AutoPtr(const AutoPtr<Other>& otherPtr):   //lint !e1931 Can't put a explicit on this constructor
        instancePtr(const_cast<Other*>(otherPtr.getPtr()))
    {
        if (instancePtr)
            instancePtr->ref();
    }

    /**
     * Delete the instance of the AutoPtr, while decrementing the reference count
     * of the underlying pointer.
     */
    ~AutoPtr()
    {        
        if (instancePtr)
            instancePtr->unref();
        instancePtr = NULL;
    }




    /**
     * Assign a raw pointer to the AutoPtr.
     *<code>
     * AutoPtr<ModelObject> someObj;
     * ModelObject *obj;
     * someObj = (ModelObject*)NULL;
     * someObj = obj;
     *</code>
     *
     * @param tp  pointer of type T
     *
     */
    AutoPtr& operator = (T* tp)
    {
        if (instancePtr != tp)
        {
            if (instancePtr)
                instancePtr->unref();
            instancePtr = tp;
            if (instancePtr)
                instancePtr->ref();
        }
        return *this;
    }



    /**
     * Assign another AutoPtr to this AutoPtr.
     *<code>
     * AutoPtr<ModelObject> someObj;
     * AutoPtr<ModelObject> thatObj;
     * someObj = thatObj;
     *</code>
     *
     * @param ap  right hand side
     *
     */
    AutoPtr& operator = (const AutoPtr& ap)
    {
        if (&ap != this)
        {
            if (instancePtr) instancePtr->unref();
            instancePtr = ap.instancePtr;            //lint !e1555 OK to copy the pointer, we are keeping track of how many times it is used
            if (instancePtr) instancePtr->ref();
        }
        return *this;
    }

    /**
     * Assign another AutoPtr of type Other to this AutoPtr.
     *<code>
     * AutoPtr<ModelObject> someObj;
     * AutoPtr<User>        thatObj;
     * someObj = thatObj;
     *</code>
     *
     * @param otherPtr  right hand side
     *
     */
    template <class Other>
    AutoPtr& operator = (const AutoPtr<Other>& otherPtr)
    {
        if (otherPtr.getPtr() != instancePtr)
        {
            if (instancePtr) instancePtr->unref();
            instancePtr = const_cast<Other*>(otherPtr.getPtr());
            if (instancePtr) instancePtr->ref();
        }
        return *this;
    }

    /**
     * Swap the contents of this and ap, without a ref/unref
     *
     * @param ap   AutoPtr to swap.
     */
    void swap(AutoPtr& ap)
    {
        if (instancePtr != ap.instancePtr)
        {
            register T* t = ap.instancePtr;
            ap.setPtr(instancePtr);
            setPtr(t);
        }
    }


    /**
     * Cast the AutoPtr using dynamic_cast.
     *<code>
     * AutoPtr<ModelObject> someObj = AutoPtr(new User());
     * AutoPtr<User>        thatObj = someObject.cast<User>();
     * someObj = thatObj;
     *</code>
     * @return Returns an AutoPtr containing NULL if the cast fails.
     */
    template <class Other>
    AutoPtr<Other> dyn_cast() const
    {
        Other* pOther = dynamic_cast<Other*>(instancePtr);
        return AutoPtr<Other>(pOther);
    }

    /**
     * Cast the AutoPtr using static_cast.
     *<code>
     * AutoPtr<ModelObject> someObj = AutoPtr(new User());
     * AutoPtr<User>        thatObj = someObject.unsafeCast<User>();
     * someObj = thatObj;
     *</code>
     * @return Returns an AutoPtr containing NULL if the cast fails.
     */
    template <class Other>
    AutoPtr<Other> cast() const
    {
        Other* pOther = static_cast<Other*>(instancePtr);
        return AutoPtr<Other>(pOther);
    }

          T* operator ->  ()                         { return  instancePtr;}
    const T* operator ->  () const                   { return  instancePtr;}
          T& operator *   ()                         { return *instancePtr;}
    const T& operator *   () const                   { return *instancePtr;}
             operator bool() const                   { return  instancePtr != NULL; } //lint !e1930 if (modelObj) 
        bool operator !   () const                   { return  instancePtr == NULL; }            // if(!modelObj)
#ifdef WNT
        // The Unix/Linux ANSI C compilers do not like NULL to be used as int.
        // So client code compiled on Windows and and Unix will need to use modelObject.isNull
        bool operator ==  (int null) const           { return  ((null == 0)? instancePtr == NULL: false);}  // if(modelObj == NULL)
        bool operator !=  (int null) const           { return  ((null == 0)? instancePtr != NULL: true); }  // if(modelObj != NULL)
#endif
        bool operator ==  (const AutoPtr& ap) const  { return  instancePtr == ap.instancePtr; } // if( modelObj1 == modelObj2 )
        bool operator !=  (const AutoPtr& ap) const  { return  instancePtr != ap.instancePtr; } // if( modelObj1 != modelObj2 )


        bool operator <  (const AutoPtr& ap) const  { return  instancePtr  < ap.instancePtr; } // Used for std::map keys



    /**
     * Return the underlying pointer.
     *
     * @return The pointer.
     */
    T* getPtr()
    {
        return instancePtr;
    }

    /**
     * Return the underlying pointer.
     *
     * @return The pointer.
     */
    const T* getPtr() const
    {
        return instancePtr;
    }

    /**
     * Test the pointer for NULL.
     *
     * @return true if the pointer is NULL.
     */
    bool isNull() const
    {
        return instancePtr == 0;
    }

    /**
     * Unrefrence the current pointer and assing to NULL.
     *
     */
    void release()
    {
        if (instancePtr)
        {
            instancePtr->unref();
            instancePtr = NULL;
        }
    }

    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AutoPtr")

private:
    void setPtr(T* tp) { instancePtr = tp; }

    T* instancePtr;
};


}}} // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
