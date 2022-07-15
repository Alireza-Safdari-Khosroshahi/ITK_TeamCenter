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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_MEASUREMENTDATAEDITSERVICE_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT_MEASUREMENTDATAEDITSERVICE_HXX

#include <teamcenter/services/productionmanagement/_2008_03/Measurementdataedit.hxx>



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
            class MeasurementdataeditService;

/**
 * The MeasurementDataEdit service exposes operations that are used to activate or deactivate
 * a measurement event.
 * <br>
 * <br>
 * This service provides the following use cases:
 * <br>
 * <br>
 * <ul>
 * <li type="disc">Change the active status of measurement events using the Dimensional
 * Planning and Validation (DPV) Measurement user interface in the rich client interface.
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

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API MeasurementdataeditService
    : public Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataedit
{
public:
    static MeasurementdataeditService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation updates the status of one or more measurement events specified in
     * the list of <code>TargetEvents</code> to active or inactive.  <code>TargetEvents</code>
     * includes a plant ID, measurement event that belongs to the plant ID, and its associated
     * active status
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Change the active status of measurement events using the Dimensional Planning and
     * Validation (DPV) Measurement user interface in the Teamcenter rich client.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Database Configuration for Dimensional Planning And Validation - This is for Dimensional
     * Planning and Validation
     *
     * @param targetRows
     *        A list of target events that  includes a plant ID, measurement event ID that belongs
     *        to a plant ID, and an active status. Different <code>TargetEvents</code> can have
     *        different active statuses.
     *
     * @return
     *         The <code>ServiceData</code> holds model objects and partial errors. No model objects
     *         are returned in this operation. Also, no specific partial error is returned by this
     *         operation and only errors from underlying subsystems are returned.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData activateOrDeactivateData ( const std::vector< Teamcenter::Services::Productionmanagement::_2008_03::Measurementdataedit::TargetEvents >& targetRows ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MeasurementdataeditService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

