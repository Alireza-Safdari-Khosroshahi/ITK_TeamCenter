/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_IOEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_IOEXCEPTION_HXX


#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Exceptions
            {


class TCSOACOMMON_API IOException
{
public:
    IOException();
    explicit IOException( const std::string& message );
    ~IOException(){};
 
    virtual void setMessage( const std::string& message );
    virtual const std::string& getMessage();
    

    SOA_CLASS_NEW_OPERATORS

private:
    std::string m_message;
     
};
    
}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
