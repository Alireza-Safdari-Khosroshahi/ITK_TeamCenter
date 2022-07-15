// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_TYPE_HXX
#define TEAMCENTER_SOA_CLIENT_TYPE_HXX

#include <string>
#include <map>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/PropertyDescription.hxx>
#include <teamcenter/soa/client/RevNameRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API Type
{
public:

    enum RevisionRuleCategory
    {
        /** The Property description does not have a  {@link RevNameRule}   */
        REVISION_RULECATEGORY_NONE = 0,
        /** There is a single {@link RevNameRule}  attached to this property description with the 'isTrue'  */
        REVISION_RULECATEGORY_ISTRUE = 1,
        /** There are one or more {@link NamingRule} attached to this type with conditions based on the
         *  current User Session. These  {@link RevNameRule}s should not be cached but instead retrieved from the
         *  {@link Type}  when ever it is display or used  */
        REVISION_RULECATEGORY_SESSIONCONDITION = 2
    };

    static const std::string TYPE_CONST_CREATE_INPUT;
    static const std::string TYPE_CONST_SAVE_AS_INPUT;
    static const std::string TYPE_CONST_ICON;

    virtual ~Type();


    /**
     * @param name Name of the desired property.
     * @return Returns the Property Description for the given property.
     */
    virtual Teamcenter::Soa::Client::PropertyDescription* getPropertyDescription( const std::string& name ) = 0;

    /**
     * The Unique Identifier of the Business Model type or class. This has the syntax of
     * TYPE::&lt;typeName&gt;::&lt;ClassName&gt;::&lt;ParentTypeName&gt;
     * (i.e. TYPE::User::User::POM_user, TYPE::Newstuff Folder::Folder::Folder).
     *
     * @return Returns the type's UID
     */
    virtual const std::string& getUid( ) = 0;

    /**
     * @return Returns the type name.
     */
    virtual const std::string& getName() = 0;

    /**
     * @return Returns the type's parent.
     */
    virtual Type* getParentType() = 0;

    /**
     * @return The localized (displayable) name of the type.
     */
    virtual const std::string& getUIFValue()= 0;

    /**
     * @return Returns true if a Match type.
     * @deprecated As of 9.0, there is no replacement for this method as the data is not relevant.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, there is no replacement for this method as the data is not relevant."))
#endif
    virtual bool isMatchType()= 0;

    /**
     * @return Returns the type's class name.
     */
    virtual const std::string& getClassName ()= 0;
    /**
     * The Unique Identifier of the Business Model type. This has the syntax of
     * TYPE::&lt;typeName&gt::&lt;ClassName&gt::&lt;ParentTypeName&gt
     *  (i.e. TYPE::ImanType::ImanType::POM_object, TYPE::ImanType::ImanType::POM_object).
     * @return Returns the type's UID.
     */
    virtual const std::string& getTypeUid()= 0;

    /**
     * @return Returns PropertyDescription for all of the type's properties.
     */
    virtual std::map<std::string, Teamcenter::Soa::Client::PropertyDescription*> getPropertyDescriptions()= 0;

    /**
     *
     * @return Return a array of the type's parent names
     */
    virtual const std::vector<std::string>& getClassNameHierarchy()= 0;    
    /**
     *
     * @param className Name of class
     * @return True if this type is child of the give class.
     */
    virtual bool isInstanceOf( const std::string& className )= 0;

    /**
     * The value for the named constant.
     *
     * <ul>
     * <li> {@link #TYPE_CONST_CREATE_INPUT}    Name of the create type descriptor.
     * <li> {@link #TYPE_CONST_SAVE_AS_INPUT}   Name of the save as type descriptor. Since Teamcenter Server 9.1
     * <li> {@link #TYPE_CONST_ICON}            Name of the icon file. Since %Teamcenter %Server 9.1
     *</ul>
     *
     * @param name The constant name
     * @return  The named constant value
     *
     * @since %Teamcenter %Server 9.0
     */
    virtual std::string  getConstant( const std::string&  name)=0;

    /**
     * The name of the owning type.
     * This applies only to Create Descriptor Types
     *
     * @return The name of the owning type.
     *
     * @since %Teamcenter %Server 9.0
     */
    virtual std::string getOwningType()=0;


    /**
     * @return  The map of constant Name/Value
     *
     * @since %Teamcenter %Server 9.0
     */
    virtual std::map<std::string,std::string>  getConstants( )=0;

    /**
     * Revision Rule for item revision id only.
     * The RevisionRuleCategory of this Type determines what will be returned from this method:
     * <UL>
     * <li> {@link #REVISION_RULECATEGORY_NONE}     No rules are attached, this method will always return null.
     * <li> {@link #REVISION_RULECATEGORY_ISTRUE}  A single rule is attached with the 'isTrue' condition, this method
     * will always return the same rule.
     * <li> {@link #REVISION_RULECATEGORY_SESSIONCONDITION} Multiple rules are attached to the type
     * with different session based conditions, however only a single rule applies at any given time.
     * The conditions are resolved at the time of the call to this method. When there are multiple true conditions,
     * the first rule with a true condition is the one that is returned. These rules should not be cached,
     * but instead retrieved from the Type when ever it is display or used.
     * </UL>
     * @return Revision Rule for item revision id only (may be null).
     * @see Type#getRevisionNamingRuleCategory()
     */
    virtual RevNameRule* getRevisionNamingRule()=0;

   /**
     * The category of the {@link RevNameRule} attached to this Type
     *
     * @return The category of {@link RevNameRule} attached to this Type
     *
     * @see Type#getRevisionNamingRule()
     */
    virtual RevisionRuleCategory getRevisionNamingRuleCategory() const =0;


    SOA_CLASS_NEW_OPERATORS


protected:
    friend class DefaultClientMetaModel;

};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
