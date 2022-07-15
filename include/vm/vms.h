/*=======================================================================================

                             Copyright (c) 2007 UGS Corporation
                             Unpublished - All rights reserved

=========================================================================================

File description:

    Filename: vms.h
    Module  : Vendor Management (vm)
    Description:

       This file contains declaration of ITK functions corresponding to Vendor,
       BidPackage classes for Vendor Management Module.


=========================================================================================
   Date                   Name                    Description of Change
   23-Feb-2007            M.Ram Narsimhamurty     Initial Version
   23-Feb-2007            Ram Kishore             Initial Version
   15-Apr-2007            Ram Kishore             Added prototypes for Vendor Part APIs
   04-Apr-2008            Ram Kishore             Added prototypes for Vendor,BidPackage,ManufacturerPart
                                                  APIs for creation with master forms
   14-jun-2008            Srinivas Pendyala       Added extra param to VMS_change_vendor to fix webitkbindings                                                  APIs for creation with master forms
   11-Aug-2008            Srinivas Pendyala       Add new API VMS_create_bidpackage_lineitem_with_type
   23-Feb-2009            Chris Scheffer          Added VMS_create_vendor_with_type
   20-Jun-2012            godbole                 Changes to deprecate VMS_init_module
$HISTORY$
=======================================================================================*/

#ifndef VMS_H
#define VMS_H

#include <unidefs.h>
#include <vm/libvm_exports.h>
#define VMS_external_id_size_c 32

#ifdef __cplusplus
    extern "C"{
#endif


/**
    ITK function to create a new Vendor
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_vendor(
                                       const char *vendorId,       /* <I> */
                                       const char *name,           /* <I> */
                                       const char *revId,          /* <I> */
                                       int no_of_roles,            /* <I> */
                                       tag_t   *vendor_role,       /* <I> */
                                       tag_t   *new_vendor,        /* <O> */
                                       tag_t   *new_vendor_rev     /* <O> */
                                   );


/**
    ITK function to create a new Vendor with a specified type
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_vendor_with_type(
                                       const char *vendorId,       /* <I> */
                                       const char *name,           /* <I> */
                                       const char *revId,          /* <I> */
                                       const char *type_name,      /* <I> */
                                       int no_of_roles,            /* <I> */
                                       tag_t   *vendor_role,       /* <I> */
                                       tag_t   *new_vendor,        /* <O> */
                                       tag_t   *new_vendor_rev     /* <O> */
                                   );


/**
    ITK function to create a new Vendor with Master forms
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_vendor_with_masters(
                                                    const char *vendorId,           /* <I> */
                                                    const char *name,               /* <I> */
                                                    const char *revId,              /* <I> */
                                                    const char *type_name,          /* <I> */
                                                    int no_of_roles,                /* <I> */
                                                    tag_t   *vendor_role,           /* <I> */
                                                    tag_t   vendor_master_tag,      /* <I> */
                                                    tag_t   vendor_rev_master_tag,  /* <I> */
                                                    tag_t   *new_vendor,            /* <O> */
                                                    tag_t   *new_vendor_rev         /* <O> */
                                                );

/**
    ITK function to find a Vendor
*/

extern VM_API int VMS_find_vendor(
                                     const char *vendorId,        /* <I> */
                                     tag_t* ventag                /* <O> */
                                 );

/**
    ITK function to create a VendorRevision for a Vendor
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_vendor_rev(
                                           tag_t vendor ,        /* <I> */
                                           const char *rev_id,   /* <I> */
                                           int no_of_roles,      /* <I> */
                                           tag_t *vendor_role,   /* <I> */
                                           tag_t *rev            /* <O> */
                                       );

/**
    ITK function to create a VendorRole
*/

extern VM_API int VMS_create_vendor_role(
                                            const char *role_name,       /* <I> */
                                            const char *role_desc,       /* <I> */
                                            tag_t      *vendor_role      /* <O> */
                                        );

/**
    ITK function to add a list of VendorRoles to a VendorRevision
*/

extern VM_API int VMS_add_vendor_roles(
                                          tag_t vrev,       /* <I> */
                                          int no_of_roles,  /* <I> */
                                          tag_t* vroles     /* <I> */
                                      );

/**
    ITK function to get a list of VendorRoles for a VendorRevision
*/

extern VM_API int VMS_get_vendor_roles(
                                          tag_t vrev,       /**< (I)  Tag of the selected vendor revision */
                                          int* no_of_roles, /**< (O)  number of vendor roles for the vendor revision */
                                          tag_t** vroles    /**< (OF) no_of_roles Array of related vendor roles */
                                      );

/**
    ITK function to remove a list of VendorRoles from a VendorRevision
*/

extern VM_API int VMS_remove_vendor_roles(
                                             tag_t vrev,       /* <I> */
                                             int no_of_roles,  /* <I> */
                                             tag_t* vroles     /* <I> */
                                         );

/**
    ITK function to Copy a Vendor
*/
/*-----------------------------------------------------------------------------*/

extern VM_API int VMS_copy_vendor(
                                    tag_t      old_rev,        /* <I> */
                                    const char *new_vendor_id, /* <I> */
                                    const char *new_rev_id,    /* <I> */
                                    tag_t      *new_vendor,    /* <O> */
                                    tag_t      *new_rev        /* <O> */
                                 );

/**
    ITK function to Copy a VendorRevision
*/
/*-----------------------------------------------------------------------------*/

extern VM_API int VMS_copy_vendor_rev(
                                         tag_t      old_rev,        /* <I> */
                                         const char *new_rev_id,    /* <I> */
                                         tag_t      *new_rev        /* <O> */
                                     );

/**
    ITK function to delete a Vendor
*/

extern VM_API int VMS_delete_vendor(
                                       tag_t vendor       /* <I> */
                                   );

/**
    ITK function to delete a VendorRevision
*/

extern VM_API int VMS_delete_vendor_rev(
                                           tag_t vrev       /* <I> */
                                       );

/**
    ITK function to create a BidPackage
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_bidpackage(
                                           const char *bpId,       /* <I> */
                                           const char *name,       /* <I> */
                                           const char *bprevId,    /* <I> */
                                           tag_t *new_bp,          /* <O> */
                                           tag_t *new_bp_rev       /* <O> */
                                       );


/**
    ITK function to create a BidPackage with Masters
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_bidpackage_with_masters(
                                                        const char *bpId,        /* <I> */
                                                        const char *name,        /* <I> */
                                                        const char *type_name,   /* <I> */
                                                        const char *bprevId,     /* <I> */
                                                        tag_t bp_master_tag,     /* <I> */
                                                        tag_t bp_rev_master_tag, /* <I> */
                                                        tag_t *new_bp,           /* <O> */
                                                        tag_t *new_bp_rev        /* <O> */
                                                    );

/**
    ITK function to create a BidPackageRevision
    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/

extern VM_API int VMS_create_bidpackage_rev(
                                               tag_t bpckg_tag,       /* <I> */
                                               const char *rev_id,    /* <I> */
                                               tag_t *rev             /* <O> */
                                           );

/**
    ITK function to Copy a BidPackage
*/
/*-----------------------------------------------------------------------------*/

extern VM_API int VMS_copy_bidpackage(
                                         tag_t      old_rev,        /* <I> */
                                         const char *new_bpckg_id, /* <I> */
                                         const char *new_rev_id,    /* <I> */
                                         tag_t      *new_bpckg,    /* <O> */
                                         tag_t      *new_rev        /* <O> */
                                     );

/**
    ITK function to Copy a BidPackageRevision
*/
/*-----------------------------------------------------------------------------*/

extern VM_API int VMS_copy_bidpackage_rev(
                                             tag_t      old_rev,        /* <I> */
                                             const char *new_rev_id,    /* <I> */
                                             tag_t      *new_rev        /* <O> */
                                         );


/**
    ITK function to create a BidPackageLineItem
*/

extern VM_API int VMS_create_bidpackage_lineitem(
                                                    const char *name,       /* <I> */
                                                    const char *desc,       /* <I> */
                                                    tag_t part,             /* <I> */
                                                    tag_t cc,               /* <I> */
                                                    double quantity,        /* <I> */
                                                    tag_t *new_bpl_tag      /* <O> */
                                                );

/**
    ITK function to create a BidPackageLineItem of specified type.
*/

extern VM_API int VMS_create_bidpackage_lineitem_with_type(
                                                              const char *name,       /* <I> */
                                                              const char *desc,       /* <I> */
                                                              tag_t part,             /* <I> */
                                                              tag_t cc,               /* <I> */
                                                              double quantity,        /* <I> */
                                                              const char*  bpli_type_name,  /* <I> */
                                                              tag_t *new_bpl_tag      /* <O> */
                                                          );

/**
    ITK function to add a list of BidPackageLineItem to BidPackageRevsision
*/

extern VM_API int VMS_add_bidpackage_lineitems(
                                                  tag_t bidpackagerev,       /* <I> */
                                                  int no_of_lineitems,       /* <I> */
                                                  tag_t *lineitems           /* <I> */
                                              );
/**
    ITK function to remove a list of BidPackageLineItems for a BidPackageRevision
*/

extern VM_API int VMS_remove_bidpackage_lineitems(
                                                     tag_t bidpackagerev,       /* <I> */
                                                     int no_of_lineitems,       /* <I> */
                                                     tag_t* lineitem            /* <I> */
                                                 );

/**
    ITK function to get a list of BidPackageLineItems for a BidPackageRevision
*/


extern VM_API int VMS_get_bidpackage_lineitems(
                                                  tag_t bidpackagerev,  /**< (I)  Tag of the selected bidpackage revision */
                                                  int* no_of_lineitems, /**< (O)  number of lineitems for the bidpackage revision */
                                                  tag_t** lineitems     /**< (OF) no_of_lineitems Array of related lineitems */
                                              );

/**
    ITK function to delete a BidPackage
*/

extern VM_API int VMS_delete_bidpackage(
                                           tag_t bidpckg       /* <I> */
                                       );

/**
    ITK function to delete a BidPackageRevision
*/

extern VM_API int VMS_delete_bidpackage_rev(
                                               tag_t bidpckgrev       /* <I> */
                                           );

/**
    ITK function to create a LineItemConfigurationContext
*/

extern VM_API int VMS_create_lineitemcc(
                                           const char* name,       /* <I> */
                                           const char* desc,       /* <I> */
                                           tag_t rev_rule,         /* <I> */
                                           tag_t variant_rule,     /* <I> */
                                           tag_t closure_rule,     /* <I> */
                                           tag_t view_type_tag,    /* <I> */
                                           tag_t *licc_tag         /* <O> */
                                       );

/**
    ITK function to add a LineItemConfigurationContext to BidPackageLineItem
*/

extern VM_API int VMS_add_lineitemcc(
                                        tag_t licc_tag,       /* <I> */
                                        tag_t bpl_tag         /* <I> */
                                    );

/**
    ITK function to crete a Quote
*/

extern VM_API int VMS_create_quote(
                                      const char *name,       /* <I> */
                                      const char *desc,       /* <I> */
                                      tag_t *quote_tag        /* <O> */
                                  );

/**
    ITK function to add a Quote to bidpackagelineitem as a "TC_part_quote_rel" relation
*/

extern VM_API int VMS_add_Quote(
                                   tag_t quote,       /* <I> */
                                   tag_t bpli         /* <I> */
                               );

/**
    ITK function to create a CommercialPart
*/

extern VM_API int VMS_create_commercial_part(
                                         const char *partId,            /* <I> */
                                         const char *desc,              /* <I> */
                                         const tag_t uom,               /* <I> */
                                         const char *partName,          /* <I> */
                                         const char *typeName,          /* <I> */
                                         const char *revId,             /* <I> */
                                         const logical isDesignReq,     /* <I> */
                                         const int makebuy,             /* <I> */
                                         tag_t vendor,                  /* <I> */
                                         tag_t *commercialpart,         /* <O> */
                                         tag_t *commercialpartrev       /* <O> */
                                     );

/**
    ITK function to create a ManufacturerPart
*/

extern VM_API int VMS_create_manufacturer_part(
                                                  const char *partId,            /* <I> */
                                                  const char *desc,              /* <I> */
                                                  const tag_t uom,               /* <I> */
                                                  const char *partName,          /* <I> */
                                                  const char *typeName,          /* <I> */
                                                  const char *revId,             /* <I> */
                                                  const logical isDesignReq,     /* <I> */
                                                  const int makebuy,             /* <I> */
                                                  tag_t vendor ,                 /* <I> */
                                                  tag_t commercialpart ,         /* <I> */
                                                  tag_t commercialpartrev ,      /* <I> */
                                                  tag_t *manufacturerpart,       /* <O> */
                                                  tag_t *manufacturerpartrev     /* <O> */
                                              );

/**
    ITK function to create a ManufacturerPart with Master Forms
*/

extern VM_API int VMS_create_manufacturer_part_with_masters(
                                                               const char *partId,            /* <I> */
                                                               const char *desc,              /* <I> */
                                                               const tag_t uom,               /* <I> */
                                                               const char *partName,          /* <I> */
                                                               const char *typeName,          /* <I> */
                                                               const char *revId,             /* <I> */
                                                               const logical isDesignReq,     /* <I> */
                                                               const int makebuy,             /* <I> */
                                                               tag_t vendor ,                 /* <I> */
                                                               tag_t commercialpart ,         /* <I> */
                                                               tag_t commercialpartrev ,      /* <I> */
                                                               tag_t mfgpartmaster ,          /* <I> */
                                                               tag_t mfgpartrevmaster ,       /* <I> */
                                                               tag_t *manufacturerpart,       /* <O> */
                                                               tag_t *manufacturerpartrev     /* <O> */
                                                           );

/**
    ITK function to add a ManufacturerPart to a CommercialPart
*/

extern VM_API int VMS_add_mfg_part_to_comm_part(
                                                   const char *idfrid,            /* <I> */
                                                   const char *idfrname,          /* <I> */
                                                   tag_t commercialpart,          /* <I> */
                                                   tag_t commercialpartrev ,      /* <I> */
                                                   tag_t manufacturerpart,        /* <I> */
                                                   tag_t vendor                   /* <I> */
                                               );


/**
    ITK function to generate an item_id based on the input IDs.
    It also returns an object tag if there is a pre-existing item with that ID.
*/

extern VM_API int VMS_get_ID_with_Context
(
    const char *objectID,          /* <I> */
    const char *contextID,         /* <I> */
    char **itemID,                 /* <O> */
    tag_t *existingObject          /* <O> */
);

extern VM_API int  VMS_get_vpsr_condition_entries(
                                                  int* condCount,       /**< (O)  number of conditions found */
                                                  tag_t** condTags      /**< (OF) condCount Array of conditions */
                                                 );



extern VM_API int  VMS_get_vendor_parts_w_sel_rule(
                                     tag_t commPartRev,   /**< (I)  Input commercial part revision */
                                     const char *conditionName, /**< (I)  name of condition to use to filter vendor part (may be NULL) */
                                     int *tagCount,       /**< (O)  number of vendor parts */
                                     tag_t **vpTags,      /**< (OF) tagCount related vendor parts */
                                     tag_t **relTags      /**< (OF) tagCount relations */
                                     );

/**
    ITK function for change Vendor
*/
extern VM_API int VMS_change_vendor(
                                     tag_t    old_vendor_to_change,  /**< (I)  Old vendor to change       */
                                     tag_t*   vendor_parts,          /**< (I)  Old vendor parts to change */
                                     tag_t    new_vendor,            /**< (I)  New vendor to associate    */
                                     int      n_vparts_supplied,     /**< (I)  n_vparts_supplied          */
                                     int*     n_vparts,              /**< (O)  Number of values returned  */
                                     char***  old_part_ids,          /**< (OF) n_vparts of old_part_ids   */
                                     char***  new_part_ids,          /**< (OF) n_vparts of new_part_ids   */
                                     char***  notes                  /**< (OF) n_vparts of notes          */
                                    );
/** Checks if the access license exists for the Supplier Relationship  Management (SRM) Exchange
    @returns      
    <ul>
    <li>#ITK_ok always
    </ul> 
 */
extern VM_API int VMS_access_license_exist(
        logical *exists                   /**< (O) True if the Access license exists */
);

/** Registers the Business Object for the Supplier Relationship  Management (SRM) Exchange license.
    @returns      
    <ul>
    <li>#ITK_ok on success
    <li>#METAFRAMEWORK_invalid_BusinessObject if a BusinessObject does not exist with the given value of the parameter @p interface_name
    <li>#METAFRAMEWORK_license_key_already_registered if the license key is already registered
    </ul> 
 */
extern VM_API int VMS_register_license(
        const char* interface_name         /**< (I) The business object name */
);

/**
    Creates Vendor Representation relation between Commercial Part Revision and Vendor Part.
    <br>This function also updates the value of preferred status attribute on the Vendor Representation relation.

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>Potentially other errors
    </ul>    
*/
extern VM_API int VMS_relate_vendor_part_to_comm_part(
    tag_t           comm_part,                  /**< (I)  The tag of the Commercial Part Revision */
    tag_t           vendor_part,                /**< (I)  The tag of the Vendor Part */
    const char*     pref_status,                /**< (I)  The value of preferred status of the Vendor Part for the given Commercial Part. Valid values are Preferred and Backup. */
    tag_t*          representation_relation     /**< (OF) The tag of the created relation of type Vendor Representation */
    );

/**
    Creates a Manufacturer Part (Vendor Part).

    @returns
    <ul>
    <li>#ITK_ok on success
    <li>#VMS_invalid_null_tag if @p vendor is either invalid or #NULLTAG.
    <li>#VMS_invalid_location_for_vendor_part if @p company_location is not attached to @p vendor by the relation "LocationInCompany".
    <li>#ITEM_duplicate_id if a Part already exists with the exact same combination of @p part_id and @p company_location.
    <li>#PROP_id_name_exceeds_allowed_length if @p part_id or @p part_name is longer than 128 characters.
    <li>#POM_string_too_long if @p part_rev_id is longer than 32 characters.
    </ul>
*/
extern VM_API int VMS_create_manufacturer_part_with_location(
    const char *part_id,        /**< (I) Vendor Part ID.<br/>If a null pointer or an empty string are provided, the code will generate a random Part ID. */
    const char *part_name,      /**< (I) Vendor Part name.<br/>If a null pointer or an empty string are provided, the code will generate a random object name.*/
    const char *type_name,      /**< (I) Part type name.<br/>It must be "Item" or any of its sub-types.*/
    const char *part_rev_id,    /**< (I) Vendor Part revision ID.<br/>If a null pointer or an empty string are provided, the code will generate a random Part revision ID.*/
    tag_t vendor,               /**< (I) Existing Vendor */
    tag_t company_location,     /**< (I) Existing Company Location */
    tag_t *vendor_part,         /**< (O) Created Vendor Part */
    tag_t *vendor_part_rev      /**< (O) Created Vendor Part revision */
    );

#ifdef __cplusplus
}
#endif

#include <vm/libvm_undef.h>

#endif
