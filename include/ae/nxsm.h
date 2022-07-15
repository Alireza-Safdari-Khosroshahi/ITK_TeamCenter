/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    UGSM header file
*/

/*  */

/**
   @file
   @deprecated  It will be removed from Tc12
*/
#ifndef NXSM_H
#define NXSM_H

#include <ae/nxsm_errors.h>
#include <ae/shell_util.h>
#include <ae/libae_exports.h>

/**
    @defgroup NXSM NXSM
    @ingroup AE
    @{
*/

#define MARKTRANS8          9
#define UNMARKTRANS8        8
#define MARKTRANS12         7
#define UNMARKTRANS12       6
#define UNMARKACTIVE        5
#define LSTCHGREFSET        4
#define CHGLAYER            3
#define MARKACTIVE          2
#define MARK                1
#define UNMARK              0
#define VIEWONLY            1
#define EDITTRANSF          2
#define EDITACTIVE          3
#define COMPONENT           0
#define ASSEMBLY            1
#define OKACTION            100
#define CANCELACTION        101

/**
    @name Generic IPC messages
    @{
*/
#define IPC_INIT            1
#define IPC_TERM            2
#define IPC_RC              3
#define IPC_FC1             4
#define IPC_PM              5
#define IPC_FS1             6
#define IPC_FILE            7
#define IPC_TRANSF_ASS1     8
#define IPC_TRANSF_ASS2     9
#define IPC_CPART           10
#define IPC_NEWSESSION      11
#define IPC_TRANSF_COMP1    12
#define IPC_TRANSF_COMP2    13
#define IPC_FC2             14
#define IPC_FS2             15
/** @} */

typedef struct {
    short len;      /**< Line length */
    char  buf[255]; /**< Text of line */
} PATH;

typedef struct {
    short len;      /**< Line length */
    char  buf[30];  /**< Text of line */
} ITMNAME;

typedef struct {
    short len;      /**< Line length */
    char  buf[10];  /**< Text of line */
} ITMVERSION;

typedef struct {
    short len;      /**< Line length */
    char  buf[6];   /**< Text of line */
} ITMSEQNO;

typedef struct {
    short len;      /**< Line length */
    char  buf[12];  /**< Text of line */
} TBL;

typedef struct {
    short len;      /**< Line length */
    char  buf[16];  /**< Text of line */
} USRPAS;

typedef struct {
    double tm[13];
} MATRIX;

typedef struct {
    short len;
    char  buf[132];
} NAME;

struct node_tag {
    NAME        fname;
    ITMNAME     itmid;
    ITMVERSION  itmver;
    ITMNAME     asmitmid;
    ITMVERSION  asmitmver;
    ITMSEQNO    seqno;
    ITMNAME     ocdesc;
    ITMNAME     refset;
    double      tm[13];
    short       layer;
    short       active;
    short       loaded;
    short       filed;
    short       level;
    short       type;
    short       eimid;
    short       fs;
    short       transf_changed;
    NAME        attrfile;
    NAME        fname2;
};

typedef struct node_tag NODE;

typedef struct {
    short   code;
    short   type;
    short   eimid;
    short   fs;
    short   assembly_trans;
    NAME    fname;
    double  tm[13];
    short   layer;
    ITMNAME refset;
    ITMNAME ocdesc;
    NAME    attrfile;
    NAME    fname2;
    NAME    fname3;
    NAME    fname4;
} IPC_MESSAGE;

#ifdef __cplusplus
extern "C"{
#endif

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXMsgHandler_init_module (void);

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXSM_isUGDataset(
    tag_t         dataset,
    logical*         verdict
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXSM_create_nxpart(
    tag_t         dataset
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API void NXSM_get_nx_switch(
    char*          data
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_create_nxprocessdata(void);

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_is_apiserver_reusable(void);

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API void HOOKUP_kill_apiserver (
    int
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_reset_export_dir(void);

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_set_dir_name (
    int*,
    char*
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_start_apiserver (
    int
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_set_base_dir_name(
    const char*
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_print(
    tag_t
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_print_using (
    tag_t
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API logical HOOKUP_can_auto_login(void);

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API void HOOKUP_display_error(
    int
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int HOOKUP_get_nxmgr_string(
    tag_t,
    logical,
    char*
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
    This function allows two dimensional images of Unigraphics parts to be generated from Teamcenter.
    These images are intended to be viewed on Web Access pages.
    The generated images will be stored as Named References to the UGMASTER dataset.
    Preferences for types and sizes of images desired can be modified in .tc_env.

    @note We anticipate changing and enhancing the interface to this function in upcoming releases.
*/
extern AE_API int NXSM_create_nx_image(
    tag_t*,
    int         /**< (I) List of UGMASTER datasets requesting image generation */
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXPV_tessellation(
    tag_t         rev
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXCGM_conversion(
    tag_t,
    char*,
    char*,
    tag_t
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXPV_batch_tessellation(
    int,
    tag_t*
    );

/**
    @deprecated <b>This function is deprecated and will be removed from Tc12. There is no replacement function.</b>
*/
extern AE_API int NXCGM_conversion_with_text_or_polylines(
    tag_t,
    char*,
    char*,
    tag_t,
    char*
    );
/** @} */

#ifdef __cplusplus
}
#endif

#include <ae/libae_undef.h>
#endif
