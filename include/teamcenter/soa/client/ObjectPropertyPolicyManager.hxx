// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_OJBECTPROPERTYPOLICYMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_OJBECTPROPERTYPOLICYMANAGER_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>
#include <teamcenter/soa/common/PolicyType.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/ServiceException.hxx>




#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * This interface manages all Object %Property Policies used throughout the client session.
 * An Object %Property Policy defines which properties are returned from a service operation for a
 * given business object type. The business logic of a service operation determines what business
 * objects are returned, while the Object %Property Policy determines which properties are returned
 * on each business object instance. This allows the client application to determine how much or how
 * little data is returned based on how the client application uses those returned business objects.
 * The policy is applied uniformly to all service operations.<br>
 *
 * By default, all applications use the Default Object %Property Policy, defined on the %Teamcenter server
 * <code>$TC_DATA/soa/policies/default.xml</code>. It is this policy that is applied to all service operation
 * responses until the client application changes the policy. Siemens PLM Software strongly recommends
 * that all applications change the policy to one applicable to the client early in the session.<br>
 *
 * Object %Property Policies may be defined in XML files and installed on the %Teamcenter server under
 * <code>$TC_DATA/soa/policies</code> or defined on the client via the ObjectPropetyPolicy class. The client application
 * can use a policy defined either way or a combination of both throughout the session. Using the
 * {@link Teamcenter::Soa::Common::ObjectPropertyPolicy} class versus the named policy on the server gives the client application greater
 * control of defining a policy. An instance of the {@link Teamcenter::Soa::Common::ObjectPropertyPolicy} class can be defined per version
 * of the client vs. the version of the %Teamcenter server, it can be constructed in the client based on user
 * preferences or user interaction and persisted to the local file system, enabling the ability to define a
 * policy for a particular user versus forcing all users of the application to have the same policy.
 * There are a few basic strategies for managing the policy.
 * <UL>
 * <li> Using a single policy
 * <li> Switching between several fixed policies
 * <li> Dynamically updating a policy throughout  the session
 *</UL>
 *
 * For the simple case of using a single policy, use the {@link #addPolicy} and {@link #setPolicy} methods to add/register the
 * policy and actively set it.<br>
 *
 * To switch between multiple policies throughout the client session, add each of the desired policies to the
 * manager with the {@link #addPolicy} method, and then use the {@link #setPolicy} method to switch policies.
 * The {@link #addPolicy} method can called at any time during the session, but must be called before the
 * {@link #setPolicy} for a given policy. The {@link #getCurrentPolicy}  and {@link #getPreviousPolicy}
 * can help in switching back and forth between two policies.<br>
 *
 * You can also dynamically update a policy throughout the session. As above, add and set the policy, then
 * call the updatePolicy method to add and/or remove types and properties from the policy. The client can
 * switch between multiple dynamic policies or a mix of dynamic and fixed policies.
 *
 */
class TCSOACLIENTMNGD_API ObjectPropertyPolicyManager
{
public:
    /**
     * Determines if and how a policy may be updated.
     */
    enum PolicyStyle
    {
        /**
         * The policy, as defined in the XML files will remain unchanged throughout the session.
         */
        PolicyFixed,
        /**
         * The policy may be updated with subsequent calls to updatePolicy.
         */
        PolicyDyanmic,
        /**
         * A Dynamic policy that can be updated with subsequent calls to updatePolicy, however reference
         * counting will be used and a type/property is only removed after a equal number of adds/removes are made.
         * The reference counting starts at one for all type/properties defined in the policy.
         */
        PolicyRefCounted
    };

    virtual ~ObjectPropertyPolicyManager();
    SOA_CLASS_NEW_OPERATORS




    /**
     * Adds the named Object %Property Policy to the list of policies available for use in this client session.
     * A {@link Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException ServiceException} (214104) is
     * thrown if the <code>policyName</code> is not valid, or does not exist
     * on the %Teamcenter server in the folder <code>$TC_DATA/soa/policies</code>.  This method does not change
     * the current policy applied to service operations, use the {@link #setPolicy} method to actually apply this policy.
     *
     * @param policyName  The name of the policy file without the <code>.xml</code> extension.
     *                    The file must exist on the %Teamcenter server volume at <code>$TC_DATA/soa/policies/&lt;policyName&gt;.xml</code>.
     *
     * @param style       The style of the policy:
     *                   <UL>
     *                     <li><b>Fixed:</b>   The policy, as defined in the XML files, will remain unchanged throughout the session.
     *
     *                     <li><b>Dynamic:</b> The policy may be updated with subsequent calls to {@link #updatePolicy}.
     *                                         Dynamic policies are only available with a %Teamcenter server 9.1 or newer.
     *                                         Setting this to Dynamic with an older server will result in 
     *                                          {@link Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException ServiceException} (535) being thrown.
     *
     *                     <li><b>RefCounted:</b>  A Dynamic policy that can be updated with subsequent calls to {@link #updatePolicy},
     *                                             however reference counting will be used and a type/property is only removed after
     *                                             a equal number of adds/removes are made. The reference counting starts at one for
     *                                             all type/properties defined in the policy. Dynamic policies are only available
     *                                             with a %Teamcenter server 9.1 or newer. Setting this to Dynamic with an older server
     *                                             will result in 
     *                                              {@link Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException ServiceException}(535) being thrown.
     *                </UL>
     *
     * @return The ID of the policy.
     * @throws  Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException If the named policy is not valid (214104), or attempt to define the policy as Dynamic with a %Teamcenter
     *                          server that does not support this(535).
     */
     virtual std::string addPolicy( const std::string& policyName, PolicyStyle style )=0;


    /**
     * Adds the Object %Property Policy to the list of policies available for use in this client session.
     * If the policy has reference counting enabled, subsequent updates to the policy will only remove a
     * type/property after an equal number of add/removes have been made. The reference counting starts
     * at one for all type/properties defined in the policy. This method does not change the current
     * policy applied to service operations, use the  {@link #setPolicy} method to actually apply this policy.
     * The ID of the policy is returned, this ID is used on subsequent calls to setPolicy and {@link #updatePolicy}.
     *
     * @param policy The desired policy.
     * @param useRefCounting  When set to true subsequent calls to {@link #updatePolicy} will only remove a type/property
     *                        after an equal number of adds/removes are made. The reference counting starts
     *                        at one for all type/properties defined in the policy.
     *
     * @return The ID of the policy.
     *
     * @throws  Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException If the server is older than 8.0 (536).
     */
    virtual std::string addPolicy ( const Teamcenter::Soa::Common::ObjectPropertyPolicy& policy, bool useRefCounting )=0;


    /**
     * Sets the Object %Property Policy.
     * This policy is applied to all subsequent service operation calls.
     *
     * @param policyName The name of the desired policy. This can either be a named policy on the %Teamcenter server,
     *                   the reserved policies of  'Default' or' Empty', or the ID of a policy defined on the client.
     *
     * @throws Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException If the named policy has not been previously added via the {@link #addPolicy} method.
     */
    virtual void setPolicy ( const std::string& policyName )=0;


    /**
     * Sets the Object %Property Policy for service operations made on this thread.
     * The policy set by this method will override a policy set through {@link #setPolicy} which apply the
     * policy to all request made in this session.  Use the {@link #clearPolicyPerThread} method to remove a
     * thread based policy and revert to the session based policy.
     *
     * @param policyName The name of the desired policy. This can either be a named policy on the %Teamcenter server,
     *                   the reserved policies of  'Default' or' Empty', or the ID of a policy defined on the client.
     *
     * @throws  Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException If the named policy has not been previously added via the {@link #addPolicy} method.
     */
    virtual void setPolicyPerThread ( const std::string& policyName )=0;


    /**
     * Clears the Object %Property Policy set for this thread.
     * Once this method is called the policy applied to service requests on this thread will revert to the
     * policy defined for the session.
     *
     */
    virtual void clearPolicyPerThread ()=0;


    /**
     * Update the named policy, adding and removing the named properties.
     * This method only applies to Object %Property Policies that have full definition on the client,
     * and have been previously added using the {@link #addPolicy} method. If the policy has reference
     * counting enabled, that reference counting will be honored by this method. The changes in the
     * policy defined by this method are accumulated and sent to the server prior to the next service request.
     * Thus multiple calls to this method will result in a single server trip to apply those changes before
     * the next service operation.
     *
     * @param policyName        The name of the policy to update. This can either be a named policy on the
     *                          %Teamcenter server or the ID of a policy defined on the client.
     * @param applyToRootTypes  If true, the properties are added or removed from the type they are defined on
     *                          in the %Client Meta %Model. For example, the <code>addProperties</code> has the
     *                          <b>ItemRevision/checked_out property</b>, will result in the policy being
     *                          updated with the <b>WorkspaceObject/checed_out property</b>, as <b>ItemRevision</b>
     *                          inherits the <b>checked_out property</b> from <b>WorkspaceObject</b>.

     * @param addProperties     List of properties to add to the named policy. If the property already exists in
     *                          the policy, all flags (excludeUiValues) on that property will be lost and only the
     *                          flags from the input will be applied.
     * @param removeProperties  List of properties to remove from the named policy. If a source {@link Teamcenter::Soa::Common::PolicyType PolicyType}
     *                          defines a type without properties, the whole type is removed. If the name policy was
     *                          created with reference counting enabled, the property will only be removed if the
     *                          reference count goes to zero (matching number of adds and removes).
     *
     * @throws  Teamcenter::Schemas::Soa::_2006_03::Exceptions::ServiceException If the named policy has not been previously added via the addPolicy method(537),
     *                          does not accept updates(538), or an added type or property does not exist in the
     *                          %Client Meta %Model(539).
     */
    virtual void updatePolicy (const std::string& policyName, bool applyToRootTypes,
                               const std::vector<Teamcenter::Soa::Common::PolicyType>& addProperties, 
                               const std::vector<Teamcenter::Soa::Common::PolicyType>& removeProperties)=0;



    /**
     * Gets the named policy, or null if the policy only has a server side definition or has not been added via
     * the {@link #addPolicy( const Teamcenter::Soa::Common::ObjectPropertyPolicy&, bool)} method.

     * @param policyName    The ID of the desired policy, as returned from {@link #addPolicy( const Teamcenter::Soa::Common::ObjectPropertyPolicy&, bool)}.
     * @return The named policy
     */
    virtual Teamcenter::Soa::Common::ObjectPropertyPolicy* getPolicy( const std::string& policyName )=0;


    /**
     * Gets a list of all policies added via the {@link #addPolicy} method.
     * The list will always include the 'Default' and 'Empty' policies.
     *
     * @return The list of available policies.
     */
    virtual std::vector<std::string> getAvailablePolices ()=0;


    /**
     * The name of the current policy.
     *
     * @return The name of the current policy.
     */
    virtual std::string getCurrentPolicy ()=0;

    /**
     * The name of the previous policy.
     * @return The name of the previous policy.
     */
    virtual std::string getPreviousPolicy ()=0;



protected:
    ObjectPropertyPolicyManager();

};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

