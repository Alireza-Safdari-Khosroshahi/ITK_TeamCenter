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

#ifndef TEAMCENTER_SERVICES_CLASSIFICATION_CLASSIFICATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_CLASSIFICATION_CLASSIFICATIONSERVICE_HXX

#include <teamcenter/services/classification/_2007_01/Classification.hxx>
#include <teamcenter/services/classification/_2009_10/Classification.hxx>
#include <teamcenter/services/classification/_2011_06/Classification.hxx>
#include <teamcenter/services/classification/_2011_12/Classification.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/classification/Classification_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Classification
        {
            class ClassificationService;

/**
 * The <code><b>Classification</b></code> service helps achieve different classification
 * operations and utilizes a classification hierarchy to categorize your company's product
 * data. The service allows users to create classification objects and associate them
 * to workspace objects in order to classify the workspace objects. <code><b>Classification</b></code>
 * service can also be used to perform add, update, or delete operations on the classification
 * hierarchy and retrieve information about the hierarchy.
 * <br>
 * The <code><b>Classification</b></code> service contains operations to achieve the
 * following:
 * <br>
 * <ul>
 * <li type="disc">Create classification objects and optionally attach them to workspace
 * objects
 * </li>
 * <li type="disc">Update existing classification objects
 * </li>
 * <li type="disc">Delete existing classification objects
 * </li>
 * <li type="disc">Get information on classification objects
 * </li>
 * <li type="disc">Search for classification objects and classified objects
 * </li>
 * <li type="disc">Get information on classification class hierarchies
 * </li>
 * <li type="disc">Get children information for a classification class in a hierarchy
 * </li>
 * <li type="disc">Get parent's information for a classification class in a hierarchy
 * </li>
 * <li type="disc">Delete classification class hierarchy
 * </li>
 * <li type="disc">Get detailed information for a classification class
 * </li>
 * <li type="disc">Get information on classification class attributes
 * </li>
 * <li type="disc">Search for classification classes
 * </li>
 * <li type="disc">Create or update classification key-LOV objects
 * </li>
 * <li type="disc">Get information on classification key-LOV objects
 * </li>
 * <li type="disc">Get part family templates information associated with a class
 * </li>
 * </ul>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * DataManagement
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaclassificationstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaclassificationtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACLASSIFICATIONSTRONGMNGD_API ClassificationService
    : public Teamcenter::Services::Classification::_2007_01::Classification,
             public Teamcenter::Services::Classification::_2009_10::Classification,
             public Teamcenter::Services::Classification::_2011_06::Classification,
             public Teamcenter::Services::Classification::_2011_12::Classification
{
public:
    static ClassificationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Creates one or more classification objects and (optionally) attach them to a workspace
     * object, thus classifying it. When the Classification objects are not associated with
     * any workspace object, they would act as standalone Classification objects. A classification
     * object is also called ICO
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to classify a workspace object or create a standalone classification object
     * (ICO) in Teamcenter. This operation can be combined with other operations like createItems()
     * to create workspace object and then associate the workspace object to the classification
     * object. Before creating a classification object, a classification class hierarchy
     * should already be created by the classification admin user in Teamcenter. This hierarchy
     * should include a storage class (a class that allows instances to be created and associated
     * to it) for which the classification objects need to be created. Values of any attributes
     * associated with classification objects can also be populated.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjs
     *        List of structure containing information about the classification object(ICO) that
     *        needs to be created including its attribute values. It also includes the classification
     *        class information for which classification object will be created & information on
     *        workspace object being classified.
     *
     * @return
     *         Returns a <code><b>CreateClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Created Classification objects in the ServiceData list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the ServiceData list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>CreateClassificationObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::CreateClassificationObjectsResponse createClassificationObjects ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationObject >& clsObjs ) = 0;

    /**
     * Deletes one or more classification objects permanently. A classification object is
     * also called ICO. The classified workspace object associated with the ICO will not
     * be deleted
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to delete classification objects. It is typically called when after creating
     * or searching the classification objects, user decides that the returned objects are
     * not needed anymore
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjTags
     *        Unique Business Object(s) representing the classification object(s) to be deleted.
     *
     * @return
     *         Returns a <code><b>DeleteClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Deleted classified WorkspaceObjects in the ServiceData list of plain
     *         objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the ServiceData list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code>ServiceData</code> list of partial
     *           errors in the returned <code><b>DeletedClassificationObjectsResponse</b></code> structure.
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteClassificationObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& clsObjTags ) = 0;

    /**
     * Finds the classification objects associated with input workspace objects (WSO). A
     * classification object is also called ICO. Each workspace object can have one or more
     * ICOs associated with it.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need to find classification objects (ICO) based on workspace objects. Each
     * time a workspace object is classified in a classification class a classification
     * object (ICO) object is created.  After searching for all the classification objects
     * corresponding to a workspace object, user can find more information about the classification(s)
     * of a workspace object. The operation <code><b>getClassificationObjects()</b></code><code>
     * </code>can be used to get detailed information about the classification objects.
     * After getting information on classification objects, user can also choose to modify
     * or delete those using operation <code><b>updateClassificationObjects()</b></code>
     * or <code><b>deleteClassificationObjects()</b></code>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param wsoIds
     *        List of identifiers for classified workspace objects(WSO), for which the associated
     *        classification objects(ICO) are required.
     *
     * @return
     *         Returns a <code><b>CreateClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Created Classification objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>CreateClassificationObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::FindClassificationObjectsResponse findClassificationObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  >& wsoIds ) = 0;

    /**
     * Finds the workspace objects (WSO) associated with input Teamcenter classification
     * objects. A classification object is also called ICO. Each ICO can have only one workspace
     * object associated with it.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need to find workspace objects based on classification objects (ICO) that
     * were created when workspace objects were classified.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param icoTags
     *        List of classification object (ICO) Business Objects, whose corresponding   workspace
     *        objects need to be found
     *
     * @return
     *         Returns a <code><b>FindClassifiedObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classified <code><b>WorkspaceObjects</b></code> in the
     *         <code><b>ServiceData</b></code> list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>FindClassifiedObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::FindClassifiedObjectsResponse findClassifiedObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& icoTags ) = 0;

    /**
     * Provides information on class attributes for the classification classes based on
     * input classification class ids. Detailed information about class attributes is provided
     * & includes class attribute name, description, format, unit system, minimum/maximum
     * value & configuration set
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user wants to view details of all class attributes associated with a classification
     * class. This operation is similar to getAttributesForClasses2(), but provides information
     * in a slightly different format. Typically, the information about class attributes
     * is used to determine which classification class a workspace object shall be classified
     * into
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param classIds
     *        Identifier for the classification class whose attribute information is requested.
     *
     * @return
     *         Returns a <code><b>GetAttributesForClassesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Map of input Class IDs and the list of references of Class attribute
     *         retrieved for each of the input Class IDs in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of the returned
     *           <code><b>GetAttributesForClassesResponse</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetAttributesForClassesResponse getAttributesForClasses ( const std::vector< std::string >& classIds ) = 0;

    /**
     * Gets the information about immediate children in classification hierarchy for given
     * group or class identifier(s).
     * <br>
     * Returns a <code><b>GetChildrenResponse</b></code> structure containing:
     * <br>
     * <ul>
     * <li type="disc">Retrieved child classes in the <code><b>ServiceData</b></code> list
     * of plain objects
     * </li>
     * <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     * list of partial errors.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to get details of all groups or classes that lie under a particular group
     * or class in a classification class hierarchy.
     * <br>
     * <br>
     * Returns a <code><b>GetChildrenResponse</b></code> structure containing:
     * <br>
     * <ul>
     * <li type="disc">Retrieved child classes in the <code><b>ServiceData</b></code> list
     * of plain objects
     * </li>
     * <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     * list of partial errors.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param groupOrClassIds
     *        Unique ID(s) of the classification class or group whose immediate children need to
     *        be determined in the classification class hierarchy
     *
     * @return
     *         <br>
     *         Returns a <code><b>GetChildrenResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved child classes in the <code><b>ServiceData</b></code> list
     *         of plain objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of the returned
     *           <code><b>GetChildrenResponse</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetChildrenResponse getChildren ( const std::vector< std::string >& groupOrClassIds ) = 0;

    /**
     * Gets detailed information about a classification class based on classification class
     * ID. This information includes class type, parent, name, description, unit system
     * and user data associated with the class.  It also includes a count of children, number
     * of classification views & number of instances of classification objects associated
     * with the classification class. Information can also be obtained on any documents
     * such as images & icons attached to the classification class.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need details of classification classes. These details can help user decide
     * whether to classify a workspace object in particular classification classes.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param classIds
     *        List of unique identifiers for classification classes whose details are needed.
     *
     * @return
     *         Returns a <code><b>GetClassDescriptionsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Class objects in the <code><b>ServiceData</b></code> list of plain
     *         objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetClassDescriptionsResponse getClassDescriptions ( const std::vector< std::string >& classIds ) = 0;

    /**
     * Looks for specified classification objects. If they are found, then detailed information
     * about those objects is provided. A classification object is also called ICO
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user need to find an existing classification object to either view or update
     * its details. It can be followed by operations like <code><b>updateClassificationObjects()</b></code>
     * or <code><b>deleteClassificationObjects()</b></code> to update or delete the classification
     * objects.
     * <br>
     * The operation <code><b>findClassificationObjects()</b></code> can be used to get
     * the list of classification objects, associated with workspace objects. Then, this
     * operation <code><b>getClassificationObjects()</b></code> is used to get the detailed
     * information on the classification objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjTags
     *        The classification object(s) for which detailed information is required.
     *
     * @return
     *         Returns a <code><b>GetClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Map of Classificaiton Object tag to its details.
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Classification
     *           object ID mapped to the error message in the <code><b>ServiceData</b></code> list
     *           of partial errors in the returned <code><b>GetClassificationObjectsResponse</b></code>
     *           structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetClassificationObjectsResponse getClassificationObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& clsObjTags ) = 0;

    /**
     * Gets the file information from any dataset that is associated with workspace object(s).
     * The dataset type can be specified along with the relation used when it is attached
     * to a workspace object. Information corresponding to a particular file inside a dataset
     * can be retrieved.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to get information about files inside a dataset that is associated with
     * workspace objects (WSO). Typically it will be used to get and view the  image or
     * icon files associated with datasets attached to workspace objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param criteria
     *        List of structures containing information on the workspace objects (WSO) to which
     *        the datasets are attached, the type of datasets, relation in which dataset is attached
     *        to the WSO, and the named reference inside the dataset. All this information can
     *        be used to get to a particular file inside a dataset
     *
     * @return
     *         Returns a <code><b>GetFileIDsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved Key-LOV objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetFileIdsResponse getFileIds ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::GetFileIdCriteria >& criteria ) = 0;

    /**
     * Gets the information for classification key-LOVs  based on given ID(s). Information
     * such as key-LOV's name, display options, and key and value entries can be obtained.
     * A key-LOV is a list of values used in classification. The key-LOVs are used to define
     * one or more values that can be set for classification dictionary attributes
     * <br>
     * <br>
     * Typical format of a key-LOV -
     * <br>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;key-LOV ID&gt;:&lt;key-LOV Name&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key10&gt;:&lt;Value10&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key20&gt;:&lt;Value20&gt;
     * <br>
     * <br>
     * Example of a key-LOV
     * <br>
     * <br>
     * - 33381:Design Categories
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des1:Bearing
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des2:Bracket
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des3:Frame
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des4:LeadBox
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to retrieve the information for an existing key-LOV using the key-LOV's
     * unique identifier. The operation is similar to <code><b>getKeyLOVs2</b></code>().
     * But <code><b>getKeyLOVs2</b></code>()provides more detailed information about any
     * key-LOVs .
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param keyLOVIds
     *        List of IDs of classification key-LOV, for which information is required. The key-LOV
     *        ID is a unique negative integer that identifies a key-LOV. In the Teamcenter rich
     *        client, key-LOVs can be accessed in the "Key LOVs" tab of the Classification Administration
     *        application. The key-LOV ID can be found in the "Key/ID" field of a key-LOV definition
     *        there.
     *
     * @return
     *         Returns a <code><b>GetKeyLOVsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved KeyLOV objects in the <code><b>ServiceData</b></code> list
     *         of plain objects
     *         </li>
     *         <li type="disc">Any failures with the KeyLOV ID are mapped to the error message in
     *         the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception. In all other cases failures will be returned with the Key-LOV
     *           ID mapped to the error message in the <code><b>ServiceData</b></code> list of partial
     *           errors of the <code><b>GetKeyLOVsResponse</b></code> return structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetKeyLOVsResponse getKeyLOVs ( const std::vector< std::string >& keyLOVIds ) = 0;

    /**
     * Gets the classification class ID(s) of all parent classes in a hierarchy, based on
     * given classification class ID. The parent class IDs are sorted as immediate parent
     * first, toplevel parent last.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to determine all the parent classes for any given class in a classification
     * hierarchy.  If user needs to get the children of the given class ID, then <code><b>getChildren</b></code>()
     * operation shall be used.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param childIds
     *        The unique identifier IDs for classification classes for which parent class ID information
     *        is being requested
     *
     * @return
     *         Returns a <code><b>GetParentsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved list of parent IDs in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of <code><b>GetParentsResponse</b></code>
     *           return structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetParentsResponse getParents ( const std::vector< std::string >& childIds ) = 0;

    /**
     * Finds the information for part family templates (PFT) based on the classification
     * class IDs. Part family templates can be used to define geometry and certain properties
     * of the geometry as variable properties. They can be attached to a classification
     * class. For any classification class, user can find out the associated part family
     * templates and their information.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * While using graphics builder, users often require information about the part family
     * template attached to the classification classes.  Graphics builder is a program used
     * by classification administration that communicates with the Teamcenter server to
     * generate graphics. The graphics builder uses NX libraries.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsClassIds
     *        List of IDs of classification classes for which the associated part family template
     *        information is required.
     *
     * @return
     *         Returns a <code><b>GetPartFamilyTemplatesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Returns the Part family templates assigned to classification class
     *         references in the <code><b>ServiceData</b></code> list of plain objects
     *         </li>
     *         <li type="disc">Any failures with class references mapped to the error message in
     *         the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::GetPartFamilyTemplatesResponse getPartFamilyTemplates ( const std::vector< std::string >& clsClassIds ) = 0;

    /**
     * Finds all the classification objects based on classification class IDs, classification
     * attribute ID and an expression for classification attribute value. A classification
     * object is also called an ICO.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to search for classification objects based on the class where they are
     * classified and the value of classification attributes.Another related operation for
     * searching classification objects is <code><b>searchByInstanceID</b></code>(), that
     * can search for classification objects based on their IDs
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param searchCriteria
     *        List of structures containing classification class ID, classification attribute ID,
     *        and an expression for classification attribute value (e.g. >= 20.00 ).
     *
     * @return
     *         Returns a <code><b>SearchResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classification objects (ICO) in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation throws a <code><b>ServiceException</b></code> in case of an error
     *           condition. Clients should  then retrieve the errors from the <code><b>ServiceData</b></code>
     *           list of partial errors in the returned <code><b>SearchResponse</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::SearchResponse search ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::SearchClassAttributes >& searchCriteria ) = 0;

    /**
     * Finds all the classification objects based on their IDs. A classification object
     * is also called an ICO. If the ICO classifies a workspace object, then ICO ID would
     * be same as the workspace object ID
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to search for classification objects based on their IDs. The returned
     * objects can then be used as input for operations like <code><b>findClassifiedObjects</b></code>(),
     * which is used to search workspace objects associated with the ICOs.
     * <br>
     * Another related operation for searching classification objects is <code><b>search</b></code>(),
     * that can search for classification objects based on class ID and attribute values
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param instanceIdQueries
     *        List of IDs of classification objects. These can contain wildcards ( e.g. ICO00*
     *        ).
     *
     * @return
     *         Returns a <code><b>SearchByInstanceIdResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classification objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::SearchByInstanceIdResponse searchByInstanceId ( const std::vector< std::string >& instanceIdQueries ) = 0;

    /**
     * Finds the classification classes based on provided search criteria and provides detailed
     * information about those classes.  The user can search using a search expression on
     * attributes of the class (Class ID, Name, Type etc.)  . For example, the user shall
     * be able to search all the classes whose name begins with a particular set of characters
     * and where the class ID matches certain pattern. The order of search results can also
     * be sorted on various criteria.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user needs to search for classification classes using a search criterion based
     * on various attributes of a class. The search criterion can be based on one or more
     * attributes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param criteria
     *        List of structure containing search expression, search attributes, and sort options
     *        for search results
     *
     * @return
     *         Returns a <code><b>SearchForClassesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classes in the <code><b>ServiceData</b></code> list of
     *         plain objects
     *         </li>
     *         <li type="disc">Any failures with class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::SearchForClassesResponse searchForClasses ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::SearchForClassesCriteria >& criteria ) = 0;

    /**
     * Updates existing classification objects. A classification object is also called ICO.
     * Values of various ICO attributes can be modified
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to update values of the attributes for an existing classification object
     * in Teamcenter. E.g. user wants to modify an integer value of a class attribute ("Length")
     * for an existing ICO. This operation is typically used after creating the classification
     * objects using <code><b>createClassificationObjects</b></code>().
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param clsObjs
     *        List of structures containing information about classification objects that needs
     *        to be modified,  along with the information that needs to be updated
     *
     * @return
     *         Returns a <code><b>UpdateClassificationObjectsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Updated Classification objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2007_01::Classification::UpdateClassificationObjectsResponse updateClassificationObjects ( const std::vector< Teamcenter::Services::Classification::_2007_01::Classification::ClassificationObject >& clsObjs ) = 0;

    /**
     * Computes the attribute values  of classification object based on other attribute
     * values within the same object or an associated classification view. Or the value
     * can be computed based on attribute values of the object being classified. A classification
     * object is also called ICO.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User need to automatically compute classification attribute values for attributes
     * marked as 'AutoComputed'. The values can be computed based on - other attribute values
     * belonging to same classification object or an associated classification view or attribute
     * values of the object being classified.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param icoId
     *        Unique ID of classification objects (ICOs) whose attributes are being computed.
     *
     * @param wso
     *        The workspace object  that is being classified. This input is optional and a NULL
     *        value can be specified. A NULL value indicates that there is no workspace object
     *        associated with classification object corresponding to input icoId
     *
     * @param classId
     *        Unique Id of classification class, in which classification object(ICO) is created/workspace
     *        object is classified.
     *
     * @param viewId
     *        Unique ID of a classification view that is associated to a classification class,
     *        under which input ICO is created/input workspace object is classified.
     *
     * @param inputAttrs
     *        Input attributes map with values and properties along with a flag indicating whether
     *        the attribute value has changed.
     *
     * @param unitSystem
     *        Unit system used to store ICO Properties. This parameter can contain the following
     *        integer values:
     *        <br>
     *        <ul>
     *        <li type="disc">0 = Metric
     *        </li>
     *        <li type="disc">1 = Nonmetric
     *        </li>
     *        </ul>
     *
     * @param mode
     *        The auto compute operation mode. This parameter can contain one of the following
     *        integer values:
     *        <br>
     *        <ul>
     *        <li type="disc">0 - Load mode
     *        </li>
     *        <li type="disc">1 - Create mode
     *        </li>
     *        <li type="disc">2 - Edit mode
     *        </li>
     *        </ul>
     *        <br>
     *        If the mode is specified as load mode, then attribute properties (mandatory, read-only,
     *        unique, propogated or hidden) are computed. Else both the attribute properties &
     *        values are computed
     *
     * @return
     *         Returns an <code><b>AutoComputeAttributesResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Auto-computed attributes map in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2009_10::Classification::AutoComputeAttributesResponse autoComputeAttributes ( const std::string&  icoId,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  wso,
        const std::string&  classId,
        const std::string&  viewId,
        const AutoComputeAttributesMap&  inputAttrs,
        int unitSystem,
        int mode ) = 0;

    /**
     * The operation creates or updates  the key-LOV objects based on the input such as
     * name, id etc., if the input ID matches that of an existing key-LOV, it will be updated.
     * Else new key-LOV object will be created. A key-LOV is a list of values used in classification.
     * The key-LOVs are used to define one or more values that can be set for classification
     * dictionary attributes
     * <br>
     * <br>
     * Typical format of a Key-LOV<b>
     * <br>
     * </b>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;key-LOV ID&gt;:&lt;key-LOV Name&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key10&gt;:&lt;Value10&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key20&gt;:&lt;Value20&gt;
     * <br>
     * <br>
     * Example of a Key-LOV:<b>
     * <br>
     * </b>
     * <br>
     * -33381 : Design Categories
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des1 : Bearing
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des2 : Bracket
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des3 : Frame
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des4 : LeadBox
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to create new key-LOVs to be used with classification or need to update
     * the existing ones in classification.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param keyLOVsInput
     *        List of structure that contains information of the key-LOV that needs to be updated
     *        or created.
     *
     * @return
     *         Any failures with KeyLOV ID mapped to the error message are returned in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *
     *
     * @exception ServiceException
     *           Throws <code><b>ServiceException</b></code> (SOA Framework class that holds model
     *           objects and partial errors) when classification system fails to create or update
     *           Key-LOV values for the given Key-LOV ID
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateKeyLOVs ( const std::vector< Teamcenter::Services::Classification::_2009_10::Classification::KeyLOVDefinition2 >& keyLOVsInput ) = 0;

    /**
     * Provides information on class attributes for the classification classes based on
     * input classification class ids. Detailed information about class attributes is provided
     * & includes class attribute name, description, format, unit system, minimum/maximum
     * value, configuration set & extended properties.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user wants to view details of all class attributes associated with a classification
     * class. The method is similar to<b> </b><code><b>getAttributesForClasses()</b></code>
     * method, but provides information in a slightly different format. Also additional
     * information like that on the extended properties of class attributes is provided
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param classIds
     *        Identifier for the classification class whose attribute information is requested.
     *
     * @return
     *         Returns a <code><b>GetAttributesForClassesResponse2</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Map of input Class IDs and the list of references of Class attributes
     *         retrieved for each of the input Class IDs. This map is added to the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Class ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.
     *           <br>
     *           In all other cases failures will be returned with the Class ID mapped to the error
     *           message in the <code><b>ServiceData</b></code> list of partial errors of the returned
     *           <code><b>GetAttributesForClassesResponse2</b></code> structure.
     */
    virtual Teamcenter::Services::Classification::_2009_10::Classification::GetAttributesForClassesResponse2 getAttributesForClasses2 ( const std::vector< std::string >& classIds ) = 0;

    /**
     * Gets the information for classification key-LOVs  based on given ID(s). Information
     * such as key-LOV's name, display options, owning site, shared sites, deprecation status
     * and key and value entries can be obtained. A key-LOV is a list of values used in
     * classification. The key-LOVs are used to define one or more values that can be set
     * for classification dictionary attributes
     * <br>
     * <br>
     * Typical format of a Key-LOV -
     * <br>
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;key-LOV ID&gt;:&lt;key-LOV Name&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key10&gt;:&lt;Value10&gt;
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&lt;Key20&gt;:&lt;Value20&gt;
     * <br>
     * 
     * <br>
     * Example of a KeyLOV:
     * <br>
     * <br>
     * - 33381:Design Categories
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des1:Bearing
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des2:Bracket
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des3:Frame
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;Des4:LeadBox
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to retrieve the information for an existing key-LOV using the key-LOV's
     * unique identifier. This operation is similar to <code><b>getKeyLOVs</b></code><code>()</code>operation,
     * but provides more detailed information about the required key-LOV.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param keyLOVIds
     *        List of IDs of classification key-LOV, for which information is required. The key-LOV
     *        ID is a unique negative integer that identifies a key-LOV. In the Teamcenter rich
     *        client, key-LOVs can be accessed in the "Key LOVs" tab of the Classification Administration
     *        application. The key-LOV ID can be found in the "Key/ID" field of a key-LOV definition
     *        there.
     *
     * @return
     *         Returns a <code><b>GetKeyLOVsResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved Key-LOV objects in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> for an unknown
     *           type of exception.In all other cases failures will be returned with the Key-LOV ID
     *           mapped to the error message in the <code><b>ServiceData</b></code> list of partial
     *           errors of <code><b>GetKeyLOVsResponse</b></code> return structure.
     */
    virtual Teamcenter::Services::Classification::_2009_10::Classification::GetKeyLOVsResponse2 getKeyLOVs2 ( const std::vector< std::string >& keyLOVIds ) = 0;

    /**
     * Deletes classification class hierarchy based on the classification class identifier.
     * All the child classes can be recursively deleted along with any classification views
     * associated with those classification classes. If needed, the classification objects
     * associated with classification classes & any workspace objects associated with the
     * classification objects can also be deleted
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to delete a classification class hierarchy, or a part of it. User may
     * also need to delete the associated data for these classes such as classification
     * views, classification objects or workspace objects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param optionsInput
     *        List of structure <code><b>HierarchyInfoAndOptions</b></code> that specifies the
     *        identifiers for classification classes whose class hierarchy needs to be deleted.
     *        It also includes information on the objects that needs to be deleted along with the
     *        classes & also the options for deleting children
     *
     * @return
     *         Any failures with Class ID mapped to the error message are returned in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteChildrenInHierarchy ( const std::vector< Teamcenter::Services::Classification::_2011_06::Classification::HierarchyInfoAndOptions >& optionsInput ) = 0;

    /**
     * Gets the classification class details such as class ID, parent information, child
     * count etc. for the specified library values criteria
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The operation is called when the user queries to get class hierarchy information
     * using the given library values.  The operation is typically used for data dictionary
     * related functionality in classification area, and the library components are created
     * using this feature in Teamcenter. Data dictionary is a central organizational repository
     * for reusable components.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param libraryValues
     *        The library value is passed as an input to the operation and is used as a search
     *        criteria to get library hierarchy information
     *
     * @return
     *         Returns a <code><b>GetLibraryHierarchyResponse</b></code> structure containing -
     *         <br>
     *         <ul>
     *         <li type="disc">The vector <code><b>classDefn</b></code> which includes the class
     *         information in the hierarchy .
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2011_06::Classification::GetLibraryHierarchyResponse getLibraryHierarchy ( const std::vector< std::string >& libraryValues ) = 0;

    /**
     * Provides detailed information on classification objects based on their unique identifiers
     * (UID). A classification object is also called an ICO
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * When user needs to get details of a classification object (ICO).  These details include
     * the classification class to which ICO belongs, the unit system, ICO ID, various ICO
     * attributes and their values and property descriptor for these attributes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param icoUids
     *        Unique IDs of classification objects whose details are required
     *
     * @param attributeIds
     *        Unique Identifiers of classification attribute associated with input classification
     *        object,  whose values are to be fetched
     *
     * @param getOptimizedValues
     *        Boolean flag to get optimized classification attribute values. When Teamcenter optimizes
     *        an attribute value, it provides the most readable value with the least number of
     *        leading or trailing zeros. For example, 1 km is easier to read than 1000 m
     *
     * @param fetchDescriptor
     *        Boolean flag to indicate whether  property descriptor for each of class attributes
     *        is to be fetched
     *
     * @param locale
     *        Locale in which classification objects attribute  values and properties descriptor
     *        are to be fetched.
     *
     * @return
     *         Returns a <code><b>ClassificationInfoResponse</b></code> structure containing:
     *         <br>
     *         <ul>
     *         <li type="disc">Retrieved classification objects and class attributes in the <code><b>ServiceData</b></code>
     *         list of plain objects
     *         </li>
     *         <li type="disc">Any failures with classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2011_12::Classification::ClassificationInfoResponse getClassificationObjectInfo ( const std::vector< std::string >& icoUids,
        const std::vector< int >& attributeIds,
        bool getOptimizedValues,
        bool fetchDescriptor,
        const std::string&  locale ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ClassificationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/classification/Classification_undef.h>
#endif

