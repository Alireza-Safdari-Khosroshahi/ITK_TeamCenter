/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_CORE__2013_05_LOV_HXX
#define TEAMCENTER_SERVICES_CORE__2013_05_LOV_HXX

#include <teamcenter/soa/client/model/ListOfValues.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2013_05
            {
                class Lov;

class TCSOACORESTRONGMNGD_API Lov
{
public:

    struct LOVInput;
    struct LovFilterData;
    struct InitialLovData;
    struct LOVColumnNames;
    struct LOVBehaviorData;
    struct LOVData;
    struct LOVSearchResults;
    struct LOVValueRow;
    struct ValidateLOVValueSelectionsResponse;

    /**
     * Map (string, vector<string>) that is a generic container that represents property
     * values. The key is the property name and the value is the string representation of
     * the property value.
     */
    typedef std::map< std::string, std::vector< std::string > > PropertyValues;

    /**
     * Maps string keys to integer values
     */
    typedef std::map< std::string, int > StringIntMap;

    /**
     * Map of Strings
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * This represents the operation data.  Operations such as Create, Edit, Revise, Save
     * As, Search or any other operation that requires the data to be passed generically
     * to the LOV service operations  have the property values represented through the LOVInput
     * for computing a LOV.
     */
    struct LOVInput
    {
        /**
         * Owning object for the operation in context. a. Edit operation - Object being edited.
         * b. Save operation - Object being saved. c. Revise operation - Object being revised.
         * d. SaveAs operation - Object being copied. e. Search operation - Saved Query Object
         * for searching. f. If an operation does not have an object, specify the value as null
         * and ensure boName is passed for the same. For example, during creation, client does
         * not have an object. Therefore specify the business object name of the object being
         * created.  For example, if Item object is being created, specify the boName as "Item"
         * and operationName as "Create".
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  owningObject;
        /**
         * Name of the source business object. For example, Item is the source business object
         * for Item Descriptors. If the owningObject is not null, then it can be empty. Server
         * can determine the business object name from the owningObject. It is mandatory for
         * Create operation where owningObject is null
         */
        std::string boName;
        /**
         * Name of the operation  being performed. Valid names are Create, Revise, SaveAs, Edit,
         * Search, Save
         */
        std::string operationName;
        /**
         * A map of property names and values (string, vector<string>). The client is responsible
         * for converting the values of the different property types (int, float, date .etc)
         * to a string using the appropriate toXXXString functions in the SOA client  framework's
         * Property class. Single valued properties will have a single value in the value vector,
         * while Multi-valued properties will have multiple values in the value vector.
         */
        PropertyValues propertyValues;
    };

    /**
     * Filter Data used in InitialLOVData.
     */
    struct LovFilterData
    {
        /**
         * The desired string used to filter the search results. For example, if "Green" is
         * entered as a filter string, the results returned for LOV values will include the
         * LOV values that match the query criteria AND contain the string "Green" in the LOV
         * Description or any of the filter attributes. Case sensitive nature is honoured based
         * on TC_ignore_case_on_search preference.
         */
        std::string filterString;
        /**
         * Maximum number of LOV results that server should retrieve from the database
         */
        int maxResults;
        /**
         * Number of objects to be processed in case of dynamic LOVs to return LOV values and
         * in other LOV cases it is to return the number of LOV values from the LOV results.
         * This number must be less than or equal to maxResults
         */
        int numberToReturn;
        /**
         * Property name on which to sort the results. This is optional
         */
        std::string sortPropertyName;
        /**
         * 1=sort in ascending order, 2=sort in descending order. Ignored if sortPropertyName
         * is null.
         */
        int order;
    };

    /**
     * Initial LOV Data sent to the server during an LOV query.
     */
    struct InitialLovData
    {
        /**
         * The ListOfValues that is being evaluated;Use this when the lovInput is not possible
         * to construct and need to get the values of specified Lov, otherwise pass as null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
        /**
         * This is a container of key-value pairs representing the desired entries for different
         * property fields for different operations (Create, SaveAs, Revise, etc.). It is used
         * for context-based evaluation of the LOV values where the property values are substituted
         * into query criteria. It is also used for interdependent LOV evaluation e.g to evaluate
         * interdependent LOV values at dependent levels given the values at the higher levels
         * that are populated on the lovInput
         */
        Teamcenter::Services::Core::_2013_05::Lov::LOVInput lovInput;
        /**
         * The name of the Property for which LOV is being evaluated.
         */
        std::string propertyName;
        /**
         * Filter critieria and other search data.
         */
        Teamcenter::Services::Core::_2013_05::Lov::LovFilterData filterData;
    };

    /**
     * Structure containing column names for the LOV value property, LOV description property
     * and the filter attributes
     */
    struct LOVColumnNames
    {
        /**
         * The attribute on the object to be used as the LOV value. When the user selects a
         * row from the list of values in the dynamic LOV widget (an item for example), this
         * configuration point tells the system which attribute to use as the LOV value. In
         * case of Static LOVs, the name of the property is returned as "lov_value". In case
         * of Dynamic LOVs, it is a name as specified in BMIDE.
         */
        std::string lovValueProp;
        /**
         * The attribute on the object to be used as the LOV value description. When the user
         * selects a row from the list of values in the dynamic LOV widget (an item for example),
         * this configuration point tells the system which attribute to use as the LOV value
         * description. In case of Static LOVs, the name of the property is returned as "lov_value_description".
         * In case of Dynamic LOVs, it is a name as specified in BMIDE. It can be have empty
         * value if it is not specified by BMIDE administrator.
         */
        std::string lovDescrProp;
        /**
         * The filter properties would appear as additional columns along with the LOV Value
         * and LOV description in the Dynamic LOV
         */
        std::vector< std::string > filterProperties;
        /**
         * Displayable names for each of lovValueProp, lovDescrProp, filterProperties that clients
         * can use to display the same
         */
        StringMap displayNames;
        /**
         * Specifies the UI characteristics such as sortability and filterability, of the filter
         * columns along with the LOV Value and LOV Description columns. The values of these
         * characteristics are provided as bit values. At present, only the first two bits are
         * populated, as listed below. Rest of the bits are reserved for future use.
         * <br>
         * The first bit indicates sortability of the column. Value "0" indicates it is not
         * sortable, while value "1" indicates it is sortable.
         * <br>
         * The second bit indicates if the column is filterable. Value "0" indicates it is not
         * filterable, while value "1" indicates it can be filtered.
         */
        StringIntMap columnManagementFlags;
    };

    /**
     * Container of data such as LOV usage, Style, Lov Column Names. Additionally it  contains
     * interdependent properties that can be used for optimization by the client
     */
    struct LOVBehaviorData
    {
        /**
         * Indicates if LOV is exhaustive (=1) or suggestive(=2) or Range (=3)
         */
        int lovUsage;
        /**
         * Possible values are Standard, Range, Hierarchical, Interdependent and Coordinated
         * Standard          - A simple list of values Interdependent - An interdependent  list
         * of values, where each value has a  nested list of values. A list of States would
         * have a list of Cities for each State. For this style of LOV the dependentProps will
         * have a list of property names that are associated with each level of the LOV hierarchy
         * Hierarchical      - Same as the Interdependent, but only the last level of values
         * is associated with a property Coordinated    - This is similar to Interdependent;
         * however levels 2-N will only have a single value. When the user selects a value from
         * the first level LOV, the system can then fill property values for all levels Range
         * - Subset (ranges) of valid values in terms of upper and lower ranges
         */
        std::string style;
        /**
         * Names of the columns when displayed in clients
         */
        Teamcenter::Services::Core::_2013_05::Lov::LOVColumnNames columnNames;
        /**
         * This is a list of Boolean values that indicates if the description for each of the
         * column properties is attached
         */
        std::vector< bool > descriptionsAttached;
        /**
         * Names of interdependent properties. If the LOV is not an interdependent or coordinated
         * LOV, this list will be empty
         */
        std::vector< std::string > dependendProps;
        /**
         * Upper limit for Range LOV. This is not applicable to any other style of LOV
         */
        std::string rangeUpperLimit;
        /**
         * Lower limit for Range LOV. This is not applicable to any other style of LOV
         */
        std::string rangeLowerLimit;
    };

    /**
     * This data structure is not for end user consumption. Data in this structure will
     * be used by server for returning the next set of LOV values
     */
    struct LOVData
    {
        /**
         * Possible values are Standard, Dynamic, Range, Hierarchical, Interdependent and Coordinated
         */
        std::string style;
        /**
         * Filter critieria and other search data.
         */
        Teamcenter::Services::Core::_2013_05::Lov::LovFilterData filterData;
        /**
         * These are the list of UIDs that will be processed by the server in subsequent calls
         * to get next set of LOV values
         */
        std::vector< std::string > unProcessedObjects;
        /**
         * Boolean flag to indicate if additional UIDs (Values in static LOV) are skipped or
         * not
         */
        bool additionalValuesSkipped;
        /**
         * Current index of the LOV results that have been processed.
         */
        int currentIndex;
        /**
         * LOVs of Dynamic LOV which is being evaluated
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  > lovs;
    };

    /**
     * This structure contains the LOV results from the getInitialLOVValues or getNextLOVValues
     * operations
     */
    struct LOVSearchResults
    {
        /**
         * This is a list of LOVValueRow objects. Each LOVValueRow object represents a single
         * row of the LOV results. It includes the LOV value property, the description property
         * and all the filter properties (the filter properties are the ones whose values are
         * used for filtering the search results based on user input)
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Lov::LOVValueRow > lovValues;
        /**
         * true indicates there are more values available which will can be retrieved by a call
         * to the getNextValues operation
         */
        bool moreValuesExist;
        /**
         * LOV data used to define the UI component behavior. This includes data such as LOV
         * usage, Style, Lov Column Names. Additionally it  contains interdependent properties
         * that can be used for optimization by the client
         */
        Teamcenter::Services::Core::_2013_05::Lov::LOVBehaviorData behaviorData;
        /**
         * If moreValuesExist is true, this object is passed as input to the getNextValues operation
         * to get the next list of LOV search results
         */
        Teamcenter::Services::Core::_2013_05::Lov::LOVData lovData;
        /**
         * The ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This represents a row of LOV values. It includes the internal and display values
     * for the various columns for each LOV value
     */
    struct LOVValueRow
    {
        /**
         * UID of the object. This applies to dynamic LOVs.  Server sends valid UID for dynamic
         * LOV and empty in other LOV cases.. Client can send the same UID when a value is selected
         * to validateLOVValueSelection operation for effective validation. This is empty for
         * for non dynamic LOVs
         */
        std::string uid;
        /**
         * The internal values of all the properties on a single row of the LOV search results.
         * The parseXXX functions in the SOA framework class can be used to retrieve the values
         * for the specific property types
         */
        PropertyValues propInternalValues;
        /**
         * value type map for each property which has internal values, PROP_untyped (0) No Value
         * type PROP_char (1) Value is a single character PROP_date (2) Value is a date PROP_double
         * (3) Value is a double PROP_float (4) Value is a float PROP_int (5) Value is an integer
         * PROP_logical (6) Value is a logical PROP_short (7) Value is a short PROP_string (8)
         * Value is a character string PROP_typed_reference (9) Value is a typed reference PROP_untyped_reference
         * (10) Value is an untyped reference PROP_external_reference (11) Value is an external
         * reference PROP_note (12) Value is a note PROP_typed_relation (13) Value is a typed
         * relation PROP_untyped_relation (14) Value is an untyped relation
         */
        StringIntMap propInternalValueTypes;
        /**
         * The display values of all the properties on a single row of the LOV search results
         */
        PropertyValues propDisplayValues;
        /**
         * Next level of row values in case of hierarchical LOV. This is recursive and can go
         * down multiple levels in the hierarchy
         */
        std::vector< Teamcenter::Services::Core::_2013_05::Lov::LOVValueRow > childRows;
    };

    /**
     * Response structure indicating validity of LOV value selection and containing updated
     * property values and interdependent LOV values
     */
    struct ValidateLOVValueSelectionsResponse
    {
        /**
         * Indicates whether input property has valid values
         */
        bool propHasValidValues;
        /**
         * Names of dependent properties server modified to be updated by client as a results
         * of dependency with input property selection. This can be empty.
         */
        std::vector< std::string > dependentPropNames;
        /**
         * Updated property values. It contains both internal and display values of the updated
         * properties.  It can be empty.
         */
        Teamcenter::Services::Core::_2013_05::Lov::LOVValueRow updatedPropValues;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is invoked to query the data for a property having an LOV attachment.
     * The results returned from the server also take into consideration any filter string
     * that is in the input.  This operation returns both LOV meta data as necessary for
     * the client to render the LOV and partial LOV values list as specified.  The operation
     * will return the results in the LOVSearchResults data structure. Maximum number of
     * results to be returned are specified in the InitialLOVData data structure. If there
     * are more results, the moreValuesExist flag in the LOVSearchResults data structure
     * will be true. If the flag is true, more values can be retrieved with a call to the
     * getNextLOVValues operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param initialData
     *        Input data to get LOV results for any LOV
     *
     * @return
     *         The LOV Search Results. This includes LOV metadata information (LOV usage, LOV style,
     *         etc.). It also contains the instance data (LOV values) that the client can use to
     *         render the LOV UI widget. The output also contains information as to whether there
     *         are more results to be processed in which case a user can page to get next set of
     *         values (this triggers a call to the getNextLOVValues operation).  The following partial
     *         errors are returned in the ServiceData:
     *         <br>
     *         -   54051 - The property  is not a valid sort property. Property must be one of the
     *         LOV Value or LOV Description or any of Filter Properties.
     *         <br>
     *         -   54052 - The Dynamic LOV  has an invalid configuration. It may be that Business
     *         Object Type this dynamic LOV may not exists in the system. Please contact your business
     *         modeler administrator with this information.
     *         <br>
     *         -   54053 - The Dynamic LOV  has an invalid configuration  with one of the filter
     *         property does not exists. Please contact your business modeler administrator with
     *         this information.
     *         <br>
     *         -   54055 - The Dynamic LOV  has an invalid configuration. The specified LOV value
     *         description property for the Dynamic LOV does not exist. Please contact your business
     *         modeler administrator with this information.
     *         <br>
     *         -   54058 - Sorting is not supported for columns representing array properties.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Lov::LOVSearchResults getInitialLOVValues ( const Teamcenter::Services::Core::_2013_05::Lov::InitialLovData&  initialData ) = 0;

    /**
     * This operation is invoked after a call to getInitialLOVValues if the moreValuesExist
     * flag is true in the LOVSearchResults output returned from a call to the getInitialLOVValues
     * operation. The operation will retrieve the next set of LOV values
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param lovData
     *        Input data to get next set of LOV results for Dynamic LOV. This is returned as part
     *        of the LOVSearchResults output from the call to getInitialLOVValues operation
     *
     * @return
     *         LOV Search Results (LOVSearchResults instance). The LOV Search Results contains LOV
     *         metadata information (LOV usage, LOV style, etc.). It also contains the instance
     *         data (LOV values) that the client can use to render the LOV UI widget. The output
     *         also contains information as to whether there are more results to be processed in
     *         which case a user can page to get next set of values (this triggers a call to the
     *         subsequent getNextLOVValues operation).  Partial errors are returned in the ServiceData
     *         field in the LOV Search Results. Possible errors are:
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Lov::LOVSearchResults getNextLOVValues ( const Teamcenter::Services::Core::_2013_05::Lov::LOVData&  lovData ) = 0;

    /**
     * This operation can be invoked after selecting a value from the LOV.  Use this operation
     * to do additional validation to be done on server such as validating Range value,
     * getting the dependent properties values in case of interdependent LOV (resetting
     * the dependendent property values), Coordinated LOVs ( populating dependent property
     * values )
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param lovInput
     *        updated LOV input with new selection
     *
     * @param propName
     *        It is the name of the Property for which LOV is being evaluated
     *
     * @param uidOfSelectedRows
     *        Pass the uids from the selected rows. Every LovValueRow returned from server is designated
     *        with valid UID for dynamic LOV. That is the value need to be passed to the server
     *        for effective validation. For other LOVs it is empty
     *
     * @return
     *         The response data indicating validity of LOV value selections and containing updated
     *         property values and interdependent property values
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Lov::ValidateLOVValueSelectionsResponse validateLOVValueSelections ( const Teamcenter::Services::Core::_2013_05::Lov::LOVInput&  lovInput,
        const std::string&  propName,
        const std::vector< std::string >& uidOfSelectedRows ) = 0;


protected:
    virtual ~Lov() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

