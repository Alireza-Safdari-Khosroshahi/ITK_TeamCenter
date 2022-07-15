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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_12_ENGINEERINGDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_12_ENGINEERINGDATAQUERY_HXX

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
            namespace _2007_12
            {
                class Engineeringdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Engineeringdataquery
{
public:

    struct ClusterData2;
    struct ClusterIdentifier2;
    struct ClusterQryResponse2;
    struct FeatureAttributeData2;
    struct FeatureAttributeInfo2;
    struct FeatureNominals2;
    struct FeatureData2;
    struct RoutineData2;
    struct RoutineIdVer2;
    struct RoutineQryResponse2;
    struct SpecSetCode2;

    /**
     * The ClusterData2 structure is used return the engineering data belonging to the cluster.
     * Each cluster has set of feature attributes These set of feature attributes are captured
     * in a vector.
     */
    struct ClusterData2
    {
        /**
         * A DPVCluster_Revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  cluster;
        /**
         * A list of  feature attribute information associated with the cluster
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::FeatureAttributeInfo2 > featureAttributeInfo;
    };

    /**
     * The ClusterIdentifier2 structure is used give the information of the clusters of
     * interest
     */
    struct ClusterIdentifier2
    {
        /**
         * A <b>DPVCluster_Revision</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  clusterRevision;
    };

    /**
     * The ClusterQryResponse2 structure is used return the engineering data of a cluster.
     * This structure has a ClusterData2 structure and the service data structure in it.
     */
    struct ClusterQryResponse2
    {
        /**
         * The feature attribute information associated with the cluster and a reference to
         * the cluster
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::ClusterData2 > clusterData;
        /**
         * The  Service  Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The FeatureAttributeData2 structure is used return the feature attribute information
     * belonging to the routine
     */
    struct FeatureAttributeData2
    {
        /**
         * Attribute Code
         */
        std::string attributeCode;
        /**
         * Attribute Code Abbreviation
         */
        std::string abbreviation;
        /**
         * Attribute Code Direction
         */
        int codeDirection;
        /**
         * Attribute Significance
         */
        int significance;
        /**
         * Attribute measurement approach
         */
        std::string measurementApproach;
        /**
         * Attribute Need
         */
        std::string need;
        /**
         * Attribute Nominal
         */
        float nominal;
        /**
         * vector of spec sets defined on the Attribute
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::SpecSetCode2 > specSetCodes;
    };

    /**
     * The FeatureAttributeInfo2 structure is used return the feature attribute information
     * belonging to the cluster
     */
    struct FeatureAttributeInfo2
    {
        /**
         * ID of the feature
         */
        std::string parentFeatureId;
        /**
         * Name of the feature
         */
        std::string parentFeatureName;
        /**
         * An attribute code/name associated with the parentFeatureId
         */
        std::string attributeCode;
    };

    /**
     * The FeatureNominals2 structure is used return the nominal values of the feature
     */
    struct FeatureNominals2
    {
        /**
         * X Nominal
         */
        float x;
        /**
         * Y Nominal
         */
        float y;
        /**
         * Z Nominal
         */
        float z;
        /**
         * I Nominal
         */
        float i;
        /**
         * J Nominal
         */
        float j;
        /**
         * K Nominal
         */
        float k;
        /**
         * I2 Nominal
         */
        float i2;
        /**
         * J2 Nominal
         */
        float j2;
        /**
         * K2 Nominal
         */
        float k2;
    };

    /**
     * The FeatureData2 structure is used return the feature information belonging to the
     * routine. Each feature has set of feature attributes These set of feature attributes
     * are captured in a vector.
     */
    struct FeatureData2
    {
        /**
         * Id of the Feature
         */
        std::string featureId;
        /**
         * Feature Name
         */
        std::string featureLabel;
        /**
         * Alternate name of the Feature
         */
        std::string altLabel;
        /**
         * Feature Description
         */
        std::string description;
        /**
         * Feature Need
         */
        std::string need;
        /**
         * Active Status of the feature
         */
        bool activeStatus;
        /**
         * Loading Split Id of the feature
         */
        std::string loadingSplitId;
        /**
         * Nominal values given in a structure
         */
        Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::FeatureNominals2 nominalValues;
        /**
         * Vector of attributes defined for this feature
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::FeatureAttributeData2 > attributeData;
    };

    /**
     * The RoutineData2 structure is used return the engineering data belonging to the routine.
     * Each routine has set of features These set of features are captured in a vector.
     */
    struct RoutineData2
    {
        /**
         * The Routine object to which the features belong
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  routine;
        /**
         * A vector of FeatureData2 structures
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::FeatureData2 > featureData;
    };

    /**
     * The RoutineIdVer2 structure is used give the information (i.e. item id and revision)
     * of the routines of interest
     */
    struct RoutineIdVer2
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
     * The RoutineQryResponse2 structure is used return the engineering data of a routine.
     * This structure has a RoutineData2 structure and the service data structure in it.
     */
    struct RoutineQryResponse2
    {
        /**
         * A vector of RoutineData2 structures with engineering data of a routine
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::RoutineData2 > routineData;
        /**
         * The Service Data object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The SpecSetCode2 structure is used return the spec set code values of an attribute
     */
    struct SpecSetCode2
    {
        /**
         * Item id of the routine
         */
        std::string specSetCodeName;
        /**
         * target value of the spec set code
         */
        float target;
        /**
         * usl value of the spec set code
         */
        float usl;
        /**
         * lsl value of the spec set code
         */
        float lsl;
    };




    /**
     * Get the Engineering Data for a given Routine.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param routineIdVer
     *        The Item Id and Revision of the Routine
     *
     * @return
     *         Has the engineering data (Features, Feature Attributes and Forms attached to Feature
     *         Attributes) of the given routine
     *
     * @deprecated
     *         As of tc2007.1.3, getEngineeringDataFromRoutine2 is deprecated in TC2007 SR1 MP3
     *         and would be supported for two more releases only. This operation is replaced with
     *         getEngineeringDataFromRoutine3
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1.3, getEngineeringDataFromRoutine2 is deprecated in TC2007 SR1 MP3 and would be supported for two more releases only. This operation is replaced with getEngineeringDataFromRoutine3"))
#endif
    virtual Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::RoutineQryResponse2 getEngineeringDataFromRoutine2 ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::RoutineIdVer2 >& routineIdVer ) = 0;

    /**
     * For a <b>DPVCluster_Revision</b>, this operation provides all the feature attributes
     * that belong to it. The feature attribute information includes the feature ID, feature
     * name, and attribute code for each feature attribute in the cluster.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Client applications, such as standalone Teamcenter lifecycle visualization, query
     * Teamcenter for cluster information.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param clusterIdentifier
     *        A list of cluster identifiers. Each cluster identifier consists of the <b>ItemRevision</b>
     *        of the cluster, as well as the <b>MEInspection_Revisio</b>n to which the cluster
     *        of interest is attached
     *        <br>
     *
     * @return
     *         A list of cluster information data and the <code>ServiceData</code>. For each cluster
     *         identifier, a list of the feature attributes that belong to it are provided. The
     *         feature attribute information includes the feature ID, feature name, and attribute
     *         code for each feature attribute that belong to the <b>DPVCluster_Revision</b>. The
     *         <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::ClusterQryResponse2 getFeatureAttributeDataOfCluster2 ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery::ClusterIdentifier2 >& clusterIdentifier ) = 0;


protected:
    virtual ~Engineeringdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

