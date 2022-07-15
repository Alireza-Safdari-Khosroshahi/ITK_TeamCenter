/*==================================================================================================
                    Copyright (c) 2003,2006 Unigraphics Solutions Inc.
                             Unpublished - All rights reserved
====================================================================================================*/
/**
    @file

    This file contains functions and declarations for validation rule ITK APIs.
*/

/*  */

#ifndef VALIDATIONRULE_H
#define VALIDATIONRULE_H

#include <unidefs.h>
#include <tc/tc_startup.h>
#include <validation/libvalidation_exports.h>

/**
    @defgroup VALIDATION_RULE Validation Rule

A validation rule is an instance of Validation Data object with additional run-time attributes: 

<ul>
    <li>A validation agent which can be a NX CheckMate checker. 
    <li>Dataset types that the validation agent (checker) is applicable. 
    <li>Whether the check is mandatorial or optional. Mandatorial check must run and pass. Optional check must 
        run (pass status is not required). 
    <li>Event names that the check is applicable. When applicable event names are specified for a validation 
        agent (checker), then the check result is verified only when these events happen. No event names specified
        means that the agent (checker) is applicable to all events. Event name can contain "*" as wildcard. Event 
        names can be marked exclusive.
    <li>List of parameter and value pairs. These parameter values need be verified from validation result log file.
</ul>

Validation rules are defined based on user business model. In a production environment, multiple validation rule 
files can be defined for different business processes.


Validation rules can be defined in a XML file which is called validation rule file. A validation rule file defines
all validation rules for a validation rule set. Here�s the guideline on how to create a validation rule file:

<ul>
    <li>Rule_Set node attributes: attributes �name? �description? �user?and �date?are not optional. These 
        attributes will be mapped as Teamcenter validation rule set object attributes when XML rule is imported 
        (for future enhancement).
    <li>Rule node defines a rule. 
    <li>Checker name is checker class name (not display name). �Checker?node is not optional.
    <li>When a check is mandatorial, the check must run and pass. When a check is not mandatorial (optional),
        check must run (result status is ignored). �Mandated?node is not optional.
    <li>Applicable dataset types list must be defined. �Datasets?node is not optional.
    <li>Applicable events list contains the event values that the check is applicable. When no event values list is
        defined, then the rule is applicable at all times. Event value can contain ??as wildcard. The values 
        listed can be exclusive when �exclude?is set to �Yes?
    <li>When class attribute is defined for an events list, the class clause defines what target revision attribute
        value should be tested against event values list.
    <li>Only the parameters that logged in profile level (for profile check result log file) are supported. 
        Child checker parameters must be promoted into profile level in order to be verified by validation rule 
        APIs.
    <li>The order that rules are defined in XML rule file is not essential.
    <li>The same checker can be instanced in the definition of multiple rules in the same rule file.
</ul>

    @code

    <?xml version="1.0"?>
    <?xml-stylesheet type="text/xsl" href="validation_rule.xsl"?>

    <Rule_Set 
        name="Test_rule_set_1" 
        description="Power Train Event 0" 
        user="your_user_id" date="2005-12-25" 
        xmlns="http://www.plmxml.org/Schemas/PLMXMLSchemaValidationRule"
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:schemaLocation="http://www.plmxml.org/Schemas/PLMXMLSchemaValidationRule validation_rule.xsd">

        <Rule>
        <Checker name="mqc_check_dim_attach_solid"></Checker>
        <Mandated>no</Mandated>
        <Datasets>
            <type>UGMASTER</type>
            <type>UGPART</type>
        </Datasets>
        <Events class="ITEMREVISION:owning_group" exclude="yes">
            <value>chassis.pe.company</value>
            <value>powertrain.pe.company</value>
        </Events>
        <Parameters>
        </Parameters>
        </Rule>
        <Rule>
        <Checker name="mqc_examine_geometry"></Checker>
        <Mandated>yes</Mandated>
        <Datasets>
            <type>UGPART</type>
            <type>UGMASTER</type>
        </Datasets>
        </Rule>
        <Rule>
        <Checker name="mqc_check_dim_attach_solid"></Checker>
        <Mandated>no</Mandated>
        <Datasets>
            <type>UGPART</type>
        </Datasets>
        </Rule>
        <Rule>
        <Checker name="mqc_exam_geom_combo"></Checker>
        <Mandated>no</Mandated>
        <Datasets>
            <type>UGMASTER</type>
            <type>UGPART</type>
            <type>UGALTREP</type>
        </Datasets>
        <Events exclude="no">
            <value>Status*3</value>
            <value>Status_4</value>
        </Events>
        <Parameters>
            <Parameter operation="=" title="Check Tiny objects" value="TRUE"></Parameter>
            <Parameter operation="=" title="Check Misaligned Objects" value="TRUE"></Parameter>    
        </Parameters>
        </Rule>
        <Rule>
        <Checker name="mqc_examine_geometry"></Checker>
        <Mandated>no</Mandated>
        <Datasets>
            <type>UGMASTER</type>
            <type>UGPART</type>
        </Datasets>
        <Events>
            <value>S*</value>
        </Events>    
        <Parameters>
            <Parameter operation="=" title="Save Log in Part" value="TRUE"></Parameter>
        </Parameters>
        </Rule>
    </Rule_Set>

    @endcode

    @{
*/

/**
    Validation expression structure defines a parameter/value pair to be verified from validation result log. For 
    checker result log, parameters fell into LOG_PARAMETER_BEGIN and LOG_PARAMETER_END section are verified. 
    For profile result log, only the parameters fell into profile level LOG_PARAMETER_BEGIN and LOG_PARAMETER_END 
    section are verified. Child checker parameters must be promoted into profile level to be verified. 
*/
typedef struct validation_expression_s {
    char        *name;          /**< Name of parameter or attribute */
    char        op;             /**< '=' */
    char        *value;         /**< required value defined in validation rule */
    char        *value_from_log;/**< value found from Check-Mate XML log */
} validation_expression_t;

/**
    Validation event structure defines a list of events that the rule is applicable. The events list is exclusive 
    when exclusive attribute is set to �yes?in the rule file. The �class_clause?defines what attribute value of 
    the target revision object should be tested against the events list. 
*/
typedef struct validation_events_s {
    char        *class_clause;    /**< Attribute class clause. For example: ITEMREVISION:owning_group */
    char        **values;         /**< List of event values (or attribute values if attribute class
                                         clause defined). "*" is translated as wildcard. Special characters
                                         such as "^" or "$" are not allowed. */
    int         num_values; 
    logical     exclude;          /**< TRUE: value list is exclusive. FALSE: value list is inclusive (default)
                                         When exclude == TRUE, no wildcard allowed in value list */
} validation_events_t;

typedef enum validation_run_status_e {
    up_to_date,
    out_of_date,
    out_Of_Date_RequirementChanged,
    verify_parameter_failed,
    missing_report_log,
    not_run,
    not_required
} validation_run_status_t;

/** 
    Validation Rule structure defines a rule parsed from rule file. It may be a rule that selected according to 
    current event or a rule that defined with event class clause. A rule defined with event class clause is 
    called an unresolved rule and must be resolved before checking validation results. One of ways to resolve an 
    unresolved rule is to test the rule events list by target revision attribute value (defined by class clause) 
    as current event. To ignore a rule, set checker_name[0] == '-'; To mark a rule as a resolved rule, 
    set events = NULL and free up the memory allocated for event variable.
*/
typedef struct validation_rule_s {
    tag_t           checker_obj;         /**< Validation Data object (checker) */
    char            *checker_name;       /**< When checker_name[0] == '-', the rule is marked to be ignored. */
    char            **dataset_types;     /**< list of dataset types */
    logical         required;            /**< true: mandatory check. Pass status is expected; false: optional. 
                                              Result status ignored. */
    validation_expression_t *attributes; /**< List of checker attributes for future enhancement*/
    validation_expression_t *parameters; /**< List of checker parameters */
    validation_events_t    *events;      /**< When events != NULL, attribute class clause defined. The rule is 
                                              unresolved. */                    
    int              num_dataset_types;
    int              num_attrs;
    int              num_paras;
    
} validation_rule_t;

/**
    Validation Rule candidate results
*/
typedef struct  candidate_validation_result_s {
    validation_run_status_t status;
    tag_t                   nx_dataset;   /**< Target Dataset */
    tag_t                   result;       /**< ValidationResult */
    validation_rule_t       *rule;        /**< validation rule */
    logical                 check_passed; /**< TRUE: passed according to rule. FALSE: failed according to rule */
} candidate_validation_result_t;

/**
    Operation between parameter and value.
*/
typedef enum VALIDATIONRULE_parameter_operation_e {
            VALIDATIONRULE_operation_equal = 0,
            VALIDATIONRULE_operation_regular_exp,
            VALIDATIONRULE_operation_not_equal,
            VALIDATIONRULE_operation_less_than,
            VALIDATIONRULE_operation_lessthan_or_euqal,
            VALIDATIONRULE_operation_greater_than,
            VALIDATIONRULE_operation_greaterthan_or_equal,
            VALIDATIONRULE_operation_begins,
            VALIDATIONRULE_operation_contains
}VALIDATIONRULE_parameter_operation_t;

/**
    Parameter/value pair will be stored inside ValReqResult objects for RDDV. 
    The requirement validation results should be verified from ValidationParams
    Object rather than result log file.
*/
typedef struct VALIDATIONRULE_parameter_s {
    char        *name;                       /**< Name of parameter or attribute */
    VALIDATIONRULE_parameter_operation_t op; /**< Indicates the comparision method, 
                                                  valid inputs are "=", "<", ">", ">=", "<=" */
    char        *value;                      /**< required value defined in validation rule */
    char        *value_from_log;             /**< value found from Check-Mate XML log or ValidationParams object*/
} VALIDATIONRULE_parameter_t;

/*
    Validation Target structrue defines the available target types for one rule. 
    Any business object could be a validation target, at the meantime, it is able to limit to
    several sub typs of the specified target type.
*/
typedef struct VALIDATIONRULE_target_s {
    char            *target_type;   /*The target type, could be any POM object, like Dataset, ItemRevision and BOMLine*/
    char           **targets;       /*The sub types of specified target type, like UGMaster, UGPart*/
    int              num_targets;   /*The number of sub types*/
} VALIDATIONRULE_target_t, *VALIDATIONRULE_target_p_t;

/**
    Validation event structure defines a list of events that the rule is applicable. The events list is exclusive 
    when exclusive attribute is set to true in the rule file. The class_clause defines what attribute value of 
    the target revision object should be tested against the events list. 
*/
typedef struct VALIDATIONRULE_event_s {
    char        *class_clause;    /**< Attribute class clause. For example: ITEMREVISION:owning_group */
    char        *application;     /**< The application which rule apply to>*/
    char        *apply_to;        /**< The condition which rule apply to>*/
    logical      exclude;         /**< TRUE: value list is exclusive. FALSE: value list is inclusive (default)
                                       When exclude == TRUE, no wildcard allowed in value list */
    char       **values;          /**< List of event values (or attribute values if attribute class
                                       clause defined). "*" is translated as wildcard. Special characters
                                       such as "^" or "$" are not allowed. */
    int          num_values;      /**< The number of event values >*/
    
} VALIDATIONRULE_event_t;

/** 
    Defines a rule parsed from rule file.
*/
typedef struct VALIDATIONRULE_rule_s {
    tag_t            checker_obj;            /**< Validation Data object (checker) */
    char            *checker_name;           /**< When checker_name[0] == '-', the rule is marked to be ignored. */
    char            *checker_version;        /**< The version of one checker> */
    logical          required;               /**< true: mandatory check. Pass status is expected; false: optional. 
                                              Result status ignored. */
    VALIDATIONRULE_target_t     *target;     /**< The validation target> */

    VALIDATIONRULE_parameter_t  *attributes; /**< List of checker attributes for future enhancement*/
    VALIDATIONRULE_parameter_t  *parameters; /**< List of checker parameters */
    VALIDATIONRULE_event_t      *events;     /**< When events != NULL, attribute class clause defined. The rule is 
                                              unresolved. */
    int              num_events;
    int              num_attrs;
    int              num_paras;
    
} VALIDATIONRULE_rule_t;

/*
    Validation rule set structure.
*/
typedef struct VALIDATIONRULE_rule_set_s {
    char                       *name;       /*The rule set name, TODO:Consider localization*/
    int                         num_rules;  /*The number of rules*/
    VALIDATIONRULE_rule_t      *rules;      /*The validation rule list*/
} VALIDATIONRULE_rule_set_t, *VALIDATIONRULE_rule_set_p_t;

/**
    The candidate rule plus validation result need to be verified.
*/
typedef struct  VALIDATIONRULE_candidate_result_s {
    validation_run_status_t status;
    tag_t                   target_obj;   /**< The validation target object > */
    tag_t                   result;       /**< ValidationResult object> */
    VALIDATIONRULE_rule_t  *rule;         /**< validation rule >*/
    logical                 check_passed; /**< TRUE: passed according to rule. FALSE: failed according to rule */
} VALIDATIONRULE_candidate_result_t;

#ifdef __cplusplus
extern "C"{
#endif

/**
    Downloads the validation rule file to a temporary directory, parses the rule file (XML) and 
    selects rules by @p current_event value (if provided). 
    <br/>When @p current_event is not provided, all rules are 
    selected. If a rule is defined without applicable events list, then the rule is always selected. Rules with 
    class clause defined are also selected as unresolved rules.
*/
extern VALIDATION_API int VALIDATIONRULE_get_rules ( 
                  char* rule_item_revision,     /**< (I) item id/revision id string */
                  char* validation_rule_set,    /**< (I) set to NULL (for future enhancement) */
                  char* current_event,          /**< (I) current event. When not provided, set to NULL */
                  validation_rule_t **rules,    /**< (OF) list of validation rules */
                  int               *num        /**< (O) number of rules */
                  );

/**
    Collects NX datasets from both target objects list and the first generation children 
    list of target revision objects. 
    <br/>NX datasets and rules are cross-tested by comparing dataset type and rule 
    dataset types. The matched rule and NX dataset is a candidate result to be verified. Unresolved rules are 
    resolved in either of the following methods:
        <ol>
        <li>If the target objects list contains only one object and that the object is an item revision, then 
            revision attribute value defined by class clause is obtained and compared with rule event values list.
        <li>In other cases, the unresolved rules are marked ignored.
        </ol>
    If neither of these methods meets user business model, then customization codes must resolve unresolved rules 
    before calling this function.
*/
extern VALIDATION_API int VALIDATIONRULE_get_candidate_results(
                  tag_t*    target_obj,                             /**< (I) target objects list */
                  int       num_target,                             /**< (I) number of target objects */
                  validation_rule_t *rules,                         /**< (I) validation rules list */
                  int       num_rules,                              /**< (I) number of validation rules */
                  candidate_validation_result_t **candidates,       /**< (OF) candidate results list */
                  int       *num_candidates                         /**< (O) number of candidate results */
                  );

/**
    Checks candidate validation result in following steps:
    <ol>
        <li>Checks if validation result object exists to see if the validation has run.
        <li>Checks if validation result timestamp is later or equal to NX dataset timestamp to see if validation 
            result is up-to-date.
        <li>Checks validation result status to see if validation result satisfies validation rule (pass status is 
            expected for mandatorial check. Result status is ignored for optional check).
        <li>Downloads and opens validation result log to see if parameter values meet validation rule.
    </ol>
*/
extern VALIDATION_API int VALIDATIONRULE_verify_result(
                  candidate_validation_result_t *candidate          /**< (I) candidate result */                               
                  );

/**
    Releases memory allocated for validation rules list.
*/
extern VALIDATION_API void VALIDATIONRULE_free_rules(
                  validation_rule_t *rules,
                  int       num_rules
                  );

/**
    Releases memory allocated for candidate validation results list.
*/
extern VALIDATION_API void VALIDATIONRULE_free_results(
                  candidate_validation_result_t *candidates,
                  int       num_candidates
                  );

/**
    Calls all validation rule functions. 
    <br/>It queries rule file, generates candidate validation
    results, verifies candidate validation results, frees up allocated memory, generates check validation 
    results log file. When validation rules are met for all target NX datasets, it returns ITK_ok. 
    <br/>Otherwise, returns NOT_ok and error store initialized. Log file created under /tmp or c:\\temp
*/
extern VALIDATION_API int VALIDATIONRULE_check_results(
                  tag_t*    target_obj,       /**< (I) target objects list */
                  int       num_target,       /**< (I) number of target objects */
                  char* rule_item_revision,   /**< (I) item/revision */
                  char* validation_rule_set,  /**< (I) set to NULL (for future enhancement) */
                  char* current_event         /**< (I) current event. When not provided, set to NULL */
                  );

/**
    Downloads validation rule file to a temporary directory, parses the rule file (XML) and 
    selects rules by @p current_event value (if provided). 
    <br/>When @p current_event is not provided, all rules are 
    selected. If a rule is defined without applicable events list, then the rule is always selected. Rules with 
    class clause defined are also selected as unresolved rules.
*/
extern VALIDATION_API int VALIDATIONRULE_get_rules2 ( 
                  tag_t rule_revision,          /**< (I) item/revision tag */
                  char* validation_rule_set,    /**< (I) set to NULL (for future enhancement) */
                  char* current_event,          /**< (I) current event. When not provided, set to NULL */
                  validation_rule_t **rules,    /**< (OF) list of validation rules */
                  int               *num        /**< (O) number of rules */
                  );

/**  
    Downloads validation rule file to a temporary directory, parses the rule file and 
    selects rules by current_event value (if provided). When current_event is not provided, all rules are 
    selected. If a rule is defined without applicable events list, then the rule is always selected. Rules with 
    class clause defined are also selected as unresolved rules.

    @note This function is to support the new PLMXML format rule file.
*/
extern VALIDATION_API int VALIDATIONRULE_get_rules3 ( 
                  char* rule_item_revision,      /**< (I) item id/revision id string */
                  char* validation_rule_set,     /**< (I) validation rule set name, set to NULL to get all rules */
                  char* current_event,           /**< (I) current event. When not provided, set to NULL */
                  VALIDATIONRULE_rule_t **rules, /**< (OF) list of validation rules */
                  int               *num         /**< (O) number of rules */
                  );

/**
    Downloads validation rule file to a temporary directory, parses the rule file and 
    selects rules by current_event value (if provided). When current_event is not provided, all rules are 
    selected. If a rule is defined without applicable events list, then the rule is always selected. Rules with 
    class clause defined are also selected as unresolved rules.

    @note This function is to support the new PLMXML format rule file.
*/
extern VALIDATION_API int VALIDATIONRULE_get_rules4 ( 
                  tag_t rule_revision,           /**< (I) item/revision tag */
                  char* validation_rule_set,     /**< (I) validation rule set name, set to NULL to get all rules */
                  char* current_event,           /**< (I) current event. When not provided, set to NULL */
                  VALIDATIONRULE_rule_t **rules, /**< (OF) list of validation rules */
                  int               *num         /**< (O) number of rules */
                  );

/**   
    Collects NX datasets from both target objects list and the first generation children 
    list of target revision objects. 
    <br/>NX datasets and rules are cross-tested by comparing dataset type and rule 
    dataset types. The matched rule and NX dataset is a candidate result to be verified. Unresolved rules are 
    resolved in either of the following methods:
        <ol>
        <li>If the target objects list contains only one object and that the object is an item revision, then 
            revision attribute value defined by class clause is obtained and compared with rule event values list.
        <li>In other cases, the unresolved rules are marked ignored.
        </ol>
    If neither of these methods meets user business model, then customization codes must resolve unresolved rules 
    before calling this function.

    @note This function is to support the new PLMXML format rule file.
*/
extern VALIDATION_API int VALIDATIONRULE_get_candidate_results2(
                  tag_t*    target_obj,                             /**< (I) target objects list */
                  int       num_target,                             /**< (I) number of target objects */
                  VALIDATIONRULE_rule_t *rules,                     /**< (I) validation rules list */
                  int       num_rules,                              /**< (I) number of validation rules */
                  VALIDATIONRULE_candidate_result_t **candidates,   /**< (OF) candidate results list */
                  int       *num_candidates                         /**< (O) number of candidate results */
                  );

/**
   Checks candidate validation result in following steps:
    <ol>
        <li>Checks if validation result object exists to see if the validation has run.
        <li>Checks if validation result timestamp is later or equal to NX dataset timestamp to see if validation 
            result is up-to-date.
        <li>Checks validation result status to see if validation result satisfies validation rule (pass status is 
            expected for mandatorial check. Result status is ignored for optional check).
        <li>Downloads and opens validation result log to see if parameter values meet validation rule.
    </ol>

   @note This function is to support the new PLMXML format rule file.
*/
extern VALIDATION_API int VALIDATIONRULE_verify_result2(
                  VALIDATIONRULE_candidate_result_t *candidate          /**< (I) candidate result */                               
                  );
                  
/**
    Evaluates the compound result pass/fail status for input candidate validation results.
    <br/>The compound result pass/fail status can be interpreted as weather the parts pass or fail the required validation checks. 
    <br/>Each candidate validation result status can be pass or fail or not run (no result was found for the part and validation check). 
    <br/>Since each pair of part and validation check can have multiple candidate validation results, one part is considered passed one validation
     check if there is at least one candidate validation result found that the status is pass. Otherwise the part is considered to be failed the validation check. 
    <br/>The compound result status is "pass" if all parts passes all required validation check. Otherwise the compound result status is "fail".
    <br/>This function also filters out candidate validation results for which the status is "fail" while the part that it references passes the validation check.
    <br/>This function is to be called after candidate results have been verified.     
    
    @returns #ITK_ok always
*/                  
extern VALIDATION_API int VALIDATIONRULE_evaluate_compound_result_status(
                  int num_candidates,                                          /**< (I) Number of candidates */
                  const VALIDATIONRULE_candidate_result_t *candidate_results,  /**< (I) num_candidates Candidate results */
                  int *num_evaluated,                                          /**< (O) Number of evaluated results */                  
                  VALIDATIONRULE_candidate_result_t **evaluated_results,       /**< (OF) num_evaluated Evaluated candidate results */                  
                  logical *status                                              /**< (O) Indicates the overall check status. Values are:
                                                                                <ul>
                                                                                    <li>true: the parts passes all validation checks
                                                                                    <li>false: at least one part has failed at least one validation check
                                                                                </ul> */
                  );

/**
    Releases memory allocated for validation rules list.
    <br/>It is apply to the new VALIDATIONRULE structure.
*/
extern VALIDATION_API void VALIDATIONRULE_free_rules2(
                  VALIDATIONRULE_rule_t *rules,
                  int       num_rules
                  );

/**
    Releases memory allocated for candidate validation results list.
    <br/>It is apply to the new VALIDATIONRULE structure.
*/
extern VALIDATION_API void VALIDATIONRULE_free_results2(
                  VALIDATIONRULE_candidate_result_t *candidates,
                  int       num_candidates
                  );

#ifdef __cplusplus
}
#endif

/** @} */
#include <validation/libvalidation_undef.h>

#endif

