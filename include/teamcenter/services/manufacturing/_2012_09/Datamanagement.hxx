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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2012_09_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2012_09_DATAMANAGEMENT_HXX

#include <teamcenter/services/manufacturing/_2009_10/Datamanagement.hxx>
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
            namespace _2012_09
            {
                class Datamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Datamanagement
{
public:

    struct ApplyConfigInput;
    struct CreateConfigInput;
    struct CreateConfigOutput;
    struct CreateConfigResponse;

    /**
     * Structure containing the configuration information and the context on which configuration
     * needs to be applied.
     */
    struct ApplyConfigInput
    {
        /**
         * Object holding the configuration information that needs to be applied
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  configObj;
        /**
         * The context to which the configuration needs to be applied.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
    };

    /**
     * Object containing input information for createOrUpdateConfigObjects action.
     */
    struct CreateConfigInput
    {
        /**
         * CreateInput structure used to capture the inputs required for creation of a business
         * object.
         */
        Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateInput data;
        /**
         * Object to be modified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  modifyObject;
        /**
         * Top line of the BOMWindow object in case of StructureContext or ConfigurationContext,
         * Null in case of CollaborationContext.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  basedOn;
        /**
         * Internal related config objects. For a CC, this would be a vector of SCs. For an
         * SC, this would be a Config Context. For ConfigContext, this would be null.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigInput > internalConfigData;
    };

    /**
     * Object containing information related to createOrUpdateConfigObjects action.
     */
    struct CreateConfigOutput
    {
        /**
         * Configuration object created or modified as per input.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The context based on which configuration object is created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * Data regarding created and updated internal nested configuration objects.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigOutput > internalConfigData;
    };

    /**
     * Response for createOrUpdateConfigObjects action.
     */
    struct CreateConfigResponse
    {
        /**
         * Object of CreateConfigOutput.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigOutput > output;
        /**
         * Service data including partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Apply configuration objects to applicable business objects.
     *
     * @param input
     *        Input parameters for applying configuration objects
     *
     * @return
     *         Service Data
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData applyConfigObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::ApplyConfigInput >& input ) = 0;

    /**
     * Creates or updates the configuration objects based on the input data.
     *
     * @param input
     *        Vector of CreateConfigInput structure which contains the information for creating
     *        or updating context objects.
     *
     * @return
     *         Contains the created or updated object and the service data.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigResponse createOrUpdateConfigObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2012_09::Datamanagement::CreateConfigInput >& input ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

