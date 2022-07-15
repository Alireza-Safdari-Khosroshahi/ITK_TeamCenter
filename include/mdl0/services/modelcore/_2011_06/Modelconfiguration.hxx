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

#ifndef MDL0_SERVICES_MODELCORE__2011_06_MODELCONFIGURATION_HXX
#define MDL0_SERVICES_MODELCORE__2011_06_MODELCONFIGURATION_HXX

#include <teamcenter/soa/client/model/RevisionRule.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mdl0/services/modelcore/ModelCore_exports.h>

namespace Mdl0
{
    namespace Services
    {
        namespace Modelcore
        {
            namespace _2011_06
            {
                class Modelconfiguration;

class MDL0SOAMODELCORESTRONGMNGD_API Modelconfiguration
{
public:

    struct FindRevisionRulesForModelResponse;

    /**
     * <code>FindRevisionRulesForModelResponse</code>  describes information regarding related
     * objects to be copied or referenced during a revise operation.This structure is the
     * same as that used for save as operations.
     */
    struct FindRevisionRulesForModelResponse
    {
        /**
         * List of revision rules that can be used to configure content of application models
         * (<b>Mdl0ApplicationModel</b>).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  > revisonRules;
        /**
         * Contains any errors encountered during the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Modelconfiguration() {}
};
            }
        }
    }
}

#include <mdl0/services/modelcore/ModelCore_undef.h>
#endif

