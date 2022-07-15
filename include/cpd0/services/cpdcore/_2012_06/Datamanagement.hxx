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

#ifndef CPD0_SERVICES_CPDCORE__2012_06_DATAMANAGEMENT_HXX
#define CPD0_SERVICES_CPDCORE__2012_06_DATAMANAGEMENT_HXX

#include <cpd0/services/cpdcore/_2011_06/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignControlElement.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <cpd0/services/cpdcore/CpdCore_exports.h>

namespace Cpd0
{
    namespace Services
    {
        namespace Cpdcore
        {
            namespace _2012_06
            {
                class Datamanagement;

class CPD0SOACPDCORESTRONGMNGD_API Datamanagement
{
public:

    struct CreateOrUpdateDesignControlElementOutput;
    struct CreateOrUpdateDesignControlElementsResponse2;
    struct SubstituteAsReuseDesignElementResponse;

    /**
     * Generic map of one business object to a vector of other business objects.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > BoToBoVectorMap2;

    /**
     * Generic map of a business object to a string (BusinessObject/string).
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::string > BoToStringMap2;

    /**
     * Map of client ID to CreateOrUpdateDesignControlElementOutput
     */
    typedef std::map< std::string, CreateOrUpdateDesignControlElementOutput > ClientIDToDesignControlElementOutputMap;

    /**
     * Generic map of a string to a business object.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > StringToBoMap2;

    /**
     * Design control element output data structure
     */
    struct CreateOrUpdateDesignControlElementOutput
    {
        /**
         * Design control element created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignControlElement>  designControlElement;
        /**
         * New ShapeDesignRevision data of the DesignControlElement.
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::NewShapeDesignData shapeDesign;
        /**
         * map of added controlled elements to their copy-stable ID
         * <br>
         * <code>csIdMap</code> is object of <code>BoToStringMap2</code>.
         * <br>
         * <code>BoToStringMap2</code> parameter : Map of(<code>Teamcenter::BusinessObject,
         * std::string</code> )
         */
        BoToStringMap2 csIdMap;
    };

    /**
     * Response to <tt>createOrUpdateDesignControlElements2</tt>. It contains <tt>ClientIDToDesignControlElementOutputMap</tt>
     * which is a map of input client ID to <tt>CreateOrUpdateDesignControlElementOutput</tt>.
     * The service data contains a list of added, updated, or deleted objects and it also
     * contains a list of any errors which occurred within the call.
     */
    struct CreateOrUpdateDesignControlElementsResponse2
    {
        /**
         * Map of client ID to corresponding <code>CreateOrUpdateDesignControlElementOutput</code>.
         * <br>
         * <code>clientIdToDCEOutputMap</code>
         * <br>
         * parameter: Map of <code> (std::string, CreateOrUpdateDesignControlElementOutput</code>
         * )
         */
        ClientIDToDesignControlElementOutputMap clientIdToDCEOutputMap;
        /**
         * Contains list of added, updated, or deleted objects.  Also contains list of any errors
         * which occurred within the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response from substituteAsReuseDesignElement operation
     */
    struct SubstituteAsReuseDesignElementResponse
    {
        /**
         * This is a map of client id to corresponding object (Cpd0DesignElement) that was substituted.
         * <br>
         * <code>clientIDMap</code> is object of <code>StringToBoMap2</code>.
         * <br>
         * <code>clientIDMap</code> parameter : Map of (<code>std:string,Teamcenter:BusinessObject</code>)
         */
        StringToBoMap2 clientIDMap;
        /**
         * Map for returned subordinates. Key is reuse design element and value is vector of
         * subordinates design elements returned for the reuse design element. Number of subordinates
         * returned is goverened by the levelsOfSubordinatesToReturn value specified on input
         * for each reuse design element.
         * <br>
         * <code>subordibateElements</code> object of <code>BoToBoMap2</code>
         * <br>
         * <code>subordibateElements</code> parameters : Map of (<code>Teamcenter:Business Object,Teamcenter:Business
         * Object[]</code>)
         */
        BoToBoVectorMap2 subordinateElements;
        /**
         * This contains added and updated objects. It also contains partial errors, if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Creates or updates a set of design control element (<b>Cpd0DesignControlElement</b>)
     * objects and their relations to the design elements and design features that they
     * conntrol.  Design control elements are used to represent welds seams (made up of
     * multiple individual welds), and mechanical routings (such as piping system) which
     * follow a path and are manifested by multiple design elements and design features
     * (welds) that make up the physical implementation of the routing.   Design control
     * elements are related to the design elements and design features they control via
     * a relation (<b>Cpd0ControlModel</b>).
     * <br>
     * Using this API, applications can create and update design control element (and
     * relation) information in bulk, giving better through put that might otherwise be
     * achieved using standard object create and update API.
     * <br>
     * <b>Cpd0ControlModel</b> relationships have a copy-stable ID which is unique within
     * the scope of the design feature.  The copy-stable ID can be specified on create;
     * if not specified, they will be automatically generated by Teamcenter.  As their name
     * suggests, when a design feature is copied the connected element relationships are
     * also copied and the copy-stable ID of the copied relations remains the same.  The
     * copy-stable ID is used by external applications, like CAD, to correlate internal
     * data to the related objects.@param elementInfos The input set of information describing
     * the design control elements to be created or updated.@return response containing
     * maps of input information to the created/updated objects (see description of CreateOrUpdateDesignControlElementsResponse
     * for more details).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the design control element authoring use cases. Design control
     * elements (weld seams, mechanical routings, etc.) are authored by users in a CAD application
     * (versus being authored in Teamcenter RAC UI).  When the user directs the CAD system
     * to save their session data, the CAD tool will invoke this API to populate or update
     * the design control element information in the Teamcenter database.
     * <br>
     * Note: standard delete API are used to destroy or obsolete design control elements
     * that are no longer required.
     * <br>
     * Use Case 1: Creation of new design control element
     * <br>
     * The following operation can be used for creating design control element (e.g. weld
     * seams and mechanical routings) in a collaborative design.
     * <br>
     * Design control elements are created always in the context of a collaborative design
     * (Cpd0CollaborativeDesign). Generally, in a production environment, a collaborative
     * design will be created ahead of time by an authorized user using the Collaborative
     * Product Development application in Teamcenter RAC UI.  Applications will generally
     * find an existing collaborative design, using the Collaborative Design saved query
     * (provided OOTB in Teamcenter) or through a custom query.
     * <br>
     * However, for testing purposes, an application may wish to create a collaborative
     * design programmatically. To do this the createObjects operation should be used.
     * <br>
     * New design control elements can be created using operation createOrUpdateDesignControlElements.
     * The application specifies the business object type for each new design control element,
     * and sets the collaborative design (found or created previously) as its modelObject.
     * Additional property and controlled element information is given and the operation
     * invoked.
     * <br>
     * Design control elements have a design control element ID which is unique within the
     * system.  Applications can assign their own value using the cpd0design_control_element_id
     * property. If this value is not specified in the input to createOrUpdateDeisgnControlElements,
     * then Teamcenter will automatically assign an ID when it creates a new design control
     * element.
     * <br>
     * During the operation, the server creates and saves the new design control elements
     * in context of the collaborative design.  It also creates and saves the relationship(Cpd0ControlModel)
     * between the design control element and the design elements and design features it
     * controls. The operation returns the new objects to the caller.
     * <br>
     * <br>
     * Use Case 2: Update of existing design control element
     * <br>
     * The following operation can be used for updating existing design control element
     * (e.g. weld seams and mechanical routings) in a collaborative design.
     * <br>
     * Design control elements are found by the application through search or by navigating
     * from a design element (Cpd0DesignElement) or design feature (Cpd0DesignFeature) via
     * the control model (Cpd0ControlModel) relation.  Note: the design control element
     * is always the primary object of the Cpd0ConnectedElement relation and the design
     * element or design feature is always the secondary object.
     * <br>
     * Existing design control elements can be updated using operation createOrUpdateDesignControlElements.
     * The application specifies which design control elements are to be updated.  Note:
     * the business object type and collaborative design (modelObject) are not set on the
     * input because they are already known to the design control element and cannot be
     * changed.  The application sets changed property values and specifies connected element
     * information for the feature.
     * <br>
     * During the operation, the server updates and saves the design control elements and
     * adds or removes Cpd0ConnectedElement relations to be consistent with the input.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * autoAssignValues, getCreateDesc
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param elementInfos
     *        The input set of information describing the design control elements to be created
     *        or updated.
     *
     * @return
     *         The response contains a map of input caller specified client ID values and the corresponding
     *         <tt>CreateOrUpdateDesignControlElementOutput</tt>. The service data contains a list
     *         of added, updated, or deleted objects and it also contains a list of any errors which
     *         occurred within the call.  See the description of <tt>CreateOrUpdateDesignControlElementsResponse2</tt>
     *         for additional details.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2012_06::Datamanagement::CreateOrUpdateDesignControlElementsResponse2 createOrUpdateDesignControlElements2 ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::DesignControlElementsInfo >& elementInfos ) = 0;

    /**
     * Transforms an existing reuse or promissory design elements ( <b>Cpd0DesignElement</b>
     * or its subtypes) to shape design elements ( <b>Cpd0DesignElement</b> or its subtypes)
     * .Substitute operation doesnt replace the existing design element with a new one.
     * The existing design element gets morphed. The category is changed from reuse (or
     * promissory) to shape. In other words, the object identity (UID) and the <b>cpd0design_element_id</b>
     * property value on Design Element remain the same after the substitution.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: This operation can be used when a promissory Design Element is to be
     * transformed into a shape Design Element.
     * <br>
     * Use Case 2: This operation can be used when a reuse Design Element is to be transformed
     * into a shape Design Element. In this case any of its subordinate Design Elements
     * are discarded as part of the substitution.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateDesignControlElements2
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param substituteInfos
     *        A vector of ReuseDesignElementInfo structures. Each structure specifies the Design
     *        Element to be substituted. Each would have inputs on Item Revision to be realized
     *        for substitution.
     *
     * @return
     *         SubstituteAsShapeDesignElementResponse contains a map of client id (provided in input)
     *         to the Shape Design Element. It has a map of Shape Design Elements to the corresponding
     *         Shape Design and Shape Design Revision objects. It has Service Data with created/updated/deleted
     *         objects along with any partial errors.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2012_06::Datamanagement::SubstituteAsReuseDesignElementResponse substituteAsReuseDesignElement2 ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ReuseDesignElementInfo >& substituteInfos ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <cpd0/services/cpdcore/CpdCore_undef.h>
#endif

