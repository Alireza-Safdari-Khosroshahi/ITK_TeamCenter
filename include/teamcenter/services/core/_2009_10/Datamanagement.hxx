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

#ifndef TEAMCENTER_SERVICES_CORE__2009_10_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2009_10_DATAMANAGEMENT_HXX

#include <teamcenter/services/core/_2007_01/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/Table.hxx>
#include <teamcenter/soa/client/model/TableDefinition.hxx>
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
            namespace _2009_10
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct GetItemFromAttributeInfo;
    struct GetItemFromAttributeItemOutput;
    struct GetItemFromAttributeItemRevOutput;
    struct GetItemFromAttributeResponse;
    struct GetTablePropertiesResponse;
    struct TableCellValueTypeInfo;
    struct TableCellInfo;
    struct TableDefInfo;
    struct TableInfo;

    /**
     * A hash map containing the key-value pairs specifying the <b>Item</b> objects to search
     * for. Used by the <code>GetItemFromAttributeInfo</code> structure to store the <b>Item</b>
     * search criteria.
     */
    typedef std::map< std::string, std::string > GetItemAttributeMap;

    /**
     * Input parameters for retrieving <b>Item</b> and <b>ItemRevision</b> objects based
     * on attribute keys
     */
    struct GetItemFromAttributeInfo
    {
        /**
         * A map of attribute names and values (<code>string/string</code>) used to peform the
         * search. Typical keys are "item_id", "object_type", "object_name", "owning_organization",
         * and "date_released".  A special key, "rev_id", may also be used to specify a single
         * related <b>ItemRevision</b> object to retrieve. This "rev_id" key is effective only
         * if the nRev parameter equals zero.
         */
        GetItemAttributeMap itemAttributes;
        /**
         * A list of revision ID strings specifying <b>ItemRevison</b> objects to retrieve.
         * This parameter only takes effect if the <code>nRev</code> parameter equals zero.
         * This list of revision IDs can be used independent of the "rev_id" key value in <code>itemAttributes</code>
         */
        std::vector< std::string > revIds;
    };

    /**
     * This data structure contains an <b>Item</b> and a list of related <b>ItemRevision</b>
     * objects retrieved by a <code>getItemFromAttribute</code> operation.
     */
    struct GetItemFromAttributeItemOutput
    {
        /**
         * The retrieved <b>Item</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The list of related <b>ItemRevision</b> objects
         */
        std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::GetItemFromAttributeItemRevOutput > itemRevOutput;
    };

    /**
     * Contains a single ItemRevision retrieved by the getItemFromAttribute operation
     */
    struct GetItemFromAttributeItemRevOutput
    {
        /**
         * The retrieved ItemRevision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * list of Datasets associated with the ItemRevision
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  > datasets;
    };

    /**
     * The return structure from from <code>getItemFromAttribute</code> operation. Contains
     * a list of <code>GetItemFromAttributeItemOutput</code> structures.
     */
    struct GetItemFromAttributeResponse
    {
        /**
         * A list of found <b>Item</b> and <b>ItemRevision</b> objects
         */
        std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::GetItemFromAttributeItemOutput > output;
        /**
         * Standard <code>ServerData</code> member with any returned error codes and messages
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure holds response from getTableProperties.
     */
    struct GetTablePropertiesResponse
    {
        /**
         * This vector contains a list of <i>TableInfo</i>, and each <i>TableInfo</i> contains
         * information pertaining to the specific <b>Table</b> it references.
         */
        std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::TableInfo > tableInfo;
        /**
         * The ServiceData structure is used to return the updated Table objects in the update
         * section and also any errors encountered during this operation call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains table cell value type info.
     */
    struct TableCellValueTypeInfo
    {
        /**
         * This specifies the data type that the cell of the table can hold. The type specified
         * in this string, should be one of the below supported type:
         * <br>
         * <ul>
         * <li type="disc">TableCellInt
         * </li>
         * <li type="disc">TableCellString
         * </li>
         * <li type="disc">TableCellDouble
         * </li>
         * <li type="disc">TableCellLogical
         * </li>
         * <li type="disc">TableCellHex
         * </li>
         * <li type="disc">TableCellSED
         * </li>
         * <li type="disc">TableCellBCD
         * </li>
         * <li type="disc">TableCellDate
         * </li>
         * </ul>
         */
        std::string type;
        /**
         * A list of values
         */
        std::vector< std::string > strValues;
    };

    /**
     * This structure contains Table Cell Info.
     */
    struct TableCellInfo
    {
        /**
         * This specifies the row number of the cell in the <b>Table</b>.
         */
        int row;
        /**
         * This specifies the column number of the cell in the <b>Table</b>.
         */
        int column;
        /**
         * This is a string which can be used to capture a description for the cell.
         */
        std::string desc;
        /**
         * This is a structure which contains information pertaining to a value on the cell.
         */
        Teamcenter::Services::Core::_2009_10::Datamanagement::TableCellValueTypeInfo value;
    };

    /**
     * This structure contains Table Definition Info.
     */
    struct TableDefInfo
    {
        /**
         * This specifies the number of rows in the <b>Table</b>.
         */
        int rows;
        /**
         * This specifies the number of columns in the <b>Table</b>.
         */
        int columns;
        /**
         * This is a vector of strings, each string representing the labels corresponding to
         * a row in the <b>Table</b>.
         */
        std::vector< std::string > rowLabels;
        /**
         * This is a vector of strings, each string representing the labels corresponding to
         * a column in the <b>Table</b>.
         */
        std::vector< std::string > colLabels;
        /**
         * tableDef is of type <b>TableDefinition</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TableDefinition>  tableDef;
    };

    /**
     * Table Info
     */
    struct TableInfo
    {
        /**
         * The Business Object corresponding to the Table
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  tableObject;
        /**
         * Meta information about the Table such as the row labels, columns labels, and its
         * size are contained in this structure.
         */
        Teamcenter::Services::Core::_2009_10::Datamanagement::TableDefInfo tableDefInfo;
        /**
         * This is a vector of the structures that contain information pertaining to each of
         * the cells in the Table.
         */
        std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::TableCellInfo > tableCells;
    };




    /**
     * This operation allows client applications to obtain the properties pertaining to
     * one or more <b>Table</b> Business Objects. Client developers will need to pass in
     * references to each <b>Table</b> that they need to query information on.  Note that
     * the input vector needs to contain only references to the Teamcenter Table business
     * object, this operation cannot be used to fetch properties of any other Business Objects.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used by a client developer, when he/she deals with obtaining
     * specific <b>Table</b> Business Object specific properties. Typically, <b>Table</b>
     * Business Objects are not themselves visible in the Teamcenter workspace and appear
     * as properties of other owning objects that are visible in the workspace.  The typical
     * scenario in such cases is that a user attempts to obtain/view all properties of the
     * the owning object, which may have one or more reference properties pointing to a
     * Table.  A custom UI would need to display the Table related properties on the parent
     * object in such cases and rendering these properties would require the client applications
     * to obtain such information using the <i>getTableProperties</i> operation.
     * <br>
     * One such example of existing usage of this operation, is the existing Teamcenter
     * Rich Client functionality for viewing properties an Integer type of <i>Parameter
     * Definition</i> [ <b>ParmDefIntRevision</b> Business Object ]. This Business Object
     * and the functionality for viewing its properties are provided by the add on Calibration
     * and Configuration Data Management module, through custom stylesheets which render
     * a Table like UI for each referenced Table property.  At the time of rendering the
     * UI, the client operations call the <i>getTableProperties</i> operation to obtain
     * properties such as the number of rows, number of columns, labels for each row and
     * column, the type of the cells and cell values and descriptions for each cell in the
     * table.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getProperties
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CCDM - Calibration and Configuration Data Management
     *
     * @param table
     *        This is a vector of the Table Business Objects for which the properties need to be
     *        obtained.
     *
     * @return
     *         Returns GetTablePropertiesResponse
     *
     */
    virtual Teamcenter::Services::Core::_2009_10::Datamanagement::GetTablePropertiesResponse getTableProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Table>  >& table ) = 0;

    /**
     * This operation allows client applications to set the properties pertaining to one
     * or more <b>Table</b> business objects. Client developers will need to set information
     * pertaining to the number of rows, columns, descriptions of each row and column, and
     * cell information for each cell of the <b>Table</b>. The cell information must contain
     * the type of cell, value to be placed in the cell, and optionally, a description of
     * those values. The current operation only works on cells of specific types and it
     * is mandatory that the type of the cells being set on the input structure corresponds
     * to one of the cell types defined in the database schema viewable through the BMIDE.
     * Supported valid types are:
     * <br>
     * <ul>
     * <li type="disc"><i>TableCellInt</i>
     * </li>
     * <li type="disc"><i>TableCellString</i>
     * </li>
     * <li type="disc"><i>TableCellDouble</i>
     * </li>
     * <li type="disc"><i>TableCellLogical</i>
     * </li>
     * <li type="disc"><i>TableCellHex</i>
     * </li>
     * <li type="disc"><i>TableCellSED</i>
     * </li>
     * <li type="disc"><i>TableCellBCD</i>
     * </li>
     * <li type="disc"><i>TableCellDate</i>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation can be used by a client developer, when he/she deals with setting
     * <b>Table</b> Business Object specific properties. Typically, <b>Table</b> Business
     * Objects are not themselves visible in the Teamcenter workspace and appear as properties
     * of other owning objects that are visible in the workspace. Modification to the owning
     * objects, may involve changes to one or more of the Table properties that they reference
     * through the Table.  In such cases, the <i>setTableProperties</i> is to be called,
     * passing in the input structure which is setup to specify the modified values.
     * <br>
     * One such example of existing usage of this operation, is the existing Teamcenter
     * Rich Client functionality for modification of an Integer type of <i>Parameter Definition</i>
     * [ <b>ParmDefIntRevision</b> Business Object ]. This Business Object and the functionality
     * for its modification are provided by the add on Calibration and Configuration Data
     * Management module.  During modification, of the integer parameter definition object,
     * client code renders table like UI for each table property of the Parameter Definition,
     * gathers the input values from the UI and populates a vector of the input structure
     * of type <i>TableInfo</i>, sets the type of thecells to <i>TableCellInt</i> and makes
     * the operation call. Client code will then parse the Service Data returned from the
     * operation to obtain a handle to the updated <b>Table</b> Business Object. Errors,
     * if any were encountered during the operation execution, are handled via the Service
     * Data.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CCDM - Calibration and Configuration Data Management
     *
     * @param tableData
     *        This vector contains a list of <i>TableInfo</i>, and each <i>TableInfo</i> contains
     *        information pertaining to the specific <b>Table</b> it references. The data present
     *        in the <i>TableInfo</i> structures are used to modify specific cell values and/or
     *        descriptions of the rows, columns or values.
     *
     * @return
     *         This operation returns a Service Data structure. The updated Table business objects
     *         are included in the updated service data member list, which contains any modifications
     *         to row and column descriptions and the size of the table. Any errors encountered
     *         at the time of modification are included as part of the Service Data errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setTableProperties ( const std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::TableInfo >& tableData ) = 0;

    /**
     * This service retrieves <b>Item</b> and its related <b>ItemRevision</b> objects based
     * on the supplied attribute key-value pairs supplied in the <code>infos</code> list.
     * All the key-value pairs except for the <code>rev_id</code> key are used to create
     * a query for <b>Item</b> objects.
     * <br>
     * <br>
     * Once a set of <b>Item</b> objects have been retrieved, their <b>ItemRevision</b>
     * objects are retrieved based on the following rules:
     * <br>
     * <ul>
     * <li type="disc">If  <code>nRev</code> is a negative value then all the <b>ItemRevision</b>
     * objects are returned
     * </li>
     * <li type="disc">If <code>nRev</code> is a positive value then the <code>nRev</code>
     * most recent <b>ItemRevision</b> objects are returned. If <code>nRev</code> is greater
     * than the number of revisions then all of them are returned.
     * </li>
     * <li type="disc">If <code>nRev</code> is zero and a <code>rev_id</code> attribute
     * key was supplied in the attribute key-value pairs, then that <b>ItemRevision</b>
     * object is returned.
     * </li>
     * <li type="disc">If <code>nRev</code> is zero and rev ids values were supplied in
     * the <code>GetItemFromAttributeInfo</code> object then all of the specified rev ids
     * will be returned.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param infos
     *        The list of attribute value keys for the retrieval. The attributes must be the unique
     *        key attributes of the class. Currently, only item_id attribute should be used
     *
     * @param nRev
     *        Maximum number of <b>ItemRevision</b> objects to retrieve.
     *        <br>
     *        <ul>
     *        <li type="disc">nRev < 0        retrieve all available ItemRevision objects
     *        </li>
     *        <li type="disc">nRev = 0        retrieve no ItemRevision objects
     *        </li>
     *        <li type="disc">nRev > 0        retrieve the most recent nRev number of ItemRevision
     *        objects
     *        </li>
     *        </ul>
     *
     * @param pref
     *        <code>GetItemFromIdPref</code> object used to filter the returned <b>ItemRevision</b>
     *        objects. If a <b>Dataset</b> is found related to the <b>ItemRevision</b> with this
     *        relation type name and is one of the types specified in the list of object type names,
     *        return the <b>ItemRevision</b> object
     *
     * @return
     *         Retrieves the <b>Item</b> and <b>ItemRevision</b> objects.The following partial errors
     *         may be returned:
     *         <br>
     *         <ul>
     *         <li type="disc">48008 - If a specified item ID is not found
     *         </li>
     *         <li type="disc">48053 - If an item revision ID specified in the rev_id attribute
     *         key-value pair is not found
     *         </li>
     *         <li type="disc">48053 - If an item revision ID specified in the GetItemFromAttributeInfo
     *         revIds list is not found
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2009_10::Datamanagement::GetItemFromAttributeResponse getItemFromAttribute ( const std::vector< Teamcenter::Services::Core::_2009_10::Datamanagement::GetItemFromAttributeInfo >& infos,
        int nRev,
        const Teamcenter::Services::Core::_2007_01::Datamanagement::GetItemFromIdPref&  pref ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

