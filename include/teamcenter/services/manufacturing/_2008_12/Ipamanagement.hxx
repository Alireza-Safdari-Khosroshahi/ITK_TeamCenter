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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2008_12_IPAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2008_12_IPAMANAGEMENT_HXX

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
            namespace _2008_12
            {
                class Ipamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Ipamanagement
{
public:

    struct IPAManagementGenerateSearchScopeResponse;
    struct IPAManagementGetFilteredIPAResponse;
    struct IPAManagementSaveSearchResultInput;
    struct IPAManagementSaveSearchResultResponse;

    /**
     * Return structure for IPAManagementGenerateSearchScope operation
     */
    struct IPAManagementGenerateSearchScopeResponse
    {
        /**
         * A vectoer of all the bomlines that are the search scope.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > bomlines;
        /**
         * This is a common data strucuture used to return sets of Teamcenter  Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Return structure for IPAManagementGetFilteredIPA operation
     */
    struct IPAManagementGetFilteredIPAResponse
    {
        /**
         * A vectoer of all the filteredIPAs found.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > filteredIPAs;
        /**
         * This is a common data strucuture used to return sets of Teamcenter  Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for IPAManagementSaveSearchResult operation
     */
    struct IPAManagementSaveSearchResultInput
    {
        /**
         * The process from which we want to filter the IPA.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  process;
        /**
         * The bomlines result from the search.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > searchResultList;
        /**
         * The name of the new filtered structure.
         */
        std::string name;
    };

    /**
     * Return structure for IPAManagementSaveSearchResult operation
     */
    struct IPAManagementSaveSearchResultResponse
    {
        /**
         * This is the new filteredIPA structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  filteredIPA;
        /**
         * The flat list of all filteredIPA structures.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  filteredIPARoot;
        /**
         * A list of all the bomlines that were not found in the IPA structure.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > rejectedList;
        /**
         * This is a common data strucuture used to return sets of Teamcenter  Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Deletes the filteredIPA structure from the process.
     *
     * @param processes
     *        Input Vector of process lines, from which we want to delete the filteredIPA.
     *
     * @return
     *         serviceData This is a common data strucuture used to return sets of Teamcenter Data
     *         Model object from a service request. This also holds services exceptions.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deletefilteredIPA ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& processes ) = 0;

    /**
     * find the IPA under the given process (for each process) and retrives the bomlines
     * from under it.
     *
     * @param processes
     *        processes Vector of process lines, that we would like to get all the search scope
     *        from.
     *
     * @return
     *         IPAManagementGenerateSearchScopeResponse Return Structure see discription in structure
     *         definition file.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_12::Ipamanagement::IPAManagementGenerateSearchScopeResponse generateSearchScope ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& processes ) = 0;

    /**
     * Return the filteredIPA structure from the process.
     *
     * @param processes
     *        Input Vector of process lines, from which we want to find the filteredIPA.
     *
     * @return
     *         IPAManagementGetFilteredIPAResponse Return Structure see discription in structure
     *         definition file.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_12::Ipamanagement::IPAManagementGetFilteredIPAResponse getFilteredIPA ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& processes ) = 0;

    /**
     * Saves the search result in a new/updated structure.
     *
     * @param input
     *        Input Vector of IPAManagementSaveSearchResultInput Structures see discription in
     *        structure definition file.
     *
     * @return
     *         IPAManagementSaveSearchResultResponse Return Structure see discription in structure
     *         definition file.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_12::Ipamanagement::IPAManagementSaveSearchResultResponse saveSearchResult ( const std::vector< Teamcenter::Services::Manufacturing::_2008_12::Ipamanagement::IPAManagementSaveSearchResultInput >& input ) = 0;


protected:
    virtual ~Ipamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

