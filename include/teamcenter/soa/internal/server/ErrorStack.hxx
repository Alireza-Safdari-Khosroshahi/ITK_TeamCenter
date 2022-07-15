/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_ERRORSTACK_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_ERRORSTACK_HXX

#include <string>
#include <map>

#include <tc/emh.h>

#include <metaframework/BusinessObjectRef.hxx>

#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ErrorStack.hxx>
#include <teamcenter/soa/server/SoaServerExports.h>

typedef int ERROR_severity_t;

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {

/**
 * The ErrorStack contains one or more ErrorValue.
 * Where an operation may have more than one contributing reason for the
 * errror. The ErrorStack may also have an optional UID or Client ID
 * associated with the error. See the service operation documentation for
 * specifics of if these optional fields are filled.
 */
class  TCSOASERVER_API ErrorStack
{
public:

   /**
     * Add the current error stack.
     * The ERROR_store_ask and ERROR_store_clear utilities are used
     * to get the current stack and clear it.
     *
     */
    ErrorStack  ( );
    ~ErrorStack ( );

   /**
     * Add the current error stack.
     * The ERROR_store_ask and ERROR_store_clear utilities are used
     * to get the current stack and clear it.
     *
     * @param clientId    Client ID to be associated with this stack
     */
    explicit ErrorStack  ( const std::string& clientId );


   /**
     * Add the current error stack.
     * The ERROR_store_ask and ERROR_store_clear utilities are used
     * to get the current stack and clear it.
     *
     * @param obj    Object to be associated with this stack
     */
    explicit ErrorStack  ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );


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
     * @param s1 to s7  Must all be const char *s substituted into the translated string,
     *                  where %n$s in the string gives the nth argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message
     */
    ErrorStack( ERROR_severity_t severity, int ifail,
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
     * @param s1 to s7  Must all be const char *s substituted into the translated string,
     *                  where %n$s in the string gives the nth argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message
     */
    ErrorStack( const std::string& clientId, ERROR_severity_t severity, int ifail,
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
     * @param s1 to s7  Must all be const char *s substituted into the translated string,
     *                  where %n$s in the string gives the nth argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message
     */
    ErrorStack( const BusinessObjectRef<Teamcenter::BusinessObject> obj, ERROR_severity_t severity, int ifail,
                const char *s1=0, const char *s2=0, const char *s3=0,
                const char *s4=0, const char *s5=0, const char *s6=0, const char *s7=0);


   /**
     * Set the Client ID on the current error stack.
     *
     * @param clientIndex    Client Index to be associated with this stack
     */

    void setClientIndex( int clientIndex );

    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack>& getWireErrorStack (  ) const;


private:

    // Don't allow copy constructors
    ErrorStack( const ErrorStack& right);
    ErrorStack& operator = ( const ErrorStack& right);

    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack>        m_wireErrorStack;

    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack> getErrorsFromStore (  );
};        // End Class
}}}}    // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
