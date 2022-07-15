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

#ifndef TEAMCENTER_SERVICES_ASBUILT__2008_06_ASBUILT_HXX
#define TEAMCENTER_SERVICES_ASBUILT__2008_06_ASBUILT_HXX

#include <teamcenter/soa/client/model/AsBuiltBOMLine.hxx>
#include <teamcenter/soa/client/model/AsBuiltStructure.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/NeutralBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/asbuilt/AsBuilt_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asbuilt
        {
            namespace _2008_06
            {
                class Asbuilt;

class TCSOAASBUILTSTRONGMNGD_API Asbuilt
{
public:

    struct ExtendedAttributes;
    struct AsBuiltStructureInfo;
    struct GenerateAsBuiltStructInput;
    struct GenerateAsBuiltStructureOutput;
    struct GenerateAsBuiltStructureResponse;
    struct InstallPhysicalPartInfo;
    struct InstallPhysicalPartOutput;
    struct InstallPhysicalPartResponse;
    struct InstallPhysicalPrtInput;
    struct RemovedLineOutput;
    struct RemoveLineInput;
    struct UnInstallPhysicalPartResponse;

    /**
     * AttributeNameValueMap
     */
    typedef std::map< std::string, std::string > AttributeNameValueMap;

    /**
     * The ExtendedAttributes structure represents the structure containing additional attributes
     * that might be passed from the client
     */
    struct ExtendedAttributes
    {
        /**
         * objectType
         */
        std::string objectType;
        /**
         * attributes
         */
        AttributeNameValueMap attributes;
    };

    /**
     * Structure represents the parameters required to generate an as-built <b>PhysicalPart</b>
     * structure for a given design <b>Item</b> structure.
     */
    struct AsBuiltStructureInfo
    {
        /**
         * The item id of the design <b>Item</b> object.
         */
        std::string neutralItemId;
        /**
         * The Serial Number, required to uniquely identify a serialized <b>PhysicalPart</b>.
         */
        std::string serialNumber;
        /**
         * The Lot Number,  if the <b>PhysicalPart</b> is of Lot type.
         */
        std::string lotNumber;
        /**
         * The Manufacturer's id, required to uniquely identify a serialized <b>PhysicalPart</b>.
         */
        std::string manufacturerId;
        /**
         * Name of the <b>StructureContext</b> object. <b>Structurecontext</b> object is created
         * with the current configuration of the <b>MroBOMWindow</b> and saved on the top <b>PhysicalPart</b>.
         */
        std::string structureContext;
        /**
         * The date on which the actual <b>PhysicalPart</b> was installed on its parent <b>PhysicalPart</b>.
         */
        Teamcenter::Soa::Common::DateTime installationDate;
        /**
         * The date on which the <b>PhysicalPart</b> was manufactured.
         */
        Teamcenter::Soa::Common::DateTime manufacturingDate;
        /**
         * If <b>SerialNumberGenerators</b> are to be used to generate the Serial Numbers for
         * the <b>PhysicalPart</b> objects.
         */
        bool useSerialNumberGenerators;
        /**
         * An integer which indicates the depth of the design <b>Item</b> structure to be traversed
         * for generating the as-built <b>PhysicalPart</b> structure.
         */
        int numberOfLevels;
        /**
         * The structure, which can hold any additional properties and values.
         */
        Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::ExtendedAttributes extendedData;
    };

    /**
     * Structure represents the parameters required to generate an as-built <b>PhysicalPart</b>
     * structure for a given design Item structure.
     */
    struct GenerateAsBuiltStructInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object, which holds all the properties from the <b>PartLogisticsForm</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::NeutralBOMLine>  neutralBOMLine;
        /**
         * The information required to generate an as-built <b>PhysicalPart</b> structure.
         */
        Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::AsBuiltStructureInfo asBuiltStructureInfo;
    };

    /**
     * Structure represents the output parameters of the generateAsBuiltStructure operation.
     */
    struct GenerateAsBuiltStructureOutput
    {
        /**
         * The <code>clientId</code> from the input GenerateAsBuiltStructInput element. This
         * value is unchanged from the input, and can be used to identify this response element
         * with the corresponding input element.
         */
        std::string clientId;
        /**
         * The top level object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  physicalPartRevision;
    };

    /**
     * Structures containing the created top level <b>PhysicalPart</b> object and the <code>ServiceData</code>.
     */
    struct GenerateAsBuiltStructureResponse
    {
        /**
         * Created <b>PhysicalPart</b> object.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::GenerateAsBuiltStructureOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to install an as-built <b>PhysicalPartRevision</b>
     * under a parent.
     */
    struct InstallPhysicalPartInfo
    {
        /**
         * A String which holds the name of the Usage. E.g. occurrence name.
         */
        std::string usageName;
        /**
         * The Installation Date which will be set on the <b>AsBuiltStructure</b> relation object.
         */
        Teamcenter::Soa::Common::DateTime installationDate;
        /**
         * An AttributeNameValueMap object, used to pass additional information.
         */
        AttributeNameValueMap attributes;
    };

    /**
     * Structure represents the output parameters of the install as-built <b>PhysicalPart</b>
     * operation.
     */
    struct InstallPhysicalPartOutput
    {
        /**
         * The <code>clientId</code> from the input InstallPhysicalPrtInput element. This value
         * is unchanged from the input, and can be used to identify this response element with
         * the corresponding input element.
         */
        std::string clientId;
        /**
         * The relation object created as a result of the installation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltStructure>  relation;
        /**
         * An object created to represent the installed <b>PhysicalPartRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  installedLine;
    };

    /**
     * Structure contains the relation created and the <code>ServiceData</code>.
     */
    struct InstallPhysicalPartResponse
    {
        /**
         * The Service Data.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::InstallPhysicalPartOutput > output;
        /**
         * Service Data contains Allowed Deviation as createdObjects along with any errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to install an as-built <b>PhysicalPart</b>
     * revision under a parent.
     */
    struct InstallPhysicalPrtInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The parent  object, under which the <b>PhysicalPartRevision</b> object will be installed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  parentAsBuiltBOMLineImpl;
        /**
         * The child object which will be installed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  childPhysicalPartRevisionImpl;
        /**
         * A install information like install date.
         */
        Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::InstallPhysicalPartInfo installInfo;
        /**
         * A String which specifies the Usage e.g. Extra to Design.
         */
        std::string usageType;
        /**
         * The object used to identify the occurrence object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  selectedBOMLineImpl;
    };

    /**
     * Structure represents the output parameters of the operation.
     */
    struct RemovedLineOutput
    {
        /**
         * The <code>clientId</code> from the input RemoveLineInput element. This value is unchanged
         * from the input, and can be used to identify this response element with the corresponding
         * input element.
         */
        std::string clientId;
        /**
         * The new object created in place of the uninstalled <b>AsBuiltBOMLine</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  replacerLine;
    };

    /**
     * Structure represents the parameters required to uninstall an as-built <b>PhysicalPartRevision</b>
     * object from the structure.
     */
    struct RemoveLineInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object to be removed from the structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  asbuiltBOMLine;
    };

    /**
     * Structure represents a list of replacer line and the <code>ServiceData</code>.
     */
    struct UnInstallPhysicalPartResponse
    {
        /**
         * A list of replacer  line.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::RemovedLineOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation generates an as-built <b>PhysicalPart</b> structure for a given design
     * <b>Item</b> structure. The design structure should be first set in an <b>MroBOMWindow</b>
     * object so that <b>NeutralBOMLine</b> objects are constructed for every <b>Item</b>
     * in the structure. An as-built <b>PhysicalPart</b> is created for every <b>Item</b>
     * in the structure which is marked as <i>Traceable</i> (This value is set on the <b>PartLogisticsForm</b>
     * associated with the <b>Item</b>). All the parent/child as-built <b>PhysicalPart</b>
     * objects are related to each other by <b>AsBuiltStructure</b> relation. A <b>StructureContext</b>
     * object is created with the configuration applied to the <b>MroBOMWindow</b> and saved
     * on the top <b>PhysicalPart</b>.
     * <br>
     * <br>
     * One can specify the following parameters on the <b>PartLogisticsForm</b>.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Traceable&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, a <b>PhysicalPart</b> will be created for the Item.
     * </li>
     * <li type="disc">Serialized&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, the created <b>PhysicalPart</b> will be marked Serialized.
     * </li>
     * <li type="disc">Lot&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, the created <b>PhysicalPart</b> will be marked as Lot.
     * </li>
     * <li type="disc">Preserve Quantity&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, only one <b>PhysicalPart</b> will be created irrespective of the Quantity
     * specified on the design <b>Item</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * An as-built <b>PhysicalPart</b> structure is a precise structure. The parent and
     * child relation, the <b>AsBuiltStructure</b> relation, is between the revisions of
     * the parent and child.
     * <br>
     * <br>
     * In a <b>PhysicalPart</b> structure, if the parts are serialized and all the required
     * information like Serial Number, Lot Number(in case of Lot parts), Manufacturer's
     * id are specified, then the <b>PhysicalPart</b> object's usage is set as <i>Preferred</i>.
     * The parts which are not marked as Serialized or Lot, the default value is set to
     * <i>Preferred</i>. For the serialized or lot parts, if the Serial or Lot Number is
     * not specified, those parts are set as <i>Missing</i>. Once the required information
     * is provided, the usage is changed to <i>Preferred</i>.
     * <br>
     * <br>
     * A Business object constant defined for the Item class governs the type of <b>PhysicalPart</b>
     * object to be created during the structure generation. By default the value it set
     * to <i>PhysicalPart</i>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createMROBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        Structures which holds the required information to generate an as-built <b>PhysicalPart</b>
     *        structure for a design <b>Item</b> structure.
     *
     * @return
     *         The created top <b>PhysicalPart</b> object is returned in the created objects list
     *         of the <code>ServiceData</code>. Any failure will be returned with <code>clientId</code>
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *         Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">237003 &nbsp;&nbsp;&nbsp;&nbsp;If  Installation Date is earlier than
     *         the Manufacturing Date of the PhysicalPart.
     *         </li>
     *         <li type="disc">237008 &nbsp;&nbsp;&nbsp;&nbsp;If the Serial Number Generator could
     *         not generate a new number as it is already reached its upper limit of number generation.
     *         </li>
     *         <li type="disc">237030 &nbsp;&nbsp;&nbsp;&nbsp;If Serial Number generator(s) is not
     *         defined for the Item object.
     *         </li>
     *         <li type="disc">237031&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the <b>Lot</b>
     *         size of the specified <b>Lot</b> is already exhausted.
     *         </li>
     *         <li type="disc">237032 &nbsp;&nbsp;&nbsp;&nbsp;If the Lot does not exist in the system.
     *         </li>
     *         <li type="disc">237069 &nbsp;&nbsp;&nbsp;&nbsp;If the specified Lot has already passed
     *         its expiry date.
     *         </li>
     *         <li type="disc">237086&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the Manufacturing
     *         Date or the Installation date of the <b>PhysicalPart</b> is specified as future date.
     *         </li>
     *         <li type="disc">238001&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the <b>Item</b>
     *         is not a valid MRO neutral item. This error is thrown if the Business Object Constant
     *         <i>"IsMRONeutralType</i>" is not set to "true" for the <b>Item</b> class in BMIDE.
     *         </li>
     *         <li type="disc">238002 &nbsp;&nbsp;&nbsp;&nbsp;If the <b>Item</b> is marked as Traceable.
     *         The values like Traceable, Serialized etc. are specified on the <b>PartLogisticsForm</b>
     *         related to the <b>Item</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::GenerateAsBuiltStructureResponse generateAsBuiltStructure ( const std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::GenerateAsBuiltStructInput >& input ) = 0;

    /**
     * This operation installs a <b>PhysicalPart</b> object under a parent object in a given
     * position. In the as-built structure, the relations are precise. Hence a revision
     * of the child <b>PhysicalPart</b> object will be installed under a revision of the
     * parent <b>PhysicalPart</b> object. An object of <b>AsBuiltStructure</b> will be created
     * between the two objects.
     * <br>
     * Based on the specified position, the usage will be determined by the code. Following
     * values are possible.
     * <br>
     * <ul>
     * <li type="disc">Preferred&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is a part of the configured design <b>Item</b>
     * structure for the parent part.
     * </li>
     * <li type="disc">Alternate&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is an <i>Alternate</i> of the <b>Item</b> configured
     * in the design <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">Substitute&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is a Substitute of the <b>Item</b> configured
     * in the design <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">Deviated&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  If the
     * design <b>Item</b> of the child part is not a part of the Item configured in the
     * design Item structure for the parent part. A Valid deviation should be already set
     * up between the parent and the child parts.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param installPhysicalPrtInput
     *        Structures which hold the required information to install an as-built <b>PhysicalPart</b>
     *        under a parent.
     *
     * @return
     *         The <b>AsBuiltBOMLine</b> object created for the installed <b>PhysicalPartRevision</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with <code>clientId</code> mapped to error message in the
     *         <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the ServiceData.
     *         <br>
     *         <ul>
     *         <li type="disc">237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation Date is earlier
     *         than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">237028&nbsp;&nbsp;&nbsp;&nbsp;    If the Deviation Authority is not
     *         released. Without an approved/released deviation authority, a deviated part cannot
     *         be installed.
     *         </li>
     *         <li type="disc">237042 &nbsp;&nbsp;&nbsp;&nbsp;An as-built PhysicalPartRevision object
     *         cannot be installed under an as-built <b>PhysicalPartRevision</b> object whose usage
     *         is set as Missing.
     *         </li>
     *         <li type="disc">237043&nbsp;&nbsp;&nbsp;&nbsp;    If the parent <b>PhysicalPartRevision</b>
     *         object is released.
     *         </li>
     *         <li type="disc">237052&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">237058&nbsp;&nbsp;&nbsp;&nbsp;    If the Installation Date specified
     *         is earlier than the Effective From date on the <b>PhysicalPartRevision</b> object.
     *         </li>
     *         <li type="disc">238006&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPart</b> object
     *         to be installed is marked as Serialized, then the Serial Number property on that
     *         object cannot be empty.
     *         </li>
     *         <li type="disc">238008&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPart</b> object
     *         to be installed is marked as Serialized and Lot, then the Serial Number and Lot Number
     *         properties on that object cannot be empty.
     *         </li>
     *         <li type="disc">238015&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPartRevision</b>
     *         parent object is not an as-built revision.
     *         </li>
     *         <li type="disc">238016&nbsp;&nbsp;&nbsp;&nbsp;    If the <b>PhysicalPartRevision</b>
     *         object to be installed is not an as-built revision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::InstallPhysicalPartResponse installPhysicalPart ( const std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::InstallPhysicalPrtInput >& installPhysicalPrtInput ) = 0;

    /**
     * This operation uninstalls an as-built <b>PhysicalPartRevision</b> object from a structure.
     * When an as-built object is uninstalled from a structure, a new <b>PhysicalPartRevision</b>
     * object is created in the structure in that position. A new <b>AsBuiltBOMLine</b>
     * object is constructed to represent that new part. The usage of the new part is set
     * to <i>Missing</i> as there is no actual part in that position (If the uninstalled
     * part is Extra to Design, the <i>Missing</i> part is not created). An object of <b>AsBuiltStructure</b>
     * relation is created between the new part and the parent part.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param removePhPartInput
     *        Structures which holds the required information to un-install an as-built <b>PhysicalPartRevision</b>
     *        from a structure.
     *
     * @return
     *         The created <b>AsBuiltBOMLine</b> object is returned in the created objects list
     *         of the <code>ServiceData</code>. Any failure will be returned with client id mapped
     *         to error message in the <code>ServiceData</code> list of partial errors.  Following
     *         error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">237043    If the parent <b>PhysicalPartRevision</b> object is released.
     *         </li>
     *         <li type="disc">237052    If the <b>PhysicalPartRevision</b> object is not the latest
     *         revision.
     *         </li>
     *         <li type="disc">238009    If the action attempts to remove a <b>PhysicalPartRevision</b>
     *         for which the usage is set to <i>Missing</i>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::UnInstallPhysicalPartResponse unInstallPhysicalPart ( const std::vector< Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::RemoveLineInput >& removePhPartInput ) = 0;


protected:
    virtual ~Asbuilt() {}
};
            }
        }
    }
}

#include <teamcenter/services/asbuilt/AsBuilt_undef.h>
#endif

