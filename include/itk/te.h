/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    This file contains function prototypes for traversal engine module.
    The traverse module attempts to present an interface that allow to develop
    programs that do traversal of Teamcenter structures.
    Presently this can be done only for product structure.

    Calls are provided for the following:
    - Initializing/Terminating TE.
    - Registering Handlers and Selector
    - Setting revrule, bomview type and variant name to configure PS
    - Filling a tree by running a Selector that determines whether
      a branch needs to be skipped or not
    - Traversing the tree and executing different handlers
    - Storing/retreiving float value with a key
    - Funciton calls to write to log file, read from config file, report statistics
      etc.
*/

/*  */

#ifndef TE_h
#define TE_h

#include <tc/tc_startup.h>
#include <tccore/tctype.h>
#include <tccore/item.h>
#include <sa/tcfile.h>
#include <itk/libitk_exports.h>

/**
    @defgroup TE Traversal Engine
    @ingroup TC

    <h3>The Traversal Engine</h3>

    The Traversal Engine (TE) is a module that is distributed as a shared library,
    and as callable subroutines (TE API calls).
    It is a framework that will enable you to develop utilities that traverse
    Teamcenter structures such as Product Structure (PS),
    without the requirement to write a traversal algorithm.

    The Traversal Engine allows you to develop Product Structure (PS) traversing applications by
    providing you with exits for various traversal stages.
    You can register custom-defined functions at these stages thus achieving
    common business tasks involving PS traversing without writing traversal algorithms.
    Also included is a utilty ps_traverse developed using this framework.
    This utility can be used to generate reports in text format and perform some common actions,
    such as Transfer Ownership and Apply Release Status for an assembly.

    Typical common tasks include:
    <ul>
    <li>Generate reports
    <li>Release assemblies
    <li>Transfer ownership of Teamcenter objects that constitute the product structure
    </ul>

    The Traversal Engine manages the traversal, while you are only required to develop simple ITK programs.
    The Traversal Engine allows you to register these functions at different stages of the traversal.
    These functions are executed at each node and contain the information of the nodes, which can be processed.

    The core module is programmed in Object Oriented Programing (OOP),
    so the framework can be expanded by adding new classes at a later date,
    and can also be extended to traverse any Teamcenter structure such as Product Structure or Folders etc.
    Presently the core module relates to PS only.

    A utility \$TC_ROOT/bin/ps_traverse has also been developed to demonstrate the use of TE.

    <b>Basic Features</b>

    The features of the Traversal Engine are:
    <ul>
    <li>Representation of the Teamcenter structure as a tree data structure with
        each node representing the Teamcenter object.
    <li>Provides user exits at different stages and allows the registration of
        user defined functions known as Handlers and Selectors.
    <li>Allows the Handlers and Selectors to return statuses that determine the
        creation of the tree and the traversal direction.
    <li>Allows PS configuration through Revision Rules and saved Variant Rule during the creation of the tree.
    <li>Allows inputs from the command line and configuration file.
    <li>Allows you to store/retrieve float value with a key as a string, typically used for summing up functionality.
    </ul>

    Using these features you can develop programs which:
    <ul>
    <li>Generate reports
    <li>Apply task release
    <li>Release assembly /Set assembly precise and other similar tasks
    </ul>

    <b>User Exits</b>

    User Exits are provided to register Selectors and Handlers,
    that are executed at different stages of the traversal activity such as creation of the tree,
    traversing in the forward direction, traversing in the reverse direction etc.

    Selectors and Handlers are user-defined functions that need to be developed following a template.
    These functions return the decisions that determine the traversal direction.
    These are registered at different stages of the Traversal and are executed
    during the creation and the traversal of the tree.
    The Selectors are run during the creation of the tree nodes.
    These determine the values stored in each node and decide whether a particular branch needs to be
    traversed or not. The Handlers are run during the tree traversal.
    The handlers have the information of the node and the information pertaining to
    the Teamcenter object that the node represents.

    <b>Minimum Requirements</b>

    You need the following minimum requirements to be able to run the Traversal Engine:
    <ul>
    <li>The Teamcenter ITK development environment
    <li>To develop new programs in TE, knowledge of writing ITK programs will be required
    </ul>

    <b>Installation</b>

    To confirm that you have installed TE successfully,
    check if the following have been added to their respective directories.
    <ul>
    <li>Library libitk.\<libraryextension\> in \$ITC_ROOT/lib
    <li>ps_traverse in \$TC_ROOT/bin
    <li>ps_traverse.cfg and te_template_itk_main.c in \$TC_ROOT/sample/examples
    </ul>

    <h3>Developing a Traversal Program</h3>

    Once you custom develop your Selectors and Handlers by using the ITK functions and the TE API calls,
    you can compile them into an executable by using the compile and
    linkitk scripts in the tools \$TC_ROOT/sample directory.

    API calls are classified into:
    <ul>
    <li>Initializing/Terminating calls. TE  modules have to be initialized to use any TE Call.
    <li>Configure PS. These configure the PS using revision rule or saved variant.
        View type to traverse also can be specified.
    <li>Register Handlers/Selectors. These register the provided the functions as Selector or Handler.
    <li>Fill/Traverse. These create the Tree and Traverse the Tree.
    <li>User Interface calls. These write messages to the log file and console,
        and receive input from the configuration file and the command line arguments.
    </ul>

    Refer to the header file te.h in the $TC_ROOT/include directory.

    <b>Compiling and Linking</b>

    Once you have written the new program using the TE API and the Selectors and Handlers,
    you can use the compile and linkitk scripts in the \$TC_ROOT/sample directory
    as you normally do for an ITK program.

    <b>Sample Implementation</b>

    The \$TC_ROOT/sample/examples/te_template_itk_main.c demonstrate TE functionality.
    These could be compiled and studied to understand how new utilities can be developed.

    <h3>Traversal Engine Selectors</h3>

    One type of Selector called called #TE_NODE_SELECTOR is provided in TE,
    which is executed at each node during the creation of the tree.
    This determines whether a particular branch needs to be built or not.

    The user has to program a Selector similar to the following template:

    @code
        TE_Decision function_name( char*, tag_t, int );

        TE_Decision function_name( char* node_type, tag_t bom_line_tag, int depth )
        {
            printf( "Bom Line Tag is %d", bom_line_tag  );
            return CONTINUE ;
        }
    @endcode

    The first argument is a string set for each node.
    The second argument is the BOM Line tag for each node of the PS and the third is the depth of the node in the PS.

    A TE API call is provided to register this function as the node selector.

    <b>Return Statuses for Selectors</b>
    <ul>
    <li>#TE_CONTINUE - Creation of Tree proceeds normally
    <li>#TE_STOP - Stops the tree creation
    <li>#TE_SKIP - Skip this Node and its branch
    <li>#TE_SKIPCHILDREN - Processes this Node but skips its child nodes
    <li>#TE_GOBACK - This decision is ignored and #TE_CONTINUE is assumed
    </ul>

    <h3>TE Module Calls</h3>

    The traverse engine module presents an interface that allows developing programs that
    do traversal of Teamcenter structures.

    The calls will allow you to:
    <UL>
    <LI>Initialize traversing by setting the top root (this involves PS configuration for PS Traversal)
    <LI>Register different handlers (possibly associating with Node type)
    <LI>Start traversal
    <LI>Retrieve node information
    <LI>Store, retrieve and process node information
    <LI>Obtain preferences from configuration file
    <LI>Display messages to console and log file, to give warnings etc
    </UL>

    For the PS traversal utility, calls will be provided for:
    <UL>
    <LI>PS Configuration (variants, substitutes, pack/unpack settings etc)
    </UL>

    If the function call is not successful,
    the returned integer can be used to get the error message from the EMH module.
    TE errors and other ITK error codes are also possible.

    <b>Common Return Values</b>

    #TE_initialize_failed - TE initialize failed <br>
    #TE_PS_initialize_failed - TE PS module not initialize or failed to initialize <br>
    #TE_file_could_not_be_opened - Specified log/config file could not be opened. <br>
    #TE_could_not_write_to_file - Could not write to file <br>
    #TE_set_null_value - Trying to set a null value <br>
    #TE_could_not_find_sp_item - Could not find specified item <br>
    #TE_could_not_find_sp_item_rev - Could not find specified revision of the item.
                                     Error Notes to Teamcenter logfile <br>
    #TE_bad_return_status - Bad return status from the handler <br>
    #TE_node_selector_not_set - Node Selector not set <br>
    #TE_rt_entry_handler_not_set - Root Entry Handler not set <br>
    #TE_rt_exit_handler_not_set - Root Exit Handler not set <br>
    #TE_at_node_handler_not_set - At Node Handler not set <br>
    #TE_reg_handler_not_set - Registry Handler not set <br>
    #TE_fw_entry_handler_not_set - Forward Entry Handler not set <br>
    #TE_fw_exit_handler_not_set - Forward Exit Handler not set <br>
    #TE_rv_entry_handler_not_set - Reverse Entry Handler not set <br>
    #TE_rv_exit_handler_not_set - Reverse Exit Handler not set <br>
    #TE_entry_not_found_inconfig - Entry not found in config file

    @{
*/

#ifndef TE_MAXLINELEN
    #define TE_MAXLINELEN   256
#endif

#define TE_LW               "Latest Working"
#define TE_LOG_FILE         "te.log"
#define TE_CFG_FILE         "te.cfg"

/*
   Possible pack states
*/
#define TE_PACK         0
#define TE_UNPACK       1
#define TE_PACK_PREF    2

/**
    Traversal Decisions
*/
typedef enum
{
    TE_CONTINUE,
    TE_STOP,
    TE_SKIPCHILDREN,
    TE_GOBACK,
    TE_SKIP
} TE_decision;

/**
    Possible input for TE_ui_print_message()
*/
typedef enum
{
    TE_LOG,
    TE_STDOUT,
    TE_LOGANDSTDOUT
} Output;

/**
    Types of Handlers
*/
typedef enum
{
    TE_NODE_SELECTOR,
    TE_REG_HANDLER,
    TE_ROOT_ENTRY,
    TE_ROOT_EXIT,
    TE_AT_NODE,
    TE_FORWARD_ENTRY,
    TE_FORWARD_EXIT,
    TE_REVERSE_ENTRY,
    TE_REVERSE_EXIT
} HandlerTypes ;

#ifdef __cplusplus
extern "C"
{
#endif

/**
    Typdef for TE function pointer
*/
typedef TE_decision ( *TE_handler_t  )  (
    char*,
    tag_t,
    int
    ) ;

/**
    Specifies which preferences you want to consider when asking for values.
*/
extern ITK_API int TE_init_module();

/**
    Called at the end of the program.
*/
extern ITK_API int TE_exit_module ( void );

/**
    Used for PS traversal. Opens a BOM window internally using the itemid and revision.
    The revision rule, BOM view type and variant that govern the creation of the BOM window must have been set
    using corresponding API calls.
*/
extern ITK_API int TE_PS_initialize(
    const char*    item_id,  /**< (I) Item identification number */
    const char*    rev      /**< (I) Identification of the Item Revision */
    );

/**
    Sets the given file fname as the log file for output.
    This calls opens the log file and returns a non #ITK_ok status if it is unable to open.
    If TE_ui_set_validate_args() is not used then this must be called before using the TE_ui_xxx calls.
*/
extern ITK_API int TE_ui_set_logfile(
    const char*    file_name    /**< (I) Name of the file to be used as logfile */
    );

/**
    Sets the given file fname as the config file,
    which will be used as configuration file for input by the traversal utility.
    This call opens the specified config file in read only mode and returns a non #ITK_ok status if this fails.
    If TE_ui_set_validate_args() is not used then this must be called before using the TE_ui_xxx calls.
*/
extern ITK_API int TE_ui_set_configfile(
    const char*    file_name    /**< (I) */
    );

/**
    Reads in the command line arguments, and stores them internally.
    It also validates the command line arguments and takes in default values when none are provided.
    It will set the log and config file for output and input and must be called before any of the TE_ui_xx calls are called.
    It should be used when you are using the command line arguments.
    If it is not, then other api calls must be used to set the required input for traversing.
*/
extern ITK_API int TE_ui_set_validate_args() ;

/**
    Retrieves the statistics like number of warnings, number of child nodes skipped,
    number of nodes skipped, number of nodes processed etc.
*/
extern ITK_API int TE_get_statistics(
    int*           n_warn,        /**< (O) Number of warnings that occurred. */
    int*           n_skipchild,   /**< (O) Number of child nodes skipped. */
    int*           n_skip,        /**< (O) Number of nodes skipped. */
    int*           n_total        /**< (O) Total number of nodes processed. */
    );

/**
    Increments the Warning Count by 1, each time a warning arises.
    Number of warnings can be found with TE_get_statistics().
*/
extern ITK_API int TE_ui_increment_warnings();

/**
    Creates the tree data structure similar to the PS.
    Runs the function set as #TE_NODE_SELECTOR.
    The return status for this function determines whether a branch needs to be built or not.

    Possible return status for the function registered as #TE_NODE_SELECTOR are #TE_CONTINUE,
    #TE_SKIP and #TE_SKIPCHILDREN.
*/
extern ITK_API int TE_PS_fill_tree ();

/**
    Traverses the built tree and executes the functions registered and the following handlers:

    <UL>
    <LI>#TE_ROOT_ENTRY - Executed when entering the root node.
    <LI>#TE_ROOT_EXIT - Executed when exiting the root node.
    <LI>#TE_AT_NODE - Executed between entry and exit at each node.
    <LI>#TE_FORWARD_ENTRY - Executed when a node is entered from another in  forward direction
    <LI>#TE_FORWARD_EXIT - Executed when a node is left for another in forward direction
    <LI>#TE_REVERSE_ENTRY - Executed when a node is entered from another in reverse direction.
    <LI>#TE_REVERSE_EXIT - Executed when a node is left for another in Reverse direction
    </UL>

    The return of these functions determines the traversal direction.
    Possible return status are #TE_CONTINUE, #TE_SKIP and #TE_GOBACK.
*/
extern ITK_API int TE_PS_traverse_tree ();

/**
    Builds and traverses a tree structure simultaneously.
    This is combination of the TE_PS_fill_tree() and TE_PS_traverse_tree().
*/
extern ITK_API int TE_PS_fill_and_traverse_tree ();

/**
    Stores the float value in the memory with the given key which is a string.
*/
extern ITK_API int TE_table_store_float(
    const char*    key,     /**< (I) String value, which is used as a key to store the float value in a table */
    float          sfloat   /**< (O) Float value, which is stored in the table */
    );

/**
    Takes in the key (String) as the argument and returns the float value which was stored earlier.
*/
extern ITK_API int TE_table_get_float(
    const char*    key,     /**< (I) String value, which is used as a key to store the float value in a table */
    float*         afloat   /**< (O) Value stored for the key */
    );

/**
    Displays the string passed as argument to the stdout/logfile or both.
*/
extern ITK_API int TE_ui_print_message(
    int            output,  /**< (I) #TE_STDOUT: Prints message to stdout only <br>
                                #TE_LOG: Prints message to TE log file only <br>
                                #TE_LOGANDSTDOUT: Prints message to te log file and stdout. */
    int            warn,    /**< (I) TRUE: Increments Warning message count <br>
                                FALSE: Does not increment message count */
    int            ifail,   /**< (I) The ERROR code returned by an ITK call.
                                If not zero then the Error message corresponding to the code also is printed. */
    const char*    msg      /**< (I) String to be printed */
    );

/**
    Retrieves values from the configuration file specified by the fg=option or the API call.
    Takes the token as the first argument and returns the number of the entries under this token and
    the string lists for these entries.
*/
extern ITK_API int TE_get_preference_list(
    const char*    sym,         /**< (I) Required token in config file, which is given as input */
    int*           n_found,     /**< (O) Number of entries under the given token */
    char***        stlist       /**< (OF) n_found String list for the entries under the given token */
    );

/**
    Same as TE_get_preference_list(), but retrieves only one entry for the specified token.
*/
extern ITK_API int TE_get_preference(
    const char*    sym,     /**< (I) Required token in config file, which is given as input */
    char**         pref     /**< (OF) Entry under the given token */
    );


/**
    Retrieves the values entered at the command line or set by
    the corresponding API call for itemid, itemrev, logfile and configfile.
*/
extern ITK_API int TE_PS_ui_get_data2(
char           **item_id,           /**< (OF) Returns itemid set by command line or corresponding api call */
char           **item_rev,          /**< (OF) Returns item revision set by command line or corresponding api call */
char           **log_file,          /**< (OF) Returns logfile name set by command line or corresponding api call */
char           **config_file        /**< (OF) Returns configfile by command line or corresponding api call */
    );

/**
    Sets the node type to that of the argument.
    This is just an additional attribute for each node.
*/
extern ITK_API int TE_node_set_type(
    const char*    node_type    /**< (I) Node type to be set */
    );

/**
    Sets the node parent node type to that of the argument.
*/
extern ITK_API int TE_parentnode_set_type(
    const char*    node_type    /**< (I) Type to be set for the Parent Node */
    );


/**
    Retrieves the data regarding the nodes (number of children and node type).
*/
extern ITK_API int TE_node_get_data2(
    int*           child_nodes,              /**< (O) Number of children for a given node */
    char           **type                   /**< (OF) Type of the given node */
    );

/**
    Retrieves the data regarding the parent node. Returns the nodes parent number of children,
    parent node type and parent node depth.
*/
extern ITK_API int TE_parentnode_get_data(
    int*           child_nodes,  /**< (O) Number of children for a given node */
    char*          type,        /**< (O) Type of the given node */
    tag_t*         tag,         /**< (O) Tag of the parent node */
    int*           depth        /**< (O) Depth of the parent node */
    );

/**
    Sets the bom view type. The saved variant object in Teamcenter database will be
    retrieved and the BOM window configured with this object.
    <br/>If multiple objects are found then the first one will be taken and corresponding warning issued.
    Sets the revision rule for the BOM window. Default is Latest Working. Sets the substitute to es or o.
    It is a switch and later needs to be referred by the selectors or handlers and as such does not have a function.
*/
extern ITK_API int TE_PS_set_config(
    const char*    view_type,    /**< (I) BOM view type to be set */
    const char*    variant,     /**< (I) Variant rule to be set */
    const char*    rev_rule,     /**< (I) Revision rule to be set */
    const char*    sub          /**< (I) Substitute to be set */
    );

/**
    Sets the BOMView type. 
    <br/>The saved variant object in Teamcenter Engineering database will be
    retrieved and the BOM window configured with this object.
    <br/>If multiple objects are found then the first one will be taken and corresponding warning issued.
    Sets the revision rule for the BOM window. Default is Latest Working. Sets the alternate to es or o.
    It is a switch and later needs to be referred by the selectors or handlers and as such does not have a function.
    Sets the pack option on the bomlines. The default is unpacked structure
*/
extern ITK_API int TE_PS_set_config_with_pack(
    const char*    view_type,    /**< (I) BOM view type to be set */
    const char*    variant,     /**< (I) Variant rule to be set */
    const char*    rev_rule,     /**< (I) Revision rule to be set */
    const char*    alt,         /**< (I) Alternate to be set */
    int            pack_state    /**< (I) Pack the structure */
    );

/**
    Retrives the BOM View type, saved variant,
    revision rule set by the API call or the command line and the substitute setting. 
*/
extern ITK_API int TE_PS_get_config_params(
    char**         view_type,    /**< (OF) BOM view type returned */
    char**         variant,     /**< (OF) Variant rule returned */
    char**         rev_rule,     /**< (OF) Revision rule returned */
    char**         sub          /**< (OF) Substitute setting that is returned */
    );

/**
    Retrieves the BOM View type, saved variant,
    revision rule, pack option set by the API call or the command line and the alternate setting.
*/
extern ITK_API int TE_PS_get_config_params_with_pack(
    char**         view_type,    /**< (OF) BOM view type returned */
    char**         variant,     /**< (OF) Variant rule returned */
    char**         rev_rule,     /**< (OF) Revision rule returned */
    char**         alt,         /**< (OF) Alternate setting that is returned */
    int*           pack_state    /**< (O) Pack the structure */
    );

/**
   Sets the function for the required handler type and function name.
*/
extern ITK_API int TE_register_node_handler(
    int            handler_type, /**< (I) Handler to which function is to be attached.<br>
                                    #TE_NODE_SELECTOR - Executed while creation of tree nodes.<br>
                                    #TE_ROOT_ENTRY - Executed when entering the root node.<br>
                                    #TE_ROOT_EXIT - Executed when exiting the root node.<br>
                                    #TE_AT_NODE - Executed between entry and exit at each node.<br>
                                    #TE_FORWARD_ENTRY - Executed when a node is entered from another in forward direction.<br>
                                    #TE_FORWARD_EXIT - Executed when a node is left for another in forward direction.<br>
                                    #TE_REVERSE_ENTRY - Executed when a node is entered from another in reverse direction.<br>
                                    #TE_REVERSE_EXIT - Executed when a node is left for another in reverse direction. */
    TE_handler_t   afun         /**< (I) Function pointer */
    );

extern ITK_API int TE_ui_get_logfile_pointer(
    FILE**         logfile   /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <itk/libitk_undef.h>

#endif

