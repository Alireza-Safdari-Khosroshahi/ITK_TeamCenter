/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVVALUEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_LOVVALUEIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/LovValue.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>





namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {



class LovValueImpl: public Teamcenter::Soa::Client::LovValue
{
public:


   /**
    * @param displayValue       The localized value.
    * @param description        The element's description
    * @param dipslayDescription The element's displayable description
    * @param childLovChoices   A map of LovInfo that can be used for the next level of LOVs for Interdependent or Coordinated LOV.
    *                         The map is keyed by conditionName
    */
    LovValueImpl(
                 const std::string& displayValue,
                 const std::string& description, const std::string& dipslayDescription,
                 ConditionChoices*   childLovChoices
                 );
    ~LovValueImpl();

    SOA_CLASS_NEW_OPERATORS

    virtual char        getCharacterValue();
    virtual Teamcenter::Soa::Common::DateTime getDateTimeValue();
    virtual double      getDoubleValue();
    virtual int         getIntegerValue();
    virtual std::string getStringValue();
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getModelObjectValue();

    virtual std::string getDisplayValue();
    virtual std::string getFullDisplayValue( const std::string& delimiter );
    virtual bool hasDescription();
    virtual std::string getDescription();
    virtual std::string getDisplayDescription();
    virtual LovInfo* getChildLov();

protected:
    const std::string               mDisplayValue;
    const std::string               mDescription;
    const std::string               mDisplayDescription;
          ConditionChoices*          mChildLovChoices;
private:
    LovValueImpl(); //do not allow use of default
};

}}}//end namespace


#endif

