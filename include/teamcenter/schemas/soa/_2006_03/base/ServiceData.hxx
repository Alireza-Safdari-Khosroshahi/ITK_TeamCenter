/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_SERVICEDATA_HXX
#define TEAMCENTER__SCHEMAS__SOA___2006_03__BASE_SERVICEDATA_HXX


#include <vector>
#include <string>
#include <set>
#include <ostream>
#include <new> // for size_t

#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/xml/BaseObject.hxx>
#include <teamcenter/soa/common/xml/XmlUtils.hxx>
#include <teamcenter/soa/common/xml/XmlStream.hxx>
#include <teamcenter/soa/common/xml/JsonStream.hxx>

#include <teamcenter/schemas/soa/_2006_03/base/RefId.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelObject.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ObjectMap.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ErrorStack.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2006_03
            {
                namespace Base
                {

                    class ServiceData;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<ServiceData> > ServiceDataArray;
                    class RefId;
                    class ModelObject;
                    class ObjectMap;
                    class ErrorStack;

                }
            }
        }
    }
}





class TCSOACOMMON_API Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    ServiceData(   );


    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& getUpdatedObjArray() const;
    void setUpdatedObjArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& updatedObjs );
    void addUpdatedObj( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId>& updatedObj );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& getDeletedObjArray() const;
    void setDeletedObjArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& deletedObjs );
    void addDeletedObj( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId>& deletedObj );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& getCreatedObjArray() const;
    void setCreatedObjArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& createdObjs );
    void addCreatedObj( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId>& createdObj );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& getChildChangeObjArray() const;
    void setChildChangeObjArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& childChangeObjs );
    void addChildChangeObj( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId>& childChangeObj );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& getPlainObjArray() const;
    void setPlainObjArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >& plainObjs );
    void addPlainObj( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId>& plainObj );
    const std::vector<std::string>& getUpdatedArray() const;
    void setUpdatedArray( const std::vector<std::string>& updated );
    void addUpdated( const std::string& updated );
    const std::vector<std::string>& getDeletedArray() const;
    void setDeletedArray( const std::vector<std::string>& deleted );
    void addDeleted( const std::string& deleted );
    const std::vector<std::string>& getCreatedArray() const;
    void setCreatedArray( const std::vector<std::string>& created );
    void addCreated( const std::string& created );
    const std::vector<std::string>& getChildChangeArray() const;
    void setChildChangeArray( const std::vector<std::string>& childChange );
    void addChildChange( const std::string& childChange );
    const std::vector<std::string>& getPlainArray() const;
    void setPlainArray( const std::vector<std::string>& plain );
    void addPlain( const std::string& plain );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> >& getDataObjectArray() const;
    void setDataObjectArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> >& dataObjects );
    void addDataObject( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& dataObject );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectMap> >& getModelObjectArray() const;
    void setModelObjectArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectMap> >& modelObjects );
    void addModelObject( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectMap>& modelObject );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack> >& getPartialErrorArray() const;
    void setPartialErrorArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack> >& partialErrors );
    void addPartialError( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack>& partialError );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "ServiceData" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual ServiceData* reallyClone();

         std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >   m_updatedObjs;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >   m_deletedObjs;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >   m_createdObjs;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >   m_childChangeObjs;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::RefId> >   m_plainObjs;
    std::vector<std::string>   m_updated;
    std::vector<std::string>   m_deleted;
    std::vector<std::string>   m_created;
    std::vector<std::string>   m_childChange;
    std::vector<std::string>   m_plain;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> >   m_dataObjects;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectMap> >   m_modelObjects;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ErrorStack> >   m_partialErrors;

};


#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

