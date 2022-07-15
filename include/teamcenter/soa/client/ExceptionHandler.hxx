/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef TEAMCENTER_SOA_CLIENT_EXCEPTIONHANDLER_HXX
#define TEAMCENTER_SOA_CLIENT_EXCEPTIONHANDLER_HXX

#include <teamcenter/schemas/soa/_2006_03/exceptions/InternalServerException.hxx>
#include <teamcenter/soa/client/CanceledOperationException.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**
 * This interface is used to provide a common means of handling exceptions.
 * Clients should implement it to change the default behaviour.
 */
class TCSOACLIENTMNGD_API ExceptionHandler
{
public:
     ExceptionHandler(void);
     virtual ~ExceptionHandler(void);

    /**
     * Handle the InternalServerException returned by a service request.
     *
     * The implementation of this method should evaluate the servarity of the excetpion,
     * display any information to the user, and decide weather to continue or terminate.
     * If it is decided to continue, simply returning from this method will send the control
     * back to the SOA Framework, where that last service request will be re-sent.
     * Throwing a RunTimeException will cause the last request to be terminated
     * and the exception will buble up to the nearest catch.<br>
     *
     * The InternalServerExcpetion is a general exception the covers configuration
     * or deployment errors internal to the server (web tier or enterprise tier) and
     * can not be recovered from. The InternalServerExcpetion has two child exception
     * classes, ConnectionException and ProtocolException. The ConnectionExeptions are
     * the result of a network being down or other I/O errors that can geneally be
     * recovered from, and the last service request be sent again. The ProtocolExceptions
     * are caused by bad or unexpected data in the service request. This is usually
     * the result of a programming error and can not be recovered from.
     *
     * @param ise The InternalServerException
     */
    virtual void handleException( Teamcenter::Schemas::Soa::_2006_03::Exceptions::InternalServerException& ise ) = 0;

    /**
     * Handle the CanceledOperationException returned by a service request
     *
     * @param coe The CanceledOperationException
     */
    virtual void handleException( Teamcenter::Soa::Client::CanceledOperationException& coe ) = 0;

    /**
     * To allows the clients to clean up any state they track on failed connections.
     *
     */
    virtual void handleSuccess() {}

};
inline ExceptionHandler::ExceptionHandler(){}
inline ExceptionHandler::~ExceptionHandler(){}

}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

