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

#ifndef TEAMCENTER_SERVICES_CORE__2008_03_SESSION_HXX
#define TEAMCENTER_SERVICES_CORE__2008_03_SESSION_HXX

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
            namespace _2008_03
            {
                class Session;

class TCSOACLIENTMNGD_API Session
{
public:

    struct ConnectResponse;
    struct FavoritesContainer;
    struct FavoritesList;
    struct FavoritesInfo;
    struct FavoritesObject;
    struct FavoritesResponse;

    /**
     * Indicates number of licenses avaliable and any failure
     */
    struct ConnectResponse
    {
        /**
         * The number of available licenses for the specified featureKey parameter.
         */
        int outputVal;
        /**
         * The ServiceData structure contains these potential error numbers:
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214401: The initialization of the license module has failed.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214402: Detaching the requested license has failed.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214403: The deallocation of the license feature key has
         * failed.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214404: Checking of the license feature key has failed.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214405: The allocation of the license feature key has failed.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214406: The module is not purchased.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;  214407: The passed in action is invalid.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A Favorites object that contains one or more subordinate favorite containers and/or
     * Teamcenter objects supporting a hierarchical favorites structure.
     */
    struct FavoritesContainer
    {
        /**
         * The identifier that relates a set of favorites container information to reported
         * errors.
         */
        std::string clientId;
        /**
         * The container identifier that is unique for all favorites. The identifier format
         * is four numeric characters with leading zeros.
         */
        std::string id;
        /**
         * The container type.
         */
        std::string type;
        /**
         * The display name used for the favorites container.
         */
        std::string displayName;
        /**
         * The parent container identifier.  An identifier of 0000 indicates the root container.
         */
        std::string parentId;
    };

    /**
     * A hierarchical favorites tree structure list that contains all the favorites containers
     * and favorites objects for the current session user. The favorites section can be
     * populated only if <code>FavoritesSection</code> is passed as a key in the input map
     * to this API.
     */
    struct FavoritesList
    {
        /**
         * List of favorite containers for the current session user.
         */
        std::vector< Teamcenter::Services::Core::_2008_03::Session::FavoritesContainer > containers;
        /**
         * List of favorite objects for the current session user.
         */
        std::vector< Teamcenter::Services::Core::_2008_03::Session::FavoritesObject > objects;
    };

    /**
     * Input information for setting the favorites for the session user.
     */
    struct FavoritesInfo
    {
        /**
         * The client copy of the current favorites containers and objects. If current containers
         * and objects are specified, they must match the current saved favorites exactly for
         * the specified new favorites to be saved.  If <code>curFavorites</code> does not match
         * the current saved favorites in Teamcenter, <code>newFavorites</code> will not be
         * saved.  This provides the client the ability to protect against simultaneous updates
         * by two clients.
         */
        Teamcenter::Services::Core::_2008_03::Session::FavoritesList curFavorites;
        /**
         * The new favorites containers and objects to be saved.  The containers and objects
         * specified in <code>newFavorites</code> make up the entire list of favorites.  If
         * no new containers and no new objects are specified, the saved favorites for the session
         * user will be cleared.
         */
        Teamcenter::Services::Core::_2008_03::Session::FavoritesList newFavorites;
    };

    /**
     * A Teamcenter favorites object.
     */
    struct FavoritesObject
    {
        /**
         * The identifier that relates a set of favorites object information to reported errors.
         */
        std::string clientId;
        /**
         * The favorite object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  objectTag;
        /**
         * The display name used for the favorites object.
         */
        std::string displayName;
        /**
         * The parent container identifier.  An identifier of 0000 indicates the root container.
         */
        std::string parentId;
    };

    /**
     * The set of Favorites containers and Favorites objects that define a hierarchical
     * Favorites structure for the current session user.
     */
    struct FavoritesResponse
    {
        /**
         * List of favorite containers and favorite objects for the current session user.
         */
        Teamcenter::Services::Core::_2008_03::Session::FavoritesList output;
        /**
         * The service data. This operation will populate the Service Data plain objects list
         * with the Favorite containers and objects.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Performs Teamcenter Flexlm license related operations, depending on the input parameters.
     * <br>
     * <br>
     * The low level actions are:
     * <br>
     * <br>
     * 1.  ILM__init_module: Initializes the license module (if it has not already been
     * initialized).
     * <br>
     * 2.  ILM__leave_module: Deallocates a license of the given module. If the user had
     * N free licenses for this module, (N plus one) will be left after this call.
     * <br>
     * 3.  ILM__check_module: Checks to see if the user has bought the specified module
     * and returns the number of purchased licenses.
     * <br>
     * 4.  ILM__enter_module: Allocates one license of the given module. If the user has
     * bought N licenses for this module, (N minus one) will be left after this call.
     * <br>
     * 5.  ILM__exit_module: Leaves the module.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Licensing - Provides the capability to assign and monitor licenses such that the
     * users (an individual; a system; a module etc.) of teamcenter can be limited to use
     * the capabilities that they have privileges for
     *
     * @param featureKey
     *        A string corresponding to the product as listed in the license file (e.g. teamcenter_author)
     *
     * @param action
     *        A string corresponding to the desired action. Valid values are:
     *        <br>
     *        1.   init: Performs the ILM__init_module action (connect to the license server).
     *        <br>
     *        2.   release: Performs the ILM__leave_module action.
     *        <br>
     *        3.   check: Performs the ILM__check_module action.
     *        <br>
     *        4.   exit: Performs the ILM__exit_module action.
     *        <br>
     *        5.   get: Performs the ILM__check_module and ILM__enter_module actions in this order.
     *        <br>
     *        6.   init_get: Performs the ILM__init_module, ILM__check_module and ILM__enter_module
     *        actions in this order.
     *        <br>
     *        7.   release_exit: Performs the ILM__leave_module and ILM__exit_module actions in
     *        this order.
     *        <br>
     *
     * @return
     *         contains a ServiceData (ConnectResponse.serviceData), and number of licenses avaliable.
     *         Any failure will be returned via ServiceData with error message.
     *
     */
    virtual Teamcenter::Services::Core::_2008_03::Session::ConnectResponse connect ( const std::string&  featureKey,
        const std::string&  action ) = 0;

    /**
     * This operation retrieves the saved Favorites containers and Favorites objects for
     * the current session user.  You can use Favorites to track containers and objects
     * you access frequently, such as folders, parts or forms.
     * <br>
     * <br>
     * If errors are encountered, partial results are returned. Partial errors are returned
     * with client IDs reflecting the index value of the saved Favorite. A service exception
     * is thrown if an error is encountered that is not related to a specific Favorite container
     * or Favorite object.
     * <br>
     * <br>
     * Any Teamcenter object that is returned as a Favorite object is added to <code>ServiceData</code>
     * plain objects.  For example, if an item exists in the list of Favorite objects, the
     * object tag value for that item will be returned in the <code>ServiceData</code> list
     * of plain objects.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User logs in and selects their saved Favorites.
     * <br>
     * <br>
     * The Favorites view in the client application is populated with the Favorites containers
     * and objects returned from this operation.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * setFavorites
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @return
     *         Hierarchical Favorite containers and Favorite objects previously saved for the current
     *         session user.
     *         <br>
     *         <br>
     *         The following error originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214335: &nbsp;&nbsp;&nbsp;&nbsp;Get favorites failure.  The error
     *         text contains information detailing the specific error.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           <code>Service Exception</code>&nbsp;&nbsp;&nbsp;&nbsp;Thrown if the retrieval
     *           of saved favorites fails for the current user, the favorites preference value is
     *           missing a field or if the favorites object for the specified ID is not found.
     * @deprecated
     *         As of Teamcenter 8.2, use the getShortcuts operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.2, use the getShortcuts operation."))
#endif
    virtual Teamcenter::Services::Core::_2008_03::Session::FavoritesResponse getFavorites (  ) = 0;

    /**
     * This operation saves new favorite containers and favorite objects for the current
     * session user.
     * <br>
     * <br>
     * Any partial errors encountered during this operation are returned using the <code>clientID</code>
     * specified by the caller. A service exception is thrown if an error is encountered
     * that is not related to a specific favorite container or favorite object.  You can
     * use favorites to track containers and objects you access frequently, such as folders,
     * parts or forms.  For example, the Newstuff folder could be added as a container to
     * the list of favorites.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User saves a container to their favorites list.
     * <br>
     * <br>
     * For this operation, the list of all current favorites for the user and the list containing
     * the container the user desires to add are supplied as input and the new container
     * is added to the list of saved favorites in Teamcenter.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param input
     *        The information required to establish a new set of saved favorites for the current
     *        session user.
     *
     * @return
     *         <code>ServiceData</code>.
     *         <br>
     *         <br>
     *         The following error originates from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">214352: &nbsp;&nbsp;&nbsp;&nbsp;Set favorites failure.  The error
     *         text contains information detailing the specific error.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           <code>Service Exception</code>&nbsp;&nbsp;&nbsp;&nbsp;Thrown if an empty or invalid
     *           container or object input parameter is specified or the list of current favorites
     *           specified is no longer current.
     */
    virtual Teamcenter::Soa::Client::ServiceData setFavorites ( const Teamcenter::Services::Core::_2008_03::Session::FavoritesInfo&  input ) = 0;


protected:
    virtual ~Session() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

