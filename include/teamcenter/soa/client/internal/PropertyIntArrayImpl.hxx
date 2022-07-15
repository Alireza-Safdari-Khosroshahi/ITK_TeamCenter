/*==============================================================================
Copyright 2009.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==============================================================================*/

/**
    @file

    A int array property on a Client Data Model object.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYINTARRAYIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYINTARRAYIMPL_HXX

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


//IntVector property class
class PropertyIntArrayImpl : public PropertyImpl
{
public:
    PropertyIntArrayImpl();
    virtual ~PropertyIntArrayImpl();

    virtual const IntVector& getIntArrayValue() const;
    virtual bool operator == (const PropertyImpl* right) const;

    SOA_CLASS_NEW_OPERATORS

protected:
    void convert(  const std::string& val );

private:

    friend class ModelManagerImpl;

    IntVector    m_intArray;
};

}}} //edn namespace
#endif //TEAMCENTER_SOA_CLIENT_PROPERTYINTARRAYIMPL_HXX


