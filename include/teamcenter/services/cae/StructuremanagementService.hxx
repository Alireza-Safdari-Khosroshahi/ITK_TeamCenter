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

#ifndef TEAMCENTER_SERVICES_CAE_STRUCTUREMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CAE_STRUCTUREMANAGEMENTSERVICE_HXX

#include <teamcenter/services/cae/_2012_02/Structuremanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/cae/Cae_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cae
        {
            class StructuremanagementService;

/**
 * The <i>StructureManagement</i> service provides operations to create and manage the
 * Computer Aided Engineering (CAE) structures. Given an input BOM structure, the output
 * BOM structure is determined by a combination of XSLT-based <i>DataMap</i> and <i>StructureMap</i>
 * <i>rules</i> executed against the input BOM structure.
 * <br>
 * <br>
 * <i>DataMap rules</i> define the mapping between an input item type and its resulting
 * output item type. <i>DataMap rules</i> are defined for an entire site and are stored
 * in the <i>datamapping.xml</i> file located in <i>TC_DATA</i>.
 * <br>
 * <br>
 * <i>StructureMap rules</i> tailor the output BOM Structure. There are several rule
 * types:
 * <br>
 * <ul>
 * <li type="disc">Filter - Removes input <b>BOMLine</b> objects (and their children)
 * from <i>DataMap</i> evaluation.
 * </li>
 * <li type="disc">Include - Inserts <b>ItemRevision</b> objects in either the input
 * or the output BOM structure as required.
 * </li>
 * <li type="disc">Reuse - Retrieve existing <b>ItemRevision</b> to be used in the output
 * structure.
 * </li>
 * <li type="disc">Create collector - Reorganization rule that creates "container" <b>ItemRevision</b>
 * objects to move <b>BOMLine</b> objects and sub-assemblies around.
 * </li>
 * <li type="disc">Move to Collector - Reorganization rule that moves <b>BOMLine</b>
 * objects and sub-assemblies to collector components.
 * </li>
 * <li type="disc">Collapse Single Component Assembly - Identifying sub-assemblies with
 * a single child component, elevating the child component to the parent sub-assembly
 * and removing the parent sub-assembly.
 * </li>
 * <li type="disc">Remove Empty Assembly - Identifying sub-assemblies with no child
 * components and removing the empty sub-assembly.
 * </li>
 * <li type="disc">Skip - Skips a <b>BOMLine</b> but still process their children.
 * </li>
 * </ul>
 * <br>
 * <br>
 * For more details on building and executing <i>DataMap</i> and <i>StructureMap rules</i>,
 * please refer to the <i>"Creating structure map rules"</i> section in the <i>Simulation
 * Process Management Guide->Using structure maps</i> chapter of the Teamcenter documentation.
 * <br>
 * <br>
 * The operations in this service allow the creation and reorganization of output BOM
 * structure by applying <i>DataMap</i> and <i>StructureMap rules</i>. This service
 * also provides operations to generate a <i>NodeXML</i> for selected <b>BOMLine</b>
 * object(s). <i>NodeXML</i> is XML-based and is most commonly used in the process of
 * creating <i>DataMap</i> and <i>StructureMap rules</i>. The generated <i>NodeXML</i>
 * consists of the visible attributes and their values associated with the <b>Item</b>,
 * <b>ItemRevision</b>, related <b>Form</b> objects and the <b>BOMLine</b>.
 * <br>
 * <br>
 * The <i>StructureManagement</i> service can be used for supporting following use-cases:
 * <br>
 * <ul>
 * <li type="disc">Create an output BOM structure by applying <i>DataMap rules</i>,
 * given a root <b>BOMLine</b> of the input BOM structure along with its configuration.
 * </li>
 * <li type="disc">Create an output BOM structure by applying <i>DataMap rules</i> given
 * a <b>Snapshot</b> folder of the input BOM structure and its <b>VariantRule</b>.
 * </li>
 * <li type="disc">Create an output BOM structure by applying <i>DataMap</i> and <i>StructureMap
 * rules</i>, given a root <b>BOMLine</b> of the input BOM structure along with its
 * configuration.
 * </li>
 * <li type="disc">Create an output BOM structure by applying <i>DataMap</i> and <i>StructureMap
 * rules</i> given a <b>Snapshot</b> folder of the input BOM structure and its <b>VariantRule</b>.
 * </li>
 * <li type="disc">Generate a <i>NodeXML</i> for selected <b>BOMLine</b> object(s) and
 * a selected <b>CAEStructureMap</b> <b>Domain</b> <b>LOV</b> defined in <i>BMIDE</i>.
 * To configure the domains, in the <i>Extensions</i> view in <i>BMIDE</i>, open <b>LOV->StructureMap
 * Domains</b> and add additional domain values.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacaestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacaetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACAESTRONGMNGD_API StructuremanagementService
    : public Teamcenter::Services::Cae::_2012_02::Structuremanagement
{
public:
    static StructuremanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates an output BOM structure given the root <b>ItemRevision</b>
     * of the root <b>BOMLine</b> of an input BOM structure along with its <b>RevisionRule</b>
     * and the <b>VariantRule</b>. A <b>Snapshot</b> folder of the input BOM structure along
     * with the <b>VariantRule</b> can also be provided as an input. The output BOM structure
     * is determined by the XSLT-based <i>DataMap</i> <i>rules</i> executed against the
     * input BOM structure. <i>DataMap</i> syntax is in compliance with the schema defined
     * in <i>tcsim_xslWithNode.xsd</i>, located in <i>TC_DATA</i>.
     * <br>
     * <br>
     * <i>DataMap rules</i> define the mapping between an input item type and its resulting
     * output item type. <i>DataMap rules</i> are defined for an entire site and are stored
     * in the <i>datamapping.xml</i> file located in <i>TC_DATA</i>. The name of the <i>datampping</i>
     * file is defined by the site preference <i>CAE_dataMapping_file</i>.
     * <br>
     * <br>
     * The <i>DataMap rules</i> can be configured for various domains defined as <b>LOV</b>
     * objects under <b>StructureMap Domains</b> in <i>BMIDE</i>. To configure the domains,
     * in the <i>Extensions</i> view in <i>BMIDE</i>, open <b>LOV->StructureMap Domains</b>
     * and add additional domain values. The domain to be used for applying <i>DataMap rules</i>
     * can also be provided as an input.
     * <br>
     * <br>
     * To use this operation, a well-defined <i>datamapping.xml</i> is required in <i>TC_DATA</i>
     * and the user should have either a <b>simulation_author</b> or <b>rtt_author license</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1: <b>Create an output structure given a top BOMLine of the input structure
     * along with its configuration</b>
     * <br>
     * Given an input root <b>BOMLine</b> of a BOM structure, along with its <b>RevisionRule</b>
     * and <b>VariantRule</b>, the user can apply <i>DataMap rule</i> to the BOM structure
     * and generate a corresponding output BOM structure. The output BOM structure would
     * consist of <b>BOMLine</b> occurrences of <b>ItemRevision</b> objects as defined in
     * the <i>datamapping.xml</i> file. The user can review the actions executed with the
     * process log returned with the <b>BOMViewRevision</b>. An email notification containing
     * the activity log would be sent to the current user if the session option for email
     * notification is set to true.
     * <br>
     * <br>
     * Use Case 2: <b>Create an output structure given a Snapshot folder of the input structure
     * along with the variant rule</b>
     * <br>
     * Given a <b>Snapshot</b> folder of the input BOM structure and its <b>VariantRule</b>,
     * the user can apply <i>DataMap rules</i> to the BOM structure and generate a corresponding
     * output BOM structure. The output BOM structure would consist of <b>BOMLine</b> occurrences
     * of <b>ItemRevision</b> objects as defined in the <i>datamapping.xml</i> file. The
     * user can review the actions executed with the process log returned with the <b>BOMViewRevision</b>.
     * An email notification containing the activity log would be sent to the current user
     * if the session option for email notification is set to true.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CAE Integrations - Provides custom extensions to the Tc data model to capture the
     * CAE data model; the services that provide behaviors that are specific to CAE clients
     * and the client side code that accesses the data model and services.
     *
     * @param rootIR
     *        <b>ItemRevision</b> of the root item of the input structure. This can be null if
     *        the <i>snapshotFolder</i> is provided as input to the operation. If the <i>rootIR</i>
     *        is not null and <i>snapshotFolder</i> is also provided as an input, then <i>rootIR</i>
     *        input will be ignored and <i>snapshotFolder</i> will take precedence.
     *
     * @param snapshotFolder
     *        The <b>Snapshot</b> folder of the input structure. The <i>snapshotFolder</i> can
     *        be null if the root <i>rootIR</i> is used as an input to the operation. The <i>snapshotFolder</i>
     *        takes precedence over the <i>rootIR</i>.
     *
     * @param revRule
     *        The <b>RevisionRule</b> of the input structure. This is an optional parameter and
     *        can be provided if the root <b>ItemRevision</b> is used as an input to the operation.
     *        This parameter will be ignored if <i>snapshotFolder</i> is used as an input.
     *
     * @param variantRule
     *        The <b>VariantRule</b> for the input structure. This can be provided for both, the
     *        <i>rootIR</i> or <i>snapshotFolder</i> as input. This is an optional parameter and
     *        can be null.
     *
     * @param domain
     *        The domain for the <i>DataMap rules</i> to be applied. The <i>datamapping.xml</i>
     *        file can be configured for various domains defined as <b>LOV</b> objects under <b>StructureMap
     *        Domains</b> in <i>BMIDE</i>. This argument is used to specify which domain to be
     *        used from the <i>datamapping.xml</i> file. If the value is not provided, the default
     *        is assumed to be <b>CAE</b>.
     *
     * @return
     *         The <b>PSBOMViewRevision</b> of the root of the newly created output structure is
     *         added to the Created list of the ServiceData. If the root of the output structure
     *         does not have a <b>BOMViewRevision</b>, then the <b>ItemRevision</b> of the root
     *         is added to the Created list of the ServiceData. An activity log is also returned
     *         which contains the results of the <i>DataMap rules</i> applied to the input structure
     *         and the output items created. The details include the type of the output item created,
     *         the <i>Item ID</i> of the output item, the relationships created between the input
     *         and the output <b>ItemRevision</b>. Any failures in creation of the output item or
     *         relationships are also returned as a part of the activity log.
     *
     */
    virtual Teamcenter::Services::Cae::_2012_02::Structuremanagement::ExecuteRuleResponse2 executeDatamap ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  rootIR,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Snapshot>  snapshotFolder,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  variantRule,
        const std::string&  domain ) = 0;

    /**
     * This operation creates an output BOM structure given the root <b>ItemRevision</b>
     * of the root <b>BOMLine</b> of an input BOM structure along with its <b>RevisionRule</b>
     * and the <b>VariantRule</b>. A <b>Snapshot</b> folder of the input BOM structure along
     * with the <b>VariantRule</b> can also be provided as an input. The output BOM structure
     * is determined by a combination of XSLT-based <i>DataMap</i> and <i>StructureMap rules</i>
     * executed against the input BOM structure. <i>DataMap/StructureMap</i> syntax is in
     * compliance with the schema defined in <i>tcsim_xslWithNode.xsd</i>, located in <i>TC_DATA</i>.
     * <br>
     * <br>
     * <i>DataMap rules</i> define the mapping between an input item type and its resulting
     * output item type. <i>DataMap rules</i> are defined for an entire site and are stored
     * in the <i>datamapping.xml</i> file located in <i>TC_DATA</i>. The name of the <i>datamapping</i>
     * file is defined by the site preference <i>CAE_dataMapping_file</i>.
     * <br>
     * <br>
     * <i>StructureMap rules</i> tailor the output BOM Structure. There are several rule
     * types:
     * <br>
     * <ul>
     * <li type="disc">Filter - Removes input BOM lines (and their children) from <i>DataMap</i>
     * evaluation.
     * </li>
     * <li type="disc">Include - Inserts item revisions in either the input or output BOM
     * structure as required.
     * </li>
     * <li type="disc">Reuse - Retrieve existing item revision to be used in the output
     * structure.
     * </li>
     * <li type="disc">Create Collector - Reorganization rule that creates "container" item
     * revisions to move <b>BOMLine</b> objects and sub-assemblies around.
     * </li>
     * <li type="disc">Move to Collector - Reorganizational rule that moves <b>BOMLine</b>
     * objects and sub-assemblies to collector components.
     * </li>
     * <li type="disc">Collapse Single Component Assembly - Identifying sub-assemblies with
     * single child component, elevating the child component to the parent sub-assembly
     * and removing the parent sub-assembly.
     * </li>
     * <li type="disc">Remove Empty Assembly - Identifying sub-assemblies with no child
     * components and removing the empty sub-assembly.
     * </li>
     * <li type="disc">Skip - Skips the <b>BOMLine</b> but still process its children.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <i>StructureMap rules</i> are stored an <i>XML named reference</i> in <b>CAEStructureMap</b>
     * dataset attached to a <b>StructureMapRevision</b>. <i>StructureMap rules</i> are
     * created with <i>Simulation Process Management CAE Structure Designer</i>.
     * <br>
     * <br>
     * To use this operation, a well-defined <i>datamapping.xml </i>is required in <i>TC_DATA</i>
     * and a <b>StructureMapRevision</b> with an attached <b>CAEStructureMap</b> dataset
     * must exist and the user should have either a <b>simulation_author</b> or <b>rtt_author</b>
     * <b>license</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1:
     * <br>
     * Given an input root <b>BOMLine</b> of a BOM structure, along with its <b>RevisionRule</b>
     * and <b>VariantRule</b>, the user can apply a <i>StructureMap rule</i> to the BOM
     * structure and generate a corresponding output BOM structure. The output BOM structure
     * would consist of <b>BOMLine</b> occurrences of <b>ItemRevision</b> objects as defined
     * in the <i>datamapping.xml</i> file and would be organized by the <i>StructureMap
     * rules</i> defined in the <b>CAEStructureMap</b> dataset attached to the <b>StructureMapRevision</b>.
     * The user can review the actions executed with the process log returned with the <b>BOMViewRevision</b>.
     * An email notification containing the activity log would be sent to the current user
     * if the session option for email notification is set to true.
     * <br>
     * <br>
     * Use Case 2:
     * <br>
     * Given a <b>Snapshot</b> folder of the input BOM structure and its <b>VariantRule</b>,
     * the user can apply a <i>StructureMap rule</i> to the BOM structure and generate a
     * corresponding output BOM structure. The output BOM structure would consist of <b>BOMLine</b>
     * occurrences of <b>ItemRevision</b> objects as defined in the <i>datamapping.xml</i>
     * file and would be organized by the <i>StructureMap rules</i> defined in the <b>CAEStructureMap</b>
     * dataset attached to the <b>StructureMapRevision</b>. The user can review the actions
     * executed with the process log returned with the <b>BOMViewRevision</b>. An email
     * notification containing the activity log would be sent to the current user if the
     * session option for email notification is set to true.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * CAE Integrations - Provides custom extensions to the Tc data model to capture the
     * CAE data model; the services that provide behaviors that are specific to CAE clients
     * and the client side code that accesses the data model and services.
     *
     * @param rootIR
     *        The <b>ItemRevision</b> of the root item of the input structure. This can be null
     *        if the <i>snapshotFolder</i> is provided as input to the operation. If the <i>rootIR</i>
     *        is not null and <i>snapshotFolder</i> is also provided as an input, then <i>rootIR</i>
     *        input will be ignored and <i>snapshotFolder</i> will take precedence.
     *
     * @param snapshotFolder
     *        The <b>Snapshot</b> folder of the input structure. The <i>snapshotFolder</i> can
     *        be null if the root <i>rootIR</i> is used as an input to the operation. The <i>snapshotFolder</i>
     *        takes precedence over the <i>rootIR</i>.
     *
     * @param revRule
     *        The <b>RevisionRule</b> of the input structure. This is an optional parameter and
     *        can be provided if the root <b>ItemRevision</b> is used as an input to the operation.
     *        This parameter will be ignored if <i>snapshotFolder</i> is used as an input.
     *
     * @param variantRule
     *        The <b>VariantRule</b> for the input structure. This can be provided for both, the
     *        <i>rootIR</i> or <i>snapshotFolder</i> as input. This is an optional parameter and
     *        can be null.
     *
     * @param structureMapIR
     *        The <b>StructureMapRevision</b> containing a <b>CAEStructureMap</b> <i>Dataset</i>
     *        with an XML <i>named reference</i> containing valid <i>StructureMap rules</i>.
     *
     * @return
     *         The <b>PSBOMViewRevision</b> of the root of the newly created output structure is
     *         added to the Created list of the ServiceData. If the root of the output structure
     *         does not have a <b>BOMViewRevision</b>, then the <b>ItemRevision</b> of the root
     *         is added to the Created list of the ServiceData. An activity log is also returned
     *         which contains the results of the <i>DataMap</i> and the <i>StructureMap rules</i>
     *         applied to the input structure and the output items created. The details include
     *         the type of the output item created, the names of the StructureMap rules applied,
     *         the <i>Item ID</i> of the output item, the relationships created between the input
     *         and the output <b>ItemRevision</b>. Any failures in creation of the output item or
     *         relationships are also returned as a part of the activity log.
     *
     */
    virtual Teamcenter::Services::Cae::_2012_02::Structuremanagement::ExecuteRuleResponse2 executeStructureMap ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  rootIR,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Snapshot>  snapshotFolder,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::VariantRule>  variantRule,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::StructureMapRevision>  structureMapIR ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructuremanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/cae/Cae_undef.h>
#endif

