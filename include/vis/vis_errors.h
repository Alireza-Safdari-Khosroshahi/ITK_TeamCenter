/*==================================================================================================

                    Copyright (c) 1995 Electronic Data Systems Corporation
                             Unpublished - All rights reserved

====================================================================================================
File description:

    Define error codes used with vis module.

====================================================================================================
   Date      Name                    Description of Change
24-Aug-2004  Bobby Ljubic            VIS ITK errorcodes
24-Aug-2004  Bobby Ljubic            VIS ITK errorcodes
27-Mar-2006  hsud                    Usha's changes
$HISTORY$
==================================================================================================*/

#ifndef VIS_ERRORS_H
#define VIS_ERRORS_H

#include <common/emh_const.h>
#include <vis/libvis_exports.h>

#define VIS_ERROR_BASE                       EMH_VIS_error_base
/**Cannot perform %2$ action on %1$.
Please check if you have permission on the dataset that contains the base file */
#define VIS_no_write_permission_on_basefile             (VIS_ERROR_BASE+ 1)

/**Cannot perform %2$ action on %1$.
The preference %3$, have either not been added into the environment file of the
repository or if added, does not have desired values listed in it currently. Please
add preferences and appropriate values as mentioned in the configuration
instructions for this adapter. Contact your system administrator */
#define VIS_preference_empty                            (VIS_ERROR_BASE+ 2)

/**Cannot perform %2$ action on %1$.
The preference %3$ does not contain reference name %4$ in the list.*/
#define VIS_referencename_not_inpreference              (VIS_ERROR_BASE+ 3)

/**Cannot perform %2$ action on %1$.
Markup datasettype name was not able to be determined for the dataset type %3$ */
#define VIS_markup_dataset_notdetermined                (VIS_ERROR_BASE+ 4)
/**Cannot perform %2$ action on %1$.
Please check if you have permission to upload in the location %3$. Note: Markups
created on a base file in a single session get uploaded to the same markup dataset.
If uploading the markups, please do check the permissions on the markup dataset. */
#define VIS_no_write_permission_on_location             (VIS_ERROR_BASE+ 5)

/**Cannot perform %2$ action on %1$.
Please check if the extensions of the files are listed in the datasettype %3$.*/
#define VIS_extension_not_available                     (VIS_ERROR_BASE+ 6)

/**Cannot perform %2$ action on %1$.
Uploading files to location, %3$ other than dataset or folder is not allowed */
#define VIS_saving_to_location_not_allowed              (VIS_ERROR_BASE+ 7)

/**Cannot perform %2$ action on %1$.
There was no base file in the location %3$, Or the base file %2$, provided does
not match the location %3$, base file. */
#define VIS_basefile_mismatch                           (VIS_ERROR_BASE+ 8)

/**Cannot perform %2$ action on %1$.
Do not upload files to a dataset that does not allow those file types.
For example: Uploading an image capture file to a markup dataset is not allowed. */
#define VIS_upload_mismatch_type                        (VIS_ERROR_BASE+ 9)

/**Cannot perform %2$ action on %1$.
The dataset %3$, that you are trying to upload the file to, was based on a different primary document. */
#define VIS_primaryds_mismatch                          (VIS_ERROR_BASE+ 10)

/**The preference %1$, have either not been added into the environment file of the
repository or if added, does not have desired values listed in it currently. Please
add preferences and appropriate values as mentioned in the configuration
instructions for this adapter. Contact your system administrator.*/
#define VISCOMMON_preference_empty                      (VIS_ERROR_BASE+ 11)

/**Launch file generation failed. Contact your system administrator */
#define VIS_launch_file_generation_failed               (VIS_ERROR_BASE+ 12)
/**The selected object is invalid for the launch operation*/
#define VIS_launch_invalid_object                       (VIS_ERROR_BASE+ 13)

/**No viewable data could be found. If the object contains some Datasets, however,
please check the configuration of the following preferences to activate 
their rendering: VMU_Datasets, VMU_SecondaryDatasets, VMU_FileSearchOrder.*/
#define VIS_noviewable_data                             (VIS_ERROR_BASE+ 14)

/**Please check preferences %1$ and %2$ and ensure that their values are appropriate. Contact your system administrator*/
#define VIS_check_preferences                           (VIS_ERROR_BASE+ 15)

/*The type of the supplied object is not correct. The Object must be of type StructureContextImpl, VisStructureContextImpl or ConfigurationContextImpl*/
#define VIS_incorrect_argument                          (VIS_ERROR_BASE+ 16)

/**No Relation was found*/
#define VIS_null_return_from_find_relation              (VIS_ERROR_BASE+ 17)

/**The input data %1$ does not match any existing data.*/
#define VIS_input_mismatch                              (VIS_ERROR_BASE+ 18)

/**Unable to find a dataset type %1$. This could be because the visualization template is not installed. Contact your system administrator. */
#define VIS_template_notfound                           (VIS_ERROR_BASE+ 19)

/**No Export Product View transfer mode is defined.*/
#define VIS_snapshot3d_PV_transfer_mode                 (VIS_ERROR_BASE+ 20)

/**An error has occurred while exporting the structure file.*/
#define VIS_snapshot3d_pie_export                       (VIS_ERROR_BASE+ 21)

/**An error has occurred while importing the structure file in Product View Dataset.*/
#define VIS_snapshot3d_import_structure_file            (VIS_ERROR_BASE+ 22)

/**An error has occurred while removing the Product View legacy structure file.*/
#define VIS_snapshot3d_remove_legacy_file               (VIS_ERROR_BASE+ 23)

/**An error has occurred while replacing the Product View structure file*/
#define VIS_snapshot3d_add_replace_structure_file       (VIS_ERROR_BASE+ 24)

/**An error has occurred while creating the Intermediate Data Capture(IDC) window for the Product View Dataset.*/
#define VIS_snapshot3d_create_idc_window                (VIS_ERROR_BASE+ 25)

/**An error has occurred while setting the top line of the Intermediate Data Capture(IDC) window for the Product View Dataset.*/
#define VIS_snapshot3d_set_idc_window_topline           (VIS_ERROR_BASE+ 26)

/**An error has occurred while traversing the Intermediate Data Capture(IDC) window.*/
#define VIS_snapshot3d_travers_idc_window               (VIS_ERROR_BASE+ 27)

/**An error has occurred while retrieving the Product View structure file type */
#define VIS_snapshot3d_structure_file_type              (VIS_ERROR_BASE+ 28)


/**An error has occurred while opening the structure file.*/
#define VIS_snapshot3d_cannot_open_structure_file       (VIS_ERROR_BASE+ 29)


/**An error has occurred while reading the structure file. */
#define VIS_snapshot3d_structure_file_io_error          (VIS_ERROR_BASE+ 30)


/**The launch request value "%1$" is not valid. It should be greater than 0.*/
#define VIS_launch_failed                               (VIS_ERROR_BASE+ 31)

/**The type of the input argument "%1$" is invalid. It must be of type "%2$". */
#define VIS_incorrect_parm_type                         (VIS_ERROR_BASE+ 32)

/**The Metadata Stamp (MDS) file was not generated. Please contact your system administrator.*/
#define VIS_mds_file_generation_failed                  (VIS_ERROR_BASE+ 33)

#include <vis/libvis_undef.h>
#endif

