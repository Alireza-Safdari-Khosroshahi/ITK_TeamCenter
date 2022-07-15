// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_CACHELESSCLIENTMETAMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_CACHELESSCLIENTMETAMODEL_HXX

#include <string>
#include <vector>
#include <map>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/internal/DefaultClientMetaModel.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>
#include <teamcenter/soa/client/Reference.hxx>
#include <teamcenter/soa/client/Tool.hxx>
#include <teamcenter/soa/common/Version.hxx>

#include <teamcenter/schemas/soa/_2011_06/metamodel/TypeSchema.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/ModelType.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/PropertyDescriptor.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/DatasetAction.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/DatasetType.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/DatasetReference.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/Tool.hxx>



namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


            class Connection;
/**
 * This is the default implementation of the ClientMetaModel.
 * The Meta Model will be backed by data retrieved interactively from the server.
 * This is done via calls to the SessionService.getTypeDescriptions
 *
 *
 */
class CachelessClientMetaModel : public DefaultClientMetaModel
{
public:
    explicit CachelessClientMetaModel( Connection* connection );
    virtual ~CachelessClientMetaModel();
    SOA_CLASS_NEW_OPERATORS



protected:
    virtual void loadTypes( const std::set<std::string>& typeKeys );

public:
    virtual bool isTypeValid( const std::string& typeName );

protected:

    ConditionChoices* parseNamingRule(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> xmlPd
            ) const;
    ConditionChoices* parseRenderers(  
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> xmlPd
            );
    ConditionChoices* parseRevNameRule(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> xmlType
            ) const;

    BasedOn* parseBasedOn (Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> xmlPd ) const;

    static std::vector<Lov::Style> getStyleList( const std::vector<std::string>& propNames, const std::string& condition, 
           std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& otherXmlDescriptors);

    void parseTools(
            const std::string& typeName,
            const std::vector<std::string>& xmlToolNames,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::DatasetAction> >& xmlDatasetActions,
            const std::map<std::string,Reference*>& dataSetReferences,
            const std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool> >& toolData,
            std::vector<Tool*>& tools
            );

private:
    CachelessClientMetaModel(); // don't allow use of default

    void getTypeDescriptions(
            const std::vector<std::string>& typeNames
            );
    void loadTypeSchema(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeSchema> xmlModelSchema
            );
    void loadParentTypes(
            const std::map<std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> >& xmlTypes
            );
    void loadSchemaTypeAndParent(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> xmlType,
            const std::map<std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> >& types,
            const std::map<std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool> >& tools 
            );
    void loadSchemaType(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> xmlType,
            const std::map<std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool> >& tools 
           );

    static std::string getPropertyDescriptorNames(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& descriptors
            );

    static std::string getListOfNames(
            const std::string& typeName,
            const std::vector<std::string>& names
            );

    static const Teamcenter::Soa::Common::Version MINIMUM_SERVER_VERSION;

};

}}}//end namespace


#endif
