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

#ifndef MES0_SERVICES_MES__2013_05_WORKINSTRUCTIONS_HXX
#define MES0_SERVICES_MES__2013_05_WORKINSTRUCTIONS_HXX

#include <mes0/services/mes/_2012_09/Workinstructions.hxx>
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
            namespace _2013_05
            {
                class Workinstructions;

class TCSOAMESSTRONGMNGD_API Workinstructions
{
public:

    struct LoadedObjectInfo;
    struct LoadedObjectsResponse;
    struct LoadedReferencedObjectInfo;
    struct ObjectsReferenced;
    struct SavedObjectInfo;
    struct SavedObjectsResponse;
    struct SavedReferencedObjectInfo;

    /**
     * Conatins loaded targetObjects (<b>MEProcessRevision</b>,<b>MEOPRevision</b> or <b>Mes0MESTXElementRevision</b>)
     * along with the elements of work instructions document i.e.(<b>Mes0MEDCD</b>, <b>Mes0MEPF</b>
     * and <b>Mes0MESymbol</b>).
     */
    struct LoadedObjectInfo
    {
        /**
         * The context object (<b>MEProcessRevision</b> or <b>MEOPRevision</b>) to help client
         * identify to whom these loaded information belongs.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContext;
        /**
         * The tag of the object loaded (<b>Mes0MESTXElementRevision</b>, <b>MEProcessRevision</b>
         * or <b>MEOPRevision</b>).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * File name of the work instructrion document located in the transient volume. If this
         * is the first time this object is viewed in the editor a file will be created.
         */
        std::string workInstructionFile;
        /**
         * A transient ID created by the server to identify the target object.
         */
        std::string targetObjectTransientId;
        /**
         * The display name of the target object.
         */
        std::string topObjectDisplayName;
        /**
         * List of loaded <b>Mes0MEDCD</b> objects, could be direct <b>Mes0MEDCD</b>s belonging
         * to the target object or / and <b>Mes0MEDCD</b>s to belonging to one of the <b>Mes0MESTXElementRevision</b>
         * assigned to target object.
         */
        std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::LoadedSubSTXInfo > loadedDCDs;
        /**
         * List of loaded <b>Mes0MEPF</b>s, could be direct <b>Mes0MEPF</b>s belonging to the
         * target object or <b>Mes0MEPF</b>s belongs to one of the <b>Mes0MESTXElementRevision</b>
         * assigned to target object.
         */
        std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::LoadedSubSTXInfo > loadedPFs;
        /**
         * List of all the <b>Mes0MESymbol</b> objects belonging to the target object.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > symbols;
        /**
         * List of loaded <b>Mes0MESTXElementRevision</b> elements added to the <b>MEProcessRevision</b>
         * or <b>MEOPRevision</b>.
         */
        std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::LoadedSTXInfo > loadedSTXs;
        /**
         * A list of structure LoadedReferencedObjectInfo holding transient ID i.e. the ID for
         * the content control holding reference and referenced <b>Dataset</b> object in textual
         * work instructions.
         */
        std::vector< Mes0::Services::Mes::_2013_05::Workinstructions::LoadedReferencedObjectInfo > referencedObjectInfo;
    };

    /**
     * LoadedObjectsResponse
     */
    struct LoadedObjectsResponse
    {
        /**
         * A vector of the load information for each targetObject and targetContext (each combination
         * of targetObject and targetContext will have its own work instruction file and its
         * own unique list of objects)
         */
        std::vector< Mes0::Services::Mes::_2013_05::Workinstructions::LoadedObjectInfo > loadedObjects;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure to hold transient ID i.e. the ID for the content control holding reference
     * and referencedObject in Textual Work Instructions.
     */
    struct LoadedReferencedObjectInfo
    {
        /**
         * Transient ID from client for referenced object.
         */
        std::string transientId;
        /**
         * Referenced Object. These can be any datasets in Teamcenter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  referencedObject;
    };

    /**
     * A list of objects and context which will give us a resulted document of the object
     * configured according to the context.
     */
    struct ObjectsReferenced
    {
        /**
         * A top line of the context we want the element to be configured according to it- if
         * non supplied will use the referenceObject current context.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetContext;
        /**
         * Object which has WorkInstruction Dataset it can be Mfg0BVROperation, Mfg0BVRProcess,
         * MES0BVRStxElement.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
    };

    /**
     * A structure consists of the edited object, the docx file related to it and all its
     * modified objects in the current session.
     */
    struct SavedObjectInfo
    {
        /**
         * File ticket of the work instruction file uploaded to the server.
         */
        std::string workInstructionFileTicket;
        /**
         * The tag of the object edited (<b>Mes0MESTXElementRevision</b>, <b>MEProcessRevision</b>
         * or <b>MEOPRevision</b>).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * List of new or updated <b>Mes0MEDCD</b> objects ,could be direct <b>Mes0MEDCD</b>s
         * belonging to the target object or / and <b>Mes0MEDCD</b>s to belonging to one of
         * the <b>Mes0MESTXElementRevision</b> assigned to target object.This parameter can
         * be empty.
         */
        std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::SavedSubSTXInfo > modifiedDCDs;
        /**
         * List of new\ updated <b>Mes0MEPF</b>s, could be direct <b>Mes0MEPF</b>s belonging
         * to the target object or <b>Mes0MEPF</b>s  belongs to one of the <b>Mes0MESTXElementRevision</b>
         * assigned to target object. This parameter can be empty.
         */
        std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::SavedSubSTXInfo > modifiedPFs;
        /**
         * List of all the <b>Mes0MESymbol</b> objects belonging to the target object. This
         * parameter can be empty.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > symbols;
        /**
         * List of new or modified <b>Mes0MESTXElementRevision</b> elements added to the <b>MEProcessRevision</b>
         * or <b>MEOPRevision</b>. This can be empty in case the operation is called for saving
         * standard text document or if work instruction document does not contain any <b>Mes0MESTXElementRevision</b>
         * elements in it.
         */
        std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::SavedSTXInfo > modifiedSTXs;
        /**
         * A list of structure SavedReferencedObjectInfo  holding transient ID i.e. the ID for
         * the content control holding reference and referenced <b>Dataset</b> object in textual
         * work instructions. This can be empty if the save operation is for saving the standard
         * text document or if the textual work instruction document does not contain any referenced
         * <b>Dataset</b>.
         */
        std::vector< Mes0::Services::Mes::_2013_05::Workinstructions::SavedReferencedObjectInfo > referencedObjectInfo;
    };

    /**
     * SavedObjectsResponse
     */
    struct SavedObjectsResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure to hold transient ID i.e. the ID for the content control holding reference
     * and referencedObject in Textual Work Instructions.
     */
    struct SavedReferencedObjectInfo
    {
        /**
         * Transient ID from client for referenced object.
         */
        std::string transientId;
        /**
         * This can be any <b>Dataset</b> in Teamcenter.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  referencedObject;
    };




    /**
     * This operation loads the work instructions document for a given target object (<b>Mes0MESTXElementRevision</b>,
     * <b>MEProcessRevision</b> or <b>MEOPRevision</b>). It receives as input target object
     * (<b>Mes0MESTXElementRevision</b>, <b>MEProcessRevision</b> or <b>MEOPRevision</b>)
     * and context object (in case when <b>Mes0MESTXElementRevision</b> is being added to
     * the <b>MEProcessRevision</b> or <b>MEOPRevision</b>).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Load standard text document</b>
     * <br>
     * The user either loads the out of the box word template document or earlier saved
     * standard text document in standard text view in client. To do this, the user selects
     * the <b>Mes0MESTXElementRevision</b> in Manufacturing Process Planner application.
     * The application either loads the empty template or collects <b>Mes0MEDCD</b>, a <b>Mes0MEPF</b>
     * and <b>Mes0MESymbol</b> object related to <b>Mes0MESTXElementRevision</b>, embeds
     * them in work instruction document and provides complete loaded standard text document
     * to the client along with the model objects.
     * <br>
     * <b>Use case 2: Load work instructions document</b>
     * <br>
     * The user either loads the out of the box word template document or earlier saved
     * work instructions document in work instructions view in client. To do this, the user
     * selects either <b>MEProcessRevision</b> or <b>MEOPRevision</b> in Manufacturing Process
     * Planner application. The application loads the empty template or collects <b>Mes0MEDCD</b>,
     * <b>Mes0MEPF</b>, <b>Mes0MESymbol</b> and <b>Mes0MESTXElementRevision</b> objects
     * related to <b>MEProcessRevision</b> or <b>MEOPRevision</b>, embeds them in textual
     * work instruction and provides complete loaded work instructions document to the client
     * along with the model objects.
     *
     * @param loadedInfo
     *        A list of target objects (<b>Mes0MESTXElementRevision</b>, <b>MEProcessRevision</b>
     *        or <b>MEOPRevision</b>), and context object (in case when <b>Mes0MESTXElementRevision</b>
     *        is added to the <b>MEProcessRevision</b> or <b>MEOPRevision</b>).
     *
     * @return
     *         This operation returns for each given object in a given context its work instruction
     *         document with the data for all the model objects it contains.
     *         <br>
     *         <b>ServiceData</b> may have the following partial errors
     *         <br>
     *         254501 A Manufacturing Execution System internal error.
     *         <br>
     *         254502 The specification template preference does not exist for Work Instruction
     *         objects.
     *         <br>
     *         254503 The value for the specification template preference is empty for Work Instruction
     *         objects.
     *         <br>
     *         254505 The object ID is missing for the object.
     *         <br>
     *         254506 ObjectNotFoundInStructureError -If an object is reference in the dataset but
     *         not found in the structure.
     *         <br>
     *         254004 Work instruction document can not be loaded for the target object supplied.
     *         <br>
     *
     */
    virtual Mes0::Services::Mes::_2013_05::Workinstructions::LoadedObjectsResponse loadWorkInstructionDoc ( const std::vector< Mes0::Services::Mes::_2013_05::Workinstructions::ObjectsReferenced >& loadedInfo ) = 0;

    /**
     * This operation updates the work instructions for a given target object (<b>Mes0MESTXElementRevision</b>,
     * <b>MEProcessRevision</b> or <b>MEOPRevision</b>). It receives as input work instructions
     * file edited by the client application, with a list of modified model objects (<b>Mes0MEDCD</b>,
     * <b>Mes0MEPF</b>) and their properties, and updates the work instructions model accordingly.
     * The document is also modified with the internal IDs for all objects and save the
     * data model.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case 1: Save standard text document</b>
     * <br>
     * The user loads the out of the box word template document in standard text view in
     * client. User creates one or more <b>Mes0MEDCD</b>, <b>Mes0MEPF</b> objects, embeds
     * one or more <b>Mes0MESymbol</b> objects in standard text document and then perform
     * save action. The application creates required objects in Teamcenter.
     * <br>
     * <b>Use case 2: Save textual work instructions document</b>
     * <br>
     * The user loads the out of the box word template document in textual work instructions
     * view in client. User creates one or more <b>Mes0MEDCD</b>, <b>Mes0MEPF</b> objects,
     * embeds one or more standard text document and then perform save action. The application
     * creates required objects in Teamcenter.
     *
     * @param savedObjects
     *        A list of target object (<b>Mes0MESTXElementRevision</b>, <b>MEProcessRevision</b>
     *        or <b>MEOPRevision</b>), the work instruction document related to it and all its
     *        modified objects (<b>Mes0MEDCD</b>, <b>Mes0MEPF</b>) in the current session.
     *
     * @return
     *         Following partial errors may be returned in <b>ServiceData</b>.
     *         <br>
     *         254002 - Standard text functionality is not supported for the target object.
     *         <br>
     *         254003 - Work instructions functionality is not supported for the target object.
     *         <br>
     *         254504 - The document does not exist in the transient volume.
     *         <br>
     *         254005 - Work instruction document can not be saved for the target object supplied.
     *
     */
    virtual Mes0::Services::Mes::_2013_05::Workinstructions::SavedObjectsResponse saveWorkInstructionDoc ( const std::vector< Mes0::Services::Mes::_2013_05::Workinstructions::SavedObjectInfo >& savedObjects ) = 0;


protected:
    virtual ~Workinstructions() {}
};
            }
        }
    }
}

#include <mes0/services/mes/MES_undef.h>
#endif

