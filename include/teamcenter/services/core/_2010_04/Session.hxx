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

#ifndef TEAMCENTER_SERVICES_CORE__2010_04_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2010_04_SESSION_HXX

#include <teamcenter/services/core/_2007_01/Session.hxx>
#include <teamcenter/services/core/_2008_03/Session.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2010_04
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct GetShortcutsResponse;
    struct LHNNonTcObjectSectionComponent;
    struct LHNSectionComponents;
    struct LHNTcObjectSectionComponent;
    struct MultiPreferenceResponse2;
    struct ReturnedPreferences2;

    /**
     * This map is used to maintain the place holder for nonTcObject.  LHNNonTcObjectSectionComponent
     * is a structure in which there is a map element haveing information  about the non
     * TcObject. Such as for 'IWanToSection' it is 'Action Name' 'Display Name' and  commandID.
     * Example:                                   LHNNonTcObjectSectionComponentMap( 1,
     * 'create an item') LHNNonTcObjectSectionComponentMap( 2, 'create a Dataset')
     */
    typedef std::map< int, LHNNonTcObjectSectionComponent > LHNNonTcObjectSectionComponentMap;

    /**
     * This is a map containing the details of a object in the left hand navigation. The
     * keys vary based on the type of the section name. Example For IWantToSection keys
     * are ActionName, DisplayName,  commandID.  Action Name = newItemAction Display Name
     * = Create an Item LHNSectionComponentDetails('Action Name',  newItemAction ); LHNSectionComponentDetails('Display
     * Name',  Create an Item ); LHNSectionComponentDetails('Display Name',  com.teamcenter.rac.newItem
     * )
     */
    typedef std::map< std::string, std::string > LHNSectionComponentDetails;

    /**
     * In this map key is the SectionName and value is the LHNSectionComponent structure,
     * which have  TcObject and nonTcObject as it's element. The prefered Keys allowed in
     * this map are MyFavorites, HistoryList, QuickLinksSection,  MyQuicklinkSection etc.
     * Example   LHNSectionComponentsMap ('HistorySection' , SectionComponent structure
     * for History  Section)
     */
    typedef std::map< std::string, LHNSectionComponents > LHNSectionComponentsMap;

    /**
     * This is a input parameter to the getShortcuts operation. This is a map where the
     * key represents the  section name in the left hand navigation  and the value represents
     * the preference name that needs to be looked up. Valid key value pairs are: Key =
     * QuickLinksSection, Value = MyTeamcenterQuicklinksection Key = FavoritesSection, value
     * = My Favorites  Valid keys in the map are QuickLinksSection, HistorySection, FavoritesSection,
     * IWantToSection, OpenItemsSection. Valid values against these keys in the map are
     * MyFavorites, HistoryList, QuickLinksSection, MyQuicklinkSection, OpenItemSection
     * etc.
     */
    typedef std::map< std::string, std::string > LHNShortcutInputs;

    /**
     * This map is used to maintain the place holder for the sectioncomponent.Which is either
     * a tcObject or  nontcobject.   LHNTcObjectSectionComponent It is simply a collection
     * of TcObject or nonTcObject.               Example: LHNTcObjectSectionComponentMap(0,
     * any tcobject or  nontcobject); LHNTcObjectSectionComponentMap(1, any tcobject or
     * nontcobject);
     */
    typedef std::map< int, LHNTcObjectSectionComponent > LHNTcObjectSectionComponentMap;

    /**
     * A structure contains Favorites hierarchy and map of LHNSectionComponent given section
     * names.
     */
    struct GetShortcutsResponse
    {
        /**
         * A hierarchical Favorites tree structure list that contains all the favorites containers
         * and favorites objects for the current session user. The Favorites section can be
         * populated only if FavoritesSection is passed as a key in the input map to this API.
         */
        Teamcenter::Services::Core::_2008_03::Session::FavoritesList favorites;
        /**
         * A map structure that includes the given section name and corresponding content of
         * the section. The key is the name of the section and the value is the LHNSectionComponent
         * structure, which has a Teamcenter object and a nonTeamcenter object . The preferred
         * keys allowed in this map are MyFavorites, HistoryList, QuickLinksSection,  MyQuicklinkSection
         * etc.
         */
        LHNSectionComponentsMap shortcuts;
        /**
         * ServiceData contains any failures and Teamcenter objects  wrapped in LHNSecitonComponents
         * and default properties. The following errors may be encountered:
         * <br>
         * 1700 (error code):  The preference cannot be found.
         * <br>
         * 515024 ( error code): The given tag does not exist in the database or is not a persistent
         * object tag.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The sections in the left hand navigation can contain either Teamcenter objects or
     * non-Teamcenter  objects. Sections which contain Teamcenter objects are 'Open Items',
     * 'History', etc and the sections which  contain non-Teamcenter bjects are 'I Want
     * To' section. This structure in turn contains the LHNSectionComponentDetails which
     * maintains additional information pertaining to the object.  Example: Consider that
     * the 'I Want To' section in the left hand navigation contains the command 'Create
     * an  Item'. This structure would contain the below details in the LHNSectionComponentDetails.
     * Key = ActionName, Value = newItemAction Key = DisplayName, Value = Create an Item
     * Key = CommandID, Value = com.teamcenter.rac.newItem  Consider that the 'QuickLinkSection'
     * section in the left hand navigation contains the command 'like  a 'home folder'
     * in quick links. key = QuickLinkId
     */
    struct LHNNonTcObjectSectionComponent
    {
        /**
         * Non Tc Objects like Home, folder etc
         */
        LHNSectionComponentDetails nonTcObjects;
    };

    /**
     * The purpose of this structure is to give a single name to 'LHNNonTcObjectSectionComponentMap'
     * and  'LHNTcObjectSectionComponentMap' which is section component. Each section component
     * is puted into   LHNSectionComponentsMap.  LHNNonTcObjectSectionComponentMap: It is
     * a map for nontcobject , whose key is 'int' using for  placeHolder and value are NonTcObjectSection.
     * LHNTcObjectSectionComponentMap key is for placeholder and value as tccomponent object.
     */
    struct LHNSectionComponents
    {
        /**
         * nonTcObjects
         */
        LHNNonTcObjectSectionComponentMap nonTcObjects;
        /**
         * tcObjects
         */
        LHNTcObjectSectionComponentMap tcObjects;
    };

    /**
     * The purpose of this structure is to represents the Teamcenter object details, Which
     * is get use in  the Left Hand Navigation pane of the clients. Which is either a tcobject
     * or non tcobject.  Teamcenter::BusinessObject  This is a TcComponent which have all
     * the bussiness property of   teamcenter object. e.g Items in History section, Items
     * in OpenItemSection etc.               LHNSectionComponentDetails It must contain
     * the detail information about the nonTcObject at which  place we have to insert and
     * what are the action name and display name  associated with it. e.g LHNSectionComponentDetails('Action
     * Name',  newItemAction );     LHNSectionComponentDetails('Display Name',  Create an
     * Item );
     */
    struct LHNTcObjectSectionComponent
    {
        /**
         * Specifies the Teamcenter object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  tcObject;
        /**
         * Additional details of the section component.
         */
        LHNSectionComponentDetails details;
    };

    /**
     * The structure used to get the returned preference
     */
    struct MultiPreferenceResponse2
    {
        /**
         * The successful Object ids, partial errors and failures
         */
        Teamcenter::Soa::Client::ServiceData data;
        /**
         * List of ReturnedPreferences2 Object
         */
        std::vector< Teamcenter::Services::Core::_2010_04::Session::ReturnedPreferences2 > preferences;
    };

    /**
     * This is the structure which is used to define the information for one preference.
     */
    struct ReturnedPreferences2
    {
        /**
         * The scope of the preference, "all", "site", "user", "group", or "role".
         */
        std::string scope;
        /**
         * The variable to hold the category name
         */
        std::string category;
        /**
         * The variable to hold the description
         */
        std::string description;
        /**
         * Preference Type
         */
        int prefType;
        /**
         * Preference Array
         */
        bool isArray;
        /**
         * Is the preference disabled
         */
        bool isDisabled;
        /**
         * The value of the preference
         */
        std::vector< std::string > values;
        /**
         * The name of the preference
         */
        std::string name;
    };




    /**
     * This operation takes an input structure which contains a scope value and vector of
     * preference names. The return type of this operation is the MultiPreferencesResponse2
     * structure whose elements are the ServiceData and the vector of ReturnedPreferences2
     * structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Preference Management - Provides the capability to store and manage both system and
     * user prefrences that are used to tune the system based on the settings. Typically
     * these consist of name value pairs that the code looks up at runtime to configure
     * the behavior.
     *
     * @param preferenceNames
     *        The input structure, the object of which would ahve 2 input parameters of scope and
     *        the preference names.
     *
     * @return
     *         This structure is used to return Preference
     *
     * @deprecated
     *         As of Teamcenter 10, use the getPreferences operation from the PreferenceManagement
     *         service in the Administration library.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10, use the getPreferences operation from the PreferenceManagement service in the Administration library."))
#endif
    virtual Teamcenter::Services::Core::_2010_04::Session::MultiPreferenceResponse2 getPreferences2 ( const std::vector< Teamcenter::Services::Core::_2007_01::Session::ScopedPreferenceNames >& preferenceNames ) = 0;

    /**
     * This operation gets the sections and corresponding content in Left Hand Navigation
     * task pane given the section name and the corresponding preference name for the current
     * session user. The preference name is the key to look up section content stored in
     * preference.&nbsp;&nbsp;&nbsp;&nbsp;In the rich client, the LHN sections are Quick
     * Links, Open Items, History, Favorites and I Want To. The user can organize Teamcenter
     * data in these sections during runtime, which is persisted in the preference. The
     * Quick Links section provides a quick access point to the user`s home folder, work
     * list, favorite Web links, projects, saved searches, and View Markup. The Open Items
     * section lists Teamcenter components currently opened in the active perspective. The
     * History section lists Teamcenter components opened before, but currently closed.
     * The Favorites section contains the Favorites container and Teamcenter components
     * the user added there for quick access. The I Want To section contains commands configured
     * by default or configured by the user.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user logs in to the rich client and retrieves Quick Links, Open Items, History,
     * Favorites and I Want To task pane section for Left Hand Navigation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * RAC Views Viewer - Rich client views and viewer framework components extending from
     * eclipse jface viewer and view extension.
     *
     * @param shortcutInputs
     *        A map of the key representing the  section name in the left hand navigation and the
     *        value representing the preference name that needs to be looked up to get the content.
     *        For example,  Key =QuickLinksSection, Value = MyTeamcenterQuicklinksection;  Key
     *        = FavoritesSection, value= My Favorites . Valid keys in the map are QuickLinksSection,
     *        HistorySection, FavoritesSection, IWantToSection, OpenItemsSection. Valid values
     *        for these keys in the map could be MyFavorites, HistoryList, QuickLinksSection, MyQuicklinkSection,
     *        OpenItemSection, etc.
     *
     * @return
     *         A hierarchical Favorites tree structure list and map of LHNSectionComponent with
     *         corresponding section name.
     *         <br>
     *         A partial error may be encountered in getShortcutsResponse if the preference name
     *         or  preference value is invalid or a problem happens during preference retrieving
     *         from the Preference ITK call or preference value converting to Teamcenter object
     *         from POM_string_to_tag  referenced in the operation
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;1700 (error code): &nbsp;&nbsp;&nbsp;&nbsp;Retrieve preference
     *         error.  The preference cannot be found.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;515024 (error code): The given tag does not exist in the
     *         database or is not a persistent object tag.
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if there is an empty or invalid section name.
     */
    virtual Teamcenter::Services::Core::_2010_04::Session::GetShortcutsResponse getShortcuts ( const LHNShortcutInputs&  shortcutInputs ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

