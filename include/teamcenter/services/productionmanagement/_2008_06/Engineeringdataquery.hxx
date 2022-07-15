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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_06_ENGINEERINGDATAQUERY_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_06_ENGINEERINGDATAQUERY_HXX

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
            namespace _2008_06
            {
                class Engineeringdataquery;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Engineeringdataquery
{
public:

    struct MappedFeature;
    struct MappedFeatureResponse;
    struct RoutineSetInfo;

    /**
     * MappedFeatureMap
     */
    typedef std::map< std::string, std::vector< MappedFeature > > MappedFeatureMap;

    /**
     * The MappedFeature structure has a couple of features that are mapped and the attributes
     * that are common to them
     */
    struct MappedFeature
    {
        /**
         * Integer identifier for first feature
         */
        std::string featureId1;
        /**
         * Integer identifier for second feature
         */
        std::string featureId2;
        /**
         * List of attribute code values that are common to <code>featureId1</code> and <code>featureId2</code>
         * <br>
         */
        std::vector< std::string > featureAttrCode;
    };

    /**
     * The MappedFeatureResponse structure represents the map which has the information
     * of mapped feature data.for a client Id
     */
    struct MappedFeatureResponse
    {
        /**
         * A Map between the <code>clientId</code> as key and a list of mapped features as value.
         * The  <code>clientId</code>  key identifies two routine revisions for which the mapped
         * feature information is provided in the <code>MappedFeature</code> structure. Each
         * <code>MappedFeature</code> structure has two features that are mapped and a list
         * of attribute codes that are common to them
         * <br>
         */
        MappedFeatureMap mappedFeatureData;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData partialErrors;
    };

    /**
     * The RoutineSetInfo structure has the routines whose mapped features need to be retrieved
     */
    struct RoutineSetInfo
    {
        /**
         * A key provided as input that is unique and associated with the two routine revisions
         * in the <code>RoutineSetInfo</code> structure. This key is used in the output <code>MappedFeatureMap</code>
         * parameter to identify the routine revisions with the associated feature map information.
         * The routine revision information is not used in the output and the clientId is used
         * in its place. It is the responsibility of the user  to ensure that the clientId is
         * unique
         */
        std::string clientId;
        /**
         * First routine revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  routine1;
        /**
         * Second routine revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  routine2;
    };




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


protected:
    virtual ~Engineeringdataquery() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

