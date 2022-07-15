/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_DYNAMICLOV_HXX
#define TEAMCENTER_SOA_CLIENT_DYNAMICLOV_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/internal/LovImpl.hxx>

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
class DynamicLov: public LovImpl
{
public:






    /**
     *
     * Constructor of a Dynamic LOV (default, that needs style, plus LOVInfo/LovValues
     * @param uid
     * @param type
     * @param specifier
     * @param dependProps
     * @param owningTypeName
     * @param owningProperty
     * @param connection
     */
    DynamicLov( const std::string& uid,  Type* type, int specifier,
                const std::vector<std::string>& dependProps, const std::vector<Lov::Style>& dependStyles,
                const std::string& owningTypeName,
                const std::string& owningProperty, Connection* connection);

    ~DynamicLov();

    SOA_CLASS_NEW_OPERATORS


    /**
     * @return The LOV

     */
    virtual Chooseable* resolve();
    virtual bool  needsToBeResolved();

    virtual Lov::Style getStyle();
    virtual LovInfo* getLovInfo();

    // OK to use these methods, so use parent impl
    //virtual std::vector<std::string> getDependantProperties();
    //vritual std::vector<Lov::Style> getDependantStyles();
    //virtual std::string getUid();
    //virtual int getSpecifier();


private:



    static const int LOV_DESC_ATTACH_LOGICAL;
    static const std::string LovAttachedSpecs;
    static       std::vector<std::string> empty;


          Connection*   mConnection;
    const std::string   mOwningTypeName;
    const std::string   mOwningProperty;
          Type*         mType;

    DynamicLov();   // don't allow the use of default
    Lov::Style calculateStyle( int level, LovInfo* lovInfo);


};

}}}//end namespace


#endif

