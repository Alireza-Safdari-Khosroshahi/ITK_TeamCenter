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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_06_ENGINEERINGDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2007_06_ENGINEERINGDATAQUERY_HXX

#include <teamcenter/soa/client/model/AppearanceGroup.hxx>
#include <teamcenter/soa/client/model/Form.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
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
            namespace _2007_06
            {
                class Engineeringdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Engineeringdataquery
{
public:

    struct ClusterData;
    struct RoutineIdVer;
    struct ClusterIdentifier;
    struct ClusterQryResponse;
    struct DatabaseDetails;
    struct DatabaseDetailsResponse;
    struct FeatureAttributeData;
    struct FeatureAttributeInfo;
    struct FeatureData;
    struct RoutineData;
    struct RoutineQryResponse;

    /**
     * The ClusterData structure is used return the engineering data belonging to the cluster.
     * Each cluster has set of feature attributes These set of feature attributes are captured
     * in a vector.
     */
    struct ClusterData
    {
        /**
         * The Routine object to which the features belong
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppearanceGroup>  cluster;
        /**
         * A vector of FeatureAttributeInfo structures
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::FeatureAttributeInfo > featureAttributeInfo;
    };

    /**
     * The RoutineIdVer structure is used give the information (i.e. item id and revision)
     * of the routines of interest
     */
    struct RoutineIdVer
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
     * The ClusterIdentifier structure is used give the information (i.e. routine id and
     * revision and cluster ref) of the clusters of interest
     */
    struct ClusterIdentifier
    {
        /**
         * Ref to the cluster
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AppearanceGroup>  cluster;
        /**
         * RoutineIdVer structure with the routine information
         */
        Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::RoutineIdVer routineIdRev;
    };

    /**
     * The ClusterQryResponse structure is used return the engineering data of a cluster.
     * This structure has a ClusterData structure and the service data structure in it.
     */
    struct ClusterQryResponse
    {
        /**
         * A vector of ClusterData structures with engineering data of a cluster
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::ClusterData > clusterData;
        /**
         * The Service Data object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The DatabaseDetails structure captures the database details for a plant
     */
    struct DatabaseDetails
    {
        /**
         * Plant ID whose database information is required
         */
        std::string plantId;
        /**
         * The name of the database that contains the measurement data for the <code>plantId</code>
         */
        std::string databaseName;
        /**
         * The type of database, which is '<i>Oracle</i>' or '<i>MSSQL</i>'
         */
        std::string databaseType;
        /**
         * The name of the hosting server of the database
         */
        std::string hostName;
    };

    /**
     * The DatabaseDetailsResponse has the details of the dbs corresponding to the given
     * input plant ids
     */
    struct DatabaseDetailsResponse
    {
        /**
         * Structures containing details of database such as database name, database type ('<i>Oracle</i>'
         * or '<i>MSSQL</i>'), as well as  a plant ID key for which the database information
         * is sought
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::DatabaseDetails > databaseDetails;
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The FeatureAttributeData structure is used return the feature attribute information
     * belonging to the routine
     */
    struct FeatureAttributeData
    {
        /**
         * Tag of the feature attribute
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  featureAttribute;
        /**
         * Vector of POMRef of the form attached to the feature attribute
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Form>  > featureAttributeForm;
    };

    /**
     * The FeatureAttributeInfo structure is used return the feature attribute information
     * belonging to the cluster
     */
    struct FeatureAttributeInfo
    {
        /**
         * Ref of the parent feature. Note that even though the variable name says occurrence,
         * Tc2007.1 doesnt support occurrences. It is objects uid.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentFeatureOccurrence;
        /**
         * Tag of the feature attribute
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  featureAttribute;
        /**
         * Vector of POMRef of the form attached to the feature attribute
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Form>  > featureAttInfoForm;
    };

    /**
     * The FeatureData structure is used return the feature information belonging to the
     * routine. Each feature has set of feature attributes These set of feature attributes
     * are captured in a vector.
     */
    struct FeatureData
    {
        /**
         * The feature.  Note that even though the variable name says occurrence, Tc2007.1 doesnt
         * support occurrences. It is objects uid.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  featureOccurrence;
        /**
         * A vector of FeatureAttributeData structures
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::FeatureAttributeData > featureAttributeData;
    };

    /**
     * The RoutineData structure is used return the engineering data belonging to the routine.
     * Each routine has set of features These set of features are captured in a vector.
     */
    struct RoutineData
    {
        /**
         * The Routine object to which the features belong
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  routine;
        /**
         * A vector of FeatureData structures
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::FeatureData > featureData;
    };

    /**
     * The RoutineQryResponse structure is used return the engineering data of a routine.
     * This structure has a RoutineData structure and the service data structure in it.
     */
    struct RoutineQryResponse
    {
        /**
         * A vector of RoutineData structures with engineering data of a routine
         */
        std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::RoutineData > routineData;
        /**
         * The Service Data object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Given a list of plant IDs, for each plant ID, this operation returns the database
     * name of the database that contains measurement data for the plant, the server in
     * which the database resides, and the type of database. There are two possible types
     * of databases: '<i>Oracle</i>' and '<i>MSSQL</i>'.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Dimensional Planning and Validation (DPV) Analysis Services client application queries
     * Teamcenter for the plant details.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param plantids
     *        List of plant IDs whose database information is required
     *
     * @return
     *         <code>DatabaseDetailsResponse</code> has the details of the databases corresponding
     *         to the given plant IDs. The database details for each plant consists of the database
     *         name, hosting server, and database type ('<i>Oracle</i>' or '<i>MSSQL</i>'). The
     *         <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::DatabaseDetailsResponse getDatabaseDetailsForPlant ( const std::vector< std::string >& plantids ) = 0;

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
     *
     * @exception ServiceException
     *           There is no exception.
     * @deprecated
     *         As of tc2007.1.2, getEngineeringDataFromRoutine is deprecated in TC2007 SR1 MP2 and
     *         would be supported for two more releases only. This operation is replaced with getEngineeringDataFromRoutine2
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1.2, getEngineeringDataFromRoutine is deprecated in TC2007 SR1 MP2 and would be supported for two more releases only. This operation is replaced with getEngineeringDataFromRoutine2"))
#endif
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::RoutineQryResponse getEngineeringDataFromRoutine ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::RoutineIdVer >& routineIdVer ) = 0;

    /**
     * Get the contents of a given Cluster.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param clusterIdentifier
     *        The Item Id, Revision of the Routine and the Cluster ref
     *
     * @return
     *         Has the Feature Attributes clustered and Forms attached to Feature Attributes along
     *         with the parent feature occurrence
     *
     *
     * @exception ServiceException
     *           There is no expection.
     * @deprecated
     *         As of tc2007.1.2, getFeatureAttributeDataOfCluster is deprecated in TC2007 SR1 MP2
     *         and would be supported for two more releases only. This operation is replaced with
     *         getFeatureAttributeDataOfCluster2
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1.2, getFeatureAttributeDataOfCluster is deprecated in TC2007 SR1 MP2 and would be supported for two more releases only. This operation is replaced with getFeatureAttributeDataOfCluster2"))
#endif
    virtual Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::ClusterQryResponse getFeatureAttributeDataOfCluster ( const std::vector< Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery::ClusterIdentifier >& clusterIdentifier ) = 0;


protected:
    virtual ~Engineeringdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

