/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_DOMEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_DOMEXCEPTION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <string>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            namespace Exceptions
            {


class TCSOACOMMON_API DomException
{
public:
    DomException();
    virtual ~DomException();
    explicit DomException( const std::string& message );

    virtual void setMessage( const std::string& message );
    virtual const std::string& getMessage();

    SOA_CLASS_NEW_OPERATORS

private:
    std::string m_message;

};

}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
