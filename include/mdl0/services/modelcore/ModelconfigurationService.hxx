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

#ifndef MDL0_SERVICES_MODELCORE_MODELCONFIGURATIONSERVICE_HXX
#define MDL0_SERVICES_MODELCORE_MODELCONFIGURATIONSERVICE_HXX

#include <mdl0/services/modelcore/_2011_06/Modelconfiguration.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            class ModelconfigurationService;

/**
 * This service contains utilities to assist with configuring application model (<b>Mdl0ApplicationModel</b>)
 * content, specifically subclasses of conditional model elements (<b>Mdl0ConditionalElemet</b>).
 * 
 * <br>
 * Currently one operation is provided by this service (<code>findRevisionRulesForModel</code>)which
 * returns revision rules which are valid for configuring <b>Mdl0ConditionalElements</b>.
 * <br>
 * Use Case 1:<b> Perform a Configured Search of an Application Model </b>
 * <br>
 * <ul>
 * <li type="disc">Find/select the application model of interest (e.g. using a saved
 * queries)
 * </li>
 * <li type="disc">Use operation <code>findRevisionRulesForModel</code> to get the list
 * of valid revision rules for configuring application models.  Display this list to
 * the user so they can select one.
 * </li>
 * <li type="disc">Allow the user to set (additional) effectivity criteria on revision
 * rule, if they choose.
 * </li>
 * <li type="disc">Create a configuration context (using operations from <code>Search</code>
 * service) which references the selected (and possibly modified revision rule)
 * </li>
 * <li type="disc">Execute the search (using operations from <code>Search</code> service)
 * </li>
 * </ul>
 * <br>
 * Use Case 2: <b>Change Presented Configuration of an Application Model </b>
 * <br>
 * <ul>
 * <li type="disc">When build display for presenting configured application models,
 * give the user a button or menu which allows them to change the revision rule used
 * to configure the model.
 * </li>
 * <li type="disc">Use operation <code>findRevisionRulesForModel</code> to get the list
 * of valid revision rules for configuring application models.  Display as options in
 * the UI for the user to pick from.
 * </li>
 * <li type="disc">When user picks a new revision rule, reload and display content of
 * the model based on the new revision rule.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmdl0soamodelcorestrongmngd.dll
 * </li>
 * <li type="disc">libmdl0soamodelcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class MDL0SOAMODELCORESTRONGMNGD_API ModelconfigurationService
    : public Mdl0::Services::Modelcore::_2011_06::Modelconfiguration
{
public:
    static ModelconfigurationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Finds all revision rules which are valid for configuring content (subtypes of <b>Mdl0ConditionalElement
     * </b>and <b>Mdl0ConditionalArtifact</b>) of an application model (<b>Mdl0ApplicationModel</b>).Not
     * all revision rules can be used to configure application models; this operation aids
     * the application in finding the list of revision rules which can be used for this
     * type of configuration. (See Teamcenter technical documentation for further information
     * regarding valid  revision rules for model content configuration.)
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Users configure application model content to select proper revisions based on criteria
     * like <code>Working</code><b> </b>or <code>Has Status</code>, and by effectivity.
     * Revision rules capture these criteria and are used within Teamcenter to select
     * revisions which match these criteria.   Because only a subset of all Teamcenter revision
     * rules can be used to configure application model content, the user/application needs
     * a way to get the list of valid revision rules for this type of configuration.   The
     * <code>findRevisionRulesForModel</code> operation is used to get this list.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Application Model Elements - Defines the basic data management operations(revise,saveAs,deepcopy)
     * for Application Model Elements,defines operations to create search expressions and
     * execute search on Model Elements in an Application Model.
     *
     * @return
     *         The response contains a list of all valid revision rules that can be used to configure
     *         an application model.
     *
     */
    virtual Mdl0::Services::Modelcore::_2011_06::Modelconfiguration::FindRevisionRulesForModelResponse findRevisionRulesForModel (  ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ModelconfigurationService")

};
        }
    }
}


#pragma warning ( pop )

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

