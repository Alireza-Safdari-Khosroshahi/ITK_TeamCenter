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

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2007_01_REQUIREMENTSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2007_01_REQUIREMENTSMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Requirementsmanagement
        {
            namespace _2007_01
            {
                class Requirementsmanagement;

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API Requirementsmanagement
{
public:

    struct AttributeInfo;
    struct AttributeInfoCAD;
    struct CommitDatasetFileInfoCAD;
    struct CreateOrUpdateOutput;
    struct CreateOrUpdateResponse;
    struct DatasetFileInfoCAD;
    struct DatasetFileTicketInfoCAD;
    struct DatasetInfo;
    struct DatasetOutput;
    struct ExportToApplicationInputData;
    struct ExportToApplicationResponse;
    struct ExtraObjectInfo;
    struct ExtraObjectOutput;
    struct ExtraObjectOutputCAD;
    struct GetContentInput;
    struct GetRichContentResponse;
    struct ImportFromApplicationInputData;
    struct ImportFromApplicationResponse;
    struct ItemInfo;
    struct ItemRevInfo;
    struct NamedReferenceObjectInfo;
    struct PartInfo;
    struct SetContentInput;
    struct SetRichContentResponse;

    /**
     * This structure allows the caller to create or update named attributes. This structure
     * must contain the name of the attribute and the value of the attribute to set.
     */
    struct AttributeInfo
    {
        /**
         * The name of the attribute to set.
         */
        std::string name;
        /**
         * The value of the attribute to set.
         */
        std::string value;
    };

    /**
     * This structure allows the caller to create or update named attributes. This structure
     * must contain the name of the attribute and the value of the attribute to set.
     */
    struct AttributeInfoCAD
    {
        /**
         * The name of the attribute to set.
         */
        std::string name;
        /**
         * The value of the attribute to set.
         */
        std::string value;
    };

    /**
     * This structure has information to commit named reference files to input <b>Dataset</b>.
     * This structure contains the necessary  information like the file ticket and if a
     * new version of <b>Dataset</b> is to be created.
     */
    struct CommitDatasetFileInfoCAD
    {
        /**
         * A tag of the <b>Dataset</b> to be updated with the named reference file.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * The value of true means that a new <b>Dataset</b> to be created, value of false means
         * that the existing <b>Dataset</b> to be updated with the named reference file.
         */
        bool createNewVersion;
        /**
         * The information about the <b>Dataset</b> file tickets.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::DatasetFileTicketInfoCAD > datasetFileTicketInfos;
    };

    /**
     * This structure is defined to store information about the newly created <b>Dataset</b>
     * or updates to the existing <b>Dataset</b>. It contains all the information about
     * the related objects that user needs to pass during the creation or update of <b>Dataset</b>.
     */
    struct CreateOrUpdateOutput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The tag of the <b>Item</b> that is created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The tag of the <b>ItemRevision</b> that is created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * The tag of the <b>Dataset</b> that is created or updated.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::DatasetOutput > datasetOutput;
        /**
         * The structure containing information about the additional <b>Item</b> objects created.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectOutput > extraItemObjs;
        /**
         * The structure containing information about the additional <b>ItemRevision</b> objects
         * created.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectOutputCAD > extraItemRevObjs;
    };

    /**
     * This structure represents the output of createOrUpdate operation.  It has the information
     * about the newly created <b>Dataset</b> or update to existing <b>Dataset</b>.
     */
    struct CreateOrUpdateResponse
    {
        /**
         * The list of structures containing information about the <b>Item</b>,
         * <br>
         * <b>ItemRevision</b> or the <b>Dataset</b> to be created or updated.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::CreateOrUpdateOutput > output;
        /**
         * The serviceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure allows the user to create or update the dataset with the named attributes
     * information. This structure must contain either an "AttributesToSet" element or an
     * "AttributesToUnset" element, but not both.
     * <br>
     */
    struct DatasetFileInfoCAD
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The name of the named reference file to be updated.
         */
        std::string fileName;
        /**
         * The named references string for that object.
         */
        std::string namedReferencedName;
        /**
         * Flag to indicate if it is text data. Value of true indicates it is text data. Value
         * of false indicates binary data.
         */
        bool isText;
        /**
         * Flag to indicate whether to replace the data. Value of true indicates data to be
         * overwritten. Value of false indicates data will not be overwritten.
         */
        bool allowReplace;
    };

    /**
     * This structure has <b>Dataset</b> FMS file ticket information.
     */
    struct DatasetFileTicketInfoCAD
    {
        /**
         * The <b>Dataset</b> file ticket information.
         */
        Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::DatasetFileInfoCAD datasetFileInfo;
        /**
         * The name of the ticket.
         */
        std::string ticket;
    };

    /**
     * The DatasetInfo structure represents all of the data necessary to construct the <b>Dataset</b>
     * object. All the attributes required to be set on the <b>Dataset</b> are passed as
     * name/value pairs in the <code>AttributeInfo</code> structure. The extraObject field
     * allows for the creation of an object(s) that will be related to this newly created
     * <b>Dataset</b>.
     */
    struct DatasetInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The tag of <b>Dataset</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * The name of <b>Dataset</b>.
         */
        std::string name;
        /**
         * The description for <b>Dataset</b>.
         */
        std::string description;
        /**
         * The real type name of <b>Dataset</b>.
         */
        std::string type;
        /**
         * The id of <b>Dataset</b>.
         */
        std::string id;
        /**
         * The name of <b>Dataset</b> revision.
         */
        std::string datasetRev;
        /**
         * The relation name of the revision to <b>Dataset</b>.
         */
        std::string itemRevRelationName;
        /**
         * The flag to create new version. Value of true indicates new revision to be created,
         * value of false indicates no new revision to be created.
         */
        bool createNewVersion;
        /**
         * The attributes to be set on the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::AttributeInfo > attrList;
        /**
         * The mapping attributes to be set on the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::AttributeInfoCAD > mappingAttributes;
        /**
         * Additional objects to be created and related to the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectInfo > extraObject;
        /**
         * The information about files attached to the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::DatasetFileInfoCAD > datasetFileInfos;
        /**
         * The information about objects attached to the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::NamedReferenceObjectInfo > namedReferenceObjectInfos;
    };

    /**
     * This structure is defined to store information about the output <b>Dataset</b> objects.
     * It also contains information about the additional objects that are related to the
     * <b>Dataset</b>.
     */
    struct DatasetOutput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The tag of the <b>Dataset</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * The structure containing information to commit named reference files.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::CommitDatasetFileInfoCAD > commitInfo;
        /**
         * The structure containing information about the objects that are related to the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectOutput > extraObjs;
        /**
         * The structure containing information about the additional named reference objects
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectOutputCAD > namedRefObjs;
    };

    /**
     * The ExportToApplicationInputData structure represents all of the data necessary to
     * export selected objects to Word/Excel.
     */
    struct ExportToApplicationInputData
    {
        /**
         * The list of Teamcenter business objects to export.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objectsToExport;
        /**
         * The list of attributes to export.
         */
        std::vector< std::string > attributesToExport;
        /**
         * The application format such as <b>MSWordXML</b>, <b>MSExcel</b> and <b>MSExcelLive</b>.
         * <br>
         * Supported application formats for this operation
         * <br>
         * <ul>
         * <li type="disc"><b>MSWord</b>XML&nbsp;&nbsp;&nbsp;&nbsp;This format is used for exporting
         * Workspace objects to static MSWord application.
         * </li>
         * <li type="disc"><b>MSExcel</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for exporting
         * Teamcenter objects to static <b>MSExcel</b>  application.&nbsp;&nbsp;&nbsp;&nbsp;
         * </li>
         * <li type="disc"><b>MSExcelLive</b>&nbsp;&nbsp;&nbsp;&nbsp;This format is used for
         * exporting Teamcenter objects to Live <b>MSExcel</b>  application.
         * </li>
         * </ul>
         */
        std::string applicationFormat;
        /**
         * The name of the <b>MSWord</b>/<b>MSExcel</b> template
         */
        std::string templateId;
    };

    /**
     * ExportToApplicationResponse structure represents the output of export to application
     * operation. It contains the read ticket to the exported <b>MSWord</b>/<b>MSExcel</b>
     * file.
     */
    struct ExportToApplicationResponse
    {
        /**
         * The transient file read tickets for the exported file.
         */
        std::vector< std::string > transientFileReadTickets;
        /**
         * The serviceData.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>ExtraObjectInfo</code> structure represents additional object information
     * that may be required to complete an operation. Example - It may be required by the
     * client application to pass additional information about the relation (GRM) and properties
     * on the relation to the server. This structure can be used to store the information
     * about any relation objects.
     */
    struct ExtraObjectInfo
    {
        /**
         * The tag of the Teamcenter Business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The real type name of the relation.
         */
        std::string relationTypeName;
        /**
         * The real type name of the object.
         */
        std::string typeName;
        /**
         * The vector of attributes names and its values to be set on the object.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::AttributeInfo > attrNameValuePairs;
    };

    /**
     * This structure is defined to store information about the additional objects that
     * are updated during the createOrUpdate operation.
     */
    struct ExtraObjectOutput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The tag of the Business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };

    /**
     * This structure is defined to add additional objects as part of the response structure.
     */
    struct ExtraObjectOutputCAD
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The tag of the Business object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
    };

    /**
     * The parameters required to open requirement in word.
     */
    struct GetContentInput
    {
        /**
         * <b>Fulltext</b> object, whose content to be  viewed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  objectToProcess;
        /**
         * The viewing application format. Only <i>MSWordXML</i> is supported.
         */
        std::string applicationFormat;
        /**
         * This parameter is not used currently.
         */
        std::string templateId;
    };

    /**
     * This structure holds FMS ticket of <b>MSWord</b> file generated as part of getRichContent
     * operation.
     */
    struct GetRichContentResponse
    {
        /**
         * FMS ticket of word file that is generated as part of getRichContent operation.
         */
        std::vector< std::string > transientFileReadTickets;
        /**
         * The <code>ServiceData</code>.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The ImportFromApplicationInputData structure represents all of the data necessary
     * to import an MSWord document into Teamcenter.
     */
    struct ImportFromApplicationInputData
    {
        /**
         * The file ticket of the. docx file to be imported into Teamcenter.
         */
        std::string transientFileWriteTicket;
        /**
         * The supported application format is "MSWordXML"
         */
        std::string applicationFormat;
        /**
         * The subtype of SpecElement to be created.
         */
        std::string createSpecElementType;
    };

    /**
     * ImportFromApplicationResponse structure represents the output of import from application
     * operation. It contains the UID of the BOMWindow after the document is imported to
     * Teamcenter.
     */
    struct ImportFromApplicationResponse
    {
        /**
         * The resultant objects which contains the UID of the BOMWindow created after the document
         * is imported.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > resultObjects;
        /**
         * The Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The <code>ItemInfo</code> structure represents all of the data necessary to construct
     * the <b>Item</b> object. It contains the information about the attributes that are
     * set on the <b>Item</b> object. All attributes are passed as name/value pairs in the
     * <code>AttributeInfo</code> structure. The extraObject field contains information
     * about the objects that are related to the newly created <b>Item</b>.
     */
    struct ItemInfo
    {
        /**
         * The object tag of the object to be updated. If it is NULL then a new object will
         * be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The object Id (item_id) of the object to be updated. If it is NULL then a new ID
         * is created.
         */
        std::string itemId;
        /**
         * The object Type (object_type) of the object to be created or updated.
         */
        std::string itemType;
        /**
         * The Name (object_name) of the object.
         */
        std::string name;
        /**
         * The Description (object_desc) of the object.
         */
        std::string description;
        /**
         * The attributes to be set on the object. This is in the form of map that stores attribute
         * name and attribute value.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::AttributeInfo > attrList;
        /**
         * The structure containing information about the objects that are related to the <b>Item</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectInfo > extraObject;
        /**
         * The tag of the <b>Folder</b> under which newly created <b>Item</b> is to be pasted.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
    };

    /**
     * The <code>ItemRevInfo</code> structure represents all of the data necessary to construct
     * the <b>ItemRevision</b> object. It contains information about the attributes to be
     * set on the revision object. All attributes are passed as name/value pairs in the
     * <code>AttributeInfo</code> structure. The extraObject field allows for the creation
     * of an objects that will be related to this newly created <b>ItemRevision</b>.
     */
    struct ItemRevInfo
    {
        /**
         * A tag of the <b>ItemRevision</b> to be created or updated. It is NULL for newly created
         * <b>Item</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The Id of the <b>ItemRevision</b>. It is NULL for new <b>ItemRevision</b> object.
         */
        std::string revId;
        /**
         * The attribute name and attribute value to be set on the <b>ItemRevision</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::AttributeInfo > attrList;
        /**
         * The information about the objects that are related to the <b>ItemRevision</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ExtraObjectInfo > extraObject;
    };

    /**
     * The <code>NamedReferenceObjectInfo</code> structure represents all of the data necessary
     * to construct the named reference file attached to a <b>Dataset</b>.
     */
    struct NamedReferenceObjectInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify
         * <br>
         * return data element and partial errors associated with this input structure.
         * <br>
         */
        std::string clientId;
        /**
         * The reference to the named reference file for <b>Dataset</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The real type name of the relation between the revision and the <b>Dataset</b>.
         * <br>
         */
        std::string relationTypeName;
        /**
         * The real type name of the <b>Dataset</b>.
         */
        std::string typeName;
        /**
         * The attribute name-value pair to set on the <b>Dataset</b>.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::AttributeInfo > attrNameValuePairs;
        /**
         * The real <b>Dataset</b> type.
         */
        std::string namedReferenceName;
    };

    /**
     * The data required to create an <b>Item</b>, <b>ItemRevision</b> and one or more <b>Dataset</b>.
     * If the Item already exists then it also has the information required to be updated
     * for that Item.
     */
    struct PartInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return
         * <br>
         * data elements and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The information required to create or update an <b>Item</b>.
         */
        Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ItemInfo itemInput;
        /**
         * The information required to create or update an <b>ItemRevision</b>.
         */
        Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::ItemRevInfo itemRevInput;
        /**
         * The information required to create or update one or more <b>Dataset</b> objects.
         */
        std::vector< Teamcenter::Services::Requirementsmanagement::_2007_01::Requirementsmanagement::DatasetInfo > datasetInput;
    };

    /**
     * <code>SetContentInput</code> structure represents the parameters required to set
     * the contents to <b>Fulltext</b> object.
     */
    struct SetContentInput
    {
        /**
         * <b>Fulltext</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  objectToProcess;
        /**
         * FMS ticket of Word file.
         */
        std::string transientFileWriteTicket;
    };

    /**
     * <code>SetRichContentResponse</code> - structure represents response parameters of
     * setRichContent SOA.
     */
    struct SetRichContentResponse
    {
        /**
         * This parameter is not used.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > resultObjects;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Requirementsmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

