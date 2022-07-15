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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2008_06_PREFERENCEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2008_06_PREFERENCEMANAGEMENT_HXX



#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/administration/Administration_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Administration
        {
            namespace _2008_06
            {
                class Preferencemanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Preferencemanagement
{
public:





    /**
     * Locks the Site preferences stored in the database.
     * <br>
     * <br>
     * This can be used by system administrators only. It is not mandatory to lock Site
     * preferences to make changes, but it ensures exclusive write accesses when necessary.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @return
     *         <b>true</b> is returned if site preferences are locked successfully.
     *
     *
     * @exception ServiceException
     *           The exception will contain the following error codes:
     *           <br>
     *           <ul>
     *           <li type="disc">1710: If the Site preferences are already locked by the user.
     *           </li>
     *           <li type="disc">1711: If the Site preferences have been locked by another user.
     *           </li>
     *           <li type="disc">1725: If the logged-in user does not have the requested privileges.
     *           </li>
     *           <li type="disc">10012: If the environment variable <i>TC_DB_CONNECT</i> is not set
     *           or set to an empty value.
     *           </li>
     *           </ul>
     */
    virtual bool lockSitePreferences (  ) = 0;

    /**
     * Releases the lock set on the site preferences stored in the database.
     * <br>
     * <br>
     * The locking comes from the call to lockSitePreferences operation. Only the user who
     * locked the site preferences is allowed to unlock them.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @return
     *         <b>true</b> is returned if site preferences are unlocked successfully.
     *
     *
     * @exception ServiceException
     *           The exception will contain one of the following error codes:
     *           <br>
     *           <ul>
     *           <li type="disc">1711: If the Site preferences have been locked by another user.
     *           </li>
     *           <li type="disc">1712: If the Site preferences are not locked.
     *           </li>
     *           <li type="disc">1725: If the logged-in user does not have the requested privileges.
     *           </li>
     *           <li type="disc">10012: If the environment variable <i>TC_DB_CONNECT</i> is not set
     *           or set to an empty value.
     *           </li>
     *           </ul>
     */
    virtual bool unlockSitePreferences (  ) = 0;


protected:
    virtual ~Preferencemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

