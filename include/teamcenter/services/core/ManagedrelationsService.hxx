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

#ifndef TEAMCENTER_SERVICES_CORE_MANAGEDRELATIONSSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_MANAGEDRELATIONSSERVICE_HXX

#include <teamcenter/services/core/_2007_01/Managedrelations.hxx>
#include <teamcenter/services/core/_2008_06/Managedrelations.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class ManagedrelationsService;

/**
 * Contains ManagedRelations Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API ManagedrelationsService
    : public Teamcenter::Services::Core::_2007_01::Managedrelations,
             public Teamcenter::Services::Core::_2008_06::Managedrelations
{
public:
    static ManagedrelationsService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation will create new managed relation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param relationinfo
     *        input information required to create managed relation
     *
     * @return
     *         has any created relation and the service data.Failure will be returned with input
     *         index and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Managedrelations::ManagedRelationResponse createRelation ( const std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::CreateManagedRelationInput >& relationinfo ) = 0;

    /**
     * This operation will create traceability report for the selected TC object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        information required to create report
     *
     * @return
     *         has traceability tree for the given TC object and the service data. Failure will
     *         be returned with input index and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Managedrelations::TraceabilityReportOutput getTraceReport ( const Teamcenter::Services::Core::_2007_01::Managedrelations::TraceabilityInfoInput&  input ) = 0;

    /**
     * This operation will Edit the managed relation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param newInput
     *        will have the modification info for given relation
     *
     * @return
     *         will loadthe modified relation along with service data. Failure will be returned
     *         with input index and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Managedrelations::ManagedRelationResponse modifyRelation ( const std::vector< Teamcenter::Services::Core::_2007_01::Managedrelations::ModifyManagedRelationInput >& newInput ) = 0;

    /**
     * This operation will return tracelinks between primary and secondary objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputdata
     *        information required to get tracelink relations
     *
     * @return
     *         will return tracelink relations between primary and secondary objects and error message
     *         in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Managedrelations::GetManagedRelationResponse getManagedRelations ( const Teamcenter::Services::Core::_2008_06::Managedrelations::GetManagedRelationInput&  inputdata ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ManagedrelationsService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

