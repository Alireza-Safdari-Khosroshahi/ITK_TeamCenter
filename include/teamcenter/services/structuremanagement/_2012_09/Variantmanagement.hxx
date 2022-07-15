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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_VARIANTMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_VARIANTMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2012_09
            {
                class Variantmanagement;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Variantmanagement
{
public:

    struct SaveAsInput;
    struct SaveAsIn;
    struct CreateOrSaveAsDescriptor;
    struct CreateAndSubsVIInput;
    struct CreateAndSubsVIOutput;
    struct CreateAndSubsVIResponse;
    struct CreateVIInput;
    struct CreateVIOutput;
    struct CreateVIResponse;
    struct DeepCopyData;
    struct ExtendedAttributes;
    struct ItemProperties;

    /**
     * Enumeration of the different property types for which DeepCopy Rule  configuration
     * is enabled
     */
    enum PropertyType{ Relation,
                 Reference
                 };

    /**
     * AttributeNameValueMap
     */
    typedef std::map< std::string, std::string > AttributeNameValueMap;

    /**
     * BoolMap
     */
    typedef std::map< std::string, bool > BoolMap;

    /**
     * BoolVectorMap
     */
    typedef std::map< std::string, std::vector< bool > > BoolVectorMap;

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
     * Map containing string property values
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
     * Structure encapsulating all information related to a Workspace Object which may be
     * required for "Save As" operation during operations '<code>createVariantItem</code>'
     * or '<code>createAndSubstituteVariantItem</code>'.
     */
    struct SaveAsInput
    {
        /**
         * Type Name Of Business Object
         */
        std::string boName;
        /**
         * Map containing string property values . Pairs (string, string)
         */
        StringMap stringProps;
        /**
         * Map containing string array property values. Pairs (string, string[])
         */
        StringVectorMap stringArrayProps;
        /**
         * Map containing double property values. Pairs (string, double)
         */
        DoubleMap doubleProps;
        /**
         * Map containing double array property values. Pairs (string,  double[])
         */
        DoubleVectorMap doubleArrayProps;
        /**
         * Map containing float property values. Pairs (string, float)
         */
        FloatMap floatProps;
        /**
         * Map containing float array property values. Pairs (string, float[])
         */
        FloatVectorMap floatArrayProps;
        /**
         * Map containing integer property values. Pairs (string, integer)
         */
        IntMap intProps;
        /**
         * Map containing integer array property values. Pairs (string, integer[])
         */
        IntVectorMap intArrayProps;
        /**
         * Map containing boolean property values. Pairs (string, boolean)
         */
        BoolMap boolProps;
        /**
         * Map containing boolean array property values. Pairs (string, boolean[])
         */
        BoolVectorMap boolArrayProps;
        /**
         * Map containing date property values. Pairs (string, Date)
         */
        DateMap dateProps;
        /**
         * Map containing date array property values . Pairs (string, Date[])
         */
        DateVectorMap dateArrayProps;
        /**
         * Map containing tag property values. Pairs (string, Tag)
         */
        TagMap tagProps;
        /**
         * Map containing tag array property values. Pairs (string, Tag[])
         */
        TagVectorMap tagArrayProps;
    };

    /**
     * Input for save as operation
     */
    struct SaveAsIn
    {
        /**
         * Target object being saved as
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  targetObject;
        /**
         * SaveAsInput (user input from SaveAs dialog) for the targetobject being saved as
         */
        Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::SaveAsInput saveAsInput;
        /**
         * DeepCopyData of the objects attached to the targetobject
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::DeepCopyData > deepCopyDatas;
    };

    /**
     * This is helper structure to collect all information of new variant <b>Item</b> required
     * for either creating New <b>Item</b> or saving existing <b>Item</b> as variant <b>Item</b>.
     */
    struct CreateOrSaveAsDescriptor
    {
        /**
         * Input properties for new variant <b>Item</b>.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::ItemProperties > properties;
        /**
         * Input for save as operation
         */
        Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::SaveAsIn saveAsIn;
        /**
         * bool flag to indicate Create new <b>Item</b> as true and "Save as" operation as false
         * value.
         */
        bool bCreateOrSaveAsFlag;
    };

    /**
     * Input structure for operation '<code>createAndSubstituteVariantItem</code>'. One
     * structure represents One new variant <b>Item</b> to be created.
     */
    struct CreateAndSubsVIInput
    {
        /**
         * <b>BOMLine</b> of configured structure from which new variant <b>Item</b> Structure
         * should be created. This structure has Variants defined and can be configured for
         * some given variant Configuration. For more details please refer section 'Creating
         * and updating variant Items' from Teamcenter Documentation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  genericBOMLine;
        /**
         * Create or SaveAs description required for <b>Item</b> Creation. This will include
         * information about new variant <b>Item</b> creation such as <b>Item</b> Id, name,
         * description, objects that need to be copied or done 'Save As' along with new <b>Item</b>.
         */
        Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateOrSaveAsDescriptor createOrSaveAsDescriptor;
        /**
         * <b>BOMLine</b> of variant <b>Item</b> structure. After creating new variant <b>Item</b>
         * from genericBOMLine, the newly created variant <b>ItemRevision</b> will be substituted
         * on this <b>viBOMLine</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  viBOMLine;
        /**
         * Flag to decide Variant <b>Item</b> should be linked to its generic structure or not.
         * Value of this parameter will be overriden by preference '<code>PSEIsNewVILinkedToModule</code>',
         * if exists on SITE level.
         */
        bool linkVIToGenericItem;
        /**
         * Find existing Variant <b>Item</b> before creating new Variant <b>Item</b>. If existing
         * Variant <b>Item</b> is found, then new Variant <b>Item</b> is not created. This existing
         * Variant <b>Item</b> will be replaced on viBOMLine.
         */
        bool findVIBeforeCreate;
    };

    /**
     * Output structure for <code>CreateAndSubstituteVI</code> SOA
     */
    struct CreateAndSubsVIOutput
    {
        /**
         * Generic <b>BOMLine</b> from which variant <b>Item</b> is created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  genericBOMLine;
        /**
         * <b>BOMLine</b> of variant <b>Item</b> structure. After creating new variant <b>Item</b>
         * from <code>genericBOMLine</code>, the newly created variant <b>ItemRevision</b> will
         * be substituted on this <code>viBOMLine</code>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  viBOMLine;
        /**
         * <b>ItemRevision</b> of newly created Variant <b>Item</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  newVariantItemRevision;
        /**
         * This flag will be returned populated only when flag '<code>findVIBeforeCreate</code>'
         * in server input '<code>CreateAndSubsVIInput</code>' is passed as 'True'. Flag to
         * indicate that if existing Variant <b>Item</b> was not found and new Variant <b>Item</b>
         * is created. If value is true, this means existing Variant <b>Item</b> was found,
         * and was used for substitute operation.
         */
        bool isExistingVIFound;
    };

    /**
     * Response structure to operation '<code>createAndSubstituteVariantItem</code>'.
     */
    struct CreateAndSubsVIResponse
    {
        /**
         * List of <code>CreateAndSubsVIOutput</code> s for each <code>CreateAndSubsVIInput</code>.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateAndSubsVIOutput > createAndSubsOutputs;
        /**
         * Service Data to return error back to caller.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input Structure for operation <code>'createVariantItem</code>'.
     */
    struct CreateVIInput
    {
        /**
         * <b>BOMLine</b> of configured structure from which new variant <b>Item</b> Structure
         * should be created. This structure has Variants defined and can be configured for
         * some given variant Configuration. For more details please refer section 'Creating
         * and updating variant Items' from Teamcenter Documentation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  genericBOMLine;
        /**
         * Create or SaveAs description required for <b>Item</b> Creation. This will include
         * information about new variant <b>Item</b> creation such as <b>Item</b> Id, name,
         * description, objects that need to be copied or done 'Save As' along with new <b>Item</b>.
         */
        Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateOrSaveAsDescriptor createOrSaveAsDescriptor;
        /**
         * Flag to decide variant <b>Item</b> should be linked to its generic structure or not.
         * Value of this parameter will be overridden by preference 'PSEIsNewVILinkedToModule',
         * if exists on SITE location.
         */
        bool linkVIToGenericItem;
    };

    /**
     * Output structure for operation <code>'createVariantItem</code>'. There will be one
     * <code>CreateVIOutput</code> for each <code>CreateVIInput</code>.
     */
    struct CreateVIOutput
    {
        /**
         * BOM Line of configured structure from which new Variant Item Structure should be
         * created. This structure has Variants defined and can be configured for some given
         * Variant Configuration. For more details please refer section 'Creating and updating
         * variant items' from Teamcenter Documentation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  genericBOMLine;
        /**
         * Item Revision of newly created Variant Item.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  newVariantItemRevision;
    };

    /**
     * Response structure for operation '<code>createVariantItem</code>'
     */
    struct CreateVIResponse
    {
        /**
         * List of outputs one each for <code>'CreateVIInput</code>'
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateVIOutput > createVariantItemOutput;
        /**
         * Service Data to return error back to caller.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure to collect information about objects which should be copied or referenced
     * in new variant <b>Item</b>.
     */
    struct DeepCopyData
    {
        /**
         * Other side object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  attachedObject;
        /**
         * Name of relation type or reference property for which DeepCopy rule is configured
         */
        std::string propertyName;
        /**
         * Name of relation type or reference property for which DeepCopy rule is configured
         */
        PropertyType propertyType;
        /**
         * DeepCopy action [NoCopy, CopyAsReference, CopyAsObject or Select]
         */
        std::string copyAction;
        /**
         * Flag indicating if target object is primary or secondary
         */
        bool isTargetPrimary;
        /**
         * If this flag is false, the copy action can be dynamically changed by user
         */
        bool isRequired;
        /**
         * This is a Boolean representing whether the Properties on the Relation if any in the
         * Relation that exists between
         */
        bool copyRelations;
        /**
         * SaveAsInput type name
         */
        std::string saveAsInputTypeName;
        /**
         * SaveAsInput field to capture user inputs on the SaveAs dialog. NOTE: This field is
         * unused in the getSaveAsDesc operation. It is used in the saveAsObjects operation
         */
        Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::SaveAsInput saveAsInput;
        /**
         * Vector of DeepCopy data for the secondary objects on the other side
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::DeepCopyData > childDeepCopyData;
    };

    /**
     * Structure to collect additional attributes to be assigned apart from default 'Save
     * As' or 'Cretae New' <b>Item</b> operation.
     */
    struct ExtendedAttributes
    {
        /**
         * Type of Business Object.
         */
        std::string objectType;
        /**
         * Map of attribute name and its value. pairs( String, String )
         */
        AttributeNameValueMap attributes;
    };

    /**
     * Specifies attributes for the new <b>Item</b> or <b>ItemRevision</b>. Mainly used
     * in 'Create new <b>Item</b>' scenario, describes specific attributes to be assigned.
     */
    struct ItemProperties
    {
        /**
         * Identifier that helps the client to track the object(s) created
         */
        std::string clientId;
        /**
         * Id of the <b>Item</b> to be created
         */
        std::string itemId;
        /**
         * Name of the <b>Item</b> to be created
         */
        std::string name;
        /**
         * Business Object type of the <b>Item</b> to be created
         */
        std::string type;
        /**
         * Id of the initial revision of the <b>Item</b> to be created
         */
        std::string revId;
        /**
         * UOM of the <b>Item</b> to be created
         */
        std::string uom;
        /**
         * Description of the <b>Item</b> to be created
         */
        std::string description;
        /**
         * List of '<code>extendedAttributes</code>' structures having Name/value pairs for
         * additional attributes to set.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::ExtendedAttributes > extendedAttributes;
    };




    /**
     * This operation will create new variant <b>Item</b> for given <b>BOMLine</b> (also
     * called as 'Generic <b>BOMLine</b>') from a BOM structure (also called as 'Generic
     * Structure') having variability using variants. Addition to creating new variant Item,
     * this is operation will also replace or substitute newly created variant Item Revision
     * in given target <b>BOMLine</b> (also called as 'VI <b>BOMLine</b>') in variant Structure
     * which corresponding to fully configured structure by fixing variability in Generic
     * BOM Structure.
     * <br>
     * <br>
     * Operation also accepts 2 flags <code>'findVIBeforeCreate</code>' used to control
     * if existing variant <b>Item</b> should be searched and used instead of creating new
     * variant <b>Item</b> and <code>'linkVIToGenericItem</code>' to link newly created
     * variant <b>Item</b> to source <b>Item</b> of generic <b>BOMLine</b>.
     * <br>
     * <br>
     * The new variant <b>Item</b> can be created in 2 ways either creating new separate
     * <b>Item</b> or doing "Save-As" operation on generic Item. In case of "Save-As" the
     * parameter <code>'CreateOrSaveAsDescriptor</code>' will provide additional information
     * about which all related objects are carried over to new <b>Item</b> from source generic
     * <b>Item</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation should be used when user has Generic Structure & corresponding created
     * variant Structure and user wants to create <b>Item</b> which is variant for each
     * child BOMLine object and replace in variant Structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param createAndSubstituteVIInput
     *        Consists of set of output structures, an output structure for each input. An output
     *        structure have respective input <code>'genericBOMLine</code>' & <code>'viBOMLine</code>'
     *        and newly created <b>ItemRevision</b> object as <code>'newVariantItemRevision</code>';
     *        along with flag '<code>isExistingVIFound</code>' indicating if <code>'newVariantItemRevision</code>'
     *        is created newly or found existing Item which is variant and used.
     *
     * @return
     *         This operation returns substituted <b>ItemRevision</b>  which is variant and flag
     *         to indicate <b>Item</b> is created newly or being used existing with same variant
     *         Configuration.
     *         <br>
     *         <br>
     *         In case of errors ServiceData will return partial errors. Possible Errors are listed
     *         below.
     *         <br>
     *         <ul>
     *         <li type="disc">48102 Variant Item cannot be created for legacy option.
     *         </li>
     *         <li type="disc">48103 Variant Item options must all have a value defined.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateAndSubsVIResponse createAndSubstituteVariantItem ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateAndSubsVIInput >& createAndSubstituteVIInput ) = 0;

    /**
     * This operation will create new variant <b>Item</b> for given <b>BOMLine</b> (also
     * called as 'Generic <b>BOMLine</b>') from a BOM structure (also called as 'Generic
     * Structure') having variability using variant Options.
     * <br>
     * <br>
     * Operation also accepts a flag <code>'linkVIToGenericItem</code>' to link newly created
     * variant <b>Item</b> to source Item of 'generic <b>BOMLine</b>'.
     * <br>
     * <br>
     * The new variant <b>Item</b> can be created in 2 ways either by creating new separate
     * <b>Item</b> or doing "Save-As" operation on generic <b>Item</b>. In case of "Save-As"
     * the parameter
     * <br>
     * <code>'CreateOrSaveAsDescriptor</code>' will provide additional information about
     * which all related objects are carried over to new <b>Item</b> from source generic
     * <b>Item</b>.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation should be used when user wants to create new variant <b>Item</b> using
     * generic <b>BOMLine</b> from a generic BOM structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param createVIInputs
     *        List of <code>createVIInput</code> structures
     *
     * @return
     *         It returns newly created variant <b>ItemRevision</b>.
     *         <br>
     *         In case of errors <code>ServiceData</code> will return partial errors. Possible Errors
     *         are listed below.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">48102 Variant Item cannot be created for legacy option.
     *         </li>
     *         <li type="disc">48103 Variant Item options must all have a value defined.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateVIResponse createVariantItem ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Variantmanagement::CreateVIInput >& createVIInputs ) = 0;


protected:
    virtual ~Variantmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

