/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOVINFOIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_LOVINFOIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/LovInfo.hxx>
#include <teamcenter/soa/client/ConditionChoices.hxx>





namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {



class LovInfoImpl: public LovInfo
{
public:



    /**
     * Constructor
     *
     * @param uid
     * @param name
     * @param displayName
     * @param description
     * @param displayDescription
     * @param type
     * @param valueType
     * @param usage
     * @param values

     */
    LovInfoImpl(
            const std::string& uid,
            const std::string& name,        const std::string& displayName,
            const std::string& description, const std::string& displayDescription,
            Type* type, int valueType,  Usage usage,
            ConditionChoices* valueChoices
             );

    ~LovInfoImpl();
    SOA_CLASS_NEW_OPERATORS


   /**
    * @param    s String to convert to a Usage
    * @return   The Usage for the given string
    */
   static  Usage constructUsage(  const std::string& s );


    virtual std::string getUid();
    virtual std::string getName();
    virtual std::string getDisplayName();
    virtual std::string getDescription();
    virtual std::string getDisplayDescription();
    virtual Teamcenter::Soa::Client::Type* getType();
    virtual int getValueType();
    virtual Usage getUsage();
    virtual void getValues(  std::vector< Teamcenter::Soa::Client::LovValue* >& values );


protected:
    const std::string               mUid;
          Type*                     mType;
    const int                       mValueType;
    const std::string               mName;
    const std::string               mDisplayName;
    const std::string               mDescription;
    const std::string               mDisplayDescription;
    const Usage                     mUsage;
          ConditionChoices*         mValueChoices;


private:
    LovInfoImpl(); // do not allow use of default
};

}}}//end namespace


#endif

