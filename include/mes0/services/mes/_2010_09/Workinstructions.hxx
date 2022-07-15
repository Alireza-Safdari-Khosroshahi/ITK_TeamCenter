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

#ifndef MES0_SERVICES_MES__2010_09_WORKINSTRUCTIONS_HXX
#define MES0_SERVICES_MES__2010_09_WORKINSTRUCTIONS_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mes0/services/mes/MES_exports.h>

namespace Mes0
{
    namespace Services
    {
        namespace Mes
        {
            namespace _2010_09
            {
                class Workinstructions;

class TCSOAMESSTRONGMNGD_API Workinstructions
{
public:

    struct CreateInput;
    struct LoadedObjectInfo;
    struct LoadedObjectsResponse;
    struct LoadedSTXInfo;
    struct LoadedSubSTXInfo;
    struct ObjectsReferenced;
    struct SavedObjectInfo;
    struct SavedObjectsResponse;
    struct SavedSTXInfo;
    struct SavedSubSTXInfo;

    /**
     * BoolMap
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * BoolVectorMap
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

    /**
     * CreateInputMap
     */
    typedef std::map< std::string, std::vector< CreateInput > > CreateInputMap;

    /**
     * DateMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > DateMap;

    /**
     * DateVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::DateTime > > DateVectorMap;

    /**
     * DoubleMap
     */
    typedef std::map< std::string, double > DoubleMap;

    /**
     * DoubleVectorMap
     */
    typedef std::map< std::string, std::vector< double > > DoubleVectorMap;

    /**
     * FloatMap
     */
    typedef std::map< std::string, float > FloatMap;

    /**
     * FloatVectorMap
     */
    typedef std::map< std::string, std::vector< float > > FloatVectorMap;

    /**
     * IntMap
     */
    typedef std::map< std::string, int > IntMap;

    /**
     * IntVectorMap
     */
    typedef std::map< std::string, std::vector< int > > IntVectorMap;

    /**
     * StringMap
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * StringVectorMap
     */
    typedef std::map< std::string, std::vector< std::string > > StringVectorMap;

    /**
     * TagMap
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > TagMap;

    /**
     * TagVectorMap
     */
    typedef std::map< std::string, std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > > TagVectorMap;

    /**
     * CreateInput structure used to capture the inputs required for creation of a business
     * object. This is a recursive structure containing the CreateInput(s) for any secondary
     * (compounded) objects that might be created (e.g Item also creates ItemRevision and
     * ItemMasterForm, etc.)
     */
    struct CreateInput
    {
        /**
         * Business Object type name
         */
        std::string type;
        /**
         * Map containing string property values
         */
        StringMap stringProps;
        /**
         * Map containing string array property values
         */
        StringVectorMap stringArrayProps;
        /**
         * Map containing string property values
         */
        DoubleMap doubleProps;
        /**
         * Map containing string array property values
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map containing string property values
         */
        FloatMap floatProps;
        /**
         * Map containing string array property values
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map containing string property values
         */
        IntMap intProps;
        /**
         * Map containing string array property values
         */
        IntVectorMap intArrayProps;
        /**
         * Map containing string property values
         */
        BoolMap boolProps;
        /**
         * Map containing string array property values
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map containing DateTime property values
         */
        DateMap dateProps;
        /**
         * Map containing DateTime array property values
         */
        DateVectorMap dateArrayProps;
        /**
         * Map containing string property values
         */
        TagMap tagProps;
        /**
         * Map containing string array property values
         */
        TagVectorMap tagArrayProps;
        /**
         * CreateInput for compounded objects
         */
        CreateInputMap compoundCreateInput;
    };

    /**
     * LoadedObjectInfo
     */
    struct LoadedObjectInfo
    {
        /**
         * we pass this parameter together with the targetObject parameter back to the client
         * to help him identify to whom these loaded information belongs
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContext;
        /**
         * we pass this parameter together with the targetContext parameter back to the client
         * to help him identify to whom these loaded information belongs
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * file name of the docx file located in the transient volume, If this is the first
         * time this object is viewed in the editor a file will be created (and an appropriate
         * error will be supplied)
         */
        std::string workInstructionFile;
        /**
         * A transient ID created by the server to identify the top object.
         */
        std::string targetObjectTransientId;
        /**
         * The display name of the target object.
         */
        std::string topObjectDisplayName;
        /**
         * a Vector containing all the available DCDs in this workInstruction document, could
         * be direct DCDs attached to the TargetObject and\or DCDs assigned to one of its assigned
         * STXs
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::LoadedSubSTXInfo > loadedDCDs;
        /**
         * a Vector containing all the available PFs in this workInstruction document, could
         * be direct PFs attached to the TargetObject or PFs assigned to one of its assigned
         * STXs
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::LoadedSubSTXInfo > loadedPFs;
        /**
         * list of symbols attached to the targetObject
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > symbols;
        /**
         * a Vector containing the assigned STX elementss in the operation\process workinstruction
         * document
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::LoadedSTXInfo > loadedSTXs;
    };

    /**
     * LoadedObjectsResponse
     */
    struct LoadedObjectsResponse
    {
        /**
         * a vector of the Load Information for each TargetObject and TargetContext (each combination
         * of TargetObject and TargetContext will have it's own WorkInstruction file and its
         * own unique list of objects)
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::LoadedObjectInfo > loadedObjects;
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * LoadedSTXInfo
     */
    struct LoadedSTXInfo
    {
        /**
         * the transient ID of the assigned Stx element (In this case we don't need to generate
         * a transient ID and can use the OccurrenceThreadStable ID of the Stx element).
         */
        std::string transientId;
        /**
         * the work instruction file name in the transient volume for this element, the client
         * will compose the entire work instruction document by pasting the content of this
         * file in the operation\process workinstruction file (the client will find the exact
         * paste location by using the transient ID)
         */
        std::string workInstructionFile;
        /**
         * the mes0ObjectData  property of the mes0BVRSTXElement object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  stxObjectData;
        /**
         * list of symbols attached to this Stx element.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > symbols;
    };

    /**
     * LoadedSubSTXInfo
     */
    struct LoadedSubSTXInfo
    {
        /**
         * the transient ID of the assigned DCD\PF element
         */
        std::string transientId;
        /**
         * A createInput object holding the appropriate DCD\PF Form attributes
         */
        Mes0::Services::Mes::_2010_09::Workinstructions::CreateInput objectData;
        /**
         * the type of the DCD\PF Form Object attached to this DCD\PF element
         */
        std::string objectType;
        /**
         * for example for a DCD assigned to an operation it's the operation object transientId,
         * DCD\PF assigned to an STX and the STX is assigned to an operation is the STX transientId
         */
        std::string owningObjectTransientId;
        /**
         * A persistent identifier for the DCD\PF object, will not be used by the client (the
         * client will pass it to the server through the save functionality)
         */
        std::string persistentId;
    };

    /**
     * a list of objects and context which will give us a resulted document of the object
     * configured according to the context
     */
    struct ObjectsReferenced
    {
        /**
         * a top line of the context we want the element to be configured according to it- if
         * non supplied will use the referenceObject current context
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContext;
        /**
         * Object which has WorkInstruction Dataset it can be Mfg0BVROperation, Mfg0BVRProcess,
         * MES0BVRStxElement
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
    };

    /**
     * a struct consist of the edited object, the docx file related to it and all its modified
     * objects in the current session.
     */
    struct SavedObjectInfo
    {
        /**
         * File ticket number used by client to upload the file to PLM. Server implementation
         * will use this ticket number to get the filepath of the uploaded file
         */
        std::string workInstructionFile;
        /**
         * the tag of the object edited (it could be the Stx or Operation\Process). Input should
         * be of type ImanItemBOPLine
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * list of new\ updated DCDs ,could be direct DCDs belonging to the target Object or\and
         * DCDs to belongs to one of the STXs assigned to target object
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::SavedSubSTXInfo > modifiedDCDs;
        /**
         * list of new\ updated PFs, could be direct PFs belonging to the target Object or (not
         * as in modifiedDCDs case)PFs  belongs to one of the STXs assigned to target object
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::SavedSubSTXInfo > modifiedPFs;
        /**
         * of all the symbols belonging to the target object.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > symbols;
        /**
         * list of new Stx elements add to the process\operation
         */
        std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::SavedSTXInfo > modifiedSTXs;
    };

    /**
     * SavedObjectsResponse
     */
    struct SavedObjectsResponse
    {
        /**
         * serviceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * struct containing new STXs
     */
    struct SavedSTXInfo
    {
        /**
         * a Unique transient ID for new STX
         */
        std::string transientId;
        /**
         * the mes0StxObjectData property of the assigned line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  stxObjectData;
    };

    /**
     * struct containing  new\ updated DCD\PF info
     */
    struct SavedSubSTXInfo
    {
        /**
         * a Unique transient ID for new DCD\PF
         */
        std::string transientId;
        /**
         * A persistent identifier for the DCD\PF object (the client will get it through the
         * load functionality)
         */
        std::string persistentId;
        /**
         * for example for a DCD assigned to an operation it's the operation object transientId
         * (the client got it in the load functionality),PF\DCD assigned to an STX and the STX
         * is assigned to an operation is the STX transientId
         */
        std::string owningObjectTransientId;
        /**
         * the runtime object for the DCD\PF Form object
         */
        Mes0::Services::Mes::_2010_09::Workinstructions::CreateInput objectData;
    };




    /**
     * This SOA returns for each given object in a given context its work instructions the
     * work instruction document with the data for all the model objects it contains.
     *
     * @param loadedInfo
     *        a list of objects and context which will give us a resulted document of the object
     *        configured according to the context
     *
     * @return
     *         this session loaded object ServiceData will have the following errors 1) NewWIFileError:
     *         will be used when a WI file was not found. In that case a new file is created 2)
     *         ObjectNotFoundInStructureError  -if an object is reference in the dataset but not
     *         found in the structure 3) TextNotfoundInStructureError : if a Text element ID not
     *         t appear in the WI dataset attributes. 4) AnotherWIRevsionConfiguredError : when
     *         configuring the reference object according to the TargetContext will result in a
     *         different revision.
     *
     * @deprecated
     *         As of Teamcenter 10, use the loadWorkInstructionDoc operation from the _2012_09 namesace.
     *         The structures loadedSubSTXInfo and loadedSTXInfo have the new element externalID.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the loadWorkInstructionDoc operation from the _2012_09 namesace. The structures loadedSubSTXInfo and loadedSTXInfo have the new element externalID."))
#endif
    virtual Mes0::Services::Mes::_2010_09::Workinstructions::LoadedObjectsResponse loadWorkInstructionDoc ( const std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::ObjectsReferenced >& loadedInfo ) = 0;

    /**
     * This service updates the work instructions for a given target object. It receives
     * as input a WI file edited by the client application, with a list of modified model
     * objects and their properties, and updates the WI model accordingly. The document
     * will also be modified with the internal IDs for all objects, and be saved together
     * with the target object.
     *
     * @param savedObjects
     *        vector of modified objects
     *
     * @return
     *         The service data will return the following errors: 1) SavingDenied When a permission
     *         problem will restrict you from saving any of the data elements involve in the save.
     *
     * @deprecated
     *         As of Teamcenter 10, use the saveWorkInstructionDoc operation from the _2012_09 namesace.
     *         The structure SavedObjectInfo, element name was changed from workInstructionFile
     *         to workInstructionFileTicket.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the saveWorkInstructionDoc operation from the _2012_09 namesace. The structure SavedObjectInfo, element name was changed from workInstructionFile to workInstructionFileTicket."))
#endif
    virtual Mes0::Services::Mes::_2010_09::Workinstructions::SavedObjectsResponse saveWorkInstructionDoc ( const std::vector< Mes0::Services::Mes::_2010_09::Workinstructions::SavedObjectInfo >& savedObjects ) = 0;


protected:
    virtual ~Workinstructions() {}
};
            }
        }
    }
}

#include <mes0/services/mes/MES_undef.h>
#endif

