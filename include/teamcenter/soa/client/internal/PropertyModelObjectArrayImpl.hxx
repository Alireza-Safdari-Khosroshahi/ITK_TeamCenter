/*==============================================================================
Copyright 2009.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==============================================================================*/

/**
    @file

    A ModelObject array property on a Client Data Model object.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYMODELOBJECTARRAYIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYMODELOBJECTARRAYIMPL_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Property.hxx>
#include <teamcenter/soa/client/internal/PropertyImpl.hxx>
#include <teamcenter/soa/client/internal/PropertyDescriptionImpl.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/RuntimeException.hxx>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

//ModelObjectVector property class
class PropertyModelObjectArrayImpl : public PropertyImpl
{
public:
    PropertyModelObjectArrayImpl();
    virtual ~PropertyModelObjectArrayImpl();

    virtual const ModelObjectVector& getModelObjectArrayValue() const;
    virtual bool operator == (const PropertyImpl* right) const;

    SOA_CLASS_NEW_OPERATORS

protected:
    void convert(  const std::string& val , ClientDataModel* clientDataModel );

private:
 

    ModelObjectVector   m_ModelObjectArray;
};
}}} //edn namespace
#endif //TEAMCENTER_SOA_CLIENT_PROPERTYMODELOBJECTARRAYIMPL_HXX


