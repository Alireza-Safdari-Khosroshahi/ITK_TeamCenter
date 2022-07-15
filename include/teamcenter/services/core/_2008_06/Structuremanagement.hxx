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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
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
            namespace _2008_06
            {
                class Structuremanagement;

class TCSOACORESTRONGMNGD_API Structuremanagement
{
public:

    struct CreateInStructureAssociationResponse;
    struct GetPrimariesOfInStructureAssociationInfo;
    struct GetPrimariesOfInStructureAssociationResponse;
    struct GetSecondariesOfInStructureAssociationInfo;
    struct GetSecondariesOfInStructureAssociationResponse;
    struct InStructureAssociationInfo;
    struct PrimariesOfInStructureAssociation;
    struct RemoveInStructureAssociationsInfo;
    struct RemoveInStructureAssociationsResponse;
    struct SecondariesOfInStructureAssociation;

    /**
     * Return structure for createInStructureAssociations  operation
     */
    struct CreateInStructureAssociationResponse
    {
        /**
         * The <i>ServiceData</i> structure is used to return the updated objects and contains
         * partial errors, if any, occurring in the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for GetPrimariesOfInStructureAssociationInfo operation
     */
    struct GetPrimariesOfInStructureAssociationInfo
    {
        /**
         * secondary object/<b>BOMLine</b> business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondary;
        /**
         * Context object of association. This is generally the parent line of the primary object
         * and is an optional parameter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  contextBOMLine;
        /**
         * the created association type e.g. <b>ConnectedTo, ImplementedBy, RealizedBy, DeviceToConnector,
         * RoutedBy, SignalToTransmitter</b> .
         */
        std::string associationType;
    };

    /**
     * Return structure for GetPrimariesOfInStructureAssociationResponse  operation
     */
    struct GetPrimariesOfInStructureAssociationResponse
    {
        /**
         * The <i>ServiceData</i> structure is used to return the primary <b>BOMLine</b> business
         * objects and partial errors if any occurring in the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Context object of association. This is generally the parent line of the primary object.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Structuremanagement::PrimariesOfInStructureAssociation > primariesInfo;
    };

    /**
     * Input structure for GetSecondariesOfInStructureAssociationInfo operation
     */
    struct GetSecondariesOfInStructureAssociationInfo
    {
        /**
         * primary <b>BOMLine</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  primaryBOMLine;
        /**
         * Context <b>BOMLine</b> business object of association (optional)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  contextBOMLine;
        /**
         * Association type between the primary and secondary <b>BOMLine</b> business objects.
         */
        std::string associationType;
    };

    /**
     * Return structure for GetSecondariesOfInStructureAssociationResponse  operation
     */
    struct GetSecondariesOfInStructureAssociationResponse
    {
        /**
         * Secondary <b>BOMLine</b> business objects and Partial errors if any
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * primary <b>BOMLine</b> and association type.
         */
        std::vector< Teamcenter::Services::Core::_2008_06::Structuremanagement::SecondariesOfInStructureAssociation > secondariesInfo;
    };

    /**
     * Input structure for InstructureAssociationInfo operation
     */
    struct InStructureAssociationInfo
    {
        /**
         * The primary object of association
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  primaryBOMLine;
        /**
         * The context in which the association of the specified type between primaryBOMLine
         * and secondaries is valid.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  contextBOMLine;
        /**
         * secondary objects of association.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaries;
        /**
         * association type to be created
         */
        std::string associationType;
    };

    /**
     * Output structure for GetPrimariesOfInStructureAssociationInfo operation
     */
    struct PrimariesOfInStructureAssociation
    {
        /**
         * secondary object for which the primaries has been returned
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  secondary;
        /**
         * association type to be created
         */
        std::string associationType;
        /**
         * Primary object associated with the secondary
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  primaryBOMLine;
    };

    /**
     * Input structure for removeInStructureAssociations operation
     */
    struct RemoveInStructureAssociationsInfo
    {
        /**
         * primary <b>BOMLine</b> object reference of association
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  primaryBOMLine;
        /**
         * Context <b>BOMLine</b> of association (optional)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  contextBOMLine;
        /**
         * Secondary <b>BOMLines</b> to be disassociated from the primary <b>BOMLine</b>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaries;
        /**
         * Association type between primary and secondary <b>BOMLines</b>.
         */
        std::string associationType;
    };

    /**
     * Return structure for GetSecondariesOfInStructureAssociationResponse  operation
     */
    struct RemoveInStructureAssociationsResponse
    {
        /**
         * The updated objects and partial errors if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Output structure for GetSecondariesOfInStructureAssociationInfo operation
     */
    struct SecondariesOfInStructureAssociation
    {
        /**
         * Primary <b>BOMLine</b> associated with the secondary.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  primaryBOMLine;
        /**
         * association type to be created
         */
        std::string associationType;
        /**
         * Secondary <b>BOMLines</b> associated with the primaries
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaries;
    };




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


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

