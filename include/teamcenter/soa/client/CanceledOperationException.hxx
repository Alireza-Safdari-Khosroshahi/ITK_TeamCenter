/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SOA_CLIENT_CANCELEDOPERATIONEXCEPTION_HXX
#define TEAMCENTER_SOA_CLIENT_CANCELEDOPERATIONEXCEPTION_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API CanceledOperationException
{
public:



    CanceledOperationException();
    explicit CanceledOperationException( const std::string& message );
    virtual ~CanceledOperationException();


    const std::string& getMessage() const;

    SOA_CLASS_NEW_OPERATORS

private:
    std::string m_message;
};
}}}//end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

