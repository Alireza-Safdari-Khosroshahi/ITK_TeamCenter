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

#ifndef MES0_SERVICES_MES_WORKINSTRUCTIONSSERVICE_HXX
#define MES0_SERVICES_MES_WORKINSTRUCTIONSSERVICE_HXX

#include <mes0/services/mes/_2010_09/Workinstructions.hxx>
#include <mes0/services/mes/_2012_09/Workinstructions.hxx>
#include <mes0/services/mes/_2013_05/Workinstructions.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mes0/services/mes/MES_exports.h>

namespace Mes0
{
    namespace Services
    {
        namespace Mes
        {
            class WorkinstructionsService;

/**
 * The WorkInstructions service provides operations to load and save work instructions
 * data in Manufacturing Process Planning application.
 * <br>
 * The service provides following use cases for the Teamcenter manufacturing structures.
 * <br>
 * <ul>
 * <li type="disc">Load and save standard text document using one or more <b>Mes0MEDCD</b>,
 * <b>Mes0MEPF</b>, <b>Mes0MESymbol</b> objects.
 * </li>
 * <li type="disc">Load and save textual work instruction document using one or more
 * <b>Mes0MEDCD</b>, <b>Mes0MEPF</b>, <b>Mes0MESTXElementRevision</b> objects.
 * </li>
 * </ul>
 * <br>
 * During the process of save it
 * <br>
 * <ul>
 * <li type="disc">Creates one or more <b>Mes0MEDCD</b>, <b>Mes0MEPF</b> objects for
 * a <b>BOPLine</b>.
 * </li>
 * <li type="disc">Relates <b>Mes0MESymbol</b> to <b>Mes0MESTXElementRevision</b> using
 * a <b>Mes0MESymbolRelation</b> and <b>Mes0MEWIAssets</b> object to <b>Mes0MESTXElementRevision</b>,
 * <b>MEProcessRevision</b> or <b>MEOPRevision</b> using <b>Mes0MEWIAssetsRelation</b>.
 * </li>
 * <li type="disc">Relates <b>Mes0MESTXElementRevision</b> to <b>MEProcessRevision</b>
 * or <b>MEOPRevision</b>.
 * </li>
 * <li type="disc">Modifies existing <b>Mes0MEDCD</b>, <b>Mes0MEPF</b> and <b>Mes0MEWIAssets</b>
 * objects.
 * </li>
 * </ul>
 * <br>
 * During the process of load it
 * <br>
 * <ul>
 * <li type="disc">Collects the <b>Mes0MEWIAssets</b> object to load the work instruction
 * document.
 * </li>
 * <li type="disc">Collects the <b>Mes0MEDCD</b>, <b>Mes0MEPF</b> and <b>Mes0MESTXElementRevision</b>
 * and embeds them in the work instruction document and provides this document to the
 * client.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmes0soamesstrongmngd.dll
 * </li>
 * <li type="disc">libmes0soamestypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMESSTRONGMNGD_API WorkinstructionsService
    : public Mes0::Services::Mes::_2010_09::Workinstructions,
             public Mes0::Services::Mes::_2012_09::Workinstructions,
             public Mes0::Services::Mes::_2013_05::Workinstructions
{
public:
    static WorkinstructionsService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This SOA returns for each given object in a given context its work instructions the
     * work instruction document with the data for all the model objects it contains.
     *
     * @param loadedInfo
     *        a list of objects and context which will give us a resulted document of the object
     *        configured according to the context
     *
     * @return
     *         this session loaded object ServiceData will have the following errors 1)NewWIFileError:
     *         will be used when a WI file was not found. In that case a new file is created 2)ObjectNotFoundInStructureError
     *         -if an object is reference in the dataset but not found in the structure 3)TextNotfoundInStructureError
     *         : if a Text element ID not t appear in the WI dataset attributes. 4)AnotherWIRevsionConfiguredError
     *         : when configuring the reference object according to the TargetContext will result
     *         in a different revision.
     *
     */
    virtual Mes0::Services::Mes::_2012_09::Workinstructions::LoadedObjectsResponse loadWorkInstructionDoc ( const std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::ObjectsReferenced >& loadedInfo ) = 0;

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
     *         The service data will return the following errors 1) SavingDenied When a permission
     *         problem will restrict you from saving any of the data elements involve in the save.
     *
     */
    virtual Mes0::Services::Mes::_2012_09::Workinstructions::SavedObjectsResponse saveWorkInstructionDoc ( const std::vector< Mes0::Services::Mes::_2012_09::Workinstructions::SavedObjectInfo >& savedObjects ) = 0;

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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WorkinstructionsService")

};
        }
    }
}


#pragma warning ( pop )

#include <mes0/services/mes/MES_undef.h>
#endif

