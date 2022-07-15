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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_VALIDATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_VALIDATIONSERVICE_HXX

#include <teamcenter/services/manufacturing/_2012_09/Validation.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class ValidationService;

/**
 * Validation Service
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API ValidationService
    : public Teamcenter::Services::Manufacturing::_2012_09::Validation
{
public:
    static ValidationService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ValidationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

