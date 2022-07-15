// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_PROPERTYIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_PROPERTYIMPL_HXX

#include <string>

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/Property.hxx>
#include <teamcenter/soa/client/internal/PropertyDescriptionImpl.hxx>

#include <teamcenter/soa/client/RuntimeException.hxx>

// Forward declare ClientDataModel and ModelObjectImpl
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class ClientDataModel;
class ModelObjectImpl;
        }
    }
}

// This is implementing the deprecated getDisplayableValue method,
// when the method is removed from interface, remove it from here, and this pragma push
#pragma warning ( push )
#pragma warning (  disable : 4996  ) 

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class PropertyImpl : public Teamcenter::Soa::Client::Property
{
public:
    virtual std::string              getDisplayValue() const;
    virtual std::string              getDisplayableValue() const;
    virtual std::vector<std::string> getDisplayableValues() const;

    virtual PropertyDescription*  getPropertyDescription() const;
    virtual bool isNull() const;
    virtual bool isModifiable() const;

    virtual         char    getCharValue() const;
    virtual const   Teamcenter::Soa::Common::DateTime& getDateTimeValue() const;
    virtual         double  getDoubleValue() const;
    virtual         float   getFloatValue() const;
    virtual         int     getIntValue() const;
    virtual         bool    getBoolValue() const;
    virtual         short   getShortValue() const;
    virtual         const   std::string& getStringValue() const;
    virtual         Teamcenter::Soa::Common::AutoPtr<ModelObject> getModelObjectValue() const;


    virtual const CharVector&        getCharArrayValue() const;
    virtual const Teamcenter::Soa::Common::DateTimeVector&  getDateTimeArrayValue() const;
    virtual const DoubleVector&      getDoubleArrayValue() const;
    virtual const FloatVector&       getFloatArrayValue() const;
    virtual const IntVector&         getIntArrayValue() const;
    virtual const BoolVector&        getBoolArrayValue() const;
    virtual const ShortVector&       getShortArrayValue() const;
    virtual const StringVector&      getStringArrayValue() const;
    virtual const ModelObjectVector& getModelObjectArrayValue() const;

    virtual ~PropertyImpl();

    void addRawValue( const std::string& str, ClientDataModel* clientDataModel, bool isNull );

    void setNull();
    virtual bool operator == (const PropertyImpl* right) const = 0;
    virtual bool operator != (const PropertyImpl* right) const;
    static std::string retrievePropertyValue(Property* prop);
    SOA_CLASS_NEW_OPERATORS

protected:
    PropertyImpl():
        m_displayVals(), m_propDesc(0), 
        m_modifiable(false), m_isNull(false)
        {}

        static PropertyImpl* createPropertyObject( const std::vector<std::string>& uiVals, const std::string& uiVal, bool modifiable, PropertyDescription* desc );
       
    friend class ModelObjectImpl;
    friend class DefaultObjectFactory;

 
    void typeMismatch(PropertyDescription::PropertyType type ) const;
    virtual void convert(  const std::string& val );
    virtual void convert(  const std::string& val ,ClientDataModel* clientDataModel );
    bool isValidConversion( PropertyDescription::PropertyType pt, bool bArray ) const;

    std::vector<std::string> m_displayVals;

    PropertyDescription* m_propDesc;

    bool m_modifiable;
    bool m_isNull;
};

}}} //edn namespace

#pragma warning ( pop )

#endif


