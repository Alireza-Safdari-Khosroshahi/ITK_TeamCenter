// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_CLIENT_BASEDONIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_BASEDONIMPL_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/BasedOn.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class BasedOnImpl: public BasedOn
{
public:

    /**
     * Constructor
     * @param sourceType
     * @param sourceProperty
     */
    BasedOnImpl( const std::string& sourceType, const std::string& sourceProperty );
    ~BasedOnImpl();
    SOA_CLASS_NEW_OPERATORS


    virtual std::string getSourceType();
    virtual std::string getSourceProperty();


private:
    const std::string   mSourceType;
    const std::string   mSourceProperty;

};

}}}//end namespace


#endif

