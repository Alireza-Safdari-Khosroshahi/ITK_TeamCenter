/*==============================================================================
Copyright 2009.
Siemens Product Lifecycle Management Software Inc.
All Rights Reserved.
==============================================================================*/

/**
    @file

    A single char property on a Client Data Model object.

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYDATETIMEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYDATETIMEIMPL_HXX

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

//DateTime property class
class PropertyDateTimeImpl : public PropertyImpl
{
public:
    PropertyDateTimeImpl();
    virtual ~PropertyDateTimeImpl();

    virtual const Teamcenter::Soa::Common::DateTime& getDateTimeValue() const;
    virtual bool operator == (const PropertyImpl* right) const;

    SOA_CLASS_NEW_OPERATORS

protected:
    void convert(  const std::string& val );

private:

    friend class ModelManagerImpl;

    Teamcenter::Soa::Common::DateTime m_datetime;
};


}}} //edn namespace
#endif //TEAMCENTER_SOA_CLIENT_PROPERTYDATETIMEIMPL_HXX


