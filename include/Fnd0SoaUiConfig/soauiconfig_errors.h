/* Copyright 2020 Siemens Digital Industries Software
==================================================
Copyright $2014.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==================================================
Copyright 2020 Siemens Digital Industries Software */

/**
    @file

    Errors for the soa uiconfig services


*/


#ifndef SOAUICONFIG_ERRORS_H
#define SOAUICONFIG_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup SOAUICONFIG_ERRORS UI Configuration SOA Errors
    @ingroup SOAUICONFIG
    @{
*/

/**
The client scope URI &quot;%1$&quot; is not defined for the client &quot;%2$&quot;.
*/
#define SOA_UICONFIG_no_client_scope_uri_for_client                     (EMH_SOAUICONFIG_error_base +  1 )

/**
&quot;%1$&quot; is not a valid scope parameter input value. Valid values are Site, Group, Role, User, LoginUser and AvailableForLoginUser.  Please report this error to your system administrator.
*/
#define SOA_UICONFIG_invalid_scope_param                                (EMH_SOAUICONFIG_error_base +  2 )
/** @} */

#endif

