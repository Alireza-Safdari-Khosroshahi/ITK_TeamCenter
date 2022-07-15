/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_REFERENCEIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_REFERENCEIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/Reference.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class ReferenceImpl: public Reference
{
public:




    ReferenceImpl( const std::string& name, const std::vector<std::string>& templates, const std::vector<std::string>& formats );
    ~ReferenceImpl();

    virtual std::string                getName();
    virtual std::vector<std::string>   getTemplates();
    virtual std::vector<std::string>   getFormats();

    SOA_CLASS_NEW_OPERATORS

private:
    ReferenceImpl();     // don't allow use of default

    const std::string                 mName;
    const std::vector<std::string>    mTemplates;
    const std::vector<std::string>    mFormats;
    



};

}}}//end namespace


#endif

