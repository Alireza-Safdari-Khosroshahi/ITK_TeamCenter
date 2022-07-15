/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_DYNAMICLOVVALUES_HXX
#define TEAMCENTER_SOA_CLIENT_DYNAMICLOVVALUES_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/LovValue.hxx>
#include <teamcenter/soa/client/LovInfo.hxx>
#include <teamcenter/soa/client/Connection.hxx>
#include <teamcenter/soa/client/Type.hxx>





namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * This class is used to retrieve LOV values from the server of LOVs found in the Client Cache
 * but do not have any values. The list of User Names is one such LOV.
 *
 */
class DynamicLovValues: public LovValue
{
public:

    /**
     *
     * Constructor of a Dynamic LOV (cached, that needs LovValues
     * @param uid
     * @param lovName
     * @param type
     * @param useage

     * @param connection
     */
    DynamicLovValues( const std::string& uid,  const std::string& lovName, Type* type, LovInfo::Usage useage, Connection* connection);
    ~DynamicLovValues();

    SOA_CLASS_NEW_OPERATORS

    /**
     * Resolve the actual value with a trip to the server
     * @return A vector of the LovValues
     */
     virtual std::vector<Chooseable*> resolveVector(  );
     virtual bool  needsToBeResolved();


       // ============================================================
    // This class implements the LovInfo interface so it can be passed
    // around like any other LovInfo, however the ConditionChoice will
    // call the resolve method once the client application wants the actual
    // data. The resolve method will return a instance created from the application's
    // ObjectFactory and the ConditionChoice will return  that instance at which
    // time this instance will go to Garbage Collection.
    // There should not be any code calling  the methods on LovInfo interface, but
    // if  they do they will get the IllegalArgumentException.
    // ==============================================================



    virtual std::string getValue();
    virtual std::string getDisplayValue();
    virtual std::string getFullDisplayValue( const std::string& delimiter );
    virtual bool hasDescription();
    virtual std::string getDescription();
    virtual std::string getDisplayDescription();
    virtual LovInfo* getChildLov();
    virtual char getCharacterValue();
    virtual Teamcenter::Soa::Common::DateTime getDateTimeValue();
    virtual double getDoubleValue();
    virtual int getIntegerValue();
    virtual std::string getStringValue();
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getModelObjectValue();


private:
    static std::map<Connection*,std::string>                   sLovPolicies;


    static const std::string LovValues;
    static const std::string LovValueFilters;
    static const std::string LovValueFiltersIndexs;
    static const std::string LovValueDescriptions;
    static const std::string LovLowerLimit;
    static const std::string LovUpperLimit;
    static const std::string BasedOnLov;
    static const std::string ShownValueIdexes;




    const std::string     mUid;
    const std::string     mLovName;
          Type*           mType;
    const LovInfo::Usage  mUsage;
          Connection*     mConnection;






    DynamicLovValues(); // do not allow use of default
    std::vector<Chooseable*> resolveWithFetch( bool haveFetched );
    void initializePolicy(  );
    void getLOVProperties( const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& listOfValues );
    static bool sortModelObjectValuesNeeded( int valueType, Type* lovType );
    static void sortModelObjectValues( std::vector<std::string>& values, std::vector<std::string>& displayValues );





};

}}}//end namespace


#endif

