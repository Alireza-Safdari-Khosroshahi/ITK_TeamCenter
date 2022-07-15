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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2012_02_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2012_02_DATAMANAGEMENT_HXX

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
            namespace _2012_02
            {
                class Datamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Datamanagement
{
public:

    struct AddAssociationInput;
    struct AssociateAndAllocateInput;
    struct FileTicket;
    struct AssociateAndAllocateResponse;
    struct AssociatedContextInfo;
    struct AssociateOutput;
    struct AssociationResponse;
    struct AutomaticAllocatePreviewResponse;
    struct ConnectObjectResponse;
    struct GeneralInfo;
    struct SourceInfo;
    struct ConnectObjectsInputData;
    struct DisconnectFromOriginInputData;
    struct GetAssociatedContextsInputData;

    /**
     * Map of allocations from the source structure to the target structure. Relevant to
     * the commands such as associateAndAllocateByPreview
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > AllocationMap;

    /**
     * BoolMap
     */
    typedef std::map< std::string, bool > BoolMap1;

    /**
     * BoolVectorMap
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap1;

    /**
     * DateMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap1;

    /**
     * DateVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap1;

    /**
     * DoubleMap
     */
    typedef std::map< std::string, double > DoubleMap1;

    /**
     * DoubleVectorMap
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap1;

    /**
     * FloatMap
     */
    typedef std::map< std::string, float > FloatMap1;

    /**
     * FloatVectorMap
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap1;

    /**
     * IntMap
     */
    typedef std::map< std::string, int > IntMap1;

    /**
     * IntVectorMap
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap1;

    /**
     * StringMap
     */
    typedef std::map< std::string, std::string > StringMap1;

    /**
     * StringVectorMap
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap1;

    /**
     * TagMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap1;

    /**
     * TagVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap1;

    /**
     * BOMLines for the contexts to be associated
     */
    struct AddAssociationInput
    {
        /**
         * target (primary) context to associate (link) to.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  associateToContext;
        /**
         * vector of contexts info that are going to be associated(added) to the target.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociatedContextInfo > addedContexts;
    };

    /**
     * Input for the automatic allocation commands such as automaticAssociateAndAllocate,
     * associateAndAllocatePreview and associateAndAllocateByPreview command.
     */
    struct AssociateAndAllocateInput
    {
        /**
         * Source Product BOP for which allocate command was called
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  sourceProductBOP;
        /**
         * Target Plant BOP's lines to which the allocation is to be done.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetPlantBOPLines;
        /**
         * Reference Product BOP according to which allocation is to be done.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  referenceProductBOP;
    };

    /**
     * To represent a file ticket and its original file name.
     */
    struct FileTicket
    {
        /**
         * The FMS file Ticket.
         */
        std::string ticket;
        /**
         * The original file name.
         */
        std::string fileName;
    };

    /**
     * Response for the automatic allocation commands such as automaticAssociateAndAllocate,
     * and associateAndAllocateByPreview.
     */
    struct AssociateAndAllocateResponse
    {
        /**
         * Service data will hold partial errors, warnings  and errors, if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * File Ticket Containing the UID and file name for the Log File generated for this
         * command.
         */
        Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::FileTicket logFileTicket;
    };

    /**
     * AssociatedContextInfo
     */
    struct AssociatedContextInfo
    {
        /**
         * context  The added (source) context that should be associated (linked) associate
         * to target context (associateToContext parameter).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * relationName  The relation to use to connect. If the string is empty then the relation
         * defined as default will be used. It should be possible to define the default association
         * relation for each pair of types.
         */
        std::string relationName;
    };

    /**
     * Associated BOMLines to the input context
     */
    struct AssociateOutput
    {
        /**
         * Input context
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * vector of pairs of contexts and relation name that are associated with the input
         * context
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociatedContextInfo > associatedContextsInfo;
    };

    /**
     * Contains a list of items tags representing the associated BOMLines with the given
     * context.
     */
    struct AssociationResponse
    {
        /**
         * A vector of BOMLines associated to the input context
         */
        std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateOutput > output;
        /**
         * Partial errors mapped to the client id
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response for the automatic allocation commands automaticAllocatePreview.
     */
    struct AutomaticAllocatePreviewResponse
    {
        /**
         * Service data will hold partial errors, warnings  and errors, if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * File Ticket Containing the UID and file name for the CSV File generated for preview
         * during this command.
         */
        Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::FileTicket previewFileTicket;
        /**
         * Map of allocations from the source structure to the target structure.
         */
        AllocationMap allocationMap;
    };

    /**
     * ConnectObjectResponse
     */
    struct ConnectObjectResponse
    {
        /**
         * new BOMLines, created as a result of connection operation under the new target BOMLines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > newObjects;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds all additional flags that are needed for the connect like quantity (number
     * of occurrences),  copy predecessor flag, copy occurrence type from the source flag,
     * propagate XForm flag.
     */
    struct GeneralInfo
    {
        /**
         * Map containing string property values
         */
        StringMap1 stringProps;
        /**
         * Map containing string array property values
         */
        StringVectorMap1 stringArrayProps;
        /**
         * Map containing string property values
         */
        DoubleMap1 doubleProps;
        /**
         * Map containing string array property values
         */
        DoubleVectorMap1 doubleArrayProps;
        /**
         * Map containing string property values
         */
        FloatMap1 floatProps;
        /**
         * Map containing string array property values
         */
        FloatVectorMap1 floatArrayProps;
        /**
         * Map containing string property values
         */
        IntMap1 intProps;
        /**
         * Map containing string array property values
         */
        IntVectorMap1 intArrayProps;
        /**
         * Map containing string property values
         */
        BoolMap1 boolProps;
        /**
         * Map containing string array property values
         */
        BoolVectorMap1 boolArrayProps;
        /**
         * Map containing DateTime property values
         */
        DateMap1 dateProps;
        /**
         * Map containing DateTime array property values
         */
        DateVectorMap1 dateArrayProps;
        /**
         * Map containing string property values
         */
        TagMap1 tagProps;
        /**
         * Map containing string array property values
         */
        TagVectorMap1 tagArrayProps;
    };

    /**
     * contains all needed information in order to connect source BOMLines to the target
     */
    struct SourceInfo
    {
        /**
         * BOMLines to connect the target
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sourceObjects;
        /**
         * occurrence type for new assigned line. If its empty  server will use the default
         * occurrence type
         */
        std::string relationType;
        /**
         * The relation for the connect. If the string is empty then the default relation will
         * be defined and used by the server
         */
        std::string relationName;
        /**
         * Holds all additional flags that are needed for connect like quantity (number of occurrences),
         * copy predecessor flag, copy occurrence type from the source flag, propagate XForm
         * flag. Can be easily extended without changing the signature of the SOA
         */
        Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::GeneralInfo additionalInfo;
    };

    /**
     * A list of ConnectInput BOMLines for the nodes to be connect
     */
    struct ConnectObjectsInputData
    {
        /**
         * BOMLines to connect with. Can be a vector as a result of the multiple selection of
         * the targets
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetObjects;
        /**
         * all needed information in order to connect source BOMLines to the target
         */
        Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::SourceInfo sourceInfo;
    };

    /**
     * Input structure for DisconnectFromOrigin Command
     */
    struct DisconnectFromOriginInputData
    {
        /**
         * Plant BOP or Product BOP line that needs to be disconnected from their origin.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  lineToDisconnect;
        /**
         * Flag specifying whether the sub-processes and sub-operations are to be disconnected
         * recursively.
         */
        bool isRecursive;
    };

    /**
     * GetAssociatedContextsInputData
     */
    struct GetAssociatedContextsInputData
    {
        /**
         * associateToContext
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  associateToContext;
        /**
         * relationName
         */
        std::vector< std::string > relationName;
    };




    /**
     * Generic operation for setting different kinds of associations. It could be between
     * Plant BOP and Product BOP (Leading Plant BOP in the future), Product (root) and Process
     * (root) structures, regular Plant (Workarea) (root) and Process (root) structures,
     * EBOM-MBOM. For now we will use it as threshold for Plant BOP and Product BOP. Other
     * types are defined as target. This SOA will be used for add operation. Remove/disconnect
     * (future) will be implemented in separate SOA.
     *
     * @param input
     *        list of AddAssociationInput BOMLines for the contexts to be associated.
     *
     * @return
     *         ServiceData
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData addAssociatedContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AddAssociationInput >& input ) = 0;

    /**
     * This function is the second function call in case a preview is required for automatic
     * allocation this function does the actual allocation from Source Product BOP to a
     * Target Plant BOP on the basis of a Reference Product BOP. This is done by passing
     * the allocation map back to the server which we recived in the  automaticAllocatePreview
     * command. This function also associates the Source Product BOP with the Target Plant
     * BOP in case they are not associated. This function can throw the following exceptions,
     * Reference Product BOP is not linked to the Target Plant BOP and Some allocation from
     * the source structure to the target structure were unsuccessful please see the log
     * for more details. Both these error messages will have the severity level of error.
     *
     * @param input
     *        Input specifying source, target and reference objects.
     *
     * @param allocationMap
     *        Map of allocations from the source structure to the target structure.
     *
     * @return
     *         Response containing the log file ticket and service data.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateResponse associateAndAllocateByPreview ( const Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateInput&  input,
        const AllocationMap&  allocationMap ) = 0;

    /**
     * This function is the first function call in case a preview is required for automatic
     * allocation from Source Product BOP to a Target Plant BOP on the basis of a Reference
     * Product BOP. This function finds the allocated lines from the reference product BOP
     * to the Plant BOP and equivalent lines in the source Product BOP and generates a preview
     * for the automatic allocation in CSV format . Also this function returns an allocationMap,
     * which needs to be sent back to server in case the user wants to go ahead with the
     * allocation , for which it calls the second server call associateAndAllocateMap command
     * . This function can throw the following exceptions, Reference Product BOP is not
     * linked to the Target Plant BOP . This error messages will have severity level of
     * error.
     *
     * @param input
     *        Input specifying source, target and reference objects.
     *
     * @return
     *         Response containing allocation map, CSV file ticket and service data.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AutomaticAllocatePreviewResponse automaticAllocatePreview ( const Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateInput&  input ) = 0;

    /**
     * This function is a single call function that does the allocation from Source Product
     * BOP to a Target Plant BOP on the basis of a Reference Product BOP. This function
     * finds the allocated lines from the reference product BOP to the Plant BOP and equivalent
     * lines in the source Product BOP and does the allocation from the Source Product BOP
     * to the Target Plant BOP in a single call. This function also associates the Source
     * Product BOP with the Target Plant BOP in case they are not associated. This function
     * can throw the following exceptions, Reference Product BOP is not linked to the Target
     * Plant BOP and Some allocation from the source structure to the target structure were
     * unsuccessful please see the log for more details. Both these error messages will
     * have the severity level of error.
     *
     * @param input
     *        Input specifying source, target and reference objects.
     *
     * @return
     *         Response containing the service data and log file path.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateResponse automaticAssociateAndAllocate ( const Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociateAndAllocateInput&  input ) = 0;

    /**
     * Generic operation for connecting MFG nodes       int        quantityNum - number
     * of BOMLines to create (used in paste special). Default value is 1. int        occurrenceNumber
     * - for packed lines. Number of occurrences to create (used in paste special). Default
     * value is 1. int        findNumber - find number. Always passed by client.
     *
     * @param input
     *        A list of ConnectInput BOMLines for the nodes to connect
     *
     * @return
     *         Generic operation for connecting MFG nodes
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::ConnectObjectResponse connectObjects ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::ConnectObjectsInputData >& input ) = 0;

    /**
     * Disconnects objects and their children from their origin relation. Origin relation
     * is created when the objects are assigned from the Product BOP/Generic BOP to the
     * Plant BOP/Product BOP. This functionality removes the origin relation created during
     * the assignment. Also this functionality can be called recursively for the processes
     * below. This functionality can return an error in the following conditions, the object
     * on which disconnect function was called called does not have an origin in case of
     * non-recursive calls. This error will have a severity level of information. And This
     * functionality is not available on this type of object only ProcessAreas, WorkAreas,
     * Partitions, Processes and Operations type objects are expected.
     *
     * @param inputVector
     *        Vector of DisconnectFromOriginInputData specifying the lines to be disconnected and
     *        whether the children are to be recursively disconnected too.
     *
     * @return
     *         Service data containing the errors that occurred during the disconnect command.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData disconnectFromOrigin ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::DisconnectFromOriginInputData >& inputVector ) = 0;

    /**
     * Returns associated contexts with the input context.
     *
     * @param input
     *        input
     *
     * @return
     *         Returns associated contexts with the input context
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::AssociationResponse getAssociatedContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2012_02::Datamanagement::GetAssociatedContextsInputData >& input ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

