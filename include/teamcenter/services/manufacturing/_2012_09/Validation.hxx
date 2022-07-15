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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2012_09_VALIDATION_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2012_09_VALIDATION_HXX

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
                class Validation;

class TCSOAMANUFACTURINGSTRONGMNGD_API Validation
{
public:

    struct ValidationCheckCallbackParam;
    struct ValidationCheckExecutionErrors;
    struct ValidationCheckExecutionErrorsDetails;
    struct ValidationCheckExecutionParam;
    struct ValidationsChecksExecutionResponse;
    struct ValidationsChecksObjectsResponse;

    /**
     * Validation Check Callback Param
     */
    struct ValidationCheckCallbackParam
    {
        /**
         * The type of the validation always MFG_ValidationChecksCallback
         */
        std::string type;
        /**
         * Customized DLL Name
         */
        std::string library;
        /**
         * Customized Name - The name of the validation test
         */
        std::string name;
        /**
         * Customized Function name
         */
        std::string function;
        /**
         * Continue to the next test if the previous test failed.
         */
        bool failAllOnError;
    };

    /**
     * Validation Check Execution Errors
     */
    struct ValidationCheckExecutionErrors
    {
        /**
         * the non valid object line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * validationErrors
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationCheckExecutionErrorsDetails > validationErrors;
        /**
         * The validation check that failed.
         */
        Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationCheckCallbackParam validationTest;
    };

    /**
     * Validation Check Execution Errors Details
     */
    struct ValidationCheckExecutionErrorsDetails
    {
        /**
         * could be ifail or lov (msgId from ValidationNotice struct)
         */
        int msgId;
        /**
         * description of the localized error
         */
        std::string msg;
        /**
         * The object on which the validation check failed
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The type of the returned notice from the callback functions
         */
        std::string validationNoticeType;
    };

    /**
     * Validation Check Execution Param
     */
    struct ValidationCheckExecutionParam
    {
        /**
         * The root object to be validated, could be any line type of Mfg0BvrProcess or Mfg0BvrOperation
         * or its derived.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  root;
        /**
         * all the validation checks to perform on the object
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationCheckCallbackParam > validationChecks;
    };

    /**
     * Validations Checks Execution Response
     */
    struct ValidationsChecksExecutionResponse
    {
        /**
         * errors
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationCheckExecutionErrors > errors;
        /**
         * Standard ServiceData member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Validations Checks Objects Response
     */
    struct ValidationsChecksObjectsResponse
    {
        /**
         * params
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationCheckCallbackParam > params;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This SOA function is to execute the validation checks by the user choice from the
     * UI.
     *
     * @param input
     *        Validation Check Execution Param
     *
     * @param failAllOnError
     *        whether or not to fail all tests when error occurs on a specific validation check
     *        for a specific line or to continue.
     *
     * @return
     *         Validations Checks Execution Response
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationsChecksExecutionResponse executeValidations ( const std::vector< Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationCheckExecutionParam >& input,
        bool failAllOnError ) = 0;

    /**
     * This SOA function is to get all the customized registered callback to show the user
     * in the UI.
     *
     * @return
     *         Validation Response Object
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_09::Validation::ValidationsChecksObjectsResponse getAllValidations (  ) = 0;


protected:
    virtual ~Validation() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

