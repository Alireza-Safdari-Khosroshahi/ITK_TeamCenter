/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_SERVER_MODELSCHEMA_HXX
#define INCLUDE_TEAMCENTER_SOA_SERVER_MODELSCHEMA_HXX

#include <string>
#include <map>
#include <set>

#include <unidefs.h>    // must be before SaxToNodeParser

#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/common/xml/XmlUtils.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelSchema.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/ModelType.hxx>

#include <teamcenter/soa/server/SoaServerExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Server
        {

/**
 */
class TCSOASERVER_API ModelSchema
{
public:

    ModelSchema();
    ModelSchema( const ModelSchema& right);
    virtual ~ModelSchema();

    void addType  ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> modelType,
                    const std::vector<std::string>& trueConditions );

    void addClass ( const std::string& className, const std::string& superClassName );



    void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out) const ;
    void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelSchema>& getWireData() const { return m_wireModelSchema;}



private:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelSchema>        m_wireModelSchema;

    // Don't allow copy constructors
    ModelSchema& operator = ( const ModelSchema& right);


};        // End Class
}}}      // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif

