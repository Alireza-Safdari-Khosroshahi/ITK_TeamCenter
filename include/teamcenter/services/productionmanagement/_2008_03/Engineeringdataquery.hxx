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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_03_ENGINEERINGDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_03_ENGINEERINGDATAQUERY_HXX

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
            namespace _2008_03
            {
                class Engineeringdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Engineeringdataquery
{
public:

    struct FeatureAttributeData3;
    struct FeatureNominals3;
    struct FeatureData3;
    struct RoutineData3;
    struct RoutineIdVer3;
    struct RoutineQryResponse3;
    struct SpecSetCode3;

    /**
     * The FeatureAttributeData3 structure is used return the feature attribute information
     * belonging to the routine
     */
    struct FeatureAttributeData3
    {
        /**
         * ID, code or name of a feature attribute
         */
        std::string attributeCode;
        /**
         * Abbreviation of a <code>attribute</code>Code
         */
        std::string abbreviation;
        /**
         * Direction of an <code>attribute</code>Code
         */
        int codeDirection;
        /**
         * Significance of the feature attribute. '<i>0</i>' - Insignificant; '<i>1</i>' - significant
         */
        int significance;
        /**
         * Specifies how the Coordinate Measuring Machine (CMM) probe measures a point for -
         * "Surface": takes into account the actual vector of the measured geometry; "Vector":
         * Takes the nominal             vector
         * <br>
         */
        std::string measurementApproach;
        /**
         * Attribute need with values such as '<i>Optional</i>', '<i>Planned</i>' or '<i>Required</i>'.This
         * information is used by the Extract Transact and Loader (ETL) client application to
         * determine if a feature attribute is required or optional for a routine revision
         */
        std::string need;
        /**
         * The ideal nominal value of each attribute. Typically, '<i>0</i>' for deviations
         */
        float nominal;
        /**
         * Derived feature expression and it is not used for a non-derived feature
         */
        std::string formula;
        /**
         * List of specification sets containing the tolerance limit information for the attribute
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::SpecSetCode3 > specSetCodes;
    };

    /**
     * The FeatureNominals3 structure is used return the nominal values of the feature
     */
    struct FeatureNominals3
    {
        /**
         * X location of the feature
         */
        float x;
        /**
         * Y location of the feature
         */
        float y;
        /**
         * Z location of the feature
         */
        float z;
        /**
         * component i of the first feature vector
         */
        float i;
        /**
         * component j of the first feature vector
         */
        float j;
        /**
         * component k of the first feature vector
         */
        float k;
        /**
         * component i of the second feature vector
         */
        float i2;
        /**
         * component j of the second feature vector
         */
        float j2;
        /**
         * component k of the second feature vector
         */
        float k2;
    };

    /**
     * The FeatureData3 structure is used return the feature information belonging to the
     * routine. Each feature has set of feature attributes These set of feature attributes
     * are captured in a vector.
     */
    struct FeatureData3
    {
        /**
         * ID of the feature
         */
        std::string featureId;
        /**
         * Feature name
         */
        std::string featureLabel;
        /**
         * Specifies the type of feature such as '<i>Point</i>', '<i>Hole</i>', '<i>Pin</i>',
         * '<i>Slot</i>', '<i>Tab</i>'
         * <br>
         */
        std::string featureType;
        /**
         * An alternative name for the feature for systems that may have length requirements
         * so you can enter another name by which to reference the feature
         * <br>
         */
        std::string altLabel;
        /**
         * Feature description
         */
        std::string description;
        /**
         * Feature Need with values such as '<i>Required</i>', '<i>Planned</i>' and '<i>Optional</i>'.
         * This information is used by the Extraction Transaction and Load (ETL) client to determine
         * if a feature is required or optional for a routine revision.
         */
        std::string need;
        /**
         * Status that shows whether or not Dimensional Planning and Validation (DPV) device
         * client and DPV Reporting & Analysis should process data for this feature (<i>'Y</i>'
         * - process the data; '<i>N</i>' - do not process the data)
         * <br>
         */
        bool activeStatus;
        /**
         * Loading Split ID of the feature. If a routine is measured with two or more devices,
         * the Loading Split ID identifies the portion of a routine (or several features) measured
         * by a device. If the routine is measured by only one device, then the Loading Split
         * ID is blank
         * <br>
         */
        std::string loadingSplitId;
        /**
         * Nominal values such as <code>x,y,z,i,j,k. x, y</code> and <code>z</code> are the
         * anchor point coordinates used in interactive reporting <code>i,j</code> and <code>k</code>
         * are the vector normal direction
         * <br>
         */
        Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::FeatureNominals3 nominalValues;
        /**
         * A list of attributes defined for the feature
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::FeatureAttributeData3 > attributeData;
    };

    /**
     * The RoutineData3 structure is used return the engineering data belonging to the routine.
     * Each routine has set of features These set of features are captured in a vector.
     */
    struct RoutineData3
    {
        /**
         * The routine revision to which the <code>featureData</code> belongs
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  routine;
        /**
         * A list of feature information, such as active status, name, description, and ID
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::FeatureData3 > featureData;
    };

    /**
     * The RoutineIdVer3 structure is used give the information (i.e. item id and revision)
     * of the routines of interest
     */
    struct RoutineIdVer3
    {
        /**
         * Item id of the routine
         */
        std::string routineId;
        /**
         * Routine revision of the routine
         */
        std::string routineRev;
    };

    /**
     * The RoutineQryResponse3 structure is used return the engineering data of a routine.
     * This structure has a RoutineData3 structure and the service data structure in it.
     */
    struct RoutineQryResponse3
    {
        /**
         * A list of structures containing engineering data of routine revisions
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::RoutineData3 > routineData;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The SpecSetCode3 structure is used return the spec set code values of an attribute
     */
    struct SpecSetCode3
    {
        /**
         * Name or identifier for the specification limits. A character string to define the
         * type of specification
         */
        std::string specSetCodeName;
        /**
         * Target value of the spec set code
         */
        float target;
        /**
         * Upper specification limit value of the spec set code
         */
        float usl;
        /**
         * Lower specification limit value of the spec set code
         */
        float lsl;
    };




    /**
     * This operation returns the engineering data of routine revisions. A routine revision
     * is an <b>ItemRevision</b> of  type <b>MEInspection_Revision</b>. The engineering
     * data includes information, such as features, feature attributes, and specification
     * limits associated with feature attributes.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * External client applications, such as standalone Teamcenter  lifecycle visualization
     * and Extracttion Transactaction and Load(ETL) query for engineering data from Teamcenter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param routineIdVer
     *        A list of <b>Item</b> IDs and revisions of routines
     *
     * @return
     *         A list of routine data for each routine revision and a <code>ServiceData</code> element.
     *         The routine data includes information such as features, feature attributes, and specification
     *         limits associated with feature attributes. The <code>ServiceData</code>  holds model
     *         objects and partial errors. No model objects are returned in this operation. Also,
     *         no specific partial error is returned by this operation and only errors from underlying
     *         subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::RoutineQryResponse3 getEngineeringDataFromRoutine3 ( const std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery::RoutineIdVer3 >& routineIdVer ) = 0;


protected:
    virtual ~Engineeringdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

