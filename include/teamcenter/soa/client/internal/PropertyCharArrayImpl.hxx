/*==============================================================================
Copyright 2009.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==============================================================================*/

/**
    @file

    A char array property on a Client Data Model object.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYCHARARRAYIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYCHARARRAYIMPL_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Property.hxx>
#include <teamcenter/soa/client/internal/PropertyImpl.hxx>
#include <teamcenter/soa/client/internal/PropertyDescriptionImpl.hxx>
#include <teamcenter/soa/client/internal/ModelManagerImpl.hxx>
#include <teamcenter/soa/client/RuntimeException.hxx>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


//Char array property class
class PropertyCharArrayImpl : public PropertyImpl
{
public:
    PropertyCharArrayImpl();
    virtual ~PropertyCharArrayImpl();

    virtual const CharVector& getCharArrayValue() const;
    virtual bool operator == (const PropertyImpl* right) const;

    SOA_CLASS_NEW_OPERATORS

protected:
    void convert(  const std::string& val );

private:

    friend class ModelManagerImpl;

    CharVector   m_charArray;
};
}}} //edn namespace
#endif //TEAMCENTER_SOA_CLIENT_PROPERTYCHARARRAYIMPL_HXX


