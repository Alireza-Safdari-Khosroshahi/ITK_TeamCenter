//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_DEBAULTCLIENTDATAMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_DEBAULTCLIENTDATAMODEL_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/ObjectFactory.hxx>
#include <teamcenter/soa/internal/common/UnorderedMap.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>



namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**

 */
class  DefaultClientDataModel : public ClientDataModel
{
public:

     DefaultClientDataModel();
    ~DefaultClientDataModel();
    SOA_CLASS_NEW_OPERATORS

    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructObject( Teamcenter::Soa::Client::Type* type, const std::string& uid );
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructObject( const std::string& uid );
    virtual bool containsObject( const std::string& uid );
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getObject( const std::string& uid );
    virtual void getObjectsFromStore( std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& modelObjects );
    virtual void removeObject( const std::string& uid );
    virtual void removeObjects( const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& objects );
    virtual void removeObjects( const std::vector<std::string>& uids);
    virtual void removeAllObjects( );
    virtual void removeObjectsRecursivelyFromStore(const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& objects );
    virtual void emptyGarbage();
    virtual int  sizeOfGarbage();
    virtual void dumpCache ( std::ostream& outStream  );

protected:
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> loadObject( Type* type, const std::string& uid);
    virtual void refineType( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> obj, Type* type );

private:

 
    typedef Teamcenter::unordered_map<
        std::string,
        Teamcenter::Soa::Common::AutoPtr<ModelObject>,
        Teamcenter::hash<std::string>,
        std::equal_to<std::string>,
        Teamcenter::Soa::Common::tcsoastlallocator< std::pair<const std::string, Teamcenter::Soa::Common::AutoPtr<ModelObject> > >
        > ObjectMap;

    ObjectMap mObjectMap;
    ObjectMap mObjectGarbage;
    ObjectFactory*   mObjectFactory;
    Teamcenter::Soa::Internal::Common::Mutex *mMapMutex;



    /**
     * Add a ModelObject to the Client Data Model
     *
     * @param modelObject The ModelObject to add
     */
    void addObject( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> modelObject );


    bool validateUID( const std::string& uid ) const;
    void recursiveDelete( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> obj );
    void emtpyManagedMap( ObjectMap& objectMap );
    int  getRefCount( const ObjectMap& objectMap, const std::string& uid) const;

};

}}}//end namespace


#endif

