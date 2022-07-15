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

#ifndef TEAMCENTER_SERVICES_WIREHARNESS_WIREHARNESSSERVICE_HXX
#define TEAMCENTER_SERVICES_WIREHARNESS_WIREHARNESSSERVICE_HXX

#include <teamcenter/services/wireharness/_2008_06/Wireharness.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/wireharness/WireHarness_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Wireharness
        {
            class WireharnessService;

/**
 * The WireHarness service exposes operations to create, update, and delete Harness
 * structures. It works with all types of harness objects like Connections, Devices,
 * Connectors, cables, Shields, Ports, Wires. It handles all associated data and allows
 * the creation of  associations between harness elements in the structure. The operations
 * allow creating precise and imprecise structures. Along with Harness structure creation
 * the associations like ConnectedTo, ImplementedBy, RealizedBy etc can also be created
 * using the operations exposed in this service. The service also exposes operations
 * which create and update Route objects and creating, deleting, or updating their associated
 * data like <b>RoutePath</b>, <b>RouteSegment</b>, <b>RouteNode</b>, and <b>RouteCurve</b>.
 * The service exposes operations to update properties on Harness objects. The service
 * also contains operations which creates and updates wire data, length data, and color
 * data of the wire objects.  The service exposes operations to manage the association
 * between wire protection objects and segment objects.
 * <br>
 * The service provides the following use cases for Harness data structure:
 * <br>
 * <ul>
 * <li type="disc">Creation of precise or imprecise harness structure.
 * </li>
 * <li type="disc">Modifying the harness data of the structure.
 * </li>
 * <li type="disc">Creating associations between structure elements of Harness structure.
 * </li>
 * <li type="disc">Removing associations between structure elements of Harness structure.
 * </li>
 * <li type="disc">Creating Route and associated objects.
 * </li>
 * <li type="disc">Updating of Route and associated objects.
 * </li>
 * <li type="disc">Deletion of Route and associated objects.
 * </li>
 * <li type="disc">Creation of wire data.
 * </li>
 * <li type="disc">Updating of wire data.
 * </li>
 * </ul>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement, StructureManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoawireharnessstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoawireharnesstypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAWIREHARNESSSTRONGMNGD_API WireharnessService
    : public Teamcenter::Services::Wireharness::_2008_06::Wireharness
{
public:
    static WireharnessService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation allows client applications to create route objects in a specified
     * context which is provided as an input by the client developer. When route objects
     * get created, they are associated with its Route segments, Route Curves and nodes.
     * Node is nothing but a point in space. You define nodes with <b>RouteNode</b> objects.
     * <b>RouteSegment</b> defines the segment of a start node and an end node. <b>RouteCurve</b>
     * models the 3D shape (b spline curve) associated with a <b>RouteSegment</b><i> </i>object.
     * The shape of the segment can optionally be defined with a <b>RouteCurve</b> object.
     * If a <b>RouteCurve</b> is not defined, Teamcenter assumes that the segment is a straight
     * line between start and end nodes. All RouteObjects are defined only in the context
     * of a given structure and these objects cannot be shared across multiple structures.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Typically this is used by the client applications which perform routing of a CAD
     * model based on connectivity information that is specified by a logical model. Once
     * client applications decide how routes are created based on physical geometry etc,
     * the route created need to be persisted into Teamcenter. Similarly, existing routes
     * can also change, based on changes in physical [CAD] geometry. In such cases, this
     * SOA can be used to create and or update the route objects. You need to mention this.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param inputs
     *        This is a list of RouteInfo structures and it contains information regarding the
     *        Routeobject which the user wants to create. RouteInfo has the context in which the
     *        client developer wants to create Routeobject, RouteData, NodeData, SegmentData and
     *        CurveData.
     *
     * @return
     *         This operation returns structures containing newly created Routes Segments, Routes
     *         Nodes and Routes Curves.
     *         <br>
     *         Any failures will be returned in the ServiceData as list of partial errors.
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">255000 Unable to create route objects: the input context is null.
     *         </li>
     *         <li type="disc">255001 Unable to create route object: input name is null string.
     *         </li>
     *         <li type="disc">255002 Failed to create <code>Name of object</code> object.
     *         </li>
     *         <li type="disc">255003 Unable to update display data on Route object.
     *         </li>
     *         <li type="disc">255004 Unable to update real length data on <code>Name of object</code>
     *         object.
     *         </li>
     *         <li type="disc">255005 Unable to update represented length data on <code>Name of
     *         object</code> object.
     *         </li>
     *         <li type="disc">255006 Failed to associate <code>Name of object</code> to <code>Name
     *         of object</code>.
     *         </li>
     *         <li type="disc">255007 Failed to update cross section data on <code>Name of object</code>
     *         object.
     *         </li>
     *         <li type="disc">255008 Failed to set node position on <code>Name of object</code>
     *         object.
     *         </li>
     *         <li type="disc">255009 Failed to set curve data.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::CreateOrUpdateRouteObjectsResponse createOrUpdateRouteObjects ( const std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::RouteInfo >& inputs ) = 0;

    /**
     * This operation is used to create a list of <b>RouteLocations</b> and their associated
     * data. Associated data consists of RouteLocation Revision, RouteLocation Master form,
     * RouteLocation Revision Master form based on the input attribute structures and creates
     * the specified relation type between the created <b>RouteLocation</b> and the input
     * container object. If the container and relation type are not input, none of the <b>RouteLocations</b>
     * will be related to a container. Container is not defaulted, if a destination is desired,
     * it must be input. <b>RouteLocation</b> objects model a region of space using objects
     * such as <b>RouteSegments</b>, <b>RouteNodes</b> and other electrical items to identify
     * the region of space in which they are located.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When the client developer wants to work on a Wire Harness design, and needs to describe
     * a space or region of the electrical system. In Teamcenter this is done by using the
     * <b>RouteLocation</b> object which is associated by <b>RouteSegments</b>, <b>RouteNodes</b>
     * and <b>RouteCurves</b>. Using this operation, the user will able to create a <b>RouteLocation</b>
     * object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param properties
     *        An <b>Item</b> is created for each <b>RouteLocation</b> Property in the list. The
     *        data on the <b>RouteLocation</b> Properties is used to create initial values on the
     *        <b>RouteLocation</b> and related objects.
     *
     * @param container
     *        Object to which all the <b>RouteLocations</b> created will be related to via the
     *        input relationType (Folder instance and contents relationType). If not specified
     *        the <b>RouteLocation</b> will be created, but without a relation to a containing
     *        object.
     *
     * @param relationType
     *        The name of the relation used to attach the created <b>RouteLocation</b> to the input
     *        container. This argument is used only when the container argument is present.
     *
     * @return
     *         A list of RouteLocationOutput, one for each successfully created <b>RouteLocation</b>,
     *         and a ServiceData element. The newly created <b>RouteLocation</b> business objects
     *         and <b>RouteLocationRevision</b> business objects are added to the Created list of
     *         the ServiceData while the input container object is added to the Updated list.
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">255033 Failed to create Form.
     *         </li>
     *         <li type="disc">255034 Failed to update &quot;Name of object&quot; properties.
     *         </li>
     *         <li type="disc">255035 Failed to create RouteLocation.
     *         </li>
     *         <li type="disc">255036 Failed to add &quot;Name of object&quot; object into container.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::CreateRouteLocationsResponse createRouteLocations ( const std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::RouteLocationProperties >& properties,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container,
        const std::string&  relationType ) = 0;

    /**
     * This operation allows client applications to delete the route objects along with
     * associated route segments, route curves and nodes in a specific context which is
     * given by the client developer.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When the client developer wants to delete route objects and its associated route
     * segment, route curve and route node objects, the deleteRouteObjects operation should
     * be used.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Mechatronics - Core objects and relationships used by Mechatronics applications such
     * as ESM; Wire harness and Manufacturing applications.
     *
     * @param inputs
     *        This is a list of DeleteRouteObjectsInfo structures and contains information of
     *        the route object which the user wants to delete. DeleteRouteObjectsInfo has the context
     *        in which client developer wants to delete the route object, RouteData, NodeData,
     *        SegmentData and curvedata.
     *
     * @return
     *         This operation returns structures containing deleted Segments, Nodes and Curves in
     *         a unique identifier string information. This information is available in the deleted
     *         objects list of serviceData element.
     *         <br>
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">255010 Unable to delete route objects: the input context is null.
     *         Context is nothing but product structure BOM view revision(PSBVR), in which RouteObjects
     *         are present. If  PSBVR does not have RouteObject then operation will throw this error
     *         in ServiceData.
     *         </li>
     *         <li type="disc">255011 Failed to delete all route objects.
     *         </li>
     *         <li type="disc">255012 Failed to delete &quot;Name of object&quot; object. This error
     *         will come when operation is not able to delete specific object which is given as
     *         a input of type RouteObject, RouteSegment, RouteCurve or RouteNode.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::DeleteRouteObjectsResponse deleteRouteObjects ( const std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::DeleteRouteObjectsInfo >& inputs ) = 0;

    /**
     * This operation is used to create the wire protection to segments association between
     * primary and secondary <b>BOMLines</b>/objects in a structure and update the protection
     * data.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Associate wire protection data to a segment.
     * <br>
     * A list of WireProtectionData is first created. WireProtectionData must contain the
     * <b>BOMLine</b> to which the route segments and the protection data are to be assigned,
     * also the list of segments and the protection data values. The protection data values
     * such as &quot;start_location&quot;, &quot;end_location&quot;, &quot;gradient&quot;
     * and &quot;taping_direction&quot; are set in the protectionAreaData map. Then this
     * list of WireProtectionData is sent as an input parameter to the associateWireProtectionToSegments
     * operation to establish the association.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param inputs
     *        This is a list of WireProtectionData structures containing information about the
     *        wire protection and the segments.
     *
     * @return
     *         This structure contains the created and the updated objects in the standard ServiceData
     *         lists for the created and the updated objects respectively.
     *         <br>
     *         The serviceData may contain the following partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">255026 Error in creating the association between wire protection
     *         line and segments.
     *         </li>
     *         <li type="disc">255027 Error in setting protection area data on wire protection instance.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::AssociateWireProtectionToSegmentsResponse associateWireProtectionToSegments ( const std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireProtectionData >& inputs ) = 0;

    /**
     * This operation is used to create or update the harness structures with all connections,
     * devices, connectors, cables, shields, ports and wires with associations.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Create a Wire Harness.
     * <br>
     * To create a wire harness the user must first create HarnessData. The HarnessData
     * must be populated with all the connections, connectors, cables, shields, devices
     * and wires that need to be created in the Teamcenter database. After all the HarnessData
     * is ready it is passed to the server along with the BOM view type and a flag to create
     * a precise or imprecise structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param inputs
     *        This is a list of HarnessInfo for creating or updating the harness structure and
     *        the associations between the <b>BOMLine</b> of the Harness Structure in Teamcenter
     *        database.
     *
     * @param bomViewTypeName
     *        This is a type of <b>BOMView</b> to be created.
     *
     * @param precise
     *        This is a flag that if true signals to create a precise structure else imprecise
     *        structure.
     *
     * @return
     *         The operation returns a list of HarnessObjectInfo objects. And any created objects
     *         and the updated objects will be sent back in the standard ServiceData lists of created
     *         and updated object respectively.  Any failure will be returned in the ServiceData
     *         list of partial errors.
     *         <br>
     *         The serviceData may contain the following partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">255041 If the harness fails  to create the harness structure.
     *         </li>
     *         <li type="disc">255045 If the operations fails to create the harness structure due
     *         to invalid BOM view type.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::CreateOrUpdateHarnessResponse createOrUpdateHarness ( const std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessInfo >& inputs,
        const std::string&  bomViewTypeName,
        bool precise ) = 0;

    /**
     * This operation is used to create or update a wire business object for each WireData
     * structure. The Wiredata consists of length data, color data, number, multiplier,
     * offset, separation code etc. associated with each wire business object. This operation
     * requires a wire business object which the client developer wants to create or update,
     * if it is not provided, the operation will fail for a particular wire business object
     * and an error is returned in service data as a partial error. If the client developer
     * inputs the wire business object as a wire <b>BOMLine</b> then only length and wire
     * properties are applicable.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Typically this is used to create wire data, assigning the wire length, color, etc.
     * It can also be used to update existing wire data, allowing these wire data attributes
     * to be changed.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param inputs
     *        Structures containing the details of the wire business object to be created/modified.
     *
     * @return
     *         The created/updated wire business objects are returned via ServiceData in the Created/Updated
     *         lists. If the input parameters are invalid, the errors are returned in ServiceData.
     *         <br>
     *         Following are some possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">255013 Unable to update Wire data: the input Wire object is null.
     *         </li>
     *         <li type="disc">255014 Unable to update length of type &quot;Name of Wire business
     *         object&quot; on Wire instance.
     *         </li>
     *         <li type="disc">255015 Unable to update Wire properties on Wire instance.
     *         </li>
     *         <li type="disc">255016 Failed to set color of type &quot;Name of Wire business object&quot;
     *         on Wire object.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::CreateOrUpdateWireDataResponse createOrUpdateWireData ( const std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireData >& inputs ) = 0;

    /**
     * This operation is used to delete all the wire related data (like length, color, multiplier
     * etc.) of given wire objects. The updated wire object will be returned in the updated
     * objects list of the ServiceData.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In this use case a list of wire <b>Item</b> objects or wire <b>BOMLine</b> objects
     * are passed to be deleted.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param wires
     *        Array of wire objects to be deleted from the Teamcenter database. These objects can
     *        be wire <b>Items</b> or wire <b>BOMLines</b>.
     *
     * @return
     *         The response structure contains serviceData.
     *         <br>
     *         The updated objects are listed in the updated objects list of serviceData.
     *         <br>
     *         The serviceData may contain following partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">255021 If the operation fails to delete the wire data.
     *         </li>
     *         <li type="disc">255022 If the operation fails to delete the wire length data.
     *         </li>
     *         <li type="disc">255023 If the operation fails to delete wire properties.
     *         </li>
     *         <li type="disc">255024 If the operation fails to delete wire color data.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::DeleteWireDataResponse deleteWireData ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& wires ) = 0;

    /**
     * This operation is used to get the wire related data e.g. length, color, multiplier,
     * offset etc.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In this use case a list of wire <b>Item</b> objects or wire <b>BOMLine</b> objects
     * are passed. These passed objects must contain the unique identifier (uid) of the
     * objects to be fetched. The operation returns the length, the color and the other
     * information for wires in a list of WireData.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param wires
     *        Array of wire objects to retrieve their wire data from the Teamcenter database. These
     *        objects can be wire <b>Items</b> or wire <b>BOMLines</b>.
     *
     * @return
     *         This operation returns a structure containing serviceData and wireData information.
     *         wireData is a list of WireData objects corresponding to the input structure wires.
     *         <br>
     *         The serviceData may contain the following partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">255017 If the operation fails to find requested wire data.
     *         </li>
     *         <li type="disc">255018 If the operation fails to get the wire length data.
     *         </li>
     *         <li type="disc">255019 If the operation fails to get wire properties.
     *         </li>
     *         <li type="disc">255020 If the operation fails to get wire color data.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::GetWireDataResponse getWireData ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& wires ) = 0;

    /**
     * This operation gets the segments and wire protection data of the input wire protection
     * line. If errors occur during this operation they are returned as part of the partial
     * errors list of the ServiceData element.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * First create a list of <b>BOMLines</b> for which the wire protection data needs to
     * be fetched. Then send this list as an input parameter of the operation. The operation
     * gets the segments and the associated wire protection area data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param inputs
     *        This is a list of Wire protection <b>BOMLines</b> for which the WireProtectionData
     *        needs to be retrieved.
     *
     * @return
     *         The serviceData may contain the following partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">255028 Unable to get wire protection data: the input wire protection
     *         instance is null.
     *         </li>
     *         <li type="disc">255029 Error in getting wire protection data associated with wire
     *         protection line.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::GetWireProtectionSegmentResponse getWireProtectionSegments ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& inputs ) = 0;

    /**
     * This operation removes the association between the segments and the wire protection
     * line and also deletes the associated wire protection area data for the <b>BOMLine</b>.
     * The updated wire protection business objects will be returned as part of the updated
     * objects list of the ServiceData.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Remove the wire protection association from a <b>BOMLine</b>.
     * <br>
     * First create a list of <b>BOMLines</b> for which wire protect data needs to be removed.
     * Then send this list as an input parameter of the operation. This operation removes
     * the association between the segments and the wire protection line, deletes the associated
     * wire protection area data for the <b>BOMLine</b> and returns the updated objects.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WireHarnessServices - SOA services to create/update/delete of Harness structure with
     * devices; connectors; pins; wires; cables; shields; connections; their attributes
     * and their association.
     *
     * @param inputs
     *        This is a list of Wire protection <b>BOMLines</b>.
     *
     * @return
     *         This structure contains the updated objects in the standard ServiceData list for
     *         the updated objects.
     *         <br>
     *         The serviceData may contain the following partial errors.
     *         <br>
     *         <ul>
     *         <li type="disc">255030 Unable to remove wire protection data: the input wire protection
     *         instance is null.
     *         </li>
     *         <li type="disc">255031 Error in removing the segments.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Wireharness::_2008_06::Wireharness::RemoveWireProtectionAssociationResponse removeWireProtectionAssociation ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WireharnessService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/wireharness/WireHarness_undef.h>
#endif

