/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_XMLPROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_XMLPROPERTYPOLICY_HXX

#include <string>
#include <map>
#include <set>

#include <unidefs.h>    // must be before SaxToNodeParser

#include <teamcenter/soa/internal/server/PropertyPolicy.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>




#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {
                class XmlPropertyPolicy;
            }
        }
    }
}


/**
  * The XmlPropertyPolicy will create Policies based on XML configuration files.
  *<pre>
  *<ObjectPropertyPolicy xmlns="http://teamcenter.com/Schemas/Soa/ObjectPropertyPolicy" >
  *     <Include file="RAC_Site_Policy.xml">
  *     <ObjectType name="WorkspaceObject">
  *        <Property name="object_string" />
  *        <Property name="object_type" />
  *        <Property name="reservation" />
  *     </ObjectType>
  *     <ObjectType name="User">
  *        <Property name="user_name"/>
  *        <Property name="default_group"/>
  *        <Property name="home_folder" withProperties="true"/>
  *        <Property name="userinbox"/>
  *     </ObjectType>
  *     <ObjectType name="Item">
  *        <Property name="has_variant_module" />
  *        <Property name="is_configuration_item" />
  *     </ObjectType>
  *        <ObjectType name="ItemRevision">
  *        <Property name="view" />
  *        <Property name="items_tag" />
  *     </ObjectType>
  *     <ObjectType name="BOMLine">
  *        <Property  name="bl_has_children" />
  *        <Property  name="bl_is_variant" />
  *        <Preference name="PortalPSEColumnsShownPref" />
  *  </ObjectType>
  *</ObjectPropertyPolicy>
  *</pre>
  * In the above examples Item and ItemReviesion objects will not only have the
  * property values returned for the properties defined under those types but also
  * the properties defined under WorkspaceObject, since WorkspaceObject is the
  * parent object for both Item and ItemRevision. BOMLine objects will have property
  * values for the two properties explicitly named and all of the property names
  * defined in the Preference variable PortalPSEColumnsShownPref. <br>
  *
  * Optionally the Property element can include the withProperties attribute. By default the
  * Object Property Policy is applied only to the objects explicitly returned by the service
  * implemenation. So if the service returns a 'User' object and the 'home_folder' property is
  * part of the policy, the referenced 'home_folder' obect will be added to the return data, but
  * without any associated properties. By adding withProperties="true" to the 'home_folder' property,
  * properties for home folder will also be returned.<br>
  *
  * Additional types and properties specified in the RAC_Site_Policy.xml file will be included in this Policy.
  *
  **/
class TCSOASERVER_API Teamcenter::Soa::Internal::Server::XmlPropertyPolicy :
               public Teamcenter::Soa::Internal::Server::PropertyPolicy
{
public:
    static const  std::string     POLICY_NAME;


    /**
     * Set the current Policy.
     * A Policy configuration XML file with the name of the policy in the
     * TC_Data/soa/policies folder is loaded.
     *
     * @param policyName    Name of the Policy
     * @return              Instance of the XmlPropertyPolicy that represents the XML configuration file.
     * @throws DomException If the policy file does not exist or there are errors in parsing it.
     **/
    static XmlPropertyPolicy* createPolicy ( const std::string& policyName );


    /**
     * Create in instance of an XmlPropertyPolicy.
     *
     * @param xmlPolicyFile     Full path to the XML policy file
     * @return                  Instance of the XmlPropertyPolicy that represents the XML configuration file.
     * @throws DomException     If the policy file does not exist or there are errors in parsing it.
     **/
    XmlPropertyPolicy( const std::string& policyName, const std::string& xmlPolicyFile );

    virtual int size() const;
    virtual std::string getName();


    std::vector<std::string> getTypeNames() const;
    Teamcenter::Soa::Common::PolicyType* getType( const std::string& name ) const;

protected:
    virtual Teamcenter::Soa::Common::PolicyType getObjectProperties( const std::string& typeOrClassName );


private:
    XmlPropertyPolicy():PropertyPolicy(), xmlNamePropertyMap(),policyName(){}

    static const std::string  OPP_NODE;
    static const std::string  INCLUDE_NODE;
    static const std::string  OBJECTTYPE_NODE;
    static const std::string  PROPERTY_ELEMENT;
    static const std::string  PREFERENCE_ELEMENT;
    static const std::string  FILE_ATTR;
    static const std::string  NAME_ATTR;

    static     std::map< std::string, Teamcenter::Soa::Internal::Server::XmlPropertyPolicy* > namePolicyMap;
    bool ToBoolean(std::string str) const;

    void processIncludeNode( const std::string& xmlPolicyFile, const Teamcenter::Soa::Common::Xml::XMLNode& node );
    void processTypeNode   ( const Teamcenter::Soa::Common::Xml::XMLNode& node,Teamcenter::Soa::Common::ObjectPropertyPolicy objPropPolicy);
    void addProperties     ( std::map< std::string, Teamcenter::Soa::Common::PolicyType >& thatNamePropertyMap );
    void addProperty       ( const Teamcenter::Soa::Common::PolicyType& thatObjProps );

    std::map< std::string, Teamcenter::Soa::Common::PolicyType > xmlNamePropertyMap;
    std::string policyName;


};



#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
