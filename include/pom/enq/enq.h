/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/*  */

#ifndef ENQ_H
#define ENQ_H

#include <unidefs.h>
#include <common/tc_deprecation_macros.h>
#include <pom/pom/libpom_exports.h>

/** @if DOX_IGNORE
    Anything after the next line will be read by process_pif_file,
    please stick to the standard formatting to avoid indigestion
@endif */

/* END OF HEADER */

#ifdef __cplusplus
    extern "C"{
#endif

/**
    @defgroup ENQ Enquiry (ENQ)
    @ingroup POM
    <b>Supported Operators</b>

    <table>
    <tr><td>#POM_enquiry_equal          </td><td>#POM_enquiry_not_equal         </td></tr>
    <tr><td>#POM_enquiry_greater_than   </td><td>#POM_enquiry_greater_than_or_eq</td></tr>
    <tr><td>#POM_enquiry_less_than      </td><td>#POM_enquiry_less_than_or_eq   </td></tr>
    <tr><td>#POM_enquiry_between        </td><td>#POM_enquiry_not_between       </td></tr>
    <tr><td>#POM_enquiry_like           </td><td>#POM_enquiry_not_like          </td></tr>
    <tr><td>#POM_enquiry_in             </td><td>#POM_enquiry_not_in            </td></tr>
    <tr><td>#POM_enquiry_exists         </td><td>#POM_enquiry_not_exists        </td></tr>
    <tr><td>#POM_enquiry_is_null        </td><td>#POM_enquiry_is_not_null       </td></tr>
    <tr><td>#POM_enquiry_union          </td><td>#POM_enquiry_unionall          </td></tr>
    <tr><td>#POM_enquiry_intersection   </td><td>#POM_enquiry_difference        </td></tr>
    <tr><td>#POM_enquiry_substr         </td><td>#POM_enquiry_upper             </td></tr>
    <tr><td>#POM_enquiry_lower          </td><td>#POM_enquiry_rtrim             </td></tr>
    <tr><td>#POM_enquiry_ltrim          </td><td>#POM_enquiry_length            </td></tr>
    <tr><td>#POM_enquiry_concat         </td><td>#POM_enquiry_max               </td></tr>
    <tr><td>#POM_enquiry_min            </td><td>#POM_enquiry_avg               </td></tr>
    <tr><td>#POM_enquiry_sum            </td><td>#POM_enquiry_countall          </td></tr>
    <tr><td>#POM_enquiry_countdist      </td><td>#POM_enquiry_and               </td></tr>
    <tr><td>#POM_enquiry_or             </td><td>#POM_enquiry_plus              </td></tr>
    <tr><td>#POM_enquiry_minus          </td><td>#POM_enquiry_divide            </td></tr>
    <tr><td>#POM_enquiry_multiply       </td><td>#POM_array_length_equals       </td></tr>
    <tr><td>#POM_array_length_not_equals</td><td>#POM_enquiry_tonumber          </td></tr>
    <tr><td>#POM_enquiry_uid_of         </td><td>#POM_enquiry_cpid_of           </td></tr>
    <tr><td>#POM_enquiry_nvl            </td><td>                               </td></tr>
    </table>

    <b>Tokens</b>

    #POM_enquiry_asc_order <br>
    #POM_enquiry_desc_order <br>
    #POM_enquiry_bind_value <br>
    #POM_enquiry_const_value

    <b>Common Return Values</b>

    <table>
    <tr><td>#ENQ_invalid_attribute </td><td>One of the following: <br>
                                            String class is not a valid POM_class name <br>
                                            String class is not a valid class alias <br>
                                            String class is not a valid pseudo class <br>
                                            String attribute is not a valid attribute of the class</td></tr>
    <tr><td>#ENQ_invalid_class     </td><td>The class string is not a valid POM_class.            </td></tr>
    <tr><td>#ENQ_invalid_expression</td><td>Either the class is not a valid class name or
                                            the attribute-expression is not a valid expression.   </td></tr>
    <tr><td>#ENQ_invalid_value     </td><td>No value exists with this identifier ID.              </td></tr>
    <tr><td>#POM_op_not_supported  </td><td>The operator is not supported.                        </td></tr>
    <tr><td>#POM_wrong_attr_type   </td><td>Attribute type is one of the following: <br>
                                            #POM_untyped_reference <br>
                                            #POM_typed_reference <br>
                                            #POM_external_reference <br>
                                            and operator is one of the following:  <br>
                                            #POM_enquiry_greater_than <br>
                                            #POM_enquiry_greater_than_or_eq <br>
                                            #POM_enquiry_less_than <br>
                                            #POM_enquiry_less_than_or_eq <br>
                                            #POM_enquiry_like <br>
                                            #POM_enquiry_not_like <br>
                                            #POM_enquiry_between <br>
                                            #POM_enquiry_not_between                              </td></tr>
    </table>

    @{
*/

/**
    Creates a new enquiry.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must not be the name of an query that already exists within the user's current session.
    </ol>
*/
POMAPI int POM_enquiry_create(
    const char*     enq_id   /**< (I) The id to be given to the new query */
    );

/**
    Creates a new sub-query on an existing query.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must be the name of a query that already exists within the user's current session.
    <li> sub_enq_id must not be the name of an query that already exists within the user's current session.
    </ol>
*/
POMAPI int POM_enquiry_set_sub_enquiry(
    const char*     enq_id,          /**< (I) The query one which the new sub-query is to be created */
    const char*     sub_enq_id       /**< (I) The id to be given to the new sub-query */
    );

POMAPI int POM_enquiry_set_setenquiry(
    const char*     enq_id,          /**< (I) */
    const char*     q1               /**< (I) */
    );

/**
    Adds a list of attributes to the select clause of the query.

    This method allows the caller to specify one or more simple attributes whose values a query is to return.

    Adding an attribute that has already been added to the select clause may or may not add it again.

    <b>Restrictions:</b>

    <ol>
    <li> enq_id must identify an existing query within the user's current session.
    <li> aclass must be one of the following:
        <ul>
        <li>A valid POM_class name
        <li>A valid class alias defined in the query
        <li>A valid pseudo class defined in the query
        <li>A valid Tc type
        </ul>
    <li> n must be a positive integer
    <li> attrs must be a valid array of n_attrs C strings, where each string is one of
        <ul>
        <li>A valid POM attribute defined on aclass
        <li>A supported Tc compound property defined on aclass
        </ul>
    </ol>

*/
POMAPI int POM_enquiry_add_select_attrs(
    const char*     enq_id,     /**< (I) The query whose selected clause is to be modified */
    const char*     aclass,     /**< (I) The POM class, class or pseudo-class alias or Tc type that the user wants to query */
    int             n_attrs,    /**< (I) The Number of attributes to be added to query's select clause */
    const char**    attrs       /**< (I) The List of attributes to be added */
    );

/**
    Adds a list of attribute-expressions to the select clause of the query.

    This method allows the caller to specify one or more evaluated expressions whose values a query is to return.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> n_expr_ids must be a positive integer
    <li> expr_ids must be a valid array of n_expr_ids C strings, where each string identifies an existing expression in the query.
         Note that expressions added to select clause cannot have bind variables. Use constant values instead.
    </ol>
*/
POMAPI int POM_enquiry_add_select_exprs(
    const char*     enq_id,     /**< (I) The query whose select clause is to be modified */
    int             n_expr_ids, /**< (I) The number of attribute-expressions to be added to the query's select clause */
    const char**    expr_ids    /**< (I) The list of attribute-expressions identifiers */
    );

/**
    Creates an attribute-expression from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> an optional right hand operand
    </ol>

    This method allows the caller to create a new expression from an attribute, an operator, and an optional expression, value or query.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must not be the name of an existing expression on the query
    <li> aclass - as #POM_enquiry_add_select_attrs
    <li> attr must be one of
        <ul>
        <li>A valid POM attribute defined on aclass, or
        <li>A supported Tc compound property defined on aclass
        </ul>
    <li>op must be a valid POM enquiry operator whose operation must be suitable for the inputs, attr and rhs_id
    <li> rhs_id must be one of the following
        <ul>
        <li>The identifier of an expression that has been defined previously on the query
        <li>The identifier of a value that has been defined previously on the query
        <li>The identifier of an existing query
        <li>The empty string, "" (which is specified if and only if op is a unary operator)
        </ul>
    </ol>
*/
POMAPI int POM_enquiry_set_attr_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The class, alias or type that owns attr */
    const char*     attr,       /**< (I) The attribute or supported compound property that is to form the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    const char*     rhs_id      /**< (I) The identifier of the right hand operand */
    );

/**
    Sets the where clause of the query to the specified expression.

    Calling this function replaces the query's existing where clause, if it has been set.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must identify an existing expression on the query, and the expression must evaluate to either true or false
    </ol>
*/
POMAPI int POM_enquiry_set_where_expr(
    const char*     enq_id,      /**< (I) The query whose where clause is to be set */
    const char*     expr_id      /**< (I) The id of an existing expression defined on the query */
    );

/**
    Sets the having clause of the query to the specified expression.

    Calling this function replaces the query's existing having clause, if it has been set.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must identify an existing expression on the query
    </ol>
*/
POMAPI int POM_enquiry_set_having_expr(
    const char*     enq_id,     /**< (I) The query whose having clause is to set */
    const char*     expr_id     /**< (I) The id of an existing expression defined on the query */
    );

/**
    Sets the set-expression of the outer query.

    The two enquiries defined by query and rhs_id identifiers must be union-compatible, that is,
    they must have the same number of attributes selected, and the attributes must respectively be of the same domain.

    <b>Restrictions: </b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>set_expr_id must be a unique identifier within the query.
    <li>set_op must be one of the following
        <ul>
        <li>#POM_enquiry_union
        <li>#POM_enquiry_unionall
        <li>#POM_enquiry_intersection
        <li>#POM_enquiry_difference
        </ul>
    <li>rhs_id must identify either a sub-query or a set-expression on the query.
    </ol>
*/
POMAPI int POM_enquiry_set_setexpr(
    const char*     enq_id,       /**< (I) The query that is to be modified */
    const char*     set_expr_id,  /**< (I) The identifier of the left hand set operand */
    int             set_op,       /**< (I) A set-expression operator */
    const char*     rhs_id        /**< (I) The sub-query or a set-expression that defines the right hand set operand */
    );

/**
    Creates a class alias for a POM_class, a Tc type or an external table in the database. Once created,
    the class alias can be used in place of the name of the class, type or table.
    The most of common use for class aliases to construct queries that have a self-join, such as in the
    classic example of finding those employees whose manager is X.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query.
    <li> If pom_class is true, then aclass must be one of the following:
        <ul>
        <li>A valid POM_class name
        <li>A valid Tc type
        </ul>
        Otherwise, if pom_class is false, aclass must the name of table that has been previously registered
        through a call to POM_enquiry_register_table.
    <li> alias must not be a POM_class, neither can be the name of one of the query's existing aliases.
    </ol>

    Note that, although it is not recommended, aliases may be given the same names as existing Tc types.
    In queries where this occurs, POM enquiry will always take the name to refer to the alias, and not the type.

*/
POMAPI int POM_enquiry_create_class_alias(
    const char*     enq_id,         /**< (I) The query that is to own the new class alias */
    const char*     aclass,         /**< (I) The name of the POM class, Tc type or registered table to which the alias is to refer */
    logical         is_pom_class,   /**< (I) true if aclass is a class or type; false if it is a registered table */
    const char*     alias           /**< (I) The name of the class alias that is to be created */
    );

/**
    Adds an attribute-expression to the group-by clause of the query.

    This method allows the caller to specify a grouping based on the value of an arbitrary attribute-expression.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must identify an existing expression on the query
    </ol>
*/
POMAPI int POM_enquiry_add_group_expr(
    const char*     enq_id,     /**< (I) The query whose group-by clause is to be modified */
    const char*     expr_id     /**< (I) The id of an existing expression on the query */
    );

/**
    Adds an attribute-expression to the order-by clause of the query.

    This method allows the caller to specify an ordering based on the value of an arbitrary attribute-expression.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must identify an existing expression on the query
    <li> sort_order must be one of
      <ul>
      <li> POM_enquiry_asc_order
      <li> POM_enquiry_desc_order
      </ul>
    </ol>
*/
POMAPI int POM_enquiry_add_order_expr(
    const char*     enq_id,     /**< (I) The query whose order-by clause is to be modified */
    const char*     expr_id,    /**< (I) The id of an existing expression on the query */
    int             sort_order  /**< (I) Whether the results are to be sorted in ascending or descending order */
    );

/**
    Adds an attribute to the group-by clause of the query.

    This method allows the caller to specify a grouping based on an attribute value.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> aclass - as #POM_enquiry_set_attr_expr
    <li> attr - as #POM_enquiry_set_attr_expr
    </ol>
*/
POMAPI int POM_enquiry_add_group_attr(
    const char*     enq_id,     /**< (I) The query whose group-by clause is to be modified */
    const char*     aclass,     /**< (I) The name of the class, alias or type that owns the attribute */
    const char*     attr        /**< (I) The name of the attribute or property to be added to the group-by clause */
    );

/**
    Adds an attribute to the order-by clause of the query.

    This method allows the caller to specify a ordering based on an attribute value.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> aclass - as #POM_enquiry_set_attr_expr
    <li> attr - as #POM_enquiry_set_attr_expr
    <li> sort_order must be one of
      <ul>
      <li> #POM_enquiry_asc_order
      <li> #POM_enquiry_desc_order
      </ul>
    </ol>
*/
POMAPI int POM_enquiry_add_order_attr(
    const char*     enq_id,     /**< (I) The query whose order-by clause is to be modified */
    const char*     aclass,     /**< (I) The name of the class, alias or type that owns the attribute */
    const char*     attr,       /**< (I) The name of the attribute or property to be added to the order-by clause */
    int             sort_order  /**< (I) Whether the results are to be sorted in ascending or descending order */
    );

/**
    Creates an attribute-expression that can be used in any of the query clauses.

    This method allows the caller to create a new expression from other expressions, values and / or queries. Once created,
    such an expression can be used in other expressions, or in the query's various clauses. Not all expressions can be
    used in all places, though; the normal restrictions of SQL apply. To give an obvious example, only expressions that
    evaluate to true or false can be used in the query's where clause.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query
    <li>expr_id must not be the name of an existing expression in the query
    <li>lhs_id must be one of
      <ul>
      <li> the identifier of an existing expression in the query
      <li> the identifier of an existing value in the query
      <li> the identifier of an existing query
      <li> the empty string, ""
      </ul>
    <li>op must be a valid POM enquiry operator whose operation must be suitable for the inputs, lhs_id and rhs_id
    <li>rhs id - as lhs_id
    </ol>
*/

POMAPI int POM_enquiry_set_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     lhs_id,     /**< (I) The id of the left hand operand */
    int             op,         /**< (I) The expression operator */
    const char*     rhs_id      /**< (I) The id of the right hand operand  */
    );

/**
    Creates an expression that adds a theta-join from one class to another. The join is based on comparing values of an attribute
    on one class with the values of an attribute on the other. The comparison can be =, \<, or \<= (except for external references
    where only = is allowed).

    The caller must ensure that the expression created is ANDed into the query's where expression.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must not be the id of any of the query's existing expressions
    <li> aclass1 - as #POM_enquiry_set_attr_expr
    <li> attr1 - as #POM_enquiry_set_attr_expr
    <li> op must be one of
      <ul>
      <li> #POM_enquiry_equal
      <li> #POM_enquiry_less_than
      <li> #POM_enquiry_less_than_or_eq
      </ul>
    <li> aclass2 - as #POM_enquiry_set_attr_expr
    <li> attr2 - as #POM_enquiry_set_attr_expr
    </ol>
*/
POMAPI int POM_enquiry_set_join_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The identifier to be given to the new expression */
    const char*     aclass1,    /**< (I) The name of the class, alias or type on the left of the join */
    const char*     attr1,      /**< (I) The attribute used to join the left hand class */
    int             op,         /**< (I) The operator used to create the join */
    const char*     aclass2,    /**< (I) The name of the class, alias or type on the right of the join */
    const char*     attr2       /**< (I) The attribute used to join the left hand class */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> an integer value
    </ol>

    This method is provided as a convenient way of making an expression using an integer value.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must not be the name of an existing expression on the query
    <li> aclass - as #POM_enquiry_set_attr_expr
    <li> attr - as #POM_enquiry_set_attr_expr
    <li> op must be a valid POM enquiry operator whose operation must be suitable for the inputs, attr and rhs_val
    </ol>

*/
POMAPI int POM_enquiry_set_int_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    int             rhs_val     /**< (I) An integer constant that acts as the right hand operand */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> a double value
    </ol>

    This method is provided as a convenient way of making an expression using a double value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_double_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    double          rhs_val     /**< (I) A double constant that acts as the right hand operand */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> a date value
    </ol>

    This method is provided as a convenient way of making an expression using a date value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_date_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    date_t          rhs_val     /**< (I) A date_t constant that acts as the right hand operand */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> a char value
    </ol>

    This method is provided as a convenient way of making an expression using a char value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_char_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    char            rhs_val     /**< (I) A char constant that acts as the right hand operand */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> a string value
    </ol>

    This method is provided as a convenient way of making an expression using a string value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_string_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    const char*     rhs_val     /**< (I) A C string that acts as the right hand operand */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> a logical value
    </ol>

    This method is provided as a convenient way of making an expression using a logical value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_logical_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    logical         rhs_val     /**< (I) A constant logical value that acts as the right hand operand */
    );

/**
    Creates an attribute-expression on a query from
    <ol>
    <li> an attribute (the left hand operand)
    <li> an operator
    <li> a tag value
    </ol>

    This method is provided as a convenient way of making an expression using a tag value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.

*/
POMAPI int POM_enquiry_set_tag_expr(
    const char*     enq_id,     /**< (I) The query that is to own the new expression */
    const char*     expr_id,    /**< (I) The id to be given to the new expression */
    const char*     aclass,     /**< (I) The POM class, alias or Tc type that owns the attribute */
    const char*     attr,       /**< (I) The attribute or supported compound property of aclass that acts as the left hand operand */
    int             op,         /**< (I) The attribute-expression operator */
    tag_t           rhs_val     /**< (I) A constant tag value that acts as the right hand operand */
    );

/**
    Creates an integer value on a query.

    The value can be a constant or a bind value. Constant values remain the same each time the query is executed.
    Bind values can have different values from one execution to another; their values must be set prior to each execution.

    The value can be a single scalar value or a list of values.

    The value can be used in any of the query's expression definitions.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> val_id must not be the name of any of the query's existing values
    <li> n_vals must be a positive integer
    <li> vals must be a C array of n_vals values
    <li> propriety must be either #POM_enquiry_bind_value or #POM_enquiry_const_value
    </ol>
*/
POMAPI int POM_enquiry_set_int_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const int*      vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specifies whether the value is a constant or a bind value */
    );

/**
    Creates a double value on a query.

    For details, see #POM_enquiry_set_int_value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_double_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const double*   vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specified whether the value is a constant or a bind value */
    );

/**
    Creates a char value on a query.

    For details, see #POM_enquiry_set_int_value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_char_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const char*     vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specifies whether the value is a constant or a bind value */
    );

/**
    Creates a string value on a query.

    For details, see #POM_enquiry_set_int_value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.
*/
POMAPI int POM_enquiry_set_string_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const char**    vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specifies whether the value is a constant or a bind value */
    );

/**
    Creates a logical value on a query.

    For details, see #POM_enquiry_set_int_value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.

*/
POMAPI int POM_enquiry_set_logical_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const logical*  vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specifies whether the value is a constant or a bind value */
    );

/**
    Creates a date value on a query.

    For details, see #POM_enquiry_set_int_value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.

*/
POMAPI int POM_enquiry_set_date_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const date_t*   vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specifies whether the value is a constant or a bind value */
    );

/**
    Creates a tag value on a query.

    For details, see #POM_enquiry_set_int_value.

    <b>Restrictions:</b>
    See #POM_enquiry_set_int_value.

*/
POMAPI int POM_enquiry_set_tag_value(
    const char*     enq_id,     /**< (I) The query that is to own the new value */
    const char*     val_id,     /**< (I) The id to be given to the new value */
    int             n_vals,     /**< (I) The number of values in the list (use 1 for a single scalar value) */
    const tag_t*    vals,       /**< (I) The list of n_vals values */
    int             propriety   /**< (I) Specifies whether the value is a constant or a bind value */
    );
/**

*/
POMAPI int POM_enquiry_set_id(
    const char*     enq_id,     /**< (I) */
    char**          id          /**< (OF) */
    );

/**
    Combines two sub-enquiries into one.
    The two sub-enquiries must be defined within the scope of the outer enquiry.
    This is useful if you have a query that looks like the following:

    QUERY-1 UNION QUERY-2 UNION QUERY-3

    In this case: define QUERY-2 and QUERY-3 as sub-enquiries of QUERY-1, <br>
    then use #POM_enquiry_combine_enquiry to create a set-expression using QUERY-2 and QUERY-3. <br>
    Finally, use #POM_enquiry_set_setexpr to set the set-expression of the outer query QUERY-1.

    <b>Restrictions:</b>
    <ol>
    <li>The enq_id must have already been defined
    <li>The set_expr_id must be a unique identifier within the query
    <li>The lhs_id must be a sub-enquiry or a set-expression.
    <li>The rhs_id must be either a sub-enquiry or a set-expression but never NULL.
    <li>The set_operator must be one of the following tokens:
        <ul>
        <li>#POM_enquiry_union
        <li>#POM_enquiry_unionall
        <li>#POM_enquiry_intersection
        <li>#POM_enquiry_difference
        </ul>
    <li>Neither rhs_id nor lvalue can be enq_id.
    <li>The two enquiries defined by the lvalue and rhs_id identifiers must be union-compatible.
        This means that the two enquiries must have the same number of attributes selected,
        and the attributes must respectively be of the same domain.
    </ol>
*/
POMAPI int POM_enquiry_combine_enquiry(
    const char*     enq_id,         /**< (I) The query that is to be modified */
    const char*     set_expr_id,    /**< (I) The id to be given to the new expression */
    const char*     lhs_id,         /**< (I) Either a sub-enquiry or a set-expression */
    int             set_operator,   /**< (I) Set-expression operator */
    const char*     rhs_id          /**< (I) Either be a sub-enquiry or a set-expression */
    );

/**
    This function returns information about the integer value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing integer values.
    </ol>
*/
POMAPI int POM_enquiry_ask_int_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n_vals,     /**< (O) The number of values the value contains */
    int**           vals        /**< (OF) The list of n_vals values */
    );

/**
    This function returns information about the double value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing double values.
    </ol>
*/
POMAPI int POM_enquiry_ask_double_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n,          /**< (O) The number of values the value contains */
    double**        vals        /**< (OF) The list of n_vals values */
    );

/**
    This function returns information about the char value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing char values.
    </ol>
*/
POMAPI int POM_enquiry_ask_char_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n_vals,     /**< (O) The number of values the value contains */
    char**          vals        /**< (OF) The list of n_vals values */
    );

/**
    This function returns information about the date value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing date values.
    </ol>
*/
POMAPI int POM_enquiry_ask_date_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n,          /**< (O) The number of values the value contains */
    date_t**        vals        /**< (OF) The list of n_vals values */
    );

/**
    This function returns information about the logical value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing logical values.
    </ol>
*/
POMAPI int POM_enquiry_ask_logical_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n,          /**< (O) The number of values the value contains */
    logical**       vals        /**< (OF) The list of n_vals values */
    );

/**
    This function returns information about the string value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing string values.
    </ol>
*/
POMAPI int POM_enquiry_ask_string_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n,          /**< (O) The number of values the value contains */
    char***         vals        /**< (OF) The list of n_vals values */
    );

/**
    This function returns information about the tag value identified by val_id.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>val_id must identify one of the query's existing tag values.
    </ol>
*/
POMAPI int POM_enquiry_ask_tag_value(
    const char*     enq_id,     /**< (I) The query that owns the value */
    const char*     val_id,     /**< (I) The value's id */
    int*            n,          /**< (O) The number of values the value contains */
    tag_t**         vals        /**< (OF) The list of n_vals values */
    );

/**
    Allows the caller to specify whether the query results should contain duplicate rows or not.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    </ol>

*/
POMAPI int POM_enquiry_set_distinct(
    const char*     enq_id,    /**< (I) The query that is to be modified */
    logical         on         /**< (I) true => the results will contain no duplicate rows;
                                        false => the results may contain duplicate rows */
    );

/**
    Allows the caller to set a hint that can be used in Oracle databases to improve query performance.
    Setting query hints requires internal understanding of POM enquiry and advanced knowledge of Oracle.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    </ol>
*/
POMAPI int POM_enquiry_set_query_hint(
    const char*     enq_id,   /**< (I) The query to which the hint is to be added */
    const char*     hint      /**< (I) The query hint */
    );

/**
    Executes the query and fetches the data.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query, and the query's definition must be valid and complete.
    </ol>
*/
POMAPI int POM_enquiry_execute(
    const char*     enq_id,     /**< (I) The query that is to be executed */
    int*            rows,       /**< (O) Number of rows returned by the query */
    int*            cols,       /**< (O) Number of columns returned by the query */
    void****        report      /**< (OF) Result of the query */
    );

/**
    Get the number of columns selected by the query.
*/
POMAPI int POM_enquiry_ask_column_count(
    const char*     enqid,      /**< (I) Enquiry identifier */
    int*            count       /**< (O) Number of columns */
    );

/**
    This function exposes internal information about the POM types of the specified columns returned by a query.
    For more information on types, see @ref POM_TOKENS.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query that has been executed.
    <li>index must be greater than or equal to 0 and less than the number of attributes and expressions that were added to the query's select clause.
    </ol>
*/
POMAPI int POM_enquiry_ask_column_type(
    const char*     enq_id,     /**< (I) The query being investigated */
    int             index,      /**< (I) The index of the query's selected column  */
    int*            type        /**< (O) POM_TOKEN describing the column's POM type */
    );

/* The next #define was used to correct an historic spelling mistake in the header file. The original function name
is now deprecated. */
#define POM_enquiry_ask_colum_size POM_enquiry_ask_column_size

/**
    This function exposes internal information about the size of the in the specified columns returned by a query.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query that has been executed.
    <li>index must be greater than or equal to 0 and less than the number of attributes and expressions that were added to the query's select clause.
    </ol>
*/
POMAPI int POM_enquiry_ask_column_size(
    const char*     enq_id,     /**< (I) The query being investigated */
    int             index,      /**< (I) The index of the query's selected column */
    int*            size        /**< (O) The size of the column's data */
    );

/**
    This function exposes internal information about the name assigned to the column returned by a query.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query that has been executed.
    <li>index must be greater than or equal to 0 and less than the number of attributes and expressions that were added to the query's select clause.
    </ol>
*/
POMAPI int POM_enquiry_ask_column_name(
    const char*     enq_id,     /**< (I) The query being investigated */
    int             index,      /**< (I) The index of the query's selected column */
    char**          name        /**< (OF) The name assigned internally to the column */
    );

/**
    This function exposes internal information about the POM class that was associated with a caller-defined class alias.
    If the caller had defined the alias the refer to a Tc type, this function returns the name of the underlying POM class.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    <li>alias must identify one of the query's existing class aliases.
    </ol>
*/
POMAPI int POM_enquiry_ask_class_of_alias(
    const char*     enq_id,         /**< (I) The query being investigated */
    const char*     alias,          /**< (I) A class alias defined on the query */
    char**          aclass,         /**< (OF) The name of the actual POM class or registered associated with the alias */
    logical*        is_pom_class    /**< (O) true => aclass is the name of a POM class; false => it is the name of a registered table */
    );

/**
    This function exposes internal information about the POM class and attribute that was associated with an attribute alias.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    </ol>
*/
POMAPI int POM_enquiry_ask_attr_of_alias(
    const char*     enq_id,     /**< (I) The query being investigated */
    const char*     alias,      /**< (I) */
    char**          aclass,     /**< (OF) */
    char**          attr        /**< (OF) */
    );

/**
    This function can be used to determine whether a query may return duplicate rows or not.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    </ol>
*/
POMAPI int POM_enquiry_ask_distinct(
    const char*     enq_id,     /**< (I) The query being investigated */
    const char*     expr_id,    /**< (I) Ignored */
    logical*        distinct    /**< (O) true => the query is set to suppress duplicate rows from the results */
    );

/**
    Deletes the query and its sub-queries.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query.
    </ol>

    The enq_id must have already been defined.
*/
POMAPI int POM_enquiry_delete(
    const char*     enq_id      /**< (I) The query to be deleted */
    );

/**
    This function allows callers to define a query that accesses a variable length array (VLA) or long array (LA) column
    by creating a new alias (called a pseudo-class alias) to represent the contents of the array . The pseudo-class alias
    can be used in the same way as a class alias.

    The alias represents a pseudo-class that has two pseudo-attributes: PVAL (holding the value) and PSEQ (holding the index or
    sequence number). When a query uses a pseudo-class's PVAL or PSEQ pseudo-attributes, POM enquiry automatically adds a join
    to the array from the class that owns it, producing one row in the results for each member of the array. The upshot is that the results
    contain no rows that stem from instances of the owning class whose arrays are empty, and it contains multiple rows
    from instances whose arrays contain multiple values.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query
    <li>aclass - see #POM_enquiry_create_class_alias
    <li>alias - see #POM_enquiry_create_class_alias
    <li>attr must be the name of a valid VLA attribute on aclass
    </ol>

    Note that pseudo-class aliases can only be defined for VLA or LA columns, not for columns of type small array (SA). Small arrays
    are supported through calls to #POM_enquiry_set_pseudo_attr.
*/
POMAPI int POM_enquiry_set_pseudo_calias(
    const char*     enq_id,     /**< (I) The query that is to own the new alias */
    const char*     aclass,     /**< (I) The name of the class that owns the VLA or LA attribute */
    const char*     attr,       /**< (I) The name of the VLA or LA attribute */
    const char*     alias       /**< (I) The name to be given to the new alias */
    );

/**
    This function allows callers to define a query that accesses a small array (SA) column, by creating a pseudo-attribute to represent
    the value at a specified position in the array. The pseudo-attribute can be used in the same way as any other of the class's
    attributes.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query
    <li>aclass - see #POM_enquiry_create_class_alias
    <li>attr must be the name of an SA attribute on aclass
    <li>index must be >= 0
    <li>palias must not be the name of any of aclass's attributes, or any of its existing pseudo-attributes
    </ol>

*/
POMAPI int POM_enquiry_set_pseudo_attr(
    const char*     enq_id,     /**< (I) The query that is to own the definition of the pseudo-attribute */
    const char*     aclass,     /**< (I) The class that owns the SA attribute */
    const char*     attr,       /**< (I) The name of the SA attribute */
    int             index,      /**< (I) The position of the value to be accessed */
    const char*     palias      /**< (I) The name that is to be given to the new pseudo-attribute */
    );

/** 
    Supports the rewrite of the old query system on top of the new POM_enquiry API. The property argument supports either POM_case_insensitive or POM_tonumber token. 

    @note This API should not be used with the POM_enquiry APIs, but use instead #POM_enquiry_upper and #POM_enquiry_tonumber or #POM_enquiry_tc_to_number. 

    @returns 
    <ul> 
    <li>#POM_ok on success 
    </ul>
*/ 
POMAPI int POM_enquiry_set_expr_property(
    const char*     enq_id,             /**< (I) The query in which to set the property */
    const char*     expr_id,            /**< (I) The ID of an existing expression defined on the query */
    int             property_value      /**< (I) The property value to be set. Supports POM_case_insensitive or POM_tonumber token */
    );

/** 
    @deprecated #POM_enquiry_set_expr_proprety deprecated in Teamcenter 12.3. Use  #POM_enquiry_set_expr_property instead.

    Supports the rewrite of the old query system on top of the new POM_enquiry API. The property argument supports either POM_case_insensitive or POM_tonumber token. 

    @note This API should not be used with the POM_enquiry APIs, but use instead #POM_enquiry_upper and #POM_enquiry_tonumber or #POM_enquiry_tc_to_number. 

    @returns 
    <ul> 
    <li>#POM_ok on success 
    </ul>
*/ 
TC_DEPRECATED( "12.3", "POM_enquiry_set_expr_proprety", "POM_enquiry_set_expr_property" )
POMAPI int POM_enquiry_set_expr_proprety(
    const char*     enq_id,             /**< (I) The query in which to set the property */
    const char*     expr_id,            /**< (I) The ID of an existing expression defined on the query */
    int             property_value      /**< (I) The property value to be set. Supports POM_case_insensitive or POM_tonumber token */
    );

/**
    Copies the contents of one query into a sub-query of another.

    The aim of this function is to allow a query that has been created by one software module to be reused as a subquery by another.

    If enq_to is a newly created query (one which has been created, but on which no other POM enquiry calls have been made)
    then, at the end of the call, enq_to is a direct copy of enq_from. If, though, enq_to already contains its own definition,
    partial or complete, then, at the end of call, enq_to contains the result of merging enq_from into the existing definition.

    <b>Restrictions: </b>
    <ol>
    <li>enq_from must identify an existing query
    <li>enq_to must identify an existing sub-query of another query
    </ol>
*/
POMAPI int POM_enquiry_copy_query(
    const char*     enq_from,    /**< (I) The query to copy from */
    const char*     enq_to       /**< (I) The query to copy into */
    );

/**
    This function returns the id of the expression that has been set of on the query's where clause.

    The aim of the function is allow a query's where clause to be set by one software and subsequently altered by another. For
    example, the module wishing to modify the where clause could replace the where expression with another that has been creating
    by ANDing the previous where expression with some other condition.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query
    </ol>
*/
POMAPI int POM_enquiry_ask_where_exprid(
    const char*     enq_id,         /**< (I) The query being investigated */
    char**          where_expr_id   /**< (OF) The id of the query's where expression */
    );

/*
    This function exposes internal information about the name of the POM class associated with the data the query returns. It is
    intended for use on queries that select only a single attribute from a class.

    <b>Restrictions:</b>
    <ol>
    <li>enq_id must identify an existing query that has been executed.
    </ol>
*/
POMAPI int POM_enquiry_ask_select_class(
    const char*     enq_id,         /**< (I) The query being investigated */
    char**          class_name      /**< (OF) The name of the POM class associated with the data the query returns */
    );

/**
    Previous query ITK used tags for the query ID, but the new ITK uses string for query ID.

    This function will convert the tag of an old POM query into a valid new POM query string
    so that it can be used in #POM_enquiry_copy_query.
*/
POMAPI int POM_enquiry_ask_query_id(
    tag_t  enq_tag,  /**< (I) A valid POM enquiry tag */
    char** enq_id    /**< (OF) The string that maps to the enquiry tag */
    );

/**
  This function is only here to support the re-write of old query system on top of the new POM_enquiry API.
  This will return the name of the attribute selected by the enqid query. Please note that this assumes that we have only one attr selected
  because old query system only returns a tag value. so it can either be a PUID or a reference attribute's name.
  This is not the case for POM_enquiry system where we support multiple selected attributes from diff classes.
  so please do not use this function with POM_enquiry API.
*/

POMAPI int POM_enquiry_ask_select_attr(
    const char*     enq_id,     /**< (I) */
    char**          attr_name   /**< (OF) */
    );

/**
  This function allows the caller to register any arbitrary table in the database. Through this function, the caller specifies
  which of the table's columns are to be registered, and, for each column, it tells POM the POM type that describes the column's contents
  and the size of the data each column contains.

  Once registered, a table can be included in a query by establishing a class alias for it (see #POM_enquiry_create_class_alias). The
  registered columns can be accessed as the class alias' attributes (the name of the attribute is the column's name); each attribute
  acts as if it has the POM type that was assigned to it during registration.

  <b>Restrictions:</b>
  <ol>
  <li>table_name must be the name of an existing table in the POM database.
  <li>n_columns must be > 0
  <li>column_names must contain n_columns C strings; each string must be a distinct name
  <li>column_types must contain n_columns POM_TOKENs, each describing the POM type of the respective column
  <li>column_sizes must containt n_columns integers > 0, each describing the size of data in the respective column
     <ul>
     <li>For POM_int,POM_logical and POM_short use sizeof(int)
     <li>For POM_date use sizeof(date_t)
     <li>For POM_double and POM_float use sizeof(double)
     <li>For POM_typed/untyped reference use 15
     <li>For POM_string use column maxsize+1
     </ul>
  </ol>

*/
POMAPI int POM_enquiry_register_table (
    const char*     table_name,     /**< (I) The name of the table the caller wishes to include in a POM query */
    int             n_columns,      /**< (I) The number of the table's columns that are to be registered with POM */
    const char**    column_names,   /**< (I) The list of the columns to be registered */
    const int*      column_types,   /**< (I) The corresponding list of the columns' types */
    const int*      column_sizes    /**< (I) The corresponding list of the data sizes for each column */
    );

/**
  This function determines whether a specified table is already registered with POM enquiry or not.

  <b>Restrictions:</b>
  None
*/
POMAPI int POM_enquiry_is_table_registered (
    const char* table_name,     /**< (I) The name of a database table that may have been registered with POM enquiry */
    logical* is_registered      /**< (O) true => the table has been registered */
    );

/**
  This function determines whether a specified query name has already been created in the user's current session.

  <b>Restrictions:</b>
  None
*/
POMAPI int POM_enquiry_does_query_exists (
    const char* enq_id,         /**< (I) The id of a query that may have been created */
    logical* verdict            /**< (O) true => the query has been created */

    );

  /**
  This function determines whether a specified class alias has already been created on a query.

  <b>Restrictions:</b>
  <ol>
  <li>enq_id must identify an existing query that has been executed.
  </ol>
*/

POMAPI int POM_enquiry_does_class_alias_exists
(
    const char* enq_id,        /**< (I) The query being investigated */
    const char* alias,         /**< (I) The name of a class alias that may have been created on the query */
    logical* verdict           /**< (O) true => the alias already exists */
);


/**
    This function joins one class to another by specifying one join attribute on either class. The join is an ANSI
    join, where instances are joined whereever the specified attributes have values that equate to one another.

    This function was introduced in order to supports outer joins; as well as a normal join, it allows the caller
    to specify a left outer join, a right outer join or a full outer join.

    Joins created by this function are limited to those evaluated by equality; there is no support for joining
    on a comparative operator. If this is required, the caller should use #POM_enquiry_set_join_expr. (Also see
    #POM_enquiry_set_outer_join_filter for a way of adding additional constraints to the join.) In addition, the
    only join attributes supported are reference attributes (typed untyped refernces are both supported) and (of
    course) the pseudo-attribute, PUID.

    The function creates an attribute expression that describes the join condition. However, unlike
    #POM_enquiry_set_join_expr, the caller is not required to include this expression in the query's WHERE clause.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> expr_id must not be the id of any of the query's existing expressions
    <li> aclass1 - as #POM_enquiry_set_attr_expr
    <li> attr1 - as #POM_enquiry_set_attr_expr
    <li> op must be one of
      <ul>
      <li> #POM_enquiry_join
      <li> #POM_enquiry_left_outer_join
      <li> #POM_enquiry_right_outer_join
      <li> #POM_enquiry_full_outer_join
      </ul>
    <li> aclass2 - as #POM_enquiry_set_attr_expr
    <li> attr2 - as #POM_enquiry_set_attr_expr
    </ol>

*/
POMAPI int POM_enquiry_add_join_expr(
    const char*     enq_id,     /**< (I) The id of the query on which the join is to be created */
    const char*     expr_id,    /**< (I) The identifier to be given to the new expression */
    const char*     aclass1,    /**< (I) The name of the class, alias or type on the left of the join */
    const char*     attr1,      /**< (I) The attribute used to join the left hand class */
    int             op,         /**< (I) The operator used to create the join */
    const char*     aclass2,    /**< (I) The name of the class, alias or type on the right of the join */
    const char*     attr2       /**< (I) The attribute used to join the left hand class */
    );

/**
    Given a query that has been defined as the sub-query of another, this function instructs POM enquiry
    to use it as a derived table within the parent query. (A derived table is an SQL query that is specified
    within the FROM CLAUSE of its parent query. It acts as a table that only exists while the parent query is
    executing.)

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query that is a sub-query of the query that is to use the derived table
    <li> table_name must not be the name of any existing POM class or attribute id
    </ol>
*/
POMAPI int POM_enquiry_create_derived_table(
    const char*     enqid,      /**< (I) The id of the sub-query that is to be treated as a derived table */
    const char*     table_name  /**< (I) The name to be given to the derived table */
    );

/**
    Given a query that has been defined as the sub-query of another, this function allows the caller to tell
    POM enquiry to use it as a common table expression (or CTE) within the parent query. (A CTE is an SQL query that
    is specified in a WITH clause. It acts as a table that only exists while the parent query is executing. One
    parent query can have a list of many CTEs, and, in this case, CTEs later in the list can use the contents of the
    earlier ones.)

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query that is a sub-query of the query that is to use the derived table
    <li> table_name must not be the name of any existing POM class or attribute id
    </ol>
*/
POMAPI int POM_enquiry_add_common_table_expr(
    const char*     enqid,      /**< (I) The id of the sub-query that is to be treated as a CTE */
    const char*     table_name  /**< (I) The name to be given to the table the CTE defines */
    );

/**
    This function returns the name of the column alias of an attribute in the query's SELECT clause. The
                For example,  if the select clause is like this:
                SELECT t1.attr1 AS col0, t1.attr2 AS col1 FROM myclass t1
                then the alias at position 0 will be col0.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> column_index must be >= 0 and < the number of attributes and expressions in the query's select clause
    </ol>
*/
POMAPI int POM_enquiry_get_column_alias(
    const char* enq_id,  /**< (I) The id of an existing query */
    int column_index,    /**< (I) The 0-based index of the column within the query's select clause */
    char** column_alias  /**< (OF) The name of the column's alias */
    );

/**
    This function allows the caller to specify a column alias to be used for any of the query's selected columns.

    This is intended for use in sub-queries that are being used as derived tables or CTEs. Once the caller has called
    this function to name the columns selected by the sub-query, they can use the table_name / column_alias pair as
    an aclass / attr pair to access the column within the parent query.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> column_index must be >= 0 and < the number of attributes and expressions in the query's select clause
    <li> column_alias must not be the name of any of the query's existing column_aliases.
    </ol>

*/
POMAPI int POM_enquiry_set_column_alias(
    const char* enq_id,         /**< (I) The id of an existing query */
    int column_index,           /**< (I) The 0-based index of the column within the query's select clause  */
    const char* column_alias    /**< (I) The name to be given to the column */
    );

/**
    This function allows the caller add an additional restriction to the condition used to create an outer join
    (see #POM_enquiry_add_join_expr for how to create an outer join).

    POM enquiry automatically ANDs the specified expression into the existing join expression. The effect is to
    change the join expression from the original, say

    ON x.reference = y.PUID
    to
    ON x.reference = y.PUID AND new constraint expression

    The caller passes in the id of one of the query's existing attribute-expressions. The expression must be
    a simple logical expression: neither AND nor OR operators are supported, nor is there support for a
    an expression that uses a sub-query, since such support is lacking in the underlying database platforms.

    <b>Restrictions:</b>
    <ol>
    <li> enq_id must identify an existing query
    <li> outer_join_expr_id must identify one of the query's existing outer join expressions
    <li> expr_id must identify one of the query's other existing expressions, which
        <ul>
        <li> is a logical expression
        <li> has not been defined using AND or OR operators
        <li> has not been defined using a subquery
        </ul>
    <li> column_alias must not be the name of any of the query's existing column_aliases.
    </ol>
*/
POMAPI int POM_enquiry_set_outer_join_filter(
    const char* enq_id,                /**< (I) The id of the query that owns the join */
    const char* outer_join_expr_id,    /**< (I) The id of the join expression that is to be further constrained */
    const char* expr_id                /**< (I) The id the expression that defines the additional constraint */
    );


/** @} */
#ifdef __cplusplus
}
#endif

#include <pom/pom/libpom_undef.h>

#endif
