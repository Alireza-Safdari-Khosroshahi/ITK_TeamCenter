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

#ifndef TEAMCENTER_SERVICES_CORE_STRUCTUREMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_STRUCTUREMANAGEMENTSERVICE_HXX

#include <teamcenter/services/core/_2008_06/Structuremanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class StructuremanagementService;

/**
 * StructureManagement services allows user to create, delete or validate associations
 * between <i>BOMLines</i>, get primary or secondary objects associated with a <i>BOMLine</i>.
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * StructureManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API StructuremanagementService
    : public Teamcenter::Services::Core::_2008_06::Structuremanagement
{
public:
    static StructuremanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates the specified association between primary and secondary <b>BOMLine</b>
     * objects in a structure.  As the name indicates, these associations are created in
     * a specific context and are applicable only in that context. The context is specified
     * as an additional input in the input structure, by the caller. Some examples of these
     * associations are: the <b>ConnectedTo, ImplementedBy, RealizedBy</b> relations that
     * are provided in Teamcenter [see Use case]. This operation takes a vector of InStructureAssociationInfo
     * as input. The input structures contain information on the <b>BOMLine</b> objects
     * that need to be associated, what context they need to be associated in and the type
     * of association. Note that the associations created are only valid in the context
     * specified.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use this operation to create an association between BOMLine objects. This is a generic
     * Teamcenter service to create various types of associations. The type of the association
     * that gets created depends on the Association Type specified in the input structure.
     * <br>
     * The ConnectedTo  functionality establishes an association between 1 or more BOMLine
     * objects and a Connection BOMLine. The association signifies that the BOMLine objects
     * are connected to the Connection BOMLine in a certain context.  Outside of that context
     * the association is not valid. The caller of this operation provides as input, one
     * or more BOMLine objects, and a Connection BOMLine. The associationType should be
     * set in the input structure to ConnectedTo and specifies a BOMLine that will act as
     * a context line within which the association is valid.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param inputs
     *        This is a vector of InStructureAssociationInfo structure. Each element shall consist
     *        of a primary <b>BOMLine</b>, the secondary <b>BOMLine</b> objects to be associated
     *        with the primary, the line in whose context the association takes place and the association
     *        type.
     *
     * @return
     *         This operation returns a <i>CreateInStructureAssociationResponse</i> structure which
     *         contains the primary and secondary <b>BOMLine</b> objects in the standard <i>ServiceData</i>
     *         list. Any failures will be returned in the <i>ServiceData</i> list of partial errors.
     *         In addition to standard errors that could be encountered during creation of associations,
     *         the following set of partial errors are specifically returned by this operation.
     *         <br>
     *         <b>Partial Errors</b>
     *         <br>
     *         <ul>
     *         <li type="disc"><i>Error Id. 214313</i>  Error in creating %1$ association.
     *         </li>
     *         <li type="disc"><i>Error Id. 214314 </i> Unable to create %1$ association: %2$ type
     *         is not supported.
     *         </li>
     *         <li type="disc"><i>Error Id. 214315</i>  Unable to create %1$ association: the input
     *         primary BOMLine is null.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Structuremanagement::CreateInStructureAssociationResponse createInStructureAssociations ( const std::vector< Teamcenter::Services::Core::_2008_06::Structuremanagement::InStructureAssociationInfo >& inputs ) = 0;

    /**
     * This operation gets the primary <b>BOMLines </b>like<b> PSConnection, Signal</b>
     * of an association given the secondary object and association type.  Examples of these
     * associations are: <b>ConnectedTo, ImplementedBy, RealizedBy, RoutedBy, FixingToSegment,
     * DeviceToConnector, SignalToTransmitter</b>. This operation takes a vector of GetPrimariesOfInStructureAssociationInfo
     * as input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A typical usecase for this operation is where callers would like to obtain primary
     * <b>BOMLine</b> objects by providing the association type and the corresponding secondary
     * <b>BOMLine</b> associated.  In a <b>SignalToTransmitter</b> association for example,
     * if the transmitting <b>BOMLine</b>  is provided, callers can get the corresponding
     * <b>Signal</b> which is the primary <b>BOMLine</b> in this relation.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param inputs
     *        This is a vector of <i>GetPrimariesOfInStructureAssociationInfo</i> structure. Each
     *        element consists of a secondary <b>BOMLine</b>, the context <b>BOMLine</b> of the
     *        association and the association type.
     *
     * @return
     *         This operation returns a GetPrimariesOfInStructureAssociationResponse that contains
     *         the secondary bomline, the primary bomlines fetched and the association type between
     *         these two lines. Service data contains the primary bomline business objects and partial
     *         errors if any.
     *         <br>
     *         <b>Partial Errors&nbsp;&nbsp;&nbsp;&nbsp;</b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         
     *         <br>
     *         <ul>
     *         <li type="disc"><i>Error No. 214316 </i> Unable to get primaries of secondary from
     *         %1$ association: the input secondary BOMLine is null.
     *         </li>
     *         <li type="disc"><i>Error No. 214317 </i> Error in getting primaries of secondary
     *         from %1$ association.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Structuremanagement::GetPrimariesOfInStructureAssociationResponse getPrimariesOfInStructureAssociation ( const std::vector< Teamcenter::Services::Core::_2008_06::Structuremanagement::GetPrimariesOfInStructureAssociationInfo >& inputs ) = 0;

    /**
     * Given the primary object and association type, returns the secondary <b>BOMLine</b>
     * business objects of in structure associations. These associations can be<b> ConnectedTo,
     * ImplementedBy, RealizedBy, RoutedBy, FixingToSegment, or DeviceToConnector</b>. It
     * takes a vector of <i>GetSecondariesOfInStructureAssociationInfo</i> as input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Users shall use this operation to get secondary <b>BOMLine</b> business objects for
     * a given association type and the primary object associated with it.
     * <br>
     * For instance, this operation could be used to get all the secondary GDE lines connected
     * to a <b>PSConnection</b> by passing the association type as <b>ConnectTo</b>. Similarly,
     * it can be used to get the connector lines connected to the <b>Device</b> Line by
     * passing appropriate primary Device and the association type as <b>DeviceToConnector</b>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param inputs
     *        This is a vector of <i>GetSecondariesOfInStructureAssociationInfo</i> structure.
     *        Each element shall consist of a primary <b>BOMLine</b>, the parent line in whose
     *        context the association takes place and the association type.
     *
     * @return
     *         This operation returns a <i>GetSecondariesOfInStructureAssociationResponse</i> that
     *         contains vector of <i>SecondariesOfInStructureAssociation</i>. Each element of this
     *         vector has the primary <b>BOMLine</b>, the secondary GDE lines fetched and the association
     *         type between these two objects. Service data contains the secondary <b>BOMLine</b>
     *         business objects fetched and can contain partial errors if any.
     *         <br>
     *         <b>Partial Errors </b>
     *         <br>
     *         <i>Error Id. 214319 </i> Error in getting secondaries of primary from %1$ association.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Structuremanagement::GetSecondariesOfInStructureAssociationResponse getSecondariesOfInStructureAssociation ( const std::vector< Teamcenter::Services::Core::_2008_06::Structuremanagement::GetSecondariesOfInStructureAssociationInfo >& inputs ) = 0;

    /**
     * Given the primary <b>BOMLine</b>, the association type, and the secondary <b>BOMLines</b>
     * this operation removes the instructure associations between the <b>BOMLines</b>.
     * These associations can be <b>ConnectTo, ImplementedBy, RealizedBy, RoutedBy, FixingToSegment,
     * DeviceToConnector</b>. The operation takes a vector of <i>RemoveInStructureAssociationsInfo</i>
     * as Input.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Developers shall use this operation when an association has to be removed between
     * the <b>BOMLines</b>. This is a generic Teamcenter service to remove various types
     * of associations.
     * <br>
     * In the case of <b>ConnectTo</b>, if the secondary <b>BOMLines</b> are passed as null
     * then all the secondary associations with the primary <b>BOMLine</b> shall be removed.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param inputs
     *        This is a vector of <i>RemoveInStructureAssociationsInfo</i> structure. Each element
     *        shall consist of a primary <b>BOMLine</b>, the secondary <b>BOMLines</b> to be removed,
     *        the parent line in whose context the association takes place and the association
     *        type.
     *
     * @return
     *         This operation returns a <i>RemoveInStructureAssociationsResponse</i> containing
     *         the entire updated primary <b>BOMLines</b> in <i>ServiceData</i> whose associations
     *         have been removed. Any failures will be updated in <i>ServiceData</i> partial errors.
     *         <br>
     *         <b>Partial Errors</b>
     *         <br>
     *         <ul>
     *         <li type="disc"><i>Error Id. 214320 </i> Unable to remove %1$ association: the input
     *         primary <b>BOMLine</b> is null.
     *         </li>
     *         <li type="disc"><i>Error Id. 214321 </i> Error in removing %1$ association between
     *         primary and secondaries.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Structuremanagement::RemoveInStructureAssociationsResponse removeInStructureAssociations ( const std::vector< Teamcenter::Services::Core::_2008_06::Structuremanagement::RemoveInStructureAssociationsInfo >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuremanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

