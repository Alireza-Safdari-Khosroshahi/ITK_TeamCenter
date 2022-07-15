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

#ifndef TEAMCENTER_SERVICES_CORE__2012_02_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2012_02_SESSION_HXX



#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2012_02
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct RegisterIndex;
    struct SetPolicyResponse;

    /**
     * Contains the index to be used for unregistering.
     */
    struct RegisterIndex
    {
        /**
         * Index to be used for unregistering.
         */
        int registryIndex;
    };

    /**
     * The policy ID and full definition of the object property policy.
     */
    struct SetPolicyResponse
    {
        /**
         * Unique ID for this object property policy.
         */
        std::string policyId;
        /**
         * The full definition of the object property policy.
         */
        Teamcenter::Soa::Common::ObjectPropertyPolicy policy;
    };




    /**
     * Register desired level for server state as used by the Server Manager to control
     * server timeout. Note that an attempt to register at LEVEL_STATELESS is ignored since
     * this is the default level when no registrations are in effect. To move from a higher
     * level to the stateless level the <code>unregister</code> operation should be used
     * to delete the earlier registration. Note that it is possible to be registered at
     * more than one level and there may be multiple registrations at each level.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * unregisterState
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param level
     *        Desired server state: "<i>Edit</i>" or "<i>Read</i>"
     *
     * @return
     *         If registration succeeds a registry index (greater than 0) is returned, and can be
     *         supplied to <code>unregister</code> operation to undo this registration.  If no registration
     *         occurs, zero is returned.
     *
     */
    virtual Teamcenter::Services::Core::_2012_02::Session::RegisterIndex registerState ( const std::string&  level ) = 0;

    /**
     * Sets the current object property policy. The business logic of a service operation
     * determines what business objects are returned, while the object property policy determines
     * which properties are returned on each business object instance. This allows the client
     * application to determine how much or how little data is returned based on how the
     * client application uses those returned business objects. The policy is applied uniformly
     * to all service operations.
     * <br>
     * By default, all applications use the <i>Default</i> object property policy, defined
     * on the Teamcenter server <code>$TC_DATA/soa/policies/default.xml. </code>It is this
     * policy that is applied to all service operation responses until the client application
     * changes the policy. Siemens PLM Software strongly recommends that all applications
     * change the policy to one applicable to the client early in the session.
     * <br>
     * The object property policy is set to the policy named in the file <code>$TC_DATA/soa/policies/<policyName>.xml</code>
     * The reserved policy name "<i>Empty</i>", will enforce a policy that only returns
     * minimum data required for each object (UID and type name).The object property policy
     * will stay in affect for this session until changed by another call to <code>setObjectPRopertyPolicy</code>.
     * The full policy is returned where the client application can modify it throughout
     * the session via calls to <code>updatObjectPropertyPolicy</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * updateObjectPropertyPolicy
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param policyName
     *        The name of the policy file without the .xml extension. The file must exist on the
     *        Teamcenter server volume at <code>$TC_DATA\soa\policies\<policyName>.xml</code>.
     *
     * @param useRefCounting
     *        When set to true, the policy will not remove a property value until there is a matching
     *        number of removes and adds in subsequent calls to <code>updateObjectPropertyPolicy</code>
     *
     * @return
     *         The policy ID and full definition of the object property policy. This ID is used
     *         on subsequent calls to <code>updateObjectPropertyPolicy</code>.
     *
     *
     * @exception ServiceException
     *           If the named policy does not exist or there are errors parsing the XML file (error
     *           code 214104).
     */
    virtual Teamcenter::Services::Core::_2012_02::Session::SetPolicyResponse setObjectPropertyPolicy ( const std::string&  policyName,
        bool useRefCounting ) = 0;

    /**
     * Remove the specified registration.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * registerState
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param index
     *        Index returned by previous call to <code>registerState</code>.
     *
     * @return
     *         True
     *
     */
    virtual bool unregisterState ( int index ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

