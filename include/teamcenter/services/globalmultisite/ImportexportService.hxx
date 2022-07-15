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

#ifndef TEAMCENTER_SERVICES_GLOBALMULTISITE_IMPORTEXPORTSERVICE_HXX
#define TEAMCENTER_SERVICES_GLOBALMULTISITE_IMPORTEXPORTSERVICE_HXX

#include <teamcenter/services/globalmultisite/_2007_06/Importexport.hxx>
#include <teamcenter/services/globalmultisite/_2007_12/Importexport.hxx>
#include <teamcenter/services/globalmultisite/_2008_06/Importexport.hxx>
#include <teamcenter/services/globalmultisite/_2010_04/Importexport.hxx>
#include <teamcenter/services/globalmultisite/_2011_06/Importexport.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/globalmultisite/GlobalMultiSite_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Globalmultisite
        {
            class ImportexportService;

/**
 * The <code>ImportExport</code> service exposes operations that are used to execute
 * PLMXML import/export operations and maintains related objects using in import/export
 * (closure rule, filter rule, property set...)
 * <br>
 * <br>
 * This service provides following import export use case for the specified Teamcenter
 * objects or PLMXML administration object.
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Creation or update transfer modes, closure rules, filter rules, property
 * sets...
 * </li>
 * <li type="disc">Import xml file to Teamcenter.
 * </li>
 * <li type="disc">Export Teamcenter objects to xml file.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaglobalmultisitestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaglobalmultisitetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAGLOBALMULTISITESTRONGMNGD_API ImportexportService
    : public Teamcenter::Services::Globalmultisite::_2007_06::Importexport,
             public Teamcenter::Services::Globalmultisite::_2007_12::Importexport,
             public Teamcenter::Services::Globalmultisite::_2008_06::Importexport,
             public Teamcenter::Services::Globalmultisite::_2010_04::Importexport,
             public Teamcenter::Services::Globalmultisite::_2011_06::Importexport
{
public:
    static ImportexportService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This is the test service.
     *
     * @return
     *         This service allways returns hadrcoded value ZERO
     *
     */
    virtual int foo (  ) = 0;

    /**
     * This operation returns a list of sites registered for the requested type of transfer.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param siteType
     *        Following type of transfer supported by a site:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>&nbsp;&nbsp;&nbsp;&nbsp;</b>GMS<b> </b>         Sites participating
     *        in Global MultiSite
     *        </li>
     *        <li type="disc">  PLM          Non Global MultiSite sites or external application
     *        sites mentorBSLib,
     *        </li>
     *        </ul>
     *        <br>
     *        mentorPadsLib, mentorExpLib, cadenceLib, orcadLib, zukenCR5000Lib,
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *        zukenCadStarLib, altiumDesLib, altiumPcadLib, mentorEDXLib, cadenceADWLib
     *        <br>
     *        <ul>
     *        <li type="disc"> Offline       GMS Sites participating in briefcase transfer
     *        </li>
     *        </ul>
     *
     * @return
     *         List of sites of particular type is returned in the plain list of the ServiceData.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getRemoteSites ( const std::string&  siteType ) = 0;

    /**
     * This operation exports objects to specified sites using Global Multisite.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation gets invoked from RAC when user does following actions from Navigator
     * or structure manager
     * <br>
     * 1>&nbsp;&nbsp;&nbsp;&nbsp;Tools->Export->To Remote Site Via Global Services.
     * <br>
     * 2>&nbsp;&nbsp;&nbsp;&nbsp;Tools->Export->To PDX
     * <br>
     * 3>&nbsp;&nbsp;&nbsp;&nbsp;Tools->Export->To Briefcase
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param reason
     *        The reason for remote export. This has limit of 240.
     *
     * @param sites
     *        A list of sites to which object(s) need to be exported.
     *
     * @param objects
     *        Objects to be exported
     *
     * @param optionSet
     *        A reference to <b>TransferOptionSet</b> object which is selected by the user. This
     *        object holds the list of options and their default values which can influence the
     *        contents of the exported briefcase or PDX or on-line export.
     *
     * @param optionNameAndValues
     *        This is the list of options and values that user has overridden from the <b>TransferOptionSet</b>
     *        object specified above. E.g option name 'opt_all_ds_files' (Export all dataset files)
     *        has default value as True in Transfer option set. If use does not want to export
     *        all dataset he can override it to false.
     *
     * @param sessionOptionNamesAndValues
     *        This is the list of session options and values (options which are not part of the
     *        option set). E.g 1) If user wants to run export in dry run mode then session option
     *        'dry_run' needs to be specified and its value should be 'True'. 2)If user wants to
     *        export unconfigured variants then 'processUnconfiguredVariants' should be set to
     *        'True'.
     *
     * @return
     *         The message ID for all the objects for which remote export transfer gets initiated
     *         through Global Services. If any error is encountered then it is stored in partial
     *         error of ServiceData. Following are possible errors:-
     *         <br>
     *         <ul>
     *         <li type="disc">105005:- Error while logging to global services.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;105039:- Cannot change site ownership in
     *         the offline transfer mode
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;203409:- Transfer Option Sets could not be
     *         retrieved.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_12::Importexport::CallToRemoteSiteResponse requestExportToRemoteSites ( const std::string&  reason,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& sites,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  optionSet,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& optionNameAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptionNamesAndValues ) = 0;

    /**
     * This operation imports objects to specified sites using Global Multisite.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is not in use.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param reason
     *        The reason of Import. This has limit of 240 characters.
     *
     * @param owningSitesAndObjs
     *        A list of owning site and corresponding objects that need to be imported.
     *
     * @param optionSet
     *        A reference to <b>TransferOptionSet</b> object which is selected by the user. This
     *        object holds the list of options and their default values which can influence the
     *        result of import.
     *
     * @param optionNamesAndValues
     *        This is the list of options and values that user has overridden from the <b>TransferOptionSet</b>
     *        object specified above.
     *
     * @param sessionOptionNamesAndValues
     *        This is the list of session options and values (options which are not part of the
     *        option set).
     *
     * @return
     *         The message ID for all the objects for which remote export transfer gets initiated
     *         through Global Services. Errors are returned in ServiceData. Following are possible
     *         errors:-
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;105005 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         Error while logging to global services.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;105039&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         Cannot change site ownership in the offline transfer mode
     *         </li>
     *         <li type="disc">  203409&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Transfer
     *         Option Sets could not be retrieved.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2007_12::Importexport::CallToRemoteSiteResponse requestImportFromRemoteSites ( const std::string&  reason,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::OwningSiteAndObjs >& owningSitesAndObjs,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  optionSet,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptionNamesAndValues ) = 0;

    /**
     * Exports the objects to an offline package called briefcase. This operation returns
     * a structure which includes the briefcase's FMS file ticket and exporter log file's
     * FMS ticket. The briefcase ticket is used for downloading the briefcase file from
     * the server to the client side by using FMS utility. Exporter log ticket is used for
     * downloading the exporter log.
     * <br>
     * The briefcase is a package contains an exported TC XML file and a set of physical
     * dataset files. The TC XML file holds the exported objects traversed by TC XML Export
     * framework with the input <b>TransferOptionSet</b> and options, session options.
     * <br>
     * Exporter log include the exporting status of the related objects.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can set a list of root objects, a destination site, a transfer option set, a
     * list of traverse options and a list of session options. All the objects which can
     * be traversed by the option set and options will be exported into an output TC XML
     * file. The physical Iman files related exported dataset objects will be downloaded
     * and packed into the briefcase file along with the TC XML file.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param reason
     *        The reason for the export, the size is limited to 240 characters.
     *
     * @param sites
     *        The destination sites, only one site is supported as of now. The site should be marked
     *        as offline in Organization application to perform a Briefcase export.
     *
     * @param objects
     *        List of root objects to be exported.
     *
     * @param optionSetTag
     *        A reference to the <b>TransferOptionSet</b> object, this object holds the list of
     *        options and their default values which can influence the contents of the exported
     *        briefcase.
     *
     * @param optionNamesAndValues
     *        A list of all the option set options names and values. This is the list of options
     *        and values that overrides the values from the optionSetTag.
     *        <br>
     *        For example: there is an option in <b>TransferOptionSet</b>, which is used to control
     *        if exporting the configured assembly or not. The default value in the TransferOptionSet
     *        is false. A replaced value can be transferred by adding the option with new value
     *        of true.
     *        <br>
     *
     * @param sessionOptionAndValues
     *        A list of all the session option names (options which are not part of the option
     *        set) and values.
     *        <br>
     *        For example: A session option will mark the export is offline or not.
     *        <br>
     *
     * @return
     *         A <b>Dataset</b> with the briefcase file as the namedReference. Also the FMS file
     *         tickets for the briefcase file and the export log file. A new mail is crated which
     *         contains the Dataset and is added to the mailbox folder of the user. The mail will
     *         be sent to the mail box of the user if the email address is set. The <b>Dataset</b>
     *         is also returned in the updated list of the ServiceData. This operation may return
     *         these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">11059    An invalid <b>ItemRevision</b> export selector was supplied
     *         </li>
     *         <li type="disc">105034  There are no target sites.
     *         </li>
     *         <li type="disc">228004  A part file could not be added into the briefcase.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2008_06::Importexport::ExportObjectsToOfflinePackageResponse exportObjectsToOfflinePackage ( const std::string&  reason,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& sites,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSetTag,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& sessionOptionAndValues ) = 0;

    /**
     * This operation imports the data of a briefcase into Teamcenter. A packed briefcase
     * contains a TC XML file which holds a number of Teamcenter objects and related physical
     * dataset files. After import, those objects will be replica in the importing site.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In data exchange, user may transfer a briefcase file from the source site to a remote
     * site. In the importing site, user can use this operation to import the briefcase
     * file into Teamcenter. After import, the objects held in the TC XML file will be created
     * or updated if they have been imported before, physical dataset files will uploaded
     * and attached to the related datasets.
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
     *         The FMS file tickets for the import log file and import error file. New imported
     *         or modified objects are returned in the updated list of the ServiceData. This operation
     *         may return these partial errors:
     *         <br>
     *         <ul>
     *         <li type="disc">11038  Importer has no privilege to update local object since owning
     *         sites are different.
     *         </li>
     *         <li type="disc">11032  Target/Master site passed for import/export is invalid.
     *         </li>
     *         <li type="disc">48043  <b>Item</b> with the same id in importing already exists in
     *         the importing site.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Globalmultisite::_2008_06::Importexport::ImportObjectsFromOfflinePackageResponse importObjectsFromOfflinePackage ( const std::string&  fmsTicket,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferOptionSet>  optionSetTag,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& optionNamesAndValues,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_06::Importexport::NamesAndValue >& sessionOptionAndValues ) = 0;

    /**
     * The <code>exportObjectsToPLMXML</code> operation will generate a PLMXML file and
     * a export log file for the input object list, transfer mode, revision rule and language
     * set.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Export object to PLMXML file</b>
     * <br>
     * You can export any business object by specify:
     * <br>
     * 1)&nbsp;&nbsp;&nbsp;&nbsp;The objects that you want to exported.
     * <br>
     * 2)&nbsp;&nbsp;&nbsp;&nbsp;Transfer mode and revision rule.
     * <br>
     * 3)&nbsp;&nbsp;&nbsp;&nbsp;Languages that for localization value.
     * <br>
     * 4)&nbsp;&nbsp;&nbsp;&nbsp;Xml file name.
     * <br>
     * 5)&nbsp;&nbsp;&nbsp;&nbsp;Session options.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param exportObjects
     *        Objects to be exported.
     *
     * @param transfermode
     *        The transfermode which you want to use to traverse from the objects.
     *
     * @param revRule
     *        Revision Rule that you want to use to traverse bom structure.
     *
     * @param languages
     *        The languages to export with.The language code is used to identify a langauge. It
     *        follows the Java locale naming conventions: 2letterlanguage_2LETTERAREA (e.g: en_US,
     *        fr_FR, de_DE). The language order will be honored and the site master language will
     *        always be included.
     *
     * @param xmlFileName
     *        The file name that you want the xml to be export to.
     *
     * @param sessionOptions
     *        The session options to control export behavior as name-value pairs. This is in place
     *        for future use to pass additional flags to the PLM XML export which can control the
     *        behavior.
     *
     * @return
     *         The output is struct <code>ExportObjectsToPLMXMLResponse</code> with the generated
     *         PLMXML file ticket, export log file ticket, dataset named reference file tickets
     *         if any and soa service data.
     *
     *
     * @exception ServiceException
     *           203331&nbsp;&nbsp;&nbsp;&nbsp;will throw while all input objects is invalid objects.
     *           <br>
     *           203447&nbsp;&nbsp;&nbsp;&nbsp;will throw while fail to get download ticket from FMS.
     *           <br>
     *           Other PIE failure in the whole export process.
     */
    virtual Teamcenter::Services::Globalmultisite::_2010_04::Importexport::ExportObjectsToPLMXMLResponse exportObjectsToPLMXML ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& exportObjects,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  transfermode,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule,
        const std::vector< std::string >& languages,
        const std::string&  xmlFileName,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptions ) = 0;

    /**
     * The <code>importObjectsFromPLMXML</code> operation will import the objects from a
     * PLMXML file. The XML file and the named reference files for datasets should be uploaded
     * to transient volume before the calling of this operation.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Import PLMXML file to database</b>
     * <br>
     * You can import PLMXML file by specify:
     * <br>
     * 1)&nbsp;&nbsp;&nbsp;&nbsp;The xml file that you want to import.
     * <br>
     * 2)&nbsp;&nbsp;&nbsp;&nbsp;The related dataset file you want to import.
     * <br>
     * 3)&nbsp;&nbsp;&nbsp;&nbsp;Transfer mode that you want to traverse to the xml.
     * <br>
     * 4)&nbsp;&nbsp;&nbsp;&nbsp;The incremental change context.
     * <br>
     * 5)&nbsp;&nbsp;&nbsp;&nbsp;Session options.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * PLMXML Import/Export - Capability to export and import PLM XML from/to Teamcenter.
     * It can transform Teamcenter data to PLM XML model and it can transform PLM XML model
     * to Teamcenter business objects using PIE engine and traversal rules.
     *
     * @param xmlFileTicket
     *        The FMS file ticket for the input XML file to be imported.
     *
     * @param namedRefFileTickets
     *        The FMS file tickets for dataset named reference files.
     *
     * @param transfermode
     *        The transfer mode used to control the import process.
     *
     * @param icRev
     *        The incremental change context for the import restuls. The ItemRevision is used to
     *        represent its sub-calss EngChange.
     *
     * @param sessionOptions
     *        The session options to control export behavior as name-value pairs. This is in place
     *        for future use to pass additional flags to the PLM XML export which can control the
     *        behavior.
     *
     * @return
     *         The output is struct <code>ImportObjectsFromPLMXMLResponse</code> with the import
     *         log and soa service data.
     *
     *
     * @exception ServiceException
     *           203474&nbsp;&nbsp;&nbsp;&nbsp;will throw while the input file name is too long.
     *           <br>
     *           Other PIE failure in the whole import process.
     */
    virtual Teamcenter::Services::Globalmultisite::_2010_04::Importexport::ImportObjectsFromPLMXMLResponse importObjectsFromPLMXML ( const std::string&  xmlFileTicket,
        const std::vector< std::string >& namedRefFileTickets,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransferMode>  transfermode,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  icRev,
        const std::vector< Teamcenter::Services::Globalmultisite::_2007_12::Importexport::NamesAndValues >& sessionOptions ) = 0;

    /**
     * This operation takes array of GSIdentityInput structure as input and creates GSIdentity
     * objects in Teamcenter. This operation allows for creation of GSIdentities in bulk
     * which is required for GMS co-existence scenarios following bulk load import of legacy
     * data into Teamcenter.Whenever an object is exported from a source site the record
     * of each imported object is stored in GSIdentity object,which has some basic information
     * of the site that owns the object,the type of the class of imported object and 14
     * digit Unique Identifier string (UID) represtening the object.Every imported object
     * will have a corresponding entry in GSIdentity object.This entry will be used later
     * during a re-import or sychronize operations internally by importer module.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation is used by user to create GSIds for objects imported by bulk loader.It
     * creates GSIds for non GSId based TcXML objects.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param gsIdVect
     *        Input to CreateGSIdentities. The GS identity input structure contains the fields
     *        required to create a GS identity object.
     *
     * @return
     *         A list of GS identity object references.Any failure will be returned as partial errors.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2011_06::Importexport::CreateGSIdentitiesResponse createGSIdentities ( const std::vector< Teamcenter::Services::Globalmultisite::_2011_06::Importexport::TIEGSIdentityInput >& gsIdVect ) = 0;

    /**
     * This operation takes a hash key as input and generates a valid Teamcenter Unique
     * Identifier  a 14 character long unique string UID based on it. For migrating data
     * from legacy systems to Teamcenter using bulk load import of TC XML, this operation
     * can be used to generate UIDs for legacy objects. The UID is composed by using Fowler
     * Noll Vo (FNV) hash algorithm for an arbitrary and unique input string.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This is used during data migration between legacy system such as Enterpise to Teamcenter
     * .
     * <br>
     * Used by the importer to generate a UID.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * TcXMLimportexportengine - Capability to import and export XML that follows the TC
     * Business Object Model. No hardcoded transformation is done. Transformations when
     * needed are supported by the mapper component
     *
     * @param ownSiteId
     *        The owning site-id or source site Id
     *
     * @param hashKey
     *        The input hash key,arbitary unique input string.
     *
     * @return
     *         A unique hashed uid generated by taking the hash key and site id as input.Any failure
     *         will be returned as partial errors.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Globalmultisite::_2011_06::Importexport::GetHashedUIDResponse getHashedUID ( int ownSiteId,
        const std::string&  hashKey ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImportexportService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/globalmultisite/GlobalMultiSite_undef.h>
#endif

