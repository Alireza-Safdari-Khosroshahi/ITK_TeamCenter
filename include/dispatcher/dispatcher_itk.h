/*
   Copyright 2020 Siemens Digital Industries Software
   ==================================================
   Copyright 2008.
   Siemens Product Lifecycle Management Software Inc.
   All Rights Reserved.
   ==================================================
   Copyright 2020 Siemens Digital Industries Software
*/

/**
    @file

    This file contains the different ITK methods available for the Dispatcher
    Management application for Teamcenter.

*/

#ifndef DISPATCHER_ITK_H
#define DISPATCHER_ITK_H


#include <dispatcher/dispatcher_errors.h>

#include <time.h>

#include <dispatcher/libdispatcher_exports.h>

/*
 * A OOTB supported translation argument that supports override of the
 * configured setting for update of existing data.
 */
#define DISPATCHER_UPDATE_EXISTING         "ETSUpdOvr"

#define DISPATCHER_PREF_SUCCESSFUL_STATES    "TS_successful_states"
#define DISPATCHER_PREF_UNSUCCESSFUL_STATES  "TS_unsuccessful_states"
#define DISPATCHER_PREF_INPROCESS_STATES     "TS_inprocess_states"

/**
   The following ETS related symbols have been deprecated and will be removed
   in the next release of Teamcenter.
 
   Please remove any instances you may have of these and replace them with the
   similar functionality available within Dispatcher Management.
*/

#define ETS_translation_arg_size_c                    255
#define ETS_TRANSLATION_ARG_NV_SEP                    "="
#define ETS_TRANSLATION_ARG_MIN_SIZE                  3

/** The original create API trigger argument */
#define ETS_TRANSLATION_ARG_NAME_TRIGGER              "ETSTrigger"

/**
  A OOTB supported translation argument that supports override of the
  configured ETS setting for update of existing translated data.
*/
#define ETS_TRANSLATION_ARG_NAME_UPDATE_OVR           "ETSUpdOvr"

/**
  Common value definitions
*/
#define ETS_TRANSLATION_ARG_VALUE_TRUE                "true"
#define ETS_TRANSLATION_ARG_VALUE_FALSE               "false"


#ifdef __cplusplus
extern "C"
{
#endif

/*
 * Dispatcher ITK Methods
 */

/*******************************************************************************
 * NAME: DISPATCHER_create_request
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This method will create a request object using the specified parameters.  The
 * minimal inputs required to create a request are the provider name, the service
 * name and a priority.  The other remaining inputs can be passed as null values.
 *
 * INPUTS
 *
 * provider_name - the name of the provider that will process this request
 * service_name - the name of the service that will process this request
 * priority - the priority to assign to the request
 *            (0 LOW to 3 HIGH)
 * start_time - the time at which to start this request
 * end_time - the time at which no more repeating requests of this same type
 *            will be processed.  If the interval option for repeating is NOT
 *            selected, then this paramater is unused
 * interval - the number of times to repeat this request
 *            0 - no repeating
 *            1 2 3 ... - number of times to repeat this task
 * num_objs - the length of the primary and secondary object arrays
 * primary_objs - the array of primary objects
 * secondary_objs - the array of related secondary objects
 * num_args - the number of request arguments
 * request_args - the array of request arguments in the format of
 *                <KEY>=<VALUE>  (i.e.  NAME=John)
 * type - a string for use by the application creating the request for use in
 *        defining a type for the request (i.e. SYSTEM, THINCLIENT, etc.)
 * num_datafiles - the number of datafiles you would like to upload
 * datafiles - the array of key/path value pairs for the datafiles you would
 *             like to upload.  The following format needs to be followed when
 *             passing the key/path value pairs:
 *             <KEY>=<PATH>    i.e. LogFile=C:/temp/logfile.log
 *
 *             NOTE: Use forward slashes(/) for the path seperators.
 *
 * OUTPUTS
 *
 * request - the request that was created
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_create_request(
        const char*         provider_name,           /**< (I)  provider name                       */
        const char*         service_name,            /**< (I)  service name                        */
        const int           priority,                /**< (I)  priority                            */
        const time_t        start_time,              /**< (I)  start time                          */
        const time_t        end_time,                /**< (I)  end time                            */
        const int           interval,                /**< (I)  repeating interval                  */
        const int           num_objs,                /**< (I)  number of primary/secondary objects */
        const tag_t*        primary_objs,            /**< (I)  primary objects                     */
        const tag_t*        secondary_objs,          /**< (I)  secondary objects                   */
        const int           num_args,                /**< (I)  number of request arguments         */
        const char**        request_args,            /**< (I)  request arguments                   */
        const char*         type,                    /**< (I)  request type string                 */
        const int           num_datafiles,           /**< (I)  number of datafiles to attach       */
        const char**        data_file_keys,          /**< (I)  keys for data files to attach       */
        const char**        datafiles,               /**< (I)  data files to attach absolute path  */
        tag_t*              request                  /**< (O)  created request                     */
    );

/*******************************************************************************
 * NAME: DISPATCHER_query_requests
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function allows the user to query for requests based on selected
 * criteria.  All defined inputs are OPTIONAL and if omitted will not become
 * part of the query.
 *
 * INPUTS
 *
 *    num_providers  - number of providers
 *    providers      - providers
 *    num_services   - number of services
 *    services       - services
 *    num_states     - number of states
 *    states         - states
 *    num_priorities - number of priorities
 *    priorities     - priorities
 *    num_users      - number of users
 *    owning_users   - owning users
 *    num_taskids    - number of taskids
 *    task_ids       - task IDs
 *
 * OUTPUTS
 *
 *    num_requests     - number of requests
 *    queried_requests - requests
 *
 * num_requests - the number of requests returned from the query
 * requests - the requests returned from the query
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_query_requests(
        const int     num_providers,   /**< (I)  number of provider                    */
        const char**  providers,       /**< (I)  providers array                       */
        const int     num_services,    /**< (I)  number of services                    */
        const char**  services,        /**< (I)  services array                        */
        const int     num_states,      /**< (I)  number of states                      */
        const char**  states,          /**< (I)  states array                          */
        const int     num_priorities,  /**< (I)  number of priorities                  */
        const int*    priorities,      /**< (I)  priority array                        */
        const int     num_users,       /**< (I)  number of users                       */
        const char**  owning_users,    /**< (I)  user array                            */
        const int     num_taskids,     /**< (I)  number of task ids                    */
        const char**  task_ids,        /**< (I)  task id array                         */
              int*    num_requests,    /**< (O)  number of requests                    */
              tag_t** queried_requests /**< (OF) num_requests number of requests found */
    );

/*******************************************************************************
 * NAME: DISPATCHER_wait_for_request
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function allows the user to query for requests based on selected
 * criteria.  All defined inputs are OPTIONAL and if omitted will not become
 * part of the query.
 *
 * INPUTS
 *
 *    request      - tag of the request to wait
 *    interval     - interval in seconds defining how often the request state should be checked
 *    time_to_wait - time in seconds to continue checking, 0 = no time limit
 *    is_final     - whether or not the request is in a final state, successful or unsuccessful
 *
 * OUTPUTS
 *
 *    complete - logical specifying if the request was complete or not
 *
  * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_wait_for_request(
        tag_t    request,       /**< (I)  tag of the request to wait */
        int      interval,      /**< (I)  interval defining how often the request state should be checked */
        int      time_to_wait,  /**< (I)  time in seconds to continue checking, 0 = no time limit */
        logical* is_final       /**< (O)  boolean specifying if the request was complete or not */
    );

/*******************************************************************************
 * NAME: DISPATCHER_delete_request
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function allows the user to delete a request.  If the user specifies to
 * check the state, then only states in a final state will be allowed to be
 * removed.
 *
 * INPUTS
 *
 * requestToDelete - the tag of the request object to delete
 * ignoreState     - should the state be ignored or validated
 *
 * OUTPUTS
 *
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_delete_request(
              tag_t   requestToDelete,  /**< (I)  tag of the request to delete         */
              int     ignoreState       /**< (I)  should state be checked, 1=YES, 0=NO */
    );

/*******************************************************************************
 * NAME: DISPATCHER_add_files_to_request
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function allows the user to attach files to a request with a given key.
 *
 * INPUTS
 *
 * request      - tag of the request
 * numFiles     - number of files to upload
 * fileKeys     - file keys to associate to files
 * files        - absolute paths to files
 *
 * OUTPUTS
 *
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_add_files_to_request(
              const tag_t   request,    /**< (I)  tag of the request               */
              const int     numFiles,   /**< (I)  number of files to upload        */
              const char**  fileKeys,   /**< (I)  file keys to associate to files  */
              const char**  files       /**< (I)  ABSOLUTE paths to file to upload */
    );

/*******************************************************************************
 * NAME: DISPATCHER_get_files_from_request
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function allows the user to get files from a request with a given key.
 *
 * INPUTS
 *
 * request      - tag of the request
 * numKeys      - number of keys to get files
 * keys         - file keys identifying which files to get
 * path         - absolute paths to directory to get files
 *
 * OUTPUTS
 *
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_get_files_from_request(
        const tag_t  request,     /**< (I) tag of the request              */
        const int    numKeys,     /**< (I) number of keys for files to get */
        const char** keys,        /**< (I) keys for files to get           */
        const char*  path         /**< (I) folder to output files          */
    );

/*******************************************************************************
 * NAME: DISPATCHER_find_request_by_tag
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function will return the attributes of a request using its tag.
 *
 * INPUTS
 *
 * requestTag       - tag of the request to load
 *
 * OUTPUTS
 *
 * task_id          - task id
 * providerName     - provider name
 * serviceName      - service name
 * priority         - priority (1, 2 or 3)
 * currentState     - current state
 * type             - type of request
 * numObjs          - number of primary/secondary objects
 * primaryObjs      - primary objects
 * secondaryObjs    - secondary objects
 * numArgs          - number of arguments
 * argKeys          - argument keys
 * argData          - argument data
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_find_request_by_tag(
        const tag_t   requestTag,       /**< (I)  tag of the request */
        char**        task_id,          /**< (OF) task id */
        char**        providerName,     /**< (OF) provider name */
        char**        serviceName,      /**< (OF) service name */
        int*          priority,         /**< (O)  priority of the request */
        char**        currentState,     /**< (OF) current state */
        char**        type,             /**< (OF) type */
        int*          numObjs,          /**< (O)  number of primary/secondary object references */
        tag_t**       primaryObjs,      /**< (OF) numObjs an array of primary object tags */
        tag_t**       secondaryObjs,    /**< (OF) numObjs an array of secondary object tags */
        int*          numArgs,          /**< (O)  number of arguments */
        char***       argKeys,          /**< (OF) numArgs array of argument keys */
        char***       argData           /**< (OF) numArgs array of argument data */
    );

/*******************************************************************************
 * NAME: DISPATCHER_is_final_state
 * AUTHOR(S): David Hollins
 *
 * DESCRIPTION
 *
 * This function allows the user to check as to whether or not a request is in
 * a final state.
 *
 * INPUTS
 *
 * request        - tag of the request
 *
 * OUTPUTS
 *
 * isFinalState   - 0 - not final state, 1 - final state
 *
 * RETURN
 *
 * ITK_ok if no errors, otherwise an error code
 *
 ******************************************************************************/
extern int DISPATCHER_API
    DISPATCHER_is_final_state(
              const tag_t  request,     /**< (I) tag of the request */
              int*         isFinalState /**< (O) 0 - not final state, 1 - final state */
    );

/* ========================================================================= */
/* DEPRECATED ETS FUNCTIONS
 *
 * The following functions have been deprecated and will be removed in the next
 * release of Teamcenter.  Please make the necessary changes to migrate to the
 * new Dispatcher Management functions defined above.
 */

    /*******************************************************************************
     * NAME: ETS_create_request (DEPRECATED)
     *
     * DESCRIPTION
     *
     * This function validates a request to create a translation request object.
     *
     * NOTE: Please use the replacement method within Dispatcher Management.
     *
     ******************************************************************************/
    extern int DISPATCHER_API
        ETS_create_request(
            const int           num_objs,                /* <I> */
            const tag_t        *primary_objs,            /* <I> */
            const tag_t        *secondary_objs,          /* <I> */
            const int           sched_priority,          /* <I> */
            const char         *provider_name,           /* <I> */
            const char         *translator_name,         /* <I> */
            const char         *trigger,                 /* <I> */
            tag_t              *request                  /* <O> */
        );

    /*******************************************************************************
     * NAME: ETS_create_request2 (DEPRECATED)
     *
     * DESCRIPTION
     *
     * This function validates a request to create a translation request object
     * that contains additional translation arguments.
     *
     * NOTE: Please use the replacement method within Dispatcher Management.
     *
     ******************************************************************************/

    extern int DISPATCHER_API ETS_create_request2 (
            const int           num_objs,                /* <I> */
            const tag_t        *primary_objs,            /* <I> */
            const tag_t        *secondary_objs,          /* <I> */
            const int           priority,                /* <I> */
            const char         *provider_name,           /* <I> */
            const char         *translator_name,         /* <I> */
            const char         *trigger,                 /* <I> */
            const int           num_translation_args,    /* <I> */
            const char        **translation_args,        /* <I> */
            tag_t              *request                  /* <O> */
            );

    /*******************************************************************************
     * NAME: ETS_query_requests (DEPRECATED)
     *
     * DESCRIPTION
     *
     * This function allows the user to query for requests bases in a state.
     *
     * NOTE: Please use the replacement method within Dispatcher Management.
     *
     ******************************************************************************/
    extern int DISPATCHER_API ETS_query_requests(
        const char *translationRequestState,    /* <I>  */
        int        *numTranslationRequests,     /* <O>  */
        tag_t      **translationRequests );     /* <OF> */


    /*******************************************************************************
     * NAME: ETS_find_request_by_tag (DEPRECATED)
     *
     * DESCRIPTION
     *
     * This function returns the properties of a request given the tag of the request
     * object.
     *
     * NOTE: Please use the replacement method within Dispatcher Management.
     *
     ******************************************************************************/
    extern int DISPATCHER_API ETS_find_request_by_tag(
            const tag_t   requestTag,              /**< (I)  tag of the request */
            char**        task_id,                 /**< (OF) task id */
            char**        state,                   /**< (OF) current state */
            int*          num_objs,                /**< (O)  number of primary/secondary object references */
            tag_t**       primary_objs,            /**< (OF) num_objs an array of primary object tags */
            tag_t**       secondary_objs,          /**< (OF) num_objs an array of secondary object tags */
            int*          priority,                /**< (O)  priority of the request */
            char**        provider_name,           /**< (OF) provider name */
            char**        translator_name,         /**< (OF) service name */
            int*          num_trans_args,          /**< (O)  number of translator arguments */
            char***       translation_args         /**< (OF) num_trans_args array of translator arguments */
            );

    /*******************************************************************************
     * NAME: ETS_is_final_state (DEPRECATED)
     *
     * DESCRIPTION
     *
     * This function returns returns an integer representing if the request that
     * was specified is currently in a final state.
     *
     * NOTE: Please use the replacement method within Dispatcher Management.
     *
     ******************************************************************************/
    extern int DISPATCHER_API
        ETS_is_final_state(
            const tag_t   request,            /**< (I) tag of the request */
            int*          isFinalState        /**< (O) 0 - not final state, 1 - final state */
        );

#ifdef __cplusplus
}
#endif

#include <dispatcher/libdispatcher_undef.h>

#endif
