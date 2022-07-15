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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_IPAMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_IPAMANAGEMENTSERVICE_HXX

#include <teamcenter/services/manufacturing/_2008_12/Ipamanagement.hxx>
#include <teamcenter/services/manufacturing/_2012_02/Ipamanagement.hxx>
#include <teamcenter/services/manufacturing/_2013_05/Ipamanagement.hxx>



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
            class IpamanagementService;

/**
 * IPA related services
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

class TCSOAMANUFACTURINGSTRONGMNGD_API IpamanagementService
    : public Teamcenter::Services::Manufacturing::_2008_12::Ipamanagement,
             public Teamcenter::Services::Manufacturing::_2012_02::Ipamanagement,
             public Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement
{
public:
    static IpamanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation removes the In-Process Assembly (IPA) occurrences from the process
     * structure and deletes the IPA occurrence group from product structure. This operation
     * cleans only the IPA which has been configured by current configuration rule and configuring
     * structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param processWindow
     *        Window of the process structure containing the IPA that is to be deleted.
     *
     * @param forceCleanAll
     *        This flag is used to forcefully delete all IPAs. This functionality is not supported
     *        currently.
     *
     * @return
     *         ServiceData element, appearance path root window along with its type which was deleted
     *         during the operation and the log file details and its ticket. The deleted occurrence
     *         groups from the process structure and deleted appearance path root of the product
     *         structure is added to the Deleted object list of ServiceData. Partial errors occurred
     *         in the operation are added to ServiceData.
     *         <br>
     *         <br>
     *         The error conditions and corresponding error codes are as listed below-
     *         <br>
     *         <br>
     *         46001:  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The input process window
     *         is not a valid window.
     *         <br>
     *         200170:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The IPA occurrence group not
     *         found for the process.
     *         <br>
     *         200172:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The consumed product not found
     *         in the process structure.
     *         <br>
     *         515186:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not write the log file.
     *         The system prevented from writing it.
     *         <br>
     *         515181:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The log file is read-only.
     *         <br>
     *         515182:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not find the log file.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::CleanIPATreeResponse cleanIPATree ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  processWindow,
        bool forceCleanAll ) = 0;

    /**
     * This operation checks if an In-Process Assembly tree exists for a process structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param processWindow
     *        Window of the process structure.
     *
     * @return
     *         ServiceData element, flag indicating whether IPA tree exists for the process structure
     *         and ticket of configuration file if the IPA tree exists for the structure. Partial
     *         errors occurred in Teamcenter internal APIs during the operation are returned in
     *         ServiceData.
     *         <br>
     *         <br>
     *         The error conditions and corresponding error codes are as listed below-
     *         <br>
     *         <br>
     *         46001:  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The input process window
     *         is not a valid window.
     *         <br>
     *         515186:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not write the configuration
     *         file. The system prevented from writing it.
     *         <br>
     *         515181:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The configuration file is
     *         read-only.
     *         <br>
     *         515182:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not find the configuration
     *         file.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::IPAExistResponse doesIPAExist ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  processWindow ) = 0;

    /**
     * An In-Process Assembly (IPA) is an aggregation of incoming parts into stations. IPA
     * is generated based on consumed item(s) from a product structure in a process structure.
     * Teamcenter creates a tree structure representing the IPA by traversing the process
     * structure and collecting IPAs from previous process elements and adding the selected
     * line's consumed objects.
     * <br>
     * <br>
     * The IPA is stored as an occurrence group and is displayed in a separate tab beside
     * the base view of the root product.
     * <br>
     * <br>
     * When the assembly tree is created by the operation, it places a configuration file
     * as an attachment on the process for which the IPA is generated.
     * <br>
     * <br>
     * Teamcenter sends an e-mail notification to the recipients specified in the input
     * after completion of the operation. This e-mail contains information about the IPA
     * creation, as well as log files that are created during generation of the IPA.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param ipaInput
     *        All the details for IPA generation that includes the name of the IPA, process types,
     *        consumption types, occurrence group type, effectivity, email notification details
     *        etc.
     *
     * @return
     *         ServiceData element, appearance path root window along with its type which was generated
     *         during the operation and the log file details and its ticket. The newly created occurrence
     *         groups from the process strcture and appearance path root of the product strcuture
     *         is added to the Created object list of ServiceData. Partial errors occurred in the
     *         operation are added to ServiceData.
     *         <br>
     *         <br>
     *         The error conditions and corresponding error codes are listed below-
     *         <br>
     *         <br>
     *         26003:  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Unclassified error/exception.
     *         See the system log file for explanation.
     *         <br>
     *         200172:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;No consumed product found
     *         in the process structure.
     *         <br>
     *         515186:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not write the log file.
     *         The system prevented from writing it.
     *         <br>
     *         515181:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The log file is read-only.
     *         <br>
     *         515182:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not find the log file.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::GenerateIPATreeResponse generateIPATree ( const Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::IPATreeInput&  ipaInput ) = 0;

    /**
     * This operation is used to perform a local update on an In-Process Assembly (IPA)
     * tree. Local update changes the IPA on which the operation is invoked. If necessary,
     * it also updates the occurrence pointing to this in-process assembly in the process
     * structure.
     * <br>
     * <br>
     * If the IPA has not been created and attached to the matching process, Teamcenter
     * also changes the matching process and adds the incoming IPA as MEWorkpiece. This
     * happens only if a process whose type is in the process types list of the configuration
     * details during the initial IPA generation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param processLines
     *        List of processes in the process structure on which local update requested.
     *
     * @return
     *         ServiceData element, the log file name and its ticket. The updated occurrence groups
     *         from the process structure and appearance path root of the product structure is added
     *         to the Updated object list of ServiceData. Partial errors occurred in the operation
     *         are added to ServiceData.
     *         <br>
     *         <br>
     *         The error conditions and corresponding error codes are as listed below-
     *         <br>
     *         <br>
     *         46001:  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The input process window
     *         is not a valid window.
     *         <br>
     *         200170:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The IPA occurrence group not
     *         found for the process to update.
     *         <br>
     *         200172:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The consumed product not found
     *         in the process structure.
     *         <br>
     *         515186:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not write the log file.
     *         The system prevented from writing it.
     *         <br>
     *         515181:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The log file is read-only.
     *         <br>
     *         515182:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not find the log file.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::LocalUpdateIPATreeResponse localUpdateIPATree ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& processLines ) = 0;

    /**
     * This operation is used to update an In-Process Assembly (IPA) tree that already exists,
     * when a process structure is changed. The options set at creation of the assembly
     * tree may be changed for example process types, consumed occurrence types, name of
     * the report on errors and problems, e-mail notification configuration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param ipaInput
     *        All the details for updating IPA that includes the name of the IPA, process types,
     *        consumption types, occurrence group type, effectivity, email notification details
     *        etc.
     *
     * @return
     *         ServiceData element, appearance path root window along with its type which was updated
     *         during the operation and the log file details and its ticket. The updated occurrence
     *         groups from the process strcture and appearance path root of the product strcuture
     *         is added to the Updated object list of ServiceData. Partial errors occurred in the
     *         operation are added to ServiceData.
     *         <br>
     *         <br>
     *         The error conditions and corresponding error codes are listed below-
     *         <br>
     *         46001:  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The input process window
     *         is not a valid window.
     *         <br>
     *         200170:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The IPA occurrence group not
     *         found for the process to update.
     *         <br>
     *         200172:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;No consumed product found
     *         in the process structure.
     *         <br>
     *         515186:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not write the log file.
     *         The system prevented from writing it.
     *         <br>
     *         515181:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The log file is read-only.
     *         <br>
     *         515182:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Could not find the log file.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::GenerateIPATreeResponse updateIPATree ( const Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::IPATreeInput&  ipaInput ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IpamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

