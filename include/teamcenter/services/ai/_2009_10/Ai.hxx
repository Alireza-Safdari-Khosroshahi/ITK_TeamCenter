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

#ifndef TEAMCENTER_SERVICES_AI__2009_10_AI_HXX
#define TEAMCENTER_SERVICES_AI__2009_10_AI_HXX

#include <teamcenter/services/ai/_2006_03/Ai.hxx>
#include <teamcenter/services/ai/_2008_06/Ai.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/ai/Ai_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Ai
        {
            namespace _2009_10
            {
                class Ai;

class TCSOAAISTRONGMNGD_API Ai
{
public:

    struct ErrorMap;
    struct GetPropertyValuesData;
    struct GetPropertyValuesResponse;
    struct ObjPropDetail;
    struct PropertyDetails;

    /**
     * The different kinds of lov usage
     */
    enum LOVUSAGE{ AI_LV_Unknown,
                 AI_LV_Exhaustive_list,
                 AI_LV_Suggestions,
                 AI_LV_Ranges,
                 AI_LV_Upper_bound
                 };

    /**
     * capture the index of the input array, and the indices for the objects within that
     * array.
     */
    struct ErrorMap
    {
        /**
         * index of the input array with the list of objects and configurations.
         */
        int index;
        /**
         * Within the index specified by "index" the location of failed indices.
         */
        std::vector< int > indices;
    };

    /**
     * Used to input the list of objects with related configuration (used to setup bomwindows
     * if needed on server), and the properties.
     */
    struct GetPropertyValuesData
    {
        /**
         * list of objects along with configuration.
         */
        std::vector< Teamcenter::Services::Ai::_2008_06::Ai::ObjectsWithConfig > objs;
        /**
         * list of  properties to be queried for on the object.
         */
        std::vector< std::string > properties;
    };

    /**
     * capture the property values for the specified object and specified properties and
     * any failures.
     */
    struct GetPropertyValuesResponse
    {
        /**
         * the properties of the object
         */
        std::vector< Teamcenter::Services::Ai::_2009_10::Ai::ObjPropDetail > objProps;
        /**
         * array of failed indices. The index is the position in the input array. And the indices
         * member is the list of failed objects (invalid tags) at each such index.
         */
        std::vector< Teamcenter::Services::Ai::_2009_10::Ai::ErrorMap > failedSetIndices;
    };

    /**
     * capture the object ApplicationRef and it's property details.
     */
    struct ObjPropDetail
    {
        /**
         * the ApplicationReference of the obj (uid/appname/version)
         */
        Teamcenter::Services::Ai::_2006_03::Ai::ApplicationRef obj;
        /**
         * array or property details per
         */
        std::vector< Teamcenter::Services::Ai::_2009_10::Ai::PropertyDetails > properties;
        /**
         * index of the failed property for the object - the index maps to the input property
         * array.
         */
        std::vector< int > failedPropIndices;
        /**
         * the error string corresponding to the error id in failedPropIndices.
         */
        std::vector< std::string > failedPropMessages;
    };

    /**
     * details of a property
     */
    struct PropertyDetails
    {
        /**
         * display name of the property
         */
        std::string name;
        /**
         * values in string form. Array - if the property has multiple values. These values
         * can be decoded/parsed using the Property SOA client class if needed.
         */
        std::vector< std::string > values;
        /**
         * in case the property value is  a string - the maximum possible length.
         */
        int maxStrLen;
        /**
         * the type of the property as a string. integer = "int", short="short", float="float",
         * double="double", char="char", logical="logical",note="note", string="string", date="date",
         * any reference="reference"
         */
        std::string type;
        /**
         * will be set to 0 if write access is allowed, 1 - for read.
         */
        int access;
        /**
         * if lov - the usage type of that lov.
         */
        LOVUSAGE usage;
        /**
         * the lovValues as strings.
         */
        std::vector< std::string > lovValues;
        /**
         * for each value in an array - is the value Null.
         */
        std::vector< int > nullElement;
        /**
         * Used to indicate if each element in an array(each value) is empty.
         */
        std::vector< int > emptyElement;
    };




    /**
     * get the property values for the object supplied as ApplicationReferences and configuration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Interface - Contains the Application Interface (AI) functionality, allowing
     * import and export transactions between Teamcenter and external applications. This
     * component contains the model, services & user interface required for working with
     * AI.
     *
     * @param input
     *        array of input structure - each of which specifies the object and configuration,
     *        along with properties.
     *
     * @return
     *         return the property values for the input properties and objects.
     *
     */
    virtual Teamcenter::Services::Ai::_2009_10::Ai::GetPropertyValuesResponse getPropertyValues ( const std::vector< Teamcenter::Services::Ai::_2009_10::Ai::GetPropertyValuesData >& input ) = 0;


protected:
    virtual ~Ai() {}
};
            }
        }
    }
}

#include <teamcenter/services/ai/Ai_undef.h>
#endif

