/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SOA_CLIENT_NOTLOADEDEXCEPTION_HXX
#define TEAMCENTER_SOA_CLIENT_NOTLOADEDEXCEPTION_HXX

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

class TCSOACLIENTMNGD_API NotLoadedException
{
public:



    NotLoadedException();
    explicit NotLoadedException( const std::string& message );
    virtual ~NotLoadedException();


    const std::string& getMessage() const;

    SOA_CLASS_NEW_OPERATORS


private:
    std::string m_message;
};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

