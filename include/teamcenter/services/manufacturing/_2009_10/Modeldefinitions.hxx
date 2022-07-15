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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2009_10_MODELDEFINITIONS_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2009_10_MODELDEFINITIONS_HXX

#include <teamcenter/soa/client/model/ListOfValues.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2009_10
            {
                class Modeldefinitions;

class TCSOAMANUFACTURINGSTRONGMNGD_API Modeldefinitions
{
public:

    struct AttachedPropDescsResponse;
    struct GetValidRelationTypesResponse;
    struct PropDesc;
    struct PropDescInfo;
    struct PropDescOutput;
    struct RelationTypeInfo;
    struct RelationTypesInput;
    struct RelationTypesOutput;

    /**
     * InputTypeNameToPropDescOutputMap
     */
    typedef std::map< std::string, std::vector< PropDescOutput > > InputTypeNameToPropDescOutputMap;

    /**
     * Attached Property Descriptors Response
     */
    struct AttachedPropDescsResponse
    {
        /**
         * Map of input type name to PropertyDescriptor
         */
        InputTypeNameToPropDescOutputMap inputTypeNameToPropDescOutput;
        /**
         * ServiceData which has output tags as plain objects and errors in partialError
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response of the getValidRelationTypes SOA.
     */
    struct GetValidRelationTypesResponse
    {
        /**
         * Array of relation types results
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::RelationTypesOutput > relationTypesResults;
        /**
         * Exceptions from internal processing returned as PartialErrors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The PropDesc struct describes information about the Teamcenter property
     */
    struct PropDesc
    {
        /**
         * Name of the property
         */
        std::string propName;
        /**
         * Display name of the property
         */
        std::string displayName;
        /**
         * Default value for the property
         */
        std::string defaultValue;
        /**
         * Value type for the property, PROP_untyped (0) No Value type PROP_char (1) Value is
         * a single character PROP_date (2) Value is a date PROP_double (3) Value is a double
         * PROP_float (4) Value is a float PROP_int (5) Value is an integer PROP_logical (6)
         * Value is a logical PROP_short (7) Value is a short PROP_string (8) Value is a character
         * string PROP_typed_reference (9) Value is a typed reference PROP_untyped_reference
         * (10) Value is an untyped reference PROP_external_reference (11) Value is an external
         * reference PROP_note (12) Value is a note PROP_typed_relation (13) Value is a typed
         * relation PROP_untyped_relation (14) Value is an untyped relation
         */
        int propValueType;
        /**
         * Type for the property PROP_unknown (0) Property type is Unknown PROP_attribute (1)
         * Based on a POM Attribute (int, string, ...) PROP_reference (2)  Based on a POM Reference
         * PROP_relation (3) Based on an ImanRelation PROP_compound (4) Based on a property
         * from another Type PROP_runtime (5) Based on a computed value
         */
        int propType;
        /**
         * isDisplayable
         */
        bool isDisplayable;
        /**
         * Specifies whether the property is an array or single value
         */
        bool isArray;
        /**
         * Specifies the max number of elements
         */
        int maxNumElems;
        /**
         * ListOfValues object attached to the property (if any)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
        /**
         * Specifies whether the property is required
         */
        bool isRequired;
        /**
         * Specifies whether the property is enabled
         */
        bool isEnabled;
        /**
         * Specifies whether the property is modifiable
         */
        bool isModifiable;
        /**
         * attachedSpecifier
         */
        int attachedSpecifier;
        /**
         * maxLength
         */
        int maxLength;
        /**
         * interdependentProps
         */
        std::vector< std::string > interdependentProps;
        /**
         * Naming patterns for property, can be null
         */
        std::vector< std::string > namingPatterns;
    };

    /**
     * Property Description Information
     */
    struct PropDescInfo
    {
        /**
         * The name of the Teamcenter Engineering type to which property belongs
         */
        std::string typeName;
        /**
         * List of Property names for which PropDesc needs to be fetched
         */
        std::vector< std::string > propNames;
    };

    /**
     * Property Description Output
     */
    struct PropDescOutput
    {
        /**
         * Input Property name for which PropDesc needs to be fetched
         */
        std::string propName;
        /**
         * The PropDescriptor struct describes information about the Teamcenter property
         */
        Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::PropDesc propertyDesc;
    };

    /**
     * RelationType information
     */
    struct RelationTypeInfo
    {
        /**
         * Name of the relation type.
         */
        std::string name;
        /**
         * Display name of the relation type (localized).
         */
        std::string displayName;
    };

    /**
     * Input structure for the getValidRelationTypes SOA.
     */
    struct RelationTypesInput
    {
        /**
         * Type of the source for assignment (part, tool, etc.)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceType;
        /**
         * Type of the target for assignment (process, operation, etc.)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetType;
    };

    /**
     * Output structure for the getValidRelationTypes SOA.
     */
    struct RelationTypesOutput
    {
        /**
         * Type of the source for assignment (part, tool, etc.)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceType;
        /**
         * Type of the target for assignment (process, operation, etc.)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetType;
        /**
         * Array of PSOccurrenceType names
         */
        std::vector< Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::RelationTypeInfo > validRelationTypes;
    };




    /**
     * Get the attached property descriptor based on input type name and property names
     * structure.
     *
     * @param inputs
     *        - vector of structure of PropDescInfo with type name and property names vector.
     *
     * @return
     *         AttachedPropDescsResponse - Response structure with Map of input typeName to PropDesc
     *         structure and serviceData
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::AttachedPropDescsResponse getManufacturingPropretyDescs ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::PropDescInfo >& inputs ) = 0;

    /**
     * This service returns a list of occurrence types that are valid for assignment between
     * two received object types.
     *
     * @param relationTypesInput
     *        Vector of source and target types pairs.
     *
     * @return
     *         List of valid occurrence types.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::GetValidRelationTypesResponse getValidRelationTypes ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Modeldefinitions::RelationTypesInput >& relationTypesInput ) = 0;


protected:
    virtual ~Modeldefinitions() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

