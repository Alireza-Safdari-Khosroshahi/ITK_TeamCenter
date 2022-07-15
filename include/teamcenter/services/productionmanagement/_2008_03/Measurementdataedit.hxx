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

#ifndef TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_03_MEASUREMENTDATAEDIT_HXX
#define TEAMCENTER_SERVICES_PRODUCTIONMANAGEMENT__2008_03_MEASUREMENTDATAEDIT_HXX



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
                class Measurementdataedit;

class TCSOAPRODUCTIONMANAGEMENTSTRONGMNGD_API Measurementdataedit
{
public:

    struct TargetEvents;

    /**
     * The TargetEvents structure is used to set as active or deactive based on the int
     * value
     */
    struct TargetEvents
    {
        /**
         * <b>MEPrPlantProcess</b> to which a measurement event or <code>eventSysId</code> belongs
         */
        std::string plantId;
        /**
         * Use '<i>1</i>' to activate and '<i>0</i>' to deactive measurement events
         */
        bool activeInactive;
        /**
         * Event system ID stored in measurement database for the measurement event for which
         * the <code>activeInactive</code> status is to be applied
         */
        std::string eventSysId;
    };




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


protected:
    virtual ~Measurementdataedit() {}
};
            }
        }
    }
}

#include <teamcenter/services/productionmanagement/ProductionManagement_undef.h>
#endif

