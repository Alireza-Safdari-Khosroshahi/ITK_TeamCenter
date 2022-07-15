/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/

/*  */


#ifndef TEAMCENTER_SOA_CLIENT_MODELOBJECTFACTORY_HXX
#define TEAMCENTER_SOA_CLIENT_MODELOBJECTFACTORY_HXX

#include <string>

#include <teamcenter/soa/client/ModelObject.hxx>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
class  ModelObjectFactory
{
public:
    virtual ~ModelObjectFactory(){};
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> construct( ) = 0;
};


 
template<class T> class  ModelObjectTypeFactory : public Teamcenter::Soa::Client::ModelObjectFactory 
{ 
public: 
    ModelObjectTypeFactory(){};
    ~ModelObjectTypeFactory(){};


    virtual Teamcenter::Soa::Common::AutoPtr<ModelObject> construct( )
    {
        Teamcenter::Soa::Common::AutoPtr<ModelObject> ptr( new T );
        return ptr;
    } 
}; 
 
}}} 
 

#endif
