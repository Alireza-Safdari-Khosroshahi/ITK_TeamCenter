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

#ifndef TEAMCENTER_SERVICES_MROCORE__2012_02_MROCORE_HXX
#define TEAMCENTER_SERVICES_MROCORE__2012_02_MROCORE_HXX

#include <teamcenter/soa/client/model/PhysicalPart.hxx>
#include <teamcenter/soa/client/model/Utilization.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/mrocore/MROCore_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Mrocore
        {
            namespace _2012_02
            {
                class Mrocore;

class TCSOAMROCORESTRONGMNGD_API Mrocore
{
public:

    struct DisplayUtilizationInfo;
    struct DisplayUtilizationOutput;
    struct DisplayUtilizationResponse;

    /**
     * Structure represents the parameters required to get the utilization data for the
     * given <b>PhysicalPart</b>.
     */
    struct DisplayUtilizationInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object for which the utilization data is to be retrieved.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPart>  physicalPart;
        /**
         * The date till the utilization is retrieved for Utilization.
         */
        Teamcenter::Soa::Common::DateTime tillDate;
    };

    /**
     * Structure represents the list of the utilization data for the given <b>PhysicalPart</b>.
     */
    struct DisplayUtilizationOutput
    {
        /**
         * The <code>clientId</code> from the input <code>DisplayUtilizationInfo</code> element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The list of <b>Utilization</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Utilization>  > output;
    };

    /**
     * Structure represents a list of <b>Utilization</b> objects along with the <code>ServiceData</code>.
     */
    struct DisplayUtilizationResponse
    {
        /**
         * A list <b>Utilization</b> objects.
         */
        std::vector< Teamcenter::Services::Mrocore::_2012_02::Mrocore::DisplayUtilizationOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation gets the utilization data till the date specified for a <b>PhysicalPart</b>.
     * The data is represented by <b>Utilization</b> object. <b>Utilization</b> object contains
     * the information like Characteristic Name, Characteristic Unit, Time Since New, Last
     * Recorded Value etc.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO Core - MRO Core
     *
     * @param inputInfo
     *        The information to capture the utilization data for a <b>PhysicalPart</b>.
     *
     * @return
     *         The list of <b>Utilization</b> object containing the utilization data for <b>PhysicalPart</b>
     *         is returned along with the <code>ServiceData</code>. Any failure will be returned
     *         with <code>clientId</code> mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Mrocore::_2012_02::Mrocore::DisplayUtilizationResponse displayUtilization ( const std::vector< Teamcenter::Services::Mrocore::_2012_02::Mrocore::DisplayUtilizationInfo >& inputInfo ) = 0;


protected:
    virtual ~Mrocore() {}
};
            }
        }
    }
}

#include <teamcenter/services/mrocore/MROCore_undef.h>
#endif

