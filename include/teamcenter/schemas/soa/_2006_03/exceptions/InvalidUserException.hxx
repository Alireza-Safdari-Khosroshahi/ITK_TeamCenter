/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_INVALIDUSEREXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_INVALIDUSEREXCEPTION_HXX


#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/SoaException.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2006_03
            {
               namespace Exceptions
               {


class TCSOACOMMON_API InvalidUserException : public SoaException
{

public:

    InvalidUserException ();
    virtual ~InvalidUserException();
    explicit  InvalidUserException ( const std::string& message );
    InvalidUserException (int code, int level, const std::string& message, const std::string& tcResponse);

    int          getCode() const;
    int          getLevel()const;
    const std::string& getTcResponse()const;

    virtual std::string  getLocalName() const;


    SOA_CLASS_NEW_OPERATORS

private:


    int         m_code;
    int         m_level;
    std::string m_tcResponse;
};

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
