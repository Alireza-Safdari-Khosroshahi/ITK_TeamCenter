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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_12_ENGINEERINGDATALOAD_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_12_ENGINEERINGDATALOAD_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2007_12
            {
                class Engineeringdataload;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Engineeringdataload
{
public:

    struct ImportFeatureDataResponse;
    struct RoutineAndFile;

    /**
     * The ImportFeatureDataResponse structure is returned from the importFeatureData. This
     * has serviceData object with any errors that occurred during execution of the operation
     */
    struct ImportFeatureDataResponse
    {
        /**
         * The Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The RoutineAndFile structure is given as input to importFeatureData. This has routine
     * revision tag for which the feature data is imported. It also has the details required
     * for creating the excel dataset.
     */
    struct RoutineAndFile
    {
        /**
         * A <b>MEInspection_Revision</b>  object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  routineRevision;
        /**
         * File ticket of a XML file that contains feature data of the <code>routineRevision</code>
         */
        std::string fmsFileTicket;
        /**
         * Name of the <b>DPVExcel</b>  dataset that the operation will create operation
         */
        std::string datasetName;
        /**
         * Optional information that gives the description of the dataset
         */
        std::string datasetDescription;
    };




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


protected:
    virtual ~Engineeringdataload() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

