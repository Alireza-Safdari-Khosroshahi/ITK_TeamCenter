/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_ACTIONREFERENCEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_ACTIONREFERENCEIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/ActionReference.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class ActionReferenceImpl: public ActionReference
{
public:




    ActionReferenceImpl( const std::string& name, bool lExport, Reference* reference );
    ~ActionReferenceImpl();

    virtual std::string getName();
    virtual Reference* getReference();
    virtual bool isExport();

    SOA_CLASS_NEW_OPERATORS

private:
    ActionReferenceImpl();     // don't allow use of default

    const std::string     mName;
    const bool           mExport;
          Reference*     mReference;



};

}}}//end namespace


#endif

