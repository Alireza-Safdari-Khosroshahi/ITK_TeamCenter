/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVINFO_HXX
#define TEAMCENTER_SOA_CLIENT_LOVINFO_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>




#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            class Type;
            class LovValue;


class TCSOACLIENTMNGD_API LovInfo : public Chooseable
{
public:
     enum Usage
     {
       /** Provides valid well-defined values  */
       Exhaustive,

       /**
        * Provides suggested valid values; the user may enter their own value.
        */
       Suggestive,

       /**
        * Provides a subset (range) of valid values in terms of upper and lower ranges
        * (1,000 - 9,999,  1/1/2000 - 12/31/2009). The upper and lower range limits are inclusive;
        * in the above example the user may enter 1,000 or 9,999. The client application should validate
        * values entered by user, to give the user immediate feedback that of an invalid entry.
        * The server will ultimately validate to ensure invalid data is not persisted in the database.
        **/
       Range
     };



    virtual ~LovInfo();
    SOA_CLASS_NEW_OPERATORS


    /**
     * @return The UID of the List of Values. (14 character database UID)
     */
    virtual std::string getUid()=0;


    /**
     * @return The name of this LOV
     */
    virtual std::string getName()=0;

    /**
     * @return The localized (displayable) name of this LOV.
     */
    virtual std::string getDisplayName()=0;

    /**
     * @return The description of this LOV.
     */
    virtual std::string getDescription()=0;

    /**
     * @return The localized (displayable) description of this LOV.
     */
    virtual std::string getDisplayDescription()=0;

    /**
     * @return The Type of this LOV.
     */
    virtual Teamcenter::Soa::Client::Type* getType()=0;


    /**
     * The value type, as defined on the PropertyDescritpion this LOV is associated with
     * @return      The value type.
     *
     * @see PropertyDescription
     */
    virtual int getValueType()=0;


    /**
     * @return The usage of the LOV
     */
    virtual Usage getUsage()=0;



    /**
     * Return the Values for this LOV.<br>
     *
     * @param   values The values in this list.
     *
     * <b>NOTICE:</b> This method may result in a server trip. For Dynamic LOVs this method will result
     * in a server trip the first time it is called for this instance. When configured without a
     * Client Meta Model Cache a server trip is made for LOV of all types.<br>
     *
     * Values can be conditionally attached to the LOV.
     * The condition is determined to be true based on valid conditions on UserSession.fnd0isTrueConditions.
     * This is evaluated when this method is called.
     *
     */
    virtual void getValues(  std::vector< Teamcenter::Soa::Client::LovValue* >& values )=0;


protected:

    LovInfo( );


};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

