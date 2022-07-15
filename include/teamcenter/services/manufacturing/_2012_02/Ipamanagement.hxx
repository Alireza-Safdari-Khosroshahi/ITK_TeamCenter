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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2012_02_IPAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2012_02_IPAMANAGEMENT_HXX

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
            namespace _2012_02
            {
                class Ipamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Ipamanagement
{
public:

    struct DeleteFilteredIPAInputInfo;
    struct GetFilteredIPATypeResponse;

    /**
     * Contains the information about deleting filtered IPAs.
     */
    struct DeleteFilteredIPAInputInfo
    {
        /**
         * The business object of the process from which filtered IPA needs to be deleted.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  process;
        /**
         * Indicates whether all the filtered IPAs in the hierachy of the process should be
         * deleted or just one filtered IPA directly under the process should be deleted.
         */
        bool isRecursive;
    };

    /**
     * resopnse for getFilteredIPAType SOA
     */
    struct GetFilteredIPATypeResponse
    {
        /**
         * serive data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * a vector of processes that their process structure already contain a flat FIPA.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > flat;
        /**
         * a vector of processes that their process structure already contains a nested FIPA
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > nested;
        /**
         * processes that their process structure doesn't contain any FIPA yet.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > unset;
    };




    /**
     * This API will delete the filtered IPA(s) under the process depending on the boolean
     * member "isRecursive" of the input structure. If " isRecursive" is true, then all
     * the filtered IPAs in the hierarchy of the member "process" will be deleted. Else
     * just one filtered IPA directly under the process will be deleted.
     *
     * @param input
     *        Contains the information about deleting filtered IPAs.
     *
     * @return
     *         the standard serviceData that contains errors\notes from executing the deletion.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteFilteredIPA ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Ipamanagement::DeleteFilteredIPAInputInfo >& input ) = 0;

    /**
     * For each process, return the type of the FIPA used for this process structure.  For
     * processes from the same process structure, the answer is the same. Therefore, from
     * perforemence point of view, it is better to pass the process context (topline) as
     * an input, instead of sending several processes from the same structure.
     *
     * @param processes
     *        a vector of processes.
     *
     * @return
     *         For each process, return the type of the FIPA used for this process structure (can
     *         be either flat or nested). If there is no FIPA for this process structure, return
     *         unset.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Ipamanagement::GetFilteredIPATypeResponse getFilteredIPAType ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& processes ) = 0;


protected:
    virtual ~Ipamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

