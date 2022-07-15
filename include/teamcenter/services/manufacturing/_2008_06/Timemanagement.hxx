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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2008_06_TIMEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2008_06_TIMEMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2008_06
            {
                class Timemanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Timemanagement
{
public:

    struct AllocatedTime;
    struct AllocatedTimeResponse;
    struct TimeAnalysisInputs;
    struct TimeAnalysisResult;
    struct TimeAnalysisRollupResponse;

    /**
     * MapAllocatedTimeResults
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , double > MapAllocatedTimeResults;

    /**
     * MapStringDouble
     */
    typedef std::map< std::string, double > MapStringDouble;

    /**
     * Allocated Time structure for allocatedTimeRollUp operation
     */
    struct AllocatedTime
    {
        /**
         * vector of Tags of the item element
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > roots;
        /**
         * The type of calculation for the allocated time algorythm.possible values: duration_time,simulated_time,estimated_time,best_available_time.
         */
        std::string calculatedBy;
    };

    /**
     * Return structure for allocatedTimeRollUp operation
     */
    struct AllocatedTimeResponse
    {
        /**
         * MAp of each root and its allocated time result.
         */
        MapAllocatedTimeResults results;
        /**
         * This is a common data strucuture used to return sets of Teamcenter Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Time Analysis Inputs structure for timeAnalysisRollup operation
     */
    struct TimeAnalysisInputs
    {
        /**
         * vector of Tags of the item element
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > roots;
        /**
         * The additional run time  properties need to be calculated for the time analysis such
         * as total time and duration time
         */
        std::vector< std::string > runTimePropertiesToRecalc;
    };

    /**
     * Time Analysis Results structure for timeAnalysisRollup operation
     */
    struct TimeAnalysisResult
    {
        /**
         * the item element for the rollup.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * a map results of the activity total time for each category.
         */
        MapStringDouble categoryResults;
        /**
         * a map results of the requested run time properties.
         */
        MapStringDouble mapRunTimeResult;
    };

    /**
     * Return structure for timeAnalysisRollup operation
     */
    struct TimeAnalysisRollupResponse
    {
        /**
         * vector of the TimeAnalysisResult.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::TimeAnalysisResult > results;
        /**
         * This is a common data strucuture used to return sets of Teamcenter Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Calculates the allocated time for each requested bop line.
     *
     * @param object
     *        TODO
     *
     * @return
     *         structure containing the results of the allocated time calculation.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::AllocatedTimeResponse allocatedTimeRollUp ( const Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::AllocatedTime&  object ) = 0;

    /**
     * Calculates the total time for each activity category under a requested bop line.
     * An additional calculation is all the run time propertie related to the bop line time
     * calculations such as total time and duration time.
     *
     * @param inputs
     *        a Time Analysis Input structure, required
     *
     * @return
     *         structure containing the results of the time analysis calculation.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::TimeAnalysisRollupResponse timeAnalysisRollup ( const Teamcenter::Services::Manufacturing::_2008_06::Timemanagement::TimeAnalysisInputs&  inputs ) = 0;


protected:
    virtual ~Timemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

