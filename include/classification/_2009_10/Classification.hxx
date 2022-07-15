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

#ifndef TEAMCENTER_SERVICES_CLASSIFICATION__2009_10_CLASSIFICATION_HXX
#define TEAMCENTER_SERVICES_CLASSIFICATION__2009_10_CLASSIFICATION_HXX

#include <teamcenter/services/classification/_2007_01/Classification.hxx>
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
            namespace _2009_10
            {
                class Classification;

class TCSOACLASSIFICATIONSTRONGMNGD_API Classification
{
public:

    struct AttributeConfiguration;
    struct AutoComputeAttribute;
    struct AutoComputeAttributesResponse;
    struct FormatProperties;
    struct ClassAttribute2;
    struct ExtendedProeprty;
    struct ExtendedPropertyValues;
    struct GetAttributesForClassesResponse2;
    struct GetKeyLOVsResponse2;
    struct KeyLOVDefinition2;
    struct KeyLOVEntry;

    /**
     * <b>Structure elements:</b>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Primary key - Integer Attribute IDs for attributes. This will be
     * provided as an input.
     * </li>
     * <li type="disc">Values - References an AutoComputeAttribute structure  for the corresponding
     * attribute ID in the primary key of this map.
     * </li>
     * </ul>
     */
    typedef std::map< int, AutoComputeAttribute > AutoComputeAttributesMap;

    /**
     * Map to store Key-LOV definitions details.Any failure will be returned with the Key-LOV
     * ID mapped to the error message in the <code><b>ServiceData</b></code> list of partial
     * errors.
     */
    typedef std::map< std::string, KeyLOVDefinition2 > StrKeyLOVDefMap2;

    /**
     * StrVClsAttrMap2
     */
    typedef std::map< std::string, std::vector< ClassAttribute2 > > StrVClsAttrMap2;

    /**
     * Holds the configuration attached to an attibute
     */
    struct AttributeConfiguration
    {
        /**
         * Preconfiguration attached to the attribute
         */
        std::string preConfig;
        /**
         * Base configuration attached to the attribute.
         */
        std::string config;
        /**
         * Post configuration attached to the attribute.Configurations could be any combinations
         * of the following individual configurations:
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
     * Contains the attributes that are used for the auto compute operation.
     */
    struct AutoComputeAttribute
    {
        /**
         * List of references to the <code><b>ClassificationPropertyValue</b></code> structures
         * that will hold the values (single or multiple values) for the Attribute represented
         * by this <code><b>AutoComputeAttribute</b></code>.
         */
        std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationPropertyValue > values;
        /**
         * Display unit name for this attribute.
         */
        std::string unitName;
        /**
         * Length of an Attribute. This field will hold the number of values for this Attribute.
         * <br>
         * <ul>
         * <li type="disc">For a single valued attribute, length = 1
         * </li>
         * <li type="disc">For an array type of attribute, length = n [where n is the size of
         * the array.]
         * </li>
         * </ul>
         */
        int length;
        /**
         * Represents the Attribute property flags concatenated into a single Integer value.
         * <br>
         * To access  individual flag, a bitwise operation will need to be performed by the
         * Client.
         * <br>
         * Valid values are as specified in the <code><b>enum AutoComputeAttrPropertyFlags</b></code>.
         */
        int attributeProperties;
        /**
         * Flag to indicate whether the attribute referenced by this <code><b>AutoComputerAttribute</b></code>
         * structure is modified by the client. It is only used when <code><b>AutoComputeAttribute</b></code>
         * structure is used as an Input parameter to the <code><b>autoComputeAttributes</b></code>
         * operation. This parameter is should not be used by clients when reading the <code><b>AutoComputeAttribute</b></code>
         * structure as part of the  returned <code><b>AutoComputeAttributesResponse</b></code>.
         */
        bool isModified;
    };

    /**
     * Contains the attribute values for the corresponding autocomputed attributes after
     * the autocompute operation is called. The structure element is a key,value pair of
     * attribute IDs and their corresponding attribute properties. The attribute properties
     * of type AutoComputeAttribute  contains the following information:
     * <br>
     * <ul>
     * <li type="disc">values : This structure element of type ClassificationPropertyValue
     * holds the classification properties for the classification object
     * </li>
     * <li type="disc">length : the number of attributes computed
     * </li>
     * <li type="disc">unitName : the unit of measure for the attribute
     * </li>
     * <li type="disc">attributeProperties : Properties of the attributes
     * </li>
     * <li type="disc">isModified : Boolean value to check if attribute is modified
     * </li>
     * </ul>
     */
    struct AutoComputeAttributesResponse
    {
        /**
         * Map containing references of the <code><b>AutoComputeAttribute</b></code> structures
         * with their respective attribute IDs.
         */
        AutoComputeAttributesMap autoComputedAttrs;
        /**
         * Any failures with classification object ID mapped to the error message in the ServiceData
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure representing Format details
     */
    struct FormatProperties
    {
        /**
         * References the <code><b>AttributeFormat</b></code> structure holding the format definition
         * for this attribute.
         */
        Teamcenter::Services::Classification::_2007_01::Classification::AttributeFormat format;
        /**
         * Unit display name associated with this attribute in this unit system.
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
         * <b>Note:</b> Only applicable to numerical formats of attributes
         */
        std::string minimumValue;
        /**
         * Maximum value contraint of this Class attribute. This can be an empty string indicating
         * no maximum value constraint.
         * <br>
         * <b>Note:</b> Only applicable to numerical formats of attributes
         */
        std::string maximumValue;
    };

    /**
     * Structure representing Class Attribute details
     */
    struct ClassAttribute2
    {
        /**
         * Integer ID for this attribute.
         */
        int id;
        /**
         * Name for this attribute.
         */
        std::string name;
        /**
         * Short name defined for this attribute.
         */
        std::string shortName;
        /**
         * Description added for this attribute.
         */
        std::string description;
        /**
         * References the <code><b>FormatProperties</b></code> structure defining the metric
         * format of this attribute.
         */
        Teamcenter::Services::Classification::_2009_10::Classification::FormatProperties metricFormat;
        /**
         * References the <code><b>FormatProperties</b></code> structure defining the nonmetric
         * format of this attribute.
         */
        Teamcenter::Services::Classification::_2009_10::Classification::FormatProperties nonMetricFormat;
        /**
         * Annotation information added to this attribute.
         */
        std::string annotation;
        /**
         * Reference the <code><b>AttributeConfiguration</b></code> structure that defines any
         * additional configuration for this attribute.
         */
        Teamcenter::Services::Classification::_2009_10::Classification::AttributeConfiguration attributeConfiguration;
        /**
         * Array size or the number of values for this attribute.
         * <br>
         * <ul>
         * <li type="disc">If single valued (nonarray), then <code><b>arraySize</b></code> =
         * 1
         * </li>
         * <li type="disc">If multi valued (array), then <code><b>arraySize</b></code> >= 1
         * corresponding to the size of the array defined in the attribute definition.
         * </li>
         * </ul>
         */
        int arraySize;
        /**
         * Attribute property flags represented as a single integer. To access individual property
         * flags, a bitwise operation will be required by the client.Valid values are:
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
         * <li type="disc">ATTR_localizable         = (1
         * </li>
         * </ul>
         */
        int options;
        /**
         * List of references to the ExtendedProeprty structure holding the extended metadata
         * properties of this attribute.
         */
        std::vector< Teamcenter::Services::Classification::_2009_10::Classification::ExtendedProeprty > extendedProperties;
    };

    /**
     * This Structure will have the Extended metadata name and its coresponding Values
     */
    struct ExtendedProeprty
    {
        /**
         * Name of the extended metadata property associated to the given attribute.
         */
        std::string propertyName;
        /**
         * List of references to the <code><b>ExtendedPropertyValues</b></code> structure holding
         * actual values of the Extended metadata properties.
         */
        std::vector< Teamcenter::Services::Classification::_2009_10::Classification::ExtendedPropertyValues > values;
    };

    /**
     * This structure is used to hold extended metadata property values
     */
    struct ExtendedPropertyValues
    {
        /**
         * Values of the Extended metadata property associated to a Classification Attribute.
         */
        std::string value;
    };

    /**
     * Holds the values returned by <code><b>getAttributesForClass2()</b></code>
     */
    struct GetAttributesForClassesResponse2
    {
        /**
         * Map of Class IDs and the Class attributes found for each of those classes.
         */
        StrVClsAttrMap2 attributes;
        /**
         * Any failure will be returned with Class ID mapped to the error message in the ServiceData
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Holds the keylovs returned by the<code> </code><code><b>getKeyLOVs2()</b></code>
     * method.
     */
    struct GetKeyLOVsResponse2
    {
        /**
         * Map of KeyLOV definitions details.
         */
        StrKeyLOVDefMap2 keyLOVs;
        /**
         * Any failure will be returned with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
         * list of partial errors
         */
        Teamcenter::Soa::Client::ServiceData data;
    };

    /**
     * Structure representing KeyLOVDefinition
     */
    struct KeyLOVDefinition2
    {
        /**
         * Unique Key-LOV ID. This is a negative number.This can be found in the Key/ID field
         * of a Key-LOV definition in the Key-LOV tab of Classification Administration.
         */
        std::string id;
        /**
         * Name of the Key-LOV.
         */
        std::string name;
        /**
         * Unused parameter. Reserved for future use
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  keyLovtag;
        /**
         * Key-LOV options to Show/Hide keys.Valid values are:
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
         * List of Key-LOV entries.
         */
        std::vector< Teamcenter::Services::Classification::_2009_10::Classification::KeyLOVEntry > keyLovEntries;
        /**
         * Owning Site
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  owningSite;
        /**
         * List of sites where this Key-LOV is to be shared using Multisite operations.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sharedSites;
    };

    /**
     * Structure representing KeyLOVEntry
     */
    struct KeyLOVEntry
    {
        /**
         * String representing a Key of a Key-LOV entry.
         */
        std::string lovKey;
        /**
         * String representing a Value  of the Key-LOV  entry.
         */
        std::string lovValue;
        /**
         * Flag indicating whether this particular Key-LOV entry is deprecated or not.
         */
        bool deprecatedSatus;
    };




    /**
     * Computes the attribute values  of classification object based on other attribute
     * values within the same object or an associated classification view. Or the value
     * can be computed based on attribute values of the object being classified. A classification
     * object is also called ICO.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User need to automatically compute classification attribute values for attributes
     * marked as 'AutoComputed'. The values can be computed based on - other attribute values
     * belonging to same classification object or an associated classification view or attribute
     * values of the object being classified.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param icoId
     *        Unique ID of classification objects (ICOs) whose attributes are being computed.
     *
     * @param wso
     *        The workspace object  that is being classified. This input is optional and a NULL
     *        value can be specified. A NULL value indicates that there is no workspace object
     *        associated with classification object corresponding to input icoId
     *
     * @param classId
     *        Unique Id of classification class, in which classification object(ICO) is created/workspace
     *        object is classified.
     *
     * @param viewId
     *        Unique ID of a classification view that is associated to a classification class,
     *        under which input ICO is created/input workspace object is classified.
     *
     * @param inputAttrs
     *        Input attributes map with values and properties along with a flag indicating whether
     *        the attribute value has changed.
     *
     * @param unitSystem
     *        Unit system used to store ICO Properties. This parameter can contain the following
     *        integer values:
     *        <br>
     *        <ul>
     *        <li type="disc">0 = Metric
     *        </li>
     *        <li type="disc">1 = Nonmetric
     *        </li>
     *        </ul>
     *
     * @param mode
     *        The auto compute operation mode. This parameter can contain one of the following
     *        integer values:
     *        <br>
     *        <ul>
     *        <li type="disc">0 - Load mode
     *        </li>
     *        <li type="disc">1 - Create mode
     *        </li>
     *        <li type="disc">2 - Edit mode
     *        </li>
     *        </ul>
     *        <br>
     *        If the mode is specified as load mode, then attribute properties (mandatory, read-only,
     *        unique, propogated or hidden) are computed. Else both the attribute properties &
     *        values are computed
     *
     * @return
     *         Returns an <code><b>AutoComputeAttributesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Auto-computed attributes map in the <code><b>ServiceData</b></code>
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
    virtual Teamcenter::Services::Classification::_2009_10::Classification::AutoComputeAttributesResponse autoComputeAttributes ( const std::string&  icoId,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  wso,
        const std::string&  classId,
        const std::string&  viewId,
        const AutoComputeAttributesMap&  inputAttrs,
        int unitSystem,
        int mode ) = 0;

    /**
     * The operation creates or updates  the key-LOV objects based on the input such as
     * name, id etc., if the input ID matches that of an existing key-LOV, it will be updated.
     * Else new key-LOV object will be created. A key-LOV is a list of values used in classification.
     * The key-LOVs are used to define one or more values that can be set for classification
     * dictionary attributes
     * <br>
     * <br>
     * Typical format of a Key-LOV<b>
     * <br>
     * </b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;key-LOV ID&gt;:&lt;key-LOV Name&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key10&gt;:&lt;Value10&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key20&gt;:&lt;Value20&gt;
     * <br>
     * <br>
     * Example of a Key-LOV:<b>
     * <br>
     * </b>
     * <br>
     * -33381 : Design Categories
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des1 : Bearing
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des2 : Bracket
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des3 : Frame
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des4 : LeadBox
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to create new key-LOVs to be used with classification or need to update
     * the existing ones in classification.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param keyLOVsInput
     *        List of structure that contains information of the key-LOV that needs to be updated
     *        or created.
     *
     * @return
     *         Any failures with KeyLOV ID mapped to the error message are returned in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *
     *
     * @exception ServiceException
     *           Throws <code><b>ServiceException</b></code> (SOA Framework class that holds model
     *           objects and partial errors) when classification system fails to create or update
     *           Key-LOV values for the given Key-LOV ID
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateKeyLOVs ( const std::vector< Teamcenter::Services::Classification::_2009_10::Classification::KeyLOVDefinition2 >& keyLOVsInput ) = 0;

    /**
     * Provides information on class attributes for the classification classes based on
     * input classification class ids. Detailed information about class attributes is provided
     * & includes class attribute name, description, format, unit system, minimum/maximum
     * value, configuration set & extended properties.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user wants to view details of all class attributes associated with a classification
     * class. The method is similar to<b> </b><code><b>getAttributesForClasses()</b></code>
     * method, but provides information in a slightly different format. Also additional
     * information like that on the extended properties of class attributes is provided
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
     *         Returns a <code><b>GetAttributesForClassesResponse2</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Map of input Class IDs and the list of references of Class attributes
     *         retrieved for each of the input Class IDs. This map is added to the <code><b>ServiceData</b></code>
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
     *           <code><b>GetAttributesForClassesResponse2</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2009_10::Classification::GetAttributesForClassesResponse2 getAttributesForClasses2 ( const std::vector< std::string >& classIds ) = 0;

    /**
     * Gets the information for classification key-LOVs  based on given ID(s). Information
     * such as key-LOV's name, display options, owning site, shared sites, deprecation status
     * and key and value entries can be obtained. A key-LOV is a list of values used in
     * classification. The key-LOVs are used to define one or more values that can be set
     * for classification dictionary attributes
     * <br>
     * <br>
     * Typical format of a Key-LOV -
     * <br>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;key-LOV ID&gt;:&lt;key-LOV Name&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key10&gt;:&lt;Value10&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key20&gt;:&lt;Value20&gt;
     * <br>
     * 
     * <br>
     * Example of a KeyLOV:
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
     * <b>Use Cases:</b>
     * <br>
     * User wants to retrieve the information for an existing key-LOV using the key-LOV's
     * unique identifier. This operation is similar to <code><b>getKeyLOVs</b></code><code>()</code>operation,
     * but provides more detailed information about the required key-LOV.
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
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Key-LOV ID
     *           mapped to the error message in the <code><b>ServiceData</b></code> list of partial
     *           errors of <code><b>GetKeyLOVsResponse</b></code> return structure.
     */
    virtual Teamcenter::Services::Classification::_2009_10::Classification::GetKeyLOVsResponse2 getKeyLOVs2 ( const std::vector< std::string >& keyLOVIds ) = 0;


protected:
    virtual ~Classification() {}
};
            }
        }
    }
}

#include <teamcenter/services/classification/Classification_undef.h>
#endif

