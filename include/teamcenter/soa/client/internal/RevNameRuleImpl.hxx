/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_REVNAMERULEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_REVNAMERULEIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/RevNameRule.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class RevNameRuleImpl: public RevNameRule
{
public:


    static RevNameRule::RuleType constructRuleType( int value );
    static RevNameRule::SupplementalRuleType constructSuppRuleType( int value );
    static RevNameRule::AlphabeticCase constructAlphaCase( int value );


    /**
     * Constructor
     *
     * @param name
     * @param start
     * @param type
     * @param excludeLetters
     */
    RevNameRuleImpl(
                    const std::string& name,
                    const std::string& initStart,   const std::string& initDescription,   RevNameRule::RuleType initType,
                    const std::string& secondStart, const std::string& secondDescription, RevNameRule::RuleType secondType,
                    bool excludeLetters, const std::string& skipLetters,
                    RevNameRule::AlphabeticCase alphaCase, RevNameRule::SupplementalRuleType suppRuleType
                    );
    ~RevNameRuleImpl();

    virtual std::string getName();
    virtual std::string getStartingRevision();
    virtual std::string getDescription ();
    virtual RuleType getType();
    virtual std::string getSecondaryStartingRevision ();
    virtual std::string getSecondaryDescription ();
    virtual RuleType getSecondaryType();
    virtual bool exludeSkipLetters();
    virtual std::string getSkipLetters ();
    virtual AlphabeticCase getAlphabeticCase();
    virtual SupplementalRuleType getSupplementalType();


    SOA_CLASS_NEW_OPERATORS

private:
    RevNameRuleImpl(); // do not allow use of default

    const std::string                 mName;
    const std::string                 mInitStart;
    const std::string                 mInitDescription;
    const RevNameRule::RuleType       mInitType;
    const std::string                 mSecondStart;
    const std::string                 mSecondDescription;
    const RevNameRule::RuleType       mSecondType;
    const bool                        mExcludeLetters;
    const std::string                 mSkipLetters;
    const RevNameRule::AlphabeticCase mAlphaCase;
    const RevNameRule::SupplementalRuleType  mSuppType;



};

}}}//end namespace


#endif

