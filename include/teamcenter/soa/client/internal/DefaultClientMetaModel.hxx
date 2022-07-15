//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_DEFAULTCLIENTMETAMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_DEFAULTCLIENTMETAMODEL_HXX

#include <string>
#include <vector>
#include <map>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/ClientMetaModel.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelSchema.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelType.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/PropDescriptor.hxx>
#include <teamcenter/soa/internal/common/UnorderedMap.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


            class Connection;
/**
 * This is the default implementation of the ClientMetaModel.
 * The Meta Model will be backed by data retrieved interactively from the server.
 * This is done via calls to the SessionService.initTypesByName
 *
 *
 */
class DefaultClientMetaModel : public ClientMetaModel
{
public:
    explicit DefaultClientMetaModel( Connection* connection );
    virtual ~DefaultClientMetaModel();
    SOA_CLASS_NEW_OPERATORS




    /**
     *  Share this ModelManager and ClientDataModel
     *
     * @return Place holder for an unknown type
     */
    static  Type*  getUnknownType();


    /**
     * Determine the value type of an LOV based on the the LOV Type.
     *
     * @param lovType   The LOV Type
     * @return          The value type.
     * <UL>
     * <li> {@link PropertyDescription#CLIENT_PROP_TYPE_char}
     * <li> {@link PropertyDescription#CLIENT_PROP_TYPE_date}
     * <li> {@link PropertyDescription#CLIENT_PROP_TYPE_double}
     * <li> {@link PropertyDescription#CLIENT_PROP_TYPE_int}
     * <li> {@link PropertyDescription#CLIENT_PROP_TYPE_string}
     * <li> {@link PropertyDescription#CLIENT_PROP_TYPE_ModelObject}
     *</UL>
     *
     * @see PropertyDescription
     * @throws IllegalArgumentException if input lovType is not a known sub-type of ListOfValues
     */
    static int getLovValueType( Type* lovType );



    virtual bool containsType( const std::string& typeKey );
    virtual bool isTypeValid( const std::string& typeName );
    virtual Type* getType( const std::string& typeKey );
    virtual std::vector<Type*> getTypes( const std::vector<std::string>& typeKeys );
    virtual void removeType( const std::string& typeKey );
    virtual bool containsLovInfo( const std::string& uid  );
    virtual LovInfo* getLovInfo( const std::string& uid, Type* type );




protected:
    virtual void loadTypes(  const std::set<std::string>&  typeKeys );
    virtual void loadLovInfo( const std::string&  uid, Type* type );

    typedef Teamcenter::unordered_map<
    std::string,
    Type*,
    Teamcenter::hash<std::string>,
    std::equal_to<std::string>,
    Teamcenter::Soa::Common::tcsoastlallocator< std::pair<const std::string, Type* > >
    > TypeMap;

    typedef Teamcenter::unordered_map<
    std::string,
    LovInfo*,
    Teamcenter::hash<std::string>,
    std::equal_to<std::string>,
    Teamcenter::Soa::Common::tcsoastlallocator< std::pair<const std::string, LovInfo* > >
    > LovMap;



    TypeMap     mTypeCache;
    LovMap      mLovCache;
    Connection  *mConnection;

    // The Map Mutex of for general read/write access to the Map of Types and Lovs
    // while the Load Mutex is to ensure only one thread is getting new Types or Lovs
    // from the server at at time. Other threads can read from the Type/Lov maps when
    // another thread is getting more data from the server, when the types are actually
    // added to the map it will use the general Map Mutex to lock out any other readers.
    Teamcenter::Soa::Internal::Common::Mutex *mMapMutex;
    Teamcenter::Soa::Internal::Common::Mutex *mLoadMutex;

    virtual  void addType ( Type* type );
    virtual  void addLovInfo ( LovInfo* lovInfo );

    const std::set<std::string> initialize( const std::set<std::string>& typeKeys  );
    static std::vector<std::string> getStringList( const std::string& names );
    static std::string getListOfNames( const std::vector<std::string>& typeKeys );
    static std::vector<std::string> getClassHierarchy(
            const std::string& typeName,
            const std::string& className,
            const std::string& parentTypeName,
            const std::string& owningType,
            Connection* connection
            );
    static std::vector<std::string> getTypeHierarchy(
            const std::string& typeName,
            const std::string& parentTypeName,
            Connection* connection
            );

    static std::vector<Lov::Style> getStyleList( 
            const std::vector<std::string>& propNames,
                  std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor> >& otherXmlDescriptors
            );

private:
           bool     initialized;
    static Type*    sUnknownType;
    DefaultClientMetaModel(); // don't allow use of default

    static std::string resolveLovAttachType(
            const std::vector<std::string>& typeNameHierarchy,
            const std::vector<std::string>& sourceTypes
            );


    static std::string getPropertyDescriptorNames(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PropDescriptor> >& descriptors
            );


    void ensureTypesAreLoaded(
            const std::vector<std::string>& typeKeys
            );
    void ensureLovIsLoaded(
            const std::string& uid,
            Type* type
            );

    void loadTypesByName(
            const std::vector<std::string>& typeNames
            );
    void loadTypesByUid(
            const std::vector<std::string>& typeUids
            );
    void loadModelSchema(
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelSchema> xmlModelSchema
            );
    void loadSchemaTypeAndParent(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelType> xmlType,
            const std::map<std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelType> >& types,
            const std::map<std::string, std::vector<std::string> >& classNameHierarchyMap
            );
    void loadSchemaType(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelType> xmlType,
            const std::map<std::string, std::vector<std::string> >& classNameHierarchyMap
            );
    void loadParentTypes(
            const std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelType> >& xmlTypes,
            const std::map<std::string,  std::vector<std::string> >& classNameHierarchyMap
            );
    std::map<std::string, std::vector<std::string> > loadClassNameHierarchy(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelSchema> wireModelSchema
            ) const;





};

}}}//end namespace


#endif
