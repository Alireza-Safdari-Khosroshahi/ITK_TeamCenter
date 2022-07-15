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

#ifndef TEAMCENTER_SERVICES_CORE__2007_06_PROPDESCRIPTOR_HXX
#define TEAMCENTER_SERVICES_CORE__2007_06_PROPDESCRIPTOR_HXX

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
            namespace _2007_06
            {
                class Propdescriptor;

class TCSOACORESTRONGMNGD_API Propdescriptor
{
public:

    struct AttachedPropDescsResponse;
    struct PropDesc;
    struct PropDescInfo;
    struct PropDescOutput;

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
    };

    /**
     * PropDescInfo structure represents all the Property Names and associated type to retrieve
     * Property Descriptors.
     */
    struct PropDescInfo
    {
        /**
         * The name of the type associated with the input Property Names.
         */
        std::string typeName;
        /**
         * A list of the input Property Names to retrieve Property Descriptors.
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
        Teamcenter::Services::Core::_2007_06::Propdescriptor::PropDesc propertyDesc;
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
     * @deprecated
     *         As of Teamcenter 9, use the getAttachedPropDescs2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the getAttachedPropDescs2 operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_06::Propdescriptor::AttachedPropDescsResponse getAttachedPropDescs ( const std::vector< Teamcenter::Services::Core::_2007_06::Propdescriptor::PropDescInfo >& inputs ) = 0;


protected:
    virtual ~Propdescriptor() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

