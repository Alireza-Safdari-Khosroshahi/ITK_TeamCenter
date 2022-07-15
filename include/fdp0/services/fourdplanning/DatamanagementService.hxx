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

#ifndef FDP0_SERVICES_FOURDPLANNING_DATAMANAGEMENTSERVICE_HXX
#define FDP0_SERVICES_FOURDPLANNING_DATAMANAGEMENTSERVICE_HXX

#include <fdp0/services/fourdplanning/_2013_05/Datamanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <fdp0/services/fourdplanning/FourDPlanning_exports.h>

namespace Fdp0
{
    namespace Services
    {
        namespace Fourdplanning
        {
            class DatamanagementService;

/**
 * Data Management Service
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libfdp0soafourdplanningstrongmngd.dll
 * </li>
 * <li type="disc">libfdp0soafourdplanningtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class FDP0SOAFOURDPLANNINGSTRONGMNGD_API DatamanagementService
    : public Fdp0::Services::Fourdplanning::_2013_05::Datamanagement
{
public:
    static DatamanagementService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <fdp0/services/fourdplanning/FourDPlanning_undef.h>
#endif

