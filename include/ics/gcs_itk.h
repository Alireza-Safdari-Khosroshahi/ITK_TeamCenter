/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains the ITK function declarations for the GCS module
    (Guided Component Search)
*/

/*  */

#ifndef I_GCS_ITK_HXX
#define I_GCS_ITK_HXX

#include <pom/pom/pom.h>
#include <ics/ics_errors.h>
#include <ics/libics_exports.h>

/**
    @defgroup GCS Guided Component Search

    GCS accelearates and simplifies the build process of assemblies. Only matching components will be selectable.
    Before GCS can be used the administrator has to produce the GCS information that define what components
    match to what components. This ITK contains all functions to create this GCS information.

    You will use GCS ITK to:

    <UL>
    <LI>Create, modify, remove, read GCS Connection Types
    <LI>Create, modify, remove, read GCS Connection Point Definitions (add CPD to class, etc.)
    <LI>Create, update, remove, read GCS Connection Points
    <LI>Search for ICOs that match for a given ICO
    </UL>
    @{
*/


#ifdef __cplusplus
extern "C"{
#endif



/**
    @name Connection Type Functions (CT)
    @{
*/

/**
    This function returns the count and the IDs of all connection types that are defined in the GCS system.
*/
extern ICS_API int GCS_ct_ask
(int    *theCTCount,                     /**< (O) */
 tag_t **theCTTags                       /**< (OF) theCTCount */
);


/**
    This function returns the values (ID, name, attributes and comparison criteria) for a given connection type.
    @note theCTId, theCTName & theAttributeCount the must not be NULL pointers!
    @note If you don't want to retrieve theAttributeIds, theAttributeNames or theComparisonCriteria
          you can use NULL pointers as arguments there.
*/
extern ICS_API int GCS_ct_describe
(tag_t       theCTTag,                   /**< (I) */
 char      **theCTId,                    /**< (O) */
 char      **theCTName,                  /**< (O) */
 int        *theAttributeCount,          /**< (O) */
 int       **theAttributeIds,            /**< (OF) theAttributeCount */
 char     ***theAttributeNames,          /**< (OF) theAttributeCount */
 char     ***theComparisonCriteria       /**< (OF) theAttributeCount */
);


/**
    This function creates a new connection type and sets its values (name, attributes and comparison criteria).
*/
extern ICS_API int GCS_ct_create
(char       *theCTName,                  /**< (I) */
 int         theAttributeCount,          /**< (I) */
 int        *theAttributeIds,            /**< (I) */
 char      **theComparisonCriteria,      /**< (I) */
 tag_t      *theCTTag,                   /**< (O) */
 char      **theCTId                     /**< (OF) */
);


/**
    This function sets the values (name, attributes and comparison criteria) for a given, existing connection type.
*/
extern ICS_API int GCS_ct_set
(tag_t       theCTTag,                   /**< (I) */
 char       *theCTName,                  /**< (I) */
 int         theAttributeCount,          /**< (I) */
 int        *theAttributeIds,            /**< (I) */
 char      **theComparisonCriteria       /**< (I) */
);


/**
    This function removes a given connection type.
    @warning When you remove a CT with this function, all CPDs and CPs using this CT will be removed as well.
             This can have major consequences for the whole GCS system.
*/
extern ICS_API int GCS_ct_remove
(tag_t       theCTTag                    /**< (I) */
);


/**
    This function updates all CPDs and CPs that belong to the given connection type.
*/
extern ICS_API int GCS_ct_update
(tag_t       theCTTag                    /**< (I) */
);

/**
    This function updates all CPDs and CPs that belong to the given connection type.
    It also creates or updates the ICO's associated item, item revision, and
    PSConnection, if requested by setting theCreateWsos to true.
*/
extern ICS_API int GCS_ct_update_wsos
(tag_t   theCTTag,                       /**< (I) */
 logical theCreateWsos                   /**< (I) */
);

/**
    This function returns all classes and CPDs that are using a given connection type.
*/
extern ICS_API int GCS_ct_where_referenced
(tag_t        theCTTag,                  /**< (I) */
 int         *theClassCount,             /**< (O) */
 char      ***theClassIDs,               /**< (OF) theClassCount */
 tag_t      **theClassTags,              /**< (OF) theClassCount */
 int         *theCPDCount,               /**< (O) */
 tag_t      **theCPDTags                 /**< (OF) theCPDCount */
);


/**
    This function returns the CT tag for a given CT name.
*/
extern ICS_API int GCS_ct_ask_tag_for_name
(const char* theCTName,                  /**< (I) */
 tag_t*      theCTTag                    /**< (O) */
);

/** @} */

/**
    @name Connection Point Definition (for classes) Functions (CPD)
    @{
*/

/**
    This function returns all connection point definitions that are defined for a given component class.
*/
extern ICS_API int GCS_cpd_ask
(tag_t        theComponentClassTag, /**< (I) */
 int         *theCPDCount,          /**< (O) */
 tag_t      **theCPDTags            /**< (OF) theCPDCount */
);


/**
    This function returns the values (component class, CT, CPD index, CP quantity, direction, physical shape (socket or plug)
    and attribute mapping) for a given connection point definition.
*/
extern ICS_API int GCS_cpd_describe
(tag_t   theCPDTag,           /**< (I) */
 tag_t  *theClassTag,         /**< (O) */
 tag_t  *theCTTag,            /**< (O) */
 int    *theCPDIndex,         /**< (O) */
 char  **theCPQuantity,       /**< (O) */
 char  **theDirection,        /**< (O) */
 char  **theShape,            /**< (O) */
 int    *theAttributeCount,   /**< (O) */
 int   **theAttributeIds,     /**< (OF) theAttributeCount */
 char ***theAttributeMappings /**< (OF) theAttributeCount */
 );


/**
    This function adds a connection point definition to a given class, sets its
    values (CT, CPD index, CP quantity, direction, physical shape and attribute
    mapping), and returns the tag of the new connection point definition.
    It also creates or updates the associated connection points, and creates or
    updates items, item revisions, and PSConnections pertaining to their
    associated component ICOs.
*/
extern ICS_API int GCS_cpd_add
(tag_t   theClassTag,         /**< (I) */
 tag_t   theCTTag,            /**< (I) */
 int     theCPDIndex,         /**< (I) */
 char   *theCPQuantity,       /**< (I) */
 char   *theDirection,        /**< (I) */
 char   *theShape,            /**< (I) */
 int     theAttributeCount,   /**< (I) */
 int    *theAttributeIds,     /**< (I) theAttributeCount */
 char  **theAttributeMappings,/**< (I) theAttributeCount */
 tag_t  *theCPDTag            /**< (O) */
);


/**
    This function adds a connection point definition to a given class, sets its
    values (CT, CPD index, CP quantity, direction, physical shape and attribute
    mapping), and returns the tag of the new connection point definition.
    It also creates or updates the associated connection points, and creates or
    updates items, item revisions, and PSConnections pertaining to their
    associated component ICOs, if this was requested by setting theCreateWsos
    to true.
*/
extern ICS_API int GCS_cpd_add_wsos
(tag_t     theClassTag,         /**< (I) */
 tag_t     theCTTag,            /**< (I) */
 int       theCPDIndex,         /**< (I) */
 char     *theCPQuantity,       /**< (I) */
 char     *theDirection,        /**< (I) */
 char     *theShape,            /**< (I) */
 int       theAttributeCount,   /**< (I) */
 int      *theAttributeIds,     /**< (I) theAttributeCount */
 char    **theAttributeMappings,/**< (I) theAttributeCount */
 logical   theCreateWsos,       /**< (I) */
 tag_t  *theCPDTag            /**< (O) */
);


/**
    This function sets the values (component class, CT, CPD index, CP quantity,
    direction, physical shape and attribute mapping) for a given, existing
    connection point definition.  It also creates or updates the associated
    connection points, and creates or updates items, item revisions, and
    PSConnections pertaining to their associated component ICOs.
*/
extern ICS_API int GCS_cpd_set
(tag_t   theCPDTag,           /**< (I) */
 tag_t   theClassTag,         /**< (I) */
 tag_t   theCTTag,            /**< (I) */
 int     theCPDIndex,         /**< (I) */
 char   *theCPQuantity,       /**< (I) */
 char   *theDirection,        /**< (I) */
 char   *theShape,            /**< (I) */
 int     theAttributeCount,   /**< (I) */
 int    *theAttributeIds,     /**< (I) theAttributeCount */
 char  **theAttributeMappings /**< (I) theAttributeCount */
 );


/**
    This function sets the values (component class, CT, CPD index, CP quantity,
    direction, physical shape and attribute mapping) for a given, existing
    connection point definition.  It also creates or updates the associated
    connection points, and creates or updates items, item revisions, and
    PSConnections pertaining to their associated component ICOs, if requested
    by setting theCreateWsos to true.
*/
extern ICS_API int GCS_cpd_set_wsos
(tag_t     theCPDTag,            /**< (I) */
 tag_t     theClassTag,          /**< (I) */
 tag_t     theCTTag,             /**< (I) */
 int       theCPDIndex,          /**< (I) */
 char     *theCPQuantity,        /**< (I) */
 char     *theDirection,         /**< (I) */
 char     *theShape,             /**< (I) */
 int       theAttributeCount,    /**< (I) */
 int      *theAttributeIds,      /**< (I) theAttributeCount */
 char    **theAttributeMappings, /**< (I) theAttributeCount */
 logical   theCreateWsos         /**< (I) */
);


/**
    This function removes a given connection point definition.
    @warning When you remove a CPD with this function, all CPs for this CPD will be removed as well.
             This can have major consequences for the whole GCS system.
*/
extern ICS_API int GCS_cpd_remove
(tag_t theCPDTag              /**< (I) */
);


/**
    This function updates (and creates if needed) all connection points (CPs) for a given connection point definition (CPD).
    It also creates or updates the associated connection points, and creates or updates items, item revisions, and
    PSConnections pertaining to their associated component ICOs.
*/
extern ICS_API int GCS_cpd_update
(tag_t   theCPDTag            /**< (I) */
);


/**
    This function updates (and creates if needed) all connection points (CPs) for a given connection point definition (CPD).
    It also creates or updates the associated connection points, and creates or updates items, item revisions, and
    PSConnections pertaining to their associated component ICOs, if requested by setting theCreateWsos to true.
*/
extern ICS_API int GCS_cpd_update_wsos
(tag_t   theCPDTag,           /**< (I) */
 logical   theCreateWsos      /**< (I) */
);


/**
    This function returns all connection points and ICOs using a given connection point definition.
*/
extern ICS_API int GCS_cpd_ask_instances
(tag_t   theCPDTag,           /**< (I) */
 int    *theCPCount,          /**< (O) */
 tag_t **theCPTags,           /**< (OF) theCPCount */
 tag_t **theICOTags           /**< (OF) theCPCount */
);

/** @} */

/**
    @name Connection Point Functions (CP)
    @{
*/

/**
    This function returns all connection points for a given ICO.
*/
extern ICS_API int GCS_cp_ask
(tag_t   theICOTag,          /**< (I) */
 int    *theCPCount,         /**< (O) */
 tag_t **theCPTags           /**< (OF) theCPCount */
);


/**
    This function returns the values (component ICO, CPD, CT, CPD index, CP index, direction, shape and
    attribute values) for a given connection point.
*/
extern ICS_API int GCS_cp_describe
(tag_t   theCPTag,           /**< (I) */
 tag_t  *theComponentTag,    /**< (O) */
 tag_t  *theCPDTag,          /**< (O) */
 tag_t  *theCTTag,           /**< (O) */
 int    *theCPDIndex,        /**< (O) */
 int    *theCPIndex,         /**< (O) */
 char  **theDirection,       /**< (O) */
 char  **theShape,           /**< (O) */
 int    *theAttributeCount,  /**< (O) */
 int   **theAttributeIds,    /**< (OF) theAttributeCount */
 char ***theAttributeValues  /**< (OF) theAttributeCount */
);


/**
This function returns the values (CP, component ICO, CPD, CT, CPD index, CP index, direction, shape and attribute values) for a given connection point occurrence.
*/
extern ICS_API int GCS_cp_ask_cp_of_occ
(tag_t   theOccurrenceTag,   /**< (I)  */
 tag_t  *theCPTag,           /**< (O)  */
 tag_t  *theComponentTag,    /**< (O)  */
 tag_t  *theCPDTag,          /**< (O)  */
 tag_t  *theCTTag,           /**< (O)  */
 int    *theCPDIndex,        /**< (O)  */
 int    *theCPIndex,         /**< (O)  */
 char  **theDirection,       /**< (O)  */
 char  **theShape,           /**< (O)  */
 int    *theAttributeCount,  /**< (O)  */
 int   **theAttributeIds,    /**< (OF) theAttributeCount */
 char ***theAttributeValues  /**< (OF) theAttributeCount */
);


/**
    This function creates all connection points for a given ICO.
*/
extern ICS_API int GCS_cp_create_for_ICO
(tag_t   theICOTag           /**< (I) */
);


/**
    This function creats the connection point for a given ICO corresponding to the given CPD.
*/
extern ICS_API int GCS_cp_create_for_ICO_and_CPD
(tag_t   theICOTag,          /**< (I) */
 tag_t   theCPDTag           /**< (I) */
);


/**
    This function updates a given connection point (CP).
*/
extern ICS_API int GCS_cp_update
(tag_t   theCPTag            /**< (I) */
);


/**
    This function updates all connection points for a given ICO.
*/
extern ICS_API int GCS_cp_update_for_ICO
(tag_t   theICOTag           /**< (I) */
);


/**
    This function updates the connection point for a given ICO that corresponds to the given CPD.
*/
extern ICS_API int GCS_cp_update_for_ICO_and_CPD
(tag_t   theICOTag,          /**< (I) */
 tag_t   theCPDTag           /**< (I) */
);


/**
    This function removes a given connection point.
*/
extern ICS_API int GCS_cp_remove
(tag_t   theCPTag            /**< (I) */
);


/**
    This function removes all connection points for a given ICO.
*/
extern ICS_API int GCS_cp_remove_for_ICO
(tag_t   theICOTag           /**< (I) */
);

/** @} */

/**
    @name General GCS Functions
    @{
*/

/**
    This function initializes the database for GCS usage.
    It creates all needed Attributes, Key LOVs, Classes.
    If those elements are already there it does nothing.
*/
extern ICS_API int GCS_init_module();


/**
    This function searches for all matching CPs and the attached comp ICOs for a given CP.
*/
extern ICS_API int GCS_search
(tag_t   theCPTag,           /**< (I) */
 int    *theMatchingCount,   /**< (O) */
 tag_t **theMatchingCPTags,  /**< (OF) theMatchingCount */
 tag_t **theMatchingICOTags  /**< (OF) theMatchingCount */
);


/**
    This function searches for all matching CPs, ICOs and classes (including parents) containing those ICOs for a given CP.
*/
extern ICS_API int GCS_class_search
(tag_t   theCPTag,           /**< (I) */
 int    *theCPCount,         /**< (O) */
 tag_t **theCPTags,          /**< (OF) theCPCount */
 int    *theICOCount,        /**< (O) */
 tag_t **theICOTags,         /**< (OF) theICOCount */
 int    *theClassCount,      /**< (O) */
 char ***theClassIDs         /**< (OF) theClassCount */
);


/**
    This function searches for all matching CPs, ICOs and classes (including parents) containing those ICOs for a given occurrence.
*/
extern ICS_API int GCS_class_search_by_occ
(tag_t   theOccurrenceTag,   /**< (I) */
 int    *theCPCount,         /**< (O) */
 tag_t **theCPTags,          /**< (OF) theCPCount */
 int    *theICOCount,        /**< (O) */
 tag_t **theICOTags,         /**< (OF) theICOCount */
 int    *theClassCount,      /**< (O) */
 char ***theClassIDs         /**< (OF) theClassCount */
);

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#include <ics/libics_undef.h>

#endif /* I_GCS_ITK_HXX */
