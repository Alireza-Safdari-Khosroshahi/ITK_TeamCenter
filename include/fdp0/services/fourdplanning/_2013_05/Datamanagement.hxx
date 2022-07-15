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

#ifndef FDP0_SERVICES_FOURDPLANNING__2013_05_DATAMANAGEMENT_HXX
#define FDP0_SERVICES_FOURDPLANNING__2013_05_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <fdp0/services/fourdplanning/FourDPlanning_exports.h>

namespace Fdp0
{
    namespace Services
    {
        namespace Fourdplanning
        {
            namespace _2013_05
            {
                class Datamanagement;

class FDP0SOAFOURDPLANNINGSTRONGMNGD_API Datamanagement
{
public:

    struct CreateOrUpdateProcessToTaskRelationInfo;

    /**
     * Input structure for <i>createOrUpdateProcessToTaskRelation</i>.
     * <br>
     * It contains the process or task as target objects and the objects to add & delete
     * the relation with.
     */
    struct CreateOrUpdateProcessToTaskRelationInfo
    {
        /**
         * The input object (<b>MEProcess</b> or <b>ScheduleTask</b>) on which relation needs
         * to be created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * If <i>targetObject</i> is a <b>MEProcess</b>, this will be list of <b>ScheduleTask</b>
         * which needs to be related to the <b>MEProcess</b> and viceversa.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToAdd;
        /**
         * If <i>targetObject</i> is a <b>MEProcess</b>, this will be list of <b>ScheduleTasks</b>
         * with which relation needs to be deleted and viceversa.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToDelete;
    };




    /**
     * This operation takes the source, target and naming information as input and creates
     * a process structure based on that.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * FourD Planning - This Teamcenter component deals with specific requirements related
     * to Ship Building Industry.        Which includes enhancements to structure search
     * to support 4D search  i.e. search along a time line.
     *
     * @param inputs
     *        Vector of CreateOrUpdateProcessToTaskRelationInfo structure.
     *
     * @return
     *         Returns service data which contain the created relation objects <b>Fdp0ProcessTasksRelation</b>
     *         and/or  the updated objects (<b>MEProcess</b> or <b>ScheduleTask</b>).
     *         <br>
     *         Service data may contain following partial errors at the same index as the input
     *         causing it:
     *         <br>
     *         <b>136001</b> - Create relation operation failed.
     *         <br>
     *         <b>136002</b> - Delete relation operation failed.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateProcessToTaskRelation ( const std::vector< Fdp0::Services::Fourdplanning::_2013_05::Datamanagement::CreateOrUpdateProcessToTaskRelationInfo >& inputs ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <fdp0/services/fourdplanning/FourDPlanning_undef.h>
#endif

