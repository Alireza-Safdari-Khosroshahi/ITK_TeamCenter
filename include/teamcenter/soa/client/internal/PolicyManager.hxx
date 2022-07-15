// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_POLICYMANAGER_HXX
#define TEAMCENTER_SOA_CLIENT_POLICYMANAGER_HXX

#include <string>
#include <set>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/Version.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>
#include <teamcenter/soa/internal/common/Threads.hxx>
#include <teamcenter/soa/client/ObjectPropertyPolicyManager.hxx>







namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            class Connection;

class RequestLock
{
public:
    RequestLock();
    ~RequestLock();
};

class DynamicPolicy 
{
public:
    DynamicPolicy( const std::string& policyName, const Teamcenter::Soa::Common::ObjectPropertyPolicy& policy, bool useRefCounting );
   ~DynamicPolicy();
    SOA_CLASS_NEW_OPERATORS
  
   void removeProperties( Teamcenter::Soa::Common::PolicyType& policyType, bool colllectUpdates );
   void addProperties   ( Teamcenter::Soa::Common::PolicyType& policyType, bool collectUpdates  );


    bool typeHasChanges( Teamcenter::Soa::Common::PolicyType* left, const Teamcenter::Soa::Common::PolicyType&  right );

    std::string          mPolicyName;
    bool                 mUseRefCounting;
    Teamcenter::Soa::Common::ObjectPropertyPolicy*    mThePolicy;
    std::map<std::string,Teamcenter::Soa::Common::PolicyType*>  mPendingAdds;
    std::map<std::string,Teamcenter::Soa::Common::PolicyType*>  mPendingRemoves;
    std::map<std::string,int>     mPropRefCounts;

};

class PolicyManager: public ObjectPropertyPolicyManager
{
public:
    explicit PolicyManager(Connection* connection);
    ~PolicyManager();

    SOA_CLASS_NEW_OPERATORS




    void initialize( const std::string& current, const std::string& previous );




    virtual std::string addPolicy( const std::string& policyName, PolicyStyle style );
    virtual std::string addPolicy( const Teamcenter::Soa::Common::ObjectPropertyPolicy& policy, bool useRefCounting );
    virtual void setPolicy( const std::string& policyName );
    virtual void setPolicyPerThread( const std::string& policyName );
    virtual void clearPolicyPerThread();
    virtual void updatePolicy( const std::string& policyName, bool applyToRootTypes,
                               const std::vector<Teamcenter::Soa::Common::PolicyType>& addProperties, 
                               const std::vector<Teamcenter::Soa::Common::PolicyType>& removeProperties );
    virtual std::vector<std::string> getAvailablePolices();
    virtual std::string getPreviousPolicy();
    virtual std::string getCurrentPolicy();
    virtual Teamcenter::Soa::Common::ObjectPropertyPolicy* getPolicy( const std::string& policyName );


    /**
     * @return the Active policy to be set on the client context
     */
    std::string getActive();
    void sendPendingUpdate();
    void cacheStateInformation( const std::string& port, const std::string& method, const std::string& args, const std::string& response );
    std::string getRealId( const std::string& policyId );
    void restoreServerPolicies();
    std::string getPolicyId( const std::string& realId );


private:
    DynamicPolicy* getDynamicPolicy( const std::string& policyName );



private:
    friend class RequestLock;
    // Don't allow these
    PolicyManager( );

    static const Teamcenter::Soa::Common::Version v91;
    static const Teamcenter::Soa::Common::Version v80;
    static       std::set<ThreadId_t> managedRequests;

    Connection*              mConnection;
    std::string              mCurrentPolicy;
    std::string              mPreviousPolicy;
    std::map<ThreadId_t, std::string> mPerThreadPolicies;
    // This map starts off with key/value being the same for each policy
    // as the client gets re-assigned to a new server the dynamic policies will get a new ID
    // this maps the original ID (known to the calling client) to then new IDs known by the server
    std::map<std::string, std::string> mValidPolicies;
    std::map<std::string,DynamicPolicy*> mOjbectPropertyPolicies;

};

}}}//end namespace


#endif

