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

#ifndef TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_DATASETACTION_HXX
#define TEAMCENTER__SCHEMAS__SOA___2011_06__METAMODEL_DATASETACTION_HXX


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

#include <teamcenter/schemas/soa/_2011_06/metamodel/ActionReference.hxx>


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_exports.h>

namespace Teamcenter
{
    namespace Schemas
    {
        namespace Soa
        {
            namespace _2011_06
            {
                namespace Metamodel
                {

                    class DatasetAction;
                    typedef std::vector< Teamcenter::Soa::Common::AutoPtr<DatasetAction> > DatasetActionArray;
                    class ActionReference;

                }
            }
        }
    }
}





class METAMODEL_API Teamcenter::Schemas::Soa::_2011_06::Metamodel::DatasetAction : 
        public Teamcenter::Soa::Common::Xml::BaseObject 
{
 public:
    
    DatasetAction(   );


    std::string& getToolName() ;
    const std::string& getToolName() const;
    void setToolName( const std::string& toolName );
    std::string& getAction() ;
    const std::string& getAction() const;
    void setAction( const std::string& action );
    const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ActionReference> >& getActionReferenceArray() const;
    void setActionReferenceArray( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ActionReference> >& actionReferences );
    void addActionReference( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ActionReference>& actionReference );


    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const { outputXML( out, "DatasetAction" ); }
    virtual void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out, const std::string& elementName ) const;
    virtual void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    virtual void getNamespaces( std::set< std::string >& namespaces ) const;
  
    virtual void writeJSON( Teamcenter::Soa::Common::Xml::JsonStream* stream ) const;
    virtual void parseJSON( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Internal::Json::JSONObject> node );

    
    SOA_CLASS_NEW_OPERATORS
    

protected:
    virtual DatasetAction* reallyClone();

         std::string   m_toolName;
    std::string   m_action;
    std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ActionReference> >   m_actionReferences;

};


#include <teamcenter/schemas/soa/_2011_06/metamodel/Metamodel_undef.h>
#endif

