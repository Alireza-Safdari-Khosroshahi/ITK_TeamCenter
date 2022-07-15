/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef POM_OLD_ON_NEW_H
#define POM_OLD_ON_NEW_H

#include <pom/pom/pom_typedefs.h>

#include <pom/pom/libpom_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @addtogroup ENQ
    @{
*/

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_int(
    tag_t       classid,    /**< (I) */
    tag_t       attrid,     /**< (I) */
    int         op,         /**< (I) */
    const int*  val,        /**< (I) 1 */
    tag_t*      enqid       /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_int but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_ints(
    tag_t       classid,    /**< (I) */
    tag_t       attrid,     /**< (I) */
    int         op,         /**< (I) */
    int         start,      /**< (I) */ 
    int         n_values,   /**< (I) */ 
    const int*  val,        /**< (I) n_values */
    tag_t*      enqid       /**< (O) */
    );

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_char(
    tag_t       classid,    /**< (I) */
    tag_t       attrid,     /**< (I) */
    int         op,         /**< (I) */
    const char* val,        /**< (I) 1 */
    tag_t*      enqid       /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_char but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_chars(
    tag_t       classid,    /**< (I) */
    tag_t       attrid,     /**< (I) */
    int         op,         /**< (I) */
    int         start,      /**< (I) */ 
    int         n_values,   /**< (I) */ 
    const char* val,        /**< (I) n_values */
    tag_t*      enqid       /**< (O) */
    );

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_string(
    tag_t  classid,     /**< (I) */
    tag_t  attrid,      /**< (I) */
    int    op,          /**< (I) */
    char** val,         /**< (I) 1 */
    tag_t* enqid        /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_string but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_strings(
    tag_t  classid,     /**< (I) */
    tag_t  attrid,      /**< (I) */
    int    op,          /**< (I) */
    int    start,       /**< (I) */ 
    int    n_values,    /**< (I) */ 
    char** val,         /**< (I) n_values */
    tag_t* enqid        /**< (O) */
    );

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_double(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    const double*   val,        /**< (I) 1 */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_double but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_doubles(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    int             start,      /**< (I) */ 
    int             n_values,   /**< (I) */
    const double*   val,        /**< (I) n_values */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_date(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    const date_t*   val,        /**< (I) 1 */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_date but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_dates(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    int             start,      /**< (I) */ 
    int             n_values,   /**< (I) */ 
    const date_t*   val,        /**< (I) n_values */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_logical(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    const logical*  val,        /**< (I) 1 */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_logical but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_logicals(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    int             start,      /**< (I) */ 
    int             n_values,   /**< (I) */
    const logical*  val,        /**< (I) n_values */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This corresponds to the SQL:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute\> \<operator\> \<value\>); 

    Where \<class\>, \<attribute\>, \<operator\>, and \<value\> correspond to
    the values handed to the POM function, and the internal_uid is purely internal to POM
    (it never appears through the POM interface).
    The value is passed in as a pointer so that the enquiry can be reused later with a different set of values.

    This function does not execute the enquiry.

    For string-value attributes, value can contain valid SQL wildcards.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_tag(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    const tag_t*    val,        /**< (I) 1 */
    tag_t*          enqid       /**< (O) */
    );

/**
    Creates an enquiry. This is similar to #POM_create_enquiry_on_tag but applies to array-valued attributes.
    The enquiry can still be reused later with a different set of values.

    @note This function accepts the date in local time.
*/
POMAPI int POM_create_enquiry_on_tags(
    tag_t           classid,    /**< (I) */
    tag_t           attrid,     /**< (I) */
    int             op,         /**< (I) */
    int             start,      /**< (I) */ 
    int             n_values,   /**< (I) */
    const tag_t*    val,        /**< (I) n_values */
    tag_t*          enqid       /**< (O) */
    );

/**
    Combines two enquiries to create a new one.

    If enq1 and enq2 correspond to:

    SELECT internal_uid FROM (\<class\> WHERE \<attribute1\> \<operator1\> \<value1\>);

    SELECT internal_uid FROM (\<class\> WHERE \<attribute2\> \<operator2\> \<value2\>);

    then the combination corresponds to:

    SELECT internal_uid FROM (\<class\> WHERE (\<attribute1\> \<operator1\> \<value1\>)
    \<conjunction\> (\<attribute2\> \<operator2\> \<value2\>));

    For example:

    SELECT internal_uid FROM employee WHERE (salary \> 5000) AND (title \<\> "Manager");

    This does not delete the original enquiries, 
    so for instance they can be recombined with a different conjunction.

    There are two basic combination tokens that can be used to combine two enquiries.
    There is also a modifier token that can be used in combination with
    these basic tokens to generate two further combination tokens:

    <table>
    <tr><td>Simple Tokens</td><td>Composite Tokens</td><td>Modifier Tokens</td></tr>
    <tr><td>#POM_and</td>     <td>#POM_nand</td>       <td>#POM_not</td></tr>
    <tr><td>#POM_or</td>      <td>#POM_nor</td>        <td></td></tr>
    </table>
*/
POMAPI int POM_combine_enquiries(
    tag_t  enq1,    /**< (I) ID of first enquiry */
    int    op,      /**< (I) Token for combination of enquiries - "and", "or", etc. */
    tag_t  enq2,    /**< (I) ID of second enquiry */ 
    tag_t* new_enq  /**< (O) ID of combined enquiry */
    );

/**
    Executes the specified enquiry.

    This enquiry may have been built up by several calls to POM_create_enquiry_on_\<type\>,
    POM_create_enquiry_on_\<type\>s, #POM_create_enquiry_on_ids, 
    #POM_create_enquiry_on_ref and #POM_combine_enquiries.

    If nval is 0, then values is NULL.

    This function is provided for completeness.

    Usually the enqid is handed to a function like #POM_load_instances_by_enq,
    which executes the enquiry and acts on the instances which the enquiry produces.
*/
POMAPI int POM_execute_enquiry ( 
    tag_t   enqid,  /**< (I) ID of enquiry to execute */ 
    int*    nval,   /**< (O) Number of selected instances */ 
    tag_t** values  /**< (OF) nval Tags of selected instances */
    );

/**
    Deletes the specified enquiries.
*/
POMAPI int POM_delete_enquiries (
    int             n_enquiry,  /**< (I) Number of enquiries to delete */ 
    const tag_t*    enqid       /**< (I) n_enquiry ID of enquiries to delete */
    );

/**
    Specifies the order in which to produce the instances.

    Each attribute can be ordered in ascending or descending order.
    The instances are ordered on the value of each attribute in turn, starting with the first attribute in the array.

    This function can be used to override a previously specified order, 
    so that for instance the same enquiry_id can be used more than once to produce different orderings of the same instances.
*/
POMAPI int POM_order_enquiry(
    tag_t           enq1,               /**< (I) ID of enquiry, the result of which is to be ordered. */
    int             n_attrs,            /**< (I) Number of attributes to use for ordering */
    const tag_t*    attr_ids,           /**< (I) n_attrs IDs of attributes to use for ordering */ 
    const int*      up_or_down_tokens   /**< (I) n_attrs Array of tokens for whether to order attribute values in 
                                            ascending or descending order such as #POM_order_ascending or #POM_order_descending */
    );

/**
    This is used to build a query where the tag of some set of instances is already known.
    This is distinct from creating an enquiry on tag attributes,
    since the objects own identity is not accessed as a regular attribute.
    A trivial example of the use of this function would be to take a list of instance and
    filter this by some set of attributes to get a shorter list of instances qualifying before loading same.

    Example

    A more realistic example might be to find which revisions of an item contain
    a reference to a "production" release status. In this example the tags used are:

    <table>
    <tr><td>rs_c</td>  <td>ReleaseStatus class tag.</td></tr>
    <tr><td>name_a</td><td>name attribute tag in releasestatus class.</td></tr>
    <tr><td>wso_c</td> <td>WorkSpaceObject class tag.</td></tr>
    <tr><td>rsl_a</td> <td>release_status_list attr tag in workspaceobject class.</td></tr>
    <tr><td>strptr</td><td>Pointer to a buffer containing the text "production."</td></tr>
    <tr><td>insts</td> <td>Input list of item revisions. 
                        found is the subset of that list that have a release status of "production."</td></tr>
    </table>

    @code
        ifail = POM_create_enquiry_on_string (rs_c, name_a, POM_is_equal_to, &strptr, &enq1);
        check_fail(ifail);
        
        ifail = POM_create_enquiry_on_ref (wso_c, rsl_a, POM_has_reference_to, &enq1, &enq2);
        check_fail(ifail);
        
        ifail = POM_create_enquiry_on_ids (no_insts, insts, &enq3);
        check_fail(ifail);
        
        ifail = POM_combine_enquiries (enq2, POM_and, enq3, &enq4);
        check_fail(ifail);
        
        ifail = POM_execute_enquiry(enq4, &nofound, &found);
        check_fail(ifail); 
    @endcode
*/
POMAPI int POM_create_enquiry_on_ids(
    int             n_ids,      /**< (I) Number of instance tags to be supplied */
    const tag_t*    ids,        /**< (I) n_ids Tags of instance */
    tag_t*          new_enq     /**< (O) ID for enquiry */
    );

/**
    Creates an enquiry based on a reference attribute 
    (type #POM_typed_reference or #POM_untyped_reference) and an existing enquiry (subenquiry).

    The enquiry produced can act in one of two ways, controlled by the operator token:
    <ul>
    <li>#POM_has_reference_to In this mode, it selects instances of the class_id which have references
                             (via attr_id) to instances which satisfy the enquiry.
    <li>#POM_is_referenced_by In this mode, it selects whatever is referenced by the reference attribute
                              attr_id by the instances of class_id that satisfy the enquiry.
    </ul>
    This function does not execute the enquiry.

    The subenquiry is passed in as a reference to an enquiry ID so that
    the enquiry created with this function can be executed several times with different sub enquiries.

    If the attribute specified by attr_id is an array type attribute (fixed or variable length)
    then the functionality of the operation is as follows:
    <ul>
    <li>#POM_has_reference_to - Returns all instances that have one or more references in the array attribute
                                to the instances satisfying the subenquiry.  
    <li>#POM_is_referenced_by - Returns all the values in the array attribute for all instances
                                that are selected by the sub-enquiry.
    </ul>
    Example

    Select all users that are linked to the group "DBA" via one (or more) GroupMember objects, then:
    <ul>
    <li>Create an enquiry selecting all Groups that have the name "DBA" - call this enquiry ENQ1;
    <li>Using #POM_create_enquiry_on_ref, create an enquiry over the class "GroupMember" (attribute "group")
        that has-reference-to the instances returned by the enquiry ENQ1.
        This enquiry, ENQ2, returns all the GroupMember objects that reference the Group "DBA."
    <li>Create a third enquiry ENQ3, again over the class "GroupMember" but this time using the attribute "user",
        which returns any object which is-referenced-by the GroupMember objects selected by ENQ2.
    <li>The result of ENQ3 is the list of Users that are members of the "DBA" Group. 
    </ul>

    There are seven basic tokens that describe the type of enquiry comparison that can be used,
    and two "modifier" tokens that can be added to the basic tokens to form composite tokens 
    (five of which are supplied for compatibility with earlier releases).

    <table>
    <tr><td>Simple Tokens</td>        <td>Composite Tokens</td>        <td>Modifier Tokens</td></tr>
    <tr><td>#POM_is_equal_to</td>     <td>#POM_is_not_equal_to</td>    <td>#POM_not</td></tr>
    <tr><td>#POM_is_greater_than</td> <td>#POM_is_not_greater_than</td><td>#POM_case_insensitive</td></tr>
    <tr><td>#POM_is_less_than</td>    <td>#POM_is_not_less_than</td>   <td></td></tr>
    <tr><td>#POM_is_null</td>         <td>#POM_is_not_null</td>        <td></td></tr>
    <tr><td>#POM_is_like</td>         <td>#POM_is_not_like</td>        <td></td></tr>
    <tr><td>#POM_has_reference_to</td><td></td>                        <td></td></tr>
    <tr><td>#POM_is_referenced_by</td><td></td>                        <td></td></tr>
    </table>
*/
POMAPI int POM_create_enquiry_on_ref(
    tag_t           classid,        /**< (I) ID of class from which to select instances */
    tag_t           attrid,         /**< (I) ID of attribute to use for selection */
    int             op,             /**< (I) Token for operator - "equal to", "greater than", etc. */
    const tag_t*    subenquiry,     /**< (I) 1 Value to compare with value of attribute */
    tag_t*          enqid           /**< (O) */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <pom/pom/libpom_undef.h>

#endif

