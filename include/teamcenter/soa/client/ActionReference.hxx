/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_ACTIONREFERENCE_HXX
#define TEAMCENTER_SOA_CLIENT_ACTIONREFERENCE_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/client/Reference.hxx>
#include <teamcenter/soa/common/MemoryManager.hxx>




#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 */
class TCSOACLIENTMNGD_API ActionReference
{
public:

    virtual ~ActionReference();

    /**
     * @return The name
     */
    virtual std::string getName()=0;
    
    
    /**
     * @return The Reference.
     */
    virtual Reference* getReference()=0;


    /**
     * @return is export
     */
    virtual bool isExport()=0;

   SOA_CLASS_NEW_OPERATORS

protected:
    ActionReference();


};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

