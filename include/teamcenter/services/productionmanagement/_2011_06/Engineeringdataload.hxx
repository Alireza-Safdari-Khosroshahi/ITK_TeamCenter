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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2011_06_ENGINEERINGDATALOAD_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2011_06_ENGINEERINGDATALOAD_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/productionmanagement/ProductionManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Productionmanagement
        {
            namespace _2011_06
            {
                class Engineeringdataload;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Engineeringdataload
{
public:





    /**
     * This operation creates a <b>Dpv0CustomRoutineRuleset</b>  relationship between a
     * <b>Dpv0ruleset</b>  and a routine revision (<b>MEInspection_Revison</b>). The operation
     * determines the <b>Dpv0ruleset</b> from the <code>xlsbDs</code>, which is associated
     * to any revision of the <b>Dpv0ruleset</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * In the Manufacturing Process Planner (MPP) application in the Teamcenter rich client,
     * a user can associate a <b>Dpv0ruleset</b>  with  a routine revision via Tools|"Import
     * Feature Data" after a routine revision is selected.
     * <br>
     * <br>
     * In the MPP application, a user can associate a <b>Dpv0ruleset</b>  with  a routine
     * revision by right-clicking the routine revision and selecting "Apply Rule Set" from
     * the ensuing context menu.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param xlsbDs
     *        The <b>Dpv0RuleSetDataset</b> dataset attached to a<b> Dpv0rulesetRevision</b>
     *
     * @param routineRev
     *        A routine revision of type <b>MEInspection_Revison</b>
     *
     * @return
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createRelBwDsRoutineRev ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  xlsbDs,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  routineRev ) = 0;


protected:
    virtual ~Engineeringdataload() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

