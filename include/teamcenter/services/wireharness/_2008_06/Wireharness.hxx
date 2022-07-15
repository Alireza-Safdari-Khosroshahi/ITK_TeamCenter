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

#ifndef TEAMCENTER_SERVICES_WIREHARNESS__2008_06_WIREHARNESS_HXX
#define TEAMCENTER_SERVICES_WIREHARNESS__2008_06_WIREHARNESS_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/RouteLocation.hxx>
#include <teamcenter/soa/client/model/RouteLocationRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/wireharness/WireHarness_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Wireharness
        {
            namespace _2008_06
            {
                class Wireharness;

class TCSOAWIREHARNESSSTRONGMNGD_API Wireharness
{
public:

    struct AssociateWireProtectionToSegmentsResponse;
    struct HarnessObjectInfo;
    struct CableData;
    struct ColorData;
    struct ConnectionData;
    struct ConnectorData;
    struct ControlPoint;
    struct CreateOrUpdateHarnessResponse;
    struct CreateOrUpdateRouteObjectsResponse;
    struct CreateOrUpdateWireDataResponse;
    struct CreateRouteLocationsResponse;
    struct CurveData;
    struct DataOutput;
    struct DeleteRouteObjectsInfo;
    struct DeleteRouteObjectsResponse;
    struct DeleteWireDataResponse;
    struct DeviceData;
    struct DisplayData;
    struct ExtendedAttributes;
    struct GetWireDataResponse;
    struct GetWireProtectionSegmentResponse;
    struct HarnessData;
    struct HarnessInfo;
    struct ItemElementData;
    struct LengthData;
    struct NodeData;
    struct RemoveWireProtectionAssociationResponse;
    struct RouteData;
    struct RouteDataOutput;
    struct SegmentDataOutput;
    struct RouteDataOutputInfo;
    struct SegmentData;
    struct RouteInfo;
    struct RouteLocationOutput;
    struct RouteLocationProperties;
    struct ShieldData;
    struct WireProperties;
    struct WireData;
    struct WireInfo;
    struct WireProtectionData;

    /**
     * AttributeMap
     */
    typedef std::map< std::string, std::string > AttributeMap;

    /**
     * AttributeNameValueMap
     */
    typedef std::map< std::string, std::string > AttributeNameValueMap;

    /**
     * Return structure for associateWireProtectionToSegments  operation
     */
    struct AssociateWireProtectionToSegmentsResponse
    {
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model objects
         * from a service request. This also holds services exceptions and updated objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This is the input/output structure for Harness object information
     */
    struct HarnessObjectInfo
    {
        /**
         * Identifier string that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * A Harness, <b>ItemRevision</b>, or ItemElement object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A Harness, <b>Item</b>, or ItemElement object occurrence.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectOcc;
        /**
         * A Harness or ItemElement object occurrence thread.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectOccThread;
    };

    /**
     * This is a structure to hold the cable data.
     */
    struct CableData
    {
        /**
         * This is a HarnessObjectInfo input structure containing cable object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo cable;
        /**
         * It is a map of name/value pairs (string/string) of cable occurrence properties. It
         * is optional.
         */
        AttributeMap cableOccProps;
        /**
         * These are connections associated with this cable.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectionData > connections;
        /**
         * These are connectors associated with this cable.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectorData > connectors;
        /**
         * These are child cables of this cable.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::CableData > childcables;
        /**
         * These are shields associated with this cable.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ShieldData > shields;
        /**
         * These are devices associated with this cable.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::DeviceData > devices;
        /**
         * These are wires associated with this cable.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireInfo > wires;
    };

    /**
     * ColorData structure of WireData input/output structure.
     */
    struct ColorData
    {
        /**
         * This is a wire color type.
         */
        std::string colorType;
        /**
         * This is the color of the wire.
         */
        std::string color;
    };

    /**
     * This is a structure for Connection data.
     */
    struct ConnectionData
    {
        /**
         * This is HarnessObjectInfo input structure containing Connection object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo connection;
        /**
         * It is a map of name/value pairs (string/string) of connection occurrence properties.
         * It is optional.
         */
        AttributeMap connectionOccProps;
        /**
         * This is a list of connection to port (Connect_To) association information to be created
         * in the harness structure.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo > associatedPorts;
        /**
         * This is a list of connection to wire (Implemented_By) association information to
         * be created in the harness structure.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo > associatedWires;
        /**
         * This is a list of connection to shield (Implemented_By) association information to
         * be created in the harness structure.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo > associatedshilds;
    };

    /**
     * This is structure for Connector data.
     */
    struct ConnectorData
    {
        /**
         * This is a HarnessObjectInfo input structure containing connector object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo connector;
        /**
         * It is a map of name/value pairs (string/string) of connector occurrence properties.
         * It is optional.
         */
        AttributeMap connectorOccProps;
        /**
         * A list of ports connected to this connector.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ItemElementData > ports;
    };

    /**
     * ControlPoint structure for CurveData structure
     */
    struct ControlPoint
    {
        /**
         * Array of control points.
         */
        std::vector< double > points;
    };

    /**
     * This is a return structure for createOrUpdateHarness operation.
     */
    struct CreateOrUpdateHarnessResponse
    {
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * This is a list of HarnessObjectInfo objects which contains the created harness data
         * and the instance data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo > output;
    };

    /**
     * The response structure for the createOrUpdateRouteObjects operation.
     */
    struct CreateOrUpdateRouteObjectsResponse
    {
        /**
         * A list of created route objects and their associated RouteData, NodeData, SegmentData
         * and CurveData.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::RouteDataOutputInfo > output;
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model objects
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure is a response from this operation.  It returns the created and updated
     * objects, as well as any errors.
     */
    struct CreateOrUpdateWireDataResponse
    {
        /**
         * This is a common data structure is used to return sets of Teamcenter Data Model objects
         * from a service request as well as partial error.  ServiceData has the wire business
         * objects which were created or updated according to the input provided by the client
         * developer.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Return structure for RouteLocations operation
     */
    struct CreateRouteLocationsResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of created <b>RouteLocation</b> business objects and associated <b>RouteLocationRevision</b>
         * business objects.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::RouteLocationOutput > output;
    };

    /**
     * CurveData structure of RouteData input structure for createOrUpdateRouteObjects operation
     */
    struct CurveData
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The name of the Route curve to be created.
         */
        std::string name;
        /**
         * A list of points which will control the curve for the Route Object.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ControlPoint > controlPoints;
        /**
         * A list of knots on the curve the Route Object.
         */
        std::vector< double > knots;
        /**
         * A list of multiplicities on the curve of the Route Object.
         */
        std::vector< int > multiplicities;
        /**
         * A map of attributes names and initial values pairs (string/string). The calling client
         * is responsible for converting the different property types (int, float, date, etc.)
         * to a string using the appropriate toXXXString functions in the SOA client framework&#39;s
         * Property class. Multi&ndash;valued properties are represented with a comma separated
         * string.
         * <br>
         * The following attributes are supported:
         * <br>
         * <ul>
         * <li type="disc">degree Degree of the Route curve.
         * </li>
         * <li type="disc">dimension Dimension of the Route curve.
         * </li>
         * <li type="disc">isRational Flag indicating whether this Route curve is rational.
         * </li>
         * <li type="disc">isUniform Flag indicating whether this Route curve is uniform.
         * </li>
         * <li type="disc">startParameter Start interval of the Route curve between 0 and 1.
         * </li>
         * <li type="disc">endParameter End interval of the Route curve between 0 and 1.
         * </li>
         * </ul>
         */
        AttributeMap curveAttributes;
        /**
         * The <b>RouteCurve</b> object used to update the route object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  curve;
    };

    /**
     * Output structure for Route, Segment, Node and Curve
     */
    struct DataOutput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this output structure.
         */
        std::string clientId;
        /**
         * The output object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };

    /**
     * Input structure for deleteRouteObjects operation
     */
    struct DeleteRouteObjectsInfo
    {
        /**
         * This is input of type <b>PSBOMView</b> revision BVR (BOM view revision) in which
         * the route object needs to be deleted. It is required if the deleteAll flag is true.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * This is used to indicate if all the route objects need to be deleted
         */
        bool deleteAll;
        /**
         * A list of route objects to be deleted (optional).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > routes;
        /**
         * A list of route node objects to be deleted (optional).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > nodes;
        /**
         * A list of route segment objects to be deleted (optional).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > segments;
        /**
         * A list of route curve objects to be deleted (optional).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > curves;
    };

    /**
     * This is the response structure for the deleteRouteObjects operation. DeleteRouteObjectsResponse
     * consists of servicedata. Service data has unique identifier string for each object
     * which was deleted as part of the deleted objects list of the ServiceData element,
     * as well as the objects which were not deleted as part of the partial errors.
     */
    struct DeleteRouteObjectsResponse
    {
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model objects
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Return structure for deleteWireData operation
     */
    struct DeleteWireDataResponse
    {
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model objects
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This is a structure to hold device data .
     */
    struct DeviceData
    {
        /**
         * This is a HarnessObjectInfo input structure containing device object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo device;
        /**
         * It is a map of name/value pairs (string/string) of device occurrence properties.
         * It is optional.
         */
        AttributeMap deviceOccProps;
        /**
         * These are connectors associated with this device.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectorData > connectors;
        /**
         * These are ports associated with this device.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ItemElementData > ports;
        /**
         * These are connectors associated with this device.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo > associatedConnectors;
    };

    /**
     * DisplayData structure of RouteData input structure for createOrUpdateRouteObjects
     * operation
     */
    struct DisplayData
    {
        /**
         * The font for display of route data.
         */
        int font;
        /**
         * The width for display of route data.
         */
        double width;
        /**
         * This is a list which contains display color with RGB values for route data.
         */
        std::vector< double > rgbValues;
    };

    /**
     * Input structure for createItems operation to support setting attribute values on
     * the created Item, ItemRevision, or corresponding master forms that may be created
     * with the objects.
     */
    struct ExtendedAttributes
    {
        /**
         * The type of object to set these properties on, <b>RouteLocation</b>, <b>RouteLocationRevision</b>
         * etc.
         */
        std::string objectType;
        /**
         * A map of attributes names and initial values pairs (string/string). The calling client
         * is responsible for converting the different property types (int, float, date, etc.)
         * to a string using the appropriate toXXXString functions in the SOA client framework's
         * Property class. Multi-valued properties are represented with a comma separated string.
         */
        AttributeNameValueMap attributes;
    };

    /**
     * Return structure for getWireData operation
     */
    struct GetWireDataResponse
    {
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model objects
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * This is an output list of wire data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireData > wireData;
    };

    /**
     * This is the return structure of getWireProtectionSegments operation.
     */
    struct GetWireProtectionSegmentResponse
    {
        /**
         * This is a common data structure used to return the sets of Teamcenter Data Model
         * objects from a service request. This also holds the partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * This is a list of WireProtectionData objects corresponding to the <b>BOMLine</b>
         * objects sent as an input to the getWireProtectionSegments operation.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireProtectionData > output;
    };

    /**
     * This is a HarnessData input structure for createOrUpdateRouteObjects operation.
     */
    struct HarnessData
    {
        /**
         * This contains Harness object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo harness;
        /**
         * It is a map of name/value pairs (string/string) of harness occurrence properties.
         * It is optional.
         */
        AttributeMap harnessOccProps;
        /**
         * A list of connection data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectionData > connections;
        /**
         * A list of connector data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectorData > connectors;
        /**
         * A list of cable data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::CableData > cables;
        /**
         * A list of shield data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ShieldData > shields;
        /**
         * A list of device data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::DeviceData > devices;
        /**
         * A list of wire data.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireInfo > wires;
    };

    /**
     * This is an Input structure for createOrUpdateHarness operation and specifies the
     * parent and harness data
     */
    struct HarnessInfo
    {
        /**
         * A unique string supplied by the caller. This ID can be used to identify returned
         * HarnessObjectInfo elements and associated Partial Errors.
         */
        std::string clientId;
        /**
         * This object is the parent of the harness structure to which the harness data are
         * to be added as children.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * This contains the data to be used to create or update harness data in Teamcenter
         * database.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessData > harnessData;
    };

    /**
     * ItemElementData structure.
     */
    struct ItemElementData
    {
        /**
         * This is a HarnessObjectInfo input structure containing item object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo itemElement;
        /**
         * It is a map of name/value pairs (string/string) of item occurrence properties. It
         * is optional.
         */
        AttributeMap itemElementOccProps;
        /**
         * A list of item element data children.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ItemElementData > childItemElements;
        /**
         * A list of Port to Port (Realized_By) association information.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo > realizedPorts;
    };

    /**
     * LengthData structure of WireData input/output structure.
     */
    struct LengthData
    {
        /**
         * This is a wire length type.
         */
        std::string lengthType;
        /**
         * This is the length of the wire.
         */
        double length;
    };

    /**
     * NodeData structure of RouteData input structure for createOrUpdateRouteObjects operation
     */
    struct NodeData
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The name of the <b>RouteNode</b> to be created.
         */
        std::string name;
        /**
         * A map of attributes names and initial values pairs (string/string). The calling client
         * is responsible for converting the different property types (int, float, date .etc)
         * to a string using the appropriate toXXXString functions in the SOA client framework's
         * Property class. Multi&ndash;valued properties are represented with a comma separated
         * string.
         * <br>
         * The following attributes are supported:
         * <br>
         * <ul>
         * <li type="disc">x The x coordinate for this Route Node.
         * </li>
         * <li type="disc">y The y coordinate for this Route Node.
         * </li>
         * <li type="disc">z The z coordinate for this Route Node.
         * </li>
         * </ul>
         */
        AttributeMap nodeAttributes;
        /**
         * The <b>RouteNode</b> Object used to update the route object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  node;
    };

    /**
     * Return structure for RemoveWireProtectionAssociationResponse  operation
     */
    struct RemoveWireProtectionAssociationResponse
    {
        /**
         * This is a common data structure used to return sets of Teamcenter Data Model objects
         * from a service request. This also holds services exceptions and updated objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * RouteData input structure for createOrUpdateRouteObjects operation
     */
    struct RouteData
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The name of the Route data to be created.
         */
        std::string name;
        /**
         * The DisplayData.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DisplayData displayData;
        /**
         * A list which will hold NodeData information.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::NodeData > nodeData;
        /**
         * A list which will hold SegmentData information.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::SegmentData > segmentData;
        /**
         * The CurveData.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::CurveData curveData;
        /**
         * A map of attributes names and initial values pairs (string/string). The calling client
         * is responsible for converting the different property types (int, float, date .etc)
         * to a string using the appropriate toXXXString functions in the SOA client framework's
         * Property class. Multi&ndash;valued properties are represented with a comma separated
         * string.
         */
        AttributeMap routeAttributes;
        /**
         * This is a RouteData Object and used in case of update of RouteObject.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  route;
    };

    /**
     * Output structure for RouteDataOutput
     */
    struct RouteDataOutput
    {
        /**
         * Output information for route object.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput route;
        /**
         * A list which consists of output information for Route Segments and its associated
         * nodes and curve.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::SegmentDataOutput > segments;
        /**
         * A Route node list.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput > nodes;
        /**
         * Output information for route curve.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput curve;
    };

    /**
     * Output structure for SegmentDataOutput
     */
    struct SegmentDataOutput
    {
        /**
         * Output information for route segment.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput segment;
        /**
         * A Route node list.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput > nodes;
        /**
         * Output information for route curve.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput curve;
    };

    /**
     * Output structure for RouteData for createOrUpdateRouteObjects operation
     */
    struct RouteDataOutputInfo
    {
        /**
         * This will have output information for the route object which is created or updated.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::RouteDataOutput route;
        /**
         * This will have output information for the route segments which are created or updated.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::SegmentDataOutput segment;
        /**
         * Output information for route node.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput node;
        /**
         * Output information for route curve.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::DataOutput curve;
    };

    /**
     * SegmentData structure of RouteData input structure for createOrUpdateRouteObjects
     * operation
     */
    struct SegmentData
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The name of the Route segment data to be created.
         */
        std::string name;
        /**
         * The start node of the Route segment.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::NodeData startNode;
        /**
         * The end node of the Route segment.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::NodeData endNode;
        /**
         * The B&ndash;Spline curve associated with the given Route segment.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::CurveData centerCurve;
        /**
         * A map of attributes names and initial values pairs (string/string). The calling client
         * is responsible for converting the different property types (int, float, date .etc)
         * to a string using the appropriate toXXXString functions in the SOA client framework's
         * Property class. Multi-valued properties are represented with a comma separated string.
         * <br>
         * The following attributes are supported:
         * <br>
         * <ul>
         * <li type="disc">position It is a position of the segment in the Route context. First
         * segment starts at 0 and so on and -1 indicates, the segments are placed in order.
         * </li>
         * <li type="disc">realLength The real length of the segment.
         * </li>
         * <li type="disc">representedLength The represented length of the segment.
         * </li>
         * <li type="disc">crossSectionalArea The cross sectional area of the segment.
         * </li>
         * </ul>
         */
        AttributeMap segmentAttributes;
        /**
         * The <b>RouteSegment</b> object, used to update the route object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  segment;
    };

    /**
     * Any one or all of the routeData, nodeData, segmentData, curveData can be provided
     * as input and route data will be created in the given context.
     */
    struct RouteInfo
    {
        /**
         * This is <b>PSBOMViewRevision</b> in which the route object needs to be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * Associated data for route object.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::RouteData routeData;
        /**
         * Associated route node data of route object.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::NodeData nodeData;
        /**
         * Associated route segment data of route object.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::SegmentData segmentData;
        /**
         * Associated curve data for route object.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::CurveData curveData;
    };

    /**
     * Output structure for createRouteLocations operation
     */
    struct RouteLocationOutput
    {
        /**
         * Identifying string from the source <b>RouteLocations</b> Properties.
         */
        std::string clientId;
        /**
         * The <b>RouteLocation</b> object reference that was created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RouteLocation>  routeLoc;
        /**
         * The newly created <b>RouteLocationRevision</b> reference for the newly created <b>RouteLocation</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RouteLocationRevision>  routeLocRev;
    };

    /**
     * Input structure for createRouteLocations operation.  Specifies attributes for the
     * new <b>RouteLocation</b> or <b>RouteLocationRevision</b>.
     */
    struct RouteLocationProperties
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned RouteLocationOutput
         * elements and Partial Errors associated with this input RouteLocationProperties.
         */
        std::string clientId;
        /**
         * ID for the <b>RouteLocation</b> objects to be created.
         */
        std::string routeLocId;
        /**
         * Name of the <b>RouteLocation</b> to be created.
         */
        std::string name;
        /**
         * The type of <b>RouteLocation</b> to be created, if left blank, default type is <b>RouteLocation</b>.
         */
        std::string type;
        /**
         * Identifier of the initial revision of the <b>RouteLocation</b> to be created.
         */
        std::string revId;
        /**
         * The Unit Of Measure for <b>RouteLocation</b> to be created, if left blank no UOM
         * will be set for the <b>RouteLocation</b>.
         */
        std::string uom;
        /**
         * The description text for the <b>RouteLocation</b> to be created.
         */
        std::string description;
        /**
         * Any additional attribute values to be set on the created <b>RouteLocation</b>, <b>RouteLocationRevision</b>
         * or corresponding RouteLocation Master Forms.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ExtendedAttributes > extendedAttributes;
    };

    /**
     * This is a structure to hold the shield data.
     */
    struct ShieldData
    {
        /**
         * This is a HarnessObjectInfo input structure containing shield object information.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo shield;
        /**
         * It is a map of name/value pairs (string/string) of cable occurrence properties. It
         * is optional.
         */
        AttributeMap shieldOccProps;
        /**
         * These are connections associated with this shield.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectionData > connections;
        /**
         * These are connectors associated with this shield.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ConnectorData > connectors;
        /**
         * These are cables associated with this shield.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::CableData > cables;
        /**
         * These are child shields of this shield.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ShieldData > childshields;
        /**
         * These are devices associated with this shield.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::DeviceData > devices;
        /**
         * These are wires associated with this shield.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireInfo > wires;
    };

    /**
     * WireProperties structure of WireData input/output structure.
     */
    struct WireProperties
    {
        /**
         * Wire number gives wire specifications.
         */
        std::string wireNumber;
        /**
         * This is the multiplier attribute of the wire.
         */
        std::string multiplier;
        /**
         * This is the offset attribute of the wire.
         */
        std::string offset;
        /**
         * Separation code used for routing of the wire.
         */
        std::string separationCode;
    };

    /**
     * The WireData structure represents all the details of a wire business object.
     */
    struct WireData
    {
        /**
         * A wire business object. This can be a wire <b>Item</b> or a wire <b>BOMLine</b>.
         * To assign color data, a wire item revision needs to be provided as input. To assign
         * length/properties the <b>BOMLine</b> of the wire needs to be provided as input.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  wire;
        /**
         * This is a list of wire length information.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::LengthData > lengthData;
        /**
         * This is a list of wire color information.
         */
        std::vector< Teamcenter::Services::Wireharness::_2008_06::Wireharness::ColorData > colorData;
        /**
         * This contains wire properties like multiplier, offset, separation code.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::WireProperties properties;
    };

    /**
     * WireInfo structure.
     */
    struct WireInfo
    {
        /**
         * HarnessObjectInfo input sturcture containg Wire object info.
         */
        Teamcenter::Services::Wireharness::_2008_06::Wireharness::HarnessObjectInfo wire;
        /**
         * Name/value pairs of Wire occurrence properties and it is optional.
         */
        AttributeMap wireOccProps;
    };

    /**
     * Input structure for associateWireProtectionToSegments operation
     */
    struct WireProtectionData
    {
        /**
         * This is a primary wire protection <b>BOMLine</b> to which the protection data and
         * the route segments are to be assigned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  wireProtectionLine;
        /**
         * These are the route segments to be associated with the wire protection <b>BOMLines</b>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > segments;
        /**
         * This is a map of (String/String) name/value pairs of protection area data to be associated
         * with the wire protection lines.
         * <br>
         * The Map provides the following information.
         * <br>
         * <ul>
         * <li type="disc">Key=start_location, Value=e.g. 10.00
         * </li>
         * <li type="disc">Key=end_location, Value=e.g. 20.00
         * </li>
         * <li type="disc">Key=gradient, Value=e.g. 30.00
         * </li>
         * <li type="disc">Key=taping_direction, Value=e.g. north
         * </li>
         * </ul>
         * <br>
         * The values of start_location, end_location and gradient need to be converted from
         * double to string while populating protectionAreaData.
         */
        AttributeMap protectionAreaData;
    };




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


protected:
    virtual ~Wireharness() {}
};
            }
        }
    }
}

#include <teamcenter/services/wireharness/WireHarness_undef.h>
#endif

