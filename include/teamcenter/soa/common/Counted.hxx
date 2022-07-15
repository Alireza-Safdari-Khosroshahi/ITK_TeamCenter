/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef TEAMCENTER_SOA_COMMON_COUNTED_HXX
#define TEAMCENTER_SOA_COMMON_COUNTED_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
         namespace Common
         {
            template <class T> class AutoPtr;
/**
 *
 **/
class TCSOACOMMON_API Counted
{
public:


    int  getCount() const;

    SOA_CLASS_NEW_OPERATORS

protected:
    Counted();
    virtual ~Counted ();


private:
    template <class T> friend class AutoPtr;

    int count;

    void ref();
    void unref();



};




}}} // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
