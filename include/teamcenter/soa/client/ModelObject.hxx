/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

/**
    @file

    This is the root Client Data Model Object.
    This object is a client side representation of Objects from the Teamcenter
    Data Model. When the SOA Client Framework is operating with a Generic Client Data
    Model this object will represent all server objects, when operating in
    a Strongly Typed Client Data Model, this object is the root object for all Client
    Data Model objects.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_MODELOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODELOBJECT_HXX

#include <string>
#include <new>
#include <set>
#include <list>
#include <teamcenter/soa/common/Counted.hxx>
#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/Property.hxx>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>

#define MODELOBJECT_NULLID  "AAAAAAAAAAAAAA"

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
class ModelObjectImpl;
class TypeImpl;
class Property;

class TCSOACLIENTMNGD_API ModelObject: public Teamcenter::Soa::Common::Counted
{
public:


    /**
     * Returns the UID for this object.
     *
     * @return       The model's unique identifier
     */
    const std::string& getUid() const;


    /**
     * Returns the Type for this object.
     *
     * @return      The Type
     */
    Teamcenter::Soa::Client::Type* getType();

    /**
     * Returns the list of poperty names.
     *
     * @return       List of names
     */
    const std::vector<std::string> getPropertyNames();



    /**
     * Returns the named property.
     *
     * @param name   The name of the desired property.
     * @return       The property
     * @throws NotLoadedException The client data model is sparsly populated with properties
     * returned with service calls. If this property has not been returned the NotLoadedException
     * is thrown.
     */
    Teamcenter::Soa::Client::Property* getProperty( const std::string& name );

    /**
     * Returns the display value of the named property.
     *
     * @param name   The name of the desired property.
     * @return       The display value of the named Property.
     * @throws NotLoadedException The client data model is sparsely populated with properties
     * returned with service calls. If this property has not been returned the NotLoadedException
     * is thrown.
     *
     */
    std::string getPropertyDisplayableValue( const std::string& name );

    /**
     * Returns the list of display values of the named property.
     *
     * @param name   The name of the desired property.
     * @return       The list of display values of the named Property.
     * @throws NotLoadedException The client data model is sparsely populated with properties
     * returned with service calls. If this property has not been returned the NotLoadedException
     * is thrown.
     *
     */
    std::vector<std::string> getPropertyDisplayableValues( const std::string& name );

    std::string toString();
    static  void stats();

    SOA_CLASS_NEW_OPERATORS


protected:
    ModelObject();

    void setModelObjectImpl( ModelObjectImpl* impl );
    virtual ~ModelObject();

    friend class ModelManagerImpl;
    friend class DefaultObjectFactory;
    friend class DefaultClientDataModel;

private:

    static   int     nInstantiated;
    static   int     nDeleted;

    std::string toString(const std::string& pad, std::set<std::string>& uids );


    ModelObjectImpl* m_impl;

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
