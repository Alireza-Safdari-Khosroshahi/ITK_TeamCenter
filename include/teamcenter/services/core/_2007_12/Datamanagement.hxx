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

#ifndef TEAMCENTER_SERVICES_CORE__2007_12_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2007_12_DATAMANAGEMENT_HXX

#include <teamcenter/soa/client/model/IdContext.hxx>
#include <teamcenter/soa/client/model/IdDispRule.hxx>
#include <teamcenter/soa/client/model/ImanType.hxx>
#include <teamcenter/soa/client/model/User.hxx>
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
            namespace _2007_12
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct IdentifierData;
    struct AlternateIdentifiersInput;
    struct ContextAndIdentifierTypes;
    struct GetContextAndIdentifiersResponse;
    struct ListAlternateIdDisplayRulesInfo;
    struct ListAlternateIdDisplayRulesResponse;
    struct ValidateAlternateIdInput;
    struct ValidateAlternateIdOutput;
    struct ValidateAlternateIdResponse;

    /**
     * A map of enum of the status for validating ids.
     */
    enum ValidateIdsStatus{ Valid,
                 Invalid,
                 Modified,
                 Override,
                 Duplicate
                 };

    /**
     * Map of <b>IManType</b> to the list of <code>ContextAndIdentifierTypes</code>.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanType> , std::vector< ContextAndIdentifierTypes > > ContextAndIdentifierTypesMap;

    /**
     * Map of name and values
     */
    typedef std::map< std::string, std::vector< std::string > > NameValueMap2;

    /**
     * A map of user to <code>IdDispRule</code>.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User> , std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdDispRule>  > > UserDisplayRuleMap;

    /**
     * This structure contains information for <b>Identifier</b> data.
     */
    struct IdentifierData
    {
        /**
         * identifiableObject
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  identifiableObject;
        /**
         * alternateId
         */
        std::string alternateId;
        /**
         * additionalProps
         */
        NameValueMap2 additionalProps;
        /**
         * makeDefault
         */
        bool makeDefault;
    };

    /**
     * Description of Alternate Identifiers to create.
     */
    struct AlternateIdentifiersInput
    {
        /**
         * The IdContext to associate with the Alternate ID.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdContext>  context;
        /**
         * The Type of Alternate Identifier to create.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanType>  identifierType;
        /**
         * The <b>Item</b> to be associated with the Alternate ID.
         */
        Teamcenter::Services::Core::_2007_12::Datamanagement::IdentifierData mainObject;
        /**
         * An <b>ItemRevision</b> to associate with the Alternate ID, optional.
         */
        Teamcenter::Services::Core::_2007_12::Datamanagement::IdentifierData revObject;
    };

    /**
     * This structure contains <b>Context</b> and <b>Identifier</b> Types.
     */
    struct ContextAndIdentifierTypes
    {
        /**
         * The <b>IdContext</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdContext>  context;
        /**
         * The list of <b>ImanType</b>s that are valid for the <b>IdContext</b>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanType>  > identfierTypes;
    };

    /**
     * <code>GetContextAndIdentifierTypes</code> response
     */
    struct GetContextAndIdentifiersResponse
    {
        /**
         * A map of context and identifier types for each requested <b>ImanType</b> (<b>ImanType</b>/<code>ContextAndIdentifierTypes</code>)
         */
        ContextAndIdentifierTypesMap contextAndIdentifierTypesMap;
        /**
         * Service data associated with the call
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure for <code>ListAlternateIdDisplayRules</code> operation
     * <br>
     */
    struct ListAlternateIdDisplayRulesInfo
    {
        /**
         * A list of users to return display rules for.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::User>  > users;
        /**
         * Flag to indicate display rules for current user.
         */
        bool currentUser;
    };

    /**
     * Return structure <code>ListAlternateIdDisplayRules</code>
     */
    struct ListAlternateIdDisplayRulesResponse
    {
        /**
         * A list of maps of <code>Teamcenter::UserImpl</code> to <code>IdDisplayRules</code>.
         * <br>
         */
        UserDisplayRuleMap userDisplayRuleMaps;
        /**
         * The current rule in the database ( valid for current user only ).
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdDispRule>  currentRuleInDB;
        /**
         * <code>ServiceData</code> associated with the call.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Input structure representing the alternate id to validate.
     */
    struct ValidateAlternateIdInput
    {
        /**
         * Input <code>clientId</code> to help the caller match the input to the output and
         * identify error conditions.
         */
        std::string clientId;
        /**
         * The <b>Item</b> alternateId to be validated.
         */
        std::string alternateId;
        /**
         * The <b>ItemRevision</b> alternate id to be validated.
         */
        std::string alternateRevId;
        /**
         * The name of the pattern for the alternate id. This is passed to the user exit <code>USER_validate_alt_id</code>
         * for validation.
         */
        std::string patternName;
        /**
         * The <b>IdContext</b> for the alternate id.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::IdContext>  context;
        /**
         * The <b>ImanType</b> for the Identifier.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanType>  identifierType;
    };

    /**
     * This structure contains information for <code>ValidateAlternateIdOutput</code>.
     */
    struct ValidateAlternateIdOutput
    {
        /**
         * Input <code>clientId</code> to help the caller match the input to the output.
         */
        std::string clientId;
        /**
         * Returned alternate id for the <b>Item</b>. This will be a modified id if the input
         * id was invalid.
         */
        std::string modifiedAltId;
        /**
         * Returned alternate id for the <b>ItemRevision</b>. This will be a modified id if
         * the input id was invalid.
         */
        std::string modifiedAltRevId;
        /**
         * Status of the validation for the alternate id for the <b>Item</b>. The values can
         * be found in <code>Teamcenter::Soa::Core::_2007_12::DataManagement::ValidateIdsStatus</code>
         */
        ValidateIdsStatus validityId;
        /**
         * Status of the validation for the alternate id for the <b>ItemRevision</b>. The values
         * can be found in <code>Teamcenter::Soa::Core::_2007_12::DataManagement::ValidateIdsStatus</code>
         */
        ValidateIdsStatus validityRevId;
    };

    /**
     * Return structure containing a list of output corresponding to the input and the <code>ServiceData</code>.
     */
    struct ValidateAlternateIdResponse
    {
        /**
         * List of <code>ValidateAlternateIdOutput</code>.
         */
        std::vector< Teamcenter::Services::Core::_2007_12::Datamanagement::ValidateAlternateIdOutput > output;
        /**
         * The <code>ServiceData</code> will contain the objects that are returned by the service
         * call. Any partial errors will be mapped with input client id and error message in
         * the <code>ServiceData</code>.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Create new alternate identifiers. Given an <code>IdContext</code>, an <code>IdentifierType</code>
     * and an <b>Item</b> ( and optionally an <b>ItemRevision</b> ), create <b>an Identifier</b>
     * object to display an option part number when the <code>IdContext</code> is valid.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User has a part number for an <b>Item</b> that is used to track the <b>Item</b>.
     * The manufacturer of the <b>Item</b> has a different part number. The sales department
     * has another part number. The user needs to keep all 3 part numbers with the <b>Item</b>
     * and display them at different times. The user can get a list of <code>IdContext</code>
     * and <code>IdentifierTypes</code> from the <code>getContextsAndIdentifierTypes</code>
     * operation. Using the <code>IdContext</code> and <code>IdentifierType</code>, the
     * client can create an <b>Identifer</b> for the <b>Item</b> and <b>ItemRevision</b>
     * to be displayed when the <code>IdContext</code> is valid.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getContextsAndIdentifierTypes, listAlternateIdDisplayRules
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param input
     *        This data describes the alternate identifiers to create.
     *
     * @return
     *         The <code>ServiceData</code> will contain the newly created objects of type <b>Identifier</b>
     *         for the <b>Item</b> and <b>ItemRevision</b> ( if requested ) in the created list
     *         and the updated objects of type <b>Identifier</b> for the <b>Item</b> and <b>ItemRevision</b>
     *         ( if requested ) will be in the updatedObjects section.. Error messages are returned
     *         in the ServiceData as partial errors, this service does not have any specific errors,
     *         just errors from the sub-system.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createAlternateIdentifiers ( const std::vector< Teamcenter::Services::Core::_2007_12::Datamanagement::AlternateIdentifiersInput >& input ) = 0;

    /**
     * Returns the context and identifier types for the supplied identifiable types.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * A user has defined several <b>IdContexts</b> and <b>Idenitfiers</b> in preparation
     * for creating <b>AlternateIds</b>. This service returns the current <b>IdContext</b>
     * and Identifiers allowing the user to select the appropriate data for <b>AlternateId</b>
     * creation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param typeTags
     *        A list of <b>ImanType</b> objects.
     *
     * @return
     *         A map of identifiable types with their contexts and the identifier types for each
     *         context. This service will return partial error 9999 if a <code>typeTag</code> is
     *         invalid. Other error messages are for problems in the subsystem.
     *
     */
    virtual Teamcenter::Services::Core::_2007_12::Datamanagement::GetContextAndIdentifiersResponse getContextsAndIdentifierTypes ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanType>  >& typeTags ) = 0;

    /**
     * Return the current display rule. If the current user flag is set then also return
     * the display rules for the current user. If a list of users is supplied, then return
     * the display rules for the list of users; otherwise return the display rules for all
     * users.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Return the current display rule in effect and optionally return all the display rules
     * for the current user. Also return the display rules for all users or for a list of
     * users only.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param input
     *        A <code>ListAlternateIdDisplayRulesInfo</code> data structure.
     *
     * @return
     *         A map of <b>User</b> objects to <code>IdDispRuleSpec</code>. Error messages for problems
     *         are returned in the <code>ServiceData</code> partial errors. This service throws
     *         no specific errors but the subsystem may.
     *
     */
    virtual Teamcenter::Services::Core::_2007_12::Datamanagement::ListAlternateIdDisplayRulesResponse listAlternateIdDisplayRules ( const Teamcenter::Services::Core::_2007_12::Datamanagement::ListAlternateIdDisplayRulesInfo&  input ) = 0;

    /**
     * Determines if the supplied alternateIds are valid. The USER exit USER_validate_alt_id
     * is used for validation. A "modified" alternate id is returned. If the alternate id
     * supplied is valid then the modified one returned is the same as the one supplied.
     * If the alternate id supplied is not valid, then the one returned is a valid one.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user has an alternate id that they wish to use for an object. The alternate id
     * is sent to this function to determine if the new alternate id conforms to the rules
     * defined by the user.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getContextsAndIdentifierTypes
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Identifier - Component to define Identifier and associate it with an Item or Item
     * Revision. An identifier can be an Alternate identifier for an object as well as an
     * Alias identifier for other objects at the same time.
     *
     * @param inputs
     *        A list of <code>ValidateAlternateIdInput</code> data structures.
     *
     * @return
     *         A list giving the status and output id of each input. This service throws no errors
     *         explicitly but the system calls may generate errors. Error messages are returned
     *         in the <code>ServiceData</code> partial errors.
     *
     */
    virtual Teamcenter::Services::Core::_2007_12::Datamanagement::ValidateAlternateIdResponse validateAlternateIds ( const std::vector< Teamcenter::Services::Core::_2007_12::Datamanagement::ValidateAlternateIdInput >& inputs ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

