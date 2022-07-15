/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PROPERTYPOLICY_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_PROPERTYPOLICY_HXX

#include <string>
#include <map>
#include <set>

#include <teamcenter/soa/common/PolicyType.hxx>
#include <teamcenter/soa/server/ServicePolicy.hxx>



#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {
                class PropertyPolicy;
            }
        }
    }
}


/**
 * The base class for Property Policies.
 * Sub-classes to this class will gather Policies from a particular source, while
 * this class will ensure that propeties are inherited from parent classes, and
 * properties from referenced Perferences will be included.
 * Property inheritance will produce the following policy:
 *   User{volume, mailbox,home_folder }
 *   Pom_user { user_id, group}
 *
 *   Policy: User{volume, mailbox,home_folder,user_id, group }
 *
 * Referenced Prefenes will produce the following policy:
 *     BOMLine{ bl_has_children, bl_is_variant, Preference:PortalPSEColumnsShownPref}
 *
 * Policy: BOMLine{ bl_has_children, bl_is_variant, bl_indented_title, bl_item_object_type,bl_config_string}
 *
 **/
class TCSOASERVER_API Teamcenter::Soa::Internal::Server::PropertyPolicy
{
public:

    PropertyPolicy():namePropertyMap(){}

    virtual ~PropertyPolicy(){}


    /**
     * Returns an PolicyType (with list of properties) that reflects the current Policy
     * for the given Type or Class.
     *
     * @param typeName   Name of Type, may be blank
     * @param className  Name of Class, may  be blank
     *
     * @return Policy for this Type or Class.
     **/
    const Teamcenter::Soa::Common::PolicyType* getObjectProperties( const std::string& typeName, const std::string& className );

    /**
     * Returns the number of Types or Classes in this Policy.
     *
     **/
    virtual int size() const;

        virtual std::string getName()=0;

    /**
     * Return a string that represents this Object Property list.
     * The string will have the format:
     * TypeOrClassName { propertyName [,propertyName]...}
     *
     * @return String representation of this class
     **/
    std::string toString();

protected:

    /**
     * This method is used to retrieve the properties for a given type or class from the implementing sub-class.
     *
     **/
    virtual Teamcenter::Soa::Common::PolicyType getObjectProperties( const std::string& typeOrClassName ) =0;

    void clearCache();

private:

    const Teamcenter::Soa::Common::PolicyType* createPolicyForType  ( const std::string& typeName  );
    const Teamcenter::Soa::Common::PolicyType* createPolicyForClass ( const std::string& className );
    void expandPreferences( Teamcenter::Soa::Common::PolicyType& objProps ) const;
    void addFixedProperties( Teamcenter::Soa::Common::PolicyType& objProps, const std::string& typeName ) const;
    Teamcenter::Soa::Common::PolicyType createFullPolicy( const std::string& typeOrClassName, bool isType );
    std::string getParent( const std::string& typeOrClassName, bool isType ) const;



    std::map< std::string, Teamcenter::Soa::Common::PolicyType > namePropertyMap;
};




#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
