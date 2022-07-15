//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_MODElOBJECTIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_MODElOBJECTIMPL_HXX

#include <string>
#include <map>
#include <new>
#include <list>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>

#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/internal/PropertyImpl.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelObject.hxx>

class Teamcenter::Soa::Client::ModelObjectImpl
{
public:
    /**
     * Returns the UID for this object.
     *
     * @return       The model's unique identifier
     */
    const std::string& getUid() const;

    /**
     * Returns the named property.
     *
     * @param name   The name of the desired property.
     * @return       The property
     */
    Property* getProperty( const std::string& name );
    /**
     * Returns the UI value of named property.
     *
     * @param name   The name of the desired property.
     * @return       The display value
     */
    std::string getPropertyDisplayableValue( const std::string& name );
    /**
     * Returns the UI values of named property.
     *
     * @param name   The name of the desired property.
     * @return       list of display values
     */
    std::vector<std::string> getPropertyDisplayableValues( const std::string& name );

    Type* getType();

    bool refineType( Type* newType );

    const std::vector<std::string> getPropertyNames();

    ModelObjectImpl( const std::string& uid, Type* type );
    ~ModelObjectImpl();
    void releaseProperties();

    void addProperty( const std::string& name, PropertyImpl* prop );
    void putProperty( const std::string& name, std::vector<std::string> values );


    typedef std::map< std::string, PropertyImpl* > PropertyMap;
    typedef std::map< std::string, std::vector<std::string> > DisplayMap;

    /**
     * Returns a copy of the properties list.
     * @return Property List
     *
     */
    std::map< std::string, Teamcenter::Soa::Client::PropertyImpl* > copyProperties();

    SOA_CLASS_NEW_OPERATORS

private:
    ModelObjectImpl(); // do not allow use of default

    friend class ModelManagerImpl;
    friend class DefaultObjectFactory;

    bool isTypeOf( Type* base );
    static std::vector<Teamcenter::Soa::Internal::Common::Mutex*> s_MapMutexes;

    std::string m_uid;
    PropertyMap m_props;
    DisplayMap  m_propsUIValues;
    Teamcenter::Soa::Internal::Common::Mutex *m_MapMutex;

    Type* m_type;
};


#endif
