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

#ifndef TEAMCENTER_SERVICES_CAD_DATAMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CAD_DATAMANAGEMENTSERVICE_HXX

#include <teamcenter/services/cad/_2007_01/Datamanagement.hxx>
#include <teamcenter/services/cad/_2007_12/Datamanagement.hxx>
#include <teamcenter/services/cad/_2008_03/Datamanagement.hxx>
#include <teamcenter/services/cad/_2008_06/Datamanagement.hxx>
#include <teamcenter/services/cad/_2010_09/Datamanagement.hxx>
#include <teamcenter/services/cad/_2011_06/Datamanagement.hxx>
#include <teamcenter/services/cad/_2012_09/Datamanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            class DatamanagementService;

/**
 * The CAD DataManagement  service allows clients to create and expand Teamcenter data.
 * Specifically, there are operations to support creating the CAD part concept<b> (
 * Item</b>, <b>ItemRevision</b>, and <b>Dataset</b> ) createOrUpdate<b>Part</b>s and
 * createOrUpdateRelations. There are operations to expand data that CAD integrations
 * are interested in ( expandFoldersForCAD and expandPrimaryObjects ).  There are also
 * operations to work with the Teamcenter attribute mapping  functionality ( getAllAttrMappings,
 * getAttrMappingsForDatasetType, resolveAttrMappings ).
 * <br>
 * This service supports the following use cases for Teamcenter product structure:
 * <br>
 * <ul>
 * <li type="disc">Creation of CAD concept of Part ( <b>Item</b>/<b>ItemRevision</b>/<b>Dataset</b>
 * ) as well as accompanying data such as named references and ancillary forms
 * </li>
 * <li type="disc">Retrieving folder contents that CAD integrations are typically interested
 * in : <b>Item</b> objects, <b>ItemRevision</b> objects, and <b>Dataset</b> objects
 * </li>
 * <li type="disc">Retrieving attribute mappings for reading and writing CAD part mapped
 * attributes
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacadstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacadtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACADSTRONGMNGD_API DatamanagementService
    : public Teamcenter::Services::Cad::_2007_01::Datamanagement,
             public Teamcenter::Services::Cad::_2007_12::Datamanagement,
             public Teamcenter::Services::Cad::_2008_03::Datamanagement,
             public Teamcenter::Services::Cad::_2008_06::Datamanagement,
             public Teamcenter::Services::Cad::_2010_09::Datamanagement,
             public Teamcenter::Services::Cad::_2011_06::Datamanagement,
             public Teamcenter::Services::Cad::_2012_09::Datamanagement
{
public:
    static DatamanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * CreateOrUpdateParts allows the user to create or update a set of parts using Items,
     * Item Revisions, Datasets and ExtraObjects. If the user supplies a valid Item object
     * reference without specifying a valid item revision object reference or id, then only
     * the item will be updated. If the user specifies a valid item object reference with
     * a null item revision object reference and a non-null revision id, then a new item
     * revision will be created and attached to the item with no relations from the new
     * item revision to the previous item revision. If the user specifies a valid item object
     * reference and a valid item revision object reference, then the item and item revision
     * and related objects will be updated. If no item object reference or item revision
     * object references are specified then a new item and item revision and related objects
     * will be created. All objects created and updated will be returned in the ServiceData.
     * All partial errors will contain the clientIDs for all items related to the error
     * message, i.e. if a dataset encounters an error, then the ID for that erro will be
     * the item client ID concantentated with the item revision id contantenated with the
     * dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of PartInfo structures
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     * @deprecated
     *         As of tc2007, use the createOrUpdateParts operation from the _2007_12 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the createOrUpdateParts operation from the _2007_12 namespace."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::PartInfo >& info ) = 0;

    /**
     * <code>createOrUpdateRelations</code> creates or updates GRM relations between existing
     * objects in Teamcenter. If the <code>complete</code> flag is set and a filter is supplied,
     * then any relation types that exist for primary objects in the info that are listed
     * in the filter, but the relations are not sent in the input, those relations will
     * be deleted.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user wishes to relate two objects in Teamcenter. The user specifies the primary
     * and secondary objects, the type of relation to be created and any optional data the
     * user wants added to the relation.
     * <br>
     * The user wishes to modify the user data on the relationship between two objects.
     * The user specifies the primary and secondary objects and the existing relationship.
     * The user also specifies the new user data to be placed on the relationship.
     * <br>
     * The user wishes to relate two objects in Teamcenter and remove any existing relationships
     * between the objects. The user specifies the primary and secondary objects, the type
     * of relation to be created and any optional data the user wants added to the relation.
     * The user also sets the <code>complete</code> option to true to delete the existing
     * relationships that pass the supplied filter, but does not send those existing relationships
     * in the input.  For example, there is an item revision and a dataset related with
     * an IMAN_specification relationship in Teamcenter and the user wants to change this
     * to an IMAN_Rendering relationship. The user can specify the item revision and the
     * dataset, specify the new relationship is IMAN_Rendering and set the <code>complete</code>
     * flag. With the filter specifying the relation type of IMAN_specification and the
     * object type as dataset. This will delete the current relationship and create the
     * new one.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of <code>CreateOrUpdateRelationsInfo</code>
     *
     * @param complete
     *        A flag to check whether any existing relations that pass the filter needs to be deleted.
     *
     * @param pref
     *        A list of <code>RelationAndTypesFilter2</code> structure.
     *
     * @return
     *         Relations that were successfully created or updated are returned in the <code>CreateOrUpdateRelationsResponse</code>.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsResponse createOrUpdateRelations ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsInfo >& info,
        bool complete,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdateRelationsPref&  pref ) = 0;

    /**
     * The purpose of this service is to provide the contents of a folder that a CAD integration
     * typically needs in one service call as opposed to multiple expand calls. This service
     * is specifically for Folder expansion and will only return Items, Item Revisions and
     * Folders that are contained in the input Folder. Other types of objects (Forms, Datasets,
     * etc...) that are contained directly under the input folder will not be returned.
     * The service will also return the Item Revisions and Datasets for the Items found
     * in the folder and Datasets found for the Item Revisions found directly under the
     * folder. The Item Revisions returned, are controlled thru an input latestNRevs specifying
     * how many latest revisions should be sent to output. The Items, Item Revisions and
     * Datasets returned can be filtered thru an input preference of a list of relation
     * names and dataset types filter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param folders
     *        A list of input TcEng folders
     *
     * @param pref
     *        Filter and expand preferences
     *
     * @return
     *         contains a list of ExpandFoldersForCADOutput structures (which contain information
     *         about the input TcEng folder, and filtered folder contents viz. folders, items and
     *         itemRevs). Failures and error message are in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFoldersForCADResponse expandFoldersForCAD ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  >& folders,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandFolderForCADPref&  pref ) = 0;

    /**
     * Returns the secondary objects related to the input object for the given list of relation
     * names and other side object types filter. If no relation names or other side objects
     * types are provided in the input, then all related objects will be returned. In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned. Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned. However this additional expansion is controlled through the expItemRev
     * flag.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param objects
     *        A list of object references of objects of interest
     *
     * @param pref
     *        A ExpandGRMRelationsPref structure
     *
     * @return
     *         contains a list of ExpandGRMRelationsOutput structures (which contain information
     *         about the input TcEng Object, filtered Otherside related objects and the relationName
     *         they are related). Failures and error message are in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandGRMRelationsResponse expandGRMRelations ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandGRMRelationsPref&  pref ) = 0;

    /**
     * Returns the secondary objects related to the input object for the given list of relation
     * names and other side object types filter. If no relation names or other side objects
     * types are provided in the input, then all related objects will be returned. In addition,
     * for performance, if an Item is the output of the expansion, then its associated Item
     * Revisions and the Datasets for those Item Revisions will be returned. Similarly,
     * if an Item Revision is the output of the expansion, then its associated Datasets
     * will be returned. However this additional expansion is controlled through the expItemRev
     * flag.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param objects
     *        A list of input TcEng object references and filter and expand preferences
     *
     * @param pref
     *        A ExpandPrimaryObjectsPref structure
     *
     * @return
     *         contains a list of ExpandPrimaryObjectsOutput structures (which contain information
     *         about the input TcEng Object, filtered Otherside related objects and the relation/property
     *         Name they are related). Failures and error message are in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandPrimaryObjectsResponse expandPrimaryObjects ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        const Teamcenter::Services::Cad::_2007_01::Datamanagement::ExpandPrimaryObjectsPref&  pref ) = 0;

    /**
     * Generate a list of alternate ids. An alternate id is a displayable id for an <b>Item</b>
     * or <b>ItemRevision</b> that is controlled by the user via display rules. The client
     * creates <b>Identifiers</b> that contain the various alternate ids to be displayed.
     * Each <b>Identifier</b> is controlled by a display rule. When a display rule is active
     * then the appropriate alternate id is displayed.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The client defines several alternate ids for a part. One alternate id is for the
     * manufacturer of the part( this would be their part number ), another would be for
     * a customer ( their part number ) and maybe one for a second customer ( again, another
     * part number ). This service allows the client to invoke the user exit USER_new_alt_id.
     * This exit will be called once for each count specified in the input using the data
     * passed in as parameters.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getContextsAndIdentifierTypes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        A list of <code>GenerateAlternateIdsProperties</code>.
     *
     * @return
     *         Contains the map of index to list of ids generated. The index refers to the input
     *         data in the input list.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GenerateAlternateIdsResponse generateAlternateIds ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::GenerateAlternateIdsProperties >& input ) = 0;

    /**
     * Retrieves all CAD attribute mapping definitions. Additionally, if a CadAttributeMappingDefinition
     * object has a path that includes a GRM or NR part, the associated PropertyDescriptor
     * and any attached ListOfValues objects will be returned.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         contains only failure information
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if any Teamcenter subsystem errors occur during the
     *           retrieval of all attribute mappings, finding the dataset type or finding the attribute
     *           mapping type.
     * @deprecated
     *         As of Teamcenter 9, use the getAllAttrMappings2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 9, use the getAllAttrMappings2 operation."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAllAttrMappingsResponse getAllAttrMappings (  ) = 0;

    /**
     * This operation retrieves the CAD attribute mapping definitions for one or more dataset
     * type and item type combinations.  If a <code>CadAttributeMappingDefinition</code>
     * object has a path that includes a Generic Relationship Manager (GRM) or named reference
     * part, the associated property descriptor and any attached <code>ListOfValues</code>
     * (LOV) objects will be returned.
     * <br>
     * <br>
     * Since this operation returns existing Teamcenter attribute mappings, please reference
     * the Teamcenter help section on creating attribute mappings.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to have attribute mappings defined in Teamcenter.
     * <br>
     * <br>
     * For this operation, the dataset object type is passed as input. The client application
     * uses the list of returned attribute mapping definitions to present the CAD attributes
     * to the user that correspond to the correct Teamcenter attributes.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of dataset and item types used to get a specific set of attribute mapping
     *        definitions from the all of the attribute mapping definitions in Teamcenter.
     *
     * @return
     *         The requested CAD attribute mapping definitions for the specified dataset type.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215070:  Unknown dataset type name specified.
     *         </li>
     *         <li type="disc">215071:  Unknown item type name specified.
     *         </li>
     *         <li type="disc">215073:  The operation failed to get the list of attribute mapping
     *         definitions for the specifed types.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if any Teamcenter subsystem errors
     *           occur during the retrieval of all attribute mappings.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAttrMappingsForDatasetTypeResponse getAttrMappingsForDatasetType ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAttrMappingsForDatasetTypeCriteria >& info ) = 0;

    /**
     * Finds types implemented by the given input class name.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User selects File New Item and is presented with a list of creatable item types.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param classes
     *        A list of the classes to return subtypes for
     *
     * @return
     *         Contains the map of input class names and for each input class name, the object references
     *         of found types (NULL, if none found). Failure will be returned via <code>ServiceData</code>
     *         with original input class string mapped to error message.
     *
     * @deprecated
     *         As of tc2007, use the getAvailabelTypes operation from the Core DataManagement service.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007, use the getAvailabelTypes operation from the Core DataManagement service."))
#endif
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::GetAvailableTypesResponse getAvailableTypes ( const std::vector< std::string >& classes ) = 0;

    /**
     * Retrieves CAD attribute mapped properties for one or more datasets.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User does a FileOpen of Teamcenter Item or Dataset (CAD Part).  CAD properties mapped
     * to Teamcenter attribute values are shown in the Part attribute display.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        An array of <code>ResolveAttrMappingsForDatasetInfo</code> structures each containing
     *        a <b>Dataset</b> object reference, an optional item revision, and a list of corresponding
     *        CAD Attribute Mapping Definitions to be resolved for the dataset. The optional item
     *        revision is recommended for improved performance in cases where resolution of the
     *        mapping string would otherwise require a relation query to find the item revision.
     *
     * @return
     *         Contains the resolved objects and properties. In addition to errors that may be returned
     *         from the Teamcenter subsystem, the following errors originate from this operation:
     *         <br>
     *         215074 : The Dataset supplied is invalid..
     *         <br>
     *         215075 : The Item Revision supplied is invalid.
     *         <br>
     *         215076 : The CadAttrMappingDefinition is invalid.
     *         <br>
     *         215077 : Failed to get the Attribute Mapping Title.
     *         <br>
     *         215078 : Failed to get the Attribute Mapping Dataset Type.
     *         <br>
     *         215079 : Failed to get the Attribute Mapping Dataset Type name.
     *         <br>
     *         215080 : Failed to get the Attribute Mapping Item Type.
     *         <br>
     *         215081 : Failed to get the Attribute Mapping Item Type name.
     *         <br>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::ResolveAttrMappingsForDatasetResponse resolveAttrMappingsForDataset ( const std::vector< Teamcenter::Services::Cad::_2007_01::Datamanagement::ResolveAttrMappingsForDatasetInfo >& info ) = 0;

    /**
     * CreateOrUpdateParts allows the user to create or update a set of parts using Items,
     * Item Revisions, Datasets and ExtraObjects and also changes the ownership of the newly
     * created object to the user/group supplied. If the user supplies a valid Item object
     * reference without specifying a valid item revision object reference or id, then only
     * the item will be updated. If the user specifies a valid item object reference with
     * a null item revision object reference and a non-null revision id, then a new item
     * revision will be created and attached to the item with no relations from the new
     * item revision to the previous item revision. If the user specifies a valid item object
     * reference and a valid item revision object reference, then the item and item revision
     * and related objects will be updated. If no item object reference or item revision
     * object references are specified then a new item and item revision and related objects
     * will be created. All objects created and updated will be returned in the ServiceData.
     * All partial errors will contain the clientIDs for all items related to the error
     * message, i.e. if a dataset encounters an error, then the ID for that erro will be
     * the item client ID concantentated with the item revision id contantenated with the
     * dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of PartInfo2 structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual.
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2007_12::Datamanagement::PartInfo2 >& info,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;

    /**
     * CreateOrUpdateParts allows the user to create or update a set of parts using Items,
     * Item Revisions, Datasets and ExtraObjects and also changes the ownership of the newly
     * created object to the user/group supplied. If the user supplies a valid Item object
     * reference without specifying a valid item revision object reference or id, then only
     * the item will be updated. If the user specifies a valid item object reference with
     * a null item revision object reference and a non-null revision id, then a new item
     * revision will be created and attached to the item with no relations from the new
     * item revision to the previous item revision. If the user specifies a valid item object
     * reference and a valid item revision object reference, then the item and item revision
     * and related objects will be updated. If no item object reference or item revision
     * object references are specified then a new item and item revision and related objects
     * will be created. All objects created and updated will be returned in the ServiceData.
     * All partial errors will contain the clientIDs for all items related to the error
     * message, i.e. if a dataset encounters an error, then the ID for that erro will be
     * the item client ID concantentated with the item revision id contantenated with the
     * dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        A list of PartInfo3 structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual.
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_01::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2008_03::Datamanagement::PartInfo3 >& info,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;

    /**
     * Retrieves CAD attribute mapped properties for item revisions or datasets.  Attribute
     * Mapping is a scheme whereby Teamcenter attributes can be retrieved or set via a defined
     * path to the attribute from the starting object, usually a dataset.  For example,
     * a mapped attribute can be defined in the client integration with a particular name
     * ATTR1.  Using Teamcenter attribute mapping, the customizer can define a path named
     * ATTR1 from a starting point item revision type or dataset type to the actual attribute
     * that holds the value for ATTR1. The client integration then can access the attribute
     * using the attribute mapping title ATTR1 and the starting point object.
     * <br>
     * For more information about Attribute Mapping including examples with syntax, please
     * consult the "Configuring attribute mapping section" of the Application Administration
     * Guide in Teamcenter Online Help.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user performs a File Open operation on an existing Teamcenter dataset.  The client
     * integration has defined an attribute mapping in Teamcenter for that Dataset type.
     * The resolveAttrMappings call performed as a part of the File Open, sends the mapping
     * definition, defined by the mapping title, and the Dataset as input.  The operation
     * traverses from the input Dataset to the mapped property which in this case resides
     * on the Datasets parent Item Revision.  The operation will return the item revision
     * and the mapped property name such that the client integration can retrieve the property
     * value from the item revision.  The value is then displayed in the attribute data
     * for the dataset in the client integration.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        An array of ResolveAttrMappingsInfo structures each containing a <b>Dataset</b> object
     *        reference, an optional item revision, and a list of corresponding CAD Attribute Mapping
     *        Definitions to be resolved for the dataset.
     *
     * @return
     *         contains the resolved objects, properties, and failure information This service can
     *         return errors from utilities and also defines its own errors. The errors this service
     *         can return are:
     *         <br>
     *         215119 No Dataset or Item Revision specified
     *         <br>
     *         215074 Invalid Dataset
     *         <br>
     *         215075 Invalid Item Revision
     *         <br>
     *         215076 Invalid CadAttrMappingDefinitionInfo object
     *         <br>
     *         215200 No clientId specified
     *         <br>
     *         215201 Duplicate clientId specified
     *         <br>
     *
     */
    virtual Teamcenter::Services::Cad::_2008_03::Datamanagement::ResolveAttrMappingsResponse resolveAttrMappings ( const std::vector< Teamcenter::Services::Cad::_2008_03::Datamanagement::ResolveAttrMappingsInfo >& info ) = 0;

    /**
     * CreateOrUpdateParts allows the user to update or create a set of parts using Items,
     * Item Revisions, and Datasets and save the boudingbox information related to these
     * objects. The service first attempts to validate the existence of the Item, Item Revision,
     * and Dataset. If the Item and Item Revision already exist, but the Dataset does not,
     * then only the Dataset is created. If the Dataset exists, a new version will be added
     * to the existing series. If any of the objects exist but the input attribute values
     * that differ from those already set, attempts are made to update the values if possible.
     * If the boundingbox information exists it saves that information on that particular
     * dataset else it willnot save the boudingbox information. If no item object reference
     * or item revision object references are specified then a new item and item revision
     * and related objects will be created. All objects created and updated will be returned
     * in the ServiceData. All partial errors will contain the clientIDs for all items related
     * to the error message, i.e. if a dataset encounters an error, then the ID for that
     * erro will be the item client ID concantentated with the item revision id contantenated
     * with the dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param partInput
     *        A list of PartInfo structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2008_06::Datamanagement::PartInfo >& partInput,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;

    /**
     * The purpose of this service is to provide the contents of a folder that a CAD integration
     * typically needs in one service call as opposed to multiple expand calls. This service
     * is specifically for folder expansion and will only return items, item revisions and
     * folders that are contained in the input folder. Other types of objects ( forms, datasets,
     * etc.. ) that are contained directly under the input folder can be returned if their
     * type is specified in the preference. The service will also return the item revisions
     * and datasets for the items found in the folder and datasets found for the item revisions
     * found directly under the folder. The item revisions returned, are controlled thru
     * an input <code>latestNRevs</code> specifying how many latest revisions should be
     * sent to output. The items, item revisions and datasets returned can be filtered thru
     * an input preference of a list of relation names and dataset types filter.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A CAD application needs to know what objects in the database are relative to the
     * cad application. The CAD application can get the contents of the home folder and
     * display to the user. If the user then selects a subfolder of home then the application
     * can expand that folder to get to the desired data. This service will return objects
     * that the cad application understands such as subfolders, items, item revisions and
     * datasets and other objects of the type the application specifies in the input filter.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param folders
     *        A list of folders to expand.
     *
     * @param pref
     *        Filter and expand preferences
     *
     * @return
     *         Contains a list of <code>ExpandFoldersForCADOutput</code> structures  (which contain
     *         information about the input  folder, and filtered folder contents viz. folders, items,
     *         item revisions and objects of specified type). Any error messages are in the <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::ExpandFoldersForCADResponse2 expandFoldersForCAD ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  >& folders,
        const Teamcenter::Services::Cad::_2008_06::Datamanagement::ExpandFolderForCADPref2&  pref ) = 0;

    /**
     * CreateOrUpdateParts allows the user to update or create a set of parts using Items,
     * Item Revisions, and Datasets and save the boudingbox information related to these
     * objects. The service first attempts to validate the existence of the Item, Item Revision,
     * and Dataset. If the Item and Item Revision already exist, but the Dataset does not,
     * then only the Dataset is created. If the Dataset exists, a new version will be added
     * to the existing series. If any of the objects exist but the input attribute values
     * that differ from those already set, attempts are made to update the values if possible.
     * If the boundingbox information exists it saves that information on that particular
     * dataset else it willnot save the boudingbox information. If no item object reference
     * or item revision object references are specified then a new item and item revision
     * and related objects will be created. All objects created and updated will be returned
     * in the ServiceData. All partial errors will contain the clientIDs for all items related
     * to the error message, i.e. if a dataset encounters an error, then the ID for that
     * erro will be the item client ID concantentated with the item revision id contantenated
     * with the dataset client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param partInput
     *        A list of PartInfo structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual
     *
     * @return
     *         contains a list of CreateOrUpdatePartsOutput structures (which contain information
     *         about the item, itemrevisions. datasets and extra objects ). Failure will be with
     *         client id and error message in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2010_09::Datamanagement::PartInfo >& partInput,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;

    /**
     * This operation retrieves all CAD attribute mapping definitions. If a <code>CadAttributeMappingDefinition</code>
     * object has a path that includes a Generic Relationship Manager (GRM) or named reference
     * part, the associated property descriptor and any attached <code>ListOfValues</code>
     * (LOV) objects will be returned. This operation also returns LOV attachments category
     * information to be used in object based conditions.
     * <br>
     * <br>
     * Since this operation returns existing Teamcenter attribute mappings, please reference
     * the Teamcenter help section on creating attribute mappings.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User needs to have attributes set on an object in Teamcenter.
     * <br>
     * <br>
     * For this operation, the client application uses the list of returned attribute mapping
     * definitions to present the correct CAD attributes to the user that correspond to
     * the correct Teamcenter attributes including property descriptor information about
     * the Teamcenter attributes.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         The full list of CAD attribute mapping definitions.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215072:  The operation failed to get all attribute mapping definitions.
     *         </li>
     *         <li type="disc">215117:  Failed to get the <code>CADAttributeMappingDefinition</code>
     *         property descriptor.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if any Teamcenter subsystem errors
     *           occur during the retrieval of all attribute mappings, finding the dataset type or
     *           finding the attribute mapping type.
     */
    virtual Teamcenter::Services::Cad::_2011_06::Datamanagement::GetAllAttrMappingsResponse getAllAttrMappings2 (  ) = 0;

    /**
     * <code>CreateOrUpdateParts</code> allows the user to create or update a set of <b>Items</b>,
     * <b>ItemRevisions</b>, and <b>Datasets</b> (CAD concept of a Part includes these Teamcenter
     * objects). The service first attempts to validate the existence of the <b>Item</b>,
     * <b>ItemRevision</b>, and <b>Dataset</b>. If the <b>Item</b> already exist,s but the
     * <b>ItemRevision</b> does not, then a new initial <b>ItemRevision</b> is created-any
     * existing <b>ItemRevisions</b> are not revised. If the <b>Item</b> and <b>ItemRevision</b>
     * already exist, but the <b>Dataset</b> does not, then only the <b>Dataset</b> is created.
     * If the <b>Dataset</b> exists, a new version will be added to the existing series.
     * If any of the objects exist but the input attribute values that differ from those
     * already set, attempts are made to update the values if possible. If no <b>Item</b>
     * object reference or <b>ItemRevision</b> object references are specified then a new
     * <b>Item</b> and <b>ItemRevision</b> and related objects will be created. All objects
     * created and updated will be returned in the <code>ServiceData</code>. All partial
     * errors will contain the <code>clientIDs</code> for all items related to the error
     * message, i.e. if a dataset encounters an error, then the ID for that error will be
     * the item client ID concatenated with the item revision id concatenated with the dataset
     * client ID, all separated by semi-colons ( ; ).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to create a new CAD Part (item, item revision, and dataset). User fills
     * in the <code>CreateOrUpdateInput</code> structure with the information for the item
     * and item ievision.
     * <br>
     * <br>
     * User wants to create an item and item revision with one or more datasets. Client
     * fills in the <code>CreateOrUpdateInput</code> structure with the information for
     * the item and item revision from the user. Client also fills in one or more <code>DatasetInfos</code>
     * with the information about the datasets to create from the user. Upon return from
     * the service, the client will extract the <code>FileTickets</code> from the <code>DatasetOutputs</code>
     * and upload the data files for the datasets using FMS. Once the uploads have completed,
     * then the client will use the <code>DatasetCommitInfos</code> to attach the upload
     * files to the datasets using the Core Services <code>commitDatasetFiles</code>.
     * <br>
     * <br>
     * User wants to modify properties on an item, item revision or dataset. Client fills
     * in the <code>CreateOrUpdateInput</code> structure with the new information for the
     * item or item revision. Client fills in the new information in a <code>DatasetInfo</code>
     * structure then invokes the service using an existing item or item revision or dataset.
     * <br>
     * <br>
     * <b>User</b> wants to create or update an existing item and/or item revision with
     * User created Form object. The client fills in the necessary data to create or update
     * an item and/or item revision. The client also specifies <code>itemExtraObjectInfo</code>
     * and/or <code>itemRevisionExtraObjectInfo</code> containing the form and relation
     * to be used to attach the form to another object.
     * <br>
     * <br>
     * <b>User</b> wants to add objects to a dataset. This can be done as Extra Objects
     * or using the NamedReference feature. The user fills in the information necessary
     * to create or update a dataset. The user can then specify <code>ExtraObjectInfo</code>
     * data for attaching forms or <code>NamedReferenceObjectInfo</code> for other objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param partInput
     *        A list of <code>PartInfo</code> structures
     *
     * @param pref
     *        A Struct which contains information whether dataset needs to be modified, if input
     *        last modified date is different from actual
     *
     * @return
     *         contains a list of <code>CreateOrUpdatePartsOutput</code> structures (which contain
     *         information about the item, itemrevisions. datasets and extra objects ). Failure
     *         will be with client id and error message in the <code>ServiceData</code>.
     *
     */
    virtual Teamcenter::Services::Cad::_2008_06::Datamanagement::CreateOrUpdatePartsResponse createOrUpdateParts ( const std::vector< Teamcenter::Services::Cad::_2012_09::Datamanagement::PartInfo >& partInput,
        const Teamcenter::Services::Cad::_2007_12::Datamanagement::CreateOrUpdatePartsPref&  pref ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DatamanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/cad/Cad_undef.h>
#endif

