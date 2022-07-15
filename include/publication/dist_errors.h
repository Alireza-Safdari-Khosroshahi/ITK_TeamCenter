/*==================================================================================================

                    Copyright (c) 2004 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Errors for the Application Distribution ITK

====================================================================================================
   Date      Name                    Description of Change
25-Feb-2004  Tom McCabe              remote checkin-checkout project
26-Feb-2004  Tom McCabe              add DIST_object_is_local error
19-Feb-2006  Tom McCabe              on demand sync
10-Apr-2006  x_aravin                Added support for tracking the owning site (after merge from Tom Mccabe)
$HISTORY$
==================================================================================================*/

#ifndef DIST_ERRORS_H
#define DIST_ERRORS_H

/* When/if the "DIST_" ITK is released to the customer, we'll need to include without module */
#include <common/emh_const.h>

#define DIST_unsupported_client          (EMH_DIST_error_base + 1)
#define DIST_no_server_handler           (EMH_DIST_error_base + 2)
#define DIST_unsupported_operation       (EMH_DIST_error_base + 3)
#define DIST_server_handler_registered   (EMH_DIST_error_base + 4)
#define DIST_invalid_server_type         (EMH_DIST_error_base + 5)
#define DIST_argument_error              (EMH_DIST_error_base + 6)
#define DIST_object_is_local             (EMH_DIST_error_base + 7)

// DIST_no_replica_objects, DIST_all_objects_failed, DIST_tracking_owning_site are at 8,9,10
// respectively(in 9.1.3 MP2 onwards). If you happen to add these error code here add with
// respective error code.
// Other wise backword compatibility with 9.1.3 would be broken.
// This is the reason I am changing the error code of following as per PR#5521720
#define DIST_no_replica_objects          (EMH_DIST_error_base + 8)
#define DIST_all_objects_failed          (EMH_DIST_error_base + 9)
#define DIST_tracking_owning_site        (EMH_DIST_error_base + 10)
#define DIST_object_is_not_local         (EMH_DIST_error_base + 11)
#define DIST_cannot_checkout_replica_from_hub (EMH_DIST_error_base + 12)
#define DIST_MS_TIE_invalid_parameter_creation  (EMH_DIST_error_base + 13)

/**The distribution application name received by the client is not registered.*/
#define DIST_application_not_registered                     (EMH_DIST_error_base + 14 )

/**There is a mismatch in the sizes expected by the specification and what is received in the argument.*/
#define DIST_arg_validation_failed_mismatched_sizes         (EMH_DIST_error_base + 15 )

/**The dist operation initialization has failed, because the argument "%1$" is already present in the operation code specifications. Argument duplication is not allowed.*/
#define DIST_argument_already_specified                     (EMH_DIST_error_base + 16 )

/**The argument "%1$" needed in the specifications is not present in the arguments received.*/
#define DIST_arg_validation_arg_not_present                 (EMH_DIST_error_base + 17 )

/**A server side business-logic function is not defined. Please check the log for more information and contact the system administrator.*/
#define DIST_no_server_side_business_logic                  (EMH_DIST_error_base + 18 )

/**The distributed execution has failed. Please refer to the log files for details.*/
#define DIST_distributed_execution_failed                   (EMH_DIST_error_base + 19 )

/**The input arguments to the distributed call are not valid. Please refer to the log files for details.*/
#define DIST_input_validation_failed                        (EMH_DIST_error_base + 20 )

/**The output arguments to the distributed call are not valid. Please refer to the log files for details.*/
#define DIST_output_validation_failed                       (EMH_DIST_error_base + 21 )

/**The distributed (DIST) call arguments could not be validated in accordance with the specifications for the same operation code. Please refer to the log files for details.*/
#define DIST_argument_validation_failed                     (EMH_DIST_error_base + 22 )

/**The distributed call execution for the application "%1$" and the expand_abbreviation_opcode "%2$" has failed at the server side. Please refer to the log files for details.*/
#define DIST_server_execution_failed                        (EMH_DIST_error_base + 23 )

/**The server side business logic has failed. Please refer to the log files for details.*/
#define DIST_server_businesslogic_failed                    (EMH_DIST_error_base + 24 )

/**Some errors have occurred in the client server distributed function messages exchange. Please refer to the log files for details.*/
#define DIST_rpc_server_messaging_failed                    (EMH_DIST_error_base + 25 )

/**An error has occurred while converting the input to a 'distributed argument'. Please refer to the log files for details.*/
#define DIST_converting_pod_to_dist_struct_failed           (EMH_DIST_error_base + 26 )

/**4GD on demand synchronization is not supported on a hub site.*/
#define DIST_4GD_on_demand_sync_no_hub                      (EMH_DIST_error_base + 27 )

/**The search recipe "%1$" is not identical at both sites.*/
#define DIST_4GD_recipes_not_identical                      (EMH_DIST_error_base + 28 )

/**The search recipe "%1$" is not found.*/
#define DIST_4GD_recipe_not_found                           (EMH_DIST_error_base + 29 )

/**Multiple search recipes named "%1$" were found. Search recipes must be uniquely named for 4GD on demand synchronization.*/
#define DIST_4GD_recipe_name_not_unique                     (EMH_DIST_error_base + 30 )

/**Island based check-out is not supported at the remote site. Please contact your system administrator to upgrade the remote site to at least Teamcenter 11.1.0.*/
#define DIST_island_cico_not_supported                      (EMH_DIST_error_base + 31 )

/*
 * DIST_no_server_handler     -> No handler is registered for the given application and server type.
 * DIST_unsupported_operation -> A handle is registered for app_name for the given server, but the handler rejects client
 *
 * Either of these should be further qualified by pushing on top of them, a DIST_unsupported_client.  For example:
 *
 * For example, for DIST_no_server_handler:
 *
 *    "The client version 8.1.0.3 is unsupported by the server version 10.0.0.0"
 *    "No ODS server handler registered for application xxxx"
 *
 * or for example, for DIST_unsupported_operation:
 *
 *    "The client version 8.1.0.3 is unsupported by the server version 10.0.0.0"
 *    "Operation 2 of application xxxx is unsupported"
 *
 * This still doesn't do much for a "newer" client relative to an "older" server scenario.
 * As the distributed application evolves, you might want to code a "newer" client
 * to do things the "old" way when dealing with an "old" server and the "new" way when
 * dealing with a server that understands the new way.  This should be handled by the
 * client using DIST_version_check to interrogate server for its version.
 */
#endif
