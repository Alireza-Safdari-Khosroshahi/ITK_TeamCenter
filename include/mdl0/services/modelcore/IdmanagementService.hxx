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

#ifndef MDL0_SERVICES_MODELCORE_IDMANAGEMENTSERVICE_HXX
#define MDL0_SERVICES_MODELCORE_IDMANAGEMENTSERVICE_HXX

#include <mdl0/services/modelcore/_2011_06/Idmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            class IdmanagementService;

/**
 * This service contains utilities to assist with assignment of ID values for application
 * models (Mdl0ApplicationModel) and their content in support of create, save as, and
 * revise actions.
 * <br>
 * Currently one operation is provided by this service (<code>autoAssignValues</code>).
 * <br>
 * <br>
 * <b>Use case:</b>
 * <br>
 * Please see documentation for <code>autoAssignValues</code> operation.
 * <br>
 * <br>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmdl0soamodelcorestrongmngd.dll
 * </li>
 * <li type="disc">libmdl0soamodelcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class MDL0SOAMODELCORESTRONGMNGD_API IdmanagementService
    : public Mdl0::Services::Modelcore::_2011_06::Idmanagement
{
public:
    static IdmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Auto generates the values of the auto assignable  properties in bulk. The input parameters
     * expected on the input, include the business object or the business object name.
     * For cases where the assignment is based on other properties, those values must be
     * supplied on input; this includes any reference objects.  The output includes the
     * generated values as well as other properties defined in the input.
     * <br>
     * <br>
     * Support is currently limited to the following Collaborative Product Development (CPD)
     * specific classes:
     * <br>
     * <b>&nbsp;&nbsp;&nbsp;&nbsp;Mdl0ApplicationModel (</b><code>mdl0model_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Ptn0Partition (</b><code>ptn0partition_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Cpd0DesignElement (</b><code>cpd0design_element_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Cpd0DesignFeature (</b><code>cpd0design_feature_id</code><b>)
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Cpd0DesignControlElement (c</b><code>pd0design_control_element_id</code><b>)
     * <br>
     * </b>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the authoring use case for model content.It is used to fill in
     * autoassignable property values. Applications may choose to allow a user to enter
     * a value or assign one.
     * <br>
     * Use Case 1: <b>Assign ID during Create </b>
     * <br>
     * During creation of a new object, the user requests the system to assign a value
     * <br>
     * <ul>
     * <li type="disc">Application constructs <code>AssignInput</code> and specifies the
     * business object type (boType) of the object being created and an operationType: <code>CreateOperation</code>.
     * A client ID (unique for the call) is also specified on the <code>AssignInput</code>
     * for error reporting.
     * </li>
     * <li type="disc">Generate new ID values for the object using the <code>autoAssignValues</code>
     * operation.
     * </li>
     * <li type="disc">Post process the new ID value (e.g. display it back to the user).
     * </li>
     * </ul>
     * <br>
     * Use Case 2:<b> Assign ID during Revise </b>
     * <br>
     * During revise of an existing object, the user requests the system to assign an ID
     * value to the new revision.
     * <br>
     * <ul>
     * <li type="disc">Application constructs AssignInput and specifies the business object
     * (bo) of the object being revised and an operationType: <code>ReviseOperation</code>.
     * A client ID (unique for the call) can be optionally specified on the <code>AssignInput</code>.
     * </li>
     * <li type="disc">Generate ID value for new revision using the <code>autoAssignValues</code>
     * operation.
     * </li>
     * <li type="disc">Post process the ID value (e.g. display it back to the user).
     * </li>
     * </ul>
     * <br>
     * Use Case 3: <b>Assign ID during SaveAs </b>
     * <br>
     * During saveas (copy) of an existing object, the user requests the system to assign
     * an ID value to the new object.
     * <br>
     * <ul>
     * <li type="disc">Application constructs <code>AssignInput</code> and specifies the
     * business object (bo) of the object being revised and an operationType: <code>SaveAsOperation</code>.A
     * client ID (unique for the call) can be optionally specified on the <code>AssignInput</code>.
     * </li>
     * <li type="disc">Generate ID value for new revision using the <code>autoAssignValues</code>
     * operation.
     * </li>
     * <li type="disc">Post process the ID value (e.g. display it back to the user).
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @param input
     *        A list of <code>AssignInput</code> for which property values should be autoassigned.
     *
     * @return
     *         The the input data with autoassigned values filled in.The errors if any are returned
     *         in the service data.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Idmanagement::AssignResponse autoAssignValues ( const std::vector< Mdl0::Services::Modelcore::_2011_06::Idmanagement::AssignInput >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IdmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

