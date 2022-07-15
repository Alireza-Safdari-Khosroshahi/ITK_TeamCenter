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

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT_REQUIREMENTSMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT_REQUIREMENTSMANAGEMENTSERVICE_HXX

#include <teamcenter/services/requirementsmanagement/_2007_01/Requirementsmanagement.hxx>
#include <teamcenter/services/requirementsmanagement/_2008_06/Requirementsmanagement.hxx>
#include <teamcenter/services/requirementsmanagement/_2009_10/Requirementsmanagement.hxx>
#include <teamcenter/services/requirementsmanagement/_2010_09/Requirementsmanagement.hxx>
#include <teamcenter/services/requirementsmanagement/_2011_06/Requirementsmanagement.hxx>
#include <teamcenter/services/requirementsmanagement/_2012_09/Requirementsmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Requirementsmanagement
        {
            class RequirementsmanagementService;

/**
 * The RequirementsManagement service provides operations to create and update <b>Item</b>
 * objects. This service can create and update the <b>Dataset</b> when creating the
 * <b>Item</b> objects. It can update the related objects such as <b>Dataset</b> and
 * <b>Form</b>. It provides a basic support for editing the rich text of <b>Requirement</b>
 * objects.  It also provides support for exporting Teamcenter objects to <b>MSWord</b>
 * and <b>MSExcel</b>.
 * <br>
 * The RequirementsManagement service service can be used for supporting following use
 * cases:
 * <br>
 * <ul>
 * <li type="disc">Create object of type <b>Item</b>
 * </li>
 * <li type="disc">Update objects of type <b>Item</b>
 * </li>
 * <li type="disc">Create and update <b>Dataset</b>
 * </li>
 * <li type="disc">Get the rich text of <b>Requirement</b>
 * </li>
 * <li type="disc">Set the rich text of <b>Requirement</b>
 * </li>
 * <li type="disc">Export Teamcenter objects to <b>MSWord</b>
 * </li>
 * <li type="disc">Export Teamcenter objects to <b>MSExcel</b>
 * </li>
 * <li type="disc">Create the traceability matrix between two BOM structures based on
 * <b>TraceLink</b> relation
 * </li>
 * <li type="disc">Manipulate the <b>BOMLine</b> by moving the <b>BOMLine</b> upwards,
 * downwards or to specified &nbsp;&nbsp;&nbsp;&nbsp;location
 * </li>
 * <li type="disc">Open objects of type <b>Fnd0ParamReqment</b>
 * </li>
 * <li type="disc">Publish the column configuration that is marked as publishable by
 * the user.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoarequirementsmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoarequirementsmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API RequirementsmanagementService
    : public Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement,
             public Teamcenter::Services::Requirementsmanagement::_2008_06::Requirementsmanagement,
             public Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement,
             public Teamcenter::Services::Requirementsmanagement::_2010_09::Requirementsmanagement,
             public Teamcenter::Services::Requirementsmanagement::_2011_06::Requirementsmanagement,
             public Teamcenter::Services::Requirementsmanagement::_2012_09::Requirementsmanagement
{
public:
    static RequirementsmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation creates objects of type <b>Item</b> .  The related objects such as
     * <b>ItemRevision</b>, <b>Dataset</b> and <b>Forms</b> are also created during this
     * operation.  This operation checks for the existence of the <b>Item</b>, <b>ItemRevision</b>,
     * and <b>Dataset</b>.  If the <b>Item</b> and <b>ItemRevision</b> already exists, but
     * the <b>Dataset</b> does not exist, then the <b>Dataset</b> is created.  If the <b>Dataset</b>
     * exists, a new version will be added to the existing version.  If any of the objects
     * exists, but the input attribute values that differ from those already set, attempts
     * are made to update the values. There is no attempt to query and update an existing
     * object without a reference to that object. This operation has the additional behavior
     * to create and update the <b>Dataset</b> along with the creation of <b>Item</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create objects of type <b>Item</b> using this operation.
     * <br>
     * User can create or update objects of type <b>Dataset</b> using this operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param info
     *        A list of structures containing the required information to create/update objects
     *        of type <b>Item</b>.
     *
     * @return
     *         The created or updated <b>Item</b>, <b>ItemRevision</b> and <b>Dataset</b> object
     *         for each requested input. Each of the created or updated objects will also be added
     *         to the appropriate created or updated list in the <code>ServiceData</code>.  If there
     *         are any errors during the creation of <b>Item</b>, then the appropriate error is
     *         added in the <code>ServiceData</code>.
     *
     *
     * @exception ServiceException
     *           None.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::CreateOrUpdateResponse createOrUpdate ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::PartInfo >& info ) = 0;

    /**
     * This operation is used for exporting Teamcenter objects (<b>WorkspaceObject</b>)
     * to applications like <b>MSWord</b> and <b>MSExcel</b>.  Teamcenter business objects
     * should already be created so that the objects can be exported to <b>MSWord</b> and
     * <b>MSExcel</b> using the service operation.
     * <br>
     * <br>
     * An Excel (.mhtml) or a Word (.docx) file is generated at the server as a result of
     * this operation.  The generated file will contain Teamcenter objects and their properties.
     * Depending upon the application format that is being passed as input parameter, the
     * generated file can be opened in <b>MSWord</b> or <b>MSExcel</b>.  If the application
     * format is <b>MSWordXML</b> then the generated document is a Word document.  If the
     * application format is <b>MSExcel</b> then the generated sheet is a static Excel spreadsheet.
     * If the application format is <b>MSExcelLive</b> then the generated sheet is a Live
     * Excel spreadsheet. "Live" sheet means that modifications can be done to the data
     * in <b>MSExcel</b> which will reflect to Teamcenter.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create Teamcenter objects in RAC and then export those objects and their
     * properties to <b>MSWord</b> or <b>MSExcel</b>. If "Live" option is selected then
     * User can create "Live" spreadsheet after export to <b>MSExcel</b>.
     * <br>
     * <br>
     * Following usecases are supported in this operation
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Export of Workspace objects to MSWord (static)
     * </li>
     * <li type="disc">Export of Teamcenter objects to MSExcel(static)
     * </li>
     * <li type="disc">Export of Teamcenter objects to MSExcel(Live) and edit the properties
     * from Excel Live sheet.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A vector of <code>ExportToApplicationInputData</code> structures containing the required
     *        information to export Teamcenter business objects to <b>MSWord</b> /<b>MSExcel</b>.
     *
     * @return
     *         A vector of <code>ExportToApplicationResponse</code> structures containing the ticket
     *         of the exported file is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the generation of file then the appropriate error is added in the ServiceData and
     *         returned. Example if there is a error generated during export of non workspace objects
     *         to <b>MSWord</b> then the appropriate error code and the error message is added to
     *         the error stack. This error stack is part of serviceData.
     *
     *
     * @exception ServiceException
     *           If there is any error during generating transient file read ticket due to a configuration
     *           issue at the server, then the operation throws a service exception. Example- If the
     *           transient volume directory is not configured at the server then the FMS fails to
     *           generate a file at the server and subsequent file download operation fails. In such
     *           situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExportToApplicationResponse exportToApplication ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExportToApplicationInputData >& inputs ) = 0;

    /**
     * getRichContent operation is used to retrieve rich text contents of <b>SpecElement</b>
     * type of objects which is a subclass of <b>WorkspaceObject</b>.  A .<i>docm</i> file
     * is generated as a result of getRichContent operation which can be opened in MSWord.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can open content (body text) in word for view and edit purpose.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of structures containing the required information to open requirement content
     *        in word.
     *
     * @return
     *         A list of FMS transient file tickets for each requested requirement. Each ticket
     *         is for MSWord file containing rich text generated at the server.
     *
     *
     * @exception ServiceException
     *           If there is any error during generating transient file read ticket due to a configuration
     *           issue at the server, then the operation throws a service exception. Example- If the
     *           transient volume directory is not configured at the server then the FMS fails to
     *           generate a file at the server and subsequent file download operation fails. In such
     *           situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::GetRichContentResponse getRichContent ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::GetContentInput >& inputs ) = 0;

    /**
     * This operation is used for importing the contents of the given MSWord document  to
     * create objects of type <b>SpecElement</b>.  The MSWord document to be imported to
     * Teamcenter should have .docx file format. If the application format is MSWordXML
     * then the operation parses the given MSWord document to creates a structure of chosen
     * subtype of <b>SpecElement</b>.
     * <br>
     * <br>
     * Objects of type <b>Requirement</b>/<b>Paragraph</b> are created at the server after
     * importing the document.  When this operation is called from Teamcenter rich client,
     * a structure is created and is opened in the <code>RequirementsManagement</code> application.
     * The structure and indentation of the child <b>Requirement</b> is driven by the MSWord
     * outline level in the document.  Each <b>Paragraph</b> that is formatted in an outline
     * level style produces a separate Requirement. This file may be located in a local
     * file system folder or a network folder.  This operation supports MSWord documents
     * in <b>MS</b> Office Open XML format (.docx format) only.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can create an MSWord document and import it using this operation to create a
     * structure. Each <b>Paragraph</b> in MSWord document represents a <b>Requirement</b>/<b>Paragraph</b>
     * in the structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of <code>ImportFromApplicationInputData</code> structures containing the information
     *        to import MSWord document and create a structure.  It contains the file ticket of
     *        the document to be imported, the application format "<i>MSWordXML</i>" and the subtype
     *        of the <b>SpecElement</b> to be created after import of document to Teamcenter.
     *
     * @return
     *         A vector of <code>ImportFromApplicationResponse</code> structures, one for each successfully
     *         imported Word document is returned.
     *         <br>
     *         There are no objects returned in the ServiceData. If there are any errors during
     *         the import of document then the import operation is aborted and appropriate error
     *         code along with the error message is added to the error stack. This error stack is
     *         part of serviceData which is returned to the caller.
     *         <br>
     *
     *
     * @exception ServiceException
     *           If there is any error during generating transient file ticket due to a configuration
     *           issue at the server, then the operation throws a service exception. For example If
     *           the transient volume directory is not configured at the server then the FMS fails
     *           to import the document and subsequent file upload operation fails. In such situation
     *           a service exception is thrown.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ImportFromApplicationResponse importFromApplication ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ImportFromApplicationInputData >& inputs ) = 0;

    /**
     * The SOA operation is responsible for setting rich text contents from Word document
     * to a <b>Fulltext</b> object of requirement. This SOA operation will be called when;
     * User modified rich content of requirements through word document. This operation
     * will basically accept <b>Fulltext</b> object to process in "objectToProcess" variable.
     * Along with <b>Fulltext</b> object, this operation will accept transient file tickets
     * for <b>MSWord</b> Document which is modified by user. All exceptions are added to
     * service data, if occurred.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can set rich text contents of <b>SpecElement</b> object by using setRichContent
     * SOA.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of <code>SetContentInput</code>  type of structure needed to set the content
     *        of <b>Fulltext</b> object using <b>MSWord</b> file.
     *        <br>
     *
     * @return
     *         A <code>SetRichContent</code> structure is returned.  It contains information about
     *         the failure in ServiceData.
     *
     *
     * @exception ServiceException
     *           If there is any error while downloading file then the operation throws a service
     *           exception. Example- The transient volume directory is not configured at the server
     *           then the FMS fails to generate a file at the server and subsequent file download
     *           operation fails. In such situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::SetRichContentResponse setRichContent ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::SetContentInput >& inputs ) = 0;

    /**
     * The SOA operation is responsible for retrieving contents of objects of type <b>SpecElement</b>.
     * It can be used to view content of <b>SpecElement</b> in word. SOA also provides capability
     * to view contents by applying default templates.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can open requirements in word using default templates or they can open content
     * (body text) in word for view and edit purpose.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        A list of structures containing the required information to open requirement content
     *        in word.
     *
     * @return
     *         A vector of transientFileReadTickets containing the document having rich text is
     *         returned to the user.
     *
     *
     * @exception ServiceException
     *           If there is any error during generating transient file read ticket due to a configuration
     *           issue at the server, then the operation throws a service exception. Example- If the
     *           transient volume directory is not configured at the server then the FMS fails to
     *           generate a file at the server and subsequent file download operation fails. In such
     *           situation a service exception is thrown.
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::GetRichContentResponse getRichContent ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2008_06::Requirementsmanagement::GetContentInput1 >& inputs ) = 0;

    /**
     * This operation helps to open <b>Fnd0ParamReqment</b> object, or its Revision <b>Fnd0ParamReqmentRevision</b>
     * contents in Teamcenter MS Word view. User will get the note text associated with
     * the selected <b>Fnd0ParamReqmentRevision</b> allowing editing in that view. Opening
     * <b>Fnd0ParamReqment</b>/ <b>Fnd0ParamReqmentRevision</b> happens in two different
     * ways:
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;In context with <code>Fnd0ListsParamReqments</code> relation:
     * In this case, operation gives the Parameter/ value pairs selected in context for
     * the parent object of <code>Fnd0ListsParamReqments</code>, allowing editing the values.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Without context: In this case, it gives note text associated
     * for the <b>Fnd0ParamReqmentRevision</b> for view/edit purpose.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Suppose user created <b>Fnd0ParamReqment</b> object, and
     * now wants to see/edit note text of it, then opening Teamcenter MS Word view, user
     * will see it, and can edit it.
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Suppose user has attached any <b>Fnd0ParamReqment</b>/<b>Fnd0ParamReqmentRevision</b>
     * object to any other <b>Item</b>/<b>ItemRevision</b> object with <code>Fnd0ListsParamReqments</code>
     * relation, and now wants to edit/view parameter values which are set while attaching
     * this <b>Fnd0ParamReqment</b>/<b>Fnd0ParamReqmentRevision</b>, then opening Teamcenter
     * MS Word view will show it.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A list of structures containing <b>Fnd0ParamReqmentRevision</b> object with <code>Fnd0ListsParamReqments</code>
     *        relation object by which <b>Fnd0ParamReqmentRevision</b> is attached to any other
     *        object.
     *
     * @return
     *         Result of operation is including resultant <code>OpenStdNoteContents</code> structures
     *         along with ServiceData. This structure will contain input object, Note Text, Template
     *         text, and Parameter and Values details in selected context.
     *         <br>
     *         Any failure to getting <code>Fnd0ParamReqment</code> values will be returned with
     *         client id mapped to error message in the ServiceData list of partial errors.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::OpenStdNoteResponse openStdNote ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::StdNoteInput >& input ) = 0;

    /**
     * Sets the parameters and their values on <b>Standard Note</b>/<b>Parametric Requirement</b>.
     * This SOA operation can set values on one or more <b>Standard Note</b>/<b>Parametric
     * Requirement</b> in one operation call. When any <b>Standard Note</b>/<b>Parametric
     * Requirement</b> attached to any <b>ItemRevision</b> it will get attached with relation
     * <b>Fnd0ListsParamRequirements</b> (Parametric Requirements Lists). In that context
     * if that <b>Standard Note</b>/<b>Parametric Requirement</b> object is selected, and
     * edited in <b>MS Word</b> view, then saving of editing values from this view will
     * be set on this <b>Standard Note</b>/<b>Parametric Requirement</b> using this SOA.
     * This SOA will set those parameters and their values on given relation object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can edit, and set <b>Standard Note</b>/<b>Parametric Requirement</b> Parameter
     * values using <b>MS Word view</b> in Teamcenter. This view can be launched using Window->Show
     * view->Other->Teamcenter->MS Word
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        List of standard note input details with their values on parameters to be set.
     *
     * @return
     *         Result of SOA operation is including resultant <code>SetStdNoteResult</code> structure
     *         along with ServiceData. This structure will contain <b>Standard Note</b>/<b>Parametric
     *         Requirement</b> object and it's Note Text.
     *         <br>
     *         Any failure to setting <b>Standard Note</b> values will be returned with client id
     *         mapped to error message in the ServiceData list of partial errors.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::SetStdNoteResponse setStdNote ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2009_10::Requirementsmanagement::SetStdNoteDetails >& input ) = 0;

    /**
     * This operation manipulates the <b>BOMLine</b> Structure (<b>Requirement</b>/ <b>Function</b>/
     * <b>SEBlock</b> structure) by moving the selected <b>BOMLine</b> object either Upwards,
     * Downwards or to a specific position. A <b>Number</b> property will be updated for
     * selected <b>Fnd0BuildingBlockBOMLine</b> object along with its children.
     * <br>
     * Following operation are supported by this service operation.
     * <br>
     * <ul>
     * <li type="disc">Move Up - To move up the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, if a requirement structure
     * "Req_01", we have two children "SubReq_01" and "SubReq_02". In move up structure
     * modification can be done with respect to the parent. Requirements "SubReq_01" and
     * "SubReq_02" can be move up in context of parent "Req_01".
     * </li>
     * <li type="disc">Move Down - To move down the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, if a requirement structure
     * "Req_01", we have two children "SubReq_01" and "SubReq_02". In move down structure
     * modification can be done with respect to the parent. Requirements "SubReq_01" and
     * "SubReq_02" can be move down in context of parent "Req_01".
     * </li>
     * <li type="disc">Promote - To indent the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, promote a requirement
     * previously occupying level 2, with number "1.1", moves to the level 1, with number
     * "2.0". Children previously occupying level 3 with number "1.1.1", moves to the level
     * 2, with number "2.1".
     * </li>
     * <li type="disc">Demote - To out-dent the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, demote a requirement
     * previously occupying level 2, with number "1.0", moves to the level 3, with number
     * "1.1.1". Children previously occupying level 3, with number "1.1.1", moves to the
     * level 4, with number "1.1.1.1".
     * </li>
     * <li type="disc">Edit Number - To move the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. You can able to move selected BOM
     * line object from one level to other and from one parent to other parent.  For instance,
     * if a requirement has number "1.1.1" which means it is under parent "1.1". If the
     * number changed to "1.1.3", the requirement is repositioned under the parent. If the
     * number is changed to "2.1", then requirement will be removed from the parent and
     * put under the sibling of the parent.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can manipulate the hierarchy for a selected <b>Requirement</b> /<b>Function</b>/
     * <b>SEBlockBOMLine</b> object by using the moveLine operation. The given <b>Fnd0BuildingBlockBOMLine</b>
     * object will be moved as per the choice along with its children and the Number property
     * will be updated with new values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A list of <code>MoveLineInfo</code> structures which hold the required information
     *        to move selected <b>Fnd0BuildingBlockBOMLine</b> object along with its sibling.
     *
     * @return
     *         ServiceData object is returned. The updated <b>Fnd0BuildingBlockBOMLine</b> object
     *         is returned in the updated object list of ServiceData. Any failure will be returned
     *         with client id mapped to error message in the ServiceData list of partial errors.
     *         Following error codes are returned in the ServiceData.
     *         <br>
     *         <ul>
     *         <li type="disc">266001&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be Move Up in the BOM structure because it is the top children for
     *         parent object of selected object.
     *         </li>
     *         <li type="disc">266002&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be Move Down in the BOM structure because it is the last children
     *         for parent object of selected object.
     *         </li>
     *         <li type="disc">266003&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be promoted in the BOM structure because selected object could not
     *         be indent.
     *         </li>
     *         <li type="disc">266004&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         could not be demoted in the BOM structure because selected object could not be out-dented.
     *         </li>
     *         <li type="disc">266005&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be Move to any level in the BOM structure as pre input number property
     *         value.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2010_09::Requirementsmanagement::MoveLineResponse moveLine ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2010_09::Requirementsmanagement::MoveLineInfo >& input ) = 0;

    /**
     * This operation publishes the Column Configuration that is <b>Mark as Publishable</b>
     * by the user. This operation will get the column configuration values from the specified
     * <b>Fnd0ColumnConfiguration</b> object and create the site preferences. After creating
     * the site preference it will set the "IsPublished" property to true present on the
     * specified <b>Fnd0ColumnConfiguration</b> object.  So by creating the site preference
     * these column configuration will be visible to all present users in the system. This
     * operation converts the user preferences to the site level preferences in Teamcenter
     * Context so that all users can use it. When user save the column configuration, applied
     * on the BOM structure then it will store all applied column configuration values as
     * user protection scope preferences. After that user can mark the same column configuration
     * as <b>Mark as Publishable</b> that means user want that column configuration to be
     * available to other users in the system. So <b>Administrator privileged user</b> can
     * publish the column configuration so it will be available to all other users in the
     * system. The user which originally saved the column configuration will see two preferences
     * with same name, one with protection scope user and other one with site protection
     * scope.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can publish the column configuration that is <b>Mark as Publishable</b> by the
     * user so that it will be visible to all other users and others users can apply the
     * publish column configuration on BOM structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A list of <code>PublishColumnConfigInfo</code> structures which hold the required
     *        information to publish the column configuration.
     *
     * @return
     *         ServiceData object is returned. The updated <b>Fnd0ColumnConfiguration</b> object
     *         is returned in the updated object list of ServiceData. Any failure will be returned
     *         with client id mapped to error message in the ServiceData list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData publishColumnConfiguration ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2011_06::Requirementsmanagement::PublishColumnConfigInfo >& input ) = 0;

    /**
     * This operation creates a BOMLine for a newly created  Item and adds it to the selected
     * parent BOMLine and checks out the latest revision of newly created Item based on
     * a check-out preference. The inputs structure for this operation contains selected
     * parent BOMLine and newly created Item (e.g. Functionality or Logical Block).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        This argument contains parent BOMLine and newly created business object of the Item.
     *        The newly created Item is used to create the BOMLine and to get the latest ItemRevision
     *        for the checkout. The parent BOMLine in the input list is used to attach the newly
     *        created BOMLine.
     *
     * @return
     *         A GetBOMLineResponse with ServiceData element containing the newly created BOMLine.
     *         The following partial error may be returned: 515024  Specified object tag is not
     *         a valid.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getBomlineAfterCreate ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2012_09::Requirementsmanagement::GetBOMLineInfo >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RequirementsmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

