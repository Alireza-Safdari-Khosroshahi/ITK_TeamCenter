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

#ifndef TEAMCENTER_SERVICES_CORE__2012_02_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2012_02_DATAMANAGEMENT_HXX

#include <teamcenter/services/core/_2008_06/Datamanagement.hxx>
#include <teamcenter/soa/client/model/Folder.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2012_02
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct BulkCreIn;
    struct ValidationResponse;
    struct WhereUsedConfigParameters;
    struct WhereUsedInputData;
    struct WhereUsedOutputData;
    struct WhereUsedParentInfo;
    struct WhereUsedResponse;

    /**
     * A map of type bool indicating if the ID is valid. The key is clientId from <code>CreateIn</code>.
     * The value is of type bool.  True if id is valid, otherise id is invalid
     */
    typedef std::map< std::string, bool > ValidationResult;

    /**
     * Map of bool property names to values (<code>string, bool</code>).
     */
    typedef std::map< std::string, bool > WUBoolMap;

    /**
     * Map of DateTime property names to values <code>(string, DateTime</code>).
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::DateTime > WUDateMap;

    /**
     * Map of double property names to values (<code>string, double</code>).
     */
    typedef std::map< std::string, double > WUDoubleMap;

    /**
     * Map of float property names to values (<code>string, float</code>).
     */
    typedef std::map< std::string, float > WUFloatMap;

    /**
     * Map of int property names to values (<code>string, in</code>).
     */
    typedef std::map< std::string, int > WUIntMap;

    /**
     * Map of sting property names to values <code>(string, string</code>).
     */
    typedef std::map< std::string, std::string > WUStringMap;

    /**
     * Map of <b>BusinessObject</b> property names to values (<code>string, BusinessObject</code>).
     */
    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > WUTagMap;

    /**
     * Input for bulk create operation including unique client identifier.
     */
    struct BulkCreIn
    {
        /**
         * client id Unique client identifier.
         */
        std::string clientId;
        /**
         * Number of instances of each type for creation.
         */
        int quantity;
        /**
         * Containing folder for the newly created items.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Folder>  folder;
        /**
         * Input data for create operation.
         */
        Teamcenter::Services::Core::_2008_06::Datamanagement::CreateInput data;
    };

    /**
     * Return structure for <code>createConnections</code> operation
     */
    struct ValidationResponse
    {
        /**
         * A map of type <<code>std::string ,bool</code>> indicating if the ID is valid. The
         * key is clientId from <code>CreateIn</code>.  The value is true if the id is valid,
         * otherwise id is invalid.
         */
        ValidationResult validationResult;
        /**
         * Service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Additional Configuration Parameters required for <code>whereUsed</code> search. For
     * example <code>tagMap</code> to specify the <b>RevisionRule</b>, <code>boolMap</code>
     * to specify <code>whereUsedPreciseFlag</code>, and <code>intMap</code> to specify
     * number of levels.
     */
    struct WhereUsedConfigParameters
    {
        /**
         * String Input parameters ( std::string, std::string )
         */
        WUStringMap stringMap;
        /**
         * Double Input parameters ( std::string, double )
         */
        WUDoubleMap doubleMap;
        /**
         * int Input parameters ( std::string, int )
         */
        WUIntMap intMap;
        /**
         * bool Input parameters ( std::string, bool )
         */
        WUBoolMap boolMap;
        /**
         * Date Input parameters ( std::string, Teamcenter::DateTime )
         */
        WUDateMap dateMap;
        /**
         * Object Input parameters   ( std::string, BusinessObjectRef ( Teamcenter::BusinessObject
         * ) )
         */
        WUTagMap tagMap;
        /**
         * Float Input Parameters ( std::string, float )
         */
        WUFloatMap floatMap;
    };

    /**
     * Input data for <code>whereUsed</code> search contains the target object to perform
     * search along with the configuration parameters.
     */
    struct WhereUsedInputData
    {
        /**
         * Target object to do <code>whereUsed</code> search
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  inputObject;
        /**
         * Flag to decide which config paramerters to be used, local or common
         */
        bool useLocalParams;
        /**
         * Additional Configuration Parameters required for <code>whereUsed</code> search
         */
        Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedConfigParameters inputParams;
        /**
         * Client ID to uniquely idnetify this input data
         */
        std::string clientId;
    };

    /**
     * This structure contains output information of Where Used Call.
     */
    struct WhereUsedOutputData
    {
        /**
         * Input object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  inputObject;
        /**
         * List of where used result objects
         */
        std::vector< Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedParentInfo > info;
        /**
         * Client ID of input object which this output object is for
         */
        std::string clientId;
    };

    /**
     * Generic Parent Info Structure
     */
    struct WhereUsedParentInfo
    {
        /**
         * Parent Workspace Object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  parentObject;
        /**
         * levet at which parent is found
         */
        int level;
    };

    /**
     * <code>WhereUsedResponse</code> object contains list of  <code>WhereUsedOutputData</code>
     * structure. This structure contains list of <b>ItemRevision</b> objects which are
     * result of <code>whereUsed</code> search.
     */
    struct WhereUsedResponse
    {
        /**
         * List of <code>WhereUsedOutputData</code> structures
         */
        std::vector< Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedOutputData > output;
        /**
         * Standard <code>ServiceData</code> Member
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation determines if the given <code>MultiFieldKey</code> properties are
     * unique based on the <code>MultiFieldKey</code> definition.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use this operation before creating a new object to validate if the <code>MultiFieldKey</code>
     * property combination is already used.  This is an existence check rather than a true
     * validation. It does not validate the property values against Naming Rules.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Core Model Item - A set of capabilities/functionality (data model and behaviours)
     * that form the very core of Teamcenter PLM platform. This component defines the Item
     * Class and behavior.
     *
     * @param input
     *        A list of MultiFieldKey attribute/value pairs for the object to be created
     *
     * @return
     *         A list of <code>MultiFieldKey</code> attribute/value pairs for the object to be created.
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Datamanagement::ValidationResponse validateIdValue ( const std::vector< Teamcenter::Services::Core::_2008_06::Datamanagement::CreateIn >& input ) = 0;

    /**
     * This is a generic operation for bulk creation of Business Objects. This will create
     * instances of the given quantity of the specified type in their specified containing
     * folders. This will also create any secondary(compounded) objects that need to be
     * created, assuming the <code>CreateInput</code> for the secondary object is represented
     * in the recursive <code>CreateInput</code> object e.g. <b>Item</b> is Primary Object
     * that also creates<b> Item Master</b>, <b>ItemRevision</b> and <b>ItemRevision</b>
     * in turn creates <b>ItemRevision</b> <b>Master</b>. The input for all these levels
     * is passed in through the recursive <code>CreateInput</code> object. This operation
     * is applicable for bulk creation of <b>Item</b>, <b>Form</b> and <b>Dataset</b> Types
     * only.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * To create large number of objects of specified types namely <b>Item</b>, <b>Dataset</b>
     * and <b>Form</b> each of specified quantities and save them through a single transaction
     * to significantly reduce the number of sql queries incurred during object creation,
     * thus improving object creation performance and making object creation scalable.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createFolders
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param input
     *        A vector of <code>BulkCreIn</code> structures representing the <code>CreateInput</code>
     *        for the bulk creation of business objects of the specified quantity for each type.
     *
     * @return
     *         A list of newly created objects, one for each specified type of specified quantity
     *         in the input <code>BulkCreIn</code> structure. This operation does not support Partial
     *         Errors.
     *         <br>
     *         <br>
     *         For Example,  to create Items of quantity 5 and Documents of quantity 4, we specify
     *         an input vector of two <code>BulkCreIn</code> structures, one each refering to <b>Item</b>
     *         and <b>Document</b> business objects respectively.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Datamanagement::CreateResponse bulkCreateObjects ( const std::vector< Teamcenter::Services::Core::_2012_02::Datamanagement::BulkCreIn >& input ) = 0;

    /**
     * The <code>whereUsed</code> service identifies all the parent <b>Item</b> and <b>ItemRevision</b>
     * objects in the structure where the input <b>Item</b> or <b>ItemRevision</b> is used.
     * User can provide <b>RevisionRule</b> to search for specific <b>ItemRevision</b> .
     * By default all <b>ItemRevision</b> objects are returned. The number of levels of
     * <code>whereUsed</code> search indicates, whether to return one or top or all levels
     * of assemblies. It supports <code>whereUsed</code> search on any <b>WorkspaceObject</b>
     * which implements the "<code>whereUsed</code>" interface.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user performs <code>whereUsed</code> search to find all the assemblies that contain
     * a particular <b>Item</b> or <b>ItemRevision</b>. User inputs <b>Item</b> or <b>ItemRevision</b>
     * and the search can be made with following options:
     * <br>
     * <ul>
     * <li type="disc"><b>RevisionRule</b>  This can be set to All, displaying all <b>ItemRevision</b>
     * objects  that have an occurrence of target <b>ItemRevision</b>. If a specific <b>RevisionRule</b>
     * is selected only the <b>ItemRevision</b> objects  configured by the rule are returned
     * in the search.
     * </li>
     * <li type="disc">Depth up to which numbers of levels are to be returned.
     * </li>
     * </ul>
     * <br>
     * <br>
     * The output contains list of  each parent level search result in the structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * WhereUsed - Provides where used search capability for Item, ItemRevision, DataSet
     * and apperanceGroup objects in the database. User can apply the Rev Rule criteria
     * to filter the results for configured results.
     *
     * @param input
     *        <code>WhereUsedInputData</code> object list
     *
     * @param configParams
     *        Additional Configuration Parameters if required. For example <code>tagMap</code>
     *        to specify the <b>RevisionRule</b>, <code>boolMap</code> to specify whereUsedPreciseFlag,
     *        and <code>intMap</code> tp specify number of levels .
     *
     * @return
     *         Contains input object and for each input object, the parent object(s) found and the
     *         level at which it was found.
     *         <br>
     *         Failure will be returned via <code>ServiceData</code> with original input object
     *         mapped to error message.
     *         <br>
     *         214110&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         input object is not valid
     *         <br>
     *         27074&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>whereUsed</code>
     *         funtionality is not supported for this object
     *         <br>
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedResponse whereUsed ( const std::vector< Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedInputData >& input,
        const Teamcenter::Services::Core::_2012_02::Datamanagement::WhereUsedConfigParameters&  configParams ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

