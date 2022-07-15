/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  **/
#ifndef TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_SOAEXCEPTION_HXX
#define TEAMCENTER_SCHEMAS_SOA_200603_EXCEPTIONS_SOAEXCEPTION_HXX


#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

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

class ServiceException;
class InvalidCredentialsException;
class InternalServerException;

class TCSOACOMMON_API Error
{
public:

    enum Severity
    {
        Severity_information = 1,
        Severity_warning     = 2,
        Severity_error       = 3,
        Severity_user_error  = 4
    };

     std::string message;
     int         code;
     Severity    level;


    ~Error(void){};
    Error& operator  =(const Error& that);


    SOA_CLASS_NEW_OPERATORS

private:
    Error( );
    Error( const std::string& message, const int code, const Severity level);

    friend class ServiceException;
    friend class InvalidCredentialsException;
    friend class InternalServerException;
};

class TCSOACOMMON_API SoaException
{
public:
    SoaException();
    explicit SoaException( const std::string& message );
    virtual ~SoaException();

    virtual void setMessage( const std::string& message );
    virtual const std::string& getMessage() const;

    virtual std::string  getNamespace() const;
    virtual std::string  getLocalName() const;

    SOA_CLASS_NEW_OPERATORS

private:
    std::string m_message;



};

inline SoaException::~SoaException(){}

}}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
