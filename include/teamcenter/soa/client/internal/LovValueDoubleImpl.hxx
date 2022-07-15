/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVVALUEDOUBLEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_LOVVALUEDOUBLEIMPL_HXX

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



class LovValueDoubleImpl: public LovValueImpl
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
    LovValueDoubleImpl(
                 double value, const std::string& displayValue,
                 const std::string& description, const std::string& dipslayDescription,
                 ConditionChoices*   childLovChoices
                 );
    ~LovValueDoubleImpl();

    SOA_CLASS_NEW_OPERATORS

    virtual double      getDoubleValue();

private:
    const double                   mValue;
    
    LovValueDoubleImpl();
};

}}}//end namespace


#endif

