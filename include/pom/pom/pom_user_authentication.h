/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Support for integrating with external user authentication. e.g. LDAP.

    The existing Teamcenter Engineering clients and servers expect to be given a
    user id and password. The authentication of which is performed within the POM
    login code. The POM's default login code can now be replaced via a user exit.
    However there are several issues the exit must cope with to balance the requirement
    to be replaced while still be secure given ITK and split client/server
    authentication schemes.

    Requirements:
    <ol>
    <li>Allow the POM authentication of user id/password to be replaced - requires an exit.
    <li>Ensure that exit can be validated - avoid the obvious replacement with an
    implementation that simply returns true (ignoring the password). i.e. prevent
    subversion of security by ensuring the code is trustworthy.
    <li>Allow the client side to perform the authentication. Since it has the UIF and
    many authentication devices operate at the client side, we should allow the
    client to assert the user as authenticated. This means we wont have a password
    for the user. However a password should still be required inorder that we
    trust the source of the user id. In the case of the server side exit expecting
    the client to assert a user then in the absence of a password of some sort
    being given to the server an alternative client could call the server without
    actually having performed the authentication.
    </ol>

    The exit is given the user, their password as entered, and a "key" for validating
    the algorithim is approved by the admin. The key has a corresponding "secret"
    that is derived from the key in a manner known only to the exits implementor.
    The key and secret are made known to the POM via an install option:

    \$TC_BIN/install -set_eim_key \<dba user\> \<dba pass\> \<dba group\> login \<key\> \<secret\>

    @note The secret is stored one-way encrypted in the DB - so sql access should not
    allow it to be compromised.

    Once a key/secret pair is established then the implementor can register their
    exit using POM_set_user_authentication_fn from the user exit ::USER_preinit_module.
    The key will be looked up inorder to call the exit with the necessary info.

    The exit informs the POM of whether the password is correct via a callback. The
    callback also expects to be told what the keys corresponding secret was. If this
    compares against the DB record then the exit is trusted and its verdict on the
    validity of the password is accepted.

    This is done as a callback in preference to simple return arguments so as to
    avoid attempts to replace the user exit with a wrapper that calls the genuine
    implementation, and thus can intecept the correct secret, but changes the
    verdict on the password is avoided.

    When the users password is fully authenticated at the client then the password
    sent to the server should be used to ensure the client is trusted. Whatever
    password is sent should be derived in a secure manner from the user id. So,
    for the Web client, if I observe the http requests of my own authenticated
    session then I could only use that info to access the server directly (bypassing
    the Web client and authentication code) for my own account - which is obviously
    already checked and so not revealing anything not already available. However
    such observation of the password sent should not allow a socket level accessor
    to guess the password for other users accounts (either due it being hardwired
    or trivially derived).

    Thus: for a secure login with external authentication (client side) the
    system should be secure against attempts to replace the exit (server side)
    and/or present a client that asserts it's authentic without having used
    the required tests.

    @note If the exit requires some context (such as certificates, connection info, etc)
    then the closure arg can be passed in when setting the exit and requested from
    within the exit via #POM_ask_user_authentication_data.

    @note This scheme does still require that the user identified does exist in the
    Teamcenter Engineering DB. It is simply the Teamcenter Engineering password
    that is unused.

    @note #POM_check_password will also use the exit to authenticate. But the
    #POM_set_password function will return #POM_op_not_supported. We don't have any
    basis for communicating a password change to an authentication server.

    Typical usage:
    <ol>
    <li>Establish a key/secret pair.

        \$TC_BIN/install -set_eim_key infodba \<dba-pass\> dba login key secret

    <li>Prior to POM login ( #POM_login / #POM_start ) register your own
        password authentication function via POM_set_user_authentication_fn. Do this
        from ::USER_preinit_module - which gets called before login. 
        @note ::USER_init_module gets called after login, and thus does not satisfy the requirements.

    <li>Within that exit derive the secret from the key and determine the validity
        of your password against the given user. Callback to the POM code with
        the secret and status (true if the password was good) via #POM_user_authentication_cb.
    </ol>
    Error messages given to the user:

    By default the error codes you may get from POM_start/login/etc are
    (in order raised):

    #POM_no_exit_key_set -   Couldn't find the "login" key. Inorder to validate the exit
                             a "key" must be set via "install -set_eim_key".

    #POM_bad_pass_exit -     The exit called back with a "secret" that did not match the
                             "login" secret. Suggests exit not trustworthy.
                         
    #POM_pass_exit_failure - This is a catch all - if the exit code raises an error of
                             some sort it is caught. Check syslog for what may have failed.

    #POM_invalid_account_values  -     The exit succeeded and is trusted, but it claims the user id and or password
                             is false. This is the same error a POM login with no exit
                             would raise when the password is not correct.

    If an error code other than #POM_invalid_account_values is required then it can
    be set via #POM_user_auth_set_error. The POM_start/POM_login/etc will
    still return #POM_invalid_account_values , but #POM_user_auth_ask_error can be used
    to see that the customization has set a more specific error.

    For Teamcenter Engineering login, if the POM returns #POM_invalid_account_values,
    and we get a non-zero return from #POM_user_auth_ask_error, then the Teamcenter Engineering
    error stack is left alone - as it is assumed the user has already posted relevant info
    (via the EHM functions - see ehm.h). If #POM_user_auth_ask_error does
    return zero (no error set) then the #POM_invalid_account_values error will be
    posted (as usual). The higher precedence error codes cannot be overridden
    in this manner - since they imply the exit was bad, not just failing.

    By allowing the exit to post errors directly to the Teamcenter Engineering error stack
    more info can be supplied to the user than the POM error code would allow.
    The errors should at least differentiate failure to check the password
    from a test that worked, but found the password to be wrong. e.g. supply
    substituted values - such as a server name if there was a problem
    contacting the external authentication service. Or "number of tries left"
    if the exit enforces a limited number of attempts on login.

    Further notes.
    <ul>
    <li>Using Teamcenter Engineering password checking from the exit.

        If a combination of external and internal authentication is required
        (e.g. infodba requires Teamcenter Engineering password, but regular users
        use a common external account) then the existing Teamcenter Engineering
        password checker can be called via: #POM_user_auth_default_checker. e.g.
        @code
            static void auth_test_fn(char* user, char* password, char* key)
            {
                logical status = false;

                if (strcmp(user, "infodba") == 0)
                {
                    status = POM_user_auth_default_checker(user, password);
                }
                else
                {
                    int err = 0;
                    char* server = my_ext_auth_server();
                    err = my_check_password(server, user, password, &status);

                    if (err != 0)
                    {
                        EMH_store_initial_error_s1(EMH_severity_error, USER_ERROR_CODE, server_name);
                        POM_user_auth_set_error(USER_ERROR_CODE);
                    }
                }

                POM_user_authentication_cb(my_key_to_secret(key), status);
            }
        @endcode
        The "my_ext_auth_server", "my_check_password" and "my_key_to_secret" are
        a fictional example of what you might have to call outside of iMAN...
        Note the need to demonstrate exit is good - even if just delegating
        back to Teamcenter Engineering check.

    <li>Access to other objects within exit.

        Most POM functions require the user to be logged in before they
        can be called. A small subset can be used. Notably, you cannot
        load POM objects (requires access checks). But you can use POM
        queries. This may pose a problem for storing information gathered
        during login - e.g. marking user as disabled after some number
        of failed attempts to login.

        As a side note to developers - making load/edit/save available with
        bypass wouldn't help since the login will rollback on getting an
        error. Today if I were to need to store "additional attributes"
        against a user I'd create a seperate table (since we don't support
        adding attributes to core objects, like user) and accessing it via the
        POM procedure functions - therein an autonomous transaction can ensure
        that any updates are not rolled back on raising an error.

    <li>#POM_check_password vs. #POM_start / #POM_login.

        Compare will only test for whether the password is right or
        wrong. If an error has been set (via #POM_user_auth_set_error) then
        it is raised. If no error is set (the default) then the compare
        function will just return the status given. Therefore if no error
        is set then you should return false, but the caller will not
        be able to differentiate "check failed" (e.g. external server
        down) from "checked ok, and the password is wrong".

    <li>User id lowercasing and i18n issues.

        The user id and password are both passed into the authentication
        exit raw (as supplied to POM login). The user id's are stored in
        lower case in the DB - thus user id's returned once logged in
        may differ from what the user supplied the exit. This may matter
        when contacting external services. If a query is needed to lookup
        the user tag (hence UID) then the case insensitive flag should be
        used. Internally the case mapping uses the TEXT functions so as to
        be sensitive to locale. Passwords have case preserved.
    </ul>
*/

/*  */

#ifndef POM_USER_AUTHENTICATION_H_INCLUDED
#define POM_USER_AUTHENTICATION_H_INCLUDED

#include <pom/pom/libpom_exports.h>

/**
    @defgroup POM_USER_AUTHENTICATION User Authentication
    @ingroup POM
    @{
*/

typedef void (*POM_user_authentication_fn_t)(
    const char* user,
    const char* password,
    const char* key
    );

#ifdef __cplusplus
    extern "C"{
#endif

/** Obtains the current external authenticator function and user_data */
POMAPI void POM_get_user_authentication_fn(
    POM_user_authentication_fn_t    *user_exit,     /**< (O) pointer to the authentication function */
    void*                           *user_data      /**< (O) pointer to user data required by the authenticator; authenticator-dependent */
    );

/** Sets the external authenticator function and function-specific user_data */
POMAPI void POM_set_user_authentication_fn(
    POM_user_authentication_fn_t    user_exit,      /**< (I) pointer to the authentication function */
    void*                           user_data       /**< (I) data as required by the authenticator; authenticator-dependent */
    );

POMAPI void POM_user_authentication_cb(
    const char* secret,
    logical     status
    );

POMAPI void POM_user_auth_set_error(
    int     error
    );

POMAPI void* POM_ask_user_authentication_data(void);

POMAPI logical POM_has_user_authentication_fn(void);

POMAPI logical POM_user_authentication_invoke(
    const char* user,
    const char* password
    );

POMAPI logical POM_user_auth_default_checker(
    const char* user,
    const char* password
    );

POMAPI int POM_user_auth_ask_error(void);

/**
 Checks the authentication with the user inputs as provided
  The return type is void
*/
POMAPI void POM_user_auth_test_checker(
    const char *user, /**< (I) The user ID which is given by the user */
    const char *password,/**< (I) The password to be authenticated */ 
    const char *key/**< (I) The unique key, which was used when invoking the "set_eim_key" utility */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <pom/pom/libpom_undef.h>

#endif

