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

#ifndef TEAMCENTER_SERVICES_CAE__2012_02_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAE__2012_02_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/model/Snapshot.hxx>
#include <teamcenter/soa/client/model/StructureMapRevision.hxx>
#include <teamcenter/soa/client/model/VariantRule.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cae/Cae_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cae
        {
            namespace _2012_02
            {
                class Structuremanagement;

class TCSOACAESTRONGMNGD_API Structuremanagement
{
public:

    struct ExecuteRuleResponse2;

    /**
     * <i>ExecuteRuleResponse2</i> represents the outputs of the published execute <i>StructureMap</i>
     * and execute <i>Datamap</i> operations.
     */
    struct ExecuteRuleResponse2
    {
        /**
         * If the root of the output structure has a <b>BOMView Revision</b>, <b>PSBOMViewRevision</b>
         * of the root of the output structure is returned as a part of Created Object in the
         * Service Data, else the <b>ItemRevision</b> of the root is returned as a part of the
         * Created Object in the Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A log containing the results of the <i>DataMap</i> and <i>StructureMap rules</i>
         * applied to the input structure and the output items created. The details include
         * the <i>DataMap</i> and <i>StructureMap</i> <i>rules</i> applied, type of the output
         * item created, the <i>Item ID</i> of the output item, the relationships created between
         * the input and the output <b>ItemRevision</b>. Any failures in creation of the output
         * item or relationships are also returned as a part of the activity log.
         * <br>
         * <br>
         * Following are some possible errors returned in ServiceData:
         * <br>
         * <ul>
         * <li type="disc">206622 Structure Engine unable to load/read/parse <i>DataMap</i>.
         * </li>
         * <li type="disc">206642 XML Libraries for <i>StructureMap</i> Engine not available.
         * </li>
         * <li type="disc">206643 <i>CAE_dataMapping_file</i> preference not defined.
         * </li>
         * <li type="disc">206647 <b>Item</b> creation failed, operation aborted.
         * </li>
         * <li type="disc">206648 Occurrence creation failed, operation aborted.
         * </li>
         * <li type="disc">206649 Unknown attribute found.
         * </li>
         * <li type="disc">206650 Object not modifiable, set attribute operation failed.
         * </li>
         * <li type="disc">206651 <b>Form</b> creation failed.
         * </li>
         * <li type="disc">206652 <b>BOMView</b> creation failed.
         * </li>
         * <li type="disc">206653 Unable to save the <b>Item</b> in the Newstuff folder.
         * </li>
         * <li type="disc">206658 Existing Relationship found, relationship not being created.
         * </li>
         * <li type="disc">206662 Error encountered in Variant Condition creation.
         * </li>
         * <li type="disc">206664 Error in relationship creation.
         * </li>
         * <li type="disc">206665 <b>Item</b> node line definition missing in <i>DataMap</i>.
         * </li>
         * <li type="disc">206666 <i>StructureMap</i> domain not found for <b>StructureMapRevision</b>.
         * </li>
         * <li type="disc">206672 Rules with different domains found in the same <i>StructureMap/DataMap</i>.
         * </li>
         * <li type="disc">206673 Rules with no domain defined found in <i>StructureMap/DataMap</i>.
         * </li>
         * <li type="disc">206677 Multiple variant clauses found in the variant condition. Variant
         * Condition creation failed.
         * </li>
         * <li type="disc">206678 Invalid or missing variant clause expression. Variant Condition
         * creation failed.
         * </li>
         * <li type="disc">206679 Mapped <b>BOMView</b> Type does not exist, creating default
         * view type.
         * </li>
         * </ul>
         */
        std::string activityLog;
    };




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


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cae/Cae_undef.h>
#endif

