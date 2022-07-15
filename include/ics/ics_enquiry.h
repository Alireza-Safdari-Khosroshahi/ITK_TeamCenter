/*==============================================================================
                Copyright (c) 2003-2005 UGS Corporation
                   Unpublished - All Rights Reserved
 ==============================================================================*/

/**
    @file

    The header file for inclass query funtions
*/

/*  */

#ifndef _ICS_ENQUIRY_H_INCLUDED
#define _ICS_ENQUIRY_H_INCLUDED

/**
    @defgroup ICS_enquiry Enquiry
    @ingroup ICS

    The following functions are used to enable the Classification extended search features.

    @note To search in both unit systems you need to create two separate enquiries, one for each 
    unit system. You need to specify the active unitsystem as part of each query: -630 = 0/1 (metric/non-metric).
    #ICS_attribute_convert_attribute_values can be used to convert attribute values from one unit to another unit.
    These two enquiries can be combined using #POM_enquiry_combine_enquiry.

    @{
*/

typedef struct ICS_value_list_entry_s{
    int        unct;       /**< Unct for values */
    int        n_values;   /**< Number of values in values */
    char**     values;     /**< Values  */
    char **displayValues;  /**< display Values e.g for KeyLOVs */
} ICS_value_list_entry_t, *ICS_value_list_entry_p_t;

typedef struct ICS_value_list_s{
    int                         n_entries;  /**< Number of entries */
    ICS_value_list_entry_p_t    entries;    /**< List of entries */
} ICS_value_list_t, *ICS_value_list_p_t;

#include <ics/libics_exports.h>

#ifdef __cplusplus
    extern "C"{
#endif

/**
    This function returns the name of the POM class in which ICOs are stored (at most sites the name is "icm0").
    thePomClassName has to be freed.
*/
ICS_API int ICS_enquiry_getPomClassNameForICSClass( 
    char**  thePomClassName     /**< (OF) Holds the name of the POM class where ICOs are stored */
    );

/**
    This function creates the expression theExprName (as the expression resulting from theEnquiryValues) 
    in POM enquiry theEnquiry (this POM enquiry must exist).
    This expression can be used like any POM expression.
*/
ICS_API int ICS_enquiry_set_ics_expr( 
    const char*                 theQueryName,       /**< (I) The name of the POM enquiry that will be created */
    const char*                 theExprName,        /**< (I) The name of the expression to be created */ 
    const char*                 theClassId,         /**< (I) The ID of the inCLASS class to be queried */ 
    const ICS_value_list_p_t    theICSQueryList,    /**< (I) A list containing attributes and search values */
    int                         theOptions          /**< (I) The enquiry options: #ICS_SEARCH_THIS_CLASS_ONLY to limit
                                                        search results to the class with the unique ID, theClassId,
                                                        #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity */
    );

/**
    This function returns a list of POM class attribute names for the given attribute IDs. 
    If an error occurs, thePomColumnNames is not set; otherwise, thePomColumnNames must be freed.
*/
ICS_API int ICS_enquiry_askPomAttributeNames( 
    const char* theClassId,         /**< (I) The attribute IDs belong to this inCLASS class */
    int         theCount,           /**< (I) The number of attributes */ 
    const int*  theUnctList,        /**< (I) The POM class attribute names will be given for these attribute IDs */
    char***     thePomColumnNames   /**< (OF) theCount The POM class attribute names for the attribute IDs
                                             <br/>The array is packed, which means that the memory is deallocated by calling #MEM_free on the container only.*/
    );

/**
    This function creates a POM enquiry named theEnquiryName and sets the WHERE expression of the 
    enquiry to the expression resulting from theEnquiryValues.

    No SELECT- or ORDER- statements are added.
*/
ICS_API int ICS_enquiry_create_enquiry( 
    const char*                 theQueryName,       /**< (I) The name of the POM enquiry that will be created */ 
    const char*                 theClassId,         /**< (I) The ID of the inCLASS class to be queried */ 
    const ICS_value_list_p_t    theICSQueryList,    /**< (I) A list containing attributes and search values */
    int                         theOptions          /**< (I) The enquiry options: #ICS_SEARCH_THIS_CLASS_ONLY to limit 
                                                        search results to the class with the unique ID, theClassId.
                                                        #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity */
    );

/**
    This function adds attribute IDs (theSelectAttrIDs) to the SELECT clause of the 
    POM enquiry theEnquiryName (this enquiry must exist).
*/
ICS_API int ICS_enquiry_add_select_attrs(
    const char* theQueryName,           /**< (I) The name of the POM enquiry where the SELECT statements will be created */
    const char* theClassId,             /**< (I) The name of the inCLASS class to which the select attributes belong */
    int         theSelectAttrCount,     /**< (I) The number of select attributes to be added */
    const int*  theSelectAttrs          /**< (I) The attributes to be selected */
    );

/**
    This function adds an expression to the SELECT clause of POM enquiry, theEnquiryName. 
    The expression is made of theAttributeId and thePomOperator, for example, #POM_tonumber.
*/
ICS_API int ICS_enquiry_add_select_expr(
    const char* theQueryName,       /**< (I) The name of the POM enquiry where the SELECT statement will be created */
    const char* theClassId,         /**< (I) The name of the inCLASS class to which the select attributes belong */
    int         theAttributeId,     /**< (I) The ID of the attribute for the SELECT statement */
    int         theSelectExpr       /**< (I) The POM operator to build the SELECT expression */
    );
                                       
/**
    This function creates the expression theExprName in POM enquiry theEnquiryName (this POM enquiry must exist).
    The theExprName expression results from theAttributeId and theCompareString.

    @note This function must be used in combination with #ICS_enquiry_set_expr_for_class, 
    because an expression has to be set for the inCLASS class that is to be searched.
    If you do not call #ICS_enquiry_set_expr_for_class or do not use the expression created by this function,
    your enquiry will search ALL inCLASS classes.

    Example:
    @code
        int ifail, attributeID = 1025;
        char *classID = "CLASS1",
            *enquiryName = "myEnquiry",
            *expressionName = "myExpression",
            *classExpressionName = "myClassExpression",
            *whereExpressionName = "myWhereExpression";

        ifail = POM_enquiry_create( enquiry );
        if ( POM_ok == ifail )
        {
            ifail = ICS_enquiry_set_ics_attr_expr(enquiryName,
                                                expressionName,
                                                classID,
                                                attributeID,
                                                "!= London",
                                                ICS_SEARCH_CASE_INSENSITIVE);

            if ( ITK_ok == ifail )
            {
                ifail = ICS_enquiry_set_expr_for_class(enquiryName,
                                                    classExpressionName,
                                                    classID,
                                                    ICS_SEARCH_THIS_CLASS_ONLY);

                if ( ITK_ok == ifail )
                {
                    ifail = POM_enquiry_set_expr(enquiryName,
                                                whereExpressionName,
                                                myExpressionName,
                                                POM_enquiry_and,
                                                classExpressionName);

                    if ( ITK_ok == ifail )
                    {
                        ifail = POM_enquiry_set_where_expr(enquiryName,
                                                        whereExpressionName);

                        if ( ITK_ok == ifail )
                        {
                            ... add attributes to select, execute enquiry and use result
                        }
                    }
                }
            }
        }
    @endcode
*/
ICS_API int ICS_enquiry_set_ics_attr_expr(
    const char* theQueryName,       /**< (I) The name of the POM enquiry where the expression will be created */
    const char* theExprName,        /**< (I) The name of the POM expression to be created */
    const char* theClassId,         /**< (I) The inCLASS class for which the expression will be created */
    int         theAttributeId,     /**< (I) The attribute for which the POM expression will be created */
    const char* theICSExpr,         /**< (I) The search string for the attribute */
    int         theOptions          /**< (I) The enquiry options: #ICS_SEARCH_CASE_INSENSITIVE to search without
                                            case sensitivity; otherwise, set theOptions to 0 */
    );

/**
    Create a POM enquiry expression based on the theICSExpr for the given attribute of a POM class
*/
ICS_API int ICS_enquiry_set_attr_icsexpr(
    const char* theQueryName,       /**< (I) */
    const char* theExprName,        /**< (I) */
    const char* thePOMClassName,    /**< (I) */
    const char* thePOMAttrName,     /**< (I) */
    const char* theICSExpr,         /**< (I) */
    int         theEnqOptions       /**< (I) */
    );

/**
    This function creates the expression theExprName in POM enquiry theEnquiryName 
    (this POM enquiry must exist). The theExprName expression results from theAttributeId, 
    thePomOperator (for example, #POM_enquiry_equal) and theExpressionValue.

    @note This function must be used in combination with #ICS_enquiry_set_expr_for_class,
    because an expression has to be set for the inCLASS class that is to be searched. 
    If you do not call #ICS_enquiry_set_expr_for_class or do not use the expression created by this function, 
    your enquiry will search ALL inCLASS classes.
*/
ICS_API int ICS_enquiry_set_attr_expr( 
    const char* theQueryName,       /**< (I) The name of the POM enquiry where the expression will be created */
    const char* theExprName,        /**< (I) The name of the POM expression to be created */
    const char* theClassId,         /**< (I) The inCLASS class for which the class expression will be created */
    int         theAttributeId,     /**< (I) The POM expression will be created for this attribute */
    int         thePomOperator,     /**< (I) The POM operator for the expression */
    const char* thePomExpression,   /**< (I) The value is one of the following:
                                        <UL>
                                        <LI>An expression identifier
                                        <LI>A value identifier
                                        <LI>A sub-enquiry identifier
                                        <LI>NULL
                                        </UL> */
    int         theOptions           /**< (I) The enquiry options: #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity;
                                        otherwise, set theOptions to 0 */
    );

/**
    This function executes the POM enquiry resulting from the theICSQueryList argument with order expressions for
    the theOrderAttrIds (== attribute IDs) argument. 
    The sorting order of the theOrderAttrIds[i] is theOrder[i] (#POM_enquiry_desc_order or #POM_enquiry_asc_order).

    If the function succeeds, then the theResults argument points to an array where the tags of the
    resulting ICOs (Classification objects) are stored.
*/
ICS_API int ICS_enquiry_search( 
    const char*                 theClassId,         /**< (I) The ID of the inCLASS class to be queried */
    const ICS_value_list_p_t    theICSQueryList,    /**< (I) A list containing attributes and search values */
    int                         theOrderAttrCount,  /**< (I) The number of ORDER BY attributes */
    const int*                  theOrderAttrs,      /**< (I) The attribute values by which the enquiry results will be ordered */
    const int*                  theOrder,           /**< (I) The sorting order, either: <br>
                                                        #POM_enquiry_desc_order or #POM_enquiry_asc_order */
    int                         theOptions,         /**< (I) The enquiry options: <br>
                                                        #ICS_SEARCH_THIS_CLASS_ONLY to limit search results to
                                                        the class with the unique ID, theClassId. <br>
                                                        #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity */
    int*                        theResultCount,     /**< (O) The number of selected tags */
    tag_t**                     theResults          /**< (OF) theResultCount The selected tags */
    );

/**
    This function adds an order statement for theOrderAttributes to the POM enquiry theEnquiryName 
    (this POM enquiry must exist).
    Sorting order for theOrderAttrs[i] is thePomOrder[i] (#POM_enquiry_desc_order or #POM_enquiry_asc_order).
*/
ICS_API int ICS_enquiry_add_order_attrs( 
    const char* theQueryName,       /**< (I) The name of the POM enquiry to which the order attributes will be added */
    const char* theClassId,         /**< (I) The name of the inCLASS class to which the order attributes belong */
    int         theOrderAttrCount,  /**< (I) The number of ORDER attributes to be added */
    const int*  theOrderAttrs,      /**< (I) The IDs of the order attributes */
    const int*  theOrder            /**< (I) The POM order for attributes */
    );

/**
    This function selects values of the theAttributeId argument from the inCLASS class, theClassId,
    with a WHERE expression resulting from the theICSQueryList argument.
    The argument theResults contains the values as strings.
*/
ICS_API int ICS_enquiry_select_distinct( 
    const char*                 theClassId,         /**< (I) The ID of the inCLASS class to be queried */ 
    const ICS_value_list_p_t    theEnquiryValues,   /**< (I) A list containing attributes and search values */
    int                         theAttributeId,     /**< (I) The values of this attribute will be selected */
    int                         theOptions,         /**< (I) The enquiry options: <br>
                                                        #ICS_SEARCH_THIS_CLASS_ONLY to limit search results to
                                                        the class with the unique ID, theClassId. <br>
                                                        #ICS_SEARCH_CASE_INSENSITIVE to search without case sensitivity */
    int*                        theResultCount,     /**< (O) The number of selected values */
    char***                     theResults          /**< (OF) theResultCount The selected values */
    );

/**
    This function creates an inCLASS class expression in POM enquiry theEnquiryName.
    This expression must be used in combination with #ICS_enquiry_set_ics_attr_expr and #ICS_enquiry_set_attr_expr.
*/
ICS_API int ICS_enquiry_set_expr_for_class( 
    const char* theQueryName,   /**< (I) The name of the POM enquiry where the SELECT statement will be created */
    const char* theExprName,    /**< (I) The name of the POM expression to be created */
    const char* theClassId,     /**< (I) The inCLASS class for which the class expression will be created */
    int         theOptions      /**< (I) The enquiry options:<br>
                                        #ICS_SEARCH_THIS_CLASS_ONLY to limit search results to the class with
                                        the unique ID, theClassId; otherwise, set theOptions to 0 */
    );

/**
    This function processes list of attribute ids and attribute values to create structure containing attibute ids and their values.
*/
ICS_API int ICS_get_value_list( 
    int                  theEntryCount,  /**< (I) The number of entries to be a list */
    const int*           theAttrIds,     /**< (I) The list of attributes (ids) */
    const char**         theValues,      /**< (I) The list of attributes values */
    ICS_value_list_p_t * theValueList    /**< (OF) A list containing attributes (ids) and values */
    );

/** @} */

#ifdef __cplusplus
}
#endif

#include <ics/libics_undef.h>
#endif
