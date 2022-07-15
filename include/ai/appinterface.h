/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    ITK API for ApplicationInterface related class.

    This file contains methods related to Application Interface module.
*/

/*  */

#ifndef APPINTERFACE_H
#define APPINTERFACE_H

#include <unidefs.h>
#include <pie/pie.h>

#include <ai/libai_exports.h>

/**
    @defgroup APPINTERFACE Application Interface
    @ingroup PIE
    @{
*/

/**
    @name Collaboration Context related
    @{
*/
#define AppInterface_class_name_c                   "AppInterface"
#define MasterRecord_class_name_c                   "MasterRecord"
#define RequestObject_class_name_c                  "RequestObject"
#define RecordObject_class_name_c                   "RecordObject"
/** @} */

/**
    @name Type related
    @{
*/
#define AppInterfaceType_class_name_c "AppInterfaceType"
#define AppInterface_private_structure_type_name_c  "PrivateContext"
#define AppInterface_private_appgrp_type_name_c     "PrivateAppGrp"
#define AppInterface_vis_structure_type_name_c  "VisStructureContext"
/** @} */

#define TC_link_ic_relation_name                  "IMAN_eco_link"

#define AI_id_size_c                                WSO_desc_size_c
#define AI_msg_size_c                               WSO_desc_size_c

/** Preference */
#define AI_request_no_dependancy                    "AI_request_no_dependancy"

/** String max size */
#define AI_max_app_ref_string                       240

/** Request Object type */
#define AppInterfaceType_idc_type_name_c  "IntermediateDataCapture"
typedef enum Request_type_e
{
    Request_type_publish =0,
    Request_type_sync    =1,
    Request_type_any     =2
} Request_type_t;

/** Request Object status */
typedef enum Request_status_e
{
    Request_status_normal  =0,
    Request_status_warning =1,
    Request_status_severe  =2,
    Request_status_abort   =3,
    Request_status_any     =4
} Request_status_t;

/** Request Object state */
typedef enum Request_state_e
{
    Request_state_new           =0,
    Request_state_processing    =1,
    Request_state_pending       =2,
    Request_state_communicating =3,
    Request_state_completed     =4,
    Request_state_rejected      =5,
    Request_state_any           =6
} Request_state_t;

/** Request Object scope */
typedef enum Request_scope_e
{
    Request_scope_whole     =0,
    Request_scope_partial   =1,
    Request_scope_any       =2
} Request_scope_t;

/** Update type */
typedef enum Request_update_e
{
    Request_update_full     =0,
    Request_update_delta    =1,
    Request_update_any      =2
} Request_update_t;

typedef struct AI_search_criteria_s
{
    char       name[WSO_name_size_c+1];
    char       desc[WSO_desc_size_c+1];
    char       type[WSO_name_size_c+1];
    tag_t      owner;
    tag_t      group;

    date_t     createdBefore;
    date_t     modifiedBefore;
    date_t     releasedBefore;

    date_t     createdAfter;
    date_t     modifiedAfter;
    date_t     releasedAfter;

    char       context[AI_id_size_c+1];
    char       site_id[AI_id_size_c+1];
    char       project_id[AI_id_size_c+1];

} AI_search_criteria_t, *AI_search_criteria_p_t;

#ifdef __cplusplus
    extern "C"{
#endif

extern AI_API int AI_init_module();

/**
    @name AppInterface Related
    @{
*/

/**
    Create the AppInterface instance.
*/
extern AI_API int AI_create_instance(
    const char*    type,    /**< (I) */
    const char*    name,    /**< (I) */
    const char*    desc,    /**< (I) */
    tag_t*         ai       /**< (O) Tag of AppInterface instance */
    );

/**
    Export selected object through this AI. It will:
    <ol>
    <li>Store the objects in AI;
    <li>Create requestObject (sync)
    <li>Generate PLMXML file and store in requestobject
    </ol>
*/
extern AI_API int AI_export_objects(
    tag_t          ai,      /**< (I) This AI */
    int            num,     /**< (I) Number of objects */
    tag_t*         objects, /**< (I) Selcted objects */
    logical        partial  /**< (I) Export as partial request */
    );
/**
    Export selected object through this AI with Incremental Update. It will:
    <ol>
    <li>Store the objects in AI;
    <li>Create requestObject (sync)
    <li>Generate Incremental PLMXML file and store in requestobject
    </ol>
*/
extern AI_API int AI_export_objects_incremental(
    tag_t          ai,      /**< (I) This AI */
    int            num,     /**< (I) Number of objects */
    tag_t*         objects, /**< (I) Selcted objects */
    logical        partial  /**< (I) Export as partial request */
);
/**
    Ask whether we can add new request: right now the logical is:
    <ol>
    <li>Can not add new sync if pending Publish request
    <li>Can not add publish if pending sync
    </ol>
*/
extern AI_API int AI_can_add_request(
    tag_t          ai,      /**< (I) Owning AI */
    Request_type_t type,    /**< (I) Type of request (sync/publish) */
    logical*       ok       /**< (O) Whether ok to add or not */
    );

/**
    Create a RequestObject with the specific type. Tasks will be performed:
    <ol>
    <li>Create RequestObject instance
    <li>Assign RequestObject to this AI
    </ol>
*/
extern AI_API int AI_create_request(
    tag_t          ai,      /**< (I) Owning AI */
    const char*    name,    /**< (I) Name */
    const char*    desc,    /**< (I) Description */
    Request_type_t reqType, /**< (I) Type of request (sync/publish) */
    tag_t*         req      /**< (O) Requestobject created */
    );

/**
    Ask the requestObject from the AI, given the request type and/or state.
*/
extern AI_API int AI_ask_request_objects(
    tag_t           ai,     /**< (I) Owning AI */
    Request_type_t  type,   /**< (I) Type of request (sync/publish) */
    Request_state_t state,  /**< (I) State of the request */
    int*            num,    /**< (O) Number of requestobject found */
    tag_t**         req     /**< (OF) num Tag list of requestobject */
    );

/**
    Ask the next available requestObject from the AI, given the request type.
*/
extern AI_API int AI_ask_next_request(
    tag_t           ai,         /**< (I) */
    tag_t           cur_req,    /**< (I) Current requestobject */
    Request_type_t  type,       /**< (I) Type of request (sync/publish) */
    Request_state_t state,      /**< (I) */
    tag_t*          req         /**< (O) The next request object */
    );

extern AI_API int AI_remove_request_object(
    tag_t          ai,      /**< (I) */
    tag_t          req      /**< (I) */
    );

/**
    Given the search criteria, find all the AIs in the database
*/
extern AI_API int AI_find(
    AI_search_criteria_t* seach,    /**< (I) Search criteria for AI */
    int*                  num,      /**< (O) Number of AI found */
    tag_t**               ais       /**< (OF) num Tag list of AI */
    );

extern AI_API int AI_init_search(
    AI_search_criteria_t* seach     /**< (I) */
    );

extern AI_API int AI_ask_transfermode(
    tag_t           ai,     /**< (I) */
    PIE_direction_t type,   /**< (I) */
    tag_t*          tm      /**< (O) */
    );

extern AI_API int AI_set_transfermode(
    tag_t           ai,     /**< (I) */
    PIE_direction_t type,   /**< (I) */
    tag_t           tm      /**< (I) */
    );

extern AI_API int AI_ask_master_record(
    tag_t          ai,  /**< (I) */
    tag_t*         ma   /**< (O) */
    );

extern AI_API int AI_set_master_record(
    tag_t          ai,  /**< (I) */
    tag_t          ma   /**< (I) */
    );

extern AI_API int AI_ask_base_refs(
    tag_t          ai,      /**< (I) */
    int*           num,     /**< (O) */
    tag_t**        refs     /**< (OF) num */
    );

/*****************************************************************************
    * Description
    *   Set the input tags to base references ( the root objects used by this interface)
    *   If the tags are run time configured objects such as BOMLine, we need to
    *   persistant it.
    *
    *   If multiple BOMLines are input, we will just create one single private StructureContext
    *
    *   Note: it will reset the previous baserefs.
    *
    * Input:
    *   ref - tag of reference
    * Output:
    *
    *
    * Returns:
    *   status_t
    *
    * Side Effects:
    *   see Description
    *
    *****************************************************************************/
extern AI_API int AI_set_base_refs(
    tag_t          ai,      /**< (I) */
    int            num,     /**< (I) */
    tag_t*         refs     /**< (I) */
    );

extern AI_API int AI_add_base_ref(
    tag_t          ai,      /**< (I) */
    tag_t          ref      /**< (I) */
    );

/*****************************************************************************
    * Description
    *   Add the input tags to base references ( the root objects used by this interface)
    *   If the tags are run time configured objects such as BOMLine, we need to
    *   persistant it.
    *
    *   If multiple BOMLines are input, we will just create one single private StructureContext
    *
    * Input:
    *   ref - tag of reference
    * Output:
    *
    *
    * Returns:
    *   status_t
    *
    * Side Effects:
    *   see Description
    *
    *****************************************************************************/
extern AI_API int AI_add_base_refs(
    tag_t          ai,      /**< (I) */
    int            num,     /**< (I) */
    tag_t*         refs,     /**< (I) */
    int*            persistNum,  /**< (O) */
    tag_t**        persistObj   /**< (OF) */
    );

/** For Site id */
extern AI_API int AI_ask_site_id2(
    tag_t          ai,                  /**< (I) */
    char           **id                 /**< (OF) */
    );

extern AI_API int AI_set_site(
    tag_t          ai,      /**< (I) */
    tag_t          site     /**< (I) */
    );


/** For context */
extern AI_API int AI_ask_app_id2(
    tag_t          ai,                  /**< (I) */
    char           **id                 /**< (OF) */
    );

/** For project id */
extern AI_API int AI_ask_project_id2(
    tag_t          ai,                  /**< (I) */
    char           **id                 /**< (OF) */
    );

extern AI_API int AI_set_project_id(
    tag_t          ai,  /**< (I) */
    const char*    id   /**< (I) */
    );

/** For Master XML file */
extern AI_API int AI_ask_master_file(
    tag_t          ai,  /**< (I) */
    tag_t*         mf   /**< (O) */
    );

extern AI_API int AI_set_master_file(
    tag_t          ai,  /**< (I) */
    tag_t          mf   /**< (I) */
    );

/** @} */

/**
    @name Request Object related
    @{
*/

/**
    Process request:
    <ol>
    <li>Sync request: Generate XML file and save it to database.
    <li>Publish request: import using ECO.
    </ol>
*/
extern AI_API int AI_request_process(
    tag_t          req,     /**< (I) Request object tag */
    tag_t          eco      /**< (I) ECO object tag for incremental. It will be used for Publish request only */
    );

/**
    Ask whether we can process this request
*/
extern AI_API int AI_request_can_process(
    tag_t          req,     /**< (I) Request */
    logical*       ok       /**< (O) Whether ok or not */
    );

/** Export selected objects only */
extern AI_API int AI_request_process_partial(
    tag_t          req,         /**< (I) */
    int            num_obj,     /**< (I) */
    tag_t*         objs         /**< (I) */
    );

extern AI_API int AI_request_ask_type(
    tag_t          req,     /**< (I) */
    int*           type     /**< (O) */
    );

/** Ask for the scope, which is Whole/Partial */
extern AI_API int AI_request_ask_scope(
    tag_t          req,     /**< (I) */
    int*           scope    /**< (O) */
    );

extern AI_API int AI_request_set_scope(
    tag_t           req,    /**< (I) */
    Request_scope_t scope   /**< (I) */
    );

/** Ask for update type, which is Full/Delta */
extern AI_API int AI_request_ask_update_type(
    tag_t          req,     /**< (I) */
    int*           update   /**< (O) */
    );

/*Set for update type, which is Full/Delta*/
extern AI_API int AI_request_set_update_type
(
    tag_t             req,    /**< (I) */
    Request_update_t  update  /**< (I) */
);

extern AI_API int AI_request_ask_state(
    tag_t          req,     /**< (I) */
    int*           stat     /**< (O) */
    );

extern AI_API int AI_request_set_state(
    tag_t           req,    /**< (I) */
    Request_state_t stat    /**< (I) */
    );


extern AI_API int AI_request_ask_state_msg2(
    tag_t          req,                         /**< (I) */
    char           **stat_msg                   /**< (OF) */
    );

extern AI_API int AI_request_set_state_msg(
    tag_t          req,         /**< (I) */
    const char*    stat_msg     /**< (I) */
    );

extern AI_API int AI_request_ask_status(
    tag_t          req,     /**< (I) */
    int*           stat     /**< (O) */
    );

extern AI_API int AI_request_set_status(
    tag_t            req,   /**< (I) */
    Request_status_t stat   /**< (I) */
    );


extern AI_API int AI_request_ask_status_msg2(
    tag_t          req,                         /**< (I) */
    char           **stat_msg                   /**< (OF) */
    );

extern AI_API int AI_request_set_status_msg(
    tag_t          req,         /**< (I) */
    const char*    stat_msg     /**< (I) */
    );

extern AI_API int AI_request_ask_structure_file(
    tag_t            req,       /**< (I) */
    Request_update_t type,      /**< (I) */
    tag_t*           file       /**< (O) */
    );

extern AI_API int AI_request_set_structure_file(
    tag_t            req,       /**< (I) */
    Request_update_t type,      /**< (I) */
    tag_t            file       /**< (I) */
    );

extern AI_API int AI_request_ask_process_by(
    tag_t          req,     /**< (I) */
    tag_t*         user     /**< (O) */
    );

extern AI_API int AI_request_ask_process_on(
    tag_t          req,     /**< (I) */
    date_t*        date     /**< (O) */
    );

extern AI_API int AI_request_ask_owning_ai(
    tag_t          req,     /**< (I) */
    tag_t*         owner    /**< (O) */
    );

extern AI_API int AI_request_add_file_map(
    tag_t          req,         /**< (I) */
    const char*    fileRef,     /**< (I) */
    const char*    fileId       /**< (I) */
    );

/**
    Import the associated files (such as dataset file) to TC.
    If passed in ApplicationRef, it will be stored as PLMAppUID.
*/
extern AI_API int AI_request_import_file(
    tag_t          req,         /**< (I) */
    const char*    fName,       /**< (I) Full file path */
    const char*    fRefId,      /**< (I) File reference id, which can be either PLMXML element ID, or Application UID */
    int            fileType,    /**< (I) File type */
    const char*    appName,     /**< (I) Application name (optional) */
    const char*    siteId,      /**< (I) Application site id (optional) */
    const char*    version,     /**< (I) Version (optional) */
    tag_t*         fileTag      /**< (O) File tag after import */
    );

/** @} */

/**
    @name MasterRecord related
    @{
*/

/**
    Save all the records to Database. Need to call this after MasterRecord is modified.
*/
extern AI_API int AI_save_records(
    tag_t          ai   /**< (I) */
    );

/**
    Add or modify a record of an AI.
*/
extern AI_API int AI_add_record(
    tag_t          ai,          /**< (I) */
    const char*    objId,       /**< (I) Object UID to record */
    const char*    masterId,    /**< (I) Master UID (could be just the objID) */
    date_t         date,        /**< (I) Last processed date */
    tag_t*         record       /**< (O) The record of this object */
    );

extern AI_API int AI_ask_record(
    tag_t          ai,      /**< (I) */
    const char*    objId,   /**< (I) */
    tag_t*         record   /**< (O) */
    );

extern AI_API int AI_remove_record(
    tag_t          ai,      /**< (I) */
    const char*    objId    /**< (I) */
    );

/**
    Check the MasterRecord to see whether an Object is modified since last export.
    If this object is not recorded in MasterRecord, it is considered modified
*/
extern AI_API int AI_is_object_modified(
    tag_t          ai,          /**< (I) */
    const char*    objId,       /**< (I) Object UID */
    date_t         modDate,     /**< (I) modDate */
    logical*       modified     /**< (O) Modified */
    );

/** @} */

/** @} */

#ifdef __cplusplus
    }
#endif

/* ----------------------------------------------------------------------------------
                AppInterface Type related
-------------------------------------------------------------------------------------*/

/*****************************************************************************
* Description
*   Finds an AppInterface Type with specified name
*
* Input:
*   name - Name of new AIType
*
* Output:
*   typeTag - Tag of AIType
*
* Returns:
*
* Side Effects:
*   see Description
*
*****************************************************************************/
extern AI_API int AIType_find
(
    const char   *name,          /* (I) */
    tag_t        *type           /* (O) */
);

/*****************************************************************************
* Description
*   Returns isUsedForIDC logical flag on AppInterface type.
*
* Input:
*   aitype - AppInterface Type object tag
*
* Output:
*   status - TRUE/FALSE
*
* Returns:
*
* Side Effects:
*   see Description
*
*****************************************************************************/
extern AI_API int AIType_ask_is_used_for_idc
(
    tag_t        aitype,          /* (I) */
    logical*     status           /* (O) */
);

/*********************************************************************************
    Utility Funtion
**********************************************************************************/
/*****************************************************************************
* Description
*   Utility funtion to validate the PLMXML file, given a checking data file.
*   It will be able to check:
*       1) Total number of element:                Element ; Occurrence; 100
*       2) Total Number of attribute:              Attribute ; Occurrence ; linkedOccurrenceRef; 23
*       3) Check whether has require attribute:    Required ; Occurrence ; instancedRef
*
*   If any checking failes, will return failure. Checking result will be print to the log file
*
* Input:
*    char* plmxml_file,        PLMXML file full name
*    char *custom_fptr,        Customization file which contains the checking info
*    char *log_fptr,           Log file
*
*
* Output:
*    write the result to the log file
*    logical* failed     check failed or not
* Returns:
*
* Side Effects:
*   see Description
*
*****************************************************************************/

extern AI_API int AI_validate_plmxml
(
    char* plmxml_file,   /* (I) */
    char *custom_fptr,      /* (I) */
    char *log_fptr,      /* (I) */
    logical* failed       /* (O) */
);
extern AI_API int AI_request_find_by_ai_type(
    Request_type_t req_type, /* (I) */
    Request_state_t  state,  /* (I) */
    const char* ai_type,     /* (I) */
    int*  num,            /* (O) */
    tag_t **reqs             /* (OF) */
);

#include <ai/libai_undef.h>

#endif
