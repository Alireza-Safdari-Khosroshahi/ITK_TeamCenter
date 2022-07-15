// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_CLIENT_NAMINGRULEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_NAMINGRULEIMPL_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/NamingRule.hxx>





// This is implementing the deprecated getPattern method,
// when the method is removed from interface, remove it from here, and this pragma push
#pragma warning ( push )
#pragma warning (  disable : 4996  ) 


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class NamingRuleImpl : public NamingRule
{
public:

    /**
     * Constructor
     *
     * @param pattern
     * @param caze
     * @unpublished
     */
    NamingRuleImpl( const std::string& pattern, NamingRule::RuleCase caze, const std::vector<RulePattern*>& patterns);
    ~NamingRuleImpl();


    virtual std::string getPattern();
    virtual NamingRule::RuleCase getCase();
    virtual std::vector<RulePattern*> getPatterns();

    SOA_CLASS_NEW_OPERATORS
    /**
     * @param    s String to convert to a RuleCase
     * @return   The RuleCase for the given string
     */
    static RuleCase constructRuleCase( const std::string& s );

private:
    NamingRuleImpl(); // do not allow use of default
    const std::string               mPattern;
    const NamingRule::RuleCase      mCase;
    const std::vector<RulePattern*> mPatterns;




};

}}}//end namespace

#pragma warning ( pop )

#endif

