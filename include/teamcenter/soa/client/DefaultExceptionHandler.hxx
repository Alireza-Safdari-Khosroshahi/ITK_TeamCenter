/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SOA_CLIENT_DEFAULTEXCEPTIONHANDLER_HXX
#define TEAMCENTER_SOA_CLIENT_DEFAULTEXCEPTIONHANDLER_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>
#include <teamcenter/soa/client/CanceledOperationException.hxx>
#include <teamcenter/soa/client/ExceptionHandler.hxx>


#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**
 * This is the defualt implementation of the ExceptionHandler used by the Connection
 * class to handle InternalServerExceptions.
 */
class TCSOACLIENTMNGD_API DefaultExceptionHandler :
          public      Teamcenter::Soa::Client::ExceptionHandler
{
public:
    DefaultExceptionHandler(): ExceptionHandler(){};
    ~DefaultExceptionHandler(){};


    /**
     * Handle the InternalServerException returned by a service request
     *
     * @param ise The InternalServerException
     */
    virtual void handleException( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InternalServerException& ise );

    /**
     * Handle the CanceledOperationException returned by a service request
     *
     * @param coe The CanceledOperationException
     */
    virtual void handleException( Teamcenter::Soa::Client::CanceledOperationException& coe );

    SOA_CLASS_NEW_OPERATORS

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif


