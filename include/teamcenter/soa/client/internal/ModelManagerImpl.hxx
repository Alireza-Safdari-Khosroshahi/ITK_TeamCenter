// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_MODELMANAGERIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_MODELMANAGERIMPL_HXX

#include <string>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/internal/common/UnorderedMap.hxx>
#include <teamcenter/soa/common/SoaStlAllocator.h>

#include <teamcenter/soa/client/ModelManager.hxx>
#include <teamcenter/soa/client/Connection.hxx>
#include <teamcenter/soa/client/Preferences.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/ClientMetaModel.hxx>

#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelObject.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ServiceData.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/PartialErrors.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/Preferences.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelSchema.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/Property.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/DisplayProperty.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/RefId.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/TypeSchema.hxx>
#include <teamcenter/soa/client/internal/PropertyImpl.hxx>
#include <teamcenter/soa/client/ModelEventListener.hxx>
#include <teamcenter/soa/client/internal/EventSharerImpl.hxx>

// To avoid having to have everthing have the core services
// include path - we declare this here
namespace Teamcenter{ namespace Services { namespace Internal { namespace Core { class SessionService; } } } }

#include <teamcenter/soa/client/ModelObjectFactory.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

// This is implementing the deprecated add/removeXXXListener methods,
// when these methods are removed from interface, remove them from here, and this pragma push
#pragma warning ( push )
#pragma warning (  disable : 4996  ) 


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API ModelManagerImpl : public Teamcenter::Soa::Client::ModelManager
{
public:
    explicit ModelManagerImpl( Teamcenter::Soa::Client::Connection* conn );

    virtual ~ModelManagerImpl();


    virtual Teamcenter::Soa::Common::AutoPtr<ModelObject> getObject( const std::string& uid );
    virtual void getObjectsFromStore( ModelObjectVector& );
    virtual std::vector<Teamcenter::Soa::Client::Type*> getTypes( const std::vector<std::string>& typeNames);

    virtual Teamcenter::Soa::Common::AutoPtr<ModelObject> constructObject( std::string typeStr, std::string uid );
    virtual Teamcenter::Soa::Common::AutoPtr<ModelObject> constructObject( std::string uid );

    virtual void removeObjectsFromStore( ModelObjectVector& objects );
    virtual void removeObjectsFromStore( StringVector uids);
    virtual void removeAllObjectsFromStore( );
    virtual void removeObjectsRecursivelyFromStore(ModelObjectVector& objects );
    virtual void emptyGarbage();
    virtual int  sizeOfGarbage();
    virtual void dumpCache ( std::ostream& outStream  );

    virtual void registerModelObjectFactory( std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >* objectFactory);

    typedef Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> SchemaModelObject;
    typedef Teamcenter::Schemas::Soa::_2006_03::Base::ModelObjectArray SchemaModelObjectArray;
    typedef Teamcenter::Schemas::Soa::_2006_03::Base::RefIdArray RefIdArray;

    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> loadObjectData( const SchemaModelObject& obj );

            ModelObjectVector loadObjectData( const SchemaModelObjectArray& obj, bool& userSessionChanged );
    virtual ModelObjectVector loadObjectData( const SchemaModelObjectArray& obj );

    virtual Teamcenter::Soa::Client::ServiceData  loadServiceData( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData>& obj );
    virtual Teamcenter::Soa::Client::PartialErrors  loadPartialErrors( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PartialErrors>& obj );
    virtual Teamcenter::Soa::Client::Preferences  loadPreferences( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Preferences>& obj );

    virtual void addChangeListener       ( ChangeListener* listener );
    virtual void addCreateListener        (CreateListener* listener); 
    virtual void addDeleteListener       ( DeleteListener* listener );
    virtual void addPartialErrorListener ( PartialErrorListener* listener );

    virtual void removeChangeListener       ( ChangeListener* listener );
    virtual void removeCreateListener       (CreateListener * listener);
    virtual void removeDeleteListener       ( DeleteListener* listener );
    virtual void removePartialErrorListener ( PartialErrorListener* listener );



    static Teamcenter::Soa::Common::AutoPtr<ModelObject> constructObjectOfType( Type* type );
    virtual void addModelEventListener( Teamcenter::Soa::Client::ModelEventListener *listener);
    virtual void removeModelEventListener( Teamcenter::Soa::Client::ModelEventListener* listener );
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getUserSessionObject() const;
    virtual void addSharedSessionHandler( Teamcenter::Soa::Client::SessionHandler *handler );
    virtual void removeSharedSessionHandler( Teamcenter::Soa::Client::SessionHandler *handler  );


    /**
     * Remove objects that aren't referenced by objects being kept
     *
     * @param objects list of all objects, from which some are to be removed
     * @param eventObjs - UIDs of objects that should be kept
     * @unpublished
     */
    void removeUnreferencedObjects ( Teamcenter::Schemas::Soa::_2006_03::Base::ModelObjectArray &objects, std::set<std::string> &eventObjs );

    /**
     * Load objects and events from TcMEM, notifying appropriate listeners
     * (defined for use by published method in Connection)
     * @param sharedWireSD ServiceData from TcMEM
     */
    void  processSharedEvents( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData>& sharedWireSD );


    ClientMetaModel* getClientMetaModel();
    ClientDataModel* getClientDataModel();

    /**
     *
     * @param theLogger
     * @param label
     * @param arg
     */
    static void  logDebug( const std::string& clazz, const std::string& label, const std::string& arg);


    /** UserSession */
    static const std::string USER_SESSION;


    SOA_CLASS_NEW_OPERATORS

private:

    ModelManagerImpl():
        ModelManager(),
        m_connection( 0 ),
        m_sessionService(0),
        m_changeListeners(),
        m_createListeners(),
        m_deleteListeners(),
        m_partialErrorListeners(),
        m_eventListeners(),
        m_sessionHandlers(),
        m_userSession(),
        m_eventSharer( 0 ),
        m_clientMetaModel(0),
        m_clientDataModel(0){}

    void loadTypes( const std::set< std::string>& types ) const;
    void removeType( const std::string& name ) const;
    void loadRefIdArray( const RefIdArray&, ModelObjectVector& objs ) const;
    void loadPartialErrors(const Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStackArray& wireErrors, const SchemaModelObjectArray& dataObjs, ErrorStackVector& partialErrors );
    bool checkForPartialPropertyInflate( const Teamcenter::Soa::Client::ErrorStack& stack,   const SchemaModelObjectArray& dataObjs );
    std::map<std::string, std::vector< std::string> > loadClassNameHierarchy ( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelSchema>& wireModelSchema ) const;

    void loadTypesForModelObjects( const SchemaModelObjectArray& wireObjects );
    ClientDataModel* constructClientDataModel(   ) const;
    ClientMetaModel* constructClientMetaModel(  Connection* connection  ) const;


    void remove( const std::string& uid ) const;

    /**
     * Invoke listeners for local model events (non-shared)
     * @param serviceData
     */
    void notifyLocalModelListeners( const Teamcenter::Soa::Client::ServiceData& serviceData ) const;

    /**
     * Invoke handler for local session event (non-shared)
     */
    void notifyLocalSessionHandler() const;

    /**
     * Invoke listeners for shared model events from TcMEM
     * @param serviceData
     * @unpublished
     */
    void notifySharedModelListeners( const Teamcenter::Soa::Client::ServiceData& serviceData ) const;

    /**
     * Invoke handler for shared session event
     */
    void notifySharedSessionHandler() const;

    
    void findReferencedObjects(std::map<std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> > objectMap, 
                               Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> obj, 
                              std::set<std::string>& referencedUids);
    /**
     * Remove overlapping events from shared using these rules from FS:
     * - If delete event exists, ignore all change events and any create event for that UID
     * - Only process one change event per UID (latest props are returned with the object)
     * - If a create and change event (s)exist, keep them both
     *
     * @param sharedWireSD shared ServiceData
     * @param localWireSD local ServiceData
     */
    void consolidateEvents( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> sharedWireSD, const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData> localWireSD ) const;

    std::set<std::string> getObjUids( Teamcenter::Schemas::Soa::_2006_03::Base::ModelObjectArray dataObjects ) const;

    std::set<std::string> getUids ( Teamcenter::Schemas::Soa::_2006_03::Base::RefIdArray eventObjs )const;

    /**
     * These call ES logging because originally it labeled output with connId,
     *  though now that using LogCorrId, could do that here 
     *
     * Logging method for displaying activity prefixed by LogCorrelationId.
     * Logs at info level.
     * @param msg message to print
     */
    void info( const std::string& msg )const;

    /**
     * Logging method for displaying activity prefixed by LogCorrelationId.
     * Logs at debug level.
     * @param msg message to print
     */
    void debug( const std::string& msg )const;

    static std::string getPropertyNames ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modObj, const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Property> >& properties);
    static std::string getUiPropertyNames(Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modObj, const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::DisplayProperty> >& xmlProperties);

    static const int                                     PARTIAL_PROPERTY_RETURN;

    Connection* m_connection;
    Teamcenter::Services::Internal::Core::SessionService*      m_sessionService;

    std::set< Teamcenter::Soa::Client::ChangeListener* >       m_changeListeners;
    std::set< Teamcenter::Soa::Client::CreateListener* >       m_createListeners;
    std::set< Teamcenter::Soa::Client::DeleteListener* >       m_deleteListeners;
    std::set< Teamcenter::Soa::Client::PartialErrorListener* > m_partialErrorListeners;
    std::set< Teamcenter::Soa::Client::ModelEventListener* >   m_eventListeners;
    std::set< Teamcenter::Soa::Client::SessionHandler* >       m_sessionHandlers;
    Teamcenter::Soa::Common::AutoPtr<ModelObject> m_userSession;
    EventSharerImpl*         m_eventSharer;
    ClientMetaModel*         m_clientMetaModel;
    ClientDataModel*         m_clientDataModel;


};
}}} //end namespace

#pragma warning ( pop )

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
