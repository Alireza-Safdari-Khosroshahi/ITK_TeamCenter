/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_SERVER_TYPESCHEMA_HXX
#define INCLUDE_TEAMCENTER_SOA_SERVER_TYPESCHEMA_HXX

#include <string>
#include <map>
#include <set>

#include <unidefs.h>    // must be before SaxToNodeParser

#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/common/xml/XmlUtils.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/TypeSchema.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/ModelType.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/Tool.hxx>

#include <pom/eim/eim.h>
#include <pom/eim/eim_dm.h>
#include <tcgateway/tcpolicy.hxx>        // Use TcGateway Policy stuff

#include <teamcenter/soa/server/SoaServerExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Server
        {

/**
 */
class TCSOASERVER_API TypeSchema
{
public:

    TypeSchema();
    TypeSchema( const TypeSchema& right);
    virtual ~TypeSchema();

    void addType  ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> modelType );
    void addTool  ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool>      tool );


    void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out) const ;
    void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeSchema>& getWireData() const { return m_wireTypeSchema;}



private:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeSchema>        m_wireTypeSchema;

    // Don't allow copy constructors
    TypeSchema& operator = ( const TypeSchema& right);


};        // End Class
}}}      // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif

