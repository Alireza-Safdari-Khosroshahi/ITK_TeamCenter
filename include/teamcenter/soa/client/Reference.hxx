/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_REFERENCE_HXX
#define TEAMCENTER_SOA_CLIENT_REFERENCE_HXX

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
class TCSOACLIENTMNGD_API Reference
{
public:

    virtual ~Reference();

    /**
     * @return The name
     */
    virtual std::string getName()=0;
    
   

    /**
     * @return The template.
     */
    virtual std::vector<std::string> getTemplates()=0;


    /**
     * @return The format.
     */
    virtual std::vector<std::string>   getFormats()=0;




   SOA_CLASS_NEW_OPERATORS

protected:
    Reference();


};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

