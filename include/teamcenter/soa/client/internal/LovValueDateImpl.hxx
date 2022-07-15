/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVVALUEDATEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_LOVVALUEDATEIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/internal/LovValueImpl.hxx>





namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {



class LovValueDateImpl: public LovValueImpl
{
public:


   /**
    * @param value              The value
    * @param displayValue       The localized value.
    * @param description        The element's description
    * @param dipslayDescription The element's displayable description
    * @param childLovChoices   A map of LovInfo that can be used for the next level of LOVs for Interdependent or Coordinated LOV.
    *                         The map is keyed by conditionName
    */
    LovValueDateImpl(
                 const Teamcenter::Soa::Common::DateTime& value, const std::string& displayValue,
                 const std::string& description, const std::string& dipslayDescription,
                 ConditionChoices*   childLovChoices
                 );
    ~LovValueDateImpl();

    SOA_CLASS_NEW_OPERATORS

    virtual Teamcenter::Soa::Common::DateTime getDateTimeValue();

private:
    const  Teamcenter::Soa::Common::DateTime               mValue;


    LovValueDateImpl();

};

}}}//end namespace


#endif

