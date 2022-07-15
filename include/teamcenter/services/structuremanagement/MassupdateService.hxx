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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_MASSUPDATESERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_MASSUPDATESERVICE_HXX

#include <teamcenter/services/structuremanagement/_2012_09/Massupdate.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            class MassupdateService;

/**
 * This service provides all the operations required to perform a mass update feature.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoastructuremanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoastructuremanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API MassupdateService
    : public Teamcenter::Services::Structuremanagement::_2012_09::Massupdate
{
public:
    static MassupdateService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation will call ITK PS__masschange_get_parents to get all the affected impacted
     * parent parts and there selectablility for mass update.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MassUpdate - Provides the ability to perform mass changes on multiple assemblies
     * at one time, by using a single (non-workflow related) process or with a Change Management
     * two phase CR orCN change process.
     *
     * @param input
     *        The input is a vector of MassUpdateAffectedInput structures.
     *
     * @return
     *         The results of the ITK PS__masschange_get_parents are returned by this SOA operation.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateAffectedResponse massGetAffectedParents ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateAffectedInput >& input ) = 0;

    /**
     * This operation will call ITK PS__masschange_execute which will process all the change
     * item revision markup changes recorded during the ECR CM process.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MassUpdate - Provides the ability to perform mass changes on multiple assemblies
     * at one time, by using a single (non-workflow related) process or with a Change Management
     * two phase CR orCN change process.
     *
     * @param changeItemRevs
     *        A vector of mass update change item revisions to be executed during the ECN CM process.
     *
     * @return
     *         The results of the ITK PS__masschange_execute will be return.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateExecuteECNresponse massUpdateExecutionECN ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  >& changeItemRevs ) = 0;

    /**
     * This operation will call one of three ITKs: execute mode=1 calls PS__PS__masschange_onetime,
     * execute mode=2 calls PS__masschange_authorize_add and execute mode=3 calls PS__masschange_authorize_remove.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MassUpdate - Provides the ability to perform mass changes on multiple assemblies
     * at one time, by using a single (non-workflow related) process or with a Change Management
     * two phase CR orCN change process.
     *
     * @param input
     *        This is a vector of MassUpdateExecuteECRinput structures.
     *
     * @return
     *         The results from the three ITKs PS__PS__masschange_onetime, PS__masschange_authorize_add
     *         and PS__masschange_authorize_remove is return.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateExecuteECRresponse massUpdateExecutionECR ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateExecuteECRinput >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MassupdateService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

