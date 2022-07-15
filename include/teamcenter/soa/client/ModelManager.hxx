// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_MODElMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_MODElMANAGER_HXX

#include <string>
#include <map>
#include <new>
#include <iostream>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ChangeListener.hxx>
#include <teamcenter/soa/client/DeleteListener.hxx>
#include <teamcenter/soa/client/CreateListener.hxx>
#include <teamcenter/soa/client/SessionHandler.hxx>
#include <teamcenter/soa/client/PartialErrorListener.hxx>
#include <teamcenter/soa/client/ModelEventListener.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
class ModelObjectFactory;

class TCSOACLIENTMNGD_API ModelManager
{
public:

    /**
     * Returns the instance of the Model Object referenced by the UID.
     * When operating with the Loosely Typed Client Data Model, this method
     * will always return an object of type 'CdmObject'. When operating with the
     * Strongly Typed Client Data Model, this method will return a stronly typed
     * object.
     *
     *
     * @param uid   UID of the desired object
     *
     * @return Client Data Model object
     *
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getObject ( const std::string& uid ) = 0;

    /* Returns all Model Objects in the cache
     * The type returned is a vector of ModelObjects.
     *
     * @param Client Data Model object
     *
     */
    virtual void getObjectsFromStore( ModelObjectVector& ) = 0;


    /**
     * Returns a vector of Type objects for the given set of input names.
     * The ModelManager caches Type data for ModelObjects that returned in the
     * different service operation, if the requested Types are in the ModelManager's
     * cache they will be retuned from the cached data, otherwise a service request
     * to the server will be made for the server for the missing type information.
     *
     * @param typeNames     List of Type names to be retrieved from the ModelManager's cache
     * @return              Vector of Type objects
     *
     * @throws NotLoadedException If any of the input type names do not exist in the
     *                            client cache and can not be loaded from the server
     *                            (most likely the name does not exist in the server
     *                            Business Model schema).
     */
    virtual std::vector<Teamcenter::Soa::Client::Type*> getTypes( const std::vector<std::string>& typeNames) =0;

    /**
     * Returns an instance of the Model Object referenced by the UID.
     * Unless this object happens to be already loaded, this method
     * will construct an empty object of the specified type.
     * If the type information for the specified type has not already been
     * loaded from the server, then the object will have empty type information.
     * In either case, if this is a strongly typed client,
     * then assuming the type specified is a valid one,
     * then a strongly typed object will be returned.
     * Otherwise an instance of the general ModelObject is returned.
     *
     * @param typeStr  type of the desired object - can't be null
     * @param uid      UID of the desired object
     *
     * @return Client Data Model object
     *
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructObject( std::string typeStr, std::string uid ) = 0;

    /**
     * Returns an instance of the Model Object referenced by the UID.
     * The type returned is always ModelObject.
     *
     * @param uid      UID of the desired object
     *
     * @return Client Data Model object
     *
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructObject( std::string uid ) = 0;

    /**
     * Remove the list of ModelObjects from the local store
     * managed by the Model Manager.  Note that this also frees
     * up the memory for the object, so references to it are invalid.
     *
     * @param objects   ModelObjects to remove.
     */
    virtual void removeObjectsFromStore( ModelObjectVector& objects ) = 0;

    /**
     * Remove the list of ModelObjects from the local store
     * managed by the Model Manager.  Note that this also frees
     * up the memory for the object, so references to it are invalid.
     *
     * @param uids   UIDs of ModelObjects to remove.
     */
    virtual void removeObjectsFromStore( StringVector uids) = 0;

    /**
     * Remove *all* ModelObjects form the local store
     * and any of their references  managed by the Model Manager to free their memory.
     */
    virtual void removeAllObjectsFromStore( ) = 0;

     /**
     * Remove all ModelObjects form the local store
     * managed by the Model Manager.  Assuming there are no other references
     * to them, this will allow them to be released, freeing their memory.
     * @param objects Vector of ModelObjects to delete.
     */
    virtual void removeObjectsRecursivelyFromStore(ModelObjectVector& objects )=0;

    /**
     * Force an empty of the ModelObject gargbage.
     * The removeObjectsFromStore method will move the ModelObjects from the active
     * cache to the 'garbage'. The 'garbage' is periodically checked for ModleObject whose
     * reference count (not used anywhere else) has gone to zero. When the count is zero those objects
     * are removed from the 'garbage' and from the system entirely. This method forces an
     * emediate checking of ModelObject to remove from the garbage.
     *
     */
    virtual void emptyGarbage() = 0;

    /**
     * Returns the number of ModelObjects currently in the garbage.
     *
     */
    virtual int  sizeOfGarbage() = 0;

    /**
     * Display the contents of the Model Manager cache, and a list of
     * of object in the garbage that are pending removal.
     *
     * @param outStream  The stream the serialized data is written to.
     */
    virtual void dumpCache ( std::ostream& outStream  ) = 0;

    /**
     * @deprecated As of 9.0, use addModelEventListener.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use addModelEventListener."))
#endif
    virtual void addChangeListener ( Teamcenter::Soa::Client::ChangeListener* listener ) = 0;
    /**
     * @deprecated As of 9.0, use addModelEventListener.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use addModelEventListener."))
#endif
    virtual void addCreateListener(Teamcenter::Soa::Client::CreateListener * listener)=  0;
    /**
     * @deprecated As of 9.0, use addModelEventListener.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use addModelEventListener."))
#endif
    virtual void addDeleteListener ( Teamcenter::Soa::Client::DeleteListener* listener ) = 0;
    virtual void addPartialErrorListener ( Teamcenter::Soa::Client::PartialErrorListener* listener ) = 0;


    /**
     * @deprecated As of 9.0, use removeModelEventListener.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use removeModelEventListener."))
#endif
    virtual void removeChangeListener ( Teamcenter::Soa::Client::ChangeListener* listener ) = 0;
    /**
     * @deprecated As of 9.0, use removeModelEventListener.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use removeModelEventListener."))
#endif
     virtual void removeCreateListener(Teamcenter ::Soa ::Client::CreateListener *listener)  = 0;
    /**
     * @deprecated As of 9.0, use removeModelEventListener.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use removeModelEventListener."))
#endif
    virtual void removeDeleteListener ( Teamcenter::Soa::Client::DeleteListener* listener ) = 0;
    virtual void removePartialErrorListener ( Teamcenter::Soa::Client::PartialErrorListener* listener ) = 0;

    /**
     * Register a Model Object Factory with the Model Manager.
     * This is only required if using the Model Extentions. Before registring the ModelObjectFactory,
     * you must first create it:
     *<pre>
     *  std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >* objFactory;
     *  objFactory = VendormanagementObjectFactory::init();
     *  modelManager->registerModelObjectFactory( objFactory );
     *</pre>
     */
    virtual void registerModelObjectFactory( std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >* objectFactory) =0;

    /**
     * Set the listener for processing local and shared model events and errors.
     * Add a ModelEventListener to the Model Manager.
     * All registered ModelEventListeners are called by the Model Manager
     * when a service request returns local events or when shared events
     * for the server being used are obtained from the TCCS Event Sharer.
     *
     * @param listener  The ModelEventListener to add.
     */
    virtual void addModelEventListener( Teamcenter::Soa::Client::ModelEventListener* listener ) = 0;

    /**
     * Remove a ModelEventListener from the Model Manager.
     *
     * @param listener  The ModelEventListener to remove.
     */
    virtual void removeModelEventListener( Teamcenter::Soa::Client::ModelEventListener* listener ) = 0;

    /**
     * Returns the UserSession object cached by the SOA framework.
     * It contains the current values for Group, Role, Project, etc.
     * at least as far as this client knows.
     */
     virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getUserSessionObject() const = 0;


    /**
     * Add the handler for processing shared session events and errors.
     *
     * @param handler The SessionHandler
     */
     virtual void addSharedSessionHandler( Teamcenter::Soa::Client::SessionHandler *handler )=0;

    /**
     * Removes the current SessionHandler handler.
     *
     * @param handler The SessionHandler
     *
     */
     virtual void removeSharedSessionHandler( Teamcenter::Soa::Client::SessionHandler *handler  ) =0;

     SOA_CLASS_NEW_OPERATORS

protected:
    ModelManager(){}
    virtual ~ModelManager() = 0;

};
}}} //end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
