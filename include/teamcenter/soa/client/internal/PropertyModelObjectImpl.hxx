/*==============================================================================
Copyright 2009.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==============================================================================*/

/**
    @file

    A single ModelObject property on a Client Data Model object.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYMODELOBJECTIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYMODELOBJECTIMPL_HXX

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


//ModelObject property class
class PropertyModelObjectImpl : public PropertyImpl
{
public:
    PropertyModelObjectImpl();
    virtual ~PropertyModelObjectImpl();

    virtual Teamcenter::Soa::Common::AutoPtr<ModelObject> getModelObjectValue() const;
    virtual bool operator == (const PropertyImpl* right) const;

    SOA_CLASS_NEW_OPERATORS

protected:
    void convert(  const std::string& val , ClientDataModel*  clientDataModel );


private:


    Teamcenter::Soa::Common::AutoPtr<ModelObject> m_ModelObject;
};
}}} //edn namespace
#endif //TEAMCENTER_SOA_CLIENT_PROPERTYMODELOBJECTIMPL_HXX


