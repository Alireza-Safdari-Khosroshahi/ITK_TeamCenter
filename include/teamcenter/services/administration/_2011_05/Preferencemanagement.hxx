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

#ifndef TEAMCENTER_SERVICES_ADMINISTRATION__2011_05_PREFERENCEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ADMINISTRATION__2011_05_PREFERENCEMANAGEMENT_HXX



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
            namespace _2011_05
            {
                class Preferencemanagement;

class TCSOAADMINISTRATIONSTRONGMNGD_API Preferencemanagement
{
public:





    /**
     * Refreshes the preference values stored in the server cache, so that they are synchronized
     * with the latest values.
     * <br>
     * <br>
     * This situation might happen when the preferences for a given user are being changed
     * in 2 different sessions, or when an administrator is making changes to the Site /
     * Role or Group preferences.
     * <br>
     * <Calling the <i>refreshPreferences</i> operation will retrieve the updated values.
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
     *         <b>true</b> if the refresh operation is successful.
     *
     *
     * @exception ServiceException
     *           If the operation has failed.
     *           <br>
     */
    virtual bool refreshPreferences (  ) = 0;


protected:
    virtual ~Preferencemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/administration/Administration_undef.h>
#endif

