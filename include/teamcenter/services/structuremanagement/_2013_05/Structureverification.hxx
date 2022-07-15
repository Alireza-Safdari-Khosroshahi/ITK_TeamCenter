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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2013_05_STRUCTUREVERIFICATION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2013_05_STRUCTUREVERIFICATION_HXX

#include <teamcenter/services/structuremanagement/_2012_02/Structureverification.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2013_05
            {
                class Structureverification;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structureverification
{
public:

    struct AttributeDetailElement;
    struct AttributeGroupAndFormComparisonResponse;
    struct AttributeGroupAndFormDetail;
    struct AttributeGroupsDetailElement;
    struct BusinessObjectVec;
    struct ConnectedObjectsComparisonResponse;
    struct ConnectedObjectsDetail;
    struct ConnectedObjectsDetailElement;

    /**
     * Comparison result of an attribute in an Attribute Group.
     */
    struct AttributeDetailElement
    {
        /**
         * Corresponding attribute names for each member  of the equivalentObjects vector. The
         * size of this vector matches the size of equivalentObjects vector and it has corresponding
         * indices.
         */
        std::vector< std::string > attributeNames;
        /**
         * False if the property value is equal in the source and target, otherwise true.
         */
        bool isDifferent;
    };

    /**
     * For each supplied attribute group the operation returns the list of its attributes,
     * the attributes' values for each supplied source and target, and the result of comparing
     * each attribute on all supplied sources and targets.
     */
    struct AttributeGroupAndFormComparisonResponse
    {
        /**
         * Contains the property values for each property in each attribute group for each supplied
         * equivalent set and any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of attribute groups information elements - one for each input equivalent set.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::AttributeGroupAndFormDetail > attributeGroupAndFormDetails;
    };

    /**
     * Attribute groups details of an equivalent set of objects.
     */
    struct AttributeGroupAndFormDetail
    {
        /**
         * Index of equivalent set in the input vector for which these details were calculated.
         */
        int index;
        /**
         * The list of all equivalent business objects in the input equivalent set (all equivalent
         * sources in sequence and then all targets in sequence).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > equivalentObjects;
        /**
         * Attribute groups details of this equivalent set. Each element in the list represents
         * one attribute group.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::AttributeGroupsDetailElement > attributeGroupDetailElements;
    };

    /**
     * Comparison results of an Attribute Group.
     */
    struct AttributeGroupsDetailElement
    {
        /**
         * The name of this attribute group.
         */
        std::string attributeGroupName;
        /**
         * True if any of the properties in this attribute group are different, otherwise false.
         */
        bool isDifferent;
        /**
         * Corresponding attribute groups and forms objects for each member of the equivalentObjects
         * vector.   The size of this vector matches the size of equivalentObjects vector and
         * it has corresponding indices.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > attrGroupsAndForms;
        /**
         * The list of details for each mapped property in the attribute group.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::AttributeDetailElement > attributeDetails;
    };

    /**
     * Vector of business objects.
     */
    struct BusinessObjectVec
    {
        /**
         * Vector of business objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > businessObjects;
    };

    /**
     * For each input set of equivalent objects a vector of comparison results of their
     * connected elements (can be full match, partial match, or multiple match) and for
     * each object in the set a detailed connected elements breakdown.
     */
    struct ConnectedObjectsComparisonResponse
    {
        /**
         * Object that captures any partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of connected objects information elements - one for each input equivalent set.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::ConnectedObjectsDetail > connectedObjectsDetails;
    };

    /**
     * Comparison results of connected elements of an equivalent set of objects (can be
     * full match, partial match, or multiple match) and for each object in the set a detailed
     * connected elements breakdown.
     */
    struct ConnectedObjectsDetail
    {
        /**
         * The index of equivalent set in the input list for which these details were calculated.
         */
        int index;
        /**
         * A list of the comparison results (0 means full match, 1 means partial match, 2 means
         * multiple match) of all rows of the output table. Each vector element is the result
         * of comparing one equivalent group of connected objects (one row in the table).
         */
        std::vector< int > matchResults;
        /**
         * A list of input equivalent object and its detailed set of connected elements. This
         * vector contains the whole ouput results table, where each vector element represents
         * a column in the table.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::ConnectedObjectsDetailElement > connectedObjectsDetails;
    };

    /**
     * Contains connected objects of the equivalentObject.
     */
    struct ConnectedObjectsDetailElement
    {
        /**
         * The input equivalent object for which these details are defined.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  equivalentObject;
        /**
         * The set of connected objects for this input object. The outer vector is  insync with
         * the index of the matchResults, each element representing one cell in the output table,
         * and the inner vector will be the group of connected elements that are equivalent
         * to each other (if there are no equivalent elements in this group at all the inner
         * vector will be empty). Each inner list will have only one element, and all equivalent
         * elements will be put in separate inner list.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::BusinessObjectVec > connectedObjects;
    };




    /**
     * This operation returns the details of differences between the supplied Attribute
     * Groups for the supplied equivalent objects (that can be Cpd0DesignElement, Cpd0DesignFeature,
     * or BOMLine objects). For each supplied attribute group the operation returns the
     * list of its attributes, the attributes values for each supplied source and target,
     * and the result of comparing each attribute on all supplied sources and targets.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        The list ofCpd0DesignElement, Cpd0DesignFeature or BOMLine objects that  were deemed
     *        equivalent by some method, for which any differences in attribute groups is required.
     *
     * @param attributeGroupsNames
     *        The list of attribute groups names that need to be compared.
     *
     * @return
     *         For each supplied attribute group the operation returns the list of its attributes,
     *         the attributes' values for each supplied source and target, and the result of comparing
     *         each attribute on all supplied sources and targets. The following partial errors
     *         may be returned: - 253049 The input equivalent set doesn't contain any sources or
     *         any targets. - 253001 This error can only be returned if there is some kind of environment
     *         issue or a bug in the code, it will never happen during normal execution.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::AttributeGroupAndFormComparisonResponse getAttributeGroupsAndFormsComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects,
        const std::vector< std::string >& attributeGroupsNames ) = 0;

    /**
     * This operation returns the details of any differences between connected objects (that
     * can be either BOMLines or Cpd0DesignElements) for the supplied equivalent objects
     * (that can be either BOMLines or Cpd0DesignFeatures). The operation takes the source
     * and target and compares their connected objects. The source and target connected
     * objects are returned by this operation in the form of a table that is created by
     * the output structures.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param equivalentObjects
     *        The list of BOMLines or Cpd0DesignFeatures that were deemed  equivalent  by some
     *        method, for which any differences in connected objects are required.
     *
     * @return
     *         For each input set of equivalent objects a list of comparison results of their connected
     *         elements (can be full match, partial match, or multiple match) and for each object
     *         in the set a detailed connected elements breakdown. The following partial errors
     *         may be returned:  - 253049 The input equivalent set doesn't contain any sources or
     *         any targets. -  253001 This error can only be returned if there is some kind of environment
     *         issue or a bug in    the code, it will never happen during normal execution.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2013_05::Structureverification::ConnectedObjectsComparisonResponse getConnectedObjectsComparisonDetails ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Structureverification::EquivalentLines >& equivalentObjects ) = 0;


protected:
    virtual ~Structureverification() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

