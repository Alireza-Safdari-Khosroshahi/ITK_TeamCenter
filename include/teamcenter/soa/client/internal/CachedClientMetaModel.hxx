// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.




#ifndef TEAMCENTER_SOA_CLIENT_CACHEEDCLIENTMETAMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_CACHEEDCLIENTMETAMODEL_HXX

#include <string>
#include <vector>
#include <map>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/internal/CachelessClientMetaModel.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>
#include <teamcenter/soa/client/ObjectFactory.hxx>
#include <teamcenter/soa/client/ClientDataModel.hxx>
#include <teamcenter/soa/client/FccProxy.hxx>
#include <teamcenter/soa/common/Version.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/internal/common/ZipFile.hxx>
#include <teamcenter/services/core/SessionService.hxx>

#include <teamcenter/schemas/soa/_2011_06/metamodel/ModelType.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/PropertyDescriptor.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/LovL10N.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/DatasetAction.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/DatasetReference.hxx>
#include <teamcenter/schemas/soa/_2011_06/metamodel/TypeL10N.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


            class Connection;

class CachedClientMetaModel : public CachelessClientMetaModel
{
public:
    
    explicit CachedClientMetaModel( Connection* connection );
    virtual ~CachedClientMetaModel();
    SOA_CLASS_NEW_OPERATORS





   /**
     * Initialize the Client Meta Model with a map of Feature Dataset to root folder that have the un-zipped data
     * @param dsFolderMap
     * @param connection
     */
    void initialize( const std::map<std::string,Teamcenter::Soa::Internal::Common::ZipFile*>& dsFolderMap );
protected:
    virtual void loadTypes(   const std::set<std::string>& typeKeys );
    virtual void loadLovInfo( const std::string& uid, Type* type );

public:
    virtual bool isTypeValid( const std::string& typeName );

private:

    static const std::string TypesDataset;
    static const std::string TypesFile;
    static const std::string LovDataset;
    static const std::string LovIndexFile;
    static const std::string ToolsDataset;
    static const std::string ToolsFile;
    static const std::string TypeLocaleDataset;
    static const std::string TypeLocaleFile;
    static const std::string LovLocaleDataset;
    static       FccProxy*   fmu;
    std::string              encoding;

    ObjectFactory*   factory;

    std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool> >  toolData;
    std::map<std::string,std::string>                 lovIndex;
    std::vector<std::map<std::string,std::string> >   lovL10NIndex;
    bool                                        initialized;
    std::vector<std::string>                    locales;
    std::map<std::string,Teamcenter::Soa::Internal::Common::ZipFile*>           mDatasetName2ZipFileMap;

    static std::string replaceAll( const std::string& source, const std::string& from, const std::string& to);

    CachedClientMetaModel(); // don't allow use of default

    void initLocales(  );
    void initialize (  );


    ///**
    // * Load the named types from the local cache of data (xml files). Any types not loaded
    // * are returned a 'missing' list that will be processed by the parent ClientMetaModel (loaded from server)
    // *
    // * @param typeKeys      std::vector type type names
    // * @param connection    The connection to resolve dynamic data
    // * @return              std::vector of types not loaded from the cache
    // */
    std::set<std::string> loadTypesFromCache( const std::vector<std::string>& typeNames );

    /**
     * Load the named type from the local cache of data (JAXB object).
     * Distinguish between normal types and Dataset types, load property data, and nested LOV data
     *
     * @param typeName      The desired type name
     * @param xmlType       The JAXB representation of this type from the cache
     * @param connection    The connection used to get dynamic data
     */
    void parseModelType( const std::string& typeName,
                          Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::ModelType> xmlType );



    /**
     * Parse the all of the property data for the given type
     *
     * @param typeUid           The UID of the parent type
     * @param typeName          The name of the parent type
     * @param xmlDescriptors    The JAXB representation of the properties from the cache
     * @param typeL10Ns         The JAXB representation of the L10n data from the cache
     * @param connection        The connection to resolve dynamic data
     * @return                  The list of constructed PropertyDescriptions
     */
    void  parsePropertyDescriptorFromCache(
                const std::string& typeUid, const std::vector<std::string>& typeNameHierarchy,
                const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& xmlDescriptors,
                const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeL10N> >& typeL10Ns,
                std::map<std::string,PropertyDescription*>& pds
                );






    int getArraySize(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> xmlDescriptor
            ) const;
    int getLovCategory(
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> xmlDescriptor
            ) const;
    void getIntegerList(
            const std::string& numbers,
            std::vector<int>& intList
            ) const;






    /**
     * Parse the all of the LOVs associated with the given Property
     * This will return all of the LOVs in a ConditionChoide struct that
     * will resolve which LOV the client application will see at the time of access (PropertyDescription.getLov())
     *
     * @param typeName              The name of the Type associated with this LOV
     * @param propName              The name of the Property associated with this LOV
     * @param xmlDescriptor         The JaXB representation of the LOVRerfernce from the cache
     * @param connection            The connection object for dynamic data
     * @return                      The list of LOV choices available for this property
     */
    ConditionChoices* parseLovReferences(
            const std::vector<std::string>& typeNameHierarchy,
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> xmlDescriptor,
            std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& xmlDescriptors
            );





    ConditionChoices* parseLovRange(
            const std::string& lovUid,
            Type*   lovType,
            int lovValueType,
            Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovInfo> xmlLovInfo,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& lovL10Ns
            );

    ConditionChoices* parseLovValues(
            const std::string& lovUid,
            Type*   lovType,
            int lovValueType,
            LovInfo::Usage usage,
            const std::string& lovName,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue> >& xmlValues,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& lovL10Ns
            );


    void loadModelObjects(
            const std::string& lovName,
            int lovValueType,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue> >& xmlValues
            ) const;
    void geTypeL10ns(
            const std::string& typeName,
            std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeL10N> >& typeL10ns
            );
    std::string getLocalizedTypeName(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeL10N> >& typeL10ns,
            const std::string& typeName
            ) const;
    std::string getLocalizedPropName(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::TypeL10N> >&typeL10ns,
            const std::string& propName
            ) const;
    void getLovL10Ns(
            const std::string& uid,
            std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& myLovL10Ns
            );
    std::string getLocalizedLovName(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& myLovL10Ns,
            const std::string& lovName
            ) const;
    std::string getLocalizedLovDescription(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& myLovL10Ns,
            const std::string& lovDescription
            ) const;
    std::string getLocalizedLovValue(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& myLovL10Ns,
            const std::string& xmlValue,
            int lovValueType,
            ClientDataModel* clientDataModel,
            bool isRange
            ) const;
    std::string getLocalizedLovValueDescription(
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> >& myLovL10Ns,
            const std::string& description
            ) const;
    void getADatasetFile(
            const Teamcenter::Services::Core::_2011_06::Session::Feature& clientMetaModelFeature,
            const std::string& dataset,
            std::map<std::string,Teamcenter::Soa::Internal::Common::ZipFile*>& datasetName2ZipFileMap ); //throws InternalServerException



    void getCacheZipFiles(
            const Teamcenter::Services::Core::_2011_06::Session::Feature&  clientMetaModelFeature,
            const std::vector<std::string>& locales,
            std::map<std::string,Teamcenter::Soa::Internal::Common::ZipFile*>& datasetName2ZipFileMap
           );
    void clearDatasetZipMap( std::map<std::string,Teamcenter::Soa::Internal::Common::ZipFile*>& ds2ZipMap );


    static std::string getListOfNames(
            const std::vector<std::string>& typeKeys
            );
    static std::string getPropertyDescriptorNames(
            const std::string& typeName,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::PropertyDescriptor> >& descriptors
            );
    static std::string getPropertyLovValues(
            const std::string& name,
            const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovValue> >& values
            );




    static void indexLovData(
            Teamcenter::Soa::Internal::Common::ZipFile* lovZipFile,
            std::map<std::string,std::string>& lovData,
            const std::string& encodingStr
            );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovInfo> parseLovInfo(
            const std::string& uid
            );
    static void  indexLovL10nData(
            const std::map<std::string,Teamcenter::Soa::Internal::Common::ZipFile*>& ds2ZipMap,
            const std::vector<std::string>& locales,
            std::vector<std::map<std::string,std::string> >& lovData,
            const std::string& encodingStr
            );
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::LovL10N> parseLovL10NInfo(
            const std::string& datasetName,
            const std::string& xmlFile
            ) const;
    static void indexTools(
            Teamcenter::Soa::Internal::Common::ZipFile* toolZipFile,
            std::map<std::string,Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2011_06::Metamodel::Tool> >& toolData,
            const std::string& encodingStr
            );
    

    static bool extractFileFromZip( 
        Teamcenter::Soa::Internal::Common::ZipFile* zipFile, 
        const std::string& entryName,
        const std::string& encodingName,
        Teamcenter::Soa::Common::Xml::SAXToNodeParser &  parser
        );

};

}}}//end namespace


#endif
