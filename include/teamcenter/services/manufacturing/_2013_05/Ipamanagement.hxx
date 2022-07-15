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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_IPAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_IPAMANAGEMENT_HXX

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
                class Ipamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Ipamanagement
{
public:

    struct AppPathRootWindowDetails;
    struct FileTicketDetails;
    struct CleanIPATreeResponse;
    struct EffectivityDetails;
    struct ConfigDetails;
    struct EmailNotificationDetails;
    struct GenerateIPATreeResponse;
    struct IPAExistResponse;
    struct IPATreeInput;
    struct LocalUpdateIPATreeResponse;

    /**
     * The apperance path root window and its type.
     */
    struct AppPathRootWindowDetails
    {
        /**
         * The appearance path root window.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  productWindowAppPathRoot;
        /**
         * The type of appearance path root window.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  appPathRootType;
    };

    /**
     * The details of the file ticket.
     */
    struct FileTicketDetails
    {
        /**
         * The name of the log file.
         */
        std::string fileName;
        /**
         * The file management server ticket of the file.
         */
        std::string fileTicket;
    };

    /**
     * ServiceData element, appearance path root window along with its type which was deleted
     * during the operation and the log file details and its ticket. The deleted occurrence
     * groups from the process structure and deleted appearance path root of the product
     * structure is added to the Deleted object list of ServiceData. Partial errors occurred
     * in the operation are added to ServiceData.
     */
    struct CleanIPATreeResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of appearance windows deleted by the operation. These windows corressponds to
         * product structures consumed in the process strcuture to be cleaned.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::AppPathRootWindowDetails > appPathRootWindows;
        /**
         * The details of the log file ticket.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::FileTicketDetails logFileTicket;
    };

    /**
     * The effectivity details for the IPA generation like end item, its revision, range
     * and/or unit of effectivity.
     */
    struct EffectivityDetails
    {
        /**
         * The end item of generated assembly tree to which the effectivity is associated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  effectivityEndItem;
        /**
         * The end item revision of generated assembly tree to which the effectivity is associated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  effectivityEndItemRev;
        /**
         * The unit range of effectivity associated with IPA generated occurrence.
         */
        std::string effectivityUnitRange;
        /**
         * The date range of effectivity associated with IPA generated occurrence.
         */
        std::string effectivityDateRange;
    };

    /**
     * The configuration details about the IPA generation which includes details of process
     * structure, consumption types, occurrence group types and effectivity details.
     */
    struct ConfigDetails
    {
        /**
         * The window of the process structure in which items are consumed from a product structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  processWindow;
        /**
         * The name of the IPA to be processed.
         */
        std::string ipaName;
        /**
         * The type of occurrence group to be generated for the assembly tree.
         */
        std::string occGrpType;
        /**
         * List of process types for which an assembly tree is generated.
         */
        std::vector< std::string > processTypes;
        /**
         * List of consumed occurrence types considered for generation of the assembly tree.
         */
        std::vector< std::string > consumptionOccTypes;
        /**
         * The effectivity details for the IPA generation like end item, its revision, range
         * and/or unit of effectivity.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::EffectivityDetails effectivityDetails;
    };

    /**
     * The e-mail notification details like recipients of the e-mail, subject and content
     * of the message.
     */
    struct EmailNotificationDetails
    {
        /**
         * This is name of the report on errors and problems during the operation. This report
         * contains all the problems or conflicts that occurred during generate/update that
         * need to be addressed, for example, missing targets, locked nodes, or checked out
         * nodes.
         * <br>
         * This file is saved as an attachment on the top-level process element on which the
         * assembly tree was generated/updated.
         * <br>
         */
        std::string logFileName;
        /**
         * This flag is used to create a run-time statistic log for IPA generation.
         */
        bool isLogFileNeeded;
        /**
         * List of recipients to be added in 'To' list of the e-mail notification.
         */
        std::vector< std::string > mailToReceivers;
        /**
         * List of recipients to be added in 'Cc' list of the e-mail notification.
         */
        std::vector< std::string > mailCcReceivers;
        /**
         * The subject of the e-mail notification.
         */
        std::string mailSubject;
        /**
         * The message content of the e-mail notification.
         */
        std::string mailMessage;
    };

    /**
     * ServiceData element, appearance path root window along with its type which was generated
     * during the operation and the log file details and its ticket. The newly created occurrence
     * groups from the process strcture and appearance path root of the product strcuture
     * is added to the Created object list of ServiceData. Partial errors occurred in the
     * operation are added to ServiceData.
     */
    struct GenerateIPATreeResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The appearance window which was created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  productWindowAppPathRoot;
        /**
         * The type of appearance window which was created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  appPathRootType;
        /**
         * The details of the log file ticket.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::FileTicketDetails logFileTicket;
    };

    /**
     * ServiceData element, flag indicating whether IPA tree exists for the process structure
     * and ticket of configuration file if the IPA tree exists for the structure. Partial
     * errors occurred in Teamcenter internal APIs during the operation are returned in
     * ServiceData.
     */
    struct IPAExistResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The flag indicating whether IPA tree exists for the process structure.
         */
        bool isIPAExist;
        /**
         * The ticket of configuration file. This file is saved as an attachment on the top-level
         * process element on which the assembly tree was generated/updated. This file contains
         * information about all the configured product structures consumed in the process structure.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::FileTicketDetails configFileTicket;
    };

    /**
     * All the details for IPA generation that includes the name of the IPA, process types,
     * consumption types, occurrence group type, effectivity, email notification details
     * etc.
     */
    struct IPATreeInput
    {
        /**
         * The configuration details about the IPA generation which includes details of process
         * structure, consumption types, occurrence group types and effectivity details.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::ConfigDetails configDetails;
        /**
         * The e-mail notification details like recipients of the e-mail, subject and content
         * of the message.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::EmailNotificationDetails emailDetails;
    };

    /**
     * ServiceData element, the log file name and its ticket. The updated occurrence groups
     * from the process structure and appearance path root of the product structure is added
     * to the Updated object list of ServiceData. Partial errors occurred in the operation
     * are added to ServiceData.
     */
    struct LocalUpdateIPATreeResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The details about the log file ticket.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Ipamanagement::FileTicketDetails logFileticket;
    };




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


protected:
    virtual ~Ipamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

