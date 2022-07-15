/*==============================================================================
                Copyright (c) 2008 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    Extensionframework errors
*/

/*  */

#ifndef EXTENSIONFRAMEWORK_ERRORS_H
#define EXTENSIONFRAMEWORK_ERRORS_H

#include <common/emh_const.h>
#include <extensionframework/libextensionframework_exports.h>

#define EXTENSIONFRAMEWORK_unknown                               (EMH_EXTENSIONFRAMEWORK_error_base + 0)
#define EXTENSIONFRAMEWORK_object_deleted                        (EMH_EXTENSIONFRAMEWORK_error_base + 1)
#define EXTENSIONFRAMEWORK_Operation_not_found                   (EMH_EXTENSIONFRAMEWORK_error_base + 2)
#define EXTENSIONFRAMEWORK_Property_Id_not_found                 (EMH_EXTENSIONFRAMEWORK_error_base + 3)
#define EXTENSIONFRAMEWORK_Property_Operation_not_found          (EMH_EXTENSIONFRAMEWORK_error_base + 4)
#define EXTENSIONFRAMEWORK_Invalid_Property_Operation_Id         (EMH_EXTENSIONFRAMEWORK_error_base + 5)
#define EXTENSIONFRAMEWORK_Invalid_Operation_Id                  (EMH_EXTENSIONFRAMEWORK_error_base + 6)
#define EXTENSIONFRAMEWORK_Operation_Dispatcher_not_found        (EMH_EXTENSIONFRAMEWORK_error_base + 7)
#define EXTENSIONFRAMEWORK_base_action_not_defined               (EMH_EXTENSIONFRAMEWORK_error_base + 8)


#include <extensionframework/libextensionframework_undef.h>
#endif
