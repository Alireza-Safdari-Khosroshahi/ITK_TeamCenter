//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2012.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    This file contains ITK function declarations for Fnd0nweditor.
*/


#ifndef FND0NWEDITOR_H
#define FND0NWEDITOR_H
#include <unidefs.h>

#include <Fnd0nweditor/libfnd0nweditor_exports.h>

//----------------------------------------------------------------------------
#ifdef __cplusplus
    extern "C"{
#endif

/**
This function creates a Diagram object for the selected object. The objects shown on the diagram
follow the relationship rules and membership rules selected on the diagram template.
*/
extern FND0NWEDITOR_API int FND0NWEDITOR_create_diagram
(
    tag_t  selectedObj,                 /**< (I) Selected/Starting/Root object of the diagram (BusinessObjectRef<Teamcenter::BusinessObject>)  */
    int numNames,                       /**< (I) Number of property names  */
    char**  names,                      /**< (I) Property Names  */
    int numValues,                      /**< (I) Number of property values  */
    char**  values,                     /**< (I) Property Values  */
    logical openDiagram,                /**< (I) Whether to open diagram or not  */
    char ** appDomain,                  /**< (O) Application domain of this diagram  */
    int * numTmplFilePaths,             /**< (O) Number of template files  */
    char *** diagramTmplFilePaths,      /**< (O) numTmplFilePaths File paths of the stencil and template files */
    char ** diagMappingFilePath,        /**< (O) File path of the Diagram mapping file */
    tag_t * diagramRev,                 /**< (O) Rev tag for new diagram created  */
    int * numDiagramMem,                /**< (O) count of memebers  */
    tag_t ** diagramMembersPrimary,     /**< (O) numDiagramMem List of diagram members */
    tag_t ** diagramMembersPersistent,  /**< (O) numDiagramMem List of persistent objects of the diagram members */
    char *** typeNames,                 /**< (O) numDiagramMem List of type names of diagram members */
    int * numRelationMembers,           /**< (O) count of relations  */
    tag_t ** relationMembers            /**< (O) numRelationMembers List of relation objects between diagram members */
  );


/**
This function saves a Diagram dataset.
*/
extern FND0NWEDITOR_API int FND0NWEDITOR_save_diagram
(
    tag_t   selectedObj,                /**< (I) Selected/Starting/Root object of the diagram (BusinessObjectRef<Teamcenter::BusinessObject>)  */
    tag_t   diagramRevisionTag,         /**< (I) Diagram Revision tag (NULLTAG is NOT allowed) */
    char*   fms_diagramTicket,          /**< (I) FMS ticket to the diagram file */
    char*   fms_diagramImageTicket,     /**< (I) FMS ticket to the diagram Image file(JPEG or PNG) */
    int *   numResultObjs,              /**< (O) Number of result objects */
    tag_t ** resultObjs                 /**< (O) numResultObjs Result objects */
);


/**
This function opens a Diagram created for the selected object.
*/

extern FND0NWEDITOR_API int FND0NWEDITOR_open_diagram
(
    tag_t   selectedObj,                    /**< (I) Selected/Starting/Root object of the diagram (BusinessObjectRef<Teamcenter::BusinessObject>)  */
    tag_t   diagram_revision,               /**< (I) Diagram for the selection */
    int*    n_template_tickets,             /**< (O) The number of diagram templates */
    char***  fms_template_tickets,          /**< (O) n_template_tickets The diagram templates  */
    char**   diagMappingFileTicket,         /**< (O) The diagram Mapping file  */
    char**   diagramFileTicketStr,          /**< (O) The diagram */
    char ** appDomain,                      /**< (O) The Application Domain for the diagram  */
    tag_t * startObjectTag,                 /**< (O) Root object for the Diagram  */
    int * numObjectUIDs,                    /**< (O) Number of object UIDs  */
    char *** objectUIDsStr,                 /**< (O) numObjectUIDs Object UIDs  */
    int ** shapeIDsInt,                     /**< (O) Shape IDs  */
    int * numDiagramMem,                    /**< (O) Number of Diagram Members  */
    tag_t ** DiagramMembersTagsPrimary,     /**< (O) numDiagramMem Diagram Tags Primary  */
    tag_t ** DiagramMembersTagsPersistent,  /**< (O) numDiagramMem Diagram Tags Persistent  */
    char *** typeNamesStr,                  /**< (O) numDiagramMem Type Names for Diagram Members  */
    tag_t ** shapeRelationsOnMembers,       /**< (O) numDiagramMem Shape relations for Diagram Memebers  */
    int * numRelationMembers,               /**< (O) Number of Relation Members  */
    tag_t ** RelationMembersTags,           /**< (O) numRelationMembers Relation Member tags  */
    tag_t ** shapeRelationsOnRelationsTags  /**< (O) numRelationMembers Shape Relations on relation tags  */
    );



/**
This function creates or updates a diagram template.
*/
extern FND0NWEDITOR_API int FND0NWEDITOR_create_or_update_template
(
    tag_t revTag,                    /**< (I) Revision Tag */
    int numNames,                    /**< (I) count of property names */
    char**  names,                   /**< (I) Names of properties */
    int numValues,                   /**< (I) Count of property values */
    char**  values,                  /**< (I) Values for properties */
    logical isAvailable,             /**< (I) Is this template available */
    int numStencilFilePaths,         /**< (I) Number of stencil files to import */
    char ** tmplStencilFilePaths,    /**< (I) Collection of FMS tickets to diagramming tool specific stencil/template files */
    char * tmplMappingFilePath,      /**< (I) FMS ticket to property map xml file */
    tag_t membershipRule,            /**< (I) Membership Rule */
    int numRelationRule,             /**< (I) Number of Relations in the Relationship Rule */
    char ** relationRule,            /**< (I) Relationship Rules */
    logical hidePorts,               /**< (I) Flag to indicate whether ports have to be shown for diagrams using this template*/
    tag_t * diagramTmplRev           /**< (O) Diagram Template Revision Object*/
);

#ifdef __cplusplus
}
#endif

/** @} */

#include <Fnd0nweditor/libfnd0nweditor_undef.h>
#endif



