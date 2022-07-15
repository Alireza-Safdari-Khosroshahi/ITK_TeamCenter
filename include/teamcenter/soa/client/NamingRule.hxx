// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2013
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_NAMINGRULE_HXX
#define TEAMCENTER_SOA_CLIENT_NAMINGRULE_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/RulePattern.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>





#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * Naming rule of the property. Naming Rule is used to specify the patterns
 * the property value has to follow.
 * <pre>
 * Example:
 *  object_name. Its Name Rule is: "CSTMNOTE-"nnnnnn.
 *   The object name has to be: CSTMNOTE - 123456.
 * </pre>
 *
 */
class TCSOACLIENTMNGD_API NamingRule : public Chooseable
{
public:



    /** */
    enum RuleCase
    {
        Mixed,
        Lower,
        Upper
    };


    virtual ~NamingRule();
    /**
     * Name rule patterns of the property name rule.
     * If there are multiple patterns, they are returned as a comma separated string.
     * Example: Default Naming Rule for Custom Note item_id is "CSTMNOTE-"nnnnnn
     *
     * @return Name rule patterns of the property name rule.
     * @deprecated As of 10.0, use getPatterns.
     */
#ifdef WNT
__declspec(deprecated("As of 10.0, use getPatterns."))
#endif
    virtual std::string getPattern() =0;

    /**
     * @return  Mixed, Lower or Upper case letters
     */
    virtual RuleCase getCase() =0;

    /**
     * The list of naming patterns.
     * @return The list of naming patterns.
     * @since Teamcenter server 10.0
     */
    virtual std::vector<RulePattern*> getPatterns() = 0;

    SOA_CLASS_NEW_OPERATORS

protected:
    NamingRule();

};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

