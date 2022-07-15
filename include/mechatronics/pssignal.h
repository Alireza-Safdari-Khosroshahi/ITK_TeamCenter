/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains definitions and interfaces for pssignal class
*/

/*  */

#ifndef PSSIGNAL_H
#define PSSIGNAL_H

#include <unidefs.h>
#include <mechatronics/libmechatronics_exports.h>

/**
    @defgroup PSSIGNAL PS Signal
    @ingroup MECHATRONICS
    @{
*/

/**
    @name PS Signal definitions
    @{
*/
#define  PSSIGNAL_CLASS_NAME       "PSSignal"
#define  PSSIGNAL_TYPE_NAME        PSSIGNAL_CLASS_NAME
#define  PSSignalClassName         PSSIGNAL_CLASS_NAME

#define  PSSIGNAL_REV_CLASS_NAME   "PSSignalRevision"
#define  PSSIGNAL_REV_TYPE_NAME    PSSIGNAL_REV_CLASS_NAME
#define  PSSignalRevClassName      PSSIGNAL_REV_CLASS_NAME
/** @} */

/**
    @name Type for OOTB Message type defined - parent is PSSignal
    @{
*/
#define MESSAGE               "Message"
#define MESSAGE_REV           "Message Revision"
/** @} */

/**
    @name Type for OOTB signal
    @{
*/
#define SIGNAL_TYPE_NAME           "Signal"
#define SIGNAL_REV_TYPE_NAME       "SignalRevision"
/** @} */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This function will create a new, standalone signal object given an ID and name.

    <b>Restrictions:</b>
    <OL>
    <LI>For a signal_type other than null, the type must be defined by the site using "install_types" utility.
        If value is specified as null, the default type "PSSignal" will be used.
    <LI>The signal_name will be used as the revision’s name.
    </OL>

    @note This itk will not save the object. AOM_save_with_extensions needs to be called separately to save the object.
*/
extern MECHATRONICS_API int SIG_create_signal (
    const char*             signal_id,      /**< (I) Unique identifier for the signal.
                                                If null, the system will automatically generate ID. */
    const char*             signal_name,    /**< (I) Signal name */
    const char*             signal_type,    /**< (I) Type of the signal to be created. Null is allowed for this argument. */
    const char*             signal_rev_id,  /**< (I) Identifier for the default signal revision. A null is allowed for this argument.
                                                If null, the system will automatically generate revision id. */
    tag_t*                  new_signal,     /**< (O) Tag of new signal object */
    tag_t*                  new_signal_rev  /**< (O) Tag of new signal revision object */
    );

/**
    This function will associate a process_variable to the given signal instance
    in the context of a product structure.

    <b>Restrictions:</b>

    Only one process variable can be associated for a given signal instance.

    @retval ifail1 Does not belong to the same structure
    @retval ifail2 Process variable at a higher level than Signal
    @retval ifail3 Signal is already associated with a process variable.
                   Signal cannot be associated with more than one Process variable.
*/
extern MECHATRONICS_API int SIG_set_signal_pvariable(
    tag_t                   signal_line_tag,    /**< (I) BomLine tag of a signal occurrence */
    tag_t                   pvar_line_tag       /**< (I) BomLine tag of a process variable */
    );

/**
    This function will disassociate a process_variable, if exists,
    from the given signal instance in the context of a product structure.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_unset_signal_pvariable (
    tag_t                   signal_line_tag     /**< (I) BomLine tag of a signal occurrence */
    );

/**
    This function will find the process_variable associated with the signal instance in the context of a product structure.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_ask_signal_pvariable(
    tag_t                   signal_line_tag,    /**< (I) Signal line tag whose associated systems you are trying to find */
    tag_t*                  pvar_line_tagptr    /**< (O) Instance of process variable associated with signal instance */
    );

/** Removes associations between primary and secondary bomlines for the specific role.

    @returns
    <ul>
     <li>#ITK_ok on success
     <li>#SIG_invalid_signal_line if input signal line is invalid.
     <li>#MECH_some_relations_unset_failed if relation removal fails.
    </ul>
 */
extern MECHATRONICS_API int SIG_unset_associated_systems(
     tag_t primary,                 /**< (I) Signal line whose association will be removed*/
     int num_secondaries,            /**< (I) Number of secondary BOM Lines*/
     tag_t* secondaries,            /**< (I) Tags of secondary BOM Lines. If one of the secondaries is invalid they will be added to the @p failedLines.
                                             If an association does not exist between the primary and one or more of the
                                             secondaries, the secondary will be added to the @p failedLines array and the function
                                             will process the next secondary.*/
     char* role,                    /**< (I) Callers must pass a valid non-null role in the char* role string
                                             argument for transmitter association. For source or target role,
                                             this input is optional and may or may not be passed.
                                             If input role is empty, the source and target association
                                             between the primary and secondary will be removed.
                                             This ITK will then remove the associations between the
                                             primary and secondaries, if they exist for that specific role.*/
     logical *has_failures,          /**< (O) Flag to indicate failures*/
     int *num_failed_lines,          /**< (O) Number of failed BOM Lines.*/
     tag_t **failed_lines            /**< (OF) num_failed_lines Failed BOM Lines tag */
     );


/**
    Creates associations between a signal line and valid bomlines.
    <br/>This method will handle multiple secondary lines and will be used to
    create associated system relations of role "source", "target", "transmitter".
    <br/>This call can be used to set source, target or transmitters for signals.
    @note In order to associate a signal to a process variable or
    <br/>redundant signal, the ITKs #SIG_set_signal_pvariable and
    <br/>#SIG_set_redundant_signal must be used

    @returns
    <ul>
     <li>#ITK_ok on success
     <li>#MECH_invalid_input if one or more of the input parameters are invalid.
     <li>#SIG_no_role_no_gde_direction if the General Design Element has empty direction value and the input role is empty.
     <li>#SIG_invalid_role if the input role passed in is invalid.
     <li>#MECH_some_relations_set_failed if relation creation failed.
    </ul>
 */
extern MECHATRONICS_API int SIG_set_associated_systems(
    tag_t primary,                     /**< (I) Signal line for which association will be created*/
    int    num_secondaries,             /**< (I) Number of secondary BOM Lines*/
    tag_t* secondaries,                /**< (I) Tags of secondary BOM Lines.*/
    char*  role,                       /**< (I) Callers must pass a valid non-null role in the char* role string
                                             argument for transmitter association. For source or target role,
                                             this input is optional and may or may not be passed.
                                             If input role is empty, the direction attribute value on the
                                             secondary GDE will be used for association creation. */

    logical *has_failures,              /**< (O) Flag to indicate failures*/
    int     *num_failed_lines,           /**< (O) Number of failed BOM Lines*/
    tag_t  **failed_lines               /**< (OF) num_failed_lines Failed BOM Lines tag*/
    );

/**
    Creates association between a signal line and an Item line for a given role.
    <br/>Role input must be passed for transmitter association.
    <br/>For source or target role, this input is optional and
    may or may not be passed.
    <br/>If input role is empty, the direction attribute value on the
    secondary GDE will be used for association creation between the primary and secondary.

    <b>Restrictions:</b>
    <OL>
    <LI>Only one association is permitted between signal and associated system for the role "source".
    <LI>Only one "role" is permitted between a signal instance and the associated system line.
    </OL>

    @returns
    <ul>
     <li>#ITK_ok on success
     <li>#MECH_invalid_input if one or more of the input parameters are invalid.
     <li>#SIG_no_role_no_gde_direction if the General Design Element has empty direction value and the input role is empty.
     <li>#SIG_invalid_role if the input role passed in is invalid.
     <li>#MECH_some_relations_set_failed if relation creation failed.
    </ul>
*/
extern MECHATRONICS_API int SIG_set_associated_system(
    tag_t                   signal_line_tag,    /**< (I) Tag of signal or process variable (GDE) line */
    tag_t                   system_line_tag,    /**< (I) Tag of BOM Line to be associated with Signal */
    const char*             role,               /**< (I) Callers must pass a valid non-null role in the char* role string
                                                         argument for transmitter association. For source or target role,
                                                         this input is optional and may or may not be passed.
                                                         If input role is empty, the direction attribute value on the
                                                         secondary GDE will be used for association creation. */
    tag_t*                  relation_tagptr     /**< (O) Tag of the relation. The function returns #NULLTAG if unable to create relation. */
    );

/**
    This function will disassociate a signal instance from another Item line,
    which was connected through "associated_system" relation in the context of a product structure.
    This ITK will remove ALL the associations between the signal_line_tag and the system_line_tag
    corresponding to valid associated system roles between the two lines

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_unset_associated_system(
    tag_t                   signal_line_tag,    /**< (I) BomLine tag of a signal or process variable */
    tag_t                   system_line_tag     /**< (I) Any Item line in the product/function structure at
                                                        the same or lower level than Signal line */
    );

/**
    This function will find all the systems (Port, Terminal, Connection, Device etc) that are
    associated with signal instance using "associcated_system" relations.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_ask_associated_systems (
    tag_t                   signal_line_tag,            /**< (I) Signal or process variable line tag whose associated systems you are trying to find */
    int*                    associated_systems_count,   /**< (O) Count of systems associated with signal instance */
    tag_t**                 associated_systems_tags     /**< (OF) associated_systems_count List of associated system tags */
    );

/**
    This function returns the role of association between a
    Process variable (GDE) line and another BOM line (Item or GDE line)

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_ask_associated_system_role (
    tag_t                   signal_line_tag,        /**< (I) Tag of signal or process variable line */
    tag_t                   associated_sysline_tag, /**< (I) Tag of bom Line associated with signal using associated system relation */
    char**                  role                    /**< (OF) Name of the role which defines the purpose of association between
                                                            signal and other BOM line. Must be freed with #MEM_free after usage. */
    );

/**
    This function associates "redundant_signal_line" as a redundant for the given signal

    <b>Restrictions:</b>

    There can be only one redundant for a given signal.
    The function returns error if the primary signal already contains a redundant.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_set_redundant_signal(
    tag_t                   primary_signal_line_tag,    /**< (I) Tag of primary signal line */
    tag_t                   redundant_signal_line_tag,  /**< (I) Tag of signal Line to be associated with primary as a redundant */
    tag_t*                  relation_tagptr             /**< (O) Tag of the redundant relation */
    );

/**
    This function removes the association between the given signal line and
    another signal line, which is a redundant.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_unset_redundant_signal(
    tag_t                   primary_signal_line_tag,    /**< (I) Tag of signal line, whose redundant to be removed */
    tag_t                   redundant_signal_line_tag   /**< (I) Tag of redundant signal line */
    );

/**
    This function returns the redundant signal if any for the given signal line.
    If there is no redundant, the function returns #NULLTAG.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_ask_redundant_signals(
    tag_t                   primary_signal_line_tag,    /**< (I) Tag of signal line, whose redundant to be returned */
    int*                    redundant_signal_count,     /**< (O) Count of redundant signals for the given primary signal */
    tag_t**                 redundant_signal_line_tags  /**< (OF) redundant_signal_count Tag list of redundant signal lines */
    );

/**
    This function sets units on a given signal object.

    @note Alternately, you may use, #ITEM_set_unit_of_measure to set signal units.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_set_signal_units (
    tag_t                   signal_tag,     /**< (I) Signal object tag */
    tag_t                   uom_tag         /**< (I) Tag of UOM object to be set as units of the given signal */
    );

/**
    This function returns units set on a given signal object.

    @note Alternately, you may use, #ITEM_ask_unit_of_measure to get signal units.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIG_ask_signal_units (
    tag_t                   signal_tag,     /**< (I) Signal revision object tag */
    tag_t*                  uom_tagptr      /**< (O) Pointer to Tag object for returning signal units (uom) of the given signal object.
                                                    If units is not set, this function returns #NULLTAG. */
    );

/**
    This function sets the given value on given signal revision.

    @note User needs to call AOM_save() on Signal revision after this function call to commit the changes.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIGREV_set_signal_value (
    tag_t                   signal_rev_tag,     /**< (I) Signal revision object tag */
    double                  signal_value        /**< (I) Value to be assigned to the signal revision */
    );

/**
    This function returns the value of the  given signal revision.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIGREV_ask_signal_value (
    tag_t                   signal_rev_tag,     /**< (I) Signal revision object tag */
    double*                 signal_value        /**< (O) Pointer to double data for returning signal value from the revision */
    );

/**
    This function sets the given characteristics on the given signal revision.

    @note User need to call AOM_save() on Signal revision after this function call to commit the changes.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIGREV_set_signal_characteristics (
    tag_t                   signal_rev_tag,         /**< (I) Signal revision object tag */
    const char*             signal_characteristics  /**< (I) Characteristics of the signal to be assigned to the given signal revision */
    );

/**
    This function returns the characteristics of given signal revision.

    @retval ifail1 No process variable is associated with Signal
    @retval ifail2 Cannot disassociate Process variable
*/
extern MECHATRONICS_API int SIGREV_ask_signal_characteristics (
    tag_t                   signal_rev_tag,         /**< (I) Signal revision object tag */
    char**                  signal_characteristics  /**< (OF) Pointer to char* for returning signal characteristics of the given
                                                            signal revision. The memory must be freed using #MEM_free. */
    );

/**
    This function returns the "signal value" associated with signal line.
*/
extern MECHATRONICS_API int SIG_ask_signal_line_value(
     tag_t                  signal_line_tag,    /**< (I) */
     double*                signal_value        /**< (O) */
     );

/**
    This function sets the "signal value" on a signal line.
*/
extern MECHATRONICS_API int SIG_set_signal_line_value(
     tag_t                  signal_line_tag,    /**< (I) */
     double                 signal_value        /**< (I) */
     );

/**
    This function asks the "pvar value" on a process variable line.
*/
extern MECHATRONICS_API int SIG_ask_pvariable_line_value (
    tag_t                   pvar_line_tag,      /**< (I) */
    double*                 pvar_line_value     /**< (O) */
    );

/**
    This function sets the "pvar value" on a process variable line.
*/
extern MECHATRONICS_API int SIG_set_pvariable_line_value (
    tag_t                   pvar_line_tag,      /**< (I) */
    double                  pvar_line_value     /**< (I) */
    );


extern MECHATRONICS_API int SIG_ask_is_message (
    tag_t   lineTag,     /**< (I) */
    logical  *verdict    /**< (O) */
    );


extern MECHATRONICS_API int SIG_ask_signal_sources  (
    const tag_t linetag,     /**< (I)  */
    int     *sourcecount,    /**< (O)  */
    tag_t  **sourcetags      /**< (OF) sourcecount */
   );

extern MECHATRONICS_API int SIG_ask_signal_targets  (
    const tag_t linetag,    /**< (I)  */
    int     *targetcount,   /**< (O)  */
    tag_t  **targettags     /**< (OF) targetcount */
   );

extern MECHATRONICS_API int SIG_ask_signal_transmitters  (
   const tag_t linetag,       /**< (I)  */
   int     *txmittercount,    /**< (O)  */
   tag_t  **txmittertags      /**< (OF) txmittercount */
   );

extern MECHATRONICS_API int SIG_ask_device_sources (
    const tag_t linetag,        /**< (I) */
    int     *sourcecount,       /**< (O) */
       tag_t  **sourcetags      /**< (OF) sourcecount */

     );

extern MECHATRONICS_API int SIG_ask_device_targets (
     const tag_t linetag,      /**< (I) */
     int     *targetcount,     /**< (O) */
     tag_t  **targettags       /**< (OF) targetcount */
      );

extern MECHATRONICS_API int SIG_ask_device_transmitted_signals  (
     const tag_t linetag,      /**< (I) */
     int     *txmittedcount,   /**< (O) */
     tag_t  **txmittedtags     /**< (OF) txmittedcount */
    );


extern MECHATRONICS_API int SIG_ask_device_received_signals  (
     const tag_t linetag,        /**< (I) */
     int     *receivedcount,     /**< (O) */
     tag_t  **receivedtags       /**< (OF) receivedcount */
    );

/**
    This function returns the proccess variable if any for the given signal line.
    If there is no proccess variable, the function returns #NULLTAG.
*/
extern MECHATRONICS_API int SIG_ask_signal_pvariables(
    tag_t       signalLineTag,      /**< (I) Tag of signal line, whose pvariable to be returned */
    int*        pvariableCount,     /**< (O) Count of pvariables for the given primary signal */
    tag_t**     pvariableLineTags   /**< (OF) pvariableCount Tag list of pvariable lines */
    );

/**
    This function returns the primary signals if any for the given secondary pvariable line.
    If there is no signal, the function returns #NULLTAG.
*/
extern MECHATRONICS_API int SIG_ask_signals_of_pvariable(
    tag_t       pvariableLineTag,   /**< (I) Tag of pvariable line, whose signals to be returned */
    int*        signalCount,        /**< (O) Count of signals for the given primary pvariable */
    tag_t**     signalLineTags      /**< (OF) signalCount Tag list of signal lines */
    );


/** @} */

#ifdef __cplusplus
}
#endif

#include <mechatronics/libmechatronics_undef.h>

#endif
