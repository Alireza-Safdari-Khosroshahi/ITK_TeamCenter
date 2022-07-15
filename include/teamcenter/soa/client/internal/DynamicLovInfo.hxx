/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_DYNAMICLOVINFO_HXX
#define TEAMCENTER_SOA_CLIENT_DYNAMICLOVINFO_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/internal/LovInfoImpl.hxx>
#include <teamcenter/soa/client/Connection.hxx>





namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


/**
 * This class is used to retrieve full LOV instance. This is when we just have the LOV UID (the Type data
 * is pulled from the server vs. the client cache)
 *
 */
class DynamicLovInfo: public LovInfoImpl
{
public:

    /**
     * Constructor
     *
     * @param uid
     * @param type
     * @param connection
     * @param owningType
     * @param owningProp
     * @unpublished
     */
    DynamicLovInfo( const std::string& uid,  Type* type, Connection* connection,
                    const std::string& owningType, const std::string& owningProp);
    ~DynamicLovInfo();

    SOA_CLASS_NEW_OPERATORS

    /**
     * Resolve the LovInfo data with a trip to the server
     * @return  The LovInfo
     */
    virtual Chooseable* resolve();
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


    virtual std::string getUid();
    virtual std::string getName();
    virtual std::string getDisplayName();
    virtual std::string getDescription();
    virtual std::string getDisplayDescription();
    virtual Type* getType();
    virtual int getValueType();
    virtual LovInfo::Usage getUsage();
    virtual void getValues( std::vector< Teamcenter::Soa::Client::LovValue* >& values );


private:
    static std::map<Connection*,std::string>   sLovPolicies;

    static const std::string LovUsage;
    static const std::string LovName;
    static const std::string LovDesc;
    static const std::string LovAttachedProps;
    static const std::string LovAttachedSpecs;
    static const std::string LovAttachedTypes;
    static const std::string BasedOnLov;
    static const std::string ShownValueIdexes;





          Connection*    mConnection;
    const std::string    mOwningType; // for logging
    const std::string    mOwningProp; // for logging


    DynamicLovInfo();   // do not allow use of default
    LovInfo* resolveWithFetch( bool haveFetched );



    void initializePolicy(  );
    void getLOVProperties( const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& listOfValues );




};

}}}//end namespace


#endif

