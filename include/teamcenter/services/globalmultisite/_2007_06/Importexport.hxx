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

#ifndef TEAMCENTER_SERVICES_GLOBALMULTISITE__2007_06_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_GLOBALMULTISITE__2007_06_IMPORTEXPORT_HXX

#include <teamcenter/soa/client/model/ClosureRule.hxx>
#include <teamcenter/soa/client/model/Filter.hxx>
#include <teamcenter/soa/client/model/Group.hxx>
#include <teamcenter/soa/client/model/ImanFile.hxx>
#include <teamcenter/soa/client/model/PIEActionRule.hxx>
#include <teamcenter/soa/client/model/POM_imc.hxx>
#include <teamcenter/soa/client/model/PropertySet.hxx>
#include <teamcenter/soa/client/model/Role.hxx>
#include <teamcenter/soa/client/model/TransferMode.hxx>
#include <teamcenter/soa/client/model/TransferOptionSet.hxx>
#include <teamcenter/soa/client/model/User.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/globalmultisite/GlobalMultiSite_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Globalmultisite
        {
            namespace _2007_06
            {
                class Importexport;

class TCSOAGLOBALMULTISITESTRONGMNGD_API Importexport
{
public:

    struct CreateOrUpdateActionRuleInputData;
    struct CreateOrUpdateActionRuleResponse;
    struct CreateOrUpdateClosureRuleInputData;
    struct CreateOrUpdateClosureRuleResponse;
    struct CreateOrUpdateFilterRuleInputData;
    struct CreateOrUpdateFilterRuleResponse;
    struct CreateOrUpdatePropertySetInputData;
    struct CreateOrUpdatePropertySetRuleResponse;
    struct CreateOrUpdateTransferModeInputData;
    struct CreateOrUpdateTransferModeResponse;
    struct CreateOrUpdateTransferOptionSetInputData;
    struct CreateOrUpdateTransferOptionSetResponse;
    struct GetActionRulesResponse;
    struct GetAllTransferOptionSetsResponse;
    struct GetAvailableTransferOptionSetsInputData;
    struct GetAvailableTransferOptionSetsResponse;
    struct GetClosureRulesResponse;
    struct GetFilterRulesResponse;
    struct GetPLMXMLRuleInputData;
    struct GetPropertySetsResponse;
    struct GetTransferModesResponse;
    struct NamesAndValue;
    struct OptionInputData;
    struct RequestImportFromOfflinePackageResponse;

    /**
     * The <code>CreateOrUpdateActionRuleInputData</code> specifies complete data for creating
     * an action rule.
     */
    struct CreateOrUpdateActionRuleInputData
    {
        /**
         * The name of the action rule which can be 32 characters long.
         */
        std::string name;
        /**
         * The description of the action rule which can be 240 characters long.
         */
        std::string description;
        /**
         * The action rule is for import or export.  The value can be "IMPORT" or "EXPORT".
         */
        std::string scope;
        /**
         * The schema for the imported/exported xml file. The value can be "TCXML" or "PLMXML".
         */
        std::string schemaFormat;
        /**
         * The  location where the action happens. The value could be "PREACTION", "DURINGACTION"
         * or "POSTACTION".
         */
        std::string actionLocation;
        /**
         * The Function handler which will be invoked when this rule is executed. For how to
         * create a function for a action rule, please refer to PLM XML Import Export Administration
         * Guide.
         */
        std::string actionName;
        /**
         * Holds the reference of the action rule in case of modification.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PIEActionRule>  actionRuleToUpdate;
    };

    /**
     * The <code>CreateOrUpdateActionRuleResponse</code> structure defines the response
     * from <code>createOrUpdateActionRules</code> operation. It contains vector of action
     * rule object references that were created on the server.
     */
    struct CreateOrUpdateActionRuleResponse
    {
        /**
         * A list of created or modified action rule objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PIEActionRule>  > actionRuleObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>CreateOrUpdateClosureRuleInputData</code> specifies complete data for creating
     * a closure rule.
     */
    struct CreateOrUpdateClosureRuleInputData
    {
        /**
         * The name of the closure rule which can be 32 characters long.
         */
        std::string name;
        /**
         * The description of the closure rule which can be 240 characters long.
         */
        std::string description;
        /**
         * The closure rule is for import or export.  The value can be "IMPORT" or "EXPORT".
         */
        std::string scope;
        /**
         * The schema for the imported/exported xml file. The value can be "TCXML" or "PLMXML".
         */
        std::string schemaFormat;
        /**
         * The comments for every clause in this closure rule which can be 240 characters long.
         */
        std::vector< std::string > comments;
        /**
         * The depth for every clause in this closure rule.
         */
        std::vector< int > depth;
        /**
         * The clause contents of closure rule which can be 240 characters long.
         */
        std::vector< std::string > clauses;
        /**
         * Holds the reference of the closure rule in case of modification.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ClosureRule>  closureRuleToUpdate;
    };

    /**
     * The <code>CreateOrUpdateClosureRuleResponse</code> structure defines the response
     * from <code>createOrUpdateClosureRules</code> operation. It contains vector of closure
     * rule object references that were created on the server.
     */
    struct CreateOrUpdateClosureRuleResponse
    {
        /**
         * A list of created or modified closure rule objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ClosureRule>  > closureRuleObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>CreateOrUpdateFilterRuleInputData</code> specifies complete data for creating
     * a filter rule.
     */
    struct CreateOrUpdateFilterRuleInputData
    {
        /**
         * The name of the filter rule which can be 32 characters long.
         */
        std::string name;
        /**
         * The description of the filter rule which can be 240 characers long.
         */
        std::string description;
        /**
         * The filter rule is for import or export. The value can be "IMPORT" or "EXPORT".
         */
        std::string scope;
        /**
         * The schema for the imported/exported xml file. The value can be "TCXML" or "PLMXML".
         */
        std::string schemaFormat;
        /**
         * The  clauses contents of filter rule which can be 128 characters long.
         */
        std::vector< std::string > clauses;
        /**
         * Holds the reference of the filter rule in case of modification.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Filter>  filterRuleToUpdate;
    };

    /**
     * The <code>CreateOrUpdateFilterRuleResponse</code> structure defines the response
     * from <code>createOrUpdateFilterRules</code> operation. It contains vector of filter
     * rule object references that were created on the server.
     */
    struct CreateOrUpdateFilterRuleResponse
    {
        /**
         * A list of created or modified filter rule objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Filter>  > filterRuleObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>CreateOrUpdatePropertySetInputData</code> specifies complete data for creating
     * a property set.
     */
    struct CreateOrUpdatePropertySetInputData
    {
        /**
         * The name of the property set which can be 32 characters long.
         */
        std::string name;
        /**
         * The description of the property set which can be 240 characters long.
         */
        std::string description;
        /**
         * The property set is for import or export. The value can be "IMPORT" or "EXPORT".
         */
        std::string scope;
        /**
         * The clause contents of property set which can be 128 characters long.
         */
        std::vector< std::string > clauses;
        /**
         * Holds the reference of the property set in case of modification.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PropertySet>  propertySetToUpdate;
    };

    /**
     * The <code>CreateOrUpdatePropertySetResponse</code> structure defines the response
     * from createOrUpdatePropertySets operation. It contains vector of property sets object
     * references that were created on the server.
     */
    struct CreateOrUpdatePropertySetRuleResponse
    {
        /**
         * A list of created or modified property set objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PropertySet>  > propertySetObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>CreateOrUpdateTransferModeInputData</code> specifies complete data for
     * creating a transfer mode.
     */
    struct CreateOrUpdateTransferModeInputData
    {
        /**
         * The name of the transfer mode which can be 128 characters long.
         */
        std::string name;
        /**
         * The description of the transfer mode which can be 240 characters long.
         */
        std::string description;
        /**
         * The context string used in export/import. The value can be 240 characters long.
         */
        std::string contextString;
        /**
         * Defines the transfer mode is for import or export.  The value can be "IMPORT" or
         * "EXPORT".
         */
        std::string direction;
        /**
         * The schema for the imported/exported xml file. The value can be "TCXML" or "PLMXML".
         */
        std::string schemaFormat;
        /**
         * Specifies whether transfermode can be used in incremental data transfer or not.
         */
        bool isIncremental;
        /**
         * Specifies whether transfermode is multisite or not.
         */
        bool isMultiSite;
        /**
         * The closure rule reference for the transfer mode.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ClosureRule>  closurerule;
        /**
         * The filter rule reference for the transfer mode.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Filter>  filter;
        /**
         * The property set reference for the transfer mode.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PropertySet>  propertyset;
        /**
         * The style sheet file reference for the transfer mode.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanFile>  > xsltFiles;
        /**
         * The revision rule reference for the transfer mode.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > configObjs;
        /**
         * The action rule reference for the transfer mode.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > actionList;
        /**
         * Holds the reference of the transfer mode in case of modification.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  tmToUpdate;
    };

    /**
     * The <code>CreateOrUpdateTransferModeResponse</code> structure defines the response
     * from <code>createOrUpdateTransferModes</code> operation. It contains vector of transfer
     * mode object references that were created on the server.
     */
    struct CreateOrUpdateTransferModeResponse
    {
        /**
         * A list of created or modified transfer mode objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  > transferModeObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The CreateOrUpdateTransferOptionSetInputData structure defines the input data for
     * creating a TransferOptionSetObject.
     */
    struct CreateOrUpdateTransferOptionSetInputData
    {
        /**
         * The name of the transfer opton set.
         */
        std::string name;
        /**
         * The description of the transfer opton set.
         */
        std::string description;
        /**
         * Specifies whether it is public or private. If the value is true, the transfer option
         * set will be visibale and used for all user.
         */
        bool publiclyVisible;
        /**
         * Specifies the site reference (local site or remote site).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_imc>  siteId;
        /**
         * Specifies the transfer mode reference.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  transfermode;
        /**
         * The vector of options (See OptionInputData structure).
         */
        std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::OptionInputData > options;
        /**
         * This holds the reference to transfer option set object in case of modification.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSetObjectToModify;
    };

    /**
     * The CreateOrUpdateTransferOptionSetResponse structure defines the response from createOrUpdateTransferOptionSets
     * operation. It contains vector of TransferOptionSet object references that were created
     * on the server.
     */
    struct CreateOrUpdateTransferOptionSetResponse
    {
        /**
         * A list of created or modified transfer option set objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  > transferOptionSets;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetActionRulesResponse</code> structure defines the response from <code>getActionRules</code>
     * operation. It contains vector of action rule object references that were created
     * on the server that satisfy the input criteria scope and schema format.
     */
    struct GetActionRulesResponse
    {
        /**
         * A list of action rule objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PIEActionRule>  > actionRuleObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetAllTransferOptionSetsResponse</code> structure defines the response
     * from <code>getAllTransferOptionSets</code> operation. It contains vector of transfer
     * option set object references that were present on the server.
     */
    struct GetAllTransferOptionSetsResponse
    {
        /**
         * A list of transfer option sets.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  > optionSetObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure <code>GetAvailableTransferOptionSetsInputData</code> defines input
     * criteria for the operation <code>getAvailableTransferOptionSets</code>. The values
     * of <code>isPush</code>, <code>isExport</code> are to be known before calling this
     * operation.
     * <br>
     * <br>
     * Case 1: Remote Export&nbsp;&nbsp;&nbsp;&nbsp;- on-line  --- <code>isPush</code> =
     * True   <code>isExport</code> = True
     * <br>
     * Case 2: Remote Import&nbsp;&nbsp;&nbsp;&nbsp;- on-line  --- <code>isPush</code> =
     * False  <code>isExport</code> = True
     * <br>
     * Case 3: Briefcase Export - off-line --- <code>isPush</code> = True   <code>isExport</code>
     * = True
     * <br>
     * case 4: Briefcase Import - off-line --- isPush = NA&nbsp;&nbsp;&nbsp;&nbsp; isExport
     * = False
     * <br>
     * <br>
     * For 2007.1, the site can not be more than one for the Push case. The access rules
     * will be evaluated thru RBF (Rules Based Framework) for the given user, group, role
     * and all the option sets that satisfy the criteria will be returned
     */
    struct GetAvailableTransferOptionSetsInputData
    {
        /**
         * The user reference that executing this API.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  user;
        /**
         * The group reference that the executing user belongs to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Group>  group;
        /**
         * The role reference that the executing user belongs to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Role>  role;
        /**
         * The site that the user want to export to.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_imc>  > site;
        /**
         * Option that control the online or offline.
         */
        bool isPush;
        /**
         * Option that control the data transfer direction.
         */
        bool isExport;
    };

    /**
     * The <code>GetAvailableTransferOptionSetsResponse</code> structure defines the response
     * from <code>getAvailableTransferOptionSets</code> operation. It contains vector of
     * transfer option set object references that satisfies the input criteria.
     */
    struct GetAvailableTransferOptionSetsResponse
    {
        /**
         * A list of transfer option set objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  > optionSetObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetClosureRulesResponse</code> structure defines the response from <code>getClosureRules</code>
     * operation. It contains vector of closure rule object references that were created
     * on the server that satisfy the input criteria scope and schema format.
     */
    struct GetClosureRulesResponse
    {
        /**
         * A list of closure rule objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ClosureRule>  > closureRuleObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetFilterRulesResponse</code> structure defines the response from<code>
     * getFilterRules</code> operation. It contains vector of filter rule object references
     * that were created on the server that satisfy the input criteria scope and schema
     * format.
     */
    struct GetFilterRulesResponse
    {
        /**
         * A list of filter rule objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Filter>  > filterRuleObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure <code>GetPLMXMLRuleInputData</code> is used for many operations related
     * to PLMXML Admin application. This structure specifies input criteria for get list
     * methods for Transfermode, closure rule, filter rule action rule. The get list operation
     * is expected to return all rule objects based on the given scope and schema format.
     */
    struct GetPLMXMLRuleInputData
    {
        /**
         * The direction that scope rule is used. The allowed values are"EXPORT", "IMPORT" or
         * "ALL". When the value is "EXPORT", only export based scope rules will be queried.
         * Value "ALL" implies both export and import scope rules will be queried.
         */
        std::string scope;
        /**
         * The schema format associated with the scope rule. The allowed values are "PLMXML"
         * or  "TCXML" or "ALL". When the value is "PLMXML", only PLMXML based scope rules will
         * be queried. Value "ALL" implies both PLMXML and TCXML scope rules will be queried.
         */
        std::string schemaFormat;
    };

    /**
     * The <code>GetPropertySetsResponse</code> structure defines the response from<code>
     * getPropertySets</code> operation. It contains vector of property set object references
     * that were created on the server that satisfy the input criteria scope. (Schema format
     * is not applicable in input)
     */
    struct GetPropertySetsResponse
    {
        /**
         * A list of property set objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PropertySet>  > propertySetObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>GetTransferModesResponse</code> structure defines the response from <code>getTransferModes</code>
     * operation. It contains vector of transfer mode object references that were created
     * on the server that satisfy the input criteria scope and schema format.
     */
    struct GetTransferModesResponse
    {
        /**
         * A list of transfer mode objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  > transferModeObjects;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * NameAndValue structure represents a generic name-value pair
     */
    struct NamesAndValue
    {
        /**
         * The name of the name-value pair
         */
        std::string name;
        /**
         * The value of the name-value pair
         */
        std::string value;
    };

    /**
     * Transfer Option Set is a the object which holds complete configuration information
     * about the data transfer. It is basically collection of options. Options are grouped
     * in UI to give better readability for the options The options will be grouped in GUI
     * based on the group name. The default values will be true or false for 2007.1. If
     * the readOnlyFlag is set on a particular option only "dba" can override the value
     * during transfer. it will be shown to the regular user but read-only  The OptionInputData
     * structure defines complete data for one option (Symbol)
     */
    struct OptionInputData
    {
        /**
         * The real variable name that used in code.
         */
        std::string realName;
        /**
         * Specify the name that user see in the transfer option setting .
         */
        std::string displayName;
        /**
         * The description for the transfer option.
         */
        std::string description;
        /**
         * The group that the tranfer option belongs to in the whole transfer option set.
         */
        std::string groupName;
        /**
         * The default value for this transfer option.
         */
        std::string defaultValue;
        /**
         * Specify that wheter this transfer option is modified in transfer option setting.
         * If the value is true, this option will be unmodifiable in the transfer option setting.
         */
        bool readOnlyFlag;
    };

    /**
     * RequestImportFromOfflinePackageResponse structure defines the response from requestImportFromOfflinePackage
     * operation. It contains message Id of the request and partial errors and objects that
     * are imported.
     */
    struct RequestImportFromOfflinePackageResponse
    {
        /**
         * Message Id of this request, to be used to check the status import seesion run at
         * Global Service.
         */
        std::string msgId;
        /**
         * Service data contains the list of created or modified objects and also the partial
         * errors listed above in case of failure conditions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation imports the contents of the briefcase container into database by placing
     * a request to the Global Services (GS) components. This operation is very much similar
     * to <i>importObjectsFromOfflinePackage</i> with the exception that this operation
     * is used in GS enabled environment whereas <i>importObjectsFromOfflinePackage</i>
     * operation is used in Non GS environment. A packed briefcase contains a TC XML file
     * which holds a serious of Teamcenter objects and related physical dataset files. After
     * import, those objects will be replica in the importing site.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In data exchange, user may transfer a briefcase file from the source site to a remote
     * site. In the importing site, user can use this operation to import the briefcase
     * file into the Teamcenter. After import, the objects held in the TC XML file will
     * be created or updated if they have been imported before, physical dataset files will
     * uploaded and attached to the related datasets.
     * <br>
     * The SOA needs the GS (Global Service) been configured for the importing site.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param fmsTicket
     *        The FMS file ticket for the briefcase file, the file should be uploaded to the server
     *        before calling this operation.
     *
     * @param optionSetTag
     *        A reference to the <b>TransferOptionSet</b> object, this object holds the list of
     *        options and their default values which can influence importing briefcase.
     *
     * @param optionNamesAndValues
     *        A list of all the option set options names and values. This is the list of options
     *        and values that overrides the values from the optionSetTag.
     *        <br>
     *        For example: there is an option in TransferOptionSet, opt_imp_XXX. The default value
     *        in the TransferOptionSet is false. A replaced value can be transferred by adding
     *        the option with new value of true.
     *        <br>
     *
     * @param sessionOptionAndValues
     *        A list of all the session option names (options which are not part of the option
     *        set) and values.
     *        <br>
     *        For example: A session option modified_objects_only will mark the import is only
     *        importing modified object or not.
     *        <br>
     *
     * @return
     *         A message id of this request. New imported or modified objects are returned in the
     *         updated list of the ServiceData. This operation may return these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">105006  Error while logging to global services.
     *         </li>
     *         <li type="disc">105007  Error while invoking global services method.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::RequestImportFromOfflinePackageResponse requestImportFromOfflinePackage ( const std::string&  fmsTicket,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSetTag,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& sessionOptionAndValues ) = 0;

    /**
     * Creates or updates an action rule based on input parameters. Action rule in the PLM
     * XML framework is used to invoke additional actions before/during/after import/export.
     * For more information on action rules, please refer to PLM XML Import Export Administration
     * Guide.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Modify an Action Rule</b>
     * <br>
     * The following types of modifications can be done on existing action rule using <code>createOrUpdateActionRules</code>
     * operation:
     * <br>
     * <ul>
     * <li type="disc">Change the rule description.
     * </li>
     * <li type="disc">Change the action handler. This means that we can change the action
     * rule's clause to invoke a different action than what was initially assigned.
     * </li>
     * <li type="disc">Change the action location. This means we can change action location
     * from pre-action to post-action etc.
     * </li>
     * <li type="disc">Change the schema format. This means we can change the action rule
     * from PLM XML schema based one to TC XML schema.
     * </li>
     * <li type="disc">Change data transfer direction scope. This means we can change the
     * direction from export to import and vice-versa.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Vector containing data for creation or modification of action rule.
     *
     * @return
     *         A listed created or modified action rule objects. The following partial errors may
     *         be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If the schemaFormat is not in the allowed values.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If the scope is not in the allowed values.
     *         <br>
     *         203426&nbsp;&nbsp;&nbsp;&nbsp;If the action location is not in the allowed values.
     *         <br>
     *         203316&nbsp;&nbsp;&nbsp;&nbsp;If  the operation fails to create action rule.
     *         <br>
     *         203413&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to modify the given action rule.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateActionRuleResponse createOrUpdateActionRules ( const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateActionRuleInputData >& inputs ) = 0;

    /**
     * Creates or updates a closure rule based on input parameters. Closure rule specify
     * how the data structure is traversed by specifying which relationships are of interest
     * and what should be done when these relationships are encountered. For more information,
     * please refer to PLM XML Import Export Administration Guide.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Modify a Closure Rule</b>
     * <br>
     * The following types of modifications can be done on existing closure rule using <code>createOrUpdateClosureRules</code>
     * operation:
     * <br>
     * <ul>
     * <li type="disc">Change the closure rule description.
     * </li>
     * <li type="disc">Change schema format. This means we can change the closure rule from
     * PLM XML schema based one to TC XML schema.
     * </li>
     * <li type="disc">Change transfer direction. This means we can change the direction
     * from export to import and vice-versa.
     * </li>
     * <li type="disc">Change clause contents, depth and comments for each clause. You can
     * change detailed clauses in this closure rule. For more information to how to write
     * clauses, please refer to PLM XML Import Export Administration Guide.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Vector containing data for creation or modification of closure rule.
     *
     * @return
     *         A list of created or modified closure rule objects. The following partial errors
     *         may be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If the schemaFormat is not in the allowed values.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If the scope is not in the allowed values.
     *         <br>
     *         203307&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to create closure rule.
     *         <br>
     *         203411&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to modify closure rule.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateClosureRuleResponse createOrUpdateClosureRules ( const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateClosureRuleInputData >& inputs ) = 0;

    /**
     * Creates or updates a filter rule based on input parameters. Filter rules allow a
     * finer level of control over the data that gets translated along with the primary
     * objects by specifying that a user-written function is called to determine the operation
     * applied against a given object. For more information, please refer to PLM XML Import
     * Export Administration Guide.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Modify a Filter Rule</b>
     * <br>
     * The following types of modifications can be done on existing filter rule using <code>createOrUpdateFilterRules</code>
     * operation:
     * <br>
     * <ul>
     * <li type="disc">Change the filter rule description.
     * </li>
     * <li type="disc">Change clauses. For more information about how to write clause, please
     * refer to PLM XML Import Export Administration Guide.
     * </li>
     * <li type="disc">Change schema format. This means we can change the filter rule from
     * PLM XML schema based one to TC XML schema.
     * </li>
     * <li type="disc">Change data transfer direction scope. This means we can change the
     * direction from export to import and vice-versa.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Vector containing data for creation or modification of filter rule.
     *
     * @return
     *         A list of created or modified filter rule objects. The following partial errors may
     *         be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If the schemaFormat is not in the allowed values.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If the scope is not in the allowed values.
     *         <br>
     *         203309&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to create filter rule.
     *         <br>
     *         203416&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to modify filter rule.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateFilterRuleResponse createOrUpdateFilterRules ( const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateFilterRuleInputData >& inputs ) = 0;

    /**
     * Creates or updates a property set based on input parameters. Property sets provide
     * a non-programmatic way to control what is placed in the <b>UserData</b> element.
     * For more information, please refer to PLM XML Import Export Administration Guide.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Modify a Property Set</b>
     * <br>
     * The following types of modifications can be done on existing property set using <code>createOrUpdatePropertySets</code>
     * operation:
     * <br>
     * <ul>
     * <li type="disc">Change the property set description.
     * </li>
     * <li type="disc">Change data transfer direction scope. This means we can change the
     * direction from export to import and vice-versa.
     * </li>
     * <li type="disc">Change clauses. For more information about how to write clause, please
     * refer to PLM XML Import Export Administration Guide.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Vector containing data for creation or modification of property set.
     *
     * @return
     *         A list of created or modified property set objects. The following partial errors
     *         may be returned:
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If the scope is not in the allowed values.
     *         <br>
     *         203311&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to create property set.
     *         <br>
     *         203417&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to modify property set.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdatePropertySetRuleResponse createOrUpdatePropertySets ( const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdatePropertySetInputData >& inputs ) = 0;

    /**
     * Creates or updates a transfer mode based on input parameters. Transfer modes are
     * created in the PLMXML application. Transfer modes define how to import/export data
     * between PLMXML file and sites. For more information, please refer to PLM XML Import
     * Export Administration Guide.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Modify a Transfer Mode</b>
     * <br>
     * The following types of modifications can be done on existing transfer mode using
     * <code>createOrUpdateTransferModes</code> operation.
     * <br>
     * <ul>
     * <li type="disc">Change the transfer mode description
     * </li>
     * <li type="disc">Change context string. Context string is used to map the transfer
     * mode object to a customized processor for the given object type. For more information,
     * please refer to PLM XML Import Export Administration Guide.
     * </li>
     * <li type="disc">Change data transfer direction scope. This means we can change the
     * direction from export to import and vice-versa.
     * </li>
     * <li type="disc">Change schema format. This means we can change the closure rule from
     * PLM XML schema based one to TC XML schema.
     * </li>
     * <li type="disc">Change Incremental setting.  This option allows updates to existing
     * data during PLM XML import. For example, if an item being imported from an .xml file
     * already exists in the database and "support incremental" is selected, the PLM XML
     * import updates the item. If "support incremental" is not selected, the updates from
     * the .xml file are ignored.
     * </li>
     * <li type="disc">Change closure rule, filter rule, property set, revision rule and
     * action rule which are used by this transfer mode.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Vector containing data for creation or modification of transfer mode.
     *
     * @return
     *         A List of created or modified transfer mode objects. The following partial errors
     *         may be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If the schemaFormat is not in the allowed values.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If the scope is not in the allowed values.
     *         <br>
     *         203305&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to create transfer mode.
     *         <br>
     *         203410&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to modify transfer mode.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateTransferModeResponse createOrUpdateTransferModes ( const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateTransferModeInputData >& inputs ) = 0;

    /**
     * Creates or update a list of transfer option sets based on the input properties structure.
     * The transfer option set contains a set of variables which will control the export/import
     * behavior. For more information, please refer to PLM XML Import Export Administration
     * Guide.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Modify a Transfer Option Set</b>
     * <br>
     * The following types of modifications can be done on existing transfer option set
     * using createOrUpdateTransferOptionSets operation:
     * <br>
     * <ul>
     * <li type="disc">Change the transfer option set description
     * </li>
     * <li type="disc">Change referenced site id. It shows whether the transfer option set
     * is for a remote site, thus an import. If so, its remote site ID is included.
     * </li>
     * <li type="disc">Change the attached transfer mode id.
     * </li>
     * <li type="disc">Change the detail options for the transfer option set. For more information
     * to the options, please refer to PLM XML Import Export Administration Guide.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Vector containing data for creation or modification of transfer option set.
     *
     * @return
     *         1. A List of created or modified transfer option set objects 2. Failure will be returned
     *         via the ServiceData. For details please refer to ServiceException Description.
     *
     *
     * @exception ServiceException
     *           203406&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to create transfer option
     *           set.
     *           <br>
     *           203407&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to modify transfer option set.
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateTransferOptionSetResponse createOrUpdateTransferOptionSets ( const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::CreateOrUpdateTransferOptionSetInputData >& inputs ) = 0;

    /**
     * This operation return a set of action rule objects depending upon input query parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Data that contains info to query action rule objects from the database.
     *
     * @return
     *         1. A List of action rule objects 2. Failure will be returned via the ServiceData.
     *         For details please refer to ServiceException Description.
     *
     *
     * @exception ServiceException
     *           203419&nbsp;&nbsp;&nbsp;&nbsp;If schema input is incorrect.
     *           <br>
     *           203420&nbsp;&nbsp;&nbsp;&nbsp;If the scope input is incorrect.
     *           <br>
     *           203424&nbsp;&nbsp;&nbsp;&nbsp;If the query cannot find action rules.
     *           <br>
     *           203414&nbsp;&nbsp;&nbsp;&nbsp;If the query fails to execute to while fetching the
     *           action rules from database.
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetActionRulesResponse getActionRules ( const Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetPLMXMLRuleInputData&  inputs ) = 0;

    /**
     * This operation return a set of transfer option set objects that were created with
     * scope - public.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @return
     *         A List of transfer option set objects. Failure below will be returned via the ServiceData:
     *         <br>
     *         203409&nbsp;&nbsp;&nbsp;&nbsp;If the operation fails to get any transfer option set.
     *
     *
     * @exception ServiceException
     *           Other exception throwed by called API.
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetAllTransferOptionSetsResponse getAllTransferOptionSets (  ) = 0;

    /**
     * This operation return a set of transfer option set object depending upon input query
     * parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Data that contains info to query transfer option set from the database.
     *
     * @return
     *         A List of transfer option set objects. Failure below will be returned via the ServiceData:
     *         <br>
     *         203409&nbsp;&nbsp;&nbsp;&nbsp;If the query  fails to get any transfer option set.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetAvailableTransferOptionSetsResponse getAvailableTransferOptionSets ( const Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetAvailableTransferOptionSetsInputData&  inputs ) = 0;

    /**
     * This operation return a set of closure rule objects depending upon input query parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Data that contains info to query closure rule objects from the database.
     *
     * @return
     *         A List of closure rule objects. The following partial errors may be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If schema input is incorrect.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If scope input is incorrect.
     *         <br>
     *         203425&nbsp;&nbsp;&nbsp;&nbsp;If the query cannot find closure rules.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetClosureRulesResponse getClosureRules ( const Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetPLMXMLRuleInputData&  inputs ) = 0;

    /**
     * This operation return a set of filter rule objects depending upon input query parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Data that contains info to query filter rule objects from the database.
     *
     * @return
     *         A list of filter rule objects. The following partial errors may be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If schema input is incorrect.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If scope input is incorrect.
     *         <br>
     *         203423&nbsp;&nbsp;&nbsp;&nbsp;If the query cannot find filter rules.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetFilterRulesResponse getFilterRules ( const Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetPLMXMLRuleInputData&  inputs ) = 0;

    /**
     * This operation return a set of property set objects depending upon input query parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Data that contains info to query property set objects from the database.
     *
     * @return
     *         A List of property set objects. The following partial errors may be returned:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If schema input is incorrect.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If scope input is incorrect.
     *         <br>
     *         203422&nbsp;&nbsp;&nbsp;&nbsp;If the query cannot find property sets.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetPropertySetsResponse getPropertySets ( const Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetPLMXMLRuleInputData&  inputs ) = 0;

    /**
     * This operation returns a set of transfer mode objects depending upon input query
     * parameters.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param inputs
     *        Data that contains info to query transfer mode objects from the database.
     *
     * @return
     *         A List of transfer mode objects. Failure below will be returned via the ServiceData:
     *         <br>
     *         203419&nbsp;&nbsp;&nbsp;&nbsp;If schema input is incorrect.
     *         <br>
     *         203420&nbsp;&nbsp;&nbsp;&nbsp;If scope input is incorrect.
     *         <br>
     *         203422&nbsp;&nbsp;&nbsp;&nbsp;If the query cannot find transfer mode.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetTransferModesResponse getTransferModes ( const Teamcenter::Services::Globalmultisite::_2007_06::Importexport::GetPLMXMLRuleInputData&  inputs ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/globalmultisite/GlobalMultiSite_undef.h>
#endif

