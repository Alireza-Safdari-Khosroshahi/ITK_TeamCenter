/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_CONDITIONALCHOICE_HXX
#define TEAMCENTER_SOA_CLIENT_CONDITIONALCHOICE_HXX

#include <vector>
#include <map>
#include <set>
#include <string>

#include <teamcenter/soa/client/Connection.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/SessionHandler.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
class  PropertyDescriptionImpl;
class  LovValueImpl;

class  ConditionResolver : public Teamcenter::Soa::Client::SessionHandler
{
public:
    static const std::string IS_TRUE;
    static ConditionResolver* getResolver( Teamcenter::Soa::Client::Connection* connection);

    bool    isTrueConditions( const std::string& condition ) const;

    void localSessionChange ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> userSession );
    void sharedSessionChange( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> userSession );
    SOA_CLASS_NEW_OPERATORS

private:
    ConditionResolver();
    ~ConditionResolver();

    static std::map< Teamcenter::Soa::Client::Connection*, ConditionResolver*>  conditionResolvers;

    std::set<std::string>    trueConditions;

};

class TCSOACLIENTMNGD_API Choice
{
public:
    const std::string   mCondition;
          Chooseable*   mElement;

    Choice( const std::string& condition, Chooseable* element );
   ~Choice();

     SOA_CLASS_NEW_OPERATORS

private:
    Choice();
};



class TCSOACLIENTMNGD_API ConditionChoices
{
public:

   /**
    *
    * Create a ConditionChoice that will only resolve isTrue
    *
    */
    ConditionChoices( );


    /**
     *
     * Create a ConditionChoice that will resolve valid conditions from the UserSession object
     *
     * @param connection
     */
    explicit ConditionChoices( Teamcenter::Soa::Client::Connection* connection );
    ~ConditionChoices( );
    SOA_CLASS_NEW_OPERATORS




    /**
     * @param element
     */
    void addChoice( Chooseable* element );


    /**
     * @param condition
     * @param element
     */
    void addChoice( const std::string& condition, Chooseable* element );

    /**
     * Return the first true condition choice in the list.
     * If this holds a Dynamic LOV (initTypesByName only returns
     * UID of an LOV and we don't have the Client Meta Model Cache)
     * this will resolve that LOV (go to the server) on the first time
     * this is called.
     *
     * @return The first available choice in the list.
     */
    Chooseable* getFirst();


    /**
    * Peek at the first choice regardless of true conditions.
     *
     * @return  The first choice, null if there are no choices in the list.
     */
    Chooseable* peek();

    /**
    * Peek at the condition name of the first element.
     *
     * @return The condition name of the first element, null if  there are no choices in the list.
     */
    std::string peekAtCondition();

    /**
     * Return a list of all choices that are true.
     * If this choice holds a Dynamic LOV (we have the LOV Info,but not the actual values)
     * this will result in the values being resolved (server trip) every time this method is called
     *
     * @return A list of all choices that are true.
     */
    void getAll( std::vector<Chooseable*>& allChoices );



private:

    friend class PropertyDescriptionImpl;
    friend class LovValueImpl;

    std::vector< Choice* > choices;
    ConditionResolver*   resolver;

    void clearChoices();            //PropertyDescriptionImpl and LovValueImpl needs to remove references to LOVs 

};
}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>


#endif

