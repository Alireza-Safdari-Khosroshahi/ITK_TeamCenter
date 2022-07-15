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

#ifndef TEAMCENTER_SERVICES_ASMAINTAINED__2009_06_ASMAINTAINED_HXX
#define TEAMCENTER_SERVICES_ASMAINTAINED__2009_06_ASMAINTAINED_HXX

#include <teamcenter/soa/client/model/AsMaintainedBOMLine.hxx>
#include <teamcenter/soa/client/model/DispositionApplicability.hxx>
#include <teamcenter/soa/client/model/DispositionType.hxx>
#include <teamcenter/soa/client/model/MroRevisionRule.hxx>
#include <teamcenter/soa/client/model/NeutralBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalLocation.hxx>
#include <teamcenter/soa/client/model/PhysicalLocationUsage.hxx>
#include <teamcenter/soa/client/model/PhysicalPart.hxx>
#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/asmaintained/AsMaintained_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asmaintained
        {
            namespace _2009_06
            {
                class Asmaintained;

class TCSOAASMAINTAINEDSTRONGMNGD_API Asmaintained
{
public:

    struct ApplyMroRevisionRuleInfo;
    struct ApplyMroRevisionRuleInputInfo;
    struct ApplyMroRevisionRuleOutput;
    struct ApplyMroRevisionRuleResponse;
    struct AsMaintainedStructureInfo;
    struct ChangeDispositionInfo;
    struct ChangeDispositionOutput;
    struct ChangeDispositionResponse;
    struct ExtendedAttributes;
    struct GenerateAsMaintainedStructureInfo;
    struct GenerateAsMaintainedStructureOutput;
    struct GenerateAsMaintainedStructureResponse;
    struct InstallAsmPhysicalPartInfo;
    struct InstallAsmPhysicalPartInputInfo;
    struct InstallAsmPhysicalPartOutput;
    struct InstallAsmPhysicalPartResponse;
    struct MovePhysicalPartInfo;
    struct MovePhysicalPartOutput;
    struct MovePhysicalPartResponse;
    struct ReplaceAsMaintainedPartInfo;
    struct ReplaceAsMaintainedPartInputInfo;
    struct ReplacePhysicalPartOutput;
    struct ReplacePhysicalPartResponse;
    struct UninstallPhysicalPartInfo;
    struct UninstallPhysicalPartInputInfo;
    struct UninstallPhysicalPartOutput;
    struct UninstallPhysicalPartResponse;

    /**
     * Attribute Name Value Map
     */
    typedef std::map< std::string, std::string > AttributeNameValueMap;

    /**
     * Structure represents the parameters of the <b>MRORevisionRule</b>.
     */
    struct ApplyMroRevisionRuleInfo
    {
        /**
         * The <code>clientId</code> from the input <code>ApplyMroRevisionRuleInfo</code> element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * If true, the As-Maintained structure is to be configured for today's date.
         */
        bool today;
        /**
         * If true, only the <i>Serviceable</i> objects are to be configured.
         */
        bool serviceable;
        /**
         * A Boolean which indicates the status required to create the Mro Revision rule.
         */
        bool any;
        /**
         * The date used to configure the exact <b>PhysicalPartRevision</b> objects. If "today"
         * flag is selected, this field value will not be considered.
         */
        Teamcenter::Soa::Common::DateTime effectiveDate;
    };

    /**
     * Structure represents the parameters required to apply MRO Revision rule to an as-maintained
     * <b>PhysicalPart</b> structure.
     */
    struct ApplyMroRevisionRuleInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The top <b>AsMaintainedBOMLine</b> object set in the <b>MroBOMWindow</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  topLine;
        /**
         * The <b>MroRevisionRule</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MroRevisionRule>  mroRevRule;
        /**
         * The structure containing information about the <b>MroRevisionRule</b> object.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ApplyMroRevisionRuleInfo applyMroRevisionRuleInfo;
    };

    /**
     * Structure contains the configured <b>AsMaintainedBOMLine</b> object.
     */
    struct ApplyMroRevisionRuleOutput
    {
        /**
         * The <code>clientId</code> from the input <code>ApplyMroRevisionRuleInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The configured top line object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  configuredTopLine;
    };

    /**
     * Structure contains the configured top level <b>AsMaintainedBOMLine</b> object and
     * the <code>ServiceData</code>.
     */
    struct ApplyMroRevisionRuleResponse
    {
        /**
         * Structure containing the configured top line.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ApplyMroRevisionRuleOutput > applyMroRevRuleOutput;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to generate an as-maintained <b>PhysicalPart</b>
     * structure for a given design <b>Item</b> structure.
     */
    struct AsMaintainedStructureInfo
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
         * An integer which indicates the depth of the design <b>Item</b> structure to be traversed
         * for generating the as-maintained <b>PhysicalPart</b> structure.
         */
        int numberOfLevels;
        /**
         * A Boolean to indicate if Serial Number generators are to be used to generate the
         * Serial Numbers for the <b>PhysicalParts</b>.
         */
        bool useSerialNumberGenerators;
        /**
         * Name of the Structure Context object. Structure context object is created with the
         * current configuration of the <b>MroBOMWindow</b> and saved on the top <b>PhysicalPart</b>.
         */
        std::string structureContext;
        /**
         * The name of the <b>PhysicalLocation</b> object.
         */
        std::string locationName;
        /**
         * The date on which the actual <b>PhysicalPart</b> was installed on its parent <b>PhysicalPart</b>.
         */
        Teamcenter::Soa::Common::DateTime installationDate;
        /**
         * The date on which the <b>PhysicalPart</b> was manufactured.
         */
        Teamcenter::Soa::Common::DateTime manufacturingDate;
        /**
         * The disposition type to be applied to the <b>PhysicalPart</b> objects.
         */
        std::string dispositionType;
        /**
         * The Date from which the <b>PhysicalPartRevision</b> object is effective.
         */
        Teamcenter::Soa::Common::DateTime effectiveFromDate;
        /**
         * The Date up to which the <b>PhysicalPartRevision</b> object is effective.
         */
        Teamcenter::Soa::Common::DateTime effectiveToDate;
    };

    /**
     * Represents the parameters required to change the disposition of an as-maintained
     * <b>PhysicalPart</b> object.
     */
    struct ChangeDispositionInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The <b>PhysicalPart</b> object, whose disposition is to be changed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPart>  physicalPart;
        /**
         * The <b>DispositionType</b> object which is the new disposition value.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::DispositionType>  dispositionType;
        /**
         * The start time of the new disposition.
         */
        Teamcenter::Soa::Common::DateTime dispStartTime;
    };

    /**
     * The output parameters of the Change Disposition operation.
     */
    struct ChangeDispositionOutput
    {
        /**
         * The <code>clientId</code> from the input <code>ChangeDispositionInfo</code> element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The relation object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::DispositionApplicability>  dispRelation;
    };

    /**
     * <b>DispositionApplicability</b> relation object and the <code>ServiceData</code>.
     */
    struct ChangeDispositionResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * <b>DispositionApplicability</b> relation object.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ChangeDispositionOutput > output;
    };

    /**
     * Structure represents the structure containing additional attributes.
     */
    struct ExtendedAttributes
    {
        /**
         * Object Type
         */
        std::string objectType;
        /**
         * Attributes
         */
        AttributeNameValueMap attributes;
    };

    /**
     * Represents the parameters required to generate an as-maintained <b>PhysicalPart</b>
     * structure for a given design <b>Item</b> structure.
     */
    struct GenerateAsMaintainedStructureInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The line object which holds all the properties from the <b>PartLogisticsForm</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::NeutralBOMLine>  neutralBOMLine;
        /**
         * The structure holding all the information required to generate an as-maintained <b>PhysicalPart</b>
         * structure.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::AsMaintainedStructureInfo asMaintainedStructureInfo;
    };

    /**
     * Structure represents the output parameters of the generateAsMaintainedStructure operation.
     */
    struct GenerateAsMaintainedStructureOutput
    {
        /**
         * The <code>clientId</code> from the output <code>GenerateAsMaintainedStructureInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The top level object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  physicalPartRevision;
    };

    /**
     * Structure contains the created top level <b>PhysicalPart</b> object and the <code>ServiceData</code>.
     */
    struct GenerateAsMaintainedStructureResponse
    {
        /**
         * Created top level <b>PhysicalPart</b> object.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::GenerateAsMaintainedStructureOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The parameters required to install an as-maintained <b>PhysicalPart</b> under a parent.
     */
    struct InstallAsmPhysicalPartInfo
    {
        /**
         * Usage Property Value
         */
        std::string usagePropertyValue;
        /**
         * The Installation Date which will be set on the <b>AsMaintainedStructure</b> relation
         * object.
         */
        Teamcenter::Soa::Common::DateTime installationDate;
        /**
         * An AttributeNameValueMap object, used to pass additional information.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ExtendedAttributes extendedData;
    };

    /**
     * The parameters required to install an as-maintained <b>PhysicalPart</b> under a parent.
     */
    struct InstallAsmPhysicalPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The parent  line object, under which the <b>PhysicalPart</b> object will be installed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  selectedLine;
        /**
         * The object which will be installed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPart>  copiedPhysPart;
        /**
         * The line object corresponding to the selected usage.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::NeutralBOMLine>  selectedUsageLine;
        /**
         * A structure containing the install information like install date.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::InstallAsmPhysicalPartInfo installInfo;
    };

    /**
     * Structure represents the output parameters of the Install as-maintained <b>PhysicalPart</b>
     * operation.
     */
    struct InstallAsmPhysicalPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>InstallAsmPhysicalPartInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The line object created to represent the installed <b>PhysicalPartRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  installedLine;
    };

    /**
     * Structure contains the new <b>AsMaintainedBOMLine</b> and the <code>ServiceData</code>.
     */
    struct InstallAsmPhysicalPartResponse
    {
        /**
         * A list of newly created <b>AsMaintainedBOMLine</b>.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::InstallAsmPhysicalPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to move the <b>PhysicalPart</b> .
     */
    struct MovePhysicalPartInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The  object to move into location.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPart>  physicalPart;
        /**
         * The location object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalLocation>  location;
        /**
         * The installation time.
         */
        Teamcenter::Soa::Common::DateTime inTime;
    };

    /**
     * Structure represents the output parameters of the move <b>PhysicalPart</b> operation.
     */
    struct MovePhysicalPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>MovePhysicalPartInfo</code> element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The location usage object created to represent the moved  <b>PhysicalPart</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalLocationUsage>  relation;
    };

    /**
     * Structure represents a list of <b>PhysicalLocationUsage</b> relation and the <code>ServiceData</code>.
     */
    struct MovePhysicalPartResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A list of <b>PhysicalLocationUsage</b> relation.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::MovePhysicalPartOutput > output;
    };

    /**
     * Structure represents the parameters required to replace an as-maintained <b>PhysicalPart</b>.
     */
    struct ReplaceAsMaintainedPartInfo
    {
        /**
         * Disposition value.
         */
        std::string dispositionValue;
        /**
         * Location name.
         */
        std::string locationName;
        /**
         * The date at which the <b>PhysicalPart</b> object which is replaced.
         */
        Teamcenter::Soa::Common::DateTime replaceDate;
        /**
         * An AttributeNameValueMap object, used to pass additional information.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ExtendedAttributes extendedData;
    };

    /**
     * Structure represents the parameters required to replace an as-maintained <b>PhysicalPart</b>.
     */
    struct ReplaceAsMaintainedPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The line object, line which will be replaced.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  selectedAsMaintainedBOMLine;
        /**
         * The object which will be replaced.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPart>  copiedPhysPart;
        /**
         * A structure containing the information to replace the part like replace date.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ReplaceAsMaintainedPartInfo replacePhysicalPartInfo;
    };

    /**
     * Structure represents the output parameters of the replace as-maintained <b>PhysicalPart</b>
     * operation.
     */
    struct ReplacePhysicalPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>ReplaceAsMaintainedPartInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The line object, created to represent the replaced <b>PhysicalPartRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  replacerAsMaintainedBOMLine;
    };

    /**
     * Structure containing the replace <b>AsMaintainedBOMLine</b> and the <code>ServiceData</code>.
     */
    struct ReplacePhysicalPartResponse
    {
        /**
         * A structure containing the replaced <b>AsMaintainedBOMLine</b>.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ReplacePhysicalPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure containing the information to uninstall the <b>PhysicalPart</b>.
     */
    struct UninstallPhysicalPartInfo
    {
        /**
         * Disposition value.
         */
        std::string dispositionValue;
        /**
         * Location name.
         */
        std::string locationName;
        /**
         * The date at which the <b>PhysicalPart</b> object which is uninstalled.
         */
        Teamcenter::Soa::Common::DateTime uninstallationDate;
        /**
         * An AttributeNameValueMap object, used to pass additional information.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ExtendedAttributes extendedData;
    };

    /**
     * The parameters required to uninstall an as-maintained <b>PhysicalPartRevision</b>
     * object from the structure.
     */
    struct UninstallPhysicalPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The line object to be removed from the structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  selectedAsMaintainedBOMLine;
        /**
         * The structure containing the information to uninstall the <b>PhysicalPart</b>.
         */
        Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::UninstallPhysicalPartInfo uninstallPhysicalPartInfo;
    };

    /**
     * Structure represents the output parameters of the replace as-maintained <b>PhysicalPart</b>
     * operation.
     */
    struct UninstallPhysicalPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>UninstallPhysicalPartInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The created object to represent the replaced <b>PhysicalPartRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsMaintainedBOMLine>  replacerAsMaintainedBOMLine;
    };

    /**
     * Structure containing the un installed <b>BOMLine</b> and the <code>ServiceData</code>.
     */
    struct UninstallPhysicalPartResponse
    {
        /**
         * A un-installed <b>BOMLine</b>.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::UninstallPhysicalPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation applies the revision rule specific to as-maintained structure configuration.
     * As-Maintained structures can be configured only by Date and Serviceability.
     * <br>
     * The <b>PhysicalPartRevision</b> objects have "<i>Effective From</i>" and "<i>Effective
     * To</i>" dates. If the date applied on the <b>MroBOMWindow</b> object falls in-between
     * those two dates then that revision is considered to be effective. This filter is
     * applied on the entire as-maintained structure. Once an <b>MRORevisionRule</b> is
     * applied or changed, the entire structure is updated to show the updated configuration.
     * <br>
     * Serviceability indicates whether a <b>PhysicalPart</b> object is in its useful life.
     * By default, all the Serviceable parts are configured.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        Apply MRO Revision Rule Input
     *
     * @return
     *         The top <b>AsMaintainedBOMLine</b> object which is configured as a result of application
     *         of the <b>MRORevisionrule</b> is returned in the created objects list of the <code>ServiceData</code>.
     *         Any failure will be returned with <code>clientId</code> mapped to error message in
     *         the <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242011&nbsp;&nbsp;&nbsp;&nbsp;If the <b>MRORevisionRule</b>
     *         object is not applied on the <b>MroBOMWindow</b> object
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ApplyMroRevisionRuleResponse applyMroRevisionRule ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ApplyMroRevisionRuleInputInfo >& inputData ) = 0;

    /**
     * This operation changes the disposition of an as-maintained <b>PhysicalPart</b> object.
     * When a <b>PhysicalPart</b> object is created, a default disposition <i>In-Service</i>
     * is created. It can be changed to any user specified value later on.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        The required information to change the disposition of an as-maintained <b>PhysicalPart</b>
     *        object.
     *
     * @return
     *         The <b>DispositionApplicability</b>  relation along with the <code>ServiceData</code>
     *         is returned. Any failure will be returned with <code>clientId</code> mapped to error
     *         message in the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ChangeDispositionResponse changePhysicalPartDisposition ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ChangeDispositionInfo >& input ) = 0;

    /**
     * This operation generates an as-maintained <b>PhysicalPart</b> structure for a given
     * design <b>Item</b> structure. The design structure should be first set in an <b>MroBOMWindow</b>
     * object so that <b>NeutralBOMLine</b> objects are constructed for every <b>Item</b>
     * in the structure. An as-maintained <b>PhysicalPart</b> is created for every <b>Item</b>
     * in the structure which is marked as Traceable (This value is set on the <b>PartLogisticsForm</b>
     * associated with the <b>Item</b>). All the parent/child as-maintained <b>PhysicalPart</b>
     * objects are related to each other by <b>AsMaintainedStructure</b> relation. A <b>StructureContext</b>
     * object is created with the configuration applied to the <b>MroBOMWindow</b> and saved
     * on the top <b>PhysicalPart</b> objects.
     * <br>
     * One can specify the following parameters on the <b>PartLogisticsForm</b>.
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Traceable&nbsp;&nbsp;&nbsp;&nbsp;If marked
     * true, a <b>PhysicalPart</b> will be created for the <b>Item</b>.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Serialized&nbsp;&nbsp;&nbsp;&nbsp;If marked
     * true, the created <b>PhysicalPart</b> will be marked as serialized.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Lot&nbsp;&nbsp;&nbsp;&nbsp;If marked true,
     * the created <b>PhysicalPart</b> will be marked as lot.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Preserve Quantity&nbsp;&nbsp;&nbsp;&nbsp;If
     * marked true, only one <b>PhysicalPart</b> will be created irrespective of the quantity
     * specified on the design <b>Item</b>.
     * </li>
     * </ul>
     * <br>
     * <br>
     * An as-maintained <b>PhysicalPart</b> structure is an imprecise structure. The parent
     * and child relation, the <b>AsMaintainedStructure</b> relation, is between the revision
     * of the parent and the item of the child.
     * <br>
     * In a <b>PhysicalPart</b> structure, if the parts are serialized and all the required
     * information like<i> Serial Number, Lot Number</i>(in case of Lot parts), <i>Manufacturer's
     * id</i> are specified, then the <b>PhysicalPart</b> object's usage is set as <i>Preferred</i>.
     * The parts which are not marked as <i>Serialized</i> or <i>Lot</i>, the default value
     * is set to <i>Preferred</i>. For the serialized or lot parts, if the <i>Serial Number
     * or Lot Number</i> is not specified, those parts are set as <i>Missing</i>. Once the
     * required information is provided, the usage is changed to Preferred.
     * <br>
     * A Business object constant defined for the Item class governs the type of <b>PhysicalPart</b>
     * object to be created during the structure generation. By default the value it set
     * to <b>PhysicalPart</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        Holds the required information to generate an as-maintained <b>PhysicalPart</b> structure
     *        for a design <b>Item</b> structure.
     *
     * @return
     *         Generated <b>PhysicalPart</b> object along with the <code>ServiceData</code> are
     *         returned. The created top <b>PhysicalPart</b> object is returned in the created objects
     *         list of the <code>ServiceData</code>. Any failure will be returned with client id
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *         Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237008 &nbsp;&nbsp;&nbsp;&nbsp;If the <b>SerialNumberGenerator</b>
     *         object could not generate a new number as it already has reached its upper limit
     *         of number generation.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237030 &nbsp;&nbsp;&nbsp;&nbsp;If SerialNumberGenerator(s)
     *         is not defined for the <b>Item</b> object.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237031&nbsp;&nbsp;&nbsp;&nbsp;If the Lot
     *         size of the specified Lot is already exhausted.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237032 &nbsp;&nbsp;&nbsp;&nbsp;If the Lot
     *         does not exist in the system.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237069 &nbsp;&nbsp;&nbsp;&nbsp;If the specified
     *         Lot has already passed its expiry date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237086&nbsp;&nbsp;&nbsp;&nbsp;If the Manufacturing
     *         Date or the Installation date of the <b>PhysicalPart</b> is specified as future date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242023&nbsp;&nbsp;&nbsp;&nbsp;If a <b>PhysicalLocation</b>
     *         object for the specified location name is not found.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::GenerateAsMaintainedStructureResponse generateAsMaintainedStructure ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::GenerateAsMaintainedStructureInfo >& input ) = 0;

    /**
     * This operation installs a <b>PhysicalPart</b> object under a parent object in a given
     * position. In the as-maintained structure, the relations are imprecise. Hence the
     * child <b>PhysicalPart</b> object will be installed under the parent <b>PhysicalPartRevision</b>
     * object. An object of <b>AsMaintainedStructure</b> will be created between the two
     * objects.
     * <br>
     * Based on the specified position, the usage will be determined by the code. Following
     * values are possible.
     * <br>
     * <ul>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Preferred&nbsp;&nbsp;&nbsp;&nbsp;If the design
     * <b>Item</b> of the child part is a part of the configured design <b>Item</b> structure
     * for the parent part.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Alternate&nbsp;&nbsp;&nbsp;&nbsp;If the design
     * Item of the child part is an Alternate of the <b>Item</b> configured in the design
     * <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Substitute&nbsp;&nbsp;&nbsp;&nbsp;If the
     * design <b>Item</b> of the child part is a Substitute of the <b>Item</b> configured
     * in the design <b>Item</b> structure for the parent part.
     * </li>
     * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Deviated&nbsp;&nbsp;&nbsp;&nbsp;If the design
     * <b>Item</b> of the child part is not a part of the <b>Item</b> configured in the
     * design <b>Item</b> structure for the parent part. A Valid deviation should be already
     * set up between the parent and the child parts.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        Holds the required information to install an as-maintained <b>PhysicalPart</b> under
     *        a parent.
     *
     * @return
     *         The <b>AsMaintainedBOMLine</b> object created for the installed <b>PhysicalPart</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with <code>clientId</code> mapped to error message in the
     *         <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237028&nbsp;&nbsp;&nbsp;&nbsp;If the Deviation
     *         Authority is not released. Without an approved/released deviation authority, a deviated
     *         part cannot be installed.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237049
     *         This error occurs when the <b>PhysicalPart</b> is getting installed as deviated,
     *         but the valid deviation is not setup.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051
     *         This error occurs when the <b>PhysicalPart</b> is not uniquely identified in
     *         the system. This check is done for the serialized <b>PhysicalPart</b>. The Part number,
     *         serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237052&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the Physical Structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237058&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if Installation Date is less than effective from date of <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242007&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242022&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPart</b> is already installed and cannot be moved.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242028&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::InstallAsmPhysicalPartResponse installAsmPhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::InstallAsmPhysicalPartInputInfo >& inputData ) = 0;

    /**
     * This operation moves the <b>PhysicalPart</b> to specified location.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        A list of structures which hold the required information to move the <b>PhysicalPart</b>
     *        from one location to another.
     *
     * @return
     *         The <b>PhysicalLocationUsage</b> object created for the moved <b>PhysicalPart</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with <code>clientId</code> mapped to error message in the
     *         <code>ServiceData</code> list of partial errors.  Following error codes are returned
     *         in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051   This error occurs when the <b>PhysicalPart</b>
     *         is not uniquely identified in the system. This check is done for the serialized <b>PhysicalPart</b>.
     *         The Part number, serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242021&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the installation date cannot be earlier than installation date of previous
     *         location.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242022&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> is installed. Installed <b>PhysicalPart</b> cannot
     *         be moved to location using this operation.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242034&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> movement date is future date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242030&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> is already in that location.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242034&nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::MovePhysicalPartResponse movePhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::MovePhysicalPartInfo >& input ) = 0;

    /**
     * This operation replaces an as-maintained <b>PhysicalPart</b> in a structure with
     * a given as-maintained <b>PhysicalPart</b> object.  The existing as-maintained <b>PhysicalPart</b>
     * object will be removed from the structure and the new object will be installed in
     * that position. A new <b>AsMaintainedStructure</b> relation will be created between
     * the parent and the new <b>PhysicalPart</b> objects. The Installation Time specified
     * will be set as the Installation Time on the relation object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        A list of structures which hold the required information to replace the existing
     *        as-maintained <b>PhysicalPart</b> object in a structure with a new <b>PhysicalPart</b>
     *        object.
     *
     * @return
     *         The created <b>AsMaintainedBOMLine</b> object for the replacer <b>PhysicalPart</b>
     *         object is returned in the created objects list of the <code>ServiceData</code>. Any
     *         failure will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors. Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237003 &nbsp;&nbsp;&nbsp;&nbsp;If the Installation
     *         Date is earlier than the Manufacturing Date of the <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237028&nbsp;&nbsp;&nbsp;&nbsp;If the Deviation
     *         Authority is not released. Without an approved/released deviation authority, a deviated
     *         part cannot be installed.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237049  This error occurs when the <b>PhysicalPart</b>
     *         is getting installed as deviated, but the valid deviation is not setup.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051   This error occurs when the <b>PhysicalPart</b>
     *         is not uniquely identified in the system. This check is done for the serialized <b>PhysicalPart</b>.
     *         The Part number, serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237052&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237055&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the part to replace is top <b>PhysicalPart</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the physical structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237058&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if Installation Date is less than effective from date of PhysicalPartRevision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237073&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the replace date is less than effective from date of PhysicalPartRevision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242007&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242014&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the disposition value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242015&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the location value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242022&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPart</b> is already installed and cannot be moved.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242028&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the child <b>PhysicalPartRevision</b> is not as-maintained revision.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ReplacePhysicalPartResponse replaceAsmPhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::ReplaceAsMaintainedPartInputInfo >& inputData ) = 0;

    /**
     * This operation uninstalls an as-maintained <b>PhysicalPartRevision</b> object from
     * a structure. When an as-maintained object is uninstalled from a structure, if the
     * usage is not '<i>Extra to Design</i>' a new <b>PhysicalPartRevision</b> object is
     * created in the structure in that position. A new <b>AsMaintainedBOMLine</b> is constructed
     * to represent that new part. The usage of the new part is set to <i>Missing</i> as
     * there is no actual part in that position. An object of <b>AsMaintainedStructure</b>
     * relation is created between the new part and the parent part.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param inputData
     *        Holds the required information to un-install an as-maintained <b>PhysicalPartRevision</b>
     *        from a structure.
     *
     * @return
     *         The created <b>AMaintainedBOMLine</b> object is returned in the created objects list
     *         of the <code>ServiceData</code>. Any failure will be returned with client id mapped
     *         to error message in the <code>ServiceData</code> list of partial errors.  Following
     *         error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237051   This error occurs when the <b>PhysicalPart</b>
     *         is not uniquely identified in the system. This check is done for the serialized <b>PhysicalPart</b>.
     *         The Part number, serial number and Manufacturing id is compared to check the uniqueness.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237054&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the top line is selected to uninstall.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the physical structure in <b>BOMWindow</b> is not configured for today.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;237057&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if uninstall date is less that the effective from date of the <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242013&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the uninstall date is either a future date or not a valid date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242014&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the disposition value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242015&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the location value is not specified.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242016&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the <b>PhysicalPart</b> is already uninstalled.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;242020&nbsp;&nbsp;&nbsp;&nbsp;This error
     *         occurs if the uninstall date is less that the install date.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::UninstallPhysicalPartResponse uninstallPhysicalPart ( const std::vector< Teamcenter::Services::Asmaintained::_2009_06::Asmaintained::UninstallPhysicalPartInputInfo >& inputData ) = 0;


protected:
    virtual ~Asmaintained() {}
};
            }
        }
    }
}

#include <teamcenter/services/asmaintained/AsMaintained_undef.h>
#endif

