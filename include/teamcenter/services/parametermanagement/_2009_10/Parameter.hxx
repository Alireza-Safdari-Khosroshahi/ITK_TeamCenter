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

#ifndef TEAMCENTER_SERVICES_PARAMETERMANAGEMENT__2009_10_PARAMETER_HXX
#define TEAMCENTER_SERVICES_PARAMETERMANAGEMENT__2009_10_PARAMETER_HXX

#include <teamcenter/soa/client/model/BitDef.hxx>
#include <teamcenter/soa/client/model/BitValue.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/parametermanagement/ParameterManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Parametermanagement
        {
            namespace _2009_10
            {
                class Parameter;

class TCSOAPARAMETERMANAGEMENTSTRONGMNGD_API Parameter
{
public:

    struct BitDefinitionInfo;
    struct BitValueInfo;
    struct GetBitDefinitionPropertiesResponse;
    struct GetBitValuePropertiesResponse;

    /**
     * <code>BitDefinitionInfo</code> structure represents all the details of bit definition
     * to be created/updated.
     */
    struct BitDefinitionInfo
    {
        /**
         * <b>BitDef</b> business object. If it is null, <i>setBitDefinitionProperties</i> operation
         * creates a new <b>BitDef</b> business object. If not null, <i>setBitDefinitionProperties</i>
         * updates this <b>BitDef</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bitDefinitionObject;
        /**
         * Index of the byte within a <b>BitDef</b> business object
         */
        int byteNum;
        /**
         * Index of the bit within a byte
         */
        int bitNum;
        /**
         * Bit name
         */
        std::string name;
        /**
         * Meaning if the bit equals to 0
         */
        std::string meaningOf0;
        /**
         * Meaning if the bit equals to 1
         */
        std::string meaningOf1;
    };

    /**
     * <code>BitValueInfo</code> structure represents all the details of bit value to be
     * updated.
     */
    struct BitValueInfo
    {
        /**
         * <b>BitValue</b> business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bitValueObject;
        /**
         * Bit value
         */
        bool value;
        /**
         * Bit Definition
         */
        Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitDefinitionInfo bitDefinition;
    };

    /**
     * <code>GetBitDefinitionPropertiesResponse</code> structure represents all the details
     * of bit definition for the input <b>BitDef</b>.
     */
    struct GetBitDefinitionPropertiesResponse
    {
        /**
         * Bit definition for each <b>BitDef</b> business object
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitDefinitionInfo > bitDefinitionInfo;
        /**
         * Service data to hold Teamcenter Services framework objects that were created or updated
         * by the service.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * <code>GetBitValuePropertiesResponse</code> structure represents all the details of
     * bit value for the input <b>BitValue</b>.
     */
    struct GetBitValuePropertiesResponse
    {
        /**
         * Bit value for each <b>BitValue</b> business object
         */
        std::vector< Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitValueInfo > bitValueInfo;
        /**
         * Service data to hold Teamcenter Services framework objects that were created or updated
         * by the service.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation loads the bit definition for each <code>ccdm::BitDef</code> supplied.
     * Bit definition contains information for properties such as byte number, bit number
     * within the byte, name, meaning of 0 and meaning of 1.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Get bit definition for a BitDef</b>
     * <br>
     * You can get the bit definition data using <i>getBitDefinitionProperties</i> operation
     * by providing the <b>BitDef</b> tag.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitDefinitions
     *        BitDef objects
     *
     * @return
     *         The bit definition for the input <b>BitDef</b> is returned via <code>GetBitDefinitionPropertiesResponse</code>.
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2009_10::Parameter::GetBitDefinitionPropertiesResponse getBitDefinitionProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BitDef>  >& bitDefinitions ) = 0;

    /**
     * This operation loads the bit value for each <code>ccdm::BitValue</code> supplied.
     * Bit value contains information for properties such as value (true/false), bit definition
     * object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Get bit value for a BitValue object</b>
     * <br>
     * You can get the bit value data using <i>getBitValueProperties</i> operation by providing
     * the <b>BitValue</b> object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitValues
     *        <b>BitValue</b> objects
     *
     * @return
     *         The bit value details for the input <b>BitValue</b> is returned via <code>GetBitValuePropertiesResponse</code>.
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2009_10::Parameter::GetBitValuePropertiesResponse getBitValueProperties ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BitValue>  >& bitValues ) = 0;

    /**
     * This operation creates or modifies a <b>BitDef</b> business object for each <code>BitDefinitionInfo</code>
     * supplied. The <code>BitDefinitionInfo</code> contains information for properties
     * such as byte number, bit number within the byte, name, meaning of 0, and meaning
     * of 1. If the <b>BitDef</b> is not null in <code>BitDefinitionInfo</code> structure,
     * the operation updates this <b>BitDef</b> with the rest of the property values. Otherwise
     * the operation creates a new <b>BitDef</b> with the specific property values.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Create a Bit Definition</b>
     * <br>
     * You can create a new <b>BitDef</b> using <i>setBitDefinitionProperties</i> operation
     * by providing <code>bitDefinitionObject</code> as null in <code>BitDefinitionInfo</code>
     * structure.
     * <br>
     * <br>
     * <b>Use case 2: Modify a Bit Definition</b>
     * <br>
     * You can modify an existing <b>BitDef</b> using <i>setBitDefinitionProperties</i>
     * operation by providing <code>bitDefinitionObject</code> as an existing <b>BitDef</b>
     * in <code>BitDefinitionInfo</code> structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitDefinitionInfo
     *        Structures containing the details of the bit definition to be created/modified.
     *
     * @return
     *         The created/updated <b>BitDef</b> business objects are returned via <code>ServiceData</code>
     *         in Created/Updated lists.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setBitDefinitionProperties ( const std::vector< Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitDefinitionInfo >& bitDefinitionInfo ) = 0;

    /**
     * This operation modifies a <b>BitValue</b> business object for each <code>BitValueInfo</code>
     * supplied. The <code>BitValueInfo</code> contains information for properties such
     * as value (true/false), bit definition object. The <b>BitValue</b> business object
     * is specified in <code>BitValueInfo</code> structure as well.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Modify a Bit Value</b>
     * <br>
     * You can modify an existing <b>BitValue</b> using <i>setBitValueProperties</i> operation
     * by providing bitValueObject as an existing <b>BitValue</b> in <code>BitValueInfo</code>
     * structure.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param bitValInfo
     *        Structures containing the details of the bit value to be modified.
     *
     * @return
     *         The updated <b>BitValue</b> business objects are returned via <code>ServiceData</code>
     *         in Updated lists.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setBitValueProperties ( const std::vector< Teamcenter::Services::Parametermanagement::_2009_10::Parameter::BitValueInfo >& bitValInfo ) = 0;


protected:
    virtual ~Parameter() {}
};
            }
        }
    }
}

#include <teamcenter/services/parametermanagement/ParameterManagement_undef.h>
#endif

