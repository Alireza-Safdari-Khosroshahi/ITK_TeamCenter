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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_ENGINEERINGDATAQUERYSERVICE_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_ENGINEERINGDATAQUERYSERVICE_HXX

#include <teamcenter/services/productionmanagement/_2007_06/Engineeringdataquery.hxx>
#include <teamcenter/services/productionmanagement/_2007_12/Engineeringdataquery.hxx>
#include <teamcenter/services/productionmanagement/_2008_03/Engineeringdataquery.hxx>
#include <teamcenter/services/productionmanagement/_2008_06/Engineeringdataquery.hxx>



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
            class EngineeringdataqueryService;

/**
 * The EngineeringDataQuery service exposes operations that are used to query engineering
 * data of plants, routines, and clusters.
 * <br>
 * <br>
 * This service provides the following use cases:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Get database details of a plant
 * </li>
 * <li type="disc">Get feature attribute, specification limits, and data load information
 * for a routine revision
 * </li>
 * <li type="disc">Get the mapped feature data given two routine revisions
 * </li>
 * <li type="disc">Get feature attributes associated with a <b>DPVCluster_Revision</b>
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

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API EngineeringdataqueryService
    : public Teamcenter::Services::Productionmanagement::_2007_06::Engineeringdataquery,
             public Teamcenter::Services::Productionmanagement::_2007_12::Engineeringdataquery,
             public Teamcenter::Services::Productionmanagement::_2008_03::Engineeringdataquery,
             public Teamcenter::Services::Productionmanagement::_2008_06::Engineeringdataquery
{
public:
    static EngineeringdataqueryService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation returns a set of mapped features for each pair of routine revisions
     * in the request list. For each pair of routine revisions, the mapped feature information
     * maps a subset of features in the second routine to features in the first routine
     * revision. This map information is for features and not feature attributes. If one
     * feature is mapped to another feature, then all the common attribute codes between
     * the two features are mapped that is, there is no way to map select attribute codes
     * under a feature).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The DPV Reporting & Analysis client application in standalone Teamcenter lifecycle
     * visualization queries Teamcenter for mapped features between two routine revisions.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param request
     *        A list of routine set information structures. Each structure contains a <code>clientId</code>
     *        and a pair of routine revisions for which the mapped feature information is requested.
     *        The <code>clientId</code> is a unique integer and a key that represents the pair
     *        of routine revisions in the structure. It is the responsibility of the user to ensure
     *        that the <code>clientId</code> is unique
     *
     * @return
     *         This operation returns a set of mapped features for each pair of routine revisions
     *         in the request list. Given two routine revisions, the mapped feature information
     *         maps a subset of features in the second routine to features in the first routine.
     *         The <code>ServiceData</code>  holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Services::Productionmanagement::_2008_06::Engineeringdataquery::MappedFeatureResponse getMappedFeatureData ( const std::vector< Teamcenter::Services::Productionmanagement::_2008_06::Engineeringdataquery::RoutineSetInfo >& request ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EngineeringdataqueryService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

