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

#ifndef TEAMCENTER_SERVICES_PARAMETERMANAGEMENT__2012_02_PARAMETER_HXX
#define TEAMCENTER_SERVICES_PARAMETERMANAGEMENT__2012_02_PARAMETER_HXX

#include <teamcenter/soa/client/model/TableDefinition.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/parametermanagement/ParameterManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Parametermanagement
        {
            namespace _2012_02
            {
                class Parameter;

class TCSOAPARAMETERMANAGEMENTSTRONGMNGD_API Parameter
{
public:

    struct GetMemoryInfoResponse;
    struct MemLayoutOrBlockInfo;
    struct MemoryBlockInfo;
    struct MemoryContentInfo;
    struct MemoryLayoutInfo;
    struct MemoryOverrideInfo;
    struct ParmDefRecordInfo;
    struct TableCellSEDInfo;
    struct TableDefInfo;
    struct TableSEDInfo;

    /**
     * <code>GetMemoryInfoResponse</code> structure represents all the details of the memory
     * layouts/blocks, unassigned parameters and override records to be loaded.
     */
    struct GetMemoryInfoResponse
    {
        /**
         * Memory layout list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemoryLayoutInfo > memLayoutInfo;
        /**
         * Memory block list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemoryBlockInfo > memBlockInfo;
        /**
         * Unassigned parameter definition list
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > unassignedParmDefRevs;
        /**
         * Override record list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemoryOverrideInfo > memOverrides;
        /**
         * Service data to hold SOA framework objects that were created or updated by the service.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>MemLayoutOrBlockInfo</code> structure represents the memory layout/block object
     * to load.
     */
    struct MemLayoutOrBlockInfo
    {
        /**
         * Memory layout or block business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  memLayoutOrBlock;
        /**
         * True indicates that <code>memLayoutOrBlock</code> is a memory layout.
         */
        bool isLayout;
    };

    /**
     * <code>MemoryBlockInfo</code> structure represents the details of the memory block
     * to be loaded.
     */
    struct MemoryBlockInfo
    {
        /**
         * Memory block business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  memBlock;
        /**
         * Memory block header business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  headerObject;
        /**
         * Memory block trailer business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  trailerObject;
        /**
         * Sub block list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemoryBlockInfo > memBlocks;
        /**
         * Assigned parameter list to this memory block
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::ParmDefRecordInfo > parmDefRecords;
    };

    /**
     * <code>MemoryContentInfo</code> structure represents the details of the memory content
     * to be loaded.
     */
    struct MemoryContentInfo
    {
        /**
         * Memory content business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  memContent;
        /**
         * Memory block list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemoryBlockInfo > memBlocks;
        /**
         * Assigned parameter list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::ParmDefRecordInfo > parmDefRecords;
    };

    /**
     * <code>MemoryLayoutInfo</code> structure represents the details of the memory layout
     * to be loaded.
     */
    struct MemoryLayoutInfo
    {
        /**
         * Memory layout business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  layoutObject;
        /**
         * Memory layout header business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  headerObject;
        /**
         * Memory layout trailer business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  trailerObject;
        /**
         * Memory content information
         */
        Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemoryContentInfo memoryContent;
    };

    /**
     * <code>MemoryOverrideInfo</code> structure represents the details of the override
     * records to be loaded.
     */
    struct MemoryOverrideInfo
    {
        /**
         * Override container business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  overrideContainer;
        /**
         * Memory override record list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::ParmDefRecordInfo > memOverrides;
        /**
         * Converion rule override record list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::ParmDefRecordInfo > convRuleOverrides;
    };

    /**
     * <code>ParmDefRecordInfo</code> structure represents the details of the assigned parameter
     * to be loaded.
     */
    struct ParmDefRecordInfo
    {
        /**
         * Parameter record business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parmDefRec;
        /**
         * Parameter definition business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parmDefRev;
    };

    /**
     * <code>TableCellSEDInfo</code> structure represents all the details of <b>TableCellSED</b>
     * to be created/updated. If the cell [row, column] is found in the Table in Teamcenter,
     * <i>setTableSEDProperties</i> operation will update this cell with the specified properties.
     * Otherwise, <i>setTableSEDProperties</i> operation will create a new cell.
     */
    struct TableCellSEDInfo
    {
        /**
         * Cell row index
         */
        int row;
        /**
         * Cell column index
         */
        int col;
        /**
         * Domain element name
         */
        std::string domainElementName;
        /**
         * Domain element description
         */
        std::string description;
        /**
         * Domain element value
         */
        std::string value;
    };

    /**
     * <code>TableDefInfo</code> structure represents all the details of Table Definition
     */
    struct TableDefInfo
    {
        /**
         * Number of rows
         */
        int rows;
        /**
         * Number of columns
         */
        int cols;
        /**
         * <b>TableDefinition</b> business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TableDefinition>  tableDef;
        /**
         * Row labels
         */
        std::vector< std::string > rowLabels;
        /**
         * Column labels
         */
        std::vector< std::string > colLabels;
    };

    /**
     * <code>TableSEDInfo</code> structure represents all the details of SED <b>Table</b>
     * to be updated.
     */
    struct TableSEDInfo
    {
        /**
         * <b>Table</b> business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  tableObject;
        /**
         * Table definition information
         */
        Teamcenter::Services::Parametermanagement::_2012_02::Parameter::TableDefInfo tableDefInfo;
        /**
         * Table cell list
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::TableCellSEDInfo > tableCells;
    };




    /**
     * This operation refreshes and loads memory layouts and/or blocks information for the
     * parameter dictionary/project supplied. If <code>memLayoutOrBlock</code> is empty,
     * the operation finds out unassigned parameters in context of the parameter dictionary/project.
     * Meanwhile, it loads the associated memory layouts, as well as the memory blocks and
     * sub blocks if <code>includeChildren</code> is true. However, if <code>memLayoutOrBlock</code>
     * is not empty, the operation loads the assigned parameters for each memory layout/block,
     * as well as the sub blocks if includeChildren is true. If <code>parmGrpDevRev</code>
     * points to a parameter project and <code>includeOverrides</code> is true, the operation
     * loads the override records from the associated override container as well.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case1: Refresh and load a parameter dictionary/project</b>
     * <br>
     * You can refresh and load a parameter dictionary/project using <i>getMemoryLayoutOrBlockInfo</i>
     * operation by setting <code>memLayoutOrBlock</code> as empty. The operation finds
     * out the unassigned parameters in context of the parameter dictionary/project. It
     * loads the associated memory layouts, as well as the memory blocks and sub blocks
     * if <code>includeChildren</code> is true. If <code>includeOverrides</code> is true
     * and <code>parmGrpDev</code> points to a parameter project, the operation loads the
     * override records from the associated override container as well.
     * <br>
     * <br>
     * <b>Use Case2: Refresh and load memory layouts and blocks</b>
     * <br>
     * You can refresh and load memory layouts and blocks using <i>getMemoryLayoutOrBlockInfo</i>
     * operation by specifying memory layout/block objects in the <code>memLayoutOrBlock</code>.
     * The operation loads the assigned parameters for each selected memory layout/block,
     * as well as the sub blocks if <code>includeChildren</code> is true. If <code>includeOverrides</code>
     * is true and <code>parmGrpDev</code> points to a parameter project, the operation
     * loads the override records from the associated override container as well.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param parmGrpDefRev
     *        <b>ParmGrpDefRevision</b> business object. It shall be parameter dictionary or project.
     *        If <b>ParmGrpDef</b> represents property equals <b>Parameter Dictionary</b>, <code>ParmGrpDefRev</code>
     *        points to a parameter dictionary. If equaling to <b>Parameter Breakdown</b>, <code>ParmGrpDefRev</code>
     *        points to a parameter project.
     *
     * @param memLayoutOrBlock
     *        Structures of memory layout or block information
     *
     * @param includeChildren
     *        True to load the sub blocks
     *
     * @param includeOverrides
     *        True to load the override records. Only if <code>parmGrpDefRev</code> points to a
     *        parameter project, is the parameter useful.
     *
     * @return
     *         Unassigned parameters (if <code>memLayoutOrBlock</code> is empty) in context of the
     *         parameter dictionary/project or assigned parameters (if <code>memLayoutOrBlock</code>
     *         is not empty) for the memory layouts/blocks supplied, the associated memory layouts/blocks,
     *         and the override records (if <code>includeOverrides</code> is true) are returned
     *         via <code>GetMemoryInfoResponse</code>. If the input parameters are invalid, the
     *         errors are returned in <code>ServiceData</code>. Following are some possible errors
     *         returned in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">248450 <code>ParmGrpDefRev</code> cannot be null.
     *         </li>
     *         <li type="disc">248451 <code>ParmGrpDefRev</code> is not a valid object.
     *         </li>
     *         <li type="disc">248452 <code>ParmGrpDefRev</code> is not the type of <code>ParmGrpDefRevision</code>.
     *         </li>
     *         <li type="disc">248455 <code>ParmGrpDefRev</code> is not a parameter dictionary or
     *         project.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2012_02::Parameter::GetMemoryInfoResponse getMemoryLayoutOrBlockInfo ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parmGrpDefRev,
        const std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::MemLayoutOrBlockInfo >& memLayoutOrBlock,
        bool includeChildren,
        bool includeOverrides ) = 0;

    /**
     * This operation modifies a SED (State Encoded) <b>Table</b> for each <code>TableSEDInfo</code>
     * supplied. The <code>TableSEDInfo</code> contains information for properties such
     * as table definition, and table cells information. The <b>Table</b> business object
     * is specified in <code>TableSEDInfo</code> structure as well.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Modify a SED Table</b>
     * <br>
     * You can modify an existing SED <b>Table</b> using <i>setTableSEDProperties</i> operation
     * by providing tableObject as an existing SED <b>Table</b> in <code>TableSEDInfo</code>
     * structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param tableData
     *        Structures containing the details of the SED <b>Table</b> to be modfied.
     *
     * @return
     *         The updated SED <b>Table</b> business objects are returned via <code>ServiceData</code>
     *         in Updated lists.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setTableSEDProperties ( const std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Parameter::TableSEDInfo >& tableData ) = 0;


protected:
    virtual ~Parameter() {}
};
            }
        }
    }
}

#include <teamcenter/services/parametermanagement/ParameterManagement_undef.h>
#endif

