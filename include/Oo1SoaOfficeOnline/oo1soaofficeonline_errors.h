/* 
 Copyright 2020 Siemens Digital Industries Software
 ==================================================
 Copyright 2017
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2020 Siemens Digital Industries Software
*/


/**
    @file

    Office Online SOA Error Codes Declaration

*/

#ifndef OO1SOAOFFICEONLINE_ERRORS_H
#define OO1SOAOFFICEONLINE_ERRORS_H

#include <common/emh_const.h>

/**
    @defgroup OO1SOAOFFICEONLINE_ERRORS Errors for the SOA operations of the Office Online solution
    @ingroup OO1OFFICEONLINE
    @{
*/


#define OO1SOAOFFICEONLINE_ERROR_BASE                                        EMH_OO1SOAOFFICEONLINE_error_base 

/** No action is provided. */
#define OO1SOAOFFICEONLINE_input_action_empty                                (OO1SOAOFFICEONLINE_ERROR_BASE +   1 )

/** No object is provided. */
#define OO1SOAOFFICEONLINE_input_object_empty                                (OO1SOAOFFICEONLINE_ERROR_BASE +   2 )

/** The action "%1$" is not supported for objects of type "%2$". */
#define OO1SOAOFFICEONLINE_input_action_not_supported                        (OO1SOAOFFICEONLINE_ERROR_BASE +   3 )

/** Objects of type "%1$" are not supported by Teamcenter Office Online. */
#define OO1SOAOFFICEONLINE_input_object_type_not_supported                   (OO1SOAOFFICEONLINE_ERROR_BASE +   4 )

/** No valid file is provided for the input object. */
#define OO1SOAOFFICEONLINE_no_valid_file                                     (OO1SOAOFFICEONLINE_ERROR_BASE +   5 )

/** The Office Online Server could not be accessed. Please contact your system administrator. */
#define OO1SOAOFFICEONLINE_problem_access_oos                                (OO1SOAOFFICEONLINE_ERROR_BASE +   6 )

/** The action URL could not be retrieved during the parsing of the Discovery XML file. Please contact your system administrator. */
#define OO1SOAOFFICEONLINE_problem_processing_xml                            (OO1SOAOFFICEONLINE_ERROR_BASE +   7 )

/** No value is provided for the preference "%1$". */
#define OO1SOAOFFICEONLINE_preference_need_configured                        (OO1SOAOFFICEONLINE_ERROR_BASE +   8 )

/** @} */

#endif 
