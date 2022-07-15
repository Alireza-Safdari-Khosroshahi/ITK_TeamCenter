/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef STANDARDTCACTIONHANDLERS_H
#define STANDARDTCACTIONHANDLERS_H

#include <sub_mgr/libsub_mgr_exports.h>

/**
    @defgroup STANDARD_TC_ACTION_HANDLERS Standard Action Handlers
    @ingroup SUBSCRIPTION
    @{
*/

#define STDHANDLER_GS_SYNC_ID        "IMAN_G_iMAN_Auto_Sync"
#define STDHANDLER_GS_SYNC_FUNC      "IMANHANDLER_start_giman_auto_sync"

#define STDHANDLER_MAIL_NOTIFY_ID       "IMAN_Smtp_Mail_Notify"
#define STDHANDLER_MAIL_NOTIFY_FUNC     "IMANHANDLER_mail_notify"

#define STDHANDLER_PROXY_LINK_ID        "IMAN_Proxy_Link"
#define STDHANDLER_PROXY_LINK_FUNC      "TCHANDLER_proxy_link"

// Schedule Notifications
#define STDHANDLER_SCHMGT_NOTIFICATION_ID    "TC_SCHMGT_Notifications"
#define STDHANDLER_SCHMGT_NOTIFICATION_FUNC  "TCHANDLER_schmgt_notifications"

/** @} */

#include <sub_mgr/libsub_mgr_undef.h>
#endif
