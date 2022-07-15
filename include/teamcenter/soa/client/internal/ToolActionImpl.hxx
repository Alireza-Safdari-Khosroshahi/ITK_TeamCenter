/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_TOOLACTIONIMPL_HXX
#define TEAMCENTER_SOA_CLIENT_TOOLACTIONIMPL_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/client/ToolAction.hxx>
#include <teamcenter/soa/client/ActionReference.hxx>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class ToolActionImpl: public ToolAction
{
public:



    /**
     *
     * Constructor
     *
     * @param name          The name
     * @param references    The references
     */
    ToolActionImpl( const std::string& name, const std::map<std::string,ActionReference*>& references );
    ~ToolActionImpl();

    virtual std::string getName();
    virtual std::vector<ActionReference*> getActionReferences();
    virtual std::vector<std::string> getActionReferenceNames();
    virtual ActionReference* getActionReference( const std::string& name );

    SOA_CLASS_NEW_OPERATORS

private:
    ToolActionImpl();     // don't allow use of default

    const std::string                   mName;
          std::map<std::string,ActionReference*>   mReferences;




};

}}}//end namespace


#endif

