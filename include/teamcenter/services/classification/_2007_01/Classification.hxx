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

#ifndef TEAMCENTER_SERVICES_CLASSIFICATION__2007_01_CLASSIFICATION_HXX
#define TEAMCENTER_SERVICES_CLASSIFICATION__2007_01_CLASSIFICATION_HXX

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/classification/Classification_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Classification
        {
            namespace _2007_01
            {
                class Classification;

class TCSOACLASSIFICATIONSTRONGMNGD_API Classification
{
public:

    struct AttributeFormat;
    struct ChildDef;
    struct ClassAttribute;
    struct ClassFlags;
    struct ClassDef;
    struct ClassificationObject;
    struct ClassificationProperty;
    struct ClassificationPropertyValue;
    struct CreateClassificationObjectsResponse;
    struct FindClassificationObjectsResponse;
    struct FindClassifiedObjectsResponse;
    struct GetAttributesForClassesResponse;
    struct GetChildrenResponse;
    struct GetClassDescriptionsResponse;
    struct GetClassificationObjectsResponse;
    struct GetFileIdAttributes;
    struct GetFileIdCriteria;
    struct GetFileIdsResponse;
    struct GetKeyLOVsResponse;
    struct GetParentsResponse;
    struct GetPartFamilyTemplatesResponse;
    struct KeyLOVDefinition;
    struct SearchAttribute;
    struct SearchByInstanceIdResponse;
    struct SearchClassAttributes;
    struct SearchForClassesCriteria;
    struct SearchForClassesResponse;
    struct SearchResponse;
    struct TypedDocument;
    struct UpdateClassificationObjectsResponse;

    /**
     * Enumerates the class attributes available for searching.
     */
    enum ClassSearchAttribute{ CSA_CLASSID,
                 CSA_CLASSNAME,
                 CSA_CLASSTYPE,
                 CSA_SHORTNAME,
                 CSA_GROUPID,
                 CSA_USERDATA1,
                 CSA_USERDATA2,
                 CSA_ATTRID,
                 CSA_ATTRNAME
                 };

    /**
     * Enumerates the sort options available for listing the search results.
     */
    enum ClassSortOption{ CSO_CLASSID,
                 CSO_CLASSNAME,
                 CSO_CLASSTYPE,
                 CSO_SHORTNAME,
                 CSO_GROUPID,
                 CSO_USERDATA1,
                 CSO_USERDATA2,
                 CSO_ATTRID,
                 CSO_ATTRNAME
                 };

    /**
     * <b>UNSPECIFIED</b> - In case of working with Classes, use this option-
     * <br>
     * <ul>
     * <li type="disc">if no unit system is set or
     * </li>
     * <li type="disc">if 'Both' unit system of measure is selected.
     * </li>
     * </ul>
     * <br>
     * In case of working with Classification objects, use this option to-
     * <br>
     * <ul>
     * <li type="disc">if the Class is set with 'Both' unit systems of measure
     * </li>
     * </ul>
     * <br>
     * <b>METRIC</b> - Metric unit system of measure.
     * <br>
     * <b>ENGLISH</b>&nbsp;&nbsp;&nbsp;&nbsp; - Non-metric unit system of measure.
     */
    enum UnitBase{ UNSPECIFIED,
                 METRIC,
                 ENGLISH
                 };

    /**
     * Map of search criteria index and the classes found for each of those searches
     */
    typedef std::map< int, std::vector< ClassDef > > IntClassDefVecMap;

    /**
     * References to map of <b>WorkspaceObject</b> objects and attached <b>Document</b>
     * objects.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject> , std::vector< TypedDocument > > ObjTicketMap;

    /**
     * Map of Class IDs and their respective child Class IDs
     */
    typedef std::map< std::string, ClassDef > StrClsDescMap;

    /**
     * Structure elements:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">primary key - Class IDs.
     * </li>
     * <li type="disc">values - List of the retreived part family template references
     * </li>
     * </ul>
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > > StringPOMRefVecMap;

    /**
     * Structure elements:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">keyLOVs - Map of Key-LOV definitions details.
     * </li>
     * <li type="disc">data&nbsp;&nbsp;&nbsp;&nbsp; - Any failure will be returned with
     * the Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
     * list of partial errors.
     * </li>
     * </ul>
     */
    typedef std::map< std::string, KeyLOVDefinition > StrKeyLOVDefMap;

    /**
     * Map contains a list of parents Class IDs for each of the input Class ID.
     */
    typedef std::map< std::string, std::vector< std::string > > StrParentVecMap;

    /**
     * Structure elements:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">primary key - String representing a key of a Key-LOV entry.
     * </li>
     * <li type="disc">value - String representing a value  of the Key-LOV  entry.
     * </li>
     * </ul>
     */
    typedef std::map< std::string, std::string > StrStrMap;

    /**
     * Maps the query string and the resulting Objects (identified by a tag)
     * <br>
     * <br>
     * Structure elements:
     * <br>
     * <br>
     * <ul>
     * <li type="disc">primary key - Input query string used for this search.
     * </li>
     * <li type="disc">values - References of the objects found for this query string.
     * </li>
     * </ul>
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > StrTagVecMap;

    /**
     * Map of Class IDs and their respective child Class IDs. For every Class ID, there
     * will be a list of Child Class IDs.
     */
    typedef std::map< std::string, std::vector< ChildDef > > StrVChildDefMap;

    /**
     * Contains a list of Child Classes found for the given Classes.
     * <br>
     * <i>
     * <br>
     * </i><b>Structure elements:</b><i>
     * <br>
     * <br>
     * <ul>
     * <li type="disc"></i>Primary key : Alpha-numeric Class ID for which class attributes
     * are being asked for.
     * </li>
     * <li type="disc">Values : List of references to ClassAttribute structures.
     * </li>
     * </ul>
     */
    typedef std::map< std::string, std::vector< ClassAttribute > > StrVClsAttrMap;

    /**
     * Map of Classification Object tag to the details of Classification Object.
     * <br>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Key - Classification Object tag.
     * </li>
     * <li type="disc">Value - ClassificationObject structure representing Classification
     * Object details.
     * </li>
     * </ul>
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , ClassificationObject > TagClsObjMap;

    /**
     * <ul>
     * <li type="disc"><b>primary key :</b> Reference of the classified WorkspaceObject
     * that was used to find the classification objects.
     * </li>
     * <li type="disc"><b>Values :</b> List of Classification object references associated
     * with the classified WorksoaceObject referenced in the primary key
     * </li>
     * </ul>
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > WsoIcoMap;

    /**
     * Structure representing format details of an attribute
     */
    struct AttributeFormat
    {
        /**
         * Integer representing the attribute type, which could be one of the following
         * <br>
         * <ul>
         * <li type="disc">- 1 => KeyLOV
         * </li>
         * <li type="disc">0 => String
         * </li>
         * <li type="disc">1 => Integer
         * </li>
         * <li type="disc">2 => Real
         * </li>
         * <li type="disc">3 => Date
         * </li>
         * <li type="disc">4 => Time range
         * </li>
         * </ul>
         */
        int formatType;
        /**
         * Integer to indicate whether the attribute is configured for one of the following
         * -
         * <br>
         * <ul>
         * <li type="disc">0 - Force positive number
         * </li>
         * <li type="disc">1 - Accept and display either + or -
         * </li>
         * <li type="disc">2 - Accept + or - but display - sign only
         * </li>
         * </ul>
         * <br>
         * <b>Note</b>: This field will return 0 if not applicable. Only applicable if the selected
         * formatType is 1 or 2
         */
        int formatModifier1;
        /**
         * Integer to indicate additional information about the selected formatType from one
         * of the following :
         * <br>
         * If formatType = 0 then:
         * <br>
         * <ul>
         * <li type="disc">0 = Print characters in upper and lower case
         * </li>
         * <li type="disc">1 = Print all characters in upper case
         * </li>
         * <li type="disc">2 = Print all characters in lower case
         * </li>
         * </ul>
         * <br>
         * If formatType = 2 then Number of digits after the decimal point
         * <br>
         * <b>
         * <br>
         * Note:</b> This field will return 0 if not applicable. Only applicable if the selected
         * formatType is 0 or 2
         */
        int formatModifier2;
        /**
         * Integer representing the length of the attribute. In case of a Key-LOV, this will
         * contain the Key-LOV ID.
         */
        int formatLength;
    };

    /**
     * Structure representing Child Definition
     */
    struct ChildDef
    {
        /**
         * Child class ID.
         */
        std::string id;
        /**
         * Type of Class. Valid values are -
         * <br>
         * <ul>
         * <li type="disc">Group         &nbsp;&nbsp;&nbsp;&nbsp;    = (1 << 0)
         * </li>
         * <li type="disc">Class      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    =
         * (1 << 1)
         * </li>
         * <li type="disc">View   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * = (1 << 2)
         * </li>
         * <li type="disc">Storage class &nbsp;&nbsp;&nbsp;&nbsp;= (1 << 4)
         * </li>
         * </ul>
         */
        std::string type;
        /**
         * Name of the child class
         */
        std::string name;
        /**
         * Description of the child class
         */
        std::string description;
        /**
         * Number of children underneath this child class.
         */
        int childCount;
        /**
         * Number of instances of classification objects in this child class and its descendents.
         */
        int instanceCount;
        /**
         * Number of views for this child class.
         */
        int viewCount;
        /**
         * List of references to the <code><b>TypedDocument</b></code> structure containing
         * Documents attached to this child class.
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::TypedDocument > documents;
    };

    /**
     * Contains a list of Child Classes found for the given Classes
     */
    struct ClassAttribute
    {
        /**
         * Integer ID for this attribute
         */
        int id;
        /**
         * Name for this attribute
         */
        std::string name;
        /**
         * Short name defined for this attribute
         */
        std::string shortName;
        /**
         * Annotation information added to this attribute
         */
        std::string annotation;
        /**
         * References the <code><b>FormatProperties</b></code> structure defining the metric
         * format of this attribute.
         */
        Teamcenter::Services::Classification::_2007_01::Classification::AttributeFormat format;
        /**
         * References the FormatProperties structure defining the nonmetric format of this attribute.
         */
        Teamcenter::Services::Classification::_2007_01::Classification::AttributeFormat altFormat;
        /**
         * Unit display name associated with this attribute in this unit system.<b>Note: </b>Only
         * applicable to numerical formats of attributes.
         */
        std::string unitName;
        /**
         * Default value of this Class attribute. This can be an empty string indicating no
         * default value.
         */
        std::string defaultValue;
        /**
         * Minimum value constraint of this Class attribute. This can be an empty string indicating
         * no minimum value constraint.
         * <br>
         * <b>Note</b>: Only applicable to numerical formats of attributes.
         */
        std::string minValue;
        /**
         * Maximum value contraint of this Class attribute. This can be an empty string indicating
         * no maximum value constraint.
         * <br>
         * <b>Note:</b> Only applicable to numerical formats of attributes.
         */
        std::string maxValue;
        /**
         * Description added for this attribute.
         */
        std::string description;
        /**
         * Array size or the number of values for this attribute
         * <br>
         * <ul>
         * <li type="disc">If single valued (non array), then <code><b>arraySize</b></code>
         * = 1
         * </li>
         * <li type="disc">If multi valued (array), then <code><b>arraySize</b></code> >= 1
         * corresponding to the size of the array defined in the attribute definition.
         * </li>
         * </ul>
         */
        int arraySize;
        /**
         * Attribute property flags represented as a single integer.
         * <br>
         * To access individual property flags, a bitwise operations will be required by the
         * client.
         * <br>
         * Valid values are:
         * <br>
         * <ul>
         * <li type="disc">ATTR_vla &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * = (1 << 0)
         * </li>
         * <li type="disc">ATTR_external_vla      = (1 << 1)
         * </li>
         * <li type="disc">ATTR_mandatory&nbsp;&nbsp;&nbsp;&nbsp;     = (1 << 2)
         * </li>
         * <li type="disc">ATTR_protected&nbsp;&nbsp;&nbsp;&nbsp;         = (1 << 3)
         * </li>
         * <li type="disc">ATTR_unique&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * = (1 << 4)
         * </li>
         * <li type="disc">ATTR_propagated&nbsp;&nbsp;&nbsp;&nbsp;     = (1 << 5)
         * </li>
         * <li type="disc">ATTR_localValue&nbsp;&nbsp;&nbsp;&nbsp;         = (1 << 6)
         * </li>
         * <li type="disc">ATTR_reference&nbsp;&nbsp;&nbsp;&nbsp;         = (1 << 7)
         * </li>
         * <li type="disc">ATTR_auto_computed = (1 << 15)
         * </li>
         * <li type="disc">ATTR_hidden&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
         * = (1 << 20)
         * </li>
         * <li type="disc">ATTR_localizable        = (1
         * </li>
         * </ul>
         */
        int options;
        /**
         * Preconfiguration attached to the attribute.
         */
        std::string preConfig;
        /**
         * Base configuration attached to the attribute
         */
        std::string config;
        /**
         * Post configuration attached to the attribute.
         * <br>
         * Configurations could be any combinations of the following individual configurations:
         * <br>
         * <ul>
         * <li type="disc">multifield
         * </li>
         * <li type="disc">horizontal
         * </li>
         * <li type="disc">vertical
         * </li>
         * <li type="disc">separator
         * </li>
         * <li type="disc">arrow
         * </li>
         * <li type="disc">button
         * </li>
         * <li type="disc">wide
         * </li>
         * <li type="disc">mandatory flag
         * </li>
         * <li type="disc">protected flag
         * </li>
         * <li type="disc">unique flag
         * </li>
         * </ul>
         */
        std::string postConfig;
    };

    /**
     * Contains a list of child classes found for the given classes.
     */
    struct ClassFlags
    {
        /**
         * Flag indicates whether the class is abstract.
         * <br>
         * <ul>
         * <li type="disc">TRUE = Abstract class
         * </li>
         * <li type="disc">FALSE = Storage class
         * </li>
         * </ul>
         */
        bool isValid;
        /**
         * Flag indicates whether the class is abstract or not.
         * <br>
         * <ul>
         * <li type="disc">TRUE = Abstract class
         * </li>
         * <li type="disc">FALSE = Storage class
         * </li>
         * </ul>
         */
        bool isAbstract;
        /**
         * Flag indicates wehther the object is a class or group.
         * <br>
         * <ul>
         * <li type="disc">TRUE = Group
         * </li>
         * <li type="disc">FALSE = Class
         * </li>
         * </ul>
         */
        bool isGroup;
        /**
         * Flag indicates whether the class represents an assembly structure.
         */
        bool isAssembly;
    };

    /**
     * Properties of the given class.
     */
    struct ClassDef
    {
        /**
         * Class ID
         */
        std::string id;
        /**
         * Class ID of the parent class.
         */
        std::string parent;
        /**
         * Class name
         */
        std::string name;
        /**
         * Short name
         */
        std::string shortName;
        /**
         * Class description
         */
        std::string description;
        /**
         * Unit system of the class. See enum <code><b>UnitBase</b></code> for list of valid
         * values
         */
        UnitBase unitBase;
        /**
         * Class options as specified in the enum <code><b>ClassFlags</b></code> below
         */
        Teamcenter::Services::Classification::_2007_01::Classification::ClassFlags options;
        /**
         * User data 1 added to this class
         */
        std::string userData1;
        /**
         * User data 2 added to this class
         */
        std::string userData2;
        /**
         * Number of child classes for this class
         */
        int childCount;
        /**
         * Total number of classification objects instantiated in this class or any of its descendents
         */
        int instanceCount;
        /**
         * Number of <code><b>Views</b></code> defined for this class
         */
        int viewCount;
        /**
         * List of attached <code><b>Icons</b></code>, <code><b>Images</b></code> and <code><b>NamedRefs</b></code>
         * to this class
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::TypedDocument > documents;
    };

    /**
     * Structure representing Classification Object details
     */
    struct ClassificationObject
    {
        /**
         * Reference of Classification object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  clsObjTag;
        /**
         * Alphanumeric ID of the Classification object.
         */
        std::string instanceId;
        /**
         * Unique Alphanumeric ID of the Classification class where this object was created.
         */
        std::string classId;
        /**
         * Unit system of measure in which the Classification object is stored in.
         */
        UnitBase unitBase;
        /**
         * Reference of the <b>WorkspaceObject</b> (WSO) that is associated by this Classification
         * object. This can be empty. Allowed WSO types will be defined by the preference '<b>ICS_allowable_types</b>'.
         * <br>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  wsoId;
        /**
         * Array of Classification attributes references that store the properties of this Classification
         * object.
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationProperty > properties;
    };

    /**
     * Structure representing Classification Property which holds attribute ids  and their
     * values
     */
    struct ClassificationProperty
    {
        /**
         * Holds the unique identifier of an attribute.
         */
        int attributeId;
        /**
         * Holds a array of values for this attribute in the context of a Classification object.
         * <br>
         * [Note: An array is required as an attribute can be single or multi-valued.]
         * <br>
         * <br>
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationPropertyValue > values;
    };

    /**
     * Holds the 'DB value' and  an optional 'Display value' of a property
     */
    struct ClassificationPropertyValue
    {
        /**
         * Value of the Classification attribute as stored in the database.
         */
        std::string dbValue;
        /**
         * Value of the Classification attribute as  it should displayed in the client.
         * <br>
         * [ For example, If the attribute is a Key-LOV then the Key is stored as the '<b>dbValue</b>',
         * while the '<b>displayValue</b>' can be configured to be either of the following based
         * on the Key-Value pairs in the Key-LOV definition:
         * <br>
         * <ul>
         * <li type="disc">"<b>Value</b>" only.
         * </li>
         * <li type="disc">Concatenated "<b>Key</b>" and "<b>Value</b>". ]
         * </li>
         * </ul>
         */
        std::string displayValue;
    };

    /**
     * Holds the classification objects returned by the <code><b>getCreateClassificationObjects()</b></code>
     * method.
     */
    struct CreateClassificationObjectsResponse
    {
        /**
         * List of created Classification objects.
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationObject > clsObjs;
        /**
         * Any failure will be returned with Classification object ID mapped to the error message
         * in the ServiceData list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the classfication objects returned by the <code><b>findClassificationObjects()</b></code>
     * method.
     */
    struct FindClassificationObjectsResponse
    {
        /**
         * Map of classified <b>WorkspaceObjects</b> and their associated Classification objects.
         */
        WsoIcoMap icos;
        /**
         * Any failure will be returned with <b>WorkspaceObject</b> ID mapped to the error message
         * in the ServiceData list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the classified objects returned by the  <code><b>getFindClassifiedObjects()</b></code><b>
     * </b>method.
     */
    struct FindClassifiedObjectsResponse
    {
        /**
         * List of classified <b>WorkspaceObjects</b> found for the given list of Classification
         * objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > wsos;
        /**
         * Any failure will be returned with <b>WorkspaceObject</b> ID mapped to the error message
         * in the ServiceData list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Contains a list of Child Classes found for the given Classes
     */
    struct GetAttributesForClassesResponse
    {
        /**
         * Map of Class IDs and the Class attributes found for each of those classes
         */
        StrVClsAttrMap attributes;
        /**
         * Any failure will be returned with Class ID mapped to the error message in the ServiceData
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Contains a list of Child Classes found for the given Classes
     */
    struct GetChildrenResponse
    {
        /**
         * Map of Child classes found for input Class IDs.
         */
        StrVChildDefMap children;
        /**
         * Any failures with Class ID mapped to the error message are returned in the ServiceData
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Contains a list of Child Classes found for the given Classes.
     */
    struct GetClassDescriptionsResponse
    {
        /**
         * Map of Child classes found for input Class IDs.
         */
        StrClsDescMap descriptions;
        /**
         * Internal errors encounterd during the operation are added to the partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the classification object details returned by the <code><b>GetClassificationObjects()</b></code>
     * operation.
     */
    struct GetClassificationObjectsResponse
    {
        /**
         * TagClsObjMap map of input classification object to its details.
         */
        TagClsObjMap clsObjs;
        /**
         * Any failure will be returned with Classification Object ID mapped to the error message
         * in the <code><b>ServiceData</b></code> list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Contains a list of child classes found for the given classes.
     */
    struct GetFileIdAttributes
    {
        /**
         * Name of the relation for attachement.
         */
        std::string relation;
        /**
         * Internal type of the attached <b>Dataset</b> object.
         */
        std::string datasetType;
        /**
         * List of named references.
         */
        std::vector< std::string > namedRefs;
    };

    /**
     * Contains a list of child classes found for a class in the classification hierarchy.
     */
    struct GetFileIdCriteria
    {
        /**
         * List of associated <code><b>WorkspaceObjects</b></code> to execute the search for
         * File IDs.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > wsos;
        /**
         * Reference to the search criterion.
         */
        Teamcenter::Services::Classification::_2007_01::Classification::GetFileIdAttributes criteria;
    };

    /**
     * Contains a list of child classes found for the given classes
     */
    struct GetFileIdsResponse
    {
        /**
         * References to map of <b>WorkspaceObject</b> objects and attached <b>Document</b>
         * objects.
         */
        ObjTicketMap ids;
        /**
         * Internal errors encounterd during the operation are added to the partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the key-LOV returned by the <code><b>getKeyLOVs()</b></code> method.
     */
    struct GetKeyLOVsResponse
    {
        /**
         * Map of Key-LOV definitions details.
         */
        StrKeyLOVDefMap keyLOVs;
        /**
         * Any failure will be returned with the Key-LOV ID mapped to the error message in the
         * <code><b>ServiceData</b></code> list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the parents returned by the <code><b>getParents()</b></code><code> </code>method.
     */
    struct GetParentsResponse
    {
        /**
         * Map contains a list of parents for each of the input Class IDs
         */
        StrParentVecMap parents;
        /**
         * Internal errors encounterd during the operation are added to the partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the PartFamilyTemplates returned by the<b> </b><code><b>getPartFamilyTemplates()</b></code><code>
     * </code>method.
     */
    struct GetPartFamilyTemplatesResponse
    {
        /**
         * Map of part family templates found for input Class IDs.
         */
        StringPOMRefVecMap wsos;
        /**
         * Failures mapped to the error message in the <code><b>ServiceData</b></code> list
         * of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Structure representing KeyLOVDefinition
     */
    struct KeyLOVDefinition
    {
        /**
         * Name of the Key-LOV.
         */
        std::string name;
        /**
         * Key-LOV options to Show/Hide keys.
         * <br>
         * Valid values are
         * <br>
         * <ul>
         * <li type="disc">0 = Show key
         * </li>
         * <li type="disc">1 = Hide key
         * </li>
         * </ul>
         */
        int options;
        /**
         * Map of the Key-Value pairs.
         */
        StrStrMap keyValuePairs;
    };

    /**
     * Structure SearchAttribute holds the attribute id and expression for attribute search
     */
    struct SearchAttribute
    {
        /**
         * Alphanumeric attribute ID of the attribute used in this search.
         */
        int attributeId;
        /**
         * Query expression for this attribute e.g. >= 20.00.
         */
        std::string query;
    };

    /**
     * Holds the Instance identifier returned by the <code><b>getSearchByInstanceId</b></code>()
     * method.
     */
    struct SearchByInstanceIdResponse
    {
        /**
         * Retrieved classification objects.
         */
        StrTagVecMap clsObjTags;
        /**
         * Any failure will be returned with classification object IDs mapped to the error message
         * in the <code><b>ServiceData</b></code> list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * SearchClassAttributes holds classIds and expressions to search class attributes
     */
    struct SearchClassAttributes
    {
        /**
         * List of class IDs to perform search
         */
        std::vector< std::string > classIds;
        /**
         * List of references to the search attributes in these classes.
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::SearchAttribute > searchAttributes;
        /**
         * Unused parameter for this operation.
         */
        int searchOption;
    };

    /**
     * Searches for classes based on the specified class attribute. Also allows sorting
     * the results based on a predefined criterion. Search criteria must be specified and
     * cannot be empty.
     */
    struct SearchForClassesCriteria
    {
        /**
         * Class attribute to be searched for. Valid values are as defined in enum <code><b>ClassSearchAttribute</b></code>.
         */
        ClassSearchAttribute searchAttribute;
        /**
         * Query string to search the class attribute by.
         */
        std::string searchString;
        /**
         * Option to sort the returned results. Valid values are as defined in enum <code><b>ClassSortOption</b></code>.
         */
        ClassSortOption sortOption;
    };

    /**
     * Returns a <code><b>SearchForClassesResponse</b></code> structure containing:
     * <br>
     * <ul>
     * <li type="disc">Retrieved classes in the <code><b>ServiceData</b></code> list of
     * plain objects
     * </li>
     * <li type="disc">Any failures with class ID mapped to the error message in the <code><b>ServiceData</b></code>
     * list of partial errors.
     * </li>
     * </ul>
     */
    struct SearchForClassesResponse
    {
        /**
         * Map of search criteria index and the classes found for each of those searches.
         */
        IntClassDefVecMap classes;
        /**
         * Internal errors encounterd during the operation are added to the partial errors
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * SearchResponse holds the response of search details
     */
    struct SearchResponse
    {
        /**
         * Map of the input query strings and references to the retrieved objects.
         */
        StrTagVecMap clsObjTags;
        /**
         * Any failure will be returned mapped to the error message in the <code><b>ServiceData</b></code>
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Structure holding the attached <b>Icon</b>, <b>Image</b> or <b>NamedRef</b> or this
     * child class.
     */
    struct TypedDocument
    {
        /**
         * Contains type of document attached. Valid values are:
         * <br>
         * <ul>
         * <li type="disc">icon
         * </li>
         * <li type="disc">image
         * </li>
         * <li type="disc">NamedRef
         * </li>
         * </ul>
         */
        std::string documentType;
        /**
         * Ticket identifier for the attached file
         */
        std::string ticket;
        /**
         * File name for this attachment.
         */
        std::string originalFileName;
    };

    /**
     * UpdateClassificationObjectsResponse
     */
    struct UpdateClassificationObjectsResponse
    {
        /**
         * List of updated Classification objects.
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationObject > clsObjs;
        /**
         * Any failure will be returned with Classification object ID mapped to the error message
         * in the <code><b>ServiceData</b></code> list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };




    /**
     * Creates one or more classification objects and (optionally) attach them to a workspace
     * object, thus classifying it. When the Classification objects are not associated with
     * any workspace object, they would act as standalone Classification objects. A classification
     * object is also called ICO
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to classify a workspace object or create a standalone classification object
     * (ICO) in Teamcenter. This operation can be combined with other operations like createItems()
     * to create workspace object and then associate the workspace object to the classification
     * object. Before creating a classification object, a classification class hierarchy
     * should already be created by the classification admin user in Teamcenter. This hierarchy
     * should include a storage class (a class that allows instances to be created and associated
     * to it) for which the classification objects need to be created. Values of any attributes
     * associated with classification objects can also be populated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjs
     *        List of structure containing information about the classification object(ICO) that
     *        needs to be created including its attribute values. It also includes the classification
     *        class information for which classification object will be created & information on
     *        workspace object being classified.
     *
     * @return
     *         Returns a <code><b>CreateClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Created Classification objects in the ServiceData list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the ServiceData list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>CreateClassificationObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::CreateClassificationObjectsResponse createClassificationObjects ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationObject >& clsObjs ) = 0;

    /**
     * Deletes one or more classification objects permanently. A classification object is
     * also called ICO. The classified workspace object associated with the ICO will not
     * be deleted
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to delete classification objects. It is typically called when after creating
     * or searching the classification objects, user decides that the returned objects are
     * not needed anymore
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjTags
     *        Unique Business Object(s) representing the classification object(s) to be deleted.
     *
     * @return
     *         Returns a <code><b>DeleteClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Deleted classified WorkspaceObjects in the ServiceData list of plain
     *         objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the ServiceData list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code>ServiceData</code> list of partial
     *           errors in the returned <code><b>DeletedClassificationObjectsResponse</b></code> structure.
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteClassificationObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& clsObjTags ) = 0;

    /**
     * Finds the classification objects associated with input workspace objects (WSO). A
     * classification object is also called ICO. Each workspace object can have one or more
     * ICOs associated with it.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need to find classification objects (ICO) based on workspace objects. Each
     * time a workspace object is classified in a classification class a classification
     * object (ICO) object is created.  After searching for all the classification objects
     * corresponding to a workspace object, user can find more information about the classification(s)
     * of a workspace object. The operation <code><b>getClassificationObjects()</b></code><code>
     * </code>can be used to get detailed information about the classification objects.
     * After getting information on classification objects, user can also choose to modify
     * or delete those using operation <code><b>updateClassificationObjects()</b></code>
     * or <code><b>deleteClassificationObjects()</b></code>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param wsoIds
     *        List of identifiers for classified workspace objects(WSO), for which the associated
     *        classification objects(ICO) are required.
     *
     * @return
     *         Returns a <code><b>CreateClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Created Classification objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>CreateClassificationObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::FindClassificationObjectsResponse findClassificationObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  >& wsoIds ) = 0;

    /**
     * Finds the workspace objects (WSO) associated with input Teamcenter classification
     * objects. A classification object is also called ICO. Each ICO can have only one workspace
     * object associated with it.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need to find workspace objects based on classification objects (ICO) that
     * were created when workspace objects were classified.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param icoTags
     *        List of classification object (ICO) Business Objects, whose corresponding   workspace
     *        objects need to be found
     *
     * @return
     *         Returns a <code><b>FindClassifiedObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classified <code><b>WorkspaceObjects</b></code> in the
     *         <code><b>ServiceData</b></code> list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>FindClassifiedObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::FindClassifiedObjectsResponse findClassifiedObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& icoTags ) = 0;

    /**
     * Provides information on class attributes for the classification classes based on
     * input classification class ids. Detailed information about class attributes is provided
     * & includes class attribute name, description, format, unit system, minimum/maximum
     * value & configuration set
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user wants to view details of all class attributes associated with a classification
     * class. This operation is similar to getAttributesForClasses2(), but provides information
     * in a slightly different format. Typically, the information about class attributes
     * is used to determine which classification class a workspace object shall be classified
     * into
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param classIds
     *        Identifier for the classification class whose attribute information is requested.
     *
     * @return
     *         Returns a <code><b>GetAttributesForClassesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Map of input Class IDs and the list of references of Class attribute
     *         retrieved for each of the input Class IDs in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of the returned
     *           <code><b>GetAttributesForClassesResponse</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetAttributesForClassesResponse getAttributesForClasses ( const std::vector< std::string >& classIds ) = 0;

    /**
     * Gets the information about immediate children in classification hierarchy for given
     * group or class identifier(s).
     * <br>
     * Returns a <code><b>GetChildrenResponse</b></code> structure containing:
     * <br>
     * <ul>
     * <li type="disc">Retrieved child classes in the <code><b>ServiceData</b></code> list
     * of plain objects
     * </li>
     * <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     * list of partial errors.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to get details of all groups or classes that lie under a particular group
     * or class in a classification class hierarchy.
     * <br>
     * <br>
     * Returns a <code><b>GetChildrenResponse</b></code> structure containing:
     * <br>
     * <ul>
     * <li type="disc">Retrieved child classes in the <code><b>ServiceData</b></code> list
     * of plain objects
     * </li>
     * <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     * list of partial errors.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param groupOrClassIds
     *        Unique ID(s) of the classification class or group whose immediate children need to
     *        be determined in the classification class hierarchy
     *
     * @return
     *         <br>
     *         Returns a <code><b>GetChildrenResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved child classes in the <code><b>ServiceData</b></code> list
     *         of plain objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of the returned
     *           <code><b>GetChildrenResponse</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetChildrenResponse getChildren ( const std::vector< std::string >& groupOrClassIds ) = 0;

    /**
     * Gets detailed information about a classification class based on classification class
     * ID. This information includes class type, parent, name, description, unit system
     * and user data associated with the class.  It also includes a count of children, number
     * of classification views & number of instances of classification objects associated
     * with the classification class. Information can also be obtained on any documents
     * such as images & icons attached to the classification class.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need details of classification classes. These details can help user decide
     * whether to classify a workspace object in particular classification classes.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param classIds
     *        List of unique identifiers for classification classes whose details are needed.
     *
     * @return
     *         Returns a <code><b>GetClassDescriptionsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Class objects in the <code><b>ServiceData</b></code> list of plain
     *         objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetClassDescriptionsResponse getClassDescriptions ( const std::vector< std::string >& classIds ) = 0;

    /**
     * Looks for specified classification objects. If they are found, then detailed information
     * about those objects is provided. A classification object is also called ICO
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need to find an existing classification object to either view or update
     * its details. It can be followed by operations like <code><b>updateClassificationObjects()</b></code>
     * or <code><b>deleteClassificationObjects()</b></code> to update or delete the classification
     * objects.
     * <br>
     * The operation <code><b>findClassificationObjects()</b></code> can be used to get
     * the list of classification objects, associated with workspace objects. Then, this
     * operation <code><b>getClassificationObjects()</b></code> is used to get the detailed
     * information on the classification objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjTags
     *        The classification object(s) for which detailed information is required.
     *
     * @return
     *         Returns a <code><b>GetClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Map of Classificaiton Object tag to its details.
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>GetClassificationObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetClassificationObjectsResponse getClassificationObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& clsObjTags ) = 0;

    /**
     * Gets the file information from any dataset that is associated with workspace object(s).
     * The dataset type can be specified along with the relation used when it is attached
     * to a workspace object. Information corresponding to a particular file inside a dataset
     * can be retrieved.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to get information about files inside a dataset that is associated with
     * workspace objects (WSO). Typically it will be used to get and view the  image or
     * icon files associated with datasets attached to workspace objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param criteria
     *        List of structures containing information on the workspace objects (WSO) to which
     *        the datasets are attached, the type of datasets, relation in which dataset is attached
     *        to the WSO, and the named reference inside the dataset. All this information can
     *        be used to get to a particular file inside a dataset
     *
     * @return
     *         Returns a <code><b>GetFileIDsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved Key-LOV objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetFileIdsResponse getFileIds ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::GetFileIdCriteria >& criteria ) = 0;

    /**
     * Gets the information for classification key-LOVs  based on given ID(s). Information
     * such as key-LOV's name, display options, and key and value entries can be obtained.
     * A key-LOV is a list of values used in classification. The key-LOVs are used to define
     * one or more values that can be set for classification dictionary attributes
     * <br>
     * <br>
     * Typical format of a key-LOV -
     * <br>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;key-LOV ID&gt;:&lt;key-LOV Name&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key10&gt;:&lt;Value10&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key20&gt;:&lt;Value20&gt;
     * <br>
     * <br>
     * Example of a key-LOV
     * <br>
     * <br>
     * - 33381:Design Categories
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des1:Bearing
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des2:Bracket
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des3:Frame
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des4:LeadBox
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to retrieve the information for an existing key-LOV using the key-LOV's
     * unique identifier. The operation is similar to <code><b>getKeyLOVs2</b></code>().
     * But <code><b>getKeyLOVs2</b></code>()provides more detailed information about any
     * key-LOVs .
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param keyLOVIds
     *        List of IDs of classification key-LOV, for which information is required. The key-LOV
     *        ID is a unique negative integer that identifies a key-LOV. In the Teamcenter rich
     *        client, key-LOVs can be accessed in the "Key LOVs" tab of the Classification Administration
     *        application. The key-LOV ID can be found in the "Key/ID" field of a key-LOV definition
     *        there.
     *
     * @return
     *         Returns a <code><b>GetKeyLOVsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved KeyLOV objects in the <code><b>ServiceData</b></code> list
     *         of plain objects
     *         </li>
     *         <li type="disc">Any failures with the KeyLOV ID are mapped to the error message in
     *         the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception. In all other cases failures will be returned with the Key-LOV
     *           ID mapped to the error message in the <code><b>ServiceData</b></code> list of partial
     *           errors of the <code><b>GetKeyLOVsResponse</b></code> return structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetKeyLOVsResponse getKeyLOVs ( const std::vector< std::string >& keyLOVIds ) = 0;

    /**
     * Gets the classification class ID(s) of all parent classes in a hierarchy, based on
     * given classification class ID. The parent class IDs are sorted as immediate parent
     * first, toplevel parent last.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to determine all the parent classes for any given class in a classification
     * hierarchy.  If user needs to get the children of the given class ID, then <code><b>getChildren</b></code>()
     * operation shall be used.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param childIds
     *        The unique identifier IDs for classification classes for which parent class ID information
     *        is being requested
     *
     * @return
     *         Returns a <code><b>GetParentsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved list of parent IDs in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of <code><b>GetParentsResponse</b></code>
     *           return structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetParentsResponse getParents ( const std::vector< std::string >& childIds ) = 0;

    /**
     * Finds the information for part family templates (PFT) based on the classification
     * class IDs. Part family templates can be used to define geometry and certain properties
     * of the geometry as variable properties. They can be attached to a classification
     * class. For any classification class, user can find out the associated part family
     * templates and their information.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * While using graphics builder, users often require information about the part family
     * template attached to the classification classes.  Graphics builder is a program used
     * by classification administration that communicates with the Teamcenter server to
     * generate graphics. The graphics builder uses NX libraries.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsClassIds
     *        List of IDs of classification classes for which the associated part family template
     *        information is required.
     *
     * @return
     *         Returns a <code><b>GetPartFamilyTemplatesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Returns the Part family templates assigned to classification class
     *         references in the <code><b>ServiceData</b></code> list of plain objects
     *         </li>
     *         <li type="disc">Any failures with class references mapped to the error message in
     *         the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetPartFamilyTemplatesResponse getPartFamilyTemplates ( const std::vector< std::string >& clsClassIds ) = 0;

    /**
     * Finds all the classification objects based on classification class IDs, classification
     * attribute ID and an expression for classification attribute value. A classification
     * object is also called an ICO.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to search for classification objects based on the class where they are
     * classified and the value of classification attributes.Another related operation for
     * searching classification objects is <code><b>searchByInstanceID</b></code>(), that
     * can search for classification objects based on their IDs
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param searchCriteria
     *        List of structures containing classification class ID, classification attribute ID,
     *        and an expression for classification attribute value (e.g. >= 20.00 ).
     *
     * @return
     *         Returns a <code><b>SearchResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classification objects (ICO) in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation throws a <code><b>ServiceException</b></code> in case of an error
     *           condition. Clients should  then retrieve the errors from the <code><b>ServiceData</b></code>
     *           list of partial errors in the returned <code><b>SearchResponse</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::SearchResponse search ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::SearchClassAttributes >& searchCriteria ) = 0;

    /**
     * Finds all the classification objects based on their IDs. A classification object
     * is also called an ICO. If the ICO classifies a workspace object, then ICO ID would
     * be same as the workspace object ID
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to search for classification objects based on their IDs. The returned
     * objects can then be used as input for operations like <code><b>findClassifiedObjects</b></code>(),
     * which is used to search workspace objects associated with the ICOs.
     * <br>
     * Another related operation for searching classification objects is <code><b>search</b></code>(),
     * that can search for classification objects based on class ID and attribute values
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param instanceIdQueries
     *        List of IDs of classification objects. These can contain wildcards ( e.g. ICO00*
     *        ).
     *
     * @return
     *         Returns a <code><b>SearchByInstanceIdResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classification objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::SearchByInstanceIdResponse searchByInstanceId ( const std::vector< std::string >& instanceIdQueries ) = 0;

    /**
     * Finds the classification classes based on provided search criteria and provides detailed
     * information about those classes.  The user can search using a search expression on
     * attributes of the class (Class ID, Name, Type etc.)  . For example, the user shall
     * be able to search all the classes whose name begins with a particular set of characters
     * and where the class ID matches certain pattern. The order of search results can also
     * be sorted on various criteria.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user needs to search for classification classes using a search criterion based
     * on various attributes of a class. The search criterion can be based on one or more
     * attributes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param criteria
     *        List of structure containing search expression, search attributes, and sort options
     *        for search results
     *
     * @return
     *         Returns a <code><b>SearchForClassesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classes in the <code><b>ServiceData</b></code> list of
     *         plain objects
     *         </li>
     *         <li type="disc">Any failures with class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::SearchForClassesResponse searchForClasses ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::SearchForClassesCriteria >& criteria ) = 0;

    /**
     * Updates existing classification objects. A classification object is also called ICO.
     * Values of various ICO attributes can be modified
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to update values of the attributes for an existing classification object
     * in Teamcenter. E.g. user wants to modify an integer value of a class attribute ("Length")
     * for an existing ICO. This operation is typically used after creating the classification
     * objects using <code><b>createClassificationObjects</b></code>().
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjs
     *        List of structures containing information about classification objects that needs
     *        to be modified,  along with the information that needs to be updated
     *
     * @return
     *         Returns a <code><b>UpdateClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Updated Classification objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::UpdateClassificationObjectsResponse updateClassificationObjects ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationObject >& clsObjs ) = 0;


protected:
    virtual ~Classification() {}
};
            }
        }
    }
}

#include <teamcenter/services/classification/Classification_undef.h>
#endif

