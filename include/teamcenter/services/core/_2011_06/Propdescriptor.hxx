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

#ifndef TEAMCENTER_SERVICES_CORE__2011_06_PROPDESCRIPTOR_HXX
#define TEAMCENTER_SERVICES_CORE__2011_06_PROPDESCRIPTOR_HXX

#include <teamcenter/services/core/_2007_06/Propdescriptor.hxx>
#include <teamcenter/soa/client/model/ListOfValues.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2011_06
            {
                class Propdescriptor;

class TCSOACORESTRONGMNGD_API Propdescriptor
{
public:

    struct AttachedPropDescsResponse;
    struct PropDesc;
    struct PropDescOutput2;

    /**
     * InputTypeNameToPropDescOutputMap2
     */
    typedef std::map< std::string, std::vector< PropDescOutput2 > > InputTypeNameToPropDescOutputMap2;

    /**
     * AttachedPropDescsResponse  structure contains a map of PropDescOutput2 lists mapped
     * to the input type name  and the serviceData with possible errors.
     */
    struct AttachedPropDescsResponse
    {
        /**
         * A map of property descriptor lists and the associated input type name.
         */
        InputTypeNameToPropDescOutputMap2 inputTypeNameToPropDescOutput;
        /**
         * The Service Data.
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
         * LOV attachments Category
         */
        int lovAttachmentsCategory;
        /**
         * interdependentProps
         */
        std::vector< std::string > interdependentProps;
    };

    /**
     * Property Description Output
     */
    struct PropDescOutput2
    {
        /**
         * Input Property name for which PropDesc needs to be fetched
         */
        std::string propName;
        /**
         * The PropDescriptor struct describes information about the Teamcenter property
         */
        Teamcenter::Services::Core::_2011_06::Propdescriptor::PropDesc propertyDesc;
    };




    /**
     * Returns a list of Property Descriptors based on the input structure.  The Property
     * Descriptors contain the Display Name, Description and other information about the
     * input property.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation provides following use case for retrieving a set of Property Descriptors
     * given a type name and list of property names for that type.
     * <br>
     * <br>
     * Use Case 1:<b>Retrieve a set of Property Descriptors for a list of property names.</b>
     * <br>
     * <ul>
     * <li type="disc">Create a new PropDescInfo input structure.
     * </li>
     * <li type="disc">Populate the type name and input list of property names.
     * </li>
     * <li type="disc">Call getAttachedPropDescs2 with the newly created input structure.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Property Layer - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of our PLM platform.  This component defines properties.
     *
     * @param inputs
     *        An input Type Name and a list of property names on the input type.  A Property Descriptor
     *        is returned for each Property Name in the list.
     *
     * @return
     *         A map of InputTypeNameToPropDescOutputMap2, which maps each returned Property Descriptor
     *         to the associated input Type Name.  If any of the input data is invalid, it will
     *         be added to the ServiceData along with the partial error associated with the input
     *         type and property name.
     *         <br>
     *         <br>
     *         Some of the possible error codes added to the ServiceData are listed below.
     *         <br>
     *         <ul>
     *         <li type="disc">214170 The input type name is NULL.
     *         </li>
     *         <li type="disc">214171 The input property is NULL.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           .
     */
    virtual Teamcenter::Services::Core::_2011_06::Propdescriptor::AttachedPropDescsResponse getAttachedPropDescs2 ( const std::vector< Teamcenter::Services::Core::_2007_06::Propdescriptor::PropDescInfo >& inputs ) = 0;


protected:
    virtual ~Propdescriptor() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

