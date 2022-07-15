/**
    @file

    This file contains definitions used for the Dispatcher application.
*/
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <dispatcher/dispatcher_errors.h>

#ifdef _cplusplus
extern "C"
{
#endif

/**
     Static strings representing the different attributes of the DispatcherRequest class
 */
static const char *DISPATCHER_CLASS_NAME                  =  "DispatcherRequest";
static const char *DISPATCHER_ATTR_NAME_STATE             =  "currentState";
static const char *DISPATCHER_ATTR_NAME_PRIMARY_OBJS      =  "primaryObjects";
static const char *DISPATCHER_ATTR_NAME_SECONDARY_OBJS    =  "secondaryObjects";
static const char *DISPATCHER_ATTR_NAME_PRIORITY          =  "priority";
static const char *DISPATCHER_ATTR_NAME_PROVIDER_NAME     =  "providerName";
static const char *DISPATCHER_ATTR_NAME_SERVICE_NAME      =  "serviceName";
static const char *DISPATCHER_ATTR_NAME_TASK_ID           =  "taskID";
static const char *DISPATCHER_ATTR_NAME_TYPE              =  "type";
static const char *DISPATCHER_ATTR_NAME_CREATION_DATE     =  "creation_date";
static const char *DISPATCHER_ATTR_NAME_MODIFICATION_DATE =  "last_mod_date";
static const char *DISPATCHER_ATTR_NAME_OWNING_USER       =  "owning_user";
static const char *DISPATCHER_ATTR_NAME_ARGUMENT_KEYS     =  "argumentKeys";
static const char *DISPATCHER_ATTR_NAME_ARGUMENT_DATA     =  "argumentData";

/**
     Dispatcher Request States
 */
static const char *DISPATCHER_STATES_INITIAL   = "INITIAL";
static const char *DISPATCHER_STATES_CANCELLED = "CANCELLEd";

/**
     Preference used to determine if the Dispatcher Service has been installed.
 */    
static const char *DISPATCHER_CLIENT_INSTALLED_PREF   = "DISPATCHER_CLIENT_INSTALLED";

/**
     OLD ETS RELATED DEFINES

     This definition determines which datasets will trigger a removal or related 
     requests when that dataset is deleted...
 */
static const char *ETS_PREF_TR_REFERENCED_DATASET_TYPES     = "ETS_trans_rqst_referenced_dataset_types";
static const char *DISPATCHER_TR_CANCEL_REFERENCED_SERVICES = "DISPATCHER_rqst_cancel_referenced_services";

#ifdef _cplusplus
}
#endif

#endif
