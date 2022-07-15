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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_ENGINEERINGDATALOADSERVICE_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_ENGINEERINGDATALOADSERVICE_HXX

#include <teamcenter/services/productionmanagement/_2007_12/Engineeringdataload.hxx>
#include <teamcenter/services/productionmanagement/_2011_06/Engineeringdataload.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/productionmanagement/ProductionManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Productionmanagement
        {
            class EngineeringdataloadService;

/**
 * The EngineeringDataLoad service exposes operations that import feature data for a
 * routine revision and create relationship between a routine revision and a <b>Dpv0ruleset</b>
 * item.
 * <br>
 * <br>
 * This service provides the following use cases:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Import an xml file with Feature data in the Manufacturing Process
 * Planner (MPP) application in the Teamcemcenter rich client by selecting a Routine
 * Revision of the type <b>MEInspection_Revision</b> and then using the Tools|'Import
 * Feature Data' menu option.
 * </li>
 * <li type="disc">In the MPP application, a user can associate a <b>Dpv0ruleset</b>
 * item to  a routine revision after selecting a routine revision and choosing the Tools|'Import
 * Feature Data' menu option.
 * </li>
 * <li type="disc">In the MPP application, a user can associate a <b>Dpv0ruleset</b>
 * item to  a routine revision by right-clicking the routine revision and then selecting
 * "Apply Rule Set" from the ensuing context menu.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaproductionmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaproductionmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API EngineeringdataloadService
    : public Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataload,
             public Teamcenter::Services::Productionmanagement::_2011_06::Engineeringdataload
{
public:
    static EngineeringdataloadService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation uploads the feature data for a routine revision. A routine revision
     * is an <b>ItemRevision</b> of the type <b>MEInspection_Revision</b>. This operation
     * takes an FMS file ticket of an XML file containing engineering data of a routine,
     * such as feature ID, feature name, feature attributes and specification limits, as
     * an input. It creates a <b>DPVExcel</b> dataset under the routine revision with an
     * <code>IMAN_specification</code> relation on successful execution of the operation.
     * All the features and attributes in the XML file are included in the <b>DPVExcel</b>
     * dataset.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Import an XML file in Manufacturing Process Planner (MPP) application in the Teamcenter
     * rich client by selecting a routine revision of type <b>MEInspection_Revision</b>
     * and usinging the Tools|"Import Feature Data" menu option.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param input
     *        A list of feature import data. Each element has the routine revision object for which
     *        the feature data is to be imported, the FMS file ticket for an XML file with feature
     *        data for the routine revision,  the name of the <b>DPVExcel</b> dataset that is to
     *        be attached to the routine revision, and a description of the <b>DPVExcel</b> dataset
     *
     * @return
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataload::ImportFeatureDataResponse importFeatureData ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataload::RoutineAndFile >& input ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EngineeringdataloadService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

