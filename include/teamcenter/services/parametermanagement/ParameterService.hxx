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

#ifndef TEAMCENTER_SERVICES_PARAMETERMANAGEMENT_PARAMETERSERVICE_HXX
#define TEAMCENTER_SERVICES_PARAMETERMANAGEMENT_PARAMETERSERVICE_HXX

#include <teamcenter/services/parametermanagement/_2009_10/Parameter.hxx>
#include <teamcenter/services/parametermanagement/_2012_02/Parameter.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/parametermanagement/ParameterManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Parametermanagement
        {
            class ParameterService;

/**
 * The <i>Parameter</i> service provides operations to get and set the <b>BitDefintion</b>
 * properties, get and set the <b>BitValue</b> properties, set the SED <b>Table</b>
 * properties, refresh and load a parameter dictionary/project, refresh and load memory
 * layouts and blocks.
 * <br>
 * The Parameter service can be used for the following use cases:
 * <br>
 * <ul>
 * <li type="disc">Get bit definition for a <b>BitDefinition</b>
 * </li>
 * <li type="disc">Create a <b>BitDefinition</b>
 * </li>
 * <li type="disc">Modify a <b>BitDefinition</b>
 * </li>
 * <li type="disc">Get a <b>BitValue</b>
 * </li>
 * <li type="disc">Modify a <b>BitValue</b>
 * </li>
 * <li type="disc">Modify a SED <b>Table</b>
 * </li>
 * <li type="disc">Refresh and load a <b>Parameter Dictionary</b>/<b>Project</b>
 * </li>
 * <li type="disc">Refresh and load Memory Layouts and Blocks
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaparametermanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaparametermanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAPARAMETERMANAGEMENTSTRONGMNGD_API ParameterService
    : public Teamcenter::Services::Parametermanagement::_2009_10::Parameter,
             public Teamcenter::Services::Parametermanagement::_2012_02::Parameter
{
public:
    static ParameterService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation loads the bit definition for each <code>ccdm::BitDef</code> supplied.
     * Bit definition contains information for properties such as byte number, bit number
     * within the byte, name, meaning of 0 and meaning of 1.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Get bit definition for a BitDef</b>
     * <br>
     * You can get the bit definition data using <i>getBitDefinitionProperties</i> operation
     * by providing the <b>BitDef</b> tag.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitDefinitions
     *        BitDef objects
     *
     * @return
     *         The bit definition for the input <b>BitDef</b> is returned via <code>GetBitDefinitionPropertiesResponse</code>.
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2009_10::Parameter::GetBitDefinitionPropertiesResponse getBitDefinitionProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BitDef>  >& bitDefinitions ) = 0;

    /**
     * This operation loads the bit value for each <code>ccdm::BitValue</code> supplied.
     * Bit value contains information for properties such as value (true/false), bit definition
     * object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Get bit value for a BitValue object</b>
     * <br>
     * You can get the bit value data using <i>getBitValueProperties</i> operation by providing
     * the <b>BitValue</b> object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitValues
     *        <b>BitValue</b> objects
     *
     * @return
     *         The bit value details for the input <b>BitValue</b> is returned via <code>GetBitValuePropertiesResponse</code>.
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2009_10::Parameter::GetBitValuePropertiesResponse getBitValueProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BitValue>  >& bitValues ) = 0;

    /**
     * This operation creates or modifies a <b>BitDef</b> business object for each <code>BitDefinitionInfo</code>
     * supplied. The <code>BitDefinitionInfo</code> contains information for properties
     * such as byte number, bit number within the byte, name, meaning of 0, and meaning
     * of 1. If the <b>BitDef</b> is not null in <code>BitDefinitionInfo</code> structure,
     * the operation updates this <b>BitDef</b> with the rest of the property values. Otherwise
     * the operation creates a new <b>BitDef</b> with the specific property values.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Create a Bit Definition</b>
     * <br>
     * You can create a new <b>BitDef</b> using <i>setBitDefinitionProperties</i> operation
     * by providing <code>bitDefinitionObject</code> as null in <code>BitDefinitionInfo</code>
     * structure.
     * <br>
     * <br>
     * <b>Use case 2: Modify a Bit Definition</b>
     * <br>
     * You can modify an existing <b>BitDef</b> using <i>setBitDefinitionProperties</i>
     * operation by providing <code>bitDefinitionObject</code> as an existing <b>BitDef</b>
     * in <code>BitDefinitionInfo</code> structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitDefinitionInfo
     *        Structures containing the details of the bit definition to be created/modified.
     *
     * @return
     *         The created/updated <b>BitDef</b> business objects are returned via <code>ServiceData</code>
     *         in Created/Updated lists.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setBitDefinitionProperties ( const std::vector< Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitDefinitionInfo >& bitDefinitionInfo ) = 0;

    /**
     * This operation modifies a <b>BitValue</b> business object for each <code>BitValueInfo</code>
     * supplied. The <code>BitValueInfo</code> contains information for properties such
     * as value (true/false), bit definition object. The <b>BitValue</b> business object
     * is specified in <code>BitValueInfo</code> structure as well.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Modify a Bit Value</b>
     * <br>
     * You can modify an existing <b>BitValue</b> using <i>setBitValueProperties</i> operation
     * by providing bitValueObject as an existing <b>BitValue</b> in <code>BitValueInfo</code>
     * structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitValInfo
     *        Structures containing the details of the bit value to be modified.
     *
     * @return
     *         The updated <b>BitValue</b> business objects are returned via <code>ServiceData</code>
     *         in Updated lists.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setBitValueProperties ( const std::vector< Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitValueInfo >& bitValInfo ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParameterService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/parametermanagement/ParameterManagement_undef.h>
#endif

