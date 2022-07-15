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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2011_06_ATTRIBUTEEXCHANGE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2011_06_ATTRIBUTEEXCHANGE_HXX

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/documentmanagement/DocumentManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Documentmanagement
        {
            namespace _2011_06
            {
                class Attributeexchange;

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API Attributeexchange
{
public:

    struct MappingObject;
    struct AttrExchangeMapping;
    struct AttrExchangeMappingSetValue;
    struct FailedObjInfo;
    struct Relation;
    struct TcAttributeValue;
    struct ResolveAndGetData;
    struct ResolveAndGetResult;
    struct ResolveAndSetResult;
    struct ResolveAttrMappingsAndGetPropertiesInfo;
    struct ResolveAttrMappingsAndGetPropertiesResponse;
    struct ResolveAttrMappingsAndSetPropertiesInfo;
    struct ResolveAttrMappingsAndSetPropertiesResponse;

    /**
     * This is the key structure holding the metadata exchange mapping information.  Only
     * one of the three values can be set: <i>nextLevelMappedObject</i>, <i>relationObject</i>,
     * or <i>attributeName</i>.
     * <br>
     * <ul>
     * <li type="disc">If the next level mapping is linked by referenced Teamcenter object,
     * then the <i>nextLevelMappedObject</i> is set.
     * </li>
     * <li type="disc">If the next level mapping is linked by Teamcenter relation, then
     * the <i>relationObject</i> is set.
     * </li>
     * <li type="disc">If the current Teamcenter object is where the property is from, then
     * the <i>attributeName</i> is set.
     * </li>
     * </ul>
     */
    struct MappingObject
    {
        /**
         * the Teamcenter object type name.
         */
        std::string objectType;
        /**
         * the Teamcenter property on the upper level Teamcenter object by which the current
         * Teamcenter object is being referenced (For example, an Item Revision relates to a
         * Dataset with the References relation, the upper level object is the Item Revision,
         * and the current object is the Dataset).  This value is set when Teamcenter property
         * type is any other Teamcenter type.
         */
        std::string referencedName;
        /**
         * the indicator of how to find the next level.  If ReferencedObject is the value then
         * use referencedObject from the MappingObject.  If Realtion is the value, then use
         * relationObject, or if Leaf is the value then use attributeName.
         */
        std::string path;
        /**
         * the name of the Teamcenter property on the last level object for the exchange.
         */
        std::string attributeName;
        /**
         * the MappingObject collection which contains mapping information for the next level.
         * This will be a vector of single object.  Using a collection since circular references
         * are not supported.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::MappingObject > nextLevelMappedObject;
        /**
         * the relationship information between the current Teamcenter object and the next level
         * object.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::Relation > relationObject;
    };

    /**
     * The metadata exchange mapping information and the client object property name.
     */
    struct AttrExchangeMapping
    {
        /**
         * the property name of the client object which the Teamcenter property would be exchanged
         * with.
         */
        std::string foreignObjectPropertyName;
        /**
         * the top level MappingObject.
         */
        Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::MappingObject mapping;
    };

    /**
     * The metadata exchange mapping information and the value to be set on the Teamcenter
     * property.
     */
    struct AttrExchangeMappingSetValue
    {
        /**
         * the attribute exchange mapping information.
         */
        Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::AttrExchangeMapping attrExchange;
        /**
         * the property value to be on the Teamcenter object attribute.
         */
        std::string tcPropertyValue;
    };

    /**
     * The failed client object property name and failed error list.
     */
    struct FailedObjInfo
    {
        /**
         * the name of the failed client object property.
         */
        std::string failedForeignObjectName;
        /**
         * the list of failure errors.
         */
        std::vector< std::string > errorStack;
    };

    /**
     * The information about relationship between two Teamcenter objects.
     */
    struct Relation
    {
        /**
         * the relationship name that exists between two Teamcenter objects.
         */
        std::string relationName;
        /**
         * a next level object which contains mapping information.  This collection will only
         * contain one object, using a collection since circular references are not supported.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::MappingObject > mappedObject;
        /**
         * the information about what the relation is between two Teamcenter objects.  The values
         * could be Primary or Secondary. If it is primary, the containing object is the primary
         * object in the relation.  If it is secondary, the containing object is the secondary
         * object in the relation.
         */
        std::string relationType;
    };

    /**
     * The resolved attribute information.
     */
    struct TcAttributeValue
    {
        /**
         * the Teamcenter property value.  The actual value is converted to string before sending
         * to the client.
         */
        std::string tcVal;
        /**
         * the Teamcenter property type.  The type of the value can be of char, double, float,
         * int, logical, short or string.  The client and the server will need to do the conversion
         * based on these types.
         */
        std::string typeOfVal;
    };

    /**
     * The Teamcenter object property values based on the given metadata exchange mapping
     * information.
     */
    struct ResolveAndGetData
    {
        /**
         * the property name of the client object which the Teamcenter object property would
         * be exchanged with.
         */
        std::string foreignObjectPropertyName;
        /**
         * the Teamcenter property value to be set on the client object property.
         */
        Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::TcAttributeValue tcAttrVal;
        /**
         * this value is true if the mapping resolve for this input object failed.
         */
        bool isFailed;
        /**
         * these are the errors return from the server for the particular mapping resolve or
         * getting properties.
         */
        std::vector< std::string > errorStack;
    };

    /**
     * The WorkspaceObject (the current implementation in the Microsoft Office client, this
     * is the Dataset) object and its corresponding resolved attribute mapping outputs.
     */
    struct ResolveAndGetResult
    {
        /**
         * the WorkspaceObject (the current implementation in the Microsoft Office client, this
         * is the Dataset) object from which the resolving of the mapping begins.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  dataset;
        /**
         * the list of resolved attribute structures whether it succeeded or failed.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAndGetData > resolveAndGetDataList;
    };

    /**
     * The Teamcenter object and the corresponding failed mapping information about which
     * Teamcenter object property setting has failed.
     */
    struct ResolveAndSetResult
    {
        /**
         * the WorkspaceObject (the current implementation in the Microsoft Office client, this
         * is the Dataset)  object where the attribute mapping start from.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  dataset;
        /**
         * the list of the failed mappping information.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::FailedObjInfo > failedObjInfos;
    };

    /**
     * The input structure for ResolveAttrMappingsAndGetProperties service method.
     */
    struct ResolveAttrMappingsAndGetPropertiesInfo
    {
        /**
         * the locale information for the dataset content.
         */
        std::string locale;
        /**
         * the WorkspaceObject (the current implementation in the Microsoft Office client, this
         * is the Dataset) object from which the metadata exchange is initiated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  datsetObject;
        /**
         * the list of structures with the metadata exchange mapping information.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::AttrExchangeMapping > attrExchange;
    };

    /**
     * The return structure for resolving metadata exchange mappings and the Teamcenter
     * object property values.
     */
    struct ResolveAttrMappingsAndGetPropertiesResponse
    {
        /**
         * the list of structures that have the Teamcenter object property values.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAndGetResult > resolveAndGetResults;
        /**
         * the list of errors.  The error would be associated with the property names of the
         * client object property for the which the metadata exchange failed.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The input structure for resolving metadata exchange mappings and to set the Teamcenter
     * object property.
     */
    struct ResolveAttrMappingsAndSetPropertiesInfo
    {
        /**
         * the locale information for the dataset content.
         */
        std::string locale;
        /**
         * the WorkspaceObject (normally is Dataset) object from which the metadata exchange
         * is initiated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  datasetObject;
        /**
         * the list of structures with the metadata exchange mapping information.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::AttrExchangeMappingSetValue > attrExchange;
    };

    /**
     * The return structure for resolving metadata exchange mappings, and the Teamcenter
     * object property values.
     */
    struct ResolveAttrMappingsAndSetPropertiesResponse
    {
        /**
         * the list of partial errors returned for failed metadata exchange object.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * the list of structures that have the client object property name that fails to set
         * and the corresponding list of errors.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAndSetResult > resolvedAndSetResults;
    };




    /**
     * This operation processes the metadata exchange mapping information between the client
     * application and Teamcenter from the provided input list of <b>ResolveAttrMappingsAndGetPropertiesInfo</b>
     * structure (containing the metadata exchange mapping information from the client application).
     * The operation then gets and returns the property  values of the corresponding Teamcenter
     * object from provided input information.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Metadata exchange between Teamcenter and Microsoft Office Word application</b>
     * <br>
     * From the Teamcenter client for Microsoft Office Word 2010, a user opens and checks
     * out a WordX Dataset.  User then clicks on the Teamcenter ribbon and clicks on Attribute
     * Exchange> Configurations> Create.  From here user can set up the metadata exchange
     * between the properties of the Microsoft Office Word file properties and the properties
     * of the Teamcenter object.
     * <br>
     * <br>
     * In the configuration, user can set the direction of the metadata exchange either
     * as File to Teamcenter, Teamcenter to File, or Two Way.  In this case, user selects
     * Teamcenter to File for the metadata exchange from the client to Teamcenter.  User
     * sets up the property mapping by selecting a file property (Comments for example)
     * and selecting a Teamcenter object property (object_desc for example), and saves the
     * attribute exchange configuration.  User then clicks on Attribute Exchange>Reload
     * button.  The Microsoft Office Word initiates this operation and gets Teamcenter object
     * property (object_desc for example) value back.  To verify the client file property
     * gets updated, from Microsoft Office Word menu File, select Info (in the left panel),
     * then select Properties (in the right panel), then select Show Document Panel.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param info
     *        It contains the attribute exchange mappings information.
     *
     * @return
     *         <i>ResolveAttrMappingsAndGetProperpertiesResponse</i> structure which includes the
     *         <i>ServiceData</i> with some of possible Partial Errors listed below for any object
     *         that fails in the metadata exchange and a list of <i>ResultAndGetResult</i> structure
     *         (containing the <i>WorkspaceObject</i> that initiates the operation with the  corresponding
     *         list of resolved metadata exchange mapping information: the client property name,
     *         the Teamcenter property value, success or failure, any errors).
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">262019&nbsp;&nbsp;&nbsp;&nbsp;The Mapping object Attriubte Name is
     *         empty.
     *         </li>
     *         <li type="disc">262021&nbsp;&nbsp;&nbsp;&nbsp;The Relation object is not valid.
     *         </li>
     *         <li type="disc">262022&nbsp;&nbsp;&nbsp;&nbsp;The Mapping path is not valid.
     *         </li>
     *         <li type="disc">262024&nbsp;&nbsp;&nbsp;&nbsp;No object matches the provided Relation
     *         name.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndGetPropertiesResponse resolveAttrMappingsAndGetProperties ( const std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndGetPropertiesInfo >& info ) = 0;

    /**
     * This operation processes the metadata exchange mapping information between the client
     * and Teamcenter from the provided input list of <b>ResolveAttrMappingsAndSetPropertiesInfo</b>
     * structure (containing the metadata exchange mapping information from the client application).
     * The operation sets the Teamcenter property values based on the provided input information.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Metadata exchange between Teamcenter and Microsoft Office Word application</b>
     * <br>
     * <br>
     * From the Teamcenter client for Microsoft Office Word 2010, a user opens and checks
     * out a WordX Dataset.  User then clicks on the Teamcenter ribbon and clicks on Attribute
     * Exchange >Configurations>Create.  From here user can set up the metadata exchange
     * between the properties of the Microsoft Office Word file and the properties of the
     * Teamcenter object.
     * <br>
     * <br>
     * In the configuration, user can set the direction of the metadata exchange either
     * as File to Teamcenter, Teamcenter to File, or Two Way.  In this case, user selects
     * File to Teamcenter for the metadata exchange, pick a file property (Comment for example),
     * pick a Teamcenter object property (object_desc for example), and save the attribute
     * exchange configuration.  From Microsoft Office Word menu File, select Info (left
     * panel), then select Properties (right panel)>Show Document Panel.  Update the Comments
     * text box in the Document Properties Panel with some text.  Now select Teamcenter
     * ribbon and click on Save.  Save and check in the Dataset.  During this process, the
     * Microsoft Office Word initiates this operation and updates Teamcenter object property
     * (object_desc for example) value.  User can verify the Teamcenter object property
     * (object_desc for example) by login to a Teamcenter client such as Rich Application
     * Client (RAC), do a View properties on the Teamcenter object.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param info
     *        It contains information for Resolving the attribute exchange and the value to be
     *        set on the Teamcenter attribute.
     *
     * @return
     *         <i>ResolveAttrMappingsAndSetProperpertiesResponse</i> structure which includes the
     *         <i>ServiceData</i> with some possible Partial Errors listed below for any object
     *         that fails in the metadata exchange and a list of <i>ResolveAndSetResult</i> structure
     *         (containing the <i>WorkspaceObject</i> that has failure along with the corresponding
     *         list of client properties and error messages).
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndSetPropertiesResponse resolveAttrMappingsAndSetProperties ( const std::vector< Teamcenter::Services::Documentmanagement::_2011_06::Attributeexchange::ResolveAttrMappingsAndSetPropertiesInfo >& info ) = 0;


protected:
    virtual ~Attributeexchange() {}
};
            }
        }
    }
}

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

