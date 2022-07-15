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

#ifndef TEAMCENTER_SERVICES_CLASSIFICATION__2011_12_CLASSIFICATION_HXX
#define TEAMCENTER_SERVICES_CLASSIFICATION__2011_12_CLASSIFICATION_HXX

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
            namespace _2011_12
            {
                class Classification;

class TCSOACLASSIFICATIONSTRONGMNGD_API Classification
{
public:

    struct AttrDescriptor;
    struct AttributeValues;
    struct ClassAttrDescriptor;
    struct ClassAttrInfo;
    struct ClassificationInfoResponse;
    struct ExtendedProperties;
    struct Value;

    /**
     * Enumerates the list of value for class unit system.
     */
    enum ClassUnitBase{ CLS_METRIC,
                 CLS_NONMETRIC,
                 CLS_BOTH
                 };

    /**
     * Contains descriptor of an attribute.
     */
    typedef std::map< int, ClassAttrDescriptor > AttributeDescriptorMap;

    /**
     * Contains attriute Id and corresponding value(s).
     * <br>
     * <br>
     * <b>Structure elements:</b>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">primary key - Attribute ID.
     * </li>
     * <li type="disc">values - Value structure for this attribute.
     * </li>
     * </ul>
     */
    typedef std::map< int, AttributeValues > AttributeValuesMap;

    /**
     * Contains class Id and corresponding attribute descriptor.
     */
    typedef std::map< std::string, AttrDescriptor > ClassAttributeDescMap;

    /**
     * Contains classification object information.
     * <br>
     * <br>
     * <b>Structure elements:</b>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">primary key - Classification object (ICO) ID.
     * </li>
     * <li type="disc">values - Reference of the structure containing additional ICO properties
     * </li>
     * </ul>
     */
    typedef std::map< std::string, ClassAttrInfo > ClassificationObjectInfoMap;

    /**
     * Structure containing map of class attribute descriptors.
     */
    struct AttrDescriptor
    {
        /**
         * Map of attribute descriptors.
         */
        AttributeDescriptorMap attrDescMap;
    };

    /**
     * Contains values for ico attributes and boolean to check whether attribute is valid.
     */
    struct AttributeValues
    {
        /**
         * Flag to indicate whethe the attribute is valid
         */
        bool isAttrValid;
        /**
         * List of values for this attribute
         */
        std::vector< Teamcenter::Services::Classification::_2011_12::Classification::Value > values;
    };

    /**
     * Structure representing Class attribute description.
     */
    struct ClassAttrDescriptor
    {
        /**
         * An attribute id.
         */
        int id;
        /**
         * An attribute name.
         */
        std::string name;
        /**
         * An attribute shortName.
         */
        std::string shortName;
        /**
         * An attribute description.
         */
        std::string description;
        /**
         * An attribute annotation.
         */
        std::string annotation;
        /**
         * An attribute array size.
         */
        int arraySize;
        /**
         * An attribute options.
         */
        int options;
        /**
         * An attribute metric format.
         */
        int metricFormat;
        /**
         * An attribute metric unit.
         */
        std::string metricUnit;
        /**
         * An attribute metric default value.
         */
        std::string metricDefaultValue;
        /**
         * An attribute metric min value.
         */
        std::string metricMinValue;
        /**
         * An attribute metric max value.
         */
        std::string metricMaxValue;
        /**
         * An attribute non metric format.
         */
        int nonMetricFormat;
        /**
         * An attribute non metric unit.
         */
        std::string nonMetricUnit;
        /**
         * An attribute non metric default value.
         */
        std::string nonMetricDefaultValue;
        /**
         * An attribute non metric min value.
         */
        std::string nonMetricMinValue;
        /**
         * An attribute non metric max value.
         */
        std::string nonMetricMaxValue;
        /**
         * Extended properties.
         */
        std::vector< Teamcenter::Services::Classification::_2011_12::Classification::ExtendedProperties > extendedProps;
    };

    /**
     * Structure containing classification object information.
     */
    struct ClassAttrInfo
    {
        /**
         * Classification class Id.
         */
        std::string cid;
        /**
         * Class attributes map
         */
        AttributeValuesMap attrValuesMap;
        /**
         * Class unit system of measure.
         */
        ClassUnitBase unitBase;
        /**
         * Reference of the classified <code><b>WorkspaceObject</b></code> object. This can
         * be a NULLTAG if it is a standalone ICO.
         */
        std::string icoId;
        /**
         * The tag of classifying WSO.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  wsoTag;
    };

    /**
     * Contains classification objects info returned by getClassificationObjectInfo() method.
     */
    struct ClassificationInfoResponse
    {
        /**
         * Map of classification objects and list of references to their class attributes.
         */
        ClassificationObjectInfoMap classificationObjectInfo;
        /**
         * Map of classification objects and list of references to their attribute descriptors.
         */
        ClassAttributeDescMap classAttributeDesc;
        /**
         * Any failures with classification object ID mapped to the error message in the <code><b>ServiceData</b></code>
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData svcData;
    };

    /**
     * Extended metadata properties for an attribute.
     */
    struct ExtendedProperties
    {
        /**
         * An extended prop name.
         */
        std::string propName;
        /**
         * Extended prop values.
         */
        std::vector< std::string > propValue;
    };

    /**
     * structure for each ico attribute value.
     */
    struct Value
    {
        /**
         * Value of the attribute
         */
        std::string attrValue;
        /**
         * Unit of the attribute.
         */
        std::string unit;
        /**
         * Locale for this attribute.
         */
        std::string locale;
    };




    /**
     * Provides detailed information on classification objects based on their unique identifiers
     * (UID). A classification object is also called an ICO
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user needs to get details of a classification object (ICO).  These details include
     * the classification class to which ICO belongs, the unit system, ICO ID, various ICO
     * attributes and their values and property descriptor for these attributes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param icoUids
     *        Unique IDs of classification objects whose details are required
     *
     * @param attributeIds
     *        Unique Identifiers of classification attribute associated with input classification
     *        object,  whose values are to be fetched
     *
     * @param getOptimizedValues
     *        Boolean flag to get optimized classification attribute values. When Teamcenter optimizes
     *        an attribute value, it provides the most readable value with the least number of
     *        leading or trailing zeros. For example, 1 km is easier to read than 1000 m
     *
     * @param fetchDescriptor
     *        Boolean flag to indicate whether  property descriptor for each of class attributes
     *        is to be fetched
     *
     * @param locale
     *        Locale in which classification objects attribute  values and properties descriptor
     *        are to be fetched.
     *
     * @return
     *         Returns a <code><b>ClassificationInfoResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classification objects and class attributes in the <code><b>ServiceData</b></code>
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
    virtual Teamcenter::Services::Classification::_2011_12::Classification::ClassificationInfoResponse getClassificationObjectInfo ( const std::vector< std::string >& icoUids,
        const std::vector< int >& attributeIds,
        bool getOptimizedValues,
        bool fetchDescriptor,
        const std::string&  locale ) = 0;


protected:
    virtual ~Classification() {}
};
            }
        }
    }
}

#include <teamcenter/services/classification/Classification_undef.h>
#endif

