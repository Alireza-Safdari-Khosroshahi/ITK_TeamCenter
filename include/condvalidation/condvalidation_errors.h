//Copyright 2020 Siemens Digital Industries Software
//==================================================
//Copyright $2009.
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2020 Siemens Digital Industries Software

/**
    @file

    CondValidation Error Codes Declaration

*/

#ifndef CONDVALIDATION_ERRORS_H
#define CONDVALIDATION_ERRORS_H

/*================================================================================================*/
#ifndef EMH_CONST_H
    #include <common/emh_const.h>
#endif

#include <condvalidation/libcondvalidation_exports.h>

/*================================================================================================*/

#define CONDVALIDATION_ERROR_BASE                                   EMH_CONDVALIDATION_error_base

#define CONDVALIDATION_internal_error                               ( EMH_CONDVALIDATION_error_base + 1 )
#define CONDVALIDATION_invalid_condition_scope                      ( EMH_CONDVALIDATION_error_base + 2 )
#define CONDVALIDATION_fail_ask_apn                                 ( EMH_CONDVALIDATION_error_base + 3 )
#define CONDVALIDATION_return_count_mismatch                        ( EMH_CONDVALIDATION_error_base + 4 )
#define CONDVALIDATION_return_evaluate_bomline_mismatch             ( EMH_CONDVALIDATION_error_base + 5 )
#define CONDVALIDATION_return_evaluate_condvalresults_mismatch      ( EMH_CONDVALIDATION_error_base + 6 )
#define CONDVALIDATION_return_evaluate_results_mismatch             ( EMH_CONDVALIDATION_error_base + 7 )
#define CONDVALIDATION_undefined_test_name                          ( EMH_CONDVALIDATION_error_base + 8 )
#define CONDVALIDATION_chkObjProp_Mismatch                          ( EMH_CONDVALIDATION_error_base + 9 )
#define CONDVALIDATION_invalid_instance_creation                    ( EMH_CONDVALIDATION_error_base + 10 )
#define CONDVALIDATION_empty_overridden_decision_user               ( EMH_CONDVALIDATION_error_base + 11 )

#include <condvalidation/libcondvalidation_undef.h>
#endif
