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

#ifndef CPD0_SERVICES_CPDCORE__2011_06_DATAMANAGEMENT_HXX
#define CPD0_SERVICES_CPDCORE__2011_06_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignControlElement.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignElement.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignFeature.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignModelElement.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignSubsetElement.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignSubsetInstance.hxx>
#include <teamcenter/soa/client/model/Cpd0ShapeDesign.hxx>
#include <teamcenter/soa/client/model/Cpd0ShapeDesignRevision.hxx>
#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/Mdl0CopyStableRelation.hxx>
#include <teamcenter/soa/client/model/Mdl0PositionedModelElement.hxx>
#include <teamcenter/soa/client/model/Mdl0SubsetDefinition.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/StoredOptionSet.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
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
            namespace _2011_06
            {
                class Datamanagement;

class CPD0SOACPDCORESTRONGMNGD_API Datamanagement
{
public:

    struct AuxiliaryObjectInfo;
    struct CompoundCreateInfo;
    struct CompoundCreateInput;
    struct ControlModelInfo;
    struct CreateOrUpdateDesignControlElementsResponse;
    struct CreateOrUpdateDesignElementsInfo;
    struct CreateOrUpdateDesignElementsResponse;
    struct CreateOrUpdateDesignFeaturesResponse;
    struct CreateOrUpdateDesignSubsetElementsResponse;
    struct DesignControlElementsInfo;
    struct DesignFeatureConnectionInfo;
    struct DesignFeatureInfo;
    struct DesignSubsetElementData;
    struct DesignSubsetElementInfo;
    struct NewShapeDesignData;
    struct PromissoryDesignElementInfo;
    struct RelatedObjectFilter;
    struct RelatedObjectInput;
    struct RelatedObjectOutput;
    struct RelatedObjectsResponse;
    struct RelationAttributeValues;
    struct RelationAttributeFilter;
    struct RelationInfo;
    struct ReuseDesignElementInfo;
    struct ShapeDesignElementInfo;
    struct SubordinateDesignElementInfo;
    struct SubstituteAsReuseDesignElementResponse;
    struct SubstituteAsShapeDesignElementResponse;

    /**
     * This enumerated type specifies the data type of an attribute on a relation.
     */
    enum RelationAttributeDataType{ BooleanType,
                 IntegerType,
                 StringType,
                 DoubleType,
                 DateType,
                 TagType
                 };

    /**
     * A bag of attributes which maps attribute name to value(s).  All attributes values
     * are expressed in their string equivalant.
     */
    typedef std::map< std::string, std::vector< std::string > > AttributeInfoMap;

    /**
     * Map of relation property name to AuxiliaryObjectInfo. The property name must be the
     * relation property on the main object which will be used to attach the auxiliary objects.
     */
    typedef std::map< std::string, std::vector< AuxiliaryObjectInfo > > AuxiliaryObjectInfoMap;

    /**
     * Generic map of one business object to another business object.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > BoToBoMap;

    /**
     * Generic map of one business object to a vector of other business objects.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > BoToBoVectorMap;

    /**
     * Generic map of one business object to another.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::string > BoToStringMap;

    /**
     * Map of property name to CompoundCreateInfo
     */
    typedef std::map< std::string, std::vector< CompoundCreateInfo > > CompoundCreateInfoMap;

    /**
     * NewShapeDesignDataMap maps a new DesignElement or DesignControlElement to a ShapeDesign
     * object that was created in its behalf.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement> , NewShapeDesignData > NewShapeDesignDataMap;

    /**
     * Generic map of a string to a business object.
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > StringToBoMap;

    /**
     * Generic map of a string to another string
     */
    typedef std::map< std::string, std::string > StringToStringMap;

    /**
     * AuxiliaryObjectInfo is used as input for creating or updating auxiliary objects along
     * with main objects. For example, it can be used to pass information about attribute
     * group objects to be created along with DesignElement.
     */
    struct AuxiliaryObjectInfo
    {
        /**
         * Type of the auxiliary object used for creation. For update of auxiliary object, this
         * field is ignored.
         */
        std::string boType;
        /**
         * Auxiliary object to be updated.  This field is empty when auxiliary object is being
         * created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Contains information about attributes of the auxiliary objects. This is used during
         * creation and updating auxiliary object.
         * <br>
         * <code>attrInfo</code> parameter : Map of <code>(std::string</code>, <code>std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * Contains information about sub-objects to be created for auxiliary object. This field
         * is ignored when auxiliary object is being updated.
         */
        CompoundCreateInfoMap subObjects;
    };

    /**
     * Generic CreateInfo construct to support compound object create
     */
    struct CompoundCreateInfo
    {
        /**
         * The name of the Business Object type to be created.
         */
        std::string boType;
        /**
         * This contains property data for the newly created object. It is a map of property
         * and values for the newly created object.  All property values are expressed in their
         * string equivalent.  Object reference (tag) values can be passed using the client
         * string representation (e.g. UID) of the referenced object.  Array values are always
         * treated as replacement for entire array content.  Non array values are passed as
         * first element in value list. It is basically a map of String (Property Name) to Property
         * Value (List of Strings)\
         * <br>
         * <code>attrInfo</code> is object of <code>AttributeInfoMap</code>.
         * <br>
         * <code>attrInfo</code> parameter : Map of <code>(std::string</code>, <code>std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * Compound object data. <code>CompoundCreateInfoMap</code> is a map of property name
         * to <code>CompoundCreateInfo</code>. It is basically a map of String (property Name)
         * to property Value (<code>CompoundCreateInfo</code>) which in turn describes a different
         * object to be created.
         */
        CompoundCreateInfoMap compoundInfo;
    };

    /**
     * Input for creating a new Shape design item.
     */
    struct CompoundCreateInput
    {
        /**
         * Input to create Shape Design Item, Shape Design Revision data and respective master
         * forms
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CompoundCreateInfo createInfo;
        /**
         * NULL. This argument is not applicable for this operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * ControlModelInfo is used as input to describe control model relations between a <b>Cpd0DesignControlElement</b>
     * and the <b>Cpd0DesignElements</b> and the <b>Cpd0DesignFeatures</b> generated from
     * the control model (e.g. mechanical routing or weld seam) managed by the design control
     * element.
     * <br>
     * <br>
     * At a minimum, applications must specify the secondaryObject (the <code>DesignElement</code>
     * or <code>DesignFeature</code>).  Normally, applications will want to keep track,
     * internally, how this relation maps to the applications data model.   In that case,
     * the application should set the clientId for new relations, the corresponding relation
     * and csId will be returned to the application in a map based on the input clientId.
     * (Note: the clientId values must unique within the entire input set).
     * <br>
     * <br>
     * If the application is intending to replace a connected part relation with another
     * relation having the same copy stable ID then the applicaiton may pass the original
     * <code>csId</code> as input and Teamcenter will use that to remove and replace the
     * relation having that <code>csId</code>.  If the <code>csId</code> is not specified
     * Teamcenter will generate them automatically.
     * <br>
     */
    struct ControlModelInfo
    {
        /**
         * The use of this value is optional, but recommended.  It is used for mapping server
         * errors and for correlating data in the response to the inputs.  The caller should
         * populate each <b>ControlModelInfo</b> with a value that is unique within the input
         * set.   The value is not interpreted or manipulated internally by the server.
         */
        std::string clientId;
        /**
         * Copy stable ID; optional, except for replace requests
         */
        std::string csId;
        /**
         * specifies object to relelate.  If set to <i>NULLTAG</i>, csId must not be empty (nulltag
         * signifies remove of control model relation for csId)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  secondaryObject;
        /**
         * A set of name value pairs used to specify additional property data for the relation.
         * All values are specified as strings, the caller is responsible for generating the
         * correct string representation of each value passed.  For tag values, the UID of the
         * tag is used.
         * <br>
         * <code>attrInfo</code> is object of <code>AttributeInfoMap</code>.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string</code>, <code>std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
    };

    /**
     * It contains a map of input client ID to the objects that were created or updated.
     * It also returns a map of the control element to the <code>ShapeDesign</code> created
     * for it. It also returns a map of the secondaryObject listed in the <b>ControlModelInfo</b>
     * to the corresponding copy stable ID of the control model relation that references
     * it.
     */
    struct CreateOrUpdateDesignControlElementsResponse
    {
        /**
         * map of client id to corresponding object (<code>DesignControlElement</code>) that
         * was created
         * <br>
         * <code>csIdMap</code> is object of <code>StringToBoMap</code>.
         * <br>
         * <code>StringToBoMap</code> parameter : Map of(<code>std::string</code> <code>,Teamcenter::BusinessObject</code>)
         */
        StringToBoMap clientIDMap;
        /**
         * map of <code>DesignControlElement</code> to  <code>NewShapeDesignData</code>.
         */
        NewShapeDesignDataMap shapeDesigns;
        /**
         * map of added controlled elements to their copy stable ID
         * <br>
         * <code>csIdMap</code> is object of <code>BoToStringMap</code>.
         * <br>
         * <code>BoToStringMap</code> parameter : Map of(<code>Teamcenter::BusinessObject, std::string</code>
         * )
         */
        BoToStringMap csIdMap;
        /**
         * Contains list of added, updated, or deleted objects.  Also contains list of any errors
         * which occurred within the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * CreateOrUpdateDesignElementsInfo is used as input into createOrUpdateDesignElements.It
     * contains a lists if input for creating or updating "shape", "reuse", "promissory"
     * and "subordinate" DesignElement objects.
     */
    struct CreateOrUpdateDesignElementsInfo
    {
        /**
         * shapeDesignElements
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ShapeDesignElementInfo > shapeDesignElements;
        /**
         * reuseDesignElements
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ReuseDesignElementInfo > reuseDesignElements;
        /**
         * promissoryDesignElements
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::PromissoryDesignElementInfo > promissoryDesignElements;
        /**
         * subordinateDesignElements
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::SubordinateDesignElementInfo > subordinateDesignElements;
    };

    /**
     * It contains a map of input client ID to the objects that were created or updated.
     * It also returns a map of returned <i>subordinates</i>; where key is <i>reuse</i>
     * design elements and value is a vector of <i>subordinate</i> design elements. Number
     * of <i>subordinates</i> returned is governed by the <code>levelsOfSubordinatesToReturn</code>
     * value specified on input for each <i>reuse</i> design elements. It also returns
     * <code>ShapeDesign</code> and <code>ShapeDesignRevision</code> pair of objects for
     * those newly created.
     */
    struct CreateOrUpdateDesignElementsResponse
    {
        /**
         * map of client ID to corresponding object (<b>Cpd0DesignElement</b>) that was created
         * <br>
         * <code>clientIDMap</code> is object of <code>StringToBoMap</code>.
         * <br>
         * <code>clientIDMap</code> parameter: Map of (<code>std::string,Teamcenter::BusinessObject</code>)
         */
        StringToBoMap clientIDMap;
        /**
         * map of design elements to  new shape design revision.
         */
        NewShapeDesignDataMap shapeDesigns;
        /**
         * This is for overrides geometry. Map of design elements to  new shape design revision.
         */
        NewShapeDesignDataMap shapeOverrideDesigns;
        /**
         * A list of <i>reuse</i> design elements where effectivity conditions are encountered
         * in the realized item structure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignElement>  > unmappedEffectivityEncountered;
        /**
         * Contains list of added, updated, or deleted objects.  Also contains list of any errors
         * which occurred within the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A map of <i>reuse</i> design element(Key) and a list of its <i>subordinate</i> design
         * elements(Values). The list of <i>subordinate</i> designelements will be governed
         * by the input argument levelsOfSubordinatesToReturn
         * <br>
         * <code>subordinateElements</code> is object of <code>BoToBoVectorMap</code>.
         * <br>
         * <code>subordinateElements</code> parameter : Map of (<code>Teamcenter:BusinessObject,Teamcenter:Business
         * Object[] </code>)
         */
        BoToBoVectorMap subordinateElements;
    };

    /**
     * The response contains  map of input caller specified client ID values and the corresponding
     * objects that were created/updated features. The response also contains a map of caller
     * specified client ID values for (connected element) relations and their corresponding
     * copy stable ID values. The service data contains a list of added, updated, or deleted
     * objects and it also contains a list of any errors which occurred within the call.
     */
    struct CreateOrUpdateDesignFeaturesResponse
    {
        /**
         * Map of client ID to corresponding object (<b>Cpd0DesignFeature</b>) that was created.
         * <br>
         * <code>clientIDMap</code> is object of <code>StringToBoMap</code>.
         * <br>
         * <code>clientIDMap</code> parameter : Map of (<code>std:string,Teamcenter:BusinessObject</code>)
         */
        StringToBoMap clientIDMap;
        /**
         * Map of client ID, specified in DesignFeatureConnectionInfo, to the copy stable ID
         * of the corresponding relation.
         * <br>
         * <code>connectionIDMap</code> object of <code>StringToStringMap</code>
         * <br>
         * <code>connectionIDMap</code> parameter : Map of (<code>std:string,std:string</code>)
         */
        StringToStringMap connectionIDMap;
        /**
         * Contains list of added, updated, or deleted objects.  Also contains list of any errors
         * which occurred within the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response to createOrUpdateDesignDSubsetElements.   It contains a list of design subset
     * element data which is one to one correspondance with input subset element info.
     */
    struct CreateOrUpdateDesignSubsetElementsResponse
    {
        /**
         * added, updated, deleted object data plus any error information
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of design subset element data which has one to one correpondance with input
         * subset element info.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::DesignSubsetElementData > dseData;
    };

    /**
     * <code>DesignControlElementsInfo</code> is used as input to describe create or update
     * request for a <b>Cpd0DesignControlElement</b>. New <b>Cpd0DesignControlElement</b>
     * objects require creation of a new <b>Cpd0ShapeDesign</b> objects.
     * <br>
     * Transform and bounding box can be optionally specified. <b>Note:</b> Changing the
     * transform of a control model in Teamcenter does not affect a change in position of
     * the elements that it produced.
     * <br>
     * Changes to <b>Cpd0ControlModel</b> relations are passed as a set of delta (adds,removed,replace,
     * delete) requests.
     * <br>
     * <ul>
     * <li type="disc">The add requests from new relations.
     * </li>
     * <li type="disc">The remove requests discard existing relations.
     * </li>
     * <li type="disc">The replace requests do a remove and an add retaining the same csIS
     * on the new relation that existed on the old;the copy stable ID(csId) must be specified
     * in the <b>ControlModelInfo</b> for any requests.
     * </li>
     * <li type="disc">The delete requests discard the existing relation and then attempts
     * to delete the object it referenced.
     * </li>
     * </ul>
     * <br>
     * Effectivity is specified in attrInfo in its string form via the <code>mdl0effectivity_formula</code>
     * property.  Effectivity is applied after control model relation updates.  The effectivity
     * condition can be cascaded to the design elements and features that were generated/updated
     * by the design control element. The cascade of effectivity takes into considerations
     * the fact that the controlled elements may be shared between (revisions of) design
     * control elements and, in that case, applies a combined effectivity of each revision
     * to the shared elements.There may be cases when effectivity cannot be cascaded to
     * a design element or feature (e.g. it may be owned by a different site). In that case,
     * a warning is generated and the change will need to be reconciled manually.
     */
    struct DesignControlElementsInfo
    {
        /**
         * The use of this value is optional, but recommended.  It is used for mapping server
         * errors and for correlating data in the response to the inputs. The caller should
         * populate each <code>DesignControlElementInfo</code> with a value that is unique within
         * the input set. The value is not interpreted or manipulated internally by the server.
         */
        std::string clientId;
        /**
         * A design control element to be updated.  Required for updating an existing <code>DesignControlElement</code>,
         * empty otherwise
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignControlElement>  element;
        /**
         * required for creating new <code>DesignControlElement</code>, empty otherwise
         */
        std::string boType;
        /**
         * The collaborative design which will contain the new design control element; required
         * for new <code>DesignControlElement</code>, empty otherwise
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  modelObject;
        /**
         * Creation input for corresponding <b>Cpd0ShapeDesignRevison</b>; required for creating
         * new <code>DesignControlElement</code>, empty otherwise
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CompoundCreateInput compoundCreateInput;
        /**
         * Absolute transform (units in meters) positioning the design feature in the coordinate
         * space of the collaborative design.  This is a vector of 16 double precision values;
         * order of values corresponds to PLMXML standard.   An empty vector is interpreted
         * as an identity matrix.
         */
        std::vector< double > transform;
        /**
         * Bounding box data (units in meters) in coordinate space of the collaborative design;
         * empty = no box.  Order of values is { x min, y min, z min, x max, y max, zmax }.
         */
        std::vector< double > boundingBox;
        /**
         * A set of name value pairs used to specify additional property data for design control
         * elements.  All values are specified as strings, the caller is responsible for generating
         * the correct string representation of each value passed.  For tag values, the UID
         * of the tag is used.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string</code>, <code>std::string</code>[])
         */
        AttributeInfoMap attrInfo;
        /**
         * Specifies the set of objects (design elements and design features) this control model
         * manages. Control model (<b>Cpd0ControlModel</b>) relations in Teamcenter will be
         * created such that they match the entries in the <code>addControlledElements</code>
         * list.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ControlModelInfo > addControlledElements;
        /**
         * Specifies the set of objects (design elements and design features) this control model
         * no longer manages. The corresponding Control model (<b>Cpd0ControlModel</b>) relations
         * Teamcenter will be deleted; the design elements and design features will not be deleted.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ControlModelInfo > removeControlledElements;
        /**
         * Specifies the set of objects (design elements and design features) this control model
         * that are replaced by another object. The corresponding Control model (<b>Cpd0ControlModel</b>)
         * relations in Teamcenter will be deleted then re created referencing the replacing
         * object; the copy stable ID from the old relation will be reused for the new relation.
         * The replaced design elements and design features will not be deleted.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ControlModelInfo > replaceControlledElements;
        /**
         * Specifies the set of objects (design elements and design features) this control model
         * no longer manages. The corresponding Control model (<b>Cpd0ControlModel</b>) relations
         * Teamcenter will be deleted; once the relations are deleted, Teamcenter will attempt
         * to delete the corresponding design elements and design features.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ControlModelInfo > deleteControlledElements;
        /**
         * Reference to a <b>DirectModel</b> dataset to associate with the design feature.
         * Value can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  directModelDataset;
        /**
         * Reference to a dataset, containing Trushape information, to associate with the design
         * feature.  Typically this will be a <b>UGMASTER</b> or <b>DirectModel</b> dataset.
         * Optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  trueshapeDataset;
        /**
         * Flag, if set to true, causes the update of design feature to check last modified
         * date to avoid data overwrite.
         */
        bool guardObjLastModifiedDate;
        /**
         * Modification date guard is used if <code>guardObjLastModifiedDate</code> is set to
         * true. Object update will abort if the last modified date of the object is not same
         * as <code>objLastModifiedDateGuard</code>.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * Information about auxiliary objects (attribute groups) attached to the design feature
         * to be created or updated.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code>.
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * <code>DesignFeatureConnectionInfo</code> is used as input for creating or updating
     * the set of design elements connected to the design feature.
     */
    struct DesignFeatureConnectionInfo
    {
        /**
         * The use of this value is optional, but recommended.  It is used for mapping server
         * errors and for correlating data in the response to the inputs.  The caller should
         * populate each <code>DesignFeatureConnectionInfo</code> with a value that is unique
         * within the input set. The value is not interpreted or manipulated internally by the
         * server.
         */
        std::string clientId;
        /**
         * Connected design element, required.  The design element must exist in the same collaborative
         * design as the design feature.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignModelElement>  designElement;
        /**
         * Copy stable ID, required when replacing once connected with another, otherwise optional.
         * Also, if <code>designElement</code> is set to <i>NULLTAG</i> during a replace, the
         * connected info is removed from Teamcenter.
         */
        std::string csId;
        /**
         * A set of name value pairs used to specify additional property data for the relation.
         * All values are specified as strings, the caller is responsible for generating the
         * correct string representation of each value passed.  For tag values, the UID of the
         * tag is used.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
    };

    /**
     * <code>DesignFeatureInfo</code> is used as input for creating or updating design feature
     * objects and their connection to design element objects.  When creating a new design
     * feature, the caller must specify the business object type (boType) of the new design
     * feature.  During update, boType is left empty and a reference to the design feature
     * (feature) is specified.
     */
    struct DesignFeatureInfo
    {
        /**
         * The use of this value is optional, but recommended.  It is used for mapping server
         * errors and for correlating data in the response to the inputs. The caller should
         * populate each <code>DesignFeatureInfo</code> with a value that is unique within the
         * input set. The value is not interpreted or manipulated internally by the server.
         */
        std::string clientId;
        /**
         * A reference to a design feature to be updated.  A value is required for update, otherwise
         * (create case) this value should be empty
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignFeature>  feature;
        /**
         * The business object type of a design feature to be created.  This value is required
         * for creating a new design feature, and must be a valid subtype of <b>Cpd0DesignFeature</b>.
         * For update of an existing design feature, this value should be empty.
         */
        std::string boType;
        /**
         * The collaborative design which will contain the new design feature; required for
         * creating a new design feature.  If an existing design feature is being updated, then
         * this value should be empty.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  modelObject;
        /**
         * Absolute transform (units in meters) positioning the design feature in the coordinate
         * space of the collaborative design.  This is a vector of 16 double precision values;
         * order of values corresponds to PLMXML standard. An empty vector is interpreted as
         * an identity matrix.
         */
        std::vector< double > transform;
        /**
         * A set of name value pairs used to specify additional property data for design features.
         * All values are specified as strings, the caller is responsible for generating the
         * correct string representation of each value passed.  For tag values, the UID of the
         * tag is used.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * List  of objects to which the design feature is connected. The connected element
         * (<b>Cpd0ConnectedElement</b>) relations in Teamcenter will be created/updated/removed
         * such that they match the entries in the <code>connectedInfo</code> list, unless the
         * mergeConnected option is set to true.  If mergeConnected option is false, relations
         * not referenced in the input will not be automatically removed from the feature.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::DesignFeatureConnectionInfo > connectedInfo;
        /**
         * flag, when set to true, indicates that connected info should be merged with existing
         * content in Teamcenter; otherwise all connected data is replaced for the feature.
         * If no connected information for this feature currently exists in Teamcenter, then
         * merge and replace have the same effect.
         */
        bool mergeConnected;
        /**
         * Reference to a <b>DirectModel</b> dataset to associate with the design feature.Value
         * can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  directModelDataset;
        /**
         * Reference to a dataset, containing Trushape information, to associate with the design
         * feature.  Typically this will be a <b>UGMASTER</b> or <b>DirectModel</b> dataset.
         * Optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  trueshapeDataset;
        /**
         * Flag, if set to true, causes the update of design feature to check last modified
         * date to avoid data overwrite.
         */
        bool guardObjLastModifiedDate;
        /**
         * Modification date guard is used if <code>guardObjLastModifiedDate</code> is set to
         * true. Object update will abort if the last modified date of the object is greater
         * than <code>objLastModifiedDateGuard</code>.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * Information about auxiliary objects (attribute groups) attached to the design feature
         * to be created or updated.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code> which
         * is map of relation property name to  <code>AuxiliaryObjectInfo</code> .
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         * <br>
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * Response to <code>createOrUpdateDesignSubsetElements</code> contains information
     * about <code>DesignSubsetElements</code> created or updated, its clientId, its CopyStable
     * Id.  It also contains a list of appended and removed <code>DesignElements</code>
     * from the <code>workSetModel</code>.
     */
    struct DesignSubsetElementData
    {
        /**
         * map of client ID to corresponding object that was created. It can be empty if  <code>DesignSubsetElementInfo</code>
         * do not have Client ID populated.
         */
        std::string clientID;
        /**
         * Business Object reference to <code>DesignSubsetElement</code> created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignSubsetElement>  subsetElement;
        /**
         * Business Object reference to <code>DesignSubsetInstance</code> created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignSubsetInstance>  subsetInstance;
        /**
         * copy stable ID of design subset element.
         */
        std::string dseCsID;
        /**
         * This is for override mapping. Not supported currently. Reserved for future development.
         * <br>
         * <code>subordinateMap</code> is object of <code>BoToBoMap</code>
         * <br>
         * <code>subordinateMap</code> parameter :Map of (<code>Teamcenter::BusinessObject,
         * Teamcenter::BusinessObject</code>)
         */
        BoToBoMap subordinateMap;
        /**
         * Map of new source design element to its copy stable id.
         * <br>
         * <code>csIdMap</code> is object of <code>BoToStringMap</code>
         * <br>
         * <code>BoToStringMap</code> parameter : Map of(<code>Teamcenter::BusinessObject, std::strin</code>g
         * )
         */
        BoToStringMap csIDMap;
        /**
         * Contains list of appended source elements.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement>  > appendedSourceElementList;
        /**
         * Contains list of removed source elements.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement>  > removedSourceElementList;
    };

    /**
     * Data on <code>DesignSubsetElementInfo</code> used to create or update <code>DesignSubsetElements</code>
     * in a workset.
     * <br>
     * <br>
     */
    struct DesignSubsetElementInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned CreatedItemsOutput
         * elements and Partial Errors associated with this input ItemProperties. This is an
         * optional argument.
         */
        std::string clientId;
        /**
         * Business Object reference to an existing <code>DesignSubsetElements</code> that needs
         * to be updated. If  none supplied, it is assumed to create a new <code>DesignSubsetElement</code>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignSubsetElement>  element;
        /**
         * If specified a new <code>DesignSubsetElement</code> is created. This value is required
         * for creating new a DesignSubsetElement, and must be a valid subtype of <b>Cpd0DesignSubsetElement</b>.
         * For update of an existing <code>DesignSubsetElement</code>, this value should be
         * empty.
         */
        std::string boType;
        /**
         * Business object reference to the workset Revision in which the objects to be created
         * or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  modelObject;
        /**
         * BOMView type. Optional if modelObject is WorksetRevision, empty otherwise.
         */
        std::string viewType;
        /**
         * Business object reference to the Collaborative Design from which contect is being
         * instanced, optional for update usecase.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  sourceModel;
        /**
         * Absolute transform which positions the shape in the coordinate system of the collaborative
         * design (units in meters), empty = identity, otherwise contains 16 doubles in the
         * following order: { r00, r10, r20, p0, r01, r11, r21, p1, r02, r12, r22, p2, t0, t1,
         * t2, s }, where the letter prefix signifies the following:
         * <br>
         * <ul>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;r    a rotation component
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;p   a perspective component
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;t    a translation component
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;s   the inverse scale.
         * </li>
         * </ul>
         */
        std::vector< double > transform;
        /**
         * A set of name value pairs used to specify additional property data for design control
         * elements. All values are specified as strings, the caller is responsible for generating
         * the correct string representation of each value passed.  For tag values, the UID
         * of the tag is used.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * A list of business object references of the object to be append from <code>sourceModel</code>
         * into the <code>modelObject</code>  i.e the list of objects to be Appended from sourceModel
         * into worksetModel.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement>  > appendSourceElements;
        /**
         * A list of business object references of the object to be removed from the <code>modelObject</code>
         * i.e the list of objects to be removed  from Workset Model. It is expected that this
         * parameter contains the complete list of presented parent design elements and the
         * actual design elements to be removed unless <code>removechildrenautomicatlly</code>
         * is set to true.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement>  > removeSourceElements;
        /**
         * If this is set to <i>true</i>, then the recipe include/exclude elements criteria
         * will be modified acoordingly based on  <code>appendSourcElements</code> and <code>removeSourceElements</code>
         * input arguments.
         */
        bool updateRecipeForAppendsAndRemoves;
        /**
         * Specify the source objects for which there must be a persistant subordinate design
         * element to be created. Only supported when subset is part of a Workset.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement>  > subordinateSourceElements;
        /**
         * Business Object reference to the <b>Cpd0Subset</b> business object.This is used when
         * a subset is instantiated into a worksetrevision. Instead of explicitly passing design
         * element to be added or removed in a workset revision,user can choose to pass a subset
         * as an input such that all the design elements fulfilling the recipe criteria will
         * be instanced into worksetrevision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0SubsetDefinition>  subset;
        /**
         * This flag specifies if the children of  design elements  specified in <code>removeSourceElements</code>
         * input parameter must also be removed  from <code>worksetModel</code>. It is set to
         * <i>false</i> by default. It this is <i>false</i>, it is expected that <code>removeSourceElements</code>
         * contains complete hierachy of design elements to be removed.
         */
        bool removeChildrenAutomatically;
        /**
         * This designElements in this list will replace the designElements from workset model
         * while retaining csId. If no designElement is found corresponding to key csId, a case
         * of change in csId is assumed. In case of change in csId, csId of existing design
         * element in workset model is changed.Input must contain all elements which complete
         * valid and logical structure .Invalid
         * <br>
         * input may result into inconsistent data model.
         */
        StringToBoMap replaceSourceElements;
        /**
         * Flag, if set to true, causes the update of DesignElement to check last modified date
         * to avoid data overwrite.
         */
        bool guardObjLastModifiedDate;
        /**
         * Modification date guard is used if <code>guardObjLastModifiedDate</code> is set to
         * true. Object update will abort if the last modified date of the object is greater
         * than <code>objLastModifiedDateGuard</code>.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * Information about auxiliary objects (attribute groups) attached to the design feature
         * to be created or updated.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code> which
         * is map of relation property name to  <code>AuxiliaryObjectInfo</code> .
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * <code>NewShapeDesignData</code> is used for returning the pair of new <b>Cpd0ShapeDesign</b>
     * and <b>Cpd0ShapeDesignRevision</b> objects newly created by a service.
     */
    struct NewShapeDesignData
    {
        /**
         * New Cpd0ShapeDesign object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0ShapeDesign>  shapeDesign;
        /**
         * New <b>Cpd0ShapeDesignRevision</b> object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0ShapeDesignRevision>  shapeDesignRevsion;
    };

    /**
     * <code>PromissoryDesignElementInfo</code> is used as input for creating <i>promissory</i>
     * DesignElement objects.
     */
    struct PromissoryDesignElementInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned <code>CreatedItemsOutput</code>
         * elements and Partial Errors associated with this input ItemProperties.
         */
        std::string clientId;
        /**
         * The <i>promissory</i>  design element to be updated or substituted. Can be empty
         * otherwise.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignElement>  element;
        /**
         * The business object type of a design element to be created.  This value is required
         * for creating a new design element, and must be a valid subtype of <b>Cpd0DesignElement</b>.
         * For update of an existing design element, this value should be empty.
         */
        std::string boType;
        /**
         * Collaborative Design for creating a new <i>promissory</i>  design element. Can be
         * empty otherwise.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  modelObject;
        /**
         * Bounding box data (units in meters), empty = no box, otherwise contains 6 doubles
         * in the following order:{ x min, y min, z min, z max, y max, z max }
         */
        std::vector< double > boundingBox;
        /**
         * A set of name value pairs used to specify additional property data for design control
         * elements.  All values are specified as strings, the caller is responsible for generating
         * the correct string representation of each value passed.  For tag values, the UID
         * of the tag is used.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * Flag, if set to true, causes the update of <code>DesignElement</code> to check last
         * modified date to avoid data overwrite.
         */
        bool guardObjLastModifiedDate;
        /**
         * Modification date guard is used if <code>guardObjLastModifiedDate</code> is set to
         * true. Object update will abort if the last modified date of the object is greater
         * than <code>objLastModifiedDateGuard</code>.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * Information about auxiliary objects (attribute groups) attached to the design feature
         * to be created or updated.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code> which
         * is map of relation property name to  <code>AuxiliaryObjectInfo</code> .
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * This filter can specify a combination of the type of the relation to traverse, the
     * possible attributes on the relation, and the type of Business Object at the other
     * end of that relation. An empty string denotes no filter (acts as a wildcard returning
     * all objects without filtering the particular aspect that is not specified).
     * <br>
     * <br>
     * The combination of filters specified by <code>relatedTypeName</code>, all <code>filters</code>
     * and <code>otherSideObjectTypeName</code> are combined together with a logical AND
     * operation, meaning all criteria must be met for the related object to be returned
     * to the caller.
     * <br>
     * <br>
     * <b>WARNING</b>:  Any attribute filter other than <code>mdl0cs_id</code>, if passed
     * in, will cause a not mplemented error and a service exception.  This service may
     * be extended in the future to support filtering on any relation attribute.
     * <br>
     */
    struct RelatedObjectFilter
    {
        /**
         * Filters based on the type of relation between the sourceObject and the related object.
         * If not specified, then all relations from the source object are evaluated.
         */
        std::string relationTypeName;
        /**
         * Filters based on a list of relation attribute values.  If the list is empty, then
         * no relationship attribute filtering is applied.  NOTE: Currently only one attribute
         * (<code>mdl0cd_id</code>) is supported
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelationAttributeFilter > filters;
        /**
         * Filters based on the type of the object related to the sourceObject.  If not specified,
         * then all related objects are evaluated, irrespective of their type.
         */
        std::string otherSideObjectTypeName;
    };

    /**
     * The <code>RelatedObjectInput</code> construct expresses a set of filter criteria
     * to be applied to objects related to a sourceObject.  Multiple instances of <code>RelatedObjectFilter</code>
     * are combined together with a logical OR, meaning if a related object matches any
     * of the filter criteria, it will be returned to the caller.
     */
    struct RelatedObjectInput
    {
        /**
         * The input (source) object for which related objects are to be found.  This value
         * is required; an empty sourceObject results in an exception being thrown.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceObject;
        /**
         * A set of filters to apply to the objects related to the sourceObject.  An empty filter
         * list denotes no filter ( acts as a wildcard returning all objects without filtering).
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelatedObjectFilter > filters;
    };

    /**
     * <code>RelatedObjectOutput</code> contains the result corresponding to one source
     * object. It returns the input source object itself, the related object at the other
     * end of the relation, and the relation itself.
     */
    struct RelatedObjectOutput
    {
        /**
         * source object specified in <code>RelatedObjectInput</code>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceObject;
        /**
         * A list of <code>relationInfo</code> which contains the filtered and configured results
         * of the query.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelationInfo > relationInfos;
    };

    /**
     * <code>RelatedObjectsResponse</code> is used to return the results of a call to either
     * <code>queryRelatedPrimaryObjects</code> or <code>queryRelatedSecondaryObjects</code>.
     * It contains a set of all objects that satisfy any one or more of the input filter
     * criteria and that satisfy the input configuration criteria.
     */
    struct RelatedObjectsResponse
    {
        /**
         * A list of <code>RelatedObjectOutput</code> which correspond to the inputs.
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelatedObjectOutput > outputObjects;
        /**
         * Contains a  list of any errors which occurred within the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure contains the values to filter a relation attribute by.  Only one of
     * the fields in <code>RelationAttributeValues</code> should be populated, the field
     * populated must correspond to the value of <code>RelationAttributeDataType</code>
     * in the <code>RelationAttributeFilter</code>.  Multiple values, if passed in, are
     * logically grouped with OR, meaning if any of the values match, the relation will
     * pass through the filter.
     */
    struct RelationAttributeValues
    {
        /**
         * A list of boolean values
         */
        std::vector< bool > booleanValues;
        /**
         * A list of integer values
         */
        std::vector< int > integerValues;
        /**
         * A list of string values; string value comparisions are case sensitive.
         */
        std::vector< std::string > stringValues;
        /**
         * A list of double values
         */
        std::vector< double > doubleValues;
        /**
         * A list of date values
         */
        std::vector< Teamcenter::Soa::Common::DateTime > dateValues;
        /**
         * A list of tag values
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tagValues;
    };

    /**
     * This structure specifies a filter on one attribute of a relation.  A mismatch between
     * the <code>attributeType</code> and the <code>attributeValues</code> data type results
     * in an invalid input error and an SOA exception.  Any attribute other than <code>mdl0cs_id</code>,
     * if passed in, will cause a not mplemented error and an SOA exception.
     */
    struct RelationAttributeFilter
    {
        /**
         * Name of the attribute to be filtered. Cannot be an empty stringFilters
         */
        std::string attributeName;
        /**
         * The data type of the attribute to be filtered.  Supported values are:
         * <br>
         * <ul>
         * <li type="disc">BooleanType
         * </li>
         * <li type="disc">IntegerType
         * </li>
         * <li type="disc">StringType
         * </li>
         * <li type="disc">DoubleType
         * </li>
         * <li type="disc">DateType
         * </li>
         * <li type="disc">TagType
         * </li>
         * </ul>
         */
        RelationAttributeDataType attributeType;
        /**
         * A list of values to filter by.  At least one value of the proper type must be specified.
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelationAttributeValues attributeValues;
    };

    /**
     * <code>RelationInfo</code> contains the result data for one related object in the
     * output, for a given relation.
     */
    struct RelationInfo
    {
        /**
         * The object found on the other side of the relation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  otherSideObject;
        /**
         * The relation object which relates <code>otherSideObject</code> to the <code>sourceObject</code>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Mdl0CopyStableRelation>  relationObject;
    };

    /**
     * <code>ReuseDesignElementInfo</code> is used as input for creating <i>reuse</i> Design
     * Element and for substituting a <i>reuse</i> in an existing a <i>shape</i> or <i>promissory</i>
     * Design Element.
     */
    struct ReuseDesignElementInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned <code>CreatedItemsOutput</code>
         * elements and Partial Errors associated with this input ItemProperties.
         */
        std::string clientId;
        /**
         * Business object reference to the Design Element to be substituted. It can be either
         * a <code>shape</code> Design Element or a <i>priomisorry</i> Design Element.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignElement>  element;
        /**
         * This argument is not applicable for this operation.
         */
        std::string boType;
        /**
         * The argument is not applicable for this operation
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  modelObject;
        /**
         * Source Item revision to be realized to create a <i>reuse</i>. Any Item type other
         * than <b>ShapeDesign</b> and its subtypes can be used for substitution.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceObject;
        /**
         * <b>RevisionRule</b> to be applied to configure the structure of the source object
         * (should it be an assembly). The configured structure objects will be realized in
         * to the Collaborative Design. If empty, the value will be defaulted based on the value
         * set in the <b>Cpd0DefaultDERevRule</b> business constant.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
        /**
         * <b>BomView</b> type to be used to configure the structure of the source object. If
         * empty, then it will be defaulted to the value set in the <b>Cpd0DefaultBomViewPreference</b>
         * business constant. This argument is only required for creation of <i> reuse</i>
         * and <i> subordinate</i> design elements.
         */
        std::string bomView;
        /**
         * Reserved for future.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  variantRule;
        /**
         * Reserved for future.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StoredOptionSet>  sos;
        /**
         * The argument is not applicable for this operation.
         */
        bool updateSubordinates;
        /**
         * The argument is not applicable for this operation
         */
        bool guardLastModifiedDate;
        /**
         * The argument is not applicable for this operation
         */
        Teamcenter::Soa::Common::DateTime lastModifiedDateGuard;
        /**
         * Absolute transform which positions the source object in the coordinate system of
         * the collaborative design (units in meters), empty = identity, otherwise contains
         * 16 doubles in the following order: { r00, r10, r20, p0, r01, r11, r21, p1, r02, r12,
         * r22, p2, t0, t1, t2, s }, where the letter prefix signifies the following:
         * <br>
         * <ul>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;r   a rotation component
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;p  a perspective component
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;t   the inverse scale.
         * </li>
         * </ul>
         */
        std::vector< double > transform;
        /**
         * Reference to a <b>DirectModel</b> dataset to attach to <i>reuse</i> design element.
         * This argument is optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  directModelDataset;
        /**
         * Bounding box data (units in meters) in coordinate space of the collaborative design;
         * empty = no box.  Order of values is { x min, y min, z min, x max, y max, z max }.This
         * is an optional argument.
         */
        std::vector< double > boundingBox;
        /**
         * A set of name value pairs used to specify additional property data for design control
         * elements.  All values are specified as strings, the caller is responsible for generating
         * the correct string representation of each value passed.  For tag values, the UID
         * of the tag is used. To carry Variant expressions and Occurrence Effectivity expressions
         * from source objects to corresponding subordinate design elements during realization,
         * the properties <i>rlz0sync_variant_exprs</i> and <i>rlz0sync_effectivity_exprs</i>
         * must be set to <i>true</i>  accordingly.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * Number of levels of <i>subordinate</i> design elements to be returned. Valid values
         * are
         * <br>
         * Negative 1  (return all subordinates of the reuse)
         * <br>
         * 0  (dont return any subordinate for the reuse)
         * <br>
         * 1  (return first level of subordinates only)
         * <br>
         * <br>
         * Note: subordinate design elements are created when the source object is an assembly.
         * <br>
         */
        int levelsOfSubordinatesToReturn;
        /**
         * geometryOverrideShapeCreateInput
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CompoundCreateInput geometryOverrideShapeCreateInput;
        /**
         * Flag, if set to true, causes the update of DesignControlElement to check last modified
         * date to avoid data overwrite.
         */
        bool guardObjLastModifiedDate;
        /**
         * Modification date guard is used if <code>guardObjLastModifiedDate</code> is set to
         * true. Object update will abort if the last modified date of the object is not same
         * as <code>objLastModifiedDateGuard</code>.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * Information about auxiliary objects (attribute groups) attached to the design element
         * to be created or updated.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code> which
         * is map of relation property name to  <code>AuxiliaryObjectInfo</code> .
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * <i>ShapeDesignElementInfo</i> is used as input for creating <i>shape</i> Design Elements
     * and for substituting a <i>shape</i> in an existing a <i>reuse</i> or <i>promissory</i>
     * Design Element.
     */
    struct ShapeDesignElementInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify returned in <code>CreatedItemsOutput</code>
         * elements and Partial Errors associated with this input ItemProperties.
         */
        std::string clientId;
        /**
         * The <b>cpd0DesignElement</b> business object reference to be substituted. It must
         * be of category <i>reuse</i> or <i>promissory</i>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignElement>  element;
        /**
         * Empty string value .This argument is not applicable for this operation.
         */
        std::string boType;
        /**
         * This argument is not applicable for this operation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  modelObject;
        /**
         * Required for creating a new <i>shape</i> design element; otherwise, it should be
         * empty.<code>CompountCreateInput</code> is a Map of relation property name to <code>AuxiliaryObjectInfo</code>.
         * The property name must be the relation property on the main object which will be
         * used to attach the auxiliary objects. AuxiliaryObjectInfo is used as input for creating
         * or updating auxiliary objects along with main objects. For example, it can be used
         * to pass information about attribute group objects to be created along with <code>DesignElement</code>
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CompoundCreateInput compoundCreateInput;
        /**
         * Absolute transform which positions the shape in the coordinate system of the collaborative
         * design (units in meters), empty = identity, otherwise contains 16 doubles in the
         * following order: { r00, r10, r20, p0, r01, r11, r21, p1, r02, r12, r22, p2, t0, t1,
         * t2, s }, where the letter prefix signifies the following:
         * <br>
         * <ul>
         * <li type="disc"> r&nbsp;&nbsp;&nbsp;&nbsp;  a rotation component
         * </li>
         * <li type="disc"> p&nbsp;&nbsp;&nbsp;&nbsp;  a perspective component
         * </li>
         * <li type="disc"> t&nbsp;&nbsp;&nbsp;&nbsp;  a translation component
         * </li>
         * <li type="disc"> s&nbsp;&nbsp;&nbsp;&nbsp;  the inverse scale.
         * </li>
         * </ul>
         */
        std::vector< double > transform;
        /**
         * This is an optional argument. It is a <b>DirectModel</b> dataset to attach to <i>shape</i>
         * design element.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  directModelDataset;
        /**
         * This is an optional argument . It is a  reference to a dataset, containing Trushape
         * information, to associate with the design element.Typically this will be a <b>UGMASTER</b>
         * or <b>DirectModel</b> dataset.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  trueshapeDataset;
        /**
         * Bounding box data (units in meters) in coordinate space of the Collaborative Design;
         * empty = no box.  Order of values is { x min, y min, z min, x max, y max, z max }.
         */
        std::vector< double > boundingBox;
        /**
         * This argument is not applicable for this operation.
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * This argument is not applicable for this operation.
         */
        bool guardObjLastModifiedDate;
        /**
         * This argument is not applicable for this operation.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * This argument is not applicable for this operation.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code> which
         * is map of relation property name to  <code>AuxiliaryObjectInfo</code> .
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * SubordinateDesignElementInfo is used as input for applying overrides on "subordinate"
     * DesignElement objects.
     */
    struct SubordinateDesignElementInfo
    {
        /**
         * client id
         */
        std::string clientId;
        /**
         * required
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignElement>  element;
        /**
         * Absolute transform (units in meters), empty vector == identity
         */
        std::vector< double > transform;
        /**
         * extra attribute data for DE
         * <br>
         * <code>attrInfo</code> parameter : Map of (<code>std::string, std::string[]</code>)
         */
        AttributeInfoMap attrInfo;
        /**
         * geometryOverrideShapeCreateInput is used by applications that required items for
         * managing their data files.  Specifying this input creates a ShapeDesign to hold override
         * geometry for the subordinate design element.
         */
        Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CompoundCreateInput geometryOverrideShapeCreateInput;
        /**
         * DirectModel dataset to attach to SubordinateDesignElement as override
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  directModelDataset;
        /**
         * Bounding box data (units in meters), empty = no box, otherwise contains 6 doubles
         * in the following order:{ x-min, y-min, z-min, z-max, y-max, z-max }
         */
        std::vector< double > boundingBox;
        /**
         * Flag, if set to true, causes the update of DesignControlElement to check last modified
         * date to avoid data overwrite.
         */
        bool guardObjLastModifiedDate;
        /**
         * Modification date guard is used if guardObjLastModifiedDate is set to true. Object
         * update will abort if the last modified date of the object is not same as objLastModifiedDateGuard.
         */
        Teamcenter::Soa::Common::DateTime objLastModifiedDateGuard;
        /**
         * information about auxiliary objects to be created or updated.
         * <br>
         * <code>auxiliarObjects</code> is object of <code>AuxiliaryObjectInfoMap</code> which
         * is map of relation property name to  <code>AuxiliaryObjectInfo</code> .
         * <br>
         * <code>axiliaryObject</code> paramter: Map of (<code>std:string,AuxiliaryObjectInfo[]</code>)
         */
        AuxiliaryObjectInfoMap auxiliaryObjects;
    };

    /**
     * Contains a map of client id (provided in input) to the reuse Design Element. It has
     * Service Data with created/updated/deleted objects along with any partial errors.
     */
    struct SubstituteAsReuseDesignElementResponse
    {
        /**
         * This is a map of client id to corresponding object (Cpd0DesignElement) that was substituted
         * (String/Business object).
         * <br>
         * <code>clientIDMap</code> is object of <code>StringToBoMap</code>
         * <br>
         * <code>clientIDMap</code> parameter : Map of (<code>std:string, Teamcenter:BusinessObject</code>)
         */
        StringToBoMap clientIDMap;
        /**
         * This contains added and updated objects. It also contains partial errors, if any
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains a map of client id (provided in input) to the Shape Design Element. It has
     * a map of Shape Design Elements to the corresponding Shape Design and Shape Design
     * Revision objects. It has Service Data with created/updated/deleted objects along
     * with any partial errors.
     */
    struct SubstituteAsShapeDesignElementResponse
    {
        /**
         * This is a map of client id to corresponding business object reference (Cpd0DesignElement)
         * that was substituted.
         * <br>
         * <code>clientIDMap</code> is object of <code>StringToBoMap</code>
         * <br>
         * <code>clientIDMap</code> parameter : Map of (<code>std:string, Teamcenter:BusinessObject</code>)
         */
        StringToBoMap clientIDMap;
        /**
         * This is a map of Cpd0DesignElement business object reference to newly created shape
         * designs.
         */
        NewShapeDesignDataMap shapeDesigns;
        /**
         * This contains added and updated objects. It also contains partial errors, if any
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
     * Using this API, applications can create and update design control element (and relation)
     * information in bulk, giving better through put that might not otherwise be achieved
     * using standard object create and update API.
     * <br>
     * <br>
     * <b>Cpd0ControlModel</b> relationships have a copy stable ID which is unique within
     * the scope of the design feature.  The copy stable ID can be specified on create;
     * if not specified, they will be automatically generated by Teamcenter.  As their name
     * suggests, when a design feature is copied the connected element relationships are
     * also copied and the copy stable ID of the copied relations remains the same. The
     * copy stable ID is used by external applications, like CAD, to correlate internal
     * data to the related objects.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the design control element authoring use cases. Design control
     * elements (weld seams, mechanical routings, etc.) are authored by users in a CAD application
     * (versus being authored in Teamcenter RAC UI).  When the user directs the CAD system
     * to <i>save</i> their session data, the CAD tool will invoke this API to populate
     * or update the design control element information in the Teamcenter database.
     * <br>
     * Note: standard delete API are used to destroy or obsolete design control elements
     * that are no longer required.
     * <br>
     * Use Case 1: <b>Creation of new design control element </b>
     * <br>
     * The following operation can be used for creating design control element (e.g. weld
     * seams and mechanical routings) in a collaborative design.
     * <br>
     * <ul>
     * <li type="disc">Design control elements are created always in the context of a collaborative
     * design (<b>Cpd0CollaborativeDesign</b>). Generally, in a production environment,
     * a collaborative design will be created ahead of time by an authorized user using
     * the Collaborative Product Development application in Teamcenter RAC UI.  Applications
     * will generally find an existing collaborative design, using the <i>Collaborative
     * Design</i> saved query (provided OOTB in Teamcenter) or through a custom query.
     * </li>
     * <li type="disc">However, for testing purposes, an application may wish to create
     * a collaborative design programmatically. To do this the createObjects operation should
     * be used.
     * </li>
     * <li type="disc">New design control elements can be created using operation createOrUpdateDesignControlElements.
     * The application specifies the business object type for each new design control element,
     * and sets the collaborative design (found or created previously) as its modelObject.
     * Additional property and controlled element information is given and the operation
     * invoked.
     * </li>
     * <li type="disc">Design control elements have a design control element ID which is
     * unique within the system.  Applications can assign their own value using the cpd0design_control_element_id
     * property. If this value is not specified in the input to createOrUpdateDeisgnControlElements,
     * then Teamcenter will automatically assign an ID when it creates a new design control
     * element.
     * </li>
     * <li type="disc">During the operation, the server creates and saves the new design
     * control elements in context of the collaborative design.  It also creates and saves
     * the relationship(<b>Cpd0ControlModel</b>) between the design control element and
     * the design elements and design features it controls. The operation returns the new
     * objects to the caller.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use Case 2: <b>Update of existing design control element </b>
     * <br>
     * The following operation can be used for updating existing design control element
     * (e.g. weld seams and mechanical routings) in a collaborative design.
     * <br>
     * <ul>
     * <li type="disc">Design control elements are found by the application through search
     * or by navigating from a design element (<b>Cpd0DesignElement</b>) or design feature
     * (<b>Cpd0DesignFeature</b>) via the control model (<b>Cpd0ControlModel</b>) relation.
     * Note: the design control element is always the primary object of the <b>Cpd0ConnectedElement</b>
     * relation and the design element or design feature is always the secondary object.
     * </li>
     * <li type="disc">Existing design control elements can be updated using operation createOrUpdateDesignControlElements.
     * The application specifies which design control elements are to be updated.  Note:
     * the business object type and collaborative design (modelObject) are not set on the
     * input because they are already known to the design control element and cannot be
     * changed.  The application sets changed property values and specifies connected element
     * information for the feature.
     * </li>
     * <li type="disc">During the operation, the server updates and saves the design control
     * elements and adds or removes <b>Cpd0ConnectedElement</b> relations to be consistent
     * with the input.
     * </li>
     * </ul>
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
     *         objects that were created/updated features ( String/Business Object reference). The
     *         response also contains a map of caller specified client ID values for (connected
     *         element) relations and their corresponding copy stable ID values. The service data
     *         contains a list of added, updated, or deleted objects and it also contains a list
     *         of any errors which occurred within the call.
     *
     * @deprecated
     *         As of Teamcenter 9.1.1, use the createOrUpdateDesignControlElements operation from
     *         the _2012_06 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9.1.1, use the createOrUpdateDesignControlElements operation from the _2012_06 namespace."))
#endif
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CreateOrUpdateDesignControlElementsResponse createOrUpdateDesignControlElements ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::DesignControlElementsInfo >& elementInfos ) = 0;

    /**
     * Create or update  Design Elements(<b>Cpd0DesignElement</b>) of categories <i>shape</i>,
     * <i>promissory</i>,  <i>reuse</i>  and <i>subordinate</i>  in an application  model
     * (Cpd0CollaborativeDesign) based on input structure.
     * <br>
     * Creation of new <i>shape</i> design elements includes creation of new <code>ShapeDesign</code>
     * and <code>ShapeDesignRevision</code> objects. Creation of <i>reuse</i> design element
     * forces creation of <i>subordinate</i> design elements if the source item revision
     * has structure.  Position and effectivity information for new or updated design elements
     * can be set using this operation.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A design element represents the use of a standard part design, a design component,
     * or a design assembly in a product. Design elements may be created by CAD applications
     * or directly in the Teamcenter RAC UI using the Collaborative Product Development
     * application.
     * <br>
     * Design elements fall into one of the following categories:
     * <br>
     * <br>
     * <i>shape</i> design element
     * <br>
     * The shape element represents a product specific design or other model specific design
     * shape. A shape design element may become a reuse design element if the business standardizes
     * on an existing product specific design. This change of purpose does not change the
     * identity of the design element or affect its revision history.
     * <br>
     * <br>
     * <i>reuse</i> design element
     * <br>
     * The reuse design element represents an instance of a component or assembly (e.g.
     * standard part) in a collaborative design.
     * <br>
     * <br>
     * <i>subordinate</i> design element
     * <br>
     * The subordinate design element is created as the result of a <i>reuse</i> design
     * element, when the source object has structure.
     * <br>
     * <br>
     * <i>promissory</i> design element
     * <br>
     * The promissory design element is a placeholder that can later becomes a <i>reuse</i>
     * or <i>shape</i>  design element.  A <i>promissory</i> design element does not have
     * a source object.
     * <br>
     * <br>
     * This API supports the design element authoring use cases. When the user directs the
     * CAD system to <i>save</i> their session data, the CAD tool will invoke this API to
     * populate or update the design element information in the Teamcenter database.
     * <br>
     * Note: standard delete API are used to destroy or obsolete design elements that are
     * nolonger required.
     * <br>
     * <br>
     * <br>
     * <br>
     * Use Case 1: <b>Creation of new design elements </b>
     * <br>
     * Precondition: Any assembly to be realized into collaborative design (as a reuse)
     * must have a precise structure.
     * <br>
     * <br>
     * The following operation can be used for creating design element in a collaborative
     * design.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Design elements are always created in the context of a collaborative
     * design (<b>Cpd0CollaborativeDesign</b>). Generally, in a production environment,
     * a collaborative design will be created ahead of time by an authorized user using
     * the Collaborative Product Development application in Teamcenter RAC UI.  Applications
     * will generally find an existing collaborative design, using the <i>Collaborative
     * Design</i> saved query (provided OOTB in Teamcenter) or through a custom query.
     * </li>
     * <li type="disc">However, for testing purposes, an application may wish to create
     * a collaborative design programmatically.To do this the <code>createObjects</code>
     * operation should be used.
     * </li>
     * <li type="disc">New design elements can be created using operation <code>createOrUpdateDesignElements</code>.
     * The application specifies the business object type for each new design element, and
     * sets the collaborative design (found or created previously) as its modelObject.
     * Additional property and positional element information is given and the operation
     * invoked.
     * </li>
     * <li type="disc">Design elements have a design element ID which is unique within the
     * system. Applications can assign their own value using the <code>cpd0design_element_id</code>
     * property. If this value is not specified in the input to <code>createOrUpdateDesignElements</code>,
     * then Teamcenter will automatically assign an ID when it creates a new design control
     * element.
     * </li>
     * <li type="disc">During the operation, the server creates and saves the new design
     * elements in context of the collaborative design. The operation returns the new objects
     * to the caller.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <br>
     * Use Case 2: <b>Update of existing design element </b>
     * <br>
     * The following operation can be used for updating existing design element in a collaborative
     * design.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Design elements are found by the application through search.
     * </li>
     * <li type="disc">Existing design elements can be updated using operation <code>createOrUpdateDesignElements</code>.
     * The application specifies which design elements are to be updated.  Note: the business
     * object type and collaborative design (modelObject) are not set on the input because
     * they are already known to the design element and cannot be changed.
     * </li>
     * <li type="disc">The application sets changed property values.
     * </li>
     * <li type="disc">During the <code>createOrUpdateDesignElements</code> operation, the
     * server updates and saves the design elements along with its auxilliary objects if
     * any.
     * </li>
     * </ul>
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
     * @param input
     *        This Input contains a set of design elements to be created or updated. The design
     *        elements could be of category <i>shape</i>, <i>reuse</i>, <i>subordinate</i> or <i>promissory</i>
     *        based on arguments populated in the input structure (<code>CreateOrUpdateDesignElementInfo</code>).
     *        The same information is used to create or update initial values on design elements
     *        and related objects
     *        <br>
     *        <br>
     *        The inputs are separated based on category of design elements. For example, inorder
     *        to create a <i>promissory</i> design element, it is expected to populate <code>PromissoryDesignElementInfo</code>,
     *        similarly with other categories of design elements.
     *        <br>
     *        <br>
     *        As explained in the above listed structures,
     *        <br>
     *        <ul>
     *        <li type="disc"><code>ShapeDesignElementInfo</code> is to create or update <i>shape</i>
     *        design elements.
     *        </li>
     *        <li type="disc"><code>PromissoryDesignElementInfo</code> is to create or update <i>promissory</i>
     *        design elements.
     *        </li>
     *        <li type="disc"><code>ReuseDesignElementInfo</code> is to create or update <i>reuse</i>
     *        and <i>subordinate</i> design elements.
     *        </li>
     *        </ul>
     *
     * @return
     *         It contains a map of input client ID to the objects that were created or updated.
     *         It also returns a map of returned <i>subordinates</i>; where key is <i>reuse</i>
     *         design elements and value is a vector of <i>subordinate</i> design elements. Number
     *         of subordinates returned is governed by the <code>levelsOfSubordinatesToReturn</code>
     *         value specified on input for each <i>reuse</i> design elements. It also returns
     *         <code>ShapeDesign</code> and <code>ShapeDesignRevision</code> pair of objects for
     *         those newly created.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CreateOrUpdateDesignElementsResponse createOrUpdateDesignElements ( const Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CreateOrUpdateDesignElementsInfo&  input ) = 0;

    /**
     * Creates or updates a list of design feature (<b>Cpd0DesignFeature</b>) objects and
     * their relations to the design elements they connect.  Design features are used to
     * represent welds (arc and spot), adhesive beads, etc.   Design features are related
     * to the design elements they connect via a relation (<b>Cpd0ConnectedElement</b>).
     * <br>
     * <br>
     * Using this API, applications can create and update design feature information in
     * bulk, giving better through put that might not otherwise be achieved using standard
     * object create and update API.
     * <br>
     * 
     * <br>
     * <b>Cpd0ConnectedElement</b> relationships have a copy stable ID which is unique within
     * the scope of the design feature.  The copy stable ID can be specified on create;
     * if not specified, they will be automatically generated by Teamcenter.  As their name
     * suggests, when a design feature is copied the connected element relationships are
     * also copied and the copy stable ID of the copied relations remains the same.  The
     * copy stable ID is used by external applications, like CAD, to correlate internal
     * data to the related items.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the design feature authoring use cases.   Design features (welds,
     * etc.) are authored by users in a CAD application (versus being authored in Teamcenter
     * RAC UI).  When the user directs the CAD system to <i>save</i> their session data,
     * the CAD tool will invoke this API to populate or update the design feature information
     * in the Teamcenter database.
     * <br>
     * Note: standard delete API are used to destroy or obsolete design features that are
     * no longer required.
     * <br>
     * Use Case 1: <b>Creation of new design feature </b>
     * <br>
     * <br>
     * The following operation can be used for creating design features (e.g. welds) in
     * a collaborative design.
     * <br>
     * <ul>
     * <li type="disc">Design features are  created always in the context of a collaborative
     * design (Cpd0CollaborativeDesign. Generally, in a production environment, a collaborative
     * design will be created ahead of time by an authorized user using the Collaborative
     * Product Development application in Teamcenter RAC UI. Applications will generally
     * find an existing collaborative design, using the <i>Collaborative Design</i> saved
     * query (provided OOTB in Teamcenter) or through a custom query.
     * </li>
     * <li type="disc">However, for testing purposes, an application may wish to create
     * a collaborative design programmatically. To do this the <code>createObjects</code>
     * operation should be used.
     * </li>
     * <li type="disc">New design features can be created using operation <code>createOrUpdateDesignFeatures</code>.
     * The application specifies the business object type for each new design feature, and
     * sets the collaborative design (found or created previously) as its modelObject. Additional
     * property and connected element information is given and the operation invoked.
     * </li>
     * <li type="disc">Design features have a design feature ID which is unique within the
     * system. Applications can assign their own value using the <code>cpd0design_feature_id</code>
     * property.  If this value is not specified in the input to <code>createOrUpdateDesignFeatures</code>,
     * then Teamcenter will automatically assign an ID when it creates of new design feature.
     * </li>
     * <li type="disc">During the operation, the server creates and saves the new design
     * features in context of the collaborative design. It also creates and saves the relationship
     * between the design features and their connected design elements. The operation returns
     * the new objects to the caller.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use Case 2:<b> Update of existing design feature</b>
     * <br>
     * <br>
     * The following operation can be used for updating existing design features (e.g.
     * welds) in a collaborative design.
     * <br>
     * <ul>
     * <li type="disc">Design features are found by the application through search or by
     * navigating from a design element (<b>Cpd0DesignElement</b>) via the connected element
     * (<b>Cpd0ConnectedElement</b>) relation.  Note: the design feature is always the primary
     * object of the Cpd0ConnectedElement relation and the design element is always the
     * secondary object.
     * </li>
     * <li type="disc">The existing design features can be updated using operation <code>createOrUpdateDesignFeatures</code>.
     * The application specifies which design features are to be updated.  Note: the business
     * object type and collaborative design (<code>modelObject</code>) are not set on the
     * input because they are already know to the design feature and cannot be changed.
     * The application sets changed property values and specifies connected element information
     * for the feature.
     * </li>
     * <li type="disc">During the operation, the server updates and saves the design features
     * and adds or removes <code>Cpd0ConnectedElement</code> relations to be consistent
     * with the input..
     * </li>
     * </ul>
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
     * @param featureInfos
     *        The input list of design feature information describing the features to be created
     *        or updated.
     *
     * @return
     *         The response contains a map of input caller specified client ID values and the corresponding
     *         objects that were created/updated features. The response also contains a map of caller
     *         specified client ID values for (connected element) relations and their corresponding
     *         copy stable ID values. The service data contains a list of added, updated, or deleted
     *         objects and it also contains a list of any errors which occurred within the call.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CreateOrUpdateDesignFeaturesResponse createOrUpdateDesignFeatures ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::DesignFeatureInfo >& featureInfos ) = 0;

    /**
     * This operation is used to create or update workset Subset and Design Subset Elements
     * (<b>Cpd0DesignSubsetElements</b>) in a workset (<b>Cpd0Workset</b>). A Workset acts
     * as a collector of design elements (<b>Cpd0DesignElements</b>) instantiated from one
     * or more Collaborative Designs (<b>Cpd0CollaborativeDesigns</b>). It allows creating
     * local copies of  workset subsets to update. It can contain subsets or item assemblies
     * as its direct children. The subset design element content is precise and Teamcenter
     * does not automatically update it with changes to the source data.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     * <br>
     * The elements to be appended or removed to/from the Workset subset can be either an
     * explicit list of elements or results from a Recipe.
     * <br>
     * <br>
     * When a designelement from a Collaborative Design is realized into a subset in a
     * <br>
     * workset, the same design element is referenced in both the Collaborative Design and
     * <br>
     * the workset. Changes made to this design element in a workset are visible in
     * <br>
     * the Collaborative Design and vice versa.
     * <br>
     * <br>
     * Once workset subset is created using this operation, Realization Service operation
     * like <code>updateWorksetSubsetContent</code> can be used to update workset subset
     * content.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A design subset element is used to represent a subset of collaborative design in
     * a workset. Design elements  may be created by CAD applications or directly in the
     * Teamcenter RAC UI using the Collaborative Product Development application.
     * <br>
     * <br>
     * This API supports the workset authoring use cases. When the user directs the CAD
     * system to <i>save</i> their session data, the CAD tool will invoke this API to populate
     * or update the design subset element information in the Teamcenter database.  Similary
     * RAC will call this API when search results or subset definitions are added to a workset.
     * <br>
     * Note: standard delete API are used to destroy or obsolete design subset elements
     * that are no longer required in the workset revision.
     * <br>
     * <br>
     * Use Case 1:<b> Creation of new design subset elements </b>
     * <br>
     * <br>
     * Pre condition:  Design elements or design features exist in a collaborative design.
     * A workset revision has been created or found in Teamcenter.
     * <br>
     * The following operation can be used for creating design subset elements in a workset.
     * <br>
     * <ul>
     * <li type="disc">Design subset elements are always created in the context of a workset
     * revison (<b>Cpd0WorksetRevision</b>).  Users can create a new workset or open an
     * existing workset in a CAD tool or in the Collaborative Product Development application
     * in the RAC User Interface.
     * </li>
     * <li type="disc">However, for testing purposes, an application may wish to create
     * a workset programmatically.To do this the <code>createObjects</code> operation should
     * be used.
     * </li>
     * <li type="disc">New design subset elements can be created using the createOrUpdateDesignSubsetElements
     * operation. The application specifies a workset revision which will contain the design
     * subset element.Optionally, the application can specify a <b>BOMView</b> type; if
     * none is specified the system will use the default BOM view type.
     * </li>
     * <li type="disc">After the design subset element is created, the application may save
     * a search recipe on the subset using the <code>setRecipes</code> operation.
     * </li>
     * </ul>
     * <br>
     * <br>
     * Use Case 2: <b>Update of existing design subset element </b>
     * <br>
     * <br>
     * The following operation can be used for updating an existing design subset element
     * in a workset
     * <br>
     * <ul>
     * <li type="disc">Design subset elements are found by the application by expanding
     * a workset (see <code>startStructureExpand</code> operation).
     * </li>
     * <li type="disc">Design subset elements can be updated using the <code>createOrUpdateDesignSubsetElements</code>
     * operation.  The application specifies which design subset elements are to be updated.
     * Note: the business object type, workset revision, and BOM view type are not set
     * on the input because they are already known to the design subset element and cannot
     * be changed.
     * </li>
     * <li type="disc">The application sets changed property values.
     * </li>
     * <li type="disc">During the <code>createOrUpdateDesignElements</code> operation, the
     * server updates and saves the design elements along with its auxiliary objects if
     * any.
     * </li>
     * </ul>
     * <br>
     * Note: The search recipe on design subset elements is normally changed using the <code>setRecipes</code>
     * operation. The <code>createOrUpdateDesignElements</code> supports limited recipe
     * modification indirectly by adding lists of design elements for inclusion or exclusion
     * from the current search recipe stored on the design subset element.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateDesignElements, updateWorksetSubsetContent
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param subsetInfos
     *        Data on <code>DesignSubsetElementInfo</code> used to create or update <code>DesignSubsetElements</code>
     *        in a workset.
     *
     * @return
     *         A list of <code>DesignSubsetElementData</code> which is one to one correspondence
     *         with input <code>subsetInfos</code>.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::CreateOrUpdateDesignSubsetElementsResponse createOrUpdateDesignSubsetElements ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::DesignSubsetElementInfo >& subsetInfos ) = 0;

    /**
     * Query, filter, and configure all primary objects attached to the given input set
     * of secondary objects.  Filter criteria are provided through the <code>RelatedObjectInput</code>
     * construct.  Filtering can be based on the type of the relation, the type of the related
     * object, and relation attribute values.  Configuration conditions are specified by
     * a <b>ConfigurationContext</b> object, which provides revision and unit effectivity
     * rule information.
     * <br>
     * Returned objects are configured by the given configuration context and are access
     * checked before being returned. An empty vector of <code>RelatedObjectInput</code>
     * results in an invalid input exception being thrown.
     * <br>
     * <b>RESTRICTION</b>:  Currently this API is only supported for navigation of <b>Mdl0CopyStableRelation</b>
     * and its subtypes.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports configured navigation of relationship. Some applications, such
     * as CAD tools, need to navigate relationships and return results only if they match
     * certain configuration criteria. An example is the navigation from a design element
     * to a design control element.  A design element  may be related to multiple revisions
     * of a design control element, however within a configured view of the system, only
     * one of the design control elements may actually be relevant.  This API helps find
     * the primary object (e.g. <b>Cpd0DesignControlElement</b>) of a relation (e.g. <b>Cpd0ControlModel</b>)
     * given a secondary object (e.g. <b>Cpd0DesignElement</b>).
     * <br>
     * <br>
     * Use Case 1: <b>Navigate to Configured Design Control Elements from Design Element
     * </b>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Perform a configured search to find design elements (<b>Cpd0DesignElement</b>)
     * in a collaborative design
     * </li>
     * <li type="disc">Using operation <code>queryRelatedPrimaryObjects</code> to find the
     * design control elements (<b>Cpd0DesignControlElement</b>) that are related to the
     * found design elements and match the same configuration criteria used to find the
     * design elements.
     * </li>
     * </ul>
     * <br>
     * Use Case 2: <b>Navigate to Configured Design Features from Design Element </b>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Perform a configured search to find design elements (<b>Cpd0DesignElement</b>)
     * in a collaborative design
     * </li>
     * <li type="disc">Using operation queryRelatedPrimaryObjects to find the design features
     * (<b>Cpd0DesignFeature</b>) that are related (via <b>Cpd0ConnectedElement</b>) to
     * the found design elements and match the same configuration criteria used to find
     * the design elements.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param configurationContext
     *        Configuration criteria to apply to the filtered set of related primary objects.
     *        Objects not satisfying the configuration criteria will not be returned.
     *
     * @param inputObjects
     *        A set of secondary objects and the filter criteria.
     *
     * @return
     *         A set of objects that are access checked before being returned. An empty list of
     *         <code>RelatedObjectInput</code> results in an invalid input exception being thrown.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelatedObjectsResponse queryRelatedPrimaryObjects ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext,
        const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelatedObjectInput >& inputObjects ) = 0;

    /**
     * Query, filter, and configure all secondary objects attached to the given input set
     * of primary objects.  Filter criteria are provided through the <code>RelatedObjectInput</code>
     * construct.  Filtering can be based on the type of the relation, the type of the related
     * object, and relation property values. Configuration conditions are specified by a
     * <b>ConfigurationContext</b> object, which provides revision and unit effectivity
     * rule information.
     * <br>
     * Returned objects are configured by the given configuration context and are access
     * checked before being returned. An empty vector of <code>RelatedObjectInput</code>
     * results in an invalid input exception being thrown.
     * <br>
     * <b>RESTRICTION</b>:  Currently this API is only supported for navigation of <b>Mdl0CopyStableRelation</b>
     * and its subtypes.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param configurationContext
     *        Configuration criteria to apply to the filtered set of related secondary objects.
     *        Objects not satisfying the configuration criteria will not be returned.
     *
     * @param inputObjects
     *        A set of primary objects and the filter criteria.
     *
     * @return
     *         A set of objects that are access checked before being returned. An empty list of
     *         <code>RelatedObjectInput</code> results in an invalid input exception being thrown.
     *         <br>
     *         <br>
     *         <b>NOTE</b>:  The input and response for this operation are identical to <code>getRelatedPrimaryObject</code>.
     *         The only difference between the operations is the direction of navigation across
     *         the relationship.  Please see <code>getRelatedPrimaryObject</code> documentation
     *         for a detailed description of <code>RelatedObjectInput</code> and <code>RelatedObjectsResponse</code>.
     *         <br>
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelatedObjectsResponse queryRelatedSecondaryObjects ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext,
        const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::RelatedObjectInput >& inputObjects ) = 0;

    /**
     * Transforms an existing <i>shape</i> or <i>promissory</i> Design Elements (<b>Cpd0DesignElement</b>
     * or its subclasses) to <i>reuse</i> Design Elements (<b>Cpd0DesignElement</b> or its
     * subtypes).This operation doesnt replace the existing Design Element business object
     * reference with a new one rather, changes category to <i>reuse</i>.The business object
     * reference still remains the same. In other words, the object identity (UID) and the<code>
     * cpd0design_element_id</code> property value on Design Element remain the same after
     * the substitution.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: This operation can be used when a <i>promissory</i> Design Element is
     * to be transformed into a <i>reuse</i> Design Element.
     * <br>
     * Use Case 2: This operation can be used when a <i>shape</i> Design Element is to be
     * transformed into a <i>reuse</i> Design Element.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateDesignElements
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
     *        substituteInfos: A vector of <b>ReuseDesignElementInfo</b> structures. Each structure
     *        specifies the Design Element to be substituted. Each would have inputs on Item Revision
     *        to be realized for substitution.
     *
     * @return
     *         <code>SubstituteAsReuseDesignElementResponse</code> contains a map of client id (provided
     *         in input) to the reuse Design Element. It has Service Data with created/updated/deleted
     *         objects along with any partial errors.
     *         <br>
     *         <br>
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::SubstituteAsReuseDesignElementResponse substituteAsReuseDesignElement ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ReuseDesignElementInfo >& substituteInfos ) = 0;

    /**
     * Transforms an existing <i>reuse</i> or <i>promissory</i> design elements ( <b>Cpd0DesignElement</b>
     * or its subtypes) to <i>shape</i> design elements ( <b>Cpd0DesignElement</b> or its
     * subtypes) .Substitute operation doesnt replace the existing design element with a
     * new one. The existing design element gets morphed. The category is changed from <i>reuse</i>
     * (or <i>promissory</i>) to <i>shape</i>. In other words, the object identity (UID)
     * and the cpd0design_element_id property value on Design Element remain the same after
     * the substitution.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: This operation can be used when a <i>promissory</i> Design Element is
     * to be transformed into a <i>shape</i> Design Element.
     * <br>
     * Use Case 2: This operation can be used when a <i>reuse</i> Design Element is to be
     * transformed into a <i>shape</i> Design Element. In this case any of its <i>subordinate</i>
     * Design Elements are discarded as part of the substitution.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateDesignElements
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
     *        A list of <code>ShapeDesignElementInfo</code> structures. Each structure specifies
     *        the Design Element to substitute and also the new shape information for the substitution.
     *
     * @return
     *         SubstituteAsShapeDesignElementResponse contains a map of client id (provided in input)
     *         to the Shape Design Element. It has a map of Shape Design Elements to the corresponding
     *         Shape Design and Shape Design Revision objects. It has Service Data with created/updated/deleted
     *         objects along with any partial errors.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Datamanagement::SubstituteAsShapeDesignElementResponse substituteAsShapeDesignElement ( const std::vector< Cpd0::Services::Cpdcore::_2011_06::Datamanagement::ShapeDesignElementInfo >& substituteInfos ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <cpd0/services/cpdcore/CpdCore_undef.h>
#endif

