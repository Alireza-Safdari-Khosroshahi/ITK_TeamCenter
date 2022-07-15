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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_STRUCTURESEARCH_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_STRUCTURESEARCH_HXX

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
            namespace _2013_05
            {
                class Structuresearch;

class TCSOAMANUFACTURINGSTRONGMNGD_API Structuresearch
{
public:

    struct FindStudiesResponse;
    struct FindStudiesResults;

    /**
     * The response data from the findStudies service operation.
     */
    struct FindStudiesResponse
    {
        /**
         * The found Mfg0BvrStudy objects for each inputNodes Mfg0BvrProcess or Mfg0BvrOperation
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Structuresearch::FindStudiesResults > results;
        /**
         * Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A list of Mfg0BvrStudy objects
     */
    struct FindStudiesResults
    {
        /**
         * A list of Mfg0BvrStudy objects
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > listOfStudies;
    };




    /**
     * This operation finds all study objects that reference a given process/operation business
     * object.
     *
     * @param inputNodes
     *        A list of business objects for which referencing studies should be searced (objects
     *        of type Mfg0BvrProcess or Mfg0BvrOperation).
     *
     * @return
     *         The Mfg0BvrStudy objects that refer to the input business objects.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Structuresearch::FindStudiesResponse findStudies ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& inputNodes ) = 0;


protected:
    virtual ~Structuresearch() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

