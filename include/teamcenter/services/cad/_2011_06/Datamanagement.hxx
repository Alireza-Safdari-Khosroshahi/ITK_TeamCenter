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

#ifndef TEAMCENTER_SERVICES_CAD__2011_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2011_06_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/CadAttrMappingDefinition.hxx>
#include <teamcenter/soa/client/model/ListOfValues.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            namespace _2011_06
            {
                class Datamanagement;

class TCSOACADSTRONGMNGD_API Datamanagement
{
public:

    struct PropDescriptor;
    struct AttrMappingInfo;
    struct GetAllAttrMappingsResponse;

    /**
     * The <code>PropDescriptor</code> struct describes information about the Teamcenter
     * property
     */
    struct PropDescriptor
    {
        /**
         * Name of the property
         */
        std::string propName;
        /**
         * Display name of the property. This is the localized name for the property.
         */
        std::string displayName;
        /**
         * Default value for the property. This is also sometimes known as the initial value
         * of the property
         */
        std::string defaultValue;
        /**
         * Value type for the property in integer form:
         * <br>
         * PROP_untyped (0) No value
         * <br>
         * PROP_char (1) Value is a single character
         * <br>
         * PROP_date (2) Value is a date
         * <br>
         * PROP_double (3) Value is a double
         * <br>
         * PROP_float (4) Value is a float
         * <br>
         * PROP_int (5) Value is an integer
         * <br>
         * PROP_logical (6) Value is a logical
         * <br>
         * PROP_short (7) Value is a short
         * <br>
         * PROP_string (8) Value is a character string
         * <br>
         * PROP_typed_reference (9) Value is a typed reference
         * <br>
         * PROP_untyped_reference (10) Value is an untyped reference
         * <br>
         * PROP_external_reference (11) Value is an external reference
         * <br>
         * PROP_note (12) Value is a note
         * <br>
         * PROP_typed_relation (13) Value is a typed relation
         * <br>
         * PROP_untyped_relation (14) Value is an untyped relation
         */
        int propValueType;
        /**
         * Type for the property in integer form:
         * <br>
         * PROP_unknown (0) Property type is unknown
         * <br>
         * PROP_attribute (1)  Based on a POM attribute (int, string, ...)
         * <br>
         * PROP_reference (2)  Based on a POM reference
         * <br>
         * PROP_relation (3) Based on an <b>ImanRelation</b>
         * <br>
         * PROP_compound (4) Based on a property from another type
         * <br>
         * PROP_runtime (5) Based on a computed value
         */
        int propType;
        /**
         * Boolean property indicating if the property should be displayed (true) or not (false).
         */
        bool isDisplayable;
        /**
         * Specifies whether the property is an array or single value
         */
        bool isArray;
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
         * Attached specifier holds the following information:
         * <br>
         * <ul>
         * <li type="disc">Is it a hierarchical LOV attachment? If it is hierarchical LOV attachment,
         * the specifier value is 0;  This value can be 0 in following cases:
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Standard LOV attachment (Combobox, Range
         * etc)
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Value Ddescription attachment only ( specifier
         * value is 0 for the value attachment )
         * </li>
         * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;To check whether it is hierarchical or not,
         * one needs to verify the children LOVs (value filters from LOV). If there are children
         * LOVs then it could be a hierarchical LOV.
         * </li>
         * <li type="disc"> Is it attached with interdependent?
         * </li>
         * <li type="disc">bool isInterdependent = ( specifier & (1 << 1) ) != 0;
         * </li>
         * <li type="disc"> Is it attached with description attachment?
         * </li>
         * <li type="disc">bool  isDescriptionAttach = ( specifier & (1 << 1) )!= 0;
         * </li>
         * </ul>
         * <br>
         * If attached with interdependent or description attachment what is the order of the
         * attachment?
         * <br>
         * int order = specifier >> 8;
         */
        int attachedSpecifier;
        /**
         * Maximum length for a string property.
         */
        int maxLength;
        /**
         * Defines categories of LOVs attached to the property.
         * <br>
         * 0:  No attachments
         * <br>
         * 1:  Only isTrue condition is attached
         * <br>
         * 2:  Only session based conditions are attached
         * <br>
         * 3:  One or more object based conditions are attached
         * <br>
         */
        int lovAttachmentsCategory;
        /**
         * Interdependent properties for interdependent LOVs.
         */
        std::vector< std::string > interdependentProps;
    };

    /**
     * Attribute mapping information.
     */
    struct AttrMappingInfo
    {
        /**
         * The <b>CadAttrMappingDefinition</b> object reference representing the mapping definition.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::CadAttrMappingDefinition>  cadAttrMappingDefinition;
        /**
         * The property descriptor structure containing property information for the mapping
         * definition property.
         */
        Teamcenter::Services::Cad::_2011_06::Datamanagement::PropDescriptor propDesc;
    };

    /**
     * The response from the <code>getAllAttrMappings2</code> operation.
     */
    struct GetAllAttrMappingsResponse
    {
        /**
         * A list of attribute mapping information.
         */
        std::vector< Teamcenter::Services::Cad::_2011_06::Datamanagement::AttrMappingInfo > attrMappingInfos;
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData</code>
         * plain objects with <code>CadAttrMappingDefinition</code> objects and property descriptor
         * LOV objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation retrieves all CAD attribute mapping definitions. If a <code>CadAttributeMappingDefinition</code>
     * object has a path that includes a Generic Relationship Manager (GRM) or named reference
     * part, the associated property descriptor and any attached <code>ListOfValues</code>
     * (LOV) objects will be returned. This operation also returns LOV attachments category
     * information to be used in object based conditions.
     * <br>
     * <br>
     * Since this operation returns existing Teamcenter attribute mappings, please reference
     * the Teamcenter help section on creating attribute mappings.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to have attributes set on an object in Teamcenter.
     * <br>
     * <br>
     * For this operation, the client application uses the list of returned attribute mapping
     * definitions to present the correct CAD attributes to the user that correspond to
     * the correct Teamcenter attributes including property descriptor information about
     * the Teamcenter attributes.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         The full list of CAD attribute mapping definitions.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215072:  The operation failed to get all attribute mapping definitions.
     *         </li>
     *         <li type="disc">215117:  Failed to get the <code>CADAttributeMappingDefinition</code>
     *         property descriptor.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if any Teamcenter subsystem errors
     *           occur during the retrieval of all attribute mappings, finding the dataset type or
     *           finding the attribute mapping type.
     */
    virtual Teamcenter::Services::Cad::_2011_06::Datamanagement::GetAllAttrMappingsResponse getAllAttrMappings2 (  ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

