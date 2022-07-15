/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_SERVER_SERVICEEXCPETION_HXX
#define INCLUDE_TEAMCENTER_SOA_SERVER_SERVICEEXCPETION_HXX

#include <string>
#include <map>

#include <metaframework/BusinessObjectRef.hxx>

#include <teamcenter/schemas/soa/_2006_03/exceptions/ServiceException.hxx>
#include <teamcenter/soa/internal/server/ErrorStack.hxx>
#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Server
        {

/**
 * The ServiceException type is used to return an error from a service.
 */
class  TCSOASERVER_API ServiceException
{
public:

   /**
     * Add the current error stack.
     * The ERROR_store_ask and ERROR_store_clear utilities are used
     * to get the current stack and clear it.
     */
    ServiceException  ( );

   /**
     * Add the current error stack.
     * The ERROR_store_ask and ERROR_store_clear utilities are used
     * to get the current stack and clear it.
     * @param clientId    Client ID to be associated with this stack
     */
    explicit ServiceException  ( const std::string& clientId );


   /**
     * Add the current error stack.
     *
     * The ERROR_store_ask and ERROR_store_clear utilities are used
     * to get the current stack and clear it.
     * @param obj    Object to be associated with this stack
     */
    explicit ServiceException  ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );


    /**
     *
     * Add the given error to the store.
     * After this error is added ERROR_store_ask and ERROR_store_clear utilities
     * are used to get the full stack and clear it.
     *
     * @param severity  The severity of the error, must be one of
     *                  ERROR_severity_information
     *                  ERROR_severity_warning
     *                  ERROR_severity_error
     *                  ERROR_severity_user_error
     * @param ifail     Error code
     * @param s1        Substituted into the translated string,
     *                  where %n$s in the string gives the 1st argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message.
     * @param s2        Substituted into the translated string,
     *                  where %n$s in the string gives the 2nd argument to substitute.
     * @param s3        Substituted into the translated string,
     *                  where %n$s in the string gives the 3rd argument to substitute.
     * @param s4        Substituted into the translated string,
     *                  where %n$s in the string gives the 4th argument to substitute.
     * @param s5        Substituted into the translated string,
     *                  where %n$s in the string gives the 5th argument to substitute.
     * @param s6        Substituted into the translated string,
     *                  where %n$s in the string gives the 6th argument to substitute.
     * @param s7        Substituted into the translated string,
     *                  where %n$s in the string gives the 7th argument to substitute.
     */
    explicit ServiceException( ERROR_severity_t severity, int ifail,
                const char *s1=0, const char *s2=0, const char *s3=0,
                const char *s4=0, const char *s5=0, const char *s6=0, const char *s7=0);

    /**
     *
     * Add the given error to the store.
     * After this error is added ERROR_store_ask and ERROR_store_clear utilities
     * are used to get the full stack and clear it.
     *
     * @param clientId  Client ID to be associated with this stack
     * @param severity  The severity of the error, must be one of
     *                  ERROR_severity_information
     *                  ERROR_severity_warning
     *                  ERROR_severity_error
     *                  ERROR_severity_user_error
     * @param ifail     Error code
     * @param s1        Substituted into the translated string,
     *                  where %n$s in the string gives the 1st argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message.
     * @param s2        Substituted into the translated string,
     *                  where %n$s in the string gives the 2nd argument to substitute.
     * @param s3        Substituted into the translated string,
     *                  where %n$s in the string gives the 3rd argument to substitute.
     * @param s4        Substituted into the translated string,
     *                  where %n$s in the string gives the 4th argument to substitute.
     * @param s5        Substituted into the translated string,
     *                  where %n$s in the string gives the 5th argument to substitute.
     * @param s6        Substituted into the translated string,
     *                  where %n$s in the string gives the 6th argument to substitute.
     * @param s7        Substituted into the translated string,
     *                  where %n$s in the string gives the 7th argument to substitute.
     */
    ServiceException( const std::string& clientId, ERROR_severity_t severity, int ifail,
                const char *s1=0, const char *s2=0, const char *s3=0,
                const char *s4=0, const char *s5=0, const char *s6=0, const char *s7=0);

    /**
     *
     * Add the given error to the store.
     * After this error is added ERROR_store_ask and ERROR_store_clear utilities
     * are used to get the full stack and clear it.
     *
     * @param obj       Object to be associated with this stack
     * @param severity  The severity of the error, must be one of
     *                  ERROR_severity_information
     *                  ERROR_severity_warning
     *                  ERROR_severity_error
     *                  ERROR_severity_user_error
     * @param ifail     Error code
     * @param s1        Substituted into the translated string,
     *                  where %n$s in the string gives the 1st argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message.
     * @param s2        Substituted into the translated string,
     *                  where %n$s in the string gives the 2nd argument to substitute.
     * @param s3        Substituted into the translated string,
     *                  where %n$s in the string gives the 3rd argument to substitute.
     * @param s4        Substituted into the translated string,
     *                  where %n$s in the string gives the 4th argument to substitute.
     * @param s5        Substituted into the translated string,
     *                  where %n$s in the string gives the 5th argument to substitute.
     * @param s6        Substituted into the translated string,
     *                  where %n$s in the string gives the 6th argument to substitute.
     * @param s7        Substituted into the translated string,
     *                  where %n$s in the string gives the 7th argument to substitute.
     */
    ServiceException( const BusinessObjectRef<Teamcenter::BusinessObject> obj,  ERROR_severity_t severity, int ifail,
                const char *s1=0, const char *s2=0, const char *s3=0,
                const char *s4=0, const char *s5=0, const char *s6=0, const char *s7=0);

    /**
     * Virtual destructor
     */
    ~ServiceException  ( );

    const Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException& getWireData() const { return m_wireServiceException;}

private:
    void fillWireData( const Teamcenter::Soa::Internal::Server::ErrorStack& errorStack);

    Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException        m_wireServiceException;
};        // End Class
}}}       // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
