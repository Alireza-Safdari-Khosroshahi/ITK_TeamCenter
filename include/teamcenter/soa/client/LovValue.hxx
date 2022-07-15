/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_LOVVALUE_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            class LovInfo;



class TCSOACLIENTMNGD_API LovValue: public Chooseable
{
public:


    virtual ~LovValue();


    /**
     * @return The element's  value as a char. Valid only if value type is {@link PropertyDescription#CLIENT_PROP_TYPE_char}
     */
    virtual char getCharacterValue()=0;


    /**
     * @return The element's  value as a Calendar. Valid only if value type is {@link PropertyDescription#CLIENT_PROP_TYPE_date}
     */
    virtual Teamcenter::Soa::Common::DateTime getDateTimeValue()=0;


    /**
     * @return The element's  value as a double. Valid only if value type is {@link PropertyDescription#CLIENT_PROP_TYPE_double}
     */
    virtual double getDoubleValue()=0;


    /**
     * @return The element's  value as a int. Valid only if value type is {@link PropertyDescription#CLIENT_PROP_TYPE_int}
     */
    virtual int getIntegerValue()=0;


    /**
     * @return The element's  value as a String. Valid only if value type is {@link PropertyDescription#CLIENT_PROP_TYPE_string}
     */
    virtual std::string getStringValue()=0;


    /**
     * @return The element's  value as a ModelObject. Valid only if value type is {@link PropertyDescription#CLIENT_PROP_TYPE_ModelObject}
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getModelObjectValue()=0;


    /**
     * @return The element's localized (displayable) value.
     */
    virtual std::string getDisplayValue()=0;


    /**
     * The element may have and an optional description.
     * When present the display value and the display description are returned as a singled string.
     * <pre>
     * Example:  '01, Engineer'
     *   Where 01       is the value
     *         Engineer is the description
     *</pre>
     * If the value does not have description attached this method will return just the display value.
     *
     * @param delimiter     Delimiter to use between the value and description
     *
     * @return  The full displayable value
     */
    virtual std::string getFullDisplayValue( const std::string& delimiter )=0;


    /**
     * The element may have and an optional description.
     * When present the value and the description should both be displayed
     * <pre>
     * Example:  '01, Engineer'
     *   Where 01       is the value
     *         Engineer is the description
     *</pre>
     *
     * @return True if there is a description

     */
    virtual bool hasDescription()=0;

    /**
     * @return The element's description.
     */
    virtual std::string getDescription()=0;



    /**
     * @return The element's localized displayable description
     */
    virtual std::string getDisplayDescription()=0;


    /**
     * @return The next level of LOVs for Interdependent or Coordinated LOV.
     */
    virtual LovInfo* getChildLov()=0;


    SOA_CLASS_NEW_OPERATORS


protected:
     LovValue();


};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif


