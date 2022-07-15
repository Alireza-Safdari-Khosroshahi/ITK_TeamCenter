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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_MASSUPDATE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_MASSUPDATE_HXX

#include <teamcenter/soa/client/model/Fnd0Markup.hxx>
#include <teamcenter/soa/client/model/Fnd0MarkupChange.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2012_09
            {
                class Massupdate;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Massupdate
{
public:

    struct MassUpdateAffectedInput;
    struct MassUpdateAffectedOutput;
    struct MassUpdateAffectedResponse;
    struct MassUpdateExecuteECNoutput;
    struct MassUpdateExecuteECNresponse;
    struct MassUpdateExecuteECRinput;
    struct MassUpdateExecuteECRoutput;
    struct MassUpdateExecuteECRresponse;

    /**
     * This structure provides a set of input values for the massGetAffectedParents operation.
     */
    struct MassUpdateAffectedInput
    {
        /**
         * Item Revision to base the where used search on.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  target;
        /**
         * The change item revision object to record mass update results in.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  change;
        /**
         * Operation type used to help identify type of filtering to use when searching for
         * impacted parent parts.
         */
        int operation;
    };

    /**
     * This structure provides a set of output values for the massGetAfectedParents operation.
     */
    struct MassUpdateAffectedOutput
    {
        /**
         * This is the impacted parent part that references the target part.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parent;
        /**
         * This indicates if the impacted parent part is selectable for mass update or not.
         */
        bool selectable;
        /**
         * This text informs why the impacted parent part is not selectable.
         */
        std::string selectableComment;
    };

    /**
     * This structure contains all the results from the massGetAffectedParents operation.
     */
    struct MassUpdateAffectedResponse
    {
        /**
         * This is a vector of MassUpdateAffectedOutput structures.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateAffectedOutput > massUpdateAffectedOutputs;
        /**
         * Standard service data to handle partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure provides a set of output values for the massUpdateExecutionECN operation.
     */
    struct MassUpdateExecuteECNoutput
    {
        /**
         * Change item revision used for mass update execution on the ECN change management
         * process.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  changeItemRev;
        /**
         * Markup on ChangeItemRev that was processed during the ECN CM process.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0Markup>  markup;
        /**
         * This is a vector of markup changes that was processed during the ECN CM process.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0MarkupChange>  > markupChanges;
    };

    /**
     * This structure provides output for the massUpdateExecutionECN operation.
     */
    struct MassUpdateExecuteECNresponse
    {
        /**
         * This is a vector of MassUpdateExecuteECNoutput structures.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateExecuteECNoutput > outputs;
        /**
         * Standard service data for partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure provides a set of input values for the massUpdateExecutionECR operation.
     */
    struct MassUpdateExecuteECRinput
    {
        /**
         * This defines the ECR execution being performed 1=one time execute, 2=save as markup
         * and 3=remove markup.
         */
        int executionMode;
        /**
         * The mass update operation type being executed.
         */
        int operation;
        /**
         * Part that is being replaced or removed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  target;
        /**
         * Add the target part to the problem folder.
         */
        bool addToProblem;
        /**
         * Add the newItem to solution folder.
         */
        bool addToSolution;
        /**
         * The part that is doing the replacing or being added.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  newItem;
        /**
         * The change item revision object to record mass update results in.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  change;
        /**
         * The markup change to remove from the markup and the change item revision object impacted
         * folder.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0MarkupChange>  markupChange;
        /**
         * A vector of impacted parent parts that reference the target part.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  > parents;
        /**
         * A vector of bools that indicate if the impacted parent parts are selectable or not
         * for mass update.
         */
        std::vector< bool > sParents;
    };

    /**
     * This structure provides a set of output values for the massUpdateExecutionECR operation.
     */
    struct MassUpdateExecuteECRoutput
    {
        /**
         * The impacted parent part that references the target part.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parent;
        /**
         * This indicates if the impacted parent part was successful or not during the massUpdateExecutionECR
         * operation.
         */
        int status;
        /**
         * Detailed status text on why the impacted parent part succeded or failed to process
         * correctly.
         */
        std::string statusComment;
    };

    /**
     * This structure provides output for the massUpdateExecutionECR operation.
     */
    struct MassUpdateExecuteECRresponse
    {
        /**
         * This is a vector of MassUpdateExecuteECRoutput structures.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Massupdate::MassUpdateExecuteECRoutput > outputs;
        /**
         * Standard service data for partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Massupdate() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

