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

#ifndef TEAMCENTER_SERVICES_CAD__2007_06_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2007_06_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            namespace _2007_06
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct ClassicOptionInfo;
    struct CreateOrUpdateVariantCondInput;
    struct CreateUpdateClassicOptionsInput;
    struct DelClassicOptionsInput;
    struct DeleteVariantCondInput;
    struct GetConfiguredItemRevisionInfo;
    struct GetConfiguredItemRevisionOutput;
    struct GetConfiguredItemRevisionResponse;
    struct VariantCondInfo;

    /**
     * This enum contains comparison operator has 6 values - EQ, NEQ, LT, GT, GTEQ and LTEQ.
     */
    enum ComparisonOperator{ EQ,
                 NEQ,
                 LT,
                 GT,
                 GTEQ,
                 LTEQ
                 };

    /**
     * Operation
     */
    enum Operation{ Create,
                 Update
                 };

    /**
     * This is an enum for operations on variant option, has values <code>CreateOption</code>
     * ,<code>AddValue</code> ,<code>RemoveValue</code>  and <code>ReplaceValue</code>.
     */
    enum OptionOperation{ CreateOption,
                 AddValue,
                 RemoveValue,
                 ReplaceValue
                 };

    /**
     * VariantOperator
     */
    enum VariantOperator{ AND,
                 OR
                 };

    /**
     * Contains the information about classic variant option.
     */
    struct ClassicOptionInfo
    {
        /**
         * Refers to classic variant option name.
         */
        std::string optionName;
        /**
         * Refers to classic variant option description.
         */
        std::string optionDesc;
        /**
         * Refers to list of classic variant option values. This input is given for new or update
         * scenarios.
         */
        std::vector< std::string > values;
        /**
         * Refers to list of existing classic variant option values.
         */
        std::vector< std::string > existingValues;
    };

    /**
     * Contains the input for create/update variant condition associated with a <b>BOMLine</b>
     * object.
     */
    struct CreateOrUpdateVariantCondInput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * This indicates the operation type which can be create or update variant condition.
         */
        Operation operation;
        /**
         * Refers to <b>BOMLine</b> object on which variant condition has been defined.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Refers to a list of <code>VariantCondInfo</code> struct, and contains the information
         * needed to create/update a variant condition.
         */
        std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::VariantCondInfo > variantCondInfo;
    };

    /**
     * Contains the input for creating or updating classic variant options associated with
     * a <b>BOMLine</b> object.
     */
    struct CreateUpdateClassicOptionsInput
    {
        /**
         * Refers to clientId attribute.
         */
        std::string clientId;
        /**
         * Refers to operation type, as defined in <code>OptionOperation</code>. The operation
         * could be <code>CreateOption</code>, <code>AddValue</code>, <code>RemoveValue</code>
         * or <code>ReplaceValue</code>.
         */
        OptionOperation operation;
        /**
         * Refers to <b>BOMLine</b> object on which classic variant options are created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Refers to list of <code>ClassicOptionInfo</code> structure which needs to be updated.
         */
        std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::ClassicOptionInfo > options;
    };

    /**
     * Contains the input for deleting variant condition associated with a <b>BOMLine</b>
     * object.
     */
    struct DelClassicOptionsInput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * Refers to <b>BOMLine</b> object on which classic variant options are defined, which
         * needs to be deleted.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Refers to list of classic variant option names which are needs to be deleted.
         */
        std::vector< std::string > optionNames;
    };

    /**
     * This contains the input for deleting variant condition associated with a <b>BOMLine</b>
     * object.
     */
    struct DeleteVariantCondInput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * Refers to <b>BOMLine</b> object on which variant conditions are defined, which needs
         * to be deleted.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
    };

    /**
     * Contains the item/item revision object reference and revision rule object reference
     * to find the configured itemRevision.
     */
    struct GetConfiguredItemRevisionInfo
    {
        /**
         * object reference of the item / item revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Teamcenter::RevisionRuleImpl object reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  revRule;
    };

    /**
     * The response for the getConfiguredItemRevision operation.
     */
    struct GetConfiguredItemRevisionOutput
    {
        /**
         * Member of type GetConfiguredItemRevisionInfo, copy of input data
         */
        Teamcenter::Services::Cad::_2007_06::Structuremanagement::GetConfiguredItemRevisionInfo inputInfo;
        /**
         * ItemRevision object reference found
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  configuredItemRev;
    };

    /**
     * The response for the getConfiguredItemRevision call.
     */
    struct GetConfiguredItemRevisionResponse
    {
        /**
         * A List of type GetConfiguredItemRevisionOutput
         */
        std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::GetConfiguredItemRevisionOutput > output;
        /**
         * The SOA framework object containing plain objects and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains the information neede to create/update a variant condition.
     */
    struct VariantCondInfo
    {
        /**
         * optionName
         */
        std::string optionName;
        /**
         * joinOperator
         */
        VariantOperator joinOperator;
        /**
         * compOperator
         */
        ComparisonOperator compOperator;
        /**
         * value
         */
        std::string value;
    };




    /**
     * Finds the revision of the given item / item revision that is configured when the
     * given revision rule is used to configure the given item / item revision.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        A list of GetConfiguredItemRevisionInfo structures, each of which contain a item
     *        or item revision object and revision rule.
     *
     * @return
     *         contains a ServiceData and a list of GetConfiguredItemRevisionOutput, each of which
     *         contain the configured item revision and list of GetConfiguredItemRevisionInfo structures,
     *         each of which contain the input object and revision rule. Any failure will be returned
     *         via ServiceData with original input object mapped to error message.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_06::Structuremanagement::GetConfiguredItemRevisionResponse getConfiguredItemRevision ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::GetConfiguredItemRevisionInfo >& inputs ) = 0;

    /**
     * In the Create mode this operation creates a new option(s), with given option values,
     * and declares them against the given <b>ItemRevision</b> object. In the update mode
     * following operations can be performed with the given option
     * <br>
     * <ul>
     * <li type="disc">1.&nbsp;&nbsp;&nbsp;&nbsp;Replace the current text value for the
     * specified index with a new string from option revision.
     * </li>
     * <li type="disc">2.&nbsp;&nbsp;&nbsp;&nbsp;Add a new value to the option revision.
     * </li>
     * <li type="disc">3.&nbsp;&nbsp;&nbsp;&nbsp;Remove an existing value from the option
     * revision.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when user wants to create classic variant options for
     * a given <b>BOMLine</b> object(s). This also can be used to update an Option
     * <br>
     * <ul>
     * <li type="disc">a) adding a new value
     * </li>
     * <li type="disc">b) removing an existing value
     * </li>
     * <li type="disc">c) replace an existing value by new value.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        Refers to the list of CreateUpdateClassicOptionsInput struct, which are used to create
     *        a new variant option or update an existing variant option.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors  with serviceData with
     *         original input object(s) if any.
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module.
     *         </li>
     *         <li type="disc">215163 Option not valid.
     *         </li>
     *         <li type="disc">215162 Unable to find Item Revision.
     *         </li>
     *         <li type="disc">215160 Not a valid operation.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateClassicOptions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::CreateUpdateClassicOptionsInput >& inputObjects ) = 0;

    /**
     * This operation is to <code>create</code> or <code>update</code> (depending on the
     * Operation) a variantCondition ( which is variant expression of type load if) for
     * a <b>BOMLine</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when user wants to create a new or update an existing
     * classic variant condition for a given <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        This has the list of <code>CreateOrUpdateVariantCondInput</code> struct, which are
     *        used to create a new variant condition or update an existing variant condition.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         <li type="disc">46110 You cannot have substitutes of the top line of the BOM
     *         </li>
     *         <li type="disc">215160 Not a valid operation
     *         </li>
     *         <li type="disc">215161 Cannot find a valid Variant Expression block assosiated with
     *         this BOMLine
     *         </li>
     *         <li type="disc">215166 Failed to save BOMWindow.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of tc2007.1, use  the createOrUpdateVariantConditions2 operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use  the createOrUpdateVariantConditions2 operation."))
#endif
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateVariantConditions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::CreateOrUpdateVariantCondInput >& inputObjects ) = 0;

    /**
     * Delete option deletes the option and all the values associated with it.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        A list of DelClassicOptionsInput structures, each of which contains a bomline tag,
     *        and list of options. If the option exists then it will be deleted.
     *
     * @return
     *         ServiceData:Any failure will be returned via ServiceData with original input object
     *         mapped to error message.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteClassicOptions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::DelClassicOptionsInput >& inputObjects ) = 0;

    /**
     * This service will be used to delete the variant Condition(load_if) associated with
     * a BOMLine If the variant condition exists then it will be deleted. Failure will be
     * with client id and error message in the ServiceData.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        Consists of the clientId and the BOMLine for which we need to delete the variant
     *        Condition
     *
     * @return
     *         ServiceData
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteVariantConditions ( const std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::DeleteVariantCondInput >& inputObjects ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

